#include "g_local.h"
#include "m_badass.h"

#include <stddef.h>

#define MODEL_SCALE 1.0f
#define BADASS_SPAWNFLAG_DEAD 8
#define BADASS_ACTIVATE_RETAIL_FRAME_COUNT 6

typedef struct
{
	const char *model;
	vec3_t mins;
	vec3_t maxs;
} badass_gib_def_t;

typedef struct
{
	mframe_t frames[BADASS_ACTIVATE_RETAIL_FRAME_COUNT];
	mmove_t move;
} badass_activate_retail_blob_t;

static const badass_gib_def_t badass_gib_defs[] = {
	{
		"models/monsters/badass/gib_torso.md2",
		{-17.0f, -15.0f, -50.0f},
		{ 41.0f,  22.0f, -29.0f}
	},
	{
		"models/monsters/badass/gib_lleg.md2",
		{-35.0f,   1.0f, -46.0f},
		{ 47.0f,  53.0f, -22.0f}
	},
	{
		"models/monsters/badass/gib_rleg.md2",
		{-34.0f, -51.0f, -44.0f},
		{ 48.0f,  -1.0f, -21.0f}
	},
	{
		"models/monsters/badass/gib_larm.md2",
		{-29.0f, -12.0f, -33.0f},
		{ 31.0f,  53.0f, -12.0f}
	},
	{
		"models/monsters/badass/gib_rarm.md2",
		{-34.0f, -51.0f, -42.0f},
		{ 26.0f, -30.0f, -21.0f}
	}
};

static int sound_pain;
static int sound_death;
static int sound_step;
static int sound_sight;
/*
 * Retail spawn still caches these slots even though the committed corpus does
 * not yet expose a direct standalone consumer for them.
 */
static int sound_idle_preload;
static int sound_attack_primary_preload;
static int sound_attack_secondary_preload;

static vec3_t badass_rocket_offsets[2] = {
	{18.0f,  40.0f, 0.0f},
	{18.0f, -40.0f, 0.0f}
};

static mmove_t badass_move_idle_closed;
static mmove_t badass_move_activate;
static mmove_t badass_move_deactivate;
static mmove_t badass_move_stand;
static mmove_t badass_move_walk;
static mmove_t badass_move_run;
static mmove_t badass_move_attack;
static mmove_t badass_move_pain;
static mmove_t badass_move_death;

static void badass_sight(edict_t *self, edict_t *other);
static void badass_stand(edict_t *self);
static void badass_idle(edict_t *self);
static void badass_walk(edict_t *self);
static void badass_run(edict_t *self);
static void badass_attack(edict_t *self);
static void badass_attack_loop(edict_t *self);
static void badass_rocket_right(edict_t *self);
static void badass_rocket_left(edict_t *self);
static void badass_gib_explosion(edict_t *self);
static void badass_die_gibs(edict_t *self);
static void badass_dead(edict_t *self);
static void badass_die(edict_t *self, edict_t *inflictor, edict_t *attacker, int damage,
	vec3_t point);
static void badass_step(edict_t *self);
static void badass_thud(edict_t *self);
static void badass_pain(edict_t *self, edict_t *other, float kick, int damage);
static void badass_gib_think(edict_t *self);

static mframe_t badass_frames_idle_closed[] = {
	{ai_stand, 0.0f, NULL}
};
static mmove_t badass_move_idle_closed = {
	FRAME_ACTIVATE1,
	FRAME_ACTIVATE1,
	badass_frames_idle_closed,
	NULL
};

/*
 * Retail stores the activation band as six contiguous `mframe_t` records
 * immediately followed by the `mmove_t` root, so the declared `0..6` range
 * overlaps the move header at the would-be seventh slot. Mirror that raw blob
 * in source, then keep a separate runtime-safe projection below rather than
 * letting `M_MoveFrame` walk into the overlapped header bytes as a callback.
 */
static badass_activate_retail_blob_t badass_activate_retail_blob = {
	{
		{ai_move, 0.0f, NULL},
		{ai_move, 0.0f, NULL},
		{ai_move, 0.0f, NULL},
		{ai_move, 0.0f, NULL},
		{ai_move, 0.0f, NULL},
		{ai_move, 0.0f, NULL}
	},
	{
		FRAME_ACTIVATE1,
		FRAME_ACTIVATE7,
		NULL,
		badass_run
	}
};

static mframe_t badass_frames_activate[] = {
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}
};
static mmove_t badass_move_activate = {
	FRAME_ACTIVATE1,
	FRAME_ACTIVATE7,
	badass_frames_activate,
	badass_run
};

static mframe_t badass_frames_deactivate[] = {
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}
};
static mmove_t badass_move_deactivate = {
	FRAME_DEACTIVATE1,
	FRAME_DEACTIVATE15,
	badass_frames_deactivate,
	badass_idle
};

static mframe_t badass_frames_stand[] = {
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}
};
static mmove_t badass_move_stand = {
	FRAME_STAND1,
	FRAME_STAND20,
	badass_frames_stand,
	NULL
};

static mframe_t badass_frames_walk[] = {
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, badass_step},
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, NULL},
	{ai_walk, 7.0f, badass_step}
};
static mmove_t badass_move_walk = {
	FRAME_WALK1,
	FRAME_WALK14,
	badass_frames_walk,
	NULL
};

static mframe_t badass_frames_run[] = {
	{ai_run, 14.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 21.0f, NULL},
	{ai_run, 24.0f, badass_step},
	{ai_run, 14.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 21.0f, NULL},
	{ai_run, 24.0f, badass_step}
};
static mmove_t badass_move_run = {
	FRAME_RUN1,
	FRAME_RUN8,
	badass_frames_run,
	NULL
};

static mframe_t badass_frames_attack[] = {
	{ai_charge, -5.0f, badass_rocket_right},
	{ai_charge, 0.0f, NULL},
	{ai_charge, -5.0f, badass_rocket_left},
	{ai_charge, 0.0f, NULL}
};
static mmove_t badass_move_attack = {
	FRAME_ATTACK1,
	FRAME_ATTACK4,
	badass_frames_attack,
	badass_attack_loop
};

static mframe_t badass_frames_pain[] = {
	{ai_move, 8.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, -16.0f, NULL},
	{ai_move, -16.0f, NULL},
	{ai_move, -8.0f, NULL},
	{ai_move, 0.0f, NULL}
};
static mmove_t badass_move_pain = {
	FRAME_PAIN1,
	FRAME_PAIN10,
	badass_frames_pain,
	badass_run
};

static mframe_t badass_frames_death[] = {
	{ai_move, -8.0f, badass_gib_explosion},
	{ai_move, -8.0f, NULL},
	{ai_move, -8.0f, NULL},
	{ai_move, -7.0f, NULL},
	{ai_move, -4.0f, badass_thud},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, badass_gib_explosion},
	{ai_move, 4.0f, NULL},
	{ai_move, 2.0f, NULL},
	{ai_move, 2.0f, NULL},
	{ai_move, 2.0f, NULL},
	{ai_move, 2.0f, NULL},
	{ai_move, 2.0f, NULL},
	{ai_move, 2.0f, badass_thud},
	{ai_move, 0.0f, badass_gib_explosion},
	{ai_move, 0.0f, badass_thud},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, badass_thud}
};
static mmove_t badass_move_death = {
	FRAME_DEATH1,
	FRAME_DEATH20,
	badass_frames_death,
	badass_dead
};

/*
=============
badass_sight
=============
*/
static void badass_sight(edict_t *self, edict_t *other)
{
	(void)other;

	if (self->monsterinfo.currentmove == &badass_move_idle_closed)
	{
		self->monsterinfo.currentmove = &badass_move_activate;
	}
	else
	{
		badass_run(self);
	}

	gi.sound(self, CHAN_VOICE, sound_sight, 1.0f, ATTN_NORM, 0);
}

/*
=============
badass_stand
=============
*/
static void badass_stand(edict_t *self)
{
	if (self->monsterinfo.currentmove != &badass_move_idle_closed)
	{
		self->monsterinfo.currentmove = &badass_move_stand;
	}
}

/*
=============
badass_idle
=============
*/
static void badass_idle(edict_t *self)
{
	if (self->monsterinfo.currentmove == &badass_move_stand)
	{
		self->monsterinfo.currentmove = &badass_move_deactivate;
		return;
	}

	self->monsterinfo.currentmove = &badass_move_idle_closed;
}

/*
=============
badass_walk
=============
*/
static void badass_walk(edict_t *self)
{
	self->monsterinfo.currentmove = &badass_move_walk;
}

/*
=============
badass_run
=============
*/
static void badass_run(edict_t *self)
{
	self->monsterinfo.currentmove = &badass_move_run;
}

/*
=============
badass_attack
=============
*/
static void badass_attack(edict_t *self)
{
	vec3_t delta;

	if (!self->enemy)
	{
		return;
	}

	VectorSubtract(self->s.origin, self->enemy->s.origin, delta);
	if ((VectorLength(delta) > 200.0f) && (random() < 0.5f))
	{
		return;
	}

	self->monsterinfo.currentmove = &badass_move_attack;
}

/*
===================
badass_attack_loop
===================
*/
static void badass_attack_loop(edict_t *self)
{
	vec3_t delta;

	if (self->enemy && visible(self, self->enemy) && (self->enemy->health > 0))
	{
		VectorSubtract(self->s.origin, self->enemy->s.origin, delta);
		if (VectorLength(delta) < 200.0f)
		{
			return;
		}

		if (random() <= 0.45f)
		{
			return;
		}
	}

	self->monsterinfo.currentmove = &badass_move_run;
}

/*
===================
badass_rocket_right
===================
*/
static void badass_rocket_right(edict_t *self)
{
	vec3_t forward;
	vec3_t right;
	vec3_t start;
	vec3_t dir;
	vec3_t target;

	if (!self->enemy)
	{
		return;
	}

	AngleVectors(self->s.angles, forward, right, NULL);
	G_ProjectSource(self->s.origin, badass_rocket_offsets[0], forward, right, start);

	VectorCopy(self->enemy->s.origin, target);
	target[2] += self->enemy->viewheight;
	VectorSubtract(target, start, dir);
	VectorNormalize(dir);

	fire_oblivion_rocket(self, start, dir, 50, 550, 70.0f, 50, MOD_ROCKET, MOD_R_SPLASH);
}

/*
==================
badass_rocket_left
==================
*/
static void badass_rocket_left(edict_t *self)
{
	vec3_t forward;
	vec3_t right;
	vec3_t start;
	vec3_t dir;
	vec3_t target;

	if (!self->enemy)
	{
		return;
	}

	AngleVectors(self->s.angles, forward, right, NULL);
	G_ProjectSource(self->s.origin, badass_rocket_offsets[1], forward, right, start);

	VectorCopy(self->enemy->s.origin, target);
	target[2] += self->enemy->viewheight;
	VectorSubtract(target, start, dir);
	VectorNormalize(dir);

	fire_oblivion_rocket(self, start, dir, 50, 550, 70.0f, 50, MOD_ROCKET, MOD_R_SPLASH);
}

/*
=================
badass_gib_think
=================
*/
static void badass_gib_think(edict_t *self)
{
	self->nextthink = level.time + 0.1f;
	if (self->count == 4)
	{
		self->nextthink = 0;
		return;
	}

	self->count++;
}

/*
======================
badass_gib_explosion
======================
*/
static void badass_gib_explosion(edict_t *self)
{
	gi.WriteByte(svc_temp_entity);
	gi.WriteByte(TE_EXPLOSION1);
	gi.WritePosition(self->s.origin);
	gi.multicast(self->s.origin, MULTICAST_PVS);

	T_RadiusDamage(self, self, 100.0f, NULL, 100.0f, MOD_EXPLOSIVE);

	if (self->think == badass_gib_explosion)
	{
		self->think = badass_die_gibs;
		self->nextthink = level.time + 0.5f;
	}
}

/*
=================
badass_die_gibs
=================
*/
static void badass_die_gibs(edict_t *self)
{
	vec3_t forward;
	vec3_t right;
	vec3_t up;
	size_t i;

	AngleVectors(self->s.angles, forward, right, up);

	for (i = 0; i < sizeof(badass_gib_defs) / sizeof(badass_gib_defs[0]); ++i)
	{
		edict_t *gib = G_Spawn();

		VectorCopy(self->s.origin, gib->s.origin);
		VectorCopy(self->s.origin, gib->s.old_origin);
		VectorCopy(self->s.angles, gib->s.angles);
		VectorCopy(self->s.angles, gib->avelocity);
		VectorScale(gib->avelocity, 200.0f, gib->avelocity);
		gib->mass = 0;
		gib->avelocity[ROLL] = 0.0f;
		gib->avelocity[YAW] = 0.0f;
		gib->owner = self;
		gib->movetype = MOVETYPE_BOUNCE;
		gib->solid = SOLID_BBOX;
		gib->deadflag = DEAD_DEAD;
		gib->svflags |= SVF_DEADMONSTER;
		gib->think = badass_gib_think;
		gib->nextthink = level.time + 0.1f;
		gib->avelocity[YAW] = ((random() - 0.5f) * 2.0f) * 200.0f;

		gib->s.modelindex = gi.modelindex((char *)badass_gib_defs[i].model);
		VectorCopy(badass_gib_defs[i].mins, gib->mins);
		VectorCopy(badass_gib_defs[i].maxs, gib->maxs);

		switch (i)
		{
		case 0:
			VectorScale(forward, random() * -100.0f, gib->velocity);
			VectorMA(gib->velocity, 300.0f, up, gib->velocity);
			break;

		case 1:
			VectorMA(gib->velocity, 200.0f, up, gib->velocity);
			VectorMA(gib->velocity, -200.0f, right, gib->velocity);
			break;

		case 2:
			VectorMA(gib->velocity, 200.0f, up, gib->velocity);
			VectorMA(gib->velocity, 200.0f, right, gib->velocity);
			break;

		case 3:
			VectorScale(forward, -200.0f, gib->velocity);
			VectorMA(gib->velocity, random() * 275.0f + 50.0f, up, gib->velocity);
			VectorMA(gib->velocity, -100.0f, right, gib->velocity);
			break;

		case 4:
			VectorScale(forward, -200.0f, gib->velocity);
			VectorMA(gib->velocity, random() * 300.0f, up, gib->velocity);
			VectorMA(gib->velocity, 50.0f, right, gib->velocity);
			break;
		}

		gi.linkentity(gib);
	}

	VectorAdd(self->s.origin, right, self->s.origin);
	badass_gib_explosion(self);
	VectorMA(self->s.origin, -2.0f, right, self->s.origin);
	badass_gib_explosion(self);
	G_FreeEdict(self);
}

/*
=============
badass_dead
=============
*/
static void badass_dead(edict_t *self)
{
	self->deadflag = DEAD_DEAD;
	VectorSet(self->mins, -44.0f, -62.0f, -64.0f);
	VectorSet(self->maxs, 44.0f, 62.0f, -5.0f);
	self->svflags |= SVF_DEADMONSTER;
	self->think = badass_gib_explosion;
	self->count = 0x7a69;
	self->nextthink = level.time + 0.5f;
	gi.linkentity(self);
}

/*
============
badass_die
============
*/
static void badass_die(edict_t *self, edict_t *inflictor, edict_t *attacker, int damage,
	vec3_t point)
{
	(void)inflictor;
	(void)attacker;
	(void)damage;
	(void)point;

	if (self->deadflag != DEAD_DEAD)
	{
		self->deadflag = DEAD_DEAD;
		self->takedamage = DAMAGE_YES;
		self->monsterinfo.currentmove = &badass_move_death;
	}
}

/*
=============
badass_step
=============
*/
static void badass_step(edict_t *self)
{
	gi.sound(self, CHAN_BODY, sound_step, 1.0f, ATTN_NORM, 0);
}

/*
=============
badass_thud
=============
*/
static void badass_thud(edict_t *self)
{
	gi.sound(self, CHAN_BODY, sound_death, 1.0f, ATTN_NORM, 0);
}

/*
=============
badass_pain
=============
*/
static void badass_pain(edict_t *self, edict_t *other, float kick, int damage)
{
	(void)other;
	(void)kick;

	if (self->health < (self->max_health / 2))
	{
		self->s.skinnum |= 1;
	}

	if ((damage > 20) && (self->pain_debounce_time <= level.time))
	{
		if ((damage < 51) && (random() > 0.2f))
		{
			return;
		}

		self->monsterinfo.currentmove = &badass_move_pain;
		self->pain_debounce_time = level.time + 3.0f;
		gi.sound(self, CHAN_VOICE, sound_pain, 1.0f, ATTN_NORM, 0);
	}
}

/*
=================
SP_monster_badass
=================
*/
void SP_monster_badass(edict_t *self)
{
	if (deathmatch->value)
	{
		G_FreeEdict(self);
		return;
	}

	badass_activate_retail_blob.move.frame = badass_activate_retail_blob.frames;

	self->s.modelindex = gi.modelindex("models/monsters/badass/tris.md2");
	gi.modelindex("models/monsters/badass/gib_larm.md2");
	gi.modelindex("models/monsters/badass/gib_rarm.md2");
	gi.modelindex("models/monsters/badass/gib_lleg.md2");
	gi.modelindex("models/monsters/badass/gib_rleg.md2");
	gi.modelindex("models/monsters/badass/gib_torso.md2");

	VectorSet(self->mins, -52.0f, -40.0f, -64.0f);
	VectorSet(self->maxs, 38.0f, 40.0f, 32.0f);
	self->movetype = MOVETYPE_STEP;
	self->solid = SOLID_BBOX;
	self->yaw_speed = 25.0f;
	self->health = 1500;
	self->gib_health = 0;
	self->mass = 1000;

	if (self->spawnflags & BADASS_SPAWNFLAG_DEAD)
	{
		self->s.skinnum |= 1;
		self->health = -1;
		self->deadflag = DEAD_DEAD;
		VectorSet(self->mins, -31.0f, -88.0f, -64.0f);
		VectorSet(self->maxs, 38.0f, 21.0f, -13.0f);
		self->svflags |= SVF_DEADMONSTER;
		self->nextthink = 0;
		gi.linkentity(self);
		return;
	}

	sound_pain = gi.soundindex("tank/tnkpain2.wav");
	sound_death = gi.soundindex("tank/tnkdeth2.wav");
	sound_idle_preload = gi.soundindex("tank/tnkidle1.wav");
	gi.soundindex("tank/death.wav");
	sound_step = gi.soundindex("tank/step.wav");
	sound_attack_primary_preload = gi.soundindex("tank/tnkatck4.wav");
	sound_attack_secondary_preload = gi.soundindex("tank/tnkatck5.wav");
	sound_sight = gi.soundindex("tank/sight1.wav");
	gi.soundindex("tank/tnkatck1.wav");
	gi.soundindex("tank/tnkatk2a.wav");
	gi.soundindex("tank/tnkatk2b.wav");
	gi.soundindex("tank/tnkatk2c.wav");
	gi.soundindex("tank/tnkatk2d.wav");
	gi.soundindex("tank/tnkatk2e.wav");
	gi.soundindex("tank/tnkatck3.wav");

	self->pain = badass_pain;
	self->die = badass_die;

	self->monsterinfo.stand = badass_stand;
	self->monsterinfo.idle = badass_idle;
	self->monsterinfo.walk = badass_walk;
	self->monsterinfo.run = badass_run;
	self->monsterinfo.dodge = NULL;
	self->monsterinfo.attack = badass_attack;
	self->monsterinfo.melee = badass_attack;
	self->monsterinfo.sight = badass_sight;

	gi.linkentity(self);
	self->monsterinfo.scale = MODEL_SCALE;
	walkmonster_start(self);
	self->monsterinfo.currentmove = &badass_move_idle_closed;
}
