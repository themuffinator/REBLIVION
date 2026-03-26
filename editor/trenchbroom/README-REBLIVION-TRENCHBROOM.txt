REBLIVION TrenchBroom pack
==========================

Extract this archive into the TrenchBroom root directory so the bundled
`games/REBLIVION/` folder lands beside the stock game configurations.

Recommended setup inside TrenchBroom:
- Set the REBLIVION game path to the Quake II rerelease root that contains
  both `baseq2/` and `reblivion/`.
- New REBLIVION maps start with `_tb_mod` set to `reblivion`, so custom
  REBLIVION textures and model previews load on top of the retail q2re assets.
- For older maps, set the worldspawn `_tb_mod` property to `reblivion` if the
  mod is not already enabled in the Map Inspector.

The pack keeps the stock q2re TrenchBroom definitions intact and appends a
generated runtime delta from the current REBLIVION source tree, with legacy
Oblivion metadata used only as a fallback. That preserves the retail q2re
surface while also exposing the extra rerelease/runtime and REBLIVION-specific
entities this mod actually supports.
