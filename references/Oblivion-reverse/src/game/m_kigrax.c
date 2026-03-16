/*
 * Kigrax hovering plasma sentry.
 * Reconstructed from retail Oblivion Ghidra mapping and decompilation.
 */

#include "g_local.h"

enum
{
	KIGRAX_FRAME_STAND_FIRST = 0,
	KIGRAX_FRAME_STAND_LAST = 27,
	KIGRAX_FRAME_SCAN_FIRST = 28,
	KIGRAX_FRAME_SCAN_LAST = 48,
	KIGRAX_FRAME_WALK1_FIRST = 61,
	KIGRAX_FRAME_WALK1_LAST = 82,
	KIGRAX_FRAME_WALK2_FIRST = 83,
	KIGRAX_FRAME_WALK2_LAST = 104,
	KIGRAX_FRAME_SIGHT_FIRST = 105,
	KIGRAX_FRAME_SIGHT_LAST = 121,
	KIGRAX_FRAME_RUN_FIRST = 122,
	KIGRAX_FRAME_RUN_LAST = 138,
	KIGRAX_FRAME_PAIN_FIRST = 139,
	KIGRAX_FRAME_PAIN_LAST = 149,
	KIGRAX_FRAME_DEATH_FIRST = 150,
	KIGRAX_FRAME_DEATH_LAST = 168,
	KIGRAX_FRAME_MELEE1_FIRST = 169,
	KIGRAX_FRAME_MELEE1_LAST = 183,
	KIGRAX_FRAME_MELEE2_FIRST = 184,
	KIGRAX_FRAME_MELEE2_LAST = 194,
	KIGRAX_FRAME_ATTACK_FIRST = 195,
	KIGRAX_FRAME_ATTACK_LAST = 204
};

#define KIGRAX_STAND_SELECT_CHANCE	0.333333f
#define KIGRAX_SEARCH_SOUND_CHANCE	0.5f
#define KIGRAX_MELEE_SKIP_CHANCE	0.1f
#define KIGRAX_MELEE_PRIMARY_CHANCE	0.9f
#define KIGRAX_PAIN_COOLDOWN	3.0f

#define KIGRAX_YAW_SPEED	20
#define KIGRAX_MELEE_KICK	100
#define KIGRAX_PLASMA_DAMAGE	10
#define KIGRAX_PLASMA_SPEED	1000
#define KIGRAX_PLASMA_FLASH	1
#define KIGRAX_PLASMA_TYPE	1

static vec3_t kigrax_plasma_offset = {16.0f, 0.0f, -16.0f};

static void kigrax_stand(edict_t *self);
static void kigrax_walk(edict_t *self);
static void kigrax_run(edict_t *self);
static void kigrax_attack(edict_t *self);
static void kigrax_melee(edict_t *self);
static void kigrax_search(edict_t *self);
static void kigrax_sight(edict_t *self, edict_t *other);
static void kigrax_pain(edict_t *self, edict_t *other, float kick, int damage);
static void kigrax_die(edict_t *self, edict_t *inflictor, edict_t *attacker,
	int damage, vec3_t point);
static void kigrax_dead(edict_t *self);
static void kigrax_strike1(edict_t *self);
static void kigrax_strike2(edict_t *self);
static void kigrax_fire_plasma(edict_t *self);

static mframe_t kigrax_frames_stand[] = {
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
static mmove_t kigrax_move_stand = {KIGRAX_FRAME_STAND_FIRST,
	KIGRAX_FRAME_STAND_LAST, kigrax_frames_stand, NULL};

static mframe_t kigrax_frames_scan[] = {
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
	{ai_stand, 0.0f, NULL},
	{ai_stand, 0.0f, NULL}
};
static mmove_t kigrax_move_scan = {KIGRAX_FRAME_SCAN_FIRST,
	KIGRAX_FRAME_SCAN_LAST, kigrax_frames_scan, NULL};

static mframe_t kigrax_frames_walk1[] = {
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL}
};
static mmove_t kigrax_move_walk1 = {KIGRAX_FRAME_WALK1_FIRST,
	KIGRAX_FRAME_WALK1_LAST, kigrax_frames_walk1, NULL};

static mframe_t kigrax_frames_walk2[] = {
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL},
	{ai_walk, 4.0f, NULL}
};
static mmove_t kigrax_move_walk2 = {KIGRAX_FRAME_WALK2_FIRST,
	KIGRAX_FRAME_WALK2_LAST, kigrax_frames_walk2, NULL};

static mframe_t kigrax_frames_sight[] = {
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL},
	{ai_run, 10.0f, NULL}
};
static mmove_t kigrax_move_sight = {KIGRAX_FRAME_SIGHT_FIRST,
	KIGRAX_FRAME_SIGHT_LAST, kigrax_frames_sight, NULL};

static mframe_t kigrax_frames_run[] = {
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL},
	{ai_run, 15.0f, NULL}
};
static mmove_t kigrax_move_run = {KIGRAX_FRAME_RUN_FIRST,
	KIGRAX_FRAME_RUN_LAST, kigrax_frames_run, NULL};

static mframe_t kigrax_frames_pain[] = {
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
static mmove_t kigrax_move_pain = {KIGRAX_FRAME_PAIN_FIRST,
	KIGRAX_FRAME_PAIN_LAST, kigrax_frames_pain, kigrax_run};

static mframe_t kigrax_frames_death[] = {
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
	{ai_move, 0.0f, kigrax_dead},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL},
	{ai_move, 0.0f, NULL}
};
static mmove_t kigrax_move_death = {KIGRAX_FRAME_DEATH_FIRST,
	KIGRAX_FRAME_DEATH_LAST, kigrax_frames_death, kigrax_dead};

static mframe_t kigrax_frames_melee1[] = {
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, kigrax_strike1},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, kigrax_strike1},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL}
};
static mmove_t kigrax_move_melee1 = {KIGRAX_FRAME_MELEE1_FIRST,
	KIGRAX_FRAME_MELEE1_LAST, kigrax_frames_melee1, kigrax_melee};

static mframe_t kigrax_frames_melee2[] = {
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, kigrax_strike2},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL},
	{ai_charge, 1.0f, NULL}
};
static mmove_t kigrax_move_melee2 = {KIGRAX_FRAME_MELEE2_FIRST,
	KIGRAX_FRAME_MELEE2_LAST, kigrax_frames_melee2, kigrax_melee};

static mframe_t kigrax_frames_attack[] = {
	{ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, kigrax_fire_plasma},
	{ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL},
	{ai_charge, 0.0f, NULL}
};
static mmove_t kigrax_move_attack = {KIGRAX_FRAME_ATTACK_FIRST,
	KIGRAX_FRAME_ATTACK_LAST, kigrax_frames_attack, kigrax_run};

static int sound_pain;
static int sound_death;
static int sound_sight;
static int sound_search1;
static int sound_search2;
static int sound_attack;
static int sound_idle;

/*
=============
kigrax_stand
=============
*/
static void kigrax_stand(edict_t *self)
{
	if (self->monsterinfo.aiflags & AI_STAND_GROUND)
		return;

	if (random() <= KIGRAX_STAND_SELECT_CHANCE)
		self->monsterinfo.currentmove = &kigrax_move_scan;
	else
		self->monsterinfo.currentmove = &kigrax_move_stand;
}

/*
=============
kigrax_walk
=============
*/
static void kigrax_walk(edict_t *self)
{
	gi.dprintf("walking...\n");

	if (random() < KIGRAX_STAND_SELECT_CHANCE)
		self->monsterinfo.currentmove = &kigrax_move_walk2;
	else
		self->monsterinfo.currentmove = &kigrax_move_walk1;
}

/*
=============
kigrax_run
=============
*/
static void kigrax_run(edict_t *self)
{
	gi.dprintf("running...\n");

	if (self->monsterinfo.aiflags & AI_STAND_GROUND)
	{
		self->monsterinfo.currentmove = &kigrax_move_stand;
		return;
	}

	self->monsterinfo.currentmove = &kigrax_move_run;
}

/*
=============
kigrax_search
=============
*/
static void kigrax_search(edict_t *self)
{
	if (random() < KIGRAX_SEARCH_SOUND_CHANCE)
		gi.sound(self, CHAN_VOICE, sound_search1, 1.0f, ATTN_NORM, 0.0f);
	else
		gi.sound(self, CHAN_VOICE, sound_search2, 1.0f, ATTN_NORM, 0.0f);
}

/*
=============
kigrax_sight
=============
*/
static void kigrax_sight(edict_t *self, edict_t *other)
{
	(void)other;

	gi.sound(self, CHAN_VOICE, sound_sight, 1.0f, ATTN_NORM, 0.0f);
	self->monsterinfo.currentmove = &kigrax_move_sight;
}

/*
=============
kigrax_attack
=============
*/
static void kigrax_attack(edict_t *self)
{
	self->monsterinfo.currentmove = &kigrax_move_attack;
}

/*
=============
kigrax_melee
=============
*/
static void kigrax_melee(edict_t *self)
{
	if (self->enemy->health <= 0)
	{
		self->monsterinfo.currentmove = &kigrax_move_run;
		return;
	}

	if (range(self, self->enemy) != RANGE_MELEE)
	{
		self->monsterinfo.currentmove = &kigrax_move_run;
		return;
	}

	if (random() < KIGRAX_MELEE_SKIP_CHANCE)
	{
		self->monsterinfo.currentmove = &kigrax_move_run;
		return;
	}

	if (random() < KIGRAX_MELEE_PRIMARY_CHANCE)
		self->monsterinfo.currentmove = &kigrax_move_melee1;
	else
		self->monsterinfo.currentmove = &kigrax_move_melee2;
}

/*
=============
kigrax_strike1
=============
*/
static void kigrax_strike1(edict_t *self)
{
	vec3_t	aim;

	gi.sound(self, CHAN_WEAPON, sound_attack, 1.0f, ATTN_NORM, 0.0f);
	VectorSet(aim, MELEE_DISTANCE, self->mins[0], 10.0f);
	fire_hit(self, aim, 10 + (rand() % 6), KIGRAX_MELEE_KICK);
}

/*
=============
kigrax_strike2
=============
*/
static void kigrax_strike2(edict_t *self)
{
	vec3_t	aim;

	gi.sound(self, CHAN_WEAPON, sound_attack, 1.0f, ATTN_NORM, 0.0f);
	VectorSet(aim, MELEE_DISTANCE, self->mins[0], 10.0f);
	fire_hit(self, aim, 20 + (rand() % 20), KIGRAX_MELEE_KICK);
}

/*
=============
kigrax_fire_plasma
=============
*/
static void kigrax_fire_plasma(edict_t *self)
{
	vec3_t	forward;
	vec3_t	right;
	vec3_t	start;
	vec3_t	target;
	vec3_t	dir;

	AngleVectors(self->s.angles, forward, right, NULL);
	G_ProjectSource(self->s.origin, kigrax_plasma_offset, forward, right, start);

	VectorCopy(self->enemy->s.origin, target);
	target[2] += self->enemy->viewheight;

	VectorSubtract(target, start, dir);

	fire_plasma_bolt(self, start, dir, KIGRAX_PLASMA_DAMAGE, KIGRAX_PLASMA_SPEED,
		KIGRAX_PLASMA_TYPE);

	gi.WriteByte(svc_muzzleflash2);
	gi.WriteShort(self - g_edicts);
	gi.WriteByte(KIGRAX_PLASMA_FLASH);
	gi.multicast(start, MULTICAST_PVS);
}

/*
=============
kigrax_pain
=============
*/
static void kigrax_pain(edict_t *self, edict_t *other, float kick, int damage)
{
	(void)other;
	(void)kick;
	(void)damage;

	if (level.time < self->pain_debounce_time)
		return;

	self->pain_debounce_time = level.time + KIGRAX_PAIN_COOLDOWN;

	if (skill->value == 3)
		return;

	gi.sound(self, CHAN_VOICE, sound_pain, 1.0f, ATTN_NORM, 0.0f);
	self->monsterinfo.currentmove = &kigrax_move_pain;
}

/*
=============
kigrax_dead
=============
*/
static void kigrax_dead(edict_t *self)
{
	VectorSet(self->mins, -16.0f, -16.0f, -16.0f);
	VectorSet(self->maxs, 16.0f, 16.0f, 0.0f);
	self->movetype = MOVETYPE_TOSS;
	self->svflags |= SVF_DEADMONSTER;
	self->nextthink = 0.0f;
	gi.linkentity(self);
}

/*
=============
kigrax_die
=============
*/
static void kigrax_die(edict_t *self, edict_t *inflictor, edict_t *attacker,
	int damage, vec3_t point)
{
	int	n;

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
		gi.sound(self, CHAN_VOICE, gi.soundindex("misc/udeath.wav"),
			1.0f, ATTN_NORM, 0.0f);
		for (n = 0; n < 2; n++)
			ThrowGib(self, "models/objects/gibs/bone/tris.md2", damage, GIB_ORGANIC);
		for (n = 0; n < 2; n++)
			ThrowGib(self, "models/objects/gibs/sm_meat/tris.md2", damage, GIB_ORGANIC);
		ThrowHead(self, "models/objects/gibs/sm_meat/tris.md2", damage, GIB_ORGANIC);
		self->deadflag = DEAD_DEAD;
		return;
	}

	if (self->deadflag == DEAD_DEAD)
		return;

	self->deadflag = DEAD_DEAD;
	self->takedamage = DAMAGE_YES;
	self->monsterinfo.currentmove = &kigrax_move_death;
}

/*
=============
SP_monster_kigrax
=============
*/
void SP_monster_kigrax(edict_t *self)
{
	if (deathmatch->value)
	{
		G_FreeEdict(self);
		return;
	}

	self->s.modelindex = gi.modelindex("models/monsters/kigrax/tris.md2");

	sound_pain = gi.soundindex("hover/hovpain1.wav");
	sound_death = gi.soundindex("hover/hovdeth1.wav");
	sound_sight = gi.soundindex("hover/hovsght1.wav");
	sound_search1 = gi.soundindex("hover/hovsrch1.wav");
	sound_search2 = gi.soundindex("hover/hovsrch2.wav");
	sound_attack = gi.soundindex("chick/chkatck3.wav");
	gi.soundindex("kigrax/hovatck1.wav");
	sound_idle = gi.soundindex("kigrax/hovidle1.wav");

	self->s.sound = sound_idle;

	VectorSet(self->mins, -20.0f, -20.0f, -32.0f);
	VectorSet(self->maxs, 20.0f, 20.0f, 12.0f);
	self->movetype = MOVETYPE_STEP;
	self->solid = SOLID_BBOX;
	self->health = 200;
	self->gib_health = -100;
	self->mass = 150;
	self->yaw_speed = KIGRAX_YAW_SPEED;
	self->viewheight = 90;

	self->pain = kigrax_pain;
	self->die = kigrax_die;

	self->monsterinfo.stand = kigrax_stand;
	self->monsterinfo.idle = kigrax_stand;
	self->monsterinfo.walk = kigrax_walk;
	self->monsterinfo.run = kigrax_run;
	self->monsterinfo.attack = kigrax_attack;
	self->monsterinfo.melee = kigrax_melee;
	self->monsterinfo.sight = kigrax_sight;
	self->monsterinfo.search = kigrax_search;
	self->monsterinfo.scale = 1.0f;

	gi.linkentity(self);

	self->monsterinfo.currentmove = &kigrax_move_stand;
	flymonster_start(self);
}
