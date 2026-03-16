# Spawn manifest notes

## Outstanding classname coverage gaps

The latest extractor pass still cannot emit manifest rows for the majority of
classnames listed under `missing_in_hlil` in the comparison snapshot, which
covers the remaining ammo, movers, info nodes, pickups, keys, misc props,
monsters, targets, triggers, turrets, weapons, and even `worldspawn`.
【F:docs/manifests/spawn_manifest_comparison.json†L140-L309】 The parser now
handles inline `strcmp` chains, but most of the unfilled entries live behind
static data blocks or runtime string resolvers that the HLIL dump does not
expand, so those classnames continue to require manual recovery.

## Intentional `func_rotate_train` divergence

`func_rotate_train` never shows up in the interpreted HLIL string tables or the
monolithic dump; the only reference in the split assets is the handwritten stub
at `gamex86.dll_hlil_block9999_sub_10015750.txt`, which mirrors the existing
Quake II code.【F:references/HLIL/oblivion/split/gamex86.dll_hlil_block9999_sub_10015750.txt†L1-L27】 Because there is no literal classname to parse, the runtime
hooks now default to enabled via `OBLIVION_ENABLE_ROTATE_TRAIN` so that the repo
mirrors the recovered HLIL behavior.【F:src/game/g_spawn.c†L64-L76】【F:src/game/g_rtrain.c†L1-L5】
The manifest extractor still honors the macro and omits the repo entry if a
custom build toggles it off, allowing contributors to emulate the retail binary
when necessary.

### Static `spawn_t` table hidden in `data_10046928`

`ED_CallSpawn` (`sub_10016750`) still walks the compiled `spawn_t` array rooted
at `data_10046928` and falls back to the secondary list at `data_1004a5c0` when a
match is not found, yet the HLIL split does not decode either array. The loop
simply iterates the 0x48-byte records, compares the incoming classname, and then
jumps through the stored function pointer, which prevents the parser from seeing
any of the strings in that blob and leaves every item, weapon, key, info node,
and brush class unresolved.【F:references/HLIL/oblivion/split/types/gamex86.dll_hlil_type_00011_block.txt†L303-L413】 Manual strategy:

* Open `data_10046928` in Binary Ninja or a hex viewer and treat every pair of
  pointers as `{ char*, sub_* }`. Cross-reference the character data in
  `gamex86.dll_hlil_block0407_char.txt` (`data_10046e38` →
  `"weapon_grenadelauncher"`) and `gamex86.dll_hlil_block0447_char.txt`
  (`data_10046fa0` → `"weapon_bfg"`) to name the records before wiring the
  associated `sub_` symbols back into the manifest.【F:references/HLIL/oblivion/split/gamex86.dll_hlil_block0407_char.txt†L1-L4】【F:references/HLIL/oblivion/split/gamex86.dll_hlil_block0447_char.txt†L1-L4】
* If a classname does not appear in the char blocks, follow the pointer chain
  `edi += 0x48` in `sub_10016750` with the BN disassembly view to locate the
  literal addresses, then create typed arrays so the extractor can pick them up
  once the structure is defined.

### Runtime lookups via `sub_1000b150`

Many weapon, ammo, and key spawns never compare the literal classname in HLIL.
Instead, helpers such as `sub_10030460` resolve strings like "Plasma Pistol" and
"PistolPlasma" at runtime by calling `sub_1000b150`, converting the result into
an index relative to `data_10046928`, and toggling the corresponding slots.
【F:references/HLIL/oblivion/split/types/gamex86.dll_hlil_type_00019_block.txt†L290-L310】 Because the extractor scans for textual string literals, it never sees
these indirections.

`tools/extract_spawn_manifest.py` now replays those calls when building the
manifest: every literal seen in `sub_1000b150("…")` is resolved back to the
underlying `spawn_t` entry, the `(ptr - &data_10046928) / 0x48` index is
recorded, and the canonical classname/function pair is fed back into the
manifest builder so the ammo/weapon rows no longer require manual annotation.
The interpreted data is stored at
`references/HLIL/oblivion/interpreted/sub_1000b150_map.json`; regenerate it
with:

```
python tools/extract_spawn_manifest.py \
    --dump-b150-map references/HLIL/oblivion/interpreted/sub_1000b150_map.json
```

when a new binary is analyzed. The snapshot test will fail if the map drifts,
making the refresh requirement explicit for contributors.

### Target/trigger names resolved through `sub_1001ad80`

Target-centric classes (e.g., `target_actor`, `target_crosslevel_target`, and
other controller triggers) funnel through `sub_1001ad80`, which walks the target
list, returns the referenced edict, and only then compares its stored classname.
`sub_1001f380` demonstrates the pattern by calling `sub_1001ad80` on `self->target`
and comparing the result to the literal `"target_actor"`, so the parser cannot
see the relationship without executing the call graph.【F:references/HLIL/oblivion/split/types/gamex86.dll_hlil_type_00012_block.txt†L6229-L6355】 Related routines such as the
mission-crosslevel dispatcher around `sub_100166e7` also hard-code controller
names like `"target_crosslevel_target"` in nested loops, again relying on the
runtime traversal instead of a declarative spawn table.【F:references/HLIL/oblivion/split/types/gamex86.dll_hlil_type_00011_block.txt†L200-L260】

* To recover these entries, instrument `sub_1001ad80`/`sub_100166e7` to log the
  string literal they compare and the callback pointer they eventually call, or
  manually read the surrounding HLIL and note the `data_*` label that holds the
  string. Feeding those observations back into the manifest will unblock the
  remaining `target_*`, `trigger_*`, and mission-controller classnames that the
  static parser cannot infer today.
