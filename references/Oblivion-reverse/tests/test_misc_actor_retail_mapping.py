import re
from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
ACTOR_SOURCE = REPO_ROOT / "src" / "game" / "m_actor.c"
ACTOR_HEADER = REPO_ROOT / "src" / "game" / "m_actor.h"
AI_SOURCE = REPO_ROOT / "src" / "game" / "g_ai.c"
MONSTER_SOURCE = REPO_ROOT / "src" / "game" / "g_monster.c"
SAVE_SOURCE = REPO_ROOT / "src" / "game" / "g_save.c"


def extract_function_block(source: str, function_name: str) -> str:
    pattern = re.compile(rf"{function_name}\s*\([^)]*\)\s*\{{", re.MULTILINE)
    match = pattern.search(source)
    if not match:
        raise AssertionError(f"Could not locate function {function_name}")
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


class MiscActorRetailMappingTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.actor_text = ACTOR_SOURCE.read_text(encoding="utf-8")
        cls.header_text = ACTOR_HEADER.read_text(encoding="utf-8")
        cls.ai_text = AI_SOURCE.read_text(encoding="utf-8")
        cls.monster_text = MONSTER_SOURCE.read_text(encoding="utf-8")
        cls.save_text = SAVE_SOURCE.read_text(encoding="utf-8")

    def test_reconstruction_helpers_are_removed(self) -> None:
        for token in (
            "Actor_UseOblivion",
            "Actor_SpawnOblivion",
            "Actor_PathAssignController",
            "Actor_PathResetState",
            "Actor_PathThink",
            "Actor_PathAdvance",
            "Actor_PathApplyWait",
            "Actor_UpdateMissionObjective",
            "Actor_PostLoad",
            "Actor_BroadcastMessage",
            "Actor_ResetChatCooldown",
            "Actor_PreThink",
            "Actor_AttachController",
        ):
            self.assertNotIn(token, self.actor_text)

    def test_header_exports_only_spawn_entries(self) -> None:
        self.assertIn("void SP_misc_actor (edict_t *self);", self.header_text)
        self.assertIn("void SP_target_actor (edict_t *self);", self.header_text)
        for token in (
            "Actor_PostLoad",
            "actor_stand",
            "actor_walk",
            "actor_run",
            "target_actor_touch",
        ):
            self.assertNotIn(token, self.header_text)

    def test_spawn_defaults_match_retail_mapping(self) -> None:
        block = extract_function_block(self.actor_text, "SP_misc_actor")
        self.assertIn('"Yo Mama"', block)
        self.assertIn("self->spawnflags |= ACTOR_SPAWNFLAG_START_ON;", block)
        self.assertIn("self->s.modelindex = 0xff;", block)
        self.assertIn("self->s.modelindex2 = 0xff;", block)
        self.assertIn("VectorSet(self->mins, -16, -16, -24);", block)
        self.assertIn("VectorSet(self->maxs, 16, 16, 32);", block)
        self.assertIn("self->health = 100;", block)
        self.assertIn("self->mass = 200;", block)

    def test_spawn_ai_flags_match_retail_mapping(self) -> None:
        block = extract_function_block(self.actor_text, "SP_misc_actor")
        self.assertIn("self->monsterinfo.aiflags |= AI_ACTOR_PATH_IDLE;", block)
        self.assertIn("self->monsterinfo.aiflags |= AI_ACTOR_FRIENDLY;", block)
        self.assertIn("self->monsterinfo.aiflags |= AI_GOOD_GUY;", block)
        self.assertNotRegex(
            block,
            r"ACTOR_SPAWNFLAG_WIMPY[\s\S]*health",
            "Retail WIMPY handling should only affect friendly AI bits",
        )

    def test_walkmonster_start_is_followed_by_actor_use_restore(self) -> None:
        block = extract_function_block(self.actor_text, "SP_misc_actor")
        self.assertIn("walkmonster_start(self);", block)
        self.assertIn("retail actors keep actor_use.", block)
        self.assertIn("self->use = actor_use;", block)

    def test_actor_die_matches_retail_thresholds(self) -> None:
        block = extract_function_block(self.actor_text, "actor_die")
        self.assertIn("meansOfDeath == 0x23", block)
        self.assertIn("self->health <= -80", block)
        self.assertIn("self->s.modelindex2 = 0;", block)
        for token in ("actor_move_death1", "actor_move_death2", "actor_move_death3"):
            self.assertIn(token, block)

    def test_target_actor_touch_uses_direct_chat_broadcast(self) -> None:
        block = extract_function_block(self.actor_text, "target_actor_touch")
        self.assertIn('gi.cprintf(ent, PRINT_CHAT, "%s: %s\\n",', block)
        self.assertIn("if (!ent->inuse || !ent->client)", block)
        self.assertNotIn("Actor_BroadcastMessage", block)
        self.assertNotIn("Actor_UpdateMissionObjective", block)
        self.assertNotIn("Actor_Path", block)

    def test_actor_pain_uses_retail_three_message_table(self) -> None:
        self.assertEqual(self.actor_text.count('"Watch it"'), 1)
        self.assertEqual(self.actor_text.count('"#$@*&"'), 1)
        self.assertEqual(self.actor_text.count('"Idiot"'), 1)
        self.assertNotIn('"Check your targets"', self.actor_text)

    def test_actor_use_matches_retail_failure_fallback_without_debug_print(self) -> None:
        block = extract_function_block(self.actor_text, "actor_use")
        self.assertIn('strcmp(self->movetarget->classname, "target_actor") != 0', block)
        self.assertIn("self->monsterinfo.pausetime = 100000000.0f;", block)
        self.assertIn("self->monsterinfo.stand(self);", block)
        self.assertIn("self->monsterinfo.walk(self);", block)
        self.assertNotIn("gi.dprintf", block)

    def test_actor_ai_helpers_use_retail_hostile_and_follow_filters(self) -> None:
        enemy_block = extract_function_block(self.ai_text, "Actor_FindEnemyTarget")
        self.assertIn("ent->monsterinfo.aiflags & AI_GOOD_GUY", enemy_block)
        self.assertNotIn("ent->monsterinfo.aiflags & AI_STAND_GROUND", enemy_block)

        follow_block = extract_function_block(self.ai_text, "Actor_FindFollowTarget")
        self.assertIn("!ent->client && !(ent->monsterinfo.aiflags & AI_GOOD_GUY)", follow_block)

    def test_actor_ai_wrappers_match_retail_good_guy_branches(self) -> None:
        tail_block = extract_function_block(self.ai_text, "ai_stand_tail")
        self.assertIn("!(self->monsterinfo.aiflags & (AI_STAND_GROUND | AI_TEMP_STAND_GROUND))", tail_block)
        self.assertIn("self->monsterinfo.pausetime && (level.time > self->monsterinfo.pausetime)", tail_block)

        stand_block = extract_function_block(self.ai_text, "ai_stand")
        self.assertIn("if (self->monsterinfo.aiflags & AI_GOOD_GUY)", stand_block)
        self.assertIn("ai_stand_tail (self);", stand_block)
        self.assertIn("if (self->monsterinfo.pausetime && (level.time > self->monsterinfo.pausetime))", stand_block)

        walk_block = extract_function_block(self.ai_text, "ai_walk")
        self.assertIn("if (!(self->monsterinfo.aiflags & AI_GOOD_GUY))", walk_block)
        self.assertIn("else if (self->monsterinfo.aiflags & AI_ACTOR_PATH_IDLE)", walk_block)

    def test_foundtarget_uses_retail_actor_engageenemy_fallback(self) -> None:
        block = extract_function_block(self.ai_text, "FoundTarget")
        self.assertIn("Actor_EngageEnemy(self);", block)
        self.assertNotIn("HuntTarget (self);", block)
        self.assertNotIn("gi.dprintf", block)

    def test_monster_start_go_accepts_target_actor_start_nodes(self) -> None:
        block = extract_function_block(self.monster_text, "monster_start_go")
        self.assertIn('strcmp(self->movetarget->classname, "path_corner") == 0', block)
        self.assertIn('strcmp(self->movetarget->classname, "target_actor") == 0', block)
        self.assertIn("self->monsterinfo.walk(self);", block)
        self.assertIn("self->target = NULL;", block)

    def test_save_layer_no_longer_serializes_actor_path_band(self) -> None:
        for token in (
            "mission_controller",
            "mission_last_controller",
            "mission_prev_path",
            "mission_path_target",
            "mission_script_target",
            "mission_controller_serial",
            "mission_path_toggle",
            "mission_controller_distance",
            "mission_controller_resume",
            "mission_path_wait",
            "mission_path_time",
            "mission_path_speed",
            "mission_path_step_speed",
            "mission_path_remaining",
            "mission_path_state",
            "mission_path_dir",
            "mission_path_velocity",
            "mission_custom_name",
            "mission_custom_name_time",
            "Actor_PostLoad",
        ):
            self.assertNotIn(token, self.save_text)


if __name__ == "__main__":
    unittest.main()
