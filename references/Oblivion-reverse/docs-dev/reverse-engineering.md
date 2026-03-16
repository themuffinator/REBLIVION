# Oblivion Reverse-Engineering Workflow

## Scope

This project reconstructs the retail Oblivion Quake II game DLL by combining the existing Binary Ninja HLIL corpus with a committed Ghidra export corpus for `gamex86.dll`.

Retail binary in scope:

- `C:\q2Clean\oblivion\gamex86.dll`

## Canonical Reference Policy

Oblivion-reverse is still HLIL-led because the repository was built around the existing Binary Ninja corpus.

Evidence precedence for new reverse-engineering work:

1. Retail `gamex86.dll`
2. Binary Ninja HLIL under `references/HLIL/oblivion/`
3. Committed Ghidra corpus under `reference/reverse-engineering/ghidra/gamex86/`
4. Stock Quake II GPL source under `references/source-code/Quake-2-master/`

Use the GPL source as a structural cross-reference only. If Quake II source behavior conflicts with retail Oblivion, follow the retail evidence.

## Committed Ghidra Corpus

Generated outputs are committed under:

- `reference/reverse-engineering/ghidra/gamex86/`

Each regeneration produces:

- `metadata.txt`
- `functions.csv`
- `imports.txt`
- `exports.txt`
- `analysis_symbols.txt`
- `decompile_exports.c`
- `decompile_top_functions.c`
- `selected_functions_summary.csv`
- `decompile_selected_functions.c`

## Current Corpus Snapshot

Current committed export pass for `C:\q2Clean\oblivion\gamex86.dll`:

- `GetGameAPI @ 0x1000D490`
- image base `0x10000000`
- `function_count=762`
- `import_count=62`
- `export_count=1`
- `analysis_symbol_count=507`
- `decompiled_function_count=620`
- current coverage now includes the save/load, spawn-parse, edict lifecycle, and IP-filter helper bands that were below the original top-function cutoff
- the committed notes now also include a now-fully direct `level_locals_t` member map for the retail `level` block at `0x1006C2E0`, with `level_name`, map and nextmap strings, the intermission band, the sensory pointer or frame band, the full secret or goal or monster counter band, `current_entity`, `body_que`, and `power_cubes` all backed by committed Ghidra evidence
- the committed notes now also include a retail `gclient_t` member map for the `0xF34` client block, with direct anchors for `pers` at `+0x0BC`, `resp` at `+0x730`, `old_pmove` at `+0xDBC`, the button or weapon or damage or powerup-timer bands, and the RTDU remote-view tail at `+0xF0C`, `+0xF10`, `+0xF18`, `+0xF28`, `+0xF2C`, and `+0xF30`; the main remaining client-struct unknowns are the persistent slot at `+0x710` and the exact names for `+0xF04` / `+0xF08`
- the committed notes now also include a retail `edict_t` member map for the `0x3D0` entity block, with direct anchors for the fixed server-visible prefix through `owner`, the gameplay/control band through `classname`, `spawnflags`, `movedir`, `nextthink`, `health`, `enemy`, `activator`, `style`, and `item`, and the compact AI tail rooted by `monsterinfo.currentmove @ +0x358`; the main remaining entity-struct unknowns are the retail extension band at `+0x1AC..+0x1E8`, the mover/timer band at `+0x294..+0x357`, and the exact final tail slot at `+0x3CC`
- the committed notes now also distinguish the retail `game` block at `0x1006C440` from the current source mission layer: direct retail coverage currently stops at `game.autosaved @ +0x618`, while current `game.mission`, the `Mission_*` hook chain, and the `edict.oblivion.mission_*` / controller-path bands are now explicitly documented as reconstruction-only until a second retail signal surfaces; the only direct retail mission-adjacent anchors are the help buffers, `helpchanged`, `target_help`, and the client help counters
- the targeted selected-function pass now captures the full export callback cluster and adjacent helper functions used to anchor frame flow, intermission handling, save/load, spawn parsing, the broader item subsystem through lookup, timed-use powerups, key pickup, health spawn wrappers, armor, power-armor, dropped-item touchability, trigger-spawn activation, respawn, and spawn flow (`GetItemByIndex`, `FindItemByClassname`, `FindItem`, `DoRespawn`, `SetRespawn`, `Pickup_Powerup`, `Drop_General`, `Pickup_Adrenaline`, `Pickup_AncientHead`, `Pickup_Bandolier`, `Pickup_Pack`, `Use_Quad`, `Use_Breather`, `Use_Envirosuit`, `Use_Invulnerability`, `Use_Silencer`, `Pickup_Key`, `Add_Ammo`, `Pickup_Ammo`, `Drop_Ammo`, `MegaHealth_think`, `Pickup_Health`, `ArmorIndex`, `Pickup_Armor`, `PowerArmorType`, `Use_PowerArmor`, `Pickup_PowerArmor`, `Drop_PowerArmor`, `Touch_Item`, `Drop_Item`, `drop_temp_touch`, `drop_make_touchable`, `Use_Item`, `droptofloor`, `PrecacheItem`, `SpawnItem`, `SP_item_health`, `SP_item_health_small`, `SP_item_health_large`, `SP_item_health_mega`, `InitItems`, `SetItemNames`, `Pickup_Weapon`, `P_ProjectSource`), the low-address `g_misc.c` world-object band (`SP_path_corner`, `point_combat_touch`, `SP_point_combat`, `TH_viewthing`, `SP_viewthing`, `SP_info_notnull`, `SP_light`, `light_use`), the early `g_misc.c` world-entity band (`SP_misc_banner`, `SP_misc_viper`, `SP_misc_bigviper`, `SP_misc_strogg_ship`, `SP_misc_satellite_dish`, `SP_light_mine1`, `SP_light_mine2`, `SP_misc_gib_arm`, `SP_misc_gib_leg`, `SP_misc_gib_head`, `SP_target_character`, `target_string_use`, `func_clock_format_countdown`, `SP_func_clock`, `teleporter_touch`, `SP_misc_teleporter`, `SP_misc_teleporter_dest`), the stock `g_target.c` help/secret/goal band (`Use_Target_Help`, `SP_target_help`, `use_target_secret`, `SP_target_secret`, `use_target_goal`, `SP_target_goal`), the adjacent explosion or exit or splash or spawner or target-weapon band (`target_explosion_explode`, `use_target_explosion`, `SP_target_explosion`, `use_target_changelevel`, `SP_target_changelevel`, `use_target_splash`, `SP_target_splash`, `use_target_spawner`, `SP_target_spawner`, `use_target_blaster`, `SP_target_blaster`, `use_target_railgun`, `SP_target_railgun`, `target_rocket_fire`, `SP_target_rocket`), the crosslevel and laser band (`trigger_crosslevel_trigger_use`, `SP_target_crosslevel_trigger`, `target_crosslevel_target_think`, `SP_target_crosslevel_target`, `target_laser_think`, `target_laser_on`, `target_laser_off`, `target_laser_use`, `target_laser_start`, `SP_target_laser`), the later light-ramp and earthquake band (`target_lightramp_think`, `target_lightramp_use`, `SP_target_lightramp`, `target_earthquake_think`, `target_earthquake_use`, `SP_target_earthquake`), the stock `g_trigger.c` utility and trigger band (`InitTrigger`, `multi_wait`, `multi_trigger`, `Use_Multi`, `Touch_Multi`, `trigger_enable`, `SP_trigger_multiple`, `SP_trigger_once`, `trigger_relay_use`, `SP_trigger_relay`, `trigger_key_use`, `SP_trigger_key`, `trigger_counter_use`, `SP_trigger_counter`, `SP_trigger_always`, `trigger_push_touch`, `SP_trigger_push`, `hurt_use`, `hurt_touch`, `SP_trigger_hurt`, `trigger_gravity_touch`, `SP_trigger_gravity`, `trigger_monsterjump_touch`, `SP_trigger_monsterjump`), the retail custom teleport band (`trigger_teleport_touch`, `trigger_teleport_enable`, `trigger_teleport_disable`, `trigger_teleport_activate`, `trigger_teleport_toggle`, `SP_trigger_teleport`), the adjacent low-address `g_turret.c` / `g_utils.c` helper band (`AnglesNormalize`, `SnapToEights`, `turret_breach_fire`, `turret_breach_think`, `turret_breach_finish_init`, `SP_turret_breach`, `SP_turret_base`, `Think_Delay`, `G_UseTargets`, `tv`, `G_SetMovedir`, `vectoangles`), the retail RTDU band (`rtdu_use`, `RTDU_SpawnTurret`, `RTDU_TurretThink`, `RTDU_RemoveTurret`, `RTDU_BeginRemoteView`, `RTDU_EndRemoteView`, `RTDU_TurretAttack`, the recovered callback body at `0x10014750`, and `RTDU_InitTurret`), the death/respawn and persistent-loadout path (`player_die`, `InitClientPersistant`, `CopyToBodyQue`, `respawn`, `spectator_respawn`), the actor helper cluster and direct `misc_actor` / `target_actor` lifecycle (`visible`, `Actor_EngageEnemy`, `Actor_FindEnemyTarget`, `Actor_IsPlayerFollowTarget`, `Actor_FindFollowTarget`, `actor_stand`, `actor_walk`, `actor_run`, `actor_pain`, `actorMachineGun`, `actor_die`, `actor_fire`, `actor_attack`, `actor_use`, `SP_misc_actor`, `target_actor_touch`, `SP_target_actor`), the directly recovered Kigrax monster module (`kigrax_search`, `kigrax_sight`, `kigrax_stand`, `kigrax_run`, `kigrax_walk`, `kigrax_fire_plasma`, `kigrax_attack`, `kigrax_melee`, `kigrax_strike1`, `kigrax_strike2`, `kigrax_pain`, `kigrax_die`, `SP_monster_kigrax`, `kigrax_dead`), the directly recovered Spider monster module (`spider_checkattack`, `spider_idle`, `spider_sight`, `spider_search`, `spider_melee_swing`, `spider_stand`, `spider_walk`, `spider_charge_think`, `spider_charge_start`, `spider_charge_end`, `spider_run`, `spider_melee_hit`, `spider_melee`, `spider_rocket_left`, `spider_rocket_right`, `spider_attack`, `spider_pain`, `spider_dead`, `spider_die`, `SP_monster_spider`), the recovered low-address `g_ai.c` wrapper band (`ai_move`, `FUN_100010b0`, `ai_stand_tail`, `ai_stand`, `ai_walk`, `ai_charge`, `ai_turn`), the stock monster target-acquisition and attack-gate chain (`range`, `infront`, `FoundTarget`, `FindTarget`, `ai_checkattack`), the adjacent monster combat and movement band (`ai_run`, `FacingIdeal`, `ai_run_melee`, `ai_run_missile`, `ai_run_slide`, `AttackFinished`, `M_CheckBottom`, `SV_movestep`, `M_ChangeYaw`, `SV_StepDirection`, `SV_FixCheckBottom`, `SV_NewChaseDir`, `SV_CloseEnough`, `M_MoveToGoal`, `M_walkmove`), the stock monster utility/startup chain (`M_CheckAttack`, `M_FlyCheck`, `M_FliesOn`, `M_FliesOff`, `M_CatagorizePosition`, `M_WorldEffects`, `M_droptofloor`, `M_SetEffects`, `M_MoveFrame`, `monster_think`, `monster_use`, `monster_triggered_spawn`, `monster_triggered_spawn_use`, `monster_triggered_start`, `monster_death_use`, `monster_start`, `monster_start_go`, `walkmonster_start_go`, `walkmonster_start`, `flymonster_start_go`, `flymonster_start`, `swimmonster_start_go`, `swimmonster_start`), the widened weapon layer (`ChangeWeapon`, `NoAmmoWeaponChange`, `Think_Weapon`, `Use_Weapon`, `Drop_Weapon`, `Weapon_Generic`, `Machinegun_Fire`, `Weapon_Machinegun`, `Chaingun_Fire`, `Weapon_Chaingun`, `weapon_shotgun_fire`, `Weapon_Shotgun`, `weapon_supershotgun_fire`, `Weapon_SuperShotgun`, `weapon_grenadelauncher_fire`, `Weapon_GrenadeLauncher`, `Weapon_RocketLauncher_Fire`, `Weapon_RocketLauncher`, `Blaster_Fire`, `Weapon_Blaster_Fire`, `Weapon_Blaster`, `Weapon_HyperBlaster_Fire`, `Weapon_HyperBlaster`, `weapon_railgun_fire`, `Weapon_Railgun`, `weapon_bfg_fire`, `Weapon_BFG`, `Weapon_Deatomizer`, `Weapon_Deatomizer_Fire`, `Weapon_Plasma_Fire`, `Weapon_PlasmaPistol_Fire`, `Weapon_PlasmaPistol`, `Weapon_PlasmaRifle_Fire`, `Weapon_PlasmaRifle`, the retail `Weapon_DetonationPack` / `Weapon_DetonationPack_Fire` split, `Weapon_RemoteDetonator`, `Weapon_RemoteDetonator_Fire`, `Weapon_DOD`, `Weapon_DOD_Fire`, `Weapon_ProximityMines_Fire`, `Weapon_ProximityMines`, `Weapon_Obliterator_Fire`, `Weapon_Obliterator`), the projectile-helper layer (`blaster_touch`, `fire_blaster`, `Grenade_Explode`, `fire_grenade2`, `rocket_touch`, `fire_rocket`, `obliterator_projectile_think`, `fire_obliterator_projectile`, `fire_rail`, `bfg_explode`, `bfg_touch`, `bfg_think`, `fire_bfg`, `fire_proximity_mine`, `proximity_mine_explode`, `plasma_bolt_touch`, `fire_plasma_bolt`, `detpack_detonate`, `fire_detpack`, `dod_client_reset`, `dod_pulse_think`, `fire_dod`), the shared dodge/math helper band (`check_dodge @ 0x1001C1C0`, `vectoyaw`, `AngleVectors`, `anglemod`, `AddPointToBounds`, `VectorNormalize`, `VectorCompare`, `VectorMA`, `DotProduct`, `CrossProduct`, `VectorLength`, `VectorScale`), `Oblivion_UpdateWeaponRegen`, and adjacent helper identities such as `AI_SetSightClient`, `SaveClientData`, `BeginIntermission`, `PlayerTrail_Init`, `ClientEndServerFrame`, `G_SetStats`, `DeathmatchScoreboardMessage`, `P_DamageFeedback`, `SV_CalcViewOffset`, `SV_CalcGunOffset`, `SV_CalcBlend`, `P_FallingDamage`, `P_WorldEffects`, `G_SetClientEffects`, `G_SetClientEvent`, `G_SetClientSound`, `G_SetClientFrame`, `PlayerNoise`, and `KillBox`; the spectator-only tail still exposes a retail-only dummy-body or camera-support cluster around `0x10002CA0` / `0x10002D40` / `0x10002DE0` / `0x10002E20` that remains behaviorally mapped but not safely renamed, the core RTDU item/turret band is now directly recovered and the remaining RTDU-adjacent save/load question is `G_RestoreRTDUTurretLinks`, `ai_fly` still is not isolated as a stable standalone retail body, the deatomizer path still has a wrapper/helper split around `0x10037BF0` / `0x10037A10`, the immediate post-`Weapon_Obliterator` addresses now resolve mostly into shared math/orientation helpers rather than a hidden custom-weapon wrapper band, the current source now reconstructs the retail `weapon_hellfury -> Weapon_Obliterator` alias directly and preserves the `16`-rocket pickup grant in `Pickup_Weapon`, the stock blaster projectile pair now also includes direct `blaster_touch @ 0x1001BF10` and direct `fire_blaster @ 0x1001C000`, the stock launcher-side helpers now also include direct `rocket_touch @ 0x1001C960`, `fire_rocket @ 0x1001CAD0`, and direct `fire_rail @ 0x1001CF50`, the stock BFG projectile chain now also includes direct `bfg_explode @ 0x1001D120`, `bfg_touch @ 0x1001D2E0`, `bfg_think @ 0x1001D440`, and `fire_bfg @ 0x1001D6F0`, the retail DoD path now also includes direct `dod_client_reset @ 0x1001ECA0` and `dod_pulse_think @ 0x1001ECC0`, the retail `misc_actor` and `target_actor` entity path is now directly recovered but a standalone `actor_dead` body still is not isolated, retail `SP_monster_kigrax` now also proves that the current `kigrax_seed_frames()` / `kigrax_init_moves()` helpers are reconstruction scaffolding rather than retail functions because the DLL wires prebuilt `.data` move tables directly, retail `SP_monster_spider` now also shows that the current shared `spider_rocket()` helper is source-side factoring rather than a direct retail body because the DLL recovers distinct `spider_rocket_left` / `spider_rocket_right` callbacks and prebuilt Spider move tables in `.data`, and the newly recovered `spider_checkattack @ 0x10021460` shows retail Spider also overrides `monsterinfo.checkattack` instead of falling back to generic `M_CheckAttack`, while `spider_step` still is not isolated as a standalone retail body, a clean standalone retail `HuntTarget` body is still not isolated because the recovered `FoundTarget` fallback currently reuses `Actor_EngageEnemy`, the selected pass now also makes the retail/source delta explicit where `use_target_railgun` is thinner than the current source wrapper and `SP_target_rocket` wires directly to `target_rocket_fire`, the new light-ramp and earthquake tranche matches current source closely with no visible retail/source split beyond the recovered callbacks, the new stock `g_trigger.c` tranche now directly recovers the multi or relay or key or counter or push or hurt or gravity or monsterjump helper layer, the retail custom teleport tranche now directly recovers the enable or disable or toggle or activate path plus the custom destination-lookup touch routine, the adjacent post-teleport helper space now resolves into the turret-breach and shared utility band through `AnglesNormalize`, `SnapToEights`, `SP_turret_base`, `Think_Delay`, `G_UseTargets`, `tv`, `G_SetMovedir`, and `vectoangles`, and the remaining nearby work is the unresolved turret-driver spillover plus documentation style for compiler-folded locals such as `path_corner_touch`
- the wide decompilation plus raw disassembly and HLIL cross-check now also anchor the retail rotate-train mover band (`RotateTrain_MoveDone @ 0x10014940`, `RotateTrain_MoveFinal @ 0x100149D0`, `RotateTrain_MoveBegin @ 0x10014AD0`, `RotateTrain_MoveCalc @ 0x10014C50`, `rotate_train_wait @ 0x10015140`, `rotate_train_next @ 0x10015250`, `rotate_train_resume @ 0x100154C0`, `rotate_train_find @ 0x10015560`, `rotate_train_use @ 0x100156F0`, `SP_func_rotate_train @ 0x10015750`), showing that retail uses the classname `func_rotate_train`, reuses `train_blocked`, moves directly to each path-corner origin, and reads per-corner `duration` or `rotate` or `speeds` overrides from the resolved corners
- the committed notes now also include a dedicated `SP_trigger_*` spawn-wrapper to helper-chain map, making the retail trigger surface explicit as wrapper-to-callback wiring rather than only a flat symbol list; the main direct chains are `SP_trigger_multiple -> Touch_Multi` or `trigger_enable -> Use_Multi -> multi_trigger`, `SP_trigger_once -> SP_trigger_multiple`, `SP_trigger_counter -> trigger_counter_use -> multi_trigger`, the `InitTrigger`-based movement or hazard wrappers (`SP_trigger_push`, `SP_trigger_hurt`, `SP_trigger_gravity`, `SP_trigger_monsterjump`), and the separate custom `SP_trigger_teleport` control chain
- the committed notes now also include a dedicated `SP_target_*` spawn-wrapper to helper-chain map, making the retail target surface explicit as wrapper-to-use or think or fire wiring rather than only a flat symbol list; the main direct chains are `SP_target_help -> Use_Target_Help`, `SP_target_secret` or `SP_target_goal -> use_target_*`, `SP_target_explosion -> use_target_explosion -> target_explosion_explode`, the single-use target wrappers (`SP_target_changelevel`, `SP_target_splash`, `SP_target_spawner`, `SP_target_blaster`, `SP_target_railgun`), the direct retail `SP_target_rocket -> target_rocket_fire` split, the crosslevel wrapper pair, the deferred laser chain `SP_target_laser -> target_laser_start`, and the wrapper -> use -> think pairs for lightramp and earthquake
- the committed notes now also include a dedicated `SP_func_*` spawn-wrapper to helper-chain map, making the retail brush-entity surface explicit as wrapper-to-mover or think or use wiring rather than only isolated callbacks; the direct wrapper coverage now includes `SP_func_clock`, `SP_func_plat`, `SP_func_button`, `SP_func_door`, `SP_func_door_rotating`, `SP_func_water`, `SP_func_train`, `SP_func_rotate_train`, `SP_func_timer`, and `SP_func_conveyor`, while the remaining unresolved wrapper starts are narrowed to `SP_func_rotating`, `SP_func_door_secret`, and `SP_func_killbox`
- the committed notes now also include a dedicated `SP_misc_*` spawn-wrapper to helper-chain map, making the retail `misc_*` surface explicit as wrapper-to-think or use or touch wiring rather than only isolated world-entity rows; the direct chains are `SP_misc_banner -> misc_banner_think`, `SP_misc_viper` or `SP_misc_strogg_ship -> local reveal/use helper -> train_use` plus `func_train_find`, `SP_misc_satellite_dish -> local dish-use callback`, the gib wrappers -> `gib_die` plus timed `G_FreeEdict`, `SP_misc_teleporter -> teleporter_touch`, and `SP_misc_actor -> actor_*` callbacks, while current-source wrappers such as `SP_misc_explobox` and `SP_misc_screenfader` still are not isolated as stable retail starts
- the committed notes now also include a dedicated `SP_info_*` spawn-wrapper to helper-chain map, separating the one direct retail wrapper `SP_info_notnull` from the strong retail class-name/call-site mappings for `SP_info_teleport_dest` and the player spawn/intermission wrappers; the direct or inferred chains now cover `SP_info_player_start`, `SP_info_player_deathmatch`, `SP_info_player_coop`, `SP_info_player_intermission`, `SP_info_teleport_dest`, and the source-side `SP_info_null` / `func_group` sink alias, with the non-direct wrappers explicitly marked as not yet isolated retail starts
- the targeted selected-function pass now also captures the retail Cyborg monster module (`cyborg_footstep`, `cyborg_sight`, `cyborg_search`, `cyborg_stand`, `cyborg_idle`, `cyborg_walk`, `cyborg_run`, `cyborg_pain`, `cyborg_hit_left`, `cyborg_hit_right`, `cyborg_hit_alt`, `cyborg_touch`, `cyborg_attack_start`, `cyborg_attack_end`, `cyborg_fire_right`, `cyborg_fire_left`, `cyborg_fire_both`, `cyborg_attack`, `cyborg_melee`, `cyborg_check_range`, `cyborg_checkattack`, `cyborg_dead`, `cyborg_die`, `SP_monster_cyborg`); current retail string, disassembly, and decompile evidence shows `SP_monster_cyborg` at `0x10025200` preloads the dedicated Cyborg asset set, wires the full callback table, seeds prebuilt move roots from `.data` instead of the current source's runtime `mmove_t` construction, and folds the current standalone `cyborg_die_select()` helper back into the retail `cyborg_die` body
- the Cyborg module now also has an exact retail move-root and frame-payload map for all seventeen animation tables, plus a direct retail data-surface map: stand `@ 0x10051540` and idle `@ 0x10051560` use direct `ai_stand @ 0x10001220` with `dist 0`, walk `@ 0x10051648` uses the retail `12,2,2,2,5,5,6,8,13,12,2,2,2,5,5,6,8,13` `ai_walk` sequence, run `@ 0x100516A0` uses `ai_run` with `dist 6,23,8,6,23,8` and hooks `19/21 -> cyborg_footstep`, the attack or melee or pain or death tables now all have direct retail payloads, the backflip table `@ 0x100519F0` carries the full `38 -> cyborg_attack_start`, `43 -> cyborg_attack_end`, `44 -> cyborg_fire_both` hook chain, the spawn bbox is now corrected to `(-16,-16,-38)` through `(16,16,27)`, and the model or sound string VAs plus sound-slot globals are now documented directly
- the targeted selected-function pass now also captures the private retail Laser Mine callback chain behind `Weapon_ProximityMines` and `fire_proximity_mine` (`proximity_mine_think`, `proximity_mine_laser_start`, `proximity_mine_laser_think`, `proximity_mine_touch`, `proximity_mine_die`); current string evidence still points to the public item surface `ammo_mines` / `Mines`, so `Laser Mine` currently reads as a behavior label driven by the spawned `mine laser` child entities rather than a distinct `weapon_lasermine` gitem string
- the retail Plasma Pistol path is now documented end-to-end from its public string surface (`weapon_plasma_pistol`, `Plasma Pistol`, `PistolPlasma`, `models/weapons/v_pistol/tris.md2`, `models/objects/pistolplasma/tris.md2`, `plasma1/fire.wav`, `plasma1/hit.wav`) through `Weapon_PlasmaPistol_Fire -> Weapon_Plasma_Fire(mode 0) -> fire_plasma_bolt -> plasma_bolt_touch` plus `Oblivion_UpdateWeaponRegen`, and the reconstruction now follows that recovered shared helper path directly
- the retail Plasma Rifle path is now documented end-to-end from its public string surface (`weapon_plasma_rifle`, `Plasma Rifle`, `Rifle Plasma`, `w_plasma`, `models/weapons/v_plasma/tris.md2`, `models/objects/plasma/tris.md2`, `plasma2/fire.wav`, `plasma2/hit.wav`) through `Pickup_RiflePlasma -> Oblivion_UpdateWeaponRegen` on the ammo side and `Weapon_PlasmaRifle_Fire -> Weapon_Plasma_Fire(mode 1) -> fire_plasma_bolt -> plasma_bolt_touch` on the firing side; the retail `ammo_rifleplasma` row now also resolves the formerly unknown persistent slot at `+0x710` as the rifle regen divisor
- the targeted selected-function pass now also captures the retail Badass monster module (`badass_sight`, `badass_stand`, `badass_idle`, `badass_attack`, `badass_attack_loop`, `badass_rocket_right`, `badass_rocket_left`, `badass_gib_explosion`, `badass_die_gibs`, `badass_dead`, `badass_die`, `badass_step`, `badass_thud`, `badass_walk`, `badass_run`, `badass_pain`, `SP_monster_badass`); current retail string and decompile evidence still shows this is the real monster surface behind the source-side Sentinel concept because `gamex86.dll` exposes `monster_badass` plus the Badass model or tank-sound preload set and does not expose a separate `monster_sentinel` token, and the module now also has a near-complete retail move-root, frame-payload, model-path, and cached-sound map with the malformed activation-table overlap in `badass_move_activate @ 0x1004C8F0` now represented directly in source alongside the runtime-safe projection required to keep `M_MoveFrame` from executing overlapped `.data` bytes as code
- the targeted selected-function pass now also captures the retail soldier module and monster-side deatom bolt chain (`soldier_stand`, `soldier_walk`, `soldier_run`, `soldier_pain`, `soldier_fire`, `soldier_attack6_refire`, `soldier_fire4`, `soldier_fire8`, `soldier_attack`, `soldier_sight`, `soldier_dodge`, `soldier_die`, `SP_monster_soldier_x`, `SP_monster_soldier_light`, `SP_monster_soldier`, `SP_monster_soldier_ss`, `SP_monster_soldier_deatom`, `monster_fire_deatom`, `deatom_touch`, `deatom_think`, `fire_deatom`); the main retail/source delta in that band is that `SP_monster_soldier_deatom` is a skin-`6`, `40 / -30` SS-derived spawn and the deatom path is driven by `soldier_fire` skin branching rather than the current source's `count = 1` / `55 / -40` spawn variant
- the Kigrax module now has an exact retail move-root and frame-payload map for all eleven animation tables: `stand @ 0x10058818` and `scan @ 0x10058928` use direct `ai_stand @ 0x10001220` with `dist 0`, `walk1 @ 0x10058AE0` and `walk2 @ 0x10058C08` use `ai_walk` with `dist 4`, `sight @ 0x10058CE8` and `run @ 0x10058DC8` use `ai_run` with `dist 10` and `15`, `pain @ 0x10058E60` and `death @ 0x10058F58` use `ai_move` with `dist 0`, `melee1 @ 0x10059020` and `melee2 @ 0x100590B8` use `ai_charge` with `dist 1`, and `attack @ 0x10059140` uses `ai_charge` with `dist 0`; the direct hook set is now `163 -> kigrax_dead`, `176/180 -> kigrax_strike1`, `188 -> kigrax_strike2`, and `198 -> kigrax_fire_plasma`
- the Spider module now also has an exact retail move-root and frame-payload map for all thirteen animation tables: stand `@ 0x1005CA00` uses direct `ai_stand @ 0x10001220` with `dist 0` and no direct `spider_step` hook, walk `@ 0x1005CA88` uses `ai_walk` with `dist 0,4,6,4,2,0,4,6,4,2`, run1 `@ 0x1005CB10` uses `ai_run` with hooks `67 -> spider_charge_start` and `72 -> spider_charge_end`, run2 `@ 0x1005CB68` uses `ai_run` with `dist 16`, the melee and rocket tables use `ai_charge` with the expected retail hit or rocket hooks, `pain2 @ 0x1005CDF8` uses `ai_move` with `dist -16,-32,-8,0,0,0,0,0`, and both death tables now have direct nonzero retail falloff sequences rather than the current source's all-zero placeholders
- the Spider data and control surface is now also direct: `SP_monster_spider` loads `models/monsters/spider/tris.md2`, reuses Gladiator melee or pain or idle or search sounds plus `mutant/thud1.wav`, overwrites the temporary mutant sight preload with `spider/sight.wav`, installs `spider_checkattack @ 0x10021460` into `monsterinfo.checkattack`, and the only direct committed consumer of the cached step/thud slot is `spider_charge_end`, which leaves source-side `spider_step` looking like pure factoring unless a second retail signal appears
- the remaining Kigrax uncertainty is now narrow rather than data-wide: `hover/hovdeth1.wav` plus the preloaded `kigrax/hovatck1.wav` are not referenced by any recovered standalone Kigrax callback
- the selected-function summary now records whether an existing exact-address function was renamed into a stable retail symbol during the temporary analysis pass

Observed handshake summary from the current Ghidra plus HLIL cross-check:

- copies `0xB0` bytes (`0x2C` dwords) from the incoming `game_import_t` into the global import table
- returns the export block rooted at `0x1006C120`
- sets `apiversion = 3`
- sets `edict_size = 0x3D0`
- wires the standard Quake II callback cluster through retail Oblivion implementations

## Tooling

- Headless exporter script: `scripts/ghidra/ExportOblivionReference.java`
- Runner wrapper: `scripts/ghidra/run_oblivion_reference.ps1`
- Targeted helper exporter: `scripts/ghidra/ExportSelectedFunctions.java`
- Targeted runner wrapper: `scripts/ghidra/run_oblivion_selected_functions.ps1`
- Optional GhidrAssistMCP bootstrap: `scripts/ghidra/setup_ghidrassist_mcp.ps1`
- Default Ghidra install path used by the wrapper:
  - `C:\Users\djdac\Tools\ghidra_12.0.4_PUBLIC`

## Optional Live MCP Analysis

GhidrAssistMCP is an interactive analysis aid, not a canonical evidence source by itself.

Quick setup:

```powershell
scripts\ghidra\setup_ghidrassist_mcp.ps1 -Mode release
```

Full setup and usage details:

- `docs-dev/ghidrassist-mcp.md`

## Regeneration

Run from repository root:

```powershell
scripts\ghidra\run_oblivion_reference.ps1 -BinaryPath "C:\q2Clean\oblivion\gamex86.dll"
```

Optional parameters:

- `-GhidraHome` to point at another Ghidra install
- `-OutputRoot` to write to a different output directory
- `-MaxDecompFunctions` to tune the wide decompile hint set

For focused callback/helper recovery:

```powershell
scripts\ghidra\run_oblivion_selected_functions.ps1 -BinaryPath "C:\q2Clean\oblivion\gamex86.dll"
```

## Reconstruction Rules

- Treat Ghidra exports as evidence, not drop-in source code.
- Cross-check each semantic claim with at least two signals:
  - Ghidra corpus files
  - Binary Ninja HLIL extracts
  - import/export behavior
  - constants, strings, or offset patterns
  - stock Quake II source analogs
- Keep observed facts separate from inferred meaning in notes.
- Track confidence when renaming functions, globals, or struct fields.
- Prefer interface edges first:
  - `GetGameAPI`
  - import table layout
  - export table slot population
  - persistent globals like `edict_size`

## Active Mapping Workflow

Use these files together:

- `reference/reverse-engineering/corpus-map.md`
- `docs-dev/game-api-mapping-mvp.md`
- `docs-dev/reverse-engineering-export-evidence.md`
- `docs-dev/reverse-engineering-symbol-map.md`

Each reverse-engineering pass should:

1. Refresh the Ghidra corpus if the binary or analysis state changed.
2. Confirm `GetGameAPI` behavior and any recovered slot mappings.
3. Record evidence-backed additions in the export evidence log.
4. Reflect stable conclusions in source reconstruction work and parity docs.

## Open Questions From First Ghidra Pass

- Ghidra currently reports `62` imports, while the existing HLIL-oriented notes mention `75`; that difference should be reconciled before treating import counts as settled metadata.
- Retail `gamex86.dll` currently exposes `monster_badass`, not `monster_sentinel`, so the feature-flagged `src/game/m_sentinel.c` should continue to be treated as reconstruction-only until a second retail signal appears.
- Ghidra decompilation now recovers the full export callback cluster directly when driven through the targeted pass, and it now also covers the wider item subsystem through lookup, timed-use powerups, key pickup, health spawn wrappers, armor, power-armor, dropped-item touchability, trigger-spawn activation, respawn, and spawn flow, the early `g_misc.c` world-entity band including `SP_light_mine1` and `SP_light_mine2` plus the lower-address pathing/debug/light helpers (`SP_path_corner`, `point_combat_touch`, `SP_point_combat`, `TH_viewthing`, `SP_viewthing`, `SP_info_notnull`, `SP_light`, `light_use`), the core retail RTDU band (`rtdu_use @ 0x10014270`, `RTDU_SpawnTurret @ 0x100142E0`, `RTDU_TurretThink @ 0x10014320`, `RTDU_RemoveTurret @ 0x100144C0`, `RTDU_BeginRemoteView @ 0x10014530`, `RTDU_EndRemoteView @ 0x100145C0`, `RTDU_TurretAttack @ 0x10014610`, the direct RTDU client callback `0x10014750`, and `RTDU_InitTurret @ 0x100147D0`), the main HUD/view/trail band, the death/respawn path, the actor path-idle helper cluster, the newly recovered low-address `g_ai.c` wrapper band (`ai_move @ 0x10001090`, `FUN_100010b0 @ 0x100010B0`, `ai_stand_tail @ 0x10001170`, direct `ai_stand @ 0x10001220`, `ai_walk @ 0x10001350`, `ai_charge @ 0x10001430`, `ai_turn @ 0x100014A0`), the adjacent monster combat and movement band, the widened weapon layer through retail detpack/remote-detonator and DOD recovery plus the directly recovered shared retail plasma helper `Weapon_Plasma_Fire @ 0x10037DE0`, the underlying projectile-helper layer including direct `blaster_touch @ 0x1001BF10`, direct `fire_blaster @ 0x1001C000`, direct `rocket_touch @ 0x1001C960`, direct `fire_rocket @ 0x1001CAD0`, direct `fire_rail @ 0x1001CF50`, direct `bfg_explode @ 0x1001D120`, direct `bfg_touch @ 0x1001D2E0`, direct `bfg_think @ 0x1001D440`, direct `fire_bfg @ 0x1001D6F0`, the retail Obliterator projectile pair, and the retail DoD local helper pair `dod_client_reset @ 0x1001ECA0` / `dod_pulse_think @ 0x1001ECC0`, the shared dodge/math helper band including `anglemod` and `VectorNormalize`, and `Oblivion_UpdateWeaponRegen`; HLIL and source cross-reference are still required for broader subsystem naming and for resolving the remaining mission deltas plus the remaining RTDU-adjacent gap (`G_RestoreRTDUTurretLinks`), the retail-only dummy-body or spectator-support cluster around `0x10002CA0` / `0x10002D40` / `0x10002DE0` / `0x10002E20`, the now-reconstructed retail/source naming delta where `weapon_hellfury @ 0x10046EC8` aliases `Weapon_Obliterator @ 0x100386D0` in the item table, `Pickup_Weapon` preserves the retail `16`-rocket ammo grant, `Cmd_UseToggle_f @ 0x10004870` plus its private parser helper at `0x10004750` are now mirrored in `src/game/g_cmds.c` through the retail `usetoggle` dispatcher plus apostrophe-delimited multiword item parsing, the still-unisolated standalone `ai_fly` body, and the remaining source-structure choice in this low-address `g_misc.c` region to keep compiler-folded locals such as `path_corner_touch` documented as embedded labels rather than forcing standalone symbols.
