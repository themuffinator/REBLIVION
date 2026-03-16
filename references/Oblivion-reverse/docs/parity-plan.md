# Parity Restoration Plan

Purpose: track the work required to bring the reconstructed Oblivion game DLL to feature parity with the retail binary. Status values will be updated as each milestone finishes.

## Current parity gaps (audit snapshot)
- **Spawn coverage** – HLIL manifests show core Quake II items, weapons, keys, and trigger/target classes missing from `g_spawn.c`, so retail maps drop entities during parsing.【F:docs/manifests/spawn_manifest_comparison.json†L2-L59】【F:docs/manifests/spawn_manifest_comparison.json†L18-L55】
- **Default seeds and spawnflag handling** – Moving brushes, mission helpers, and several monsters lack the default speed/accel/decel and AI pointer assignments present in the retail DLL; brush entities also diverge on spawnflag bit clearing (e.g., `func_door`).【F:docs/manifests/spawn_manifest_comparison.json†L65-L183】
- **Monster AI completeness** – Cyborg, spider, and kigrax behaviour still differs from the HLIL snapshot (collapsed mmove tables, simplified attack/pain handling, missing salvo/hull toggles).【F:docs/monster_ai_discrepancies.md†L6-L82】【F:docs/monster_ai_discrepancies.md†L84-L180】
- **Mission/path actors** – `misc_actor` and related mission scripting paths add hidden defaults (e.g., injected `"Yo Mama"` targetname, START_ON spawnflag) and broadened timers that need verification across spawn, save, and think loops. Audit also shows `mission_velocity`/`mission_blend` are serialized but not yet consumed when building mission objectives, so HLIL validation is still required.【F:docs/oblivion_reverse_analysis.md†L35-L206】【F:src/game/g_local.h†L65-L76】【F:src/game/g_save.c†L74-L85】【F:src/game/g_mission.c†L390-L413】

## Work plan (ordered and task-oriented)
- [x] **Draft and check in the parity plan** – Capture the current audit state and ordered milestones in this document.
- [ ] **Rebuild spawn table parity**
  - [x] Enumerate all missing `SP_` entries from the HLIL manifest and map each to source file locations.
    - Missing HLIL entries and likely homes:
      - `%s/listip.cfg` – Not a real spawn; this string comes from the server IP persistence helper in `g_svcmds.c` and should be excluded from spawn reconciliation work.【F:docs/manifests/spawn_manifest_comparison.json†L11536-L11542】【F:src/game/g_svcmds.c†L233-L271】
      - `detpack` – HLIL lists a spawner stub, but the only coverage in-source is the thrown detpack projectile logic in `g_weapon.c` (class `"detpack"`). A future spawner should likely wire into that implementation or add a map-placed variant near the existing detpack helpers.【F:docs/manifests/spawn_manifest_comparison.json†L11536-L11542】【F:src/game/g_weapon.c†L1383-L1542】
      - `grenade` – The HLIL manifest includes a standalone `grenade` spawner. The repo only instantiates grenades through the weapon code paths (`fire_grenade`/`fire_grenade2`), so `g_weapon.c` is the right anchor for adding an `SP_` hook if retail maps expect one.【F:docs/manifests/spawn_manifest_comparison.json†L11536-L11542】【F:src/game/g_weapon.c†L532-L567】
      - `mine` – Reconstructed in `g_weapon.c` as the retail map spawner `SP_mine`, which now feeds the `fire_proximity_mine` projectile path and uses the retail `"mine"` classname throughout.【F:docs/manifests/spawn_manifest_comparison.json†L11536-L11542】【F:src/game/g_weapon.c†L1831-L1901】【F:src/game/g_spawn.c†L257-L257】
      - `j` – HLIL points to `sub_10001350` without a mapped classname in the repo. The decompiled block manipulates entity fields at offsets 0x35c/0x370/0x3c0, so we still need to locate or reconstruct the corresponding game-side function before adding a spawn entry.【F:docs/manifests/spawn_manifest_comparison.json†L11536-L11542】【F:references/HLIL/oblivion/split/types/gamex86.dll_hlil_type_00006_block.txt†L188-L230】
  - [ ] Implement stubs or full spawners for retail items, weapons, keys, triggers, and targets in `g_spawn.c`.
  - [ ] Regenerate spawn manifests and compare against `spawn_manifest_comparison.json` to confirm coverage.
  - [ ] Add regression tests that fail if future spawner omissions reappear.
- [ ] **Restore spawn defaults and spawnflag semantics**
  - [ ] Port default speed/accel/decel and AI pointer wiring for movers, cameras, and monsters noted in the manifest diff.
  - [ ] Mirror retail spawnflag bit mutations (e.g., `func_door` clears) and document rationale inline.
  - [ ] Refresh manifests to verify default values match the retail DLL.
  - [ ] Extend tests to assert on key defaults and spawnflag state transitions.
- [ ] **Complete monster AI parity (cyborg, spider, kigrax)**
  - [ ] Reconstruct HLIL mmove tables and attack/pain sequences for each monster.
  - [ ] Restore special behaviours (kigrax salvo/hull toggles, spider/cyborg audio and timing tables).
  - [ ] Add focused AI regression tests per monster to lock behaviour timelines.
  - [ ] Validate against HLIL traces and update documentation with any remaining deltas.
- [ ] **Verify mission actor/controller parity**
  - [ ] Align `misc_actor`/`target_actor` spawn defaults, START_ON handling, and injected targetnames.
  - [ ] Confirm mission timer/state persistence through save/load and multi-client messaging paths.
  - [ ] Validate `mission_velocity`/`mission_blend` consumption in mission objective updates; currently the mission HUD pipeline only reads origin/angles/radius and timer/flag data.【F:src/game/g_local.h†L65-L76】【F:src/game/g_save.c†L74-L85】【F:src/game/g_mission.c†L400-L413】
  - [ ] Add mission-script regression coverage for spawn, think, and completion loops.
  - [ ] Re-run map-level checks to ensure actor entities spawn and behave identically.
- [ ] **Full-game regression and demo validation**
  - [ ] Rebuild DLL and run spawn/AI/mission regression suites.
  - [ ] Capture parity evidence via manifest diffs and (when possible) demo playback.
  - [ ] Log remaining gaps and backfill earlier milestones as needed.

**Next action when working the plan:** continue wiring the remaining missing `SP_` entries, starting with `detpack` and `grenade`, now that `mine` has been reconstructed in `g_spawn.c` and `g_weapon.c`.
