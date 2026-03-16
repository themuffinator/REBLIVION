import sys
import unittest
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[1]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from tools.extract_spawn_manifest import HLILParser


class HLILParserSpawnMapStrcmpTest(unittest.TestCase):
    def test_extracts_spawn_entries_from_strcmp_chains(self) -> None:
        parser = HLILParser(Path("references/HLIL/oblivion/gamex86.dll_hlil.txt"))

        block = parser.function_blocks["sub_10005e30"]
        monster_entries = parser._extract_spawn_map_from_strcmp(block)

        expected_monsters = {
            "monster_tank": "sub_10001ac0",
            "monster_supertank": "sub_10001ac0",
            "monster_makron": "sub_10001ac0",
            "monster_jorg": "sub_10001ac0",
        }
        for classname, func in expected_monsters.items():
            self.assertIn(classname, monster_entries)
            self.assertEqual(monster_entries[classname], func)

        spawn_map = parser.spawn_map
        for classname, func in expected_monsters.items():
            self.assertIn(classname, spawn_map)
            self.assertEqual(spawn_map[classname], func)

        func_entries = parser._extract_spawn_map_from_strcmp(parser.function_blocks["sub_100090f0"])
        expected_funcs = {
            "func_door": "sub_10006b20",
            "func_door_rotating": "sub_10006df0",
        }
        for classname, func in expected_funcs.items():
            self.assertIn(classname, func_entries)
            self.assertEqual(func_entries[classname], func)
            self.assertIn(classname, spawn_map)
            self.assertEqual(spawn_map[classname], func)

    def test_extracts_spawn_entries_with_nested_gotos(self) -> None:
        parser = HLILParser(Path("references/HLIL/oblivion/gamex86.dll_hlil.txt"))

        block = parser.function_blocks["sub_10031d70"]
        entries = parser._extract_spawn_map_from_strcmp(block)

        self.assertIn("misc_actor", entries)
        self.assertEqual(entries["misc_actor"], "sub_10037cd0")

        spawn_map = parser.spawn_map
        self.assertIn("misc_actor", spawn_map)
        self.assertEqual(spawn_map["misc_actor"], "sub_1001f460")

    def test_extracts_spawn_entries_from_spawn_tables_and_switches(self) -> None:
        parser = HLILParser(Path("references/HLIL/oblivion/gamex86.dll_hlil.txt"))

        block = [
            "10000000  spawn_t spawn_table[] = {",
            "10000004      { data_1004aaa0, sub_10001000 }",
            "10000008      { &data_1004bbb0, sub_10002000 }",
            "1000000c      { 0x1004ccc0, sub_10003000 }",
            "10000010      { \"func_gate\", sub_10004000 }",
            "10000014  }",
        ]
        literal_map = {
            "data_1004aaa0": "item_health",
            "data_1004bbb0": "item_armor",
            "data_1004ccc0": "func_plat",
            "0x1004ccc0": "func_plat",
        }
        table_entries = parser._extract_spawn_map_from_spawn_tables(block, literal_map)
        self.assertEqual(table_entries["item_health"], "sub_10001000")
        self.assertEqual(table_entries["item_armor"], "sub_10002000")
        self.assertEqual(table_entries["func_plat"], "sub_10003000")
        self.assertEqual(table_entries["func_gate"], "sub_10004000")

        switch_block = [
            "10000020  switch (classname_hash)",
            "10000024      case 0x1:",
            "10000028          if (sub_10038b20(*(arg1 + 0x118), \"func_water\") == 0)",
            "1000002c              return sub_10005000(arg1)",
            "10000030      case 0x2:",
            "10000034          if (sub_10038b20(*(arg1 + 0x118), \"func_conveyor\") == 0)",
            "10000038              goto label_10000060",
            "1000003c      default:",
            "1000003c          goto label_10000080",
            "10000060  label_10000060:",
            "10000064      return sub_10006000(arg1)",
            "10000080  label_10000080:",
            "10000084      return sub_10007000(arg1)",
        ]
        switch_entries = parser._extract_spawn_map_from_spawn_tables(switch_block)
        self.assertEqual(switch_entries["func_water"], "sub_10005000")
        self.assertEqual(switch_entries["func_conveyor"], "sub_10006000")

    def test_spawn_table_entries_include_rotate_train(self) -> None:
        parser = HLILParser(Path("references/HLIL/oblivion/gamex86.dll_hlil.txt"))
        spawn_map = parser.spawn_map
        self.assertIn("func_rotate_train", spawn_map)
        self.assertEqual(spawn_map["func_rotate_train"], "sub_10015750")
        self.assertNotIn("func_train_rotating", spawn_map)

    def test_spawn_map_includes_binary_table_entries(self) -> None:
        parser = HLILParser(Path("references/HLIL/oblivion/gamex86.dll_hlil.txt"))

        binary_entries = parser._spawn_entries_from_binary_tables()
        expected = {
            "weapon_grenadelauncher": "sub_10035260",
            "ammo_bullets": "sub_1000bef0",
            "func_button": "sub_10008d30",
        }

        for classname, func in expected.items():
            self.assertIn(classname, binary_entries)
            self.assertEqual(binary_entries[classname], func)

        spawn_map = parser.spawn_map
        for classname, func in expected.items():
            self.assertIn(classname, spawn_map)
            self.assertEqual(spawn_map[classname], func)


if __name__ == "__main__":
    unittest.main()
