from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parent
ACTOR_SOURCE = REPO_ROOT / "src" / "m_actor.cpp"
AI_SOURCE = REPO_ROOT / "src" / "g_ai.cpp"
LOCAL_HEADER = REPO_ROOT / "src" / "g_local.h"
TRAIL_SOURCE = REPO_ROOT / "src" / "p_trail.cpp"
KIGRAX_SOURCE = REPO_ROOT / "src" / "m_kigrax.cpp"
HUBA_MAP = REPO_ROOT / "src" / "maps" / "obl" / "huba.map"


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


class MiscActorRuntimeRegressionTest(unittest.TestCase):
	@classmethod
	def setUpClass(cls) -> None:
		cls.actor_source = ACTOR_SOURCE.read_text(encoding="utf-8")
		cls.ai_source = AI_SOURCE.read_text(encoding="utf-8")
		cls.header_source = LOCAL_HEADER.read_text(encoding="utf-8")
		cls.trail_source = TRAIL_SOURCE.read_text(encoding="utf-8")
		cls.kigrax_source = KIGRAX_SOURCE.read_text(encoding="utf-8")
		cls.huba_source = HUBA_MAP.read_text(encoding="utf-8")

	def test_actor_attack_endfunc_resumes_single_shot_paths(self) -> None:
		self.assertIn("AI_ACTOR_TEMP_HOLD = bit_v<43>", self.header_source)
		self.assertIn("bool Actor_ResumeScriptedPath(edict_t *self);", self.header_source)
		self.assertIn("actor_attack_finished", self.actor_source)
		self.assertIn("actor_attack_finished };", self.actor_source)

		block = extract_function_block(self.actor_source, "actor_attack_finished")
		self.assertIn("AI_ACTOR_SHOOT_ONCE", block)
		self.assertIn("self->enemy = nullptr;", block)
		self.assertIn("Actor_ResumeScriptedPath(self)", block)

	def test_actor_checkattack_handles_single_shot_and_blocked_stand_ground(self) -> None:
		self.assertIn("bool Actor_SanitizeEnemy(edict_t *self);", self.header_source)

		block = extract_function_block(self.actor_source, "actor_checkattack")
		self.assertIn("Actor_SanitizeEnemy(self)", block)
		self.assertIn("AI_ACTOR_SHOOT_ONCE", block)
		self.assertIn("M_CheckClearShot(self, monster_flash_offset[MZ2_ACTOR_MACHINEGUN_1])", block)
		self.assertIn("M_CheckAttack_Base(self, 0.65f, 0.35f, 0.2f, 0.04f, 0.0f, 1.0f)", block)

	def test_target_actor_touch_queues_waits_and_marks_temporary_hold(self) -> None:
		block = extract_function_block(self.actor_source, "target_actor_touch")
		self.assertIn("Actor_QueueNodePause(other, self->wait);", block)
		self.assertIn("other->monsterinfo.aiflags |= AI_ACTOR_TEMP_HOLD;", block)
		self.assertIn("other->monsterinfo.pausetime = other->timestamp;", block)

	def test_good_guy_actor_can_break_script_path_for_nearby_hostiles(self) -> None:
		block = extract_function_block(self.ai_source, "FindTarget")
		self.assertIn("Actor_FindEnemyTarget(self, ACTOR_PATH_COMBAT_RANGE)", block)
		self.assertIn("Actor_IsPathNode(self->goalentity) || Actor_IsPathNode(self->movetarget)", block)

	def test_companion_escort_selection_is_player_anchored_and_coop_aware(self) -> None:
		block = extract_function_block(self.ai_source, "Actor_SelectEscortTarget")
		self.assertIn("self->target_ent", block)
		self.assertIn("active_players()", block)
		self.assertIn("Actor_ScoreEscortTarget(self, player, current)", block)
		self.assertIn("ACTOR_ESCORT_SWITCH_SCORE", block)

		score_block = extract_function_block(self.ai_source, "Actor_ScoreEscortTarget")
		self.assertIn("Actor_CountFollowers(player, self)", score_block)
		self.assertIn("Actor_PlayerUnderPressure(player)", score_block)
		self.assertIn("self->enemy && self->enemy->inuse && self->enemy->enemy == player", score_block)

	def test_follow_target_selection_uses_escort_state_and_breadcrumbs(self) -> None:
		block = extract_function_block(self.ai_source, "Actor_FindFollowTarget")
		self.assertIn("escort = Actor_SelectEscortTarget(self);", block)
		self.assertIn("self->target_ent = escort;", block)
		self.assertIn("goal = Actor_SelectFollowGoal(self, escort);", block)
		self.assertIn("self->goalentity = self->movetarget = goal;", block)
		self.assertIn("ACTOR_FOLLOW_FRONT_STOP_DISTANCE", block)
		self.assertIn("ACTOR_FOLLOW_RUN_DISTANCE", block)
		self.assertIn("ACTOR_FOLLOW_WALK_DISTANCE", block)
		self.assertIn("ACTOR_FOLLOW_STOP_DISTANCE", block)

		select_block = extract_function_block(self.ai_source, "Actor_SelectFollowGoal")
		self.assertIn("visible(self, escort)", select_block)
		self.assertIn("Actor_PickEscortBreadcrumb(self, escort)", select_block)

		breadcrumb_block = extract_function_block(self.ai_source, "Actor_PickEscortBreadcrumb")
		self.assertIn("PlayerTrail_PickTarget(self, escort, false)", breadcrumb_block)
		self.assertIn("PlayerTrail_PickTarget(self, escort, true)", breadcrumb_block)
		self.assertIn("escort->client->trail_head", breadcrumb_block)
		self.assertIn("best_visible", breadcrumb_block)
		self.assertIn("best_any", breadcrumb_block)

	def test_companion_threat_selection_prioritizes_player_protection(self) -> None:
		block = extract_function_block(self.ai_source, "Actor_ScoreThreatTarget")
		self.assertIn("ent->enemy == escort", block)
		self.assertIn("visible(escort, ent)", block)
		self.assertIn("!infront(escort, ent)", block)
		self.assertIn("Actor_PlayerUnderPressure(escort)", block)
		self.assertIn("ACTOR_PLAYER_PROTECT_RANGE", block)

	def test_idle_companions_only_break_follow_for_protection_threats(self) -> None:
		block = extract_function_block(self.ai_source, "FindTarget")
		self.assertIn("Actor_FindEnemyTarget(self, ACTOR_PLAYER_PROTECT_RANGE)", block)
		self.assertIn("Actor_FindEnemyTarget(self, ACTOR_PATH_COMBAT_RANGE)", block)

	def test_damage_reaction_uses_actor_specific_hook_and_never_inherits_player_enemy(self) -> None:
		self.assertIn("edict_t *PlayerTrail_PickTarget(edict_t *self, edict_t *target, bool next);", self.header_source)

		combat_source = (REPO_ROOT / "src" / "g_combat.cpp").read_text(encoding="utf-8")
		combat_block = extract_function_block(combat_source, "M_ReactToDamage")
		self.assertIn("Actor_ReactToDamage(targ, attacker, inflictor)", combat_block)
		self.assertLess(
			combat_source.index("Actor_ReactToDamage(targ, attacker, inflictor)"),
			combat_source.index("if (!(attacker->client) && !(attacker->svflags & SVF_MONSTER))"),
		)

		reaction_block = extract_function_block(self.ai_source, "Actor_ReactToDamage")
		self.assertIn("Actor_ResolveDamageThreat(attacker, inflictor)", reaction_block)
		self.assertIn("edict_t *threat =", reaction_block)
		self.assertIn("if (attacker->client || (attacker->monsterinfo.aiflags & AI_GOOD_GUY))", reaction_block)
		self.assertIn("Actor_BeginDefensiveFire(self, escort, threat)", reaction_block)
		self.assertIn("self->enemy = threat;", reaction_block)
		self.assertNotIn("attacker->enemy", reaction_block)

	def test_companion_cleanup_sanitizes_player_enemy_and_can_withdraw(self) -> None:
		sanitize_block = extract_function_block(self.ai_source, "Actor_SanitizeEnemy")
		self.assertIn("self->enemy->client", sanitize_block)
		self.assertIn("Actor_ResolveDamageThreat(self->monsterinfo.damage_attacker, self->monsterinfo.damage_inflictor)", sanitize_block)
		self.assertIn("self->goalentity = threat;", sanitize_block)
		self.assertIn("self->goalentity = self->movetarget;", sanitize_block)
		self.assertIn("self->monsterinfo.last_player_enemy = nullptr;", sanitize_block)

		run_block = extract_function_block(self.ai_source, "void ai_run(edict_t *self, float dist)")
		self.assertIn("Actor_SanitizeEnemy(self)", run_block)
		self.assertIn("Actor_ShouldWithdraw(self, escort, self->enemy)", run_block)
		self.assertIn("Actor_FindFollowTarget(self);", run_block)
		self.assertIn("self->goalentity = self->movetarget;", run_block)

	def test_friendly_actor_pain_and_firing_paths_reject_player_targets(self) -> None:
		pain_block = extract_function_block(self.actor_source, "actor_pain")
		self.assertIn("Actor_SanitizeEnemy(self);", pain_block)
		self.assertIn("!(self->monsterinfo.aiflags & AI_ACTOR_FRIENDLY)", pain_block)

		fire_block = extract_function_block(self.actor_source, "actorMachineGun")
		self.assertIn("Actor_SanitizeEnemy(self)", fire_block)

	def test_player_trail_can_be_picked_for_explicit_follow_target(self) -> None:
		block = extract_function_block(self.trail_source, "PlayerTrail_PickTarget")
		self.assertIn("!self || !target || !target->client || !target->client->trail_head", block)
		self.assertIn("for (marker = target->client->trail_head; marker; marker = marker->enemy)", block)
		self.assertIn("return PlayerTrail_PickTarget(self, self->enemy, next);", self.trail_source)

	def test_misc_actor_spawns_as_ranged_companion_and_clears_escort_on_script_use(self) -> None:
		spawn_block = extract_function_block(self.actor_source, "SP_misc_actor")
		self.assertIn("self->monsterinfo.combat_style = COMBAT_RANGED;", spawn_block)
		self.assertIn("!self->spawnflags.has(SPAWNFLAG_MONSTER_TRIGGER_SPAWN)", spawn_block)

		leave_idle_block = extract_function_block(self.actor_source, "Actor_LeaveIdlePath")
		self.assertIn("self->target_ent = nullptr;", leave_idle_block)
		self.assertIn("AI_ACTOR_DEFENSIVE_FIRE", leave_idle_block)

		use_block = extract_function_block(self.actor_source, "actor_use")
		self.assertIn("self->target_ent = nullptr;", use_block)
		self.assertIn("if (self->monsterinfo.aiflags & AI_SPAWNED_ALIVE)", use_block)
		self.assertIn("self->target = nullptr;", use_block)

	def test_start_on_huba_actor_keeps_route_until_monster_startup_consumes_it(self) -> None:
		use_block = extract_function_block(self.actor_source, "actor_use")
		self.assertIn("START_ON actors are pre-used before monster_start_go() runs", use_block)
		self.assertIn("if (self->monsterinfo.aiflags & AI_SPAWNED_ALIVE)", use_block)

		self.assertIn('"origin" "-1168 -1600 -216"', self.huba_source)
		self.assertIn('"spawnflags" "96"', self.huba_source)
		self.assertIn('"target" "t26"', self.huba_source)
		self.assertIn('"targetname" "t26"', self.huba_source)

	def test_defensive_follow_fire_keeps_escort_state_and_updates_reliably(self) -> None:
		self.assertIn("AI_ACTOR_DEFENSIVE_FIRE = bit_v<44>", self.header_source)

		begin_block = extract_function_block(self.ai_source, "Actor_BeginDefensiveFire")
		self.assertIn("AI_ACTOR_DEFENSIVE_FIRE | AI_ACTOR_FOLLOW", begin_block)
		self.assertIn("self->monsterinfo.run(self);", begin_block)

		run_block = extract_function_block(self.ai_source, "Actor_RunDefensiveFollow")
		self.assertIn("ai_checkattack(self, dist)", run_block)
		self.assertIn("ACTOR_DEFENSIVE_FIRE_TIMEOUT", run_block)
		self.assertIn("Actor_MoveFollowGoal(self, dist, self->enemy)", run_block)
		self.assertIn("Actor_FindFollowTarget(self);", run_block)

	def test_following_actor_can_yield_out_of_player_path_and_guard_their_rear(self) -> None:
		yield_block = extract_function_block(self.ai_source, "Actor_BuildYieldGoal")
		self.assertIn("ACTOR_YIELD_SIDE_DISTANCE", yield_block)
		self.assertIn("ACTOR_YIELD_BACKSTEP", yield_block)
		self.assertIn("gi.trace(self->s.origin, self->mins, self->maxs, candidate, self, MASK_MONSTERSOLID)", yield_block)

		move_block = extract_function_block(self.ai_source, "Actor_MoveFollowGoal")
		self.assertIn("Actor_BuildYieldGoal(self, escort, yield_goal)", move_block)
		self.assertIn("Actor_ShouldGuardRear(self, escort, threat)", move_block)
		self.assertIn("M_MoveToGoal(self, dist)", move_block)

	def test_kigrax_uses_a_bbox_consistent_viewheight_for_visibility_and_attack_traces(self) -> None:
		kigrax_block = extract_function_block(self.kigrax_source, "SP_monster_kigrax")
		self.assertIn("self->viewheight = 12;", kigrax_block)
		self.assertNotIn("self->viewheight = 90;", kigrax_block)
		self.assertIn("other->viewheight", self.ai_source)
		self.assertIn("self->enemy->viewheight", self.ai_source)

	def test_enemy_death_clears_temporary_actor_hold_before_generic_recovery(self) -> None:
		block = extract_function_block(self.ai_source, "ai_checkattack")
		self.assertIn("AI_ACTOR_SHOOT_ONCE | AI_ACTOR_TEMP_HOLD | AI_BRUTAL | AI_STAND_GROUND | AI_ACTOR_DEFENSIVE_FIRE", block)
		self.assertIn("scripted_pause_waiting", block)
		self.assertIn("Actor_ResumeScriptedPath(self)", block)


if __name__ == "__main__":
	unittest.main()
