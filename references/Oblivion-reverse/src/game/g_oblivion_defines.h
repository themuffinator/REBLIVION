/*
==============================================================================

  Oblivion specific defines and flags

==============================================================================
*/

#ifndef G_OBLIVION_DEFINES_H
#define G_OBLIVION_DEFINES_H

// Retail Oblivion-specific Means of Death recovered from the player obituary
// tables. `MOD_MINE` aliases the same numeric slot as `MOD_TARGET_LASER` and
// is disambiguated by attacker context.
#define MOD_MINE 30
#define MOD_TARGET_RAILGUN 34
#define MOD_DEATOMIZER 35
#define MOD_DISINTEGRATOR MOD_DEATOMIZER
#define MOD_DEATOMIZER_SPLASH MOD_DEATOMIZER
#define MOD_PLASMA_PISTOL 36
#define MOD_PLASMA_RIFLE 37
#define MOD_DETPACK 38
#define MOD_REMOTE_DETONATOR MOD_DETPACK
#define MOD_OBLITERATOR 39
#define MOD_LASERCANNON MOD_OBLITERATOR
#define MOD_HELLFURY MOD_OBLITERATOR
#define MOD_DONUT 40
#define MOD_REMOTE_CANNON 41
#define MOD_MINE_SPLASH 42

// Spawnflags (SVF_) or Entity Flags (FL_)
// Using available bits where possible.
// SVF_NOCLIENT = 1, SVF_DEADMONSTER = 2, SVF_MONSTER = 4
#define SVF_PROJECTILE 0x00000008

// FL_ flags typically start at 0x00000001 (FL_FLY). standard goes up to
// 0x00002000 (FL_RESPAWN) Picking a high bit for safety.
#define FL_DODGE 0x00004000

// Effect Flags (EF_)
// Using a define to map to existing or unused flag
#define EF_DUALFIRE EF_ANIM_ALLFAST

#endif
