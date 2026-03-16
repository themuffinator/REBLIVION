/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
// g_actor.c

#include "g_local.h"
#include "m_actor.h"

#define MAX_ACTOR_NAMES 8
#define MODEL_SCALE 1.0f

enum
{
	ACTOR_FRAME_STAND_FIRST = 0,
	ACTOR_FRAME_STAND_LAST = 39,
	ACTOR_FRAME_WALK_FIRST = 40,
	ACTOR_FRAME_WALK_LAST = 45,
	ACTOR_FRAME_RUN_FIRST = 40,
	ACTOR_FRAME_RUN_LAST = 45,
	ACTOR_FRAME_ATTACK_FIRST = 46,
	ACTOR_FRAME_ATTACK_LAST = 53,
	ACTOR_FRAME_PAIN1_FIRST = 54,
	ACTOR_FRAME_PAIN1_LAST = 57,
	ACTOR_FRAME_PAIN2_FIRST = 58,
	ACTOR_FRAME_PAIN2_LAST = 61,
	ACTOR_FRAME_PAIN3_FIRST = 62,
	ACTOR_FRAME_PAIN3_LAST = 65,
	ACTOR_FRAME_FLIPOFF_FIRST = 72,
	ACTOR_FRAME_FLIPOFF_LAST = 83,
	ACTOR_FRAME_TAUNT_FIRST = 95,
	ACTOR_FRAME_TAUNT_LAST = 95,
	ACTOR_FRAME_DEATH1_FIRST = 178,
	ACTOR_FRAME_DEATH1_LAST = 183,
	ACTOR_FRAME_DEATH2_FIRST = 184,
	ACTOR_FRAME_DEATH2_LAST = 189,
	ACTOR_FRAME_DEATH3_FIRST = 190,
	ACTOR_FRAME_DEATH3_LAST = 197
};

static const char *const actor_names[MAX_ACTOR_NAMES] =
{
	"Hellrot",
	"Tokay",
	"Killme",
	"Disruptor",
	"Adrianator",
	"Rambear",
	"Titus",
	"Bitterman"
};

static const char *const actor_messages[] =
{
	"Watch it",
	"#$@*&",
	"Idiot"
};

static void actor_dead(edict_t *self);
static void actorMachineGun(edict_t *self);
static void actor_fire(edict_t *self);
static void actor_attack(edict_t *self);
static void actor_use(edict_t *self, edict_t *other, edict_t *activator);
static void target_actor_touch(edict_t *self, edict_t *other, cplane_t *plane, csurface_t *surf);

/*
=============
Actor_FallbackName
=============
*/
static const char *Actor_FallbackName(edict_t *self)
{
	int index;

	if (!self)
		return actor_names[0];

	index = (int)(self - g_edicts);
	if (index < 0)
		index = 0;

	return actor_names[index % MAX_ACTOR_NAMES];
}

mframe_t actor_frames_stand[] =
{
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL},
	{ai_stand, 0, NULL}
};
mmove_t actor_move_stand = {ACTOR_FRAME_STAND_FIRST, ACTOR_FRAME_STAND_LAST, actor_frames_stand, NULL};

/*
=============
actor_stand
=============
*/
static void actor_stand(edict_t *self)
{
	self->monsterinfo.currentmove = &actor_move_stand;

	if (level.time < 1.0f)
	{
		self->s.frame = self->monsterinfo.currentmove->firstframe
			+ (rand() % (self->monsterinfo.currentmove->lastframe
				- self->monsterinfo.currentmove->firstframe + 1));
	}
}

mframe_t actor_frames_walk[] =
{
	{ai_walk, 8, NULL},
	{ai_walk, 30, NULL},
	{ai_walk, 30, NULL},
	{ai_walk, 16, NULL},
	{ai_walk, 40, NULL},
	{ai_walk, 30, NULL}
};
mmove_t actor_move_walk = {ACTOR_FRAME_WALK_FIRST, ACTOR_FRAME_WALK_LAST, actor_frames_walk, NULL};

/*
=============
actor_walk
=============
*/
static void actor_walk(edict_t *self)
{
	self->monsterinfo.currentmove = &actor_move_walk;
}

mframe_t actor_frames_run[] =
{
	{ai_run, 8, NULL},
	{ai_run, 30, NULL},
	{ai_run, 30, NULL},
	{ai_run, 16, NULL},
	{ai_run, 40, NULL},
	{ai_run, 30, NULL}
};
mmove_t actor_move_run = {ACTOR_FRAME_RUN_FIRST, ACTOR_FRAME_RUN_LAST, actor_frames_run, NULL};

/*
=============
actor_run
=============
*/
static void actor_run(edict_t *self)
{
	if ((level.time < self->pain_debounce_time) || self->enemy)
	{
		if (!(self->monsterinfo.aiflags & AI_STAND_GROUND))
		{
			self->monsterinfo.currentmove = &actor_move_run;
			return;
		}
	}
	else if (self->movetarget)
	{
		actor_walk(self);
		return;
	}

	actor_stand(self);
}

mframe_t actor_frames_pain1[] =
{
	{ai_move, -5, NULL},
	{ai_move, 4, NULL},
	{ai_move, 1, NULL},
	{ai_move, 1, NULL}
};
mmove_t actor_move_pain1 = {ACTOR_FRAME_PAIN1_FIRST, ACTOR_FRAME_PAIN1_LAST, actor_frames_pain1, actor_run};

mframe_t actor_frames_pain2[] =
{
	{ai_move, -4, NULL},
	{ai_move, 0, NULL},
	{ai_move, 4, NULL},
	{ai_move, 0, NULL}
};
mmove_t actor_move_pain2 = {ACTOR_FRAME_PAIN2_FIRST, ACTOR_FRAME_PAIN2_LAST, actor_frames_pain2, actor_run};

mframe_t actor_frames_pain3[] =
{
	{ai_move, -1, NULL},
	{ai_move, -1, NULL},
	{ai_move, 1, NULL},
	{ai_move, 0, NULL}
};
mmove_t actor_move_pain3 = {ACTOR_FRAME_PAIN3_FIRST, ACTOR_FRAME_PAIN3_LAST, actor_frames_pain3, actor_run};

mframe_t actor_frames_flipoff[] =
{
	{ai_turn, 0, NULL},
	{ai_turn, 0, NULL},
	{ai_turn, 0, NULL},
	{ai_turn, 0, NULL},
	{ai_turn, 0, NULL},
	{ai_turn, 0, NULL},
	{ai_turn, 0, NULL},
	{ai_turn, 0, NULL},
	{ai_turn, 0, NULL},
	{ai_turn, 0, NULL},
	{ai_turn, 0, NULL},
	{ai_turn, 0, NULL}
};
mmove_t actor_move_flipoff = {ACTOR_FRAME_FLIPOFF_FIRST, ACTOR_FRAME_FLIPOFF_LAST, actor_frames_flipoff, actor_run};

mframe_t actor_frames_taunt[] =
{
	{ai_turn, 0, NULL}
};
mmove_t actor_move_taunt = {ACTOR_FRAME_TAUNT_FIRST, ACTOR_FRAME_TAUNT_LAST, actor_frames_taunt, actor_run};

/*
=============
actor_pain
=============
*/
static void actor_pain(edict_t *self, edict_t *other, float kick, int damage)
{
	vec3_t v;
	int n;

	(void)kick;
	(void)damage;

	if (level.time < self->pain_debounce_time)
		return;

	self->pain_debounce_time = level.time + 3.0f;

	if (other->client && (random() < 0.4f))
	{
		VectorSubtract(other->s.origin, self->s.origin, v);
		self->ideal_yaw = vectoyaw(v);

		if (random() < 0.5f)
			self->monsterinfo.currentmove = &actor_move_flipoff;
		else
			self->monsterinfo.currentmove = &actor_move_taunt;

		gi.cprintf(other, PRINT_CHAT, "%s: %s!\n",
			Actor_FallbackName(self),
			actor_messages[rand() % 3]);
		return;
	}

	n = rand() % 3;
	if (n == 0)
		self->monsterinfo.currentmove = &actor_move_pain1;
	else if (n == 1)
		self->monsterinfo.currentmove = &actor_move_pain2;
	else
		self->monsterinfo.currentmove = &actor_move_pain3;
}

/*
=============
actorMachineGun
=============
*/
static void actorMachineGun(edict_t *self)
{
	vec3_t forward;
	vec3_t right;
	vec3_t start;
	vec3_t target;

	AngleVectors(self->s.angles, forward, right, NULL);
	G_ProjectSource(self->s.origin, monster_flash_offset[MZ2_ACTOR_MACHINEGUN_1], forward, right, start);

	if (self->enemy)
	{
		if (self->enemy->health > 0)
		{
			VectorMA(self->enemy->s.origin, -0.2f, self->enemy->velocity, target);
			target[2] += self->enemy->viewheight;
		}
		else
		{
			VectorCopy(self->enemy->absmin, target);
			target[2] += self->enemy->size[2] * 0.5f;
		}

		VectorSubtract(target, start, forward);
		VectorNormalize(forward);
	}
	else
	{
		AngleVectors(self->s.angles, forward, NULL, NULL);
	}

	monster_fire_bullet(self, start, forward, 3, 4,
		DEFAULT_BULLET_HSPREAD, DEFAULT_BULLET_VSPREAD,
		MZ2_ACTOR_MACHINEGUN_1);
}

/*
=============
actor_dead
=============
*/
static void actor_dead(edict_t *self)
{
	VectorSet(self->mins, -16, -16, -24);
	VectorSet(self->maxs, 16, 16, -8);
	self->movetype = MOVETYPE_TOSS;
	self->svflags |= SVF_DEADMONSTER;
	self->nextthink = 0;
	gi.linkentity(self);
}

mframe_t actor_frames_death1[] =
{
	{ai_move, 0, NULL},
	{ai_move, 0, NULL},
	{ai_move, -13, NULL},
	{ai_move, 1, NULL},
	{ai_move, 14, NULL},
	{ai_move, 1, NULL}
};
mmove_t actor_move_death1 = {ACTOR_FRAME_DEATH1_FIRST, ACTOR_FRAME_DEATH1_LAST, actor_frames_death1, actor_dead};

mframe_t actor_frames_death2[] =
{
	{ai_move, 0, NULL},
	{ai_move, -6, NULL},
	{ai_move, -5, NULL},
	{ai_move, 1, NULL},
	{ai_move, 1, NULL},
	{ai_move, 0, NULL}
};
mmove_t actor_move_death2 = {ACTOR_FRAME_DEATH2_FIRST, ACTOR_FRAME_DEATH2_LAST, actor_frames_death2, actor_dead};

mframe_t actor_frames_death3[] =
{
	{ai_move, 0, NULL},
	{ai_move, -6, NULL},
	{ai_move, -5, NULL},
	{ai_move, 1, NULL},
	{ai_move, 1, NULL},
	{ai_move, 1, NULL},
	{ai_move, 1, NULL},
	{ai_move, 0, NULL}
};
mmove_t actor_move_death3 = {ACTOR_FRAME_DEATH3_FIRST, ACTOR_FRAME_DEATH3_LAST, actor_frames_death3, actor_dead};

/*
=============
actor_die
=============
*/
static void actor_die(edict_t *self, edict_t *inflictor, edict_t *attacker, int damage, vec3_t point)
{
	int n;

	(void)inflictor;
	(void)attacker;
	(void)point;

	if (meansOfDeath == 0x23)
	{
		BecomeExplosion1(self);
		return;
	}

	if (self->health <= -80)
	{
		for (n = 0; n < 2; n++)
			ThrowGib(self, "models/objects/gibs/bone/tris.md2", damage, GIB_ORGANIC);
		for (n = 0; n < 4; n++)
			ThrowGib(self, "models/objects/gibs/sm_meat/tris.md2", damage, GIB_ORGANIC);
		ThrowHead(self, "models/objects/gibs/head2/tris.md2", damage, GIB_ORGANIC);
		self->deadflag = DEAD_DEAD;
		return;
	}

	if (self->deadflag == DEAD_DEAD)
		return;

	self->deadflag = DEAD_DEAD;
	self->takedamage = DAMAGE_YES;
	self->s.modelindex2 = 0;

	n = rand() % 3;
	if (n == 0)
		self->monsterinfo.currentmove = &actor_move_death1;
	else if (n == 1)
		self->monsterinfo.currentmove = &actor_move_death2;
	else
		self->monsterinfo.currentmove = &actor_move_death3;
}

/*
=============
actor_fire
=============
*/
static void actor_fire(edict_t *self)
{
	actorMachineGun(self);

	if (level.time >= self->monsterinfo.pausetime)
		self->monsterinfo.aiflags &= ~AI_HOLD_FRAME;
	else
		self->monsterinfo.aiflags |= AI_HOLD_FRAME;
}

mframe_t actor_frames_attack[] =
{
	{ai_charge, -2, actor_fire},
	{ai_charge, -2, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 0, NULL},
	{ai_charge, 3, NULL},
	{ai_charge, 2, NULL}
};
mmove_t actor_move_attack = {ACTOR_FRAME_ATTACK_FIRST, ACTOR_FRAME_ATTACK_LAST, actor_frames_attack, actor_stand};

/*
=============
actor_attack
=============
*/
static void actor_attack(edict_t *self)
{
	self->monsterinfo.currentmove = &actor_move_attack;
	self->monsterinfo.pausetime = level.time + ((rand() & 15) + 10) * FRAMETIME;
}

/*
=============
actor_use
=============
*/
static void actor_use(edict_t *self, edict_t *other, edict_t *activator)
{
	vec3_t v;

	(void)other;
	(void)activator;

	self->goalentity = self->movetarget = G_PickTarget(self->target);
	if (!self->movetarget || strcmp(self->movetarget->classname, "target_actor") != 0)
	{
		self->target = NULL;
		self->monsterinfo.pausetime = 100000000.0f;
		self->monsterinfo.stand(self);
		return;
	}

	VectorSubtract(self->goalentity->s.origin, self->s.origin, v);
	self->ideal_yaw = self->s.angles[YAW] = vectoyaw(v);
	self->monsterinfo.walk(self);
	self->target = NULL;
}

/*QUAKED misc_actor (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse x START_ON WIMPY
START_ON		actor immediately begins its scripted path
WIMPY		clear the friendly idle-enemy scan bit
*/

/*
=============
SP_misc_actor
=============
*/
void SP_misc_actor(edict_t *self)
{
	static const int corpse_frames[] =
	{
		ACTOR_FRAME_DEATH1_LAST,
		ACTOR_FRAME_DEATH2_LAST,
		ACTOR_FRAME_DEATH3_LAST
	};

	if (deathmatch->value)
	{
		G_FreeEdict(self);
		return;
	}

	if (!self->targetname)
	{
		self->targetname = "Yo Mama";
		self->spawnflags |= ACTOR_SPAWNFLAG_START_ON;
	}

	self->s.modelindex = 0xff;
	self->s.modelindex2 = 0xff;
	self->movetype = MOVETYPE_STEP;
	self->solid = SOLID_BBOX;
	VectorSet(self->mins, -16, -16, -24);
	VectorSet(self->maxs, 16, 16, 32);

	if (!self->health)
		self->health = 100;
	self->mass = 200;

	if (self->spawnflags & ACTOR_SPAWNFLAG_CORPSE)
	{
		self->s.frame = corpse_frames[rand() % 3];
		self->health = -1;
		self->deadflag = DEAD_DEAD;
		self->takedamage = DAMAGE_YES;
		VectorSet(self->mins, -16, -16, -24);
		VectorSet(self->maxs, 16, 16, -8);
		self->svflags |= SVF_DEADMONSTER;
		self->nextthink = 0;
		gi.linkentity(self);
		return;
	}

	self->pain = actor_pain;
	self->die = actor_die;
	self->use = actor_use;
	self->monsterinfo.stand = actor_stand;
	self->monsterinfo.walk = actor_walk;
	self->monsterinfo.run = actor_run;
	self->monsterinfo.attack = actor_attack;
	self->monsterinfo.melee = NULL;
	self->monsterinfo.sight = NULL;
	self->monsterinfo.currentmove = &actor_move_stand;
	self->monsterinfo.scale = MODEL_SCALE;

	if (!self->target)
		self->monsterinfo.aiflags |= AI_ACTOR_PATH_IDLE;
	if (!(self->spawnflags & ACTOR_SPAWNFLAG_WIMPY))
		self->monsterinfo.aiflags |= AI_ACTOR_FRIENDLY;
	self->monsterinfo.aiflags |= AI_GOOD_GUY;

	gi.linkentity(self);
	walkmonster_start(self);

	/* monster_start() rewires use to monster_use; retail actors keep actor_use. */
	self->use = actor_use;

	if (self->spawnflags & ACTOR_SPAWNFLAG_START_ON)
		self->use(self, world, world);
}

/*QUAKED target_actor (.5 .3 0) (-8 -8 -8) (8 8 8) JUMP SHOOT ATTACK x HOLD BRUTAL
JUMP			jump in set direction upon reaching this target
SHOOT			take a single shot at the pathtarget
ATTACK			attack pathtarget until it or actor is dead

"target"		next target_actor
"pathtarget"	target of any action to be taken at this point
"wait"			amount of time actor should pause at this point
"message"		actor will "say" this to the player

for JUMP only:
"speed"			speed thrown forward (default 200)
"height"		speed thrown upwards (default 200)
*/

/*
=============
target_actor_touch
=============
*/
static void target_actor_touch(edict_t *self, edict_t *other, cplane_t *plane, csurface_t *surf)
{
	vec3_t v;
	edict_t *pathtarget_ent;
	int i;

	(void)plane;
	(void)surf;

	if (other->movetarget != self)
		return;
	if (other->enemy)
		return;

	other->goalentity = NULL;
	other->movetarget = NULL;

	if (self->message)
	{
		for (i = 1; i <= game.maxclients; i++)
		{
			edict_t *ent = &g_edicts[i];

			if (!ent->inuse || !ent->client)
				continue;

			gi.cprintf(ent, PRINT_CHAT, "%s: %s\n",
				Actor_FallbackName(other), self->message);
		}
	}

	if (self->spawnflags & TARGET_ACTOR_FLAG_JUMP)
	{
		other->velocity[0] = self->movedir[0] * self->speed;
		other->velocity[1] = self->movedir[1] * self->speed;

		if (other->groundentity)
		{
			other->groundentity = NULL;
			other->velocity[2] = self->movedir[2];
			gi.sound(other, CHAN_VOICE, gi.soundindex("player/male/jump1.wav"), 1, ATTN_NORM, 0);
		}
	}

	if (self->spawnflags & (TARGET_ACTOR_FLAG_SHOOT | TARGET_ACTOR_FLAG_ATTACK))
	{
		pathtarget_ent = G_PickTarget(self->pathtarget);
		other->enemy = pathtarget_ent;

		if (other->enemy)
		{
			other->goalentity = other->enemy;

			if (self->spawnflags & TARGET_ACTOR_FLAG_SHOOT)
				other->monsterinfo.aiflags |= AI_ACTOR_SHOOT_ONCE;
			if (self->spawnflags & TARGET_ACTOR_FLAG_BRUTAL)
				other->monsterinfo.aiflags |= AI_BRUTAL;

			if (self->spawnflags & (TARGET_ACTOR_FLAG_HOLD | TARGET_ACTOR_FLAG_SHOOT))
			{
				other->monsterinfo.aiflags |= AI_STAND_GROUND;
				actor_stand(other);
			}
			else
			{
				actor_run(other);
			}
		}
	}

	if (self->pathtarget)
	{
		char *savetarget;

		savetarget = self->target;
		self->target = self->pathtarget;
		G_UseTargets(self, other);
		self->target = savetarget;
	}

	other->movetarget = G_PickTarget(self->target);
	if (!other->goalentity)
		other->goalentity = other->movetarget;

	if (!other->movetarget && !other->enemy)
	{
		other->monsterinfo.pausetime = level.time + 100000000.0f;
		actor_stand(other);
		other->monsterinfo.aiflags |= AI_ACTOR_PATH_IDLE;
		return;
	}

	if (other->movetarget == other->goalentity)
	{
		VectorSubtract(other->movetarget->s.origin, other->s.origin, v);
		other->ideal_yaw = vectoyaw(v);
	}
}

/*
=============
SP_target_actor
=============
*/
void SP_target_actor(edict_t *self)
{
	VectorSet(self->mins, -8, -8, -8);
	VectorSet(self->maxs, 8, 8, 8);
	self->solid = SOLID_TRIGGER;
	self->touch = target_actor_touch;
	self->svflags = SVF_NOCLIENT;

	if (self->spawnflags & TARGET_ACTOR_FLAG_JUMP)
	{
		if (!self->speed)
			self->speed = 200;
		if (!st.height)
			st.height = 200;
		if (!self->s.angles[YAW])
			self->s.angles[YAW] = 360;

		G_SetMovedir(self->s.angles, self->movedir);
		self->movedir[2] = st.height;
	}

	gi.linkentity(self);
}
