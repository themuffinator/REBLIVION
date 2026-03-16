import json
import re
from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
CYBORG_SOURCE = REPO_ROOT / "src" / "game" / "m_cyborg.c"
MONSTER_SOURCE = REPO_ROOT / "src" / "game" / "g_monster.c"
FIXTURE_PATH = Path(__file__).resolve().parent / "fixtures" / "cyborg_expected_behaviour.json"

ENUM_FRAME_RE = re.compile(r"(FRAME_[A-Za-z0-9_]+)\s*=\s*([^,\n]+)")
MMOVE_RE = re.compile(
    r"mmove_t\s+([a-z0-9_]+)\s*=\s*\{\s*([^}]+?)\s*\};",
    re.DOTALL,
)
SOUND_SETUP_RE = re.compile(r"sound_([a-z0-9_]+)\s*=\s*gi.soundindex\s*\(\"([^\"]+)\"\);")
VECTOR_SET_RE = re.compile(
    r"VectorSet\s*\(\s*self->(mins|maxs)\s*,\s*([-+0-9.]+)f?\s*,\s*([-+0-9.]+)f?\s*,\s*([-+0-9.]+)f?\s*\)\s*;"
)


def load_fixture() -> dict:
    return json.loads(FIXTURE_PATH.read_text(encoding="utf-8"))


def parse_frame_constants(source: str) -> dict[str, int]:
    frames: dict[str, int] = {}
    for name, raw_value in ENUM_FRAME_RE.findall(source):
        cleaned = raw_value.strip()
        if cleaned.lower().startswith("0x"):
            frames[name] = int(cleaned, 16)
        else:
            frames[name] = int(cleaned)
    return frames


def parse_mmoves(source: str, frames: dict[str, int]) -> dict[str, dict[str, int]]:
    mmoves: dict[str, dict[str, int]] = {}

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
        if len(parts) < 2:
            continue
        mmoves[name] = {
            "start": resolve_symbol(parts[0]),
            "end": resolve_symbol(parts[1]),
        }
    return mmoves


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


def extract_frame_array(source: str, array_name: str) -> list[dict[str, object]]:
    pattern = re.compile(
        rf"mframe_t\s+{array_name}\[\]\s*=\s*\{{(.*?)\}};",
        re.DOTALL,
    )
    match = pattern.search(source)
    if not match:
        raise AssertionError(f"Frame array {array_name} not found")

    body = match.group(1)
    entries: list[dict[str, object]] = []
    for raw_entry in re.findall(r"\{([^{}]+)\}", body):
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


def parse_vectors(block: str) -> dict[str, list[float]]:
    vectors: dict[str, list[float]] = {}
    for match in VECTOR_SET_RE.finditer(block):
        vectors[match.group(1)] = [float(part) for part in match.groups()[1:]]
    return vectors


class CyborgRegressionTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.source_text = CYBORG_SOURCE.read_text(encoding="utf-8")
        cls.monster_source_text = MONSTER_SOURCE.read_text(encoding="utf-8")
        cls.fixture = load_fixture()
        cls.frames = parse_frame_constants(cls.source_text)
        cls.mmoves = parse_mmoves(cls.source_text, cls.frames)

    def test_mmove_ranges_match_fixture(self) -> None:
        for name, expected in self.fixture["mmoves"].items():
            self.assertIn(name, self.mmoves, f"Missing mmove {name}")
            actual = self.mmoves[name]
            self.assertEqual(actual["start"], expected["start"], f"Start frame mismatch for {name}")
            self.assertEqual(actual["end"], expected["end"], f"End frame mismatch for {name}")

    def test_spawn_audio_and_hulls_match_fixture(self) -> None:
        sounds: dict[str, list[str]] = {}
        for slot, sound_path in SOUND_SETUP_RE.findall(self.source_text):
            sounds.setdefault(slot, []).append(sound_path)

        audio = self.fixture["audio"]
        self.assertEqual(sounds.get("attack1", [None])[0], audio["attack"][0])
        self.assertEqual(sounds.get("attack2", [None])[0], audio["attack"][1])
        self.assertEqual(sounds.get("attack3", [None])[0], audio["attack"][2])
        self.assertEqual(sounds.get("death", [None])[0], audio["death"])
        self.assertEqual(sounds.get("idle", [None])[0], audio["idle"])
        self.assertEqual(sounds.get("sight", [None])[0], audio["sight"])
        self.assertEqual(sounds.get("search", [None])[0], audio["search"])
        self.assertEqual(sounds.get("pain1", [None])[0], audio["pain"][0])
        self.assertEqual(sounds.get("pain2", [None])[0], audio["pain"][1])
        self.assertEqual(sounds.get("step1", [None])[0], audio["steps"][0])
        self.assertEqual(sounds.get("step2", [None])[0], audio["steps"][1])
        self.assertEqual(sounds.get("step3", [None])[0], audio["steps"][2])
        self.assertEqual(sounds.get("thud", [None])[0], audio["thud"])

        spawn_vectors = parse_vectors(extract_function_block(self.source_text, "SP_monster_cyborg"))
        corpse_vectors = parse_vectors(extract_function_block(self.source_text, "cyborg_dead"))
        self.assertEqual(spawn_vectors.get("mins"), self.fixture["spawn"]["mins"])
        self.assertEqual(spawn_vectors.get("maxs"), self.fixture["spawn"]["maxs"])
        self.assertEqual(corpse_vectors.get("mins"), self.fixture["corpse"]["mins"])
        self.assertEqual(corpse_vectors.get("maxs"), self.fixture["corpse"]["maxs"])

        spawn_block = extract_function_block(self.source_text, "SP_monster_cyborg")
        self.assertIn("self->health = 300;", spawn_block)
        self.assertIn("self->gib_health = -120;", spawn_block)
        self.assertIn("self->mass = 300;", spawn_block)
        self.assertIn("self->monsterinfo.dodge = NULL;", spawn_block)
        self.assertNotIn("self->monsterinfo.power_armor_type", spawn_block)
        self.assertNotIn("self->monsterinfo.power_armor_power", spawn_block)
        self.assertLess(
            spawn_block.index("self->monsterinfo.stand = cyborg_stand;"),
            spawn_block.index("self->monsterinfo.walk = cyborg_walk;"),
            "Spawn callback order no longer matches the recovered retail stand -> walk wiring",
        )
        self.assertLess(
            spawn_block.index("self->monsterinfo.walk = cyborg_walk;"),
            spawn_block.index("self->monsterinfo.run = cyborg_run;"),
            "Spawn callback order no longer matches the recovered retail walk -> run wiring",
        )
        self.assertLess(
            spawn_block.index("self->monsterinfo.run = cyborg_run;"),
            spawn_block.index("self->monsterinfo.dodge = NULL;"),
            "Retail spawn clears dodge after the run callback write",
        )
        self.assertLess(
            spawn_block.index("self->monsterinfo.attack = cyborg_attack;"),
            spawn_block.index("self->monsterinfo.melee = cyborg_melee;"),
            "Retail spawn writes attack before melee",
        )
        self.assertLess(
            spawn_block.index("self->monsterinfo.melee = cyborg_melee;"),
            spawn_block.index("self->monsterinfo.sight = cyborg_sight;"),
            "Retail spawn wires sight after the attack and melee callbacks",
        )
        self.assertLess(
            spawn_block.index("self->monsterinfo.sight = cyborg_sight;"),
            spawn_block.index("self->monsterinfo.search = cyborg_search;"),
            "Retail spawn wires search after sight",
        )
        self.assertLess(
            spawn_block.index("self->monsterinfo.search = cyborg_search;"),
            spawn_block.index("self->monsterinfo.idle = cyborg_idle;"),
            "Retail spawn wires idle after search",
        )
        self.assertLess(
            spawn_block.index("self->monsterinfo.currentmove = &cyborg_move_stand;"),
            spawn_block.index("self->monsterinfo.scale = MODEL_SCALE;"),
            "Retail spawn seeds the stand move before writing monster scale",
        )
        self.assertIn(
            "/*QUAKED monster_cyborg (1 .5 0) (-16 -16 -38) (16 16 27) Ambush Trigger_Spawn",
            self.source_text,
        )

    def test_retail_frame_payloads_match_selected_mapping(self) -> None:
        expected_arrays = {
            "cyborg_frames_walk": [
                {"aifunc": "ai_walk", "dist": 12.0, "think": None},
                {"aifunc": "ai_walk", "dist": 2.0, "think": None},
                {"aifunc": "ai_walk", "dist": 2.0, "think": None},
                {"aifunc": "ai_walk", "dist": 2.0, "think": None},
                {"aifunc": "ai_walk", "dist": 5.0, "think": None},
                {"aifunc": "ai_walk", "dist": 5.0, "think": None},
                {"aifunc": "ai_walk", "dist": 6.0, "think": None},
                {"aifunc": "ai_walk", "dist": 8.0, "think": None},
                {"aifunc": "ai_walk", "dist": 13.0, "think": None},
                {"aifunc": "ai_walk", "dist": 12.0, "think": None},
                {"aifunc": "ai_walk", "dist": 2.0, "think": None},
                {"aifunc": "ai_walk", "dist": 2.0, "think": None},
                {"aifunc": "ai_walk", "dist": 2.0, "think": None},
                {"aifunc": "ai_walk", "dist": 5.0, "think": None},
                {"aifunc": "ai_walk", "dist": 5.0, "think": None},
                {"aifunc": "ai_walk", "dist": 6.0, "think": None},
                {"aifunc": "ai_walk", "dist": 8.0, "think": None},
                {"aifunc": "ai_walk", "dist": 13.0, "think": None},
            ],
            "cyborg_frames_run": [
                {"aifunc": "ai_run", "dist": 6.0, "think": None},
                {"aifunc": "ai_run", "dist": 23.0, "think": "cyborg_footstep"},
                {"aifunc": "ai_run", "dist": 8.0, "think": None},
                {"aifunc": "ai_run", "dist": 6.0, "think": "cyborg_footstep"},
                {"aifunc": "ai_run", "dist": 23.0, "think": None},
                {"aifunc": "ai_run", "dist": 8.0, "think": None},
            ],
            "cyborg_frames_attack1": [
                {"aifunc": "ai_charge", "dist": 4.0, "think": None},
                {"aifunc": "ai_charge", "dist": 4.0, "think": None},
                {"aifunc": "ai_charge", "dist": 5.0, "think": None},
                {"aifunc": "ai_charge", "dist": 7.0, "think": None},
                {"aifunc": "ai_charge", "dist": 7.0, "think": None},
                {"aifunc": "ai_charge", "dist": 9.0, "think": "cyborg_fire_right"},
                {"aifunc": "ai_charge", "dist": 4.0, "think": None},
                {"aifunc": "ai_charge", "dist": 4.0, "think": None},
                {"aifunc": "ai_charge", "dist": 5.0, "think": None},
                {"aifunc": "ai_charge", "dist": 7.0, "think": None},
                {"aifunc": "ai_charge", "dist": 7.0, "think": None},
                {"aifunc": "ai_charge", "dist": 9.0, "think": "cyborg_fire_left"},
            ],
            "cyborg_frames_attack_backflip": [
                {"aifunc": "ai_charge", "dist": 0.0, "think": None},
                {"aifunc": "ai_charge", "dist": -17.0, "think": None},
                {"aifunc": "ai_charge", "dist": -15.0, "think": "cyborg_attack_start"},
                {"aifunc": "ai_charge", "dist": -15.0, "think": None},
                {"aifunc": "ai_charge", "dist": -15.0, "think": None},
                {"aifunc": "ai_charge", "dist": -15.0, "think": None},
                {"aifunc": "ai_charge", "dist": -15.0, "think": None},
                {"aifunc": "ai_charge", "dist": -15.0, "think": "cyborg_attack_end"},
                {"aifunc": "ai_charge", "dist": 0.0, "think": "cyborg_fire_both"},
                {"aifunc": "ai_charge", "dist": 3.0, "think": None},
                {"aifunc": "ai_charge", "dist": 0.0, "think": None},
            ],
            "cyborg_frames_melee1": [
                {"aifunc": "ai_charge", "dist": 8.0, "think": None},
                {"aifunc": "ai_charge", "dist": 10.0, "think": None},
                {"aifunc": "ai_charge", "dist": 0.0, "think": "cyborg_hit_right"},
                {"aifunc": "ai_charge", "dist": 0.0, "think": None},
                {"aifunc": "ai_charge", "dist": -5.0, "think": "cyborg_hit_alt"},
                {"aifunc": "ai_charge", "dist": -5.0, "think": None},
                {"aifunc": "ai_charge", "dist": -5.0, "think": None},
                {"aifunc": "ai_charge", "dist": -5.0, "think": None},
            ],
            "cyborg_frames_melee2": [
                {"aifunc": "ai_charge", "dist": 6.0, "think": None},
                {"aifunc": "ai_charge", "dist": 6.0, "think": None},
                {"aifunc": "ai_charge", "dist": 6.0, "think": None},
                {"aifunc": "ai_charge", "dist": -3.0, "think": "cyborg_hit_left"},
                {"aifunc": "ai_charge", "dist": -3.0, "think": None},
                {"aifunc": "ai_charge", "dist": -10.0, "think": None},
            ],
            "cyborg_frames_pain1": [
                {"aifunc": "ai_move", "dist": -16.0, "think": None},
                {"aifunc": "ai_move", "dist": -4.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
            ],
            "cyborg_frames_pain2": [
                {"aifunc": "ai_move", "dist": -11.0, "think": None},
                {"aifunc": "ai_move", "dist": -8.0, "think": None},
                {"aifunc": "ai_move", "dist": 4.0, "think": None},
            ],
            "cyborg_frames_pain2_end": [
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
            ],
            "cyborg_frames_move": [
                {"aifunc": "ai_move", "dist": 8.0, "think": None},
                {"aifunc": "ai_move", "dist": 7.0, "think": None},
                {"aifunc": "ai_move", "dist": 3.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
                {"aifunc": "ai_move", "dist": -2.0, "think": None},
                {"aifunc": "ai_move", "dist": -3.0, "think": None},
                {"aifunc": "ai_move", "dist": 2.0, "think": None},
                {"aifunc": "ai_move", "dist": 5.0, "think": None},
                {"aifunc": "ai_move", "dist": 16.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
            ],
            "cyborg_frames_death1": [
                {"aifunc": "ai_move", "dist": -2.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
                {"aifunc": "ai_move", "dist": -3.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
                {"aifunc": "ai_move", "dist": -1.0, "think": None},
                {"aifunc": "ai_move", "dist": -2.0, "think": None},
                {"aifunc": "ai_move", "dist": -3.0, "think": None},
                {"aifunc": "ai_move", "dist": -2.0, "think": None},
            ],
            "cyborg_frames_death2": [
                {"aifunc": "ai_move", "dist": -6.0, "think": None},
                {"aifunc": "ai_move", "dist": -4.0, "think": None},
                {"aifunc": "ai_move", "dist": -2.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
            ],
            "cyborg_frames_death3": [
                {"aifunc": "ai_move", "dist": 8.0, "think": None},
                {"aifunc": "ai_move", "dist": 4.0, "think": None},
                {"aifunc": "ai_move", "dist": 2.0, "think": None},
                {"aifunc": "ai_move", "dist": 1.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
                {"aifunc": "ai_move", "dist": 0.0, "think": None},
            ],
        }

        for array_name, expected_entries in expected_arrays.items():
            self.assertEqual(extract_frame_array(self.source_text, array_name), expected_entries)

    def test_attack_dispatch_and_melee_dispatch_match_retail_thresholds(self) -> None:
        attack_block = extract_function_block(self.source_text, "cyborg_attack")
        melee_block = extract_function_block(self.source_text, "cyborg_melee")
        footstep_block = extract_function_block(self.source_text, "cyborg_footstep")
        run_block = extract_function_block(self.source_text, "cyborg_run")
        range_block = extract_function_block(self.source_text, "cyborg_check_range")
        checkattack_block = extract_function_block(self.source_text, "cyborg_checkattack")

        self.assertIn("n = (rand() + 1) % 3;", footstep_block)
        self.assertIn("if (r < 0.5f)", attack_block)
        self.assertIn("else if (r < 0.7f)", attack_block)
        self.assertIn("self->monsterinfo.currentmove = &cyborg_move_attack1;", attack_block)
        self.assertIn("self->monsterinfo.currentmove = &cyborg_move_attack3;", attack_block)
        self.assertIn("self->monsterinfo.currentmove = &cyborg_move_attack2;", attack_block)
        self.assertLess(
            attack_block.index("self->monsterinfo.currentmove = &cyborg_move_attack3;"),
            attack_block.index("self->monsterinfo.currentmove = &cyborg_move_attack2;"),
            "Ranged attack fallback order no longer matches the retail 1 -> 3 -> 2 selection",
        )
        self.assertIn("if (r < 0.6f)", melee_block)
        self.assertIn("else if (random() < 0.7f)", melee_block)
        self.assertIn("self->monsterinfo.currentmove = &cyborg_move_melee1;", melee_block)
        self.assertIn("self->monsterinfo.currentmove = &cyborg_move_melee2;", melee_block)
        self.assertIn("self->monsterinfo.currentmove = &cyborg_move_attack_backflip;", melee_block)
        self.assertIn("if (self->monsterinfo.currentmove == &cyborg_move_pain2_end)", run_block)
        self.assertIn("if (random() < 0.1f)", run_block)
        self.assertIn("self->monsterinfo.currentmove = &cyborg_move_move;", run_block)
        self.assertNotIn("if (!enemy)", range_block)
        self.assertIn("if (self->enemy && self->enemy->health > 0)", checkattack_block)
        self.assertNotIn("if (!self->enemy || self->enemy->health <= 0)", checkattack_block)
        self.assertIn("if (range(self, self->enemy) == RANGE_MELEE)", checkattack_block)
        self.assertIn("self->monsterinfo.attack_state = AS_MELEE;", checkattack_block)
        self.assertIn("self->monsterinfo.attack_state = AS_MISSILE;", checkattack_block)

    def test_backflip_launch_touch_and_dual_fire_match_retail(self) -> None:
        attack_start_block = extract_function_block(self.source_text, "cyborg_attack_start")
        attack_end_block = extract_function_block(self.source_text, "cyborg_attack_end")
        touch_block = extract_function_block(self.source_text, "cyborg_touch")
        fire_right_block = extract_function_block(self.source_text, "cyborg_fire_right")
        fire_left_block = extract_function_block(self.source_text, "cyborg_fire_left")
        fire_both_block = extract_function_block(self.source_text, "cyborg_fire_both")

        self.assertIn("AngleVectors(self->s.angles, forward, NULL, NULL);", attack_start_block)
        self.assertIn("self->s.origin[2] += 1.0f;", attack_start_block)
        self.assertIn("VectorScale(forward, -100.0f, self->velocity);", attack_start_block)
        self.assertIn("self->velocity[2] = 250.0f;", attack_start_block)
        self.assertLess(
            attack_start_block.index("self->groundentity = NULL;"),
            attack_start_block.index("self->monsterinfo.aiflags |= AI_MANUAL_STEERING;"),
            "Backflip setup no longer matches the recovered retail ground-clear then manual-steering order",
        )
        self.assertIn("self->monsterinfo.attack_finished = level.time + 3.0f;", attack_start_block)

        self.assertLess(
            attack_end_block.index("gi.sound(self, CHAN_WEAPON, sound_thud, 1, ATTN_NORM, 0);"),
            attack_end_block.index("self->monsterinfo.attack_finished = 0;"),
            "Retail landing cleanup resets the attack timeout after playing the thud",
        )
        self.assertLess(
            attack_end_block.index("self->monsterinfo.attack_finished = 0;"),
            attack_end_block.index("self->monsterinfo.aiflags &= ~AI_MANUAL_STEERING;"),
            "Retail landing cleanup clears manual steering after resetting the timeout",
        )
        self.assertIn("if (self->health > 0)", touch_block)
        self.assertIn("VectorLength(self->velocity) > 400.0f", touch_block)
        self.assertIn("VectorMA(self->s.origin, self->maxs[0], dir, point);", touch_block)
        self.assertIn(
            "T_Damage(other, self, self, self->velocity, point, dir, damage,",
            touch_block,
        )
        self.assertIn("damage, 0, MOD_UNKNOWN);", touch_block)
        self.assertIn("if (!M_CheckBottom(self))", touch_block)
        self.assertIn("if (!self->groundentity)", touch_block)
        self.assertIn("self->touch = NULL;", touch_block)
        self.assertLess(
            touch_block.index("if (!self->groundentity)"),
            touch_block.index("return;"),
            "Retail airborne touch logic still returns early while the backflip remains ungrounded",
        )
        self.assertLess(
            touch_block.index("return;"),
            touch_block.index("self->touch = NULL;"),
            "Retail only clears the temporary touch callback after the landing path resolves",
        )
        self.assertIn("self->monsterinfo.nextframe = FRAME_attack401 + 5;", touch_block)

        self.assertNotIn("if (!self->enemy)", fire_right_block)
        self.assertNotIn("if (!self->enemy)", fire_left_block)
        self.assertNotIn("if (!self->enemy)", fire_both_block)
        self.assertLess(
            fire_both_block.index("VectorSet(offset, 15, -12, 12);"),
            fire_both_block.index("VectorSet(offset, 15, 12, 12);"),
            "Dual-shot order no longer matches the retail left-then-right volley",
        )
        self.assertEqual(fire_both_block.count("monster_fire_deatom(self, start, dir, 50, 600);"), 2)

    def test_die_path_matches_retail_structure(self) -> None:
        die_block = extract_function_block(self.source_text, "cyborg_die")

        self.assertNotIn("cyborg_die_select", self.source_text)
        self.assertIn("meansOfDeath == 0x23", die_block)
        self.assertIn("self->s.skinnum = 1;", die_block)
        self.assertIn("r = random();", die_block)
        self.assertIn("if (r < 0.33f)", die_block)
        self.assertIn("else if (r < 0.66f)", die_block)
        self.assertIn("self->monsterinfo.currentmove = &cyborg_move_death1;", die_block)
        self.assertIn("self->monsterinfo.currentmove = &cyborg_move_death2;", die_block)
        self.assertIn("self->monsterinfo.currentmove = &cyborg_move_death3;", die_block)

    def test_monster_fire_deatom_wrapper_matches_retail(self) -> None:
        wrapper_block = extract_function_block(self.monster_source_text, "monster_fire_deatom")
        self.assertIn("fire_deatom(self, start, dir, damage, speed);", wrapper_block)
        self.assertNotIn("svc_muzzleflash2", wrapper_block)


if __name__ == "__main__":
    unittest.main()
