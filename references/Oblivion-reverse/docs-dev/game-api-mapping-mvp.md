# Oblivion Game API Mapping (Initial) and MVP Plan

Date: 2026-03-14

## Objective

Map the retail Oblivion `gamex86.dll` interface tightly enough that reconstruction work can move from raw HLIL reading toward stable, evidence-backed function and structure recovery.

MVP targets:

- Confirm the retail DLL export surface.
- Confirm `GetGameAPI` wiring and `game_export_t` population.
- Build an incremental map of the returned export table.
- Use the Ghidra corpus to prioritize high-value subsystem recovery.

## Evidence Sources

- `reference/reverse-engineering/ghidra/gamex86/*`
- `references/HLIL/oblivion/gamex86.dll_hlil.txt`
- `references/HLIL/oblivion/split/*`
- `references/Assembly/Oblivion/gamex86.dll_disassembly.txt`
- `references/source-code/Quake-2-master/game/*`
- retail binary: `C:\q2Clean\oblivion\gamex86.dll`

## Initial Export-Mapping Plan

### 1. Confirm the DLL export edge

Confirmed from the current Ghidra corpus:

- `GetGameAPI` at `0x1000D490`
- image base `0x10000000`
- one gameplay-facing DLL export in `exports.txt`
- committed export decompilation in `decompile_exports.c`

### 2. Map `GetGameAPI`

Confirmed from Ghidra plus HLIL:

- copies `0xB0` bytes (`0x2C` dwords) from the engine import table into the module global import block at `0x1006C1C0`
- returns the `game_export_t` block rooted at `0x1006C120`
- sets `apiversion = 3`
- sets `edict_size = 0x3D0`

### 3. Current high-confidence `game_export_t` slot map

- `[0]` `apiversion = 3`
- `[1]` `Init = 0x100158D0` (`InitGame`)
- `[2]` `Shutdown = 0x1000D460` (`ShutdownGame`)
- `[3]` `SpawnEntities = 0x10016C60`
- `[4]` `WriteGame = 0x10016020`
- `[5]` `ReadGame = 0x10016100`
- `[6]` `WriteLevel = 0x10016400`
- `[7]` `ReadLevel = 0x100164E0`
- `[8]` `ClientConnect = 0x10031950`
- `[9]` `ClientBegin = 0x10031610`
- `[10]` `ClientUserinfoChanged = 0x10031760`
- `[11]` `ClientDisconnect = 0x10031C30`
- `[12]` `ClientCommand = 0x100055F0`
- `[13]` `ClientThink = 0x10031D70`
- `[14]` `RunFrame = 0x1000D940`
- `[15]` `ServerCommand = 0x10017850`
- `[16]` `edicts` global present at `0x1006C160`, with live array base observed as `DAT_1006C2C4`
- `[17]` `edict_size = 0x3D0`
- `[18]` `num_edicts` global at `0x1006C168`
- `[19]` `max_edicts` global at `0x1006C16C`

### 4. Keep mapping incremental

- Only promote names or struct interpretations when supported by multiple signals.
- Preserve unknown slots as address-backed placeholders until evidence is stronger.
- Update `docs-dev/reverse-engineering-export-evidence.md` after each confirmed addition.
