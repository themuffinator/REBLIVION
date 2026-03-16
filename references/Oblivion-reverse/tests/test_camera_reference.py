import re
from pathlib import Path
import unittest


def _extract_function_block(source: str, function_name: str) -> str:
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


class CameraReferenceTest(unittest.TestCase):
	@classmethod
	def setUpClass(cls) -> None:
		repo_root = Path(__file__).resolve().parents[1]
		cls.repo_root = repo_root
		cls.g_camera_source = (repo_root / "src" / "game" / "g_camera.c").read_text(
			encoding="utf-8"
		)
		cls.g_local_header = (repo_root / "src" / "game" / "g_local.h").read_text(
			encoding="utf-8"
		)
		cls.g_save_source = (repo_root / "src" / "game" / "g_save.c").read_text(
			encoding="utf-8"
		)
		cls.g_cmds_source = (repo_root / "src" / "game" / "g_cmds.c").read_text(
			encoding="utf-8"
		)
		cls.p_client_source = (repo_root / "src" / "game" / "p_client.c").read_text(
			encoding="utf-8"
		)
		cls.p_hud_source = (repo_root / "src" / "game" / "p_hud.c").read_text(
			encoding="utf-8"
		)
		cls.p_view_source = (repo_root / "src" / "game" / "p_view.c").read_text(
			encoding="utf-8"
		)
		cls.game_001_source = (repo_root / "src" / "game" / "game.001").read_text(
			encoding="utf-8"
		)
		cls.game_dsp_source = (repo_root / "src" / "game" / "game.dsp").read_text(
			encoding="utf-8"
		)

	def test_dummy_body_sync_matches_recovered_helper(self) -> None:
		sync_block = _extract_function_block(self.g_camera_source, "DummyBody_Sync")

		self.assertIn("VectorCopy(player->s.origin, body->s.origin);", sync_block)
		self.assertIn("VectorCopy(player->s.angles, body->s.angles);", sync_block)
		self.assertIn("VectorCopy(player->velocity, body->velocity);", sync_block)
		self.assertIn("VectorCopy(player->avelocity, body->avelocity);", sync_block)
		self.assertIn("body->s.modelindex = player->s.modelindex;", sync_block)
		self.assertIn("body->s.modelindex2 = player->s.modelindex2;", sync_block)
		self.assertIn("body->s.frame = player->s.frame;", sync_block)
		self.assertNotIn("VectorCopy(player->mins, body->mins);", sync_block)
		self.assertNotIn("VectorCopy(player->maxs, body->maxs);", sync_block)

	def test_dummy_body_setup_keeps_bbox_copy_in_setup(self) -> None:
		setup_block = _extract_function_block(self.g_camera_source, "DummyBody_Setup")

		self.assertIn('body->classname = "dummy_body";', setup_block)
		self.assertIn("body->enemy = player;", setup_block)
		self.assertIn("VectorCopy(player->mins, body->mins);", setup_block)
		self.assertIn("VectorCopy(player->maxs, body->maxs);", setup_block)

	def test_remote_view_client_state_matches_recovered_tail(self) -> None:
		state_block = _extract_function_block(self.g_camera_source, "RemoteView_ApplyClientState")

		self.assertIn("ent->client->ps.pmove.origin[0] = viewent->s.origin[0] * 8.0f;", state_block)
		self.assertIn("ent->client->ps.pmove.origin[1] = viewent->s.origin[1] * 8.0f;", state_block)
		self.assertIn("ent->client->ps.pmove.origin[2] = viewent->s.origin[2] * 8.0f;", state_block)
		self.assertIn("VectorCopy(viewent->s.angles, ent->client->ps.viewangles);", state_block)
		self.assertIn("ent->client->ps.viewoffset[0] = (float)ent->client->remote_view_state_1;", state_block)
		self.assertIn("ent->client->ps.viewoffset[1] = (float)ent->client->remote_view_state_2;", state_block)
		self.assertIn("ent->client->ps.viewoffset[2] = ent->client->remote_view_timer;", state_block)
		self.assertIn("ent->client->ps.pmove.pm_type = PM_FREEZE;", state_block)
		self.assertNotIn("ps.pmove.velocity", state_block)
		self.assertNotIn("ps.gunindex = 0;", state_block)
		self.assertNotIn("VectorCopy(viewent->s.angles, ent->client->v_angle);", state_block)

	def test_remote_view_postframe_applies_state_before_syncing_dummy_body(self) -> None:
		post_block = _extract_function_block(self.g_camera_source, "RemoteView_ClientPostFrame")

		apply_index = post_block.find("RemoteView_ApplyClientState(ent, viewent);")
		sync_index = post_block.find("DummyBody_Sync(ent, body);")
		self.assertNotEqual(-1, apply_index)
		self.assertNotEqual(-1, sync_index)
		self.assertLess(apply_index, sync_index)

	def test_remote_view_slot_is_shared_between_camera_and_rtdu(self) -> None:
		self.assertIn("union {", self.g_local_header)
		self.assertIn("edict_t *remote_view_entity; // retail +0xF18 shared tracked-entity slot", self.g_local_header)
		self.assertIn("edict_t *turret; // source-side RTDU alias for the shared tracked-entity slot", self.g_local_header)
		self.assertIn('{"rtdu.turret", CLOFS(rtdu.turret), F_EDICT},', self.g_save_source)
		self.assertNotIn('{"remote_view_entity", CLOFS(remote_view_entity), F_EDICT},', self.g_save_source)

	def test_remote_view_helpers_match_single_tracked_entity_slot(self) -> None:
		get_block = _extract_function_block(self.g_camera_source, "RemoteView_GetEntity")
		begin_block = _extract_function_block(self.g_camera_source, "RemoteView_Begin")
		end_block = _extract_function_block(self.g_camera_source, "RemoteView_End")
		attach_block = _extract_function_block(self.g_camera_source, "RemoteView_AttachController")
		detach_block = _extract_function_block(self.g_camera_source, "RemoteView_DetachController")

		self.assertIn("viewent = ent->client->remote_view_entity;", get_block)
		self.assertNotIn("ent->client->rtdu.turret = viewent;", get_block)
		self.assertIn("ent->client->remote_view_entity = NULL;", get_block)

		self.assertIn("(void)viewent;", begin_block)
		self.assertNotIn("ent->client->remote_view_entity = viewent;", begin_block)

		self.assertIn("ent->client->ps.gunindex = ent->client->remote_view_saved_gunindex;", end_block)
		self.assertNotIn("was_active", end_block)
		self.assertNotIn("ent->client->remote_view_entity = NULL;", end_block)

		self.assertIn("if (ent->client->remote_view_entity)", attach_block)
		self.assertIn("ent->client->remote_view_entity = viewent;", attach_block)
		self.assertNotIn("ent->client->rtdu.turret = viewent;", attach_block)

		self.assertIn("if (ent->client->remote_view_entity != viewent)", detach_block)
		self.assertIn("ent->client->remote_view_entity = NULL;", detach_block)
		self.assertNotIn("ent->client->rtdu.turret = NULL;", detach_block)

	def test_misc_camera_spawn_defaults_match_hlil(self) -> None:
		camera_block = _extract_function_block(self.g_camera_source, "SP_misc_camera")

		self.assertIn("self->solid = SOLID_NOT;", camera_block)
		self.assertIn("self->movetype = MOVETYPE_FLYMISSILE;", camera_block)
		self.assertIn("self->svflags |= SVF_NOCLIENT;", camera_block)
		self.assertIn("VectorClear(self->mins);", camera_block)
		self.assertIn("VectorClear(self->maxs);", camera_block)
		self.assertIn('gi.bprintf(PRINT_HIGH, "%s with no targetname\\n", self->classname);', camera_block)
		self.assertIn('self->targetname = "unused";', camera_block)
		self.assertIn("if (self->wait == 0.0f)", camera_block)
		self.assertIn("self->wait = CAMERA_DEFAULT_WAIT;", camera_block)
		self.assertIn("self->use = Camera_Use;", camera_block)
		self.assertIn("self->think = Camera_Think;", camera_block)
		self.assertIn('self->s.modelindex = gi.modelindex("sprites/s_deatom1.sp2");', camera_block)

	def test_misc_camera_target_spawn_defaults_match_hlil(self) -> None:
		target_block = _extract_function_block(self.g_camera_source, "SP_misc_camera_target")

		self.assertIn("self->solid = SOLID_NOT;", target_block)
		self.assertIn("self->movetype = MOVETYPE_FLYMISSILE;", target_block)
		self.assertIn("self->svflags |= SVF_NOCLIENT;", target_block)
		self.assertIn("VectorClear(self->mins);", target_block)
		self.assertIn("VectorClear(self->maxs);", target_block)
		self.assertIn('gi.bprintf(PRINT_HIGH, "%s with no targetname\\n", self->classname);', target_block)
		self.assertIn('self->targetname = "unused";', target_block)
		self.assertIn("self->count = 0;", target_block)
		self.assertIn("self->movetarget = NULL;", target_block)
		self.assertIn("self->use = Camera_TargetUse;", target_block)
		self.assertIn("self->think = Camera_TargetThink;", target_block)
		self.assertIn('self->s.modelindex = gi.modelindex("sprites/s_deatom1.sp2");', target_block)

	def test_camera_use_activate_and_deactivate_match_hlil(self) -> None:
		use_block = _extract_function_block(self.g_camera_source, "Camera_Use")
		activate_block = _extract_function_block(self.g_camera_source, "Camera_Activate")
		deactivate_block = _extract_function_block(self.g_camera_source, "Camera_Deactivate")

		self.assertIn("if (self->count == 0)", use_block)
		self.assertIn("Camera_Activate(self);", use_block)
		self.assertIn("Camera_Deactivate(self);", use_block)

		self.assertIn("if (!self->enemy && self->target)", activate_block)
		self.assertIn("self->enemy = G_PickTarget(self->target);", activate_block)
		self.assertIn("self->movetarget = G_Find(NULL, FOFS(targetname), self->pathtarget);", activate_block)
		self.assertIn("self->speed ? self->speed : CAMERA_PATH_DEFAULT_SPEED;", activate_block)
		self.assertIn("VectorCopy(self->movetarget->s.origin, self->s.origin);", activate_block)
		self.assertIn("Camera_AttachClient(player, self);", activate_block)
		self.assertIn("self->count = 1;", activate_block)
		self.assertIn("self->timestamp = level.time;", activate_block)
		self.assertIn("self->nextthink = level.time + FRAMETIME;", activate_block)

		self.assertIn("Camera_DetachClient(player, self);", deactivate_block)
		self.assertIn("self->delay = 0.0f;", deactivate_block)
		self.assertIn("self->oblivion.deatom_f_32c = 0.0f;", deactivate_block)
		self.assertIn("self->oblivion.deatom_state = 0;", deactivate_block)
		self.assertIn("self->count = 0;", deactivate_block)
		self.assertIn("self->nextthink = 0.0f;", deactivate_block)

	def test_camera_move_step_matches_recovered_state_machine(self) -> None:
		move_block = _extract_function_block(self.g_camera_source, "Camera_MoveStep")

		self.assertIn("switch (self->oblivion.deatom_state)", move_block)
		self.assertIn("self->delay = CAMERA_PATH_STOPPED;", move_block)
		self.assertIn("full_frames = (int)(move_time * 10.0f);", move_block)
		self.assertIn("self->oblivion.deatom_v_340[2] = remaining_speed;", move_block)
		self.assertIn('gi.bprintf(PRINT_HIGH, "no main move\\n");', move_block)
		self.assertIn("self->delay = self->movetarget->delay;", move_block)
		self.assertIn("self->movetarget = G_PickTarget(self->movetarget->target);", move_block)

	def test_camera_think_matches_recovered_tracking_and_schedule_logic(self) -> None:
		think_block = _extract_function_block(self.g_camera_source, "Camera_Think")

		self.assertIn("self->timestamp + self->wait < level.time", think_block)
		self.assertIn("self->delay == CAMERA_PATH_STOPPED", think_block)
		self.assertIn("Camera_MoveStep(self);", think_block)
		self.assertIn("if (self->enemy && !self->enemy->inuse)", think_block)
		self.assertIn("VectorAdd(self->enemy->absmin, self->enemy->absmax, target);", think_block)
		self.assertIn("target[2] += self->enemy->viewheight;", think_block)
		self.assertIn("VectorScale(current_forward, 0.9f, current_forward);", think_block)
		self.assertIn("VectorMA(current_forward, 0.1f, target_dir, current_forward);", think_block)
		self.assertIn("self->nextthink = level.time + FRAMETIME;", think_block)
		self.assertIn("self->nextthink = self->timestamp + self->wait;", think_block)
		self.assertIn("self->nextthink = self->oblivion.deatom_f_32c;", think_block)

	def test_camera_target_runtime_matches_recovered_toggle_and_think_logic(self) -> None:
		target_use_block = _extract_function_block(self.g_camera_source, "Camera_TargetUse")
		target_think_block = _extract_function_block(self.g_camera_source, "Camera_TargetThink")

		self.assertIn("if (self->count != 0)", target_use_block)
		self.assertIn("self->delay = 0.0f;", target_use_block)
		self.assertIn("self->oblivion.deatom_f_32c = 0.0f;", target_use_block)
		self.assertIn("self->movetarget = G_Find(NULL, FOFS(targetname), self->target);", target_use_block)
		self.assertIn("self->speed ? self->speed : CAMERA_PATH_DEFAULT_SPEED;", target_use_block)
		self.assertIn("self->oblivion.deatom_f_32c = level.time;", target_use_block)
		self.assertIn("self->nextthink = level.time + FRAMETIME;", target_use_block)
		self.assertIn('gi.bprintf(PRINT_HIGH, "%s at %s: invalid target %s\\n",', target_use_block)

		self.assertIn("if (self->movetarget)", target_think_block)
		self.assertIn("if (self->delay == CAMERA_PATH_STOPPED)", target_think_block)
		self.assertIn("Camera_MoveStep(self);", target_think_block)
		self.assertIn("self->nextthink = self->oblivion.deatom_f_32c;", target_think_block)

	def test_trigger_misc_camera_runtime_matches_recovered_hlil(self) -> None:
		fire_block = _extract_function_block(self.g_camera_source, "TriggerCamera_Fire")
		use_block = _extract_function_block(self.g_camera_source, "TriggerCamera_Use")
		touch_block = _extract_function_block(self.g_camera_source, "TriggerCamera_Touch")
		spawn_block = _extract_function_block(self.g_camera_source, "SP_trigger_misc_camera")

		self.assertIn("if (self->nextthink)", fire_block)
		self.assertIn("for (camera = G_Find(NULL, FOFS(targetname), self->target);", fire_block)
		self.assertIn('strcmp(camera->classname, "misc_camera") != 0', fire_block)
		self.assertIn("if (self->wait != 0.0f)", fire_block)
		self.assertIn("camera->wait = self->wait;", fire_block)
		self.assertIn("camera->target = self->pathtarget;", fire_block)
		self.assertIn("camera->enemy = self->activator;", fire_block)
		self.assertIn("Camera_Use(camera, self, self->activator);", fire_block)
		self.assertIn("camera->timestamp = level.time;", fire_block)
		self.assertIn("self->think = multi_wait;", fire_block)
		self.assertIn("self->think = G_FreeEdict;", fire_block)
		self.assertIn("self->nextthink = level.time + FRAMETIME;", fire_block)
		self.assertIn('gi.bprintf(PRINT_HIGH, "Illegal target for trigger_misc_camera\\n");', fire_block)

		self.assertIn("self->activator = activator;", use_block)
		self.assertIn("TriggerCamera_Fire(self);", use_block)

		self.assertIn("if (self->spawnflags & 2)", touch_block)
		self.assertIn("if (!(self->spawnflags & 1))", touch_block)
		self.assertIn("if (!VectorCompare(self->movedir, vec3_origin))", touch_block)
		self.assertIn("if (_DotProduct(forward, self->movedir) < 0)", touch_block)
		self.assertIn("self->activator = other;", touch_block)

		self.assertIn('self->noise_index = gi.soundindex("misc/secret.wav");', spawn_block)
		self.assertIn('self->noise_index = gi.soundindex("misc/talk.wav");', spawn_block)
		self.assertIn('self->noise_index = gi.soundindex("misc/trigger1.wav");', spawn_block)
		self.assertIn("InitTrigger(self);", spawn_block)
		self.assertIn("self->touch = TriggerCamera_Touch;", spawn_block)
		self.assertIn("self->use = trigger_enable;", spawn_block)
		self.assertIn("self->use = TriggerCamera_Use;", spawn_block)

	def test_camera_client_frames_only_service_remote_view(self) -> None:
		pre_block = _extract_function_block(self.g_camera_source, "Camera_ClientPreFrame")
		post_block = _extract_function_block(self.g_camera_source, "Camera_ClientPostFrame")

		self.assertIn("RemoteView_ClientPreFrame(ent);", pre_block)
		self.assertNotIn("client->camera", pre_block)
		self.assertIn("RemoteView_ClientPostFrame(ent);", post_block)
		self.assertNotIn("camera_state", post_block)

	def test_item_selection_helpers_do_not_route_through_stock_chase_camera(self) -> None:
		next_block = _extract_function_block(self.g_cmds_source, "SelectNextItem")
		prev_block = _extract_function_block(self.g_cmds_source, "SelectPrevItem")

		self.assertNotIn("cl->chase_target", next_block)
		self.assertNotIn("ChaseNext(ent);", next_block)
		self.assertIn("cl->pers.selected_item = index;", next_block)

		self.assertNotIn("cl->chase_target", prev_block)
		self.assertNotIn("ChasePrev(ent);", prev_block)
		self.assertIn("cl->pers.selected_item = index;", prev_block)

	def test_clientthink_no_longer_uses_stock_chase_camera_runtime(self) -> None:
		think_block = _extract_function_block(self.p_client_source, "ClientThink")

		self.assertNotIn("ent->client->chase_target", think_block)
		self.assertNotIn("GetChaseTarget(ent);", think_block)
		self.assertNotIn("ChaseNext(ent);", think_block)
		self.assertNotIn("UpdateChaseCam(other);", think_block)
		self.assertNotIn("if (client->resp.spectator)", think_block)
		self.assertNotIn("if (!client->resp.spectator)", think_block)
		self.assertIn("Oblivion_UpdateWeaponRegen(ent);", think_block)

	def test_clientendserverframe_uses_retail_stats_path_without_chase_overlay(self) -> None:
		frame_block = _extract_function_block(self.p_view_source, "ClientEndServerFrame")

		self.assertIn("G_SetStats (ent);", frame_block)
		self.assertNotIn("G_SetSpectatorStats(ent);", frame_block)
		self.assertNotIn("G_CheckChaseStats(ent);", frame_block)

	def test_legacy_stock_chase_camera_code_is_retired(self) -> None:
		self.assertFalse((self.repo_root / "src" / "game" / "g_chase.c").exists())
		self.assertNotIn("G_SetSpectatorStats", self.g_local_header)
		self.assertNotIn("G_CheckChaseStats", self.g_local_header)
		self.assertNotIn("UpdateChaseCam", self.g_local_header)
		self.assertNotIn("ChaseNext", self.g_local_header)
		self.assertNotIn("ChasePrev", self.g_local_header)
		self.assertNotIn("GetChaseTarget", self.g_local_header)
		self.assertNotIn("chase_target", self.g_local_header)
		self.assertNotIn("update_chase", self.g_local_header)
		self.assertIn("remote_view_aux_entity", self.g_local_header)
		self.assertIn("remote_view_aux_flag", self.g_local_header)
		self.assertNotIn("void G_SetSpectatorStats", self.p_hud_source)
		self.assertNotIn("void G_CheckChaseStats", self.p_hud_source)
		self.assertNotIn("SOURCE=.\\g_chase.c", self.game_001_source)
		self.assertNotIn("SOURCE=.\\g_chase.c", self.game_dsp_source)

	def test_putclientinserver_clears_unresolved_remote_view_tail_slots(self) -> None:
		self.assertIn("client->remote_view_aux_entity = NULL;", self.p_client_source)
		self.assertIn("client->remote_view_aux_flag = false;", self.p_client_source)


if __name__ == "__main__":
	unittest.main()
