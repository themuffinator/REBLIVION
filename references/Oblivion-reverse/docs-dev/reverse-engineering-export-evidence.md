# Oblivion Export Evidence Log

Date: 2026-03-15

## Scope

This log records incremental, evidence-backed recovery notes for the retail Oblivion `gamex86.dll` export interface and its returned `game_export_t` wiring.

Primary sources in this pass:

- `reference/reverse-engineering/ghidra/gamex86/exports.txt`
- `reference/reverse-engineering/ghidra/gamex86/decompile_exports.c`
- `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`
- `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`
- `reference/reverse-engineering/ghidra/gamex86/metadata.txt`
- `references/HLIL/oblivion/gamex86.dll_hlil.txt`
- `docs/oblivion_reverse_analysis.md`

## DLL Export Surface

Identifier: `GetGameAPI @ 0x1000D490`
- Likely role: sole Quake II game DLL export used by the engine to hand over imports and receive the populated `game_export_t`.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/exports.txt` contains exactly one export: `1000d490 GetGameAPI`.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_exports.c` decompiles that export directly.
  - `references/HLIL/oblivion/gamex86.dll_hlil.txt` identifies the same address and names it `GetGameAPI`.
- Suggested rename/type: keep `GetGameAPI`; signature should remain `game_export_t *GetGameAPI(game_import_t *import)`.
- Related items: `reference/reverse-engineering/ghidra/gamex86/exports.txt`, `reference/reverse-engineering/ghidra/gamex86/decompile_exports.c`, `references/source-code/Quake-2-master/game/game.h`.
- Confidence: High.
- Open questions: none on the exported symbol itself; remaining ambiguity is in downstream field naming and broader subsystem recovery.

## GetGameAPI Handshake

Identifier: `GetGameAPI` return block at `0x1006C120`
- Likely role: copies the incoming engine import table into module state, fills the retail Oblivion export table, and returns it to the engine.
- Evidence:
  - Ghidra decompilation shows a loop copying `0x2C` dwords from the incoming import pointer into the module import block rooted at `0x1006C1C0`.
  - The HLIL corpus describes the same action as `__builtin_memcpy(dest: &gi, src: import, n: 0xb0)`.
  - Ghidra and HLIL both show `apiversion = 3`.
  - Ghidra and HLIL both show `edict_size = 0x3D0`.
  - Ghidra returns `&DAT_1006C120`; HLIL returns `&globals`, whose field map begins at `0x1006C120`.
- Suggested rename/type: keep field names aligned with stock `game_export_t` until retail evidence justifies divergence.
- Related items: `docs/oblivion_reverse_analysis.md`, `docs-dev/game-api-mapping-mvp.md`, `references/source-code/Quake-2-master/game/game.h`.
- Confidence: High.
- Open questions: Ghidra does not automatically name the export block fields, so slot naming still depends on HLIL plus Quake II structure cross-reference.

## High-Confidence Export Slot Map

Identifier: `game_export_t` slots in `GetGameAPI`
- Likely role: standard Quake II game DLL callback surface, wired to retail Oblivion implementations.
- Evidence:
  - Ghidra assigns concrete function addresses to each callback slot in the returned block.
  - HLIL names those same addresses with stock callback names.
  - Quake II `game_export_t` ordering in `references/source-code/Quake-2-master/game/game.h` matches the observed write order.
- Suggested rename/type:
  - `Init = 0x100158D0`
  - `Shutdown = 0x1000D460`
  - `SpawnEntities = 0x10016C60`
  - `WriteGame = 0x10016020`
  - `ReadGame = 0x10016100`
  - `WriteLevel = 0x10016400`
  - `ReadLevel = 0x100164E0`
  - `ClientConnect = 0x10031950`
  - `ClientBegin = 0x10031610`
  - `ClientUserinfoChanged = 0x10031760`
  - `ClientDisconnect = 0x10031C30`
  - `ClientCommand = 0x100055F0`
  - `ClientThink = 0x10031D70`
  - `RunFrame = 0x1000D940`
  - `ServerCommand = 0x10017850`
- Related items: `reference/reverse-engineering/ghidra/gamex86/decompile_exports.c`, `references/HLIL/oblivion/gamex86.dll_hlil.txt`, `references/source-code/Quake-2-master/game/game.h`.
- Confidence: High.
- Open questions:
  - `edicts`, `num_edicts`, and `max_edicts` are present in the global block, but only `edict_size` is assigned explicitly inside `GetGameAPI`; the live initialization flow for the remaining shared fields should be documented separately.

## Selected Callback Recovery Pass

Identifier: targeted callback/helper pass under `selected_functions_summary.csv`
- Likely role: promotes high-value export-slot addresses and adjacent helper callees into direct Ghidra functions so the mapping no longer depends only on `GetGameAPI` slot wiring.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now reports direct coverage for the full export callback cluster:
    - created at target address: `ShutdownGame`, `G_RunFrame`, `WriteGame`, `ReadGame`, `InitGame`, `WriteLevel`, `ReadLevel`, `SpawnEntities`, `ServerCommand`, `ClientBegin`, `ClientThink`, `ClientCommand`
    - existing exact-match functions promoted to stable retail names: `ClientConnect`, `ClientUserinfoChanged`, `ClientDisconnect`, plus the frame/save/spawn/admin helpers already mapped in earlier passes
  - The same summary now includes a `renamed` column, making it explicit when an existing Ghidra function was renamed to the requested retail identity during the temporary analysis pass.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows the expected Quake II control flow for each recovered callback.
- The same targeted pass now directly names the `ClientCommand` helper band: `SelectNextItem`, `SelectPrevItem`, `ValidateSelectedItem`, `Cmd_Give_f`, `Cmd_God_f`, `Cmd_Notarget_f`, `Cmd_Noclip_f`, `Cmd_Use_f`, `Cmd_UseToggle_f`, `Cmd_Drop_f`, `Cmd_Inven_f`, `Cmd_InvUse_f`, `Cmd_WeapPrev_f`, `Cmd_WeapNext_f`, `Cmd_WeapLast_f`, `Cmd_InvDrop_f`, `Cmd_Kill_f`, `Cmd_PutAway_f`, `Cmd_Players_f`, `Cmd_Wave_f`, `Cmd_Say_f`, `Cmd_PlayerList_f`, `Cmd_Score_f`, and `Cmd_Help_f`.
- Negative evidence inside that same command band is now strong: the direct `SelectNextItem` and `SelectPrevItem` bodies are pure inventory walkers with no stock chase-camera diversion through `chase_target`, `ChaseNext`, or `ChasePrev`.
- The widened 2026-03-14 helper pass now directly names the HUD / trail / player-view band as well: `DeathmatchScoreboardMessage`, `DeathmatchScoreboard`, `HelpComputer`, `G_SetStats`, `PlayerTrail_Add`, `PlayerTrail_LastSpot`, `SV_CalcRoll`, `P_DamageFeedback`, `SV_CalcViewOffset`, `SV_CalcGunOffset`, `SV_CalcBlend`, `P_FallingDamage`, `P_WorldEffects`, `G_SetClientEffects`, `G_SetClientEvent`, `G_SetClientSound`, `G_SetClientFrame`, `PlayerNoise`, `Think_Weapon`, and `G_TouchTriggers`.
- The latest selected pass also directly names the wider item and projection helper band: `GetItemByIndex`, `FindItemByClassname`, `FindItem`, `DoRespawn`, `SetRespawn`, `Pickup_Powerup`, `Drop_General`, `Pickup_Adrenaline`, `Pickup_AncientHead`, `Pickup_Bandolier`, `Pickup_Pack`, `Use_Quad`, `Use_Breather`, `Use_Envirosuit`, `Use_Invulnerability`, `Use_Silencer`, `Pickup_Key`, `Add_Ammo`, `Pickup_Ammo`, `Drop_Ammo`, `MegaHealth_think`, `Pickup_Health`, `ArmorIndex`, `Pickup_Armor`, `PowerArmorType`, `Use_PowerArmor`, `Pickup_PowerArmor`, `Drop_PowerArmor`, `Touch_Item`, `Drop_Item`, `drop_temp_touch`, `drop_make_touchable`, `Use_Item`, `droptofloor`, `PrecacheItem`, `SpawnItem`, `SP_item_health`, `SP_item_health_small`, `SP_item_health_large`, `SP_item_health_mega`, `InitItems`, `SetItemNames`, `Pickup_Weapon`, and `P_ProjectSource`.
- The same pass also directly names the death, respawn, persistence, and weapon-core helper band: `player_die`, `InitClientPersistant`, `CopyToBodyQue`, `respawn`, `spectator_respawn`, `ChangeWeapon`, `NoAmmoWeaponChange`, `Think_Weapon`, `Use_Weapon`, `Drop_Weapon`, `Weapon_Generic`, `weapon_grenade_fire`, `Weapon_Grenade`, `weapon_grenadelauncher_fire`, `Weapon_Deatomizer_Fire`, and `Oblivion_UpdateWeaponRegen`.
- The current targeted pass also directly names the actor helper and entity-lifecycle cluster (`visible`, `Actor_EngageEnemy`, `Actor_FindEnemyTarget`, `Actor_IsPlayerFollowTarget`, `Actor_FindFollowTarget`, `actor_stand`, `actor_walk`, `actor_run`, `actor_pain`, `actorMachineGun`, `actor_die`, `actor_fire`, `actor_attack`, `actor_use`, `SP_misc_actor`, `target_actor_touch`, `SP_target_actor`), the adjacent `g_target.c` help/secret/goal band (`Use_Target_Help`, `SP_target_help`, `use_target_secret`, `SP_target_secret`, `use_target_goal`, `SP_target_goal`), the directly recovered Badass monster module (`badass_sight`, `badass_stand`, `badass_idle`, `badass_attack`, `badass_attack_loop`, `badass_rocket_right`, `badass_rocket_left`, `badass_gib_explosion`, `badass_die_gibs`, `badass_dead`, `badass_die`, `badass_step`, `badass_thud`, `badass_walk`, `badass_run`, `badass_pain`, `SP_monster_badass`), the directly recovered Cyborg monster module (`cyborg_footstep`, `cyborg_sight`, `cyborg_search`, `cyborg_stand`, `cyborg_idle`, `cyborg_walk`, `cyborg_run`, `cyborg_pain`, `cyborg_hit_left`, `cyborg_hit_right`, `cyborg_hit_alt`, `cyborg_touch`, `cyborg_attack_start`, `cyborg_attack_end`, `cyborg_fire_right`, `cyborg_fire_left`, `cyborg_fire_both`, `cyborg_attack`, `cyborg_melee`, `cyborg_check_range`, `cyborg_checkattack`, `cyborg_dead`, `cyborg_die`, `SP_monster_cyborg`), the directly recovered Kigrax monster module (`kigrax_search`, `kigrax_sight`, `kigrax_stand`, `kigrax_run`, `kigrax_walk`, `kigrax_fire_plasma`, `kigrax_attack`, `kigrax_melee`, `kigrax_strike1`, `kigrax_strike2`, `kigrax_pain`, `kigrax_die`, `SP_monster_kigrax`, `kigrax_dead`), the directly recovered Spider monster module (`spider_idle`, `spider_sight`, `spider_search`, `spider_melee_swing`, `spider_stand`, `spider_walk`, `spider_charge_think`, `spider_charge_start`, `spider_charge_end`, `spider_run`, `spider_melee_hit`, `spider_melee`, `spider_rocket_left`, `spider_rocket_right`, `spider_attack`, `spider_pain`, `spider_dead`, `spider_die`, `SP_monster_spider`), the broader monster target-acquisition and attack-gate chain (`range`, `infront`, `FoundTarget`, `FindTarget`, `ai_checkattack`), the adjacent monster combat and movement band (`ai_run`, `FacingIdeal`, `ai_run_melee`, `ai_run_missile`, `ai_run_slide`, `AttackFinished`, `M_CheckBottom`, `SV_movestep`, `M_ChangeYaw`, `SV_StepDirection`, `SV_FixCheckBottom`, `SV_NewChaseDir`, `SV_CloseEnough`, `M_MoveToGoal`, `M_walkmove`), the shared dodge, orientation, and vector helper band (`check_dodge`, `vectoyaw`, `AngleVectors`, `anglemod`, `AddPointToBounds`, `VectorNormalize`, `VectorCompare`, `VectorMA`, `DotProduct`, `CrossProduct`, `VectorLength`, `VectorScale`), and the widened projectile helper band (`blaster_touch`, `fire_blaster`, `Grenade_Explode`, `fire_grenade2`, `rocket_touch`, `fire_rocket`, `obliterator_projectile_think`, `fire_obliterator_projectile`, `fire_rail`, `bfg_explode`, `bfg_touch`, `bfg_think`, `fire_bfg`, `fire_proximity_mine`, `proximity_mine_explode`, `plasma_bolt_touch`, `fire_plasma_bolt`, `detpack_detonate`, `fire_detpack`, `fire_dod`).
- The same selected pass now also directly names the retail soldier module and monster-side deatom chain: `soldier_stand`, `soldier_walk`, `soldier_run`, `soldier_pain`, `soldier_fire`, `soldier_attack6_refire`, `soldier_fire4`, `soldier_fire8`, `soldier_attack`, `soldier_sight`, `soldier_dodge`, `soldier_die`, `SP_monster_soldier_x`, `SP_monster_soldier_light`, `SP_monster_soldier`, `SP_monster_soldier_ss`, `SP_monster_soldier_deatom`, `monster_fire_deatom`, `deatom_touch`, `deatom_think`, and `fire_deatom`.
- The same selected pass now directly names the remaining stock monster startup locals and adjacent telefrag helper as well: `M_FliesOff`, `M_MoveFrame`, `monster_use`, `monster_triggered_spawn_use`, and `KillBox`.
- The current selected pass also directly names the low-address `g_misc.c` map-logic band: `SP_path_corner`, `point_combat_touch`, `SP_point_combat`, `TH_viewthing`, `SP_viewthing`, `SP_info_notnull`, `SP_light`, and `light_use`.
- The current selected pass also directly names the early `g_misc.c` world-entity band: `SP_misc_banner`, `SP_misc_viper`, `SP_misc_bigviper`, `SP_misc_strogg_ship`, `SP_misc_satellite_dish`, `SP_light_mine1`, `SP_light_mine2`, `SP_misc_gib_arm`, `SP_misc_gib_leg`, `SP_misc_gib_head`, `SP_target_character`, `target_string_use`, `func_clock_format_countdown`, `SP_func_clock`, `teleporter_touch`, `SP_misc_teleporter`, and `SP_misc_teleporter_dest`.
- The current selected pass now also directly names the retail RTDU band: `rtdu_use`, `RTDU_SpawnTurret`, `RTDU_TurretThink`, `RTDU_RemoveTurret`, `RTDU_BeginRemoteView`, `RTDU_EndRemoteView`, `RTDU_TurretAttack`, and `RTDU_InitTurret`.
- Suggested rename/type: keep the callback names aligned with stock Quake II names and reuse the helper aliases above in future notes instead of raw `FUN_...` ids.
- Related items: `docs-dev/reverse-engineering-symbol-map.md`, `reference/reverse-engineering/corpus-map.md`, `scripts/ghidra/run_oblivion_selected_functions.ps1`.
- Confidence: High.
- Open questions:
  - deeper monster subsystem naming still needs the same multi-signal process used here
  - several source-side hooks currently present in the reconstruction (`Mission_BeginLevel`, `Mission_OnGameLoaded`, `Mission_FrameUpdate`, `Actor_PostLoad`) are still not backed by a second retail signal in the recovered direct bodies
  - the retail `usetoggle` command path is now reconstructed in `src/game/g_cmds.c`, including the direct `ClientCommand` dispatcher entry, the private parser helper at `0x10004750`, the apostrophe-delimited multiword item parser, the retained unmatched-quote trailing-space edge case, and the `newweapon`-gated requested-item cycle
  - the recovered `ClientEndServerFrame @ 0x10034D80` body now shows the opposite of the earlier stock assumption: it stays on `G_SetStats` and then uses `0x10002E20` plus `0x10002CA0` only for the retail remote-view or dummy-body tail, so the source-side `G_SetSpectatorStats` / `G_CheckChaseStats` helpers are not part of the active retail camera path

## Retail Negative Evidence For Source-Side RTDU Wrappers And Save/Load Relink

Identifier: `G_RunFrame @ 0x1000D940`, `player_die @ 0x10030160`, `ReadLevel @ 0x100164E0`, `InitClientPersistant @ 0x10030460`, `ClientConnect @ 0x10031950`, and `ClientDisconnect @ 0x10031C30`
- Likely role: direct retail control-flow proof that the old source-side `RTDU_RunFrame`, `RTDU_PlayerDie`, `RTDU_PlayerDisconnect`, and `G_RestoreRTDUTurretLinks` hooks are reconstruction-only helpers rather than retail behaviors.
- Evidence:
  - `G_RunFrame @ 0x1000D940` in `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` advances `level.framenum`, derives `level.time`, calls `AI_SetSightClient()`, iterates entities, then calls `CheckDMRules()` and `ClientEndServerFrames()`; there is no RTDU-specific outer call in the retail body.
  - `player_die @ 0x10030160` in the same selected-function decompile enters the normal death path immediately after clearing angular velocity; no retail `RTDU_PlayerDie`-style helper appears before obituary, inventory clear, or animation setup.
  - `ReadLevel @ 0x100164E0` restores `edict.client` pointers for the player slots and then clears retail client offset `+0x2D0`, with no extra RTDU scan or relink call anywhere in the recovered body.
  - `InitClientPersistant @ 0x10030460`, `ClientConnect @ 0x10031950`, and `ClientDisconnect @ 0x10031C30` all write that same client offset `+0x2D0` as the session-connected flag, so the post-`ReadLevel` zero at `0x1001668B` is `pers.connected`, not an RTDU field.
  - `ClientDisconnect @ 0x10031C30` prints the disconnect message, emits the logout effect, unlinks the entity, clears the player slot, and updates the skin configstring; no retail `RTDU_PlayerDisconnect`-style helper appears in that body.
  - The matching assembly listings in `references/Assembly/Oblivion/gamex86.dll_disassembly.txt` for `0x1000D940`, `0x10030160`, `0x100164E0`, `0x10030460`, `0x10031950`, and `0x10031C30` show the same direct flow with no hidden calls to the removed source-side wrapper names or to any RTDU-specific post-load relink helper.
  - In the current source save/load path, `ReadClient` already rebuilds `F_EDICT` client fields as `&g_edicts[index]`, and `ReadLevel` repopulates that same long-lived `g_edicts` array in place; this means the old source-side `G_RestoreRTDUTurretLinks()` pass was unnecessary as well as non-retail.
- Suggested rename/type: treat `RTDU_RunFrame`, `RTDU_PlayerDie`, `RTDU_PlayerDisconnect`, and `G_RestoreRTDUTurretLinks` as disproven source-only helpers and keep them out of the retail reconstruction surface.
- Related items: `src/game/g_main.c`, `src/game/p_client.c`, `src/game/g_rtdu.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - whether the retail RTDU/remote-view support layer still has any outer callback entry beyond the now-isolated RTDU input callback stored through `0xF10`

## Retail `game_locals_t` Help Surface And Mission Delta

Identifier: retail `game` block rooted at `0x1006C440`
- Likely role: persistent game-global state for the stock help-message buffers, the help-change counter, the client-array pointer, latched cvars, crosslevel flags, item count, and the autosave/loadgame gate.
- Evidence:
  - `WriteGame @ 0x10016020` stores `param_2` into `DAT_1006ca58`, writes exactly `0x61C` bytes from `&DAT_1006c440`, then clears `DAT_1006ca58` before serializing clients. `ReadGame @ 0x10016100` restores the same `0x61C` byte block before loading clients.
  - `Use_Target_Help @ 0x10017AA0` copies `ent->message` into `DAT_1006c440` or `DAT_1006c640` depending on spawnflag `1`, and increments `DAT_1006c840` directly.
  - The help/HUD path later reads those same buffers, and the client-side help icon logic compares the client help counter against `DAT_1006c840`.
  - Crosslevel trigger/target helpers OR and test `DAT_1006ca50`, directly anchoring `game.serverflags`.
  - Retail item init seeds `DAT_1006ca54 = 0x36`, and item lookup loops use it as the live `num_items` bound.
  - `ClientBegin` checks `DAT_1006ca58` as the autosave/loadgame gate after `ReadGame`.
  - A local retail string sweep against `C:\q2Clean\oblivion\gamex86.dll` surfaced `target_help` but did not surface stable `Mission_` or `mission_` tokens.
- Suggested rename/type:
  - Keep the current `game_locals_t` names `helpmessage1`, `helpmessage2`, `helpchanged`, `clients`, `maxclients`, `maxentities`, `serverflags`, `num_items`, and `autosaved`.
  - Treat the current source `game.mission` block as reconstruction-only until a second retail signal appears; the retail `0x61C` serialized block already ends at `game.autosaved @ +0x618`.
- Related items: `src/game/g_local.h`, `src/game/g_mission.c`, `src/game/g_save.c`, `src/game/g_target.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - Whether any retail mission-like behavior survives only as actor/help control flow rather than as a serialized `game.mission` block.
  - No direct retail offset map has surfaced yet for the current source `edict.oblivion.mission_*` or controller/path bands.

## Current Source Mission Reconstruction Layer

Identifier: current source mission system in `src/game/g_mission.c`
- Likely role: a reconstruction-only objective-log layer that reuses the retail help-message UI surface for mission text, unread-state blinking, and help-menu display.
- Evidence:
  - `Mission_InitGame()` is called from `src/game/g_save.c` during game init, `Mission_OnGameLoaded()` is called from `ReadGame` tail in the current source, `Mission_BeginLevel()` is called from `src/game/g_spawn.c`, and `Mission_FrameUpdate()` is called from `src/game/g_main.c`.
  - `Mission_TargetHelpFired()` is called from the current actor path in `src/game/m_actor.c`, and the menu/HUD layer uses `Mission_GetObjectiveCount()`, `Mission_GetObjective()`, `Mission_ClearUnread()`, and `Mission_HasUnread()`.
  - `Mission_RebuildHelpMessages_Internal()` writes to `game.helpmessage1`, `game.helpmessage2`, and `game.helpchanged`, which matches the direct retail help-buffer surface but does not prove the surrounding objective storage exists in retail.
  - Current source save fields serialize `mission_controller`, `mission_path_*`, `mission_custom_name*`, `mission_id`, `mission_title`, `mission_text`, `mission_event`, `mission_timer_*`, `mission_origin`, `mission_angles`, `mission_velocity`, `mission_blend`, and `mission_radius`, but the retail `edict_t` map still has no direct offset-level confirmation for that band.
- Suggested rename/type:
  - Keep the current `Mission_*` API and `edict.oblivion.mission_*` names as reconstruction labels only.
  - Do not project current `mission_state_t` / `mission_objective_save_t` storage onto retail globals or retail entity offsets without a second retail signal.
- Related items: `src/game/g_mission.c`, `src/game/g_local.h`, `src/game/g_save.c`, `src/game/g_spawn.c`, `src/game/g_main.c`, `src/game/m_actor.c`, `src/game/p_hud.c`, `src/game/p_menu.c`.
- Confidence: Medium.
- Open questions:
  - `Mission_RegisterHelpTarget()` currently has no confirmed external caller in the checked source tree outside the mission module itself.
  - The exact retail origin of the current mission/controller/path field set is still unresolved.

## Respawn And Spectator Lifecycle Helpers

Identifier: `CopyToBodyQue @ 0x10030B40`, `respawn @ 0x10030CD0`, `spectator_respawn @ 0x10030D60`
- Likely role: retail death or respawn handling around body-queue persistence, `PutClientInServer`, and spectator admission checks.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now reports all three helpers as exact-address existing functions renamed to stable retail identities.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `CopyToBodyQue` rotating the body queue, cloning the dead player state into the queued corpse edict, installing `body_die`, and relinking the body.
  - The same decompile shows `respawn` following the deathmatch or coop path, skipping corpse creation for noclip spectators, clearing `SVF_NOCLIENT`, calling `PutClientInServer`, and applying the teleport hold state before returning; the non-deathmatch path issues `menu_loadgame`.
  - The same decompile shows `spectator_respawn` validating spectator and player passwords, enforcing `maxspectators`, writing back `spectator 0` or `spectator 1`, calling `PutClientInServer`, and printing the expected join or sidelines messages.
  - `src/game/p_client.c` contains direct source counterparts with the same control flow and strings.
- Suggested rename/type: keep the stock Quake II names above.
- Related items: `src/game/p_client.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions: none on these names; the remaining ambiguity is in adjacent retail-only spectator support helpers, not in the core respawn path itself.

## `level_locals_t` Global Block And Member Map

Identifier: retail `level` block rooted at `0x1006C2E0`
- Likely role: live `level_locals_t` state used for frame timing, map-flow strings, intermission state, AI sensory tracking, scoreboard counters, and the current-edict or body-queue runtime fields.
- Evidence:
  - `WriteLevelLocals @ 0x100162D0` copies `0x130` bytes from `&DAT_1006c2e0`, rewrites only the current `levelfields[]` pointer set (`changemap`, `sight_client`, `sight_entity`, `sound_entity`, `sound2_entity`), writes the block, then writes any trailing pointer payloads. `ReadLevelLocals @ 0x100163B0` restores the same `0x130` byte block and then runs the same pointer-field rebuild loop.
  - The current `src/game/g_local.h` `level_locals_t` layout is also `0x130` bytes and matches the same pointer-field set declared in current `src/game/g_save.c` `levelfields[]`, so retail save or load structure order still matches the current reconstruction for this block.
  - `G_RunFrame @ 0x1000D940` directly advances `DAT_1006c2e0` and derives `DAT_1006c2e4 = framenum * FRAMETIME`, which anchors `level.framenum` and `level.time`.
  - `SpawnEntities @ 0x10016C60` copies the incoming map token into `DAT_1006c328`, while the worldspawn-style level-init path copies either `message` or `mapname` into `DAT_1006c2e8`, and `CreateTargetChangeLevel` plus `EndDMLevel` use `&DAT_1006c368` as the stored next-map string, anchoring `level_name`, `mapname`, and `nextmap`.
  - The intermission flow directly writes `_DAT_1006c3a8`, `DAT_1006c3ac`, `DAT_1006c3b0`, `DAT_1006c3b4..0x3bc`, and `DAT_1006c3c0..0x3c8`, then `MoveClientToIntermission` copies the latter six values into the client origin and view-angle state, which anchors `intermissiontime`, `changemap`, `exitintermission`, `intermission_origin`, and `intermission_angle`.
  - `AI_SetSightClient` rotates and stores `DAT_1006c3cc`, while the sensory target-selection and `PlayerNoise` paths write `DAT_1006c3d0..0x3e4`, anchoring the `sight_*` and `sound_*` pointer or frame fields.
  - `G_SetStats` reads `DAT_1006c3e8` into the HUD stat slot for the health icon, the help-screen summary reads `DAT_1006c3ec..0x400` as the secrets or goals or monster counter band, retail `SP_target_secret @ 0x10017BC0` and `SP_target_goal @ 0x10017CD0` now decompile directly in the committed selected corpus and increment `DAT_1006c3ec` and `DAT_1006c3f4`, retail `use_target_secret @ 0x10017B70` and `use_target_goal @ 0x10017C70` increment `DAT_1006c3f0` and `DAT_1006c3f8`, the monster-death path directly increments `DAT_1006c400`, monster startup increments `DAT_1006c3fc`, `G_RunFrame` writes `DAT_1006c404`, `CopyToBodyQue` rotates `DAT_1006c408`, and the coop power-cube path increments `DAT_1006c40c`.
- Suggested rename or type:
  - Keep the current `level_locals_t` field order in `src/game/g_local.h`.
  - Treat the full current `level_locals_t` field set as directly observed retail members for this block: `framenum`, `time`, `level_name`, `mapname`, `nextmap`, the intermission band, the sensory pointer or frame band, `pic_health`, the secrets or goals or monster counter band, `current_entity`, `body_que`, and `power_cubes`.
- Related items: `src/game/g_local.h`, `src/game/g_save.c`, `src/game/g_main.c`, `src/game/g_ai.c`, `src/game/p_hud.c`, `src/game/p_client.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - None on the current `level_locals_t` field order; any remaining ambiguity is outside this block and in adjacent subsystem naming only.

## Retail `gclient_t` Global Block And Member Map

Identifier: retail client block serialized as `0xF34` bytes
- Likely role: the live `gclient_t` state carrying `player_state_t`, persistent inventory/loadout data, respawn/session state, pmove carry-over, HUD or view or damage accumulators, powerup timers, RTDU remote-view state, and plasma regeneration timers.
- Evidence:
  - `WriteClient @ 0x10015F40` and `ReadClient @ 0x10015FD0` copy exactly `0xF34` bytes per client, then run the current `clientfields[]` pointer rebuild flow; `SaveClientData @ 0x10030A80` also iterates clients with a `0xF34` stride, so retail `gclient_t` size is directly anchored.
  - `ClientUserinfoChanged @ 0x10031760` anchors the start of `pers` at `+0x0BC`: it copies the raw userinfo string into `client + 0x0BC`, writes the parsed player name to `client + 0x2BC`, writes `hand` to `+0x2CC`, and writes the spectator flag to `+0x72C`.
  - `InitClientPersistant @ 0x10030460` anchors the persistent layout: it seeds `connected = 1`, `health = 100`, `max_health = 100`, clears or initializes the inventory and selected-item band, seeds the full retail max-ammo block at `+0x6E4..+0x70C`, stores the default weapon pointer at `+0x714`, and zeros the adjacent rifle-plasma regen-divisor slot at `+0x710`.
  - That same persistent init path now resolves cleanly against the current `g_local.h` field order: the copied retail max-ammo block is `bullets=200`, `shells=100`, `rockets=50`, `grenades=50`, `mines=25`, `cells=200`, `slugs=50`, `pistolplasma=50`, `rifleplasma=50`, `detpacks=10`, and `dods=2`.
  - `InitClientResp @ 0x10031070` anchors the start of `resp` at `+0x730` by copying the full persistent block there as `coop_respawn`, then storing `enterframe` at `+0xDA4`.
  - `SaveClientData @ 0x10030A80` anchors `pers.health`, `pers.max_health`, `pers.savedFlags`, and the coop `pers.score <- resp.score` path at `+0x2D4`, `+0x2D8`, `+0x2DC`, and `+0x720`.
  - `ClientThink @ 0x10031D70` anchors the pmove and button band: `old_pmove` starts at `+0xDBC`, then the retail client block continues through `ammo_index`, `buttons`, `oldbuttons`, `latched_buttons`, `weapon_thunk`, and `newweapon`.
  - The same direct `ClientThink` body does not surface the stock chase-camera runtime: there is no recovered `chase_target` fast path, no spectator attack/jump-to-chase toggle, and no follower-update loop at the tail.
  - `G_SetStats @ 0x10032CA0` and adjacent HUD code anchor `ammo_index`, `pers.selected_item`, and the powerup frame-deadline block (`quad_framenum`, `invincible_framenum`, `breather_framenum`, `enviro_framenum`) in the expected post-`old_pmove` band, with no extra retail plasma/DoD timer HUD pass surfacing beyond the stock timer slot.
  - `P_DamageFeedback @ 0x10035450` anchors `damage_parmor`, `damage_armor`, `damage_blood`, `damage_knockback`, `damage_from`, `damage_alpha`, `damage_blend`, and the nearby view-damage scalars; `SV_CalcViewOffset @ 0x10035840` and `ClientEndServerFrame @ 0x10034D80` then anchor the adjacent `kick_*`, `v_angle`, and bob or oldview or oldvelocity band.
  - `P_WorldEffects @ 0x10035FE0` anchors `next_drown_time`, `old_waterlevel`, and `breather_sound`; weapon and animation flow in `ChangeWeapon @ 0x10037150`, `Think_Weapon`, and the current weapon wrappers anchor `weaponstate`, `machinegun_shots`, `anim_end`, `anim_priority`, `grenade_time`, and `weapon_sound`.
  - `Pickup_RiflePlasma @ 0x10037C80` resolves the persistent slot at `+0x710`: the direct body adds `50` to `pers.max_rifleplasma @ +0x704`, increments `+0x710`, then hands the item to `Add_Ammo`, which matches the current `pers.plasma_rifle_regen_divisor` name and the divisor math later used by `Oblivion_UpdateWeaponRegen`.
  - `Oblivion_UpdateWeaponRegen @ 0x10037CD0` directly anchors the retail plasma regeneration tail at `+0xF2C` and `+0xF30`.
  - `RTDU_BeginRemoteView @ 0x10014620`, `RTDU_EndRemoteView @ 0x100146F0`, `rtdu_use @ 0x10014350`, `RTDU_SpawnTurret @ 0x10013F20`, and the shared attach/detach helpers at `0x10002EB0` / `0x10002F20` now anchor the retail-only tail at `+0xF0C`, `+0xF10`, `+0xF18`, `+0xF1C`, `+0xF20`, `+0xF24`, and `+0xF28`: the current source now models that band behaviorally as `remote_view_active`, `remote_view_cmd_hook`, `remote_view_entity`, `remote_view_state_1`, `remote_view_state_2`, `remote_view_timer`, and `remote_view_saved_gunindex`, while keeping `rtdu.turret` as the source-side alias for the retail tracked-entity / turret ownership slot.
- Suggested rename/type:
  - Keep the current `gclient_t` member names where the retail evidence directly matches the existing reconstruction layout.
  - Keep the retail-only RTDU or remote-view tail documented as behavioral aliases for now rather than forcing current `camera` names onto `+0xF0C..+0xF28`, and keep the unresolved `+0xF04` / `+0xF08` slots neutral in source instead of preserving stock `chase_target` / `update_chase` names there.
- Related items: `src/game/g_local.h`, `src/game/p_client.c`, `src/game/p_view.c`, `src/game/p_weapon.c`, `src/game/g_rtdu.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - The adjacent tail slots at `+0xF04` and `+0xF08` still could be additional remote-view or other retail-only support fields; the current source now keeps them as neutral placeholders because the selected evidence no longer argues for the old stock chase-camera path there.
  - The current source tail likely needs reordering once the RTDU/camera layer is fully recovered from additional retail evidence.

## Retail `edict_t` Global Block And Member Map

Identifier: retail entity block serialized as `0x3D0` bytes
- Likely role: the live `edict_t` state used for the engine-facing entity prefix, target/path or mover or trigger runtime state, item ownership or pickup state, and the compact retail AI tail rooted by `monsterinfo.currentmove`.
- Evidence:
  - `WriteEdict @ 0x10016240` and `ReadEdict @ 0x10016360` copy exactly `0x3D0` bytes per entity and then rebuild only the serialized `fields[]` pointer set, so the retail entity block size is directly anchored.
  - The engine-facing prefix through `owner` still matches stock Quake II ordering exactly: `PutClientInServer`, `KillBox`, and the retail trace/spawn flow use `client @ +0x054`, `svflags @ +0x0B8`, `mins @ +0x0BC`, `maxs @ +0x0C8`, `solid @ +0x0F8`, `clipmask @ +0x0FC`, and the rest of the fixed collision prefix without any retail divergence signal.
  - `G_InitEdict @ 0x1001B310` anchors `inuse @ +0x058`, `classname @ +0x118`, `gravity @ +0x198`, and `s.number @ +0x000`; `G_Spawn @ 0x1001B350` and `G_FreeEdict @ 0x1001B400` then anchor `freetime @ +0x110` plus the free-entity reuse path.
  - `PutClientInServer @ 0x10031070` anchors the shared player-entity band directly: `movetype @ +0x104`, `flags @ +0x108`, `model @ +0x10C`, `classname @ +0x118`, `mins`, `maxs`, `solid`, `clipmask`, `mass @ +0x190`, `air_finished @ +0x194`, `viewheight @ +0x23C`, `takedamage @ +0x240`, `pain @ +0x204`, and `die @ +0x208`; the recovered retail rebuild path does not preserve the plasma regen timers at `client + 0xF2C/+0xF30` across respawn resets.
  - The target and trigger helpers anchor the mid-entity control surface directly: `spawnflags @ +0x11C`, `timestamp @ +0x120`, `targetname @ +0x12C`, `movedir @ +0x154`, `nextthink @ +0x1EC`, `think @ +0x1F4`, `touch @ +0x1FC`, `use @ +0x200`, `dmg @ +0x244`, `sounds @ +0x250`, `count @ +0x254`, `activator @ +0x264`, `wait @ +0x290`, `style @ +0x2C8`, and `item @ +0x2CC`.
  - The AI and monster startup band anchors the compact retail monster tail: `enemy @ +0x25C`, `oldenemy @ +0x260`, `groundentity @ +0x268`, `monsterinfo.currentmove @ +0x358`, `monsterinfo.aiflags @ +0x35C`, `monsterinfo.nextframe @ +0x360`, `monsterinfo.scale @ +0x364`, the callback table at `+0x368..+0x38C`, `monsterinfo.pausetime @ +0x390`, `monsterinfo.attack_finished @ +0x394`, `monsterinfo.search_time @ +0x3A4`, `monsterinfo.last_sighting @ +0x3AC`, `monsterinfo.attack_state @ +0x3B8`, `monsterinfo.lefty @ +0x3BC`, `monsterinfo.idle_time @ +0x3C0`, `monsterinfo.linkcount @ +0x3C4`, and `monsterinfo.power_armor_type @ +0x3C8`.
  - The retail layout is not the current source layout. A local x86 record-layout cross-check of current `src/game/g_local.h` shows the reconstruction now appends `edict_oblivion_ext_t` and much larger `moveinfo_t` / `monsterinfo_t` blocks, pushing the current source well past the retail `0x3D0` boundary. That means the current source is useful for names and behavior, but not as a direct retail offset map after the fixed server-visible prefix.
  - Cross-check against stock Quake II source shows the retail block still follows the stock naming/order strongly in the early and mid bands, but with two important retail insertions or expansions:
    - an unresolved `+0x1AC..+0x1E8` extension band between `ideal_yaw` and `nextthink`
    - a larger post-item mover/AI tail, including a `moveinfo` root at `+0x2D0` and `monsterinfo` root at `+0x358`, rather than the stock `+0x28C` / `+0x304` roots
- Suggested rename/type:
  - Keep the stock `edict_t` names for the directly matched retail fields above.
  - Treat `+0x1AC..+0x1E8` and `+0x294..+0x357` as unresolved retail extension bands until more direct decompilation evidence stabilizes per-slot names.
  - Do not treat the current `src/game/g_local.h` `edict_t` tail as a direct retail offset map; it is already structurally larger than the retail binary.
- Related items: `src/game/g_local.h`, `src/game/g_save.c`, `src/game/g_spawn.c`, `src/game/g_trigger.c`, `src/game/g_target.c`, `src/game/g_monster.c`, `src/game/p_client.c`, `references/source-code/Quake-2-master/game/g_local.h`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - The exact contents of the retail `+0x1AC..+0x1E8` extension band are still unresolved.
  - The retail `+0x294..+0x357` mover/timer band is heavily used by target, turret, and custom entity code, but its exact per-slot names still need more direct evidence.
  - The last retail dword at `+0x3CC` is likely the monster tail power-armor or final AI scalar slot, but this pass did not isolate a direct symbolic write.

## `g_target.c` Help, Secret, And Goal Wrappers

Identifier: `Use_Target_Help @ 0x10017AA0`, `SP_target_help @ 0x10017B00`, `use_target_secret @ 0x10017B70`, `SP_target_secret @ 0x10017BC0`, `use_target_goal @ 0x10017C70`, `SP_target_goal @ 0x10017CD0`
- Likely role: the stock target-help, target-secret, and target-goal helper or spawn-wrapper band immediately before the explosion helpers in retail `g_target.c`.
- Evidence:
  - The selected Ghidra corpus now carries all six addresses directly in `selected_functions_summary.csv` and `decompile_selected_functions.c`.
  - `Use_Target_Help` copies `ent->message` into one of the two game-help buffers based on spawnflag `1` and increments the shared help-change counter, matching current `src/game/g_target.c`.
  - `SP_target_help` matches the stock wrapper exactly: deathmatch auto-remove, `%s with no message at %s` diagnostic on missing `message`, and `Use_Target_Help` installation otherwise.
  - `use_target_secret` and `use_target_goal` match the current source directly, including the sound playback, `G_UseTargets`, and `G_FreeEdict` tail; the goal path also clears `CS_CDTRACK` when the goal count reaches the total.
  - `SP_target_secret` and `SP_target_goal` match the current spawn wrappers directly: deathmatch auto-remove, default `misc/secret.wav`, `SVF_NOCLIENT`, `use` installation, and direct increments of `level.total_secrets` or `level.total_goals`; `SP_target_secret` also carries the stock `mine3` map-bug hack.
- Suggested rename/type: keep the current `src/game/g_target.c` names above.
- Related items: `src/game/g_target.c`, `docs-dev/reverse-engineering-symbol-map.md`, `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`.
- Confidence: High.
- Open questions:
  - None on these six wrappers; the remaining local `g_target.c` uncertainty is now further down in later helper bands such as `target_lightramp` and any retail/source structure deltas beyond the laser path.

## `g_target.c` Explosion, Exit, Splash, Spawn, Crosslevel, And Laser Band

Identifier: `target_explosion_explode @ 0x10017D40`, `use_target_explosion @ 0x10017DE0`, `SP_target_explosion @ 0x10017E30`, `use_target_changelevel @ 0x10017E50`, `SP_target_changelevel @ 0x10017F80`, `use_target_splash @ 0x10018000`, `SP_target_splash @ 0x10018090`, `use_target_spawner @ 0x100180E0`, `SP_target_spawner @ 0x10018180`, `use_target_blaster @ 0x100181E0`, `SP_target_blaster @ 0x10018230`, `use_target_railgun @ 0x100182A0`, `SP_target_railgun @ 0x100182E0`, `target_rocket_fire @ 0x10018340`, `SP_target_rocket @ 0x100183A0`, `trigger_crosslevel_trigger_use @ 0x10018470`, `SP_target_crosslevel_trigger @ 0x10018490`, `target_crosslevel_target_think @ 0x100184B0`, `SP_target_crosslevel_target @ 0x100184F0`, `target_laser_think @ 0x10018540`, `target_laser_on @ 0x10018790`, `target_laser_off @ 0x100187D0`, `target_laser_use @ 0x10018800`, `target_laser_start @ 0x10018830`, and `SP_target_laser @ 0x100189B0`
- Likely role: the wider retail `g_target.c` control and weapon-helper tranche covering explosion, changelevel, splash, spawn, target-weapon, crosslevel-serverflag, and laser behaviors.
- Evidence:
  - The selected Ghidra corpus now carries all twenty-five addresses above directly in `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` and `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`.
  - `target_explosion_explode`, `use_target_explosion`, and `SP_target_explosion` match the stock helper split exactly: `TE_EXPLOSION1`, `T_RadiusDamage`, temporary `delay` clear around `G_UseTargets`, immediate-fire vs scheduled-think behavior, and the `SVF_NOCLIENT` wrapper.
  - `use_target_changelevel` directly anchors the retail exit flow: the intermission guard, single-player dead-player guard, deathmatch `DF_ALLOW_EXIT` damage path, exit announcement, `*`-map cross-trigger clear, and the final `BeginIntermission` call. `SP_target_changelevel` also still carries the stock `fact1 -> fact3$secret1` map hack.
  - `use_target_splash` and `SP_target_splash` match the stock splash path directly: `TE_SPLASH`, `count`, `movedir`, `sounds`, optional `T_RadiusDamage`, `G_SetMovedir`, default `count = 32`, and `SVF_NOCLIENT`.
  - `use_target_spawner` and `SP_target_spawner` recover the stock runtime-spawn helper directly: `G_Spawn`, `classname = target`, origin and angle copy, `ED_CallSpawn`, unlink, `KillBox`, relink, plus optional velocity from precomputed `movedir * speed`.
  - `use_target_blaster`, `SP_target_blaster`, `use_target_railgun`, `SP_target_railgun`, `target_rocket_fire`, and `SP_target_rocket` anchor the full stock target-weapon band. The selected decompilation shows direct `fire_blaster`, `fire_rail`, and `fire_rocket` calls from `self->s.origin` and `self->movedir`, plus the expected sound defaults and damage or speed defaults in the spawn wrappers.
  - The target-weapon band also exposes two clear retail/source deltas. Retail `use_target_railgun @ 0x100182A0` is just the thin direct-fire helper plus sound playback, so the current reconstruction's richer `wait` / `timestamp` / `move_origin` / `move_angles` flow is not evidenced at that retail address. Retail `SP_target_rocket @ 0x100183A0` installs `target_rocket_fire` directly, so the current source-side `target_rocket_use` factoring is not a direct retail body split.
  - `trigger_crosslevel_trigger_use`, `SP_target_crosslevel_trigger`, `target_crosslevel_target_think`, and `SP_target_crosslevel_target` directly recover the stock crosslevel serverflag path: OR spawnflags into `game.serverflags`, free the trigger, defer the target check by `delay`, then compare the cross-trigger mask before running `G_UseTargets`.
  - `target_laser_think`, `target_laser_on`, `target_laser_off`, `target_laser_use`, `target_laser_start`, and `SP_target_laser` recover the full laser chain directly, including optional enemy tracking through `target`, beam trace walking, hit damage, spark temp entities, beam color or renderfx selection from spawnflags, the `START_ON` toggle, and the deferred startup think.
- Suggested rename/type:
  - Keep the stock `g_target.c` names above for the retail bodies.
  - Treat the current `target_rocket_use` helper and the richer current `use_target_railgun` wrapper state as reconstruction-side structure unless a second retail signal surfaces for those exact splits.
- Related items: `src/game/g_target.c`, `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - The main remaining `g_target.c` work is now further down in the target-entity band, such as speaker or temp-entity parity notes and any later retail-only source-structure deltas.

## `g_target.c` Light Ramp And Earthquake Band

Identifier: `target_lightramp_think @ 0x100189E0`, `target_lightramp_use @ 0x10018AB0`, `SP_target_lightramp @ 0x10018BD0`, `target_earthquake_think @ 0x10018D10`, `target_earthquake_use @ 0x10018E60`, and `SP_target_earthquake @ 0x10018EA0`
- Likely role: the later stock `g_target.c` utility band covering scripted light-style ramps and level-wide earthquake impulses.
- Evidence:
  - The selected Ghidra corpus now carries all six addresses above directly in `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` and `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`.
  - `target_lightramp_think` directly matches the stock ramp update logic: derive the current style character from the stored ramp start plus elapsed frames times step, write the one-character style string to `CS_LIGHTS + enemy->style`, reschedule while the elapsed time is still below `speed`, and swap endpoints plus negate step when the `TOGGLE` spawnflag is set.
  - `target_lightramp_use` directly matches the lazy target-resolution flow in current `src/game/g_target.c`: repeated `G_Find` over `targetname`, explicit rejection of non-`light` targets with the stock diagnostics, failure cleanup when no valid light is found, then `timestamp = level.time` and an immediate handoff to `target_lightramp_think`.
  - `SP_target_lightramp` directly validates the two-letter lowercase `message` ramp, removes itself in deathmatch, validates `target`, marks `SVF_NOCLIENT`, installs the use and think callbacks, and converts the two letters into the stored start, end, and per-frame step values used by the think path.
  - `target_earthquake_think` directly matches the stock quake loop: periodic `positioned_sound` playback through `world/quake.wav`, iteration over active grounded clients, `groundentity` clear, randomized horizontal velocity kicks, vertical impulse scaled by `speed * (100.0 / mass)`, and `FRAMETIME` reschedule until `timestamp`.
  - `target_earthquake_use` and `SP_target_earthquake` also match current source directly: `timestamp = level.time + count`, first-think arm at `FRAMETIME`, `activator` store, `last_move_time` reset, untargeted warning, default `count = 5`, default `speed = 200`, `SVF_NOCLIENT`, callback install, and `world/quake.wav` precache.
- Suggested rename/type:
  - Keep the stock `g_target.c` names above.
  - No additional retail/source structure delta is evident in this band; current `src/game/g_target.c` already matches the recovered retail split closely.
- Related items: `src/game/g_target.c`, `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - The remaining obvious `g_target.c` work is now after the earthquake band, mainly later target-entity helpers and any speaker or temp-entity parity differences that still are not directly recovered in the selected corpus.

## `SP_target_*` Spawn-Wrapper To Helper Chain

Identifier: `SP_target_help @ 0x10017B00`, `SP_target_secret @ 0x10017BC0`, `SP_target_goal @ 0x10017CD0`, `SP_target_explosion @ 0x10017E30`, `SP_target_changelevel @ 0x10017F80`, `SP_target_splash @ 0x10018090`, `SP_target_spawner @ 0x10018180`, `SP_target_blaster @ 0x10018230`, `SP_target_railgun @ 0x100182E0`, `SP_target_rocket @ 0x100183A0`, `SP_target_crosslevel_trigger @ 0x10018490`, `SP_target_crosslevel_target @ 0x100184F0`, `SP_target_laser @ 0x100189B0`, `SP_target_lightramp @ 0x10018BD0`, and `SP_target_earthquake @ 0x10018EA0`
- Likely role: a consolidated retail map of every `SP_target_*` spawn wrapper in `src/game/g_target.c` and the immediate use or think or fire chain each wrapper installs or reaches.
- Evidence:
  - The selected Ghidra corpus now carries every retail `SP_target_*` wrapper present in current `src/game/g_target.c`, plus the connecting helper set that those wrappers wire: `Use_Target_Help`, `use_target_secret`, `use_target_goal`, `target_explosion_explode`, `use_target_explosion`, `use_target_changelevel`, `use_target_splash`, `use_target_spawner`, `use_target_blaster`, `use_target_railgun`, `target_rocket_fire`, `trigger_crosslevel_trigger_use`, `target_crosslevel_target_think`, `target_laser_think`, `target_laser_on`, `target_laser_off`, `target_laser_use`, `target_laser_start`, `target_lightramp_think`, `target_lightramp_use`, `target_earthquake_think`, and `target_earthquake_use`.
  - `SP_target_help`, `SP_target_secret`, and `SP_target_goal` are the thin info-target wrappers in this band. Retail shows the exact split: the wrapper validates or seeds message or sound state, then the runtime path is entirely in `Use_Target_Help`, `use_target_secret`, or `use_target_goal`.
  - `SP_target_explosion` installs `use_target_explosion`, and the use callback either calls `target_explosion_explode` immediately or schedules it through `delay`; this is a real two-stage retail chain, not just source-side factoring.
  - `SP_target_changelevel`, `SP_target_splash`, `SP_target_spawner`, `SP_target_blaster`, and `SP_target_railgun` all install a single direct use callback after seeding wrapper-side defaults such as `map`, `movedir`, `count`, `dmg`, or `speed`.
  - `SP_target_rocket` is the important retail/source delta in this family: the wrapper installs `target_rocket_fire` directly, so the current source-side `target_rocket_use` split is reconstruction structure rather than a directly recovered retail function body.
  - `SP_target_crosslevel_trigger` and `SP_target_crosslevel_target` split the stock crosslevel behavior cleanly between an immediate use callback and a scheduled think callback. Retail `SP_target_crosslevel_target` does not wait for an external use; it seeds `delay` and schedules `target_crosslevel_target_think` itself.
  - `SP_target_laser` is also a staged chain: the wrapper only schedules `target_laser_start`, which then installs `target_laser_use` and routes into `target_laser_on` or `target_laser_off`, with beam behavior owned by `target_laser_think`.
  - `SP_target_lightramp` and `SP_target_earthquake` both follow the wrapper -> use -> think pattern, with the wrapper seeding parsed configuration and the use callback arming the timed think loop.
- Suggested rename/type:
  - Keep the current `src/game/g_target.c` names above.
  - Treat the `SP_target_*` spawn-wrapper map as closed for the currently recovered retail surface; the remaining `g_target.c` work is outside this wrapper family and further down in later target helpers.
- Related items: `src/game/g_target.c`, `docs-dev/reverse-engineering-symbol-map.md`, `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`.
- Confidence: High.
- Open questions:
  - None on the wrapper-to-helper mapping itself. The meaningful remaining `g_target.c` uncertainty is outside the `SP_target_*` family, in later target-entity helpers and any residual retail/source structure deltas.

## `g_func.c` Brush Movers, Timers, Conveyors, And Secret-Door Band

Identifier: `plat_hit_top @ 0x10007100`, `plat_hit_bottom @ 0x10007170`, `plat_go_up @ 0x100071C0`, `plat_go_down @ 0x10007220`, `plat_blocked @ 0x10007280`, `plat_spawn_inside_trigger @ 0x10007390`, `SP_func_plat @ 0x100074F0`, `rotating_use @ 0x100083C0`, `button_return @ 0x10008B80`, `button_wait @ 0x10008BD0`, `button_fire @ 0x10008C40`, `SP_func_button @ 0x10008D30`, `door_use_areaportals @ 0x10008F90`, `door_hit_top @ 0x10009010`, `door_hit_bottom @ 0x10009090`, `door_go_down @ 0x100090F0`, `door_go_up @ 0x10009200`, `door_use @ 0x10009340`, `Think_CalcMoveSpeed @ 0x10009430`, `door_touch @ 0x100097B0`, `SP_func_door @ 0x10009830`, `SP_func_door_rotating @ 0x10009BD0`, `SP_func_water @ 0x10009FA0`, `train_next @ 0x1000A300`, `train_resume @ 0x1000A4C0`, `func_train_find @ 0x1000A560`, `train_use @ 0x1000A620`, `SP_func_train @ 0x1000A680`, `func_timer_think @ 0x1000A9A0`, `SP_func_timer @ 0x1000AA60`, `SP_func_conveyor @ 0x1000AB80`, `door_secret_use @ 0x1000AC00`, `door_secret_blocked @ 0x1000AD70`, and `train_blocked @ 0x10015090`
- Likely role: the retail `g_func.c` brush-entity control band covering plats, rotating or push buttons, sliding and rotating doors, water doors, trains, timers, conveyors, and the directly recovered secret-door callbacks.
- Evidence:
  - The selected Ghidra corpus now carries every direct address above except `train_blocked`, which is still visible in the committed wide decompilation and matches the same helper surface from current `src/game/g_func.c`.
  - `SP_func_plat` now decompiles as the real retail plat wrapper: BSP push-solid setup, `plats/pt1_*` sound seeds, speed/accel/decel/dmg defaults, `pos1/pos2` calculation, `plat_blocked`, and `plat_spawn_inside_trigger`. The direct helper band around it (`plat_go_up`, `plat_hit_top`, `plat_go_down`, `plat_hit_bottom`) matches current source exactly. The remaining `Use_Plat` / `Touch_Plat_Center` path is still compiled as a local callback inside the trigger chain rather than a standalone function start.
  - `rotating_use` directly recovers the runtime rotating behavior for both continuous and partial-rotation (`mangle`) entities, including the touch-pain enable and loop wait behavior. That proves the retail rotating path is present, but the outer `SP_func_rotating` wrapper itself still is not isolated as a stable selected function start in the current corpus.
  - `SP_func_button`, `button_fire`, `button_wait`, and `button_return` match the stock/current button lifecycle directly: movedir derivation, endpoint calculation, animation-flag toggles, target firing, return-to-start, and health-gated shootable buttons. `button_use`, `button_touch`, `button_killed`, and `button_done` remain local callback labels rather than standalone starts.
  - The door tranche is now direct end to end. `door_use_areaportals`, `door_hit_top`, `door_hit_bottom`, `door_go_down`, `door_go_up`, `door_use`, `Think_CalcMoveSpeed`, `door_touch`, `SP_func_door`, `SP_func_door_rotating`, and `SP_func_water` all match current source directly, including the `doors/dr1_*` sound family, the deathmatch speed doubling, the message-touch gate, the teamed speed harmonizer, the rotating-door axis logic, and the `func_water -> func_door` class rewrite.
  - The train tranche is also direct. `train_next`, `train_resume`, `func_train_find`, `train_use`, and `SP_func_train` now decompile as the stock/current path-corner mover chain, including `train_next: bad target %s`, `connected teleport path_corners, see %s at %s`, `train_find: no target`, `train_find: target %s not found`, and `func_train without a target at %s`. The wide decompilation also shows `train_blocked @ 0x10015090` as the exact stock crush helper with the non-client/non-monster `BecomeExplosion1` fallback and the `dmg`-guarded debounce branch.
  - `func_timer_think` and `SP_func_timer` now directly anchor the timer band, including the `func_timer at %s has random >= wait` clamp diagnostic, while `SP_func_conveyor` directly anchors the conveyor wrapper with the expected start-off `count`/`speed` fold. The small `func_timer_use` and `func_conveyor_use` callbacks are still local installs rather than standalone recovered starts.
  - `door_secret_use` and `door_secret_blocked` are now direct, and both match current `src/game/g_func.c`: origin-vs-`vec3_origin` open-state detection, `door_use_areaportals(self, 1)`, the non-client/non-monster gib case, and the debounce-gated crush damage. The outer `SP_func_door_secret` wrapper plus the `door_secret_move1..6` / `door_secret_done` chain still remain compiled as local callback labels rather than selected standalone bodies.
- Suggested rename/type:
  - Keep the stock/current `src/game/g_func.c` names above for the directly recovered retail bodies.
  - Treat `SP_func_rotating`, `SP_func_door_secret`, `SP_func_killbox`, `use_killbox`, and the smaller callback tails in this band (`Use_Plat`, `Touch_Plat_Center`, `button_use`, `button_touch`, `button_killed`, `button_done`, `Think_SpawnDoorTrigger`, `train_wait`, `func_timer_use`, `func_conveyor_use`, and `door_secret_move1..6` / `door_secret_done`) as unresolved or inlined until a second retail signal stabilizes standalone function starts for them.
- Related items: `src/game/g_func.c`, `references/source-code/Quake-2-master/game/g_func.c`, `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_top_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High for the direct selected bodies and `train_blocked`; Medium for the unresolved wrapper identities that are still only helper-backed.
- Open questions:
  - `SP_func_rotating` still is not isolated as a stable standalone retail wrapper start; only the runtime `rotating_use` body is direct today.
  - `SP_func_door_secret` still is not isolated as a stable standalone retail wrapper start, even though `door_secret_use` and `door_secret_blocked` are direct.
  - `SP_func_killbox` and `use_killbox` still have not surfaced as standalone starts in the committed corpus.
  - Several callback tails in this band remain embedded labels rather than selected standalone functions.

## Retail `func_rotate_train` Band

Identifier: local `RotateTrain_MoveDone @ 0x10014940`, local `RotateTrain_MoveFinal @ 0x100149D0`, local `RotateTrain_MoveBegin @ 0x10014AD0`, local `RotateTrain_MoveCalc @ 0x10014C50`, local `rotate_train_wait @ 0x10015140`, `rotate_train_next @ 0x10015250`, `rotate_train_resume @ 0x100154C0`, `rotate_train_find @ 0x10015560`, `rotate_train_use @ 0x100156F0`, and `SP_func_rotate_train @ 0x10015750`
- Likely role: the retail Oblivion rotating-train mover chain that layers per-corner travel-duration and angular-motion overrides on top of the stock train/path-corner flow.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/decompile_top_functions.c`, `references/Assembly/Oblivion/gamex86.dll_disassembly.txt`, and `references/HLIL/oblivion/split/gamex86.dll_hlil_block9999_sub_10015750.txt` agree on the helper order, wrapper entry, and retail classname `func_rotate_train`.
  - `RotateTrain_MoveDone` and `RotateTrain_MoveFinal` match the retail move tail exactly: both velocity bands are cleared at completion, final angles are wrapped through signed `% 360`, the last linear frame uses `remaining_distance * 10`, and the rotate-vector path derives its final `avelocity` from `end_angles - s.angles`.
  - `RotateTrain_MoveBegin` and `RotateTrain_MoveCalc` recover the retail timing semantics directly: travel frames are floored on the 10 Hz mover cadence, angular timing uses explicit `duration` when present or `VectorLength(angle_delta) / moveinfo.speed` otherwise, `duration` overrides `moveinfo.speed`, `rotate` builds `end_angles`, and `speeds` copies directly into `avelocity` when no `rotate` vector is active.
  - `rotate_train_next`, `rotate_train_resume`, `rotate_train_find`, and `rotate_train_use` match current `src/game/g_rtrain.c`, including direct path-corner origin placement instead of the stock `origin - mins` train path, first-corner `speed` seeding, preserved speed when later corners omit `speed`, per-corner `duration` or `rotate` or `speeds` overrides, the retail toggle-stop behavior that clears only linear velocity plus `nextthink`, and reuse of the stock `func_train without a target at %s` diagnostic.
  - `SP_func_rotate_train` also reuses the stock `train_blocked @ 0x10015090` crush helper rather than a rotate-train-specific blocked callback, which closes the runtime/source parity gap that used to exist in `src/game/g_rtrain.c`.
- Suggested rename/type:
  - Keep the current `src/game/g_rtrain.c` names above and treat `func_rotate_train` as the retail classname; `func_train_rotating` is not evidenced in the checked retail material.
  - Keep `rotate_train_wait` plus the move helpers as local/static callbacks because the current retail evidence still surfaces them as locals rather than as selected standalone starts.
- Related items: `src/game/g_rtrain.c`, `src/game/g_func.c`, `src/game/g_misc.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_top_functions.c`, `references/Assembly/Oblivion/gamex86.dll_disassembly.txt`, `references/HLIL/oblivion/split/gamex86.dll_hlil_block9999_sub_10015750.txt`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - None on the runtime chain itself.

## `SP_func_*` Spawn-Wrapper To Helper Chain

Identifier: `SP_func_clock @ 0x10011160`, `SP_func_plat @ 0x100074F0`, `SP_func_button @ 0x10008D30`, `SP_func_door @ 0x10009830`, `SP_func_door_rotating @ 0x10009BD0`, `SP_func_water @ 0x10009FA0`, `SP_func_train @ 0x1000A680`, `SP_func_rotate_train @ 0x10015750`, `SP_func_timer @ 0x1000AA60`, and `SP_func_conveyor @ 0x1000AB80`, plus the unresolved retail wrappers `SP_func_rotating`, `SP_func_door_secret`, and `SP_func_killbox`
- Likely role: a consolidated retail map of the `SP_func_*` spawn wrappers across `src/game/g_func.c` and `src/game/g_misc.c`, with the immediate mover or use or think chain each wrapper installs or reaches.
- Evidence:
  - The committed corpus and adjacent rotate-train reference set now directly carry `SP_func_clock`, `SP_func_plat`, `SP_func_button`, `SP_func_door`, `SP_func_door_rotating`, `SP_func_water`, `SP_func_train`, `SP_func_rotate_train`, `SP_func_timer`, and `SP_func_conveyor`, plus the main helper chains they wire.
  - `SP_func_clock` is the one `SP_func_*` wrapper outside `g_func.c`; retail shows it seeding the clock state and then handing runtime text updates through a local callback into `func_clock_format_countdown` and `target_string_use`.
  - `SP_func_plat` is the clearest multi-stage mover wrapper in this family: the wrapper spawns the inside trigger, the local center callback reaches `plat_go_up`, and the direct retail chain then runs `plat_hit_top -> plat_go_down -> plat_hit_bottom`.
  - `SP_func_button` is also multi-entry rather than single-use. Retail installs `button_touch`, `button_use`, or `button_killed` at spawn time, but all three paths converge into the direct `button_fire -> button_wait -> button_return` chain.
  - `SP_func_door`, `SP_func_door_rotating`, and `SP_func_water` all converge into the same direct door helper layer. The main difference is wrapper-side setup: `SP_func_door_rotating` seeds angular motion, and `SP_func_water` rewrites itself into `func_door` after seeding water/lava-specific sounds and endpoints.
  - `SP_func_train` seeds the train and then hands off into `func_train_find`, which enters the direct `train_next` / `train_resume` mover chain. Retail `train_wait` is still local, so the wrapper-to-helper chain is direct but not fully selected at every callback boundary.
  - `SP_func_rotate_train` is the retail rotating-train wrapper. It reuses `train_blocked`, delays into `rotate_train_find`, then reaches the direct `rotate_train_next` / `rotate_train_resume` chain with local `rotate_train_wait`, direct path-corner origin placement, and per-corner `duration` or `rotate` or `speeds` overrides from the next corner.
  - `SP_func_timer` and `SP_func_conveyor` are thin wrappers around local use callbacks. The direct recovered runtime body in this pair is `func_timer_think`; the conveyor runtime toggle is still only visible as a local callback install.
  - `SP_func_rotating`, `SP_func_door_secret`, and `SP_func_killbox` remain partial cases. Retail helper evidence is now strong for `rotating_use`, `door_secret_use`, and `door_secret_blocked`, but no stable standalone wrapper start has been promoted yet for those three `SP_func_*` names.
- Suggested rename/type:
  - Keep the current `src/game/g_func.c` and `src/game/g_misc.c` names above.
  - Treat the direct `SP_func_*` wrapper map as mostly closed for the current retail surface, with the remaining work limited to isolating the three unresolved wrapper starts and smaller local callback tails.
- Related items: `src/game/g_func.c`, `src/game/g_misc.c`, `docs-dev/reverse-engineering-symbol-map.md`, `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`.
- Confidence: High for the direct wrapper-to-helper map listed above; Medium for the unresolved rotating or secret-door or killbox wrappers.
- Open questions:
  - The only meaningful remaining uncertainty in this wrapper family is the lack of stable standalone starts for `SP_func_rotating`, `SP_func_door_secret`, and `SP_func_killbox`.

## `g_trigger.c` Multi, Key, Counter, Push, Hurt, Gravity, And Monsterjump Band

Identifier: `InitTrigger @ 0x10018F40`, `multi_wait @ 0x10018FA0`, `multi_trigger @ 0x10018FB0`, `Use_Multi @ 0x10019040`, `Touch_Multi @ 0x10019060`, `trigger_enable @ 0x100190F0`, `SP_trigger_multiple @ 0x10019120`, `SP_trigger_once @ 0x10019210`, `trigger_relay_use @ 0x10019290`, `SP_trigger_relay @ 0x100192B0`, `trigger_key_use @ 0x100192C0`, `SP_trigger_key @ 0x10019530`, `trigger_counter_use @ 0x100195E0`, `SP_trigger_counter @ 0x100196A0`, `SP_trigger_always @ 0x100196D0`, `trigger_push_touch @ 0x10019700`, `SP_trigger_push @ 0x10019850`, `hurt_use @ 0x100198C0`, `hurt_touch @ 0x10019900`, `SP_trigger_hurt @ 0x100199C0`, `trigger_gravity_touch @ 0x10019A40`, `SP_trigger_gravity @ 0x10019A60`, `trigger_monsterjump_touch @ 0x10019AC0`, and `SP_trigger_monsterjump @ 0x10019B30`
- Likely role: the stock retail `g_trigger.c` utility and trigger-entity control layer immediately after the recovered `g_target.c` earthquake band and before the later custom teleport block.
- Evidence:
  - The selected Ghidra corpus now carries all twenty-four addresses above directly in `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` and `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`.
  - `InitTrigger` through `SP_trigger_once` recover the stock multi-trigger core directly, including `G_SetMovedir`, `SVF_NOCLIENT`, the `wait = 0.2` default, the `TRIGGERED` start-off path through `trigger_enable`, and the legacy `fixed TRIGGERED flag on %s at %s` repair in `SP_trigger_once`.
  - `trigger_relay_use` and `SP_trigger_relay` recover the thin relay wrapper exactly, while `trigger_key_use` and `SP_trigger_key` recover the full key-gated relay path including the `You need the %s` prompt, `misc/keytry.wav`, `misc/keyuse.wav`, coop power-cube bit handling, shared key clear, `FindItemByClassname`, and the stock missing-item or missing-target diagnostics.
  - `trigger_counter_use`, `SP_trigger_counter`, and `SP_trigger_always` match current `src/game/g_trigger.c` directly, including `%i more to go...`, `Sequence completed!`, `misc/talk1.wav`, `wait = -1`, the `count = 2` default, and the forced minimum `delay = 0.2` in the always-trigger wrapper.
  - `trigger_push_touch`, `SP_trigger_push`, `hurt_use`, `hurt_touch`, and `SP_trigger_hurt` recover the stock push and hurt hazard layer directly, including `misc/windfly.wav`, `world/electro.wav`, `speed = 1000`, `dmg = 5`, `START_OFF`, `TOGGLE`, `SLOW`, and `DAMAGE_NO_PROTECTION`.
  - `trigger_gravity_touch`, `SP_trigger_gravity`, `trigger_monsterjump_touch`, and `SP_trigger_monsterjump` recover the remaining stock movement-affecting trigger wrappers in this tranche, including the `trigger_gravity without gravity set at %s` diagnostic, the `atoi(st.gravity)` parse, the `YAW 0 -> 360` fix, and the stored height lift in `movedir[2]`.
- Suggested rename/type:
  - Keep the stock `g_trigger.c` names above.
  - Treat the next open retail band starting at `0x10019BA0` as the later custom teleport tranche; the stock trigger-utility band above is now directly recovered and should no longer be described through raw `FUN_...` placeholders.
- Related items: `src/game/g_trigger.c`, `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - This stock tranche is now directly recovered; the next nearby unmapped space is the post-teleport helper band beginning at `0x10019F40`.

## `g_trigger.c` Custom Teleport Band

Identifier: `trigger_teleport_touch @ 0x10019BA0`, `trigger_teleport_enable @ 0x10019D20`, `trigger_teleport_disable @ 0x10019D40`, `trigger_teleport_activate @ 0x10019D60`, `trigger_teleport_toggle @ 0x10019D90`, and `SP_trigger_teleport @ 0x10019DB0`
- Likely role: the retail Oblivion custom `trigger_teleport` implementation layered on top of the stock trigger framework, including enable/disable/toggle control, one-frame activation, and the custom destination lookup plus teleport-state handling.
- Evidence:
  - The selected Ghidra corpus now carries all six addresses above directly in `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` and `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`; `trigger_teleport_toggle` is created as a clean standalone selected function at `0x10019D90`.
  - `trigger_teleport_touch` directly recovers the gameplay path in current `src/game/g_trigger.c`: debounce via `touch_debounce_time`, player-vs-monster spawnflag gates, destination lookup through repeated `G_Find(..., FOFS(targetname), self->target)`, the `Couldn't find destination` diagnostic, unlink, origin and old_origin copy plus `+10` z offset, velocity clear, `groundentity = NULL`, `teleport_time = level.time`, optional teleport events, client pmove hold flags and delta-angle rebuild, `KillBox`, and relink.
  - The touch body also shows that the current `trigger_teleport_find_destination` helper is compiled into the retail touch routine instead of surfacing as its own standalone function. It prefers `info_teleport_dest` but still falls back to `misc_teleporter_dest`, matching the current source logic.
  - `trigger_teleport_enable`, `trigger_teleport_disable`, `trigger_teleport_activate`, and `trigger_teleport_toggle` match the control wrappers directly: enable installs the touch callback and clears think state; disable clears the touch callback and prints `disabled`; activate enables and schedules disable at `level.time + FRAMETIME`; toggle branches between enable and disable based on the live `touch` pointer.
  - `SP_trigger_teleport` matches the current custom spawn wrapper directly: it validates `target`, prints `teleporter without a target.` on failure, sets `MOVETYPE_NONE`, `SOLID_TRIGGER`, and `SVF_NOCLIENT`, defaults `wait = 0.2`, installs the custom use path, and emits the stock ignored-spawnflag diagnostics for the one-shot `NOTOUCH` activation mode.
- Suggested rename/type:
  - Keep the current `src/game/g_trigger.c` names above.
  - Keep `trigger_teleport_find_destination` documented as inlined into `trigger_teleport_touch` instead of forcing a standalone symbol with no retail function start.
- Related items: `src/game/g_trigger.c`, `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - The adjacent low-address helper band is now partly resolved into `g_turret.c` plus `g_utils.c`; the remaining nearby work is the still-unpromoted turret-driver spillover between `SP_turret_base` and `Think_Delay`.

## `SP_trigger_*` Spawn-Wrapper To Helper Chain

Identifier: `SP_trigger_multiple @ 0x10019120`, `SP_trigger_once @ 0x10019210`, `SP_trigger_relay @ 0x100192B0`, `SP_trigger_key @ 0x10019530`, `SP_trigger_counter @ 0x100196A0`, `SP_trigger_always @ 0x100196D0`, `SP_trigger_push @ 0x10019850`, `SP_trigger_hurt @ 0x100199C0`, `SP_trigger_gravity @ 0x10019A60`, `SP_trigger_monsterjump @ 0x10019B30`, and `SP_trigger_teleport @ 0x10019DB0`
- Likely role: a consolidated retail map of every `SP_trigger_*` spawn wrapper in `src/game/g_trigger.c` and the immediate callback chain each one installs or reaches.
- Evidence:
  - The selected Ghidra corpus now carries every retail `SP_trigger_*` wrapper present in current `src/game/g_trigger.c`, plus the shared helper set that those wrappers wire: `InitTrigger`, `multi_wait`, `multi_trigger`, `Use_Multi`, `Touch_Multi`, `trigger_enable`, `trigger_relay_use`, `trigger_key_use`, `trigger_counter_use`, `trigger_push_touch`, `hurt_use`, `hurt_touch`, `trigger_gravity_touch`, `trigger_monsterjump_touch`, `trigger_teleport_touch`, `trigger_teleport_enable`, `trigger_teleport_disable`, `trigger_teleport_activate`, and `trigger_teleport_toggle`.
  - `SP_trigger_multiple` is the retail root for the stock multi-trigger chain: default `Touch_Multi`, optional `trigger_enable` start-off path, then `Use_Multi -> multi_trigger`, with `multi_trigger` either rescheduling `multi_wait` or clearing `touch` and freeing the entity.
  - `SP_trigger_once` is not a separate runtime chain. Retail only repairs the bad legacy `TRIGGERED` bit, forces `wait = -1`, and immediately reuses `SP_trigger_multiple`, so its real tail is the same `Touch_Multi` or `Use_Multi -> multi_trigger -> G_FreeEdict` path as the stock once-trigger.
  - `SP_trigger_relay`, `SP_trigger_key`, and `SP_trigger_counter` are the three use-driven trigger wrappers in this tranche. Retail shows the exact split: relay installs only `trigger_relay_use`, key installs only `trigger_key_use`, and counter installs `trigger_counter_use`, which then falls back into `multi_trigger` instead of duplicating the rearm or free logic.
  - `SP_trigger_push`, `SP_trigger_hurt`, `SP_trigger_gravity`, and `SP_trigger_monsterjump` all route through the shared `InitTrigger` setup before installing their specialized touch callback. `SP_trigger_hurt` is the one exception that can also expose a live `hurt_use` toggle path when the retail wrapper keeps `TOGGLE` or `START_OFF`.
  - `SP_trigger_always` is the one wrapper in this family with no persistent callback chain: it only clamps `delay` to `0.2` and immediately fires `G_UseTargets(self, self)`.
  - `SP_trigger_teleport` is deliberately separate from the stock `InitTrigger` family. Retail wires the custom touch or activation or enable or disable control chain directly, and the current `trigger_teleport_find_destination` helper is compiled into `trigger_teleport_touch` rather than existing as its own function start.
- Suggested rename/type:
  - Keep the current `src/game/g_trigger.c` names above.
  - Treat the trigger spawn-wrapper map as closed for the current retail surface; the remaining nearby work is outside the `SP_trigger_*` family and sits in the post-teleport helper band.
- Related items: `src/game/g_trigger.c`, `docs-dev/reverse-engineering-symbol-map.md`, `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`.
- Confidence: High.
- Open questions:
  - None on the wrapper-to-helper mapping itself. The only nearby ambiguity is still the adjacent post-teleport helper spillover, not the `SP_trigger_*` surface.

## Adjacent `g_turret.c` And `g_utils.c` Helper Band

Identifier: `AnglesNormalize @ 0x10019E90`, `SnapToEights @ 0x10019F40`, `turret_breach_fire @ 0x10019FE0`, `turret_breach_think @ 0x1001A100`, `turret_breach_finish_init @ 0x1001A4B0`, `SP_turret_breach @ 0x1001A540`, `SP_turret_base @ 0x1001A670`, `Think_Delay @ 0x1001AE00`, `G_UseTargets @ 0x1001AE20`, `tv @ 0x1001B040`, `G_SetMovedir @ 0x1001B0C0`, and `vectoangles @ 0x1001B1E0`
- Likely role: the post-teleport low-address helper band transitions out of custom trigger code into the retail turret-breach setup and the early shared `g_utils.c` support layer.
- Evidence:
  - The selected Ghidra corpus now carries all twelve addresses above directly in `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` and `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`.
  - `AnglesNormalize` is the exact two-axis clamp from current `src/game/g_turret.c`, and the recovered `turret_breach_think` body calls it twice on the live and desired angle vectors. That makes the earlier `trigger_teleport_normalize_angles` alias too narrow.
  - `SnapToEights` matches the stock turret quantizer exactly: multiply by `8`, bias by `0.5` toward the sign of the value, truncate, then rescale by `0.125`.
  - `turret_breach_fire` directly rebuilds the muzzle point from `self->move_origin` using `AngleVectors` plus three `VectorMA` applications, calls `fire_rocket(self->teammaster->owner, ...)`, and emits `weapons/rocklf1a.wav`, which is the exact current `src/game/g_turret.c` fire path.
  - `turret_breach_think` directly matches the current breach controller: normalize and clamp current and desired angles, derive `avelocity`, mirror yaw into the teamchain, reposition the attached driver through `SnapToEights`, and consume the `65536` fire latch.
  - `turret_breach_finish_init`, `SP_turret_breach`, and `SP_turret_base` match the current source wrappers directly, including the `G_PickTarget` muzzle-anchor setup and the BSP push-solid spawn configuration.
  - `Think_Delay` and `G_UseTargets` match current `src/game/g_utils.c` exactly, including delayed-use spawning, the `Think_Delay with no activator` diagnostic, message or sound dispatch, killtarget removal, target firing, the `func_areaportal` skip, and the self-use warning.
  - `tv` matches the stock 8-slot temporary vector ring, `G_SetMovedir` matches the `VEC_UP` / `VEC_DOWN` special cases plus `AngleVectors` fallback, and `vectoangles` matches the vertical special case plus negated-pitch conversion used across the current source.
- Suggested rename/type:
  - Keep the current `src/game/g_turret.c` and `src/game/g_utils.c` names above.
  - Treat `AnglesNormalize @ 0x10019E90` as the shared low-address helper name going forward instead of the narrower teleport-specific alias.
- Related items: `src/game/g_turret.c`, `src/game/g_utils.c`, `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - The committed corpus still does not isolate the `turret_driver_die` / `turret_driver_think` / `turret_driver_link` / `SP_turret_driver` band as direct selected functions.

## Retail Dummy-Body And Remote-View Support Cluster

Identifier: `0x10002CA0`, `0x10002D40`, `0x10002DE0`, `0x10002E20`
- Likely role: shared retail dummy-body remote-view support centered on a client-owned `dummy_body` helper entity and reused by RTDU plus other controller paths.
- Evidence:
  - `0x10002D40` unconditionally spawns a fresh `dummy_body` edict, stores it in client slot `+0xF14`, sets the active flag at `+0xF0C`, applies `SVF_NOCLIENT` to the live player, relinks the player, copies the player bbox into the helper, and then calls `0x10002CA0`.
  - `0x10002CA0` copies the player `s.origin`, `s.angles`, `s.modelindex`, `s.modelindex2`, `s.frame`, `velocity`, and `avelocity` into that helper edict, then relinks it.
  - `0x10002DE0` reads the helper edict back from `+0xF14`, clears that slot and the active flag at `+0xF0C`, restores the player `SVF_NOCLIENT` bit, relinks the player, and then frees the `dummy_body`.
  - `0x10002E20` copies the tracked target origin into `ps.pmove.origin`, copies tracked angles into `ps.viewangles`, feeds client slots `+0xF1C` / `+0xF20` / `+0xF24` back into `ps.viewoffset`, and forces `PM_FREEZE`.
  - `ClientEndServerFrame @ 0x10034D80` gates `SV_CalcViewOffset` plus `SV_CalcGunOffset` on the same active flag at `+0xF0C`, then after `G_SetClientFrame` directly calls `0x10002E20` followed by `0x10002CA0`; the current source mirrors that tail through `Camera_ClientPostFrame()`.
  - Nearby functions `0x10002F20`, `RTDU_SpawnTurret`, `RTDU_TurretThink`, `RTDU_BeginRemoteView`, and `RTDU_EndRemoteView` remain in the same call and data neighborhood, suggesting a wider retail-only support cluster.
- Suggested rename/type: keep these as behavioral aliases only for now (`DummyBody_Sync`, `DummyBody_Setup`, `DummyBody_Teardown`, and `RemoteView_ApplyClientState`) rather than forcing stock Quake II spectator names.
- Related items: `docs-dev/reverse-engineering-symbol-map.md`, `src/game/g_camera.c`, `src/game/p_hud.c`, `src/game/p_view.c`.
- Confidence: High.
- Open questions:
  - whether any adjacent, still-unnamed client fields around the remote-view band belong to the same retail helper cluster
  - whether the reconstruction needs a retail-only helper layer here instead of forcing these bodies into stock spectator names

## RTDU Item, Turret, And Remote-View Helpers

Identifier: `rtdu_use @ 0x10014270`, `RTDU_SpawnTurret @ 0x100142E0`, `RTDU_TurretThink @ 0x10014320`, `RTDU_RemoveTurret @ 0x100144C0`, `RTDU_BeginRemoteView @ 0x10014530`, `RTDU_EndRemoteView @ 0x100145C0`, `RTDU_TurretAttack @ 0x10014610`, `RTDU_RemoteViewCmd @ 0x10014750`, and `RTDU_InitTurret @ 0x100147D0`
- Likely role: the retail RTDU item-use path, turret spawn/init/update flow, remote-view enter/exit path, firing loop, and teardown path.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records the eight selected-function RTDU bodies (`rtdu_use` through `RTDU_InitTurret`) as exact-address existing functions renamed to stable retail identities, and the assembly corpus also exposes the standalone callback body at `0x10014750`.
  - `rtdu_use` checks the owner client slot at `0xF18`; when it still points at a live entity labeled `RTDU`, the body toggles `RTDU_BeginRemoteView` vs `RTDU_EndRemoteView` based on the dummy-body flag at `0xF0C`, otherwise it spawns a new turret through `RTDU_SpawnTurret`.
  - `RTDU_SpawnTurret` allocates a new edict through `G_Spawn`, calls `RTDU_InitTurret`, stores the owner pointer, copies owner origin plus yaw, and writes the spawned turret pointer back into the owner client slot at `0xF18`.
  - `RTDU_InitTurret` loads `models/objects/rtdu/rtdu.md2`, resolves the item pointer through the retail `rtdu` string, installs `RTDU_TurretThink` plus `RTDU_RemoveTurret`, then spawns a linked child labeled `RTDUTripod` with `models/objects/rtdu/tripod.md2` at `origin.z + 40`; the direct assembly anchor is `data_10044288 = 0x42200000`.
  - `RTDU_TurretThink` validates the owner/client link, mirrors origin and angles into the tripod child without reapplying the init-time `+40` Z lift, refreshes the activation-time field, and rearms itself at `FRAMETIME`.
  - `RTDU_BeginRemoteView` and `RTDU_EndRemoteView` directly call the retail dummy-body helpers at `0x10002D40` and `0x10002DE0`, back up and restore the owner client field at `0x58` through `0xF28`, and install or remove the RTDU remote-view input callback at `0xF10`.
  - The callback body at `0x10014750` zeroes `forwardmove`, `sidemove`, and `upmove`, converts the three command-angle shorts into turret `s.angles[]` floats with pitch scaled by `1/3`, then routes `BUTTON_ATTACK` into `RTDU_TurretAttack` before clearing that bit from the live `usercmd_t`.
  - `RTDU_TurretAttack` decrements the turret ammo field and the owner's RTDU inventory count, derives the muzzle point through `AngleVectors` plus `G_ProjectSource`, fires the shared projectile helper with the retail RTDU constants, advances the frame loop from `7` through `15`, and emits `PlayerNoise` for the owner.
  - Direct string scans against the retail DLL also anchor the public RTDU surface: `weapon_rtdu`, `RTDU`, `w_rtdu`, `models/objects/rtdu/rtdu.md2`, `RTDUTripod`, and `models/objects/rtdu/tripod.md2`.
- Suggested rename/type: keep the direct names above; `RTDU_RemoteViewCmd` is now a safe behavioral alias for the standalone callback body at `0x10014750`.
- Related items: `src/game/g_rtdu.c`, `src/game/g_main.c`, `src/game/g_save.c`, `src/game/p_client.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High for `rtdu_use`, `RTDU_SpawnTurret`, `RTDU_TurretThink`, `RTDU_RemoveTurret`, `RTDU_TurretAttack`, and `RTDU_InitTurret`; Medium for `RTDU_BeginRemoteView` and `RTDU_EndRemoteView`.
- Open questions:
  - none inside the recovered RTDU band; the remaining uncertainty sits in the wider spectator/dummy-body helper cluster rather than in RTDU-specific control flow

## Generic Remote-View Attach/Detach And Retail Camera Support

Identifier: `0x10002CA0`, `0x10002D40`, `0x10002DE0`, `0x10002E20`, `0x10002EB0`, `0x10002F20`, `0x10002F70`, `0x100031A0`, `0x100031E0`, `0x10003392`, `0x100035D0`, `0x100035F0`, `0x100036B0`, `0x10003760`, `0x10003880`, and `0x10003BA0`
- Likely role: shared retail remote-view helper band reused by RTDU and the retail `misc_camera` or `misc_camera_target` path for dummy-body setup, tracked-entity attach/detach, input suppression, controller activation, and path-node scheduling while a camera controller owns the view.
- Evidence:
  - `0x10002CA0` copies the active player's `origin`, `angles`, `modelindex`, `modelindex2`, `frame`, `velocity`, and `avelocity` into the dummy-body edict stored at `+0xF14`, then relinks that dummy.
  - `0x10002D40` allocates the dummy body through `G_Spawn`, stores it in the client slot at `+0xF14`, raises the remote-view active flag at `+0xF0C`, hides the player with `SVF_NOCLIENT`, copies the player's bbox extents into the dummy, and then calls `0x10002CA0`.
  - `0x10002DE0` clears the dummy-body slot, clears the remote-view active flag, restores player visibility, relinks the player, and frees the spawned dummy edict.
  - `0x10002E20` writes the tracked entity origin into `ps.pmove.origin`, copies its angles into `ps.viewangles`, restores the three stored remote-view offsets from `+0xF1C..+0xF24`, and forces `PM_FREEZE`.
  - `0x10002EB0` checks whether the client tracked-entity slot at `+0xF18` is empty, stores the passed entity there, calls the dummy-body setup helper at `0x10002D40`, backs up `ps.gunindex` into `+0xF28`, zeroes the live `ps.gunindex`, installs the callback currently held in `PTR_LAB_10046048` into `+0xF10`, and clears `+0xF24`, `+0xF20`, and `+0xF1C`.
  - `0x10002F20` checks whether `+0xF18` still matches the passed entity, calls the dummy-body teardown helper at `0x10002DE0`, clears `+0xF18`, restores `ps.gunindex` from `+0xF28`, and clears `+0xF0C` plus `+0xF10`.
  - `0x10002F70` is the shared controller or path move-step state machine for both `misc_camera` and `misc_camera_target`; it advances the `0x320..0x34C` fields, carries the `no main move` split, reuses node `delay` values, and hops to the next node through `G_PickTarget`.
  - `0x100031A0` loads the tracked entity from `+0xF18`, tests its spawnflags bit `1`, then zeroes `usercmd.angles[0..2]`, `forwardmove`, `sidemove`, and `upmove`, and masks `buttons &= 0xFC`.
  - `0x100031E0` iterates clients, calls `0x10002F20` for the passed entity, then clears the target entity's motion/state fields, matching the wider detach or cleanup flow used by the retail `misc_camera` controller.
  - The activation block around `0x10003392` temporarily sets `PTR_LAB_10046048 = &LAB_100031A0`, iterates live clients, calls `0x10002EB0(client, controller)` for each, then clears the global callback pointer again before arming the controller; this shows retail `misc_camera` reuses the generic remote-view helpers rather than a bespoke RTDU-only path.
  - `0x100035D0` is the retail `misc_camera` use-toggle wrapper, `0x100035F0` is the `misc_camera` spawn wrapper, `0x100036B0` and `0x10003760` are the `misc_camera_target` think or use callbacks, `0x10003880` is the `misc_camera_target` spawn wrapper, and `0x10003BA0` is the `trigger_misc_camera` spawn wrapper that fans into the stock trigger helper band.
- Suggested rename/type: keep `DummyBody_Sync`, `DummyBody_Setup`, `DummyBody_Teardown`, and `RemoteView_ApplyClientState` as stable helper names for the newly surfaced `0x10002CA0..0x10002E20` quartet; continue treating `RemoteView_AttachController`, `RemoteView_DetachController`, `RemoteView_Begin`, `RemoteView_End`, and `Camera_RemoteViewCmd` as behavioral aliases for the wider recovered helper band until the exact retail symbol names stabilize, and keep the retired stock chase-camera helpers out of the active source tree.
- Related items: `src/game/g_camera.c`, `src/game/p_client.c`, `src/game/p_view.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High for behavior; Medium for final standalone helper names.
- Open questions:
  - whether `0x10002EB0`, `0x10002F20`, and `0x100031E0` should eventually be promoted to stable retail names or kept documented as shared helper aliases

## Weapon Regeneration Helper

Identifier: `Oblivion_UpdateWeaponRegen @ 0x10037CD0`
- Likely role: retail Oblivion ammo-regeneration helper for the plasma weapon pair.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now reports `Oblivion_UpdateWeaponRegen` as the exact-address function at `0x10037CD0`.
  - The direct disassembly checks `client->plasma_pistol_next_regen + 1.0 < level.time`, increments `PistolPlasma` up to `pers.max_pistolplasma`, and then stores the current time back to `client + 0xF2C`.
  - The same body checks `pers.plasma_rifle_regen_divisor @ +0x710`, computes `1.0 / divisor + client->plasma_rifle_next_regen`, increments `Rifle Plasma` up to `pers.max_rifleplasma` when that interval has elapsed, and then stores the current time back to `client + 0xF30`.
  - The recovered `ClientThink @ 0x10031D70` body calls `Oblivion_UpdateWeaponRegen(param_1)` in the post-attack `Think_Weapon(param_1)` thunk tail; `Think_Weapon @ 0x10035830` itself does not contain the regen logic, and the selected body does not expose a separate chase-camera branch around that tail call.
- Suggested rename/type: keep the current reconstruction name; this is a retail Oblivion extension absent from stock Quake II.
 - Related items: `src/game/p_client.c`, `src/game/p_weapon.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions: broader weapon-subsystem mapping still needs more direct recovery beyond this helper and `Think_Weapon`.

## Rifle Plasma Ammo Pickup Surface

Identifier: `Pickup_RiflePlasma @ 0x10037C80`
- Likely role: the retail pickup callback behind the `ammo_rifleplasma` item, combining a permanent rifle-plasma capacity or regen upgrade with a one-time ammo grant.
- Evidence:
  - The direct body checks `other->client`, adds `50` to `pers.max_rifleplasma @ +0x704`, increments `pers.plasma_rifle_regen_divisor @ +0x710`, then calls `Add_Ammo(other, ent->item, ent->item->quantity)` and returns success.
  - The retail `gitem_t` dump at `0x10047150` points the `ammo_rifleplasma` row's `pickup` field directly at `0x10037C80`, sets quantity `50`, and marks the item with flags `IT_AMMO | IT_POWERUP`.
  - This explains why `Oblivion_UpdateWeaponRegen @ 0x10037CD0` uses a divisor-based rifle timer while the pistol side stays at a fixed one-second cadence: each retail rifle-plasma pickup permanently increases the regen rate.
- Suggested rename/type: keep `Pickup_RiflePlasma` as the stable retail pickup name for the `Rifle Plasma` ammo item.
- Related items: `src/game/g_items.c`, `src/game/p_weapon.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - whether the retail UI or mission layer ever surfaces the rifle-plasma divisor directly outside the passive regen timer behavior

## Entity Utility And Telefrag Helper

Identifier: `KillBox @ 0x1001B510`
- Likely role: stock Quake II occupied-space clearing helper used by monster triggered-spawn and player respawn paths when the spawn point is already blocked.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now reports `KillBox` as an exact-address existing function renamed to the stable retail helper identity.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows a looped `gi.trace(ent->s.origin, ent->mins, ent->maxs, ent->s.origin, NULL, MASK_PLAYERSOLID)` at the entity origin, followed by the stock `T_Damage(..., 100000, 0, DAMAGE_NO_PROTECTION, MOD_TELEFRAG)` kill path against the blocking occupant.
  - The same body returns `0` only if the blocking entity survives after damage and otherwise keeps looping until the box is clear, matching `src/game/g_utils.c` exactly.
  - Current recovered callers include `monster_triggered_spawn`, and the same helper also appears in the respawn path, which is the stock Quake II usage pattern.
- Suggested rename/type: keep the stock `KillBox` name.
- Related items: `src/game/g_utils.c`, `src/game/g_monster.c`, `src/game/p_client.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions: none on the name; remaining work is only broader caller coverage.

## Item Lookup, Pickup, Armor, Respawn, Spawn, And Projection Helpers

Identifier: `GetItemByIndex @ 0x1000B0E0`, `FindItemByClassname @ 0x1000B100`, `FindItem @ 0x1000B150`, `DoRespawn @ 0x1000B1A0`, `SetRespawn @ 0x1000B210`, `Pickup_Powerup @ 0x1000B270`, `Drop_General @ 0x1000B3C0`, `Pickup_Adrenaline @ 0x1000B410`, `Pickup_AncientHead @ 0x1000B490`, `Pickup_Bandolier @ 0x1000B4F0`, `Pickup_Pack @ 0x1000B650`, `Use_Quad @ 0x1000B990`, `Use_Breather @ 0x1000BA60`, `Use_Envirosuit @ 0x1000BAF0`, `Use_Invulnerability @ 0x1000BB80`, `Use_Silencer @ 0x1000BC30`, `Pickup_Key @ 0x1000BC90`, `Add_Ammo @ 0x1000BDF0`, `Pickup_Ammo @ 0x1000BEF0`, `Drop_Ammo @ 0x1000C010`, `MegaHealth_think @ 0x1000C0E0`, `Pickup_Health @ 0x1000C150`, `ArmorIndex @ 0x1000C290`, `Pickup_Armor @ 0x1000C2E0`, `PowerArmorType @ 0x1000C460`, `Use_PowerArmor @ 0x1000C4B0`, `Pickup_PowerArmor @ 0x1000C560`, `Drop_PowerArmor @ 0x1000C5F0`, `Touch_Item @ 0x1000C650`, `Drop_Item @ 0x1000C850`, `drop_temp_touch @ 0x1000CA10`, `drop_make_touchable @ 0x1000CA40`, `Use_Item @ 0x1000CA80`, `droptofloor @ 0x1000CAE0`, `PrecacheItem @ 0x1000CD00`, `SpawnItem @ 0x1000CF20`, `SP_item_health @ 0x1000D160`, `SP_item_health_small @ 0x1000D1D0`, `SP_item_health_large @ 0x1000D250`, `SP_item_health_mega @ 0x1000D2C0`, `InitItems @ 0x1000D340`, `SetItemNames @ 0x1000D350`, `Pickup_Weapon @ 0x10035260`, `P_ProjectSource @ 0x10035DB0`
- Likely role: retail item-table lookup, generic pickup and drop dispatch, timed powerup use, key handling, health and health-spawn wrapper handling, armor and power-armor state handling, item touch and spawn setup, dropped-item touchability, trigger-spawn activation, ammo accounting, weapon pickup logic, and player-handed projectile origin projection.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now reports all of the addresses above as exact-address existing functions renamed to stable retail identities.
  - `GetItemByIndex`, `FindItemByClassname`, and `FindItem` recover all three stock item-table lookup entry points over the retail `itemlist` rooted at `0x10046928`.
  - `DoRespawn` and `SetRespawn` match the stock Quake II respawn flow: team-chain selection, `SVF_NOCLIENT` clear, trigger-solid restore, relink, respawn event, and delayed `nextthink` wiring through `DoRespawn`.
  - `Pickup_Powerup`, `Drop_General`, `Pickup_Adrenaline`, `Pickup_AncientHead`, `Pickup_Bandolier`, `Pickup_Pack`, `Use_Quad`, `Use_Breather`, `Use_Envirosuit`, `Use_Invulnerability`, `Use_Silencer`, and `Pickup_Key` now cover the early and mid-band `g_items.c` pickup path: timed powerup inventory and auto-use, generic drop flow, health-cap raises, the exact retail bandolier cap/grant surface (`bullets=250`, `shells=150`, `cells=250`, `slugs=75`, with bundled `Bullets` and `Shells` only), the exact retail pack cap/grant surface (`bullets=300`, `shells=200`, `rockets=100`, `grenades=100`, `mines=10`, `cells=300`, `slugs=100`, `detpacks=5`, `dods=2`, with bundled `Bullets`, `Shells`, `Cells`, `Grenades`, `Rockets`, and `Slugs` only), the timed-use frame counters for quad/breather/enviro/invulnerability, the silencer-shot increment, and the coop `key_power_cube` bitfield handling.
  - `Add_Ammo` matches the extended Oblivion ammo-tag map, including the extra retail ammo-cap fields for mines, detpacks, DOD rounds, and the two plasma ammo types.
  - `MegaHealth_think` and `Pickup_Health` recover the timed-mega-health path directly, including over-max health drainback, style-flag checks, and the `MegaHealth_think` callback installation.
  - `Pickup_Ammo`, `Drop_Ammo`, `ArmorIndex`, `Pickup_Armor`, `PowerArmorType`, `Use_PowerArmor`, `Pickup_PowerArmor`, `Drop_PowerArmor`, `Touch_Item`, and `Drop_Item` match the current `src/game/g_items.c` flow for ammo pickups, armor salvage, power-armor toggling and forced shutoff on last-drop, touch-time pickup HUD state, grenade-ammo drop protection, and tossed dropped-item spawn setup.
  - `drop_temp_touch`, `drop_make_touchable`, `Use_Item`, and `droptofloor` recover the dropped-item and trigger-spawn activation layer directly from the retail body, including owner-ignore touch, the deathmatch self-free timeout, `ITEM_NO_TOUCH`, `ITEM_TRIGGER_SPAWN`, and the floor-trace `startsolid` path.
  - `PrecacheItem`, `SpawnItem`, `SP_item_health`, `SP_item_health_small`, `SP_item_health_large`, `SP_item_health_mega`, `InitItems`, and `SetItemNames` recover the item-spawn and registration layer: recursive asset precache, deathmatch or coop spawn filtering, all four health spawn wrappers, `game.num_items` initialization, configstring item names, and cached armor or power-armor indices.
  - `Pickup_Weapon` matches the retail weapon pickup path in `src/game/p_weapon.c`, including the `FindItem`/`Add_Ammo` handoff, the recovered `weapon_hellfury -> 16 rockets` pickup special-case, respawn logic, and default-weapon auto-switch from `Plasma Pistol`.
  - `P_ProjectSource` matches the local player-handed offset helper in `src/game/p_weapon.c` and forwards into the lower-level projected-source helper used by both weapon fire and item tossing.
- Suggested rename/type: keep the source-aligned names above.
- Related items: `src/game/g_items.c`, `src/game/p_weapon.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - the core `g_items.c` timed-use, key, and health-wrapper band is now directly named; remaining item-adjacent gaps are mostly higher-level weapon wrappers or any retail-only item branches outside the current selected pass
  - the lower-level helper under `FUN_1001ABA0` is now strongly evidenced as `G_ProjectSource`, but it still lives as a common-helper alias rather than a selected direct rename

## Misc Entity, Clock, And Teleporter Helpers

Identifier: `SP_misc_banner @ 0x10010200`, `SP_misc_viper @ 0x100103F0`, `SP_misc_bigviper @ 0x100104F0`, `SP_misc_strogg_ship @ 0x100107F0`, `SP_misc_satellite_dish @ 0x10010960`, `SP_misc_gib_arm @ 0x10010A50`, `SP_misc_gib_leg @ 0x10010B40`, `SP_misc_gib_head @ 0x10010C30`, `SP_target_character @ 0x10010D20`, `target_string_use @ 0x10010D60`, `func_clock_format_countdown @ 0x10011000`, `SP_func_clock @ 0x10011160`, `teleporter_touch @ 0x10011240`, `SP_misc_teleporter @ 0x10011390`, `SP_misc_teleporter_dest @ 0x100114A0`
- Likely role: the stock `g_misc.c` world-entity band covering animated banners, trigger-spawned flyby ships, the satellite dish set piece, target-string displays, countdown-clock setup, teleporter discs, and target-spawnable gib props.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now reports each address above as an exact-address existing function renamed to the stable `g_misc.c` identity.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `SP_misc_banner` installing the banner model, seeding a random frame modulo `16`, and arming the local frame-advance think exactly like stock Quake II.
  - The same selected decompilation shows `SP_misc_viper` and `SP_misc_strogg_ship` validating `target`, defaulting `speed` to `300`, installing `MOVETYPE_PUSH` plus the expected model and bbox, hiding the entity with `SVF_NOCLIENT`, and wiring the local reveal-or-`train_use` helper plus `func_train_find`.
  - `SP_misc_bigviper` and `SP_misc_satellite_dish` match the stock bbox and model setup for the intro-scene viper and the satellite dish set piece, with the dish also wiring the local use callback.
  - `SP_misc_gib_arm`, `SP_misc_gib_leg`, and `SP_misc_gib_head` each install the expected gib model, `EF_GIB`, toss movement, damageable gib death path, random angular velocity, and a timed free callback.
  - `SP_target_character` matches the stock string-display character entity, and `target_string_use` walks the teamchain, uses each member's `count` as a message index, and maps characters into the stock `0-9`, `-`, `:`, or blank frame set.
  - `func_clock_format_countdown` matches the stock style `0`, `1`, and `2` countdown formatter, including the zero-fill fixes for `mm:ss` and `hh:mm:ss`, while `SP_func_clock` validates `target` and timer-down `count`, defaults timer-up clocks to `3600`, resets the live timer state, allocates the `16` byte message buffer, and installs the local think or optional use callback.
  - `teleporter_touch` matches the stock teleporter trigger path: destination lookup by targetname, unlink, destination origin copy plus `+10` z offset, velocity clear, teleport hold flags, delta-angle rebuild, `KillBox`, and relink. `SP_misc_teleporter` and `SP_misc_teleporter_dest` match the stock teleporter disc and destination wrappers around that touch helper.
- Suggested rename/type: keep the stock `g_misc.c` names above.
- Related items: `src/game/g_misc.c`, `references/source-code/Quake-2-master/game/g_misc.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - `misc_banner_think`, the local viper or strogg `*_use` wrappers, and the smaller clock locals remain embedded labels rather than selected standalone functions

## SP_misc_* Spawn-Wrapper To Helper Chain

Identifier: `SP_misc_banner @ 0x10010200`, `SP_misc_viper @ 0x100103F0`, `SP_misc_bigviper @ 0x100104F0`, `SP_misc_strogg_ship @ 0x100107F0`, `SP_misc_satellite_dish @ 0x10010960`, `SP_misc_gib_arm @ 0x10010A50`, `SP_misc_gib_leg @ 0x10010B40`, `SP_misc_gib_head @ 0x10010C30`, `SP_misc_teleporter @ 0x10011390`, `SP_misc_teleporter_dest @ 0x100114A0`, `SP_misc_actor @ 0x1001F460`
- Likely role: consolidated retail spawn-wrapper wiring for the `misc_*` surface, separating the directly recovered world-prop and teleporter wrappers from the current-source-only or not-yet-isolated extras in the broader spawn table.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` reports exact-address direct retail identities for the `SP_misc_*` wrappers above, plus a created selected function for `SP_misc_actor @ 0x1001F460`.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `SP_misc_banner` arming the embedded `misc_banner_think` callback, `SP_misc_viper` and `SP_misc_strogg_ship` wiring the local reveal-or-`train_use` helper plus `func_train_find`, `SP_misc_satellite_dish` wiring the local dish-use callback, the gib wrappers installing `gib_die` and a timed `G_FreeEdict` self-free, and `SP_misc_teleporter` spawning a separate trigger that routes into `teleporter_touch`.
  - The same committed selected corpus already recovers the full actor-side callback band behind `SP_misc_actor`, so that wrapper now anchors directly into `actor_use` plus the `actor_stand` / `actor_walk` / `actor_run` / `actor_attack` lifecycle rather than remaining a disconnected spawn name.
  - The current source spawn table in `src/game/g_spawn.c` still declares additional `SP_misc_*` wrappers (`SP_misc_explobox`, `SP_misc_deadsoldier`, `SP_misc_viper_bomb`, `SP_misc_blackhole`, `SP_misc_eastertank`, `SP_misc_easterchick`, `SP_misc_easterchick2`, `SP_misc_screenfader`), but the committed retail corpus does not yet isolate those as stable function starts. The one extra retail signal so far is the `misc_explobox` classname string read by the recovered retail `bfg_think` body, which confirms the classname exists without yet proving the wrapper-body match.
- Suggested rename/type: keep the direct stock-style `SP_misc_*` names above, keep the local banner or viper or strogg or dish callbacks documented as embedded helpers rather than forced standalone symbols, and keep the unresolved current-source wrappers clearly marked as not yet directly evidenced.
- Related items: `src/game/g_misc.c`, `src/game/m_actor.c`, `src/game/g_spawn.c`, `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High for the direct wrapper-to-helper chains above; Medium for `misc_explobox` as retail classname-string evidence only.
- Open questions:
  - `SP_misc_explobox` has a direct retail classname signal but still is not isolated as a wrapper-body start in the committed corpus.
  - `SP_misc_deadsoldier`, `SP_misc_viper_bomb`, `SP_misc_blackhole`, `SP_misc_eastertank`, `SP_misc_easterchick`, `SP_misc_easterchick2`, and `SP_misc_screenfader` remain current-source wrappers without a second committed retail signal.

## Mine Light Helpers

Identifier: `SP_light_mine1 @ 0x100109D0`, `SP_light_mine2 @ 0x10010A10`
- Likely role: the stock decorative mine-light wrappers that sit between `SP_misc_satellite_dish` and the gib prop spawners in the retail `g_misc.c` world-entity band.
- Evidence:
  - Raw disassembly around `0x100109D0` and `0x10010A10` pushes the exact retail model-string VAs `0x10049514` and `0x1004953C`, which resolve to `models/objects/minelite/light1/tris.md2` and `models/objects/minelite/light2/tris.md2`.
  - Temporary single-target Ghidra probes of those addresses decompile as the expected tiny wrappers: write `MOVETYPE_NONE`, write `SOLID_BBOX`, call `gi.modelindex` with the mine-light path, store the returned model index, and call `gi.linkentity`.
  - The recovered bodies match both the current `src/game/g_misc.c` implementation and the stock Quake II `references/source-code/Quake-2-master/game/g_misc.c` layout and behavior.
- Suggested rename/type: keep the stock `SP_light_mine1` and `SP_light_mine2` names.
- Related items: `src/game/g_misc.c`, `references/source-code/Quake-2-master/game/g_misc.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - None on these wrappers; the only remaining choice in this immediate band is whether tiny adjacent locals should stay documented as embedded labels.

## Pathing, Debug View, And Light Helpers

Identifier: `SP_path_corner @ 0x1000E670`, `point_combat_touch @ 0x1000E7E0`, `SP_point_combat @ 0x1000E940`, `TH_viewthing @ 0x1000E9D0`, `SP_viewthing @ 0x1000EA00`, `SP_info_notnull @ 0x1000EAA0`, `SP_light @ 0x1000EAE0`, `light_use @ 0x1000EB60`
- Likely role: the earlier low-address `g_misc.c` map-logic and debug-object band covering path-corner triggers, combat points, the stock debug `viewthing`, no-op `info_notnull` anchors, and switchable style-controlled lights.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now reports each address above as a direct exact-address identity in the committed selected corpus.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `SP_path_corner` installing the stock trigger-solid wrapper, using the exact `path_corner with no targetname at %s` diagnostic, and compiling the matching `path_corner_touch` flow into the local `LAB_1000E500` tail instead of a separate standalone function.
  - The same selected decompilation shows `point_combat_touch` matching the stock/current source closely: it validates `other->movetarget == self`, optionally retargets through `G_PickTarget`, clears `AI_COMBAT_POINT`, preserves stand-ground behavior, rebuilds the `pathtarget` activator fallback, and calls `G_UseTargets`.
  - The same decompilation plus raw disassembly around `0x1000E940` show `SP_point_combat` performing the deathmatch free-edict check, assigning `point_combat_touch`, installing the stock `(-8,-8,-16)` to `(8,8,16)` trigger bounds, and linking the entity.
  - `TH_viewthing` decompiles as the stock modulo-`7` frame advance with `nextthink = level.time + FRAMETIME`, while `SP_viewthing` prints `viewthing spawned`, installs the banner model plus stock bbox, wires `TH_viewthing`, and schedules the initial `0.5` second think.
  - `SP_info_notnull` decompiles as the minimal origin copy into the paired bbox vectors, which is exactly the stock no-op anchor wrapper.
  - `SP_light` decompiles with the untargeted deathmatch cleanup, the `style >= 32` gating, and the `light_use` callback installation. `light_use` toggles the target light style configstring between the two stock string states and flips the spawnflag bit exactly like the Quake II switchable-light helper.
- Suggested rename/type: keep the stock `g_misc.c` names above; keep `path_corner_touch` documented as the embedded local at `LAB_1000E500` rather than forcing a standalone selected alias.
- Related items: `src/game/g_misc.c`, `references/source-code/Quake-2-master/game/g_misc.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - `path_corner_touch` is still compiler-folded into `SP_path_corner`, so the remaining choice there is documentation style, not identification confidence
  - no stock world-object wrapper remains open in this immediate pathing/light band; the remaining work here is documentation style for embedded locals such as `path_corner_touch`

## SP_info_* Spawn-Wrapper To Helper Chain

Identifier: `SP_info_null`, `SP_info_notnull @ 0x1000EAA0`, `SP_info_teleport_dest`, `SP_info_player_start`, `SP_info_player_deathmatch`, `SP_info_player_coop`, `SP_info_player_intermission`
- Likely role: consolidated spawn-wrapper wiring for the `info_*` surface, covering world anchors, custom-teleport destinations, and the player spawn or intermission classnames that the retail runtime searches by string even where the wrapper bodies themselves are not yet directly isolated.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` directly recovers `SP_info_notnull @ 0x1000EAA0`, and `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows the exact stock no-op anchor behavior: copy `s.origin` into the paired bbox vectors.
  - The already documented retail `trigger_teleport_touch` body searches destination entities by classname and prefers `info_teleport_dest` before falling back to `misc_teleporter_dest`, which is strong retail evidence for the `SP_info_teleport_dest` role even though the wrapper body itself is not yet isolated.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_top_functions.c` and the overlapping selected top-function corpus show the retail intermission path searching `info_player_intermission` first, then falling back through `info_player_start` and `info_player_deathmatch`.
  - The same retail top-function corpus shows direct classname walks for `info_player_start`, `info_player_deathmatch`, and `info_player_coop` inside the spawn-selection layer, which anchors the roles of the `SP_info_player_*` wrappers even without direct standalone wrapper bodies.
  - The current source in `src/game/p_client.c` provides the best source-side reconstruction of the wrapper chains: `SP_info_player_start` schedules `SP_CreateCoopSpots` on `security`, `SP_info_player_deathmatch` delegates to `SP_misc_teleporter_dest`, `SP_info_player_coop` schedules `SP_FixCoopSpots` on the stock hack-map set, and `SP_info_player_intermission` remains empty. Those source-side helpers should still be treated as reconstruction scaffolding until a second retail signal surfaces.
  - The current source spawn table in `src/game/g_spawn.c` also shows `func_group -> SP_info_null`, with `SP_info_null` simply freeing the entity, but that alias has not yet surfaced as a direct or string-backed retail signal in the committed corpus.
- Suggested rename/type: keep the stock `SP_info_*` names above, treat `SP_info_notnull` as direct retail, treat `SP_info_player_*` and `SP_info_teleport_dest` as high-confidence role mappings from retail class-name/call-site evidence, and keep `SP_info_null` / `func_group` as source-side mappings until a stronger retail signal appears.
- Related items: `src/game/g_misc.c`, `src/game/p_client.c`, `src/game/g_spawn.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_top_functions.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High for `SP_info_notnull`, `SP_info_teleport_dest` as the preferred custom-teleport destination class, and the spawn/intermission roles of `SP_info_player_start`, `SP_info_player_deathmatch`, `SP_info_player_coop`, and `SP_info_player_intermission`; Medium for exact wrapper-body parity of the non-direct `SP_info_*` entries and for the `func_group -> SP_info_null` alias.
- Open questions:
  - `SP_info_teleport_dest`, `SP_info_player_start`, `SP_info_player_deathmatch`, `SP_info_player_coop`, and `SP_info_player_intermission` still are not isolated as standalone retail function starts in the committed selected corpus.
  - `SP_info_null` and the `func_group` alias currently remain source-side mappings without a second committed retail signal.

## Client Death, Persistence, And Weapon Core Helpers

Identifier: `player_die @ 0x10030160`, `InitClientPersistant @ 0x10030460`, `ChangeWeapon @ 0x10035420`, `NoAmmoWeaponChange @ 0x10035530`, `Think_Weapon @ 0x10035830`, `Use_Weapon @ 0x100358C0`, `Drop_Weapon @ 0x10035980`, `Weapon_Generic @ 0x10035A10`, `weapon_grenade_fire @ 0x10035CA0`, `Weapon_Grenade @ 0x10035E20`, `weapon_grenadelauncher_fire @ 0x100360B0`, `Weapon_GrenadeLauncher @ 0x10036210`, `Weapon_RocketLauncher_Fire @ 0x10036240`, `Weapon_RocketLauncher @ 0x100363D0`, `Blaster_Fire @ 0x10036400`, `Weapon_Blaster_Fire @ 0x10036560`, `Weapon_Blaster @ 0x100365B0`, `Weapon_HyperBlaster_Fire @ 0x100365E0`, `Weapon_HyperBlaster @ 0x10036790`, `Machinegun_Fire @ 0x100367C0`, `Weapon_Machinegun @ 0x10036AC0`, `Chaingun_Fire @ 0x10036AF0`, `Weapon_Chaingun @ 0x10036EB0`, `weapon_shotgun_fire @ 0x10036EE0`, `Weapon_Shotgun @ 0x10037080`, `weapon_supershotgun_fire @ 0x100370B0`, `Weapon_SuperShotgun @ 0x100372A0`, `weapon_railgun_fire @ 0x100372D0`, `Weapon_Railgun @ 0x10037450`, `weapon_bfg_fire @ 0x10037480`, `Weapon_BFG @ 0x10037680`, `Weapon_ProximityMines_Fire @ 0x100376B0`, `Weapon_ProximityMines @ 0x10037790`, `Weapon_Deatomizer_Fire @ 0x10037A10`, `Weapon_Deatomizer @ 0x10037C50`, `Weapon_Plasma_Fire @ 0x10037DE0`, `Weapon_PlasmaPistol_Fire @ 0x10037FA0`, `Weapon_PlasmaPistol @ 0x10038020`, `Weapon_PlasmaRifle_Fire @ 0x10038050`, `Weapon_PlasmaRifle @ 0x100380D0`, `Weapon_DetonationPack_Fire @ 0x10038100`, `Weapon_DetonationPack @ 0x10038270`, `Weapon_RemoteDetonator_Fire @ 0x100382A0`, `Weapon_RemoteDetonator @ 0x100383E0`, `Weapon_DOD_Fire @ 0x10038410`, `Weapon_DOD @ 0x10038490`, `Weapon_Obliterator_Fire @ 0x100384C0`, `Weapon_Obliterator @ 0x100386D0`
- Likely role: retail player-death cleanup, default player loadout initialization, weapon selection and drop gating, the full stock Quake II weapon band through machinegun, chaingun, shotgun, and super shotgun, and the wider retail Oblivion weapon layer through proximity mines, deatomizer, plasma, the detpack or remote-detonator split, DOD, and the retail-only Obliterator path.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now reports all of the addresses above as direct exact-address identities, including the launcher, blaster, hyperblaster, railgun, BFG, plasma, detpack, remote-detonator, and DOD wrappers that were not in the earlier pass.
- `player_die` decompiles with the expected death cleanup, obituary, gib, animation, and `DEAD_DEAD` flow from `src/game/p_client.c`.
- `InitClientPersistant` decompiles with the expected retail default inventory and cap setup: `Plasma Pistol`, `PistolPlasma`, health, max-health, and the Oblivion ammo-cap extensions.
- `ChangeWeapon`, `Use_Weapon`, `Drop_Weapon`, and `Weapon_Generic` match the current `src/game/p_weapon.c` control flow for weapon swaps, ammo-gated selection, drop protection under `DF_WEAPONS_STAY` or the last carried active weapon, and the standard Quake II weapon-state machine. The direct `NoAmmoWeaponChange` decompile is narrower than the older source-side Oblivion fallback chain: it preserves `weapon_plasma_rifle`, otherwise checks only the stock Quake II fallback order before defaulting to `Plasma Pistol`. The direct `Think_Weapon` body likewise only dispatches the active weapon callback; retail plasma regeneration stays in `ClientThink` as a separate `Oblivion_UpdateWeaponRegen` tail call after the attack-triggered thunk check.
- `weapon_grenadelauncher_fire` is now directly recovered at `0x100360B0`, and the prior `0x10036400` label is corrected to `Blaster_Fire`; the corresponding retail wrappers for grenade launcher, rocket launcher, blaster, hyperblaster, railgun, and BFG are now all directly decompiled.
- `Machinegun_Fire`, `Weapon_Machinegun`, `Chaingun_Fire`, `Weapon_Chaingun`, `weapon_shotgun_fire`, `Weapon_Shotgun`, `weapon_supershotgun_fire`, and `Weapon_SuperShotgun` are now directly recovered at their exact retail addresses, closing the remaining stock Quake II firearm band between `Weapon_HyperBlaster` and `weapon_railgun_fire`.
- `Weapon_ProximityMines_Fire` and `Weapon_ProximityMines` are now directly recovered and reconstructed in-source; the retail body uses a grenade-style custom state machine with arm or cook sounds, explicit timed calls into the fire helper, and the non-throwing `ChangeWeapon` timer-cancel path.
- `Weapon_Deatomizer @ 0x10037C50` confirms the retail wrapper, and its callback target `LAB_10037BF0` shows that the current source-level `Weapon_Deatomizer_Fire` body is split in retail between a tiny damage-roll wrapper at `0x10037BF0` and the lower-level fire helper currently named `Weapon_Deatomizer_Fire @ 0x10037A10`.
- `Weapon_Plasma_Fire @ 0x10037DE0` is now directly promoted as the retail shared player-plasma fire helper. `Weapon_PlasmaPistol_Fire` and `Weapon_PlasmaRifle_Fire` both route into it after choosing damage, then handle only gunframe advance and their wrapper-specific fire sounds.
- `Weapon_DetonationPack_Fire` and `Weapon_DetonationPack` expose a retail split between the thrown `Detonation Pack` weapon and the trigger-side `Weapon_RemoteDetonator` path. The current source now reconstructs that split in `src/game/p_weapon.c` and `src/game/g_items.c`, including the frame-`14` handoff into the temporary `Remote Detonator` slot, the retail temp-slot `weapon_remote_detonator` row with `Use_Weapon` / `Weapon_RemoteDetonator` but no pickup, drop, ammo, or `weapmodel` pointer, and the preserved `Detonation Pack` -> `Remote Detonator` `usetoggle` pair in `src/game/g_cmds.c`.
- `Weapon_DOD_Fire` and `Weapon_DOD` now directly anchor the DOD projectile path, and the current source now matches the recovered retail wrapper bands: the callback advances the gunframe, launches the DOD projectile helper from player origin, and decrements `DOD`.
- `Weapon_Obliterator_Fire` and `Weapon_Obliterator` now directly anchor the recovered retail custom weapon after `Weapon_DOD`, and the current source now mirrors that wrapper directly instead of routing the slot through the old `Weapon_LaserCannon` placeholder. The wrapper exposes four fire frames, and the fire callback launches the dedicated projectile helper with laser-style muzzle offsets and a one-cell drain per shot.
- A direct `.data` dump of the retail `gitem_t` table shows the entry at `0x10046EC8` with `classname -> "weapon_hellfury"`, `pickup/use/drop -> Pickup_Weapon / Use_Weapon / Drop_Weapon`, `weaponthink -> 0x100386D0`, `pickup_name -> "HellFury"`, and `ammo -> "Rockets"`, tying the retail `HellFury` item surface directly to the recovered `Weapon_Obliterator` wrapper; the current source now mirrors that alias directly and preserves the retail `16`-rocket pickup grant in `Pickup_Weapon`.
- Suggested rename/type: keep the source-aligned names where direct counterparts exist, keep `Weapon_DetonationPack` / `Weapon_DetonationPack_Fire` as retail-specific behavioral names, keep `Weapon_Obliterator` as the retail-facing name for the recovered custom weapon path, treat `HellFury` as the inventory-facing retail alias to that same wrapper, and retain `MOD_LASERCANNON` only as a compatibility alias to the retail-facing `MOD_OBLITERATOR` constant.
- Related items: `src/game/g_cmds.c`, `src/game/p_client.c`, `src/game/p_weapon.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - the retail deatomizer split between `0x10037BF0` and `0x10037A10` should eventually be reflected cleanly in the reconstruction source, rather than being treated as a one-function match

## Shared Retail Plasma Fire Helper

Identifier: `Weapon_Plasma_Fire @ 0x10037DE0`
- Likely role: the retail shared player-plasma fire helper that consolidates the current source-side `Weapon_PlasmaPistol_Fire` and `Weapon_PlasmaRifle_Fire` logic behind a mode parameter.
- Evidence:
  - The direct body takes the shared zero-vector data slot `data_10061C18 @ 0x10061C18`, adds the retail muzzle offsets `+16` and `+8` before `P_ProjectSource`, and then applies the standard `viewheight - 8` vertical adjustment.
  - The decompiled body projects the muzzle source, applies the same kick and `MZ_BLASTER2` behavior, fires a plasma-bolt path at `2000` speed, calls `PlayerNoise`, and then decrements either `PistolPlasma` by `1` or `Rifle Plasma` by `5` depending on a mode flag.
  - The underlying projectile spawn and impact layer is now directly recovered separately as `fire_plasma_bolt @ 0x1001E640` and `plasma_bolt_touch @ 0x1001E520`, so `Weapon_Plasma_Fire` is confirmed as a higher-level shared fire helper rather than the low-level projectile constructor itself.
  - The directly recovered wrappers `Weapon_PlasmaPistol_Fire @ 0x10037FA0` and `Weapon_PlasmaRifle_Fire @ 0x10038050` both call this helper, then only advance gunframe and play `plasma1/fire.wav` or `plasma2/fire.wav`, which pins the helper boundary cleanly.
- Suggested rename/type: promote this as the stable retail helper name `Weapon_Plasma_Fire`; it is not a one-to-one stock Quake II source function, but it is a directly recovered retail consolidation used by both plasma weapon wrappers.
- Related items: `src/game/p_weapon.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - whether `data_10061C18` should stay documented as a shared zero-vector data slot or receive a narrower semantic alias once more of its non-plasma callsites are mapped

## Plasma Pistol Weapon Surface

Identifier: `Weapon_PlasmaPistol @ 0x10038020`, `Weapon_PlasmaPistol_Fire @ 0x10037FA0`, `Weapon_Plasma_Fire @ 0x10037DE0`, `fire_plasma_bolt @ 0x1001E640`, `plasma_bolt_touch @ 0x1001E520`, and `Oblivion_UpdateWeaponRegen @ 0x10037CD0`
- Likely role: the full retail Plasma Pistol player path, from its public item/ammo identity through wrapper dispatch, shared fire logic, projectile spawn/impact, and passive ammo regeneration.
- Evidence:
  - Retail string decoding now anchors the public item and asset surface directly: `weapon_plasma_pistol`, `Plasma Pistol`, `PistolPlasma`, `models/weapons/v_pistol/tris.md2`, `models/objects/pistolplasma/tris.md2`, `plasma1/fire.wav`, and `plasma1/hit.wav` are all present in `gamex86.dll`.
  - `Weapon_PlasmaPistol_Fire @ 0x10037FA0` decompiles as a thin retail wrapper: it chooses `10` or `15` damage by deathmatch state, calls `Weapon_Plasma_Fire(..., mode 0)`, bumps gunframe, and only then plays `plasma1/fire.wav`.
  - `Weapon_Plasma_Fire @ 0x10037DE0` decompiles as the shared retail player-plasma helper: it uses the shared zero-vector data slot at `0x10061C18`, adds the retail `+16,+8,-8` muzzle bias internally, applies kick, fires `fire_plasma_bolt(..., 2000, 0/1)`, emits `MZ_BLASTER2`, calls `PlayerNoise`, and decrements either `PistolPlasma` by `1` or `Rifle Plasma` by `5`.
  - `fire_plasma_bolt @ 0x1001E640` and `plasma_bolt_touch @ 0x1001E520` decompile as the lower-level shared projectile path, including the pistol-specific model `models/objects/pistolplasma/tris.md2`, the pistol-vs-rifle hit sound split, and the pistol-vs-rifle obituary split.
  - `Oblivion_UpdateWeaponRegen @ 0x10037CD0` checks `client->plasma_pistol_next_regen + 1.0 < level.time`, increments `PistolPlasma` up to `pers.max_pistolplasma`, and then stores the current time back to `client + 0xF2C`.
  - Other already recovered retail callsites reinforce the same surface: `InitClientPersistant` seeds the default `Plasma Pistol` plus `PistolPlasma` loadout, `Pickup_Weapon` keeps the default auto-select path anchored on `Plasma Pistol`, and `NoAmmoWeaponChange` falls back to it.
  - Negative evidence: no standalone retail `fire_plasma_pistol` or `plasma_pistol_touch` label surfaced in the DLL strings or the committed selected-function corpus. The recovered pistol path stays `Weapon_PlasmaPistol_Fire -> Weapon_Plasma_Fire(mode 0) -> fire_plasma_bolt -> plasma_bolt_touch`.
- Suggested rename/type: keep `Weapon_PlasmaPistol`, `Weapon_PlasmaPistol_Fire`, `Weapon_Plasma_Fire`, `fire_plasma_bolt`, and `plasma_bolt_touch` as the stable retail labels; the reconstruction now follows that shared helper path directly.
- Related items: `src/game/g_items.c`, `src/game/g_weapon.c`, `src/game/p_client.c`, `src/game/p_weapon.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - whether the exact retail `gitem_t` entry address for `weapon_plasma_pistol` should be decoded explicitly from the item table, or whether the current string-plus-wrapper evidence is sufficient for reconstruction work

## Plasma Rifle Weapon Surface

Identifier: `Weapon_PlasmaRifle @ 0x100380D0`, `Weapon_PlasmaRifle_Fire @ 0x10038050`, `Weapon_Plasma_Fire @ 0x10037DE0`, `fire_plasma_bolt @ 0x1001E640`, `plasma_bolt_touch @ 0x1001E520`, and `Oblivion_UpdateWeaponRegen @ 0x10037CD0`
- Likely role: the full retail Plasma Rifle player path, from its public item/ammo identity through wrapper dispatch, shared fire logic, projectile spawn/impact, and passive ammo regeneration.
- Evidence:
  - Retail string decoding anchors the public item and asset surface directly: `weapon_plasma_rifle`, `Plasma Rifle`, `Rifle Plasma`, `w_plasma`, `models/weapons/v_plasma/tris.md2`, `models/objects/plasma/tris.md2`, `plasma2/fire.wav`, and `plasma2/hit.wav` are all present in `gamex86.dll`.
  - `Weapon_PlasmaRifle_Fire @ 0x10038050` decompiles as a thin retail wrapper: it chooses `35` or `50` damage by deathmatch state, calls `Weapon_Plasma_Fire(..., mode 1)`, bumps gunframe, and only then plays `plasma2/fire.wav`.
  - `Weapon_PlasmaRifle @ 0x100380D0` decompiles as `Weapon_Generic(ent, 7, 10, 24, 32, ..., Weapon_PlasmaRifle_Fire)`, matching the reconstructed retail wrapper timing now carried in `src/game/p_weapon.c`.
  - `Weapon_Plasma_Fire @ 0x10037DE0` decompiles as the shared retail player-plasma helper: it uses the shared zero-vector data slot at `0x10061C18`, adds the retail `+16,+8,-8` muzzle bias internally, applies kick, fires `fire_plasma_bolt(..., 2000, 0/1)`, emits `MZ_BLASTER2`, calls `PlayerNoise`, and decrements either `PistolPlasma` by `1` or `Rifle Plasma` by `5`.
  - `fire_plasma_bolt @ 0x1001E640` and `plasma_bolt_touch @ 0x1001E520` decompile as the lower-level shared projectile path, including the rifle-specific model `models/objects/plasma/tris.md2`, the rifle hit sound `plasma2/hit.wav`, and the rifle obituary split when the mode flag is set.
  - `Oblivion_UpdateWeaponRegen @ 0x10037CD0` checks `pers.plasma_rifle_regen_divisor`, computes `1.0 / divisor + client->plasma_rifle_next_regen`, increments `Rifle Plasma` up to `pers.max_rifleplasma`, and then stores the current time back to `client + 0xF30`.
- Other already recovered retail callsites reinforce the same surface: `NoAmmoWeaponChange` explicitly avoids switching away when the currently equipped classname is `weapon_plasma_rifle`, while `Pickup_RiflePlasma` and `Oblivion_UpdateWeaponRegen` handle the rifle-side ammo sustain path.
  - Negative evidence: the recovered `G_SetStats @ 0x10032CA0` body runs only the stock powerup timer slot before moving into selected-item, layout, frags, and help-icon stats; no extra retail plasma/DoD timer HUD pass surfaced beyond that stock path.
  - Negative evidence: no standalone retail `fire_plasma_rifle` or `plasma_rifle_touch` label surfaced in the DLL strings or the committed selected-function corpus. The recovered retail path stays `Weapon_PlasmaRifle_Fire -> Weapon_Plasma_Fire(mode 1) -> fire_plasma_bolt -> plasma_bolt_touch`.
- Suggested rename/type: keep `Weapon_PlasmaRifle`, `Weapon_PlasmaRifle_Fire`, `Weapon_Plasma_Fire`, `fire_plasma_bolt`, and `plasma_bolt_touch` as the stable retail labels; the current source now follows the recovered retail shared-helper split, wrapper timing, and item-table surface.
- Related items: `src/game/g_items.c`, `src/game/g_weapon.c`, `src/game/p_hud.c`, `src/game/p_weapon.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - whether the exact retail `gitem_t` entry address for `weapon_plasma_rifle` should be decoded explicitly from the item table, or whether the current string-plus-wrapper evidence is sufficient for reconstruction work

## Actor Path-Idle, Visibility, And Normalize Helpers

Identifier: `visible @ 0x10001560`, `Actor_EngageEnemy @ 0x10001690`, `Actor_FindEnemyTarget @ 0x10001730`, `Actor_IsPlayerFollowTarget @ 0x10001880`, `Actor_FindFollowTarget @ 0x10001910`, and `VectorNormalize @ 0x10038900`
- Likely role: the retail actor path-idle helper cluster plus the stock visibility and vector-normalization support those helpers depend on.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records each address above as an exact-address function renamed into a stable retail helper identity.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `visible` tracing from `self` eye height to `other` eye height and returning success only when the trace fraction reaches `1.0`, matching the stock Quake II `visible` predicate.
  - The same decompilation shows `Actor_EngageEnemy` copying the current enemy into the follow or goal slot, dispatching the stand or run callback based on `AI_STAND_GROUND`, recomputing `ideal_yaw` through `vectoyaw`, and scheduling the randomized attack cooldown on the non-stand-ground path.
  - `Actor_FindEnemyTarget` scans all edicts for the nearest visible hostile monster, clears the retail follow flag, sets `enemy`, updates `ideal_yaw`, and then hands off to `Actor_EngageEnemy`; that matches the current `src/game/g_ai.c` actor-idle enemy-acquisition helper rather than a generic monster support routine.
  - `Actor_IsPlayerFollowTarget` accepts either a direct `player` classname or a bounded `AI_ACTOR_FOLLOW` chain, while `Actor_FindFollowTarget` reuses that predicate when selecting or reusing the nearest visible follow target and choosing walk vs stand by distance.
  - `VectorNormalize` decompiles as the stock in-place sqrt-and-scale helper, and several surrounding callsites still consume its x87 return as a vector length exactly where current source and stock Quake II do.
- Suggested rename/type: keep the actor helper names aligned with the current `src/game/g_ai.c` recovery layer and reuse the stock helper names `visible` and `VectorNormalize` rather than falling back to `FUN_...` identifiers.
- Related items: `src/game/g_ai.c`, `src/game/m_move.c`, `src/game/g_weapon.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
- `HellFury` should now be treated strictly as the retail item-table alias to `Weapon_Obliterator`; the remaining work here is spot validation of already reconstructed side-effects rather than any missing wrapper or command-path mapping.

## misc_actor And target_actor Lifecycle

Identifier: `actor_stand @ 0x1001EEB0`, `actor_walk @ 0x1001EF00`, `actor_run @ 0x1001EF10`, `actor_pain @ 0x1001EF70`, `actorMachineGun @ 0x1001F0F0`, `actor_die @ 0x1001F220`, `actor_fire @ 0x1001F300`, `actor_attack @ 0x1001F340`, `actor_use @ 0x1001F380`, `SP_misc_actor @ 0x1001F460`, `target_actor_touch @ 0x1001F690`, and `SP_target_actor @ 0x1001F930`
- Likely role: the retail `misc_actor` scripted monster lifecycle, from spawn and activation through pain, attack, death, and `target_actor` path control.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records every address above as an exact-address `m_actor.c` identity, either by renaming an existing body or by creating a new standalone function at the local callback address.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `actor_stand`, `actor_walk`, and `actor_run` writing the expected actor `mmove_t` pointers, with `actor_stand` seeding a random startup frame while `level.time < 1.0` and `actor_run` falling back through the same `pain_debounce_time` and `movetarget` gates used by the current `src/game/m_actor.c`.
  - The same selected decompilation shows `actor_pain` enforcing the retail pain debounce, special-casing client attackers into the actor talk or taunt branch with the three recovered retail chat strings, and otherwise selecting one of three pain moves; `actor_die` keeps the matching `meansOfDeath == 0x23` disintegration case, the `health <= -80` gib threshold, and the three normal death moves.
  - `actorMachineGun`, `actor_fire`, and `actor_attack` now decompile as one coherent actor attack chain: the muzzle is built from `monster_flash_offset[MZ2_ACTOR_MACHINEGUN_1]`, the aim path targets a live enemy or corpse midpoint, the machinegun helper is fired with the expected flash index, and the hold-frame state is controlled only by the randomized `pausetime` window.
  - `actor_use` resolves `self->target` through `G_PickTarget`, requires the resolved entity to be `target_actor`, writes `goalentity` and `movetarget`, updates `ideal_yaw`, and dispatches the walk callback; on failure it clears `target`, restores the huge idle pause, and dispatches the stand callback with no retail bad-target diagnostic.
  - `SP_misc_actor` now decompiles as the retail spawn body rather than just a slot alias: it applies the deathmatch free, targetname or `START_ON` fixups, `modelindex` and `modelindex2` defaults, bbox or corpse setup, health or mass initialization, callback-slot writes for `use`, `pain`, `die`, `stand`, `walk`, `run`, and `attack`, then hands off into `walkmonster_start` and optionally self-activates on `START_ON`.
  - `target_actor_touch` and `SP_target_actor` now directly anchor the scripted path-controller side too: the touch body validates `other->movetarget == self`, broadcasts `message` directly to live clients, handles jump launch and attack or `pathtarget` branches, fires `G_UseTargets`, advances to the next actor waypoint, and either restores the idle pause or recomputes yaw, while the spawn body installs that touch callback, trigger bounds, `SVF_NOCLIENT`, and the stock jump defaults via `G_SetMovedir`.
- Suggested rename/type: keep the current `src/game/m_actor.c` names above as the stable retail labels; do not promote `actor_dead` until a second retail signal pins its exact source-level role.
- Related items: `src/game/m_actor.c`, `src/game/g_spawn.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - the standalone retail `actor_dead` cleanup body still is not isolated as a stable exact-address function
  - the current source-side `Actor_UseOblivion` and `Actor_PostLoad` helpers still lack a second retail signal and should remain treated as reconstruction scaffolding for now

## Badass Monster Module (Retail Sentinel Counterpart)

Identifier: `badass_sight @ 0x1001FA00`, `badass_stand @ 0x1001FA50`, `badass_idle @ 0x1001FA70`, `badass_attack @ 0x1001FAA0`, `badass_attack_loop @ 0x1001FB20`, `badass_rocket_right @ 0x1001FBC0`, `badass_rocket_left @ 0x1001FC80`, `badass_gib_explosion @ 0x1001FD40`, `badass_die_gibs @ 0x1001FDE0`, `badass_dead @ 0x10020240`, `badass_die @ 0x100202D0`, `badass_step @ 0x10020300`, `badass_thud @ 0x10020330`, `badass_walk @ 0x10020360`, `badass_run @ 0x10020370`, `badass_pain @ 0x10020380`, and `SP_monster_badass @ 0x10020430`
- Likely role: retail heavy rocket monster module built on the Badass classname and asset set; this is the direct retail counterpart to the current source-side Sentinel concept, not a separate `monster_sentinel` module.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records every address above as a direct exact-address identity in the committed selected corpus, including the created exact-address `badass_attack_loop @ 0x1001FB20`.
  - A direct retail string scan of `C:\q2Clean\oblivion\gamex86.dll` now returns `monster_badass`, `models/monsters/badass/tris.md2`, `tank/tnkpain2.wav`, and `tank/tnkatck4.wav`, while returning no `monster_sentinel` or other `sentinel` token.
- `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `SP_monster_badass` as the true deathmatch-guarded spawn entry at `0x10020430`, loading the Badass model plus all five gib models, preloading the tank sound set, writing the callback table (`pain`, `die`, `stand`, `idle`, `walk`, `run`, `attack`, `melee`, `sight`), seeding the retail move-table roots, handling the dead-corpse spawnflag branch, and finishing through `walkmonster_start`.
  - The same selected decompilation shows the front-end callbacks matching the current [m_badass.c](/E:/Repositories/Oblivion-reverse/src/game/m_badass.c) structure: `badass_sight` swaps from `badass_move_idle_closed` into `badass_move_activate` or falls through to `badass_run`, `badass_stand` and `badass_idle` drive the closed-idle vs stand-vs-deactivate state split, and `badass_attack` installs `badass_move_attack` after the retail distance and random gate.
  - `badass_attack_loop` now decompiles directly as the retail attack endfunc: it keeps the attack move active while `visible(self, enemy)` holds, enemy health stays positive, and the recovered distance or random gate does not eject; otherwise it writes the retail run move root at `0x1004CCC8`.
  - `badass_rocket_right` and `badass_rocket_left` now decompile as separate muzzle helpers using the retail local offsets `{18, 40, 0}` and `{18, -40, 0}` respectively, both aiming at enemy origin plus viewheight and firing the shared Oblivion rocket helper with the Badass damage or speed profile.
  - `badass_step`, `badass_thud`, `badass_walk`, `badass_run`, and `badass_pain` now directly expose the expected support layer: two small sound callbacks plus the walk or run wrappers and the gated pain callback that installs `badass_move_pain` only after the damage and debounce checks pass.
  - The death tail is now directly recovered and differs materially from the current source structure: `badass_die` installs the death move, `badass_dead` performs the corpse bbox or toss setup then arms delayed `badass_gib_explosion`, `badass_gib_explosion` emits the explosion temp entity plus radius damage and then rearms `badass_die_gibs`, and `badass_die_gibs` spawns the five per-limb gibs, emits the paired explosion bursts, and frees the original entity.
  - The recovered currentmove writes and spawn defaults anchor the prebuilt retail move-table set in `.data`: `0x1004C8F0` `badass_move_activate`, `0x1004C9B8` `badass_move_deactivate`, `0x1004C9F8` `badass_move_attack`, `0x1004CAF8` `badass_move_death`, `0x1004CB18` `badass_move_idle_closed`, `0x1004CBA0` `badass_move_pain`, `0x1004CC58` `badass_move_walk`, `0x1004CCC8` `badass_move_run`, and `0x1004CDC8` `badass_move_stand`.
  - Those retail move roots now align one-to-one with the current source frame-array partition in [m_badass.c](/E:/Repositories/Oblivion-reverse/src/game/m_badass.c): idle_closed `0`, activate `0..6`, deactivate `7..21`, attack `22..25`, pain `26..35`, stand `36..55`, walk `56..69`, run `70..77`, and death `78..97`.
  - A direct retail `mmove_t` / `mframe_t` decode now fixes the exact per-move payloads: idle_closed uses direct `ai_stand @ 0x10001220` with `dist = 0` and no think hook; deactivate uses `ai_move` with `dist = 0` across all fifteen frames and returns through `badass_idle`; stand uses direct `ai_stand @ 0x10001220` with `dist = 0` across all twenty frames and no think hook; walk uses `ai_walk` with `dist = 7` on every frame; run uses direct `ai_run @ 0x10002530` with `dist = 14,15,21,24,14,15,21,24`; pain uses `ai_move` with `dist = 8,0,0,0,0,0,-16,-16,-8,0`; attack uses `ai_charge` with `dist = -5,0,-5,0`; death uses `ai_move` with `dist = -8,-8,-8,-7,-4,0,0,0,0,4,2,2,2,2,2,2,0,0,0,0`.
  - The recovered hook map is now direct: `badass_move_walk` carries `62` and `69 -> badass_step`; `badass_move_run` carries `73` and `77 -> badass_step`; `badass_move_attack` carries `22 -> badass_rocket_right` and `24 -> badass_rocket_left` and returns through `badass_attack_loop`; `badass_move_death` carries `78/86/94 -> badass_gib_explosion` plus `82/93/95/97 -> badass_thud` and returns through `badass_dead`.
  - The retail data surface is now directly anchored too: `0x1004CFB0` `models/monsters/badass/tris.md2`, `0x1004CE68` `models/monsters/badass/gib_torso.md2`, `0x1004CE44` `models/monsters/badass/gib_lleg.md2`, `0x1004CE20` `models/monsters/badass/gib_rleg.md2`, `0x1004CDFC` `models/monsters/badass/gib_larm.md2`, and `0x1004CDD8` `models/monsters/badass/gib_rarm.md2`; the in-text xrefs land inside `SP_monster_badass` and `badass_die_gibs`.
- The spawn-side sound map is now split cleanly into consumed slots versus preload-only assets. Direct consumed slots are `DAT_10060FE8 <- tank/tnkpain2.wav`, `_DAT_10060FF8 <- tank/tnkdeth2.wav`, `DAT_10060FF4 <- tank/sight1.wav`, and `_DAT_10060FFC <- tank/step.wav`, which are then consumed by `badass_pain`, `badass_thud`, `badass_sight`, and `badass_step` respectively. `badass_die` itself only installs the retail death move.
  - The wider Tank-derived preload set is also direct from `SP_monster_badass`, but no recovered standalone Badass callback currently consumes those slots in the committed corpus: `_DAT_10060FEC <- tank/tnkidle1.wav`, `_DAT_10060FF0 <- tank/death.wav`, `_DAT_10061004 <- tank/tnkatck4.wav`, `_DAT_10061000 <- tank/tnkatck5.wav`, plus the uncached preloads `tank/tnkatck1.wav`, `tank/tnkatk2a.wav`, `tank/tnkatk2b.wav`, `tank/tnkatk2c.wav`, `tank/tnkatk2d.wav`, `tank/tnkatk2e.wav`, and `tank/tnkatck3.wav`.
  - The broader `decompile_top_functions.c` export sharpens that boundary instead of expanding it: outside `SP_monster_badass`, the only reappearing Badass sound-slot consumers in the committed corpus are `DAT_10060FE8` inside `badass_pain` and `DAT_10060FF4` inside `badass_sight`; the idle and attack-slot globals do not surface as additional top-function consumers.
  - Retail and current source are not identical at the frame-hook layer: the retail `badass_move_idle_closed` and `badass_move_stand` tables do not currently expose the source-side `badass_idle_sound` hooks, and the retail `badass_move_deactivate` endfunc is `badass_idle` rather than the current source's separate `badass_idle_end`.
- `badass_move_activate @ 0x1004C8F0` remains malformed in the retail bytes rather than normalized away: a direct raw retail DLL dump confirms that the move root points to `0x1004C8A8`, where only six contiguous `ai_move` frames with `dist = 0` materialize before the root itself, so the final activation-slot payload overlaps the move header instead of decoding cleanly as a seventh `mframe_t`. Current [m_badass.c](/E:/Repositories/Oblivion-reverse/src/game/m_badass.c) now mirrors that overlapping raw blob explicitly and keeps a separate runtime-safe seven-frame projection for actual `M_MoveFrame` execution.
- Suggested rename/type: keep the stable retail names above aligned with `src/game/m_badass.c`; do not rename this band to `sentinel_*`, because the retail DLL evidence is currently Badass-only.
- Related items: `src/game/m_badass.c`, `src/game/m_sentinel.c`, `src/game/g_spawn.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - whether the malformed `badass_move_activate @ 0x1004C8F0` final slot is a retail packing quirk, a frame-header mismatch, or a still-misidentified array boundary
  - the current source-side [m_sentinel.c](/E:/Repositories/Oblivion-reverse/src/game/m_sentinel.c) remains reconstruction-only and still should not be treated as a direct retail module until a second retail signal appears
- the current [m_badass.c](/E:/Repositories/Oblivion-reverse/src/game/m_badass.c) now matches the delayed retail corpse explosion or gib sequence, no longer carries the older idle or attack sound factoring, and now also mirrors the malformed overlapping activation blob directly; the remaining Badass or Sentinel-side delta is only the unavoidable runtime projection that keeps `M_MoveFrame` from executing overlapped `.data` bytes as code

## Cyborg Monster Module

Identifier: `cyborg_footstep @ 0x100244F0`, `cyborg_sight @ 0x10024570`, `cyborg_search @ 0x100245A0`, `cyborg_stand @ 0x100245D0`, `cyborg_idle @ 0x100245E0`, `cyborg_walk @ 0x10024610`, `cyborg_run @ 0x10024620`, `cyborg_pain @ 0x100246A0`, `cyborg_hit_left @ 0x10024770`, `cyborg_hit_right @ 0x10024800`, `cyborg_hit_alt @ 0x10024890`, `cyborg_touch @ 0x10024920`, `cyborg_attack_start @ 0x10024A30`, `cyborg_attack_end @ 0x10024AD0`, `cyborg_fire_right @ 0x10024B20`, `cyborg_fire_left @ 0x10024BE0`, `cyborg_fire_both @ 0x10024CA0`, `cyborg_attack @ 0x10024E00`, `cyborg_melee @ 0x10024E70`, `cyborg_check_range @ 0x10024F10`, `cyborg_checkattack @ 0x10024FF0`, `cyborg_dead @ 0x10025050`, `cyborg_die @ 0x100250B0`, and `SP_monster_cyborg @ 0x10025200`
- Likely role: retail Cyborg monster module covering sound callbacks, stand or idle or walk or run state selection, airborne backflip handling, dual deatom muzzle helpers, custom ranged-vs-melee gating, damage or death handling, and spawn setup.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records all twenty-five Cyborg addresses above as direct exact-address identities in the committed selected corpus.
  - A direct retail string decode around `0x10051BE0` through `0x10051CF0` now anchors the dedicated Cyborg asset set: `models/monsters/cyborg/tris.md2`, `cyborg/mutatck1.wav`, `cyborg/mutatck2.wav`, `cyborg/mutatck3.wav`, `cyborg/mutdeth1.wav`, `cyborg/mutidle1.wav`, `cyborg/mutpain1.wav`, `cyborg/mutpain2.wav`, `cyborg/mutsght1.wav`, `cyborg/mutsrch1.wav`, `cyborg/step1.wav`, `cyborg/step2.wav`, `cyborg/step3.wav`, and `cyborg/thud1.wav`.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `SP_monster_cyborg` as the true deathmatch-guarded spawn entry at `0x10025200`, preloading that asset set, applying bbox `(-16,-16,-38)` to `(16,16,27)`, health `300`, gib health `-120`, mass `300`, the full callback table, and the final `walkmonster_start` handoff. The wider `(-32,-32,-38)` through `(32,32,-20)` box belongs to the later corpse callback `cyborg_dead`, not the live spawn.
  - The same selected decompilation shows the front-end callbacks matching the current [m_cyborg.c](/E:/Repositories/Oblivion-reverse/src/game/m_cyborg.c) structure: `cyborg_footstep` random-selects one of three step sounds, `cyborg_sight` and `cyborg_search` are tiny voice callbacks, `cyborg_idle` installs the idle move while playing the cached idle sound, and `cyborg_run` matches the current `pain2 -> pain2_end -> move901` tail before falling back to stand vs run.
  - `cyborg_fire_right`, `cyborg_fire_left`, and `cyborg_fire_both` now directly expose the retail deatom muzzle geometry: local offsets `{15, 12, 12}`, `{15, -12, 12}`, and the paired dual-shot path, all projecting through `G_ProjectSource`, aiming at enemy origin plus viewheight, normalizing the aim vector, and calling `monster_fire_deatom`.
  - `cyborg_attack_start`, `cyborg_touch`, and `cyborg_attack_end` now directly recover the airborne backflip chain: the start callback plays the sight sound, raises origin `z`, sets upward velocity, enables the manual-steering flag, clears ground contact, installs `cyborg_touch`, and arms the timeout; `cyborg_touch` applies high-speed collision damage, returns early while the backflip is still airborne and ungrounded, and only clears itself once the landing path resolves; `cyborg_attack_end` waits for landing, then plays the thud sound, resets the timeout, and clears the steering state.
  - `cyborg_hit_left` and `cyborg_hit_right` decompile to duplicated `fire_hit` helpers with the same `mins[0]` aim vector and hit-vs-miss sound branch; direct move-table xrefs place `0x10024770` on the retail melee2 path and `0x10024800` on the retail melee1 path, which is the only stable way to distinguish the two identical bodies.
  - `cyborg_check_range` and `cyborg_checkattack` directly preserve the custom Cyborg attack gate from the current source: enemy liveness, vertical overlap tests, the `100`-unit floor, the `dist > 100` skip-randomizer, and the explicit `AS_MELEE` vs `AS_MISSILE` state writes.
  - `cyborg_die` now directly recovers the normal death entry, including the `meansOfDeath == 0x23` disintegration branch, the organic gib path, the cached death sound, and the inline random death-move selection. The current source-side `cyborg_die_select()` helper is therefore reconstruction-only as a standalone symbol; retail folds that choice into `cyborg_die`.
  - A focused final low-address AI pass now also recovers the exact stand helper split used by the Cyborg and Kigrax frame tables: `FUN_100010b0 @ 0x100010B0` is the compiler-split idle-timer local, `ai_stand_tail @ 0x10001170` is the adjacent no-dist tail, and created `ai_stand @ 0x10001220` is the full retail wrapper with `dist` movement, `AI_GOOD_GUY` dispatch, `AI_TEMP_STAND_GROUND` release, and the normal `FindTarget`/`pausetime` flow.
  - The recovered currentmove writes anchor the prebuilt retail move-table set in `.data`: `0x10051540` `cyborg_move_stand`, `0x10051560` `cyborg_move_idle`, `0x10051648` `cyborg_move_walk`, `0x100516A0` `cyborg_move_run`, `0x100516F8` `cyborg_move_pain1`, `0x10051730` `cyborg_move_pain2`, `0x10051750` `cyborg_move_pain2_end`, `0x100517F0` `cyborg_move_move`, `0x10051860` `cyborg_move_melee1`, `0x100518B8` `cyborg_move_melee2`, `0x10051958` `cyborg_move_attack1`, `0x100519F0` `cyborg_move_attack_backflip`, `0x10051A48` `cyborg_move_attack2`, `0x10051AA0` `cyborg_move_attack3`, `0x10051B20` `cyborg_move_death1`, `0x10051B78` `cyborg_move_death2`, and `0x10051BD0` `cyborg_move_death3`.
  - Those retail move roots now align one-to-one with the current source frame-array partition in [m_cyborg.c](/E:/Repositories/Oblivion-reverse/src/game/m_cyborg.c): stand `125`, idle `125`, walk `0..17`, run `18..23`, attack1 `24..35`, attack_backflip `36..46`, attack2 `47..52`, attack3 `53..58`, melee1 `59..66`, melee2 `67..72`, pain1 `73..78`, pain2 `79..81`, pain2_end `82`, move `93..104`, death1 `105..112`, death2 `113..118`, and death3 `119..124`.
  - A direct retail `mmove_t` / `mframe_t` decode now fixes the exact per-move payloads: stand and idle use direct `ai_stand @ 0x10001220` with `dist = 0`; walk uses `ai_walk` with `dist = 12,2,2,2,5,5,6,8,13,12,2,2,2,5,5,6,8,13`; run uses direct `ai_run @ 0x10002530` with `dist = 6,23,8,6,23,8`; pain1 uses `ai_move` with `dist = -16,-4,0,0,0,0`; pain2 uses `ai_move` with `dist = -11,-8,4`; pain2_end uses `ai_move` with `dist = 0`; the `move901` band uses `ai_move` with `dist = 8,7,3,0,-2,-3,2,5,16,0,0,0`; melee1 uses `ai_charge` with `dist = 8,10,0,0,-5,-5,-5,-5`; melee2 uses `ai_charge` with `dist = 6,6,6,-3,-3,-10`; attack1 uses `ai_charge` with `dist = 4,4,5,7,7,9,4,4,5,7,7,9`; attack_backflip uses `ai_charge` with `dist = 0,-17,-15,-15,-15,-15,-15,-15,0,3,0`; attack2 and attack3 use `ai_charge` with `dist = 0`; death1 uses `ai_move` with `dist = -2,0,-3,0,-1,-2,-3,-2`; death2 uses `ai_move` with `dist = -6,-4,-2,0,0,0`; death3 uses `ai_move` with `dist = 8,4,2,1,0,0`.
  - The recovered hook map is now fully direct: `cyborg_move_run` carries frames `19` and `21 -> cyborg_footstep`; `cyborg_move_attack1` carries `29 -> cyborg_fire_right` and `35 -> cyborg_fire_left`; `cyborg_move_attack_backflip` carries `38 -> cyborg_attack_start`, `43 -> cyborg_attack_end`, and `44 -> cyborg_fire_both`; `cyborg_move_attack2` carries `47 -> cyborg_fire_right`; `cyborg_move_attack3` carries `53 -> cyborg_fire_left`; `cyborg_move_melee1` carries `61 -> cyborg_hit_right` and `63 -> cyborg_hit_alt`; `cyborg_move_melee2` carries `70 -> cyborg_hit_left`; `cyborg_move_idle` returns through `cyborg_stand`; `cyborg_move_pain1`, `cyborg_move_pain2`, `cyborg_move_pain2_end`, and `cyborg_move_move` all return through `cyborg_run`; and all three death moves return through `cyborg_dead`.
  - The retail data surface is now directly anchored too: `0x10051BE0` `models/monsters/cyborg/tris.md2`, `0x10051CF0` `cyborg/mutatck1.wav`, `0x10051CDC` `cyborg/mutatck2.wav`, `0x10051CC8` `cyborg/mutatck3.wav`, `0x10051CB4` `cyborg/mutdeth1.wav`, `0x10051CA0` `cyborg/mutidle1.wav`, `0x10051C8C` `cyborg/mutpain1.wav`, `0x10051C78` `cyborg/mutpain2.wav`, `0x10051C64` `cyborg/mutsght1.wav`, `0x10051C50` `cyborg/mutsrch1.wav`, `0x10051C3C` `cyborg/step1.wav`, `0x10051C28` `cyborg/step2.wav`, `0x10051C14` `cyborg/step3.wav`, and `0x10051C00` `cyborg/thud1.wav`; the in-text xrefs all land inside `SP_monster_cyborg`.
  - The spawn-side sound-slot map is now direct from the retail decompilation: `_DAT_10061120 <- mutatck1`, `_DAT_10061148 <- mutatck2`, `_DAT_10061118 <- mutatck3`, `DAT_10061138 <- mutdeth1`, `DAT_1006111C <- mutidle1`, `DAT_10061140 <- mutpain1`, `DAT_1006113C <- mutpain2`, `DAT_10061124 <- mutsght1`, `DAT_10061144 <- mutsrch1`, `_DAT_10061130 <- step1`, `_DAT_10061134 <- step2`, `_DAT_1006112C <- step3`, and `_DAT_10061128 <- thud1`. Those exact globals are then consumed by `cyborg_footstep`, `cyborg_idle`, `cyborg_search`, `cyborg_sight`, `cyborg_attack_start`, `cyborg_attack_end`, `cyborg_pain`, `cyborg_die`, and the three melee-hit helpers.
- Suggested rename/type: keep the current [m_cyborg.c](/E:/Repositories/Oblivion-reverse/src/game/m_cyborg.c) callback names above as the stable retail labels; keep the standalone `cyborg_die_select()` helper documented as source-side factoring because retail does not isolate it as a separate body.
- Related items: `src/game/m_cyborg.c`, `src/game/g_spawn.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - whether the reconstruction should preserve the retail prebuilt move-table layout more literally instead of keeping the current runtime `mmove_t` construction in [m_cyborg.c](/E:/Repositories/Oblivion-reverse/src/game/m_cyborg.c)
  - whether the current source should eventually collapse `cyborg_die_select()` back into `cyborg_die()` to mirror the recovered retail structure more closely

## Kigrax Monster Module

Identifier: `kigrax_search @ 0x10028DF0`, `kigrax_sight @ 0x10028E60`, `kigrax_stand @ 0x10028E90`, `kigrax_run @ 0x10028EE0`, `kigrax_walk @ 0x10028F20`, `kigrax_fire_plasma @ 0x10028F80`, `kigrax_attack @ 0x10029020`, `kigrax_melee @ 0x10029030`, `kigrax_strike1 @ 0x100290D0`, `kigrax_strike2 @ 0x10029140`, `kigrax_pain @ 0x100291B0`, `kigrax_die @ 0x10029220`, `SP_monster_kigrax @ 0x10029354`, and `kigrax_dead @ 0x1002F030`
- Likely role: retail Kigrax hover-monster module covering spawn setup, idle or walk or run state selection, ranged plasma fire, melee strikes, pain or death handling, and corpse collapse.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records all fourteen Kigrax addresses above as direct exact-address identities in the committed selected corpus.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `SP_monster_kigrax` loading `models/monsters/kigrax/tris.md2`, the mixed hover or Kigrax sound set, bbox `(-20,-20,-32)` to `(20,20,12)`, health `200`, gib health `-100`, mass `150`, viewheight `90`, the Kigrax callback table, the idle sound slot, and the final `flymonster_start` handoff.
  - The same selected decompilation shows `kigrax_run` and `kigrax_walk` retaining the retail debug-print path before move selection, `kigrax_stand` random-gating between stand and scan, and `kigrax_sight` switching directly into the sight move.
  - `kigrax_fire_plasma` decompiles with the retail firing geometry: it projects from the offset vector at `0x1005914C`, aims at enemy origin plus viewheight, calls `fire_plasma_bolt` with damage `10`, speed `1000`, and type `1`, then emits Kigrax muzzleflash byte `1`.
  - `kigrax_melee`, `kigrax_strike1`, and `kigrax_strike2` now directly expose the retail melee path: abort back to run when the enemy is dead or out of `RANGE_MELEE`, then choose between the two strike helpers, which call `fire_hit` with damage `10 + rand()%6` and `20 + rand()%20` respectively, both with kick `100`.
- `kigrax_pain`, `kigrax_die`, and `kigrax_dead` directly match the retail damage lifecycle: a `3.0` second pain debounce, nightmare-skill animation skip, the special `meansOfDeath == 0x23` disintegration branch, normal gib gating at `gib_health`, and the corpse bbox or toss cleanup with `SVF_DEADMONSTER`.
- Direct currentmove writes plus the `.data` decode now anchor the full retail move-root set at exact addresses: `kigrax_move_stand @ 0x10058818`, `kigrax_move_scan @ 0x10058928`, `kigrax_move_walk1 @ 0x10058AE0`, `kigrax_move_walk2 @ 0x10058C08`, `kigrax_move_sight @ 0x10058CE8`, `kigrax_move_run @ 0x10058DC8`, `kigrax_move_pain @ 0x10058E60`, `kigrax_move_death @ 0x10058F58`, `kigrax_move_melee1 @ 0x10059020`, `kigrax_move_melee2 @ 0x100590B8`, and `kigrax_move_attack @ 0x10059140`.
- Those retail move roots now align one-to-one with the current source frame-array partition in `src/game/m_kigrax.c`: stand `0..27`, scan `28..48`, walk1 `61..82`, walk2 `83..104`, sight `105..121`, run `122..138`, pain `139..149`, death `150..168`, melee1 `169..183`, melee2 `184..194`, and attack `195..204`.
- A direct retail `mmove_t` / `mframe_t` decode now fixes the exact per-move payloads: stand and scan use direct `ai_stand @ 0x10001220` with `dist = 0`; walk1 and walk2 use `ai_walk` with `dist = 4`; sight and run use direct `ai_run @ 0x10002530` with `dist = 10` and `15`; pain and death use `ai_move` with `dist = 0`; melee1 and melee2 use `ai_charge` with `dist = 1`; attack uses `ai_charge` with `dist = 0`.
- The recovered hook map is now fully direct: `kigrax_move_attack` carries frame `198 -> kigrax_fire_plasma` and returns through `kigrax_run`; `kigrax_move_melee1` carries frames `176` and `180 -> kigrax_strike1` and loops through `kigrax_melee`; `kigrax_move_melee2` carries frame `188 -> kigrax_strike2` and also loops through `kigrax_melee`; `kigrax_move_pain` returns through `kigrax_run`; `kigrax_move_death` carries the direct frame `163 -> kigrax_dead` hook and also returns through `kigrax_dead`.
- The recovered Kigrax asset/sound surface is now direct as well: `kigrax_fire_plasma` consumes the offset vector at `0x10059150` (`{16, 0, -16}`), `kigrax_run` and `kigrax_walk` consume the retail debug strings at `0x1005915C` (`"running...\n"`) and `0x10059168` (`"walking...\n"`), and `SP_monster_kigrax` loads `models/monsters/kigrax/tris.md2` at `0x1005919C`, sets `self->s.sound` from `kigrax/hovidle1.wav` at `0x10059174`, and also preloads `kigrax/hovatck1.wav` at `0x10059188`.
- The sound-slot map is now explicit: `DAT_10061268 <- hover/hovpain1.wav`, `DAT_10061274 <- hover/hovdeth1.wav`, `DAT_1006126C <- hover/hovsght1.wav`, `DAT_10061264 <- hover/hovsrch1.wav`, `DAT_10061260 <- hover/hovsrch2.wav`, `_DAT_10061270 <- chick/chkatck3.wav`, and the idle loop comes from the `self->s.sound` assignment rather than a private Kigrax callback.
- No further standalone Kigrax function is visible in the current raw Ghidra function list. The nearest unlabeled body, `FUN_100294E0`, is not part of the Kigrax module: it performs a `findradius`/`visible` target scan and later routes into unrelated move roots at `0x100595F8` / `0x100596F0`.
- Retail string anchors at `0x1005919C` (`models/monsters/kigrax/tris.md2`) plus the nearby Kigrax sound VAs confirm that this is a dedicated Kigrax module rather than just a stock hover alias.
- Suggested rename/type: keep the current `src/game/m_kigrax.c` function names above as the stable retail labels; keep the direct `kigrax_move_*` / `kigrax_frames_*` tables as the source-level reconstruction of the recovered retail move roots, and do not reintroduce runtime builders because the retail spawn body wires prebuilt `.data` move tables directly.
- Related items: `src/game/m_kigrax.c`, `src/game/g_spawn.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
- `hover/hovdeth1.wav` and the preloaded `kigrax/hovatck1.wav` still are not referenced by any recovered standalone Kigrax callback, so they may either be truly unused preloads or be consumed by a still-undumped frame-table callback

## Soldier Monster Module And Deatomiser Variant

Identifier: `soldier_stand @ 0x1002C2D0`, `soldier_walk @ 0x1002C360`, `soldier_run @ 0x1002C3B0`, `soldier_pain @ 0x1002C400`, `soldier_fire @ 0x1002C560`, `soldier_attack6_refire @ 0x1002CAF0`, `soldier_fire4 @ 0x1002CB20`, `soldier_fire8 @ 0x1002CB30`, `soldier_attack @ 0x1002CB80`, `soldier_sight @ 0x1002CBE0`, `soldier_dodge @ 0x1002CC90`, `soldier_die @ 0x1002CD90`, `SP_monster_soldier_x @ 0x1002CEF0`, `SP_monster_soldier_light @ 0x1002D170`, `SP_monster_soldier @ 0x1002D200`, `SP_monster_soldier_ss @ 0x1002D280`, `SP_monster_soldier_deatom @ 0x1002D300`, `monster_fire_deatom @ 0x10011AF0`, `deatom_touch @ 0x1001DF80`, `deatom_think @ 0x1001E070`, and `fire_deatom @ 0x1001E240`
- Likely role: the retail soldier monster module, including the shared light/regular/SS/deatom skin family and the monster-side deatom bolt chain used by the Deatomiser Soldier and other deatom-firing monsters.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records all twenty-one addresses above as direct exact-address identities in the committed selected corpus.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `SP_monster_soldier_x` loading `models/monsters/soldier/tris.md2`, the base soldier sound set, bbox `(-16,-16,-24)` to `(16,16,32)`, mass `100`, the corpse-spawnflag branch, the full callback table, and the final `walkmonster_start` handoff.
  - The same selected decompilation shows `soldier_stand`, `soldier_walk`, `soldier_run`, `soldier_pain`, `soldier_attack`, `soldier_sight`, `soldier_dodge`, and `soldier_die` matching the current `src/game/m_soldier.c` roles rather than a generic stock infantry alias, including the run-start gating, skin-driven pain sound selection, higher-skill sight-to-run-and-shoot branch, and the `meansOfDeath == 0x23` disintegration path.
  - `soldier_fire` now decompiles as the exact shared firing helper: low skins route into the blaster helper, mid skins route into the shotgun helper, the SS-like skin band uses the machinegun-style hold-frame loop, and the Deatomiser branch is only reached when `s.skinnum >= 6`, where it calls `monster_fire_deatom(self, start, aim, 50, 600)`.
  - `soldier_attack6_refire`, `soldier_fire4`, and `soldier_fire8` are also now direct bodies instead of inferred locals, which anchors both the stationary heavy-fire callback and the running-shoot callback in the retail soldier move-table band.
  - The recovered spawn wrappers show the retail sibling layout clearly: `SP_monster_soldier_light` uses skin band `0` with `20 / -30`, `SP_monster_soldier` ORs the skin bits to `2` with `30 / -30`, `SP_monster_soldier_ss` ORs the skin bits to `4` with `40 / -30`, and `SP_monster_soldier_deatom` ORs the skin bits to `6` while keeping the same `40 / -30` durability.
  - `SP_monster_soldier_deatom` differs materially from the current source in [m_soldier.c](/E:/Repositories/Oblivion-reverse/src/game/m_soldier.c): the retail body does not set `count = 1`, does not force `monsterinfo.run(self)`, and does not preload `deatom/dfire.wav`, `deatom/dfly.wav`, or `deatom/dimpact.wav` there; it only reloads the SS pain/death/attack sound set and depends on the `soldier_fire` skin-band split to reach the deatom projectile path later.
  - `monster_fire_deatom` is now directly recovered as a thin retail wrapper that only forwards into `fire_deatom`, so the current source-level muzzleflash tail in `monster_fire_deatom()` is not present at that wrapper address in retail.
  - `fire_deatom`, `deatom_touch`, and `deatom_think` now directly expose the retail homing bolt chain from [g_monster.c](/E:/Repositories/Oblivion-reverse/src/game/g_monster.c): spawn the `deatom_bolt` model with `deatom/dfly.wav`, acquire a best client target through `findradius` plus `visible`, steer through the dot-gated homing think, play `deatom/dimpact.wav` on impact, apply `MOD_DEATOMIZER` damage, emit the blue hyperblaster temp entity on world hits, and free the projectile.
- Suggested rename/type: keep the current `src/game/m_soldier.c` callback names and `src/game/g_monster.c` deatom projectile names above as the stable retail labels, but treat the current `SP_monster_soldier_deatom()` body as reconstruction-divergent until it matches the retail skin-`6`, `40 / -30`, no-`count`, no-forced-run spawn.
- Related items: `src/game/m_soldier.c`, `src/game/g_monster.c`, `src/game/g_spawn.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - a clean standalone retail `soldier_dead` corpse helper still is not isolated as a separate selected function
  - the current source still needs a reconstruction decision on whether to mirror the retail no-muzzleflash `monster_fire_deatom` split literally or fold that behavior elsewhere

## Spider Monster Module

Identifier: `spider_idle @ 0x1002D380`, `spider_sight @ 0x1002D3B0`, `spider_search @ 0x1002D3E0`, `spider_melee_swing @ 0x1002D410`, `spider_stand @ 0x1002D440`, `spider_walk @ 0x1002D450`, `spider_charge_think @ 0x1002D460`, `spider_charge_start @ 0x1002D570`, `spider_charge_end @ 0x1002D610`, `spider_run @ 0x1002D660`, `spider_melee_hit @ 0x1002D6C0`, `spider_melee @ 0x1002D750`, `spider_rocket_left @ 0x1002D7B0`, `spider_rocket_right @ 0x1002D850`, `spider_attack @ 0x1002D8F0`, `spider_pain @ 0x1002D9E0`, `spider_dead @ 0x1002DB70`, `spider_die @ 0x1002DBD0`, and `SP_monster_spider @ 0x1002DCF0`
- Likely role: retail Spider monster module covering spawn setup, idle or search or sight callbacks, charge-start or charge-think or landing logic, melee and rocket attack selection, pain or death handling, and corpse collapse.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records all nineteen Spider addresses above as direct exact-address identities in the committed selected corpus.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `SP_monster_spider` loading `models/monsters/spider/tris.md2`, the Spider sound set, bbox `(-32,-32,-35)` to `(32,32,32)`, health `400`, gib health `-175`, mass `300`, the full Spider callback table, the corpse-spawnflag branch, and the final `walkmonster_start` handoff.
  - The same selected decompilation shows `spider_idle`, `spider_sight`, `spider_search`, and `spider_melee_swing` as the exact retail sound callbacks: idle and search use the Gladiator-derived sound slots loaded by spawn, while sight uses the dedicated `spider/sight.wav` slot.
- `spider_charge_think`, `spider_charge_start`, and `spider_charge_end` now directly expose the retail charge chain: `spider_charge_start` nudges origin `z`, launches forward with the retail vertical boost, sets `AI_DUCKED` (`0x800` in the recovered `aiflags`), clears ground contact, and installs `spider_charge_think` through the `touch` slot; `spider_charge_think` applies close charge damage while velocity stays high, redirects to `SPIDER_FRAME_RUN1_START + 3` once ground contact returns, and clears the touch callback when the charge resolves; `spider_charge_end` plays the thud or step sound only after the monster regains ground contact, then clears `AI_DUCKED` and the charge timer.
- `selected_functions_summary.csv` now also records `spider_checkattack @ 0x10021460` directly, and `decompile_selected_functions.c` shows `SP_monster_spider @ 0x1002DCF0` writing that exact body into `monsterinfo.checkattack` before the final `walkmonster_start` handoff instead of leaving the slot null for stock `monster_start` to fill with `M_CheckAttack`.
- The recovered `spider_checkattack` body is not a thin alias to stock `M_CheckAttack`: it performs a live-enemy top-of-bbox clear-shot trace, recomputes `ideal_yaw`, uses the real Spider melee callback presence to pick `AS_MELEE` vs `AS_MISSILE` at melee range, and otherwise applies its own near/mid ranged chance plus cooldown gate before optionally falling through the stock-style sliding-state branch. Current [m_spider.c](/E:/Repositories/Oblivion-reverse/src/game/m_spider.c) now reconstructs and installs this custom override directly.
- `spider_melee_hit`, `spider_melee`, `spider_rocket_left`, `spider_rocket_right`, and `spider_attack` now directly expose the retail attack layer: melee uses the stock `fire_hit` path plus hit-vs-miss sounds, while the rocket attack path snapshots enemy origin plus viewheight into `pos1`, then fires separate left and right muzzle helpers rather than a shared standalone retail `spider_rocket` function.
- `spider_pain`, `spider_die`, and `spider_dead` directly match the retail damage lifecycle: half-health skin swap, a `3.0` second pain debounce, the `meansOfDeath == 0x23` disintegration case, the Spider gib path, the normal death1 vs death2 move selection, and the corpse bbox or toss cleanup with `SVF_DEADMONSTER`.
- Direct currentmove writes in the recovered Spider bodies anchor the prebuilt Spider move tables in `.data`: `0x1005CA00` `spider_move_stand`, `0x1005CA88` `spider_move_walk`, `0x1005CB10` `spider_move_run1`, `0x1005CB68` `spider_move_run2`, `0x1005CBB8` `spider_move_melee_primary`, `0x1005CC20` `spider_move_melee_secondary`, `0x1005CC70` `spider_move_attack_left`, `0x1005CCC0` `spider_move_attack_right`, `0x1005CD30` `spider_move_attack_dual`, `0x1005CD88` `spider_move_pain1`, `0x1005CDF8` `spider_move_pain2`, `0x1005CEF8` `spider_move_death1`, and `0x1005CFF8` `spider_move_death2`.
- Those retail move roots now align one-to-one with the current source frame-array partition in [m_spider.c](/E:/Repositories/Oblivion-reverse/src/game/m_spider.c): stand `0..54`, walk `55..64`, run1 `65..74`, run2 `75..80`, attack_left `81..85`, attack_right `86..90`, attack_dual `91..98`, melee_primary `99..103`, melee_secondary `104..110`, pain1 `111..116`, pain2 `117..124`, death1 `125..144`, and death2 `145..164`.
- A direct retail `mmove_t` / `mframe_t` decode now fixes the exact per-move payloads: stand uses direct `ai_stand @ 0x10001220` with `dist = 0` on every frame and no hook; walk uses `ai_walk` with `dist = 0,4,6,4,2,0,4,6,4,2`; run1 uses `ai_run` with `dist = 0`; run2 uses `ai_run` with `dist = 16,16,16,16,16,16`; all three rocket-attack tables use `ai_charge` with `dist = 0`; both melee tables use `ai_charge` with `dist = 0`; pain1 uses `ai_move` with `dist = 0,0,0,0,0,0`; pain2 uses `ai_move` with `dist = -16,-32,-8,0,0,0,0,0`; death1 uses `ai_move` with `dist = -8,-4,-2,0,0,-2,-6,-4,0,4,6,4,0,0,0,0,0,0,0,0`; and death2 uses `ai_move` with `dist = -24,-22,-20,-18,-16,-16,-16,-16,-16,-4,-12,-8,0,0,0,0,0,0,0,0`.
- The recovered hook map is now fully direct: `spider_move_run1` carries `67 -> spider_charge_start` and `72 -> spider_charge_end`; `spider_move_attack_left` carries `83 -> spider_rocket_left`; `spider_move_attack_right` carries `88 -> spider_rocket_right`; `spider_move_attack_dual` carries `92 -> spider_rocket_left` and `96 -> spider_rocket_right`; `spider_move_melee_primary` carries `102 -> spider_melee_swing` and `103 -> spider_melee_hit`; `spider_move_melee_secondary` carries `108 -> spider_melee_swing` and `109/110 -> spider_melee_hit`; `spider_move_run1`, all three rocket-attack tables, both melee tables, both pain tables, and both death tables now have direct retail endfuncs through `spider_run` or `spider_dead` exactly where listed in the symbol map.
- The retail Spider data surface is now direct from the selected decompilation and string layer: `SP_monster_spider` loads `models/monsters/spider/tris.md2` at `0x1005D018`, caches `gladiator/melee1.wav`, `gladiator/melee2.wav`, `gladiator/melee3.wav`, `gladiator/pain.wav`, `gladiator/gldpain2.wav`, `gladiator/gldidle1.wav`, `gladiator/gldsrch1.wav`, and `mutant/thud1.wav`, then overwrites the temporary mutant sight preload with the final Spider-specific `spider/sight.wav` at `0x1005D038`.
- The spawn-side sound-slot map is now explicit too: `_DAT_10061328 <- gladiator/melee1.wav`, `_DAT_1006132C <- gladiator/melee2.wav`, `DAT_10061330 <- gladiator/gldidle1.wav`, `_DAT_10061334 <- gladiator/melee3.wav`, `DAT_10061338 <- spider/sight.wav` after first being populated from `mutant/mutsght1.wav`, `_DAT_1006133C <- mutant/thud1.wav`, `DAT_10061340 <- gladiator/gldpain2.wav`, `DAT_10061344 <- gladiator/pain.wav`, and `DAT_10061348 <- gladiator/gldsrch1.wav`. The direct consumers in the committed corpus are `spider_melee_swing`, `spider_melee_hit`, `spider_idle`, `spider_sight`, `spider_charge_start`, `spider_charge_end`, `spider_pain`, and `spider_search`.
- The gib and dismember surface is now anchored too: the Spider gib branch in `spider_die` uses `misc/udeath.wav`, `models/objects/gibs/sm_meat/tris.md2`, `models/objects/gibs/sm_metal/tris.md2`, `models/objects/gibs/chest/tris.md2`, and `models/objects/gibs/head2/tris.md2`.
- The remaining retail/source delta is now representational rather than behavioral: retail Spider still stores its move roots as prebuilt `.data` objects, while current source expresses the same recovered payloads through C `mmove_t` tables.
- The negative-evidence case for `spider_step` is now effectively closed in source: the only direct consumer of the cached step/thud slot `_DAT_1006133C` is `spider_charge_end`, and current `m_spider.c` no longer carries a standalone Spider-local step helper.
- Suggested rename/type: keep `spider_checkattack` and the current `src/game/m_spider.c` callback names above as the stable retail labels; keep the split `spider_rocket_left` / `spider_rocket_right` helpers as the direct retail reconstruction, and do not reintroduce `spider_step` unless a second retail signal isolates it as a standalone body.
- Related items: `src/game/m_spider.c`, `src/game/g_spawn.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - whether current [m_spider.c](/E:/Repositories/Oblivion-reverse/src/game/m_spider.c) should eventually mirror the retail prebuilt `.data` move-root layout more literally instead of keeping equivalent source-side `mmove_t` tables

## Stand-State And Simple Movement Wrappers

Identifier: `ai_move @ 0x10001090`, `FUN_100010b0 @ 0x100010B0`, `ai_stand_tail @ 0x10001170`, `ai_stand @ 0x10001220`, `ai_walk @ 0x10001350`, `ai_charge @ 0x10001430`, and `ai_turn @ 0x100014A0`
- Likely role: the retail low-address `g_ai.c` entry-wrapper band for simple forward movement, standing idle logic, walking goal pursuit, direct charge movement, and turn-in-place behavior, with `ai_stand` split into an idle-helper local plus an adjacent tail body by optimization.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records all seven addresses above, with `FUN_100010b0`, `ai_stand_tail`, and created `ai_stand` committed alongside the earlier `ai_move`, `ai_walk`, `ai_charge`, and `ai_turn` recoveries in the same low-address band as `AI_SetSightClient`, `range`, `visible`, and the actor-idle helpers.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `ai_move` as the exact stock stub `M_walkmove(self, self->s.angles[YAW], dist)` with no extra retail logic.
  - The same selected decompilation now shows `ai_stand @ 0x10001220` as the full retail wrapper: optional `dist` movement, an `AI_GOOD_GUY` fast path into `ai_stand_tail`, the stock `AI_STAND_GROUND` / `AI_TEMP_STAND_GROUND` release path with `run()`, and then the normal `FindTarget`, `pausetime`, and idle-helper flow from current and stock `ai_stand`.
  - The same selected decompilation shows `ai_walk` opening with `M_MoveToGoal(self, dist)`, then following the stock `FindTarget` plus search-idle timer flow; retail adds an early actor-follow-style flag branch, but the body still cleanly matches the current and stock `ai_walk` role.
  - The same selected decompilation shows `ai_charge` computing the enemy delta, routing it through `vectoyaw`, writing `ideal_yaw`, calling `M_ChangeYaw`, and then optionally advancing through `M_walkmove`, which matches stock `ai_charge` exactly.
  - The same selected decompilation shows `ai_turn` optionally taking the tiny `dist` move through `M_walkmove`, then calling `FindTarget` and only falling through to `M_ChangeYaw` when no target is acquired, again matching stock `ai_turn`.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `ai_stand_tail @ 0x10001170` loading `enemy`, computing the origin delta, routing it through `vectoyaw`, writing `ideal_yaw`, calling `M_ChangeYaw`, and then handing off into `ai_checkattack`; when no enemy is present it falls back through `FindTarget`, then checks the `pausetime` field and the `walk` callback exactly where the tail of stock `ai_stand` does.
  - The adjacent `FUN_100010b0 @ 0x100010B0` body checks the idle callback pointer, the idle timer field, and the `spawnflags & 1` gate, then either seeds the first randomized idle delay or calls the idle callback and reschedules it with the same `15 + random() * 15` cadence used by current `src/game/g_ai.c` and stock Quake II `ai_stand`.
  - Direct retail Cyborg and Kigrax `mframe_t` decodes now show `cyborg_move_stand`, `cyborg_move_idle`, `kigrax_move_stand`, and `kigrax_move_scan` all pointing every frame at direct `ai_stand @ 0x10001220` with `dist = 0`, closing the earlier ambiguity around the stand-table `aifunc`.
  - The source-order anchor is also strong: in both current `src/game/g_ai.c` and stock `references/source-code/Quake-2-master/game/g_ai.c`, the simple movement and stand-state wrappers cluster immediately after `AI_SetSightClient` and before `range`, matching the recovered retail address layout.
- Suggested rename/type: promote `ai_move`, `ai_stand`, `ai_walk`, `ai_charge`, and `ai_turn` as stable retail `g_ai.c` identities; keep `FUN_100010b0` and `ai_stand_tail` documented as compiler-split `ai_stand` support bodies rather than forcing extra source-level symbols.
- Related items: `src/game/g_ai.c`, `references/source-code/Quake-2-master/game/g_ai.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - `ai_fly` still is not isolated as a standalone retail body; it may have been compiled away into the recovered `ai_walk` path, as in the current source-level alias

## Monster Target Acquisition And Attack Gate

Identifier: `range @ 0x100014E0`, `infront @ 0x10001600`, `FoundTarget @ 0x10001AC0`, `FindTarget @ 0x10001BC0`, and `ai_checkattack @ 0x100022A0`
- Likely role: the stock Quake II monster acquisition and attack-decision chain, with a retail-specific `FoundTarget` handoff that reuses `Actor_EngageEnemy` where stock source would typically call `HuntTarget`.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records each address above as an exact-address rename into a stable `g_ai.c` helper identity.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `range` computing the delta to `other`, routing it through `VectorLength`, and returning the stock `RANGE_MELEE` / `RANGE_NEAR` / `RANGE_MID` / `RANGE_FAR` ladder from the expected distance thresholds.
  - The same selected decompilation shows `infront` building the forward vector through `AngleVectors`, normalizing the target delta, and returning true only when `DotProduct(vec, forward) > 0.3`, which matches stock Quake II exactly.
  - `FindTarget` contains the stock sight-entity and sound-entity arbitration, `AI_GOOD_GUY` / `AI_COMBAT_POINT` early-outs, actor-idle follow branches, and `range` / `visible` / `infront` gating before it installs `enemy` and hands off into `FoundTarget`.
  - `FoundTarget` updates `level.sight_entity` for client enemies, seeds `show_hostile`, copies `last_sighting`, handles `combattarget` through `G_PickTarget`, and in the no-`combattarget` or target-miss path falls back through `Actor_EngageEnemy`; that is a close retail analogue of the stock `FoundTarget` plus `HuntTarget` chain.
  - `ai_checkattack` handles sound-target timeout cleanup, dead-enemy and `oldenemy` fallback, seeds the global `enemy_vis` / `enemy_infront` / `enemy_range` / `enemy_yaw` state through `visible`, `infront`, `range`, and `vectoyaw`, then dispatches `ai_run_melee`, `ai_run_missile`, or the monster-specific `checkattack` callback exactly where stock Quake II does.
- Suggested rename/type: keep the stock `g_ai.c` names for `range`, `infront`, `FindTarget`, and `ai_checkattack`; keep `FoundTarget` as the stable label for `0x10001AC0`, but document the retail fallback into `Actor_EngageEnemy` instead of forcing an unsupported standalone `HuntTarget` rename.
- Related items: `src/game/g_ai.c`, `references/source-code/Quake-2-master/game/g_ai.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
  - a clean standalone retail `HuntTarget` body is still not isolated; the recovered `FoundTarget` fallback currently reuses `Actor_EngageEnemy`
  - `ai_fly` still needs a second retail signal before it should be promoted in the committed corpus

## Monster Combat And Movement Helpers

Identifier: `ai_run @ 0x10002530`, `FacingIdeal @ 0x10001F00`, `ai_run_melee @ 0x10002190`, `ai_run_missile @ 0x100021D0`, `ai_run_slide @ 0x10002210`, `AttackFinished @ 0x10011C70`, `M_CheckBottom @ 0x1002A0C0`, `SV_movestep @ 0x1002A330`, `M_ChangeYaw @ 0x1002A850`, `SV_StepDirection @ 0x1002A920`, `SV_FixCheckBottom @ 0x1002AA00`, `SV_NewChaseDir @ 0x1002AA20`, `SV_CloseEnough @ 0x1002AD60`, `M_MoveToGoal @ 0x1002ADC0`, and `M_walkmove @ 0x1002AE40`
- Likely role: the stock Quake II monster-facing combat and chase-movement layer that sits directly underneath the actor helper cluster and broader monster AI.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records each address above as an exact-address rename into a stable monster-combat or monster-movement identity.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` now shows `ai_run` taking the stock run-state branches: `AI_COMBAT_POINT` falls straight into `M_MoveToGoal`, the sound-target path measures enemy distance through `VectorLength`, the normal combat path gates through `ai_checkattack`, and the sliding branch routes into `ai_run_slide`. The raw Kigrax sight/run frame tables also call this same helper with `dist = 10` and `15`.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `FacingIdeal` performing the same wrapped-yaw cone check used by stock Quake II, and both `ai_run_melee` and `ai_run_missile` call it immediately after `M_ChangeYaw` before dispatching the monster melee or missile callback and restoring `AS_STRAIGHT`.
  - The same selected decompilation shows `ai_run_slide` copying `enemy_yaw`, calling `M_ChangeYaw`, picking a `+/-90` offset from the `lefty` flag, attempting one `M_walkmove`, then flipping `lefty` and retrying, which matches the stock Quake II strafe-side helper exactly.
  - `AttackFinished` writes `level.time + time` into the attack-cooldown field, and `Actor_EngageEnemy` reaches it at the same randomized first-attack site used by the current `src/game/g_ai.c` actor path.
  - `M_CheckBottom`, `SV_movestep`, `SV_StepDirection`, `SV_FixCheckBottom`, `SV_NewChaseDir`, `SV_CloseEnough`, `M_MoveToGoal`, and `M_walkmove` all decompile with the same step-height constants, ledge checks, relink-plus-trigger touch behavior, octant chase-direction search, close-enough bounds test, and yaw-to-planar-move conversion as the stock `src/game/m_move.c` chain.
  - `M_ChangeYaw` now decompiles as the stock ideal-yaw clamp helper: it reads `ideal_yaw`, wraps current and destination yaw through the same tiny arithmetic helper used by `FacingIdeal` and `SV_NewChaseDir`, then writes back `s.angles[YAW]` after the yaw-speed-limited turn.
- Suggested rename/type: keep the stock `g_ai.c`, `g_monster.c`, and `m_move.c` names above; they now have a stronger evidence chain than the earlier slot-only or caller-only aliases.
- Related items: `src/game/g_ai.c`, `src/game/g_monster.c`, `src/game/m_move.c`, `references/source-code/Quake-2-master/game/g_ai.c`, `references/source-code/Quake-2-master/game/g_monster.c`, `references/source-code/Quake-2-master/game/m_move.c`.
- Confidence: High.
- Open questions:
  - `ai_fly` still is not isolated as a standalone entry wrapper above this movement band

## Monster Utility And Startup Helpers

Identifier: `M_CheckAttack @ 0x10001F40`, `M_FlyCheck @ 0x10011B90`, `M_FliesOn @ 0x10011C00`, `M_FliesOff @ 0x10011C50`, `M_CatagorizePosition @ 0x10011D90`, `M_WorldEffects @ 0x10011E50`, `M_droptofloor @ 0x10012170`, `M_SetEffects @ 0x10012230`, `M_MoveFrame @ 0x100122C0`, `monster_think @ 0x100123C0`, `monster_use @ 0x10012410`, `monster_triggered_spawn @ 0x10012460`, `monster_triggered_spawn_use @ 0x100124F0`, `monster_triggered_start @ 0x10012530`, `monster_death_use @ 0x10012570`, `monster_start @ 0x100125E0`, `monster_start_go @ 0x10012750`, `walkmonster_start_go @ 0x10012A80`, `walkmonster_start @ 0x10012B30`, `flymonster_start_go @ 0x10012B50`, `flymonster_start @ 0x10012C10`, `swimmonster_start_go @ 0x10012C40`, and `swimmonster_start @ 0x10012C90`
- Likely role: the stock Quake II monster utility, environment, triggered-spawn, and startup layer that bridges the recovered AI helpers into the live monster entity lifecycle.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now records each address above as an exact-address `g_monster.c` identity, either by renaming an existing function or by creating a standalone function at the local callback address.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `monster_start` performing the stock monster init flow and installing `M_CheckAttack` into the default `monsterinfo.checkattack` slot when the monster-specific callback is absent.
  - The same selected decompilation shows `M_FlyCheck` random-gating into `M_FliesOn`, while `M_FliesOn` sets `EF_FLIES`, plays `infantry/inflies1.wav`, arms `M_FliesOff` with the stock `60` second delay, and the newly created `M_FliesOff` body clears `s.sound` plus the `EF_FLIES` bit exactly like the stock local helper in `src/game/g_monster.c`.
  - `M_CatagorizePosition`, `M_WorldEffects`, `M_droptofloor`, `M_SetEffects`, and `monster_think` decompile as the stock water-classification, drowning or lava/slime damage, floor-drop, shell/effect refresh, and per-frame monster upkeep chain used by Quake II monsters after spawn.
  - `M_MoveFrame` now decompiles as the stock frame-advance state machine: it reads `monsterinfo.currentmove`, schedules `nextthink = level.time + FRAMETIME`, honors `AI_HOLD_FRAME`, runs `endfunc` when the move wraps, and dispatches the per-frame AI and think callbacks with the expected distance scaling.
  - `monster_use` now decompiles as the stock activator gate: it rejects already-engaged or dead monsters, ignores `FL_NOTARGET`, accepts client or `AI_GOOD_GUY` activators, stores the activator in `enemy`, and then calls `FoundTarget`.
  - `monster_triggered_spawn_use` now stands alone as a direct selected function and matches the current `src/game/g_monster.c` helper: it queues `monster_triggered_spawn` for the next frame, stores a client activator as `enemy`, and swaps in `monster_use` as the persistent use callback.
  - `monster_triggered_start` now decompiles as the stock hidden-triggered-monster stub and installs `monster_triggered_spawn_use` directly rather than leaving that edge as only a `LAB_...` placeholder.
  - `monster_triggered_spawn`, `monster_death_use`, `monster_start`, `monster_start_go`, `walkmonster_start_go`, `walkmonster_start`, `flymonster_start_go`, `flymonster_start`, `swimmonster_start_go`, and `swimmonster_start` all decompile with the expected `target` / `combattarget` resolution, triggered-start handoff, `path_corner` or `target_actor` startup handling, item-drop or `deathtarget` use flow, solid checks, flag setup, and default yaw-speed or viewheight initialization from current `src/game/g_monster.c` and stock `references/source-code/Quake-2-master/game/g_monster.c`.
- Suggested rename/type: keep the stock `g_monster.c` names above; the thin local callback layer is now directly named in the selected corpus rather than left as raw `LAB_...` targets.
- Related items: `src/game/g_monster.c`, `references/source-code/Quake-2-master/game/g_monster.c`, `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions: none on these names; the remaining nearby ambiguity is outside this recovered startup layer.

## Dodge, Orientation, And Shared Vector Helpers

Identifier: `check_dodge @ 0x1001C1C0`, `vectoyaw @ 0x1001B160`, `AngleVectors @ 0x10038700`, `anglemod @ 0x10038850`, `AddPointToBounds @ 0x10038880`, `VectorCompare @ 0x100388C0`, `VectorMA @ 0x10038950`, `DotProduct @ 0x10038990`, `CrossProduct @ 0x100389B0`, `VectorLength @ 0x100389F0`, and `VectorScale @ 0x10038A20`
- Likely role: stock Quake II dodge support plus the shared orientation and vector-math layer reused heavily by the retail weapon, item, AI, and view code; the immediate post-`Weapon_Obliterator` band is helper code, not a direct `HellFury` wrapper cluster.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now reports each address above as an exact-address existing function renamed to the stable retail helper identity.
  - `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c` shows `check_dodge` tracing from the projectile start to `start + 8192 * dir`, checking the hit entity for the monster, health, and dodge-function conditions, and then calling the dodge callback with the expected ETA based on `VectorLength`.
  - The same selected decompilation plus the wider `decompile_top_functions.c` callers show `anglemod` reached directly from `FacingIdeal`, `M_ChangeYaw`, and `SV_NewChaseDir` in exactly the same wrapped-yaw sites used by current `src/game/g_ai.c`, `src/game/m_move.c`, and stock Quake II.
  - The same selected decompilation shows `AngleVectors`, `AddPointToBounds`, `VectorCompare`, `VectorMA`, `DotProduct`, `CrossProduct`, `VectorLength`, and `VectorScale` decompiling cleanly as the stock Quake II math helpers, matching their current uses in `src/common/q_shared.c`, `src/game/g_utils.c`, `src/game/g_weapon.c`, `src/game/g_items.c`, and `src/game/p_weapon.c`.
- Suggested rename/type: keep the stock helper names above and reuse them in future notes instead of falling back to `FUN_...` identifiers.
- Related items: `src/common/q_shared.c`, `src/game/g_utils.c`, `src/game/g_weapon.c`, `src/game/p_weapon.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
- the retail `weapon_hellfury -> Weapon_Obliterator` alias now explains the retained `HellFury` name surface in source; any remaining divergence is limited to verification of exact side-effects such as pickup ammo grants and projectile wobble timing.

## Projectile, Plasma, Mine, And Detpack Helpers

Identifier: `monster_fire_deatom @ 0x10011AF0`, `blaster_touch @ 0x1001BF10`, `fire_blaster @ 0x1001C000`, `Grenade_Explode @ 0x1001C4A0`, `fire_grenade2 @ 0x1001C740`, `rocket_touch @ 0x1001C960`, `fire_rocket @ 0x1001CAD0`, `obliterator_projectile_think @ 0x1001CC30`, `fire_obliterator_projectile @ 0x1001CD20`, `fire_rail @ 0x1001CF50`, `bfg_explode @ 0x1001D120`, `bfg_touch @ 0x1001D2E0`, `bfg_think @ 0x1001D440`, `fire_bfg @ 0x1001D6F0`, `fire_proximity_mine @ 0x1001D870`, `proximity_mine_explode @ 0x1001DB40`, `proximity_mine_think @ 0x1001DC00`, `proximity_mine_laser_start @ 0x1001DC60`, `proximity_mine_laser_think @ 0x1001DD00`, `proximity_mine_touch @ 0x1001DED0`, `proximity_mine_die @ 0x1001DF50`, `deatom_touch @ 0x1001DF80`, `deatom_think @ 0x1001E070`, `fire_deatom @ 0x1001E240`, `plasma_bolt_touch @ 0x1001E520`, `fire_plasma_bolt @ 0x1001E640`, `detpack_detonate @ 0x1001E820`, `fire_detpack @ 0x1001E8F0`, `dod_client_reset @ 0x1001ECA0`, `dod_pulse_think @ 0x1001ECC0`, and `fire_dod @ 0x1001ED70`
- Likely role: the retail projectile-support layer underneath the monster deatom bolt, hand grenades, rocket launcher, the shared rocket-touch path reused by the Obliterator projectile, railgun, the full BFG projectile chain, proximity mines, plasma weapons, detpacks, and the DoD launcher.
- Evidence:
  - `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` now reports each address above as an exact-address existing function renamed to a stable retail identity.
  - `Blaster_Fire @ 0x10036400` now calls `fire_blaster @ 0x1001C000` directly in the selected decompilation, which cleanly separates the wrapper-level muzzle and kick logic from the lower-level laser-bolt constructor.
  - `fire_blaster` decompiles as the stock laser-bolt spawn helper: it normalizes the direction, allocates a projectile, assigns `models/objects/laser/tris.md2`, `misc/lasfly.wav`, `blaster_touch`, `G_FreeEdict`, `bolt`, and the hyper spawnflag, then performs the stock `check_dodge` and immediate trace-on-spawn impact path.
  - `blaster_touch` decompiles as the stock bolt impact callback: it ignores owner hits, frees on sky, emits `PlayerNoise` for client owners, uses `self->count` or the hyper spawnflag to choose between `MOD_BLASTER` and `MOD_HYPERBLASTER`, writes `TE_BLASTER` on non-damage impacts, and frees the projectile.
  - `fire_grenade2` and `Grenade_Explode` decompile as the stock hand-grenade spawn and timed-explosion pair, including grenade spawnflags, armed sound, impact-vs-splash handling, and temp-entity selection.
  - `monster_fire_deatom` is now a direct selected function rather than a call-edge alias; it only forwards into `fire_deatom`, so the current source-level muzzleflash write in `monster_fire_deatom()` is not present at the recovered retail wrapper address.
  - `rocket_touch` now decompiles directly as the stock rocket impact callback: it ignores owner hits and sky surfaces, emits `PlayerNoise`, rewinds the origin for the explosion effect, applies direct-hit damage, throws debris only for non-deathmatch non-coop world impacts, applies splash damage, chooses the water-vs-air rocket explosion temp entity, and frees the projectile.
  - `fire_rocket` is called directly from `Weapon_RocketLauncher_Fire`; it spawns the stock rocket-model projectile, assigns direct `rocket_touch`, uses `G_FreeEdict` for the timeout, stores direct and splash damage, sets `rockfly.wav` and `rocket`, and preserves the stock `check_dodge` warning call.
  - `fire_obliterator_projectile` is called only from `Weapon_Obliterator_Fire`; it spawns the rocket-model retail custom projectile with `rockfly.wav`, the stock `check_dodge` warning call, dedicated direct/splash damage fields, reuses `rocket_touch`, and layers the custom `obliterator_projectile_think` wobble handler on top rather than introducing a separate touch body.
  - `obliterator_projectile_think` is only referenced from `fire_obliterator_projectile`; it stores the current movement vector, injects small random perturbations from the owner's aim basis, rebuilds the projectile velocity from the saved speed, and rearms the short timed callback while the projectile remains airborne.
  - `fire_rail` is called directly from `weapon_railgun_fire`; it performs the stock long trace through water and monster or client penetrations, applies direct damage, emits `TE_RAILTRAIL` once or twice depending on water, and calls `PlayerNoise` at the impact endpos.
  - `weapon_bfg_fire @ 0x10037480` now calls `fire_bfg @ 0x1001D6F0` directly, which cleanly separates the wrapper-level charge, muzzleflash, and ammo logic from the lower-level BFG projectile chain.
  - `fire_bfg` decompiles as the stock BFG spawn helper: it allocates the projectile, assigns `sprites/s_bfg1.sp2`, stores `bfg_touch` and `bfg_think`, seeds the retail BFG sound and `bfg blast` classname, preserves the direct and radius damage fields, and retains the stock `check_dodge` warning call.
  - `bfg_touch` decompiles as the stock BFG impact callback: it ignores owner hits and sky surfaces, emits `PlayerNoise`, applies the direct-hit and splash blast damage, switches the projectile to `sprites/s_bfg3.sp2`, clears touch and velocity, rearms `bfg_explode`, and emits the big BFG explosion temp entity.
  - `bfg_think` decompiles as the stock BFG laser sweep: it chooses deathmatch-vs-singleplayer laser damage, scans a 256-unit radius, filters to monsters, clients, or `misc_explobox`, traces through penetrations, applies the laser-hit damage path, emits `TE_LASER_SPARKS` and `TE_BFG_LASER`, and rearms the short think interval.
  - `bfg_explode` decompiles as the stock terminal BFG effect: on frame 0 it walks `findradius` over `dmg_radius`, gates damage through dual `CanDamage` checks against both the projectile and owner, emits `TE_BFG_EXPLOSION`, applies the falloff effect damage, advances the frame counter, and hands off to `G_FreeEdict` on frame 5.
  - `fire_proximity_mine` now directly wires the richer retail mine callback chain: `proximity_mine_touch @ 0x1001DED0`, `proximity_mine_think @ 0x1001DC00`, `proximity_mine_die @ 0x1001DF50`, and `proximity_mine_explode @ 0x1001DB40`, while also inlining the owner-scoped five-mine cap enforcement loop.
  - `proximity_mine_think` decompiles as the armed watch loop for the retail mine: it scans a `100`-unit radius around the resting mine, rearms itself when idle, and hands off to `proximity_mine_laser_start` once it has found a `DAMAGE_AIM` target.
  - `proximity_mine_laser_start` decompiles as the trigger handoff: it freezes the mine, zeroes its angles for the retail beam basis, caches `weapons/hgrenc1b.wav`, and schedules `proximity_mine_laser_think` instead of exploding immediately.
  - `proximity_mine_laser_think` decompiles as the retail laser phase now reconstructed in the current source: on first entry it makes the mine non-solid, changes the parent spin to `(0,74,0)`, spawns four linked child entities with classname `mine laser` and spawnflags `0x89`, then refreshes their beam basis each tick, advances an internal phase counter, frees the child chain at timeout, and swaps back into `proximity_mine_explode`.
  - `proximity_mine_touch` decompiles as the retail landing/impact callback: it plays `weapons/hgrenb1a.wav`, arms the delayed think timer, and if the touched entity is a `DAMAGE_AIM` actor it freezes the mine and biases directly toward detonation instead of leaving it in the idle watch loop.
  - `proximity_mine_die` decompiles as the retail damage response for the armed mine: when the callback is still in the watch phase it rewires the short-delay think to `proximity_mine_explode` instead of exploding inline.
  - The retail item surface around the mine path still decodes as `ammo_mines`, pickup `Mines`, icon `a_mines`, `models/items/ammo/mines/tris.md2`, and `models/weapons/v_mine/tris.md2`; there is still no separate `weapon_lasermine` string in the DLL, so `Laser Mine` currently reads as behavior driven by the spawned `mine laser` children rather than a distinct gitem classname.
  - `fire_deatom` now decompiles as the monster-side deatom projectile constructor from `src/game/g_monster.c`: it normalizes the aim vector, spawns `deatom_bolt` with `models/objects/deatom/tris.md2` and `deatom/dfly.wav`, installs `deatom_touch`, acquires the best visible client target through `findradius`, and arms `deatom_think` as the homing callback.
  - `deatom_touch` decompiles as the direct deatom impact callback: owner/sky rejection, `PlayerNoise`, `deatom/dimpact.wav`, direct `MOD_DEATOMIZER` damage, the blue hyperblaster temp entity on world hits, and `G_FreeEdict`.
  - `deatom_think` decompiles as the dot-gated homing turn for the monster deatom bolt, including the same deathmatch-vs-singleplayer steering scale and the invalid-target fallback to `G_FreeEdict`.
  - `plasma_bolt_touch` and `fire_plasma_bolt` decompile as the lower-level shared plasma projectile path used by `Weapon_Plasma_Fire @ 0x10037DE0`, including pistol-vs-rifle bolt models, hit sounds, direct energy damage, `TE_PLASMA_EXPLOSION`, and the immediate trace-on-spawn behavior.
- `detpack_detonate` and `fire_detpack` decompile as the retail detpack blast and thrown-charge path. The current source now matches the recovered delayed-detonation gate, owner impact noise, water-vs-ground temp-entity selection, toss constants, fixed roll/spin, `FL_NO_KNOCKBACK`, optional timed self-detonation, and owner-scoped five-charge cap without the stray `EF_GRENADE` or preseeded health fields.
- `fire_dod` decompiles as the retail DoD projectile spawn helper with the expected model, sound, short timed callback, and DoD damage-radius fields.
- The probe-created `dod_pulse_think @ 0x1001ECC0` body is the timed callback installed by `fire_dod`: it advances the DoD model through `s.frame` up to `10`, expands stored damage/radius fields, applies repeated radius damage with the retail donut obituary id, rearms itself on short intervals, then hands off to `G_FreeEdict` and clears the owner-client callback slot.
- The probe-created `dod_client_reset @ 0x1001ECA0` body is the tiny owner-client helper stored by `fire_dod`; it zeroes three short fields in the callback output block and does not match a clean standalone current-source function.
- The adjacent retail death-message block still maps `MOD_DETPACK` at case `0x16` and `MOD_REMOTE_CANNON` at `0x19`; no live `MOD_REMOTE_DETONATOR` obituary case has surfaced, so the current header constant remains documented as scaffolding rather than promoted into a runtime path.
- Suggested rename/type: keep the current source-aligned names above where a direct counterpart exists, keep the behavioral aliases `fire_obliterator_projectile` / `obliterator_projectile_think` and `dod_pulse_think` / `dod_client_reset` for the retail-only custom paths, treat `rocket_touch` as the shared retail impact callback used by both the stock rocket path and the retail Obliterator projectile helper, and keep the monster-side deatom chain split across `monster_fire_deatom` / `fire_deatom` / `deatom_touch` / `deatom_think` instead of collapsing it back into the current source's slightly different wrapper behavior.
- Related items: `src/game/g_monster.c`, `src/game/g_weapon.c`, `src/game/p_weapon.c`, `docs-dev/reverse-engineering-symbol-map.md`.
- Confidence: High.
- Open questions:
- the current source no longer models `HellFury` and the old `Weapon_LaserCannon` / Obliterator slot separately; remaining follow-up in this area is additional retail validation rather than structural cleanup.

## Shared Global Fields

Identifier: `globals.edicts`, `globals.num_edicts`, `globals.max_edicts`
- Likely role: shared engine/game state fields embedded in the returned `game_export_t`.
- Evidence:
  - HLIL declares `edicts` at `0x1006C160`, `edict_size` at `0x1006C164`, `num_edicts` at `0x1006C168`, and `max_edicts` at `0x1006C16C`.
  - Ghidra top-function decompilation repeatedly uses `DAT_1006C2C4` as the live edict-array base and `DAT_1006C168` as the active edict-count bound in iteration loops.
- Suggested rename/type:
  - `0x1006C160` likely backs `globals.edicts`
  - `0x1006C168` is high-confidence `globals.num_edicts`
  - `0x1006C16C` remains high-confidence `globals.max_edicts` by structure position
- Related items: `reference/reverse-engineering/ghidra/gamex86/decompile_top_functions.c`, `references/HLIL/oblivion/gamex86.dll_hlil.txt`.
- Confidence: Medium.
- Open questions:
  - confirm where the exported `edicts` pointer is initialized relative to `DAT_1006C2C4`
  - confirm whether `max_edicts` has a distinct heavily-used alias in the current Ghidra corpus

## Corpus Backed Workflow Rule

Identifier: committed Ghidra export corpus
- Likely role: secondary, high-signal reference layer that complements the existing HLIL dump and supports incremental export/interface mapping.
- Evidence:
  - The corpus stores imports, exports, wide function inventory, and a focused export decompilation in stable text artifacts.
  - This mirrors the successful OpenAlice pattern of committed Ghidra evidence plus a separate live MCP workflow.
- Suggested rename/type: none.
- Related items: `docs-dev/reverse-engineering.md`, `docs-dev/ghidrassist-mcp.md`, `reference/reverse-engineering/corpus-map.md`.
- Confidence: High.
- Open questions:
  - whether future passes should add targeted string/global exports or dedicated per-function notes for recovered export slots
  - whether the `import_count=62` seen in the first Ghidra pass reflects true PE imports or a tool-count mismatch versus earlier HLIL-oriented notes
