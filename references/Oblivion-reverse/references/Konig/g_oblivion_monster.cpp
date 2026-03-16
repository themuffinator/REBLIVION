// Licensed under the GNU General Public License 2.0.

#include "../g_local.h"

/*
=================

fire_deatomizer

=================
*/

THINK(deatom_think) (edict_t* self) -> void
{
	self->s.frame++;

	if (self->s.frame > 14)
		self->s.frame = 0;

	self->nextthink = level.time + 10_hz;
}

TOUCH(deatom_touch) (edict_t* self, edict_t* other, const trace_t& tr, bool other_touching_self) -> void
{
	if (other == self->owner)
		return;

	if (tr.surface && (tr.surface->flags & SURF_SKY))
	{
		G_FreeEdict(self);
		return;
	}

	// PMM - crash prevention
	if (self->owner && self->owner->client)
		PlayerNoise(self->owner, self->s.origin, PNOISE_IMPACT);

	gi.sound(self, CHAN_WEAPON, gi.soundindex("deatom/dimpact.wav"), 1, ATTN_NORM, 0);

	if (other->takedamage)
	{
		T_Damage(other, self, self->owner, self->velocity, self->s.origin, tr.plane.normal, self->dmg, 1, DAMAGE_ENERGY, MOD_DISINTEGRATOR);

		if (other->health <= 0) // target was killed
		{
			gi.WriteByte(svc_temp_entity);
			gi.WriteByte(TE_TELEPORT_EFFECT);
			gi.WritePosition(other->s.origin);
			gi.multicast(other->s.origin, MULTICAST_PVS, false);
			G_FreeEdict(other);
		}
	}
	else
	{
		gi.WriteByte(svc_temp_entity);
		gi.WriteByte(TE_BLUEHYPERBLASTER);
		gi.WritePosition(self->s.origin);
		gi.WriteDir(tr.plane.normal);
		gi.multicast(self->s.origin, MULTICAST_PHS, false);
	}

	G_FreeEdict(self);
}

void fire_deatom(edict_t* self, const vec3_t& start, const vec3_t& dir, int damage, int speed)
{
	edict_t* deatom;
	trace_t	 tr;

	gi.sound(self, CHAN_WEAPON, gi.soundindex("deatom/dfire.wav"), 1, ATTN_NORM, 0);

	deatom = G_Spawn();
	deatom->s.origin = start;
	deatom->s.old_origin = start;
	deatom->s.angles = vectoangles(dir);
	deatom->velocity = dir * speed;
	deatom->svflags |= SVF_PROJECTILE;
	deatom->movetype = MOVETYPE_FLYMISSILE;
	deatom->clipmask = MASK_PROJECTILE;
	deatom->flags |= FL_DODGE;

	// [Paril-KEX]
	if (self->client && !G_ShouldPlayersCollide(true))
		deatom->clipmask &= ~CONTENTS_PLAYER;

	deatom->solid = SOLID_BBOX;
	deatom->s.effects |= EF_DUALFIRE;
	deatom->dmg_radius = 128;
	deatom->s.modelindex = gi.modelindex("models/objects/deatom/tris.md2");
	deatom->s.scale = 0.75f;
	deatom->touch = deatom_touch;
	deatom->s.sound = gi.soundindex("deatom/dfly.wav");

	deatom->owner = self;
	deatom->nextthink = level.time + 2_sec;
	deatom->think = G_FreeEdict;
	deatom->dmg = damage;
	deatom->classname = "deatom";

	deatom->think = deatom_think;
	deatom->nextthink = level.time + 10_hz;
	gi.linkentity(deatom);

	tr = gi.traceline(self->s.origin, deatom->s.origin, deatom, deatom->clipmask);
	if (tr.fraction < 1.0f)
	{
		deatom->s.origin = tr.endpos + (tr.plane.normal * 1.f);
		deatom->touch(deatom, tr.ent, tr, false);
	}
}

void monster_fire_deatom(edict_t* self, const vec3_t& start, const vec3_t& dir, int damage, int speed, monster_muzzleflash_id_t flashtype)
{
	if (EMPNukeCheck(self, self->s.origin))
	{
		gi.sound(self, CHAN_AUTO, gi.soundindex("items/empnuke/emp_missfire.wav"), 1, ATTN_NORM, 0);
		return;
	}

	fire_deatom(self, start, dir, damage, speed);
	monster_muzzleflash(self, start, flashtype);
}