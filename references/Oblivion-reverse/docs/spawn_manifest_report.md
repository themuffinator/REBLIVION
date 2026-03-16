# Spawn manifest comparison report

This report summarizes the manifest that `tools/extract_spawn_manifest.py` now
builds from the Oblivion retail `gamex86.dll` HLIL dump and the current
reimplementation under `src/game/`. The script emits a consolidated manifest at
`docs/manifests/spawn_manifest.json` and a diff-centric view at
`docs/manifests/spawn_manifest_comparison.json`.

## Overview

* `tools/extract_spawn_manifest.py` parses Quake II-style `field_t` metadata,
  spawn tables, and spawn functions in the HLIL text and cross-references the
  active `SP_` implementations in this repository. The script also walks the C
  sources to recover default assignments and spawnflag mutations so that we can
  diff those behaviours against the original binary.
* `tests/test_spawn_manifest.py` snapshots the generated data to prevent drift
  and ensure future contributors rerun the extractor when the engine changes.

## Entities present in HLIL but missing from the repo

The comparison manifest shows a large gap in fundamental pickup, weapon, key,
trigger, and target classnames. Highlighted groups include:

* **Items and weapons** – standard Quake II items such as
  `item_adrenaline`, `item_enviro`, `item_quad`, `weapon_railgun`, and
  `weapon_supershotgun` do not have corresponding spawn entries in the current
  `g_spawn.c` table. 【F:docs/manifests/spawn_manifest_comparison.json†L2-L59】
* **Keys and mission-critical objects** – the retail binary exposes
  `key_power_cube`, `key_commander_head`, `key_pass`, and map progression keys
  (`key_red_key`, `key_blue_key`, etc.), none of which appear in the reverse
  engineered spawn list. 【F:docs/manifests/spawn_manifest_comparison.json†L18-L41】
* **Triggers and targets** – HLIL includes `trigger_teleport`, `target_rocket`,
  and `target_railgun`, all currently absent. 【F:docs/manifests/spawn_manifest_comparison.json†L42-L55】

Each of these groups will need either full gameplay ports or, at minimum,
placeholder implementations so that map entities do not silently drop during
loading.

## Entities only present in the repo

`monster_sentinel` is implemented in the modern codebase but does not surface in
the retail `gamex86.dll` spawn table, which suggests it was added post-release
or is specific to Oblivion’s fork. The repo now gates its spawn registration
behind `OBLIVION_ENABLE_MONSTER_SENTINEL`, mirroring the rotate-train option so
parity builds can compile without the custom monster and produce clean manifest
diffs. Run `tools/extract_spawn_manifest.py --define
OBLIVION_ENABLE_MONSTER_SENTINEL=0` when regenerating parity-focused manifests
to keep `missing_in_hlil` empty for the sentinel entry. 【F:docs/manifests/spawn_manifest_comparison.json†L60-L63】

## Spawnflag mismatches

Several core movers and interaction points check or mutate different spawnflag
bits compared to the binary:

| Entity             | HLIL behaviour | Repo behaviour |
|--------------------|----------------|----------------|
| `func_door`        | Clears bit 0 (forces re-open) on load | Only checks bits 1, 16, and 64, never clears bit 0 |
| `misc_actor`       | HLIL spawn (`sub_1001f460`) injects `"Yo Mama"` and sets bit 0x20 so `sub_1001f380`/`sub_1001ef70` always receive an addressable controller target | Repo performs the same hidden START_ON write inside `Actor_SpawnOblivion`, but the wrapper-only `SP_misc_actor` keeps the extractor from seeing it |

The gap for `misc_actor` is therefore a reporting artifact: the HLIL manifest
records the hidden START_ON bit, while the repo manifest inspects only `SP_`
wrappers and does not follow helper functions such as `Actor_SpawnOblivion`.
(See `docs/manifests/spawn_manifest_comparison.json` under
`spawnflag_mismatches` for the exact bit sets.)

`func_water` now mirrors the HLIL behaviour: it only respects `START_OPEN`
without injecting additional spawnflag toggles, although the HLIL manifest
still omits the entry and flags it as missing. Manual review of
`sub_20007d20`/`sub_20007fa0` shows the water brush only checks bit 0 and
stores the class name without mutating `spawnflags`. 【F:references/HLIL/quake2/gamex86.dll_hlil.txt†L6074-L6117】

These gaps need manual review—the extractor only records literal bitmasks so
any macro or logic change should be double-checked before porting behaviour.

## Default value drift

The HLIL data reveals broad categories where the reverse engineered code no
longer seeds the same defaults as the retail binary:

* **Moving brushes** – classic brush entities such as `func_plat` set `speed`
  to 20 and `accel`/`decel` to 5 when absent, while our code leaves them at
  zero. 【F:docs/manifests/spawn_manifest_comparison.json†L74-L111】
* **Monsters** – HLIL assigns AI function pointers (`currentmove`, `dodge`,
  behaviour callbacks) and health thresholds during spawn. Our modern code
  expects those to be wired elsewhere, so monsters like `monster_gladiator` and
  `monster_tank` start without the baseline state the binary assumed.
  【F:docs/manifests/spawn_manifest_comparison.json†L124-L183】
* **Miscellaneous scene props** – camera helpers (`misc_camera`,
  `misc_camera_target`), gibs, and banners all receive wait/delay defaults and
  moveinfo setup in the retail binary that we currently skip. That likely leads
  to stuck animations or zero-length think times. 【F:docs/manifests/spawn_manifest_comparison.json†L84-L123】

Bringing these defaults across should be prioritised because they frequently
alter startup timing and AI reliability.

## Recommended follow-ups

1. **Restore core pickup/weapon spawn entries.** Implement (or stub) missing
   `SP_` functions for the item/weapon/key classes above so map parsing matches
   retail expectations, and document any deliberately omitted gameplay changes
   in `docs/`. 【F:docs/manifests/spawn_manifest_comparison.json†L2-L55】
2. **Audit spawnflag handling on movers and actors.** Compare `func_door*`,
   `func_water`, `misc_actor`, `target_actor`, and related
   entities against their HLIL bit usage, porting the missing masks or noting
   intentional behaviour changes. 【F:docs/manifests/spawn_manifest_comparison.json†L65-L101】
3. **Port critical default assignments.** Migrate the binary’s default values
   for brush movement (`func_plat`, `func_train`, etc.), monster AI pointers,
   and camera helpers so that runtime state matches the original game. Include
   inline comments or doc updates summarizing any remaining differences.
   【F:docs/manifests/spawn_manifest_comparison.json†L74-L183】
4. **Document custom-only assets.** Flag entities like `monster_sentinel` as
   Oblivion-specific in design docs to avoid confusion when porting retail
   maps. 【F:docs/manifests/spawn_manifest_comparison.json†L60-L63】

With the snapshot test in place, future engine tweaks that touch spawn logic
must update the manifest, ensuring drift stays visible.
