import json
import re
import subprocess
import sys
from pathlib import Path
from typing import Set
import unittest


def _extract_itemlist_block(source: str) -> str:
    anchor = re.search(r"gitem_t\s+itemlist\[\]\s*=", source)
    if not anchor:
        raise AssertionError("Could not locate gitem_t itemlist[] block in g_items.c")
    brace_start = source.find("{", anchor.end())
    if brace_start == -1:
        raise AssertionError("Could not locate opening brace for itemlist[]")
    depth = 0
    for idx in range(brace_start, len(source)):
        char = source[idx]
        if char == "{":
            depth += 1
        elif char == "}":
            depth -= 1
            if depth == 0:
                return source[brace_start:idx]
    raise AssertionError("Failed to locate the end of itemlist[]")


def _collect_itemlist_classnames(source: str) -> Set[str]:
    block = _extract_itemlist_block(source)
    classnames = set(re.findall(r"\{\s*\"([^\"]+)\",", block))
    return classnames


class HLILItemlistSyncTest(unittest.TestCase):
    def test_hlil_items_exist_in_itemlist(self) -> None:
        repo_root = Path(__file__).resolve().parents[1]
        script = repo_root / "tools" / "extract_spawn_manifest.py"
        result = subprocess.run(
            [sys.executable, str(script)],
            check=True,
            capture_output=True,
            text=True,
        )
        manifest = json.loads(result.stdout)
        hlil_manifest = manifest.get("combined", {}).get("hlil", {})
        tracked = {
            name
            for name in hlil_manifest
            if name.startswith(("weapon_", "key_", "ammo_", "item_power_"))
        }
        self.assertGreater(
            len(tracked),
            0,
            "HLIL manifest did not produce any weapon/key classnames to validate",
        )
        g_items_source = (repo_root / "src" / "game" / "g_items.c").read_text(encoding="utf-8")
        itemlist_classnames = _collect_itemlist_classnames(g_items_source)
        missing = sorted(tracked - itemlist_classnames)
        self.assertEqual(
            missing,
            [],
            f"HLIL weapon/key classnames missing from g_items itemlist: {missing}",
        )


if __name__ == "__main__":
    unittest.main()
