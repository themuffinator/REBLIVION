import re
from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
P_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "p_weapon.c"
G_ITEMS_SOURCE = REPO_ROOT / "src" / "game" / "g_items.c"
G_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "g_weapon.c"
G_LOCAL_HEADER = REPO_ROOT / "src" / "game" / "g_local.h"
P_CLIENT_SOURCE = REPO_ROOT / "src" / "game" / "p_client.c"
P_HUD_SOURCE = REPO_ROOT / "src" / "game" / "p_hud.c"


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


class PlasmaRifleRetailRegression(unittest.TestCase):
	@classmethod
	def setUpClass(cls) -> None:
		cls.p_weapon_source = P_WEAPON_SOURCE.read_text(encoding="utf-8")
		cls.g_items_source = G_ITEMS_SOURCE.read_text(encoding="utf-8")
		cls.g_weapon_source = G_WEAPON_SOURCE.read_text(encoding="utf-8")
		cls.g_local_header = G_LOCAL_HEADER.read_text(encoding="utf-8")
		cls.p_client_source = P_CLIENT_SOURCE.read_text(encoding="utf-8")
		cls.p_hud_source = P_HUD_SOURCE.read_text(encoding="utf-8")

	def test_shared_helper_matches_recovered_retail_flow(self) -> None:
		helper_block = extract_function_block(self.p_weapon_source, "Weapon_Plasma_Fire")

		self.assertIn("if (is_quad)", helper_block)
		self.assertIn("damage *= 4;", helper_block)
		self.assertIn("VectorSet(offset, g_offset[0] + 16, g_offset[1] + 8,", helper_block)
		self.assertIn("ent->viewheight - 8 + g_offset[2]);", helper_block)
		self.assertIn("fire_plasma_bolt(ent, start, forward, damage, 2000, plasma_mode);", helper_block)
		self.assertIn('ammo = FindItem("PistolPlasma");', helper_block)
		self.assertIn('ammo = FindItem("Rifle Plasma");', helper_block)
		self.assertIn("ent->client->pers.inventory[ITEM_INDEX(ammo)] -= ammo_usage;", helper_block)
		self.assertIn("gi.WriteByte(MZ_BLASTER2 | is_silenced);", helper_block)
		self.assertIn("PlayerNoise(ent, start, PNOISE_WEAPON);", helper_block)

	def test_shared_plasma_offset_matches_retail_zero_vector(self) -> None:
		self.assertRegex(
			self.p_weapon_source,
			re.compile(r"static vec3_t\s+plasma_offset\s*=\s*\{0,\s*0,\s*0\};"),
		)

	def test_plasma_rifle_fire_wrapper_stays_thin(self) -> None:
		rifle_fire_block = extract_function_block(self.p_weapon_source, "Weapon_PlasmaRifle_Fire")

		self.assertIn("damage = 50;", rifle_fire_block)
		self.assertIn("damage = 35;", rifle_fire_block)
		self.assertIn("Weapon_Plasma_Fire(ent, plasma_offset, damage, 1);", rifle_fire_block)
		self.assertIn("ent->client->ps.gunframe++;", rifle_fire_block)
		self.assertIn(
			'gi.sound(ent, CHAN_VOICE, gi.soundindex("plasma2/fire.wav"), volume, ATTN_NORM, 0);',
			rifle_fire_block,
		)
		self.assertNotIn("fire_plasma_bolt", rifle_fire_block)
		self.assertNotIn("PlayerNoise", rifle_fire_block)
		self.assertNotIn("pers.inventory", rifle_fire_block)
		self.assertNotIn("is_quad", rifle_fire_block)

	def test_plasma_rifle_wrapper_uses_recovered_frames(self) -> None:
		self.assertRegex(
			self.p_weapon_source,
			re.compile(
				r"void Weapon_PlasmaRifle\s*\(edict_t \*ent\)\s*\{"
				r"\s*static int\s+pause_frames\[\]\s*=\s*\{11,\s*18,\s*24,\s*0\};"
				r"\s*static int\s+fire_frames\[\]\s*=\s*\{9,\s*0\};"
				r"\s*Weapon_Generic\s*\(\s*ent,\s*7,\s*10,\s*24,\s*32,\s*pause_frames,\s*fire_frames,\s*Weapon_PlasmaRifle_Fire\s*\);",
				re.DOTALL,
			),
		)

	def test_shared_helper_drives_both_player_plasma_wrappers(self) -> None:
		pistol_fire_block = extract_function_block(self.p_weapon_source, "Weapon_PlasmaPistol_Fire")

		self.assertIn("Weapon_Plasma_Fire(ent, plasma_offset, damage, 0);", pistol_fire_block)
		self.assertNotIn("fire_plasma_bolt", pistol_fire_block)
		self.assertNotIn("pers.inventory", pistol_fire_block)

	def test_shared_projectile_touch_matches_retail_hit_effect_branch(self) -> None:
		touch_block = extract_function_block(self.g_weapon_source, "plasma_bolt_touch")

		self.assertIn('hit_sound = gi.soundindex("plasma2/hit.wav");', touch_block)
		self.assertIn('hit_sound = gi.soundindex("plasma1/hit.wav");', touch_block)
		self.assertIn("mod = (self->spawnflags & 1) ? MOD_PLASMA_RIFLE : MOD_PLASMA_PISTOL;", touch_block)
		self.assertIn("gi.WriteByte(TE_BLASTER2);", touch_block)
		self.assertIn("gi.WritePosition(self->s.origin);", touch_block)
		self.assertIn("gi.WriteDir(plane->normal);", touch_block)
		self.assertIn("gi.WriteDir(vec3_origin);", touch_block)
		self.assertIn("gi.multicast(self->s.origin, MULTICAST_PVS);", touch_block)

	def test_plasma_pistol_wrapper_uses_recovered_frames(self) -> None:
		self.assertRegex(
			self.p_weapon_source,
			re.compile(
				r"void Weapon_PlasmaPistol\s*\(edict_t \*ent\)\s*\{"
				r"\s*static int\s+pause_frames\[\]\s*=\s*\{20,\s*32,\s*0\};"
				r"\s*static int\s+fire_frames\[\]\s*=\s*\{7,\s*0\};"
				r"\s*Weapon_Generic\s*\(\s*ent,\s*6,\s*11,\s*32,\s*40,\s*pause_frames,\s*fire_frames,\s*Weapon_PlasmaPistol_Fire\s*\);",
				re.DOTALL,
			),
		)

	def test_rifle_plasma_pickup_matches_retail_upgrade_flow(self) -> None:
		pickup_block = extract_function_block(self.p_weapon_source, "Pickup_RiflePlasma")

		self.assertIn("if (!other->client)", pickup_block)
		self.assertIn("other->client->pers.max_rifleplasma += 50;", pickup_block)
		self.assertIn("other->client->pers.plasma_rifle_regen_divisor++;", pickup_block)
		self.assertIn("Add_Ammo(other, ent->item, ent->item->quantity);", pickup_block)
		self.assertNotIn("SetRespawn", pickup_block)

	def test_rifle_plasma_item_surface_matches_retail_item_table(self) -> None:
		self.assertIn('qboolean Pickup_RiflePlasma(edict_t *ent, edict_t *other);', self.g_items_source)
		start = self.g_items_source.index('{"ammo_rifleplasma"')
		end = self.g_items_source.index('/* precache */ ""},', start)
		item_block = self.g_items_source[start:end]

		self.assertRegex(
			item_block,
			re.compile(r'\{"ammo_rifleplasma",\s*Pickup_RiflePlasma,\s*NULL,\s*NULL,\s*NULL,', re.DOTALL),
		)
		self.assertIn('"misc/am_pkup.wav"', item_block)
		self.assertIn('"models/items/plasmapack/tris.md2"', item_block)
		self.assertIn('"a_plasma2"', item_block)
		self.assertIn('"Rifle Plasma"', item_block)
		self.assertIn("IT_AMMO | IT_POWERUP", item_block)
		self.assertIn("AMMO_RIFLEPLASMA", item_block)
		self.assertRegex(item_block, re.compile(r'/\* width \*/\s*3,\s*50,\s*NULL,', re.DOTALL))

	def test_persistent_field_mapping_is_resolved(self) -> None:
		self.assertIn(
			"int plasma_rifle_regen_divisor; // retail pers slot at +0x710; incremented by Pickup_RiflePlasma",
			self.g_local_header,
		)

	def test_init_client_persistant_matches_retail_plasma_adjacent_defaults(self) -> None:
		init_block = extract_function_block(self.p_client_source, "InitClientPersistant")

		self.assertIn('item = FindItem("Plasma Pistol");', init_block)
		self.assertIn('client->pers.inventory[ITEM_INDEX(FindItem("PistolPlasma"))] = 50;', init_block)
		for field_name, value in (
			("max_bullets", 200),
			("max_shells", 100),
			("max_rockets", 50),
			("max_grenades", 50),
			("max_mines", 25),
			("max_cells", 200),
			("max_slugs", 50),
			("max_pistolplasma", 50),
			("max_rifleplasma", 50),
			("max_detpacks", 10),
			("max_dods", 2),
			("plasma_rifle_regen_divisor", 0),
		):
			self.assertRegex(
				init_block,
				re.compile(rf"client->pers\.{field_name}\s*=\s*{value};"),
			)

	def test_put_client_in_server_does_not_preserve_plasma_regen_timers(self) -> None:
		put_client_block = extract_function_block(self.p_client_source, "PutClientInServer")

		self.assertIn("InitClientPersistant (client);", put_client_block)
		self.assertNotIn("plasma_pistol_regen_at", put_client_block)
		self.assertNotIn("plasma_rifle_regen_at", put_client_block)
		self.assertNotIn("plasma_pistol_next_regen", put_client_block)
		self.assertNotIn("plasma_rifle_next_regen", put_client_block)

	def test_bandolier_matches_retail_caps_and_grants(self) -> None:
		bandolier_block = extract_function_block(self.g_items_source, "Pickup_Bandolier")

		self.assertIn("other->client->pers.max_bullets = 250;", bandolier_block)
		self.assertIn("other->client->pers.max_shells = 150;", bandolier_block)
		self.assertIn("other->client->pers.max_cells = 250;", bandolier_block)
		self.assertIn("other->client->pers.max_slugs = 75;", bandolier_block)
		self.assertIn('item = FindItem("Bullets");', bandolier_block)
		self.assertIn('item = FindItem("Shells");', bandolier_block)
		self.assertNotIn("max_mines", bandolier_block)
		self.assertNotIn("max_detpacks", bandolier_block)
		self.assertNotIn("max_dods", bandolier_block)
		self.assertNotIn("max_pistolplasma", bandolier_block)
		self.assertNotIn("max_rifleplasma", bandolier_block)
		self.assertNotIn('FindItem("PistolPlasma")', bandolier_block)
		self.assertNotIn('FindItem("Rifle Plasma")', bandolier_block)
		self.assertNotIn('FindItem("Mines")', bandolier_block)
		self.assertNotIn('FindItem("Detonation Pack")', bandolier_block)
		self.assertNotIn('FindItem("DOD")', bandolier_block)

	def test_pack_matches_retail_caps_and_grants(self) -> None:
		pack_block = extract_function_block(self.g_items_source, "Pickup_Pack")

		self.assertIn("other->client->pers.max_bullets = 300;", pack_block)
		self.assertIn("other->client->pers.max_shells = 200;", pack_block)
		self.assertIn("other->client->pers.max_rockets = 100;", pack_block)
		self.assertIn("other->client->pers.max_grenades = 100;", pack_block)
		self.assertIn("other->client->pers.max_mines = 10;", pack_block)
		self.assertIn("other->client->pers.max_cells = 300;", pack_block)
		self.assertIn("other->client->pers.max_slugs = 100;", pack_block)
		self.assertIn("other->client->pers.max_detpacks = 5;", pack_block)
		self.assertIn("other->client->pers.max_dods = 2;", pack_block)
		self.assertIn('item = FindItem("Bullets");', pack_block)
		self.assertIn('item = FindItem("Shells");', pack_block)
		self.assertIn('item = FindItem("Cells");', pack_block)
		self.assertIn('item = FindItem("Grenades");', pack_block)
		self.assertIn('item = FindItem("Rockets");', pack_block)
		self.assertIn('item = FindItem("Slugs");', pack_block)
		self.assertNotIn("max_pistolplasma", pack_block)
		self.assertNotIn("max_rifleplasma", pack_block)
		self.assertNotIn('FindItem("PistolPlasma")', pack_block)
		self.assertNotIn('FindItem("Rifle Plasma")', pack_block)
		self.assertNotIn('FindItem("Mines")', pack_block)
		self.assertNotIn('FindItem("Detonation Pack")', pack_block)
		self.assertNotIn('FindItem("DOD")', pack_block)

	def test_g_set_stats_stays_stock_timer_only(self) -> None:
		set_stats_block = extract_function_block(self.p_hud_source, "G_SetStats")

		self.assertIn("ent->client->quad_framenum > level.framenum", set_stats_block)
		self.assertIn("ent->client->invincible_framenum > level.framenum", set_stats_block)
		self.assertIn("ent->client->enviro_framenum > level.framenum", set_stats_block)
		self.assertIn("ent->client->breather_framenum > level.framenum", set_stats_block)
		self.assertIn("ent->client->ps.stats[STAT_TIMER_ICON] = 0;", set_stats_block)
		self.assertIn("ent->client->ps.stats[STAT_TIMER] = 0;", set_stats_block)
		self.assertNotIn('FindItem("PistolPlasma")', set_stats_block)
		self.assertNotIn('FindItem("Rifle Plasma")', set_stats_block)
		self.assertNotIn('FindItem("DOD")', set_stats_block)
		self.assertNotIn("plasma_pistol_next_regen", set_stats_block)
		self.assertNotIn("plasma_rifle_next_regen", set_stats_block)
		self.assertNotIn("max_dods", set_stats_block)

	def test_no_ammo_weapon_change_matches_retail_plasma_fallback(self) -> None:
		no_ammo_block = extract_function_block(self.p_weapon_source, "NoAmmoWeaponChange")

		self.assertIn('!Q_stricmp(ent->client->pers.weapon->classname, "weapon_plasma_rifle")', no_ammo_block)
		self.assertIn('FindItem ("railgun")', no_ammo_block)
		self.assertIn('FindItem ("hyperblaster")', no_ammo_block)
		self.assertIn('FindItem ("chaingun")', no_ammo_block)
		self.assertIn('FindItem ("machinegun")', no_ammo_block)
		self.assertIn('FindItem ("super shotgun")', no_ammo_block)
		self.assertIn('FindItem ("shotgun")', no_ammo_block)
		self.assertIn('FindItem ("Plasma Pistol")', no_ammo_block)
		self.assertNotIn('FindItem ("Plasma Rifle")', no_ammo_block)
		self.assertNotIn('FindItem ("Obliterator")', no_ammo_block)
		self.assertNotIn('FindItem ("Deatomizer")', no_ammo_block)
		self.assertNotIn('FindItem ("HellFury")', no_ammo_block)
		self.assertNotIn('FindItem ("Remote Detonator")', no_ammo_block)
		self.assertNotIn('FindItem("PistolPlasma")', no_ammo_block)

	def test_plasma_regen_runs_from_client_think_not_think_weapon(self) -> None:
		think_weapon_block = extract_function_block(self.p_weapon_source, "Think_Weapon")
		client_think_block = extract_function_block(self.p_client_source, "ClientThink")

		self.assertNotIn("Oblivion_UpdateWeaponRegen", think_weapon_block)
		self.assertRegex(
			client_think_block,
			re.compile(
				r"if\s*\(\s*!client->resp\.spectator\s*\)\s*"
				r"Oblivion_UpdateWeaponRegen\(ent\);",
				re.DOTALL,
			),
		)

	def test_legacy_plasma_specific_projectile_helpers_are_removed(self) -> None:
		self.assertNotIn("static void plasma_pistol_touch", self.g_weapon_source)
		self.assertNotIn("void fire_plasma_pistol", self.g_weapon_source)
		self.assertNotIn("static void plasma_rifle_touch", self.g_weapon_source)
		self.assertNotIn("void fire_plasma_rifle", self.g_weapon_source)
		self.assertNotIn("void fire_plasma_pistol", self.g_local_header)
		self.assertNotIn("void fire_plasma_rifle", self.g_local_header)


if __name__ == "__main__":
	unittest.main()
