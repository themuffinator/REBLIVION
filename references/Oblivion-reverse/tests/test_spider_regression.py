import json
import re
import struct
from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
SPIDER_SOURCE = REPO_ROOT / "src" / "game" / "m_spider.c"
FIXTURE_PATH = Path(__file__).resolve().parent / "fixtures" / "spider_expected_behaviour.json"
RETAIL_DLL_PATH = REPO_ROOT / "references" / "HLIL" / "oblivion" / "gamex86.dll"

FRAME_DEFINE_RE = re.compile(r"#define\s+(SPIDER_FRAME_[A-Z0-9_]+)\s+([^\s]+)")
MMOVE_RE = re.compile(r"static\s+mmove_t\s+([a-z0-9_]+)\s*=\s*\{\s*([^}]+?)\s*\};", re.DOTALL)
SOUND_SETUP_RE = re.compile(r"sound_([a-z0-9_]+)\s*=\s*gi.soundindex\s*\(\"([^\"]+)\"\);")

SPIDER_RETAIL_FRAME_ARRAYS = {
	"spider_frames_stand": {"address": 0x1005c768, "count": 55},
	"spider_frames_walk": {"address": 0x1005ca10, "count": 10},
	"spider_frames_run1": {"address": 0x1005ca98, "count": 10},
	"spider_frames_run2": {"address": 0x1005cb20, "count": 6},
	"spider_frames_melee_primary": {"address": 0x1005cb78, "count": 5},
	"spider_frames_melee_secondary": {"address": 0x1005cbc8, "count": 7},
	"spider_frames_attack_left": {"address": 0x1005cc30, "count": 5},
	"spider_frames_attack_right": {"address": 0x1005cc80, "count": 5},
	"spider_frames_attack_dual": {"address": 0x1005ccd0, "count": 8},
	"spider_frames_pain1": {"address": 0x1005cd40, "count": 6},
	"spider_frames_pain2": {"address": 0x1005cd98, "count": 8},
	"spider_frames_death1": {"address": 0x1005ce08, "count": 20},
	"spider_frames_death2": {"address": 0x1005cf08, "count": 20},
}

SPIDER_RETAIL_MMOVE_ROOTS = {
	"spider_move_stand": {"address": 0x1005ca00, "frames": "spider_frames_stand"},
	"spider_move_walk": {"address": 0x1005ca88, "frames": "spider_frames_walk"},
	"spider_move_run1": {"address": 0x1005cb10, "frames": "spider_frames_run1"},
	"spider_move_run2": {"address": 0x1005cb68, "frames": "spider_frames_run2"},
	"spider_move_melee_primary": {"address": 0x1005cbb8, "frames": "spider_frames_melee_primary"},
	"spider_move_melee_secondary": {"address": 0x1005cc20, "frames": "spider_frames_melee_secondary"},
	"spider_move_attack_left": {"address": 0x1005cc70, "frames": "spider_frames_attack_left"},
	"spider_move_attack_right": {"address": 0x1005ccc0, "frames": "spider_frames_attack_right"},
	"spider_move_attack_dual": {"address": 0x1005cd30, "frames": "spider_frames_attack_dual"},
	"spider_move_pain1": {"address": 0x1005cd88, "frames": "spider_frames_pain1"},
	"spider_move_pain2": {"address": 0x1005cdf8, "frames": "spider_frames_pain2"},
	"spider_move_death1": {"address": 0x1005cef8, "frames": "spider_frames_death1"},
	"spider_move_death2": {"address": 0x1005cff8, "frames": "spider_frames_death2"},
}

SPIDER_RETAIL_AIFUNCS = {
	0x10001090: "ai_move",
	0x10001220: "ai_stand",
	0x10001350: "ai_walk",
	0x10001430: "ai_charge",
	0x10002530: "ai_run",
}

SPIDER_RETAIL_CALLBACKS = {
	0x1002d570: "spider_charge_start",
	0x1002d610: "spider_charge_end",
	0x1002d410: "spider_melee_swing",
	0x1002d6c0: "spider_melee_hit",
	0x1002d7b0: "spider_rocket_left",
	0x1002d850: "spider_rocket_right",
	0x1002d660: "spider_run",
	0x1002db70: "spider_dead",
}

SPIDER_RETAIL_ROCKET_OFFSETS = {
	"left": 0x1005237c,
	"right": 0x10052388,
}


def load_fixture() -> dict:
	return json.loads(FIXTURE_PATH.read_text(encoding="utf-8"))


def parse_frame_constants(source: str) -> dict[str, int]:
	frames: dict[str, int] = {}
	for macro, raw_value in FRAME_DEFINE_RE.findall(source):
		frames[macro] = int(raw_value, 0)
	return frames


def parse_mmoves(source: str, frames: dict[str, int]) -> dict[str, dict[str, object]]:
	mmoves: dict[str, dict[str, object]] = {}

	def resolve_symbol(symbol: str) -> int:
		symbol = symbol.strip()
		if symbol in frames:
			return frames[symbol]
		if "+" in symbol:
			total = 0
			for part in symbol.split("+"):
				part = part.strip()
				if part in frames:
					total += frames[part]
				else:
					total += int(part, 0)
			return total
		return int(symbol, 0)

	for name, payload in MMOVE_RE.findall(source):
		parts = [part.strip() for part in payload.split(",") if part.strip()]
		if len(parts) < 4:
			continue
		mmoves[name] = {
			"start": resolve_symbol(parts[0]),
			"end": resolve_symbol(parts[1]),
			"endfunc": None if parts[3] == "NULL" else parts[3],
		}
	return mmoves


def extract_function_block(source: str, function_name: str) -> str:
	pattern = re.compile(rf"{function_name}\s*\([^)]*\)\s*\{{", re.MULTILINE)
	match = pattern.search(source)
	if not match:
		raise AssertionError(f"Function {function_name} not found in m_spider.c")
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


def extract_frame_array(source: str, array_name: str) -> list[dict[str, object]]:
	match = re.search(rf"mframe_t\s+{array_name}\[\]\s*=\s*\{{(.*?)\}};", source, re.DOTALL)
	if not match:
		raise AssertionError(f"Frame array {array_name} not found in m_spider.c")

	entries: list[dict[str, object]] = []
	for raw_entry in re.findall(r"\{([^{}]+)\}", match.group(1)):
		parts = [part.strip() for part in raw_entry.split(",")]
		if len(parts) < 2:
			continue
		think = None
		if len(parts) > 2 and parts[2] != "NULL":
			think = parts[2]
		entries.append(
			{
				"aifunc": parts[0],
				"dist": float(parts[1].rstrip("f")),
				"think": think,
			}
		)
	return entries


def extract_project_source_offset(function_block: str) -> list[float]:
	match = re.search(r"tv\(([^)]+)\)", function_block)
	if not match:
		raise AssertionError("No tv() offset found in function block")

	return [float(part.strip().rstrip("f")) for part in match.group(1).split(",")]


class PortableExecutableView:
	def __init__(self, path: Path) -> None:
		self._data = path.read_bytes()
		self._image_base: int | None = None
		self._sections: list[tuple[int, int, int]] = []
		self._parse_headers()

	def _parse_headers(self) -> None:
		e_lfanew = struct.unpack_from("<I", self._data, 0x3C)[0]
		number_of_sections = struct.unpack_from("<H", self._data, e_lfanew + 6)[0]
		optional_header_size = struct.unpack_from("<H", self._data, e_lfanew + 20)[0]
		optional_header_offset = e_lfanew + 24
		section_table_offset = optional_header_offset + optional_header_size

		self._image_base = struct.unpack_from("<I", self._data, optional_header_offset + 28)[0]

		for index in range(number_of_sections):
			section_offset = section_table_offset + (40 * index)
			virtual_size = struct.unpack_from("<I", self._data, section_offset + 8)[0]
			virtual_address = struct.unpack_from("<I", self._data, section_offset + 12)[0]
			raw_size = struct.unpack_from("<I", self._data, section_offset + 16)[0]
			raw_address = struct.unpack_from("<I", self._data, section_offset + 20)[0]
			self._sections.append((virtual_address, max(virtual_size, raw_size), raw_address))

	def va_to_offset(self, address: int) -> int:
		assert self._image_base is not None
		rva = address - self._image_base
		for virtual_address, section_size, raw_address in self._sections:
			if virtual_address <= rva < (virtual_address + section_size):
				return raw_address + (rva - virtual_address)
		raise AssertionError(f"Address {hex(address)} is outside the PE section map")

	def read_u32(self, address: int) -> int:
		return struct.unpack_from("<I", self._data, self.va_to_offset(address))[0]

	def read_f32(self, address: int) -> float:
		return struct.unpack_from("<f", self._data, self.va_to_offset(address))[0]


def decode_retail_spider_binary() -> dict[str, object]:
	if not RETAIL_DLL_PATH.exists():
		raise AssertionError(f"Retail Spider reference DLL not found: {RETAIL_DLL_PATH}")

	image = PortableExecutableView(RETAIL_DLL_PATH)
	mmoves: dict[str, dict[str, object]] = {}
	frame_payloads: dict[str, list[dict[str, object]]] = {}
	rocket_offsets: dict[str, list[float]] = {}

	for name, spec in SPIDER_RETAIL_MMOVE_ROOTS.items():
		address = spec["address"]
		mmoves[name] = {
			"start": image.read_u32(address),
			"end": image.read_u32(address + 4),
			"frames": image.read_u32(address + 8),
			"endfunc": SPIDER_RETAIL_CALLBACKS.get(image.read_u32(address + 12)),
		}

	for name, spec in SPIDER_RETAIL_FRAME_ARRAYS.items():
		address = spec["address"]
		entries: list[dict[str, object]] = []
		for index in range(spec["count"]):
			entry_address = address + (index * 12)
			aifunc_address = image.read_u32(entry_address)
			think_address = image.read_u32(entry_address + 8)
			entries.append(
				{
					"aifunc": SPIDER_RETAIL_AIFUNCS.get(aifunc_address, hex(aifunc_address)),
					"dist": image.read_f32(entry_address + 4),
					"think": SPIDER_RETAIL_CALLBACKS.get(think_address),
				}
			)
		frame_payloads[name] = entries

	for name, address in SPIDER_RETAIL_ROCKET_OFFSETS.items():
		rocket_offsets[name] = [image.read_f32(address + (index * 4)) for index in range(3)]

	return {
		"mmoves": mmoves,
		"frame_payloads": frame_payloads,
		"rocket_offsets": rocket_offsets,
	}


class SpiderRegressionTests(unittest.TestCase):
	@classmethod
	def setUpClass(cls) -> None:
		cls.source_text = SPIDER_SOURCE.read_text(encoding="utf-8")
		cls.fixture = load_fixture()
		cls.frames = parse_frame_constants(cls.source_text)
		cls.mmoves = parse_mmoves(cls.source_text, cls.frames)
		cls.retail = decode_retail_spider_binary()

	def test_mmove_ranges_match_fixture(self) -> None:
		for name, expected in self.fixture["mmoves"].items():
			self.assertIn(name, self.mmoves, f"Missing mmove {name}")
			actual = self.mmoves[name]
			self.assertEqual(actual["start"], expected["start"], f"Start frame mismatch for {name}")
			self.assertEqual(actual["end"], expected["end"], f"End frame mismatch for {name}")
			self.assertEqual(actual["endfunc"], expected["endfunc"], f"Endfunc mismatch for {name}")

	def test_spawn_audio_and_corpse_setup_match_retail(self) -> None:
		sounds: dict[str, list[str]] = {}
		for slot, sound_path in SOUND_SETUP_RE.findall(self.source_text):
			sounds.setdefault(slot, []).append(sound_path)

		audio_fixture = self.fixture["audio"]
		self.assertEqual(sounds.get("step", [None])[0], audio_fixture["step"])
		self.assertEqual(sounds.get("idle", [None])[0], audio_fixture["idle"])
		self.assertEqual(sounds.get("search", [None])[0], audio_fixture["search"])
		self.assertEqual(sounds.get("sight"), audio_fixture["sight_sequence"])

		pain_paths = sounds.get("pain1", []) + sounds.get("pain2", [])
		for path in audio_fixture["pain"]:
			self.assertIn(path, pain_paths, "Pain table missing expected clip")

		melee_paths = (
			sounds.get("melee1", [])
			+ sounds.get("melee2", [])
			+ sounds.get("melee3", [])
		)
		for path in audio_fixture["melee"]:
			self.assertIn(path, melee_paths, "Melee table missing expected clip")

		spawn_block = extract_function_block(self.source_text, "SP_monster_spider")
		self.assertIn('self->s.modelindex = gi.modelindex("models/monsters/spider/tris.md2");', spawn_block)
		self.assertIn("VectorSet(self->mins, -32.0f, -32.0f, -35.0f);", spawn_block)
		self.assertIn("VectorSet(self->maxs, 32.0f, 32.0f, 32.0f);", spawn_block)
		self.assertIn("self->health = 400;", spawn_block)
		self.assertIn("self->gib_health = -175;", spawn_block)
		self.assertIn("self->mass = 300;", spawn_block)
		self.assertIn("if (self->spawnflags & SPAWNFLAG_CORPSE)", spawn_block)
		self.assertIn("self->s.skinnum |= 1;", spawn_block)
		self.assertIn("VectorSet(self->mins, -32.0f, -32.0f, -30.0f);", spawn_block)
		self.assertIn("VectorSet(self->maxs, 32.0f, 32.0f, 0.0f);", spawn_block)
		self.assertIn("self->monsterinfo.dodge = NULL;", spawn_block)
		self.assertIn("self->monsterinfo.checkattack = spider_checkattack;", spawn_block)
		self.assertIn("self->monsterinfo.currentmove = &spider_move_stand;", spawn_block)
		self.assertIn("self->monsterinfo.scale = MODEL_SCALE;", spawn_block)
		self.assertIn("walkmonster_start(self);", spawn_block)

	def test_recovered_frame_payloads_match_retail_mapping(self) -> None:
		for array_name, expected in self.fixture["frame_payloads"].items():
			entries = extract_frame_array(self.source_text, array_name)
			self.assertEqual(
				[entry["aifunc"] for entry in entries],
				[expected["aifunc"]] * len(expected["distances"]),
				f"Ai callback mismatch for {array_name}",
			)
			self.assertEqual(
				[entry["dist"] for entry in entries],
				expected["distances"],
				f"Distance payload mismatch for {array_name}",
			)
			self.assertEqual(
				[entry["think"] for entry in entries],
				expected["hooks"],
				f"Think hook mismatch for {array_name}",
			)

	def test_retail_dll_move_roots_match_source_reconstruction(self) -> None:
		for name, retail_move in self.retail["mmoves"].items():
			self.assertIn(name, self.mmoves, f"Source mmove missing retail root {name}")
			self.assertEqual(self.mmoves[name]["start"], retail_move["start"], f"Retail start mismatch for {name}")
			self.assertEqual(self.mmoves[name]["end"], retail_move["end"], f"Retail end mismatch for {name}")
			self.assertEqual(self.mmoves[name]["endfunc"], retail_move["endfunc"], f"Retail endfunc mismatch for {name}")
			self.assertEqual(
				retail_move["frames"],
				SPIDER_RETAIL_FRAME_ARRAYS[SPIDER_RETAIL_MMOVE_ROOTS[name]["frames"]]["address"],
				f"Retail frame pointer mismatch for {name}",
			)
			self.assertEqual(
				self.fixture["mmoves"][name]["start"],
				retail_move["start"],
				f"Fixture start drifted from retail for {name}",
			)
			self.assertEqual(
				self.fixture["mmoves"][name]["end"],
				retail_move["end"],
				f"Fixture end drifted from retail for {name}",
			)
			self.assertEqual(
				self.fixture["mmoves"][name]["endfunc"],
				retail_move["endfunc"],
				f"Fixture endfunc drifted from retail for {name}",
			)

	def test_retail_dll_frame_payloads_and_offsets_match_source_reconstruction(self) -> None:
		for array_name, retail_entries in self.retail["frame_payloads"].items():
			source_entries = extract_frame_array(self.source_text, array_name)
			self.assertEqual(source_entries, retail_entries, f"Retail DLL payload mismatch for {array_name}")
			self.assertEqual(
				[entry["dist"] for entry in retail_entries],
				self.fixture["frame_payloads"][array_name]["distances"],
				f"Fixture distances drifted from retail for {array_name}",
			)
			self.assertEqual(
				[entry["think"] for entry in retail_entries],
				self.fixture["frame_payloads"][array_name]["hooks"],
				f"Fixture hooks drifted from retail for {array_name}",
			)

		self.assertEqual(
			self.retail["rocket_offsets"]["left"],
			self.fixture["rocket_offsets"]["left"],
			"Fixture left rocket offset drifted from retail",
		)
		self.assertEqual(
			self.retail["rocket_offsets"]["right"],
			self.fixture["rocket_offsets"]["right"],
			"Fixture right rocket offset drifted from retail",
		)

	def test_charge_and_attack_control_flow_match_recovered_source(self) -> None:
		charge_start_block = extract_function_block(self.source_text, "spider_charge_start")
		charge_think_block = extract_function_block(self.source_text, "spider_charge_think")
		charge_end_block = extract_function_block(self.source_text, "spider_charge_end")
		attack_block = extract_function_block(self.source_text, "spider_attack")
		checkattack_block = extract_function_block(self.source_text, "spider_checkattack")
		rocket_left_block = extract_function_block(self.source_text, "spider_rocket_left")
		rocket_right_block = extract_function_block(self.source_text, "spider_rocket_right")
		spawn_block = extract_function_block(self.source_text, "SP_monster_spider")

		self.assertIn("self->s.origin[2] += 1.0f;", charge_start_block)
		self.assertIn("VectorScale(forward, SPIDER_CHARGE_SPEED, self->velocity);", charge_start_block)
		self.assertIn("self->velocity[2] = SPIDER_CHARGE_Z_SPEED;", charge_start_block)
		self.assertIn("self->groundentity = NULL;", charge_start_block)
		self.assertIn("self->monsterinfo.aiflags |= AI_DUCKED;", charge_start_block)
		self.assertIn("self->touch = spider_charge_think;", charge_start_block)
		self.assertIn("self->monsterinfo.attack_finished = level.time + 3.0f;", charge_start_block)

		self.assertIn("(void)plane;", charge_think_block)
		self.assertIn("(void)surf;", charge_think_block)
		self.assertIn("VectorLength(self->velocity) > SPIDER_CHARGE_IMPACT_SPEED", charge_think_block)
		self.assertIn("damage = (rand() % SPIDER_CHARGE_DAMAGE_RANGE) + SPIDER_CHARGE_DAMAGE_BASE;", charge_think_block)
		self.assertIn("self->monsterinfo.nextframe = SPIDER_FRAME_RUN1_START + 3;", charge_think_block)
		self.assertIn("self->touch = NULL;", charge_think_block)

		self.assertIn("gi.sound(self, CHAN_WEAPON, sound_step, 1.0f, ATTN_NORM, 0.0f);", charge_end_block)
		self.assertIn("self->monsterinfo.attack_finished = 0.0f;", charge_end_block)
		self.assertIn("self->monsterinfo.aiflags &= ~AI_DUCKED;", charge_end_block)

		self.assertIn("VectorLength(delta) <= SPIDER_ATTACK_MIN_RANGE", attack_block)
		self.assertIn("self->monsterinfo.currentmove = &spider_move_attack_left;", attack_block)
		self.assertIn("self->monsterinfo.currentmove = &spider_move_attack_right;", attack_block)
		self.assertIn("self->monsterinfo.currentmove = &spider_move_attack_dual;", attack_block)
		self.assertEqual(
			extract_project_source_offset(rocket_left_block),
			self.fixture["rocket_offsets"]["left"],
		)
		self.assertEqual(
			extract_project_source_offset(rocket_right_block),
			self.fixture["rocket_offsets"]["right"],
		)
		self.assertIn("SPIDER_MZ_LEFT", rocket_left_block)
		self.assertIn("SPIDER_MZ_RIGHT", rocket_right_block)

		self.assertIn("(void)infront(self, self->enemy);", checkattack_block)
		self.assertIn("CONTENTS_SOLID | CONTENTS_MONSTER | CONTENTS_SLIME |", checkattack_block)
		self.assertIn("CONTENTS_LAVA", checkattack_block)
		self.assertIn("CONTENTS_WINDOW", checkattack_block)
		self.assertIn("self->monsterinfo.attack_state = AS_MELEE;", checkattack_block)
		self.assertIn("self->monsterinfo.attack_state = AS_MISSILE;", checkattack_block)
		self.assertIn("self->monsterinfo.attack_finished = level.time + 2.0f * random();", checkattack_block)
		self.assertIn("self->monsterinfo.attack_state = AS_SLIDING;", checkattack_block)
		self.assertIn("self->monsterinfo.attack_state = AS_STRAIGHT;", checkattack_block)
		self.assertLess(
			spawn_block.index("self->monsterinfo.stand = spider_stand;"),
			spawn_block.index("self->monsterinfo.idle = spider_idle;"),
		)
		self.assertLess(
			spawn_block.rindex("gi.linkentity(self);"),
			spawn_block.index("self->monsterinfo.currentmove = &spider_move_stand;"),
		)
		self.assertLess(
			spawn_block.index("self->monsterinfo.scale = MODEL_SCALE;"),
			spawn_block.index("self->monsterinfo.checkattack = spider_checkattack;"),
		)
		self.assertLess(
			spawn_block.index("self->monsterinfo.checkattack = spider_checkattack;"),
			spawn_block.index("walkmonster_start(self);"),
		)

	def test_pain_logic_matches_recovered_branch_order(self) -> None:
		pain_block = extract_function_block(self.source_text, "spider_pain")

		self.assertIn("(void)other;", pain_block)
		self.assertIn("(void)kick;", pain_block)
		self.assertIn("self->pain_debounce_time = level.time + 3.0f;", pain_block)
		self.assertIn("if (random() >= 0.5f)", pain_block)
		self.assertIn("if (skill->value == 3 && random() < 0.1f)", pain_block)
		self.assertIn("if (damage < 10 && random() < 0.2f)", pain_block)
		self.assertIn("if (damage < 50 && random() < 0.5f)", pain_block)
		self.assertNotIn("level.time < self->pain_debounce_time", pain_block)
		self.assertNotIn("pain_debounce_time - 3.0f", pain_block)

	def test_die_and_melee_paths_match_retail_structure(self) -> None:
		melee_block = extract_function_block(self.source_text, "spider_melee")
		die_block = extract_function_block(self.source_text, "spider_die")
		dead_block = extract_function_block(self.source_text, "spider_dead")

		self.assertIn('gi.bprintf(PRINT_MEDIUM, "spider_melee\\n");', melee_block)
		self.assertIn("if (random() < 0.5f)", melee_block)
		self.assertIn("self->monsterinfo.currentmove = &spider_move_melee_primary;", melee_block)
		self.assertIn("self->monsterinfo.currentmove = &spider_move_melee_secondary;", melee_block)

		self.assertIn("(void)inflictor;", die_block)
		self.assertIn("(void)attacker;", die_block)
		self.assertIn("(void)point;", die_block)
		self.assertIn("meansOfDeath == 0x23", die_block)
		self.assertIn("BecomeExplosion1(self);", die_block)
		self.assertIn('gi.sound(self, CHAN_VOICE, gi.soundindex("misc/udeath.wav"), 1.0f,', die_block)
		self.assertIn('ThrowGib(self, "models/objects/gibs/sm_meat/tris.md2", damage,', die_block)
		self.assertIn('ThrowGib(self, "models/objects/gibs/sm_metal/tris.md2", damage,', die_block)
		self.assertIn('ThrowHead(self, "models/objects/gibs/head2/tris.md2", damage,', die_block)
		self.assertIn("self->monsterinfo.currentmove = &spider_move_death1;", die_block)
		self.assertIn("self->monsterinfo.currentmove = &spider_move_death2;", die_block)

		self.assertIn("VectorSet(self->mins, -32.0f, -32.0f, -30.0f);", dead_block)
		self.assertIn("VectorSet(self->maxs, 32.0f, 32.0f, 0.0f);", dead_block)
		self.assertIn("self->movetype = MOVETYPE_TOSS;", dead_block)
		self.assertIn("self->svflags |= SVF_DEADMONSTER;", dead_block)
		self.assertIn("self->nextthink = 0.0f;", dead_block)
		self.assertIn("gi.linkentity(self);", dead_block)

	def test_retail_negative_evidence_rules_out_legacy_scaffolding(self) -> None:
		charge_end_block = extract_function_block(self.source_text, "spider_charge_end")

		self.assertNotIn("static void spider_step(", self.source_text)
		self.assertNotIn("static void spider_rocket(", self.source_text)
		self.assertNotIn("spider_step", self.source_text)
		self.assertIn("sound_step", charge_end_block)


if __name__ == "__main__":
	unittest.main()
