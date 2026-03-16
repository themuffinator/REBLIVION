# Kigrax HLIL notes

## Spawn wiring (0x10029353–0x100295e2)
- `0x10029363` stores the `self` pointer in `ESI` and calls `gi.soundindex` on the hover/search/sight/pain/death string table (`0x10056b78`–`0x100514f0`), caching the handles at `0x10061260`–`0x10061274`.
- After seeding the audio table, the routine writes the Kigrax spawn defaults: bounding box mins/maxs (`0xbc`–`0xcc`), `movetype` 5, yaw speed at offset `0x1e4`, and the `viewheight` field at `0x23c`.
- The monsterinfo callbacks are wired directly to the hovering state machine: `stand` → `0x100291b0`, `idle/search` selector → `0x10029220`, `walk`/`run` dispatchers at `0x10028f20`/`0x10028ee0`, `sight` at `0x10028e60`, plus the attack handlers `0x10028ee0` and `0x1002f030` stored in `monsterinfo.currentmove` during combat.

## Animation tables recovered from `gamex86.dll`
| Label | Address | Frames | AI helper | Notes |
| --- | --- | --- | --- | --- |
| `kigrax_move_hover` | `0x10058818` | 0–27 | `sub_10001220` (`ai_stand`) | Idle hover loop, no endfunc. |
| `kigrax_move_scan` | `0x10058928` | 28–48 | `sub_10001220` (`ai_stand`) | Extended scan idle; loops back into the selector. |
| `kigrax_move_patrol_ccw` | `0x10058ae0` | 61–82 | `sub_10001350` (`ai_walk`) | Slow strafe that feeds the patrol dispatcher. |
| `kigrax_move_patrol_cw` | `0x10058c08` | 83–104 | `sub_10001350` (`ai_walk`) | Mirror of the previous patrol cycle. |
| `kigrax_move_strafe_long` | `0x10058ce8` | 105–121 | `sub_10002530` (`ai_run`) | Long gliding strafe; feeds the run dispatcher. |
| `kigrax_move_strafe_dash` | `0x10058dc8` | 122–138 | `sub_10002530` (`ai_run`) | Aggressive dash used during combat. |
| `kigrax_move_attack_prep` | `0x10058e60` | 139–149 | `sub_10001090` (`ai_move`) | Zero-distance hover that calls the run dispatcher on completion. |
| `kigrax_move_attack` | `0x10058f58` | 150–168 | `sub_10001090` (`ai_move`) | Burst loop with `0x1002f030` as both the per-frame callback (frame 163) and the mmove end function. |

## Pain and death wiring
- The pain table spans frames 139–149 (`pain1`–`pain11`) with `ai_move` pacing. The first frame seeds `timestamp` for a `0.5` second stagger, and the final frame holds until the timer expires before feeding back into the strafing selectors.
- The death table covers frames 150–168 (`death1`–`death19`) with debris spawns on `death4` and `death11` before the mmove end callback swaps the corpse to the hover-style toss hull and explosion thinker.

`0x1002f030` toggles the bounding box, sets `movetype` flags, fires four energy bolts via `sub_1000dd30`, and then routes back into the `walk`/`run` selectors, which matches the strafing controller assignments described above.
