import json
import re
from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
KIGRAX_SOURCE = REPO_ROOT / "src" / "game" / "m_kigrax.c"
FIXTURE_PATH = Path(__file__).resolve().parent / "fixtures" / "kigrax_expected_spawn.json"

FRAME_DEFINE_RE = re.compile(r"#define\s+(KIGRAX_FRAME_[A-Z0-9_]+)\s+([^\s]+)")
ENUM_FRAME_RE = re.compile(r"(KIGRAX_FRAME_[A-Z0-9_]+)\s*=\s*([^,\n]+)")
MMOVE_RE = re.compile(
    r"static\s+mmove_t\s+([a-z0-9_]+)\s*=\s*\{\s*([^}]+?)\s*\};",
    re.DOTALL,
)
FRAME_ARRAY_RE = re.compile(
    r"static\s+mframe_t\s+(kigrax_frames_[a-z0-9_]+)\s*\[\]\s*=\s*\{\s*(.*?)\s*\};",
    re.DOTALL,
)
FRAME_ENTRY_RE = re.compile(
    r"\{\s*([a-z0-9_]+)\s*,\s*([-+0-9.]+f?)\s*,\s*([a-z0-9_]+|NULL)\s*\}",
    re.IGNORECASE,
)
VECTOR_SET_RE = re.compile(
    r"VectorSet\s*\(\s*self->(mins|maxs)\s*,\s*([-+0-9.]+)f?\s*,\s*([-+0-9.]+)f?\s*,\s*([-+0-9.]+)f?\s*\)\s*;",
    re.IGNORECASE,
)
MOVETYPE_MAP = {
    "MOVETYPE_STEP": 5.0,
}


def load_spawn_fixture() -> dict:
    return json.loads(FIXTURE_PATH.read_text(encoding="utf-8"))


def parse_frame_constants(source: str) -> dict:
    frames: dict[str, int] = {}
    for macro, raw_value in FRAME_DEFINE_RE.findall(source):
        if raw_value.lower().startswith("0x"):
            frames[macro] = int(raw_value, 16)
        else:
            frames[macro] = int(raw_value)
    for macro, raw_value in ENUM_FRAME_RE.findall(source):
        cleaned = raw_value.strip()
        if cleaned.lower().startswith("0x"):
            frames[macro] = int(cleaned, 16)
        else:
            frames[macro] = int(cleaned)
    return frames


def parse_mmoves(source: str, frames: dict) -> dict:
    mmoves: dict[str, dict[str, object]] = {}
    for name, payload in MMOVE_RE.findall(source):
        parts = [part.strip() for part in payload.split(",") if part.strip()]
        if len(parts) < 4:
            continue
        start_symbol, end_symbol = parts[0], parts[1]
        start_value = frames.get(start_symbol, None)
        end_value = frames.get(end_symbol, None)
        if start_value is None:
            start_value = int(start_symbol, 0)
        if end_value is None:
            end_value = int(end_symbol, 0)
        mmoves[name] = {
            "start": start_value,
            "end": end_value,
            "frame_array": parts[2],
            "endfunc": parts[3],
        }
    return mmoves


def parse_frame_arrays(source: str) -> dict:
    frame_arrays: dict[str, list[dict[str, object]]] = {}
    for name, body in FRAME_ARRAY_RE.findall(source):
        entries: list[dict[str, object]] = []
        for aifunc, dist_raw, thinkfunc in FRAME_ENTRY_RE.findall(body):
            entries.append(
                {
                    "aifunc": aifunc,
                    "dist": float(dist_raw.rstrip("f")),
                    "thinkfunc": thinkfunc,
                }
            )
        frame_arrays[name] = entries
    return frame_arrays


def extract_function_block(source: str, function_name: str) -> str:
    pattern = re.compile(rf"{function_name}\s*\([^)]*\)\s*\{{", re.MULTILINE)
    match = pattern.search(source)
    if not match:
        raise AssertionError(f"Function {function_name} not found in m_kigrax.c")
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


def extract_spawn_defaults(source: str) -> dict[str, float]:
    block = extract_function_block(source, "SP_monster_kigrax")
    defaults: dict[str, float] = {}
    for match in VECTOR_SET_RE.finditer(block):
        vec_name = match.group(1).lower()
        values = [float(part) for part in match.groups()[1:]]
        if vec_name == "mins":
            offsets = ("offset_0xbc", "offset_0xc0", "offset_0xc4")
        else:
            offsets = ("offset_0xc8", "offset_0xcc", "offset_0xd0")
        for offset, value in zip(offsets, values):
            defaults[offset] = value

    movetype_match = re.search(r"self->movetype\s*=\s*(MOVETYPE_[A-Z_]+)", block)
    if movetype_match:
        key = movetype_match.group(1)
        defaults["offset_0xf8"] = MOVETYPE_MAP.get(key, float("nan"))

    yaw_match = re.search(r"self->yaw_speed\s*=\s*([-+0-9.]+f?|KIGRAX_YAW_SPEED)", block)
    if yaw_match:
        raw = yaw_match.group(1)
        if raw == "KIGRAX_YAW_SPEED":
            value_match = re.search(r"#define\s+KIGRAX_YAW_SPEED\s+([-+0-9.]+)", source)
            if not value_match:
                raise AssertionError("KIGRAX_YAW_SPEED define missing from m_kigrax.c")
            defaults["offset_0x1e4"] = float(value_match.group(1))
        else:
            defaults["offset_0x1e4"] = float(raw.rstrip("f"))

    viewheight_match = re.search(r"self->viewheight\s*=\s*([-+0-9.]+)", block)
    if viewheight_match:
        defaults["offset_0x23c"] = float(viewheight_match.group(1))

    return defaults


class KigraxSpawnManifestRegression(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.source_text = KIGRAX_SOURCE.read_text(encoding="utf-8")
        cls.fixture = load_spawn_fixture()
        cls.frame_constants = parse_frame_constants(cls.source_text)
        cls.mmoves = parse_mmoves(cls.source_text, cls.frame_constants)
        cls.frame_arrays = parse_frame_arrays(cls.source_text)

    def test_spawn_defaults_match_fixture(self) -> None:
        expected = self.fixture["defaults"]
        parsed = extract_spawn_defaults(self.source_text)
        for key, expected_value in expected.items():
            self.assertIn(key, parsed, f"Missing spawn default {key}")
            self.assertAlmostEqual(
                parsed[key],
                expected_value,
                places=3,
                msg=f"Spawn default {key} diverged from retail Kigrax fixture",
            )

    def test_mmove_sequences_match_fixture(self) -> None:
        expected_sequences = self.fixture["mmoves"]
        for mmove_name, expected_payload in expected_sequences.items():
            self.assertIn(mmove_name, self.mmoves, f"Missing mmove {mmove_name}")
            actual = self.mmoves[mmove_name]
            self.assertEqual(actual["start"], expected_payload["start"])
            self.assertEqual(actual["end"], expected_payload["end"])

    def test_move_timeline_matches_symbol_map_order(self) -> None:
        ordered = [
            "kigrax_move_stand",
            "kigrax_move_scan",
            "kigrax_move_walk1",
            "kigrax_move_walk2",
            "kigrax_move_sight",
            "kigrax_move_run",
            "kigrax_move_pain",
            "kigrax_move_death",
            "kigrax_move_melee1",
            "kigrax_move_melee2",
            "kigrax_move_attack",
        ]
        last_end = -1
        for name in ordered:
            self.assertIn(name, self.mmoves, f"Missing mmove {name}")
            actual = self.mmoves[name]
            self.assertGreater(
                actual["start"],
                last_end,
                f"{name} no longer follows the prior Kigrax move window",
            )
            last_end = actual["end"]

    def test_prebuilt_frame_payloads_match_fixture(self) -> None:
        expected_sequences = self.fixture["mmoves"]
        for mmove_name, expected_payload in expected_sequences.items():
            actual = self.mmoves[mmove_name]
            self.assertEqual(actual["frame_array"], expected_payload["frame_array"])
            self.assertEqual(actual["endfunc"], expected_payload["endfunc"])

            frame_array_name = actual["frame_array"]
            self.assertIn(frame_array_name, self.frame_arrays)
            entries = self.frame_arrays[frame_array_name]
            self.assertEqual(
                len(entries),
                expected_payload["end"] - expected_payload["start"] + 1,
                f"{frame_array_name} frame count diverged from retail Kigrax",
            )

            hook_map = expected_payload["hooks"]
            for index, entry in enumerate(entries):
                frame_number = expected_payload["start"] + index
                expected_thinkfunc = hook_map.get(str(frame_number), "NULL")
                self.assertEqual(entry["aifunc"], expected_payload["aifunc"])
                self.assertAlmostEqual(entry["dist"], expected_payload["dist"], places=3)
                self.assertEqual(entry["thinkfunc"], expected_thinkfunc)

    def test_runtime_scaffolding_removed(self) -> None:
        self.assertNotIn("kigrax_seed_frames", self.source_text)
        self.assertNotIn("kigrax_init_moves", self.source_text)


class KigraxBehaviorRegression(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.source_text = KIGRAX_SOURCE.read_text(encoding="utf-8")

    def test_walk_and_run_keep_retail_debug_strings(self) -> None:
        walk_block = extract_function_block(self.source_text, "kigrax_walk")
        run_block = extract_function_block(self.source_text, "kigrax_run")
        self.assertIn('gi.dprintf("walking...\\n");', walk_block)
        self.assertIn('gi.dprintf("running...\\n");', run_block)

    def test_attack_and_melee_dispatchers_install_retail_moves(self) -> None:
        attack_block = extract_function_block(self.source_text, "kigrax_attack")
        melee_block = extract_function_block(self.source_text, "kigrax_melee")
        self.assertIn("self->monsterinfo.currentmove = &kigrax_move_attack;", attack_block)
        self.assertIn("self->monsterinfo.currentmove = &kigrax_move_run;", melee_block)
        self.assertIn("self->monsterinfo.currentmove = &kigrax_move_melee1;", melee_block)
        self.assertIn("self->monsterinfo.currentmove = &kigrax_move_melee2;", melee_block)


class KigraxPainDeathRegression(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.source_text = KIGRAX_SOURCE.read_text(encoding="utf-8")

    def test_pain_matches_retail_cooldown_and_voice(self) -> None:
        pain_block = extract_function_block(self.source_text, "kigrax_pain")
        self.assertRegex(
            pain_block,
            r"pain_debounce_time\s*=\s*level\.time\s*\+\s*KIGRAX_PAIN_COOLDOWN",
        )
        self.assertIn("if (skill->value == 3)", pain_block)
        self.assertIn("sound_pain", pain_block)
        self.assertNotIn("sound_pain_strong", pain_block)
        self.assertIn("self->monsterinfo.currentmove = &kigrax_move_pain;", pain_block)

    def test_dead_cleanup_matches_retail_corpse_state(self) -> None:
        dead_block = extract_function_block(self.source_text, "kigrax_dead")
        self.assertIn("VectorSet(self->mins, -16.0f, -16.0f, -16.0f);", dead_block)
        self.assertIn("VectorSet(self->maxs, 16.0f, 16.0f, 0.0f);", dead_block)
        self.assertIn("self->movetype = MOVETYPE_TOSS;", dead_block)
        self.assertIn("self->svflags |= SVF_DEADMONSTER;", dead_block)
        self.assertIn("self->nextthink = 0.0f;", dead_block)

    def test_die_keeps_disintegration_and_direct_death_move(self) -> None:
        die_block = extract_function_block(self.source_text, "kigrax_die")
        self.assertIn("meansOfDeath == 0x23", die_block)
        self.assertIn("BecomeExplosion1(self);", die_block)
        self.assertIn("self->takedamage = DAMAGE_YES;", die_block)
        self.assertIn("self->monsterinfo.currentmove = &kigrax_move_death;", die_block)


class KigraxFireSpawnRegression(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.source_text = KIGRAX_SOURCE.read_text(encoding="utf-8")

    def test_fire_plasma_matches_recovered_geometry(self) -> None:
        fire_block = extract_function_block(self.source_text, "kigrax_fire_plasma")
        self.assertIn(
            "G_ProjectSource(self->s.origin, kigrax_plasma_offset, forward, right, start);",
            fire_block,
        )
        self.assertIn("target[2] += self->enemy->viewheight;", fire_block)
        self.assertIn(
            "fire_plasma_bolt(self, start, dir, KIGRAX_PLASMA_DAMAGE, KIGRAX_PLASMA_SPEED,",
            fire_block,
        )
        self.assertIn("gi.WriteByte(KIGRAX_PLASMA_FLASH);", fire_block)

    def test_spawn_wires_retail_callbacks_and_defaults(self) -> None:
        spawn_block = extract_function_block(self.source_text, "SP_monster_kigrax")
        self.assertNotIn("kigrax_init_moves();", spawn_block)
        self.assertIn('sound_death = gi.soundindex("hover/hovdeth1.wav");', spawn_block)
        self.assertIn('sound_search1 = gi.soundindex("hover/hovsrch1.wav");', spawn_block)
        self.assertIn('sound_search2 = gi.soundindex("hover/hovsrch2.wav");', spawn_block)
        self.assertIn('sound_attack = gi.soundindex("chick/chkatck3.wav");', spawn_block)
        self.assertIn('gi.soundindex("kigrax/hovatck1.wav");', spawn_block)
        self.assertIn('sound_idle = gi.soundindex("kigrax/hovidle1.wav");', spawn_block)
        self.assertIn("self->yaw_speed = KIGRAX_YAW_SPEED;", spawn_block)
        self.assertIn("self->monsterinfo.melee = kigrax_melee;", spawn_block)
        self.assertIn("self->monsterinfo.currentmove = &kigrax_move_stand;", spawn_block)


if __name__ == "__main__":
    unittest.main()
