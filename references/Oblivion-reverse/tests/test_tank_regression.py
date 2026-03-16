import re
from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
M_TANK_SOURCE = REPO_ROOT / "src" / "game" / "m_tank.c"


def extract_function_block(source: str, function_name: str) -> str:
	pattern = re.compile(rf"{function_name}\s*\([^)]*\)\s*\{{", re.MULTILINE)
	match = pattern.search(source)
	if not match:
		raise AssertionError(f"Function {function_name} not found")
	start = match.end()
	depth = 1
	idx = start
	while idx < len(source) and depth > 0:
		char = source[idx]
		if char == "{":
			depth += 1
		elif char == "}":
			depth -= 1
		idx += 1
	return source[match.start():idx]


class TankRetailRegression(unittest.TestCase):
	@classmethod
	def setUpClass(cls) -> None:
		cls.source_text = M_TANK_SOURCE.read_text(encoding="utf-8")

	def test_spawn_preserves_retail_corpse_branch(self) -> None:
		spawn_block = extract_function_block(self.source_text, "SP_monster_tank")

		self.assertIn('self->s.modelindex = gi.modelindex ("models/monsters/tank/tris.md2");', spawn_block)
		self.assertIn('if (self->spawnflags & SPAWNFLAG_CORPSE)', spawn_block)
		self.assertIn('self->health = -1;', spawn_block)
		self.assertIn('self->deadflag = DEAD_DEAD;', spawn_block)
		self.assertIn('self->takedamage = DAMAGE_YES;', spawn_block)
		self.assertIn('self->s.frame = FRAME_death132;', spawn_block)
		self.assertIn('tank_dead (self);', spawn_block)
		self.assertNotIn('Monster_SpawnCorpse', spawn_block)

	def test_commander_skin_is_assigned_before_corpse_return(self) -> None:
		spawn_block = extract_function_block(self.source_text, "SP_monster_tank")

		commander_branch = re.search(
			r'if \(strcmp\(self->classname, "monster_tank_commander"\) == 0\)\s*\{(?P<body>.*?)\}\s*else',
			spawn_block,
			re.DOTALL,
		)
		self.assertIsNotNone(commander_branch)
		assert commander_branch is not None
		self.assertIn('self->s.skinnum = 2;', commander_branch.group('body'))


if __name__ == "__main__":
	unittest.main()