/*
==============================================================================

SPIDER

==============================================================================
*/

#include "m_spider.h"
#include "g_local.h"
#include "g_oblivion_monster.h"

#define MODEL_SCALE 1.0f

#define SPIDER_FRAME_STAND_START 0
#define SPIDER_FRAME_STAND_END 54
#define SPIDER_FRAME_WALK_START 55
#define SPIDER_FRAME_WALK_END 64
#define SPIDER_FRAME_RUN1_START 65
#define SPIDER_FRAME_RUN1_END 74
#define SPIDER_FRAME_RUN2_START 75
#define SPIDER_FRAME_RUN2_END 80
#define SPIDER_FRAME_ATTACK_LEFT_START 81
#define SPIDER_FRAME_ATTACK_LEFT_END 85
#define SPIDER_FRAME_ATTACK_RIGHT_START 86
#define SPIDER_FRAME_ATTACK_RIGHT_END 90
#define SPIDER_FRAME_ATTACK_DUAL_START 91
#define SPIDER_FRAME_ATTACK_DUAL_END 98
#define SPIDER_FRAME_MELEE_PRIMARY_START 99
#define SPIDER_FRAME_MELEE_PRIMARY_END 103
#define SPIDER_FRAME_MELEE_SECONDARY_START 104
#define SPIDER_FRAME_MELEE_SECONDARY_END 110
#define SPIDER_FRAME_PAIN1_START 111
#define SPIDER_FRAME_PAIN1_END 116
#define SPIDER_FRAME_PAIN2_START 117
#define SPIDER_FRAME_PAIN2_END 124
#define SPIDER_FRAME_DEATH1_START 125
#define SPIDER_FRAME_DEATH1_END 144
#define SPIDER_FRAME_DEATH2_START 145
#define SPIDER_FRAME_DEATH2_END 164

#define SPIDER_ROCKET_DAMAGE 50
#define SPIDER_ROCKET_SPEED 500
#define SPIDER_MELEE_KICK 300
#define SPIDER_CHARGE_DAMAGE_BASE 40
#define SPIDER_CHARGE_DAMAGE_RANGE 10
#define SPIDER_CHARGE_IMPACT_SPEED 400.0f
#define SPIDER_CHARGE_SPEED 500.0f
#define SPIDER_CHARGE_Z_SPEED 250.0f
#define SPIDER_ATTACK_MIN_RANGE 112.0f

#define SPIDER_MZ_LEFT 0x8a
#define SPIDER_MZ_RIGHT 0x8b

static int sound_step;
static int sound_pain1;
static int sound_pain2;
static int sound_sight;
static int sound_search;
static int sound_idle;
static int sound_melee1;
static int sound_melee2;
static int sound_melee3;

static void spider_idle(edict_t *self);
static void spider_search(edict_t *self);
static void spider_sight(edict_t *self, edict_t *other);
static void spider_melee_swing(edict_t *self);
static void spider_stand(edict_t *self);
static void spider_walk(edict_t *self);
static void spider_charge_think(edict_t *self, edict_t *other, cplane_t *plane,
	csurface_t *surf);
static void spider_charge_start(edict_t *self);
static void spider_charge_end(edict_t *self);
static void spider_run(edict_t *self);
static void spider_melee_hit(edict_t *self);
static void spider_melee(edict_t *self);
static void spider_rocket_left(edict_t *self);
static void spider_rocket_right(edict_t *self);
static void spider_attack(edict_t *self);
static void spider_pain(edict_t *self, edict_t *other, float kick, int damage);
static void spider_dead(edict_t *self);
static void spider_die(edict_t *self, edict_t *inflictor, edict_t *attacker,
	int damage, vec3_t point);
static qboolean spider_checkattack(edict_t *self);

static mframe_t spider_frames_stand[] = {
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},

	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},

	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},

	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},

	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},

	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}, {ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}
};

static mmove_t spider_move_stand = {
	SPIDER_FRAME_STAND_START,
	SPIDER_FRAME_STAND_END,
	spider_frames_stand,
	NULL
};

static mframe_t spider_frames_walk[] = {
	{ai_walk, 0.0f, NULL}, {ai_walk, 4.0f, NULL},
	{ai_walk, 6.0f, NULL}, {ai_walk, 4.0f, NULL},
	{ai_walk, 2.0f, NULL}, {ai_walk, 0.0f, NULL},
	{ai_walk, 4.0f, NULL}, {ai_walk, 6.0f, NULL},
	{ai_walk, 4.0f, NULL}, {ai_walk, 2.0f, NULL}
};

static mmove_t spider_move_walk = {
	SPIDER_FRAME_WALK_START,
	SPIDER_FRAME_WALK_END,
	spider_frames_walk,
	NULL
};

static mframe_t spider_frames_run1[] = {
	{ai_run, 0.0f, NULL}, {ai_run, 0.0f, NULL},
	{ai_run, 0.0f, spider_charge_start}, {ai_run, 0.0f, NULL},
	{ai_run, 0.0f, NULL}, {ai_run, 0.0f, NULL},
	{ai_run, 0.0f, NULL}, {ai_run, 0.0f, spider_charge_end},
	{ai_run, 0.0f, NULL}, {ai_run, 0.0f, NULL}
};

static mmove_t spider_move_run1 = {
	SPIDER_FRAME_RUN1_START,
	SPIDER_FRAME_RUN1_END,
	spider_frames_run1,
	spider_run
};

static mframe_t spider_frames_run2[] = {
	{ai_run, 16.0f, NULL}, {ai_run, 16.0f, NULL},
	{ai_run, 16.0f, NULL}, {ai_run, 16.0f, NULL},
	{ai_run, 16.0f, NULL}, {ai_run, 16.0f, NULL}
};

static mmove_t spider_move_run2 = {
	SPIDER_FRAME_RUN2_START,
	SPIDER_FRAME_RUN2_END,
	spider_frames_run2,
	NULL
};

static mframe_t spider_frames_attack_left[] = {
	{ai_charge, 0.0f, NULL}, {ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, spider_rocket_left}, {ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL}
};

static mmove_t spider_move_attack_left = {
	SPIDER_FRAME_ATTACK_LEFT_START,
	SPIDER_FRAME_ATTACK_LEFT_END,
	spider_frames_attack_left,
	spider_run
};

static mframe_t spider_frames_attack_right[] = {
	{ai_charge, 0.0f, NULL}, {ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, spider_rocket_right}, {ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL}
};

static mmove_t spider_move_attack_right = {
	SPIDER_FRAME_ATTACK_RIGHT_START,
	SPIDER_FRAME_ATTACK_RIGHT_END,
	spider_frames_attack_right,
	spider_run
};

static mframe_t spider_frames_attack_dual[] = {
	{ai_charge, 0.0f, NULL}, {ai_charge, 0.0f, spider_rocket_left},
	{ai_charge, 0.0f, NULL}, {ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL}, {ai_charge, 0.0f, spider_rocket_right},
	{ai_charge, 0.0f, NULL}, {ai_charge, 0.0f, NULL}
};

static mmove_t spider_move_attack_dual = {
	SPIDER_FRAME_ATTACK_DUAL_START,
	SPIDER_FRAME_ATTACK_DUAL_END,
	spider_frames_attack_dual,
	spider_run
};

static mframe_t spider_frames_melee_primary[] = {
	{ai_charge, 0.0f, NULL}, {ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL}, {ai_charge, 0.0f, spider_melee_swing},
	{ai_charge, 0.0f, spider_melee_hit}
};

static mmove_t spider_move_melee_primary = {
	SPIDER_FRAME_MELEE_PRIMARY_START,
	SPIDER_FRAME_MELEE_PRIMARY_END,
	spider_frames_melee_primary,
	spider_run
};

static mframe_t spider_frames_melee_secondary[] = {
	{ai_charge, 0.0f, NULL}, {ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL}, {ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, spider_melee_swing},
	{ai_charge, 0.0f, spider_melee_hit},
	{ai_charge, 0.0f, spider_melee_hit}
};

static mmove_t spider_move_melee_secondary = {
	SPIDER_FRAME_MELEE_SECONDARY_START,
	SPIDER_FRAME_MELEE_SECONDARY_END,
	spider_frames_melee_secondary,
	spider_run
};

static mframe_t spider_frames_pain1[] = {
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL}
};

static mmove_t spider_move_pain1 = {
	SPIDER_FRAME_PAIN1_START,
	SPIDER_FRAME_PAIN1_END,
	spider_frames_pain1,
	spider_run
};

static mframe_t spider_frames_pain2[] = {
	{ai_move, -16.0f, NULL}, {ai_move, -32.0f, NULL},
	{ai_move, -8.0f, NULL}, {ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL}
};

static mmove_t spider_move_pain2 = {
	SPIDER_FRAME_PAIN2_START,
	SPIDER_FRAME_PAIN2_END,
	spider_frames_pain2,
	spider_run
};

static mframe_t spider_frames_death1[] = {
	{ai_move, -8.0f, NULL}, {ai_move, -4.0f, NULL},
	{ai_move, -2.0f, NULL}, {ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, -2.0f, NULL},
	{ai_move, -6.0f, NULL}, {ai_move, -4.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 4.0f, NULL},
	{ai_move, 6.0f, NULL}, {ai_move, 4.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL}
};

static mmove_t spider_move_death1 = {
	SPIDER_FRAME_DEATH1_START,
	SPIDER_FRAME_DEATH1_END,
	spider_frames_death1,
	spider_dead
};

static mframe_t spider_frames_death2[] = {
	{ai_move, -24.0f, NULL}, {ai_move, -22.0f, NULL},
	{ai_move, -20.0f, NULL}, {ai_move, -18.0f, NULL},
	{ai_move, -16.0f, NULL}, {ai_move, -16.0f, NULL},
	{ai_move, -16.0f, NULL}, {ai_move, -16.0f, NULL},
	{ai_move, -16.0f, NULL}, {ai_move, -4.0f, NULL},
	{ai_move, -12.0f, NULL}, {ai_move, -8.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}, {ai_move, 0.0f, NULL}
};

static mmove_t spider_move_death2 = {
	SPIDER_FRAME_DEATH2_START,
	SPIDER_FRAME_DEATH2_END,
	spider_frames_death2,
	spider_dead
};

/*
=============
spider_idle
=============
*/
static void spider_idle(edict_t *self)
{
	gi.sound(self, CHAN_VOICE, sound_idle, 1.0f, ATTN_IDLE, 0.0f);
}

/*
=============
spider_search
=============
*/
static void spider_search(edict_t *self)
{
	gi.sound(self, CHAN_VOICE, sound_search, 1.0f, ATTN_NORM, 0.0f);
}

/*
=============
spider_sight
=============
*/
static void spider_sight(edict_t *self, edict_t *other)
{
	(void)other;

	gi.sound(self, CHAN_VOICE, sound_sight, 1.0f, ATTN_NORM, 0.0f);
}

/*
==================
spider_melee_swing
==================
*/
static void spider_melee_swing(edict_t *self)
{
	gi.sound(self, CHAN_WEAPON, sound_melee1, 1.0f, ATTN_NORM, 0.0f);
}

/*
=============
spider_stand
=============
*/
static void spider_stand(edict_t *self)
{
	self->monsterinfo.currentmove = &spider_move_stand;
}

/*
============
spider_walk
============
*/
static void spider_walk(edict_t *self)
{
	self->monsterinfo.currentmove = &spider_move_walk;
}

/*
===================
spider_charge_think
===================
*/
static void spider_charge_think(edict_t *self, edict_t *other, cplane_t *plane,
	csurface_t *surf)
{
	vec3_t	dir;
	vec3_t	point;
	int		damage;

	(void)plane;
	(void)surf;

	if (self->health > 0)
	{
		if (other->takedamage && VectorLength(self->velocity) > SPIDER_CHARGE_IMPACT_SPEED)
		{
			VectorCopy(self->velocity, dir);
			VectorNormalize(dir);
			VectorMA(self->s.origin, self->maxs[0], dir, point);
			damage = (rand() % SPIDER_CHARGE_DAMAGE_RANGE) + SPIDER_CHARGE_DAMAGE_BASE;
			T_Damage(other, self, self, self->velocity, point, dir, damage,
				damage, 0, MOD_UNKNOWN);
		}

		if (!M_CheckBottom(self))
		{
			if (!self->groundentity)
				return;

			self->monsterinfo.nextframe = SPIDER_FRAME_RUN1_START + 3;
		}
	}

	self->touch = NULL;
}

/*
===================
spider_charge_start
===================
*/
static void spider_charge_start(edict_t *self)
{
	vec3_t	forward;

	gi.sound(self, CHAN_VOICE, sound_sight, 1.0f, ATTN_NORM, 0.0f);

	AngleVectors(self->s.angles, forward, NULL, NULL);
	self->s.origin[2] += 1.0f;
	VectorScale(forward, SPIDER_CHARGE_SPEED, self->velocity);
	self->velocity[2] = SPIDER_CHARGE_Z_SPEED;
	self->groundentity = NULL;
	self->monsterinfo.aiflags |= AI_DUCKED;
	self->touch = spider_charge_think;
	self->monsterinfo.attack_finished = level.time + 3.0f;
}

/*
=================
spider_charge_end
=================
*/
static void spider_charge_end(edict_t *self)
{
	if (self->groundentity)
	{
		gi.sound(self, CHAN_WEAPON, sound_step, 1.0f, ATTN_NORM, 0.0f);
		self->monsterinfo.attack_finished = 0.0f;
		self->monsterinfo.aiflags &= ~AI_DUCKED;
	}
}

/*
===========
spider_run
===========
*/
static void spider_run(edict_t *self)
{
	if (self->monsterinfo.aiflags & AI_STAND_GROUND)
	{
		self->monsterinfo.currentmove = &spider_move_stand;
		return;
	}

	if (random() < 0.2f)
	{
		self->monsterinfo.currentmove = &spider_move_run1;
		return;
	}

	self->monsterinfo.currentmove = &spider_move_run2;
}

/*
================
spider_melee_hit
================
*/
static void spider_melee_hit(edict_t *self)
{
	vec3_t	aim;
	int		damage;

	VectorSet(aim, MELEE_DISTANCE, self->mins[0], -4.0f);
	damage = (rand() % 5) + 20;

	if (fire_hit(self, aim, damage, SPIDER_MELEE_KICK))
	{
		gi.sound(self, CHAN_WEAPON, sound_melee2, 1.0f, ATTN_NORM, 0.0f);
		return;
	}

	gi.sound(self, CHAN_WEAPON, sound_melee3, 1.0f, ATTN_NORM, 0.0f);
}

/*
=============
spider_melee
=============
*/
static void spider_melee(edict_t *self)
{
	gi.bprintf(PRINT_MEDIUM, "spider_melee\n");

	if (random() < 0.5f)
	{
		self->monsterinfo.currentmove = &spider_move_melee_primary;
		return;
	}

	self->monsterinfo.currentmove = &spider_move_melee_secondary;
}

/*
==================
spider_rocket_left
==================
*/
static void spider_rocket_left(edict_t *self)
{
	vec3_t	forward;
	vec3_t	right;
	vec3_t	start;
	vec3_t	dir;

	AngleVectors(self->s.angles, forward, right, NULL);
	G_ProjectSource(self->s.origin, tv(30.0f, -18.0f, 3.0f), forward, right,
		start);

	VectorSubtract(self->pos1, start, dir);
	VectorNormalize(dir);

	monster_fire_rocket(self, start, dir, SPIDER_ROCKET_DAMAGE,
		SPIDER_ROCKET_SPEED, SPIDER_MZ_LEFT);
}

/*
===================
spider_rocket_right
===================
*/
static void spider_rocket_right(edict_t *self)
{
	vec3_t	forward;
	vec3_t	right;
	vec3_t	start;
	vec3_t	dir;

	AngleVectors(self->s.angles, forward, right, NULL);
	G_ProjectSource(self->s.origin, tv(30.0f, 18.0f, 3.0f), forward, right,
		start);

	VectorSubtract(self->pos1, start, dir);
	VectorNormalize(dir);

	monster_fire_rocket(self, start, dir, SPIDER_ROCKET_DAMAGE,
		SPIDER_ROCKET_SPEED, SPIDER_MZ_RIGHT);
}

/*
==============
spider_attack
==============
*/
static void spider_attack(edict_t *self)
{
	vec3_t	delta;
	float	r;

	r = random();

	VectorSubtract(self->s.origin, self->enemy->s.origin, delta);
	if (VectorLength(delta) <= SPIDER_ATTACK_MIN_RANGE)
		return;

	VectorCopy(self->enemy->s.origin, self->pos1);
	self->pos1[2] += self->enemy->viewheight;

	if (r < 0.33f)
	{
		self->monsterinfo.currentmove = &spider_move_attack_left;
		return;
	}

	if (r < 0.66f)
	{
		self->monsterinfo.currentmove = &spider_move_attack_right;
		return;
	}

	self->monsterinfo.currentmove = &spider_move_attack_dual;
}

/*
============
spider_pain
============
*/
static void spider_pain(edict_t *self, edict_t *other, float kick, int damage)
{
	int sound_id;

	(void)other;
	(void)kick;

	if (self->health < (self->max_health / 2))
		self->s.skinnum = 1;

	self->pain_debounce_time = level.time + 3.0f;

	sound_id = sound_pain1;
	if (random() >= 0.5f)
		sound_id = sound_pain2;

	if (skill->value == 3 && random() < 0.1f)
	{
		gi.sound(self, CHAN_VOICE, sound_id, 1.0f, ATTN_NORM, 0.0f);
		self->monsterinfo.currentmove = &spider_move_pain1;
		return;
	}

	if (damage < 10 && random() < 0.2f)
	{
		gi.sound(self, CHAN_VOICE, sound_id, 1.0f, ATTN_NORM, 0.0f);
		self->monsterinfo.currentmove = &spider_move_pain1;
		return;
	}

	if (damage < 50 && random() < 0.5f)
	{
		gi.sound(self, CHAN_VOICE, sound_id, 1.0f, ATTN_NORM, 0.0f);
		if (random() < 0.5f)
		{
			self->monsterinfo.currentmove = &spider_move_pain1;
			return;
		}
	}
	else
	{
		gi.sound(self, CHAN_VOICE, sound_id, 1.0f, ATTN_NORM, 0.0f);
	}

	self->monsterinfo.currentmove = &spider_move_pain2;
}

/*
============
spider_dead
============
*/
static void spider_dead(edict_t *self)
{
	VectorSet(self->mins, -32.0f, -32.0f, -30.0f);
	VectorSet(self->maxs, 32.0f, 32.0f, 0.0f);
	self->movetype = MOVETYPE_TOSS;
	self->svflags |= SVF_DEADMONSTER;
	self->nextthink = 0.0f;
	gi.linkentity(self);
}

/*
===========
spider_die
===========
*/
static void spider_die(edict_t *self, edict_t *inflictor, edict_t *attacker,
	int damage, vec3_t point)
{
	int		n;

	(void)inflictor;
	(void)attacker;
	(void)point;

	if (meansOfDeath == 0x23)
	{
		BecomeExplosion1(self);
		return;
	}

	if (self->health <= self->gib_health)
	{
		gi.sound(self, CHAN_VOICE, gi.soundindex("misc/udeath.wav"), 1.0f,
			ATTN_NORM, 0.0f);

		for (n = 0; n < 2; n++)
			ThrowGib(self, "models/objects/gibs/sm_meat/tris.md2", damage,
				GIB_ORGANIC);
		for (n = 0; n < 4; n++)
			ThrowGib(self, "models/objects/gibs/sm_metal/tris.md2", damage,
				GIB_METALLIC);

		ThrowGib(self, "models/objects/gibs/chest/tris.md2", damage,
			GIB_ORGANIC);
		ThrowHead(self, "models/objects/gibs/head2/tris.md2", damage,
			GIB_ORGANIC);

		self->deadflag = DEAD_DEAD;
		return;
	}

	if (self->deadflag == DEAD_DEAD)
		return;

	self->deadflag = DEAD_DEAD;
	self->takedamage = DAMAGE_YES;

	if (random() < 0.5f)
	{
		self->monsterinfo.currentmove = &spider_move_death1;
		return;
	}

	self->monsterinfo.currentmove = &spider_move_death2;
}

/*
==================
spider_checkattack
==================
*/
static qboolean spider_checkattack(edict_t *self)
{
	vec3_t	spot1;
	vec3_t	spot2;
	vec3_t	temp;
	float	chance;
	int		enemy_range;
	trace_t	tr;

	if (self->enemy->health > 0)
	{
		VectorCopy(self->s.origin, spot1);
		spot1[2] += self->viewheight;
		VectorCopy(self->enemy->s.origin, spot2);
		spot2[2] += self->enemy->viewheight;

		tr = gi.trace(spot1, NULL, NULL, spot2, self,
			CONTENTS_SOLID | CONTENTS_MONSTER | CONTENTS_SLIME |
			CONTENTS_LAVA | CONTENTS_WINDOW);
		if (tr.ent != self->enemy)
			return false;
	}

	(void)infront(self, self->enemy);

	enemy_range = range(self, self->enemy);
	VectorSubtract(self->enemy->s.origin, self->s.origin, temp);
	self->ideal_yaw = vectoyaw(temp);

	if (enemy_range == RANGE_MELEE)
	{
		if (self->monsterinfo.melee)
			self->monsterinfo.attack_state = AS_MELEE;
		else
			self->monsterinfo.attack_state = AS_MISSILE;
		return true;
	}

	if (!self->monsterinfo.attack)
		return false;

	if (level.time < self->monsterinfo.attack_finished)
		return false;

	if (enemy_range == RANGE_FAR)
		return false;

	if (self->monsterinfo.aiflags & AI_STAND_GROUND)
	{
		chance = 0.4f;
	}
	else
	{
		if (enemy_range != RANGE_NEAR && enemy_range != RANGE_MID)
			return false;

		chance = 0.8f;
	}

	if (random() < chance)
	{
		self->monsterinfo.attack_state = AS_MISSILE;
		self->monsterinfo.attack_finished = level.time + 2.0f * random();
		return true;
	}

	if (self->flags & FL_FLY)
	{
		if (random() < 0.3f)
			self->monsterinfo.attack_state = AS_SLIDING;
		else
			self->monsterinfo.attack_state = AS_STRAIGHT;
	}

	return false;
}

/*QUAKED monster_spider (1 .5 0) (-32 -32 -35) (32 32 32) Ambush Trigger_Spawn
 * Sight Corpse
 */
/*
=================
SP_monster_spider
=================
*/
void SP_monster_spider(edict_t *self)
{
	if (deathmatch->value)
	{
		G_FreeEdict(self);
		return;
	}

	sound_melee1 = gi.soundindex("gladiator/melee1.wav");
	sound_melee2 = gi.soundindex("gladiator/melee2.wav");
	sound_melee3 = gi.soundindex("gladiator/melee3.wav");
	sound_step = gi.soundindex("mutant/thud1.wav");
	sound_sight = gi.soundindex("mutant/mutsght1.wav");
	sound_pain1 = gi.soundindex("gladiator/pain.wav");
	sound_pain2 = gi.soundindex("gladiator/gldpain2.wav");
	sound_idle = gi.soundindex("gladiator/gldidle1.wav");
	sound_search = gi.soundindex("gladiator/gldsrch1.wav");
	sound_sight = gi.soundindex("spider/sight.wav");

	self->movetype = MOVETYPE_STEP;
	self->solid = SOLID_BBOX;
	self->s.modelindex = gi.modelindex("models/monsters/spider/tris.md2");
	VectorSet(self->mins, -32.0f, -32.0f, -35.0f);
	VectorSet(self->maxs, 32.0f, 32.0f, 32.0f);

	self->health = 400;
	self->gib_health = -175;
	self->mass = 300;

	if (self->spawnflags & SPAWNFLAG_CORPSE)
	{
		self->s.skinnum |= 1;
		self->health = -1;
		self->svflags |= SVF_DEADMONSTER;
		self->movetype = MOVETYPE_TOSS;
		VectorSet(self->mins, -32.0f, -32.0f, -30.0f);
		VectorSet(self->maxs, 32.0f, 32.0f, 0.0f);
		self->nextthink = 0.0f;
		gi.linkentity(self);
		return;
	}

	self->pain = spider_pain;
	self->die = spider_die;

	self->monsterinfo.stand = spider_stand;
	self->monsterinfo.idle = spider_idle;
	self->monsterinfo.search = spider_search;
	self->monsterinfo.walk = spider_walk;
	self->monsterinfo.run = spider_run;
	self->monsterinfo.dodge = NULL;
	self->monsterinfo.attack = spider_attack;
	self->monsterinfo.melee = spider_melee;
	self->monsterinfo.sight = spider_sight;

	gi.linkentity(self);

	self->monsterinfo.currentmove = &spider_move_stand;
	self->monsterinfo.scale = MODEL_SCALE;
	self->monsterinfo.checkattack = spider_checkattack;

	walkmonster_start(self);
}
