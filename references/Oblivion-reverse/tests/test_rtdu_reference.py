import json
import re
from pathlib import Path
import unittest


def _extract_itemlist_block(source: str) -> str:
    anchor = re.search(r"gitem_t\s+itemlist\[\]\s*=", source)
    if not anchor:
        raise AssertionError("Could not locate gitem_t itemlist[] block in g_items.c")
    brace_start = source.find("{", anchor.end())
    if brace_start == -1:
        raise AssertionError("Could not locate opening brace for itemlist[]")
    depth = 0
    for idx in range(brace_start, len(source)):
        char = source[idx]
        if char == "{":
            depth += 1
        elif char == "}":
            depth -= 1
            if depth == 0:
                return source[brace_start:idx]
    raise AssertionError("Failed to locate the end of itemlist[]")


def _extract_initializer(block: str, classname: str) -> str:
    pattern = re.compile(r"\{[^{}]*\"" + re.escape(classname) + r"\"[^{}]*\}", re.S)
    match = pattern.search(block)
    if not match:
        raise AssertionError(f"Could not locate initializer for {classname}")
    return match.group(0)


def _parse_initializer_strings(initializer: str) -> list[str]:
    literals = re.findall(r"\"([^\"]+)\"", initializer)
    if len(literals) < 5:
        raise AssertionError(
            "Expected at least five string literals in the RTDU initializer"
        )
    return literals


def _load_rtdu_hlil_literals(reference_json: Path) -> dict[str, str]:
    entries = json.loads(reference_json.read_text(encoding="utf-8"))
    try:
        start_index = next(
            idx for idx, entry in enumerate(entries) if entry["value"] == "weapon_rtdu"
        )
    except StopIteration as exc:
        raise AssertionError("HLIL strings.json is missing the weapon_rtdu entry") from exc

    expected: dict[str, str] = {"classname": "weapon_rtdu"}
    for entry in entries[start_index + 1 :]:
        category = entry.get("category")
        if category == "sound_path" and "pickup_sound" not in expected:
            expected["pickup_sound"] = entry["value"]
        elif category == "model_path" and "model_path" not in expected:
            expected["model_path"] = entry["value"]
        elif category == "text_label":
            if "icon" not in expected:
                expected["icon"] = entry["value"]
            elif "pickup_text" not in expected:
                expected["pickup_text"] = entry["value"]
        elif category and category.endswith("descriptor"):
            break

        if all(
            key in expected
            for key in ("classname", "model_path", "pickup_sound", "icon", "pickup_text")
        ):
            break

    missing = [
        key
        for key in ("classname", "model_path", "pickup_sound", "icon", "pickup_text")
        if key not in expected
    ]
    if missing:
        raise AssertionError(
            f"HLIL reference JSON missing the following RTDU fields: {', '.join(missing)}"
        )
    return expected


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


class RTDUReferenceTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        repo_root = Path(__file__).resolve().parents[1]
        cls.g_rtdu_source = (repo_root / "src" / "game" / "g_rtdu.c").read_text(encoding="utf-8")
        cls.g_local_header = (repo_root / "src" / "game" / "g_local.h").read_text(encoding="utf-8")
        cls.g_main_source = (repo_root / "src" / "game" / "g_main.c").read_text(encoding="utf-8")
        cls.p_client_source = (repo_root / "src" / "game" / "p_client.c").read_text(encoding="utf-8")
        cls.g_save_source = (repo_root / "src" / "game" / "g_save.c").read_text(encoding="utf-8")

    def test_weapon_rtdu_initializer_matches_hlil(self) -> None:
        repo_root = Path(__file__).resolve().parents[1]
        g_items_source = (repo_root / "src" / "game" / "g_items.c").read_text(encoding="utf-8")
        itemlist_block = _extract_itemlist_block(g_items_source)
        initializer = _extract_initializer(itemlist_block, "weapon_rtdu")
        literals = _parse_initializer_strings(initializer)

        actual = {
            "classname": literals[0],
            "pickup_sound": literals[1],
            "model_path": literals[2],
            "icon": literals[3],
            "pickup_text": literals[4],
        }

        reference_json = repo_root / "references" / "HLIL" / "oblivion" / "interpreted" / "strings.json"
        expected = _load_rtdu_hlil_literals(reference_json)

        self.assertEqual(
            actual,
            expected,
            "weapon_rtdu initializer no longer matches HLIL references",
        )

    def test_rtdu_runtime_flow_matches_recovered_reference(self) -> None:
        pickup_block = _extract_function_block(self.g_rtdu_source, "Pickup_RTDU")
        use_block = _extract_function_block(self.g_rtdu_source, "rtdu_use")
        spawn_block = _extract_function_block(self.g_rtdu_source, "RTDU_SpawnTurret")
        think_block = _extract_function_block(self.g_rtdu_source, "RTDU_TurretThink")
        cmd_block = _extract_function_block(self.g_rtdu_source, "RTDU_RemoteViewCmd")
        tripod_block = _extract_function_block(self.g_rtdu_source, "RTDU_SpawnTripod")
        begin_block = _extract_function_block(self.g_rtdu_source, "RTDU_BeginRemoteView")
        end_block = _extract_function_block(self.g_rtdu_source, "RTDU_EndRemoteView")
        remove_block = _extract_function_block(self.g_rtdu_source, "RTDU_RemoveTurret")
        attack_block = _extract_function_block(self.g_rtdu_source, "RTDU_TurretAttack")
        init_block = _extract_function_block(self.g_rtdu_source, "RTDU_InitTurret")

        self.assertIn("if (other->client->pers.inventory[index] > 0)", pickup_block)
        self.assertIn("other->client->pers.inventory[index] = RTDU_PICKUP_COUNT;", pickup_block)

        self.assertIn('Q_stricmp(turret->classname, "RTDU") == 0', use_block)
        self.assertIn("RTDU_EndRemoteView(turret);", use_block)
        self.assertIn("RTDU_BeginRemoteView(turret);", use_block)
        self.assertIn("RTDU_SpawnTurret(ent);", use_block)
        self.assertNotIn("turret->inuse", use_block)
        self.assertNotIn("turret->classname &&", use_block)

        self.assertIn("VectorCopy(owner->s.origin, turret->s.origin);", spawn_block)
        self.assertIn("turret->s.angles[YAW] = owner->s.angles[YAW];", spawn_block)
        self.assertNotIn("VectorCopy(owner->s.angles, turret->s.angles);", spawn_block)
        self.assertNotIn("gi.linkentity(turret);", spawn_block)
        self.assertNotIn("turret->target_ent", spawn_block)

        self.assertIn("if (self->target_ent)", think_block)
        self.assertNotIn("self->target_ent->inuse", think_block)
        self.assertNotIn("self->target_ent->s.origin[2] += RTDU_TRIPOD_Z_OFFSET;", think_block)

        self.assertIn("ucmd->forwardmove = 0;", cmd_block)
        self.assertIn("ucmd->sidemove = 0;", cmd_block)
        self.assertIn("ucmd->upmove = 0;", cmd_block)
        self.assertIn("if (!ent->client->rtdu.turret)", cmd_block)
        self.assertNotIn("remote_view_entity", cmd_block)
        self.assertIn("angle = SHORT2ANGLE(ucmd->angles[i]);", cmd_block)
        self.assertIn("for (i = 0; i < 3; i++)", cmd_block)
        self.assertIn("if (i == PITCH)", cmd_block)
        self.assertIn("angle *= (1.0f / 3.0f);", cmd_block)
        self.assertIn("ent->client->rtdu.turret->s.angles[i] = angle;", cmd_block)
        self.assertIn("ucmd->angles[i] = 0;", cmd_block)
        self.assertIn("if (ucmd->buttons & BUTTON_ATTACK)", cmd_block)
        self.assertIn("RTDU_TurretAttack(ent->client->rtdu.turret);", cmd_block)
        self.assertIn("ucmd->buttons &= ~BUTTON_ATTACK;", cmd_block)
        self.assertNotIn("turret = ent->client->rtdu.turret;", cmd_block)
        self.assertNotIn("turret->inuse", cmd_block)

        self.assertIn('tripod->classname = "RTDUTripod";', tripod_block)
        self.assertIn("tripod->s.origin[2] += RTDU_TRIPOD_Z_OFFSET;", tripod_block)
        self.assertIn("#define RTDU_TRIPOD_Z_OFFSET\t\t40.0f", self.g_rtdu_source)

        self.assertIn("owner->client->remote_view_cmd_hook = RTDU_RemoteViewCmd;", begin_block)
        self.assertIn("owner->client->remote_view_state_1 = 0;", begin_block)
        self.assertIn("owner->client->remote_view_state_2 = 0;", begin_block)
        self.assertIn("owner->client->remote_view_timer = RTDU_REMOTE_VIEW_Z;", begin_block)
        self.assertIn("turret->timestamp = level.time;", begin_block)

        self.assertIn("owner->client->remote_view_cmd_hook = NULL;", end_block)
        self.assertIn("RemoteView_End(owner);", end_block)

        self.assertIn("owner->client->pers.inventory[ITEM_INDEX(self->item)] = 0;", remove_block)
        self.assertIn("RTDU_EndRemoteView(self);", remove_block)
        self.assertIn("owner->client->rtdu.turret = NULL;", remove_block)
        self.assertIn("self->think = RTDU_RemoveTurretThink;", remove_block)

        self.assertIn("self->count--;", attack_block)
        self.assertIn("owner->client->pers.inventory[ITEM_INDEX(self->item)]--;", attack_block)
        self.assertNotIn("> 0", attack_block)
        self.assertIn("G_ProjectSource(self->s.origin, rtdu_muzzle_offsets[offset_index], forward, right, start);", attack_block)
        self.assertIn("fire_bullet(self, start, forward, RTDU_ATTACK_DAMAGE, RTDU_ATTACK_KICK,", attack_block)
        self.assertNotIn("fire_blaster_with_mod", attack_block)
        self.assertIn("gi.WriteByte(MZ_MACHINEGUN);", attack_block)
        self.assertIn("PlayerNoise(owner, start, PNOISE_WEAPON);", attack_block)

        self.assertIn('self->classname = "RTDU";', init_block)
        self.assertIn('self->item = FindItem("RTDU");', init_block)
        self.assertIn("self->health = RTDU_HEALTH;", init_block)
        self.assertIn("self->count = RTDU_AMMO;", init_block)
        self.assertIn("self->think = RTDU_TurretThink;", init_block)
        self.assertIn("self->die = RTDU_RemoveTurret;", init_block)
        self.assertIn("RTDU_SpawnTripod(self);", init_block)

    def test_source_side_rtdu_relink_helper_is_removed(self) -> None:
        read_level_block = _extract_function_block(self.g_save_source, "ReadLevel")

        self.assertNotIn("G_RestoreRTDUTurretLinks", self.g_save_source)
        self.assertIn("ent->client->pers.connected = false;", read_level_block)

    def test_source_side_rtdu_outer_wrappers_are_removed(self) -> None:
        player_die_block = _extract_function_block(self.p_client_source, "player_die")
        disconnect_block = _extract_function_block(self.p_client_source, "ClientDisconnect")

        self.assertNotIn("void RTDU_RunFrame(void);", self.g_local_header)
        self.assertNotIn("void RTDU_PlayerDisconnect(edict_t *ent);", self.g_local_header)
        self.assertNotIn("void RTDU_PlayerDie(edict_t *ent);", self.g_local_header)
        self.assertNotIn("void RTDU_RunFrame(void)", self.g_rtdu_source)
        self.assertNotIn("void RTDU_PlayerDisconnect(edict_t *ent)", self.g_rtdu_source)
        self.assertNotIn("void RTDU_PlayerDie(edict_t *ent)", self.g_rtdu_source)
        self.assertNotIn("RTDU_RunFrame", self.g_main_source)
        self.assertNotIn("RTDU_PlayerDie", player_die_block)
        self.assertNotIn("RTDU_PlayerDisconnect", disconnect_block)


if __name__ == "__main__":
    unittest.main()
