from __future__ import annotations

import argparse
import re
from collections import Counter
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable, Iterable, Sequence


DEFAULT_ROOTS = (Path("pack/textures"),)
CON_PREFIX_RE = re.compile(r"^con\d")

# These stems line up with stable material assignments in the stock Quake II
# rerelease pak, so they are safer than broad substring guesses.
EXACT_STEM_MATERIALS: dict[str, str] = {
    "comp1_1": "glass",
    "comp1_2": "glass",
    "comp1_3": "glass",
    "comp1_4": "clank",
    "comp2_1": "glass",
    "comp2_2": "clank",
    "comp2_3": "clank",
    "comp2_4": "clank",
    "comp2_5": "clank",
    "comp2_6": "clank",
    "comp2_7": "clank",
    "mettile": "clank",
    "mettile2": "clank",
    "symbol1_3": "mech",
    "symbol1_5": "mech",
}


def contains_any(text: str, keywords: Sequence[str]) -> bool:
    return any(keyword in text for keyword in keywords)


RULES: tuple[tuple[str, str, Callable[[str], bool]], ...] = (
    ("splash", "fluids", lambda stem: contains_any(stem, ("water", "lava", "slime", "oil", "sewer", "current"))),
    (
        "glass",
        "lighting",
        lambda stem: "glass" in stem or stem.startswith(("wlight", "light", "lite", "slight")),
    ),
    ("energy", "energy", lambda stem: contains_any(stem, ("force", "shield", "laser"))),
    ("meat", "gore", lambda stem: contains_any(stem, ("gore", "blood", "gib", "meat"))),
    ("flesh", "flesh", lambda stem: contains_any(stem, ("flesh", "skin", "organ"))),
    ("wood", "wood", lambda stem: contains_any(stem, ("crate", "wood"))),
    (
        "mech",
        "mechanical",
        lambda stem: contains_any(
            stem,
            ("grate", "mesh", "stud", "barrel", "drill", "button", "switch", "console", "control", "tech", "lever"),
        ),
    ),
    (
        "clank",
        "metal",
        lambda stem: contains_any(
            stem,
            ("metal", "rust", "door", "frame", "sign", "warn", "hazard", "symbol", "pipe", "plat", "trim"),
        ),
    ),
    ("tile", "tile", lambda stem: "tile" in stem),
    ("grass", "foliage", lambda stem: stem.startswith(("grass", "bush", "field")) or "vine" in stem),
    ("step", "stairs", lambda stem: stem.startswith("stair") or "step" in stem),
    (
        "boot",
        "hard-surface",
        lambda stem: contains_any(stem, ("brick", "asphalt", "dirt", "earth", "sand", "rock", "floor"))
        or CON_PREFIX_RE.match(stem) is not None,
    ),
)


@dataclass
class RunStats:
    scanned: int = 0
    matched: int = 0
    created: int = 0
    overwritten: int = 0
    skipped_existing: int = 0
    skipped_unmatched: int = 0
    per_material: Counter[str] = field(default_factory=Counter)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate Quake II rerelease .mat files for Oblivion WAL textures using conservative name-based rules."
    )
    parser.add_argument(
        "--repo-root",
        type=Path,
        default=Path(__file__).resolve().parents[1],
        help="Repository root. Defaults to the parent of this script's directory.",
    )
    parser.add_argument(
        "--root",
        dest="roots",
        action="append",
        type=Path,
        help="Relative asset root to scan. Can be specified multiple times.",
    )
    parser.add_argument(
        "--overwrite",
        action="store_true",
        help="Overwrite existing .mat files for matched textures.",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Report actions without writing files.",
    )
    parser.add_argument(
        "--quiet",
        action="store_true",
        help="Suppress per-file output and print only the summary.",
    )
    return parser.parse_args()


def iter_wal_files(repo_root: Path, roots: Sequence[Path]) -> Iterable[Path]:
    for relative_root in roots:
        asset_root = repo_root / relative_root
        if not asset_root.is_dir():
            continue

        files = sorted(
            (path for path in asset_root.rglob("*.wal") if path.is_file()),
            key=lambda item: item.relative_to(repo_root).as_posix().lower(),
        )
        yield from files


def guess_material(stem: str) -> tuple[str | None, str | None]:
    exact = EXACT_STEM_MATERIALS.get(stem)
    if exact is not None:
        return exact, "exact"

    for material, source, predicate in RULES:
        if predicate(stem):
            return material, source

    return None, None


def generate_mat_files(
    repo_root: Path,
    roots: Sequence[Path],
    overwrite: bool,
    dry_run: bool,
    quiet: bool,
) -> RunStats:
    stats = RunStats()

    for wal_path in iter_wal_files(repo_root, roots):
        stats.scanned += 1
        material, source = guess_material(wal_path.stem.lower())
        rel_path = wal_path.relative_to(repo_root).as_posix()
        mat_path = wal_path.with_suffix(".mat")

        if material is None:
            stats.skipped_unmatched += 1
            if not quiet:
                print(f"skip {rel_path} (unmatched)")
            continue

        stats.matched += 1
        stats.per_material[material] += 1

        existed_before = mat_path.exists()

        if existed_before and not overwrite:
            stats.skipped_existing += 1
            if not quiet:
                print(f"keep {mat_path.relative_to(repo_root).as_posix()} -> {material} [{source}]")
            continue

        if not dry_run:
            mat_path.write_text(material, encoding="utf-8")

        if existed_before:
            stats.overwritten += 1
            verb = "overwrite"
        else:
            stats.created += 1
            verb = "create"

        if not quiet:
            print(f"{verb} {mat_path.relative_to(repo_root).as_posix()} -> {material} [{source}]")

    return stats


def main() -> int:
    args = parse_args()
    repo_root = args.repo_root.resolve()
    roots = tuple(args.roots) if args.roots else DEFAULT_ROOTS

    stats = generate_mat_files(
        repo_root=repo_root,
        roots=roots,
        overwrite=args.overwrite,
        dry_run=args.dry_run,
        quiet=args.quiet,
    )

    print()
    print(f"Scanned {stats.scanned} WAL textures.")
    print(f"Matched {stats.matched} textures and skipped {stats.skipped_unmatched} unmatched textures.")
    print(
        f"Created {stats.created} .mat files, overwrote {stats.overwritten}, "
        f"and kept {stats.skipped_existing} existing files."
    )
    if stats.per_material:
        material_summary = ", ".join(
            f"{material}={count}" for material, count in sorted(stats.per_material.items(), key=lambda item: (-item[1], item[0]))
        )
        print(f"Material totals: {material_summary}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
