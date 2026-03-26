from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parent
CAMERA_SOURCE = REPO_ROOT / "src" / "g_camera.cpp"


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


class CameraRuntimeRegressionTest(unittest.TestCase):
	@classmethod
	def setUpClass(cls) -> None:
		cls.source = CAMERA_SOURCE.read_text(encoding="utf-8")

	def test_start_path_prefers_path_corner_speed(self) -> None:
		block = extract_function_block(self.source, "Camera_StartPath")
		self.assertIn("self->camera_path_speed = Camera_ResolvePathSpeed(start, speed);", block)

	def test_move_step_reads_corner_wait_before_tail_branch(self) -> None:
		block = extract_function_block(self.source, "Camera_MoveStep")
		wait_idx = block.find("self->delay = self->movetarget->wait;")
		remaining_idx = block.find("if (self->camera_path_remaining > 0.0f)")
		self.assertNotEqual(-1, wait_idx)
		self.assertNotEqual(-1, remaining_idx)
		self.assertLess(wait_idx, remaining_idx)

	def test_move_step_updates_next_leg_speed_from_corner(self) -> None:
		block = extract_function_block(self.source, "Camera_MoveStep")
		self.assertIn("if (self->movetarget->speed > 0.0f)", block)
		self.assertIn("next_path_speed = self->movetarget->speed;", block)

	def test_camera_think_handles_stop_markers_after_ready_steps(self) -> None:
		block = extract_function_block(self.source, "Camera_Think")
		run_idx = block.find("Camera_RunReadySteps(self);")
		stop_idx = block.rfind("if (self->delay == CAMERA_PATH_STOPPED)")
		self.assertNotEqual(-1, run_idx)
		self.assertNotEqual(-1, stop_idx)
		self.assertLess(run_idx, stop_idx)

	def test_camera_target_think_handles_stop_markers_after_ready_steps(self) -> None:
		block = extract_function_block(self.source, "Camera_TargetThink")
		run_idx = block.find("Camera_RunReadySteps(self);")
		stop_idx = block.rfind("if (self->delay == CAMERA_PATH_STOPPED)")
		self.assertNotEqual(-1, run_idx)
		self.assertNotEqual(-1, stop_idx)
		self.assertLess(run_idx, stop_idx)

	def test_camera_entities_do_not_spawn_in_deathmatch(self) -> None:
		for function_name in ("SP_misc_camera", "SP_trigger_misc_camera", "SP_misc_camera_target"):
			with self.subTest(function_name=function_name):
				block = extract_function_block(self.source, function_name)
				self.assertIn("if (deathmatch->integer)", block)
				self.assertIn("G_FreeEdict(self);", block)
				self.assertIn("return;", block)


if __name__ == "__main__":
	unittest.main()
