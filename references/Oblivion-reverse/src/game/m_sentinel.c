/*
 * Sentinel compatibility shim.
 *
 * The enhanced Ghidra and docs-dev mapping currently identifies the retail
 * Oblivion counterpart for this unit as monster_badass rather than a distinct
 * monster_sentinel module. Keep the optional Sentinel spawn surface as a thin
 * bridge into the retail-backed Badass path so enabling it does not preserve a
 * second speculative implementation.
 */

#include "g_local.h"

#if OBLIVION_ENABLE_MONSTER_SENTINEL

void SP_monster_badass (edict_t *self);

/*
=============
SP_monster_sentinel

Retail reverse-engineering currently exposes only the Badass monster surface
for this unit. Rebind the optional Sentinel classname to the retail-backed
spawn routine so the feature-flagged compatibility path stays aligned with the
current evidence.
=============
*/
void SP_monster_sentinel (edict_t *self)
{
	self->classname = "monster_badass";
	SP_monster_badass (self);
}

#endif
