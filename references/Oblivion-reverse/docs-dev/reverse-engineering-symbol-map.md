# Oblivion Retail Symbol Map (`gamex86.dll`)

Date: 2026-03-15

## Scope

This note maps currently recovered retail `gamex86.dll` symbols against:

- the committed Ghidra corpus under `reference/reverse-engineering/ghidra/gamex86/`
- the existing Binary Ninja HLIL corpus under `references/HLIL/oblivion/`
- the current reconstruction sources under `src/game/`
- the stock Quake II GPL game sources under `references/source-code/Quake-2-master/game/`

This pass is based on the widened Ghidra export with `decompiled_function_count=620` plus the targeted selected-function pass captured in `reference/reverse-engineering/ghidra/gamex86/selected_functions_summary.csv` and `reference/reverse-engineering/ghidra/gamex86/decompile_selected_functions.c`. The selected-function artifact now renames exact-address existing functions as well as newly created ones, so the committed Ghidra corpus carries stable retail names across the current helper/export surface.

Confidence labels used here:

- High: direct behavioral match from multiple signals.
- Medium: strong source-order or call-site match, but at least one link is still inferred.
- Low: omitted from this map.

## Program Anchors

| Address / item | Likely symbol | Notes | Confidence |
| --- | --- | --- | --- |
| `0x1000D490` | `GetGameAPI` | Only gameplay-facing DLL export. | High |
| `0x1006C120` | `globals` / returned `game_export_t` block | Return value of `GetGameAPI`. | High |
| `0x1006C1C0` | `gi` / copied `game_import_t` block | `GetGameAPI` copies `0xB0` bytes here. | High |
| `0x1006C160` | `globals.edicts` | Shared export field backing the live edict pointer. | Medium |
| `0x1006C164` | `globals.edict_size` | Set to `0x3D0` by `GetGameAPI`. | High |
| `0x1006C168` | `globals.num_edicts` | Iteration bound used throughout gameplay code. | High |
| `0x1006C16C` | `globals.max_edicts` | Export field position matches stock Quake II. | Medium |
| `DAT_1006C2C4` | live `g_edicts` base | Active edict array base used in loops and save/load helpers. | High |
| `0x1006C2E0` | `level` / `level_locals_t` block | `WriteLevelLocals` and `ReadLevelLocals` serialize a `0x130` byte block from this base. | High |
| `DAT_1006CA4C` | `game.maxentities` / `globals.max_edicts` source | Written during `InitGame`. | High |

## Retail `game_locals_t` Help / Mission Surface

Retail `game` globals are serialized as a `0x61C` byte block rooted at `0x1006C440`. Direct retail evidence currently supports the stock help/HUD globals through `autosaved`, but not the current source `mission_state_t` tail.

| Address / offset | Likely member | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x1006C440` / `+0x000` | `game.helpmessage1` | `src/game/g_local.h` | `Use_Target_Help` copies `ent->message` here when spawnflag `1` is set, and `WriteGame` / `ReadGame` serialize from this base. | High |
| `0x1006C640` / `+0x200` | `game.helpmessage2` | `src/game/g_local.h` | `Use_Target_Help` copies `ent->message` here when spawnflag `1` is clear, and the help/HUD layout reads the same buffer later. | High |
| `0x1006C840` / `+0x400` | `game.helpchanged` | `src/game/g_local.h` | `Use_Target_Help` increments this counter, and the client help-icon path compares against it. | High |
| `0x1006C844` / `+0x404` | `game.clients` | `src/game/g_local.h` | `WriteGame` / `ReadGame` follow the `game` block with `WriteClient` / `ReadClient` using this base and a `0xF34` stride. | High |
| `0x1006CA48` / `+0x608` | `game.maxclients` | `src/game/g_local.h` | `InitGame` seeds this latched cvar, and the client save/load loops use it as the iteration bound. | High |
| `0x1006CA4C` / `+0x60C` | `game.maxentities` | `src/game/g_local.h` | `InitGame` seeds the latched entity-count cvar here. | High |
| `0x1006CA50` / `+0x610` | `game.serverflags` | `src/game/g_local.h` | Crosslevel trigger and target logic ORs and tests this dword directly. | High |
| `0x1006CA54` / `+0x614` | `game.num_items` | `src/game/g_local.h` | Retail item init seeds this slot to `0x36`, and item lookup loops use it as the live bound. | High |
| `0x1006CA58` / `+0x618` | `game.autosaved` | `src/game/g_local.h` | `WriteGame` stores `param_2` here before serializing the block, clears it immediately after, and `ClientBegin` checks it during loadgame restore. | High |

## Mission Functionality And Variables

The current source mission subsystem is now best treated as a reconstruction layer built on top of the retail help-message surface, not as a directly recovered retail `game.mission` block.

| Current symbol or variable band | Current source location | Retail status | Notes | Confidence |
| --- | --- | --- | --- | --- |
| `game.mission` / `mission_state_t` / `mission_objective_save_t` | `src/game/g_local.h`, `src/game/g_mission.c` | reconstruction-only | Retail `WriteGame` / `ReadGame` serialize exactly `0x61C` bytes from `0x1006C440` through `game.autosaved @ +0x618`, leaving no room for the current source mission block. | High |
| `Mission_InitGame()` | `src/game/g_save.c`, `src/game/g_mission.c` | reconstruction-only hook | Current source resets the mission log during game init, but the recovered retail `InitGame` / `WriteGame` flow only exposes the stock help/global block. | Medium |
| `Mission_OnGameLoaded()` | `src/game/g_save.c`, `src/game/g_mission.c` | reconstruction-only hook | Current source rebuilds mission state after savegame load, but recovered retail `ReadGame` only restores the `0x61C` `game` block plus clients. | High |
| `Mission_BeginLevel()` | `src/game/g_spawn.c`, `src/game/g_mission.c` | reconstruction-only hook | Current source clears or re-arms objectives at level start, but the recovered retail `SpawnEntities` body does not expose an equivalent call site. | Medium |
| `Mission_FrameUpdate()` | `src/game/g_main.c`, `src/game/g_mission.c` | reconstruction-only hook | Current source runs per-frame objective timer decay and fail-state updates, but the recovered retail `G_RunFrame` body does not expose an equivalent call site. | Medium |
| `Mission_TargetHelpFired()` | `src/game/m_actor.c`, `src/game/g_mission.c` | reconstruction-only bridge onto retail help UI | Current source routes actor-side mission events into the help buffers and unread counters; the only direct retail anchors in that path are `Use_Target_Help`, `game.helpmessage1`, `game.helpmessage2`, and `game.helpchanged`. | Medium |
| `Mission_GetObjectiveCount()`, `Mission_GetObjective()`, `Mission_ClearUnread()`, `Mission_HasUnread()` | `src/game/p_menu.c`, `src/game/p_hud.c`, `src/game/g_mission.c` | reconstruction-only UI layer | Current source menu and HUD code render a mission log and unread state on top of the retail help icon path, but no direct retail objective-list storage has surfaced. | Medium |
| `edict.oblivion.mission_*` | `src/game/g_local.h`, `src/game/g_save.c`, `src/game/g_mission.c` | reconstruction-only variable band | Current save fields serialize `mission_id`, `mission_title`, `mission_text`, `mission_event`, `mission_timer_*`, `mission_origin`, `mission_angles`, `mission_velocity`, `mission_blend`, and `mission_radius`, but the retail `edict_t` map does not yet expose a matching direct offset band. | Medium |
| `edict.oblivion.controller`, `last_controller`, `prev_path`, `path_target`, `script_target`, `path_*`, `custom_name*` | `src/game/g_local.h`, `src/game/g_save.c` | reconstruction-only variable band | Current source models mission/controller/path state through explicit save fields such as `mission_controller`, `mission_path_*`, and `mission_custom_name*`; direct retail offset evidence for that controller band is still missing. | Medium |

Current source mission hook chain:

- `Mission_InitGame()` <- `src/game/g_save.c`
- `Mission_OnGameLoaded()` <- `src/game/g_save.c`
- `Mission_BeginLevel()` <- `src/game/g_spawn.c`
- `Mission_FrameUpdate()` <- `src/game/g_main.c`
- `Mission_TargetHelpFired()` <- `src/game/m_actor.c`
- `Mission_GetObjective*()`, `Mission_ClearUnread()`, `Mission_HasUnread()` <- `src/game/p_menu.c` / `src/game/p_hud.c`

## `level_locals_t` Member Map

Retail `level` state is the `0x130` byte block rooted at `0x1006C2E0`. The current `src/game/g_local.h` `level_locals_t` layout still matches that size exactly, and the retail `WriteLevelLocals` / `ReadLevelLocals` path matches the current `levelfields[]` pointer set (`changemap`, `sight_client`, `sight_entity`, `sound_entity`, `sound2_entity`).

| Address / offset | Likely member | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x1006C2E0` / `+0x000` | `level.framenum` | `src/game/g_local.h` | `G_RunFrame` increments `DAT_1006c2e0` once per frame. | High |
| `0x1006C2E4` / `+0x004` | `level.time` | `src/game/g_local.h` | `G_RunFrame` derives `DAT_1006c2e4 = framenum * FRAMETIME`. | High |
| `0x1006C2E8` / `+0x008` | `level.level_name` | `src/game/g_local.h` | The worldspawn-style level-init path copies either `message` or `mapname` into `DAT_1006c2e8`, and the help or HUD layout later reuses that same string pointer. | High |
| `0x1006C328` / `+0x048` | `level.mapname` | `src/game/g_local.h` | `SpawnEntities` copies the map token into `DAT_1006c328`, and later compares that string during map-flow logic. | High |
| `0x1006C368` / `+0x088` | `level.nextmap` | `src/game/g_local.h` | `CreateTargetChangeLevel` stores `&DAT_1006c368` into the spawned `target_changelevel`, and `EndDMLevel` checks its first byte before forcing intermission. | High |
| `0x1006C3A8` / `+0x0C8` | `level.intermissiontime` | `src/game/g_local.h` | `BeginIntermission` writes `_DAT_1006c3a8 = DAT_1006c2e4`, and `ExitLevel` clears it. | High |
| `0x1006C3AC` / `+0x0CC` | `level.changemap` | `src/game/g_local.h` | `BeginIntermission` stores `*(char **)(param_1 + 0x238)` into `DAT_1006c3ac`, and `ExitLevel` formats `gamemap "%s"` from it before clearing it. | High |
| `0x1006C3B0` / `+0x0D0` | `level.exitintermission` | `src/game/g_local.h` | `BeginIntermission` sets `DAT_1006c3b0` to the immediate-exit flag and `ExitLevel` clears it. | High |
| `0x1006C3B4` / `+0x0D4` | `level.intermission_origin[0]` | `src/game/g_local.h` | `BeginIntermission` copies the chosen intermission entity origin into `DAT_1006c3b4..0x3bc`, and `MoveClientToIntermission` copies those values back into the client edict. | High |
| `0x1006C3B8` / `+0x0D8` | `level.intermission_origin[1]` | `src/game/g_local.h` | Same observed intermission-origin copy chain. | High |
| `0x1006C3BC` / `+0x0DC` | `level.intermission_origin[2]` | `src/game/g_local.h` | Same observed intermission-origin copy chain. | High |
| `0x1006C3C0` / `+0x0E0` | `level.intermission_angle[0]` | `src/game/g_local.h` | `BeginIntermission` copies the chosen intermission angles into `DAT_1006c3c0..0x3c8`, and `MoveClientToIntermission` restores them into playerstate. | High |
| `0x1006C3C4` / `+0x0E4` | `level.intermission_angle[1]` | `src/game/g_local.h` | Same observed intermission-angle copy chain. | High |
| `0x1006C3C8` / `+0x0E8` | `level.intermission_angle[2]` | `src/game/g_local.h` | Same observed intermission-angle copy chain. | High |
| `0x1006C3CC` / `+0x0EC` | `level.sight_client` | `src/game/g_local.h`, `src/game/g_ai.c` | `AI_SetSightClient` rotates `DAT_1006c3cc` across `g_edicts`, stores a candidate client pointer there, and clears it when no valid player is found. | High |
| `0x1006C3D0` / `+0x0F0` | `level.sight_entity` | `src/game/g_local.h`, `src/game/g_ai.c` | The sensory target-selection path stores a heard or seen entity pointer in `DAT_1006c3d0`, matching `level.sight_entity`. | High |
| `0x1006C3D4` / `+0x0F4` | `level.sight_entity_framenum` | `src/game/g_local.h`, `src/game/g_ai.c` | The same path stores the current `DAT_1006c2e0` frame number into `DAT_1006c3d4` and later compares it against `level.framenum - 1`. | High |
| `0x1006C3D8` / `+0x0F8` | `level.sound_entity` | `src/game/g_local.h`, `src/game/g_ai.c` | `PlayerNoise` stores the primary sound emitter pointer in `DAT_1006c3d8`. | High |
| `0x1006C3DC` / `+0x0FC` | `level.sound_entity_framenum` | `src/game/g_local.h`, `src/game/g_ai.c` | `PlayerNoise` stamps the current `DAT_1006c2e0` into `DAT_1006c3dc`. | High |
| `0x1006C3E0` / `+0x100` | `level.sound2_entity` | `src/game/g_local.h`, `src/game/g_ai.c` | `PlayerNoise` stores the secondary sound emitter pointer in `DAT_1006c3e0`. | High |
| `0x1006C3E4` / `+0x104` | `level.sound2_entity_framenum` | `src/game/g_local.h`, `src/game/g_ai.c` | `PlayerNoise` stamps the current `DAT_1006c2e0` into `DAT_1006c3e4`. | High |
| `0x1006C3E8` / `+0x108` | `level.pic_health` | `src/game/g_local.h`, `src/game/p_hud.c` | `G_SetStats` writes `DAT_1006c3e8` into the player HUD stat slot used for the health icon. | High |
| `0x1006C3EC` / `+0x10C` | `level.total_secrets` | `src/game/g_local.h`, `src/game/g_target.c` | Retail `SP_target_secret @ 0x10017BC0` increments `DAT_1006c3ec` directly after wiring `use_target_secret` and the secret sound. | High |
| `0x1006C3F0` / `+0x110` | `level.found_secrets` | `src/game/g_local.h`, `src/game/g_target.c` | Retail `use_target_secret @ 0x10017B70` increments `DAT_1006c3f0` directly before `G_UseTargets` and `G_FreeEdict`. | High |
| `0x1006C3F4` / `+0x114` | `level.total_goals` | `src/game/g_local.h`, `src/game/g_target.c` | Retail `SP_target_goal @ 0x10017CD0` increments `DAT_1006c3f4` directly after wiring `use_target_goal` and the shared secret sound. | High |
| `0x1006C3F8` / `+0x118` | `level.found_goals` | `src/game/g_local.h`, `src/game/g_target.c` | Retail `use_target_goal @ 0x10017C70` increments `DAT_1006c3f8`, then checks it against `DAT_1006c3f4` before clearing the CD track. | High |
| `0x1006C3FC` / `+0x11C` | `level.total_monsters` | `src/game/g_local.h`, `src/game/g_monster.c` | Monster startup increments `DAT_1006c3fc` for counted monsters, and the HUD summary reads it back in the totals band. | High |
| `0x1006C400` / `+0x120` | `level.killed_monsters` | `src/game/g_local.h`, `src/game/g_combat.c` | The monster-death path increments `DAT_1006c400` directly when a non-good-guy monster dies, and the HUD summary reads it back as the first monster counter slot. | High |
| `0x1006C404` / `+0x124` | `level.current_entity` | `src/game/g_local.h`, `src/game/g_main.c` | `G_RunFrame` stores the currently iterated edict pointer into `DAT_1006c404` before running it. | High |
| `0x1006C408` / `+0x128` | `level.body_que` | `src/game/g_local.h`, `src/game/p_client.c` | `CopyToBodyQue` uses `DAT_1006c408` as the rolling corpse index and wraps it with `& 7`. | High |
| `0x1006C40C` / `+0x12C` | `level.power_cubes` | `src/game/g_local.h`, `src/game/g_items.c` | The coop power-cube pickup path sets a bit using `DAT_1006c40c` and then increments it. | High |

## Retail `gclient_t` Member Map

Retail client blocks are serialized as `0xF34` bytes. The direct save/load and client-lifecycle paths anchor `pers` at `+0x0BC`, `resp` at `+0x730`, and `old_pmove` at `+0xDBC`. The middle combat/view band still matches the current reconstruction closely, but the retail tail diverges with RTDU remote-view state and a cached `ps.gunindex`.

| Retail offset | Likely member | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `+0x000` | `ps` | `src/game/g_local.h` | `WriteClient` and `ReadClient` serialize from the client base, and all playerstate updates treat the first `0xBC` bytes as `player_state_t`. | High |
| `+0x0B8` | `ping` | `src/game/g_local.h` | `ClientThink` and scoreboard/HUD flow use the dword immediately after `ps` as the network ping field. | High |
| `+0x0BC` | `pers.userinfo` | `src/game/g_local.h` | `ClientUserinfoChanged` copies `userinfo` directly into `client + 0x0BC` with a `0x1FF` byte clamp. | High |
| `+0x2BC` | `pers.netname` | `src/game/g_local.h` | `ClientUserinfoChanged` copies the parsed player name into `client + 0x2BC` with the stock `15` char clamp. | High |
| `+0x2CC` | `pers.hand` | `src/game/g_local.h` | `ClientUserinfoChanged` writes the parsed `hand` value at `client + 0x2CC`. | High |
| `+0x2D0` | `pers.connected` | `src/game/g_local.h` | `InitClientPersistant` sets the dword at `client + 0x2D0` to `1`. | High |
| `+0x2D4` | `pers.health` | `src/game/g_local.h` | `InitClientPersistant` seeds `100`; `SaveClientData` writes the live edict health back here. | High |
| `+0x2D8` | `pers.max_health` | `src/game/g_local.h` | `InitClientPersistant` seeds `100`; `SaveClientData` copies the live max-health field back here. | High |
| `+0x2DC` | `pers.savedFlags` | `src/game/g_local.h` | `SaveClientData` stores `edict->flags & 0x1030` at this offset. | High |
| `+0x2E0` | `pers.selected_item` | `src/game/g_local.h` | `InitClientPersistant` seeds the selected item here before inventory setup. | High |
| `+0x2E4` | `pers.inventory[0]` | `src/game/g_local.h` | `InitClientPersistant`, `Pickup_Weapon`, and HUD lookup code treat the following block as the inventory array. | High |
| `+0x6E4` | `pers.max_bullets` | `src/game/g_local.h` | `InitClientPersistant` seeds `200` at the start of the retail max-ammo band. | High |
| `+0x6E8` | `pers.max_shells` | `src/game/g_local.h` | `InitClientPersistant` seeds `100` here. | High |
| `+0x6EC` | `pers.max_rockets` | `src/game/g_local.h` | `InitClientPersistant` seeds `50` here. | High |
| `+0x6F0` | `pers.max_grenades` | `src/game/g_local.h` | `InitClientPersistant` seeds `50` here. | High |
| `+0x6F4` | `pers.max_mines` | `src/game/g_local.h` | `InitClientPersistant` seeds `25` here; this is a retail-only ammo-cap ordering clue. | High |
| `+0x6F8` | `pers.max_cells` | `src/game/g_local.h` | `InitClientPersistant` seeds `200` here. | High |
| `+0x6FC` | `pers.max_slugs` | `src/game/g_local.h` | `InitClientPersistant` seeds `50` here. | High |
| `+0x700` | `pers.max_pistolplasma` | `src/game/g_local.h` | `InitClientPersistant` seeds `50` here. | High |
| `+0x704` | `pers.max_rifleplasma` | `src/game/g_local.h` | `InitClientPersistant` seeds `50` here. | High |
| `+0x708` | `pers.max_detpacks` | `src/game/g_local.h` | `InitClientPersistant` seeds `10` here. | High |
| `+0x70C` | `pers.max_dods` | `src/game/g_local.h` | `InitClientPersistant` seeds `2` here. | High |
| `+0x710` | `pers.plasma_rifle_regen_divisor` | `src/game/g_local.h` | `Pickup_RiflePlasma @ 0x10037C80` increments this slot alongside `pers.max_rifleplasma`, and `Oblivion_UpdateWeaponRegen` uses it as the rifle regen divisor in `1.0 / divisor + next_regen`. | High |
| `+0x714` | `pers.weapon` | `src/game/g_local.h` | `InitClientPersistant` and `ChangeWeapon` store the active item pointer here. | High |
| `+0x718` | `pers.lastweapon` | `src/game/g_local.h` | `ChangeWeapon` moves the previous weapon pointer here before swapping. | High |
| `+0x71C` | `pers.power_cubes` | `src/game/g_local.h` | Layout and coop persistence strongly match the retail slot between `lastweapon` and `score`, but this pass did not isolate a direct retail write. | Medium |
| `+0x720` | `pers.score` | `src/game/g_local.h` | `SaveClientData` copies `resp.score` back into this dword in coop. | High |
| `+0x724` | `pers.game_helpchanged` | `src/game/g_local.h` | Layout-backed slot between `score` and `helpchanged`; current help wrapper flow fits but this pass did not isolate a direct write. | Medium |
| `+0x728` | `pers.helpchanged` | `src/game/g_local.h` | Layout-backed slot adjacent to the help-counter band; likely current name but not directly written in the checked decompilation. | Medium |
| `+0x72C` | `pers.spectator` | `src/game/g_local.h` | `ClientUserinfoChanged` and spectator respawn logic write the spectator flag here. | High |
| `+0x730` | `resp.coop_respawn` | `src/game/g_local.h` | `InitClientResp` copies the full persistent block into this offset. | High |
| `+0xDA4` | `resp.enterframe` | `src/game/g_local.h` | `InitClientResp` stores the current frame number here. | High |
| `+0xDA8` | `resp.score` | `src/game/g_local.h` | Client lifecycle and scoreboard paths treat this dword as the live respawn/session score. | High |
| `+0xDAC` | `resp.cmd_angles` | `src/game/g_local.h` | Layout and `PutClientInServer`/`ClientThink` angle handling match the stock command-angle vector here, but this pass did not isolate a direct standalone copy site. | Medium |
| `+0xDB8` | `resp.spectator` | `src/game/g_local.h` | Spectator connect/respawn flow toggles this dword immediately before `old_pmove`. | High |
| `+0xDBC` | `old_pmove` | `src/game/g_local.h` | `ClientThink` copies pmove state into `client + 0xDBC` after the movement call. | High |
| `+0xDD8` | `showscores` | `src/game/g_local.h` | Intermission and HUD/menu flow set the first post-`old_pmove` flag here. | Medium |
| `+0xDDC` | `showinventory` | `src/game/g_local.h` | Adjacent post-`old_pmove` HUD flag in the stock/current ordering. | Medium |
| `+0xDE0` | `showhelp` | `src/game/g_local.h` | Adjacent HUD/help flag; layout-backed this pass. | Medium |
| `+0xDE4` | `showhelpicon` | `src/game/g_local.h` | Adjacent HUD/help icon flag; layout-backed this pass. | Medium |
| `+0xDE8` | `ammo_index` | `src/game/g_local.h` | `G_SetStats` and `ChangeWeapon` read this slot when building ammo HUD state. | High |
| `+0xDEC` | `buttons` | `src/game/g_local.h` | `ClientThink` writes the latest input buttons here. | High |
| `+0xDF0` | `oldbuttons` | `src/game/g_local.h` | `ClientThink` shifts the prior button state here. | High |
| `+0xDF4` | `latched_buttons` | `src/game/g_local.h` | `ClientThink` ORs rising-edge button presses into this slot. | High |
| `+0xDF8` | `weapon_thunk` | `src/game/g_local.h` | `ClientThink` and weapon execution flow use this dword as the pending-weapon-think flag. | High |
| `+0xDFC` | `newweapon` | `src/game/g_local.h` | `ChangeWeapon` clears or consumes the queued item pointer here. | High |
| `+0xE00` | `damage_parmor` | `src/game/g_local.h` | `P_DamageFeedback` reads and clears the first damage accumulator here. | High |
| `+0xE04` | `damage_armor` | `src/game/g_local.h` | `P_DamageFeedback` reads and clears the armor damage accumulator here. | High |
| `+0xE08` | `damage_blood` | `src/game/g_local.h` | `P_DamageFeedback` reads and clears the blood damage accumulator here. | High |
| `+0xE0C` | `damage_knockback` | `src/game/g_local.h` | `P_DamageFeedback` uses this dword in view-kick calculations. | High |
| `+0xE10` | `damage_from` | `src/game/g_local.h` | `P_DamageFeedback` treats this vector as the incoming damage origin. | High |
| `+0xE20` | `weaponstate` | `src/game/g_local.h` | `ChangeWeapon`, `Think_Weapon`, and weapon wrapper code all branch on this slot. | High |
| `+0xE24` | `kick_angles` | `src/game/g_local.h` | The nearby view-kick math matches the stock `kick_angles` vector, but this pass did not isolate a single direct store with symbolic context. | Medium |
| `+0xE30` | `kick_origin` | `src/game/g_local.h` | `SV_CalcViewOffset` treats the next vector band as view-kick origin state. | Medium |
| `+0xE3C` | `v_dmg_roll` | `src/game/g_local.h` | `P_DamageFeedback` writes the first scalar view-damage component here. | Medium |
| `+0xE40` | `v_dmg_pitch` | `src/game/g_local.h` | `P_DamageFeedback` writes the second scalar view-damage component here. | Medium |
| `+0xE44` | `v_dmg_time` | `src/game/g_local.h` | `P_DamageFeedback` writes the view-damage decay timer here. | Medium |
| `+0xE48` | `fall_time` | `src/game/g_local.h` | `P_FallingDamage` / `SV_CalcViewOffset` use this timer slot in the fall-kick path. | Medium |
| `+0xE4C` | `fall_value` | `src/game/g_local.h` | Adjacent fall-kick magnitude slot in the stock/current ordering. | Medium |
| `+0xE50` | `damage_alpha` | `src/game/g_local.h` | `P_DamageFeedback` accumulates the pain-blend alpha here. | High |
| `+0xE54` | `bonus_alpha` | `src/game/g_local.h` | Adjacent alpha term used by the blend pipeline; layout-backed this pass. | Medium |
| `+0xE58` | `damage_blend` | `src/game/g_local.h` | `P_DamageFeedback` and `SV_CalcBlend` treat this vector as the pain-blend color. | High |
| `+0xE64` | `v_angle` | `src/game/g_local.h` | `ClientEndServerFrame` calls `AngleVectors` on `client + 0xE64`. | High |
| `+0xE70` | `bobtime` | `src/game/g_local.h` | The view-bob pipeline uses the scalar immediately after `v_angle` as the bob timer. | Medium |
| `+0xE74` | `oldviewangles` | `src/game/g_local.h` | Adjacent vector slot matches the stock/current old-view-angle band. | Medium |
| `+0xE80` | `oldvelocity` | `src/game/g_local.h` | `trigger_push_touch` and view logic write/read the next vector band as cached old velocity. | Medium |
| `+0xE8C` | `next_drown_time` | `src/game/g_local.h` | `P_WorldEffects` checks and updates this timer directly. | High |
| `+0xE90` | `old_waterlevel` | `src/game/g_local.h` | `P_WorldEffects` uses this dword as the prior waterlevel tracker. | High |
| `+0xE94` | `breather_sound` | `src/game/g_local.h` | `P_WorldEffects` toggles this dword while managing breather/enviro sounds. | High |
| `+0xE98` | `machinegun_shots` | `src/game/g_local.h` | Weapon fire and view-kick logic use this slot as the machinegun shot counter. | High |
| `+0xE9C` | `anim_end` | `src/game/g_local.h` | Client animation code uses this dword as the current end frame. | High |
| `+0xEA0` | `anim_priority` | `src/game/g_local.h` | Client animation code branches on this dword as the priority enum. | High |
| `+0xEA4` | `anim_duck` | `src/game/g_local.h` | Adjacent animation flag in the stock/current ordering. | Medium |
| `+0xEA8` | `anim_run` | `src/game/g_local.h` | Adjacent animation flag in the stock/current ordering. | Medium |
| `+0xEAC` | `quad_framenum` | `src/game/g_local.h` | `G_SetStats` and powerup logic compare this frame deadline directly. | High |
| `+0xEB0` | `invincible_framenum` | `src/game/g_local.h` | `G_SetStats` and protection logic compare this frame deadline directly. | High |
| `+0xEB4` | `breather_framenum` | `src/game/g_local.h` | `G_SetStats` and world-effects logic compare this frame deadline directly. | High |
| `+0xEB8` | `enviro_framenum` | `src/game/g_local.h` | `G_SetStats` and world-effects logic compare this frame deadline directly. | High |
| `+0xEBC` | `grenade_blew_up` | `src/game/g_local.h` | Adjacent grenade-state flag in the stock/current weapon ordering. | Medium |
| `+0xEC0` | `grenade_time` | `src/game/g_local.h` | Weapon grenade logic uses this float timer directly. | High |
| `+0xEC4` | `silencer_shots` | `src/game/g_local.h` | Adjacent silencer shot counter in the stock/current ordering. | Medium |
| `+0xEC8` | `weapon_sound` | `src/game/g_local.h` | Weapon wrapper code and `G_SetClientSound` treat this dword as the looping weapon sound index. | High |
| `+0xECC` | `pickup_msg_time` | `src/game/g_local.h` | HUD pickup message logic uses this float deadline directly. | High |
| `+0xF00` | `respawn_time` | `src/game/g_local.h` | `respawn` and `ClientBeginServerFrame` compare this timer directly. | High |
| `+0xF04` | unresolved tail slot | `src/game/g_local.h` `remote_view_aux_entity` | Adjacent to the respawn and remote-view band; direct selected-function evidence no longer supports the old stock `chase_target` naming here, so the current source now keeps a neutral retail-tail placeholder instead. | Medium |
| `+0xF08` | unresolved tail slot | `src/game/g_local.h` `remote_view_aux_flag` | Same unresolved retail tail support slot as above; the current source no longer carries the stock `update_chase` name on this slot. | Medium |
| `+0xF0C` | retail remote-view active flag | `src/game/g_local.h` `remote_view_active` | `SV_CalcBlend`, `ClientEndServerFrame`, the dummy-body helpers, and RTDU remote-view entry/exit all branch on this flag to bypass normal player-camera updates. | High |
| `+0xF10` | retail remote-view callback/hook | `src/game/g_local.h` `remote_view_cmd_hook` | `RTDU_BeginRemoteView` installs `0x10014750` here for RTDU, the shared attach helper `0x10002EB0` installs the Deatomizer-control callback, and `RTDU_EndRemoteView` plus `0x10002F20` clear the slot. | High |
| `+0xF18` | retail tracked entity / RTDU turret slot | source-side behavioral aliases `rtdu.turret` and `remote_view_entity` | `rtdu_use`, `RTDU_SpawnTurret`, the shared attach/detach helpers `0x10002EB0` / `0x10002F20`, and the Deatomizer control activation path all use this pointer slot as the active tracked entity / owned turret reference. | High |
| `+0xF1C` | retail remote-view state | `src/game/g_local.h` `remote_view_state_1` | `RTDU_BeginRemoteView` and `0x10002EB0` zero this slot as part of remote-view setup; `0x10002E20` later feeds it back into `ps.viewoffset`. | High |
| `+0xF20` | retail remote-view state | `src/game/g_local.h` `remote_view_state_2` | `RTDU_BeginRemoteView` and `0x10002EB0` zero this slot as part of remote-view setup; `0x10002E20` later feeds it back into `ps.viewoffset`. | High |
| `+0xF24` | retail remote-view timer or distance scalar | `src/game/g_local.h` `remote_view_timer` | `RTDU_BeginRemoteView` seeds this float to `15.0`; the shared attach helper `0x10002EB0` clears it for the generic Deatomizer-control path. | High |
| `+0xF28` | retail cached `ps.gunindex` | `src/game/g_local.h` `remote_view_saved_gunindex` | `RTDU_BeginRemoteView` and `0x10002EB0` save `ps.gunindex` here before zeroing the live field; `RTDU_EndRemoteView` and `0x10002F20` restore it. | High |
| `+0xF2C` | `plasma_pistol_next_regen` | `src/game/g_local.h` | `Oblivion_UpdateWeaponRegen` uses this float deadline directly. | High |
| `+0xF30` | `plasma_rifle_next_regen` | `src/game/g_local.h` | `Oblivion_UpdateWeaponRegen` uses this float deadline directly. | High |

## Retail `edict_t` Member Map

Retail entity blocks are serialized as `0x3D0` bytes. The engine-facing prefix through `owner` still matches the stock Quake II server-visible order exactly, but the later gameplay band does not match the current reconstruction layout directly: retail `nextthink` is at `+0x1EC`, `item` is at `+0x2CC`, and the AI root `monsterinfo.currentmove` is at `+0x358`. Current `src/game/g_local.h` `edict_t` is much larger than retail, so only the fixed prefix and the directly evidenced names below should be treated as retail layout anchors.

| Retail offset | Likely member | Current / stock counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `+0x000` | `s` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer`, `target_laser_start`, and all temp-entity or model or skin updates treat the first `0x54` bytes as `entity_state_t`. | High |
| `+0x054` | `client` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer`, `ClientBegin`, and many client checks read `ent + 0x54` as the live client pointer. | High |
| `+0x058` | `inuse` | `src/game/g_local.h`, stock `edict_t` | `G_InitEdict` sets `1`, `G_Spawn` checks it, and `G_FreeEdict` clears it. | High |
| `+0x05C` | `linkcount` | `src/game/g_local.h`, stock `edict_t` | The engine/entity relink checks compare this slot directly in AI and movement paths. | High |
| `+0x060` | `area` | `src/game/g_local.h`, stock `edict_t` | Layout-backed from the stable server prefix and the expected `gi.linkentity` or `gi.unlinkentity` usage. | Medium |
| `+0x068` | `num_clusters` | `src/game/g_local.h`, stock `edict_t` | Stable server prefix field immediately after `area`; used implicitly by engine collision or PVS state. | Medium |
| `+0x06C` | `clusternums[16]` | `src/game/g_local.h`, stock `edict_t` | Stable server prefix array between `num_clusters` and `headnode`. | Medium |
| `+0x0AC` | `headnode` | `src/game/g_local.h`, stock `edict_t` | Stable server prefix field after the cluster array. | Medium |
| `+0x0B0` | `areanum` | `src/game/g_local.h`, stock `edict_t` | Stable server prefix field. | Medium |
| `+0x0B4` | `areanum2` | `src/game/g_local.h`, stock `edict_t` | Stable server prefix field. | Medium |
| `+0x0B8` | `svflags` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer`, `target_laser_on`, `target_laser_off`, and many spawn wrappers set or clear bits here. | High |
| `+0x0BC` | `mins` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer` writes the player bbox mins here and `KillBox` passes this vector to `gi.trace`. | High |
| `+0x0C8` | `maxs` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer` writes the player bbox maxs here and `KillBox` passes this vector to `gi.trace`. | High |
| `+0x0D4` | `absmin` | `src/game/g_local.h`, stock `edict_t` | Stable server prefix vector after `maxs`; layout-backed. | Medium |
| `+0x0E0` | `absmax` | `src/game/g_local.h`, stock `edict_t` | Stable server prefix vector after `absmin`; layout-backed. | Medium |
| `+0x0EC` | `size` | `src/game/g_local.h`, stock `edict_t` | Stable server prefix vector after `absmax`; layout-backed. | Medium |
| `+0x0F8` | `solid` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer`, `SP_turret_breach`, and `SP_turret_base` write this slot directly. | High |
| `+0x0FC` | `clipmask` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer` seeds the player clipmask here. | High |
| `+0x100` | `owner` | `src/game/g_local.h`, stock `edict_t` | Stable server prefix pointer immediately after `clipmask`; preserved by retail save/load field semantics. | Medium |
| `+0x104` | `movetype` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer`, `player_die`, and many mover or turret spawns set this slot directly. | High |
| `+0x108` | `flags` | `src/game/g_local.h`, stock `edict_t` | `player_die`, `SaveClientData`, AI checks, and many target or item helpers use this bitfield directly. | High |
| `+0x10C` | `model` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer` and turret spawns pass this pointer to `gi.setmodel`. | High |
| `+0x110` | `freetime` | `src/game/g_local.h`, stock `edict_t` | `G_Spawn` and `G_FreeEdict` use this float in the free-edict reuse gate. | High |
| `+0x114` | `message` | `src/game/g_local.h`, stock `edict_t` | `Use_Target_Help`, `SP_target_help`, and light-ramp validation fit the stock `message` slot here. | Medium |
| `+0x118` | `classname` | `src/game/g_local.h`, stock `edict_t` | `G_InitEdict` seeds `noclass`, `PutClientInServer` sets `player`, and diagnostics print this pointer throughout spawn or physics code. | High |
| `+0x11C` | `spawnflags` | `src/game/g_local.h`, stock `edict_t` | `target_laser_*`, trigger logic, item respawn checks, and AI state tests all use this dword directly. | High |
| `+0x120` | `timestamp` | `src/game/g_local.h`, stock `edict_t` | `target_earthquake_use`, `target_explosion_use`, and other stock target helpers schedule or compare this timer directly. | High |
| `+0x124` | `angle` | stock `edict_t` | Stock source order and target/movedir setup fit this slot, but this pass did not isolate a direct retail write with symbolic context. | Medium |
| `+0x128` | `target` | stock `edict_t` | Stock source order and target helper lookups fit this slot. | Medium |
| `+0x12C` | `targetname` | `src/game/g_local.h`, stock `edict_t` | Spawn diagnostics and `SP_target_earthquake` untargeted warnings read the pointer at this offset. | High |
| `+0x130` | `killtarget` | stock `edict_t` | Stock source order and save-field semantics fit this slot. | Medium |
| `+0x134` | `team` | stock `edict_t` | Team-chain logic and save-field semantics fit this slot. | Medium |
| `+0x138` | `pathtarget` | stock `edict_t` | Pathing or target helpers fit the stock slot here. | Medium |
| `+0x13C` | `deathtarget` | stock `edict_t` | Stock source order and save-field semantics fit this slot. | Medium |
| `+0x140` | `combattarget` | stock `edict_t` | Stock source order and save-field semantics fit this slot. | Medium |
| `+0x144` | `target_ent` | `src/game/g_local.h`, stock `edict_t` | Turret and target-resolution flow store a resolved entity pointer here. | High |
| `+0x148` | `speed` | `src/game/g_local.h`, stock `edict_t` | `SP_target_blaster`, `SP_target_railgun`, `SP_target_rocket`, `SP_target_earthquake`, and turret code all use this scalar directly. | High |
| `+0x14C` | `accel` | stock `edict_t` | Stock source-order fit for the scalar immediately after `speed`; not directly isolated this pass. | Medium |
| `+0x150` | `decel` | stock `edict_t` | Stock source-order fit for the scalar immediately after `accel`; not directly isolated this pass. | Medium |
| `+0x154` | `movedir` | `src/game/g_local.h`, stock `edict_t` | `G_SetMovedir`, `target_laser_think`, trigger facing checks, and target weapon helpers all use this vector directly. | High |
| `+0x160` | `pos1` | stock `edict_t` | Turret-breach pitch or yaw limit code and other mover-style logic fit the first stock endpoint vector here. | Medium |
| `+0x16C` | `pos2` | stock `edict_t` | Turret-breach limit code fits the second stock endpoint vector here. | Medium |
| `+0x178` | `velocity` | `src/game/g_local.h`, stock `edict_t` | `trigger_push_touch`, projectile or mover logic, and player spawn flow use this vector band directly. | Medium |
| `+0x184` | `avelocity` | stock `edict_t` | `player_die` clears this vector band and mover code fits the stock angular-velocity placement here. | Medium |
| `+0x190` | `mass` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer` seeds `200` here; world and damage logic use it as the entity mass. | High |
| `+0x194` | `air_finished` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer` and `P_WorldEffects` use this float timer directly. | High |
| `+0x198` | `gravity` | `src/game/g_local.h`, stock `edict_t` | `G_InitEdict` seeds `1.0` here. | High |
| `+0x19C` | `goalentity` | stock `edict_t` | Stock source order and AI pathing semantics fit this pointer. | Medium |
| `+0x1A0` | `movetarget` | stock `edict_t` | Stock source order and AI pathing semantics fit this pointer. | Medium |
| `+0x1A4` | `yaw_speed` | stock `edict_t` | Stock source order and mover or AI yaw logic fit this scalar. | Medium |
| `+0x1A8` | `ideal_yaw` | stock `edict_t` | Stock source order and `M_ChangeYaw` logic fit this scalar. | Medium |
| `+0x1AC..+0x1E8` | unresolved retail extension band | no clean current counterpart | Retail `nextthink` begins later than stock at `+0x1EC`, so this band is a real retail insertion or reordering that is not yet fully named. | Medium |
| `+0x1EC` | `nextthink` | `src/game/g_local.h`, stock `edict_t` | `target_laser_think`, `target_laser_off`, `target_earthquake_use`, `multi_trigger`, `SP_turret_breach`, and many other helpers schedule this slot directly. | High |
| `+0x1F0` | `prethink` | stock `edict_t` | This is the stock callback slot immediately before `think`, but this pass did not isolate a direct retail assignment. | Medium |
| `+0x1F4` | `think` | `src/game/g_local.h`, stock `edict_t` | `target_earthquake_use`, `multi_trigger`, `target_laser_*`, turret spawns, and many item/monster helpers install think callbacks here. | High |
| `+0x1F8` | `blocked` | stock `edict_t` | Turret/base setup installs a callback in this slot; stock callback ordering fits `blocked`. | Medium |
| `+0x1FC` | `touch` | `src/game/g_local.h`, stock `edict_t` | `multi_trigger`, item touchability, teleport, and mine/projectile setup clear or install this callback slot directly. | High |
| `+0x200` | `use` | `src/game/g_local.h`, stock `edict_t` | `monster_use`, `use_target_explosion`, `use_target_splash`, target weapon helpers, and many trigger wrappers install this callback slot directly. | High |
| `+0x204` | `pain` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer` installs the player pain callback here. | High |
| `+0x208` | `die` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer`, mine setup, and many monsters install a die callback here. | High |
| `+0x20C` | `touch_debounce_time` | stock `edict_t` | The first post-callback float in the stock layout; not directly isolated here. | Medium |
| `+0x210` | `pain_debounce_time` | stock `edict_t` | Damage/world-effect timing fits this float slot. | Medium |
| `+0x214` | `damage_debounce_time` | stock `edict_t` | Damage/world-effect timing fits this float slot. | Medium |
| `+0x218` | `fly_sound_debounce_time` | stock `edict_t` | The stock fly-sound debounce slot fits this retail position, but this pass did not isolate a direct sound write. | Medium |
| `+0x21C` | `last_move_time` | stock `edict_t` | `target_earthquake_use` clears this slot directly before scheduling the first think. | High |
| `+0x220` | `health` | `src/game/g_local.h`, stock `edict_t` | `P_DamageFeedback`, `Think_Weapon`, player death flow, and item pickup logic use this int directly. | High |
| `+0x224` | `max_health` | `src/game/g_local.h`, stock `edict_t` | Health item logic and spawn setup use this int directly. | High |
| `+0x228` | `gib_health` | stock `edict_t` | Player/monster death handling fits the stock slot here, but this pass did not isolate a named retail write. | Medium |
| `+0x22C` | `deadflag` / retail union slot | `src/game/g_local.h`, stock `edict_t` | Death-state code and the Deatomiser path both use this slot, so retail likely preserves a stock `deadflag` alias with custom reuse on specific entity types. | Medium |
| `+0x230` | `show_hostile` | `src/game/g_local.h`, stock `edict_t` | AI and actor logic use this small hostile-state slot directly. | Medium |
| `+0x234` | `powerarmor_time` | `src/game/g_local.h`, stock `edict_t` | Power-armor or timed-effect logic fits the stock float here. | Medium |
| `+0x238` | `map` / retail union slot | `src/game/g_local.h`, stock `edict_t` | `target_changelevel` and some custom callback reuse fit this stock union slot. | High |
| `+0x23C` | `viewheight` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer` seeds `22`, and monster solid-start diagnostics write alternate values here. | High |
| `+0x240` | `takedamage` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer`, `player_die`, and laser/trigger damage gates use this slot directly. | High |
| `+0x244` | `dmg` | `src/game/g_local.h`, stock `edict_t` | `target_blaster`, `target_railgun`, `target_rocket`, `target_splash`, and turret code all use this slot as the entity damage scalar. | High |
| `+0x248` | `radius_dmg` | `src/game/g_local.h`, stock `edict_t` | Target explosion/rocket-style helpers fit this int slot immediately after `dmg`. | High |
| `+0x24C` | `dmg_radius` | `src/game/g_local.h`, stock `edict_t` | Radius-damage target helpers fit this float slot. | High |
| `+0x250` | `sounds` | `src/game/g_local.h`, stock `edict_t` | `SP_target_splash`, `SP_target_blaster`, `SP_target_railgun`, `SP_target_earthquake`, and item/world helpers use this slot as a sound or effect selector. | High |
| `+0x254` | `count` | `src/game/g_local.h`, stock `edict_t` | `SP_target_splash`, `SP_target_earthquake`, and item pickup/respawn helpers use this int directly. | High |
| `+0x258` | `chain` | `src/game/g_local.h`, stock `edict_t` | Stock source order and save-field semantics fit this pointer; not directly isolated this pass. | Medium |
| `+0x25C` | `enemy` | `src/game/g_local.h`, stock `edict_t` | `target_laser_think`, actor AI, monster targeting, and combat code all use this pointer directly. | High |
| `+0x260` | `oldenemy` | `src/game/g_local.h`, stock `edict_t` | AI fallback code stores and restores this pointer directly. | High |
| `+0x264` | `activator` | `src/game/g_local.h`, stock `edict_t` | `Use_Multi`, `Touch_Multi`, `target_laser_use`, `target_earthquake_use`, and many target helpers store the activator here. | High |
| `+0x268` | `groundentity` | `src/game/g_local.h`, stock `edict_t` | `PutClientInServer`, monster jump, and physics/respawn code use this pointer directly. | High |
| `+0x26C` | `groundentity_linkcount` | `src/game/g_local.h`, stock `edict_t` | Ground-contact update logic fits the stock int here. | Medium |
| `+0x270` | `teamchain` | `src/game/g_local.h`, stock `edict_t` | Stock source order and save-field semantics fit this pointer. | Medium |
| `+0x274` | `teammaster` | `src/game/g_local.h`, stock `edict_t` | Turret-breach code dereferences this pointer directly to reach its paired entity. | High |
| `+0x278` | `mynoise` | `src/game/g_local.h`, stock `edict_t` | Stock source order and save-field semantics fit this pointer. | Medium |
| `+0x27C` | `mynoise2` | `src/game/g_local.h`, stock `edict_t` | Stock source order and save-field semantics fit this pointer. | Medium |
| `+0x280` | `noise_index` | `src/game/g_local.h`, stock `edict_t` | Target weapon and world helpers write the precached sound index here. | High |
| `+0x284` | `noise_index2` | `src/game/g_local.h`, stock `edict_t` | Secondary sound selector immediately after `noise_index`; layout-backed and used by sound-heavy entities. | Medium |
| `+0x288` | `volume` | `src/game/g_local.h`, stock `edict_t` | Sound-emitting helpers fit the stock float slot here. | Medium |
| `+0x28C` | `attenuation` | `src/game/g_local.h`, stock `edict_t` | Sound-emitting helpers fit the stock attenuation float here. | Medium |
| `+0x290` | `wait` | `src/game/g_local.h`, stock `edict_t` | `multi_trigger` uses this float directly for trigger re-arm scheduling. | High |
| `+0x294..+0x2C4` | retail custom mover/timer band | no clean current counterpart | Retail target, turret, RTDU, and custom entity helpers reuse this span heavily, but the exact per-slot names are not yet stable enough to force into the map. | Medium |
| `+0x2C8` | `style` | `src/game/g_local.h`, stock `edict_t` | `SP_light`, `target_laser_*`, and other configstring/light-style helpers use this int directly. | High |
| `+0x2CC` | `item` | `src/game/g_local.h`, stock `edict_t` | Pickup, drop, respawn, and health-item code all dereference this pointer directly. | High |
| `+0x2D0..+0x357` | retail `moveinfo` root and extension band | stock `moveinfo_t` | The retail mover/turret path still roots a compact `moveinfo` block here, but it is larger than stock and not yet fully field-mapped. | Medium |
| `+0x358` | `monsterinfo.currentmove` | `src/game/g_local.h`, stock `monsterinfo_t` | Monster spawn and AI code store `.data` move-table roots here directly. | High |
| `+0x35C` | `monsterinfo.aiflags` | `src/game/g_local.h`, stock `monsterinfo_t` | AI code sets and clears flags in this dword throughout `FoundTarget`, `ai_checkattack`, and monster wrappers. | High |
| `+0x360` | `monsterinfo.nextframe` | `src/game/g_local.h`, stock `monsterinfo_t` | AI and monster wrappers store explicit next-frame overrides here. | High |
| `+0x364` | `monsterinfo.scale` | `src/game/g_local.h`, stock `monsterinfo_t` | Frame or movement scaling logic multiplies by this float directly. | High |
| `+0x368` | `monsterinfo.stand` | `src/game/g_local.h`, stock `monsterinfo_t` | AI code calls the callback in this slot as the stand handler. | High |
| `+0x36C` | `monsterinfo.idle` | `src/game/g_local.h`, stock `monsterinfo_t` | AI idle logic tests and calls this callback slot directly. | High |
| `+0x370` | `monsterinfo.search` | `src/game/g_local.h`, stock `monsterinfo_t` | Search/idle timeout code calls this callback slot directly. | High |
| `+0x374` | `monsterinfo.walk` | `src/game/g_local.h`, stock `monsterinfo_t` | Monster AI dispatch calls this callback slot directly. | High |
| `+0x378` | `monsterinfo.run` | `src/game/g_local.h`, stock `monsterinfo_t` | Monster AI dispatch calls this callback slot directly. | High |
| `+0x37C` | `monsterinfo.dodge` | `src/game/g_local.h`, stock `monsterinfo_t` | Dodge-capable AI uses this callback slot directly. | High |
| `+0x380` | `monsterinfo.attack` | `src/game/g_local.h`, stock `monsterinfo_t` | Attack-gate logic checks and calls this callback slot directly. | High |
| `+0x384` | `monsterinfo.melee` | `src/game/g_local.h`, stock `monsterinfo_t` | Melee AI uses this callback slot directly. | High |
| `+0x388` | `monsterinfo.sight` | `src/game/g_local.h`, stock `monsterinfo_t` | Sight-acquisition logic uses this callback slot directly. | High |
| `+0x38C` | `monsterinfo.checkattack` | `src/game/g_local.h`, stock `monsterinfo_t` | `ai_checkattack` dispatches through this callback slot directly. | High |
| `+0x390` | `monsterinfo.pausetime` | `src/game/g_local.h`, stock `monsterinfo_t` | `ai_stand`, idle, and several monster behaviors compare and update this float timer directly. | High |
| `+0x394` | `monsterinfo.attack_finished` | `src/game/g_local.h`, stock `monsterinfo_t` | Attack gating and cooldown scheduling use this float timer directly. | High |
| `+0x398..+0x3A0` | unresolved compact AI state band | stock `monsterinfo_t` adjacency | This span sits between attack cooldowns and the path-memory band, but this pass did not isolate stable symbolic names for every slot. | Medium |
| `+0x3A4` | `monsterinfo.search_time` | `src/game/g_local.h`, stock `monsterinfo_t` | AI search/last-sighting logic stores frame times in this slot directly. | High |
| `+0x3A8` | `monsterinfo.trail_time` | `src/game/g_local.h`, stock `monsterinfo_t` | AI tracking logic uses a second nearby timer here, matching the stock trail-time slot. | Medium |
| `+0x3AC` | `monsterinfo.last_sighting` | `src/game/g_local.h`, stock `monsterinfo_t` | AI tracking code copies the last seen enemy origin into this vector directly. | High |
| `+0x3B8` | `monsterinfo.attack_state` | `src/game/g_local.h`, stock `monsterinfo_t` | `ai_checkattack` and related monster code store attack-state enums here directly. | High |
| `+0x3BC` | `monsterinfo.lefty` | `src/game/g_local.h`, stock `monsterinfo_t` | AI/animation code toggles this int directly. | High |
| `+0x3C0` | `monsterinfo.idle_time` | `src/game/g_local.h`, stock `monsterinfo_t` | Idle callback scheduling compares and updates this float timer directly. | High |
| `+0x3C4` | `monsterinfo.linkcount` | `src/game/g_local.h`, stock `monsterinfo_t` | AI pathing code compares this cached linkcount against the live entity linkcount. | High |
| `+0x3C8` | `monsterinfo.power_armor_type` | `src/game/g_local.h`, stock `monsterinfo_t` | Monster power-armor logic branches on `1` vs `2` in this slot directly. | High |
| `+0x3CC` | likely `monsterinfo.power_armor_power` or retail tail scalar | `src/game/g_local.h`, stock `monsterinfo_t` | Retail size extends through this final dword, but this pass did not isolate a direct symbolic write. | Medium |

## Export Callback Surface

| Slot | Address | Likely symbol | Current counterpart | Notes | Confidence |
| --- | --- | --- | --- | --- | --- |
| `Init` | `0x100158D0` | `InitGame` | `src/game/g_save.c` | Selected-function pass recovered the direct body; it initializes cvars, allocates edicts/clients, and seeds globals/import-backed state. | High |
| `Shutdown` | `0x1000D460` | `ShutdownGame` | `src/game/g_main.c` | Selected-function pass recovered the direct body; it logs shutdown and frees `TAG_LEVEL` / `TAG_GAME`. | High |
| `SpawnEntities` | `0x10016C60` | `SpawnEntities` | `src/game/g_spawn.c` | Selected-function pass recovered the direct body: skill clamp, entity parse loop, spawnflag inhibition, `ED_CallSpawn`, `G_FindTeams`, and trail init. | High |
| `WriteGame` | `0x10016020` | `WriteGame` | `src/game/g_save.c` | Selected-function pass recovered the direct body: optional `SaveClientData`, 16-byte build stamp, `game` block, and serialized clients. | High |
| `ReadGame` | `0x10016100` | `ReadGame` | `src/game/g_save.c` | Selected-function pass recovered the direct body: build-stamp validation, `g_edicts` / client allocation, and serialized client restore. | High |
| `WriteLevel` | `0x10016400` | `WriteLevel` | `src/game/g_save.c` | Selected-function pass recovered the direct body: edict-size sentinel, `InitGame` pointer sentinel, level locals, and in-use edict writes. | High |
| `ReadLevel` | `0x100164E0` | `ReadLevel` | `src/game/g_save.c` | Selected-function pass recovered the direct body: sentinel checks, level/entity restore, relink, and crosslevel target re-arming. | High |
| `ClientConnect` | `0x10031950` | `ClientConnect` | `src/game/p_client.c` | Selected-function pass recovered the direct body; banned-IP, spectator/password validation, and persistent-state init match the retail flow. | High |
| `ClientBegin` | `0x10031610` | `ClientBegin` | `src/game/p_client.c` | Selected-function pass recovered the direct body; deathmatch, loadgame, fresh-spawn, and intermission branches match stock Quake II flow. | High |
| `ClientUserinfoChanged` | `0x10031760` | `ClientUserinfoChanged` | `src/game/p_client.c` | Selected-function pass recovered the direct body; it rebuilds name/skin/fov/hand/spectator state and updates configstrings. | High |
| `ClientDisconnect` | `0x10031C30` | `ClientDisconnect` | `src/game/p_client.c` | Selected-function pass recovered the direct body; logout effect, unlink, cleanup, and skin reset match the retail flow. | High |
| `ClientCommand` | `0x100055F0` | `ClientCommand` | `src/game/g_cmds.c` | Selected-function pass recovered the direct dispatcher body, so this callback is now direct Ghidra evidence rather than slot-only naming. | High |
| `ClientThink` | `0x10031D70` | `ClientThink` | `src/game/p_client.c` | Selected-function pass recovered the direct body; pmove, trigger handling, chase logic, and weapon/button flow are now directly anchored. | High |
| `RunFrame` | `0x1000D940` | `G_RunFrame` | `src/game/g_main.c` | Selected-function pass recovered the direct body: frame/time advance, `AI_SetSightClient`, edict loop, `CheckDMRules`, and `ClientEndServerFrames`. | High |
| `ServerCommand` | `0x10017850` | `ServerCommand` | `src/game/g_svcmds.c` | Selected-function pass recovered the direct dispatcher for `test`, `addip`, `removeip`, `listip`, and `writeip`; the current wrapper/legacy split is likely compiled away. | High |

## Frame And Level Flow

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x1000D5A0` | `ClientEndServerFrames` | `src/game/g_main.c` | Direct selected body loops across active player edicts and calls `ClientEndServerFrame` for connected clients. | High |
| `0x1000D610` | `CreateTargetChangeLevel` | `src/game/g_main.c` | Calls `G_Spawn`, writes classname `target_changelevel`, and stores the next map string pointer. | High |
| `0x1000D650` | `EndDMLevel` | `src/game/g_main.c` | Scans maplist, checks same-level flag, searches `target_changelevel`, then calls `BeginIntermission` with the chosen destination. | High |
| `0x1000D770` | `CheckDMRules` | `src/game/g_main.c` | Emits `Timelimit hit.` / `Fraglimit hit.` and then calls `EndDMLevel`. | High |
| `0x1000D870` | `ExitLevel` | `src/game/g_main.c` | Formats `gamemap \"%s\"\n`, clears intermission flags, calls `ClientEndServerFrames`, and clamps client health. | High |
| `0x10031570` | `ClientBeginDeathmatch` | `src/game/p_client.c` | Calls `G_InitEdict`, `InitClientResp`, `PutClientInServer`, emits login effect, prints `entered the game`, then runs `ClientEndServerFrame`. | High |
| `0x100323B0` | `MoveClientToIntermission` | `src/game/p_hud.c` | Repositions client to intermission origin/angles, clears weapon effects, updates playerstate for intermission. | High |
| `0x10034D80` | `ClientEndServerFrame` | `src/game/p_view.c` | Selected-function pass recovered the direct body; this large playerstate/view update is now directly named in the Ghidra corpus. | High |

## Save / Load Serialization

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10015C90` | `WriteField1` | `src/game/g_save.c` | Converts pointers into lengths or indices based on field type, including edict/client/item/function/mmove cases. | High |
| `0x10015DC0` | `WriteField2` | `src/game/g_save.c` | Writes trailing string payloads for `F_LSTRING` fields only. | High |
| `0x10015E00` | `ReadField` | `src/game/g_save.c` | Rebuilds strings, edict pointers, client pointers, item pointers, function pointers, and mmove pointers. | High |
| `0x10015F40` | `WriteClient` | `src/game/g_save.c` | Copies a `0xF34` client block, runs `WriteField1`, writes block, then `WriteField2`. | High |
| `0x10015FD0` | `ReadClient` | `src/game/g_save.c` | Reads `0xF34` bytes, then iterates `clientfields` through `ReadField`. | High |
| `0x10016240` | `WriteEdict` | `src/game/g_save.c` | Copies a `0x3D0` edict block, serializes `fields`, writes block, then writes trailing strings. | High |
| `0x100162D0` | `WriteLevelLocals` | `src/game/g_save.c` | Serializes `level_locals_t` through the `levelfields` table. | High |
| `0x10016360` | `ReadEdict` | `src/game/g_save.c` | Reads `0x3D0` bytes, then restores pointer fields through `ReadField`. | High |
| `0x100163B0` | `ReadLevelLocals` | `src/game/g_save.c` | Reads serialized `level` block and restores `levelfields`. | High |
| `0x10016020` | `WriteGame` | `src/game/g_save.c` | Direct body writes the build stamp, `game` block, and each serialized client after the optional `SaveClientData` pre-pass. | High |
| `0x10016100` | `ReadGame` | `src/game/g_save.c` | Direct body validates the build stamp, reallocates `g_edicts` / clients, and restores client blocks before closing the file. | High |
| `0x10016400` | `WriteLevel` | `src/game/g_save.c` | Direct body writes edict size, `InitGame` pointer sentinel, level locals, and each in-use edict followed by `-1`. | High |
| `0x100164E0` | `ReadLevel` | `src/game/g_save.c` | Direct body validates sentinels, restores level locals/entities, relinks them, marks clients disconnected, and rearms crosslevel targets. | High |

## Spawn Parsing And Map Setup

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10016750` | `ED_CallSpawn` | `src/game/g_spawn.c` | Checks item list first, then `spawns[]`, prints `ED_CallSpawn: NULL classname` and `%s doesn't have a spawn function`. | High |
| `0x10016850` | `ED_NewString` | `src/game/g_spawn.c` | Allocates new string, converts `\\n` escape pairs to newline, otherwise copies bytes through. | High |
| `0x100168B0` | `ED_ParseField` | `src/game/g_spawn.c` | Walks `fields[]`, rejects `FFL_NOSPAWN`, parses int/float/vector/angle/string, prints `%s is not a field`. | High |
| `0x10016A00` | `ED_ParseEdict` | `src/game/g_spawn.c` | Calls token parser, rejects bad braces, skips underscore keys, delegates to `ED_ParseField`. | High |
| `0x10016AF0` | `G_FindTeams` | `src/game/g_spawn.c` | Chains team-linked entities and prints `%i teams with %i entities`. | High |
| `0x10016C60` | `SpawnEntities` | `src/game/g_spawn.c` | Direct body clamps `skill`, clears level/edict state, parses entity text, applies the `command` / `trigger_once` / `*27` hack, inhibits by spawnflags, then runs `G_FindTeams` and trail init. | High |

## Help, Secret, And Goal Targets

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10017AA0` | `Use_Target_Help` | `src/game/g_target.c` | Direct selected body copies `ent->message` into either help-message buffer based on spawnflag `1`, then increments the shared help-change counter. | High |
| `0x10017B00` | `SP_target_help` | `src/game/g_target.c` | Direct selected body removes itself in deathmatch, emits the stock `%s with no message at %s` diagnostic on missing `message`, and otherwise installs `Use_Target_Help`. | High |
| `0x10017B70` | `use_target_secret` | `src/game/g_target.c` | Direct selected body plays `noise_index`, increments `level.found_secrets`, runs `G_UseTargets`, and frees the edict. | High |
| `0x10017BC0` | `SP_target_secret` | `src/game/g_target.c` | Direct selected body removes itself in deathmatch, installs `use_target_secret`, defaults the shared `misc/secret.wav`, sets `SVF_NOCLIENT`, increments `level.total_secrets`, and carries the stock `mine3` map-bug hack. | High |
| `0x10017C70` | `use_target_goal` | `src/game/g_target.c` | Direct selected body plays `noise_index`, increments `level.found_goals`, conditionally clears `CS_CDTRACK`, runs `G_UseTargets`, and frees the edict. | High |
| `0x10017CD0` | `SP_target_goal` | `src/game/g_target.c` | Direct selected body removes itself in deathmatch, installs `use_target_goal`, defaults the shared `misc/secret.wav`, sets `SVF_NOCLIENT`, and increments `level.total_goals`. | High |

## Explosion, Exit, Splash, Spawn, And Target Weapon Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10017D40` | `target_explosion_explode` | `src/game/g_target.c` | Direct selected body emits `TE_EXPLOSION1`, applies `T_RadiusDamage`, then clears and restores `delay` around `G_UseTargets`, matching the stock explosion helper exactly. | High |
| `0x10017DE0` | `use_target_explosion` | `src/game/g_target.c` | Direct selected body stores `activator`, fires immediately when `delay == 0`, and otherwise schedules `target_explosion_explode` at `level.time + delay`. | High |
| `0x10017E30` | `SP_target_explosion` | `src/game/g_target.c` | Direct selected body installs `use_target_explosion` and `SVF_NOCLIENT`, matching the stock wrapper. | High |
| `0x10017E50` | `use_target_changelevel` | `src/game/g_target.c` | Direct selected body matches the retail exit flow: intermission gate, single-player dead-player gate, deathmatch `DF_ALLOW_EXIT` damage path, exit announcement, cross-trigger clear on `*` maps, then `BeginIntermission`. | High |
| `0x10017F80` | `SP_target_changelevel` | `src/game/g_target.c` | Direct selected body validates `map`, prints the stock missing-map diagnostic, carries the `fact1 -> fact3$secret1` retail hack, then installs `use_target_changelevel` plus `SVF_NOCLIENT`. | High |
| `0x10018000` | `use_target_splash` | `src/game/g_target.c` | Direct selected body emits `TE_SPLASH` from `count`, `s.origin`, `movedir`, and `sounds`, then applies optional radius damage when `dmg` is set. | High |
| `0x10018090` | `SP_target_splash` | `src/game/g_target.c` | Direct selected body installs `use_target_splash`, derives `movedir` from `s.angles`, defaults `count` to `32`, and marks the entity `SVF_NOCLIENT`. | High |
| `0x100180E0` | `use_target_spawner` | `src/game/g_target.c` | Direct selected body matches the stock spawn helper: `G_Spawn`, `classname = target`, origin and angle copy, `ED_CallSpawn`, unlink, `KillBox`, relink, and optional movedir-based velocity copy. | High |
| `0x10018180` | `SP_target_spawner` | `src/game/g_target.c` | Direct selected body installs `use_target_spawner`, marks `SVF_NOCLIENT`, and precomputes a scaled `movedir` only when `speed` is set. | High |
| `0x100181E0` | `use_target_blaster` | `src/game/g_target.c` | Direct selected body fires `fire_blaster(self, self->s.origin, self->movedir, self->dmg, speed, EF_BLASTER, MOD_TARGET_BLASTER)` and plays the precached fire sound. | High |
| `0x10018230` | `SP_target_blaster` | `src/game/g_target.c` | Direct selected body derives `movedir`, precaches `weapons/laser2.wav`, defaults `dmg` to `15` and `speed` to `1000`, then installs `use_target_blaster`. | High |
| `0x100182A0` | `use_target_railgun` | `src/game/g_target.c` | Retail body is thinner than current source: it fires directly from `self->s.origin` along `self->movedir` with `self->dmg` and plays the precached rail sound, with no retail evidence here for the current `wait` or `move_origin` or `move_angles` wrapper state. | High |
| `0x100182E0` | `SP_target_railgun` | `src/game/g_target.c` | Retail body is also thinner than current source: it derives `movedir`, precaches `weapons/railgf1a.wav`, defaults `dmg` to `150`, and installs `use_target_railgun`. | High |
| `0x10018340` | `target_rocket_fire` | `src/game/g_target.c` | Direct selected body fires `fire_rocket(self, self->s.origin, self->movedir, self->dmg, speed, dmg_radius, radius_damage)` and plays the precached fire sound. | High |
| `0x100183A0` | `SP_target_rocket` | `src/game/g_target.c` | Retail wrapper installs `target_rocket_fire` directly, derives `movedir`, precaches `weapons/rocklf1a.wav`, seeds the stock damage or radius defaults, and marks `SVF_NOCLIENT`; there is no separate retail `target_rocket_use` body at this address band. | High |

## Crosslevel And Laser Target Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10018470` | `trigger_crosslevel_trigger_use` | `src/game/g_target.c` | Direct selected body ORs `spawnflags` into `game.serverflags` and frees the trigger entity immediately, matching the stock crosslevel trigger use path. | High |
| `0x10018490` | `SP_target_crosslevel_trigger` | `src/game/g_target.c` | Direct selected body marks `SVF_NOCLIENT` and installs `trigger_crosslevel_trigger_use`. | High |
| `0x100184B0` | `target_crosslevel_target_think` | `src/game/g_target.c` | Direct selected body checks `(spawnflags & SFL_CROSS_TRIGGER_MASK)` against `game.serverflags`, then runs `G_UseTargets` and frees the entity on match. | High |
| `0x100184F0` | `SP_target_crosslevel_target` | `src/game/g_target.c` | Direct selected body defaults `delay` to `1.0`, marks `SVF_NOCLIENT`, and schedules `target_crosslevel_target_think` at `level.time + delay`. | High |
| `0x10018540` | `target_laser_think` | `src/game/g_target.c` | Direct selected body matches the stock laser trace loop: optional enemy tracking, `gi.trace` beam walk, damage on hittable targets, spark temp entity on impact, beam end update, and `FRAMETIME` reschedule. | High |
| `0x10018790` | `target_laser_on` | `src/game/g_target.c` | Direct selected body seeds `activator` when missing, sets the active beam flag, clears `SVF_NOCLIENT`, and enters `target_laser_think`. | High |
| `0x100187D0` | `target_laser_off` | `src/game/g_target.c` | Direct selected body clears `nextthink`, clears the active beam flag, and restores `SVF_NOCLIENT`. | High |
| `0x10018800` | `target_laser_use` | `src/game/g_target.c` | Direct selected body stores `activator`, then toggles the beam through `target_laser_off` or `target_laser_on` based on the live active bit. | High |
| `0x10018830` | `target_laser_start` | `src/game/g_target.c` | Direct selected body configures renderfx, beam width, and beam color from spawnflags, including the hidden `0x80` narrow-beam case used by the mine-laser children, resolves optional enemy tracking via `target`, falls back to `G_SetMovedir` when no target is present, installs the use and think callbacks, and toggles initial state from spawnflag `START_ON`. | High |
| `0x100189B0` | `SP_target_laser` | `src/game/g_target.c` | Direct selected body arms the deferred startup through `target_laser_start` at `level.time + 1`. | High |

## Light Ramp And Earthquake Target Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x100189E0` | `target_lightramp_think` | `src/game/g_target.c` | Direct selected body computes the current light style character from the stored start, step, and `level.time - timestamp`, writes it through `gi.configstring(CS_LIGHTS + enemy->style, style)`, reschedules until `speed` elapses, and swaps ramp direction when `TOGGLE` is set. | High |
| `0x10018AB0` | `target_lightramp_use` | `src/game/g_target.c` | Direct selected body lazily resolves `target` through repeated `G_Find`, validates that each hit is a `light`, emits the stock diagnostics for non-light or missing targets, stores the resolved light in `enemy`, stamps `timestamp = level.time`, and enters `target_lightramp_think`. | High |
| `0x10018BD0` | `SP_target_lightramp` | `src/game/g_target.c` | Direct selected body validates a two-letter lowercase `message` ramp, removes itself in deathmatch, validates `target`, installs the use and think callbacks, sets `SVF_NOCLIENT`, and converts the two ramp letters into the stored start, end, and per-frame step values. | High |
| `0x10018D10` | `target_earthquake_think` | `src/game/g_target.c` | Direct selected body replays the positioned quake sound on the `0.5` second cadence, iterates active grounded clients, clears `groundentity`, applies randomized horizontal kick plus mass-scaled vertical impulse, and reschedules until `timestamp`. | High |
| `0x10018E60` | `target_earthquake_use` | `src/game/g_target.c` | Direct selected body stores `timestamp = level.time + count`, arms the first `FRAMETIME` think, stores `activator`, and clears `last_move_time`. | High |
| `0x10018EA0` | `SP_target_earthquake` | `src/game/g_target.c` | Direct selected body warns on untargeted earthquakes, defaults `count` to `5` and `speed` to `200`, marks `SVF_NOCLIENT`, installs the use and think callbacks, and precaches `world/quake.wav`. | High |

## `SP_target_*` Spawn Chain Summary

| Spawn wrapper | Retail address | Immediate retail chain | Notes |
| --- | --- | --- | --- |
| `SP_target_help` | `0x10017B00` | `SP_target_help -> Use_Target_Help` | Thin message-validation wrapper; only installs the help callback after the stock deathmatch and missing-message gates. |
| `SP_target_secret` | `0x10017BC0` | `SP_target_secret -> use_target_secret -> G_UseTargets -> G_FreeEdict` | Also increments `level.total_secrets` and seeds the shared secret sound in the wrapper. |
| `SP_target_goal` | `0x10017CD0` | `SP_target_goal -> use_target_goal -> G_UseTargets -> G_FreeEdict` | Mirrors the secret path, but increments `level.total_goals` and owns the goal completion CD-track clear in the use callback. |
| `SP_target_explosion` | `0x10017E30` | `SP_target_explosion -> use_target_explosion -> target_explosion_explode` or immediate `target_explosion_explode` | The use path either fires immediately or schedules the think callback through `delay`. |
| `SP_target_changelevel` | `0x10017F80` | `SP_target_changelevel -> use_target_changelevel -> BeginIntermission` | Pure use-driven exit wrapper after map validation and the retail `fact1` hack. |
| `SP_target_splash` | `0x10018090` | `SP_target_splash -> use_target_splash` | Runtime work is all in the use callback after the wrapper derives `movedir` and defaults `count`. |
| `SP_target_spawner` | `0x10018180` | `SP_target_spawner -> use_target_spawner -> ED_CallSpawn` | Wrapper optionally precomputes scaled `movedir`; the use path owns `G_Spawn`, `KillBox`, and relink. |
| `SP_target_blaster` | `0x10018230` | `SP_target_blaster -> use_target_blaster -> fire_blaster` | Wrapper only seeds `movedir`, sound, damage, and speed defaults. |
| `SP_target_railgun` | `0x100182E0` | `SP_target_railgun -> use_target_railgun -> fire_rail` | Retail keeps this thinner than current source; no richer wait/timestamp wrapper state is evidenced here. |
| `SP_target_rocket` | `0x100183A0` | `SP_target_rocket -> target_rocket_fire -> fire_rocket` | Retail wires directly to `target_rocket_fire`; there is no separate retail `target_rocket_use` body in this band. |
| `SP_target_crosslevel_trigger` | `0x10018490` | `SP_target_crosslevel_trigger -> trigger_crosslevel_trigger_use` | Thin serverflag setter; no touch path. |
| `SP_target_crosslevel_target` | `0x100184F0` | `SP_target_crosslevel_target -> target_crosslevel_target_think -> G_UseTargets` | Wrapper defaults `delay = 1.0` and immediately schedules the think callback. |
| `SP_target_laser` | `0x100189B0` | `SP_target_laser -> target_laser_start -> target_laser_on` or `target_laser_off` -> `target_laser_use` -> `target_laser_think` | Retail laser setup is deferred; the wrapper only arms startup and the later chain owns beam state. |
| `SP_target_lightramp` | `0x10018BD0` | `SP_target_lightramp -> target_lightramp_use -> target_lightramp_think` | Wrapper parses the two-letter ramp and stores step data; use resolves the target light and hands off to think. |
| `SP_target_earthquake` | `0x10018EA0` | `SP_target_earthquake -> target_earthquake_use -> target_earthquake_think` | Wrapper seeds defaults and sound; use arms the timed quake loop. |

## Brush Mover, Timer, Conveyor, And Secret-Door Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10007100` | `plat_hit_top` | `src/game/g_func.c` | Direct selected body stops the plat at the top, clears the looping sound, marks `STATE_TOP`, and schedules the down move after `wait`, matching the stock/current plat top callback. | High |
| `0x10007170` | `plat_hit_bottom` | `src/game/g_func.c` | Direct selected body clears the looping sound, marks `STATE_BOTTOM`, and ends the plat travel exactly like the stock bottom callback. | High |
| `0x100071C0` | `plat_go_up` | `src/game/g_func.c` | Direct selected body sets `STATE_UP`, starts the movement sound, and hands off into the top callback through the stock move helper. | High |
| `0x10007220` | `plat_go_down` | `src/game/g_func.c` | Direct selected body mirrors the up path toward the start origin and routes into `plat_hit_bottom`. | High |
| `0x10007280` | `plat_blocked` | `src/game/g_func.c` | Direct selected body matches the stock plat crush path, including the gib-nuke fallback for non-clients/non-monsters and the debounce-gated `MOD_CRUSH` damage branch. | High |
| `0x10007390` | `plat_spawn_inside_trigger` | `src/game/g_func.c` | Direct selected body allocates the trigger volume for the plat center-touch path, using the stock bbox expansion and local touch callback setup. | High |
| `0x100074F0` | `SP_func_plat` | `src/game/g_func.c` | Direct selected body sets the BSP push wrapper, defaults speed/accel/decel/dmg, seeds `plats/pt1_*` sounds, computes `pos1/pos2`, installs `plat_blocked`, and spawns the inside trigger. | High |
| `0x100083C0` | `rotating_use` | `src/game/g_func.c` | Direct selected body recovers the retail toggle path for both continuous rotation and partial `mangle` rotation, including the touch-pain enable and loop scheduling branches. | High |
| `0x10008B80` | `button_return` | `src/game/g_func.c` | Direct selected body marks `STATE_DOWN`, moves back to the start origin, resets frame state, and re-enables damage on shootable buttons. | High |
| `0x10008BD0` | `button_wait` | `src/game/g_func.c` | Direct selected body marks `STATE_TOP`, flips the animation flags, fires `G_UseTargets`, and schedules `button_return` when `wait >= 0`. | High |
| `0x10008C40` | `button_fire` | `src/game/g_func.c` | Direct selected body guards the button state, plays the start sound, marks `STATE_UP`, and moves to the end origin through `button_wait`. | High |
| `0x10008D30` | `SP_func_button` | `src/game/g_func.c` | Direct selected body derives `movedir`, defaults speed/accel/decel/wait, computes `pos1/pos2`, installs the use/touch/kill paths, seeds the moveinfo block, and links the BSP button. | High |
| `0x10008F90` | `door_use_areaportals` | `src/game/g_func.c` | Direct selected body iterates matching targets, filters `func_areaportal`, and toggles each portal through the engine callback, matching the stock door-portal helper. | High |
| `0x10009010` | `door_hit_top` | `src/game/g_func.c` | Direct selected body stops the open move, clears the middle sound, marks `STATE_TOP`, and schedules `door_go_down` after `wait`. | High |
| `0x10009090` | `door_hit_bottom` | `src/game/g_func.c` | Direct selected body stops the move, marks `STATE_BOTTOM`, and closes areaportals through `door_use_areaportals(self, 0)`. | High |
| `0x100090F0` | `door_go_down` | `src/game/g_func.c` | Direct selected body matches the stock close path for both `func_door` and `func_door_rotating`, restoring the start transform and routing into `door_hit_bottom`. | High |
| `0x10009200` | `door_go_up` | `src/game/g_func.c` | Direct selected body matches the stock open path for both sliding and rotating doors, including sound state, `G_UseTargets`, and areaportal open. | High |
| `0x10009340` | `door_use` | `src/game/g_func.c` | Direct selected body walks the teammaster chain and routes each live door through `door_go_up` or `door_go_down` based on state. | High |
| `0x10009430` | `Think_CalcMoveSpeed` | `src/game/g_func.c` | Direct selected body harmonizes team-chained mover speed/accel/decel from the shortest move distance, matching the stock door-speed equalizer. | High |
| `0x100097B0` | `door_touch` | `src/game/g_func.c` | Direct selected body matches the stock touch-message path, including `misc/talk1.wav` debounce feedback for live clients. | High |
| `0x10009830` | `SP_func_door` | `src/game/g_func.c` | Direct selected body sets the BSP door wrapper, seeds `doors/dr1_*` sounds, doubles speed in deathmatch, installs `door_use`, `door_touch`, and the blocked chain, computes the move endpoints, and uses `Think_CalcMoveSpeed` when teamed. | High |
| `0x10009BD0` | `SP_func_door_rotating` | `src/game/g_func.c` | Direct selected body matches the rotating-door wrapper: axis selection from spawnflags, reverse handling, default distance `90`, shared door sounds, and the same door helper chain reached through angular motion. | High |
| `0x10009FA0` | `SP_func_water` | `src/game/g_func.c` | Direct selected body seeds the water/lava mover sounds, computes the second position, then rewrites the classname to `func_door` and reuses the sliding-door use chain. | High |
| `0x1000A300` | `train_next` | `src/game/g_func.c` | Direct selected body matches the stock path-corner advance path, including `train_next: bad target %s`, the connected-teleport diagnostic, target-ent handoff, and `Move_Calc(..., train_wait)`. | High |
| `0x1000A4C0` | `train_resume` | `src/game/g_func.c` | Direct selected body resumes the train toward the already-resolved `target_ent` destination exactly like current source. | High |
| `0x1000A560` | `func_train_find` | `src/game/g_func.c` | Direct selected body matches the spawn-side target resolution wrapper, including `train_find: no target` and `train_find: target %s not found`. | High |
| `0x1000A620` | `train_use` | `src/game/g_func.c` | Direct selected body stores `activator`, handles the `START_ON`/`TOGGLE` stop case, and otherwise routes into `train_resume` or `train_next`. | High |
| `0x1000A680` | `SP_func_train` | `src/game/g_func.c` | Direct selected body matches the retail train wrapper: BSP push setup, `train_blocked`, damage defaults, optional explosive setup, `train_use`, link, and delayed `func_train_find` startup with the `func_train without a target at %s` diagnostic. | High |
| `0x1000A9A0` | `func_timer_think` | `src/game/g_func.c` | Direct selected body fires `G_UseTargets(self, self->activator)` and reschedules through `wait + crandom() * random`, matching the stock timer loop. | High |
| `0x1000AA60` | `SP_func_timer` | `src/game/g_func.c` | Direct selected body defaults `wait`, installs the local use callback plus `func_timer_think`, enforces `random < wait` with the stock diagnostic, and handles the `START_ON` first-fire setup. | High |
| `0x1000AB80` | `SP_func_conveyor` | `src/game/g_func.c` | Direct selected body defaults `speed = 100`, folds the start-off path into `count`, installs the local use callback, and links the BSP conveyor. | High |
| `0x1000AC00` | `door_secret_use` | `src/game/g_func.c` | Direct selected body compares the current origin against the closed position and begins the secret-door move through the first local stage while opening areaportals. | High |
| `0x1000AD70` | `door_secret_blocked` | `src/game/g_func.c` | Direct selected body matches the secret-door crush path, including the non-client/non-monster gib case and the debounce-gated damage branch. | High |
| `0x10014940` | local `RotateTrain_MoveDone` | `src/game/g_rtrain.c` | Wide disassembly body matches the rotate-train move tail exactly: clear both velocity bands, wrap each angle with signed `% 360`, and jump through the stored move endfunc. | High |
| `0x100149D0` | local `RotateTrain_MoveFinal` | `src/game/g_rtrain.c` | Wide disassembly body matches the retail final-frame helper, including the `remaining_distance * 10` linear step, the conditional end-angle delta -> `avelocity * 10` path, and the handoff into `RotateTrain_MoveDone`. | High |
| `0x10014AD0` | local `RotateTrain_MoveBegin` | `src/game/g_rtrain.c` | Wide disassembly body matches the rotate-train segment starter: stock-style linear frame scheduling, `duration` or `angle_length / speed` angular timing, and the direct handoff into `RotateTrain_MoveFinal`. | High |
| `0x10014C50` | local `RotateTrain_MoveCalc` | `src/game/g_rtrain.c` | Wide disassembly body matches the retail rotate-train move calculator, including the `duration`-driven speed override, `rotate`-vector angle goal setup, `speeds`-driven direct `avelocity`, and the immediate-vs-delayed `RotateTrain_MoveBegin` dispatch based on `level.current_entity`. | High |
| `0x10015090` | `train_blocked` | `src/game/g_func.c` | Wide decompilation body matches the stock train crush logic exactly: non-client/non-monster `BecomeExplosion1` fallback, `touch_debounce_time` gate, and `dmg`-guarded `MOD_CRUSH` damage. | High |
| `0x10015140` | local `rotate_train_wait` | `src/game/g_rtrain.c` | Raw disassembly matches the retail end-of-corner callback: optional `pathtarget` fire, stock wait or toggle-stop handling, and the shared sound-end or `s.sound = 0` shutdown path. | High |
| `0x10015250` | `rotate_train_next` | `src/game/g_rtrain.c` | Raw disassembly matches the retail rotate-train advance path, including the direct path-corner origin teleport, per-corner `duration` or `rotate` or `speeds` overrides, preserved speed when the next corner omits `speed`, and `RotateTrain_MoveCalc(..., rotate_train_wait)`. | High |
| `0x100154C0` | `rotate_train_resume` | `src/game/g_rtrain.c` | Raw disassembly matches the retail resume helper: restart the current leg toward the already-resolved `target_ent` destination without re-reading the path-corner overrides. | High |
| `0x10015560` | `rotate_train_find` | `src/game/g_rtrain.c` | Raw disassembly matches the retail startup resolver, including the shared `train_find` diagnostics, the first-corner `duration` or `rotate` or `speeds` seed, the direct path-corner origin placement, and the delayed `rotate_train_next` startup. | High |
| `0x100156F0` | `rotate_train_use` | `src/game/g_rtrain.c` | Raw disassembly matches the retail use callback: store `activator`, honor `START_ON` or `TOGGLE`, clear only the linear velocity band on toggle-stop, and otherwise route into `rotate_train_resume` or `rotate_train_next`. | High |
| `0x10015750` | `SP_func_rotate_train` | `src/game/g_rtrain.c` | Raw disassembly plus HLIL stub match the retail spawn wrapper: BSP push setup, shared `train_blocked`, `dmg = 100` default, optional looping sound, `speed = 100` default, delayed `rotate_train_find`, and the reused `func_train without a target at %s` diagnostic. | High |

## `SP_func_*` Spawn Chain Summary

| Spawn wrapper | Retail address | Immediate retail chain | Notes |
| --- | --- | --- | --- |
| `SP_func_clock` | `0x10011160` | `SP_func_clock -> local think/use callback -> func_clock_format_countdown -> target_string_use` | Already recovered in the `g_misc.c` band; the wrapper seeds message storage and the runtime clock chain. |
| `SP_func_plat` | `0x100074F0` | `SP_func_plat -> plat_spawn_inside_trigger -> local center trigger -> plat_go_up -> plat_hit_top -> plat_go_down -> plat_hit_bottom` | The center touch/use callbacks are still compiled as local labels, but the outer plat chain is direct. |
| `SP_func_rotating` | not isolated | `SP_func_rotating -> rotating_use` and local rotate/stop callbacks | The retail wrapper is not yet a stable standalone function start in the committed corpus, but `rotating_use` directly anchors the runtime behavior. |
| `SP_func_button` | `0x10008D30` | `SP_func_button -> button_touch` or `button_use` or `button_killed` -> `button_fire -> button_wait -> button_return -> button_done` | Only `button_fire`, `button_wait`, and `button_return` are standalone selected bodies; the entry/use/touch/kill tails remain local callbacks. |
| `SP_func_door` | `0x10009830` | `SP_func_door -> door_use` or `door_touch` -> `door_go_up -> door_hit_top -> door_go_down -> door_hit_bottom` | `door_use_areaportals` and `Think_CalcMoveSpeed` are direct retail helpers in the same chain. |
| `SP_func_door_rotating` | `0x10009BD0` | `SP_func_door_rotating -> door_use -> door_go_up` or `door_go_down` -> `door_hit_top` or `door_hit_bottom` | Retail keeps the wrapper separate, but the runtime helper band is the same door chain with rotating movement. |
| `SP_func_water` | `0x10009FA0` | `SP_func_water -> door_use -> door_go_up` or `door_go_down` | Retail rewrites the entity into `func_door` after seeding water/lava-specific sounds and endpoints. |
| `SP_func_train` | `0x1000A680` | `SP_func_train -> func_train_find -> train_next` or `train_resume` -> local `train_wait` | `train_use` and `train_blocked` are direct helpers; `train_wait` is still compiled as a local callback rather than a standalone function. |
| `SP_func_rotate_train` | `0x10015750` | `SP_func_rotate_train -> rotate_train_find -> rotate_train_next` or `rotate_train_resume` -> local `rotate_train_wait` | Retail reuses `train_blocked`, keeps the stock `func_train without a target at %s` diagnostic, moves directly to each path-corner origin, and applies per-corner `duration` or `rotate` or `speeds` overrides from the next corner. |
| `SP_func_timer` | `0x1000AA60` | `SP_func_timer -> local func_timer_use -> func_timer_think -> G_UseTargets` | The timer loop is direct; only the simple on/off use callback remains local. |
| `SP_func_conveyor` | `0x1000AB80` | `SP_func_conveyor -> local func_conveyor_use` | Retail keeps this as a thin spawn wrapper plus a simple toggle use callback. |
| `SP_func_door_secret` | not isolated | `SP_func_door_secret -> door_secret_use -> local secret-door move stages -> local done tail` | The wrapper and move-stage callbacks are not isolated as standalone starts, but `door_secret_use` and `door_secret_blocked` are direct retail helpers. |
| `SP_func_killbox` | not isolated | `SP_func_killbox -> use_killbox -> KillBox` | Current source still has the wrapper, but no stable standalone retail function start has been promoted for it yet. |

## Trigger Utility, Multi, Key, Counter, Push, Hurt, Gravity, And Monsterjump Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10018F40` | `InitTrigger` | `src/game/g_trigger.c` | Direct selected body derives movedir from `s.angles` when needed, sets `solid = SOLID_TRIGGER`, `movetype = MOVETYPE_NONE`, applies `gi.setmodel(self, self->model)`, and marks `SVF_NOCLIENT`. | High |
| `0x10018FA0` | `multi_wait` | `src/game/g_trigger.c` | Direct selected body clears `nextthink`, matching the stock multi-trigger rearm tail. | High |
| `0x10018FB0` | `multi_trigger` | `src/game/g_trigger.c` | Direct selected body guards on `nextthink`, runs `G_UseTargets`, rearms `multi_wait` when `wait > 0`, and otherwise clears `touch` then schedules `G_FreeEdict`. | High |
| `0x10019040` | `Use_Multi` | `src/game/g_trigger.c` | Direct selected body stores `activator` and forwards immediately into `multi_trigger`. | High |
| `0x10019060` | `Touch_Multi` | `src/game/g_trigger.c` | Direct selected body gates on client vs monster spawnflags, performs the optional movedir facing test through `AngleVectors` and `DotProduct`, stores `activator`, and enters `multi_trigger`. | High |
| `0x100190F0` | `trigger_enable` | `src/game/g_trigger.c` | Direct selected body restores trigger solidity, installs `Use_Multi`, and relinks the entity. | High |
| `0x10019120` | `SP_trigger_multiple` | `src/game/g_trigger.c` | Direct selected body precaches the `sounds` variants, defaults `wait = 0.2`, installs `Touch_Multi`, handles the start-off `TRIGGERED` path through `trigger_enable`, then derives movedir, sets the model, and links. | High |
| `0x10019210` | `SP_trigger_once` | `src/game/g_trigger.c` | Direct selected body fixes the legacy wrong `TRIGGERED` bit, prints `fixed TRIGGERED flag on %s at %s`, forces `wait = -1`, and then reuses `SP_trigger_multiple`. | High |
| `0x10019290` | `trigger_relay_use` | `src/game/g_trigger.c` | Direct selected body is the thin relay wrapper: `G_UseTargets(self, activator)`. | High |
| `0x100192B0` | `SP_trigger_relay` | `src/game/g_trigger.c` | Direct selected body installs `trigger_relay_use`, matching the stock spawn wrapper exactly. | High |
| `0x100192C0` | `trigger_key_use` | `src/game/g_trigger.c` | Direct selected body matches the stock key-gated relay path, including `You need the %s`, `misc/keytry.wav`, `misc/keyuse.wav`, coop power-cube bit handling, shared key clear, final `G_UseTargets`, and `self->use = NULL`. | High |
| `0x10019530` | `SP_trigger_key` | `src/game/g_trigger.c` | Direct selected body validates `st.item`, resolves it through `FindItemByClassname`, validates `target`, precaches the key sounds, and installs `trigger_key_use`. | High |
| `0x100195E0` | `trigger_counter_use` | `src/game/g_trigger.c` | Direct selected body decrements `count`, prints `%i more to go...` or `Sequence completed!`, plays `misc/talk1.wav`, stores `activator`, and finishes through `multi_trigger`. | High |
| `0x100196A0` | `SP_trigger_counter` | `src/game/g_trigger.c` | Direct selected body forces `wait = -1`, defaults `count = 2`, mirrors `health = count`, and installs `trigger_counter_use`. | High |
| `0x100196D0` | `SP_trigger_always` | `src/game/g_trigger.c` | Direct selected body clamps `delay` up to `0.2` when needed and immediately runs `G_UseTargets(self, self)`. | High |
| `0x10019700` | `trigger_push_touch` | `src/game/g_trigger.c` | Direct selected body matches the stock push trigger: grenade or health gate, `movedir * speed * 10` velocity write, client `oldvelocity` copy, wind-sound rate limit, and optional free on `PUSH_ONCE`. | High |
| `0x10019850` | `SP_trigger_push` | `src/game/g_trigger.c` | Direct selected body runs `InitTrigger`, precaches `misc/windfly.wav`, installs `trigger_push_touch`, defaults `speed = 1000`, and links. | High |
| `0x100198C0` | `hurt_use` | `src/game/g_trigger.c` | Direct selected body toggles `solid` between `SOLID_TRIGGER` and `SOLID_NOT`, relinks, and clears its own `use` callback unless `TOGGLE` is set. | High |
| `0x10019900` | `hurt_touch` | `src/game/g_trigger.c` | Direct selected body matches the stock hurt path: takedamage gate, timestamp throttling with `SLOW`, optional sound, `DAMAGE_NO_PROTECTION` on request, and final `T_Damage(..., MOD_TRIGGER_HURT)`. | High |
| `0x100199C0` | `SP_trigger_hurt` | `src/game/g_trigger.c` | Direct selected body runs `InitTrigger`, precaches `world/electro.wav`, installs `hurt_touch`, defaults `dmg = 5`, honors `START_OFF` and `TOGGLE`, and links. | High |
| `0x10019A40` | `trigger_gravity_touch` | `src/game/g_trigger.c` | Direct selected body copies `self->gravity` into `other->gravity`, matching the stock gravity trigger. | High |
| `0x10019A60` | `SP_trigger_gravity` | `src/game/g_trigger.c` | Direct selected body validates `st.gravity`, prints `trigger_gravity without gravity set at %s` and frees on missing data, otherwise runs `InitTrigger`, parses gravity through `atoi`, and installs `trigger_gravity_touch`. | High |
| `0x10019AC0` | `trigger_monsterjump_touch` | `src/game/g_trigger.c` | Direct selected body gates on `FL_FLY | FL_SWIM`, `SVF_DEADMONSTER`, and `SVF_MONSTER`, writes XY jump velocity from `movedir * speed`, requires `groundentity` for the Z launch, clears it, then writes `velocity[2] = movedir[2]`. | High |
| `0x10019B30` | `SP_trigger_monsterjump` | `src/game/g_trigger.c` | Direct selected body defaults `speed = 200` and `st.height = 200`, applies the stock `YAW 0 -> 360` fix, runs `InitTrigger`, installs `trigger_monsterjump_touch`, and stores `movedir[2] = st.height`. | High |

## Custom Teleport Trigger Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10019BA0` | `trigger_teleport_touch` | `src/game/g_trigger.c` | Direct selected body matches the retail custom teleport path: debounce gate, client vs monster spawnflag filtering, destination lookup through `G_Find` by `targetname`, `Couldn't find destination` diagnostic, unlink, destination origin copy plus `+10` z offset, velocity clear, `teleport_time`, optional teleport events, client pmove hold flags and delta-angle rebuild, `KillBox`, and relink. The current `trigger_teleport_find_destination` helper is compiled into this body rather than isolated as a standalone function. | High |
| `0x10019D20` | `trigger_teleport_enable` | `src/game/g_trigger.c` | Direct selected body prints `enabled`, installs `trigger_teleport_touch`, and clears pending think state. | High |
| `0x10019D40` | `trigger_teleport_disable` | `src/game/g_trigger.c` | Direct selected body prints `disabled`, clears `touch`, and disables pending think state. | High |
| `0x10019D60` | `trigger_teleport_activate` | `src/game/g_trigger.c` | Direct selected body enables the trigger, schedules `trigger_teleport_disable`, and arms the one-frame activation timeout through `level.time + FRAMETIME`. | High |
| `0x10019D90` | `trigger_teleport_toggle` | `src/game/g_trigger.c` | Selected-created body cleanly matches the current source toggle wrapper: if `touch` is clear it enables the trigger, otherwise it disables it. | High |
| `0x10019DB0` | `SP_trigger_teleport` | `src/game/g_trigger.c` | Direct selected body validates `target`, prints `teleporter without a target.` on failure, sets trigger solidity plus `SVF_NOCLIENT`, defaults `wait = 0.2`, wires the custom `NOTOUCH` or `START_OFF` behavior, and emits the stock ignored-spawnflag diagnostics for the one-shot activation path. | High |

## `SP_trigger_*` Spawn Chain Summary

| Spawn wrapper | Retail address | Immediate retail chain | Notes |
| --- | --- | --- | --- |
| `SP_trigger_multiple` | `0x10019120` | `SP_trigger_multiple -> Touch_Multi` or `trigger_enable -> Use_Multi -> multi_trigger -> multi_wait` or `G_FreeEdict` | The stock multi-trigger root installs `Touch_Multi` by default, but the `TRIGGERED` start-off path rewires through `trigger_enable` and then `Use_Multi`. |
| `SP_trigger_once` | `0x10019210` | `SP_trigger_once -> SP_trigger_multiple -> Touch_Multi` or `Use_Multi -> multi_trigger -> G_FreeEdict` | Retail only adds the legacy `TRIGGERED` flag repair and forces `wait = -1` before reusing the multi-trigger path. |
| `SP_trigger_relay` | `0x100192B0` | `SP_trigger_relay -> trigger_relay_use -> G_UseTargets` | Thin relay wrapper with no touch path. |
| `SP_trigger_key` | `0x10019530` | `SP_trigger_key -> trigger_key_use -> G_UseTargets` | The wrapper resolves `st.item` through `FindItemByClassname`; the use path owns the key checks, feedback sounds, and coop clear logic. |
| `SP_trigger_counter` | `0x100196A0` | `SP_trigger_counter -> trigger_counter_use -> multi_trigger -> multi_wait` or `G_FreeEdict` | Counter completion falls back into the stock multi-trigger scheduler and free-once tail. |
| `SP_trigger_always` | `0x100196D0` | `SP_trigger_always -> G_UseTargets` | Direct fire after the `delay >= 0.2` clamp; no separate touch or use callback survives. |
| `SP_trigger_push` | `0x10019850` | `SP_trigger_push -> InitTrigger -> trigger_push_touch` | Shared stock trigger setup plus the push-specific touch path. |
| `SP_trigger_hurt` | `0x100199C0` | `SP_trigger_hurt -> InitTrigger -> hurt_touch` and optional `hurt_use` | `hurt_use` only survives when the retail wrapper exposes `TOGGLE` or `START_OFF` control. |
| `SP_trigger_gravity` | `0x10019A60` | `SP_trigger_gravity -> InitTrigger -> trigger_gravity_touch` | Gravity string parsing stays in the wrapper; runtime effect is only the touch callback. |
| `SP_trigger_monsterjump` | `0x10019B30` | `SP_trigger_monsterjump -> InitTrigger -> trigger_monsterjump_touch` | The wrapper applies the stock `YAW 0 -> 360` fix and stores the launch height in `movedir[2]`. |
| `SP_trigger_teleport` | `0x10019DB0` | `SP_trigger_teleport -> trigger_teleport_touch`, `trigger_teleport_activate`, `trigger_teleport_enable`, `trigger_teleport_disable`, or `trigger_teleport_toggle` | Retail keeps the custom teleport chain separate from the stock `InitTrigger` path. Destination lookup is compiled into `trigger_teleport_touch`, and `AnglesNormalize` is adjacent shared utility, not teleport-local logic. |

## Adjacent Turret Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10019E90` | `AnglesNormalize` | `src/game/g_turret.c` | Direct selected body normalizes pitch and yaw into the `[0,360)` range in place, and the recovered `turret_breach_think` body calls it twice on the current and desired angle vectors. | High |
| `0x10019F40` | `SnapToEights` | `src/game/g_turret.c` | Direct selected body multiplies by `8`, rounds half away from zero, and rescales by `0.125`; `turret_breach_think` uses it to quantize the driver position updates. | High |
| `0x10019FE0` | `turret_breach_fire` | `src/game/g_turret.c` | Direct body rebuilds the muzzle point from `move_origin` through `AngleVectors` plus three `VectorMA` steps, calls `fire_rocket`, and plays `weapons/rocklf1a.wav`. | High |
| `0x1001A100` | `turret_breach_think` | `src/game/g_turret.c` | Direct body normalizes and clamps the live and target angles, derives `avelocity`, mirrors yaw across the teamchain, updates the attached driver through `SnapToEights`, and fires when the `65536` spawnflag latch is set. | High |
| `0x1001A4B0` | `turret_breach_finish_init` | `src/game/g_turret.c` | Direct body resolves the muzzle anchor through `G_PickTarget`, stores the offset in `move_origin`, copies damage into the teammaster, then hands off into `turret_breach_think`. | High |
| `0x1001A540` | `SP_turret_breach` | `src/game/g_turret.c` | Direct body sets the BSP push setup, defaults speed and damage plus pitch/yaw limits, installs the blocked callback, then schedules `turret_breach_finish_init`. | High |
| `0x1001A670` | `SP_turret_base` | `src/game/g_turret.c` | Direct body installs the BSP push-solid turret base wrapper, links the model, and shares the same blocked callback as the breach half. | High |

## Pathing, Debug View, And Light Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x1000E670` | `SP_path_corner` | `src/game/g_misc.c` | Direct body installs the stock trigger-solid `path_corner` wrapper, emits the exact `path_corner with no targetname at %s` diagnostic, and compiles the matching `path_corner_touch` logic into the local `LAB_1000E500` tail instead of a standalone selected function. The wrapper itself stays stock, but the retail `func_rotate_train` chain later consumes the same corner edict's `wait`, `duration`, `rotate`, and `speeds` fields. | High |
| `0x1000E7E0` | `point_combat_touch` | `src/game/g_misc.c` | Direct body matches the stock combat-point touch path: `movetarget` validation, optional `G_PickTarget`, stand-ground gating, `AI_COMBAT_POINT` clear, `pathtarget` activator fallback, and `G_UseTargets`. | High |
| `0x1000E940` | `SP_point_combat` | `src/game/g_misc.c` | Direct body and raw disassembly both show the deathmatch free-edict check, trigger-solid setup, `(-8,-8,-16)` to `(8,8,16)` bounds, and `point_combat_touch` hookup. | High |
| `0x1000E9D0` | `TH_viewthing` | `src/game/g_misc.c` | Direct body increments `s.frame`, wraps modulo `7`, and schedules `nextthink = level.time + FRAMETIME`, matching the stock debug-view helper exactly. | High |
| `0x1000EA00` | `SP_viewthing` | `src/game/g_misc.c` | Direct body prints `viewthing spawned`, installs the banner model with the stock bbox, wires `TH_viewthing`, and schedules the initial `0.5` second think. | High |
| `0x1000EAA0` | `SP_info_notnull` | `src/game/g_misc.c` | Direct body copies `s.origin` into both paired bbox vectors, which is exactly the stock `SP_info_notnull` no-op world anchor wrapper. | High |
| `0x1000EAE0` | `SP_light` | `src/game/g_misc.c` | Direct body matches the stock light entity wrapper: deathmatch cleanup for untargeted lights, style threshold check, and `light_use` installation for switchable styles. | High |
| `0x1000EB60` | `light_use` | `src/game/g_misc.c` | Direct body toggles the target light style configstring between the two stock string states and flips the spawnflag bit, matching the Quake II switchable-light helper exactly. | High |

## SP_info_* Spawn Chain Summary

| Spawn wrapper | Retail signal | Immediate retail chain | Notes |
| --- | --- | --- | --- |
| `SP_info_null` | current-source spawn table only | `SP_info_null -> G_FreeEdict`; `func_group -> SP_info_null` | Present in the current spawn table as the `info_null` and `func_group` sink wrapper, but not yet isolated or string-evidenced in the committed retail corpus. |
| `SP_info_notnull` | direct body at `0x1000EAA0` | `SP_info_notnull` | Direct retail no-op anchor wrapper that copies `s.origin` into the paired bbox vectors. |
| `SP_info_teleport_dest` | retail class-name lookup inside `trigger_teleport_touch` | `SP_info_teleport_dest <- trigger_teleport_touch` | The retail custom teleport touch path prefers `info_teleport_dest` and only then falls back to `misc_teleporter_dest`, but the wrapper body itself is not yet isolated as a standalone retail start. |
| `SP_info_player_start` | retail class-name lookup inside spawn or intermission selection | `SP_info_player_start <- SelectSpawnPoint`; `SP_info_player_start <- intermission fallback search` | The retail corpus uses the classname in spawn and intermission search paths; the current source also schedules `SP_CreateCoopSpots` on `security`, but that wrapper body is not yet directly recovered in retail. |
| `SP_info_player_deathmatch` | retail class-name lookup inside deathmatch spawn selection and intermission fallback | `SP_info_player_deathmatch <- SelectRandomDeathmatchSpawnPoint` / `SelectFarthestDeathmatchSpawnPoint`; `SP_info_player_deathmatch <- intermission fallback search` | Strong retail role evidence from the spawn selectors. The current source reuses `SP_misc_teleporter_dest`, but that exact wrapper-body split is still source-side reconstruction rather than a direct retail match. |
| `SP_info_player_coop` | retail class-name lookup inside coop spawn selection | `SP_info_player_coop <- SelectCoopSpawnPoint` | The retail spawn selector walks `info_player_coop` by classname. The current source also schedules `SP_FixCoopSpots` on the stock hack-map set, but that wrapper body is not yet directly recovered in retail. |
| `SP_info_player_intermission` | retail class-name lookup inside intermission placement | `SP_info_player_intermission <- intermission search` | The retail intermission path searches this classname first, then falls back through `info_player_start` and `info_player_deathmatch`. The current wrapper is empty and the retail wrapper body is not yet isolated. |

## Misc Entity, Clock, And Teleporter Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10010200` | `SP_misc_banner` | `src/game/g_misc.c` | Direct body installs the banner model, picks a random starting frame modulo `16`, links the entity, and arms the local frame-advance think. | High |
| `0x100103F0` | `SP_misc_viper` | `src/game/g_misc.c` | Direct body validates `target`, defaults `speed` to `300`, installs the viper model plus `MOVETYPE_PUSH` bounds, wires the local reveal-or-`train_use` helper and `func_train_find`, then hides the entity with `SVF_NOCLIENT`. | High |
| `0x100104F0` | `SP_misc_bigviper` | `src/game/g_misc.c` | Direct body installs the stationary big-viper model and the large intro-scene bbox from stock Quake II. | High |
| `0x100107F0` | `SP_misc_strogg_ship` | `src/game/g_misc.c` | Direct body matches the trigger-spawned strogg ship flyby wrapper: target validation, default `300` speed, strogg ship model, `MOVETYPE_PUSH`, local reveal-or-`train_use` helper, and `func_train_find`. | High |
| `0x10010960` | `SP_misc_satellite_dish` | `src/game/g_misc.c` | Direct body installs the satellite model, the stock `(-64,-64,0)` to `(64,64,128)` bbox, and the local dish-use callback. | High |
| `0x100109D0` | `SP_light_mine1` | `src/game/g_misc.c` | Direct body installs `MOVETYPE_NONE`, `SOLID_BBOX`, the `models/objects/minelite/light1/tris.md2` model, and immediately links the entity, matching the stock mine-light wrapper exactly. | High |
| `0x10010A10` | `SP_light_mine2` | `src/game/g_misc.c` | Direct body matches the sister mine-light wrapper, swapping only the model path to `models/objects/minelite/light2/tris.md2` before link. | High |
| `0x10010A50` | `SP_misc_gib_arm` | `src/game/g_misc.c` | Direct body installs the arm gib model, `EF_GIB`, toss movement, random angular velocity, damageable gib death handling, and the timed free callback. | High |
| `0x10010B40` | `SP_misc_gib_leg` | `src/game/g_misc.c` | Direct body matches the stock leg-gib spawn wrapper with the same toss, damage, and timed free setup. | High |
| `0x10010C30` | `SP_misc_gib_head` | `src/game/g_misc.c` | Direct body matches the stock head-gib spawn wrapper with the same toss, damage, and timed free setup. | High |
| `0x10010D20` | `SP_target_character` | `src/game/g_misc.c` | Direct body sets `MOVETYPE_PUSH`, installs `self->model`, forces `SOLID_BSP`, seeds frame `12`, and links the entity. | High |
| `0x10010D60` | `target_string_use` | `src/game/g_misc.c` | Direct body walks the teamchain, uses each member `count` as a message index, and maps characters into the stock `0-9`, `-`, `:`, or blank frame set. | High |
| `0x10011000` | `func_clock_format_countdown` | `src/game/g_misc.c` | Direct body emits the stock style `0`, `1`, and `2` countdown text layouts and fixes the space-padded `mm:ss` or `hh:mm:ss` digits to `0`. | High |
| `0x10011160` | `SP_func_clock` | `src/game/g_misc.c` | Direct body validates `target` and timer-down `count`, defaults timer-up clocks to `3600`, resets state, allocates the `16` byte message buffer, and installs the local think or optional use callback. | High |
| `0x10011240` | `teleporter_touch` | `src/game/g_misc.c` | Direct body finds the destination by targetname, unlinks the client, copies origin plus `+10` z offset, clears velocity, sets teleport hold flags and delta angles, runs `KillBox`, then relinks. | High |
| `0x10011390` | `SP_misc_teleporter` | `src/game/g_misc.c` | Direct body validates `target`, installs the dmspot model, teleporter effect and ambient sound, then spawns the trigger entity that routes into `teleporter_touch`. | High |
| `0x100114A0` | `SP_misc_teleporter_dest` | `src/game/g_misc.c` | Direct body installs the dmspot destination model and the stock teleporter-destination bbox. | High |

## SP_misc_* Spawn Chain Summary

| Spawn wrapper | Retail address | Immediate retail chain | Notes |
| --- | --- | --- | --- |
| `SP_misc_banner` | `0x10010200` | `SP_misc_banner -> misc_banner_think` | The animated banner wrapper is direct, but the frame-advance think still lives as an embedded retail local rather than a standalone selected function. |
| `SP_misc_viper` | `0x100103F0` | `SP_misc_viper -> local reveal/use helper -> train_use`; `SP_misc_viper -> func_train_find` | Trigger-spawned flyby chain. The retail local use helper unhides the ship and hands off into the stock train mover path. |
| `SP_misc_bigviper` | `0x100104F0` | `SP_misc_bigviper` | Standalone intro-scene prop wrapper with no meaningful secondary helper chain in the committed retail corpus. |
| `SP_misc_strogg_ship` | `0x100107F0` | `SP_misc_strogg_ship -> local reveal/use helper -> train_use`; `SP_misc_strogg_ship -> func_train_find` | Same retail mover wiring pattern as `SP_misc_viper`, but for the Strogg ship model and diagnostics. |
| `SP_misc_satellite_dish` | `0x10010960` | `SP_misc_satellite_dish -> local dish-use callback` | Fixed set-piece wrapper with an embedded use callback that drives the dish animation. |
| `SP_misc_gib_arm` | `0x10010A50` | `SP_misc_gib_arm -> gib_die`; `SP_misc_gib_arm -> G_FreeEdict` | Damageable toss-gib wrapper with the stock timed self-free path. |
| `SP_misc_gib_leg` | `0x10010B40` | `SP_misc_gib_leg -> gib_die`; `SP_misc_gib_leg -> G_FreeEdict` | Same retail toss-gib chain as the arm wrapper. |
| `SP_misc_gib_head` | `0x10010C30` | `SP_misc_gib_head -> gib_die`; `SP_misc_gib_head -> G_FreeEdict` | Same retail toss-gib chain as the other gib wrappers. |
| `SP_misc_teleporter` | `0x10011390` | `SP_misc_teleporter -> teleporter_touch` | Spawns a separate trigger entity and routes player touch into the stock teleporter helper. |
| `SP_misc_teleporter_dest` | `0x100114A0` | `SP_misc_teleporter_dest` | Destination-only wrapper with no secondary helper chain beyond the placed destination entity. |
| `SP_misc_actor` | `0x1001F460` | `SP_misc_actor -> actor_use`; `SP_misc_actor -> actor_stand` / `actor_walk` / `actor_run` / `actor_attack` | Lives in `src/game/m_actor.c`, but it is part of the retail `misc_*` spawn surface and is already mapped through its actor-specific callback table. |

Current-source wrappers `SP_misc_explobox`, `SP_misc_deadsoldier`, `SP_misc_viper_bomb`, `SP_misc_blackhole`, `SP_misc_eastertank`, `SP_misc_easterchick`, `SP_misc_easterchick2`, and `SP_misc_screenfader` are not yet isolated as stable retail function starts in the committed Ghidra corpus. `misc_explobox` does have classname-string evidence in the retail binary, but that is still weaker than a direct wrapper-body match.

## Entity Utility And Target Resolution

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x1001AC00` | `G_Find` | `src/game/g_utils.c` | Iterates edicts from `from + 1`, compares string field at requested offset, returns first match. | High |
| `0x1001ACA0` | `findradius` | `src/game/g_utils.c` | Iterates solid in-use edicts and returns the first entity within radius of a point. | High |
| `0x1001AD80` | `G_PickTarget` | `src/game/g_utils.c` | Collects up to 8 matches through `G_Find`, warns on NULL targetname, logs `target %s not found`, and returns a random choice. | High |
| `0x1001AE00` | `Think_Delay` | `src/game/g_utils.c` | Direct body is the exact delayed-use thunk: `G_UseTargets(ent, ent->activator)` followed by `G_FreeEdict(ent)`. | High |
| `0x1001AE20` | `G_UseTargets` | `src/game/g_utils.c` | Direct body covers delayed-use spawning, centerprint or sound dispatch, killtarget frees, and the target-use loop with the stock self-use warning and `func_areaportal` skip. | High |
| `0x1001B040` | `tv` | `src/game/g_utils.c` | Direct body rotates through an 8-slot temporary vector ring and writes the three requested components. | High |
| `0x1001B070` | `vtos` | `src/game/g_utils.c` | Uses an 8-slot rotating string buffer and integer vector formatting; used in coordinate diagnostics. | High |
| `0x1001B0C0` | `G_SetMovedir` | `src/game/g_utils.c` | Direct body matches the stock `VEC_UP` / `VEC_DOWN` special cases, otherwise delegates to `AngleVectors`, then clears the original angle vector. | High |
| `0x1001B1E0` | `vectoangles` | `src/game/g_utils.c` | Direct body converts a vector into Quake-style pitch/yaw with the vertical special case and negated pitch exactly like current `g_utils.c`. | High |
| `0x1001B310` | `G_InitEdict` | `src/game/g_utils.c` | Marks edict in use, sets classname to `noclass`, gravity to `1.0`, and computes `s.number`. | High |
| `0x1001B350` | `G_Spawn` | `src/game/g_utils.c` | Scans for reusable free edicts, enforces no-free-edicts error, increments `globals.num_edicts`, then calls `G_InitEdict`. | High |
| `0x1001B400` | `G_FreeEdict` | `src/game/g_utils.c` | Unlinks entity, clears body, sets classname `freed`, stores freetime, and marks not in use. | High |
| `0x1001B510` | `KillBox` | `src/game/g_utils.c` | Direct body loops a `MASK_PLAYERSOLID` bbox trace at the entity origin, telefrags blockers through the stock `T_Damage(..., DAMAGE_NO_PROTECTION, MOD_TELEFRAG)` path, and returns failure only when the occupant survives. | High |

## Item Lookup, Pickup, Armor, Respawn, And Spawn Flow

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x1000B0E0` | `GetItemByIndex` | `src/game/g_items.c` | Direct body returns `NULL` for index `0` or out-of-range values and otherwise indexes directly into `itemlist`. | High |
| `0x1000B100` | `FindItemByClassname` | `src/game/g_items.c` | Direct body walks `itemlist`, compares `classname`, and returns the matched item pointer or `NULL`. | High |
| `0x1000B150` | `FindItem` | `src/game/g_items.c` | Direct body walks `itemlist`, compares `pickup_name`, and returns the matched item pointer or `NULL`. | High |
| `0x1000B1A0` | `DoRespawn` | `src/game/g_items.c` | Direct body chooses a team-chain respawn target when needed, clears `SVF_NOCLIENT`, restores trigger solidity, relinks, and emits the item-respawn event. | High |
| `0x1000B210` | `SetRespawn` | `src/game/g_items.c` | Direct body sets `FL_RESPAWN`, hides the item, stores `nextthink = level.time + delay`, installs `DoRespawn`, and relinks. | High |
| `0x1000B270` | `Pickup_Powerup` | `src/game/g_items.c` | Direct body applies skill and coop stay checks, increments inventory, respawns non-dropped pickups, and auto-uses timed pickups such as quad on the expected deathmatch path. | High |
| `0x1000B3C0` | `Drop_General` | `src/game/g_items.c` | Direct body calls `Drop_Item`, decrements the carried item slot, and finishes through `ValidateSelectedItem`. | High |
| `0x1000B410` | `Pickup_Adrenaline` | `src/game/g_items.c` | Direct body raises `max_health` outside deathmatch, heals up to the new maximum, and respawns non-dropped pickups in deathmatch. | High |
| `0x1000B490` | `Pickup_AncientHead` | `src/game/g_items.c` | Direct body raises `max_health` by `2` and respawns non-dropped pickups in deathmatch. | High |
| `0x1000B4F0` | `Pickup_Bandolier` | `src/game/g_items.c` | Direct body raises `max_bullets=250`, `max_shells=150`, `max_cells=250`, and `max_slugs=75`, grants bundled `Bullets` and `Shells` only, and respawns the pickup; no retail plasma, mine, detpack, or DOD cap/grant path surfaced here. | High |
| `0x1000B650` | `Pickup_Pack` | `src/game/g_items.c` | Direct body raises `max_bullets=300`, `max_shells=200`, `max_rockets=100`, `max_grenades=100`, `max_mines=10`, `max_cells=300`, `max_slugs=100`, `max_detpacks=5`, and `max_dods=2`, grants bundled `Bullets`, `Shells`, `Cells`, `Grenades`, `Rockets`, and `Slugs` only, and respawns the pickup. | High |
| `0x1000B990` | `Use_Quad` | `src/game/g_items.c` | Direct body decrements the inventory slot, applies the retail dropped-quad timeout hack when present, extends or starts `quad_framenum`, and plays `items/damage.wav`. | High |
| `0x1000BA60` | `Use_Breather` | `src/game/g_items.c` | Direct body decrements inventory, validates selection, and extends or starts `breather_framenum` by the stock 300-frame window. | High |
| `0x1000BAF0` | `Use_Envirosuit` | `src/game/g_items.c` | Direct body decrements inventory, validates selection, and extends or starts `enviro_framenum` by the stock 300-frame window. | High |
| `0x1000BB80` | `Use_Invulnerability` | `src/game/g_items.c` | Direct body decrements inventory, validates selection, extends or starts `invincible_framenum`, and plays `items/protect.wav`. | High |
| `0x1000BC30` | `Use_Silencer` | `src/game/g_items.c` | Direct body decrements inventory, validates selection, and adds `30` shots to the client silencer counter. | High |
| `0x1000BC90` | `Pickup_Key` | `src/game/g_items.c` | Direct body handles coop key uniqueness, special-cases `key_power_cube` through the `power_cubes` bitfield, and otherwise increments the carried key slot. | High |
| `0x1000BDF0` | `Add_Ammo` | `src/game/g_items.c` | Direct body maps ammo tags through the extended retail max-ammo fields, clamps inventory to the per-ammo maximum, and returns false when already full. | High |
| `0x1000BEF0` | `Pickup_Ammo` | `src/game/g_items.c` | Direct body computes pickup count from the item, `count`, and infinite-ammo rules, then calls `Add_Ammo`, auto-switches from the default pistol path, and respawns non-dropped pickups. | High |
| `0x1000C010` | `Drop_Ammo` | `src/game/g_items.c` | Direct body spawns the dropped ammo entity through `Drop_Item`, clips the dropped count to carried inventory, blocks dropping the last live grenade ammo when grenades are equipped, then decrements inventory and validates the selection. | High |
| `0x1000C0E0` | `MegaHealth_think` | `src/game/g_items.c` | Direct body drains over-max health back toward `max_health`, then either schedules an item respawn or frees the mega-health edict. | High |
| `0x1000C150` | `Pickup_Health` | `src/game/g_items.c` | Direct body applies ignore-max and timed-health style flags, heals by `count`, selects the matching health sound, and installs `MegaHealth_think` for mega-health pickups. | High |
| `0x1000C290` | `ArmorIndex` | `src/game/g_items.c` | Direct body returns the first owned armor slot in the expected jacket/combat/body priority order cached by `SetItemNames`. | High |
| `0x1000C2E0` | `Pickup_Armor` | `src/game/g_items.c` | Direct body matches the shard-vs-regular armor pickup logic, including salvage and replacement against the currently equipped armor class. | High |
| `0x1000C460` | `PowerArmorType` | `src/game/g_items.c` | Direct body checks the active power-armor flag and then distinguishes between owned power shield and power screen inventory. | High |
| `0x1000C4B0` | `Use_PowerArmor` | `src/game/g_items.c` | Direct body toggles `FL_POWER_ARMOR`, requires cells before enabling, prints `No cells for power armor.`, and plays the expected toggle sounds. | High |
| `0x1000C560` | `Pickup_PowerArmor` | `src/game/g_items.c` | Direct body increments the power-armor inventory slot, respawns non-dropped pickups, and auto-uses the item on the first deathmatch pickup. | High |
| `0x1000C5F0` | `Drop_PowerArmor` | `src/game/g_items.c` | Direct body disables active power armor before the last shield or screen is dropped, then falls through to `Drop_General`. | High |
| `0x1000C650` | `Touch_Item` | `src/game/g_items.c` | Direct body gates on live clients, runs the item's `pickup` callback, stamps pickup HUD state and sounds, fires targets once, and frees or preserves the edict according to coop and dropped-item rules. | High |
| `0x1000C850` | `Drop_Item` | `src/game/g_items.c` | Direct body spawns the dropped item edict, installs the dropped-item flags and touch/think handlers, projects the toss origin from player view when the owner is a client, then links the tossed entity. | High |
| `0x1000CA10` | `drop_temp_touch` | `src/game/g_items.c` | Direct body ignores the owner on the first touch window and otherwise forwards to `Touch_Item`. | High |
| `0x1000CA40` | `drop_make_touchable` | `src/game/g_items.c` | Direct body restores `Touch_Item` and, in deathmatch, arms the dropped item to free itself after the stock timeout. | High |
| `0x1000CA80` | `Use_Item` | `src/game/g_items.c` | Direct body clears `SVF_NOCLIENT`, disables `use`, and restores either trigger-touch or bbox/no-touch behavior depending on `ITEM_NO_TOUCH`. | High |
| `0x1000CAE0` | `droptofloor` | `src/game/g_items.c` | Direct body installs mins/maxs, resolves the floor trace, handles team or trigger-spawn flags, and links the final spawned item or frees it on `startsolid`. | High |
| `0x1000CD00` | `PrecacheItem` | `src/game/g_items.c` | Direct body precaches pickup sounds, world and view models, icon, recursive ammo dependencies, and parses the tokenized `precache` string for model, sound, and image assets. | High |
| `0x1000CF20` | `SpawnItem` | `src/game/g_items.c` | Direct body calls `PrecacheItem`, validates spawnflags, filters items by deathmatch and coop rules, stores the item pointer, and schedules the standard drop-to-floor think. | High |
| `0x1000D160` | `SP_item_health` | `src/game/g_items.c` | Direct body applies the deathmatch health filter, installs the medium-health model and count, calls `SpawnItem(FindItem(\"Health\"))`, and precaches the normal health sound. | High |
| `0x1000D1D0` | `SP_item_health_small` | `src/game/g_items.c` | Direct body applies the deathmatch health filter, installs the stimpack model and count `2`, calls `SpawnItem(FindItem(\"Health\"))`, sets `HEALTH_IGNORE_MAX`, and precaches the small-health sound. | High |
| `0x1000D250` | `SP_item_health_large` | `src/game/g_items.c` | Direct body applies the deathmatch health filter, installs the large-health model and count `25`, calls `SpawnItem(FindItem(\"Health\"))`, and precaches the large-health sound. | High |
| `0x1000D2C0` | `SP_item_health_mega` | `src/game/g_items.c` | Direct body applies the deathmatch health filter, installs the mega-health model and count `100`, calls `SpawnItem(FindItem(\"Health\"))`, sets `HEALTH_IGNORE_MAX | HEALTH_TIMED`, and precaches the mega-health sound. | High |
| `0x1000D340` | `InitItems` | `src/game/g_items.c` | Tiny direct body sets `game.num_items = ARRAY_COUNT(itemlist) - 1`. | High |
| `0x1000D350` | `SetItemNames` | `src/game/g_items.c` | Direct body writes all pickup names into configstrings and caches the jacket/combat/body plus power-screen/power-shield item indices used by later item helpers. | High |
| `0x10035260` | `Pickup_Weapon` | `src/game/p_weapon.c` | Direct body enforces weapons-stay and coop rules, increments the weapon slot, gives ammo through `FindItem` plus `Add_Ammo`, special-cases `weapon_hellfury` to grant `16` rockets on pickup, sets respawn or `FL_RESPAWN`, and auto-selects the pickup from the default `Plasma Pistol` path. | High |
| `0x10035DB0` | `P_ProjectSource` | `src/game/p_weapon.c` | Direct body applies the handedness adjustment to the weapon offset, then forwards to the shared projectile-source helper. | High |

## Server Admin And IP Filter Commands

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x100173E0` | `SV_FilterPacket` | `src/game/g_svcmds.c` | Parses IP octets, checks filter list, returns filterban-style allow/deny result; called from `ClientConnect`. | High |
| `0x10017490` | `SVCmd_AddIP_f` | `src/game/g_svcmds.c` | Prints `Usage:  addip <ip-mask>`, looks for a free filter slot, and calls `StringToFilter`. | High |
| `0x10017520` | `StringToFilter` | `src/game/g_svcmds.c` | Parses dotted quad, emits `Bad filter address: %s`, fills mask/compare pair. | High |
| `0x100175D0` | `SVCmd_RemoveIP_f` | `src/game/g_svcmds.c` | Prints `Usage:  sv removeip <ip-mask>`, removes exact mask/compare match, emits `Removed.` or `Didn't find %s.` | High |
| `0x100176B0` | `SVCmd_ListIP_f` | `src/game/g_svcmds.c` | Prints `Filter list:` and each dotted IP line. | High |
| `0x10017730` | `SVCmd_WriteIP_f` | `src/game/g_svcmds.c` | Writes `listip.cfg`, prints `Writing %s.` / `Couldn't open %s`, emits `set filterban` and `sv addip` lines. | High |
| `0x100173C0` | `Svcmd_Test_f` | `src/game/g_svcmds.c` | Direct helper body is a single `gi.cprintf(NULL, PRINT_HIGH, "Svcmd_Test_f()")`. | High |
| `0x10017850` | `ServerCommand` | `src/game/g_svcmds.c` | Direct dispatcher body matches stock Quake II `ServerCommand`: `test`, `addip`, `removeip`, `listip`, `writeip`, else `Unknown server command`. | High |

## Client Command Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10003DF0` | `SelectNextItem` | `src/game/g_cmds.c` | Direct body advances `selected_item` across inventory entries filtered by item flags, with no stock chase-target special case in the retail loop. | High |
| `0x10003E70` | `SelectPrevItem` | `src/game/g_cmds.c` | Direct body walks backward across inventory entries filtered by item flags, with no stock chase-target special case in the retail loop. | High |
| `0x10003EF0` | `ValidateSelectedItem` | `src/game/g_cmds.c` | Direct body checks whether the selected inventory slot is valid and falls back to `SelectNextItem`. | High |
| `0x10003F20` | `Cmd_Give_f` | `src/game/g_cmds.c` | Direct body matches cheat-gated give logic for health, weapons, ammo, armor, power shield, plasma rifle, and arbitrary item grant/spawn. | High |
| `0x10004350` | `Cmd_God_f` | `src/game/g_cmds.c` | Direct body toggles the godmode flag and prints `godmode ON/OFF`. | High |
| `0x100043D0` | `Cmd_Notarget_f` | `src/game/g_cmds.c` | Direct body toggles the notarget flag and prints `notarget ON/OFF`. | High |
| `0x10004450` | `Cmd_Noclip_f` | `src/game/g_cmds.c` | Direct body toggles between walk and noclip movetypes with the expected printouts. | High |
| `0x10004560` | `Cmd_Use_f` | `src/game/g_cmds.c` | Direct body resolves the requested item, including retail weapon-name alias swaps, and invokes the item's `use` callback. | High |
| `0x10004750` | `Cmd_UseToggle_ParseName` | `src/game/g_cmds.c` | Direct helper is called twice from `Cmd_UseToggle_f`; it consumes apostrophe-delimited multi-argv item names into the retail 64-byte scratch buffer, including the unterminated-quote path that leaves the trailing separator intact. The current source mirrors that helper directly as `Cmd_UseToggle_ParseName`, with `Cmd_UseToggle_AppendToken` kept as source-side factoring. | High |
| `0x10004870` | `Cmd_UseToggle_f` | `src/game/g_cmds.c` | Direct body walks the command arguments, uses apostrophe-delimited multi-argv item parsing for names like `'Rocket Launcher'`, finds the currently equipped usable requested item, then cycles until a requested item actually lands in `newweapon`; the retail `ClientCommand` dispatcher keys it from `usetoggle`. | High |
| `0x100049B0` | `Cmd_Drop_f` | `src/game/g_cmds.c` | Direct body resolves the requested item, checks `drop`, checks inventory count, and invokes the drop callback. | High |
| `0x10004A60` | `Cmd_Inven_f` | `src/game/g_cmds.c` | Direct body toggles inventory display, clears help/score screens, and unicasts the inventory packet. | High |
| `0x10004AD0` | `Cmd_InvUse_f` | `src/game/g_cmds.c` | Direct body validates the selected slot, checks usability, and invokes the selected item's `use` callback. | High |
| `0x10004B30` | `Cmd_WeapPrev_f` | `src/game/g_cmds.c` | Direct body cycles forward through owned weapons until a successful `use` changes the active weapon. | High |
| `0x10004BC0` | `Cmd_WeapNext_f` | `src/game/g_cmds.c` | Direct body cycles backward through owned weapons until a successful `use` changes the active weapon. | High |
| `0x10004C60` | `Cmd_WeapLast_f` | `src/game/g_cmds.c` | Direct body switches back to `lastweapon` if it is still owned and usable. | High |
| `0x10004CD0` | `Cmd_InvDrop_f` | `src/game/g_cmds.c` | Direct body validates the selected slot, checks `drop`, and invokes the selected item's drop callback. | High |
| `0x10004D30` | `Cmd_Kill_f` | `src/game/g_cmds.c` | Direct body enforces respawn delay, clears godmode, sets suicide MOD, and kills the player. | High |
| `0x10004D90` | `Cmd_PutAway_f` | `src/game/g_cmds.c` | Direct body clears score/help/inventory display flags. | High |
| `0x10004E10` | `Cmd_Players_f` | `src/game/g_cmds.c` | Direct body gathers connected clients, sorts them, formats frag/name lines, and prints the player summary. | High |
| `0x10004FA0` | `Cmd_Wave_f` | `src/game/g_cmds.c` | Direct body parses the wave index, prints the gesture name, and sets animation frame ranges. | High |
| `0x100050C0` | `Cmd_Say_f` | `src/game/g_cmds.c` | Direct body handles team/global chat, quote stripping, flood protection, dedicated-server echo, and recipient filtering. | High |
| `0x10005450` | `Cmd_PlayerList_f` | `src/game/g_cmds.c` | Direct body formats connect time, ping, score, spectator state, and name for each active client. | High |
| `0x10032AE0` | `Cmd_Score_f` | `src/game/p_hud.c` | Direct body is the expected score display toggle helper used by `ClientCommand`. | High |
| `0x10032C20` | `Cmd_Help_f` | `src/game/p_hud.c` | Direct body is the expected help/inventory/score UI toggle helper used by `ClientCommand`. | High |

## Client Lifecycle And Session Setup

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10030460` | `InitClientPersistant` | `src/game/p_client.c` | Direct body clears the persistent client block, seeds the default `Plasma Pistol` plus `PistolPlasma` loadout, restores health/max-health caps, copies the retail max-ammo defaults `200/100/50/50/25/200/50/50/50/10/2` into `+0x6E4..+0x70C`, zeros `pers.plasma_rifle_regen_divisor @ +0x710`, and marks the client connected. | High |
| `0x10030560` | `InitClientResp` | `src/game/p_client.c` | Clears respawn block then copies persistent state into `coop_respawn`. | High |
| `0x10031070` | `PutClientInServer` | `src/game/p_client.c` | Selected-function pass recovered the full retail body: spawn selection, persistent/respawn rebuild, entity setup, model/bbox/origin init, and spectator handling, with no special carry-over of the plasma regen timers at `client + 0xF2C/+0xF30`. | High |
| `0x10031610` | `ClientBegin` | `src/game/p_client.c` | Direct body resolves `ent->client`, branches to deathmatch/loadgame/fresh-spawn handling, applies intermission movement if needed, and finishes with `ClientEndServerFrame`. | High |
| `0x10031760` | `ClientUserinfoChanged` | `src/game/p_client.c` | Handles name/skin/spectator/fov/hand/userinfo updates; called from `ClientConnect`. | High |
| `0x10031950` | `ClientConnect` | `src/game/p_client.c` | Banned-IP check, spectator/password validation, `connected` print, persistent-state init. | High |
| `0x10031C30` | `ClientDisconnect` | `src/game/p_client.c` | Logout effect, unlink, clear model/solid state, clear skin configstring. | High |
| `0x10031D70` | `ClientThink` | `src/game/p_client.c` | Direct body covers player or spectator pmove, trigger touches, button-edge tracking, attack-thunk dispatch, and the plasma-regen tail; the recovered retail body does not surface the stock chase-camera attack/jump or follower-update branches. | High |

## Death, Respawn, Spectator, And Retail-Only Camera Support

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10030160` | `player_die` | `src/game/p_client.c` | Direct body handles death cleanup, obituary flow, gib-vs-normal death branching, death animations, and the final `DEAD_DEAD` transition. | High |
| `0x10030B40` | `CopyToBodyQue` | `src/game/p_client.c` | Direct body rotates `level.body_que`, copies the dead player state into the queued corpse edict, installs `body_die`, and relinks the body. | High |
| `0x10030CD0` | `respawn` | `src/game/p_client.c` | Direct body follows the deathmatch/coop path, skips body-queue creation for noclip spectators, clears `SVF_NOCLIENT`, calls `PutClientInServer`, and applies the teleport hold state; otherwise it issues `menu_loadgame`. | High |
| `0x10030D60` | `spectator_respawn` | `src/game/p_client.c` | Direct body validates spectator and player passwords, enforces `maxspectators`, writes back `spectator 0` / `spectator 1`, calls `PutClientInServer`, and prints the expected join/spectator messages. | High |
| `0x10037CD0` | `Oblivion_UpdateWeaponRegen` | `src/game/p_weapon.c` | Direct body checks `client->plasma_pistol_next_regen + 1.0 < level.time`, increments `PistolPlasma` up to `pers.max_pistolplasma`, then uses `pers.plasma_rifle_regen_divisor` to gate `Rifle Plasma` regeneration before storing the current time back to `+0xF2C` / `+0xF30`; the recovered `ClientThink @ 0x10031D70` calls it in the post-attack thunk tail with no separate chase-camera branch in that control flow. | High |
| `0x10002CA0` | `dummy_body` pose-sync helper | `src/game/g_camera.c` `DummyBody_Sync` | Direct body copies `s.origin`, `s.angles`, `s.modelindex`, `s.modelindex2`, `s.frame`, `velocity`, and `avelocity` from the player into the client-owned helper edict, then relinks it; the recovered `ClientEndServerFrame` tail and the setup helper both route through this body, and the current source now mirrors that exact field set through `DummyBody_Sync()`. | High |
| `0x10002D40` | `dummy_body` spawn/setup helper | `src/game/g_camera.c` `DummyBody_Setup` | Direct body unconditionally spawns a fresh `dummy_body` edict, stores it in client slot `0xF14`, sets the active flag at `0xF0C`, applies `SVF_NOCLIENT` to the live player, relinks the player, copies the player bbox into the helper, and then calls `0x10002CA0`; the current source now mirrors that retail order through `DummyBody_Setup()` plus `DummyBody_Sync()`. | High |
| `0x10002DE0` | `dummy_body` teardown helper | `src/game/g_camera.c` `DummyBody_Teardown`, `RemoteView_End` | Direct body reads the stored helper edict from client slot `0xF14`, clears that slot plus the active flag at `0xF0C`, restores the player `SVF_NOCLIENT` bit, relinks the player, and frees the helper edict; the current source now routes that teardown through `DummyBody_Teardown()` inside `RemoteView_End()`. | High |
| `0x10002E20` | remote-view client-state sync helper | `src/game/g_camera.c` `RemoteView_ApplyClientState` | Direct body copies the tracked entity origin into `ps.pmove.origin`, copies tracked angles into `ps.viewangles`, feeds client slots `0xF1C` / `0xF20` / `0xF24` back into `ps.viewoffset`, and forces `PM_FREEZE`; `ClientEndServerFrame @ 0x10034D80` calls it immediately before `0x10002CA0`, so the current source keeps the behavioral alias `RemoteView_ApplyClientState()`. | High |

Related medium-confidence retail-only support cluster: `0x10002F20`, `0x100142E0`, `0x10014320`, `0x10014530`, and `0x100145C0`. Current call/data relationships keep these near the same dummy-body or spectator-support subsystem, but there is not enough source-side evidence yet for stable names.

## Recovered Helper Callees

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10001000` | `AI_SetSightClient` | `src/game/g_ai.c` | Direct body rotates the sight-client pointer through active, living, targetable clients; this is the first callee in `G_RunFrame`. | High |
| `0x10001090` | `ai_move` | `src/game/g_ai.c` | Direct tiny wrapper forwards exactly to `M_walkmove(self, self->s.angles[YAW], dist)`, matching stock Quake II `ai_move` without extra retail logic. | High |
| `0x100010B0` | `ai_stand_idle_helper` | `src/game/g_ai.c` | Direct compiler-split local behind the retail stand wrapper: it gates the randomized idle callback, updates the idle timer, and returns a boolean-like status consumed by both `ai_stand_tail` and the full `ai_stand` wrapper. | High |
| `0x10001170` | `ai_stand_tail` | `src/game/g_ai.c` | Direct adjacent helper handles the no-dist, non-`AI_GOOD_GUY` stand path: enemy yawing plus `M_ChangeYaw`/`ai_checkattack`, then the `FindTarget`/`pausetime`/idle-timer tail. The now-recovered full wrapper at `0x10001220` explicitly tail-calls this body for the `AI_GOOD_GUY` branch, so `0x10001170` is no longer the best fit for the full source-level `ai_stand` symbol. | High |
| `0x10001220` | `ai_stand` | `src/game/g_ai.c` | Direct created body now matches the full retail `ai_stand` wrapper used by the Cyborg and Kigrax stand tables: optional `dist` movement through `M_walkmove`, an `AI_GOOD_GUY` fast path into `ai_stand_tail`, the stock `AI_STAND_GROUND` / `AI_TEMP_STAND_GROUND` release logic with `run()`, then the normal `FindTarget`, `pausetime`, and idle-helper flow. | High |
| `0x10001350` | `ai_walk` | `src/game/g_ai.c` | Direct body opens with `M_MoveToGoal(self, dist)`, then follows the stock `FindTarget` and search-idle timer flow; retail adds an early actor-follow-style flag branch, but the wrapper still matches the current and stock `ai_walk` role closely enough to promote. | High |
| `0x10001430` | `ai_charge` | `src/game/g_ai.c` | Direct body computes the enemy delta, writes `ideal_yaw` through `vectoyaw`, calls `M_ChangeYaw`, and optionally advances through `M_walkmove(self, self->s.angles[YAW], dist)`, matching stock `ai_charge` exactly. | High |
| `0x100014A0` | `ai_turn` | `src/game/g_ai.c` | Direct body optionally performs the tiny `dist` move through `M_walkmove`, calls `FindTarget`, and only falls through to `M_ChangeYaw` when no target is acquired, which matches stock `ai_turn`. | High |
| `0x100014E0` | `range` | `src/game/g_ai.c` | Direct body computes the origin delta, feeds it through `VectorLength`, and returns the stock `RANGE_MELEE` / `RANGE_NEAR` / `RANGE_MID` / `RANGE_FAR` ladder from the expected distance thresholds. | High |
| `0x10001560` | `visible` | `src/game/g_ai.c` | Direct body traces from `self` eye height to `other` eye height and returns true only when the trace fraction reaches `1.0`; the same predicate shape is used by the actor idle-follow helpers, `FindTarget`, `PlayerTrail_LastSpot`, and monster combat code. | High |
| `0x10001600` | `infront` | `src/game/g_ai.c` | Direct body builds the forward basis through `AngleVectors`, normalizes the delta to `other`, and applies the stock `DotProduct(vec, forward) > 0.3` sight-cone test. | High |
| `0x10001690` | `Actor_EngageEnemy` | `src/game/g_ai.c` | Direct body copies `enemy` into the follow or goal slot, dispatches the stand or run callback based on `AI_STAND_GROUND`, recomputes `ideal_yaw` from the enemy delta, and schedules the initial attack cooldown when not standing ground. | High |
| `0x10001730` | `Actor_FindEnemyTarget` | `src/game/g_ai.c` | Direct body scans all edicts for the nearest visible hostile monster while the caller is in the actor path-idle or friendly branch, clears the retail follow flag, sets `enemy`, updates `ideal_yaw`, and then hands off to `Actor_EngageEnemy`. | High |
| `0x10001880` | `Actor_IsPlayerFollowTarget` | `src/game/g_ai.c` | Direct body accepts a direct `player` classname or recursively walks the retail `AI_ACTOR_FOLLOW` chain up to depth `10` while rejecting cycles; `Actor_FindFollowTarget` uses it as its candidate predicate. | High |
| `0x10001910` | `Actor_FindFollowTarget` | `src/game/g_ai.c` | Direct body reuses an existing follow target when valid or scans for the nearest visible player or follow-chain target, then sets `goalentity` and `movetarget`, enables `AI_ACTOR_FOLLOW`, and chooses walk vs stand by distance. | High |
| `0x10001AC0` | `FoundTarget` | `src/game/g_ai.c` | Direct body updates `level.sight_entity` for player enemies, seeds `show_hostile`, copies `last_sighting`, handles `combattarget` through `G_PickTarget`, and otherwise falls back through the retail `Actor_EngageEnemy` helper instead of a separate stock-style `HuntTarget` body. | High |
| `0x10001BC0` | `FindTarget` | `src/game/g_ai.c` | Direct body covers the stock sight or sound target selection rules, `AI_GOOD_GUY` and `AI_COMBAT_POINT` early-outs, actor-idle follow branches, `range` / `visible` / `infront` gating, and the final handoff into `FoundTarget`. | High |
| `0x10001F00` | `FacingIdeal` | `src/game/g_ai.c` | Direct body applies the stock wrapped-yaw tolerance check and returns true only when `self->s.angles[YAW]` is within the expected forward cone of `ideal_yaw`; `ai_run_melee` and `ai_run_missile` use it exactly at the stock post-turn gate. | High |
| `0x10002190` | `ai_run_melee` | `src/game/g_ai.c` | Direct body copies `enemy_yaw` into `ideal_yaw`, calls `M_ChangeYaw`, and only dispatches the monster `melee` callback when `FacingIdeal` succeeds, then restores `AS_STRAIGHT`. | High |
| `0x100021D0` | `ai_run_missile` | `src/game/g_ai.c` | Direct body mirrors the stock missile path: set `ideal_yaw`, call `M_ChangeYaw`, gate on `FacingIdeal`, then dispatch the monster `attack` callback and restore `AS_STRAIGHT`. | High |
| `0x10002210` | `ai_run_slide` | `src/game/g_ai.c` | Direct body copies `enemy_yaw`, calls `M_ChangeYaw`, picks `+/-90` by the `lefty` flag, tries one lateral `M_walkmove`, flips `lefty` on failure, and retries on the opposite side. | High |
| `0x100022A0` | `ai_checkattack` | `src/game/g_ai.c` | Direct body handles sound-target timeout cleanup, dead-enemy and `oldenemy` fallback, seeds the global `enemy_vis` / `enemy_infront` / `enemy_range` / `enemy_yaw` state through `visible`, `infront`, `range`, and `vectoyaw`, then dispatches `ai_run_melee`, `ai_run_missile`, or the monster-specific `checkattack` callback. | High |
| `0x10002530` | `ai_run` | `src/game/g_ai.c` | Direct selected decomp matches the stock run-state wrapper: `AI_COMBAT_POINT` falls straight into `M_MoveToGoal`, the sound-target branch measures enemy distance through `VectorLength`, `ai_checkattack` gates the normal combat path, `AS_SLIDING` routes into `ai_run_slide`, and the chase tail preserves the stock `M_MoveToGoal` / last-sighting logic. The raw Kigrax frame tables now also point their sight and run moves at this exact `aifunc` with distances `10` and `15`. | High |
| `0x10011C70` | `AttackFinished` | `src/game/g_monster.c` | Direct body stores `level.time + time` into the monster attack-cooldown slot; `Actor_EngageEnemy` uses it at the exact stock randomized first-attack site. | High |
| `0x10011C90` | `M_CheckGround` | `src/game/g_monster.c` | Direct body traces downward, rejects steep planes or upward velocity, otherwise snaps the monster to ground and copies `groundentity` / `linkcount`. | High |
| `0x10014180` | `G_RunEntity` | `src/game/g_phys.c` | Direct body runs `prethink` if present, then dispatches to movetype-specific physics handlers exactly like stock Quake II `SV_Physics_*`. | High |
| `0x1001C1C0` | `check_dodge` | `src/game/g_weapon.c` | Direct body traces from the projectile start along the launch vector, requires a live monster target with a dodge callback, measures travel distance through `VectorLength`, and calls the monster dodge routine with the expected ETA `(distance - target->maxs[0]) / speed`. | High |
| `0x1001EEB0` | `actor_stand` | `src/game/m_actor.c` | Direct body installs the actor stand `mmove_t` and randomizes the startup frame within that stand range while `level.time < 1.0`, matching the current retail-aware idle wrapper. | High |
| `0x1001EF00` | `actor_walk` | `src/game/m_actor.c` | Tiny direct wrapper that only installs the actor walk `mmove_t`, matching the current `misc_actor` walk callback. | High |
| `0x1001EF10` | `actor_run` | `src/game/m_actor.c` | Direct body mirrors the current retail-aware source: it keeps the run move while pain debounce or an enemy is active, otherwise falls back through `movetarget` into the actor walk or stand callback. | High |
| `0x1001EF70` | `actor_pain` | `src/game/m_actor.c` | Direct body enforces the actor pain debounce, special-cases client attackers into the retail talk or taunt branch with a yaw update and the recovered three-line chat table, and otherwise picks one of the three actor pain `mmove_t` bodies. | High |
| `0x1001F0F0` | `actorMachineGun` | `src/game/m_actor.c` | Direct body computes the muzzle point from `monster_flash_offset[MZ2_ACTOR_MACHINEGUN_1]`, aims at the live enemy or corpse midpoint, and fires the stock monster machinegun helper with the expected flash index and spread. | High |
| `0x1001F220` | `actor_die` | `src/game/m_actor.c` | Direct body disintegrates on `meansOfDeath == 0x23`, gibs below `-80` health, otherwise marks the actor dead, clears `modelindex2`, and selects one of the three actor death moves. | High |
| `0x1001F300` | `actor_fire` | `src/game/m_actor.c` | Direct body calls `actorMachineGun` and toggles `AI_HOLD_FRAME` solely from the actor `pausetime` field, matching the current attack-frame callback. | High |
| `0x1001F340` | `actor_attack` | `src/game/m_actor.c` | Direct body installs the actor attack `mmove_t` and seeds `pausetime = level.time + ((rand() & 0xf) + 10) * FRAMETIME`, which matches the current source exactly. | High |
| `0x1001F380` | `actor_use` | `src/game/m_actor.c` | Direct body resolves `self->target` through `G_PickTarget`, requires a `target_actor`, writes `goalentity` and `movetarget`, recomputes `ideal_yaw`, dispatches the stand or walk callback slots, and on failure clears the target plus falls back to stand with a huge pause timer and no retail debug print. | High |
| `0x1001F460` | `SP_misc_actor` | `src/game/m_actor.c` | Direct spawn body applies deathmatch free, targetname and `START_ON` fixups, `0xFF` model defaults, bbox or corpse setup, callback-slot writes (`use`, `pain`, `die`, `stand`, `walk`, `run`, `attack`), `walkmonster_start`, and immediate self-use on `START_ON`. | High |
| `0x1001F690` | `target_actor_touch` | `src/game/m_actor.c` | Direct body matches the scripted actor path-controller touch: it validates `other->movetarget == self`, broadcasts chat directly to live clients, handles jump launch, attack or `pathtarget` branches, fires `G_UseTargets`, advances to the next `target`, and either recomputes yaw or restores the idle pause. | High |
| `0x1001F930` | `SP_target_actor` | `src/game/m_actor.c` | Direct spawn body installs `target_actor_touch`, configures the trigger bounds plus `SVF_NOCLIENT`, and applies the stock jump defaults with `G_SetMovedir` when the jump spawnflag is set. | High |
| `0x1001FA00` | `badass_sight` | `src/game/m_badass.c` | Direct body swaps from `badass_move_idle_closed` into `badass_move_activate`, otherwise falls through to `badass_run`, then plays the stored sight sound; this matches the retail tank-sound-backed Badass alert path. | High |
| `0x1001FA50` | `badass_stand` | `src/game/m_badass.c` | Tiny direct wrapper that only installs `badass_move_stand` when the monster is not in the closed-idle state. | High |
| `0x1001FA70` | `badass_idle` | `src/game/m_badass.c` | Direct body switches from `badass_move_stand` into `badass_move_deactivate`, otherwise falling back to `badass_move_idle_closed`, which matches the current stand-vs-closed-idle split. | High |
| `0x1001FAA0` | `badass_attack` | `src/game/m_badass.c` | Direct body measures the enemy delta, applies the retail distance and random gates, and then installs `badass_move_attack`; the current source now mirrors that entry wrapper directly. | High |
| `0x1001FB20` | `badass_attack_loop` | `src/game/m_badass.c` | Direct attack endfunc keeps the retail attack move active while the enemy remains visible, alive, and within the recovered distance or random gate; otherwise it falls back to `badass_run`. | High |
| `0x1001FBC0` | `badass_rocket_right` | `src/game/m_badass.c` | Direct body projects from the local muzzle offset `{18, 40, 0}`, aims at enemy origin plus viewheight, normalizes the shot, and fires the shared Oblivion rocket helper with the retail Badass damage and speed fields. | High |
| `0x1001FC80` | `badass_rocket_left` | `src/game/m_badass.c` | Direct body mirrors the right helper from local offset `{18, -40, 0}`, confirming that the retail DLL uses distinct left and right rocket callbacks rather than an inlined one-off attack frame. | High |
| `0x1001FD40` | `badass_gib_explosion` | `src/game/m_badass.c` | Direct body emits the explosion temp entity, applies the matching radius-damage burst, and when reached as the delayed corpse think rearms `badass_die_gibs` for the final gib pass. | High |
| `0x1001FDE0` | `badass_die_gibs` | `src/game/m_badass.c` | Direct body spawns the five Badass limb or torso gib models with per-piece bounds and velocity, then triggers the paired explosion tail and frees the original entity; retail folds more of the death sequence into this helper than the current source. | High |
| `0x10020240` | `badass_dead` | `src/game/m_badass.c` | Direct body shrinks the corpse bbox to `(-44,-62,-64)` through `(44,62,-5)`, marks the deadmonster state, arms delayed `badass_gib_explosion`, and relinks the corpse; the current source now mirrors that delayed corpse tail. | High |
| `0x100202D0` | `badass_die` | `src/game/m_badass.c` | Direct body is the normal death entry: it guards repeated death, sets the death-state fields, and installs `badass_move_death`; retail pushes the later gib burst into `badass_dead` plus `badass_gib_explosion` plus `badass_die_gibs`. | High |
| `0x10020300` | `badass_step` | `src/game/m_badass.c` | Tiny direct sound callback that plays the stored Badass footstep slot loaded by spawn. | High |
| `0x10020330` | `badass_thud` | `src/game/m_badass.c` | Tiny direct death-body sound callback that plays the stored Badass thud or secondary death slot. | High |
| `0x10020360` | `badass_walk` | `src/game/m_badass.c` | Tiny direct wrapper that installs `badass_move_walk`. | High |
| `0x10020370` | `badass_run` | `src/game/m_badass.c` | Tiny direct wrapper that installs `badass_move_run`. | High |
| `0x10020380` | `badass_pain` | `src/game/m_badass.c` | Direct body applies the half-health skin flag, the `damage > 20` threshold, the pain debounce, and the extra light-damage random skip before installing `badass_move_pain` and playing the pain sound. | High |
| `0x10020430` | `SP_monster_badass` | `src/game/m_badass.c` | Direct spawn body applies the deathmatch free at the true entry, loads `models/monsters/badass/tris.md2` plus the five Badass gib models, preloads the tank sound set, writes the Badass callback table and move-table roots, handles the dead-corpse spawnflag branch, and finishes through `walkmonster_start`; retail `gamex86.dll` exposes `monster_badass` and does not expose a separate `monster_sentinel` surface, so the current feature-flagged `src/game/m_sentinel.c` is not a direct retail counterpart. | High |
| `0x1004C8F0` | `badass_move_activate` | `src/game/m_badass.c` | Retail prebuilt move root for the activation band (`0..6`). A direct raw retail DLL dump confirms that the root points to `0x1004C8A8`, where only six contiguous `ai_move` / `dist 0` frames materialize before the move header overlaps the would-be seventh slot; current source now mirrors that raw overlap explicitly through the adjacent retail-blob scaffolding and keeps a separate seven-frame runtime projection so `M_MoveFrame` does not execute overlapped `.data` bytes as code. | High |
| `0x1004C9B8` | `badass_move_deactivate` | `src/game/m_badass.c` | Retail prebuilt move root for the deactivate band (`7..21`). A direct raw `mframe_t` decode shows every frame using `ai_move` with `dist = 0`, and the move endfunc returns through `badass_idle`. | High |
| `0x1004C9F8` | `badass_move_attack` | `src/game/m_badass.c` | Retail prebuilt move root for the attack band (`22..25`). A direct raw `mframe_t` decode shows `ai_charge` with `dist = -5,0,-5,0`, direct hooks `22 -> badass_rocket_right` and `24 -> badass_rocket_left`, and the move endfunc looping through `badass_attack_loop`. | High |
| `0x1004CAF8` | `badass_move_death` | `src/game/m_badass.c` | Retail prebuilt move root for the death band (`78..97`). A direct raw `mframe_t` decode shows `ai_move` with `dist = -8,-8,-8,-7,-4,0,0,0,0,4,2,2,2,2,2,2,0,0,0,0`, hooks `78/86/94 -> badass_gib_explosion` plus `82/93/95/97 -> badass_thud`, and the move endfunc returning through `badass_dead`. | High |
| `0x1004CB18` | `badass_move_idle_closed` | `src/game/m_badass.c` | Retail prebuilt move root for the closed-idle band (`0..0`). A direct raw `mframe_t` decode shows a lone `ai_stand` frame with `dist = 0` and no think hook, so the current source-side `badass_idle_sound` callback on that frame is not a direct retail match. | High |
| `0x1004CBA0` | `badass_move_pain` | `src/game/m_badass.c` | Retail prebuilt move root for the pain band (`26..35`). A direct raw `mframe_t` decode shows `ai_move` with `dist = 8,0,0,0,0,0,-16,-16,-8,0`, and the move endfunc returns through `badass_run`. | High |
| `0x1004CC58` | `badass_move_walk` | `src/game/m_badass.c` | Retail prebuilt move root for the walk band (`56..69`). A direct raw `mframe_t` decode shows `ai_walk` with `dist = 7` on every frame, plus direct hooks `62` and `69 -> badass_step`. | High |
| `0x1004CCC8` | `badass_move_run` | `src/game/m_badass.c` | Retail prebuilt move root for the run band (`70..77`). A direct raw `mframe_t` decode shows `ai_run` with `dist = 14,15,21,24,14,15,21,24`, plus direct hooks `73` and `77 -> badass_step`. | High |
| `0x1004CDC8` | `badass_move_stand` | `src/game/m_badass.c` | Retail prebuilt move root for the stand band (`36..55`). A direct raw `mframe_t` decode shows `ai_stand` with `dist = 0` on every frame and no think hook, so the current source-side `badass_idle_sound` callback on frame `36` is reconstruction-only. | High |
| `0x1004CDD8` | `badass_gib_rarm_model_path` | `src/game/m_badass.c` | Retail string `"models/monsters/badass/gib_rarm.md2"` consumed by `SP_monster_badass` preload and by `badass_die_gibs`. | High |
| `0x1004CDFC` | `badass_gib_larm_model_path` | `src/game/m_badass.c` | Retail string `"models/monsters/badass/gib_larm.md2"` consumed by `SP_monster_badass` preload and by `badass_die_gibs`. | High |
| `0x1004CE20` | `badass_gib_rleg_model_path` | `src/game/m_badass.c` | Retail string `"models/monsters/badass/gib_rleg.md2"` consumed by `SP_monster_badass` preload and by `badass_die_gibs`. | High |
| `0x1004CE44` | `badass_gib_lleg_model_path` | `src/game/m_badass.c` | Retail string `"models/monsters/badass/gib_lleg.md2"` consumed by `SP_monster_badass` preload and by `badass_die_gibs`. | High |
| `0x1004CE68` | `badass_gib_torso_model_path` | `src/game/m_badass.c` | Retail string `"models/monsters/badass/gib_torso.md2"` consumed by `SP_monster_badass` preload and by `badass_die_gibs`. | High |
| `0x1004CF1C` | `badass_sight_sound_path` | `src/game/m_badass.c` | Retail string `"tank/sight1.wav"` loaded by `SP_monster_badass` into `DAT_10060FF4` and consumed by `badass_sight`. | High |
| `0x1004CF54` | `badass_step_sound_path` | `src/game/m_badass.c` | Retail string `"tank/step.wav"` loaded by `SP_monster_badass` into `_DAT_10060FFC` and consumed by `badass_step`. | High |
| `0x1004CF74` | `badass_idle_preload_sound_path` | `src/game/m_badass.c` | Retail string `"tank/tnkidle1.wav"` preloaded by `SP_monster_badass` into `_DAT_10060FEC`, but no recovered standalone Badass callback currently consumes that slot directly. | High |
| `0x1004CF88` | `badass_death_sound_path` | `src/game/m_badass.c` | Retail string `"tank/tnkdeth2.wav"` loaded by `SP_monster_badass` into `_DAT_10060FF8` and consumed by both `badass_die` and `badass_thud`. | High |
| `0x1004CF9C` | `badass_pain_sound_path` | `src/game/m_badass.c` | Retail string `"tank/tnkpain2.wav"` loaded by `SP_monster_badass` into `DAT_10060FE8` and consumed by `badass_pain`. | High |
| `0x1004CFB0` | `badass_model_path` | `src/game/m_badass.c` | Retail string `"models/monsters/badass/tris.md2"` consumed by `SP_monster_badass`. | High |
| `0x10060FE8` | `badass_pain_sound_slot` | `src/game/m_badass.c` | Retail spawn caches `tank/tnkpain2.wav` here, and both selected and top-function decompilation show `badass_pain` consuming the slot directly. | High |
| `0x10060FEC` | `badass_idle_preload_sound_slot` | `src/game/m_badass.c` | Retail spawn caches `tank/tnkidle1.wav` here, but no recovered standalone Badass callback in the committed corpus currently consumes the slot directly. | High |
| `0x10060FF0` | `badass_attack_or_death_preload_sound_slot` | `src/game/m_badass.c` | Retail spawn caches `tank/death.wav` here, but no recovered standalone Badass callback in the committed corpus currently consumes the slot directly. | High |
| `0x10060FF4` | `badass_sight_sound_slot` | `src/game/m_badass.c` | Retail spawn caches `tank/sight1.wav` here, and both selected and top-function decompilation show `badass_sight` consuming the slot directly. | High |
| `0x10060FF8` | `badass_death_sound_slot` | `src/game/m_badass.c` | Retail spawn caches `tank/tnkdeth2.wav` here, and selected decompilation shows `badass_thud` consuming the slot directly while `badass_die` only installs the death move. | High |
| `0x10060FFC` | `badass_step_sound_slot` | `src/game/m_badass.c` | Retail spawn caches `tank/step.wav` here, and selected decompilation shows `badass_step` consuming the slot directly. | High |
| `0x10061000` | `badass_attack_secondary_preload_sound_slot` | `src/game/m_badass.c` | Retail spawn caches `tank/tnkatck5.wav` here, but no recovered standalone Badass callback in the committed corpus currently consumes the slot directly. | High |
| `0x10061004` | `badass_attack_primary_preload_sound_slot` | `src/game/m_badass.c` | Retail spawn caches `tank/tnkatck4.wav` here, but no recovered standalone Badass callback in the committed corpus currently consumes the slot directly. | High |
| `0x100244F0` | `cyborg_footstep` | `src/game/m_cyborg.c` | Direct body random-selects one of the three cached Cyborg step sounds and plays it on `CHAN_VOICE`; move-table xrefs place it in the retail Cyborg run loop. | High |
| `0x10024570` | `cyborg_sight` | `src/game/m_cyborg.c` | Tiny direct sound callback that plays the cached Cyborg sight slot. | High |
| `0x100245A0` | `cyborg_search` | `src/game/m_cyborg.c` | Tiny direct sound callback that plays the cached Cyborg search slot. | High |
| `0x100245D0` | `cyborg_stand` | `src/game/m_cyborg.c` | Tiny direct wrapper that installs the retail Cyborg stand move root at `0x10051540`. | High |
| `0x100245E0` | `cyborg_idle` | `src/game/m_cyborg.c` | Direct body installs the retail Cyborg idle move root and plays the cached idle sound, matching the current idle callback rather than a generic tank alias. | High |
| `0x10024610` | `cyborg_walk` | `src/game/m_cyborg.c` | Tiny direct wrapper that installs the retail Cyborg walk move root. | High |
| `0x10024620` | `cyborg_run` | `src/game/m_cyborg.c` | Direct body matches the current pain-tail and stand-ground logic: it promotes `pain2` into `pain2_end`, sometimes falls through the retail `move901` band, and otherwise chooses stand vs run. | High |
| `0x100246A0` | `cyborg_pain` | `src/game/m_cyborg.c` | Direct body swaps to skin `1` below half health, enforces the `3.0` second pain debounce, skips animations on nightmare, and selects the two retail pain moves with matching sound slots. | High |
| `0x10024770` | `cyborg_hit_left` | `src/game/m_cyborg.c` | Direct melee-hit helper using the shared `mins[0]` aim vector and `10 + rand() % 5` damage; its body is duplicated with `cyborg_hit_right`, and move-table xrefs place this instance on the retail melee2 path. | High |
| `0x10024800` | `cyborg_hit_right` | `src/game/m_cyborg.c` | Direct melee-hit helper using the shared `mins[0]` aim vector and `10 + rand() % 5` damage; the body is identical to `cyborg_hit_left`, and move-table xrefs place this instance on the retail melee1 path. | High |
| `0x10024890` | `cyborg_hit_alt` | `src/game/m_cyborg.c` | Direct alternate melee-hit helper that switches to `maxs[0]` and the third attack sound on hit, matching the current alt-strike callback. | High |
| `0x10024920` | `cyborg_touch` | `src/game/m_cyborg.c` | Direct body applies high-velocity collision damage while airborne, reroutes the backflip landing frame when the body is grounded but off-bottom, and only clears the temporary touch callback once that landing path resolves; the airborne no-ground case returns early with the touch callback still armed. | High |
| `0x10024A30` | `cyborg_attack_start` | `src/game/m_cyborg.c` | Direct body plays the sight sound, nudges origin `z`, sets upward velocity, enables the manual-steering flag, clears ground contact, installs `cyborg_touch`, and arms the attack timeout. | High |
| `0x10024AD0` | `cyborg_attack_end` | `src/game/m_cyborg.c` | Direct body waits for landing, then plays the cached thud sound, resets the attack timeout, and clears the manual-steering state. | High |
| `0x10024B20` | `cyborg_fire_right` | `src/game/m_cyborg.c` | Direct muzzle helper projects from the retail `{15, 12, 12}` offset, aims at enemy origin plus viewheight, normalizes the shot, and calls the shared monster deatom wrapper. | High |
| `0x10024BE0` | `cyborg_fire_left` | `src/game/m_cyborg.c` | Direct muzzle helper mirrors the right shot from the retail `{15, -12, 12}` offset and forwards into `monster_fire_deatom`. | High |
| `0x10024CA0` | `cyborg_fire_both` | `src/game/m_cyborg.c` | Direct body fires the retail dual-shot sequence by running the left then right deatom muzzle calculations back-to-back. | High |
| `0x10024E00` | `cyborg_attack` | `src/game/m_cyborg.c` | Direct body random-selects the three retail ranged-attack move roots, matching the current attack wrapper thresholds. | High |
| `0x10024E70` | `cyborg_melee` | `src/game/m_cyborg.c` | Direct body random-selects the two melee move roots vs the backflip attack move, matching the current melee wrapper thresholds. | High |
| `0x10024F10` | `cyborg_check_range` | `src/game/m_cyborg.c` | Direct body matches the custom vertical-overlap and planar-distance gate used by the Cyborg ranged attack path, including the `dist > 100` skip-randomizer. | High |
| `0x10024FF0` | `cyborg_checkattack` | `src/game/m_cyborg.c` | Direct body checks enemy liveness, promotes melee range to `AS_MELEE`, and otherwise calls the custom range gate before promoting `AS_MISSILE`. | High |
| `0x10025050` | `cyborg_dead` | `src/game/m_cyborg.c` | Direct corpse callback shrinks the bbox to `(-32,-32,-38)` through `(32,32,-20)`, switches to `MOVETYPE_TOSS`, marks `SVF_DEADMONSTER`, and relinks the corpse. | High |
| `0x100250B0` | `cyborg_die` | `src/game/m_cyborg.c` | Direct death body keeps the `meansOfDeath == 0x23` disintegration branch, the organic gib path, and the normal death-state setup; the current `cyborg_die_select()` helper is compiler-folded into this retail body rather than isolated separately. | High |
| `0x10025200` | `SP_monster_cyborg` | `src/game/m_cyborg.c` | Direct spawn body applies the deathmatch free at the true entry, precaches `models/monsters/cyborg/tris.md2` plus the full Cyborg sound set, sets bbox `(-16,-16,-38)` to `(16,16,27)`, health `300`, gib health `-120`, mass `300`, wires the Cyborg callback table, seeds the stand move, and finishes through `walkmonster_start`; retail also uses prebuilt `.data` move roots instead of the current source's runtime `mmove_t` construction. | High |
| `0x10051540` | `cyborg_move_stand` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_stand` (`125..125`). A direct raw `mframe_t` decode now shows the lone frame using direct `ai_stand @ 0x10001220` with `dist = 0`; `cyborg_stand` installs it directly. | High |
| `0x10051560` | `cyborg_move_idle` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_idle` (`125..125`). A direct raw `mframe_t` decode now shows the same `ai_stand @ 0x10001220` payload with `dist = 0`, and the move endfunc returns through `cyborg_stand`. | High |
| `0x10051648` | `cyborg_move_walk` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_walk` (`0..17`). A direct raw `mframe_t` decode now shows every frame using `ai_walk` with the exact retail distance sequence `12,2,2,2,5,5,6,8,13,12,2,2,2,5,5,6,8,13`. | High |
| `0x100516A0` | `cyborg_move_run` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_run` (`18..23`). A direct raw `mframe_t` decode now shows every frame using `ai_run` with `dist = 6,23,8,6,23,8`, plus direct hooks `19` and `21 -> cyborg_footstep`. | High |
| `0x100516F8` | `cyborg_move_pain1` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_pain1` (`73..78`). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = -16,-4,0,0,0,0`, and the move endfunc returns through `cyborg_run`. | High |
| `0x10051730` | `cyborg_move_pain2` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_pain2` (`79..81`). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = -11,-8,4`, and the move endfunc returns through `cyborg_run`. | High |
| `0x10051750` | `cyborg_move_pain2_end` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_pain2_end` (`82..82`). A direct raw `mframe_t` decode now shows the lone frame using `ai_move` with `dist = 0`, and the move endfunc also returns through `cyborg_run`. | High |
| `0x100517F0` | `cyborg_move_move` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_move` (`93..104`, the current `move901` band). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = 8,7,3,0,-2,-3,2,5,16,0,0,0`, and the move endfunc returns through `cyborg_run`. | High |
| `0x10051860` | `cyborg_move_melee1` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_melee1` (`59..66`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 8,10,0,0,-5,-5,-5,-5`, plus direct hooks `61 -> cyborg_hit_right` and `63 -> cyborg_hit_alt`, and the move endfunc returns through `cyborg_run`. | High |
| `0x100518B8` | `cyborg_move_melee2` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_melee2` (`67..72`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 6,6,6,-3,-3,-10`, plus direct hook `70 -> cyborg_hit_left`, and the move endfunc returns through `cyborg_run`. | High |
| `0x10051958` | `cyborg_move_attack1` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_attack1` (`24..35`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 4,4,5,7,7,9,4,4,5,7,7,9`, plus direct hooks `29 -> cyborg_fire_right` and `35 -> cyborg_fire_left`, and the move endfunc returns through `cyborg_run`. | High |
| `0x100519F0` | `cyborg_move_attack_backflip` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_attack_backflip` (`36..46`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 0,-17,-15,-15,-15,-15,-15,-15,0,3,0`, plus direct hooks `38 -> cyborg_attack_start`, `43 -> cyborg_attack_end`, and `44 -> cyborg_fire_both`, and the move endfunc returns through `cyborg_run`. | High |
| `0x10051A48` | `cyborg_move_attack2` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_attack2` (`47..52`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 0`, plus direct hook `47 -> cyborg_fire_right`, and the move endfunc returns through `cyborg_run`. | High |
| `0x10051AA0` | `cyborg_move_attack3` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_attack3` (`53..58`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 0`, plus direct hook `53 -> cyborg_fire_left`, and the move endfunc returns through `cyborg_run`. | High |
| `0x10051B20` | `cyborg_move_death1` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_death1` (`105..112`). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = -2,0,-3,0,-1,-2,-3,-2`, and the move endfunc returns through `cyborg_dead`. | High |
| `0x10051B78` | `cyborg_move_death2` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_death2` (`113..118`). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = -6,-4,-2,0,0,0`, and the move endfunc returns through `cyborg_dead`. | High |
| `0x10051BD0` | `cyborg_move_death3` | `src/game/m_cyborg.c` | Retail prebuilt move root for `cyborg_frames_death3` (`119..124`). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = 8,4,2,1,0,0`, and the move endfunc returns through `cyborg_dead`. | High |
| `0x10051BE0` | `cyborg_model_path` | `src/game/m_cyborg.c` | Retail model string `"models/monsters/cyborg/tris.md2"` consumed by `SP_monster_cyborg`. | High |
| `0x10051C00` | `cyborg_thud_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/thud1.wav"` loaded by `SP_monster_cyborg` and stored in the Cyborg thud slot used by `cyborg_attack_end`. | High |
| `0x10051C14` | `cyborg_step3_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/step3.wav"` loaded by `SP_monster_cyborg` and used by `cyborg_footstep`. | High |
| `0x10051C28` | `cyborg_step2_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/step2.wav"` loaded by `SP_monster_cyborg` and used by `cyborg_footstep`. | High |
| `0x10051C3C` | `cyborg_step1_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/step1.wav"` loaded by `SP_monster_cyborg` and used by `cyborg_footstep`. | High |
| `0x10051C50` | `cyborg_search_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/mutsrch1.wav"` loaded by `SP_monster_cyborg` and used by `cyborg_search`. | High |
| `0x10051C64` | `cyborg_sight_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/mutsght1.wav"` loaded by `SP_monster_cyborg` and used by `cyborg_sight` plus `cyborg_attack_start`. | High |
| `0x10051C78` | `cyborg_pain2_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/mutpain2.wav"` loaded by `SP_monster_cyborg` and used by the second pain branch in `cyborg_pain`. | High |
| `0x10051C8C` | `cyborg_pain1_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/mutpain1.wav"` loaded by `SP_monster_cyborg` and used by the first pain branch in `cyborg_pain`. | High |
| `0x10051CA0` | `cyborg_idle_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/mutidle1.wav"` loaded by `SP_monster_cyborg` and used by `cyborg_idle`. | High |
| `0x10051CB4` | `cyborg_death_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/mutdeth1.wav"` loaded by `SP_monster_cyborg` and used by the normal death path in `cyborg_die`. | High |
| `0x10051CC8` | `cyborg_attack3_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/mutatck3.wav"` loaded by `SP_monster_cyborg` and used by `cyborg_hit_alt`. | High |
| `0x10051CDC` | `cyborg_attack2_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/mutatck2.wav"` loaded by `SP_monster_cyborg` and used by `cyborg_hit_left` / `cyborg_hit_right` on successful melee hits. | High |
| `0x10051CF0` | `cyborg_attack1_sound_path` | `src/game/m_cyborg.c` | Retail string `"cyborg/mutatck1.wav"` loaded by `SP_monster_cyborg` and used by the Cyborg melee miss path. | High |
| `0x1001B480` | `G_TouchTriggers` | `src/game/g_trigger.c` | Direct body enumerates trigger touches around the entity bounds and calls each touched trigger's `touch` callback; `ClientThink` calls it exactly at the stock non-noclip site. | High |
| `0x1002A0C0` | `M_CheckBottom` | `src/game/m_move.c` | Direct body performs the stock midpoint and four-corner ground traces under the entity bounds, using the `c_yes` / `c_no` counters and the `STEPSIZE` threshold to reject ledge-hanging positions. | High |
| `0x1002A330` | `SV_movestep` | `src/game/m_move.c` | Direct body is the large stock monster step or slope mover: it handles fly/swim vertical adjustment, stair stepping, bottom checks, groundentity updates, water rejection, and optional relink plus `G_TouchTriggers`. | High |
| `0x1002A850` | `M_ChangeYaw` | `src/game/m_move.c` | Direct body reads `ideal_yaw`, wraps the current and destination yaw values through the same helper used by `FacingIdeal` and `SV_NewChaseDir`, clamps by `yaw_speed`, and writes back `s.angles[YAW]`. | High |
| `0x1002A920` | `SV_StepDirection` | `src/game/m_move.c` | Direct body sets `ideal_yaw`, calls `M_ChangeYaw`, computes the forward step from the requested yaw and distance, calls `SV_movestep`, and rewinds the attempted move when the actor has not turned far enough yet. | High |
| `0x1002AA00` | `SV_FixCheckBottom` | `src/game/m_move.c` | Tiny direct stub that only marks `FL_PARTIALGROUND`, matching the stock monster bridge-or-ledge fallback helper. | High |
| `0x1002AA20` | `SV_NewChaseDir` | `src/game/m_move.c` | Direct body bins enemy deltas into octant headings, computes `olddir` and `turnaround` from the wrapped ideal yaw, tries direct and fallback `SV_StepDirection` candidates, and falls back to `SV_FixCheckBottom` when movement fails. | High |
| `0x1002AD60` | `SV_CloseEnough` | `src/game/m_move.c` | Direct body compares the `absmin` and `absmax` bounds of `ent` and `goal` across all three axes with a caller-supplied distance margin. | High |
| `0x1002ADC0` | `M_MoveToGoal` | `src/game/m_move.c` | Direct body early-outs for airborne non-fly non-swim actors, stops when already close enough to the enemy, then tries `SV_StepDirection` on `ideal_yaw` or falls back to `SV_NewChaseDir`. | High |
| `0x1002AE40` | `M_walkmove` | `src/game/m_move.c` | Direct body rejects non-grounded non-fly non-swim actors, converts yaw plus distance into a planar move vector, and forwards straight to `SV_movestep(..., true)`. | High |
| `0x10028DF0` | `kigrax_search` | `src/game/m_kigrax.c` | Direct body random-gates between two search sound slots loaded by the Kigrax spawn path, matching the current Kigrax search callback rather than a stock hover helper. | High |
| `0x10028E60` | `kigrax_sight` | `src/game/m_kigrax.c` | Direct body plays the Kigrax sight sound and switches `currentmove` to the Kigrax sight move. | High |
| `0x10028E90` | `kigrax_stand` | `src/game/m_kigrax.c` | Direct body early-outs on `AI_STAND_GROUND`, then random-gates between the stand and scan moves using the same one-third threshold as the current source. | High |
| `0x10028EE0` | `kigrax_run` | `src/game/m_kigrax.c` | Direct body emits the retail `running...` debug print, falls back to the stand move on `AI_STAND_GROUND`, and otherwise installs the Kigrax run move. | High |
| `0x10028F20` | `kigrax_walk` | `src/game/m_kigrax.c` | Direct body emits the retail `walking...` debug print and random-gates between the two Kigrax walk moves using the same threshold as the current source. | High |
| `0x10028F80` | `kigrax_fire_plasma` | `src/game/m_kigrax.c` | Direct body builds the muzzle point through `G_ProjectSource` with the retail offset `{16, 0, -16}`, targets enemy origin plus viewheight, calls `fire_plasma_bolt` with damage `10`, speed `1000`, and type `1`, then emits the Kigrax muzzleflash byte `1`. | High |
| `0x10029020` | `kigrax_attack` | `src/game/m_kigrax.c` | Tiny direct wrapper that only installs the Kigrax ranged-attack move. | High |
| `0x10029030` | `kigrax_melee` | `src/game/m_kigrax.c` | Direct body aborts to run when the enemy is dead, not in `RANGE_MELEE`, or when the skip-randomizer triggers, then chooses melee1 vs melee2 through the same alternating threshold used by the current source. | High |
| `0x100290D0` | `kigrax_strike1` | `src/game/m_kigrax.c` | Direct body plays the Kigrax attack sound and calls `fire_hit` with damage `10 + (rand() % 6)` and kick `100`. | High |
| `0x10029140` | `kigrax_strike2` | `src/game/m_kigrax.c` | Direct body mirrors the first strike helper but raises the melee damage to `20 + (rand() % 20)`. | High |
| `0x100291B0` | `kigrax_pain` | `src/game/m_kigrax.c` | Direct body enforces a `3.0` second pain debounce, skips the animation on nightmare skill, plays the Kigrax pain sound, and installs the Kigrax pain move. | High |
| `0x10029220` | `kigrax_die` | `src/game/m_kigrax.c` | Direct body disintegrates on `meansOfDeath == 0x23`, gibs below `gib_health`, and otherwise installs the single Kigrax death move after marking the monster dead and damageable. | High |
| `0x10029354` | `SP_monster_kigrax` | `src/game/m_kigrax.c` | Direct spawn body loads the Kigrax model plus hover and Kigrax-specific sounds, applies bbox `(-20,-20,-32)` to `(20,20,12)`, health `200`, gib health `-100`, mass `150`, viewheight `90`, wires the Kigrax callback table, seeds the idle sound, and finishes through `flymonster_start`. | High |
| `0x1002F030` | `kigrax_dead` | `src/game/m_kigrax.c` | Direct body shrinks the corpse bbox to `(-16,-16,-16)` through `(16,16,0)`, switches to `MOVETYPE_TOSS`, marks `SVF_DEADMONSTER`, clears `nextthink`, and relinks the corpse. | High |
| `0x10058818` | `kigrax_move_stand` | `src/game/m_kigrax.c` | Retail prebuilt move root for `kigrax_frames_stand` (`0..27`). A direct raw `mframe_t` decode now shows every frame using direct `ai_stand @ 0x10001220` with `dist = 0`; the move is anchored by the spawn default `currentmove`, the `kigrax_stand` fallback path, and the `kigrax_run` `AI_STAND_GROUND` branch. | High |
| `0x10058928` | `kigrax_move_scan` | `src/game/m_kigrax.c` | Retail prebuilt move root for `kigrax_frames_scan` (`28..48`). A direct raw `mframe_t` decode now shows every frame using the same direct `ai_stand @ 0x10001220` payload with `dist = 0`, directly matching the random branch in `kigrax_stand`. | High |
| `0x10058AE0` | `kigrax_move_walk1` | `src/game/m_kigrax.c` | Retail prebuilt move root for `kigrax_frames_walk1` (`61..82`). A direct raw `mframe_t` decode now shows every frame using `ai_walk` with `dist = 4`, matching the fallback branch in `kigrax_walk`. | High |
| `0x10058C08` | `kigrax_move_walk2` | `src/game/m_kigrax.c` | Retail prebuilt move root for `kigrax_frames_walk2` (`83..104`). A direct raw `mframe_t` decode now shows every frame using `ai_walk` with `dist = 4`, matching the random branch in `kigrax_walk`. | High |
| `0x10058CE8` | `kigrax_move_sight` | `src/game/m_kigrax.c` | Retail prebuilt move root for `kigrax_frames_sight` (`105..121`). A direct raw `mframe_t` decode now shows every frame using `ai_run` with `dist = 10`, directly matching `kigrax_sight`. | High |
| `0x10058DC8` | `kigrax_move_run` | `src/game/m_kigrax.c` | Retail prebuilt move root for `kigrax_frames_run` (`122..138`). A direct raw `mframe_t` decode now shows every frame using `ai_run` with `dist = 15`, matching the non-stand-ground path in `kigrax_run` and the fallback path in `kigrax_melee`. | High |
| `0x10058E60` | `kigrax_move_pain` | `src/game/m_kigrax.c` | Retail prebuilt move root for `kigrax_frames_pain` (`139..149`). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = 0`, and the move endfunc returns through `kigrax_run`. | High |
| `0x10058F58` | `kigrax_move_death` | `src/game/m_kigrax.c` | Retail prebuilt move root for `kigrax_frames_death` (`150..168`). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = 0`, a direct frame hook `163 -> kigrax_dead`, and the move endfunc also returning through `kigrax_dead`. | High |
| `0x10059020` | `kigrax_move_melee1` | `src/game/m_kigrax.c` | Retail prebuilt move root for `kigrax_frames_melee1` (`169..183`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 1`, direct hooks `176` and `180 -> kigrax_strike1`, and the move endfunc looping back through `kigrax_melee`. | High |
| `0x100590B8` | `kigrax_move_melee2` | `src/game/m_kigrax.c` | Retail prebuilt move root for `kigrax_frames_melee2` (`184..194`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 1`, direct hook `188 -> kigrax_strike2`, and the move endfunc looping back through `kigrax_melee`. | High |
| `0x10059140` | `kigrax_move_attack` | `src/game/m_kigrax.c` | Retail prebuilt move root for `kigrax_frames_attack` (`195..204`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 0`, direct hook `198 -> kigrax_fire_plasma`, and the move endfunc returning through `kigrax_run`. | High |
| `0x10059150` | `kigrax_plasma_offset` | `src/game/m_kigrax.c` | Retail muzzle offset vector `{16, 0, -16}` consumed by `kigrax_fire_plasma` through `G_ProjectSource`. | High |
| `0x1005915C` | `kigrax_run_debug_string` | `src/game/m_kigrax.c` | Retail debug string `"running...\n"` consumed by `kigrax_run`. | High |
| `0x10059168` | `kigrax_walk_debug_string` | `src/game/m_kigrax.c` | Retail debug string `"walking...\n"` consumed by `kigrax_walk`. | High |
| `0x10059174` | `kigrax_idle_sound_path` | `src/game/m_kigrax.c` | Retail string `"kigrax/hovidle1.wav"` preloaded by `SP_monster_kigrax` and assigned to `self->s.sound` for the idle loop. | High |
| `0x10059188` | `kigrax_attack_preload_path` | `src/game/m_kigrax.c` | Retail string `"kigrax/hovatck1.wav"` is preloaded by `SP_monster_kigrax`, but no recovered standalone Kigrax callback currently consumes the returned sound slot. | High |
| `0x1005919C` | `kigrax_model_path` | `src/game/m_kigrax.c` | Retail model string `"models/monsters/kigrax/tris.md2"` consumed by `SP_monster_kigrax`. | High |
| `0x1002C2D0` | `soldier_stand` | `src/game/m_soldier.c` | Direct body keeps the two retail soldier stand `mmove_t` roots and randomly swaps into the alternate stand move exactly where the current soldier stand wrapper does. | High |
| `0x1002C360` | `soldier_walk` | `src/game/m_soldier.c` | Direct body random-selects the two retail soldier walk moves, matching the current walk wrapper rather than a generic stock infantry alias. | High |
| `0x1002C3B0` | `soldier_run` | `src/game/m_soldier.c` | Direct body respects `AI_STAND_GROUND`, otherwise chooses the run-start or steady run move depending on the current move root, matching the current soldier run wrapper. | High |
| `0x1002C400` | `soldier_pain` | `src/game/m_soldier.c` | Direct body applies the half-health skin swap, pain debounce, airborne pain branch, nightmare skip, and skin-driven pain sound or move selection used by the retail soldier damage path. | High |
| `0x1002C560` | `soldier_fire` | `src/game/m_soldier.c` | Direct shared muzzle helper builds the projectile origin through `G_ProjectSource`, branches by skin band into blaster, shotgun, machinegun hold-frame, or deatom fire, and proves the retail Deatomiser Soldier is selected by `s.skinnum >= 6`, not by the current source's `count` field. | High |
| `0x1002CAF0` | `soldier_attack6_refire` | `src/game/m_soldier.c` | Tiny direct callback checks the refire timer and enemy range, then jumps back into the run-and-shoot frame loop exactly like the current attack6 refire helper. | High |
| `0x1002CB20` | `soldier_fire4` | `src/game/m_soldier.c` | Tiny direct wrapper that only calls `soldier_fire(self, 3)`, matching the heavy stationary fire callback in the current source. | High |
| `0x1002CB30` | `soldier_fire8` | `src/game/m_soldier.c` | Tiny direct wrapper that only calls `soldier_fire(self, 7)`, matching the run-and-shoot fire callback in the current source. | High |
| `0x1002CB80` | `soldier_attack` | `src/game/m_soldier.c` | Direct body picks the light/regular attack move pair for lower skins and the heavy soldier attack move for SS/deatom skins, matching the current attack entry wrapper. | High |
| `0x1002CBE0` | `soldier_sight` | `src/game/m_soldier.c` | Direct body plays one of the two sight/search sounds and, on higher skill with a distant target, can switch into the retail run-and-shoot soldier move instead of only playing audio. | High |
| `0x1002CC90` | `soldier_dodge` | `src/game/m_soldier.c` | Direct body matches the stock/current soldier dodge gate: random early-out, enemy claim, skill-dependent duck-vs-attack3 choice, and pause timer setup. | High |
| `0x1002CD90` | `soldier_die` | `src/game/m_soldier.c` | Direct body preserves the retail `meansOfDeath == 0x23` disintegration branch, the gib path below `gib_health`, and the multi-move normal death selection used by the soldier skins. | High |
| `0x1002CEF0` | `SP_monster_soldier_x` | `src/game/m_soldier.c` | Direct shared spawn body loads the soldier model and base sound set, applies bbox `(-16,-16,-24)` to `(16,16,32)`, mass `100`, the corpse-spawnflag branch, the soldier callback table, and the final `walkmonster_start` handoff. | High |
| `0x1002D170` | `SP_monster_soldier_light` | `src/game/m_soldier.c` | Direct spawn wrapper applies the deathmatch free, light-soldier sound set, laser model/sound preload, skin band `0`, health `20`, and gib health `-30` before returning to the shared soldier body. | High |
| `0x1002D200` | `SP_monster_soldier` | `src/game/m_soldier.c` | Direct spawn wrapper applies the regular soldier sound set, ORs the retail skin bits to `2`, and keeps the stock `30 / -30` durability. | High |
| `0x1002D280` | `SP_monster_soldier_ss` | `src/game/m_soldier.c` | Direct spawn wrapper applies the SS pain/death/attack sound set, ORs the retail skin bits to `4`, and uses `40 / -30` durability. | High |
| `0x1002D300` | `SP_monster_soldier_deatom` | `src/game/m_soldier.c` | Direct spawn wrapper reuses `SP_monster_soldier_x`, ORs the retail skin bits to `6`, keeps the SS `40 / -30` durability, and only preloads the SS sound set; unlike the current source it does not set `count = 1`, does not force `run`, and does not preload `deatom/*.wav` here, because the retail deatom path is reached later through the `soldier_fire` skin-band branch. | High |
| `0x10021460` | `spider_checkattack` | `src/game/m_spider.c` | Direct created body overrides the default `M_CheckAttack` path for Spider: it performs a live-enemy top-of-bbox clear-shot trace, recomputes `ideal_yaw`, selects `AS_MELEE` vs `AS_MISSILE` at melee range from the real callback table, and otherwise uses a Spider-specific ranged attack-chance or cooldown gate instead of falling straight through stock `M_CheckAttack`. Current `m_spider.c` now reconstructs and installs this override directly in `SP_monster_spider`. | High |
| `0x1002D380` | `spider_idle` | `src/game/m_spider.c` | Direct body plays the Spider idle sound slot loaded by the retail spawn path, matching the current idle callback. | High |
| `0x1002D3B0` | `spider_sight` | `src/game/m_spider.c` | Direct body plays the dedicated `spider/sight.wav` slot and matches the current sight callback. | High |
| `0x1002D3E0` | `spider_search` | `src/game/m_spider.c` | Direct body plays the Spider search sound slot loaded by spawn, matching the current search callback. | High |
| `0x1002D410` | `spider_melee_swing` | `src/game/m_spider.c` | Tiny direct callback that only plays the first Spider melee windup sound, matching the current pre-hit swing helper. | High |
| `0x1002D440` | `spider_stand` | `src/game/m_spider.c` | Tiny direct wrapper that installs the Spider stand `mmove_t`. | High |
| `0x1002D450` | `spider_walk` | `src/game/m_spider.c` | Tiny direct wrapper that installs the Spider walk `mmove_t`. | High |
| `0x1002D460` | `spider_charge_think` | `src/game/m_spider.c` | Direct body matches the airborne charge impact handler: it damages a live enemy while velocity stays high, redirects to `SPIDER_FRAME_RUN1_START + 3` once ground contact returns, and clears the installed touch callback when the charge resolves. | High |
| `0x1002D570` | `spider_charge_start` | `src/game/m_spider.c` | Direct body plays the sight sound, nudges origin `z` by `1`, launches the Spider forward with the retail vertical boost, sets `AI_DUCKED` (`0x800` in the recovered `aiflags`), clears ground contact, and installs `spider_charge_think` through the touch slot. | High |
| `0x1002D610` | `spider_charge_end` | `src/game/m_spider.c` | Direct body matches the retail landing tail: when grounded it plays the thud or step sound, clears `AI_DUCKED`, and resets the charge timer. | High |
| `0x1002D660` | `spider_run` | `src/game/m_spider.c` | Direct body respects `AI_STAND_GROUND`, otherwise random-selects the two Spider run moves exactly like the current source. | High |
| `0x1002D6C0` | `spider_melee_hit` | `src/game/m_spider.c` | Direct body builds the stock melee aim vector, calls `fire_hit`, and plays the retail hit-vs-miss melee sounds. | High |
| `0x1002D750` | `spider_melee` | `src/game/m_spider.c` | Direct body emits the retail `spider_melee` debug print and then random-selects the primary vs secondary melee move. | High |
| `0x1002D7B0` | `spider_rocket_left` | `src/game/m_spider.c` | Direct body projects the left muzzle source, aims at the stored enemy view point in `pos1`, normalizes the shot vector, and fires the left Spider rocket flash. | High |
| `0x1002D850` | `spider_rocket_right` | `src/game/m_spider.c` | Direct body mirrors the left helper with the right muzzle offset and right Spider rocket flash index. | High |
| `0x1002D8F0` | `spider_attack` | `src/game/m_spider.c` | Direct body snapshots enemy origin plus viewheight into `pos1` and random-selects the left, right, or dual rocket attack move. | High |
| `0x1002D9E0` | `spider_pain` | `src/game/m_spider.c` | Direct body applies the half-health skin swap, enforces the `3.0` second pain debounce, plays one of the two pain sounds, and selects the retail pain moves by damage and skill gating. | High |
| `0x1002DB70` | `spider_dead` | `src/game/m_spider.c` | Direct body shrinks the corpse bbox, switches to `MOVETYPE_TOSS`, marks `SVF_DEADMONSTER`, clears `nextthink`, and relinks the corpse. | High |
| `0x1002DBD0` | `spider_die` | `src/game/m_spider.c` | Direct body keeps the retail disintegration-on-`meansOfDeath == 0x23` case, the Spider gib path, and the normal death1 vs death2 move selection. | High |
| `0x1002DCF0` | `SP_monster_spider` | `src/game/m_spider.c` | Direct spawn body loads the Spider model and sound set, applies bbox `(-32,-32,-35)` to `(32,32,32)`, health `400`, gib health `-175`, mass `300`, the Spider callback table including the custom `spider_checkattack` install, the corpse spawnflag branch, and the final `walkmonster_start` handoff. | High |
| `0x1005CA00` | `spider_move_stand` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_stand` (`0..54`). A direct raw `mframe_t` decode now shows every frame using direct `ai_stand @ 0x10001220` with `dist = 0`, no think hook, and no endfunc. | High |
| `0x1005CA88` | `spider_move_walk` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_walk` (`55..64`). A direct raw `mframe_t` decode now shows every frame using `ai_walk` with the exact retail distance sequence `0,4,6,4,2,0,4,6,4,2`, with no think hook or endfunc. | High |
| `0x1005CB10` | `spider_move_run1` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_run1` (`65..74`). A direct raw `mframe_t` decode now shows every frame using `ai_run` with `dist = 0`, plus direct hooks `67 -> spider_charge_start` and `72 -> spider_charge_end`, and the move endfunc returns through `spider_run`. | High |
| `0x1005CB68` | `spider_move_run2` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_run2` (`75..80`). A direct raw `mframe_t` decode now shows every frame using `ai_run` with `dist = 16`, with no think hook or endfunc. | High |
| `0x1005CBB8` | `spider_move_melee_primary` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_melee_primary` (`99..103`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 0`, plus direct hooks `102 -> spider_melee_swing` and `103 -> spider_melee_hit`, and the move endfunc returns through `spider_run`. | High |
| `0x1005CC20` | `spider_move_melee_secondary` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_melee_secondary` (`104..110`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 0`, plus direct hooks `108 -> spider_melee_swing` and `109/110 -> spider_melee_hit`, and the move endfunc returns through `spider_run`. | High |
| `0x1005CC70` | `spider_move_attack_left` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_attack_left` (`81..85`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 0`, plus direct hook `83 -> spider_rocket_left`, and the move endfunc returns through `spider_run`. | High |
| `0x1005CCC0` | `spider_move_attack_right` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_attack_right` (`86..90`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 0`, plus direct hook `88 -> spider_rocket_right`, and the move endfunc returns through `spider_run`. | High |
| `0x1005CD30` | `spider_move_attack_dual` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_attack_dual` (`91..98`). A direct raw `mframe_t` decode now shows every frame using `ai_charge` with `dist = 0`, plus direct hooks `92 -> spider_rocket_left` and `96 -> spider_rocket_right`, and the move endfunc returns through `spider_run`. | High |
| `0x1005CD88` | `spider_move_pain1` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_pain1` (`111..116`). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = 0`, and the move endfunc returns through `spider_run`. | High |
| `0x1005CDF8` | `spider_move_pain2` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_pain2` (`117..124`). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = -16,-32,-8,0,0,0,0,0`, and the move endfunc returns through `spider_run`. | High |
| `0x1005CEF8` | `spider_move_death1` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_death1` (`125..144`). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = -8,-4,-2,0,0,-2,-6,-4,0,4,6,4,0,0,0,0,0,0,0,0`, and the move endfunc returns through `spider_dead`. | High |
| `0x1005CFF8` | `spider_move_death2` | `src/game/m_spider.c` | Retail prebuilt move root for `spider_frames_death2` (`145..164`). A direct raw `mframe_t` decode now shows every frame using `ai_move` with `dist = -24,-22,-20,-18,-16,-16,-16,-16,-16,-4,-12,-8,0,0,0,0,0,0,0,0`, and the move endfunc returns through `spider_dead`. | High |
| `0x1005D018` | `spider_model_path` | `src/game/m_spider.c` | Retail string `"models/monsters/spider/tris.md2"` consumed by `SP_monster_spider`. | High |
| `0x100550EC` | `spider_melee1_sound_path` | `src/game/m_spider.c` | Retail string `"gladiator/melee1.wav"` loaded by `SP_monster_spider` and consumed by `spider_melee_swing`. | High |
| `0x100550D4` | `spider_melee2_sound_path` | `src/game/m_spider.c` | Retail string `"gladiator/melee2.wav"` loaded by `SP_monster_spider` and consumed by `spider_melee_hit` on successful melee hits. | High |
| `0x100550BC` | `spider_melee3_sound_path` | `src/game/m_spider.c` | Retail string `"gladiator/melee3.wav"` loaded by `SP_monster_spider` and consumed by `spider_melee_hit` on melee misses. | High |
| `0x1005514C` | `spider_pain1_sound_path` | `src/game/m_spider.c` | Retail string `"gladiator/pain.wav"` loaded by `SP_monster_spider` and consumed by `spider_pain`. | High |
| `0x10055134` | `spider_pain2_sound_path` | `src/game/m_spider.c` | Retail string `"gladiator/gldpain2.wav"` loaded by `SP_monster_spider` and consumed by `spider_pain`. | High |
| `0x100550A4` | `spider_idle_sound_path` | `src/game/m_spider.c` | Retail string `"gladiator/gldidle1.wav"` loaded by `SP_monster_spider` and consumed by `spider_idle`. | High |
| `0x1005508C` | `spider_search_sound_path` | `src/game/m_spider.c` | Retail string `"gladiator/gldsrch1.wav"` loaded by `SP_monster_spider` and consumed by `spider_search`. | High |
| `0x1005D038` | `spider_sight_sound_path` | `src/game/m_spider.c` | Retail string `"spider/sight.wav"` loaded by `SP_monster_spider` and consumed by both `spider_sight` and `spider_charge_start`. | High |
| `0x1005A678` | `spider_step_sound_path` | `src/game/m_spider.c` | Retail string `"mutant/thud1.wav"` loaded by `SP_monster_spider` into the Spider step/thud slot and consumed directly by `spider_charge_end`; no decoded Spider frame table currently references a standalone `spider_step` callback. | High |
| `0x100493F8` | `spider_gib_death_sound_path` | `src/game/m_spider.c` | Retail string `"misc/udeath.wav"` consumed by the Spider gib branch in `spider_die`. | High |
| `0x100493D0` | `spider_gib_meat_model_path` | `src/game/m_spider.c` | Retail string `"models/objects/gibs/sm_meat/tris.md2"` consumed by the Spider gib branch in `spider_die`. | High |
| `0x1004FC88` | `spider_gib_metal_model_path` | `src/game/m_spider.c` | Retail string `"models/objects/gibs/sm_metal/tris.md2"` consumed by the Spider gib branch in `spider_die`. | High |
| `0x1004B55C` | `spider_gib_chest_model_path` | `src/game/m_spider.c` | Retail string `"models/objects/gibs/chest/tris.md2"` consumed by the Spider gib branch in `spider_die`. | High |
| `0x100491D4` | `spider_gib_head_model_path` | `src/game/m_spider.c` | Retail string `"models/objects/gibs/head2/tris.md2"` consumed by the Spider gib branch in `spider_die`. | High |
| `0x10061328` | `spider_melee1_sound_slot` | `src/game/m_spider.c` | Retail spawn caches `"gladiator/melee1.wav"` here, and selected decompilation shows `spider_melee_swing` consuming the slot directly. | High |
| `0x1006132C` | `spider_melee2_sound_slot` | `src/game/m_spider.c` | Retail spawn caches `"gladiator/melee2.wav"` here, and selected decompilation shows `spider_melee_hit` consuming the slot on successful hits. | High |
| `0x10061330` | `spider_idle_sound_slot` | `src/game/m_spider.c` | Retail spawn caches `"gladiator/gldidle1.wav"` here, and selected decompilation shows `spider_idle` consuming the slot directly. | High |
| `0x10061334` | `spider_melee3_sound_slot` | `src/game/m_spider.c` | Retail spawn caches `"gladiator/melee3.wav"` here, and selected decompilation shows `spider_melee_hit` consuming the slot on melee misses. | High |
| `0x10061338` | `spider_sight_sound_slot` | `src/game/m_spider.c` | Retail spawn first caches `"mutant/mutsght1.wav"` here, then immediately overwrites the same slot with `"spider/sight.wav"`; selected decompilation shows `spider_sight` and `spider_charge_start` consuming the final Spider-specific slot. | High |
| `0x1006133C` | `spider_step_sound_slot` | `src/game/m_spider.c` | Retail spawn caches `"mutant/thud1.wav"` here, and selected decompilation shows `spider_charge_end` as the direct consumer; no standalone retail `spider_step` callback currently consumes this slot in the committed corpus. | High |
| `0x10061340` | `spider_pain2_sound_slot` | `src/game/m_spider.c` | Retail spawn caches `"gladiator/gldpain2.wav"` here, and selected decompilation shows `spider_pain` consuming the slot directly. | High |
| `0x10061344` | `spider_pain1_sound_slot` | `src/game/m_spider.c` | Retail spawn caches `"gladiator/pain.wav"` here, and selected decompilation shows `spider_pain` consuming the slot directly. | High |
| `0x10061348` | `spider_search_sound_slot` | `src/game/m_spider.c` | Retail spawn caches `"gladiator/gldsrch1.wav"` here, and selected decompilation shows `spider_search` consuming the slot directly. | High |
| `0x100305A0` | `SaveClientData` | `src/game/p_client.c` | Direct body iterates player edicts and copies health / max_health / saved flags back into the client blocks before save/load or map spawn reset. | High |
| `0x10032250` | `ClientBeginServerFrame` | `src/game/p_client.c` | Direct body handles end-of-frame respawn checks, animation/weapon state, player-trail upkeep, and spectator timing, with no standalone stock chase-camera upkeep in the recovered retail flow. | High |
| `0x10032530` | `BeginIntermission` | `src/game/p_hud.c` | Direct body sets intermission state, chooses an intermission/start/deathmatch target, stores the shared intermission origin/angles, and moves clients there. | High |
| `0x10033120` | `PlayerTrail_Init` | `src/game/p_trail.c` | Direct body allocates the rotating `player_trail` markers in non-deathmatch, resets the trail cursor, and enables the trail system. | High |

## RTDU Item And Remote Turret Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10014270` | `rtdu_use` | `src/game/g_rtdu.c` | Direct body checks the owner client RTDU slot at `0xF18`; if it still points at an entity labeled `RTDU`, it toggles `RTDU_BeginRemoteView` vs `RTDU_EndRemoteView` based on the dummy-body flag at `0xF0C`, otherwise it spawns a fresh turret through `RTDU_SpawnTurret`. | High |
| `0x100142E0` | `RTDU_SpawnTurret` | `src/game/g_rtdu.c` | Direct body allocates a new edict through `G_Spawn`, calls `RTDU_InitTurret`, stores the owning player pointer, copies player origin plus yaw into the spawned turret, and records the turret in the owner client slot at `0xF18`. | High |
| `0x10014320` | `RTDU_TurretThink` | `src/game/g_rtdu.c` | Direct think body validates that the owner and client RTDU slot still point back to this turret, mirrors origin and angles into the linked tripod child without reapplying the init-time `+40` Z lift, refreshes its timing field, and rearms itself at `FRAMETIME`. | High |
| `0x100144C0` | `RTDU_RemoveTurret` | `src/game/g_rtdu.c` | Direct teardown body clears the owner's RTDU inventory slot via the cached item pointer, calls `RTDU_EndRemoteView`, clears the owner client slot at `0xF18`, and schedules delayed cleanup. | High |
| `0x10014530` | `RTDU_BeginRemoteView` | `src/game/g_rtdu.c`, `src/game/g_camera.c` | Direct body calls the retail dummy-body setup helper at `0x10002D40`, backs up the owner client field at `0x58` into `0xF28`, zeroes the live field, installs the recovered RTDU client callback `0x10014750` at `0xF10`, resets short counters, and seeds a `15.0` second timer plus the turret activation timestamp; the current source now models that flow through `RemoteView_Begin` plus the RTDU-specific callback/timer aliases. | Medium |
| `0x100145C0` | `RTDU_EndRemoteView` | `src/game/g_rtdu.c`, `src/game/g_camera.c` | Direct body clears the activation timestamp, drops the owner client callback pointer, restores client field `0x58` from `0xF28`, zeroes the backup, and calls the retail dummy-body teardown helper at `0x10002DE0`; the current source now models that flow through `RemoteView_End` plus the RTDU-specific callback/timer aliases. | Medium |
| `0x10014610` | `RTDU_TurretAttack` | `src/game/g_rtdu.c` | Direct fire-loop body decrements stored ammo and the owner's RTDU inventory count, derives the muzzle point through `AngleVectors` plus `G_ProjectSource`, fires a shared projectile helper with the RTDU constants, advances the turret frame loop from `7` through `15`, and emits `PlayerNoise` for the owner. | High |
| `0x10014750` | RTDU remote-view client callback | `src/game/g_rtdu.c` `RTDU_RemoteViewCmd` | Direct retail disassembly shows the callback zeroing `forwardmove`, `sidemove`, `upmove`, and `usercmd.angles[0..2]`, translating those angles into the tracked turret's `s.angles` with the pitch component scaled by `1/3`, and triggering `RTDU_TurretAttack` when the attack bit is set before masking the bit back out. | High |
| `0x100147D0` | `RTDU_InitTurret` | `src/game/g_rtdu.c` | Direct init body labels the turret with `RTDU`, loads `models/objects/rtdu/rtdu.md2`, caches the `rtdu` item pointer, installs `RTDU_TurretThink` plus `RTDU_RemoveTurret`, then spawns a linked child labeled `RTDUTripod` with `models/objects/rtdu/tripod.md2` at `origin.z + 40` via retail constant `data_10044288 = 0x42200000`. | High |

- Retail string and item-surface evidence in `gamex86.dll` now directly anchors `weapon_rtdu`, `RTDU`, `w_rtdu`, `models/objects/rtdu/rtdu.md2`, `pARTDUTripod`, and `models/objects/rtdu/tripod.md2`.
- The current reconstruction in [g_rtdu.c](/E:/Repositories/Oblivion-reverse/src/game/g_rtdu.c) and [g_camera.c](/E:/Repositories/Oblivion-reverse/src/game/g_camera.c) now follows the retail placeable-turret plus remote-view-plus-dummy-body split, including behavioral aliases for the `0x10002CA0` / `0x10002D40` / `0x10002DE0` / `0x10002E20` helper cluster and for the RTDU input callback body at `0x10014750`.
- No RTDU-specific gaps remain in this recovered band: retail `ReadLevel` only clears client `pers.connected @ +0x2D0` after restoring `edict.client`, so the old source-side `G_RestoreRTDUTurretLinks()` save/load relink step has been removed as a non-retail helper.

## Generic Remote-View And Retail Camera Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10002EB0` | shared remote-view attach helper | `src/game/g_camera.c` `RemoteView_AttachController`, plus `src/game/g_camera.c` camera-controller callsites | Direct body checks whether client slot `0xF18` is empty, stores the tracked entity there, calls the dummy-body setup helper at `0x10002D40`, backs up `ps.gunindex` into `0xF28`, zeroes the live field, installs the callback stored in `PTR_LAB_10046048` into `0xF10`, and clears the remote-view state slots at `0xF24`, `0xF20`, and `0xF1C`. | High |
| `0x10002F20` | shared remote-view detach helper | `src/game/g_camera.c` `RemoteView_DetachController`, plus `src/game/g_camera.c` camera-controller callsites | Direct body checks whether client slot `0xF18` matches the passed entity, calls the dummy-body teardown helper at `0x10002DE0`, clears the tracked entity slot, restores `ps.gunindex` from `0xF28`, and clears `0xF0C` plus `0xF10`. | High |
| `0x10002F70` | shared controller or path move-step state machine | `src/game/g_camera.c` `Camera_MoveStep` | Direct state machine advances the `misc_camera` and `misc_camera_target` path fields at `0x320..0x34C`, including the `no main move` split, the delayed `movetarget->delay` handoff, and the `G_PickTarget` hop into the next node. | High |
| `0x100031A0` | shared remote-view input-suppression callback | `src/game/g_camera.c` `Camera_RemoteViewCmd` | Direct body loads the tracked entity from `0xF18`, checks its spawnflags bit `1`, then zeroes `usercmd.angles[0..2]`, `forwardmove`, `sidemove`, and `upmove`, and masks `buttons &= 0xFC`; the current retail camera path now mirrors that behavior directly. | High |
| `0x100031E0` | shared detach-all / tracked-entity cleanup helper | `src/game/g_camera.c` `Camera_Deactivate` | Direct body iterates clients, calls `0x10002F20` for the passed entity, then clears the target entity's motion or state fields; this matches the retail `misc_camera` deactivate or cleanup path and replaces the old stock chase-camera teardown model. | Medium |
| `0x10003392` | `misc_camera` activation block | `src/game/g_camera.c` `Camera_Activate` | Direct body temporarily sets `PTR_LAB_10046048 = &LAB_100031A0`, iterates live clients, calls the shared attach helper `0x10002EB0(client, controller)` for each, then clears the global callback pointer again before arming the controller; retail `misc_camera` reuses the shared remote-view helpers rather than a bespoke RTDU-only path. | High |
| `0x100035D0` | `misc_camera` use toggle | `src/game/g_camera.c` `Camera_Use` | Direct wrapper checks the controller `count` flag at `0x254` and dispatches either to the shared detach or activate helper. | High |
| `0x100035F0` | `SP_misc_camera` | `src/game/g_camera.c` `SP_misc_camera` | Direct spawn body clears bbox extents, enforces `MOVETYPE_FLYMISSILE`, `SOLID_NOT`, and `SVF_NOCLIENT`, defaults `wait` to `3.0`, installs the `misc_camera` use or think callbacks, and precaches `sprites/s_deatom1.sp2`. | High |
| `0x100036B0` | `misc_camera_target` think | `src/game/g_camera.c` `Camera_TargetThink` | Direct body handles the `delay == -1.0` stop sentinel, otherwise runs the shared move-step helper until `0x32C` catches up with `level.time`, then schedules the next tick from the shared path deadline. | High |
| `0x10003760` | `misc_camera_target` use toggle | `src/game/g_camera.c` `Camera_TargetUse` | Direct toggle wrapper either clears the active flag plus motion state or resolves the first target node, seeds speed or origin fields, and arms the next think at `level.time + 0.1`. | High |
| `0x10003880` | `SP_misc_camera_target` | `src/game/g_camera.c` `SP_misc_camera_target` | Direct spawn body clears bbox extents, enforces `MOVETYPE_FLYMISSILE`, `SOLID_NOT`, and `SVF_NOCLIENT`, zeros the active or `movetarget` fields, installs the retail target use or think callbacks, and precaches `sprites/s_deatom1.sp2`. | High |
| `0x10003BA0` | `SP_trigger_misc_camera` | `src/game/g_camera.c` `SP_trigger_misc_camera`, `TriggerCamera_Fire`, `TriggerCamera_Use`, `TriggerCamera_Touch` | Direct trigger wrapper reuses the stock trigger sound variants, `trigger_enable`, and `multi_wait` timing helpers, then walks the trigger `targetname` set until it finds a `misc_camera`, copies the trigger `wait` or `pathtarget` overrides, and either activates or refreshes the retail camera controller. | High |

## Monster Utility And Startup Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10001F40` | `M_CheckAttack` | `src/game/g_monster.c` | Direct body matches the stock melee-or-missile decision helper, and `monster_start` installs it into `monsterinfo.checkattack` at the expected default site. | High |
| `0x10011B90` | `M_FlyCheck` | `src/game/g_monster.c` | Direct body skips water, random-gates, then arms `M_FliesOn` on the same delayed timer used by stock Quake II. | High |
| `0x10011C00` | `M_FliesOn` | `src/game/g_monster.c` | Direct body enables `EF_FLIES`, plays `infantry/inflies1.wav`, and schedules `M_FliesOff` after `60` seconds when the monster is not in water. | High |
| `0x10011C50` | `M_FliesOff` | `src/game/g_monster.c` | Tiny direct callback created from the exact delayed target used by `M_FliesOn`; it clears `s.sound` and masks out `EF_FLIES` exactly like the stock local helper. | High |
| `0x10011D90` | `M_CatagorizePosition` | `src/game/g_monster.c` | Direct body samples contents at the feet, waist, and head offsets and writes the stock `waterlevel` / `watertype` ladder. | High |
| `0x10011E50` | `M_WorldEffects` | `src/game/g_monster.c` | Direct body handles drowning or suffocation timers plus lava/slime damage and water enter or exit sounds. | High |
| `0x10012170` | `M_droptofloor` | `src/game/g_monster.c` | Direct body nudges origin upward, traces down, copies the end position, relinks, then calls `M_CheckGround` and `M_CatagorizePosition`. | High |
| `0x10012230` | `M_SetEffects` | `src/game/g_monster.c` | Direct body clears shell/powerscreen bits, applies the resurrecting shell, and enables power-armor screen or shield effects from the active timer. | High |
| `0x100122C0` | `M_MoveFrame` | `src/game/g_monster.c` | Direct body advances the active `mmove_t` frame range, honors `AI_HOLD_FRAME`, calls the move `endfunc` when needed, schedules `nextthink`, and dispatches the per-frame AI and think callbacks with the stock scaled distance argument. | High |
| `0x100123C0` | `monster_think` | `src/game/g_monster.c` | Direct body runs the moveframe helper, refreshes ground or water classification, applies `M_WorldEffects`, and finishes with `M_SetEffects`. | High |
| `0x10012410` | `monster_use` | `src/game/g_monster.c` | Direct body rejects already-engaged, dead, or `FL_NOTARGET` activators, then accepts client or `AI_GOOD_GUY` activators, stores them as `enemy`, and hands off to `FoundTarget`. | High |
| `0x10012460` | `monster_triggered_spawn` | `src/game/g_monster.c` | Direct body reactivates the hidden triggered monster, relinks it, hands off to `monster_start_go`, and optionally calls `FoundTarget` when the stored enemy is still valid. | High |
| `0x100124F0` | `monster_triggered_spawn_use` | `src/game/g_monster.c` | Direct callback created at the exact delayed-use address from `monster_triggered_start`; it queues `monster_triggered_spawn`, stores a client activator as `enemy`, and then swaps in `monster_use` as the steady-state `use` handler. | High |
| `0x10012530` | `monster_triggered_start` | `src/game/g_monster.c` | Direct body makes the monster non-solid and hidden, clears `nextthink`, and installs `monster_triggered_spawn_use` as the delayed activation callback. | High |
| `0x10012570` | `monster_death_use` | `src/game/g_monster.c` | Direct body clears fly/swim AI bits, drops the pending item, swaps `deathtarget` into `target`, and routes through `G_UseTargets`. | High |
| `0x100125E0` | `monster_start` | `src/game/g_monster.c` | Direct body performs the stock monster init pass: deathmatch free, spawnflag fixup, total-monsters count, default flags, `FindItemByClassname(st.item)`, `oldorigin` copy, and default `M_CheckAttack`. | High |
| `0x10012750` | `monster_start_go` | `src/game/g_monster.c` | Direct body validates `target` / `combattarget`, resolves `movetarget` through `G_PickTarget`, accepts `path_corner` or `target_actor` startup nodes, and then installs `monster_think`. | High |
| `0x10012A80` | `walkmonster_start_go` | `src/game/g_monster.c` | Direct body uses `M_droptofloor` and `M_walkmove(..., 0, 0)` at the stock solid-check sites, seeds yaw speed and viewheight, then hands off to `monster_start_go`. | High |
| `0x10012B30` | `walkmonster_start` | `src/game/g_monster.c` | Tiny direct wrapper stores `walkmonster_start_go` in `think` and then calls `monster_start`. | High |
| `0x10012B50` | `flymonster_start_go` | `src/game/g_monster.c` | Direct body performs the stock airborne solid check, seeds yaw speed and viewheight including the `monster_flyer` special case, then hands off to `monster_start_go`. | High |
| `0x10012C10` | `flymonster_start` | `src/game/g_monster.c` | Tiny direct wrapper sets `FL_FLY`, stores `flymonster_start_go` in `think`, and then calls `monster_start`. | High |
| `0x10012C40` | `swimmonster_start_go` | `src/game/g_monster.c` | Direct body seeds the swim-monster defaults, calls `monster_start_go`, and uses the same triggered-start handoff as the walk/fly wrappers. | High |
| `0x10012C90` | `swimmonster_start` | `src/game/g_monster.c` | Tiny direct wrapper sets `FL_SWIM`, stores `swimmonster_start_go` in `think`, and then calls `monster_start`. | High |

## Projectile, Plasma, Mine, And Detpack Helpers

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10011AF0` | `monster_fire_deatom` | `src/game/g_monster.c` | Thin direct wrapper used by the recovered soldier/cyborg deatom callsites; retail only forwards into `fire_deatom`, so the current source-level muzzleflash tail is not present at this wrapper address. | High |
| `0x1001BF10` | `blaster_touch` | `src/game/g_weapon.c` | Direct body rejects owner hits and sky surfaces, emits `PlayerNoise` for client owners, uses `self->count` or the hyper-blaster spawnflag to choose `MOD_BLASTER` vs `MOD_HYPERBLASTER`, writes `TE_BLASTER` on world impacts, and frees the bolt. | High |
| `0x1001C000` | `fire_blaster` | `src/game/g_weapon.c` | Direct body normalizes aim, spawns the stock laser-bolt projectile with `models/objects/laser/tris.md2`, `misc/lasfly.wav`, `blaster_touch`, `G_FreeEdict`, and `bolt` classname wiring, applies the hyper spawnflag when requested, calls `check_dodge`, and preserves the immediate trace-on-spawn impact path. | High |
| `0x1001C4A0` | `Grenade_Explode` | `src/game/g_weapon.c` | Direct body applies held-grenade impact damage when needed, routes splash through the stock grenade damage path, emits the expected temp-entity effect class from grenade spawnflags, and frees the projectile. | High |
| `0x1001C740` | `fire_grenade2` | `src/game/g_weapon.c` | Direct body spawns the hand-grenade projectile, assigns `Grenade_Explode` as the timed callback, sets grenade spawnflags for held vs tossed state, and plays the armed-grenade sound when the timer stays live. | High |
| `0x1001C960` | `rocket_touch` | `src/game/g_weapon.c` | Direct body matches the stock rocket impact callback: it ignores owner hits and sky surfaces, emits `PlayerNoise`, rewinds the origin for the explosion temp entity, applies direct-hit damage, throws debris only in non-deathmatch non-coop world impacts, applies radius splash damage, writes the water-vs-air rocket explosion effect, and frees the projectile. | High |
| `0x1001CAD0` | `fire_rocket` | `src/game/g_weapon.c` | Direct body spawns the stock rocket projectile with the rocket model, direct `rocket_touch`, `G_FreeEdict` timeout, direct and splash damage fields, `rockfly.wav`, `rocket` classname, and the stock `check_dodge` warning call; `Weapon_RocketLauncher_Fire` reaches it directly. | High |
| `0x1001CC30` | `obliterator_projectile_think` | `src/game/g_weapon.c` | Direct body is only referenced as the `think` callback from `fire_obliterator_projectile`; the current source now mirrors that wobble helper directly by resetting `movedir` from the stored baseline, applying the owner's right/up perturbations, rebuilding velocity from `speed`, updating angles, and rearming the short timed callback while the projectile stays airborne. | High |
| `0x1001CD20` | `fire_obliterator_projectile` | `src/game/g_weapon.c` | Direct body is only called from `Weapon_Obliterator_Fire`; the current source now mirrors the helper directly by spawning the rocket-model projectile, preserving the retail direct/splash damage fields and `rockfly.wav`, reusing direct `rocket_touch`, seeding the straight `dir` baseline before the wobble think takes over, and keeping the stock `check_dodge` call site. | High |
| `0x1001CF50` | `fire_rail` | `src/game/g_weapon.c` | Direct body performs the stock rail trace through water and monster or client penetrations, applies direct damage, emits one or two `TE_RAILTRAIL` temp entities depending on water, and calls `PlayerNoise`; `weapon_railgun_fire` reaches it directly. | High |
| `0x1001D120` | `bfg_explode` | `src/game/g_weapon.c` | Direct body matches the stock terminal BFG effect: on frame 0 it walks `findradius` over `dmg_radius`, gates damage through dual `CanDamage` checks against both the projectile and owner, emits `TE_BFG_EXPLOSION`, applies the falloff effect damage, advances the frame counter, and hands off to `G_FreeEdict` on frame 5. | High |
| `0x1001D2E0` | `bfg_touch` | `src/game/g_weapon.c` | Direct body matches the stock BFG impact callback: it ignores owner hits and sky surfaces, emits `PlayerNoise`, applies the direct-hit and splash blast damage, rewinds the origin slightly, swaps to `sprites/s_bfg3.sp2`, clears touch and velocity, rearms `bfg_explode`, and emits the big-explosion temp entity. | High |
| `0x1001D440` | `bfg_think` | `src/game/g_weapon.c` | Direct body matches the stock BFG laser sweep: it uses deathmatch-vs-singleplayer damage, scans a 256-unit radius, filters to monsters, clients, or `misc_explobox`, traces the beam through penetrations, applies `MOD_BFG_LASER`-style hits, emits `TE_LASER_SPARKS` and `TE_BFG_LASER`, and rearms the short think interval. | High |
| `0x1001D6F0` | `fire_bfg` | `src/game/g_weapon.c` | Direct body spawns the stock BFG projectile with `sprites/s_bfg1.sp2`, `bfg_touch`, `bfg_think`, `weapons/bfg__l1a.wav`, `bfg blast`, retail direct and radius damage fields, and the stock `check_dodge` call; `weapon_bfg_fire` reaches it directly. | High |
| `0x1001D870` | `fire_proximity_mine` | `src/game/g_weapon.c` | Direct body spawns the retail `mine` projectile with the mine model, toss velocity plus the random up or right bias, `proximity_mine_touch` / `proximity_mine_think` / `proximity_mine_die`, health `10`, splash fields `150/100/180`, the `weapons/hgrent1a.wav` throw sound, and the per-owner five-mine cap enforcement loop. | High |
| `0x1001DB40` | `proximity_mine_explode` | `src/game/g_weapon.c` | Direct body zeroes velocity, applies splash-only damage with the mine obituary path, emits the retail grenade-or-rocket explosion temp entity chosen by water or ground state, and frees the entity; `fire_proximity_mine` routes over-limit cleanup through it. | High |
| `0x1001DC00` | `proximity_mine_think` | `src/game/g_weapon.c` | Direct armed-think callback scans a `100`-unit radius around the resting mine, rearms itself while idle, and hands off into `proximity_mine_laser_start` when it finds a `DAMAGE_AIM` target. | High |
| `0x1001DC60` | `proximity_mine_laser_start` | `src/game/g_weapon.c` | Direct body switches the mine into the retail lift phase by setting `MOVETYPE_FLY`, clearing spin and `s.angles`, seeding the upward lift vector and velocity, arming the loop sound, and handing off to `proximity_mine_laser_think`. | High |
| `0x1001DD00` | `proximity_mine_laser_think` | `src/game/g_weapon.c` | Direct body runs the retail triggered laser phase: on first entry it makes the mine non-solid, changes the parent spin to `(0,74,0)`, spawns four chained child `mine laser` entities via `target_laser_start` with spawnflags `0x89`, refreshes their beam basis on each tick, counts `30` phase steps, then frees the child chain and swaps back into `proximity_mine_explode`. | High |
| `0x1001DED0` | `proximity_mine_touch` | `src/game/g_weapon.c` | Direct touch callback plays the mine placement sound, arms the delayed think timer, and when the touch target is a `DAMAGE_AIM` actor it freezes motion and swaps immediately onto the detonation path. | High |
| `0x1001DF50` | `proximity_mine_die` | `src/game/g_weapon.c` | Direct die callback checks whether the mine is still in the armed watch phase and, if so, swaps it to `proximity_mine_explode` on a short delay instead of exploding inline. | High |
| `0x1001DF80` | `deatom_touch` | `src/game/g_monster.c` | Direct body matches the monster deatom-bolt impact callback: owner/sky rejection, `PlayerNoise`, `deatom/dimpact.wav`, direct energy damage with `MOD_DEATOMIZER`, the blue hyperblaster temp entity on world hits, and `G_FreeEdict`. | High |
| `0x1001E070` | `deatom_think` | `src/game/g_monster.c` | Direct body cycles the bolt frame, validates the tracked client target, applies the same dot-gated homing turn with deathmatch-vs-singleplayer scale, updates velocity/angles, and rearms the short think interval. | High |
| `0x1001E240` | `fire_deatom` | `src/game/g_monster.c` | Direct body spawns the retail `deatom_bolt` projectile with `models/objects/deatom/tris.md2`, `deatom/dfly.wav`, `deatom_touch`, the homing target-acquisition loop through `findradius`/`visible`, and `deatom_think` as the timed callback. | High |
| `0x1001E520` | `plasma_bolt_touch` | `src/game/g_weapon.c` | Direct body rejects owner/sky hits, plays `plasma1/hit.wav` or `plasma2/hit.wav` by spawnflag, applies energy damage with the pistol-vs-rifle obituary split on takedamage targets, otherwise emits `TE_PLASMA_EXPLOSION`, then frees the bolt. | High |
| `0x1001E640` | `fire_plasma_bolt` | `src/game/g_weapon.c` | Direct body normalizes aim, spawns either `models/objects/pistolplasma/tris.md2` or the rifle plasma model by mode flag, assigns `plasma_bolt_touch`, does the immediate collision trace, and reuses `check_dodge` at the stock projectile-warning site. | High |
| `0x1001E820` | `detpack_detonate` | `src/game/g_weapon.c` | Direct body now matches the reconstructed retail callback: it clears takedamage, emits owner `PlayerNoise`, chooses the retail water-vs-ground explosion temp entity, applies radius damage from the detpack damage fields, and frees the charge. | High |
| `0x1001E8F0` | `fire_detpack` | `src/game/g_weapon.c` | Direct body now matches the reconstructed retail tossed-charge path: it uses the recovered toss constants with fixed `-40` roll, sets `FL_NO_KNOCKBACK` and the retail spin, optionally arms timed self-detonation, and enforces the owner-scoped five-charge cap without the stray `EF_GRENADE` or preseeded health fields. | High |
| `0x1001ECA0` | `dod_client_reset` | no current one-to-one counterpart in `src/game/`; nearest analogue is temporary client-side weapon/view cleanup | Tiny direct helper only stored into an owner-client callback slot by `fire_dod`; it zeroes three short fields in the callback output block, so it is recorded as a retail-only DoD cleanup/reset helper rather than forced into a current source name. | Medium |
| `0x1001ECC0` | `dod_pulse_think` | no current one-to-one counterpart in `src/game/g_weapon.c`; nearest analogue is the timed `dod_explode` / `fire_donut` effect path | Direct body is the timed callback installed by `fire_dod`; it advances `s.frame` through the DoD model's ten-step pulse animation, grows the stored damage/radius fields, applies repeated radius damage with the retail donut obituary id, then switches to `G_FreeEdict` and clears the owner-client callback slot. | Medium |
| `0x1001ED70` | `fire_dod` | `src/game/g_weapon.c` | Direct body spawns the DoD projectile with the retail model and sound, seeds the short timed callback, and stores the expected DoD damage-radius fields; `Weapon_DOD_Fire` reaches it directly. | High |

## HUD, Trail, And View Pipeline

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x100327C0` | `DeathmatchScoreboardMessage` | `src/game/p_hud.c` | Direct body builds the sorted frag board layout and is called from both `MoveClientToIntermission` and `ClientEndServerFrame` before `gi.unicast`. | High |
| `0x10032AC0` | `DeathmatchScoreboard` | `src/game/p_hud.c` | Direct body is the expected thin wrapper: `DeathmatchScoreboardMessage(ent, ent->enemy)` followed by `gi.unicast`. | High |
| `0x10032B50` | `HelpComputer` | `src/game/p_hud.c` | Direct body formats the help-layout string with skill/objective text and unicasts it; `Cmd_Help_f` calls it on the non-deathmatch path. | High |
| `0x10032CA0` | `G_SetStats` | `src/game/p_hud.c` | Direct body fills health/ammo/armor, the stock powerup timer slot, selected-item, layout, and help stats; no extra retail plasma/DoD timer HUD pass or stock chase/spectator HUD overlay surfaced beyond that stock stat flow. | High |
| `0x10033170` | `PlayerTrail_Add` | `src/game/p_trail.c` | Direct body writes the next trail marker origin, timestamp, and yaw into the rotating `trail[]` ring. | High |
| `0x10033320` | `PlayerTrail_LastSpot` | `src/game/p_trail.c` | Tiny direct body returns `trail[PREV(trail_head)]`. | High |
| `0x10033340` | `SV_CalcRoll` | `src/game/p_view.c` | Direct body computes signed side velocity, clamps against `sv_rollspeed`, and scales by `sv_rollangle`. | High |
| `0x100333C0` | `P_DamageFeedback` | `src/game/p_view.c` | Direct body sets flash bits, pain animations, pain sounds, blended damage colors, and kick angles, then clears the accumulated damage counters. | High |
| `0x10033820` | `SV_CalcViewOffset` | `src/game/p_view.c` | Direct body composes view offset from kick/origin fall/bob terms and clamps the final view vector. | High |
| `0x10033B10` | `SV_CalcGunOffset` | `src/game/p_view.c` | Direct body derives gun angles/origin from bobbing, delta angles, and configured gun offsets. | High |
| `0x10033D00` | `SV_CalcBlend` | `src/game/p_view.c` | Direct body samples view contents, adds water/lava/slime and powerup blends, and merges timed damage/fade blends into `ps.blend`. | High |
| `0x10034110` | `P_FallingDamage` | `src/game/p_view.c` | Direct body compares current and previous vertical velocity, applies water-level scaling, triggers landing events, and deals fall damage when needed. | High |
| `0x10034310` | `P_WorldEffects` | `src/game/p_view.c` | Direct body handles water entry/exit sounds, drowning, envirosuit/breather timing, lava/slime pain, and related `PlayerNoise` emissions. | High |
| `0x10034930` | `G_SetClientEffects` | `src/game/p_view.c` | Direct body clears `s.effects` / `s.renderfx`, then reapplies power armor, quad, invulnerability, and godmode shells. | High |
| `0x10034A40` | `G_SetClientEvent` | `src/game/p_view.c` | Direct body emits `EV_FOOTSTEP` when the bob cycle advances while grounded and moving fast enough. | High |
| `0x10034A90` | `G_SetClientSound` | `src/game/p_view.c` | Direct body handles the help beep cadence and chooses between frying, railgun hum, BFG hum, custom weapon sound, or silence. | High |
| `0x10034BF0` | `G_SetClientFrame` | `src/game/p_view.c` | Direct body advances player animation frames across stand/run/duck/jump/pain transitions using the stock model-frame bands. | High |
| `0x100350A0` | `PlayerNoise` | `src/game/p_weapon.c` | Direct body manages the two per-player noise entities and stamps origin/type for self and impact noise; callsites match jump, water, and weapon-impact paths across `p_client.c`, `p_view.c`, and `g_weapon.c`. | High |
| `0x10035830` | `Think_Weapon` | `src/game/p_weapon.c` | Direct body clears the no-ammo flag when needed and dispatches through the equipped weapon's `weaponthink` callback; `ClientThink` and `ClientBeginServerFrame` call it at the stock weapon-thunk sites, while plasma regeneration remains a separate `ClientThink` tail call through `Oblivion_UpdateWeaponRegen`. | High |

## Weapon Core And Firing Pipeline

| Address | Likely symbol | Current counterpart | Evidence | Confidence |
| --- | --- | --- | --- | --- |
| `0x10035420` | `ChangeWeapon` | `src/game/p_weapon.c` | Direct body cancels any active grenade-style hold timer by snapping `grenade_time` to `level.time`, clearing `weapon_sound`, and zeroing the timer without forcing a throw, then swaps `lastweapon` / `weapon` / `newweapon`, recomputes `ammo_index`, updates the visible weapon model, and enters `WEAPON_ACTIVATING`. | High |
| `0x10035530` | `NoAmmoWeaponChange` | `src/game/p_weapon.c` | Direct body preserves `weapon_plasma_rifle`, otherwise checks the stock Quake II fallback order (`railgun`, `hyperblaster`, `chaingun`, `machinegun`, `super shotgun`, `shotgun`) before defaulting to `Plasma Pistol`. | High |
| `0x100358C0` | `Use_Weapon` | `src/game/p_weapon.c` | Direct body early-outs on the current weapon, checks ammo sufficiency when empty selection is disallowed, prints `No %s for %s.` / `Not enough %s for %s.`, and stores `newweapon`. | High |
| `0x10035980` | `Drop_Weapon` | `src/game/p_weapon.c` | Direct body honors `DF_WEAPONS_STAY`, blocks dropping the last currently equipped weapon with `Can't drop current weapon`, then calls `Drop_Item` and decrements inventory. | High |
| `0x10035A10` | `Weapon_Generic` | `src/game/p_weapon.c` | Direct body is the stock Quake II weapon-state machine for activating, dropping, idling, firing, attack animation setup, no-ammo handling, and `ChangeWeapon` transitions. | High |
| `0x10035CA0` | `weapon_grenade_fire` | `src/game/p_weapon.c` | Direct body computes held-grenade timing and speed, fires the projectile, decrements ammo, and sets the throw animation state. | High |
| `0x10035E20` | `Weapon_Grenade` | `src/game/p_weapon.c` | Direct body matches the hand-grenade weapon state machine: ready, cook, held detonation, throw release, and `weapon_grenade_fire` call sites. | High |
| `0x100360B0` | `weapon_grenadelauncher_fire` | `src/game/p_weapon.c` | Direct body projects the muzzle source, applies kick, fires the grenade-launcher projectile, emits `MZ_GRENADE`, calls `PlayerNoise`, and decrements ammo. | High |
| `0x10036210` | `Weapon_GrenadeLauncher` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 5, 16, 59, 64, ..., weapon_grenadelauncher_fire)`, matching the retail grenade-launcher frame band. | High |
| `0x10036240` | `Weapon_RocketLauncher_Fire` | `src/game/p_weapon.c` | Direct body rolls retail rocket damage, applies kick, fires the rocket projectile, emits `MZ_ROCKET`, calls `PlayerNoise`, and decrements ammo. | High |
| `0x100363D0` | `Weapon_RocketLauncher` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 4, 12, 50, 54, ..., Weapon_RocketLauncher_Fire)`. | High |
| `0x10036400` | `Blaster_Fire` | `src/game/p_weapon.c` | Direct body matches the shared blaster-shot helper with offset, damage, hyper, and effect parameters, then spawns the projectile through the retail blaster path. | High |
| `0x10036560` | `Weapon_Blaster_Fire` | `src/game/p_weapon.c` | Direct body selects `10` or `15` damage by deathmatch, calls `Blaster_Fire(..., EF_BLASTER)`, and advances the gunframe. | High |
| `0x100365B0` | `Weapon_Blaster` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 4, 8, 52, 55, ..., Weapon_Blaster_Fire)`. | High |
| `0x100365E0` | `Weapon_HyperBlaster_Fire` | `src/game/p_weapon.c` | Direct body matches the spinning hyperblaster loop: attack-button gating, rotating muzzle offsets, repeated `Blaster_Fire(..., hyper=true)`, muzzleflash selection, and ammo drain. | High |
| `0x10036790` | `Weapon_HyperBlaster` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 5, 20, 49, 53, ..., Weapon_HyperBlaster_Fire)`. | High |
| `0x100367C0` | `Machinegun_Fire` | `src/game/p_weapon.c` | Direct body matches the stock machinegun loop: attack-button gating, alternating `gunframe` 4 or 5, no-ammo bailout, recoil jitter, bullet fire, muzzleflash, noise, and ammo decrement. | High |
| `0x10036AC0` | `Weapon_Machinegun` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 3, 5, 45, 49, ..., Machinegun_Fire)`. | High |
| `0x10036AF0` | `Chaingun_Fire` | `src/game/p_weapon.c` | Direct body matches the stock chaingun ramp: spin-up and spin-down sounds, variable shot count by `gunframe`, recoil offsets, repeated bullet fire, muzzleflash, noise, and multi-round ammo drain. | High |
| `0x10036EB0` | `Weapon_Chaingun` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 4, 31, 61, 64, ..., Chaingun_Fire)`. | High |
| `0x10036EE0` | `weapon_shotgun_fire` | `src/game/p_weapon.c` | Direct body matches the stock shotgun path: projected muzzle source, `DEFAULT_SHOTGUN_COUNT` or deathmatch count, `MZ_SHOTGUN`, noise, and single-shell ammo drain. | High |
| `0x10037080` | `Weapon_Shotgun` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 7, 18, 36, 39, ..., weapon_shotgun_fire)`. | High |
| `0x100370B0` | `weapon_supershotgun_fire` | `src/game/p_weapon.c` | Direct body matches the stock super-shotgun dual spread path: two yaw-shifted shotgun volleys, `MZ_SSHOTGUN`, noise, and two-shell ammo drain. | High |
| `0x100372A0` | `Weapon_SuperShotgun` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 6, 17, 57, 61, ..., weapon_supershotgun_fire)`. | High |
| `0x100372D0` | `weapon_railgun_fire` | `src/game/p_weapon.c` | Direct body matches retail railgun damage and kick setup, projected muzzle source, rail trail fire, muzzleflash, noise, and ammo decrement. | High |
| `0x10037450` | `Weapon_Railgun` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 3, 18, 56, 61, ..., weapon_railgun_fire)`. | High |
| `0x10037480` | `weapon_bfg_fire` | `src/game/p_weapon.c` | Direct body matches BFG charge/fire behavior, hands projectile creation off to direct `fire_bfg`, preserves the large retail damage radius, writes the expected muzzleflash, and decrements ammo. | High |
| `0x10037680` | `Weapon_BFG` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 8, 32, 55, 58, ..., weapon_bfg_fire)`. | High |
| `0x100376B0` | `Weapon_ProximityMines_Fire` | `src/game/p_weapon.c` | Direct body projects the muzzle source, computes the retail grenade-style throw-speed ramp from `grenade_time`, calls `fire_proximity_mine`, decrements ammo, and seeds the short follow-up timer. | High |
| `0x10037790` | `Weapon_ProximityMines` | `src/game/p_weapon.c` | Direct body is now reconstructed as the retail custom state machine: it drives the ready-loop frames, arm or cook sounds, hold timing, forced release, and explicit calls into `Weapon_ProximityMines_Fire` instead of routing through `Weapon_Generic`. | High |
| `0x10037A10` | `Weapon_Deatomizer_Fire` helper | retail split of `src/game/p_weapon.c` `Weapon_Deatomizer_Fire` | Direct body handles the 10-cell ammo gate, shot emission, railgun-style muzzleflash, `deatom/dfire.wav`, and `PlayerNoise`; retail splits the current source-level fire body around this helper. | High |
| `0x10037BF0` | source-shaped `Weapon_Deatomizer_Fire` wrapper | `src/game/p_weapon.c` | Retail wrapper-level stub computes the randomized deatomizer damage, calls `0x10037A10`, and bumps gunframe; `Weapon_Deatomizer @ 0x10037C50` points at this wrapper via `LAB_10037BF0`. | Medium |
| `0x10037C50` | `Weapon_Deatomizer` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 11, 21, 43, 49, ..., LAB_10037BF0)`, confirming the retail deatomizer wrapper and the split fire path. | High |
| `0x10037C80` | `Pickup_RiflePlasma` | `src/game/p_weapon.c` and `src/game/g_items.c` | Direct body checks `other->client`, increases `pers.max_rifleplasma` by `50`, increments `pers.plasma_rifle_regen_divisor`, then calls `Add_Ammo(other, ent->item, ent->item->quantity)` and returns success. The retail `ammo_rifleplasma` item-table row at `0x10047150` points its `pickup` field here and carries quantity `50` with flags `IT_AMMO | IT_POWERUP`. | High |
| `0x10037DE0` | `Weapon_Plasma_Fire` | `src/game/p_weapon.c` `Weapon_PlasmaPistol_Fire` / `Weapon_PlasmaRifle_Fire` | Direct body is the retail shared player-plasma fire helper: it takes the shared zero-vector data slot at `0x10061C18`, adds the retail `+16,+8,-8` muzzle bias internally, applies kick, calls `fire_plasma_bolt` at `2000` speed, emits `MZ_BLASTER2`, calls `PlayerNoise`, and decrements either `PistolPlasma` by `1` or `Rifle Plasma` by `5` based on a mode parameter before the wrapper-level sound plays. | High |
| `0x10037FA0` | `Weapon_PlasmaPistol_Fire` | `src/game/p_weapon.c` | Direct wrapper selects `10` or `15` damage by deathmatch, calls `Weapon_Plasma_Fire` in pistol mode, bumps gunframe, and plays `plasma1/fire.wav`; retail keeps the Plasma Pistol wrapper thin and pushes projectile work into the shared helper. | High |
| `0x10038020` | `Weapon_PlasmaPistol` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 6, 11, 32, 40, ..., Weapon_PlasmaPistol_Fire)`; the reconstruction now matches those retail frame bands while keeping the public item surface `weapon_plasma_pistol` / `Plasma Pistol` on `PistolPlasma` ammo and the `models/weapons/v_pistol/tris.md2` view model. | High |
| `0x10038050` | `Weapon_PlasmaRifle_Fire` | `src/game/p_weapon.c` | Direct wrapper selects `35` or `50` damage by deathmatch, calls `Weapon_Plasma_Fire` in rifle mode, bumps gunframe, and plays `plasma2/fire.wav`; like the pistol wrapper, retail keeps the Plasma Rifle front-end thin and leaves projectile spawn, ammo burn, and impact behavior in the shared helper path. | High |
| `0x100380D0` | `Weapon_PlasmaRifle` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 7, 10, 24, 32, ..., Weapon_PlasmaRifle_Fire)`; the reconstruction now matches those retail frame bands while keeping the public item surface `weapon_plasma_rifle` / `Plasma Rifle` on `Rifle Plasma` ammo, icon `w_plasma`, and the `models/weapons/v_plasma/tris.md2` view model. | High |
| `0x10038100` | `Weapon_DetonationPack_Fire` | `src/game/p_weapon.c` | Direct body throws the retail detpack path, decrements `Detonation Pack`, and on gunframe `14` forces the follow-up weapon switch into `Remote Detonator`; the current source now reconstructs that split as a standalone wrapper/fire pair. | High |
| `0x10038270` | `Weapon_DetonationPack` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 4, 14, 34, 39, ..., Weapon_DetonationPack_Fire)` for the retail detpack-throw weapon; the current source now matches those frame bands. | High |
| `0x100382A0` | `Weapon_RemoteDetonator_Fire` | `src/game/p_weapon.c` | Direct body scans live edicts for owned `detpack` entities, triggers them, clears the temporary `Remote Detonator` inventory slot, and reselects `Detonation Pack` or falls back through `NoAmmoWeaponChange`; the current source now mirrors that trigger-side retail flow after the detpack split. | High |
| `0x100383E0` | `Weapon_RemoteDetonator` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 4, 8, 28, 33, ..., Weapon_RemoteDetonator_Fire)`; the current source now matches those retail frame bands. | High |
| `0x10038410` | `Weapon_DOD_Fire` | `src/game/p_weapon.c` | Direct fire callback advances gunframe, launches the DOD projectile path, and decrements `DOD`; the retail body is leaner than the current source but preserves the ammo and projectile identity. | High |
| `0x10038490` | `Weapon_DOD` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 10, 15, 35, 46, ..., Weapon_DOD_Fire)`; the current source now matches those recovered retail frame bands. | High |
| `0x100384C0` | `Weapon_Obliterator_Fire` | `src/game/p_weapon.c` | Direct body now matches the retail four-step projectile burst through `fire_obliterator_projectile`, with the recovered laser-style muzzle offsets, one-cell ammo drain per shot, and frame-local spread changes. | High |
| `0x100386D0` | `Weapon_Obliterator` | `src/game/p_weapon.c` | Direct wrapper calls `Weapon_Generic(ent, 14, 27, 40, 48, ..., Weapon_Obliterator_Fire)` with four fire frames; the retail `weapon_hellfury` gitem entry at `0x10046EC8` points its `weaponthink` field here, so `HellFury` is now treated as the inventory-facing alias to the same wrapper. | High |

## Unconfirmed Reconstruction Hooks

These current reconstruction calls are still not backed by a direct retail signal in the recovered functions above:

- `Mission_FrameUpdate()` appears in `src/game/g_main.c`, but the recovered retail `G_RunFrame` body does not currently expose an obvious equivalent call site.
- `Mission_BeginLevel()` appears in `src/game/g_spawn.c`, but the recovered retail `SpawnEntities` body does not currently expose an obvious equivalent call site for the current source objective reset/re-arm layer.
- `Mission_OnGameLoaded()` appears in `src/game/g_save.c`, but the recovered retail `ReadGame` body only restores a `0x61C` `game` block through `game.autosaved`, so the current `game.mission` rebuild step is not backed by direct retail storage evidence.
- `Actor_PostLoad()` appears in `src/game/g_save.c`, but the recovered retail `ReadLevel` body does not currently expose an obvious equivalent call site.
- The old source-side `G_RestoreRTDUTurretLinks()` helper has been removed: retail `ReadLevel` only clears client `pers.connected @ +0x2D0` after restoring `edict.client`, and the current `ReadClient` path already preserves RTDU/view edict pointers against the stable `g_edicts` base.
- The core retail RTDU band is now directly recovered as `rtdu_use @ 0x10014270`, `RTDU_SpawnTurret @ 0x100142E0`, `RTDU_TurretThink @ 0x10014320`, `RTDU_RemoveTurret @ 0x100144C0`, `RTDU_BeginRemoteView @ 0x10014530`, `RTDU_EndRemoteView @ 0x100145C0`, `RTDU_TurretAttack @ 0x10014610`, the recovered RTDU input callback body at `0x10014750`, and `RTDU_InitTurret @ 0x100147D0`; the current source now reflects the retail remote-view-plus-dummy-body flow behaviorally through `RTDU_RemoteViewCmd`.
- `Cmd_UseToggle_f` and its private parser helper at `0x10004750` are now reconstructed in `src/game/g_cmds.c`, including the retail `usetoggle` dispatcher entry, apostrophe-delimited multiword item parsing, the retained unmatched-quote trailing-space edge case, and the `newweapon`-gated requested-item cycle.
- The retail `Weapon_ProximityMines` path is now reconstructed in `src/game/p_weapon.c`, including the grenade-style custom state machine, the non-throwing `ChangeWeapon` timer-cancel path, and the explicit hand-off into `Weapon_ProximityMines_Fire`.
- The retail mine item surface still decodes as `ammo_mines`, icon `a_mines`, pickup `Mines`, and `models/weapons/v_mine/tris.md2`; no separate `weapon_lasermine` string has surfaced in `gamex86.dll`, so `Laser Mine` currently reads as a behavioral label rather than a distinct gitem classname.
- The retail mine path now also exposes private callbacks `proximity_mine_think @ 0x1001DC00`, `proximity_mine_laser_start @ 0x1001DC60`, `proximity_mine_laser_think @ 0x1001DD00`, `proximity_mine_touch @ 0x1001DED0`, and `proximity_mine_die @ 0x1001DF50`; those bodies are now reconstructed in `src/game/g_weapon.c`, including the four-child `mine laser` triggered phase before the return to `proximity_mine_explode`.
- The retail deatomizer fire path is split between the wrapper at `0x10037BF0` and the lower-level helper at `0x10037A10`, and the current source now mirrors that split through `Weapon_Deatomizer_Fire()` plus `Weapon_Deatomizer_FireHelper()`.
- The retail `Weapon_DetonationPack` / `Weapon_RemoteDetonator` split is now reconstructed in `src/game/p_weapon.c`, `src/game/g_items.c`, and `src/game/g_weapon.c`, including the temporary-slot `weapon_remote_detonator` item row with null pickup or drop or ammo or `weapmodel` fields; the remaining Remote Detonator-adjacent uncertainty is `MOD_REMOTE_DETONATOR`, which still appears only as a header constant while the recovered `player_die` obituary switch uses `MOD_DETPACK` and `MOD_REMOTE_CANNON` for the live kill paths.
- The retail Obliterator path is now reconstructed directly in source at `0x100384C0` / `0x100386D0`, including the dedicated projectile helper layer at `0x1001CD20` / `0x1001CC30`, and the legacy `weapon_lasercannon` / `Weapon_LaserCannon` placeholder scaffolding has been retired from the active mapping.
- `HellFury` remains in the retail item-table and use-command surface, but the retail `weapon_hellfury` gitem entry at `0x10046EC8` points its `weaponthink` field at `Weapon_Obliterator @ 0x100386D0`; the current source now mirrors that alias directly and preserves the recovered `16`-rocket pickup grant in `Pickup_Weapon`.
- The earlier `0x10001730 -> check_dodge` alias was incorrect. The stock trace-based projectile dodge helper is `0x1001C1C0`, and the actor path-idle helper cluster is now directly recovered instead as `visible @ 0x10001560`, `Actor_EngageEnemy @ 0x10001690`, `Actor_FindEnemyTarget @ 0x10001730`, `Actor_IsPlayerFollowTarget @ 0x10001880`, and `Actor_FindFollowTarget @ 0x10001910`.
- The retail `misc_actor` / `target_actor` entity lifecycle is now directly recovered through `actor_stand @ 0x1001EEB0`, `actor_walk @ 0x1001EF00`, `actor_run @ 0x1001EF10`, `actor_pain @ 0x1001EF70`, `actorMachineGun @ 0x1001F0F0`, `actor_die @ 0x1001F220`, `actor_fire @ 0x1001F300`, `actor_attack @ 0x1001F340`, `actor_use @ 0x1001F380`, `SP_misc_actor @ 0x1001F460`, `target_actor_touch @ 0x1001F690`, and `SP_target_actor @ 0x1001F930`, but a clean standalone retail `actor_dead` body still is not isolated and the current `Actor_UseOblivion` path remains a source-side reconstruction layer rather than a named retail callback.
- The retail Badass monster module is now directly recovered through `badass_sight @ 0x1001FA00`, `badass_stand @ 0x1001FA50`, `badass_idle @ 0x1001FA70`, `badass_attack @ 0x1001FAA0`, direct `badass_attack_loop @ 0x1001FB20`, `badass_rocket_right @ 0x1001FBC0`, `badass_rocket_left @ 0x1001FC80`, `badass_gib_explosion @ 0x1001FD40`, `badass_die_gibs @ 0x1001FDE0`, `badass_dead @ 0x10020240`, `badass_die @ 0x100202D0`, `badass_step @ 0x10020300`, `badass_thud @ 0x10020330`, `badass_walk @ 0x10020360`, `badass_run @ 0x10020370`, `badass_pain @ 0x10020380`, and `SP_monster_badass @ 0x10020430`; the retail DLL string surface exposes `monster_badass`, not `monster_sentinel`, so current [m_badass.c](/E:/Repositories/Oblivion-reverse/src/game/m_badass.c) is the direct counterpart while the feature-flagged [m_sentinel.c](/E:/Repositories/Oblivion-reverse/src/game/m_sentinel.c) remains reconstruction-only. The module now also has an exact retail move-root and frame-payload map for `badass_move_idle_closed @ 0x1004CB18`, `badass_move_activate @ 0x1004C8F0`, `badass_move_deactivate @ 0x1004C9B8`, `badass_move_stand @ 0x1004CDC8`, `badass_move_walk @ 0x1004CC58`, `badass_move_run @ 0x1004CCC8`, `badass_move_attack @ 0x1004C9F8`, `badass_move_pain @ 0x1004CBA0`, and `badass_move_death @ 0x1004CAF8`, plus a direct retail model, gib-model, and cached sound-path surface; the raw overlapping activation-table bytes are now represented in source as well, with only the unavoidable runtime-safe projection left around `M_MoveFrame` execution.
- The retail Cyborg monster module is now directly recovered through `cyborg_footstep @ 0x100244F0`, `cyborg_sight @ 0x10024570`, `cyborg_search @ 0x100245A0`, `cyborg_stand @ 0x100245D0`, `cyborg_idle @ 0x100245E0`, `cyborg_walk @ 0x10024610`, `cyborg_run @ 0x10024620`, `cyborg_pain @ 0x100246A0`, `cyborg_hit_left @ 0x10024770`, `cyborg_hit_right @ 0x10024800`, `cyborg_hit_alt @ 0x10024890`, `cyborg_touch @ 0x10024920`, `cyborg_attack_start @ 0x10024A30`, `cyborg_attack_end @ 0x10024AD0`, `cyborg_fire_right @ 0x10024B20`, `cyborg_fire_left @ 0x10024BE0`, `cyborg_fire_both @ 0x10024CA0`, `cyborg_attack @ 0x10024E00`, `cyborg_melee @ 0x10024E70`, `cyborg_check_range @ 0x10024F10`, `cyborg_checkattack @ 0x10024FF0`, `cyborg_dead @ 0x10025050`, `cyborg_die @ 0x100250B0`, and `SP_monster_cyborg @ 0x10025200`; retail precaches the dedicated Cyborg asset set, uses prebuilt move roots in `.data`, and folds the current `cyborg_die_select()` helper into `cyborg_die` rather than isolating it as a standalone body.
- The retail Kigrax monster module is now directly recovered through `kigrax_search @ 0x10028DF0`, `kigrax_sight @ 0x10028E60`, `kigrax_stand @ 0x10028E90`, `kigrax_run @ 0x10028EE0`, `kigrax_walk @ 0x10028F20`, `kigrax_fire_plasma @ 0x10028F80`, `kigrax_attack @ 0x10029020`, `kigrax_melee @ 0x10029030`, `kigrax_strike1 @ 0x100290D0`, `kigrax_strike2 @ 0x10029140`, `kigrax_pain @ 0x100291B0`, `kigrax_die @ 0x10029220`, `SP_monster_kigrax @ 0x10029354`, and `kigrax_dead @ 0x1002F030`; current `m_kigrax.c` now mirrors that recovery through direct static `mframe_t` / `mmove_t` tables with the recovered retail payloads and hook map, while the retail DLL still stores those move roots as prebuilt `.data` objects.
- The retail soldier monster module is now directly recovered through `soldier_stand @ 0x1002C2D0`, `soldier_walk @ 0x1002C360`, `soldier_run @ 0x1002C3B0`, `soldier_pain @ 0x1002C400`, `soldier_fire @ 0x1002C560`, `soldier_attack6_refire @ 0x1002CAF0`, `soldier_fire4 @ 0x1002CB20`, `soldier_fire8 @ 0x1002CB30`, `soldier_attack @ 0x1002CB80`, `soldier_sight @ 0x1002CBE0`, `soldier_dodge @ 0x1002CC90`, `soldier_die @ 0x1002CD90`, `SP_monster_soldier_x @ 0x1002CEF0`, `SP_monster_soldier_light @ 0x1002D170`, `SP_monster_soldier @ 0x1002D200`, `SP_monster_soldier_ss @ 0x1002D280`, and `SP_monster_soldier_deatom @ 0x1002D300`; the retail Deatomiser Soldier is a skin-`6`, `40 / -30` sibling of the SS soldier and reaches the custom projectile path through `soldier_fire`, not through the current source's `count = 1`, `55 / -40`, forced-run spawn variant.
- The retail Spider monster module is now directly recovered through `spider_checkattack @ 0x10021460`, `spider_idle @ 0x1002D380`, `spider_sight @ 0x1002D3B0`, `spider_search @ 0x1002D3E0`, `spider_melee_swing @ 0x1002D410`, `spider_stand @ 0x1002D440`, `spider_walk @ 0x1002D450`, `spider_charge_think @ 0x1002D460`, `spider_charge_start @ 0x1002D570`, `spider_charge_end @ 0x1002D610`, `spider_run @ 0x1002D660`, `spider_melee_hit @ 0x1002D6C0`, `spider_melee @ 0x1002D750`, `spider_rocket_left @ 0x1002D7B0`, `spider_rocket_right @ 0x1002D850`, `spider_attack @ 0x1002D8F0`, `spider_pain @ 0x1002D9E0`, `spider_dead @ 0x1002DB70`, `spider_die @ 0x1002DBD0`, and `SP_monster_spider @ 0x1002DCF0`; the spawn body proves retail installs a custom `monsterinfo.checkattack` override instead of falling back to generic `M_CheckAttack`, and current `m_spider.c` now reconstructs that override directly. The retail currentmove writes also anchor prebuilt `.data` move tables at `0x1005CA00` through `0x1005CFF8` (`spider_move_stand`, `spider_move_walk`, `spider_move_run1`, `spider_move_run2`, `spider_move_melee_primary`, `spider_move_melee_secondary`, `spider_move_attack_left`, `spider_move_attack_right`, `spider_move_attack_dual`, `spider_move_pain1`, `spider_move_pain2`, `spider_move_death1`, `spider_move_death2`) with direct frame-payloads now decoded; the retail Spider data surface is also now anchored through its model, reused Gladiator/Mutant sound paths, gib assets, and cached sound-slot globals. The remaining Spider-side uncertainty is representational rather than behavioral: source still expresses the recovered move roots as C `mmove_t` tables instead of mirroring the retail `.data` layout verbatim.
- The low-address stand-state band now directly recovers `ai_move @ 0x10001090`, `FUN_100010b0 @ 0x100010B0`, `ai_stand_tail @ 0x10001170`, direct `ai_stand @ 0x10001220`, `ai_walk @ 0x10001350`, `ai_charge @ 0x10001430`, and `ai_turn @ 0x100014A0`; `ai_fly` still is not isolated as a stable standalone retail body.
- The stock monster target-acquisition chain is now directly recovered as `range @ 0x100014E0`, `infront @ 0x10001600`, `FoundTarget @ 0x10001AC0`, `FindTarget @ 0x10001BC0`, and `ai_checkattack @ 0x100022A0`, but a clean standalone retail `HuntTarget` body is still not isolated because the recovered `FoundTarget` fallback currently routes through `Actor_EngageEnemy`.
- The adjacent monster combat and movement band is now directly recovered through `FacingIdeal`, `ai_run_melee`, `ai_run_missile`, `ai_run_slide`, `AttackFinished`, `M_CheckBottom`, `SV_movestep`, `M_ChangeYaw`, `SV_StepDirection`, `SV_FixCheckBottom`, `SV_NewChaseDir`, `SV_CloseEnough`, `M_MoveToGoal`, and `M_walkmove`, and the shared wrapped-angle helper is now directly recovered as `anglemod @ 0x10038850`.
- The stock `g_monster.c` utility and startup chain is now directly recovered through `M_CheckAttack`, `M_FlyCheck`, `M_FliesOn`, `M_FliesOff`, `M_CatagorizePosition`, `M_WorldEffects`, `M_droptofloor`, `M_SetEffects`, `M_MoveFrame`, `monster_think`, `monster_use`, `monster_triggered_spawn`, `monster_triggered_spawn_use`, `monster_triggered_start`, `monster_death_use`, `monster_start`, `monster_start_go`, `walkmonster_start_go`, `walkmonster_start`, `flymonster_start_go`, `flymonster_start`, `swimmonster_start_go`, and `swimmonster_start`; the old local-callback placeholders in that band are now directly named in the committed Ghidra corpus.
- The immediate post-`Weapon_Obliterator` band at `0x10038700` and above is now directly recovered as shared orientation and vector helpers (`AngleVectors`, `AddPointToBounds`, `VectorCompare`, `VectorMA`, `DotProduct`, `CrossProduct`, `VectorLength`, `VectorScale`) rather than a hidden `HellFury` wrapper cluster.
- The plasma pistol and plasma rifle wrappers now directly anchor the retail shared helper `Weapon_Plasma_Fire @ 0x10037DE0`, so the player-plasma path is no longer only a behavioral alias in the committed corpus.
- The retail Plasma Pistol item surface is now behaviorally anchored at the string layer too: `weapon_plasma_pistol`, pickup `Plasma Pistol`, ammo `PistolPlasma`, `models/weapons/v_pistol/tris.md2`, `models/objects/pistolplasma/tris.md2`, `plasma1/fire.wav`, and `plasma1/hit.wav` all appear in `gamex86.dll` and line up with the recovered wrapper and projectile path.
- The retail Plasma Rifle item surface is now behaviorally anchored at the string layer too: `weapon_plasma_rifle`, pickup `Plasma Rifle`, ammo `Rifle Plasma`, icon `w_plasma`, `models/weapons/v_plasma/tris.md2`, `models/objects/plasma/tris.md2`, `plasma2/fire.wav`, and `plasma2/hit.wav` all appear in `gamex86.dll` and line up with the recovered wrapper and projectile path.
- No standalone retail `fire_plasma_pistol` or `plasma_pistol_touch` body surfaced either: the recovered pistol path stays `Weapon_PlasmaPistol_Fire -> Weapon_Plasma_Fire(mode 0) -> fire_plasma_bolt -> plasma_bolt_touch`, and the reconstruction now mirrors that shared-helper path directly.
- No standalone retail `fire_plasma_rifle` or `plasma_rifle_touch` body surfaced either: the recovered rifle path also stays on `Weapon_PlasmaRifle_Fire -> Weapon_Plasma_Fire(mode 1) -> fire_plasma_bolt -> plasma_bolt_touch`, and the current source now mirrors that wrapper timing, shared-helper shape, and `ammo_rifleplasma` item-table surface directly.
- The stock blaster projectile pair `blaster_touch @ 0x1001BF10` and `fire_blaster @ 0x1001C000` are now directly recovered, so the laser-bolt path beneath `Blaster_Fire` and `Weapon_HyperBlaster_Fire` is no longer only inferred from wrapper behavior.
- The stock launcher-side projectile helpers `rocket_touch @ 0x1001C960`, `fire_rocket @ 0x1001CAD0`, and `fire_rail @ 0x1001CF50` are now directly recovered, and the same `rocket_touch` body is also reused by the retail Obliterator projectile helper.
- The stock BFG projectile chain `bfg_explode @ 0x1001D120`, `bfg_touch @ 0x1001D2E0`, `bfg_think @ 0x1001D440`, and `fire_bfg @ 0x1001D6F0` is now directly recovered, so the retail BFG path below `weapon_bfg_fire` no longer depends on HLIL or source-order inference.
- The retail DoD projectile layer now also exposes direct retail-only local helpers `dod_client_reset @ 0x1001ECA0` and `dod_pulse_think @ 0x1001ECC0`; that path diverges materially from the current source's simpler `dod_touch` / `dod_explode` split, so those names stay behavioral rather than source-forced.
- The remote-view tail of `ClientEndServerFrame` now directly routes through the dummy-body helper quartet at `0x10002D40`, `0x10002CA0`, `0x10002DE0`, and `0x10002E20`, plus the wider tracked-entity cluster at `0x10002F20`, `0x100142E0`, `0x10014320`, `0x10014530`, and `0x100145C0`; these bodies are best treated as shared remote-view support rather than forced `G_SetSpectatorStats` / `G_CheckChaseStats` renames, and the dormant stock chase-camera source has now been removed from the active reconstruction.

These are not disproven. They remain unresolved until a second retail evidence signal supports them.

## Common Helper Identities Worth Reusing

These are not export-facing, but they appear often enough in recovered functions that treating them as stable aliases is useful.

| Current id | Likely symbol | Why it matters | Confidence |
| --- | --- | --- | --- |
| `FUN_10038A70` | `COM_Parse` | Used exactly as token parser inside `ED_ParseEdict`. | High |
| `FUN_10038B20` | `Q_stricmp` | Repeated string comparator returning zero on equality across spawn/admin/entity code. | High |
| `FUN_1001ABA0` | `G_ProjectSource` | Directly called by `P_ProjectSource` and `Drop_Item` to derive a projected start point from an origin, offset, and view axes. | High |
| `0x10019E90` | `AnglesNormalize` | Shared two-axis normalization helper now directly recovered; the post-teleport band and `turret_breach_think` prove it belongs to `g_turret.c`, not only `trigger_teleport`. | High |
| `0x10019F40` | `SnapToEights` | Shared turret-driver position quantizer now directly recovered from the post-teleport helper band. | High |
| `0x1001B160` | `vectoyaw` | Now directly named; exact `atan2`-based yaw helper used by `check_dodge`, trail markers, and broad monster-facing code. | High |
| `0x1001B1E0` | `vectoangles` | Now directly named; stock vector-to-angle helper reused by turret, AI, and projectile orientation paths. | High |
| `0x10038700` | `AngleVectors` | Now directly named; confirms the stock forward/right/up basis builder used throughout weapons, items, AI, and view code. | High |
| `0x10038850` | `anglemod` | Now directly named; `FacingIdeal`, `M_ChangeYaw`, and `SV_NewChaseDir` all call this wrapped-yaw helper exactly where stock Quake II normalizes yaw into `[0,360)`. | High |
| `0x10038880` | `AddPointToBounds` | Now directly named; shared bounds-expansion helper used by collision and projectile-bound construction. | High |
| `0x100388C0` | `VectorCompare` | Now directly named; exact three-component equality helper reused across stock-style vector control flow. | High |
| `0x10038900` | `VectorNormalize` | Direct body normalizes a three-component vector in place, and the surrounding callsites still consume the x87 return as a length value where stock Quake II does; this matches the current `VectorNormalize` uses across actor AI, projectiles, mines, and chase-style code. | High |
| `0x10038950` | `VectorMA` | Now directly named; shared `out = a + scale * b` helper visible across weapon, movement, and spawn code. | High |
| `0x10038990` | `DotProduct` | Now directly named; stock dot-product helper reused across aiming and physics math. | High |
| `0x100389B0` | `CrossProduct` | Now directly named; stock cross-product helper reused by orientation and projectile setup. | High |
| `0x100389F0` | `VectorLength` | Now directly named; stock sqrt-of-squares helper used directly inside `check_dodge` and other distance gates. | High |
| `0x10038A20` | `VectorScale` | Now directly named; stock three-component scale helper reused across aiming and movement math. | High |
| `FUN_10039237` | `atoi` | Used in `StringToFilter` and integer field parsing. | High |
| `FUN_10039D65` | `atof` | Used in float and angle parsing. | High |
| `FUN_10039662` | `sscanf("%f %f %f")`-style vector parse | Used by `ED_ParseField` vector branch. | High |
| `FUN_10039A54` | `fwrite` wrapper | Used by `WriteClient`, `WriteEdict`, and `WriteLevelLocals`. | High |
| `FUN_10039B8D` | `fread` wrapper | Used by `ReadClient`, `ReadEdict`, and `ReadLevelLocals`. | High |

## Current Gaps

- The targeted selected-function pass now covers the full export callback cluster plus the immediate helper band around frame stepping, save/load, intermission handling, spawn parsing, the low-address `g_misc.c` world-object band through `SP_path_corner`, `point_combat_touch`, `SP_point_combat`, `TH_viewthing`, `SP_viewthing`, `SP_info_notnull`, `SP_light`, and `light_use`, the stock `g_misc.c` world-entity band through banner, flyby ship, satellite dish, mine lights, string-display, clock, teleporter, and gib spawns, the broader item subsystem through lookup, timed-use powerups, key pickup, health spawn wrappers, armor, power-armor, dropped-item touchability, trigger-spawn activation, respawn, and spawn flow, the retail RTDU item/turret band, client lifecycle, death/respawn handling, weapon selection and state-core flow, the stock machinegun through BFG band plus the directly recovered BFG projectile chain, the retail proximity-mine state machine, the retail-only Obliterator wrapper, the actor or monster movement chain, server command dispatch, and `ClientCommand` item/chat/UI handling. The remaining unmapped space is deeper gameplay code, mission scripting, the retail-only spectator or dummy-body support cluster, and compiler-folded locals like `path_corner_touch` that we may choose to keep as embedded labels rather than force into standalone symbols.
- The unresolved source-side hooks listed above should be treated as hypotheses rather than settled retail behavior until a second retail signal confirms them.
- The map above intentionally avoids renaming larger gameplay functions unless the evidence chain is at least as strong as the items listed here.
- Ghidra still reports `62` imports while older HLIL-oriented notes mention `75`; that metadata difference remains unresolved.
