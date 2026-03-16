import re
from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
P_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "p_weapon.c"
G_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "g_weapon.c"
G_ITEMS_SOURCE = REPO_ROOT / "src" / "game" / "g_items.c"
G_CMDS_SOURCE = REPO_ROOT / "src" / "game" / "g_cmds.c"
G_LOCAL_HEADER = REPO_ROOT / "src" / "game" / "g_local.h"
G_OBLIVION_DEFINES_HEADER = REPO_ROOT / "src" / "game" / "g_oblivion_defines.h"
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


def extract_initializer(block_source: str, classname: str) -> str:
    pattern = re.compile(r"\{[^{}]*\"" + re.escape(classname) + r"\"[^{}]*\}", re.S)
    match = pattern.search(block_source)
    if not match:
        raise AssertionError(f"Initializer for {classname} not found")
    return match.group(0)


class RemoteDetonatorRetailRegression(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        cls.p_weapon_source = P_WEAPON_SOURCE.read_text(encoding="utf-8")
        cls.g_weapon_source = G_WEAPON_SOURCE.read_text(encoding="utf-8")
        cls.g_items_source = G_ITEMS_SOURCE.read_text(encoding="utf-8")
        cls.g_cmds_source = G_CMDS_SOURCE.read_text(encoding="utf-8")
        cls.g_local_header = G_LOCAL_HEADER.read_text(encoding="utf-8")
        cls.g_oblivion_defines_header = G_OBLIVION_DEFINES_HEADER.read_text(
            encoding="utf-8"
        )
        cls.p_client_source = P_CLIENT_SOURCE.read_text(encoding="utf-8")

    def test_detonation_pack_fire_matches_retail_split(self) -> None:
        fire_block = extract_function_block(
            self.p_weapon_source, "Weapon_DetonationPack_Fire"
        )

        self.assertIn("if (ent->client->ps.gunframe == 14)", fire_block)
        self.assertIn('item = FindItem ("Remote Detonator");', fire_block)
        self.assertIn("ent->client->newweapon = item;", fire_block)
        self.assertIn("ChangeWeapon (ent);", fire_block)
        self.assertIn("damage = is_quad ? 800 : 400;", fire_block)
        self.assertIn("damage_radius = is_quad ? 600.0f : 300.0f;", fire_block)
        self.assertIn("VectorSet (offset, 8, -5, ent->viewheight);", fire_block)
        self.assertIn("VectorScale (forward, -2, ent->client->kick_origin);", fire_block)
        self.assertIn("ent->client->kick_angles[0] = -1;", fire_block)
        self.assertIn(
            "fire_detpack (ent, start, forward, damage, damage_radius, 400.0f, 0.0f);",
            fire_block,
        )
        self.assertIn('item = FindItem ("Detonation Pack");', fire_block)
        self.assertNotIn("RemoteChargesAvailable", fire_block)

    def test_wrappers_use_retail_frame_bands(self) -> None:
        detpack_block = extract_function_block(self.p_weapon_source, "Weapon_DetonationPack")
        remote_block = extract_function_block(self.p_weapon_source, "Weapon_RemoteDetonator")

        self.assertIn("static int\tpause_frames[]\t= {16, 21, 0};", detpack_block)
        self.assertIn("static int\tfire_frames[]\t= {10, 14, 0};", detpack_block)
        self.assertIn("Weapon_Generic (ent, 4, 14, 34, 39, pause_frames, fire_frames,", detpack_block)

        self.assertIn("static int\tpause_frames[]\t= {18, 23, 28, 0};", remote_block)
        self.assertIn("static int\tfire_frames[]\t= {7, 0};", remote_block)
        self.assertIn("Weapon_Generic (ent, 4, 8, 28, 33, pause_frames, fire_frames,", remote_block)

    def test_remote_detonator_reselects_detpack_and_clears_temp_slot(self) -> None:
        fire_block = extract_function_block(
            self.p_weapon_source, "Weapon_RemoteDetonator_Fire"
        )

        self.assertIn("for (i = 0; i < globals.num_edicts; i++)", fire_block)
        self.assertIn("if (check->owner != ent)", fire_block)
        self.assertIn('if (strcmp (check->classname, "detpack"))', fire_block)
        self.assertIn("detpack_detonate (check);", fire_block)
        self.assertIn('item = FindItem ("Detonation Pack");', fire_block)
        self.assertIn("NoAmmoWeaponChange (ent);", fire_block)
        self.assertIn("ent->client->newweapon = item;", fire_block)
        self.assertIn('item = FindItem ("Remote Detonator");', fire_block)
        self.assertIn("ent->client->pers.inventory[ITEM_INDEX(item)] = 0;", fire_block)
        self.assertNotIn("fire_detpack", fire_block)

    def test_item_table_exposes_the_retail_split(self) -> None:
        self.assertIn(
            '{"ammo_detpack", Pickup_Ammo, Use_Weapon, Drop_Ammo, Weapon_DetonationPack,',
            self.g_items_source,
        )
        initializer = extract_initializer(self.g_items_source, "weapon_remote_detonator")
        self.assertIn('{"weapon_remote_detonator", NULL, Use_Weapon, NULL,', initializer)
        self.assertIn('"misc/w_pkup.wav", NULL, 0, "models/weapons/v_detonator/tris.md2",', initializer)
        self.assertIn('/* icon */ "w_detpack"', initializer)
        self.assertIn('/* pickup */ "Remote Detonator", 0, 0, NULL, IT_WEAPON | IT_STAY_COOP, 0,', initializer)
        self.assertNotIn("Pickup_Weapon", initializer)
        self.assertNotIn("Drop_Weapon", initializer)
        self.assertNotIn('"Detonation Pack"', initializer)
        self.assertNotIn("WEAP_REMOTE_DETONATOR", initializer)

        remote_index = self.g_items_source.index('"weapon_remote_detonator"')
        self.assertNotIn("#if 0", self.g_items_source[max(0, remote_index - 80):remote_index])

    def test_use_toggle_keeps_detpack_paired_to_remote_detonator(self) -> None:
        self.assertIn(
            'else if (!Q_stricmp (s, "Detonation Pack"))',
            self.g_cmds_source,
        )
        self.assertIn(
            'Cmd_Use_TogglePair (ent, &s, "Remote Detonator");',
            self.g_cmds_source,
        )

    def test_detpack_helpers_match_retail_throw_and_explosion_flow(self) -> None:
        touch_block = extract_function_block(self.g_weapon_source, "detpack_touch")
        fire_block = extract_function_block(self.g_weapon_source, "fire_detpack")
        detonate_block = extract_function_block(self.g_weapon_source, "detpack_detonate")
        die_block = extract_function_block(self.g_weapon_source, "detpack_die")

        self.assertIn("if (damage < 70)", die_block)
        self.assertIn("self->health = 70;", die_block)
        self.assertIn("self->think = detpack_detonate;", die_block)
        self.assertIn("self->nextthink = level.time + 0.2f;", die_block)

        self.assertIn("if (other == &g_edicts[0])", touch_block)
        self.assertIn("self->movetype = MOVETYPE_NONE;", touch_block)
        self.assertIn("vectoangles (plane->normal, self->s.angles);", touch_block)
        self.assertNotIn("self->groundentity = other;", touch_block)

        self.assertIn("VectorMA (charge->velocity, 20.0f + crandom() * 10.0f, up,", fire_block)
        self.assertIn("VectorMA (charge->velocity, crandom() * 10.0f, right, charge->velocity);", fire_block)
        self.assertIn("charge->s.angles[2] = -40.0f;", fire_block)
        self.assertIn("charge->flags |= FL_NO_KNOCKBACK;", fire_block)
        self.assertIn("charge->avelocity[0] = -180.0f;", fire_block)
        self.assertIn("if (timer > 0.0f)", fire_block)
        self.assertIn("charge->think = detpack_detonate;", fire_block)
        self.assertIn("charge->nextthink = level.time + timer;", fire_block)
        self.assertIn("charge->dmg = damage;", fire_block)
        self.assertIn("charge->dmg_radius = damage_radius;", fire_block)
        self.assertNotIn("charge->s.effects |= EF_GRENADE;", fire_block)
        self.assertNotIn("charge->health = 70;", fire_block)
        self.assertNotIn("charge->max_health = 70;", fire_block)
        self.assertNotIn("charge->radius_dmg = damage;", fire_block)

        self.assertIn("PlayerNoise (self->owner, self->s.origin, PNOISE_IMPACT);", detonate_block)
        self.assertIn("T_RadiusDamage (self, self->owner ? self->owner : self, self->dmg, NULL,", detonate_block)
        self.assertIn("TE_GRENADE_EXPLOSION_WATER", detonate_block)
        self.assertIn("TE_ROCKET_EXPLOSION_WATER", detonate_block)

    def test_shared_header_exports_the_retail_detpack_interfaces(self) -> None:
        self.assertIn("void detpack_detonate(edict_t *self);", self.g_local_header)
        self.assertIn(
            "edict_t *fire_detpack(edict_t *self, vec3_t start, vec3_t aimdir, int damage,",
            self.g_local_header,
        )
        self.assertIn("float damage_radius, float speed, float timer);", self.g_local_header)
        self.assertNotIn("void remote_detonator_trigger(edict_t *owner);", self.g_local_header)

    def test_remote_detonator_mod_constant_remains_header_only(self) -> None:
        self.assertIn(
            "#define MOD_REMOTE_DETONATOR MOD_DETPACK", self.g_local_header
        )
        self.assertIn(
            "#define MOD_REMOTE_DETONATOR MOD_DETPACK",
            self.g_oblivion_defines_header,
        )
        self.assertIn("case MOD_DETPACK:", self.p_client_source)
        self.assertIn("message = \"stepped on\";", self.p_client_source)
        self.assertIn("case MOD_REMOTE_CANNON:", self.p_client_source)
        self.assertIn("message = \"caught some of\";", self.p_client_source)
        self.assertNotIn("case MOD_REMOTE_DETONATOR:", self.p_client_source)


if __name__ == "__main__":
    unittest.main()
