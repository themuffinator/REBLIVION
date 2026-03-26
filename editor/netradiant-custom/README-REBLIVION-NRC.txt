REBLIVION NetRadiant-Custom pack
================================

Extract this archive into the NetRadiant-Custom root directory so the bundled
`gamepacks/` folder merges with the existing one.

Recommended setup inside NRC:
- Select the `REBLIVION` game pack.
- Use the known mod/game directory `reblivion`.
- Point `EnginePath` at the Quake II rerelease root that contains `baseq2/`
  and `reblivion/`.
- Drop `ericw-tools` binaries under `NetRadiant-Custom\\ericw\\`.

The pack uses the stock Quake II rerelease q2re FGD set in `baseq2/`, then
adds a generated `reblivion/` runtime delta built from the current REBLIVION
source tree with legacy Oblivion metadata used only as a fallback. That keeps
retail q2re entities intact while exposing the extra rerelease/runtime and
REBLIVION-specific classes level designers can actually use in this mod.
