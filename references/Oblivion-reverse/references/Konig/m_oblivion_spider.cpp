// Copyright (c) ZeniMax Media Inc.
// Licensed under the GNU General Public License 2.0.
/*
==============================================================================

SPIDER

==============================================================================
*/

#include "../g_local.h"
#include "m_oblivion_spider.h"
#include "../m_flash.h"

static cached_soundindex sound_pain;
static cached_soundindex sound_death;
static cached_soundindex sound_sight;
static cached_soundindex sound_idle;
static cached_soundindex sound_melee;
static cached_soundindex sound_attack;
static cached_soundindex sound_leap;
static cached_soundindex sound_land;
static cached_soundindex sound_spawn;

constexpr spawnflags_t SPAWNFLAG_SPIDER_NOJUMPING = 8_spawnflag;

constexpr const char* default_reinforcements = "monster_stalker 1";
constexpr int32_t default_monster_slots_base = 2;

void T_SlamRadiusDamage(vec3_t point, edict_t* inflictor, edict_t* attacker, float damage, float kick, edict_t* ignore, float radius, mod_t mod);

//
//SOUNDS
//

MONSTERINFO_IDLE(spider_idle) (edict_t* self) -> void
{
	gi.sound(self, CHAN_VOICE, sound_sight, 1, ATTN_IDLE, 0);
}

MONSTERINFO_SEARCH(spider_search) (edict_t* self) -> void
{
	gi.sound(self, CHAN_VOICE, sound_sight, 1, ATTN_NORM, 0);
}

MONSTERINFO_SIGHT(spider_sight) (edict_t* self, edict_t* other) -> void
{
	gi.sound(self, CHAN_VOICE, sound_sight, 1, ATTN_NORM, 0);
}

void spider_land(edict_t* self)
{
	gi.sound(self, CHAN_BODY, sound_land, 1, ATTN_NORM, 0);
}

void spider_swing(edict_t* self)
{
	gi.sound(self, CHAN_WEAPON, sound_melee, 1, ATTN_NORM, 0);

}

//
//STAND
//

mframe_t spider_frames_stand1[] = {
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand, 0, monster_footstep },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand, 0, monster_footstep },
	{ ai_stand },
	{ ai_stand },

	{ ai_stand },
	{ ai_stand, 0, monster_footstep },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand, 0, monster_footstep },

	{ ai_stand },
	{ ai_stand, 0, monster_footstep },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand, 0, monster_footstep },
	{ ai_stand },
	{ ai_stand },

	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand }
};
MMOVE_T(spider_move_stand1) = { FRAME_stand101, FRAME_stand137, spider_frames_stand1, nullptr };

mframe_t spider_frames_stand2[] = {
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },

	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },

	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand },
	{ ai_stand }
};
MMOVE_T(spider_move_stand2) = { FRAME_stand138, FRAME_stand155, spider_frames_stand2, nullptr };

MONSTERINFO_STAND(spider_stand) (edict_t* self) -> void
{
	if (frandom() > 0.5)
		M_SetAnimation(self, &spider_move_stand1);
	else
		M_SetAnimation(self, &spider_move_stand2);
}

//
//WALKRUN
//

mframe_t spider_frames_walk[] = {
	{ ai_walk, 2, monster_footstep },
	{ ai_walk, 5 },
	{ ai_walk, 12, monster_footstep },
	{ ai_walk, 16 },
	{ ai_walk, 5 },
	{ ai_walk, 8, monster_footstep },
	{ ai_walk, 8 },
	{ ai_walk, 12 },
	{ ai_walk, 9, monster_footstep },
	{ ai_walk, 5 }
};
MMOVE_T(spider_move_walk) = { FRAME_walk101, FRAME_walk110, spider_frames_walk, nullptr };

MONSTERINFO_WALK(spider_walk) (edict_t* self) -> void
{
	M_SetAnimation(self, &spider_move_walk);
}

mframe_t spider_frames_run1[] = {
	{ ai_run, 2, monster_footstep },
	{ ai_run, 5 },
	{ ai_run, 12, monster_footstep },
	{ ai_run, 16 },
	{ ai_run, 5 },
	{ ai_run, 8, monster_footstep },
	{ ai_run, 8 },
	{ ai_run, 12 },
	{ ai_run, 9, monster_footstep },
	{ ai_run, 5 }
};
MMOVE_T(spider_move_run1) = { FRAME_walk101, FRAME_walk110, spider_frames_run1, nullptr };

mframe_t spider_frames_run3[] = {
	{ ai_run, 12, monster_footstep },
	{ ai_run, 16 },
	{ ai_run, 12 },
	{ ai_run, 12, monster_footstep },
	{ ai_run, 16 },
	{ ai_run, 12 },
};
MMOVE_T(spider_move_run3) = { FRAME_run201, FRAME_run206, spider_frames_run3, nullptr };


MONSTERINFO_RUN(spider_run) (edict_t* self) -> void
{
	if (self->monsterinfo.aiflags & AI_STAND_GROUND)
	{
		M_SetAnimation(self, &spider_move_stand1);
		return;
	}

	if (frandom() > 0.5)
		M_SetAnimation(self, &spider_move_run1);
	else
		M_SetAnimation(self, &spider_move_run3);
}

//
//MELEE
//

void spider_smack(edict_t* self)
{
	if (!self->enemy)
		return;

	ai_charge(self, 0);

	if (!CanDamage(self->enemy, self))
		return;

	vec3_t aim = { MELEE_DISTANCE, self->mins[0], -4 };
	bool hit = fire_hit(self, aim, irandom(110, 120), 120); // Slower attack
}

void spider_slam(edict_t* self)
{
	gi.WriteByte(svc_temp_entity);
	gi.WriteByte(TE_BERSERK_SLAM);
	vec3_t f, r, start;
	AngleVectors(self->s.angles, f, r, nullptr);
	start = M_ProjectFlashSource(self, { 20.f, 0.f, 14.f }, f, r);
	trace_t tr = gi.traceline(self->s.origin, start, self, MASK_SOLID);
	gi.WritePosition(tr.endpos);
	gi.WriteDir(f);
	gi.multicast(tr.endpos, MULTICAST_PHS, false);

	T_SlamRadiusDamage(tr.endpos, self, self, 32, 250.f, self, 200.f, MOD_UNKNOWN);
}

mframe_t spider_frames_melee1[] = {
	{ ai_charge },
	{ ai_charge },
	{ ai_charge },
	{ ai_charge, 0, spider_swing },
	{ ai_charge, 0, spider_smack }
};
MMOVE_T(spider_move_melee1) = { FRAME_melee101, FRAME_melee105, spider_frames_melee1, spider_run };

mframe_t spider_frames_melee2[] = {
	{ ai_charge },
	{ ai_charge },
	{ ai_charge },
	{ ai_charge },
	{ ai_charge, 0, spider_swing },
	{ ai_charge, 0, spider_slam },
	{ ai_charge }
};
MMOVE_T(spider_move_melee2) = { FRAME_melee201, FRAME_melee207, spider_frames_melee2, spider_run };

MONSTERINFO_MELEE(spider_melee) (edict_t* self) -> void
{
	float chance = frandom();
	if (chance > 0.7 || self->health == 600)
		M_SetAnimation(self, &spider_move_melee2);
	else
		M_SetAnimation(self, &spider_move_melee1);
}

//
//ATTACK
//

static void spider_attack_slam(edict_t* self)
{
	gi.sound(self, CHAN_WEAPON, sound_land, 1, ATTN_NORM, 0);
	gi.WriteByte(svc_temp_entity);
	gi.WriteByte(TE_BERSERK_SLAM);
	vec3_t f, r, start;
	AngleVectors(self->s.angles, f, r, nullptr);
	start = M_ProjectFlashSource(self, { 20.f, -14.3f, -21.f }, f, r);
	trace_t tr = gi.traceline(self->s.origin, start, self, MASK_SOLID);
	gi.WritePosition(tr.endpos);
	gi.WriteDir({ 0.f, 0.f, 1.f });
	gi.multicast(tr.endpos, MULTICAST_PHS, false);
	self->gravity = 1.0f;
	self->velocity = {};
	self->flags |= FL_KILL_VELOCITY;

	T_SlamRadiusDamage(tr.endpos, self, self, 8, 300.f, self, 165, MOD_UNKNOWN);
}

TOUCH(spider_jump_touch) (edict_t* self, edict_t* other, const trace_t& tr, bool other_touching_self) -> void
{
	if (self->health <= 0)
	{
		self->touch = nullptr;
		return;
	}

	if (self->groundentity)
	{
		self->s.frame = FRAME_run108;

		if (self->touch)
			spider_attack_slam(self);

		self->touch = nullptr;
	}
}

static void spider_high_gravity(edict_t* self)
{
	float gravity_scale = (800.f / level.gravity);

	if (self->velocity[2] < 0)
		self->gravity = 2.25f;
	else
		self->gravity = 5.25f;

	self->gravity *= gravity_scale;
}

void spider_leap_takeoff(edict_t* self)
{
	vec3_t forward;

	if (!self->enemy)
		return;

	float length = (self->s.origin - self->enemy->s.origin).length();
	float fwd_speed = length * 1.95f;
	vec3_t dir;
	PredictAim(self, self->enemy, self->s.origin, fwd_speed, false, 0.f, &dir, nullptr);
	self->s.angles[1] = vectoyaw(dir);
	AngleVectors(self->s.angles, forward, nullptr, nullptr);
	self->s.origin[2] += 1;
	self->velocity = forward * fwd_speed;
	self->velocity[2] = 400;
	self->groundentity = nullptr;
	self->monsterinfo.aiflags |= AI_DUCKED;
	self->monsterinfo.attack_finished = level.time + 3_sec;
	self->touch = spider_jump_touch;
	spider_high_gravity(self);

	self->gravity = -self->gravity;
	SV_AddGravity(self);
	self->gravity = -self->gravity;

	gi.linkentity(self);

	gi.sound(self, CHAN_BODY, sound_leap, 1, ATTN_NORM, 0);
}

void spider_check_landing(edict_t* self)
{
	spider_high_gravity(self);

	if (self->groundentity)
	{
		self->monsterinfo.attack_finished = 0_ms;
		self->s.frame = FRAME_run108;
		if (self->touch)
		{
			spider_attack_slam(self);
			self->touch = nullptr;
		}
		self->flags &= ~FL_KILL_VELOCITY;
		return;
	}

	if (level.time > self->monsterinfo.attack_finished)
		self->monsterinfo.nextframe = FRAME_run102;
	else
		self->monsterinfo.nextframe = FRAME_run104;
}

mframe_t spider_frames_leap[] = {
	{ ai_charge },
	{ ai_move, 0, spider_leap_takeoff },
	{ ai_move, 0, spider_high_gravity },
	{ ai_move, 0, spider_check_landing },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move, 0, monster_footstep },
	{ ai_move }
};
MMOVE_T(spider_move_leap) = { FRAME_run101, FRAME_run110, spider_frames_leap, spider_run };

void spider_reattack(edict_t* self);

void spider_reattack2(edict_t* self);

void spider_rocket(edict_t* self, vec3_t mz)
{
	vec3_t	forward, right;
	vec3_t	start;
	vec3_t	dir;
	vec3_t	vec;
	trace_t trace; // PMM - check target
	int		rocketSpeed = 650;
	vec3_t target;
	bool   blindfire = false;

	if (self->monsterinfo.aiflags & AI_MANUAL_STEERING)
		blindfire = true;
	else
		blindfire = false;

	if (!self->enemy || !self->enemy->inuse) // PGM
		return;								 // PGM

	AngleVectors(self->s.angles, forward, right, nullptr);
	start = M_ProjectFlashSource(self, mz, forward, right);

	if (blindfire)
		target = self->monsterinfo.blind_fire_target;
	else
		target = self->enemy->s.origin;

	if (blindfire)
	{
		vec = target;
		dir = vec - start;
	}
	else if (frandom() < 0.33f || (start[2] < self->enemy->absmin[2]))
	{
		vec = target;
		vec[2] += self->enemy->viewheight;
		dir = vec - start;
	}
	else
	{
		vec = target;
		vec[2] = self->enemy->absmin[2] + 1;
		dir = vec - start;
	}

	if ((!blindfire) && (frandom() < 0.35f))
		PredictAim(self, self->enemy, start, rocketSpeed, false, 0.f, &dir, &vec);

	dir.normalize();

	trace = gi.traceline(start, vec, self, MASK_PROJECTILE);
	if (blindfire)
	{
		if (!(trace.startsolid || trace.allsolid || (trace.fraction < 0.5f)))
		{
			fire_rocket(self, start, dir, 25, rocketSpeed, 25, 25);
		}
		else
		{
			vec = target;
			vec += (right * -10);
			dir = vec - start;
			dir.normalize();
			trace = gi.traceline(start, vec, self, MASK_PROJECTILE);
			if (!(trace.startsolid || trace.allsolid || (trace.fraction < 0.5f)))
			{
				fire_rocket(self, start, dir, 50, rocketSpeed, 50, 50);
			}
			else
			{
				vec = target;
				vec += (right * 10);
				dir = vec - start;
				dir.normalize();
				trace = gi.traceline(start, vec, self, MASK_PROJECTILE);
				if (!(trace.startsolid || trace.allsolid || (trace.fraction < 0.5f)))
				{
					fire_rocket(self, start, dir, 50, rocketSpeed, 50, 50);
				}
			}
		}
	}
	else
	{
		if (trace.fraction > 0.5f || trace.ent->solid != SOLID_BSP)
		{
			fire_rocket(self, start, dir, 50, rocketSpeed, 50, 50);
		}
	}
}

void spider_rocket_heat(edict_t* self, vec3_t mz)
{
	vec3_t	forward, right;
	vec3_t	start;
	vec3_t	dir;
	vec3_t	vec;
	trace_t trace; // PMM - check target
	int		rocketSpeed = 650;
	vec3_t target;
	bool   blindfire = false;

	if (self->monsterinfo.aiflags & AI_MANUAL_STEERING)
		blindfire = true;
	else
		blindfire = false;

	if (!self->enemy || !self->enemy->inuse) // PGM
		return;								 // PGM

	AngleVectors(self->s.angles, forward, right, nullptr);
	start = M_ProjectFlashSource(self, mz, forward, right);

	if (blindfire)
		target = self->monsterinfo.blind_fire_target;
	else
		target = self->enemy->s.origin;

	if (blindfire)
	{
		vec = target;
		dir = vec - start;
	}
	else if (frandom() < 0.33f || (start[2] < self->enemy->absmin[2]))
	{
		vec = target;
		vec[2] += self->enemy->viewheight;
		dir = vec - start;
	}
	else
	{
		vec = target;
		vec[2] = self->enemy->absmin[2] + 1;
		dir = vec - start;
	}

	if ((!blindfire) && (frandom() < 0.35f))
		PredictAim(self, self->enemy, start, rocketSpeed, false, 0.f, &dir, &vec);

	dir.normalize();

	trace = gi.traceline(start, vec, self, MASK_PROJECTILE);
	if (blindfire)
	{
		if (!(trace.startsolid || trace.allsolid || (trace.fraction < 0.5f)))
		{
			fire_heat(self, start, dir, 25, rocketSpeed, 25, 25, 0.075f);
		}
		else
		{
			vec = target;
			vec += (right * -10);
			dir = vec - start;
			dir.normalize();
			trace = gi.traceline(start, vec, self, MASK_PROJECTILE);
			if (!(trace.startsolid || trace.allsolid || (trace.fraction < 0.5f)))
			{
				fire_heat(self, start, dir, 50, rocketSpeed, 50, 50, 0.075f);
			}
			else
			{
				vec = target;
				vec += (right * 10);
				dir = vec - start;
				dir.normalize();
				trace = gi.traceline(start, vec, self, MASK_PROJECTILE);
				if (!(trace.startsolid || trace.allsolid || (trace.fraction < 0.5f)))
				{
					fire_heat(self, start, dir, 50, rocketSpeed, 50, 50, 0.075f);
				}
			}
		}
	}
	else
	{
		if (trace.fraction > 0.5f || trace.ent->solid != SOLID_BSP)
		{
			fire_heat(self, start, dir, 50, rocketSpeed, 50, 50, 0.15f);
		}
	}
}

void spider_rocket_right(edict_t* self)
{
	vec3_t offset = { 58.f, 20.f, 2 };

	spider_rocket(self, offset);
}

void spider_rocket_left (edict_t* self)
{
	vec3_t offset = { 64.f, -22.f, 2 };

	spider_rocket(self, offset);
}

void spider_rocket_right2(edict_t* self)
{
	vec3_t offset = { 58.f, 20.f, 2 };

	spider_rocket_heat(self, offset);
}

void spider_rocket_left2(edict_t* self)
{
	vec3_t offset = { 64.f, -22.f, 2 };

	spider_rocket_heat(self, offset);
}

mframe_t spider_frames_attack1[] = {
	{ ai_charge },
	{ ai_charge },
	{ ai_charge, 0, spider_rocket_left },
	{ ai_charge },
	{ ai_charge, 0, spider_reattack }
};
MMOVE_T(spider_move_attack1) = { FRAME_attackL101, FRAME_attackL105, spider_frames_attack1, nullptr };

mframe_t spider_frames_attack2[] = {
	{ ai_charge },
	{ ai_charge },
	{ ai_charge, 0, spider_rocket_right },
	{ ai_charge },
	{ ai_charge, 0, spider_reattack }
};
MMOVE_T(spider_move_attack2) = { FRAME_attackR101, FRAME_attackR105, spider_frames_attack2, nullptr };

mframe_t spider_frames_attack3[] = {
	{ ai_charge },
	{ ai_charge, 0, spider_rocket_right2 },
	{ ai_charge },
	{ ai_charge },
	{ ai_charge },
	{ ai_charge, 0, spider_rocket_left2 },
	{ ai_charge },
	{ ai_charge, 0, spider_reattack2 }
};
MMOVE_T(spider_move_attack3) = { FRAME_attack201, FRAME_attack208, spider_frames_attack3, nullptr };

void spider_reattack(edict_t* self)
{
	float r = frandom();

	self->count++;

	if (r >= 0.75f)
		M_SetAnimation(self, &spider_move_attack2);
	else if (r >= 0.5f)
		M_SetAnimation(self, &spider_move_attack1);
	else
		spider_run(self);
}

void spider_reattack2(edict_t* self)
{
	float r = frandom();

	self->count++;

	if (r >= 0.5f)
		M_SetAnimation(self, &spider_move_attack3);
	else
		M_SetAnimation(self, &spider_move_attack1);
}

void spider_summon(edict_t* self)
{
	if (skill->integer != 3)
		return;

	self->count = 0;

	static constexpr vec3_t reinforcement_position[] = { { -24.f, 124.f, 0 }, { -24.f, -124.f, 0 } };
	vec3_t f, r, offset, startpoint, spawnpoint;
	int	   count;

	AngleVectors(self->s.angles, f, r, nullptr);

	int num_summoned;
	self->monsterinfo.chosen_reinforcements = M_PickReinforcements(self, num_summoned, 2);

	for (count = 0; count < num_summoned; count++)
	{
		offset = reinforcement_position[count];

		if (self->s.scale)
			offset *= self->s.scale;

		startpoint = M_ProjectFlashSource(self, offset, f, r);
		// a little off the ground
		startpoint[2] += 10 * (self->s.scale ? self->s.scale : 1.0f);

		auto& reinforcement = self->monsterinfo.reinforcements.reinforcements[self->monsterinfo.chosen_reinforcements[count]];

		if (FindSpawnPoint(startpoint, reinforcement.mins, reinforcement.maxs, spawnpoint, 32))
		{
			if (CheckGroundSpawnPoint(spawnpoint, reinforcement.mins, reinforcement.maxs, 256, -1))
			{
				edict_t* ent = CreateGroundMonster(spawnpoint, self->s.angles, reinforcement.mins, reinforcement.maxs, reinforcement.classname, 256);

				if (!ent)
					return;

				ent->nextthink = level.time;
				ent->think(ent);

				ent->monsterinfo.aiflags |= AI_SPAWNED_COMMANDER | AI_DO_NOT_COUNT | AI_IGNORE_SHOTS;
				ent->monsterinfo.commander = self;
				ent->monsterinfo.slots_from_commander = reinforcement.strength;
				self->monsterinfo.monster_used += reinforcement.strength;

				gi.sound(ent, CHAN_BODY, sound_spawn, 1, ATTN_NONE, 0);

				if ((self->enemy->inuse) && (self->enemy->health > 0))
				{
					ent->enemy = self->enemy;
					FoundTarget(ent);
				}

				float radius = (reinforcement.maxs - reinforcement.mins).length() * 0.5f;
				SpawnGrow_Spawn(spawnpoint + (reinforcement.mins + reinforcement.maxs), radius, radius * 2.f);
			}
		}
	}
}

mframe_t spider_frames_anger[] = {
	{ ai_charge },
	{ ai_charge },
	{ ai_charge },
	{ ai_charge },
	{ ai_charge },
	{ ai_charge, 0, spider_summon },
	{ ai_charge }
};
MMOVE_T(spider_move_anger) = { FRAME_melee201, FRAME_melee207, spider_frames_anger, spider_run };

MONSTERINFO_ATTACK(spider_attack) (edict_t* self) -> void
{
	if (self->monsterinfo.melee_debounce_time <= level.time && (range_to(self, self->enemy) < MELEE_DISTANCE))
		spider_melee(self);
	else if (!self->spawnflags.has(SPAWNFLAG_SPIDER_NOJUMPING) && (self->timestamp < level.time && brandom()) && range_to(self, self->enemy) > 250.f) //KONIG - increased distance for jumping
	{
		M_SetAnimation(self, &spider_move_leap);
		gi.sound(self, CHAN_WEAPON, sound_leap, 1, ATTN_NORM, 0);
		self->timestamp = level.time + 5_sec;
	}
	else if (self->count >= 5 && skill->integer >= 3)
		M_SetAnimation(self, &spider_move_anger);
	else
	{
		if (self->health < (self->max_health / 2))
			M_SetAnimation(self, &spider_move_attack3);
		else
		{
			if (frandom() > 0.5f)
				M_SetAnimation(self, &spider_move_attack1);
			else
				M_SetAnimation(self, &spider_move_attack2);
		}
	}
}

//
//DODGE
//

void spider_jump_straightup(edict_t* self)
{
	if (self->deadflag)
		return;

	if (self->groundentity)
	{
		self->velocity[0] += crandom() * 5;
		self->velocity[1] += crandom() * 5;
		self->velocity[2] += -400 * self->gravityVector[2];
	}
}

void spider_jump_wait_land(edict_t* self)
{
	if ((frandom() < 0.4f) && (level.time >= self->monsterinfo.attack_finished))
	{
		self->monsterinfo.attack_finished = level.time + 300_ms;
		spider_attack(self);
	}

	if (self->groundentity == nullptr)
	{
		self->gravity = 1.3f;
		self->monsterinfo.nextframe = self->s.frame;

		if (monster_jump_finished(self))
		{
			self->gravity = 1;
			self->monsterinfo.nextframe = self->s.frame + 1;
		}
	}
	else
	{
		self->gravity = 1;
		self->monsterinfo.nextframe = self->s.frame + 1;
	}
}

mframe_t spider_frames_jump_straightup[] = {
	{ ai_move },
	{ ai_move, 1, spider_jump_straightup },
	{ ai_move, 1 },
	{ ai_move, -1, spider_jump_wait_land },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move, 0, monster_footstep },
	{ ai_move }
};
MMOVE_T(spider_move_jump_straightup) = { FRAME_run101, FRAME_run110, spider_frames_jump_straightup, spider_run };

void spider_dodge_jump(edict_t* self)
{
	M_SetAnimation(self, &spider_move_jump_straightup);
}

MONSTERINFO_DODGE(spider_dodge) (edict_t* self, edict_t* attacker, gtime_t eta, trace_t* tr, bool gravity) -> void
{
	if (!self->groundentity || self->health <= 0)
		return;

	if (!self->enemy)
	{
		self->enemy = attacker;
		FoundTarget(self);
		return;
	}

	if ((eta < FRAME_TIME_MS) || (eta > 5_sec))
		return;

	if (self->timestamp > level.time)
		return;

	self->timestamp = level.time + random_time(1_sec, 5_sec);

	spider_dodge_jump(self);
}

//
//PAIN
//

mframe_t spider_frames_pain1[] = {
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move }
};
MMOVE_T(spider_move_pain1) = { FRAME_pain101, FRAME_pain106, spider_frames_pain1, spider_run };

mframe_t spider_frames_pain2[] = {
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move }
};
MMOVE_T(spider_move_pain2) = { FRAME_pain201, FRAME_pain208, spider_frames_pain2, spider_run };

PAIN(spider_pain) (edict_t* self, edict_t* other, float kick, int damage, const mod_t& mod) -> void
{
	if (level.time < self->pain_debounce_time)
		return;

	self->pain_debounce_time = level.time + 3_sec;
	gi.sound(self, CHAN_VOICE, sound_pain, 1, ATTN_NORM, 0);

	self->monsterinfo.aiflags &= ~AI_MANUAL_STEERING;

	float r = frandom();

	if (r < 0.5f)
		M_SetAnimation(self, &spider_move_pain1);
	else
		M_SetAnimation(self, &spider_move_pain2);
}

MONSTERINFO_SETSKIN(spider_setskin) (edict_t* self) -> void
{
	if (self->health < (self->max_health / 2))
		self->s.skinnum |= 1;
	else
		self->s.skinnum &= ~1;
}

//
//DEATH
//
void spider_dead(edict_t* self)
{
	self->mins = { -16, -16, -35 };
	self->maxs = { 16, 16, -8 };
	self->movetype = MOVETYPE_TOSS;
	self->svflags |= SVF_DEADMONSTER;
	self->nextthink = 0_ms;
	gi.linkentity(self);
}

mframe_t spider_frames_death1[] = {
	{ ai_move, 0 },
	{ ai_move, -1.23f },
	{ ai_move, -1.23f },
	{ ai_move, -1.23f },
	{ ai_move, -1.23f },
	{ ai_move, -1.64f },
	{ ai_move, -1.64f },
	{ ai_move, -2.45f },
	{ ai_move, -8.63f },
	{ ai_move, -4.0f },
	{ ai_move, -4.5f },
	{ ai_move, -6.8f },
	{ ai_move, -8.0f },
	{ ai_move, -5.4f },
	{ ai_move, -3.4f },
	{ ai_move, -1.9f },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move }
};
MMOVE_T(spider_move_death1) = { FRAME_death101, FRAME_death120, spider_frames_death1, spider_dead };

mframe_t spider_frames_death2[] = {
	{ ai_move, 0 },
	{ ai_move, -1.23f },
	{ ai_move, -1.23f },
	{ ai_move, -1.23f },
	{ ai_move, -1.23f },
	{ ai_move, -1.64f },
	{ ai_move, -1.64f },
	{ ai_move, -2.45f },
	{ ai_move, -8.63f },
	{ ai_move, -4.0f },
	{ ai_move, -4.5f },
	{ ai_move, -6.8f },
	{ ai_move, -8.0f },
	{ ai_move, -5.4f },
	{ ai_move, -3.4f },
	{ ai_move, -1.9f },
	{ ai_move },
	{ ai_move },
	{ ai_move },
	{ ai_move }
};
MMOVE_T(spider_move_death2) = { FRAME_death201, FRAME_death220, spider_frames_death2, spider_dead };

DIE(spider_die) (edict_t* self, edict_t* inflictor, edict_t* attacker, int damage, const vec3_t& point, const mod_t& mod) -> void
{
	if (M_CheckGib(self, mod))
	{
		gi.sound(self, CHAN_VOICE, gi.soundindex("misc/udeath.wav"), 1, ATTN_NORM, 0);
		ThrowGibs(self, damage, {
			{ 2, "models/objects/gibs/bone/tris.md2" },
			{ 2, "models/objects/gibs/sm_meat/tris.md2" },
			{ 2, "models/objects/gibs/gear/tris.md2" },
			{ 4, "models/monsters/spider/gibs_leg.md2" },
			{ 2, "models/monsters/spider/gibs_rarm.md2" },
			{ 1, "models/monsters/spider/gibs_pelvis.md2" },
			{ 1, "models/monsters/spider/gibs_torso.md2" },
			{ "models/objects/gibs/head2/tris.md2", GIB_HEAD }
			});
		self->deadflag = true;
		return;
	}

	if (self->deadflag)
		return;

	gi.sound(self, CHAN_VOICE, sound_death, 1, ATTN_NORM, 0);
	self->deadflag = true;
	self->takedamage = true;

	self->monsterinfo.aiflags &= ~AI_MANUAL_STEERING;

	if (frandom() < 0.5f)
		M_SetAnimation(self, &spider_move_death1);
	else
		M_SetAnimation(self, &spider_move_death2);
}

/*QUAKED monster_spider (1 .5 0) (-32 -32 -35) (32 32 32) Ambush Trigger_Spawn Sight
 */
void SP_monster_spider(edict_t* self)
{
	const spawn_temp_t& st = ED_GetSpawnTemp();

	if (!M_AllowSpawn(self)) {
		G_FreeEdict(self);
		return;
	}

	sound_pain.assign("spider/pain.wav");
	sound_death.assign("spider/death.wav");
	sound_sight.assign("spider/sight.wav");
	sound_idle.assign("spider/idle.wav");
	sound_melee.assign("berserk/attack.wav");
	sound_attack.assign("chick/chkatck2.wav");
	sound_land.assign("mutant/thud1.wav");
	sound_leap.assign("berserk/jump.wav");

	if (skill->value >= 3)
	{
		sound_spawn.assign("medic_commander/monsterspawn1.wav");

		self->count = 0;

		const char* reinforcements = default_reinforcements;

		if (!st.was_key_specified("monster_slots"))
			self->monsterinfo.monster_slots = default_monster_slots_base;
		if (st.was_key_specified("reinforcements"))
			reinforcements = st.reinforcements;

		if (self->monsterinfo.monster_slots && reinforcements && *reinforcements)
			M_SetupReinforcements(reinforcements, self->monsterinfo.reinforcements);
	}

	self->s.modelindex = gi.modelindex("models/monsters/spider/tris.md2");
	self->mins = { -32, -32, -35 };
	self->maxs = { 32, 32, 32 };
	self->movetype = MOVETYPE_STEP;
	self->solid = SOLID_BBOX;

	self->health = 400 * st.health_multiplier;	
	self->gib_health = -150;
	self->mass = 450;

	self->monsterinfo.scale = MODEL_SCALE;

	self->pain = spider_pain;
	self->die = spider_die;

	self->monsterinfo.sight = spider_sight;
	self->monsterinfo.idle = spider_idle;
	self->monsterinfo.search = spider_search;

	self->monsterinfo.stand = spider_stand;
	self->monsterinfo.walk = spider_walk;
	self->monsterinfo.run = spider_run;

	self->monsterinfo.attack = spider_attack;
	self->monsterinfo.melee = spider_melee;

	self->monsterinfo.setskin = spider_setskin;

	self->monsterinfo.can_jump = !self->spawnflags.has(SPAWNFLAG_SPIDER_NOJUMPING);
	self->monsterinfo.drop_height = 256;
	self->monsterinfo.jump_height = 40;

	gi.linkentity(self);

	M_SetAnimation(self, &spider_move_stand1);

	walkmonster_start(self);
}