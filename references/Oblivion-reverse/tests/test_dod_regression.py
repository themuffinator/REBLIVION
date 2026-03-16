import re
from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
P_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "p_weapon.c"
G_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "g_weapon.c"
G_ITEMS_SOURCE = REPO_ROOT / "src" / "game" / "g_items.c"
G_TARGET_SOURCE = REPO_ROOT / "src" / "game" / "g_target.c"
G_LOCAL_HEADER = REPO_ROOT / "src" / "game" / "g_local.h"
G_OBLIVION_DEFINES = REPO_ROOT / "src" / "game" / "g_oblivion_defines.h"
G_SAVE_SOURCE = REPO_ROOT / "src" / "game" / "g_save.c"
P_CLIENT_SOURCE = REPO_ROOT / "src" / "game" / "p_client.c"


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


class DonutOfDestructionRetailRegression(unittest.TestCase):
	@classmethod
	def setUpClass(cls) -> None:
		cls.p_weapon_source = P_WEAPON_SOURCE.read_text(encoding="utf-8")
		cls.g_weapon_source = G_WEAPON_SOURCE.read_text(encoding="utf-8")
		cls.g_items_source = G_ITEMS_SOURCE.read_text(encoding="utf-8")
		cls.g_target_source = G_TARGET_SOURCE.read_text(encoding="utf-8")
		cls.g_local_header = G_LOCAL_HEADER.read_text(encoding="utf-8")
		cls.g_oblivion_defines = G_OBLIVION_DEFINES.read_text(encoding="utf-8")
		cls.g_save_source = G_SAVE_SOURCE.read_text(encoding="utf-8")
		cls.p_client_source = P_CLIENT_SOURCE.read_text(encoding="utf-8")

	def test_retail_mod_band_matches_recovered_obituary_tables(self) -> None:
		for header in (self.g_local_header, self.g_oblivion_defines):
			self.assertIn("#define MOD_MINE 30", header)
			self.assertIn("#define MOD_TARGET_RAILGUN 34", header)
			self.assertIn("#define MOD_DEATOMIZER 35", header)
			self.assertIn("#define MOD_DISINTEGRATOR MOD_DEATOMIZER", header)
			self.assertIn("#define MOD_DEATOMIZER_SPLASH MOD_DEATOMIZER", header)
			self.assertIn("#define MOD_PLASMA_PISTOL 36", header)
			self.assertIn("#define MOD_PLASMA_RIFLE 37", header)
			self.assertIn("#define MOD_DETPACK 38", header)
			self.assertIn("#define MOD_REMOTE_DETONATOR MOD_DETPACK", header)
			self.assertIn("#define MOD_OBLITERATOR 39", header)
			self.assertIn("#define MOD_LASERCANNON MOD_OBLITERATOR", header)
			self.assertIn("#define MOD_HELLFURY MOD_OBLITERATOR", header)
			self.assertIn("#define MOD_DONUT 40", header)
			self.assertIn("#define MOD_REMOTE_CANNON 41", header)
			self.assertIn("#define MOD_MINE_SPLASH 42", header)

	def test_dod_client_hook_stays_on_the_existing_retail_slot(self) -> None:
		self.assertIn(
			"void (*remote_view_cmd_hook)(struct edict_s *ent, usercmd_t *ucmd);",
			self.g_local_header,
		)
		self.assertIn(
			'{"remote_view_cmd_hook", CLOFS(remote_view_cmd_hook), F_FUNCTION},',
			self.g_save_source,
		)
		self.assertNotIn("remote_view_state_hook", self.g_local_header)
		self.assertNotIn("remote_view_state_hook", self.g_save_source)

	def test_dod_client_reset_zeroes_movement_input(self) -> None:
		reset_block = extract_function_block(self.g_weapon_source, "dod_client_reset")

		self.assertIn("(void)self;", reset_block)
		self.assertIn("if (!ucmd)", reset_block)
		self.assertIn("ucmd->forwardmove = 0;", reset_block)
		self.assertIn("ucmd->sidemove = 0;", reset_block)
		self.assertIn("ucmd->upmove = 0;", reset_block)
		self.assertNotIn("ucmd->angles", reset_block)

	def test_dod_pulse_helper_matches_retail_growth_and_cleanup(self) -> None:
		pulse_block = extract_function_block(self.g_weapon_source, "dod_pulse_think")

		self.assertIn("if (self->s.frame < 10)", pulse_block)
		self.assertIn("self->s.frame++;", pulse_block)
		self.assertNotIn("self->count", pulse_block)
		self.assertIn("self->dmg += 25;", pulse_block)
		self.assertIn("self->dmg_radius += 32.0f;", pulse_block)
		self.assertIn("T_RadiusDamage(self, self->owner, self->dmg, self->owner,", pulse_block)
		self.assertIn("self->dmg_radius, MOD_DONUT);", pulse_block)
		self.assertEqual(pulse_block.count("level.time + 0.1f"), 2)
		self.assertIn("self->think = G_FreeEdict;", pulse_block)
		self.assertIn("self->owner->client->remote_view_cmd_hook = NULL;", pulse_block)

	def test_fire_dod_matches_retail_stationary_pulse_entity(self) -> None:
		fire_block = extract_function_block(self.g_weapon_source, "fire_dod")

		self.assertIn("(void)dir;", fire_block)
		self.assertIn("VectorCopy(start, dod->s.origin);", fire_block)
		self.assertIn("VectorCopy(start, dod->s.old_origin);", fire_block)
		self.assertIn("VectorSet(dod->mins, -16.0f, -16.0f, -16.0f);", fire_block)
		self.assertIn("VectorSet(dod->maxs, 16.0f, 16.0f, 16.0f);", fire_block)
		self.assertIn("VectorClear(dod->s.angles);", fire_block)
		self.assertIn("VectorClear(dod->velocity);", fire_block)
		self.assertIn("dod->avelocity[YAW] = 90.0f;", fire_block)
		self.assertIn("dod->movetype = MOVETYPE_FLY;", fire_block)
		self.assertIn("dod->solid = SOLID_BBOX;", fire_block)
		self.assertIn("dod->takedamage = DAMAGE_NO;", fire_block)
		self.assertIn('dod->s.modelindex = gi.modelindex("models/objects/dod/tris.md2");', fire_block)
		self.assertIn("dod->s.frame = 0;", fire_block)
		self.assertIn("dod->s.renderfx = RF_FULLBRIGHT;", fire_block)
		self.assertIn("dod->think = dod_pulse_think;", fire_block)
		self.assertIn("dod->dmg = 50;", fire_block)
		self.assertIn("dod->dmg_radius = 64.0f;", fire_block)
		self.assertIn('dod->classname = "dod";', fire_block)
		self.assertIn('gi.sound(self, CHAN_WEAPON, gi.soundindex("dod/dod.wav"), 1, ATTN_NORM, 0);', fire_block)
		self.assertIn("self->client->remote_view_cmd_hook = dod_client_reset;", fire_block)
		self.assertNotIn("dod->health", fire_block)
		self.assertNotIn("check_dodge", fire_block)
		self.assertNotIn("MOVETYPE_FLYMISSILE", fire_block)

	def test_legacy_dod_projectile_helpers_are_removed(self) -> None:
		self.assertNotIn("static void dod_explode", self.g_weapon_source)
		self.assertNotIn("static void dod_touch", self.g_weapon_source)
		self.assertNotIn("sound/dod/DoD_hum.wav", self.g_weapon_source)

	def test_player_wrapper_stays_thin_and_uses_retail_origin(self) -> None:
		fire_block = extract_function_block(self.p_weapon_source, "Weapon_DOD_Fire")

		self.assertIn("ent->client->ps.gunframe++;", fire_block)
		self.assertIn("AngleVectors(ent->s.angles, forward, NULL, NULL);", fire_block)
		self.assertIn("fire_dod(ent, ent->s.origin, forward);", fire_block)
		self.assertIn('ammo = FindItem("DOD");', fire_block)
		self.assertIn("ent->client->pers.inventory[ITEM_INDEX(ammo)]--;", fire_block)
		self.assertNotIn("P_ProjectSource", fire_block)
		self.assertNotIn("PlayerNoise", fire_block)
		self.assertNotIn("svc_muzzleflash", fire_block)
		self.assertNotIn("is_quad", fire_block)
		self.assertNotIn("weapons/noammo.wav", fire_block)

	def test_weapon_wrapper_uses_recovered_frame_bands(self) -> None:
		self.assertRegex(
			self.p_weapon_source,
			re.compile(
				r"void Weapon_DOD\s*\(edict_t \*ent\)\s*\{"
				r"\s*static int\s+pause_frames\[\]\s*=\s*\{26,\s*0\};"
				r"\s*static int\s+fire_frames\[\]\s*=\s*\{13,\s*0\};"
				r"\s*Weapon_Generic\s*\(\s*ent,\s*10,\s*15,\s*35,\s*46,\s*pause_frames,\s*fire_frames,\s*Weapon_DOD_Fire\s*\);",
				re.DOTALL,
			),
		)

	def test_item_table_matches_retail_dod_surface(self) -> None:
		weapon_start = self.g_items_source.index('{"weapon_dod"')
		weapon_end = self.g_items_source.index('/* precache */ "sound/dod/hum.wave sound/dod/dod.wav"},', weapon_start)
		weapon_block = self.g_items_source[weapon_start:weapon_end]

		ammo_start = self.g_items_source.index('{"ammo_dod"')
		ammo_end = self.g_items_source.index('/* precache */ "sound/dod/hum.wave sound/dod/dod.wav"},', ammo_start)
		ammo_block = self.g_items_source[ammo_start:ammo_end]

		for block in (weapon_block, ammo_block):
			self.assertIn("Pickup_Ammo, Use_Weapon, Drop_Ammo, Weapon_DOD", block)
			self.assertIn('"misc/am_pkup.wav"', block)
			self.assertIn('"models/weapons/g_dod/tris.md2"', block)
			self.assertIn('"models/weapons/v_dod/tris.md2"', block)
			self.assertIn('"a_dod"', block)
			self.assertIn('"DOD"', block)
			self.assertIn("IT_AMMO | IT_WEAPON", block)
			self.assertIn("WEAP_DONUT", block)
			self.assertIn("AMMO_DOD", block)

		self.assertRegex(weapon_block, re.compile(r'"DOD",\s*2,\s*1,\s*"DOD"', re.DOTALL))
		self.assertRegex(ammo_block, re.compile(r'/\* width \*/\s*2,\s*1,\s*"DOD"', re.DOTALL))

	def test_target_railgun_matches_recovered_retail_thin_flow(self) -> None:
		use_block = extract_function_block(self.g_target_source, "use_target_railgun")
		spawn_block = extract_function_block(self.g_target_source, "SP_target_railgun")

		self.assertIn("(void)other;", use_block)
		self.assertIn("(void)activator;", use_block)
		self.assertIn("fire_rail (self, self->s.origin, self->movedir, self->dmg, 0);", use_block)
		self.assertIn("gi.sound (self, CHAN_VOICE, self->noise_index, 1, ATTN_NORM, 0);", use_block)
		self.assertNotIn("self->wait", use_block)
		self.assertNotIn("self->timestamp", use_block)
		self.assertNotIn("self->move_origin", use_block)
		self.assertNotIn("self->moveinfo.start_origin", use_block)
		self.assertNotIn("self->move_angles", use_block)
		self.assertNotIn("self->moveinfo.start_angles", use_block)
		self.assertNotIn("VectorCompare", use_block)
		self.assertNotIn("AngleVectors", use_block)
		self.assertNotIn("self->count", use_block)
		self.assertNotIn("CHAN_WEAPON", use_block)

		self.assertIn("self->use = use_target_railgun;", spawn_block)
		self.assertIn("G_SetMovedir (self->s.angles, self->movedir);", spawn_block)
		self.assertIn('self->noise_index = gi.soundindex ("weapons/railgf1a.wav");', spawn_block)
		self.assertIn("if (!self->dmg)", spawn_block)
		self.assertIn("self->dmg = 150;", spawn_block)
		self.assertIn("self->svflags = SVF_NOCLIENT;", spawn_block)
		self.assertNotIn("self->moveinfo.start_origin", spawn_block)
		self.assertNotIn("self->moveinfo.start_angles", spawn_block)
		self.assertNotIn("self->move_origin", spawn_block)
		self.assertNotIn("self->move_angles", spawn_block)
		self.assertNotIn("self->svflags |=", spawn_block)

	def test_target_rocket_matches_recovered_retail_direct_spawn_flow(self) -> None:
		fire_block = extract_function_block(self.g_target_source, "target_rocket_fire")
		spawn_block = extract_function_block(self.g_target_source, "SP_target_rocket")

		self.assertIn("(void)other;", fire_block)
		self.assertIn("(void)activator;", fire_block)
		self.assertIn(
			"fire_rocket (self, self->s.origin, self->movedir, self->dmg,",
			fire_block,
		)
		self.assertIn("(int)self->speed, self->dmg_radius, self->count);", fire_block)
		self.assertIn("gi.sound (self, CHAN_VOICE, self->noise_index, 1, ATTN_NORM, 0);", fire_block)
		self.assertNotIn("self->move_origin", fire_block)
		self.assertNotIn("self->move_angles", fire_block)
		self.assertNotIn("AngleVectors", fire_block)
		self.assertNotIn("self->think", fire_block)
		self.assertNotIn("self->nextthink", fire_block)

		self.assertIn("self->use = target_rocket_fire;", spawn_block)
		self.assertIn("G_SetMovedir (self->s.angles, self->movedir);", spawn_block)
		self.assertIn('self->noise_index = gi.soundindex ("weapons/rocklf1a.wav");', spawn_block)
		self.assertIn("if (!self->dmg)", spawn_block)
		self.assertIn("self->dmg = 100 + (int)(random() * 20.0f);", spawn_block)
		self.assertIn("if (!self->count)", spawn_block)
		self.assertIn("self->count = 120;", spawn_block)
		self.assertIn("if (!self->dmg_radius)", spawn_block)
		self.assertIn("self->dmg_radius = 120;", spawn_block)
		self.assertIn("if (!self->speed)", spawn_block)
		self.assertIn("self->speed = 650;", spawn_block)
		self.assertIn("self->svflags = SVF_NOCLIENT;", spawn_block)
		self.assertNotIn("target_rocket_use", self.g_target_source)
		self.assertNotIn("self->delay", spawn_block)
		self.assertNotIn("self->wait", spawn_block)
		self.assertNotIn("self->random", spawn_block)
		self.assertNotIn("self->move_origin", spawn_block)
		self.assertNotIn("self->move_angles", spawn_block)

	def test_donut_obituary_matches_retail_text(self) -> None:
		self.assertIn('message = "took a bite of";', self.p_client_source)
		self.assertIn('message2 = "\'s donut";', self.p_client_source)
		self.assertRegex(
			self.p_client_source,
			re.compile(
				r"case MOD_TARGET_LASER:\s*"
				r"if \(attacker == world\)\s*"
				r'message = "saw the light";',
				re.DOTALL,
			),
		)
		self.assertIn('case MOD_TARGET_RAILGUN:', self.p_client_source)
		self.assertIn('message = "got railed";', self.p_client_source)
		self.assertIn('message = "was killed by";', self.p_client_source)
		self.assertIn('message2 = " somehow";', self.p_client_source)
		self.assertNotIn('message = "was vaporized by";', self.p_client_source)
		self.assertNotIn('message2 = "\'s DoD launcher";', self.p_client_source)


if __name__ == "__main__":
	unittest.main()
