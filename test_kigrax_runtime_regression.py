from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parent
KIGRAX_SOURCE = REPO_ROOT / "src" / "m_kigrax.cpp"


def extract_function_block(source: str, function_name: str) -> str:
	search_start = 0
	match = None
	while True:
		idx = source.find(function_name, search_start)
		if idx == -1:
			raise AssertionError(f"Function {function_name} not found")
		brace_idx = source.find("{", idx)
		semi_idx = source.find(";", idx)
		if brace_idx != -1 and (semi_idx == -1 or brace_idx < semi_idx):
			match = idx
			start = brace_idx + 1
			break
		search_start = idx + len(function_name)

	depth = 1
	idx = start
	while idx < len(source) and depth > 0:
		char = source[idx]
		if char == "{":
			depth += 1
		elif char == "}":
			depth -= 1
		idx += 1

	return source[match:idx]


class KigraxRuntimeRegressionTest(unittest.TestCase):
	@classmethod
	def setUpClass(cls) -> None:
		cls.source = KIGRAX_SOURCE.read_text(encoding="utf-8")

	def test_death_move_finishes_with_explosion_callback(self) -> None:
		self.assertIn("MMOVE_T(kigrax_move_death) = { KIGRAX_FRAME_DEATH_FIRST, KIGRAX_FRAME_DEATH_LAST, kigrax_frames_death, kigrax_explode };", self.source)

	def test_kigrax_explode_uses_standard_explosion_cleanup(self) -> None:
		block = extract_function_block(self.source, "kigrax_explode")
		self.assertIn("BecomeExplosion1(self);", block)

	def test_regular_death_plays_sound_and_enters_exploding_death_move(self) -> None:
		block = extract_function_block(self.source, "kigrax_die")
		self.assertIn("gi.sound(self, CHAN_VOICE, sound_death, 1, ATTN_NORM, 0);", block)
		self.assertIn("M_SetAnimation(self, &kigrax_move_death);", block)


if __name__ == "__main__":
	unittest.main()
