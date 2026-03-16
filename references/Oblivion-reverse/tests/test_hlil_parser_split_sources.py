import sys
import tempfile
from pathlib import Path
import unittest

PROJECT_ROOT = Path(__file__).resolve().parents[1]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from tools.extract_spawn_manifest import HLILParser


class HLILParserSplitSourcesTest(unittest.TestCase):
    def test_merges_split_pointer_and_function_data(self) -> None:
        with tempfile.TemporaryDirectory() as tmpdir:
            root = Path(tmpdir) / "references" / "HLIL" / "oblivion"
            split_root = root / "split"
            split_types = split_root / "types"
            split_root.mkdir(parents=True)
            split_types.mkdir(parents=True)

            main_path = root / "gamex86.dll_hlil.txt"
            main_content = "\n".join(
                [
                    "10010000  char (* data_10010000)[0x4] = data_10020000 {\"classname_main\"}",
                    "10010010              00 01 00 00  01 00 00 00  02 00 00 00",
                    "10010060  char (* data_10010060)[0x4] = data_10020060 {\"classname_main\"}",
                    "10010070  void* data_10010070 = sub_10030000",
                    "10020000    void sub_10030000(void* arg1)",
                    "10020010      *(arg1 + 0x11c) = 0x1",
                ]
            )
            main_path.write_text(main_content, encoding="utf-8")

            block_path = split_root / "gamex86.dll_hlil_block0001_block.txt"
            block_content = "\n".join(
                [
                    "10020000    void sub_10030000(void* arg1)",
                    "10020020      *(arg1 + 0x11c) |= 0x2",
                ]
            )
            block_path.write_text(block_content, encoding="utf-8")

            type_path = split_types / "gamex86.dll_hlil_type_test_block.txt"
            type_content = "\n".join(
                [
                    "10011000  char (* data_10011000)[0x4] = data_10021000 {\"classname_split\"}",
                    "10011010              80 01 00 00  01 00 00 00  00 00 00 00",
                    "10011040  char (* data_10011040)[0x4] = data_10021040 {\"classname_split\"}",
                    "10011050  void* data_10011050 = sub_10031000",
                    "10030080    void sub_10031000(void* arg1)",
                    "10030090      *(arg1 + 0x11c) |= 0x4",
                ]
            )
            type_path.write_text(type_content, encoding="utf-8")

            parser = HLILParser(main_path)

            self.assertIn("sub_10030000", parser.function_blocks)
            self.assertIn("sub_10031000", parser.function_blocks)
            merged_block = parser.function_blocks["sub_10030000"]
            self.assertTrue(any("= 0x1" in line for line in merged_block))
            self.assertTrue(any("|= 0x2" in line for line in merged_block))

            fields = parser.fields
            self.assertIn(0x100, fields)
            self.assertIn(0x180, fields)
            self.assertEqual(fields[0x180].name, "classname_split")

            spawn_map = parser.spawn_map
            self.assertEqual(spawn_map["classname_main"], "sub_10030000")
            self.assertEqual(spawn_map["classname_split"], "sub_10031000")


if __name__ == "__main__":
    unittest.main()
