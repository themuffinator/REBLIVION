# Oblivion Feature Port Plan

Purpose: identify the unique Oblivion gameplay and content features that need to be carried onto the Quake II Rerelease codebase, and establish an initial implementation order.

## Scope and assumptions

- This plan is based on the player-facing feature list in `references/Oblivion-reverse/pack/Oblivion manual.txt` plus technical evidence in `references/Oblivion-reverse/docs/` and `references/Oblivion-reverse/docs-dev/`.
- The manual covers the public-facing feature set, but not every support system needed to make the retail mod function. This plan therefore separates confirmed gameplay features from required support systems.
- Where retail naming and reconstruction naming differ, retail behavior takes priority. The main example is the manual's Sentinel, which current reverse notes map to the retail `monster_badass` surface rather than a distinct confirmed `monster_sentinel` implementation.

## Confirmed Oblivion-unique feature set

### 1. Weapons and player gear

- Deatomizer / Deatomiser
  - Homing energy projectile.
  - High single-shot lethality with disintegration-style behavior.
  - Also used by enemy variants, so this is both a player weapon and an AI combat dependency.
- Laser Mine
  - Thrown mine.
  - Proximity-triggered jump to target height.
  - Emits perpendicular laser beams for a timed burn window, then explodes.
  - Reverse notes suggest the retail implementation hangs off the proximity-mine weapon path and supporting laser child entities, not a separate public gitem surface.
- Plasma Pistol
  - Self-regenerating plasma ammo behavior.
  - Uses the shared retail plasma projectile path.
- Plasma Rifle
  - Stronger plasma weapon using the same core projectile helper as the pistol.
  - Upgradeable processor/capacity concept in the design surface.
  - Depends on the Oblivion weapon regeneration path.
- DetPack
  - Placeable high explosive.
  - Remote-detonated.
  - Durable enough that incidental damage should not trivially trigger it.
  - Requires the paired Remote Detonator workflow.
- Remote Detonator
  - Separate player-use surface for detonating planted detpacks.
  - Needed even though it is not called out as a headline manual item.
- Hellfury
  - Heavy energy/rocket-class weapon.
  - Reverse notes indicate the retail item table aliases this to the Obliterator weapon path.
- Donut of Destruction
  - Distinct special weapon with toroidal shockwave behavior.
  - Reverse notes map this to the retail DOD code path and helpers such as `dod_client_reset`, `dod_pulse_think`, and `fire_dod`.

### 2. New enemies

- Spider
  - Rocket-heavy agile monster with leap/melee pressure.
  - Reverse project indicates this is already well understood and mostly parity-aligned there.
- Kigrax
  - Hovering/strafing plasma attacker with melee support.
  - Reverse project still flags attack cleanup and some pain/death behavior as incomplete.
- Deatomizer Soldier
  - Fast soldier variant using the Deatomizer.
  - Likely depends on adapting an existing soldier family with the Oblivion weapon path and timing.
- Cyborg
  - Heavier deatomizer-based enemy with more elaborate ranged attack chains.
  - Reverse notes show significant AI and animation coverage still matters for parity.
- Sentinel
  - Public/manual-facing name.
  - Current reverse-engineering evidence says retail exposes `monster_badass`, not a separate confirmed `monster_sentinel` token, so implementation should target retail behavior first and keep the Sentinel label as a presentation concern unless stronger evidence appears.

### 3. Mission and map scripting features

- Mission/objective briefing flow.
  - Field-computer messaging.
  - F1-readable mission text.
  - “new information” notification behavior.
- Mission timers and state.
  - Reverse notes call out retail-adjacent mission timer fields and serialization concerns.
- `misc_actor` / `target_actor` pathing and scripted combat behaviors.
  - Includes Oblivion-specific defaults such as optional `targetname` with injected fallback and START_ON-style activation behavior.
- `target_help` usage as part of the mission/help surface.
- Custom spawn coverage for Oblivion content.
  - Weapons, ammo, monsters, mission-critical objects, and map entities must all parse correctly from Oblivion maps.

### 4. Additional support surfaces likely required for parity

- Expanded or altered save/load state for mission and controller data.
- Additional spawn wrappers and classname support such as `func_rotate_train`, `light_mine1`, and `light_mine2` where retail evidence exists.
- Command/UI support for weapon switching and paired-use flows such as Plasma Rifle and Remote Detonator.
- HUD/stat integration for mission messaging, objectives, and possibly regenerating weapon state.

## Reuse opportunities in the Rerelease base

The Quake II Rerelease base already provides useful nearby systems that should reduce implementation cost:

- `src/g_spawn.cpp`, `src/g_target.cpp`, and `src/m_actor.cpp` already include `target_help`, `target_actor`, and `misc_actor` surfaces that can be extended toward Oblivion behavior.
- Rogue code already contains proximity-mine infrastructure under `src/rogue/g_rogue_newweap.cpp` and launcher support under `src/rogue/p_rogue_weapon.cpp`.
- Xatrix code already contains plasma projectile helpers under `src/xatrix/g_xatrix_weapon.cpp`.
- The rerelease base already has modernized monster, item, and projectile frameworks that are easier to extend than porting directly from older Quake II code.

## Initial implementation order

### Phase 1. Establish the Oblivion gameplay substrate

Goal: make the rerelease DLL capable of loading Oblivion maps and supporting the non-weapon systems those maps depend on.

- Audit Oblivion map classnames and compare them against `src/g_spawn.cpp`.
- Add missing spawn entries for confirmed Oblivion entities, weapons, ammo, monsters, and mission helpers.
- Port required retail default values and spawnflag mutations for those entities.
- Verify `misc_actor`, `target_actor`, and `target_help` behavior against reverse notes, especially startup/default handling.
- Add any required persistent mission/controller fields before gameplay logic depends on them.

Reason for doing this first:
- Without correct spawn coverage and mission scripting support, later weapon and monster work cannot be validated on real Oblivion content.

### Phase 2. Reconstruct the custom weapon framework

Goal: establish all player-usable Oblivion weapons and their item/ammo surfaces.

- Implement the Deatomizer weapon and its projectile/helper path.
- Implement shared plasma weapon support plus the regen system used by Plasma Pistol and Plasma Rifle.
- Implement DetPack placement and Remote Detonator usage as one feature pair.
- Implement DOD as its own projectile/pulse system.
- Implement Hellfury via the retail Obliterator path rather than inventing a separate behavior branch.
- Wire weapon entries, pickups, icons, precaches, ammo routing, and command aliases.

Reason for this order:
- Weapon behavior drives both player-facing validation and later enemy porting, especially Deatomizer Soldier and Cyborg.

### Phase 3. Build the Laser Mine on top of mine/proximity infrastructure

Goal: use the closest existing rerelease and Rogue behaviors to deliver the retail Laser Mine flow.

- Start from the Rogue proximity mine path rather than building from scratch.
- Add Oblivion-specific trigger behavior: jump/lift activation, beam entity creation, timed laser burn, then detonation.
- Support map-spawned and player-thrown variants if retail maps rely on both.
- Validate laser orientation, damage persistence, and cleanup behavior.

Reason for isolating this phase:
- The mine has a more complex lifecycle than the other weapons and is best implemented after the basic projectile/item framework is stable.

### Phase 4. Port the new enemy roster

Goal: add the unique Oblivion combat identity once the required weapon/projectile systems exist.

- Spider: bring across the known retail move tables and attack selection if missing from the rerelease branch.
- Kigrax: port hover/strafing loops, ranged/melee timing, and remaining retail pain/death cleanup.
- Cyborg: port full mmove coverage, attack variety, pain logic, audio, and wounded-state behaviors.
- Deatomizer Soldier: build on the rerelease soldier family with the Oblivion Deatomizer attack path and movement tuning.
- Sentinel / Badass: implement the retail `monster_badass` behavior first, then decide whether a separate `monster_sentinel` compatibility alias is needed.

Reason for this order:
- These enemies depend on the custom weapon systems and on correct spawn support.

### Phase 5. Complete mission flow and player-facing UX

Goal: make Oblivion feel like Oblivion rather than just exposing its weapons and monsters.

- Port field-computer mission updates and notification logic.
- Restore mission/help text pathways and any blinking/status indicator behavior supported by the rerelease HUD.
- Validate actor-driven scripted sequences and objective progression on real maps.
- Confirm save/load correctness for mission timers, actor/controller state, and objective status.

Reason for this order:
- This phase depends on entities, weapons, and monsters already existing so the mission layer can be validated in context.

### Phase 6. Map entity and mover parity cleanup

Goal: close the non-headline gameplay gaps that still affect real map behavior.

- Implement or verify `func_rotate_train` and other mover/entity wrappers surfaced by retail notes.
- Add/verify `light_mine1`, `light_mine2`, and any other confirmed Oblivion map helpers.
- Audit spawn defaults for doors, movers, and triggers that differ from stock Quake II behavior.

Reason for this order:
- These are necessary for reliable map completion, but they are lower priority than the core weapon/monster/mission identity.

### Phase 7. Regression, parity checks, and content validation

Goal: lock the port down so feature work does not regress as later parity fixes land.

- Add focused regression coverage per custom weapon.
- Add focused regression coverage for Spider, Kigrax, Cyborg, and the Badass/Sentinel surface.
- Validate map spawn manifests against Oblivion expectations.
- Run playthrough slices on representative maps covering mission scripting, mine usage, plasma regen, detpack flows, and boss/elite encounters.

## Recommended first implementation slice

The first practical slice should be:

1. Spawn-table audit and missing Oblivion classname support.
2. Actor/help/mission helper behavior alignment.
3. Shared custom weapon substrate: Deatomizer, plasma helper, regen state, detpack placement, remote detonation.
4. Laser Mine built on the existing Rogue proximity infrastructure.

This slice gives the port a working gameplay backbone without yet committing to the full monster parity burden.

## Open questions to resolve during implementation

- Whether the rerelease HUD can host the Oblivion mission notification surface directly or needs an adapted equivalent.
- Whether Plasma Rifle “upgrades” were purely map/item progression or require persistent per-player processor state beyond the current reverse notes.
- Whether any retail-only support systems outside the manual, such as RTDU-related features, should be treated as required Oblivion scope for this port or held until confirmed by map/content usage.
- Whether the project should expose `monster_sentinel` as a compatibility alias to the retail `monster_badass` behavior for mapper familiarity.