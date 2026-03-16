import re
from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
P_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "p_weapon.c"
M_SOLDIER_SOURCE = REPO_ROOT / "src" / "game" / "m_soldier.c"
G_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "g_weapon.c"
G_LOCAL_HEADER = REPO_ROOT / "src" / "game" / "g_local.h"
G_CAMERA_SOURCE = REPO_ROOT / "src" / "game" / "g_camera.c"
G_SAVE_SOURCE = REPO_ROOT / "src" / "game" / "g_save.c"
P_CLIENT_SOURCE = REPO_ROOT / "src" / "game" / "p_client.c"
P_VIEW_SOURCE = REPO_ROOT / "src" / "game" / "p_view.c"


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


class DeatomizerRetailRegression(unittest.TestCase):
	@classmethod
	def setUpClass(cls) -> None:
		cls.p_weapon_source = P_WEAPON_SOURCE.read_text(encoding="utf-8")
		cls.m_soldier_source = M_SOLDIER_SOURCE.read_text(encoding="utf-8")
		cls.g_weapon_source = G_WEAPON_SOURCE.read_text(encoding="utf-8")
		cls.g_local_header = G_LOCAL_HEADER.read_text(encoding="utf-8")
		cls.g_camera_source = G_CAMERA_SOURCE.read_text(encoding="utf-8")
		cls.g_save_source = G_SAVE_SOURCE.read_text(encoding="utf-8")
		cls.p_client_source = P_CLIENT_SOURCE.read_text(encoding="utf-8")
		cls.p_view_source = P_VIEW_SOURCE.read_text(encoding="utf-8")

	def test_player_helper_matches_retail_fire_flow(self) -> None:
		helper_block = extract_function_block(self.p_weapon_source, "Weapon_Deatomizer_FireHelper")

		self.assertIn("ent->client->pers.inventory[ent->client->ammo_index] -= 10;", helper_block)
		self.assertIn("if (is_quad)", helper_block)
		self.assertIn("damage *= 4;", helper_block)
		self.assertIn("fire_deatom(ent, start, forward, damage, 1000);", helper_block)
		self.assertIn("gi.WriteByte(MZ_RAILGUN | is_silenced);", helper_block)
		self.assertIn('gi.sound(ent, CHAN_VOICE, gi.soundindex("deatom/dfire.wav"), volume,', helper_block)
		self.assertIn("PlayerNoise(ent, start, PNOISE_WEAPON);", helper_block)
		self.assertIn("NoAmmoWeaponChange(ent);", helper_block)

	def test_player_wrapper_stays_thin_and_advances_frame(self) -> None:
		wrapper_block = extract_function_block(self.p_weapon_source, "Weapon_Deatomizer_Fire")

		self.assertIn("damage = (rand() % 30) + 90;", wrapper_block)
		self.assertIn("damage = (rand() % 80) + 120;", wrapper_block)
		self.assertIn("Weapon_Deatomizer_FireHelper(ent, damage);", wrapper_block)
		self.assertIn("ent->client->ps.gunframe++;", wrapper_block)
		self.assertNotIn("NoAmmoWeaponChange", wrapper_block)
		self.assertNotIn("pers.inventory", wrapper_block)
		self.assertNotIn("fire_deatom(", wrapper_block)
		self.assertNotIn("svc_muzzleflash", wrapper_block)

	def test_weapon_wrapper_uses_retail_frame_tables(self) -> None:
		self.assertRegex(
			self.p_weapon_source,
			re.compile(
				r"void Weapon_Deatomizer\s*\(edict_t \*ent\)\s*\{"
				r"\s*static int\s+pause_frames\[\]\s*=\s*\{32,\s*0\};"
				r"\s*static int\s+fire_frames\[\]\s*=\s*\{12,\s*0\};"
				r"\s*Weapon_Generic\s*\(\s*ent,\s*11,\s*21,\s*43,\s*49,\s*pause_frames,\s*fire_frames,"
				r"\s*Weapon_Deatomizer_Fire\s*\);",
				re.DOTALL,
			),
		)

	def test_soldier_fire_uses_skin_band_and_monster_deatom_wrapper(self) -> None:
		fire_block = extract_function_block(self.m_soldier_source, "soldier_fire")

		self.assertIn("else if (self->s.skinnum >= 6)", fire_block)
		self.assertIn("monster_fire_deatom (self, start, aim, 50, 600);", fire_block)
		self.assertIn("gi.WriteByte (svc_muzzleflash2);", fire_block)
		self.assertNotIn("self->count", fire_block)
		self.assertNotIn("fire_deatomizer", fire_block)

	def test_deatom_soldier_spawn_matches_retail_stats_and_precache(self) -> None:
		spawn_block = extract_function_block(self.m_soldier_source, "SP_monster_soldier_deatom")

		self.assertIn('sound_pain_ss = gi.soundindex ("soldier/solpain3.wav");', spawn_block)
		self.assertIn('sound_death_ss = gi.soundindex ("soldier/soldeth3.wav");', spawn_block)
		self.assertIn('gi.soundindex ("soldier/solatck3.wav");', spawn_block)
		self.assertIn("self->s.skinnum = 6;", spawn_block)
		self.assertIn("self->health = 40;", spawn_block)
		self.assertIn("self->gib_health = -30;", spawn_block)
		self.assertNotIn("deatom/", spawn_block)
		self.assertNotIn("self->count", spawn_block)
		self.assertNotIn("self->monsterinfo.run", spawn_block)

	def test_legacy_deatomizer_projectile_helper_is_removed(self) -> None:
		self.assertNotIn("static void deatomizer_touch", self.g_weapon_source)
		self.assertNotIn("void fire_deatomizer", self.g_weapon_source)
		self.assertNotIn("void fire_deatomizer", self.g_local_header)

	def test_misc_deatomizer_spawns_alias_retail_camera_spawns(self) -> None:
		control_spawn = extract_function_block(self.g_camera_source, "SP_misc_deatomizer_control")
		target_spawn = extract_function_block(self.g_camera_source, "SP_misc_deatomizer_target")

		self.assertIn("SP_misc_camera(self);", control_spawn)
		self.assertIn("SP_misc_camera_target(self);", target_spawn)

	def test_camera_runtime_moved_out_of_g_weapon(self) -> None:
		self.assertNotIn("deatomizer_control_remote_view_cmd", self.g_weapon_source)
		self.assertNotIn("deatomizer_control_attach_client", self.g_weapon_source)
		self.assertNotIn("deatomizer_control_detach_client", self.g_weapon_source)
		self.assertNotIn("deatomizer_move_step", self.g_weapon_source)
		self.assertNotIn("deatomizer_control_activate", self.g_weapon_source)
		self.assertNotIn("deatomizer_control_deactivate", self.g_weapon_source)
		self.assertNotIn("deatomizer_control_use", self.g_weapon_source)
		self.assertNotIn("deatomizer_control_think", self.g_weapon_source)
		self.assertNotIn("deatomizer_target_use", self.g_weapon_source)
		self.assertNotIn("deatomizer_target_think", self.g_weapon_source)
		self.assertNotIn("SP_misc_deatomizer_control", self.g_weapon_source)
		self.assertNotIn("SP_misc_deatomizer_target", self.g_weapon_source)

	def test_remote_view_alias_support_matches_recovered_camera_attach_flow(self) -> None:
		cmd_block = extract_function_block(self.g_camera_source, "Camera_RemoteViewCmd")
		attach_block = extract_function_block(self.g_camera_source, "Camera_AttachClient")
		detach_block = extract_function_block(self.g_camera_source, "Camera_DetachClient")
		setup_block = extract_function_block(self.g_camera_source, "DummyBody_Setup")
		teardown_block = extract_function_block(self.g_camera_source, "DummyBody_Teardown")
		apply_state_block = extract_function_block(self.g_camera_source, "RemoteView_ApplyClientState")
		attach_helper_block = extract_function_block(self.g_camera_source, "RemoteView_AttachController")
		detach_helper_block = extract_function_block(self.g_camera_source, "RemoteView_DetachController")
		begin_block = extract_function_block(self.g_camera_source, "RemoteView_Begin")
		end_block = extract_function_block(self.g_camera_source, "RemoteView_End")
		postframe_block = extract_function_block(self.g_camera_source, "RemoteView_ClientPostFrame")
		read_level_block = extract_function_block(self.g_save_source, "ReadLevel")
		client_think_block = extract_function_block(self.p_client_source, "ClientThink")
		end_server_frame_block = extract_function_block(self.p_view_source, "ClientEndServerFrame")

		self.assertIn("qboolean remote_view_active;", self.g_local_header)
		self.assertIn("void (*remote_view_cmd_hook)(struct edict_s *ent, usercmd_t *ucmd);", self.g_local_header)
		self.assertIn("edict_t *remote_view_body;", self.g_local_header)
		self.assertIn("union {", self.g_local_header)
		self.assertIn("edict_t *remote_view_entity;", self.g_local_header)
		self.assertIn("edict_t *turret;", self.g_local_header)
		self.assertIn("int remote_view_state_1;", self.g_local_header)
		self.assertIn("int remote_view_state_2;", self.g_local_header)
		self.assertIn("float remote_view_timer;", self.g_local_header)
		self.assertIn("int remote_view_saved_gunindex;", self.g_local_header)
		self.assertIn("void RemoteView_AttachController(edict_t *ent, edict_t *viewent,", self.g_local_header)
		self.assertIn("void RemoteView_DetachController(edict_t *ent, edict_t *viewent);", self.g_local_header)
		self.assertNotIn("remote_view_state_hook", self.g_local_header)
		self.assertNotIn("camera_state_t", self.g_local_header)
		self.assertNotIn("edict_t *camera;", self.g_local_header)
		self.assertNotIn("camera_freeze", self.g_local_header)
		self.assertNotIn("camera_endtime", self.g_local_header)

		self.assertIn("camera = ent->client->remote_view_entity;", cmd_block)
		self.assertIn("if (!(camera->spawnflags & 1))", cmd_block)
		self.assertIn("ucmd->angles[0] = 0;", cmd_block)
		self.assertIn("ucmd->angles[1] = 0;", cmd_block)
		self.assertIn("ucmd->angles[2] = 0;", cmd_block)
		self.assertIn("ucmd->forwardmove = 0;", cmd_block)
		self.assertIn("ucmd->sidemove = 0;", cmd_block)
		self.assertIn("ucmd->upmove = 0;", cmd_block)
		self.assertIn("ucmd->buttons &= 0xfc;", cmd_block)

		self.assertIn("RemoteView_AttachController(player, camera, Camera_RemoteViewCmd);", attach_block)
		self.assertIn("RemoteView_DetachController(player, camera);", detach_block)
		self.assertIn("if (ent->client->remote_view_entity)", attach_helper_block)
		self.assertIn("RemoteView_Begin(ent, viewent);", attach_helper_block)
		self.assertIn("ent->client->remote_view_entity = viewent;", attach_helper_block)
		self.assertIn("ent->client->remote_view_cmd_hook = cmd_hook;", attach_helper_block)
		self.assertIn("if (ent->client->remote_view_entity != viewent)", detach_helper_block)
		self.assertIn("RemoteView_End(ent);", detach_helper_block)
		self.assertIn("ent->client->remote_view_entity = NULL;", detach_helper_block)
		self.assertIn('body->classname = "dummy_body";', setup_block)
		self.assertIn("player->client->remote_view_body = body;", setup_block)
		self.assertIn("body->enemy = player;", setup_block)
		self.assertIn("player->client->remote_view_active = true;", setup_block)
		self.assertIn("player->svflags |= SVF_NOCLIENT;", setup_block)
		self.assertIn("player->client->remote_view_body = NULL;", teardown_block)
		self.assertIn("player->client->remote_view_active = false;", teardown_block)
		self.assertIn("player->svflags &= ~SVF_NOCLIENT;", teardown_block)
		self.assertIn("G_FreeEdict(body);", teardown_block)
		self.assertIn("DummyBody_Setup(ent);", begin_block)
		self.assertIn("ent->client->remote_view_cmd_hook = NULL;", begin_block)
		self.assertIn("(void)viewent;", begin_block)
		self.assertIn("ent->client->remote_view_state_1 = 0;", begin_block)
		self.assertIn("ent->client->remote_view_state_2 = 0;", begin_block)
		self.assertIn("ent->client->remote_view_timer = 0.0f;", begin_block)
		self.assertIn("ent->client->remote_view_saved_gunindex = ent->client->ps.gunindex;", begin_block)
		self.assertIn("ent->client->ps.gunindex = 0;", begin_block)
		self.assertIn("DummyBody_Teardown(ent);", end_block)
		self.assertIn("ent->client->remote_view_cmd_hook = NULL;", end_block)
		self.assertIn("ent->client->remote_view_state_1 = 0;", end_block)
		self.assertIn("ent->client->remote_view_state_2 = 0;", end_block)
		self.assertIn("ent->client->remote_view_timer = 0.0f;", end_block)
		self.assertIn("ent->client->ps.gunindex = ent->client->remote_view_saved_gunindex;", end_block)
		self.assertIn("ent->client->remote_view_saved_gunindex = 0;", end_block)
		self.assertIn("RemoteView_ApplyClientState(ent, viewent);", postframe_block)
		self.assertIn("ent->client->ps.viewoffset[0] = (float)ent->client->remote_view_state_1;", apply_state_block)
		self.assertIn("ent->client->ps.viewoffset[1] = (float)ent->client->remote_view_state_2;", apply_state_block)
		self.assertIn("ent->client->ps.viewoffset[2] = ent->client->remote_view_timer;", apply_state_block)
		self.assertIn("ent->client->ps.pmove.pm_type = PM_FREEZE;", apply_state_block)
		self.assertIn("if (client->remote_view_cmd_hook)", client_think_block)
		self.assertIn("client->remote_view_cmd_hook(ent, ucmd);", client_think_block)
		self.assertIn("if (!ent->client->remote_view_active)", end_server_frame_block)
		self.assertIn("Camera_ClientPostFrame(ent);", end_server_frame_block)
		self.assertNotIn("G_RestoreRTDUTurretLinks", self.g_save_source)
		self.assertNotIn('{"remote_view_entity", CLOFS(remote_view_entity), F_EDICT},', self.g_save_source)
		self.assertIn("ent->client->pers.connected = false;", read_level_block)
		self.assertNotIn("camera_state", self.p_client_source)
		self.assertNotIn("camera_freeze", self.p_client_source)


if __name__ == "__main__":
	unittest.main()
