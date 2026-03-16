import re
from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
P_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "p_weapon.c"
G_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "g_weapon.c"
G_ITEMS_SOURCE = REPO_ROOT / "src" / "game" / "g_items.c"
G_LOCAL_HEADER = REPO_ROOT / "src" / "game" / "g_local.h"
G_OBLIVION_DEFINES = REPO_ROOT / "src" / "game" / "g_oblivion_defines.h"
G_CMDS_SOURCE = REPO_ROOT / "src" / "game" / "g_cmds.c"
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


class HellfuryRetailRegression(unittest.TestCase):
	@classmethod
	def setUpClass(cls) -> None:
		cls.p_weapon_source = P_WEAPON_SOURCE.read_text(encoding="utf-8")
		cls.g_weapon_source = G_WEAPON_SOURCE.read_text(encoding="utf-8")
		cls.g_items_source = G_ITEMS_SOURCE.read_text(encoding="utf-8")
		cls.g_local_header = G_LOCAL_HEADER.read_text(encoding="utf-8")
		cls.g_oblivion_defines = G_OBLIVION_DEFINES.read_text(encoding="utf-8")
		cls.g_cmds_source = G_CMDS_SOURCE.read_text(encoding="utf-8")
		cls.p_client_source = P_CLIENT_SOURCE.read_text(encoding="utf-8")

	def test_hellfury_item_routes_to_retail_obliterator_wrapper(self) -> None:
		start = self.g_items_source.index('{"weapon_hellfury"')
		end = self.g_items_source.index("/*QUAKED weapon_hyperblaster", start)
		item_block = self.g_items_source[start:end]

		self.assertIn("Weapon_Obliterator", item_block)
		self.assertIn('"HellFury"', item_block)
		self.assertIn('"Rockets"', item_block)
		self.assertIn("WEAP_HELLFURY", item_block)
		self.assertIn("models/objects/rocket/tris.md2", item_block)
		self.assertNotIn("Weapon_Hellfury", item_block)

	def test_obliterator_wrapper_uses_recovered_retail_frames(self) -> None:
		wrapper_block = extract_function_block(self.p_weapon_source, "Weapon_Obliterator")

		self.assertRegex(
			wrapper_block,
			re.compile(r"static int\s+pause_frames\[\]\s*=\s*\{28,\s*31,\s*34,\s*38,\s*0\};"),
		)
		self.assertRegex(
			wrapper_block,
			re.compile(r"static int\s+fire_frames\[\]\s*=\s*\{15,\s*16,\s*17,\s*18,\s*0\};"),
		)
		self.assertIn("Weapon_Generic (ent, 14, 27, 40, 48, pause_frames, fire_frames,", wrapper_block)
		self.assertIn("Weapon_Obliterator_Fire);", wrapper_block)

	def test_obliterator_fire_matches_retail_burst_and_offsets(self) -> None:
		fire_block = extract_function_block(self.p_weapon_source, "Weapon_Obliterator_Fire")

		self.assertIn("damage = 50 + ((rand() & 0x7fff) * 5) / 32768;", fire_block)
		self.assertIn("splash = 60;", fire_block)
		self.assertIn("if (is_quad)", fire_block)
		self.assertIn("damage *= 4;", fire_block)
		self.assertIn("splash *= 4;", fire_block)
		self.assertIn("VectorCopy (forward, ent->movedir);", fire_block)
		self.assertIn("VectorCopy (right, ent->pos1);", fire_block)
		self.assertIn("VectorCopy (up, ent->pos2);", fire_block)
		self.assertIn("VectorSet (offset, 8, 12, ent->viewheight - 8);", fire_block)
		self.assertIn("VectorSet (offset, 10, 12, ent->viewheight - 8);", fire_block)
		self.assertIn("VectorSet (offset, 10, 10, ent->viewheight - 8);", fire_block)
		self.assertIn("VectorSet (offset, 8, 10, ent->viewheight - 8);", fire_block)
		self.assertIn("fire_obliterator_projectile (ent, start, forward, damage, 900, 100.0f,", fire_block)
		self.assertIn("gi.WriteByte (MZ_ROCKET | is_silenced);", fire_block)
		self.assertIn("PlayerNoise (ent, start, PNOISE_WEAPON);", fire_block)
		self.assertNotIn("weapons/noammo.wav", fire_block)
		self.assertNotIn("fire_hellfury", fire_block)
		self.assertNotIn("fire_laser_cannon", fire_block)

	def test_obliterator_projectile_spawn_matches_retail_rocket_path(self) -> None:
		projectile_block = extract_function_block(self.g_weapon_source, "fire_obliterator_projectile")

		self.assertIn("VectorCopy(start, rocket->s.old_origin);", projectile_block)
		self.assertIn("VectorCopy(dir, rocket->move_origin);", projectile_block)
		self.assertIn("VectorCopy(dir, rocket->movedir);", projectile_block)
		self.assertIn("AngleVectors(rocket->s.angles, NULL, right, up);", projectile_block)
		self.assertIn("VectorScale(rocket->pos1, 0.1f, rocket->pos1);", projectile_block)
		self.assertIn("VectorScale(rocket->pos2, 0.1f, rocket->pos2);", projectile_block)
		self.assertIn("VectorMA(self->movedir, crandom(), self->pos1, self->movedir);", projectile_block)
		self.assertIn("VectorMA(self->movedir, crandom(), self->pos2, self->movedir);", projectile_block)
		self.assertNotIn("VectorCopy(self->movedir, rocket->movedir);", projectile_block)
		self.assertIn('rocket->s.modelindex = gi.modelindex("models/objects/rocket/tris.md2");', projectile_block)
		self.assertIn("rocket->touch = rocket_touch;", projectile_block)
		self.assertIn("rocket->style = MOD_OBLITERATOR;", projectile_block)
		self.assertIn("rocket->count = MOD_OBLITERATOR;", projectile_block)
		self.assertIn('rocket->s.sound = gi.soundindex("weapons/rockfly.wav");', projectile_block)
		self.assertIn('rocket->classname = "rocket";', projectile_block)
		self.assertIn("rocket->think = obliterator_projectile_think;", projectile_block)
		self.assertIn("rocket->nextthink = level.time + 0.2f;", projectile_block)

	def test_obliterator_projectile_think_resets_baseline_each_tick(self) -> None:
		think_block = extract_function_block(self.g_weapon_source, "obliterator_projectile_think")

		self.assertIn("VectorCopy(self->move_origin, self->movedir);", think_block)
		self.assertIn("VectorMA(self->movedir, crandom(), self->pos1, self->movedir);", think_block)
		self.assertIn("VectorMA(self->movedir, crandom(), self->pos2, self->movedir);", think_block)
		self.assertIn("VectorScale(self->movedir, self->speed, self->velocity);", think_block)
		self.assertIn("vectoangles(self->movedir, self->s.angles);", think_block)
		self.assertIn("self->nextthink = level.time + 0.2f;", think_block)
		self.assertIn("if (self->timestamp + 5.0f < level.time)", think_block)
		self.assertIn("self->think = G_FreeEdict;", think_block)

	def test_cmd_use_f_matches_retail_toggle_pairs(self) -> None:
		helper_block = extract_function_block(self.g_cmds_source, "Cmd_Use_TogglePair")
		use_block = extract_function_block(self.g_cmds_source, "Cmd_Use_f")

		self.assertIn("ent->client->pers.weapon->pickup_name", helper_block)
		self.assertIn("it = FindItem(*requested_name);", helper_block)
		self.assertIn("!ent->client->pers.inventory[ITEM_INDEX(it)]", helper_block)

		for requested, alternate in (
			("Grenades", "Mines"),
			("Mines", "Grenades"),
			("Machinegun", "Plasma Rifle"),
			("Plasma Rifle", "Machinegun"),
			("Deatomizer", "Hyperblaster"),
			("Hyperblaster", "Deatomizer"),
			("Obliterator", "BFG10K"),
			("BFG10K", "Obliterator"),
			("Detonation Pack", "Remote Detonator"),
			("Rocket Launcher", "HellFury"),
		):
			self.assertIn(f'!Q_stricmp (s, "{requested}")', use_block)
			self.assertIn(f'Cmd_Use_TogglePair (ent, &s, "{alternate}");', use_block)

		self.assertNotIn('!Q_stricmp (s, "HellFury")', use_block)

	def test_cmd_usetoggle_f_matches_retail_requested_item_cycle(self) -> None:
		append_block = extract_function_block(self.g_cmds_source, "Cmd_UseToggle_AppendToken")
		parse_block = extract_function_block(self.g_cmds_source, "Cmd_UseToggle_ParseName")
		toggle_block = extract_function_block(self.g_cmds_source, "Cmd_UseToggle_f")
		client_command_block = extract_function_block(self.g_cmds_source, "ClientCommand")

		self.assertIn("memcpy(buffer + buffer_length, token, token_length);", append_block)
		self.assertIn("if (arg[0] != '\\'')", parse_block)
		self.assertIn("arg = gi.argv (*arg_index);", parse_block)
		self.assertIn('Cmd_UseToggle_AppendToken (buffer, buffer_size, " ", 1);', parse_block)
		self.assertIn("if (length && arg[length - 1] == '\\'')", parse_block)
		self.assertIn("(*arg_index)++;", parse_block)
		self.assertIn("if (*arg_index >= argc)", parse_block)
		self.assertIn("current_index = 0;", toggle_block)
		self.assertIn("Cmd_UseToggle_ParseName (item_name, sizeof(item_name), &arg_index, argc);", toggle_block)
		self.assertIn("ent->client->pers.weapon == it", toggle_block)
		self.assertIn('gi.cprintf (ent, PRINT_HIGH, "Out of item: %s\\n", item_name);', toggle_block)
		self.assertIn("it->use (ent, it);", toggle_block)
		self.assertIn("if (ent->client->newweapon == it)", toggle_block)
		self.assertIn('else if (Q_stricmp (cmd, "usetoggle") == 0)', client_command_block)
		self.assertIn("Cmd_UseToggle_f (ent);", client_command_block)

	def test_pickup_weapon_matches_retail_hellfury_ammo_bonus(self) -> None:
		pickup_block = extract_function_block(self.p_weapon_source, "Pickup_Weapon")

		self.assertIn('else if (!Q_stricmp (ent->classname, "weapon_hellfury"))', pickup_block)
		self.assertIn("Add_Ammo (other, ammo, 16);", pickup_block)

	def test_active_runtime_path_uses_obliterator_obituary(self) -> None:
		self.assertIn("case MOD_OBLITERATOR:", self.p_client_source)
		self.assertIn("message2 = \"'s obliterator\";", self.p_client_source)

	def test_lasercannon_placeholder_scaffolding_is_removed(self) -> None:
		self.assertNotIn("weapon_lasercannon", self.g_items_source)
		self.assertNotIn("OBLIVION_ENABLE_WEAPON_LASERCANNON", self.g_items_source)
		self.assertNotIn("OBLIVION_ENABLE_WEAPON_LASERCANNON", self.g_local_header)
		self.assertNotIn("WEAP_LASERCANNON", self.g_local_header)
		self.assertIn("#define MOD_OBLITERATOR 39", self.g_local_header)
		self.assertIn("#define MOD_LASERCANNON MOD_OBLITERATOR", self.g_local_header)
		self.assertIn("#define MOD_OBLITERATOR 39", self.g_oblivion_defines)
		self.assertIn("#define MOD_LASERCANNON MOD_OBLITERATOR", self.g_oblivion_defines)

	def test_legacy_non_retail_helpers_are_removed(self) -> None:
		for source in (self.p_weapon_source, self.g_weapon_source, self.g_items_source, self.g_local_header):
			self.assertNotIn("Weapon_Hellfury", source)
			self.assertNotIn("Weapon_LaserCannon", source)
			self.assertNotIn("fire_hellfury", source)
			self.assertNotIn("fire_laser_cannon", source)
			self.assertNotIn("hellfury_touch", source)


if __name__ == "__main__":
	unittest.main()
