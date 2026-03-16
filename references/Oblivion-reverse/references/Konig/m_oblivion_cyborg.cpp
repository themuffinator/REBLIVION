// Copyright (c) ZeniMax Media Inc.
// Licensed under the GNU General Public License 2.0.
/*
==============================================================================

cyborg

==============================================================================
*/

#include "../g_local.h"
#include "m_oblivion_cyborg.h"
#include "../m_flash.h"

static cached_soundindex sound_pain;
static cached_soundindex sound_death;
static cached_soundindex sound_sight;
static cached_soundindex sound_idle;
static cached_soundindex sound_attack;
static cached_soundindex sound_step;

//
//SOUNDS
//

MONSTERINFO_IDLE(cyborg_idle) (edict_t* self) -> void
{
	gi.sound(self, CHAN_VOICE, sound_sight, 1, ATTN_IDLE, 0);
}

MONSTERINFO_SEARCH(cyborg_search) (edict_t* self) -> void
{
	gi.sound(self, CHAN_VOICE, sound_sight, 1, ATTN_NORM, 0);
}

MONSTERINFO_SIGHT(cyborg_sight) (edict_t* self, edict_t* other) -> void
{
	gi.sound(self, CHAN_VOICE, sound_sight, 1, ATTN_NORM, 0);
}

void cyborg_footstep(edict_t* self)
{
	gi.sound(self, CHAN_BODY, sound_step, 0.5f, ATTN_IDLE, 0.0f);
}

//
//STAND
//

mframe_t cyborg_frames_stand[] =
{
	{ ai_stand }
};
MMOVE_T(cyborg_move_stand) = { FRAME_tpose, FRAME_tpose, cyborg_frames_stand, nullptr };

MONSTERINFO_STAND(cyborg_stand) (edict_t* self) -> void
{
	M_SetAnimation(self, &cyborg_move_stand);
}

//
//WALKRUN
//

mframe_t cyborg_frames_walk[] =
{
	{ ai_walk, 8 },
	{ ai_walk, 6 },
	{ ai_walk, 5 },
	{ ai_walk, 3 },
	{ ai_walk, 1, monster_footstep },

	{ ai_walk, 3 },
	{ ai_walk, 5 },
	{ ai_walk, 6 },
	{ ai_walk, 8 },
	{ ai_walk, 8 },

	{ ai_walk, 5 },
	{ ai_walk, 3 },
	{ ai_walk, 1 },
	{ ai_walk, 1, monster_footstep },
	{ ai_walk, 3 },

	{ ai_walk, 5 },
	{ ai_walk, 6 },
	{ ai_walk, 8 }
};
MMOVE_T(cyborg_move_walk) = { FRAME_walk1, FRAME_walk18, cyborg_frames_walk, nullptr };

MONSTERINFO_WALK(cyborg_walk) (edict_t* self) -> void
{
	M_SetAnimation(self, &cyborg_move_walk);
}

mframe_t cyborg_frames_run[] =
{
	{ ai_run, 16 },
	{ ai_run, 10, monster_footstep },
	{ ai_run, 11 },
	{ ai_run, 16 },
	{ ai_run, 10, monster_footstep },

	{ ai_run, 11 }
};
MMOVE_T(cyborg_move_run) = { FRAME_run1, FRAME_run6, cyborg_frames_run, nullptr };

MONSTERINFO_RUN(cyborg_run) (edict_t* self) -> void
{
	if (self->monsterinfo.aiflags & AI_STAND_GROUND)
	{
		M_SetAnimation(self, &cyborg_move_stand);
		return;
	}

	M_SetAnimation(self, &cyborg_move_run);
}

//
//ATTACK
//

void cyborg_fire(edict_t* self, vec3_t mz)
{
	vec3_t					 start;
	vec3_t					 forward, right;
	vec3_t					 aim;

	if (!self->enemy || !self->enemy->inuse)
		return;

	AngleVectors(self->s.angles, forward, right, nullptr);
	start = M_ProjectFlashSource(self, mz, forward, right);
	PredictAim(self, self->enemy, start, 800, false, frandom() * 0.3f, &aim, nullptr);
	for (int i = 0; i < 3; i++)
		aim[i] += crandom_open() * 0.025f;
	fire_deatom(self, start, aim, 50, 500);
}

void cyborg_fire_left(edict_t* self)
{
	vec3_t offset;

	if (self->s.frame == FRAME_attack106)
	{
		offset = { 8, 23, 13 };
	}
	else if (self->s.frame == FRAME_attack208)
	{
		offset = { 10.5, -12.5, -9 };
	}
	else if (self->s.frame == FRAME_attack402)
	{
		offset = { 11, -16, 10 };
	}
	else
	{
		offset = { 8, -5, 12.5 };
	}

	cyborg_fire(self, offset);
}

void cyborg_fire_right(edict_t* self)
{
	vec3_t offset;

	if (self->s.frame == FRAME_attack112)
	{
		offset = { 23, -8.5, 13 };
	}
	else if (self->s.frame == FRAME_attack208)
	{
		offset = { -10.5, 25, -9 };
	}
	else if (self->s.frame == FRAME_attack302)
	{
		offset = { -11, 18, 10 };
	}
	else
	{
		offset = { -8, 25, 12.5	};
	}

	cyborg_fire(self, offset);
}

void cyborg_reattack(edict_t* self);

mframe_t cyborg_frames_attack_run[] = {
	{ ai_charge, 16 },
	{ ai_charge, 16 },
	{ ai_charge, 16, monster_footstep },
	{ ai_charge, 12 },
	{ ai_charge, 12 },

	{ ai_charge, 12, cyborg_fire_left },
	{ ai_charge, 12 },
	{ ai_charge, 16 },
	{ ai_charge, 12, monster_footstep },
	{ ai_charge, 12 },

	{ ai_charge, 8 },
	{ ai_charge, 6, cyborg_fire_right },
};
MMOVE_T(cyborg_move_attack_run) = { FRAME_attack101, FRAME_attack112, cyborg_frames_attack_run, cyborg_run };

mframe_t cyborg_frames_attack_backflip[] = {
	{ ai_charge, 1 },
	{ ai_charge },
	{ ai_charge },
	{ ai_charge, -4 },
	{ ai_charge, -6 },

	{ ai_charge, -6 },
	{ ai_charge, -4, monster_footstep },
	{ ai_charge, -2, [](edict_t* self) { cyborg_fire_left(self); cyborg_fire_right(self); monster_footstep(self); }},
	{ ai_charge, -2 },
	{ ai_charge },

	{ ai_charge }
};
MMOVE_T(cyborg_move_attack_backflip) = { FRAME_attack201, FRAME_attack211, cyborg_frames_attack_backflip, cyborg_run };

mframe_t cyborg_frames_attack_right[] = {
	{ ai_charge },
	{ ai_charge, -2, cyborg_fire_right },
	{ ai_charge, -4 },
	{ ai_charge, -2 },
	{ ai_charge },

	{ ai_charge, 0, cyborg_reattack }
};
MMOVE_T(cyborg_move_attack_right) = { FRAME_attack301, FRAME_attack306, cyborg_frames_attack_right, cyborg_run };

mframe_t cyborg_frames_attack_left[] = {
	{ ai_charge },
	{ ai_charge, -2, cyborg_fire_left },
	{ ai_charge, -4 },
	{ ai_charge, -2 },
	{ ai_charge },

	{ ai_charge, 0, cyborg_reattack }
};
MMOVE_T(cyborg_move_attack_left) = { FRAME_attack401, FRAME_attack406, cyborg_frames_attack_left, cyborg_run };

void cyborg_reattack(edict_t* self)
{
	if (frandom() > 0.5f)
		return;
	else
	{
		if (frandom() >= 0.75f)
			M_SetAnimation(self, &cyborg_move_attack_backflip);
		else if (frandom() >= 0.5f)
			M_SetAnimation(self, &cyborg_move_attack_right);
		else
			M_SetAnimation(self, &cyborg_move_attack_left);
	}
}

MONSTERINFO_ATTACK(cyborg_attack) (edict_t* self) -> void
{
	if (range_to(self, self->enemy) <= (RANGE_NEAR / 3))
	{
		M_SetAnimation(self, &cyborg_move_attack_backflip);
	}
	if (range_to(self, self->enemy) >= RANGE_MID)
	{
		M_SetAnimation(self, &cyborg_move_attack_run);
	}
	else
	{
		if (frandom() > 0.5f)
			M_SetAnimation(self, &cyborg_move_attack_right);
		else
			M_SetAnimation(self, &cyborg_move_attack_left);
	}
}

//
//MELEE
//

void cyborg_punch(edict_t* self)
{
	constexpr vec3_t aim = { MELEE_DISTANCE, 0, -24 };

	if (!fire_hit(self, aim, irandom(5, 11), 250)) //	Faster attack
		self->monsterinfo.melee_debounce_time = level.time + 1.2_sec;
}

void cyborg_kick(edict_t* self)
{
	vec3_t aim = { MELEE_DISTANCE, self->mins[0], -4 };

	if (!fire_hit(self, aim, irandom(15, 21), 400)) // Slower attack
		self->monsterinfo.melee_debounce_time = level.time + 2.5_sec;
}

void cyborg_backflip(edict_t* self)
{
	if (frandom() >= 0.5f)
		M_SetAnimation(self, &cyborg_move_attack_backflip);
}

mframe_t cyborg_frames_attack_melee1[] = {
	{ ai_charge },
	{ ai_charge, 1 },
	{ ai_charge, 2, [](edict_t* self) { monster_footstep(self); cyborg_punch(self); } },
	{ ai_charge, 1 },
	{ ai_charge },

	{ ai_charge, 1 },
	{ ai_charge, 2, cyborg_punch },
	{ ai_charge, -2,  [](edict_t* self) { monster_footstep(self); cyborg_backflip(self); } }
};
MMOVE_T(cyborg_move_attack_melee1) = { FRAME_melee101, FRAME_melee108, cyborg_frames_attack_melee1, cyborg_run };

mframe_t cyborg_frames_attack_melee2[] = {
	{ ai_charge, 1 },
	{ ai_charge, 2 },
	{ ai_charge, 3, cyborg_kick },
	{ ai_charge, 3 },
	{ ai_charge, -2 },

	{ ai_charge, -2,  [](edict_t* self) { cyborg_punch(self); cyborg_backflip(self); } },
};
MMOVE_T(cyborg_move_attack_melee2) = { FRAME_melee201, FRAME_melee206, cyborg_frames_attack_melee2, cyborg_run };

MONSTERINFO_MELEE(cyborg_melee) (edict_t* self) -> void
{
	if (frandom() >= 0.5)
		M_SetAnimation(self, &cyborg_move_attack_melee1);
	else
		M_SetAnimation(self, &cyborg_move_attack_melee2);
}

//
//PAIN
//
mframe_t cyborg_frames_pain1[] = {
	{ ai_move },
	{ ai_move },
	{ ai_move },

	{ ai_move },
	{ ai_move },
	{ ai_move },
};
MMOVE_T(cyborg_move_pain1) = { FRAME_pain101, FRAME_pain106, cyborg_frames_pain1, cyborg_run };

mframe_t cyborg_frames_pain2[] = {
	{ ai_move },
	{ ai_move, -1 },
	{ ai_move, -1 },
	{ ai_move, -2 },
	{ ai_move, -2, monster_footstep },

	{ ai_move, -2 },
	{ ai_move, -1 },
	{ ai_move },
	{ ai_move, -1 },
	{ ai_move, -1 },

	{ ai_move, 1 },
	{ ai_move, 4 },
	{ ai_move, 4, monster_footstep },
	{ ai_move, 2 },
	{ ai_move },

	{ ai_move }
};
MMOVE_T(cyborg_move_pain2) = { FRAME_pain201, FRAME_pain216, cyborg_frames_pain2, cyborg_run };


PAIN(cyborg_pain) (edict_t* self, edict_t* other, float kick, int damage, const mod_t& mod) -> void
{
	if (level.time < self->pain_debounce_time)
		return;

	self->pain_debounce_time = level.time + 3_sec;
	gi.sound(self, CHAN_VOICE, sound_pain, 1, ATTN_NORM, 0);

	if (!M_ShouldReactToPain(self, mod))
		return; // no pain anims in nightmare

	self->monsterinfo.aiflags &= ~AI_MANUAL_STEERING;

	float r = frandom();

	if (r >= 0.5f)
		M_SetAnimation(self, &cyborg_move_pain1);
	else
		M_SetAnimation(self, &cyborg_move_pain2);
}

MONSTERINFO_SETSKIN(cyborg_setskin) (edict_t* self) -> void
{
	if (self->health < (self->max_health / 2))
		self->s.skinnum |= 1;
	else
		self->s.skinnum &= ~1;
}

//
//DEATH
//

void cyborg_dead(edict_t* self)
{
	self->mins = { -16, -16, -38 };
	self->maxs = { 16, 16, -16 };
	monster_dead(self);
}

static void cyborg_shrink(edict_t* self)
{
	self->maxs[2] = 0;
	self->svflags |= SVF_DEADMONSTER;
	gi.linkentity(self);
}

mframe_t cyborg_frames_death1[] = {
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move, 0, cyborg_shrink },

	{ ai_move },
	{ ai_move },
	{ ai_move, 0, monster_footstep }
};
MMOVE_T(cyborg_move_death1) = { FRAME_death101, FRAME_death108, cyborg_frames_death1, cyborg_dead };

mframe_t cyborg_frames_death2[] = {
	{ ai_move },
	{ ai_move, -1 },
	{ ai_move, -1, cyborg_shrink },
	{ ai_move, -2 },
	{ ai_move, -2, monster_footstep },

	{ ai_move }
};
MMOVE_T(cyborg_move_death2) = { FRAME_death201, FRAME_death206, cyborg_frames_death2, cyborg_dead };

mframe_t cyborg_frames_death3[] = {
	{ ai_move },
	{ ai_move, 1 },
	{ ai_move, 2 },
	{ ai_move, 2, cyborg_shrink },
	{ ai_move, 1 },

	{ ai_move, 0, monster_footstep }
};
MMOVE_T(cyborg_move_death3) = { FRAME_death301, FRAME_death306, cyborg_frames_death3, cyborg_dead };

DIE(cyborg_die) (edict_t* self, edict_t* inflictor, edict_t* attacker, int damage, const vec3_t& point, const mod_t& mod) -> void
{
	if (M_CheckGib(self, mod))
	{
		gi.sound(self, CHAN_VOICE, gi.soundindex("misc/udeath.wav"), 1, ATTN_NORM, 0);

		self->s.skinnum = 0;

		ThrowGibs(self, damage, {
			{ 3, "models/objects/gibs/bone/tris.md2" },
			{ 5, "models/objects/gibs/sm_meat/tris.md2" },
			{ 2, "models/objects/gibs/gear/tris.md2" },
			{ "models/objects/gibs/head2/tris.md2", GIB_HEAD | GIB_SKINNED }
			});
		self->deadflag = true;
		return;
	}

	if (self->deadflag)
		return;

	gi.sound(self, CHAN_VOICE, sound_death, 1, ATTN_NORM, 0);
	self->deadflag = true;
	self->takedamage = true;

	if (damage >= 50)
		M_SetAnimation(self, &cyborg_move_death2);
	else if (frandom() >= 0.5f)
		M_SetAnimation(self, &cyborg_move_death1);
	else
		M_SetAnimation(self, &cyborg_move_death3);
}

/*QUAKED monster_cyborg (1 .5 0) (-16 -16 -38) (32 32 27) Ambush Trigger_Spawn Sight Corpse
*/
void SP_monster_cyborg(edict_t* self)
{
	const spawn_temp_t& st = ED_GetSpawnTemp();

	if (!M_AllowSpawn(self)) {
		G_FreeEdict(self);
		return;
	}

	sound_pain.assign("cyborg/pain.wav");
	sound_death.assign("cyborg/death.wav");
	sound_sight.assign("cyborg/sight.wav");
	sound_idle.assign("cyborg/idle.wav");
	sound_attack.assign("chick/chkatck2.wav");
	sound_step.assign("insane/insane11.wav");

	self->s.modelindex = gi.modelindex("models/monsters/cyborg/tris.md2");
	self->mins = { -16, -16, -38 };
	self->maxs = { 16, 16, 27 };
	self->movetype = MOVETYPE_STEP;
	self->solid = SOLID_BBOX;

	self->health = 200 * st.health_multiplier;
	if (!st.was_key_specified("armor_type"))
		self->monsterinfo.armor_type = IT_ARMOR_COMBAT;
	if (!st.was_key_specified("armor_power"))
		self->monsterinfo.armor_power = 100;
	self->gib_health = -200;
	self->mass = 350;

	self->monsterinfo.scale = MODEL_SCALE;

	self->pain = cyborg_pain;
	self->die = cyborg_die;

	self->monsterinfo.sight = cyborg_sight;
	self->monsterinfo.idle = cyborg_idle;
	self->monsterinfo.search = cyborg_search;

	self->monsterinfo.stand = cyborg_stand;
	self->monsterinfo.walk = cyborg_walk;
	self->monsterinfo.run = cyborg_run;

	self->monsterinfo.attack = cyborg_attack;
	self->monsterinfo.melee = cyborg_melee;

	self->monsterinfo.setskin = cyborg_setskin;

	gi.linkentity(self);

	M_SetAnimation(self, &cyborg_move_stand);

	walkmonster_start(self);
}