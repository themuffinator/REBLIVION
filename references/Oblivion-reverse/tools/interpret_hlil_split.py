"""Generate interpreted summaries from split HLIL output.

This script analyses the files under ``references/HLIL/oblivion/split`` and
creates machine and human readable summaries in
``references/HLIL/oblivion/interpreted``.

The goal is to take the rather low level HLIL extracts (mainly describing
global data tables and string literals) and provide structured artefacts that
can be consumed while reverse engineering the game module.

Usage::

    python tools/interpret_hlil_split.py

The script is intentionally written without external dependencies so it can be
executed in constrained environments.
"""

from __future__ import annotations

import ast
import json
import re
from dataclasses import dataclass, asdict
from pathlib import Path
from typing import Dict, Iterable, List, Optional


REPO_ROOT = Path(__file__).resolve().parent.parent
SPLIT_ROOT = REPO_ROOT / "references" / "HLIL" / "oblivion" / "split"
ORIGINAL_HLIL = REPO_ROOT / "references" / "HLIL" / "oblivion" / "gamex86.dll_hlil.txt"
OUTPUT_ROOT = REPO_ROOT / "references" / "HLIL" / "oblivion" / "interpreted"
CONTROLLER_OUTPUT = OUTPUT_ROOT / "controller_classnames.json"


ADDRESS_LINE_RE = re.compile(r"^(?P<addr>[0-9a-f]{8})\s+(?P<body>.+?)\s*$", re.IGNORECASE)
ARRAY_ENTRY_RE = re.compile(r"\[0x([0-9a-f]+)\]\s*=\s*(.+)", re.IGNORECASE)
DATA_NAME_RE = re.compile(r"\bdata_[0-9a-f]+\b", re.IGNORECASE)
FUNC_DECL_RE = re.compile(
    r"^(?:\d+:)?\s*[0-9a-f]{8}\s+[^=]*\b(sub_[0-9a-f]+)\(",
    re.IGNORECASE,
)
CONTROLLER_LITERAL_RE = re.compile(
    r'"((?:target|trigger)_[a-z0-9_]+)"',
    re.IGNORECASE,
)


@dataclass
class StringEntry:
    address: str
    declaration: str
    symbol: str
    value: str
    category: str
    source_file: str


@dataclass
class ArrayEntry:
    address: str
    declaration: str
    symbol: str
    values: List[str]
    inferred_type: str
    source_file: str


@dataclass
class ControllerEntry:
    classname: str
    function: str
    source_file: str


class ControllerCollector:
    def __init__(self) -> None:
        self._entries: Dict[str, ControllerEntry] = {}

    def process(self, source_file: Path, text: str) -> None:
        lines = text.splitlines()
        current_func: Optional[str] = None
        current_lines: List[str] = []

        def flush() -> None:
            if not current_func or not current_lines:
                return
            block_text = "\n".join(current_lines)
            classnames = {
                match.group(1).lower()
                for match in CONTROLLER_LITERAL_RE.finditer(block_text)
            }
            for classname in sorted(classnames):
                if classname in self._entries:
                    continue
                self._entries[classname] = ControllerEntry(
                    classname=classname,
                    function=current_func,
                    source_file=str(source_file.relative_to(REPO_ROOT)),
                )

        for line in lines:
            match = FUNC_DECL_RE.match(line)
            if match:
                flush()
                current_func = match.group(1)
                current_lines = [line]
                continue
            if current_func:
                current_lines.append(line)
        flush()

    def as_list(self) -> List[Dict[str, str]]:
        return [
            {
                "classname": entry.classname,
                "function": entry.function,
                "source_file": entry.source_file,
            }
            for _, entry in sorted(self._entries.items())
        ]


def load_address_declarations(path: Path) -> Dict[str, str]:
    """Build a mapping from an address to the declaration line in the HLIL dump."""

    mapping: Dict[str, str] = {}
    with path.open("r", encoding="utf-8", errors="ignore") as handle:
        for line in handle:
            match = ADDRESS_LINE_RE.match(line)
            if not match:
                continue
            addr = match.group("addr").lower()
            body = match.group("body")
            mapping[addr] = body
    return mapping


def ensure_output_dir(path: Path) -> None:
    path.mkdir(parents=True, exist_ok=True)


def read_split_files(root: Path) -> Iterable[Path]:
    for item in sorted(root.glob("*.txt")):
        yield item
    # Pull in type extracts as well – they live in a dedicated directory.
    types_dir = root / "types"
    if types_dir.exists():
        for item in sorted(types_dir.glob("*.txt")):
            yield item


def extract_address(text: str) -> Optional[str]:
    for line in text.splitlines():
        match = ADDRESS_LINE_RE.match(line)
        if match:
            return match.group("addr").lower()
    return None


def extract_symbol(declaration: str) -> str:
    match = DATA_NAME_RE.search(declaration)
    if match:
        return match.group(0)
    # Fall back to the final token – this still provides a helpful hint.
    return declaration.split()[-1]


def categorise_string(value: str) -> str:
    lowered = value.lower()
    if lowered.endswith(".wav"):
        return "sound_path"
    if lowered.endswith((".md2", ".md3", ".mdl")):
        return "model_path"
    if lowered.startswith("models/"):
        return "model_path"
    if lowered.startswith("sprites/"):
        return "sprite_path"
    if lowered.startswith("misc/"):
        return "sound_path"
    if lowered.startswith("weapons/") or lowered.startswith("weapon_"):
        return "weapon_descriptor"
    if lowered.startswith("ammo_"):
        return "ammo_descriptor"
    if lowered.startswith("item_"):
        return "item_descriptor"
    if lowered.startswith("maps/"):
        return "map_resource"
    if "/" in value:
        return "resource_path"
    return "text_label"


def parse_string_entry(text: str, declaration: str, source_file: Path) -> Optional[StringEntry]:
    literal_match = re.search(r"\{(\".*?\")\}", text, re.DOTALL)
    if not literal_match:
        return None
    literal = literal_match.group(1)
    try:
        value = ast.literal_eval(literal)
    except SyntaxError:
        value = literal.strip('"')
    address = extract_address(text)
    if not address:
        return None
    symbol = extract_symbol(declaration)
    category = categorise_string(value)
    return StringEntry(
        address=f"0x{address}",
        declaration=declaration,
        symbol=symbol,
        value=value,
        category=category,
        source_file=str(source_file.relative_to(REPO_ROOT)),
    )


def parse_array_entry(text: str, declaration: str, source_file: Path) -> Optional[ArrayEntry]:
    values: List[str] = []
    for line in text.splitlines():
        entry_match = ARRAY_ENTRY_RE.search(line)
        if not entry_match:
            continue
        value = entry_match.group(2).strip()
        values.append(value)
    if not values:
        return None
    address = extract_address(text)
    if not address:
        return None
    symbol = extract_symbol(declaration)
    inferred_type = infer_array_type(values)
    return ArrayEntry(
        address=f"0x{address}",
        declaration=declaration,
        symbol=symbol,
        values=values,
        inferred_type=inferred_type,
        source_file=str(source_file.relative_to(REPO_ROOT)),
    )


def infer_array_type(values: List[str]) -> str:
    numeric_values: List[int] = []
    for raw in values:
        raw = raw.rstrip(",")
        try:
            if raw.startswith("0x"):
                numeric_values.append(int(raw, 16))
            elif raw.startswith("-"):
                numeric_values.append(int(raw, 10))
            else:
                numeric_values.append(int(raw, 10))
        except ValueError:
            return "mixed"
    if all(0 <= num <= 0xFF for num in numeric_values):
        return "uint8_t"
    if all(0 <= num <= 0xFFFF for num in numeric_values):
        return "uint16_t"
    if all(num >= 0 for num in numeric_values):
        return "uint32_t"
    return "int32_t"


def render_markdown_table(entries: Iterable[dict], headers: List[str]) -> str:
    lines = ["| " + " | ".join(headers) + " |"]
    lines.append("| " + " | ".join(["---"] * len(headers)) + " |")
    for entry in entries:
        row = [str(entry.get(header, "")) for header in headers]
        lines.append("| " + " | ".join(row) + " |")
    return "\n".join(lines) + "\n"


def main() -> None:
    declarations = load_address_declarations(ORIGINAL_HLIL)
    ensure_output_dir(OUTPUT_ROOT)

    string_entries: List[StringEntry] = []
    array_entries: List[ArrayEntry] = []
    skipped: List[str] = []
    controller_collector = ControllerCollector()

    for split_file in read_split_files(SPLIT_ROOT):
        text = split_file.read_text(encoding="utf-8", errors="ignore")
        controller_collector.process(split_file, text)
        address = extract_address(text)
        if not address:
            skipped.append(str(split_file.relative_to(REPO_ROOT)))
            continue
        declaration = declarations.get(address)
        if not declaration:
            skipped.append(str(split_file.relative_to(REPO_ROOT)))
            continue

        string_entry = parse_string_entry(text, declaration, split_file)
        if string_entry:
            string_entries.append(string_entry)
            continue

        array_entry = parse_array_entry(text, declaration, split_file)
        if array_entry:
            array_entries.append(array_entry)
            continue

        skipped.append(str(split_file.relative_to(REPO_ROOT)))

    # Persist structured JSON output.
    (OUTPUT_ROOT / "strings.json").write_text(
        json.dumps([asdict(entry) for entry in string_entries], indent=2, ensure_ascii=False)
        + "\n",
        encoding="utf-8",
    )
    (OUTPUT_ROOT / "arrays.json").write_text(
        json.dumps([asdict(entry) for entry in array_entries], indent=2, ensure_ascii=False)
        + "\n",
        encoding="utf-8",
    )
    controller_entries = controller_collector.as_list()
    CONTROLLER_OUTPUT.write_text(
        json.dumps(controller_entries, indent=2, ensure_ascii=False) + "\n",
        encoding="utf-8",
    )

    # Render Markdown tables for quick inspection.
    string_rows = [
        {
            "Address": entry.address,
            "Symbol": entry.symbol,
            "Category": entry.category,
            "Value": entry.value,
            "Source": entry.source_file,
        }
        for entry in string_entries
    ]
    strings_md = render_markdown_table(
        string_rows,
        ["Address", "Symbol", "Category", "Value", "Source"],
    )
    (OUTPUT_ROOT / "strings.md").write_text(strings_md, encoding="utf-8")

    array_rows = [
        {
            "Address": entry.address,
            "Symbol": entry.symbol,
            "Type": entry.inferred_type,
            "Values": ", ".join(entry.values[:6]) + (" …" if len(entry.values) > 6 else ""),
            "Source": entry.source_file,
        }
        for entry in array_entries
    ]
    arrays_md = render_markdown_table(
        array_rows,
        ["Address", "Symbol", "Type", "Values", "Source"],
    )
    (OUTPUT_ROOT / "arrays.md").write_text(arrays_md, encoding="utf-8")

    summary_lines = [
        f"Total strings interpreted: {len(string_entries)}",
        f"Total arrays interpreted: {len(array_entries)}",
        f"Controller classnames captured: {len(controller_entries)}",
        f"Skipped artefacts: {len(skipped)}",
    ]
    if skipped:
        summary_lines.append("\nSkipped files:")
        summary_lines.extend(f"- {item}" for item in skipped)
    (OUTPUT_ROOT / "summary.txt").write_text("\n".join(summary_lines) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
