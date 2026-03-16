/*Copyright (c) 2024 ZeniMax Media Inc.
Licensed under the GNU General Public License 2.0.

g_func.cpp (Game Function Entities) This file implements the behavior for various "func_*"
entities, which are brush-based, interactive map elements that form the core of Quake II's level
scripting and dynamism. Key Responsibilities: - Movers: Contains the logic for all moving
platforms, doors, and trains (`func_plat`, `func_door`, `func_train`). This includes handling
their movement paths, speed, acceleration, and what happens when they are blocked. - Interactive
Objects: Implements buttons (`func_button`), rotating objects (`func_rotating`), and other
interactive map features. - Special Volumes: Defines the behavior of special volumes like
`func_water` and `func_killbox`. - State Management: Manages the internal state machines for
these entities (e.g., a door's state being 'up', 'down', 'moving up', etc.).*/

#include "../g_local.hpp"

/*
=========================================================

  PLATS

  movement options:

  linear
  smooth start, hard stop
  smooth start, smooth stop

  start
  end
  acceleration
  speed
  deceleration
  begin sound
  end sound
  target fired when reaching end
  wait at end

  object characteristics that use move segments
  ---------------------------------------------
  movetype_push, or movetype_stop
  action when touched
  action when blocked
  action when used
	disabled?
  auto trigger spawning


=========================================================
*/

constexpr SpawnFlags SPAWNFLAG_DOOR_START_OPEN = 1_spawnflag;
constexpr SpawnFlags SPAWNFLAG_DOOR_CRUSHER = 4_spawnflag;
constexpr SpawnFlags SPAWNFLAG_DOOR_NOMONSTER = 8_spawnflag;
constexpr SpawnFlags SPAWNFLAG_DOOR_ANIMATED = 16_spawnflag;
constexpr SpawnFlags SPAWNFLAG_DOOR_TOGGLE = 32_spawnflag;
constexpr SpawnFlags SPAWNFLAG_DOOR_ANIMATED_FAST = 64_spawnflag;

constexpr SpawnFlags SPAWNFLAG_DOOR_ROTATING_X_AXIS = 64_spawnflag;
constexpr SpawnFlags SPAWNFLAG_DOOR_ROTATING_Y_AXIS = 128_spawnflag;
constexpr SpawnFlags SPAWNFLAG_DOOR_ROTATING_INACTIVE = 0x10000_spawnflag; // Paril: moved to non-reserved
constexpr SpawnFlags SPAWNFLAG_DOOR_ROTATING_SAFE_OPEN = 0x20000_spawnflag;

// support routine for setting moveInfo sounds
static inline int32_t G_GetMoveinfoSoundIndex(gentity_t* self, const char* default_value, const char* wanted_value) {
	if (!wanted_value) {
		if (default_value)
			return gi.soundIndex(default_value);

		return 0;
	}
	else if (!*wanted_value || *wanted_value == '0' || *wanted_value == ' ')
		return 0;

	return gi.soundIndex(wanted_value);
}

void G_SetMoveinfoSounds(gentity_t* self, const char* default_start, const char* default_mid, const char* default_end) {
	self->moveInfo.sound_start = G_GetMoveinfoSoundIndex(self, default_start, st.noise_start);
	self->moveInfo.sound_middle = G_GetMoveinfoSoundIndex(self, default_mid, st.noise_middle);
	self->moveInfo.sound_end = G_GetMoveinfoSoundIndex(self, default_end, st.noise_end);
}

//
// Support routines for movement (changes in origin using velocity)
//

static THINK(Move_Done) (gentity_t* ent) -> void {
	ent->velocity = {};
	ent->moveInfo.endFunc(ent);
}

static THINK(Move_Final) (gentity_t* ent) -> void {
	if (ent->moveInfo.remainingDistance == 0) {
		Move_Done(ent);
		return;
	}

	// [Paril-KEX] use exact remaining distance
	ent->velocity = (ent->moveInfo.dest - ent->s.origin) * (1.f / gi.frameTimeSec);

	ent->think = Move_Done;
	ent->nextThink = level.time + FRAME_TIME_S;
}

static THINK(Move_Begin) (gentity_t* ent) -> void {
	float frames;

	if ((ent->moveInfo.speed * gi.frameTimeSec) >= ent->moveInfo.remainingDistance) {
		Move_Final(ent);
		return;
	}
	ent->velocity = ent->moveInfo.dir * ent->moveInfo.speed;
	frames = floor((ent->moveInfo.remainingDistance / ent->moveInfo.speed) / gi.frameTimeSec);
	ent->moveInfo.remainingDistance -= frames * ent->moveInfo.speed * gi.frameTimeSec;
	ent->nextThink = level.time + (FRAME_TIME_S * frames);
	ent->think = Move_Final;
}

void Think_AccelMove_New(gentity_t* ent);
void Think_AccelMove(gentity_t* ent);
bool Think_AccelMove_MoveInfo(MoveInfo* moveInfo);

static constexpr float AccelerationDistance(float target, float rate) {
	return (target * ((target / rate) + 1) / 2);
}

static inline void Move_Regular(gentity_t* ent, const Vector3& dest, void(*endFunc)(gentity_t* self)) {
	if (level.currentEntity == ((ent->flags & FL_TEAMSLAVE) ? ent->teamMaster : ent)) {
		Move_Begin(ent);
	}
	else {
		ent->nextThink = level.time + FRAME_TIME_S;
		ent->think = Move_Begin;
	}
}

void Move_Calc(gentity_t* ent, const Vector3& dest, void(*endFunc)(gentity_t* self)) {
	ent->velocity = {};
	ent->moveInfo.dest = dest;
	ent->moveInfo.dir = dest - ent->s.origin;
	ent->moveInfo.remainingDistance = ent->moveInfo.dir.normalize();
	ent->moveInfo.endFunc = endFunc;

	if (ent->moveInfo.speed == ent->moveInfo.accel && ent->moveInfo.speed == ent->moveInfo.decel) {
		Move_Regular(ent, dest, endFunc);
	}
	else {
		// accelerative
		ent->moveInfo.currentSpeed = 0;

		if (gi.tickRate == 10)
			ent->think = Think_AccelMove;
		else {
			// [Paril-KEX] rewritten to work better at higher tickrates
			ent->moveInfo.curveFrame = 0;
			ent->moveInfo.numSubFrames = (0.1f / gi.frameTimeSec) - 1;

			float total_dist = ent->moveInfo.remainingDistance;

			std::vector<float> distances;

			if (ent->moveInfo.numSubFrames) {
				distances.push_back(0);
				ent->moveInfo.curveFrame = 1;
			}
			else
				ent->moveInfo.curveFrame = 0;

			// simulate 10hz movement
			while (ent->moveInfo.remainingDistance) {
				if (!Think_AccelMove_MoveInfo(&ent->moveInfo))
					break;

				ent->moveInfo.remainingDistance -= ent->moveInfo.currentSpeed;
				distances.push_back(total_dist - ent->moveInfo.remainingDistance);
			}

			if (ent->moveInfo.numSubFrames)
				distances.push_back(total_dist);

			ent->moveInfo.subFrame = 0;
			ent->moveInfo.curveRef = ent->s.origin;
			ent->moveInfo.curvePositions = make_savable_memory<float, TAG_LEVEL>(distances.size());
			std::copy(distances.begin(), distances.end(), ent->moveInfo.curvePositions.ptr);

			ent->moveInfo.numFramesDone = 0;

			ent->think = Think_AccelMove_New;
		}

		ent->nextThink = level.time + FRAME_TIME_S;
	}
}

THINK(Think_AccelMove_New) (gentity_t* ent) -> void {
	float t = 0.f;
	float target_dist;

	if (ent->moveInfo.numSubFrames) {
		if (ent->moveInfo.subFrame == ent->moveInfo.numSubFrames + 1) {
			ent->moveInfo.subFrame = 0;
			ent->moveInfo.curveFrame++;

			if (ent->moveInfo.curveFrame == ent->moveInfo.curvePositions.count) {
				Move_Final(ent);
				return;
			}
		}

		t = (ent->moveInfo.subFrame + 1) / ((float)ent->moveInfo.numSubFrames + 1);

		target_dist = lerp(ent->moveInfo.curvePositions[ent->moveInfo.curveFrame - 1], ent->moveInfo.curvePositions[ent->moveInfo.curveFrame], t);
		ent->moveInfo.subFrame++;
	}
	else {
		if (ent->moveInfo.curveFrame == ent->moveInfo.curvePositions.count) {
			Move_Final(ent);
			return;
		}

		target_dist = ent->moveInfo.curvePositions[ent->moveInfo.curveFrame++];
	}

	ent->moveInfo.numFramesDone++;
	Vector3 target_pos = ent->moveInfo.curveRef + (ent->moveInfo.dir * target_dist);
	ent->velocity = (target_pos - ent->s.origin) * (1.f / gi.frameTimeSec);
	ent->nextThink = level.time + FRAME_TIME_S;
}

//
// Support routines for angular movement (changes in angle using aVelocity)
//

static THINK(AngleMove_Done) (gentity_t* ent) -> void {
	ent->aVelocity = {};
	ent->moveInfo.endFunc(ent);
}

static THINK(AngleMove_Final) (gentity_t* ent) -> void {
	Vector3 move;

	if (ent->moveInfo.state == MoveState::Up) {
		if (ent->moveInfo.reversing)
			move = ent->moveInfo.endAnglesReversed - ent->s.angles;
		else
			move = ent->moveInfo.endAngles - ent->s.angles;
	}
	else
		move = ent->moveInfo.startAngles - ent->s.angles;

	if (!move) {
		AngleMove_Done(ent);
		return;
	}

	ent->aVelocity = move * (1.0f / gi.frameTimeSec);

	ent->think = AngleMove_Done;
	ent->nextThink = level.time + FRAME_TIME_S;
}

static THINK(AngleMove_Begin) (gentity_t* ent) -> void {
	Vector3 destdelta;
	float  len;
	float  traveltime;
	float  frames;

	// accelerate as needed
	if (ent->moveInfo.speed < ent->speed) {
		ent->moveInfo.speed += ent->accel;
		if (ent->moveInfo.speed > ent->speed)
			ent->moveInfo.speed = ent->speed;
	}

	// set destdelta to the vector needed to move
	if (ent->moveInfo.state == MoveState::Up) {
		if (ent->moveInfo.reversing)
			destdelta = ent->moveInfo.endAnglesReversed - ent->s.angles;
		else
			destdelta = ent->moveInfo.endAngles - ent->s.angles;
	}
	else
		destdelta = ent->moveInfo.startAngles - ent->s.angles;

	// calculate length of vector
	len = destdelta.length();

	// divide by speed to get time to reach dest
	traveltime = len / ent->moveInfo.speed;

	if (traveltime < gi.frameTimeSec) {
		AngleMove_Final(ent);
		return;
	}

	frames = floor(traveltime / gi.frameTimeSec);

	// scale the destdelta vector by the time spent traveling to get velocity
	ent->aVelocity = destdelta * (1.0f / traveltime);

	//  if we're done accelerating, act as a normal rotation
	if (ent->moveInfo.speed >= ent->speed) {
		// set nextThink to trigger a think when dest is reached
		ent->nextThink = level.time + (FRAME_TIME_S * frames);
		ent->think = AngleMove_Final;
	}
	else {
		ent->nextThink = level.time + FRAME_TIME_S;
		ent->think = AngleMove_Begin;
	}
}

static void AngleMove_Calc(gentity_t* ent, void(*endFunc)(gentity_t* self)) {
	ent->aVelocity = {};
	ent->moveInfo.endFunc = endFunc;

	//  if we're supposed to accelerate, this will tell anglemove_begin to do so
	if (ent->accel != ent->speed)
		ent->moveInfo.speed = 0;

	if (level.currentEntity == ((ent->flags & FL_TEAMSLAVE) ? ent->teamMaster : ent)) {
		AngleMove_Begin(ent);
	}
	else {
		ent->nextThink = level.time + FRAME_TIME_S;
		ent->think = AngleMove_Begin;
	}
}

/*
==============
Think_AccelMove

The team has completed a frame of movement, so
change the speed for the next frame
==============
*/
static void plat_CalcAcceleratedMove(MoveInfo* moveInfo) {
	float accel_dist;
	float decel_dist;

	if (moveInfo->remainingDistance < moveInfo->accel) {
		moveInfo->moveSpeed = moveInfo->speed;
		moveInfo->currentSpeed = moveInfo->remainingDistance;
		return;
	}

	accel_dist = AccelerationDistance(moveInfo->speed, moveInfo->accel);
	decel_dist = AccelerationDistance(moveInfo->speed, moveInfo->decel);

	if ((moveInfo->remainingDistance - accel_dist - decel_dist) < 0) {
		float f;

		f = (moveInfo->accel + moveInfo->decel) / (moveInfo->accel * moveInfo->decel);
		moveInfo->moveSpeed = moveInfo->currentSpeed =
			(-2 + sqrt(4 - 4 * f * (-2 * moveInfo->remainingDistance))) / (2 * f);
		decel_dist = AccelerationDistance(moveInfo->moveSpeed, moveInfo->decel);
	}
	else
		moveInfo->moveSpeed = moveInfo->speed;

	moveInfo->decelDistance = decel_dist;
};

static void plat_Accelerate(MoveInfo* moveInfo) {
	// are we decelerating?
	if (moveInfo->remainingDistance <= moveInfo->decelDistance) {
		if (moveInfo->remainingDistance < moveInfo->decelDistance) {
			if (moveInfo->nextSpeed) {
				moveInfo->currentSpeed = moveInfo->nextSpeed;
				moveInfo->nextSpeed = 0;
				return;
			}
			if (moveInfo->currentSpeed > moveInfo->decel) {
				moveInfo->currentSpeed -= moveInfo->decel;

				// [Paril-KEX] fix platforms in xdm6, etc
				if (std::fabs(moveInfo->currentSpeed) < 0.01f)
					moveInfo->currentSpeed = moveInfo->remainingDistance + 1;
			}
		}
		return;
	}

	// are we at full speed and need to start decelerating during this move?
	if (moveInfo->currentSpeed == moveInfo->moveSpeed)
		if ((moveInfo->remainingDistance - moveInfo->currentSpeed) < moveInfo->decelDistance) {
			float p1_distance;
			float p2_distance;
			float distance;

			p1_distance = moveInfo->remainingDistance - moveInfo->decelDistance;
			p2_distance = moveInfo->moveSpeed * (1.0f - (p1_distance / moveInfo->moveSpeed));
			distance = p1_distance + p2_distance;
			moveInfo->currentSpeed = moveInfo->moveSpeed;
			moveInfo->nextSpeed = moveInfo->moveSpeed - moveInfo->decel * (p2_distance / distance);
			return;
		}

	// are we accelerating?
	if (moveInfo->currentSpeed < moveInfo->speed) {
		float old_speed;
		float p1_distance;
		float p1_speed;
		float p2_distance;
		float distance;

		old_speed = moveInfo->currentSpeed;

		// figure simple acceleration up to moveSpeed
		moveInfo->currentSpeed += moveInfo->accel;
		if (moveInfo->currentSpeed > moveInfo->speed)
			moveInfo->currentSpeed = moveInfo->speed;

		// are we accelerating throughout this entire move?
		if ((moveInfo->remainingDistance - moveInfo->currentSpeed) >= moveInfo->decelDistance)
			return;

		// during this move we will accelerate from currentSpeed to moveSpeed
		// and cross over the decelDistance; figure the average speed for the
		// entire move
		p1_distance = moveInfo->remainingDistance - moveInfo->decelDistance;
		p1_speed = (old_speed + moveInfo->moveSpeed) / 2.0f;
		p2_distance = moveInfo->moveSpeed * (1.0f - (p1_distance / p1_speed));
		distance = p1_distance + p2_distance;
		moveInfo->currentSpeed =
			(p1_speed * (p1_distance / distance)) + (moveInfo->moveSpeed * (p2_distance / distance));
		moveInfo->nextSpeed = moveInfo->moveSpeed - moveInfo->decel * (p2_distance / distance);
		return;
	}

	// we are at constant velocity (moveSpeed)
	return;
}

bool Think_AccelMove_MoveInfo(MoveInfo* moveInfo) {
	if (moveInfo->currentSpeed == 0)		// starting or blocked
		plat_CalcAcceleratedMove(moveInfo);

	plat_Accelerate(moveInfo);

	// will the entire move complete on next frame?
	return moveInfo->remainingDistance > moveInfo->currentSpeed;
}

// Paril: old acceleration code; this is here only to support old save games.
THINK(Think_AccelMove) (gentity_t* ent) -> void {
	// [Paril-KEX] calculate distance dynamically
	if (ent->moveInfo.state == MoveState::Up)
		ent->moveInfo.remainingDistance = (ent->moveInfo.startOrigin - ent->s.origin).length();
	else
		ent->moveInfo.remainingDistance = (ent->moveInfo.endOrigin - ent->s.origin).length();

	// will the entire move complete on next frame?
	if (!Think_AccelMove_MoveInfo(&ent->moveInfo)) {
		Move_Final(ent);
		return;
	}

	if (ent->moveInfo.remainingDistance <= ent->moveInfo.currentSpeed) {
		Move_Final(ent);
		return;
	}

	ent->velocity = ent->moveInfo.dir * (ent->moveInfo.currentSpeed * 10);
	ent->nextThink = level.time + 10_hz;
	ent->think = Think_AccelMove;
}

void plat_go_down(gentity_t* ent);

MOVEINFO_ENDFUNC(plat_hit_top) (gentity_t* ent) -> void {
	if (!(ent->flags & FL_TEAMSLAVE)) {
		if (ent->moveInfo.sound_end)
			gi.sound(ent, CHAN_NO_PHS_ADD | CHAN_VOICE, ent->moveInfo.sound_end, 1, ATTN_STATIC, 0);
	}
	ent->s.sound = 0;
	ent->moveInfo.state = MoveState::Top;

	ent->think = plat_go_down;
	ent->nextThink = level.time + 3_sec;
}

MOVEINFO_ENDFUNC(plat_hit_bottom) (gentity_t* ent) -> void {
	if (!(ent->flags & FL_TEAMSLAVE)) {
		if (ent->moveInfo.sound_end)
			gi.sound(ent, CHAN_NO_PHS_ADD | CHAN_VOICE, ent->moveInfo.sound_end, 1, ATTN_STATIC, 0);
	}
	ent->s.sound = 0;
	ent->moveInfo.state = MoveState::Bottom;

	plat2_kill_danger_area(ent);
}

THINK(plat_go_down) (gentity_t* ent) -> void {
	if (!(ent->flags & FL_TEAMSLAVE)) {
		if (ent->moveInfo.sound_start)
			gi.sound(ent, CHAN_NO_PHS_ADD | CHAN_VOICE, ent->moveInfo.sound_start, 1, ATTN_STATIC, 0);
	}

	ent->s.sound = ent->moveInfo.sound_middle;

	ent->moveInfo.state = MoveState::Down;
	Move_Calc(ent, ent->moveInfo.endOrigin, plat_hit_bottom);
	if (g_mover_debug->integer)
		gi.Com_PrintFmt("Go down {}\n", *ent);
}

static void plat_go_up(gentity_t* ent) {
	if (!(ent->flags & FL_TEAMSLAVE)) {
		if (ent->moveInfo.sound_start)
			gi.sound(ent, CHAN_NO_PHS_ADD | CHAN_VOICE, ent->moveInfo.sound_start, 1, ATTN_STATIC, 0);
	}

	ent->s.sound = ent->moveInfo.sound_middle;

	ent->moveInfo.state = MoveState::Up;
	Move_Calc(ent, ent->moveInfo.startOrigin, plat_hit_top);

	plat2_spawn_danger_area(ent);
	if (g_mover_debug->integer)
		gi.Com_PrintFmt("Go up {}\n", *ent);
}

MOVEINFO_BLOCKED(plat_blocked) (gentity_t* self, gentity_t* other) -> void {
	if (!(other->svFlags & SVF_MONSTER) && (!other->client)) {
		// give it a chance to go away on it's own terms (like gibs)
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, 100000, 1, DamageFlags::Normal, ModID::Crushed);
		// if it's still there, nuke it
		if (other && other->inUse && other->solid)
			BecomeExplosion1(other);
		return;
	}

	//  gib dead things
	if (other->health < 1)
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, 100, 1, DamageFlags::Normal, ModID::Crushed);

	Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, self->dmg, 1, DamageFlags::Normal, ModID::Crushed);

	// [Paril-KEX] killed the thing, so don't switch directions
	if (!other->inUse || !other->solid)
		return;

	if (g_mover_debug->integer)
		gi.Com_PrintFmt("Blocked {} - speed:{} accel:{} decel:{}\n", *self, self->speed, self->accel, self->decel);

	if (self->moveInfo.state == MoveState::Up)
		plat_go_down(self);
	else if (self->moveInfo.state == MoveState::Down)
		plat_go_up(self);
}

constexpr SpawnFlags SPAWNFLAG_PLAT_LOW_TRIGGER = 1_spawnflag;
constexpr SpawnFlags SPAWNFLAG_PLAT_NO_MONSTER = 2_spawnflag;

static USE(Use_Plat) (gentity_t* ent, gentity_t* other, gentity_t* activator) -> void {
	// if a monster is using us, then allow the activity when stopped.
	if ((other->svFlags & SVF_MONSTER) && !(ent->spawnFlags & SPAWNFLAG_PLAT_NO_MONSTER)) {
		if (ent->moveInfo.state == MoveState::Top)
			plat_go_down(ent);
		else if (ent->moveInfo.state == MoveState::Bottom)
			plat_go_up(ent);

		return;
	}

	if (g_mover_debug->integer)
		gi.Com_PrintFmt("Use {}\n", *ent);

	if (ent->think)
		return; // already down
	plat_go_down(ent);
}

static TOUCH(Touch_Plat_Center) (gentity_t* ent, gentity_t* other, const trace_t& tr, bool otherTouchingSelf) -> void {
	if (!other->client)
		return;

	if (other->health <= 0)
		return;

	ent = ent->enemy; // now point at the plat, not the trigger
	if (ent->moveInfo.state == MoveState::Bottom)
		plat_go_up(ent);
	else if (ent->moveInfo.state == MoveState::Top)
		ent->nextThink = level.time + 1_sec; // the player is still on the plat, so delay going down

	if (g_mover_debug->integer)
		gi.Com_PrintFmt("Touch center {} - speed:{} accel:{} decel:{}\n", *ent, ent->speed, ent->accel, ent->decel);
}

// plat2's change the trigger field
gentity_t* plat_spawn_inside_trigger(gentity_t* ent) {
	gentity_t* trigger;
	Vector3	 tmin{}, tmax{};

	//
	// middle trigger
	//
	trigger = Spawn();
	trigger->touch = Touch_Plat_Center;
	trigger->moveType = MoveType::None;
	trigger->solid = SOLID_TRIGGER;
	trigger->enemy = ent;

	tmin[0] = ent->mins[0] + 25;
	tmin[1] = ent->mins[1] + 25;
	tmin[2] = ent->mins[2];

	tmax[0] = ent->maxs[0] - 25;
	tmax[1] = ent->maxs[1] - 25;
	tmax[2] = ent->maxs[2] + 8;

	tmin[2] = tmax[2] - (ent->pos1[2] - ent->pos2[2] + st.lip);

	if (ent->spawnFlags.has(SPAWNFLAG_PLAT_LOW_TRIGGER))
		tmax[2] = tmin[2] + 8;

	if (tmax[0] - tmin[0] <= 0) {
		tmin[0] = (ent->mins[0] + ent->maxs[0]) * 0.5f;
		tmax[0] = tmin[0] + 1;
	}
	if (tmax[1] - tmin[1] <= 0) {
		tmin[1] = (ent->mins[1] + ent->maxs[1]) * 0.5f;
		tmax[1] = tmin[1] + 1;
	}

	trigger->mins = tmin;
	trigger->maxs = tmax;

	gi.linkEntity(trigger);

	return trigger; // PGM 11/17/97
}

/*QUAKED func_plat (0 .5 .8) ? PLAT_LOW_TRIGGER x x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
speed	default 150

Plats are always drawn in the extended position, so they will light correctly.

If the plat is the target of another trigger or button, it will start out disabled in the extended position until it is triggered, when it will lower and become a normal plat.

"speed"			overrides default 200.
"accel"			overrides default 500
"lip"			overrides default 8 pixel lip
"height"		overrides the implicit height determined by the model's height.
"wait"			overrides default 3 seconds
"noise_start"	overrides default "plats/pt1_strt.wav"
"noise_middle"	overrides default "plats/pt1_mid.wav"
"noise_end"		overrides default "plats/pt1_end.wav"

Set "sounds" to one of the following:
1) base fast
2) chain slow
*/
void SP_func_plat(gentity_t* ent) {
	ent->s.angles = {};
	ent->solid = SOLID_BSP;
	ent->moveType = MoveType::Push;

	gi.setModel(ent, ent->model);

	ent->moveInfo.blocked = plat_blocked;

	if (!ent->speed)
		ent->speed = 20;
	else
		ent->speed *= 0.1f;

	if (!ent->accel)
		ent->accel = 5;
	else
		ent->accel *= 0.1f;

	if (!ent->decel)
		ent->decel = 5;
	else
		ent->decel *= 0.1f;
#if 0
	if (g_mover_speed_scale->value != 1.0f) {
		ent->speed = floor(ent->speed * g_mover_speed_scale->value);
		ent->accel = floor(ent->accel * g_mover_speed_scale->value);
		ent->decel = floor(ent->decel * g_mover_speed_scale->value);
	}
#endif
	if (g_mover_debug->integer)
		gi.Com_PrintFmt("Spawning {} - speed:{} accel:{} decel:{}\n", *ent, ent->speed, ent->accel, ent->decel);

	if (!ent->dmg)
		ent->dmg = 2;

	if (!st.lip)
		st.lip = 8;

	// pos1 is the top position, pos2 is the bottom
	ent->pos1 = ent->s.origin;
	ent->pos2 = ent->s.origin;
	if (st.height)
		ent->pos2[2] -= st.height;
	else
		ent->pos2[2] -= (ent->maxs[2] - ent->mins[2]) - st.lip;

	ent->use = Use_Plat;

	plat_spawn_inside_trigger(ent); // the "start moving" trigger

	if (ent->targetName) {
		ent->moveInfo.state = MoveState::Up;
	}
	else {
		ent->s.origin = ent->pos2;
		gi.linkEntity(ent);
		ent->moveInfo.state = MoveState::Bottom;
	}

	ent->moveInfo.speed = ent->speed;
	ent->moveInfo.accel = ent->accel;
	ent->moveInfo.decel = ent->decel;
	ent->moveInfo.wait = ent->wait;
	ent->moveInfo.startOrigin = ent->pos1;
	ent->moveInfo.startAngles = ent->s.angles;
	ent->moveInfo.endOrigin = ent->pos2;
	ent->moveInfo.endAngles = ent->s.angles;

	G_SetMoveinfoSounds(ent, "plats/pt1_strt.wav", "plats/pt1_mid.wav", "plats/pt1_end.wav");
}

/*QUAKED func_plat2 (0 .5 .8) ? PLAT_LOW_TRIGGER PLAT2_TOGGLE PLAT2_TOP PLAT2_START_ACTIVE x BOX_LIFT x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
speed	default 150

PLAT_LOW_TRIGGER - creates a short trigger field at the bottom
PLAT2_TOGGLE - plat will not return to default position.
PLAT2_TOP - plat's default position will the the top.
PLAT2_START_ACTIVE - plat will trigger it's targets each time it hits top
BOX_LIFT - this indicates that the lift is a box, rather than just a platform

Plats are always drawn in the extended position, so they will light correctly.

If the plat is the target of another trigger or button, it will start out disabled in the extended position until it is trigger, when it will lower and become a normal plat.

"speed"	overrides default 200.
"accel" overrides default 500
"lip"	no default
"height" overrides the implicit height determined by the model's height.
"wait"	overrides default 3 seconds
"noise_start" overrides default "plats/pt1_strt.wav"
"noise_middle" overrides default "plats/pt1_mid.wav"
"noise_end" overrides default "plats/pt1_end.wav"
*/

constexpr SpawnFlags SPAWNFLAGS_PLAT2_TOGGLE = 2_spawnflag;
constexpr SpawnFlags SPAWNFLAGS_PLAT2_TOP = 4_spawnflag;
constexpr SpawnFlags SPAWNFLAGS_PLAT2_START_ACTIVE = 8_spawnflag;
constexpr SpawnFlags SPAWNFLAGS_PLAT2_BOX_LIFT = 32_spawnflag;

void plat2_go_down(gentity_t* ent);
void plat2_go_up(gentity_t* ent);

void plat2_spawn_danger_area(gentity_t* ent) {
	Vector3 mins, maxs;

	mins = ent->mins;
	maxs = ent->maxs;
	maxs[2] = ent->mins[2] + 64;

	SpawnBadArea(mins, maxs, 0_ms, ent);
}

void plat2_kill_danger_area(gentity_t* ent) {
	gentity_t* t = nullptr;

	while ((t = G_FindByString<&gentity_t::className>(t, "bad_area"))) {
		if (t->owner == ent)
			FreeEntity(t);
	}
}

MOVEINFO_ENDFUNC(plat2_hit_top) (gentity_t* ent) -> void {
	if (!(ent->flags & FL_TEAMSLAVE)) {
		if (ent->moveInfo.sound_end)
			gi.sound(ent, CHAN_NO_PHS_ADD | CHAN_VOICE, ent->moveInfo.sound_end, 1, ATTN_STATIC, 0);
	}
	ent->s.sound = 0;
	ent->moveInfo.state = MoveState::Top;

	if (ent->plat2flags & PLAT2_CALLED) {
		ent->plat2flags = PLAT2_WAITING;
		if (!ent->spawnFlags.has(SPAWNFLAGS_PLAT2_TOGGLE)) {
			ent->think = plat2_go_down;
			ent->nextThink = level.time + 5_sec;
		}
		if (deathmatch->integer)
			ent->last_move_time = level.time - 1_sec;
		else
			ent->last_move_time = level.time - 2_sec;
	}
	else if (!(ent->spawnFlags & SPAWNFLAGS_PLAT2_TOP) && !ent->spawnFlags.has(SPAWNFLAGS_PLAT2_TOGGLE)) {
		ent->plat2flags = PLAT2_NONE;
		ent->think = plat2_go_down;
		ent->nextThink = level.time + 2_sec;
		ent->last_move_time = level.time;
	}
	else {
		ent->plat2flags = PLAT2_NONE;
		ent->last_move_time = level.time;
	}

	UseTargets(ent, ent);
}

MOVEINFO_ENDFUNC(plat2_hit_bottom) (gentity_t* ent) -> void {
	if (!(ent->flags & FL_TEAMSLAVE)) {
		if (ent->moveInfo.sound_end)
			gi.sound(ent, CHAN_NO_PHS_ADD | CHAN_VOICE, ent->moveInfo.sound_end, 1, ATTN_STATIC, 0);
	}
	ent->s.sound = 0;
	ent->moveInfo.state = MoveState::Bottom;

	if (ent->plat2flags & PLAT2_CALLED) {
		ent->plat2flags = PLAT2_WAITING;
		if (!(ent->spawnFlags & SPAWNFLAGS_PLAT2_TOGGLE)) {
			ent->think = plat2_go_up;
			ent->nextThink = level.time + 5_sec;
		}
		if (deathmatch->integer)
			ent->last_move_time = level.time - 1_sec;
		else
			ent->last_move_time = level.time - 2_sec;
	}
	else if (ent->spawnFlags.has(SPAWNFLAGS_PLAT2_TOP) && !ent->spawnFlags.has(SPAWNFLAGS_PLAT2_TOGGLE)) {
		ent->plat2flags = PLAT2_NONE;
		ent->think = plat2_go_up;
		ent->nextThink = level.time + 2_sec;
		ent->last_move_time = level.time;
	}
	else {
		ent->plat2flags = PLAT2_NONE;
		ent->last_move_time = level.time;
	}

	plat2_kill_danger_area(ent);
	UseTargets(ent, ent);
}

THINK(plat2_go_down) (gentity_t* ent) -> void {
	if (!(ent->flags & FL_TEAMSLAVE)) {
		if (ent->moveInfo.sound_start)
			gi.sound(ent, CHAN_NO_PHS_ADD | CHAN_VOICE, ent->moveInfo.sound_start, 1, ATTN_STATIC, 0);
	}

	ent->s.sound = ent->moveInfo.sound_middle;

	ent->moveInfo.state = MoveState::Down;
	ent->plat2flags |= PLAT2_MOVING;

	Move_Calc(ent, ent->moveInfo.endOrigin, plat2_hit_bottom);
}

THINK(plat2_go_up) (gentity_t* ent) -> void {
	if (!(ent->flags & FL_TEAMSLAVE)) {
		if (ent->moveInfo.sound_start)
			gi.sound(ent, CHAN_NO_PHS_ADD | CHAN_VOICE, ent->moveInfo.sound_start, 1, ATTN_STATIC, 0);
	}

	ent->s.sound = ent->moveInfo.sound_middle;

	ent->moveInfo.state = MoveState::Up;
	ent->plat2flags |= PLAT2_MOVING;

	plat2_spawn_danger_area(ent);

	Move_Calc(ent, ent->moveInfo.startOrigin, plat2_hit_top);
}

static void plat2_operate(gentity_t* ent, gentity_t* other) {
	MoveState	otherState;
	GameTime		pauseTime;
	float		platCenter;
	gentity_t* trigger;

	trigger = ent;
	ent = ent->enemy; // now point at the plat, not the trigger

	if (ent->plat2flags & PLAT2_MOVING)
		return;

	if ((ent->last_move_time + 2_sec) > level.time)
		return;

	platCenter = (trigger->absMin[2] + trigger->absMax[2]) / 2;

	if (ent->moveInfo.state == MoveState::Top) {
		otherState = MoveState::Top;
		if (ent->spawnFlags.has(SPAWNFLAGS_PLAT2_BOX_LIFT)) {
			if (platCenter > other->s.origin[_Z])
				otherState = MoveState::Bottom;
		}
		else {
			if (trigger->absMax[2] > other->s.origin[_Z])
				otherState = MoveState::Bottom;
		}
	}
	else {
		otherState = MoveState::Bottom;
		if (other->s.origin[_Z] > platCenter)
			otherState = MoveState::Top;
	}

	ent->plat2flags = PLAT2_MOVING;

	if (deathmatch->integer)
		pauseTime = 300_ms;
	else
		pauseTime = 500_ms;

	if (ent->moveInfo.state != otherState) {
		ent->plat2flags |= PLAT2_CALLED;
		pauseTime = 100_ms;
	}

	ent->last_move_time = level.time;

	if (ent->moveInfo.state == MoveState::Bottom) {
		ent->think = plat2_go_up;
		ent->nextThink = level.time + pauseTime;
	}
	else {
		ent->think = plat2_go_down;
		ent->nextThink = level.time + pauseTime;
	}
}

static TOUCH(Touch_Plat_Center2) (gentity_t* ent, gentity_t* other, const trace_t& tr, bool otherTouchingSelf) -> void {
	// this requires monsters to actively trigger plats, not just step on them.

	// FIXME - commented out for E3
	// if (!other->client)
	//	return;

	if (other->health <= 0)
		return;

	// PMM - don't let non-monsters activate plat2s
	if ((!(other->svFlags & SVF_MONSTER)) && (!other->client))
		return;

	plat2_operate(ent, other);
}

MOVEINFO_BLOCKED(plat2_blocked) (gentity_t* self, gentity_t* other) -> void {
	if (!(other->svFlags & SVF_MONSTER) && (!other->client)) {
		// give it a chance to go away on it's own terms (like gibs)
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, 100000, 1, DamageFlags::Normal, ModID::Crushed);
		// if it's still there, nuke it
		if (other && other->inUse && other->solid)
			BecomeExplosion1(other);
		return;
	}

	// gib dead things
	if (other->health < 1) {
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, 100, 1, DamageFlags::Normal, ModID::Crushed);
	}

	Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, self->dmg, 1, DamageFlags::Normal, ModID::Crushed);

	// [Paril-KEX] killed, so don't change direction
	if (!other->inUse || !other->solid)
		return;

	if (self->moveInfo.state == MoveState::Up)
		plat2_go_down(self);
	else if (self->moveInfo.state == MoveState::Down)
		plat2_go_up(self);
}

static USE(Use_Plat2) (gentity_t* ent, gentity_t* other, gentity_t* activator) -> void {
	gentity_t* trigger;

	if (ent->moveInfo.state > MoveState::Bottom)
		return;
	// [Paril-KEX] disabled this; causes confusing situations
	//if ((ent->last_move_time + 2_sec) > level.time)
	//	return;

	uint32_t i;
	for (i = 1, trigger = g_entities + 1; i < globals.numEntities; i++, trigger++) {
		if (!trigger->inUse)
			continue;
		if (trigger->touch == Touch_Plat_Center2) {
			if (trigger->enemy == ent) {
				//				Touch_Plat_Center2 (trigger, activator, nullptr, nullptr);
				plat2_operate(trigger, activator);
				return;
			}
		}
	}
}

static USE(plat2_activate) (gentity_t* ent, gentity_t* other, gentity_t* activator) -> void {
	gentity_t* trigger;

	//	if(ent->targetName)
	//		ent->targetName[0] = 0;

	ent->use = Use_Plat2;

	trigger = plat_spawn_inside_trigger(ent); // the "start moving" trigger

	trigger->maxs[0] += 10;
	trigger->maxs[1] += 10;
	trigger->mins[0] -= 10;
	trigger->mins[1] -= 10;

	gi.linkEntity(trigger);

	trigger->touch = Touch_Plat_Center2; // Override trigger touch function

	plat2_go_down(ent);
}

void SP_func_plat2(gentity_t* ent) {
	gentity_t* trigger;

	ent->s.angles = {};
	ent->solid = SOLID_BSP;
	ent->moveType = MoveType::Push;

	gi.setModel(ent, ent->model);

	ent->moveInfo.blocked = plat2_blocked;

	if (!ent->speed)
		ent->speed = 20;
	else
		ent->speed *= 0.1f;

	if (!ent->accel)
		ent->accel = 5;
	else
		ent->accel *= 0.1f;

	if (!ent->decel)
		ent->decel = 5;
	else
		ent->decel *= 0.1f;

	if (deathmatch->integer) {
		ent->speed *= 2;
		ent->accel *= 2;
		ent->decel *= 2;
	}

	if (g_mover_speed_scale->value != 1.0f) {
		ent->speed *= g_mover_speed_scale->value;
		ent->accel *= g_mover_speed_scale->value;
		ent->decel *= g_mover_speed_scale->value;
	}

	// PMM Added to kill things it's being blocked by
	if (!ent->dmg)
		ent->dmg = 2;

	//	if (!st.lip)
	//		st.lip = 8;

	// pos1 is the top position, pos2 is the bottom
	ent->pos1 = ent->s.origin;
	ent->pos2 = ent->s.origin;

	if (st.height)
		ent->pos2[2] -= (st.height - st.lip);
	else
		ent->pos2[2] -= (ent->maxs[2] - ent->mins[2]) - st.lip;

	ent->moveInfo.state = MoveState::Top;

	if (ent->targetName && !(ent->spawnFlags & SPAWNFLAGS_PLAT2_START_ACTIVE)) {
		ent->use = plat2_activate;
	}
	else {
		ent->use = Use_Plat2;

		trigger = plat_spawn_inside_trigger(ent); // the "start moving" trigger

		// PGM - debugging??
		trigger->maxs[0] += 10;
		trigger->maxs[1] += 10;
		trigger->mins[0] -= 10;
		trigger->mins[1] -= 10;

		gi.linkEntity(trigger);

		trigger->touch = Touch_Plat_Center2; // Override trigger touch function

		if (!(ent->spawnFlags & SPAWNFLAGS_PLAT2_TOP)) {
			ent->s.origin = ent->pos2;
			ent->moveInfo.state = MoveState::Bottom;
		}
	}

	gi.linkEntity(ent);

	ent->moveInfo.speed = ent->speed;
	ent->moveInfo.accel = ent->accel;
	ent->moveInfo.decel = ent->decel;
	ent->moveInfo.wait = ent->wait;
	ent->moveInfo.startOrigin = ent->pos1;
	ent->moveInfo.startAngles = ent->s.angles;
	ent->moveInfo.endOrigin = ent->pos2;
	ent->moveInfo.endAngles = ent->s.angles;

	G_SetMoveinfoSounds(ent, "plats/pt1_strt.wav", "plats/pt1_mid.wav", "plats/pt1_end.wav");
}


//====================================================================

/*QUAKED func_rotating (0 .5 .8) ? START_ON REVERSE X_AXIS Y_AXIS TOUCH_PAIN STOP ANIMATED ANIMATED_FAST NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP x COOP_ONLY x ACCEL
You need to have an origin brush as part of this entity.
The center of that brush will be the point around which it is rotated. It will rotate around the Z axis by default.
You can check either the X_AXIS or Y_AXIS box to change that.

func_rotating will use it's targets when it stops and starts.

"speed" determines how fast it moves; default value is 100.
"dmg"	damage to inflict when blocked (2 default)
"accel" if specified, is how much the rotation speed will increase per .1sec.
"decel" if specified, is how much the rotation speed will decrease per .1sec.
"noise" is the sound it makes when rotating (default is none).

REVERSE will cause the it to rotate in the opposite direction.
STOP mean it will stop moving instead of pushing entities
ACCEL means it will accelerate to it's final speed and decelerate when shutting down.
*/

// Paril: Rogue added a spawnflag in func_rotating that
// is a reserved editor flag.
constexpr SpawnFlags SPAWNFLAG_ROTATING_START_ON = 1_spawnflag;
constexpr SpawnFlags SPAWNFLAG_ROTATING_REVERSE = 2_spawnflag;
constexpr SpawnFlags SPAWNFLAG_ROTATING_X_AXIS = 4_spawnflag;
constexpr SpawnFlags SPAWNFLAG_ROTATING_Y_AXIS = 8_spawnflag;
constexpr SpawnFlags SPAWNFLAG_ROTATING_TOUCH_PAIN = 16_spawnflag;
constexpr SpawnFlags SPAWNFLAG_ROTATING_STOP = 32_spawnflag;
constexpr SpawnFlags SPAWNFLAG_ROTATING_ANIMATED = 64_spawnflag;
constexpr SpawnFlags SPAWNFLAG_ROTATING_ANIMATED_FAST = 128_spawnflag;
constexpr SpawnFlags SPAWNFLAG_ROTATING_ACCEL = 0x00010000_spawnflag;

static THINK(rotating_accel) (gentity_t* self) -> void {
	float currentSpeed = self->aVelocity.length();
	if (currentSpeed >= (self->speed - self->accel)) { // done
		self->aVelocity = self->moveDir * self->speed;
		UseTargets(self, self);
	}
	else {
		currentSpeed += self->accel;
		self->aVelocity = self->moveDir * currentSpeed;
		self->think = rotating_accel;
		self->nextThink = level.time + FRAME_TIME_S;
	}
}

static THINK(rotating_decel) (gentity_t* self) -> void {
	float currentSpeed = self->aVelocity.length();
	if (currentSpeed <= self->decel) { // done
		self->aVelocity = {};
		UseTargets(self, self);
		self->touch = nullptr;
	}
	else {
		currentSpeed -= self->decel;
		self->aVelocity = self->moveDir * currentSpeed;
		self->think = rotating_decel;
		self->nextThink = level.time + FRAME_TIME_S;
	}
}

MOVEINFO_BLOCKED(rotating_blocked) (gentity_t* self, gentity_t* other) -> void {
	if (!self->dmg)
		return;
	if (level.time < self->touch_debounce_time)
		return;

	if (!(other->svFlags & SVF_MONSTER) && (!other->client)) {
		// give it a chance to go away on it's own terms (like gibs)
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, 100000, 1, DamageFlags::Normal, ModID::Crushed);
		// if it's still there, nuke it
		if (other && other->inUse && other->solid)
			BecomeExplosion1(other);
		return;
	}

	self->touch_debounce_time = level.time + 10_hz;
	Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, self->dmg, 1, DamageFlags::Normal, ModID::Crushed);
}

static TOUCH(rotating_touch) (gentity_t* self, gentity_t* other, const trace_t& tr, bool otherTouchingSelf) -> void {
	if (self->aVelocity[0] || self->aVelocity[1] || self->aVelocity[2])
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, self->dmg, 1, DamageFlags::Normal, ModID::Crushed);
}

static USE(rotating_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	if (self->aVelocity) {
		self->s.sound = 0;

		if (self->spawnFlags.has(SPAWNFLAG_ROTATING_ACCEL)) // Decelerate
			rotating_decel(self);
		else {
			self->aVelocity = {};
			UseTargets(self, self);
			self->touch = nullptr;
		}
	}
	else {
		self->s.sound = self->moveInfo.sound_middle;

		if (self->spawnFlags.has(SPAWNFLAG_ROTATING_ACCEL)) // accelerate
			rotating_accel(self);
		else {
			self->aVelocity = self->moveDir * self->speed;
			UseTargets(self, self);
		}
		if (self->spawnFlags.has(SPAWNFLAG_ROTATING_TOUCH_PAIN))
			self->touch = rotating_touch;
	}
}

void SP_func_rotating(gentity_t* ent) {
	ent->solid = SOLID_BSP;
	if (ent->spawnFlags.has(SPAWNFLAG_ROTATING_STOP))
		ent->moveType = MoveType::Stop;
	else
		ent->moveType = MoveType::Push;

	if (st.noise) {
		ent->moveInfo.sound_middle = gi.soundIndex(st.noise);

		// [Paril-KEX] for rhangar1 doors
		if (!st.was_key_specified("attenuation"))
			ent->attenuation = ATTN_STATIC;
		else {
			if (ent->attenuation == -1) {
				ent->s.loopAttenuation = ATTN_LOOP_NONE;
				ent->attenuation = ATTN_NONE;
			}
			else {
				ent->s.loopAttenuation = ent->attenuation;
			}
		}
	}

	// set the axis of rotation
	ent->moveDir = {};
	if (ent->spawnFlags.has(SPAWNFLAG_ROTATING_X_AXIS))
		ent->moveDir[2] = 1.0;
	else if (ent->spawnFlags.has(SPAWNFLAG_ROTATING_Y_AXIS))
		ent->moveDir[0] = 1.0;
	else // Z_AXIS
		ent->moveDir[1] = 1.0;

	// check for reverse rotation
	if (ent->spawnFlags.has(SPAWNFLAG_ROTATING_REVERSE))
		ent->moveDir = -ent->moveDir;

	if (!ent->speed)
		ent->speed = 100;

	if (g_mover_speed_scale->value != 1.0f) {
		ent->speed *= g_mover_speed_scale->value;
		ent->accel *= g_mover_speed_scale->value;
		ent->decel *= g_mover_speed_scale->value;
	}

	if (!st.was_key_specified("dmg"))
		ent->dmg = 2;

	ent->use = rotating_use;
	if (ent->dmg)
		ent->moveInfo.blocked = rotating_blocked;

	if (ent->spawnFlags.has(SPAWNFLAG_ROTATING_START_ON))
		ent->use(ent, nullptr, nullptr);

	if (ent->spawnFlags.has(SPAWNFLAG_ROTATING_ANIMATED))
		ent->s.effects |= EF_ANIM_ALL;
	if (ent->spawnFlags.has(SPAWNFLAG_ROTATING_ANIMATED_FAST))
		ent->s.effects |= EF_ANIM_ALLFAST;

	if (ent->spawnFlags.has(SPAWNFLAG_ROTATING_ACCEL)) // Accelerate / Decelerate
	{
		if (!ent->accel)
			ent->accel = 1;
		else if (ent->accel > ent->speed)
			ent->accel = ent->speed;

		if (!ent->decel)
			ent->decel = 1;
		else if (ent->decel > ent->speed)
			ent->decel = ent->speed;
	}

	gi.setModel(ent, ent->model);
	gi.linkEntity(ent);
}

// This entire block of code should be added to g_func.cpp

//====================================================================
// FUNC_ROTATING_EXT (Advanced Rotating Brush)
//====================================================================

// Spawnflags for the new extended rotating entity
constexpr SpawnFlags SPAWNFLAG_ROTATING_EXT_START_ON = 1_spawnflag;
constexpr SpawnFlags SPAWNFLAG_ROTATING_EXT_TOUCH_PAIN = 2_spawnflag;
constexpr SpawnFlags SPAWNFLAG_ROTATING_EXT_LOOP = 4_spawnflag;
// Note: ANIMATED and ANIMATED_FAST flags are handled by the original func_rotating definitions

// Forward declaration for the end function
void rotating_ext_done(gentity_t* self);

/**
 * @brief Think function for looping a partial 'mangle' rotation.
 */
static THINK(rotating_ext_loop_wait) (gentity_t* self) -> void {
	// Reset to start and begin the rotation again
	self->s.angles = self->moveInfo.startAngles;
	self->moveInfo.state = MoveState::Bottom;
	AngleMove_Calc(self, rotating_ext_done);
}

/**
 * @brief End function called when a partial 'mangle' rotation completes.
 */
MOVEINFO_ENDFUNC(rotating_ext_done) (gentity_t* self) -> void {
	// Update state to reflect completion
	self->moveInfo.state = (self->moveInfo.state == MoveState::Up) ? MoveState::Top : MoveState::Bottom;

	UseTargets(self, self);

	// If looping is enabled, wait and then restart the rotation
	if (self->spawnFlags.has(SPAWNFLAG_ROTATING_EXT_LOOP)) {
		self->think = rotating_ext_loop_wait;
		self->nextThink = level.time + GameTime::from_sec(self->wait);
	}
}

/**
 * @brief The 'use' function for the extended rotating entity.
 */
static USE(rotating_ext_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	self->activator = activator;

	// Case 1: Partial rotation ('mangle' mode)
	if (self->plat2flags & PLAT2_MOVING) {
		if (self->moveInfo.state == MoveState::Bottom) {
			self->moveInfo.state = MoveState::Up;
			AngleMove_Calc(self, rotating_ext_done);
		}
		else if (self->moveInfo.state == MoveState::Top) {
			self->moveInfo.state = MoveState::Down;
			AngleMove_Calc(self, rotating_ext_done);
		}
		return;
	}

	// Case 2: Continuous rotation ('speeds' mode)
	if (self->aVelocity) { // Is rotating, so stop
		self->s.sound = 0;
		if (self->accel)
			rotating_decel(self); // Re-use legacy decel logic
		else {
			self->aVelocity = {};
			UseTargets(self, self);
			self->touch = nullptr;
		}
	}
	else { // Is stopped, so start
		self->s.sound = self->moveInfo.sound_middle;
		if (self->accel)
			rotating_accel(self); // Re-use legacy accel logic
		else {
			self->aVelocity = self->moveDir; // moveDir stores the 'speeds' vector
			UseTargets(self, self);
		}

		if (self->spawnFlags.has(SPAWNFLAG_ROTATING_EXT_TOUCH_PAIN))
			self->touch = rotating_touch;
	}
}


/*QUAKED func_rotating_ext (0 .5 .8) ? START_ON TOUCH_PAIN LOOP ANIMATED ANIMATED_FAST NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP x COOP_ONLY x ACCEL
An advanced rotating brush entity that supports complex rotation types.
You must include an origin brush with the group; its center will serve as the point of rotation for the entire entity.

This entity supports two main modes:
1. Continuous Rotation: Set with the "speeds" key for constant rotation on multiple axes.
2. Partial Rotation: Set with the "mangle" key to rotate to a specific target angle and stop.

START_ON: Starts rotating immediately upon spawning.
TOUCH_PAIN: Damages entities it collides with while rotating.
LOOP: Used with "mangle" to repeat the partial rotation indefinitely. The "wait" key defines the pause between loops.
ANIMATED: The brush model will cycle through its animation frames.
ANIMATED_FAST: The brush model will cycle frames at a faster rate.

"mangle"      Takes x y z values for a target angle. When triggered, the entity rotates to this angle and stops. If the LOOP flag is set, it resets and repeats this rotation after 'wait' seconds.
"speeds"      Takes x y z values for continuous rotation speeds (degrees per second) on each axis.
"duration"    Used with "mangle" to specify the number of seconds to complete the rotation. Overrides the "speed" value.
"durations"   Used with "mangle", takes x y z values for per-axis rotation times. The longest of the three values will be used as the travel time. Overridden by "duration".
"speed"       Default rotation speed (100). Used to calculate duration for a "mangle" move if "duration" is not set.
"dmg"         Damage to inflict when blocked or touched (default 2).
"accel"       Acceleration speed. The entity will accelerate to its target speed. Works with both continuous and partial rotation.
"decel"       Deceleration speed. The entity will decelerate to a stop.
"wait"        Time in seconds to wait between rotations when "mangle" and "LOOP" are used.
"noise"       Looping sound to play while the entity is rotating.
*/
void SP_func_rotating_ext(gentity_t* ent) {
	// --- Common Setup ---
	ent->solid = SOLID_BSP;
	ent->moveType = MoveType::Push;
	if (st.noise) {
		ent->moveInfo.sound_middle = gi.soundIndex(st.noise);
		if (!st.was_key_specified("attenuation")) ent->attenuation = ATTN_STATIC;
		else if (ent->attenuation == -1) ent->attenuation = ATTN_LOOP_NONE;
		ent->s.loopAttenuation = ent->attenuation;
	}

	if (!ent->speed) ent->speed = 100;
	if (!st.was_key_specified("dmg")) ent->dmg = 2;

	if (g_mover_speed_scale->value != 1.0f) {
		ent->speed *= g_mover_speed_scale->value;
		ent->accel *= g_mover_speed_scale->value;
		ent->decel *= g_mover_speed_scale->value;
	}

	ent->use = rotating_ext_use;
	if (ent->dmg) ent->moveInfo.blocked = rotating_blocked; // Reuse from legacy

	// --- Advanced Mode Logic ---
	if (st.was_key_specified("speeds") || ent->moveOrigin) {
		ent->moveDir = ent->moveOrigin; // Store 'speeds' vector in moveDir
		ent->speed = ent->moveOrigin.length();
	}
	else if (st.was_key_specified("mangle") || ent->mangle) {
		ent->moveInfo.startAngles = ent->s.angles;
		ent->moveInfo.endAngles = ent->s.angles + ent->mangle;
		ent->moveInfo.state = MoveState::Bottom;
		ent->plat2flags = PLAT2_MOVING; // Use a spare flag to signify mangle mode

		float travel_time = 0.f;
		if (ent->duration > 0) {
			travel_time = ent->duration;
		}
		else if (ent->durations) { // Use max component of 'durations' vector
			travel_time = std::max({ ent->durations.x, ent->durations.y, ent->durations.z });
		}

		if (travel_time > 0) {
			float angle_delta = (ent->moveInfo.endAngles - ent->moveInfo.startAngles).length();
			if (angle_delta > 0) ent->speed = angle_delta / travel_time;
		}
	}
	else {
		gi.Com_PrintFmt("{}: needs 'speeds' or 'mangle' key.\n", *ent);
		FreeEntity(ent);
		return;
	}

	if (st.was_key_specified("accel")) ent->accel = st.accel;
	if (st.was_key_specified("decel")) ent->decel = st.decel;

	if (ent->spawnFlags.has(SPAWNFLAG_ROTATING_EXT_START_ON))
		ent->use(ent, nullptr, nullptr);

	if (ent->spawnFlags.has(SPAWNFLAG_ROTATING_ANIMATED))
		ent->s.effects |= EF_ANIM_ALL;
	if (ent->spawnFlags.has(SPAWNFLAG_ROTATING_ANIMATED_FAST))
		ent->s.effects |= EF_ANIM_ALLFAST;

	gi.setModel(ent, ent->model);
	gi.linkEntity(ent);
}

/*QUAKED func_spinning (0 .5 .8) ? x x x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
Randomly spinning object, not controllable.

"speed" set speed of rotation (default 100)
"dmg" set damage inflicted when blocked (default 2)
"accel" set acceleration of rotation (default 1)
"decel" set deceleration of rotation (default 1)
"noise" set sound made when spinning (default none)
*/
static THINK(func_spinning_think) (gentity_t* ent) -> void {
	if (ent->timeStamp <= level.time) {
		ent->timeStamp = level.time + random_time(1_sec, 6_sec);
		ent->moveDir = { ent->decel + frandom(ent->speed - ent->decel), ent->decel + frandom(ent->speed - ent->decel), ent->decel + frandom(ent->speed - ent->decel) };

		for (size_t i = 0; i < 3; i++) {
			if (brandom())
				ent->moveDir[i] = -ent->moveDir[i];
		}
	}

	for (size_t i = 0; i < 3; i++) {
		if (ent->aVelocity[i] == ent->moveDir[i])
			continue;

		if (ent->aVelocity[i] < ent->moveDir[i])
			ent->aVelocity[i] = min(ent->moveDir[i], ent->aVelocity[i] + ent->accel);
		else
			ent->aVelocity[i] = max(ent->moveDir[i], ent->aVelocity[i] - ent->accel);
	}

	ent->nextThink = level.time + FRAME_TIME_MS;
}

// [Paril-KEX]
void SP_func_spinning(gentity_t* ent) {
	ent->solid = SOLID_BSP;

	if (!ent->speed)
		ent->speed = 100;
	if (!ent->dmg)
		ent->dmg = 2;

	ent->moveType = MoveType::Push;

	ent->timeStamp = 0_ms;
	ent->nextThink = level.time + FRAME_TIME_MS;
	ent->think = func_spinning_think;

	gi.setModel(ent, ent->model);
	gi.linkEntity(ent);
}

/*
======================================================================

BUTTONS

======================================================================
*/

/*QUAKED func_button (0 .5 .8) ? x x x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
When a button is touched, it moves some distance in the direction of it's angle, triggers all of it's targets, waits some time, then returns to it's original position where it can be triggered again.

"angle"		determines the opening direction
"target"	all entities with a matching targetName will be used
"speed"		override the default 40 speed
"wait"		override the default 1 second wait (-1 = never return)
"lip"		override the default 4 pixel lip remaining at end of move
"health"	if set, the button must be killed instead of touched

"sounds"
1) silent
2) steam metal
3) wooden clunk
4) metallic click
5) in-out
*/

MOVEINFO_ENDFUNC(button_done) (gentity_t* self) -> void {
	self->moveInfo.state = MoveState::Bottom;
	if (!self->bmodel_anim.enabled) {
		if (level.isN64)
			self->s.frame = 0;
		else
			self->s.effects &= ~EF_ANIM23;
		self->s.effects |= EF_ANIM01;
	}
	else
		self->bmodel_anim.alternate = false;
}

static THINK(button_return) (gentity_t* self) -> void {
	self->moveInfo.state = MoveState::Down;

	Move_Calc(self, self->moveInfo.startOrigin, button_done);

	if (self->health)
		self->takeDamage = true;
}

MOVEINFO_ENDFUNC(button_wait) (gentity_t* self) -> void {
	self->moveInfo.state = MoveState::Top;

	if (!self->bmodel_anim.enabled) {
		self->s.effects &= ~EF_ANIM01;
		if (level.isN64)
			self->s.frame = 2;
		else
			self->s.effects |= EF_ANIM23;
	}
	else
		self->bmodel_anim.alternate = true;

	UseTargets(self, self->activator);

	if (self->moveInfo.wait >= 0) {
		self->nextThink = level.time + GameTime::from_sec(self->moveInfo.wait);
		self->think = button_return;
	}
}

static void button_fire(gentity_t* self) {
	if (self->moveInfo.state == MoveState::Up || self->moveInfo.state == MoveState::Top)
		return;

	self->moveInfo.state = MoveState::Up;
	if (self->moveInfo.sound_start && !(self->flags & FL_TEAMSLAVE))
		gi.sound(self, CHAN_NO_PHS_ADD | CHAN_VOICE, self->moveInfo.sound_start, 1, ATTN_STATIC, 0);
	Move_Calc(self, self->moveInfo.endOrigin, button_wait);
}

static USE(button_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	self->activator = activator;
	button_fire(self);
}

static TOUCH(button_touch) (gentity_t* self, gentity_t* other, const trace_t& tr, bool otherTouchingSelf) -> void {
	if (!other->client)
		return;

	if (other->health <= 0)
		return;

	self->activator = other;
	button_fire(self);
}

static DIE(button_killed) (gentity_t* self, gentity_t* inflictor, gentity_t* attacker, int damage, const Vector3& point, const MeansOfDeath& mod) -> void {
	self->activator = attacker;
	self->health = self->maxHealth;
	self->takeDamage = false;
	button_fire(self);
}

void SP_func_button(gentity_t* ent) {
	Vector3 abs_movedir{};
	float  dist;

	SetMoveDir(ent->s.angles, ent->moveDir);
	ent->moveType = MoveType::Stop;
	ent->solid = SOLID_BSP;
	gi.setModel(ent, ent->model);

	if (ent->sounds != 1)
		G_SetMoveinfoSounds(ent, "switches/butn2.wav", nullptr, nullptr);
	else
		G_SetMoveinfoSounds(ent, nullptr, nullptr, nullptr);

	if (!ent->speed)
		ent->speed = 40;
	if (!ent->accel)
		ent->accel = ent->speed;
	if (!ent->decel)
		ent->decel = ent->speed;

	if (g_mover_speed_scale->value != 1.0f) {
		ent->speed *= g_mover_speed_scale->value;
		ent->accel *= g_mover_speed_scale->value;
		ent->decel *= g_mover_speed_scale->value;
	}

	if (!ent->wait)
		ent->wait = 3;
	if (!st.lip)
		st.lip = 4;

	ent->pos1 = ent->s.origin;
	abs_movedir[0] = std::fabs(ent->moveDir[0]);
	abs_movedir[1] = std::fabs(ent->moveDir[1]);
	abs_movedir[2] = std::fabs(ent->moveDir[2]);
	dist = abs_movedir[0] * ent->size[0] + abs_movedir[1] * ent->size[1] + abs_movedir[2] * ent->size[2] - st.lip;
	ent->pos2 = ent->pos1 + (ent->moveDir * dist);

	ent->use = button_use;

	if (!ent->bmodel_anim.enabled)
		ent->s.effects |= EF_ANIM01;

	if (ent->health) {
		ent->maxHealth = ent->health;
		ent->die = button_killed;
		ent->takeDamage = true;
	}
	else if (!ent->targetName)
		ent->touch = button_touch;

	ent->moveInfo.state = MoveState::Bottom;

	ent->moveInfo.speed = ent->speed;
	ent->moveInfo.accel = ent->accel;
	ent->moveInfo.decel = ent->decel;
	ent->moveInfo.wait = ent->wait;
	ent->moveInfo.startOrigin = ent->pos1;
	ent->moveInfo.startAngles = ent->s.angles;
	ent->moveInfo.endOrigin = ent->pos2;
	ent->moveInfo.endAngles = ent->s.angles;

	gi.linkEntity(ent);
}

/*
======================================================================

DOORS

  spawn a trigger surrounding the entire team unless it is
  already targeted by another

======================================================================
*/

/*QUAKED func_door (0 .5 .8) ? START_OPEN x CRUSHER NOMONSTER ANIMATED TOGGLE ANIMATED_FAST x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
START_OPEN		the door to moves to its destination when spawned, and operate in reverse.  It is used to temporarily or permanently close off an area when triggered (not useful for touch or takeDamage doors).
NOMONSTER		monsters will not trigger this door
TOGGLE			wait in both the start and end states for a trigger event.
ANIMATED		door will animate when opening and closing
ANIMATED_FAST	door will animate quickly when opening and closing

"message"	is printed when the door is touched if it is a trigger door and it hasn't been fired yet
"angle"		determines the opening direction
"targetName" if set, no touch field will be spawned and a remote button or trigger field activates the door.
"health"	if set, door must be shot open
"speed"		movement speed (100 default)
"wait"		wait before returning (3 default, -1 = never return)
"lip"		lip remaining at end of move (8 default)
"dmg"		damage to inflict when blocked (2 default)
"noise_start"	overrides default "doors/dr1_strt.wav"
"noise_middle"	overrides default "doors/dr1_mid.wav"
"noise_end"		overrides default "doors/dr1_end.wav"

"sounds"
1)	silent
2)	light
3)	medium
4)	heavy
*/

static void door_use_areaportals(gentity_t* self, bool open) {
	gentity_t* t = nullptr;

	if (!self->target)
		return;

	while ((t = G_FindByString<&gentity_t::targetName>(t, self->target))) {
		if (Q_strcasecmp(t->className, "func_areaportal") == 0) {
			gi.SetAreaPortalState(t->style, open);
		}
	}
}

void door_go_down(gentity_t* self);

static void door_play_sound(gentity_t* self, int32_t sound) {
	if (!self->teamMaster) {
		gi.sound(self, CHAN_NO_PHS_ADD | CHAN_VOICE, sound, 1, self->attenuation, 0);
		return;
	}

	Vector3 p = {};
	int32_t c = 0;

	for (gentity_t* t = self->teamMaster; t; t = t->teamChain) {
		p += (t->absMin + t->absMax) * 0.5f;
		c++;
	}

	if (c == 1) {
		gi.sound(self, CHAN_NO_PHS_ADD | CHAN_VOICE, sound, 1, self->attenuation, 0);
		return;
	}

	p /= c;

	if (gi.pointContents(p) & CONTENTS_SOLID) {
		gi.sound(self, CHAN_NO_PHS_ADD | CHAN_VOICE, sound, 1, self->attenuation, 0);
		return;
	}

	gi.positionedSound(p, self, CHAN_NO_PHS_ADD | CHAN_VOICE, sound, 1, self->attenuation, 0);
}

MOVEINFO_ENDFUNC(door_hit_top) (gentity_t* self) -> void {
	if (!(self->flags & FL_TEAMSLAVE)) {
		if (self->moveInfo.sound_end)
			door_play_sound(self, self->moveInfo.sound_end);
	}
	self->s.sound = 0;
	self->moveInfo.state = MoveState::Top;
	if (self->spawnFlags.has(SPAWNFLAG_DOOR_TOGGLE))
		return;
	if (self->moveInfo.wait >= 0) {
		self->think = door_go_down;
		self->nextThink = level.time + GameTime::from_sec(self->moveInfo.wait);
	}

	if (self->spawnFlags.has(SPAWNFLAG_DOOR_START_OPEN))
		door_use_areaportals(self, false);
}

MOVEINFO_ENDFUNC(door_hit_bottom) (gentity_t* self) -> void {
	if (!(self->flags & FL_TEAMSLAVE)) {
		if (self->moveInfo.sound_end)
			door_play_sound(self, self->moveInfo.sound_end);
	}
	self->s.sound = 0;
	self->moveInfo.state = MoveState::Bottom;

	if (!self->spawnFlags.has(SPAWNFLAG_DOOR_START_OPEN))
		door_use_areaportals(self, false);
}

THINK(door_go_down) (gentity_t* self) -> void {
	if (!(self->flags & FL_TEAMSLAVE)) {
		if (self->moveInfo.sound_start)
			door_play_sound(self, self->moveInfo.sound_start);
	}

	self->s.sound = self->moveInfo.sound_middle;

	if (self->maxHealth) {
		self->takeDamage = true;
		self->health = self->maxHealth;
	}

	self->moveInfo.state = MoveState::Down;
	if (strcmp(self->className, "func_door") == 0 ||
		strcmp(self->className, "func_water") == 0 ||
		strcmp(self->className, "func_door_secret") == 0)
		Move_Calc(self, self->moveInfo.startOrigin, door_hit_bottom);
	else if (strcmp(self->className, "func_door_rotating") == 0)
		AngleMove_Calc(self, door_hit_bottom);

	if (self->spawnFlags.has(SPAWNFLAG_DOOR_START_OPEN))
		door_use_areaportals(self, true);
}

static void door_go_up(gentity_t* self, gentity_t* activator) {
	if (self->moveInfo.state == MoveState::Up)
		return; // already going up

	if (self->moveInfo.state == MoveState::Top) { // reset top wait time
		if (self->moveInfo.wait >= 0)
			self->nextThink = level.time + GameTime::from_sec(self->moveInfo.wait);
		return;
	}

	if (!(self->flags & FL_TEAMSLAVE)) {
		if (self->moveInfo.sound_start)
			door_play_sound(self, self->moveInfo.sound_start);
	}

	self->s.sound = self->moveInfo.sound_middle;

	self->moveInfo.state = MoveState::Up;
	if (strcmp(self->className, "func_door") == 0 ||
		strcmp(self->className, "func_water") == 0 ||
		strcmp(self->className, "func_door_secret") == 0)
		Move_Calc(self, self->moveInfo.endOrigin, door_hit_top);
	else if (strcmp(self->className, "func_door_rotating") == 0)
		AngleMove_Calc(self, door_hit_top);

	UseTargets(self, activator);

	if (!(self->spawnFlags & SPAWNFLAG_DOOR_START_OPEN))
		door_use_areaportals(self, true);
}

static THINK(smart_water_go_up) (gentity_t* self) -> void {
	float	distance;
	gentity_t* lowestPlayer;
	float	lowestPlayerPt;

	if (self->moveInfo.state == MoveState::Top) { // reset top wait time
		if (self->moveInfo.wait >= 0)
			self->nextThink = level.time + GameTime::from_sec(self->moveInfo.wait);
		return;
	}

	if (self->health) {
		if (self->absMax[2] >= self->health) {
			self->velocity = {};
			self->nextThink = 0_ms;
			self->moveInfo.state = MoveState::Top;
			return;
		}
	}

	if (!(self->flags & FL_TEAMSLAVE)) {
		if (self->moveInfo.sound_start)
			gi.sound(self, CHAN_NO_PHS_ADD | CHAN_VOICE, self->moveInfo.sound_start, 1, ATTN_STATIC, 0);
	}

	self->s.sound = self->moveInfo.sound_middle;

	// find the lowest player point.
	lowestPlayerPt = 999999;
	lowestPlayer = nullptr;
	for (auto ec : active_clients()) {
		// don't count dead or unused player slots
		if (ec->health > 0) {
			if (ec->absMin[2] < lowestPlayerPt) {
				lowestPlayerPt = ec->absMin[2];
				lowestPlayer = ec;
			}
		}
	}

	if (!lowestPlayer) {
		return;
	}

	distance = lowestPlayerPt - self->absMax[2];

	// for the calculations, make sure we intend to go up at least a little.
	if (distance < self->accel) {
		distance = 100;
		self->moveInfo.speed = 5;
	}
	else
		self->moveInfo.speed = distance / self->accel;

	if (self->moveInfo.speed < 5)
		self->moveInfo.speed = 5;
	else if (self->moveInfo.speed > self->speed)
		self->moveInfo.speed = self->speed;

	// FIXME - should this allow any movement other than straight up?
	self->moveInfo.dir = { 0, 0, 1 };
	self->velocity = self->moveInfo.dir * self->moveInfo.speed;
	self->moveInfo.remainingDistance = distance;

	if (self->moveInfo.state != MoveState::Up) {
		UseTargets(self, lowestPlayer);
		door_use_areaportals(self, true);
		self->moveInfo.state = MoveState::Up;
	}

	self->think = smart_water_go_up;
	self->nextThink = level.time + FRAME_TIME_S;
}

static USE(door_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	gentity_t* ent;
	Vector3	 center;

	if (self->flags & FL_TEAMSLAVE)
		return;

	if ((strcmp(self->className, "func_door_rotating") == 0) && self->spawnFlags.has(SPAWNFLAG_DOOR_ROTATING_SAFE_OPEN) &&
		(self->moveInfo.state == MoveState::Bottom || self->moveInfo.state == MoveState::Down)) {
		if (self->moveInfo.dir) {
			Vector3 forward = (activator->s.origin - self->s.origin).normalized();
			self->moveInfo.reversing = forward.dot(self->moveInfo.dir) > 0;
		}
	}

	if (self->spawnFlags.has(SPAWNFLAG_DOOR_TOGGLE)) {
		if (self->moveInfo.state == MoveState::Up || self->moveInfo.state == MoveState::Top) {
			// trigger all paired doors
			for (ent = self; ent; ent = ent->teamChain) {
				ent->message = nullptr;
				ent->touch = nullptr;
				door_go_down(ent);
			}
			return;
		}
	}

	//  smart water is different
	center = self->mins + self->maxs;
	center *= 0.5f;
	if ((strcmp(self->className, "func_water") == 0) && (gi.pointContents(center) & MASK_WATER) && self->spawnFlags.has(SPAWNFLAG_WATER_SMART)) {
		self->message = nullptr;
		self->touch = nullptr;
		self->enemy = activator;
		smart_water_go_up(self);
		return;
	}

	// trigger all paired doors
	for (ent = self; ent; ent = ent->teamChain) {
		ent->message = nullptr;
		ent->touch = nullptr;
		door_go_up(ent, activator);
	}
};

static TOUCH(Touch_DoorTrigger) (gentity_t* self, gentity_t* other, const trace_t& tr, bool otherTouchingSelf) -> void {
	if (other->health <= 0)
		return;

	if (!(other->svFlags & SVF_MONSTER) && (!other->client))
		return;

	if (self->owner->spawnFlags.has(SPAWNFLAG_DOOR_NOMONSTER) && (other->svFlags & SVF_MONSTER))
		return;

	if (level.time < self->touch_debounce_time)
		return;
	self->touch_debounce_time = level.time + 1_sec;

	door_use(self->owner, other, other);
}

static THINK(Think_CalcMoveSpeed) (gentity_t* self) -> void {
	gentity_t* ent;
	float	 min;
	float	 time;
	float	 newSpeed;
	float	 ratio;
	float	 dist;

	if (self->flags & FL_TEAMSLAVE)
		return; // only the team master does this

	// find the smallest distance any member of the team will be moving
	min = std::fabs(self->moveInfo.distance);
	for (ent = self->teamChain; ent; ent = ent->teamChain) {
		dist = std::fabs(ent->moveInfo.distance);
		if (dist < min)
			min = dist;
	}

	time = min / self->moveInfo.speed;

	// adjust speeds so they will all complete at the same time
	for (ent = self; ent; ent = ent->teamChain) {
		newSpeed = std::fabs(ent->moveInfo.distance) / time;
		ratio = newSpeed / ent->moveInfo.speed;
		if (ent->moveInfo.accel == ent->moveInfo.speed)
			ent->moveInfo.accel = newSpeed;
		else
			ent->moveInfo.accel *= ratio;
		if (ent->moveInfo.decel == ent->moveInfo.speed)
			ent->moveInfo.decel = newSpeed;
		else
			ent->moveInfo.decel *= ratio;
		ent->moveInfo.speed = newSpeed;
	}
}

static THINK(Think_SpawnDoorTrigger) (gentity_t* ent) -> void {
	gentity_t* other;
	Vector3	 mins, maxs;

	if (ent->flags & FL_TEAMSLAVE)
		return; // only the team leader spawns a trigger

	mins = ent->absMin;
	maxs = ent->absMax;

	for (other = ent->teamChain; other; other = other->teamChain) {
		AddPointToBounds(other->absMin, mins, maxs);
		AddPointToBounds(other->absMax, mins, maxs);
	}

	// expand
	mins[0] -= 60;
	mins[1] -= 60;
	maxs[0] += 60;
	maxs[1] += 60;

	other = Spawn();
	other->mins = mins;
	other->maxs = maxs;
	other->owner = ent;
	other->solid = SOLID_TRIGGER;
	other->moveType = MoveType::None;
	other->touch = Touch_DoorTrigger;
	gi.linkEntity(other);

	Think_CalcMoveSpeed(ent);
}

MOVEINFO_BLOCKED(door_blocked) (gentity_t* self, gentity_t* other) -> void {
	gentity_t* ent;

	if (!other->client && !(other->svFlags & SVF_MONSTER)) {
		// give it a chance to go away on it's own terms (like gibs)
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, 100000, 1, DamageFlags::Normal, ModID::Crushed);
		// if it's still there, nuke it
		if (other && other->inUse)
			BecomeExplosion1(other);
		return;
	}

	if (self->dmg && !(level.time < self->touch_debounce_time)) {
		self->touch_debounce_time = level.time + 10_hz;
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, self->dmg, 1, DamageFlags::Normal, ModID::Crushed);
	}

	// [Paril-KEX] don't allow wait -1 doors to return
	if (self->spawnFlags.has(SPAWNFLAG_DOOR_CRUSHER) || self->wait == -1)
		return;

	// if a door has a negative wait, it would never come back if blocked,
	// so let it just squash the object to death real fast
	if (self->moveInfo.wait >= 0) {
		if (self->moveInfo.state == MoveState::Down) {
			for (ent = self->teamMaster; ent; ent = ent->teamChain)
				door_go_up(ent, ent->activator);
		}
		else {
			for (ent = self->teamMaster; ent; ent = ent->teamChain)
				door_go_down(ent);
		}
	}
}

static DIE(door_killed) (gentity_t* self, gentity_t* inflictor, gentity_t* attacker, int damage, const Vector3& point, const MeansOfDeath& mod) -> void {
	gentity_t* ent;

	for (ent = self->teamMaster; ent; ent = ent->teamChain) {
		ent->health = ent->maxHealth;
		ent->takeDamage = false;
	}
	door_use(self->teamMaster, attacker, attacker);
}

static TOUCH(door_touch) (gentity_t* self, gentity_t* other, const trace_t& tr, bool otherTouchingSelf) -> void {
	if (!other->client)
		return;

	if (level.time < self->touch_debounce_time)
		return;

	self->touch_debounce_time = level.time + 5_sec;

	gi.LocCenter_Print(other, "{}", self->message);
	gi.sound(other, CHAN_AUTO, gi.soundIndex("misc/talk1.wav"), 1, ATTN_NORM, 0);
}

static THINK(Think_DoorActivateAreaPortal) (gentity_t* ent) -> void {
	door_use_areaportals(ent, true);

	if (ent->health || ent->targetName)
		Think_CalcMoveSpeed(ent);
	else
		Think_SpawnDoorTrigger(ent);
}

void SP_func_door(gentity_t* ent) {
	Vector3 abs_movedir{};

	if (ent->sounds != 1)
		G_SetMoveinfoSounds(ent, "doors/dr1_strt.wav", "doors/dr1_mid.wav", "doors/dr1_end.wav");
	else
		G_SetMoveinfoSounds(ent, nullptr, nullptr, nullptr);

	// [Paril-KEX] for rhangar1 doors
	if (!st.was_key_specified("attenuation"))
		ent->attenuation = ATTN_STATIC;
	else {
		if (ent->attenuation == -1) {
			ent->s.loopAttenuation = ATTN_LOOP_NONE;
			ent->attenuation = ATTN_NONE;
		}
		else {
			ent->s.loopAttenuation = ent->attenuation;
		}
	}

	SetMoveDir(ent->s.angles, ent->moveDir);
	ent->moveType = MoveType::Push;
	ent->solid = SOLID_BSP;
	ent->svFlags |= SVF_DOOR;
	gi.setModel(ent, ent->model);

	ent->moveInfo.blocked = door_blocked;
	ent->use = door_use;

	if (!ent->speed)
		ent->speed = 100;
	if (deathmatch->integer)
		ent->speed *= 2;
	if (g_fastDoors->integer)
		ent->speed *= 2;

	if (g_mover_speed_scale->value != 1.0f) {
		ent->speed *= g_mover_speed_scale->value;
		ent->accel *= g_mover_speed_scale->value;
		ent->decel *= g_mover_speed_scale->value;
	}

	if (!ent->accel)
		ent->accel = ent->speed;
	if (!ent->decel)
		ent->decel = ent->speed;

	if (!ent->wait)
		ent->wait = 3;
	if (!st.lip)
		st.lip = 8;
	if (!ent->dmg)
		ent->dmg = 2;

	// calculate second position
	ent->pos1 = ent->s.origin;
	abs_movedir[0] = std::fabs(ent->moveDir[0]);
	abs_movedir[1] = std::fabs(ent->moveDir[1]);
	abs_movedir[2] = std::fabs(ent->moveDir[2]);
	ent->moveInfo.distance =
		abs_movedir[0] * ent->size[0] + abs_movedir[1] * ent->size[1] + abs_movedir[2] * ent->size[2] - st.lip;
	ent->pos2 = ent->pos1 + (ent->moveDir * ent->moveInfo.distance);

	// if it starts open, switch the positions
	if (ent->spawnFlags.has(SPAWNFLAG_DOOR_START_OPEN)) {
		ent->s.origin = ent->pos2;
		ent->pos2 = ent->pos1;
		ent->pos1 = ent->s.origin;
	}

	ent->moveInfo.state = MoveState::Bottom;

	if (ent->health) {
		ent->takeDamage = true;
		ent->die = door_killed;
		ent->maxHealth = ent->health;
	}
	else if (ent->targetName) {
		if (ent->message) {
			gi.soundIndex("misc/talk.wav");
			ent->touch = door_touch;
		}
		ent->flags |= FL_LOCKED;
	}

	ent->moveInfo.speed = ent->speed;
	ent->moveInfo.accel = ent->accel;
	ent->moveInfo.decel = ent->decel;
	ent->moveInfo.wait = ent->wait;
	ent->moveInfo.startOrigin = ent->pos1;
	ent->moveInfo.startAngles = ent->s.angles;
	ent->moveInfo.endOrigin = ent->pos2;
	ent->moveInfo.endAngles = ent->s.angles;

	if (ent->spawnFlags.has(SPAWNFLAG_DOOR_ANIMATED))
		ent->s.effects |= EF_ANIM_ALL;
	if (ent->spawnFlags.has(SPAWNFLAG_DOOR_ANIMATED_FAST))
		ent->s.effects |= EF_ANIM_ALLFAST;

	// to simplify logic elsewhere, make non-teamed doors into a team of one
	if (!ent->team)
		ent->teamMaster = ent;

	gi.linkEntity(ent);

	ent->nextThink = level.time + FRAME_TIME_S;

	if (ent->spawnFlags.has(SPAWNFLAG_DOOR_START_OPEN))
		ent->think = Think_DoorActivateAreaPortal;
	else if (ent->health || ent->targetName)
		ent->think = Think_CalcMoveSpeed;
	else
		ent->think = Think_SpawnDoorTrigger;
}

static USE(Door_Activate) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	self->use = nullptr;

	if (self->health) {
		self->takeDamage = true;
		self->die = door_killed;
		self->maxHealth = self->health;
	}

	if (self->health)
		self->think = Think_CalcMoveSpeed;
	else
		self->think = Think_SpawnDoorTrigger;
	self->nextThink = level.time + FRAME_TIME_S;
}

/*QUAKED func_door_rotating (0 .5 .8) ? START_OPEN REVERSE CRUSHER NOMONSTER ANIMATED TOGGLE X_AXIS Y_AXIS NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP RESERVED1 COOP_ONLY RESERVED2 INACTIVE SAFE_OPEN
TOGGLE causes the door to wait in both the start and end states for a trigger event.

START_OPEN	the door to moves to its destination when spawned, and operate in reverse.  It is used to temporarily or permanently close off an area when triggered (not useful for touch or takeDamage doors).
REVERSE		will cause the door to rotate in the opposite direction.
CRUSHER		will cause the door to crush players and monsters that block it.
NOMONSTER	monsters will not trigger this door
ANIMATED	door will animate when opening and closing
TOGGLE		entity will wait in both the start and end states for a trigger event.
X_AXIS		door will rotate around the X axis instead of the default Z axis.
Y_AXIS		door will rotate around the Y axis instead of the default Z axis.
INACTIVE	will cause the door to be inactive until triggered.
SAFE_OPEN	will cause the door to open in reverse if you are on the `angles` side of the door.

You need to have an origin brush as part of this entity.  The center of that brush will be
the point around which it is rotated. It will rotate around the Z axis by default.  You can
check either the X_AXIS or Y_AXIS box to change that.

"distance"	is how many degrees the door will be rotated.
"speed"		determines how fast the door moves; default value is 100.
"accel"		if specified,is how much the rotation speed will increase each .1 sec. (default: no accel)
"message"	is printed when the door is touched if it is a trigger door and it hasn't been fired yet
"angle"		determines the opening direction
"targetName" if set, no touch field will be spawned and a remote button or trigger field activates the door.
"health"	if set, door must be shot open
"speed"		movement speed (100 default)
"wait"		wait before returning (3 default, -1 = never return)
"dmg"		damage to inflict when blocked (2 default)
"noise_start"	overrides default "doors/dr1_strt.wav"
"noise_middle"	overrides default "doors/dr1_mid.wav"
"noise_end"		overrides default "doors/dr1_end.wav"

"sounds"
1)	silent
2)	light
3)	medium
4)	heavy
*/

void SP_func_door_rotating(gentity_t* ent) {
	if (ent->spawnFlags.has(SPAWNFLAG_DOOR_ROTATING_SAFE_OPEN))
		SetMoveDir(ent->s.angles, ent->moveInfo.dir);

	ent->s.angles = {};

	// set the axis of rotation
	ent->moveDir = {};
	if (ent->spawnFlags.has(SPAWNFLAG_DOOR_ROTATING_X_AXIS))
		ent->moveDir[2] = 1.0;
	else if (ent->spawnFlags.has(SPAWNFLAG_DOOR_ROTATING_Y_AXIS))
		ent->moveDir[0] = 1.0;
	else // Z_AXIS
		ent->moveDir[1] = 1.0;

	// check for reverse rotation
	if (ent->spawnFlags.has(SPAWNFLAG_DOOR_REVERSE))
		ent->moveDir = -ent->moveDir;

	if (!st.distance) {
		gi.Com_PrintFmt("{}: no distance set\n", *ent);
		st.distance = 90;
	}

	ent->pos1 = ent->s.angles;
	ent->pos2 = ent->s.angles + (ent->moveDir * st.distance);
	ent->pos3 = ent->s.angles + (ent->moveDir * -st.distance);
	ent->moveInfo.distance = (float)st.distance;

	ent->moveType = MoveType::Push;
	ent->solid = SOLID_BSP;
	ent->svFlags |= SVF_DOOR;
	gi.setModel(ent, ent->model);

	ent->moveInfo.blocked = door_blocked;
	ent->use = door_use;

	if (!ent->speed)
		ent->speed = 100;
	if (g_fastDoors->integer)
		ent->speed *= 2;

	if (g_mover_speed_scale->value != 1.0f) {
		ent->speed *= g_mover_speed_scale->value;
		ent->accel *= g_mover_speed_scale->value;
		ent->decel *= g_mover_speed_scale->value;
	}

	if (!ent->accel)
		ent->accel = ent->speed;
	if (!ent->decel)
		ent->decel = ent->speed;

	if (!ent->wait)
		ent->wait = 3;
	if (!ent->dmg)
		ent->dmg = 2;

	if (ent->sounds != 1)
		G_SetMoveinfoSounds(ent, "doors/dr1_strt.wav", "doors/dr1_mid.wav", "doors/dr1_end.wav");
	else
		G_SetMoveinfoSounds(ent, nullptr, nullptr, nullptr);

	// [Paril-KEX] for rhangar1 doors
	if (!st.was_key_specified("attenuation"))
		ent->attenuation = ATTN_STATIC;
	else {
		if (ent->attenuation == -1) {
			ent->s.loopAttenuation = ATTN_LOOP_NONE;
			ent->attenuation = ATTN_NONE;
		}
		else {
			ent->s.loopAttenuation = ent->attenuation;
		}
	}

	// if it starts open, switch the positions
	if (ent->spawnFlags.has(SPAWNFLAG_DOOR_START_OPEN)) {
		if (ent->spawnFlags.has(SPAWNFLAG_DOOR_ROTATING_SAFE_OPEN)) {
			ent->spawnFlags &= ~SPAWNFLAG_DOOR_ROTATING_SAFE_OPEN;
			gi.Com_PrintFmt("{}: SAFE_OPEN is not compatible with START_OPEN\n", *ent);
		}

		ent->s.angles = ent->pos2;
		ent->pos2 = ent->pos1;
		ent->pos1 = ent->s.angles;
		ent->moveDir = -ent->moveDir;
	}

	if (ent->health) {
		ent->takeDamage = true;
		ent->die = door_killed;
		ent->maxHealth = ent->health;
	}

	if (ent->targetName && ent->message) {
		gi.soundIndex("misc/talk.wav");
		ent->touch = door_touch;
	}

	ent->moveInfo.state = MoveState::Bottom;
	ent->moveInfo.speed = ent->speed;
	ent->moveInfo.accel = ent->accel;
	ent->moveInfo.decel = ent->decel;
	ent->moveInfo.wait = ent->wait;
	ent->moveInfo.startOrigin = ent->s.origin;
	ent->moveInfo.startAngles = ent->pos1;
	ent->moveInfo.endOrigin = ent->s.origin;
	ent->moveInfo.endAngles = ent->pos2;
	ent->moveInfo.endAnglesReversed = ent->pos3;

	if (ent->spawnFlags.has(SPAWNFLAG_DOOR_ANIMATED))
		ent->s.effects |= EF_ANIM_ALL;

	// to simplify logic elsewhere, make non-teamed doors into a team of one
	if (!ent->team)
		ent->teamMaster = ent;

	gi.linkEntity(ent);

	ent->nextThink = level.time + FRAME_TIME_S;
	if (ent->health || ent->targetName)
		ent->think = Think_CalcMoveSpeed;
	else
		ent->think = Think_SpawnDoorTrigger;

	if (ent->spawnFlags.has(SPAWNFLAG_DOOR_ROTATING_INACTIVE)) {
		ent->takeDamage = false;
		ent->die = nullptr;
		ent->think = nullptr;
		ent->nextThink = 0_ms;
		ent->use = Door_Activate;
	}
}

MOVEINFO_BLOCKED(smart_water_blocked) (gentity_t* self, gentity_t* other) -> void {
	if (!(other->svFlags & SVF_MONSTER) && (!other->client)) {
		// give it a chance to go away on it's own terms (like gibs)
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, 100000, 1, DamageFlags::Normal, ModID::Lava);
		// if it's still there, nuke it
		if (other && other->inUse && other->solid)
			BecomeExplosion1(other);
		return;
	}

	Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, 100, 1, DamageFlags::Normal, ModID::Lava);
}

/*QUAKED func_water (0 .5 .8) ? START_OPEN SMART x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
func_water is a moveable water brush.  It must be targeted to operate.  Use a non-water texture at your own risk.

START_OPEN causes the water to move to its destination when spawned and operate in reverse.
SMART causes the water to adjust its speed depending on distance to player.
		(speed = distance/accel, min 5, max self->speed)

"accel"		for smart water, the divisor to determine water speed. default 20 (smaller = faster)
"health"	maximum height of this water brush
"angle"		determines the opening direction (up or down only)
"speed"		movement speed (25 default)
"wait"		wait before returning (-1 default, -1 = TOGGLE)
"lip"		lip remaining at end of move (0 default)
"bob"		how much the water bobs up and down (16 default)
"duration"	duration of one bob cycle in seconds (8 default)
"noise_start"	overrides default "world/mov_watr.wav"
"noise_middle"	overrides default (none)
"noise_end"		overrides default "world/stp_watr.wav"

"sounds"	(yes, these need to be changed)
0)	no sound
1)	water
2)	lava
*/

/*QUAKED func_bobbingwater (0 .5 .8) ? START_OPEN SMART x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
LAZARUS: Bobbing water - identical to func_water, but bobs up and down.

START_OPEN causes the water to move to its destination when spawned and operate in reverse.
SMART causes the water to adjust its speed depending on distance to player.
		(speed = distance/accel, min 5, max self->speed)

"health"	maximum height of this water brush
"angle"		determines the opening direction (up or down only)
"speed"		movement speed (25 default)
"wait"		wait before returning (-1 default, -1 = TOGGLE)
"lip"		lip remaining at end of move (0 default)
"bob"		how much the water bobs up and down (16 default)
"duration"	duration of one bob cycle in seconds (8 default)
"noise_start"	overrides default "world/mov_watr.wav"
"noise_middle"	overrides default (none)
"noise_end"		overrides default "world/stp_watr.wav"

"sounds"	(yes, these need to be changed)
0)	no sound
1)	water
2)	lava
*/

static void BobThink(gentity_t* self) {
	const int cycleTime = static_cast<int>(self->duration * 10);
	const int frame = self->bobFrame % cycleTime;
	const int nextFrame = (self->bobFrame + 1) % cycleTime;

	const float phase0 = std::sinf(2.0f * M_PI * (frame / static_cast<float>(cycleTime)));
	const float phase1 = std::sinf(2.0f * M_PI * (nextFrame / static_cast<float>(cycleTime)));

	const float delta = (self->bob / 2.0f) * (phase1 - phase0);
	self->velocity[_Z] = delta / FRAME_TIME_MS.milliseconds();

	self->bobFrame = (self->bobFrame + 1) % cycleTime;
	self->nextThink = level.time + FRAME_TIME_MS;
	gi.linkEntity(self);
}

static void BobInit(gentity_t* self) {
	self->bobFrame = 0;
	self->think = BobThink;
	self->nextThink = level.time + FRAME_TIME_MS;
}

void SP_func_water(gentity_t* self) {
	Vector3 absMoveDir{};

	SetMoveDir(self->s.angles, self->moveDir);
	self->moveType = MoveType::Push;
	self->solid = SOLID_BSP;
	gi.setModel(self, self->model);

	// Sound assignment
	switch (self->sounds) {
	default:
		G_SetMoveinfoSounds(self, nullptr, nullptr, nullptr);
		break;
	case 1: // Water
	case 2: // Lava
		G_SetMoveinfoSounds(self, "world/mov_watr.wav", nullptr, "world/stp_watr.wav");
		break;
	}
	self->attenuation = ATTN_STATIC;

	// Calculate movement extents
	self->pos1 = self->s.origin;
	for (int i = 0; i < 3; ++i)
		absMoveDir[i] = std::fabs(self->moveDir[i]);
	self->moveInfo.distance =
		absMoveDir[0] * self->size[0] + absMoveDir[1] * self->size[1] + absMoveDir[2] * self->size[2] - st.lip;
	self->pos2 = self->pos1 + (self->moveDir * self->moveInfo.distance);

	// START_OPEN flag: begin at top position
	if (self->spawnFlags.has(SPAWNFLAG_DOOR_START_OPEN)) {
		self->s.origin = self->pos2;
		std::swap(self->pos1, self->pos2);
	}
	self->moveInfo.startOrigin = self->pos1;
	self->moveInfo.startAngles = self->s.angles;
	self->moveInfo.endOrigin = self->pos2;
	self->moveInfo.endAngles = self->s.angles;
	self->moveInfo.state = MoveState::Bottom;

	// Movement parameters
	if (!self->speed) self->speed = 25;
	if (g_mover_speed_scale->value != 1.0f) {
		self->speed *= g_mover_speed_scale->value;
		self->accel *= g_mover_speed_scale->value;
		self->decel *= g_mover_speed_scale->value;
	}
	self->moveInfo.accel = self->moveInfo.decel = self->moveInfo.speed = self->speed;

	// SMART water
	if (self->spawnFlags.has(SPAWNFLAG_WATER_SMART)) {
		if (!self->accel) self->accel = 20;
		self->moveInfo.blocked = smart_water_blocked;
	}

	// Wait/Toggle
	if (!self->wait) self->wait = -1;
	self->moveInfo.wait = self->wait;
	self->use = door_use;
	if (self->wait == -1) self->spawnFlags |= SPAWNFLAG_DOOR_TOGGLE;

	// Bobbing water
	const bool isBobbing = (!strcmp(self->className, "func_bobbingwater") || self->bob);
	if (isBobbing) {
		self->className = "func_door";
		if (!self->bob) self->bob = 16;
		if (!self->duration) self->duration = 8;
		self->think = BobInit;
		self->nextThink = level.time + FRAME_TIME_MS;
	}

	gi.linkEntity(self);
}

constexpr SpawnFlags SPAWNFLAG_TRAIN_TOGGLE = 2_spawnflag;
constexpr SpawnFlags SPAWNFLAG_TRAIN_BLOCK_STOPS = 4_spawnflag;
constexpr SpawnFlags SPAWNFLAG_TRAIN_FIX_OFFSET = 16_spawnflag;
constexpr SpawnFlags SPAWNFLAG_TRAIN_USE_ORIGIN = 32_spawnflag;

/*QUAKED func_train (0 .5 .8) ? START_ON TOGGLE BLOCK_STOPS MOVE_TEAMCHAIN FIX_OFFSET USE_ORIGIN x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
Trains are moving platforms that players can ride.
The targets origin specifies the min point of the train at each corner.
The train spawns at the first target it is pointing at.
If the train is the target of a button or trigger, it will not begin moving until activated.

START_ON	the train will start moving when spawned.
TOGGLE		the train will wait in both the start and end states for a trigger event.
BLOCK_STOPS	the train will not stop when it hits a blockable object, but will continue to move.
MOVE_TEAMCHAIN	the train will move all entities with the same team value as the train.
FIX_OFFSET	the train will not use the target's origin, but will use the train's origin as the start point.
USE_ORIGIN	the train will use the target's origin as the start point, not the train's origin.

"speed"		determines how fast the train moves; default value is 100.
"dmg"		damage to inflict when blocked; default value is 2.
"noise"		looping sound to play when the train is in motion

To have other entities move with the train, set all the piece's team value to the same thing. They will move in unison.
*/
void train_next(gentity_t* self);

MOVEINFO_BLOCKED(train_blocked) (gentity_t* self, gentity_t* other) -> void {
	if (!(other->svFlags & SVF_MONSTER) && (!other->client)) {
		// give it a chance to go away on it's own terms (like gibs)
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, 100000, 1, DamageFlags::Normal, ModID::Crushed);
		// if it's still there, nuke it
		if (other && other->inUse && other->solid)
			BecomeExplosion1(other);
		return;
	}

	if (level.time < self->touch_debounce_time)
		return;

	if (!self->dmg)
		return;
	self->touch_debounce_time = level.time + 500_ms;
	Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, self->dmg, 1, DamageFlags::Normal, ModID::Crushed);
}

MOVEINFO_ENDFUNC(train_wait) (gentity_t* self) -> void {
	if (self->targetEnt && self->targetEnt->pathTarget) {
		const char* savetarget;
		gentity_t* ent;

		ent = self->targetEnt;
		savetarget = ent->target;
		ent->target = ent->pathTarget;
		UseTargets(ent, self->activator);

		if (ent->inUse) {
			ent->target = savetarget;
		}

		// make sure we didn't get killed by a killTarget
		if (!self->inUse)
			return;
	}

	if (self->moveInfo.wait) {
		if (self->moveInfo.wait > 0) {
			self->nextThink = level.time + GameTime::from_sec(self->moveInfo.wait);
			self->think = train_next;
		}
		else if (self->spawnFlags.has(SPAWNFLAG_TRAIN_TOGGLE)) { // && wait < 0
			// clear targetEnt, let train_next get called when we get used
			self->targetEnt = nullptr;
			self->spawnFlags &= ~SPAWNFLAG_TRAIN_START_ON;
			self->velocity = {};
			self->nextThink = 0_ms;
		}

		if (!(self->flags & FL_TEAMSLAVE)) {
			if (self->moveInfo.sound_end)
				gi.sound(self, CHAN_NO_PHS_ADD | CHAN_VOICE, self->moveInfo.sound_end, 1, ATTN_STATIC, 0);
		}
		self->s.sound = 0;
	}
	else {
		train_next(self);
	}
}

MOVEINFO_ENDFUNC(train_piece_wait) (gentity_t* self) -> void {}

THINK(train_next) (gentity_t* self) -> void {
	gentity_t* ent;
	Vector3	 dest;
	bool	 first;

	first = true;
again:
	if (!self->target) {
		self->s.sound = 0;
		return;
	}

	ent = PickTarget(self->target);
	if (!ent) {
		gi.Com_PrintFmt("{}: train_next: bad target {}\n", *self, self->target);
		return;
	}

	self->target = ent->target;

	// check for a teleport path_corner
	if (ent->spawnFlags.has(SPAWNFLAG_PATH_CORNER_TELEPORT)) {
		if (!first) {
			gi.Com_PrintFmt("{}: connected teleport path_corners\n", *ent);
			return;
		}
		first = false;

		if (self->spawnFlags.has(SPAWNFLAG_TRAIN_USE_ORIGIN))
			self->s.origin = ent->s.origin;
		else {
			self->s.origin = ent->s.origin - self->mins;

			if (self->spawnFlags.has(SPAWNFLAG_TRAIN_FIX_OFFSET))
				self->s.origin -= Vector3{ 1.f, 1.f, 1.f };
		}

		self->s.oldOrigin = self->s.origin;
		self->s.event = EV_OTHER_TELEPORT;
		gi.linkEntity(self);
		goto again;
	}

	if (ent->speed) {
		self->speed = ent->speed;
		self->moveInfo.speed = ent->speed;
		if (ent->accel)
			self->moveInfo.accel = ent->accel;
		else
			self->moveInfo.accel = ent->speed;
		if (ent->decel)
			self->moveInfo.decel = ent->decel;
		else
			self->moveInfo.decel = ent->speed;
		self->moveInfo.currentSpeed = 0;
	}

	self->moveInfo.wait = ent->wait;
	self->targetEnt = ent;

	if (!(self->flags & FL_TEAMSLAVE)) {
		if (self->moveInfo.sound_start)
			gi.sound(self, CHAN_NO_PHS_ADD | CHAN_VOICE, self->moveInfo.sound_start, 1, ATTN_STATIC, 0);
	}

	self->s.sound = self->moveInfo.sound_middle;

	if (self->spawnFlags.has(SPAWNFLAG_TRAIN_USE_ORIGIN))
		dest = ent->s.origin;
	else {
		dest = ent->s.origin - self->mins;

		if (self->spawnFlags.has(SPAWNFLAG_TRAIN_FIX_OFFSET))
			dest -= Vector3{ 1.f, 1.f, 1.f };
	}

	self->moveInfo.state = MoveState::Top;
	self->moveInfo.startOrigin = self->s.origin;
	self->moveInfo.endOrigin = dest;
	Move_Calc(self, dest, train_wait);
	self->spawnFlags |= SPAWNFLAG_TRAIN_START_ON;

	if (self->spawnFlags.has(SPAWNFLAG_TRAIN_MOVE_TEAMCHAIN)) {
		gentity_t* e;
		Vector3	 dir, dst;

		dir = dest - self->s.origin;
		for (e = self->teamChain; e; e = e->teamChain) {
			dst = dir + e->s.origin;
			e->moveInfo.startOrigin = e->s.origin;
			e->moveInfo.endOrigin = dst;

			e->moveInfo.state = MoveState::Top;
			e->speed = self->speed;
			e->moveInfo.speed = self->moveInfo.speed;
			e->moveInfo.accel = self->moveInfo.accel;
			e->moveInfo.decel = self->moveInfo.decel;
			e->moveType = MoveType::Push;
			Move_Calc(e, dst, train_piece_wait);
		}
	}
}

static void train_resume(gentity_t* self) {
	gentity_t* ent;
	Vector3	 dest;

	ent = self->targetEnt;

	if (self->spawnFlags.has(SPAWNFLAG_TRAIN_USE_ORIGIN))
		dest = ent->s.origin;
	else {
		dest = ent->s.origin - self->mins;

		if (self->spawnFlags.has(SPAWNFLAG_TRAIN_FIX_OFFSET))
			dest -= Vector3{ 1.f, 1.f, 1.f };
	}

	self->s.sound = self->moveInfo.sound_middle;

	self->moveInfo.state = MoveState::Top;
	self->moveInfo.startOrigin = self->s.origin;
	self->moveInfo.endOrigin = dest;
	Move_Calc(self, dest, train_wait);
	self->spawnFlags |= SPAWNFLAG_TRAIN_START_ON;
}

THINK(func_train_find) (gentity_t* self) -> void {
	gentity_t* ent;

	if (!self->target) {
		gi.Com_PrintFmt("{}: train_find: no target\n", *self);
		return;
	}
	ent = PickTarget(self->target);
	if (!ent) {
		gi.Com_PrintFmt("{}: train_find: target {} not found\n", *self, self->target);
		return;
	}
	self->target = ent->target;

	if (self->spawnFlags.has(SPAWNFLAG_TRAIN_USE_ORIGIN))
		self->s.origin = ent->s.origin;
	else {
		self->s.origin = ent->s.origin - self->mins;

		if (self->spawnFlags.has(SPAWNFLAG_TRAIN_FIX_OFFSET))
			self->s.origin -= Vector3{ 1.f, 1.f, 1.f };
	}

	gi.linkEntity(self);

	// if not triggered, start immediately
	if (!self->targetName)
		self->spawnFlags |= SPAWNFLAG_TRAIN_START_ON;

	if (self->spawnFlags.has(SPAWNFLAG_TRAIN_START_ON)) {
		self->nextThink = level.time + FRAME_TIME_S;
		self->think = train_next;
		self->activator = self;
	}
}

USE(train_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	self->activator = activator;

	if (self->spawnFlags.has(SPAWNFLAG_TRAIN_START_ON)) {
		if (!self->spawnFlags.has(SPAWNFLAG_TRAIN_TOGGLE))
			return;
		self->spawnFlags &= ~SPAWNFLAG_TRAIN_START_ON;
		self->velocity = {};
		self->nextThink = 0_ms;
	}
	else {
		if (self->targetEnt)
			train_resume(self);
		else
			train_next(self);
	}
}

void SP_func_train(gentity_t* self) {
	self->moveType = MoveType::Push;

	self->s.angles = {};
	self->moveInfo.blocked = train_blocked;
	if (self->spawnFlags.has(SPAWNFLAG_TRAIN_BLOCK_STOPS))
		self->dmg = 0;
	else {
		if (!self->dmg)
			self->dmg = 100;
	}
	self->solid = SOLID_BSP;
	gi.setModel(self, self->model);

	if (st.noise) {
		self->moveInfo.sound_middle = gi.soundIndex(st.noise);

		// [Paril-KEX] for rhangar1 doors
		if (!st.was_key_specified("attenuation"))
			self->attenuation = ATTN_STATIC;
		else {
			if (self->attenuation == -1) {
				self->s.loopAttenuation = ATTN_LOOP_NONE;
				self->attenuation = ATTN_NONE;
			}
			else {
				self->s.loopAttenuation = self->attenuation;
			}
		}
	}

	if (!self->speed)
		self->speed = 100;

	if (g_mover_speed_scale->value != 1.0f) {
		self->speed *= g_mover_speed_scale->value;
		self->accel *= g_mover_speed_scale->value;
		self->decel *= g_mover_speed_scale->value;
	}

	self->moveInfo.speed = self->speed;
	self->moveInfo.accel = self->moveInfo.decel = self->moveInfo.speed;

	self->use = train_use;

	gi.linkEntity(self);

	if (self->target) {
		// start trains on the second frame, to make sure their targets have had
		// a chance to spawn
		self->nextThink = level.time + FRAME_TIME_S;
		self->think = func_train_find;
	}
	else {
		gi.Com_PrintFmt("{}: no target\n", *self);
	}
}

/*QUAKED func_rotate_train (0 .5 .8) ? START_ON TOGGLE BLOCK_STOPS
Rotate trains are like standard trains but can rotate as well.
The targets origin specifies the ORIGIN of the train at each corner.
The train spawns at the first target it is pointing at.
If the train is the target of a button or trigger, it will not begin
moving until activated.

speed		default 100
dmg			default 2
target		first path_corner to move to
targetname	if targetted, then does not start until triggered
speed		initial speed (may be overridden by next path_corner)
duration	time in seconds to travel to each path corner (or until
			overridden by duration on path_corner)
speeds		gives x y z speeds to rotate on specified axes
rotate		gives x y z angles to rotate for partial rotation,
			if defined, used in conjunction with duration or speed.

The train always takes the values of the NEXT corner for its moves.
For example, if you get to/start at a corner, and the next corner
you go to has a rotate 0 90 0, then the train will rotate 90 degrees
on the y (z in the editor) axis from the current point until that one.

noise	looping sound to play when the train is in motion

*/

//====================================================================
//
// QUAKED func_rotate_train (0 .5 .8) ? START_ON TOGGLE BLOCK_STOPS
// ... QuakeEd definition ...
//
//====================================================================

void rotate_train_next(gentity_t* self);

/**
 * @brief Called when the train's movement and rotation to a corner is complete.
 * This function handles stopping, firing targets, and proceeding to the next corner.
 */
static THINK(rotate_train_at_corner) (gentity_t* self) -> void {
	// Stop all movement and sound
	self->velocity = {};
	self->aVelocity = {};
	self->s.sound = 0;
	if (!(self->flags & FL_TEAMSLAVE) && self->moveInfo.sound_end) {
		gi.sound(self, CHAN_NO_PHS_ADD | CHAN_VOICE, self->moveInfo.sound_end, 1, ATTN_STATIC, 0);
	}

	// Fire targets at the destination path_corner
	if (self->targetEnt && self->targetEnt->pathTarget) {
		const char* savetarget = self->targetEnt->target;
		gentity_t* path_corner = self->targetEnt; // Store pointer locally

		path_corner->target = path_corner->pathTarget;
		UseTargets(path_corner, self->activator);

		// --- CRASH FIX ---
		// Check if the path_corner is still valid after UseTargets, as it may
		// have been freed by one of its targets.
		if (path_corner->inUse) {
			path_corner->target = savetarget;
		}
		// --- END FIX ---

		// Check if the train itself was freed by a killtarget
		if (!self->inUse)
			return;
	}

	// Handle wait time or toggle state to decide when to move next
	if (self->moveInfo.wait > 0) {
		self->nextThink = level.time + GameTime::from_sec(self->moveInfo.wait);
		self->think = rotate_train_next;
	}
	else if (self->spawnFlags.has(SPAWNFLAG_TRAIN_TOGGLE)) {
		self->targetEnt = nullptr;
		self->spawnFlags &= ~SPAWNFLAG_TRAIN_START_ON;
		self->nextThink = 0_ms;
	}
	else {
		rotate_train_next(self);
	}
}

/**
 * @brief Finds the next path_corner and calculates the required movement and rotation.
 */
THINK(rotate_train_next) (gentity_t* self) -> void
{
	if (!self->target) {
		self->s.sound = 0;
		return;
	}

	gentity_t* ent = PickTarget(self->target);
	if (!ent) {
		gi.Com_PrintFmt("{}: rotate_train_next: bad target {}\n", *self, self->target);
		return;
	}

	self->target = ent->target;
	self->targetEnt = ent;

	// Update speed and wait time from the path_corner
	if (ent->speed) self->speed = ent->speed;
	self->moveInfo.wait = ent->wait;
	self->moveInfo.speed = self->speed;

	// Store start/end states for movement and rotation
	self->moveInfo.startOrigin = self->s.origin;
	self->moveInfo.startAngles = self->s.angles;
	self->moveInfo.endOrigin = ent->s.origin;
	self->moveInfo.endAngles = self->s.angles; // Start with current angles

	// Calculate travel time. 'duration' key on path_corner takes precedence.
	float dist = (self->moveInfo.endOrigin - self->moveInfo.startOrigin).length();
	float travel_time = (ent->duration > 0) ? ent->duration : ((self->speed > 0) ? (dist / self->speed) : 0.0f);

	// If travel time is zero, snap to destination instantly
	if (travel_time <= 0.0f) {
		self->s.origin = self->moveInfo.endOrigin;
		gi.linkEntity(self);
		rotate_train_at_corner(self);
		return;
	}

	// Calculate final angles based on 'speeds' or 'rotate' keys on the path_corner
	if (ent->moveOrigin) { // 'speeds' is stored in moveOrigin
		self->moveInfo.endAngles += ent->moveOrigin * travel_time;
	}
	else if (ent->moveAngles) { // 'rotate' is stored in moveAngles
		self->moveInfo.endAngles += ent->moveAngles;
	}

	// Set linear and angular velocity to arrive at the destination in the correct time
	self->velocity = (self->moveInfo.endOrigin - self->moveInfo.startOrigin) * (1.0f / travel_time);
	self->aVelocity = (self->moveInfo.endAngles - self->moveInfo.startAngles) * (1.0f / travel_time);

	// Set the think function to check for completion
	self->think = rotate_train_at_corner;
	self->nextThink = level.time + GameTime::from_sec(travel_time);

	// Start sounds
	if (!(self->flags & FL_TEAMSLAVE)) {
		if (self->moveInfo.sound_start)
			gi.sound(self, CHAN_NO_PHS_ADD | CHAN_VOICE, self->moveInfo.sound_start, 1, ATTN_STATIC, 0);
	}
	self->s.sound = self->moveInfo.sound_middle;
	self->spawnFlags |= SPAWNFLAG_TRAIN_START_ON;
}

/**
 * @brief Resumes a paused train's movement.
 */
static void rotate_train_resume(gentity_t* self)
{
	// If there's no target, there's nowhere to go.
	if (!self->targetEnt) return;

	// This is a simplified resume; it will restart the leg of the journey.
	// For perfect resume, one would calculate remaining time and distance.
	rotate_train_next(self);
}

/**
 * @brief Handles the 'use' event for the train (e.g., from a button).
 */
USE(rotate_train_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void
{
	self->activator = activator;

	if (self->spawnFlags.has(SPAWNFLAG_TRAIN_START_ON)) {
		if (!self->spawnFlags.has(SPAWNFLAG_TRAIN_TOGGLE))
			return;
		// Pause the train
		self->spawnFlags &= ~SPAWNFLAG_TRAIN_START_ON;
		self->velocity = {};
		self->aVelocity = {};
		self->s.sound = 0;
		self->think = nullptr;
		self->nextThink = 0_ms;
	}
	else {
		// Start or resume the train
		if (self->targetEnt)
			rotate_train_resume(self);
		else
			rotate_train_next(self);
	}
}

/**
 * @brief Finds the first path_corner and sets the train's initial state.
 */
THINK(rotate_train_find) (gentity_t* self) -> void
{
	if (!self->target) {
		gi.Com_PrintFmt("{}: rotate_train_find: no target\n", *self);
		return;
	}
	gentity_t* ent = PickTarget(self->target);
	if (!ent) {
		gi.Com_PrintFmt("{}: rotate_train_find: target {} not found\n", *self, self->target);
		return;
	}
	self->target = ent->target;

	// Set start position and angles from the first path_corner
	self->s.origin = ent->s.origin;
	self->s.angles = ent->s.angles;
	gi.linkEntity(self);

	// Start immediately if not targeted by something else
	if (!self->targetName)
		self->spawnFlags |= SPAWNFLAG_TRAIN_START_ON;

	if (self->spawnFlags.has(SPAWNFLAG_TRAIN_START_ON)) {
		self->nextThink = level.time + FRAME_TIME_S;
		self->think = rotate_train_next;
		self->activator = self;
	}
}

/**
 * @brief Spawns and initializes a func_rotate_train entity.
 */
void SP_func_rotate_train(gentity_t* self)
{
	self->s.angles = {}; // Angles will be set by the first path_corner
	self->moveType = MoveType::Push;

	// Reuse the standard train blocking behavior
	self->moveInfo.blocked = train_blocked;
	if (self->spawnFlags.has(SPAWNFLAG_TRAIN_BLOCK_STOPS))
		self->dmg = 0;
	else if (!self->dmg)
		self->dmg = 2;

	self->solid = SOLID_BSP;
	gi.setModel(self, self->model);

	// Set up looping sound
	if (st.noise) {
		self->moveInfo.sound_middle = gi.soundIndex(st.noise);
		if (!st.was_key_specified("attenuation")) self->attenuation = ATTN_STATIC;
		else if (self->attenuation == -1) self->s.loopAttenuation = ATTN_LOOP_NONE;
		else self->s.loopAttenuation = self->attenuation;
	}

	if (!self->speed) self->speed = 100;
	if (g_mover_speed_scale->value != 1.0f) self->speed *= g_mover_speed_scale->value;

	self->moveInfo.speed = self->speed;

	self->use = rotate_train_use;
	gi.linkEntity(self);

	if (self->target) {
		// Defer finding the first target to ensure all entities have spawned
		self->nextThink = level.time + FRAME_TIME_S;
		self->think = rotate_train_find;
	}
	else {
		gi.Com_PrintFmt("{}: no target\n", *self);
	}
}

// ================ TRIGGER_ELEVATOR ==================

/*QUAKED trigger_elevator (0.3 0.1 0.6) (-8 -8 -8) (8 8 8) x x x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
This is a trigger that activates a func_train when used.
It is used to control elevators.

"target"		is the name of the func_train to activate.
"pathTarget"	is the name of the path_corner to activate.
 */
static USE(trigger_elevator_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	if (self->moveTarget->nextThink)
		return;

	if (!other->pathTarget) {
		gi.Com_PrintFmt("{}: elevator used with no pathTarget\n", *self);
		return;
	}

	gentity_t* target = PickTarget(other->pathTarget);
	if (!target) {
		gi.Com_PrintFmt("{}: elevator used with bad pathTarget: {}\n", *self, other->pathTarget);
		return;
	}

	self->moveTarget->targetEnt = target;
	train_resume(self->moveTarget);
}

static THINK(trigger_elevator_init) (gentity_t* self) -> void {
	if (!self->target) {
		gi.Com_PrintFmt("{}: has no target\n", *self);
		return;
	}
	self->moveTarget = PickTarget(self->target);
	if (!self->moveTarget) {
		gi.Com_PrintFmt("{}: unable to find target {}\n", *self, self->target);
		return;
	}
	if (strcmp(self->moveTarget->className, "func_train") != 0) {
		gi.Com_PrintFmt("{}: target {} is not a train\n", *self, self->target);
		return;
	}

	self->use = trigger_elevator_use;
	self->svFlags = SVF_NOCLIENT;
}

void SP_trigger_elevator(gentity_t* self) {
	self->think = trigger_elevator_init;
	self->nextThink = level.time + FRAME_TIME_S;
}

/*QUAKED func_timer (0.3 0.1 0.6) (-8 -8 -8) (8 8 8) START_ON x x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
This is used to trigger targets at intervals.

"wait"			base time between triggering all targets, default is 1
"random"		wait variance, default is 0

The basic time between firing is a random time between
(wait - random) and (wait + random)

"delay"			delay before first firing when turned on, default is 0
"pauseTime"		additional delay used only the very first time
				and only if spawned with START_ON

START_ON		the timer will start when spawned, otherwise it will wait for a trigger event.
				When START_ON is used, the timer will not fire until the pauseTime has elapsed.
				This is useful for setting up a timer that starts after a level has loaded.
*/

constexpr SpawnFlags SPAWNFLAG_TIMER_START_ON = 1_spawnflag;

static THINK(func_timer_think) (gentity_t* self) -> void {
	UseTargets(self, self->activator);
	self->nextThink = level.time + GameTime::from_sec(self->wait + crandom() * self->random);
}

static USE(func_timer_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	self->activator = activator;

	// if on, turn it off
	if (self->nextThink) {
		self->nextThink = 0_ms;
		return;
	}

	// turn it on
	if (self->delay)
		self->nextThink = level.time + GameTime::from_sec(self->delay);
	else
		func_timer_think(self);
}

void SP_func_timer(gentity_t* self) {
	if (!self->wait)
		self->wait = 1.0;

	self->use = func_timer_use;
	self->think = func_timer_think;

	if (self->random >= self->wait) {
		self->random = self->wait - gi.frameTimeSec;
		gi.Com_PrintFmt("{}: random >= wait\n", *self);
	}

	if (self->spawnFlags.has(SPAWNFLAG_TIMER_START_ON)) {
		self->nextThink = level.time + 1_sec + GameTime::from_sec(st.pauseTime + self->delay + self->wait + crandom() * self->random);
		self->activator = self;
	}

	self->svFlags = SVF_NOCLIENT;
}

constexpr SpawnFlags SPAWNFLAG_CONVEYOR_START_ON = 1_spawnflag;
constexpr SpawnFlags SPAWNFLAG_CONVEYOR_TOGGLE = 2_spawnflag;

/*QUAKED func_conveyor (0 .5 .8) ? START_ON TOGGLE x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
Conveyors are stationary brushes that move what's on them.
The brush should be have a surface with at least one current content enabled.
"speed"		determines how fast the conveyor moves; default value is 100.

START_ON	the conveyor will start moving when spawned.
TOGGLE		the conveyor will wait in the stopped state for a trigger event.
			If not set, the conveyor will start moving when spawned and never stop.
*/
static USE(func_conveyor_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	if (self->spawnFlags.has(SPAWNFLAG_CONVEYOR_START_ON)) {
		self->speed = 0;
		self->spawnFlags &= ~SPAWNFLAG_CONVEYOR_START_ON;
	}
	else {
		self->speed = (float)self->count;
		self->spawnFlags |= SPAWNFLAG_CONVEYOR_START_ON;
	}

	if (!self->spawnFlags.has(SPAWNFLAG_CONVEYOR_TOGGLE))
		self->count = 0;
}

void SP_func_conveyor(gentity_t* self) {
	if (!self->speed)
		self->speed = 100;

	if (!self->spawnFlags.has(SPAWNFLAG_CONVEYOR_START_ON)) {
		self->count = (int)self->speed;
		self->speed = 0;
	}

	self->use = func_conveyor_use;

	gi.setModel(self, self->model);
	self->solid = SOLID_BSP;
	gi.linkEntity(self);
}

/*
=============================================================================

SECRET DOOR 1

=============================================================================
*/

/*QUAKED func_door_secret (0 .5 .8) ? ALWAYS_SHOOT 1ST_LEFT 1ST_DOWN x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
A secret door. Slides back and then to the side.

ALWAYS_SHOOT	door is shootable even if targeted
1ST_LEFT		1st move is left of arrow
1ST_DOWN		1st move is down from arrow

"angle"		determines the direction
"dmg"		damage to inflict when blocked (default 2)
"wait"		how long to hold in the open position (default 5, -1 means hold)
"speed"		movement speed (default 50)
"noise_start"	overrides default "doors/dr1_strt.wav"
"noise_middle"	overrides default "doors/dr1_mid.wav"
"noise_end"		overrides default "doors/dr1_end.wav"
"message"		message to display when the door is used (default none)
*/

constexpr SpawnFlags SPAWNFLAG_SECRET_ALWAYS_SHOOT = 1_spawnflag;
constexpr SpawnFlags SPAWNFLAG_SECRET_1ST_LEFT = 2_spawnflag;
constexpr SpawnFlags SPAWNFLAG_SECRET_1ST_DOWN = 4_spawnflag;

void door_secret_move1(gentity_t* self);
void door_secret_move2(gentity_t* self);
void door_secret_move3(gentity_t* self);
void door_secret_move4(gentity_t* self);
void door_secret_move5(gentity_t* self);
void door_secret_move6(gentity_t* self);
void door_secret_done(gentity_t* self);

static USE(door_secret_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	// make sure we're not already moving
	if (self->s.origin)
		return;

	Move_Calc(self, self->pos1, door_secret_move1);
	door_use_areaportals(self, true);
}

MOVEINFO_ENDFUNC(door_secret_move1) (gentity_t* self) -> void {
	self->nextThink = level.time + 1_sec;
	self->think = door_secret_move2;
}

THINK(door_secret_move2) (gentity_t* self) -> void {
	Move_Calc(self, self->pos2, door_secret_move3);
}

MOVEINFO_ENDFUNC(door_secret_move3) (gentity_t* self) -> void {
	if (self->wait == -1)
		return;
	self->nextThink = level.time + GameTime::from_sec(self->wait);
	self->think = door_secret_move4;
}

THINK(door_secret_move4) (gentity_t* self) -> void {
	Move_Calc(self, self->pos1, door_secret_move5);
}

MOVEINFO_ENDFUNC(door_secret_move5) (gentity_t* self) -> void {
	self->nextThink = level.time + 1_sec;
	self->think = door_secret_move6;
}

THINK(door_secret_move6) (gentity_t* self) -> void {
	Move_Calc(self, vec3_origin, door_secret_done);
}

MOVEINFO_ENDFUNC(door_secret_done) (gentity_t* self) -> void {
	if (!(self->targetName) || self->spawnFlags.has(SPAWNFLAG_SECRET_ALWAYS_SHOOT)) {
		self->health = 0;
		self->takeDamage = true;
	}
	door_use_areaportals(self, false);
}

MOVEINFO_BLOCKED(door_secret_blocked) (gentity_t* self, gentity_t* other) -> void {
	if (!(other->svFlags & SVF_MONSTER) && (!other->client)) {
		// give it a chance to go away on it's own terms (like gibs)
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, 100000, 1, DamageFlags::Normal, ModID::Crushed);
		// if it's still there, nuke it
		if (other && other->inUse && other->solid)
			BecomeExplosion1(other);
		return;
	}

	if (level.time < self->touch_debounce_time)
		return;
	self->touch_debounce_time = level.time + 500_ms;

	Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, self->dmg, 1, DamageFlags::Normal, ModID::Crushed);
}

static DIE(door_secret_die) (gentity_t* self, gentity_t* inflictor, gentity_t* attacker, int damage, const Vector3& point, const MeansOfDeath& mod) -> void {
	self->takeDamage = false;
	door_secret_use(self, attacker, attacker);
}

void SP_func_door_secret(gentity_t* ent) {
	Vector3 forward, right, up;
	float  side;
	float  width;
	float  length;

	G_SetMoveinfoSounds(ent, "doors/dr1_strt.wav", "doors/dr1_mid.wav", "doors/dr1_end.wav");

	ent->attenuation = ATTN_STATIC;

	ent->moveType = MoveType::Push;
	ent->solid = SOLID_BSP;
	ent->svFlags |= SVF_DOOR;
	gi.setModel(ent, ent->model);

	ent->moveInfo.blocked = door_secret_blocked;
	ent->use = door_secret_use;

	if (!(ent->targetName) || ent->spawnFlags.has(SPAWNFLAG_SECRET_ALWAYS_SHOOT)) {
		ent->health = 0;
		ent->takeDamage = true;
		ent->die = door_secret_die;
	}

	if (!ent->dmg)
		ent->dmg = 2;

	if (!ent->wait)
		ent->wait = 5;

	if (!ent->speed)
		ent->speed = 50;

	ent->moveInfo.accel = ent->moveInfo.decel = ent->moveInfo.speed = ent->speed;

	// calculate positions
	AngleVectors(ent->s.angles, forward, right, up);
	ent->s.angles = {};
	side = 1.0f - (ent->spawnFlags.has(SPAWNFLAG_SECRET_1ST_LEFT) ? 2 : 0);
	if (ent->spawnFlags.has(SPAWNFLAG_SECRET_1ST_DOWN))
		width = std::fabs(up.dot(ent->size));
	else
		width = std::fabs(right.dot(ent->size));
	length = std::fabs(forward.dot(ent->size));
	if (ent->spawnFlags.has(SPAWNFLAG_SECRET_1ST_DOWN))
		ent->pos1 = ent->s.origin + (up * (-1 * width));
	else
		ent->pos1 = ent->s.origin + (right * (side * width));
	ent->pos2 = ent->pos1 + (forward * length);

	if (ent->health) {
		ent->takeDamage = true;
		ent->die = door_killed;
		ent->maxHealth = ent->health;
	}
	else if (ent->targetName && ent->message) {
		gi.soundIndex("misc/talk.wav");
		ent->touch = door_touch;
	}

	gi.linkEntity(ent);
}

/*
=============================================================================

SECRET DOOR 2

=============================================================================
*/

/*QUAKED func_door_secret2 (0 .5 .8) ? OPEN_ONCE x 1ST_DOWN x ALWAYS_SHOOT SLIDE_RIGHT SLIDE_FORWARD x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
Basic secret door. Slides back, then to the left. Angle determines direction.

FLAGS:
OPEN_ONCE = not implemented yet
1ST_DOWN = 1st move is forwards/backwards
ALWAYS_SHOOT = even if targeted, keep shootable
SLIDE_RIGHT = the sideways move will be to right of arrow
SLIDE_FORWARD = the to/fro move will be forward

"angle"		determines the direction,
			0 = forward, 90 = right, 180 = backward, 270 = left
"dmg"		damage to inflict when blocked (default 2)
"wait"		how long to hold in the open position (default 5, -1 means hold)
"speed"		movement speed (default 50)
*/

constexpr SpawnFlags SPAWNFLAG_SEC_OPEN_ONCE = 1_spawnflag; // stays open
// constexpr uint32_t SPAWNFLAG_SEC_1ST_LEFT		= 2_spawnflag;         // unused // 1st move is left of arrow
constexpr SpawnFlags SPAWNFLAG_SEC_1ST_DOWN = 4_spawnflag; // 1st move is down from arrow
// constexpr uint32_t SPAWNFLAG_SEC_NO_SHOOT		= 8_spawnflag;         // unused // only opened by trigger
constexpr SpawnFlags SPAWNFLAG_SEC_YES_SHOOT = 16_spawnflag; // shootable even if targeted
constexpr SpawnFlags SPAWNFLAG_SEC_MOVE_RIGHT = 32_spawnflag;
constexpr SpawnFlags SPAWNFLAG_SEC_MOVE_FORWARD = 64_spawnflag;

void door_secret2_move1(gentity_t* self);
void door_secret2_move2(gentity_t* self);
void door_secret2_move3(gentity_t* self);
void door_secret2_move4(gentity_t* self);
void door_secret2_move5(gentity_t* self);
void door_secret2_move6(gentity_t* self);
void door_secret2_done(gentity_t* self);

static USE(door_secret2_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	gentity_t* ent;

	if (self->flags & FL_TEAMSLAVE)
		return;

	// trigger all paired doors
	for (ent = self; ent; ent = ent->teamChain)
		Move_Calc(ent, ent->moveInfo.startOrigin, door_secret2_move1);
}

static DIE(door_secret2_killed) (gentity_t* self, gentity_t* inflictor, gentity_t* attacker, int damage, const Vector3& point, const MeansOfDeath& mod) -> void {
	self->health = self->maxHealth;
	self->takeDamage = false;

	if (self->flags & FL_TEAMSLAVE && self->teamMaster && self->teamMaster->takeDamage != false)
		door_secret2_killed(self->teamMaster, inflictor, attacker, damage, point, mod);
	else
		door_secret2_use(self, inflictor, attacker);
}

// Wait after first movement...
MOVEINFO_ENDFUNC(door_secret2_move1) (gentity_t* self) -> void {
	self->nextThink = level.time + 1_sec;
	self->think = door_secret2_move2;
}

// Start moving sideways w/sound...
THINK(door_secret2_move2) (gentity_t* self) -> void {
	Move_Calc(self, self->moveInfo.endOrigin, door_secret2_move3);
}

// Wait here until time to go back...
MOVEINFO_ENDFUNC(door_secret2_move3) (gentity_t* self) -> void {
	if (!self->spawnFlags.has(SPAWNFLAG_SEC_OPEN_ONCE)) {
		self->nextThink = level.time + GameTime::from_sec(self->wait);
		self->think = door_secret2_move4;
	}
}

// Move backward...
THINK(door_secret2_move4) (gentity_t* self) -> void {
	Move_Calc(self, self->moveInfo.startOrigin, door_secret2_move5);
}

// Wait 1 second...
MOVEINFO_ENDFUNC(door_secret2_move5) (gentity_t* self) -> void {
	self->nextThink = level.time + 1_sec;
	self->think = door_secret2_move6;
}

static THINK(door_secret2_move6) (gentity_t* self) -> void {
	Move_Calc(self, self->moveOrigin, door_secret2_done);
}

MOVEINFO_ENDFUNC(door_secret2_done) (gentity_t* self) -> void {
	if (!self->targetName || self->spawnFlags.has(SPAWNFLAG_SEC_YES_SHOOT)) {
		self->health = 1;
		self->takeDamage = true;
		self->die = door_secret2_killed;
	}
}

MOVEINFO_BLOCKED(door_secret2_blocked) (gentity_t* self, gentity_t* other) -> void {
	if (!(self->flags & FL_TEAMSLAVE))
		Damage(other, self, self, vec3_origin, other->s.origin, vec3_origin, self->dmg, 0, DamageFlags::Normal, ModID::Crushed);
}

static TOUCH(door_secret2_touch) (gentity_t* self, gentity_t* other, const trace_t& tr, bool otherTouchingSelf) -> void {
	if (other->health <= 0)
		return;

	if (!(other->client))
		return;

	if (self->monsterInfo.attackFinished > level.time)
		return;

	self->monsterInfo.attackFinished = level.time + 2_sec;

	if (self->message)
		gi.LocCenter_Print(other, self->message);
}

void SP_func_door_secret2(gentity_t* ent) {
	Vector3 forward, right, up;
	float  lrSize, fbSize;

	G_SetMoveinfoSounds(ent, "doors/dr1_strt.wav", "doors/dr1_mid.wav", "doors/dr1_end.wav");

	AngleVectors(ent->s.angles, forward, right, up);
	ent->moveOrigin = ent->s.origin;
	ent->moveAngles = ent->s.angles;

	SetMoveDir(ent->s.angles, ent->moveDir);
	ent->moveType = MoveType::Push;
	ent->solid = SOLID_BSP;
	gi.setModel(ent, ent->model);

	if (ent->moveAngles[YAW] == 0 || ent->moveAngles[YAW] == 180) {
		lrSize = ent->size[1];
		fbSize = ent->size[0];
	}
	else if (ent->moveAngles[YAW] == 90 || ent->moveAngles[YAW] == 270) {
		lrSize = ent->size[0];
		fbSize = ent->size[1];
	}
	else {
		gi.Com_PrintFmt("{}: not at 0/90/180/270!\n", *ent);
		FreeEntity(ent);
		return;
	}

	if (ent->spawnFlags.has(SPAWNFLAG_SEC_MOVE_FORWARD))
		forward *= fbSize;
	else
		forward *= fbSize * -1;

	if (ent->spawnFlags.has(SPAWNFLAG_SEC_MOVE_RIGHT))
		right *= lrSize;
	else
		right *= lrSize * -1;

	if (ent->spawnFlags.has(SPAWNFLAG_SEC_1ST_DOWN)) {
		ent->moveInfo.startOrigin = ent->s.origin + forward;
		ent->moveInfo.endOrigin = ent->moveInfo.startOrigin + right;
	}
	else {
		ent->moveInfo.startOrigin = ent->s.origin + right;
		ent->moveInfo.endOrigin = ent->moveInfo.startOrigin + forward;
	}

	ent->touch = door_secret2_touch;
	ent->moveInfo.blocked = door_secret2_blocked;
	ent->use = door_secret2_use;

	if (!ent->dmg)
		ent->dmg = 2;

	if (!ent->wait)
		ent->wait = 5;

	if (!ent->speed)
		ent->speed = 50;

	ent->moveInfo.accel = ent->moveInfo.decel = ent->moveInfo.speed = ent->speed;

	if (!ent->targetName || ent->spawnFlags.has(SPAWNFLAG_SEC_YES_SHOOT)) {
		ent->health = 1;
		ent->maxHealth = ent->health;
		ent->takeDamage = true;
		ent->die = door_secret2_killed;
	}

	gi.linkEntity(ent);
}

// ==================================================

/*QUAKED func_force_wall (1 0 1) ? START_ON x x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
A vertical particle force wall. Turns on and solid when triggered.
If someone is in the force wall when it turns on, they're telefragged.

START_ON - forcewall begins activated. triggering will turn it off.

"style" - color of particles to use.
	208: green, 240: red, 241: blue, 224: orange
*/

constexpr SpawnFlags SPAWNFLAG_FORCEWALL_START_ON = 1_spawnflag;

static THINK(force_wall_think) (gentity_t* self) -> void {
	if (!self->wait) {
		gi.WriteByte(svc_temp_entity);
		gi.WriteByte(TE_FORCEWALL);
		gi.WritePosition(self->pos1);
		gi.WritePosition(self->pos2);
		gi.WriteByte(self->style);
		gi.multicast(self->offset, MULTICAST_PVS, false);
	}

	self->think = force_wall_think;
	self->nextThink = level.time + 10_hz;
}

static USE(force_wall_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	if (!self->wait) {
		self->wait = 1;
		self->think = nullptr;
		self->nextThink = 0_ms;
		self->solid = SOLID_NOT;
		gi.linkEntity(self);
	}
	else {
		self->wait = 0;
		self->think = force_wall_think;
		self->nextThink = level.time + 10_hz;
		self->solid = SOLID_BSP;
		gi.linkEntity(self);
		KillBox(self, false); // Is this appropriate?
	}
}

void SP_func_force_wall(gentity_t* ent) {
	gi.setModel(ent, ent->model);

	ent->offset[0] = (ent->absMax[0] + ent->absMin[0]) / 2;
	ent->offset[1] = (ent->absMax[1] + ent->absMin[1]) / 2;
	ent->offset[2] = (ent->absMax[2] + ent->absMin[2]) / 2;

	ent->pos1[2] = ent->absMax[2];
	ent->pos2[2] = ent->absMax[2];
	if (ent->size[0] > ent->size[1]) {
		ent->pos1[0] = ent->absMin[0];
		ent->pos2[0] = ent->absMax[0];
		ent->pos1[1] = ent->offset[1];
		ent->pos2[1] = ent->offset[1];
	}
	else {
		ent->pos1[0] = ent->offset[0];
		ent->pos2[0] = ent->offset[0];
		ent->pos1[1] = ent->absMin[1];
		ent->pos2[1] = ent->absMax[1];
	}

	if (!ent->style)
		ent->style = 208;

	ent->moveType = MoveType::None;
	ent->wait = 1;

	if (ent->spawnFlags.has(SPAWNFLAG_FORCEWALL_START_ON)) {
		ent->solid = SOLID_BSP;
		ent->think = force_wall_think;
		ent->nextThink = level.time + 10_hz;
	}
	else
		ent->solid = SOLID_NOT;

	ent->use = force_wall_use;

	ent->svFlags = SVF_NOCLIENT;

	gi.linkEntity(ent);
}

// -----------------

/*QUAKED func_killbox (1 0 0) ? x DEADLY_COOP EXACT_COLLISION x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
Kills everything inside when fired, irrespective of protection.

DEADLY_COOP - if set, the killbox will be deadly in coop mode, killing players and monsters alike.
EXACT_COLLISION - if set, the killbox will only kill entities that are exactly inside it, not just touching it.
*/
constexpr SpawnFlags SPAWNFLAG_KILLBOX_DEADLY_COOP = 2_spawnflag;
constexpr SpawnFlags SPAWNFLAG_KILLBOX_EXACT_COLLISION = 4_spawnflag;

static USE(use_killbox) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	if (self->spawnFlags.has(SPAWNFLAG_KILLBOX_DEADLY_COOP))
		level.campaign.deadly_kill_box = true;

	self->solid = SOLID_TRIGGER;
	gi.linkEntity(self);

	KillBox(self, false, ModID::Telefragged, self->spawnFlags.has(SPAWNFLAG_KILLBOX_EXACT_COLLISION));

	self->solid = SOLID_NOT;
	gi.linkEntity(self);

	level.campaign.deadly_kill_box = false;
}

void SP_func_killbox(gentity_t* ent) {
	gi.setModel(ent, ent->model);
	ent->use = use_killbox;
	ent->svFlags = SVF_NOCLIENT;
}

/*QUAKED func_eye (0 1 0) ? x x x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
Camera-like eye that can track entities.

"pathTarget" point to an info_notnull (which gets freed after spawn) to automatically set
the eye_position
"target"/"killTarget"/"delay"/"message" target keys to fire when we first spot a player
"eye_position" manually set the eye position; note that this is in "forward right up" format, relative to
the origin of the brush and using the entity's angles
"radius" default 512, detection radius for entities
"speed" default 45, how fast, in degrees per second, we should move on each axis to reach the target
"yawSpeed" default 0.5, how fast, in degrees per second, we should turn to face the target
"vision_cone" default 0.5 for half cone; how wide the cone of vision should be (relative to their initial angles)
"wait" default 0, the amount of time to wait before returning to neutral angles
*/
constexpr SpawnFlags SPAWNFLAG_FUNC_EYE_FIRED_TARGETS = 17_spawnflag_bit; // internal use only

static THINK(func_eye_think) (gentity_t* self) -> void {
	// find enemy to track
	float closest_dist = 0;
	gentity_t* closest_player = nullptr;

	for (auto player : active_clients()) {
		Vector3 dir = player->s.origin - self->s.origin;
		float dist = dir.normalize();

		if (dir.dot(self->moveDir) < self->yawSpeed)
			continue;

		if (dist >= self->splashRadius)
			continue;

		if (!closest_player || dist < closest_dist) {
			closest_player = player;
			closest_dist = dist;
		}
	}

	self->enemy = closest_player;

	// tracking player
	Vector3 wanted_angles;

	Vector3 fwd, rgt, up;
	AngleVectors(self->s.angles, fwd, rgt, up);

	Vector3 eye_pos = self->s.origin;
	eye_pos += fwd * self->moveOrigin[_X];
	eye_pos += rgt * self->moveOrigin[_Y];
	eye_pos += up * self->moveOrigin[_Z];

	if (self->enemy) {
		if (!(self->spawnFlags & SPAWNFLAG_FUNC_EYE_FIRED_TARGETS)) {
			UseTargets(self, self->enemy);
			self->spawnFlags |= SPAWNFLAG_FUNC_EYE_FIRED_TARGETS;
		}

		Vector3 dir = (self->enemy->s.origin - eye_pos).normalized();
		wanted_angles = VectorToAngles(dir);

		self->s.frame = 2;
		self->timeStamp = level.time + GameTime::from_sec(self->wait);
	}
	else {
		if (self->timeStamp <= level.time) {
			// return to neutral
			wanted_angles = self->moveAngles;
			self->s.frame = 0;
		}
		else
			wanted_angles = self->s.angles;
	}

	for (int i = 0; i < 2; i++) {
		float current = anglemod(self->s.angles[i]);
		float ideal = wanted_angles[i];

		if (current == ideal)
			continue;

		float move = ideal - current;

		if (ideal > current) {
			if (move >= 180)
				move = move - 360;
		}
		else {
			if (move <= -180)
				move = move + 360;
		}
		if (move > 0) {
			if (move > self->speed)
				move = self->speed;
		}
		else {
			if (move < -self->speed)
				move = -self->speed;
		}

		self->s.angles[i] = anglemod(current + move);
	}

	self->nextThink = level.time + FRAME_TIME_S;
}

static THINK(func_eye_setup) (gentity_t* self) -> void {
	gentity_t* eye_pos = PickTarget(self->pathTarget);

	if (!eye_pos)
		gi.Com_PrintFmt("{}: bad target\n", *self);
	else
		self->moveOrigin = eye_pos->s.origin - self->s.origin;

	self->moveDir = self->moveOrigin.normalized();

	self->think = func_eye_think;
	self->nextThink = level.time + 10_hz;
}

void SP_func_eye(gentity_t* ent) {
	ent->moveType = MoveType::Push;
	ent->solid = SOLID_BSP;
	gi.setModel(ent, ent->model);

	if (!st.radius)
		ent->splashRadius = 512;
	else
		ent->splashRadius = st.radius;

	if (!ent->speed)
		ent->speed = 45;

	if (!ent->yawSpeed)
		ent->yawSpeed = 0.5f;

	ent->speed *= gi.frameTimeSec;
	ent->moveAngles = ent->s.angles;

	ent->wait = 1.0f;

	if (ent->pathTarget) {
		ent->think = func_eye_setup;
		ent->nextThink = level.time + 10_hz;
	}
	else {
		ent->think = func_eye_think;
		ent->nextThink = level.time + 10_hz;

		Vector3 right, up;
		AngleVectors(ent->moveAngles, ent->moveDir, right, up);

		Vector3 moveOrigin = ent->moveOrigin;
		ent->moveOrigin = ent->moveDir * moveOrigin[_X];
		ent->moveOrigin += right * moveOrigin[_Y];
		ent->moveOrigin += up * moveOrigin[_Z];
	}

	gi.linkEntity(ent);
}


/*QUAKED rotating_light (0 .5 .8) (-8 -8 -8) (8 8 8) START_OFF ALARM x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
Rotating dynamic spot light.

START_OFF	if set, the light will not start spinning until used.
ALARM		if set, the light will play an alarm sound when it starts spinning.
			Note that the sound will not stop until the light is killed.
			The sound is "misc/alarm.wav" by default, but can be overridden with "sound_start".

"health"	if set, the light may be killed.
"speed"		sets light radius
*/

constexpr SpawnFlags SPAWNFLAG_ROTATING_LIGHT_START_OFF = 1_spawnflag;
constexpr SpawnFlags SPAWNFLAG_ROTATING_LIGHT_ALARM = 2_spawnflag;

static THINK(rotating_light_alarm) (gentity_t* self) -> void {
	if (self->spawnFlags.has(SPAWNFLAG_ROTATING_LIGHT_START_OFF)) {
		self->think = nullptr;
		self->nextThink = 0_ms;
	}
	else {
		gi.sound(self, CHAN_NO_PHS_ADD | CHAN_VOICE, self->moveInfo.sound_start, 1, ATTN_STATIC, 0);
		self->nextThink = level.time + 1_sec;
	}
}

static DIE(rotating_light_killed) (gentity_t* self, gentity_t* inflictor, gentity_t* attacker, int damage, const Vector3& point, const MeansOfDeath& mod) -> void {
	gi.WriteByte(svc_temp_entity);
	gi.WriteByte(TE_WELDING_SPARKS);
	gi.WriteByte(30);
	gi.WritePosition(self->s.origin);
	gi.WriteDir(vec3_origin);
	gi.WriteByte(irandom(0xe0, 0xe8));
	gi.multicast(self->s.origin, MULTICAST_PVS, false);

	self->s.effects &= ~EF_SPINNINGLIGHTS;
	self->use = nullptr;

	self->think = FreeEntity;
	self->nextThink = level.time + FRAME_TIME_S;
}

static USE(rotating_light_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	if (self->spawnFlags.has(SPAWNFLAG_ROTATING_LIGHT_START_OFF)) {
		self->spawnFlags &= ~SPAWNFLAG_ROTATING_LIGHT_START_OFF;
		self->s.effects |= EF_SPINNINGLIGHTS;

		if (self->spawnFlags.has(SPAWNFLAG_ROTATING_LIGHT_ALARM)) {
			self->think = rotating_light_alarm;
			self->nextThink = level.time + FRAME_TIME_S;
		}
	}
	else {
		self->spawnFlags |= SPAWNFLAG_ROTATING_LIGHT_START_OFF;
		self->s.effects &= ~EF_SPINNINGLIGHTS;
	}
}

void SP_rotating_light(gentity_t* self) {
	self->moveType = MoveType::Stop;
	self->solid = SOLID_BBOX;

	self->s.modelIndex = gi.modelIndex("models/objects/light/tris.md2");

	self->s.frame = 0;

	self->use = rotating_light_use;

	if (self->spawnFlags.has(SPAWNFLAG_ROTATING_LIGHT_START_OFF))
		self->s.effects &= ~EF_SPINNINGLIGHTS;
	else {
		self->s.effects |= EF_SPINNINGLIGHTS;
	}

	if (!self->speed)
		self->speed = 32;
	// this is a real cheap way
	// to set the radius of the light
	// self->s.frame = self->speed;

	if (!self->health) {
		self->health = 10;
		self->maxHealth = self->health;
		self->die = rotating_light_killed;
		self->takeDamage = true;
	}
	else {
		self->maxHealth = self->health;
		self->die = rotating_light_killed;
		self->takeDamage = true;
	}

	if (self->spawnFlags.has(SPAWNFLAG_ROTATING_LIGHT_ALARM)) {
		self->moveInfo.sound_start = gi.soundIndex("misc/alarm.wav");
	}

	gi.linkEntity(self);
}

/*QUAKED func_object_repair (1 .5 0) (-8 -8 -8) (8 8 8) x x x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
An object to be repaired.

"delay"		the delay in seconds between sparks (default 1 second)
"health"	the health of the object (default 100)
*/

static THINK(object_repair_fx) (gentity_t* ent) -> void {
	ent->nextThink = level.time + GameTime::from_sec(ent->delay);

	if (ent->health <= 100)
		ent->health++;
	else {
		gi.WriteByte(svc_temp_entity);
		gi.WriteByte(TE_WELDING_SPARKS);
		gi.WriteByte(10);
		gi.WritePosition(ent->s.origin);
		gi.WriteDir(vec3_origin);
		gi.WriteByte(irandom(0xe0, 0xe8));
		gi.multicast(ent->s.origin, MULTICAST_PVS, false);
	}
}

static THINK(object_repair_dead) (gentity_t* ent) -> void {
	UseTargets(ent, ent);
	ent->nextThink = level.time + 10_hz;
	ent->think = object_repair_fx;
}

static THINK(object_repair_sparks) (gentity_t* ent) -> void {
	if (ent->health <= 0) {
		ent->nextThink = level.time + 10_hz;
		ent->think = object_repair_dead;
		return;
	}

	ent->nextThink = level.time + GameTime::from_sec(ent->delay);

	gi.WriteByte(svc_temp_entity);
	gi.WriteByte(TE_WELDING_SPARKS);
	gi.WriteByte(10);
	gi.WritePosition(ent->s.origin);
	gi.WriteDir(vec3_origin);
	gi.WriteByte(irandom(0xe0, 0xe8));
	gi.multicast(ent->s.origin, MULTICAST_PVS, false);
}

void SP_object_repair(gentity_t* ent) {
	ent->moveType = MoveType::None;
	ent->solid = SOLID_BBOX;
	ent->className = "object_repair";
	ent->mins = { -8, -8, 8 };
	ent->maxs = { 8, 8, 8 };
	ent->think = object_repair_sparks;
	ent->nextThink = level.time + 1_sec;

	if (!ent->health)
		ent->health = 100;
	if (!ent->delay)
		ent->delay = 1.0;
}

/*
===============================================================================

BOBBING

===============================================================================
*/

/*QUAKED func_bobbing (0 .5 .8) ? X_AXIS Y_AXIS
A solid bobbing object that moves up and down, left and right, or forwards and backwards.
Normally bobs on the Z axis

X_AXIS		bobs on the X axis
Y_AXIS		bobs on the Y axis

"model2"	model to also draw
"height"	amplitude of bob (32 default)
"speed"		seconds to complete a bob cycle (4 default)
"phase"		0.0 to 1.0 offset in the cycle to start at (0 default)
"dmg"		damage to inflict when blocked (2 default)
"color"		constantLight color
"light"		constantLight radius
*/
MOVEINFO_BLOCKED(func_bobbing_blocked) (gentity_t* self, gentity_t* other) -> void {
	if (!other || !other->takeDamage)
		return;

	Damage(other, self, self, vec3_origin, self->s.origin, vec3_origin, self->dmg, self->dmg, DamageFlags::NoProtection, ModID::Crushed);
}

static THINK(func_bobbing_think) (gentity_t* ent) -> void {
	const float cycle = ent->speed > 0.0f ? ent->speed : 4.0f;
	const float phase_offset = ent->phase * cycle;
	const float frac = fmodf((level.time.milliseconds() * 0.001f + phase_offset), cycle) / cycle;
	const float angle = frac * M_TWOPI;
	const float bob = std::sinf(angle) * ent->height;

	Vector3 delta = { 0, 0, 0 };

	if (ent->spawnFlags.has(1_spawnflag)) {
		delta[0] = bob;
	}
	else if (ent->spawnFlags.has(2_spawnflag)) {
		delta[1] = bob;
	}
	else {
		delta[2] = bob;
	}

	ent->s.origin = ent->pos1 + delta;
	gi.linkEntity(ent);

	ent->nextThink = level.time + FRAME_TIME_MS;
}

void SP_func_bobbing(gentity_t* ent) {
	if (ent->speed == 0.0f)
		ent->speed = 4.0f;

	if (ent->height == 0.0f)
		ent->height = 32.0f;

	if (ent->dmg == 0)
		ent->dmg = 2;

	// Clamp phase
	if (ent->phase < 0.0f)
		ent->phase = 0.0f;
	else if (ent->phase > 1.0f)
		ent->phase = 1.0f;

	// Set up as a solid BSP mover
	gi.setModel(ent, ent->model);
	ent->moveType = MoveType::Push;
	ent->solid = SOLID_BSP;
	ent->moveInfo.blocked = func_bobbing_blocked;

	ent->pos1 = ent->s.origin; // base origin

	// Think loop
	ent->think = func_bobbing_think;
	ent->nextThink = level.time + FRAME_TIME_MS;

	gi.linkEntity(ent);
}

/*QUAKED func_pendulum (0 .5 .8) ?
You need to have an origin brush as part of this entity.
Pendulums always swing north / south on unrotated models.
Add an angles field to the model to allow rotation in other directions.
Pendulum frequency is a physical constant based on the length of the beam and gravity.

"model2"	model to also draw
"speed"		the number of degrees each way the pendulum swings, (30 default)
"phase"		the 0.0 to 1.0 offset in the cycle to start at
"dmg"		damage to inflict when blocked (2 default)
"angles"	the base angles of the pendulum, relative to the origin brush
"color"		constantLight color
"light"		constantLight radius
*/

/*
=================
func_pendulum_blocked
=================
*/
MOVEINFO_BLOCKED(func_pendulum_blocked) (gentity_t* self, gentity_t* other) -> void {
	if (!other || !other->takeDamage)
		return;

	Damage(other, self, self, vec3_origin, self->s.origin, vec3_origin, self->dmg, 0, DamageFlags::NoProtection, ModID::Crushed);
}

/*
=================
func_pendulum_think
=================
*/
static THINK(func_pendulum_think) (gentity_t* ent) -> void {
	const float cycle = ent->speed > 0.0f ? ent->speed : 30.0f; // temporary use for swing angle
	const float duration = ent->wait; // seconds
	const float frac = fmodf(level.time.milliseconds() + ent->phase * duration, duration) / duration;
	const float angle = std::sinf(frac * M_TWOPI) * cycle;

	ent->s.angles = ent->pos1; // reset to base position
	ent->s.angles[ROLL] += angle;

	gi.linkEntity(ent);

	ent->nextThink = level.time + FRAME_TIME_MS;
}

/*
=================
SP_func_pendulum
=================
*/
void SP_func_pendulum(gentity_t* ent) {
	if (ent->speed == 0.0f)
		ent->speed = 30.0f;

	if (ent->dmg == 0)
		ent->dmg = 2;

	// Clamp phase
	if (ent->phase < 0.0f)
		ent->phase = 0.0f;
	else if (ent->phase > 1.0f)
		ent->phase = 1.0f;

	// Load brush model
	gi.setModel(ent, ent->model);

	// Determine pendulum length (distance from origin to lowest point)
	float length = std::fabs(ent->mins[2]);
	if (length < 8.0f)
		length = 8.0f;

	// Gravity constant
	const float gravity = g_gravity->value;

	// Pendulum frequency formula: f = 1 / (2 PI) * sqrt(g / (3L))
	const float freq = (1.0f / M_TWOPI) * std::sqrt(gravity / (3.0f * length));
	const float period = 1.0f / freq; // seconds per swing

	ent->wait = period; // store period for reuse in think

	ent->solid = SOLID_BSP;
	ent->moveType = MoveType::Push;
	ent->moveInfo.blocked = func_pendulum_blocked;

	ent->pos1 = ent->s.angles; // base rotation

	ent->think = func_pendulum_think;
	ent->nextThink = level.time + FRAME_TIME_MS;

	gi.linkEntity(ent);
}


/*QUAKED func_wall (0 .5 .8) ? TRIGGER_SPAWN TOGGLE START_ON ANIMATED ANIMATED_FAST x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
This is just a solid wall if not inhibited

TRIGGER_SPAWN	the wall will not be present until triggered
				it will then blink in to existance; it will
				kill anything that was in it's way

TOGGLE			only valid for TRIGGER_SPAWN walls
				this allows the wall to be turned on and off

START_ON		only valid for TRIGGER_SPAWN walls
				the wall will initially be present

ANIMATED		the wall will be animated
ANIMATED_FAST	if set, the wall will animate faster than normal
*/

/*QUAKED func_static (0 .5 .8) ? TRIGGER_SPAWN TOGGLE START_ON ANIMATED ANIMATED_FAST x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
This is simply a func_wall, used for compatibility with Q3 maps.
*/

constexpr SpawnFlags SPAWNFLAG_WALL_TRIGGER_SPAWN = 1_spawnflag;
constexpr SpawnFlags SPAWNFLAG_WALL_TOGGLE = 2_spawnflag;
constexpr SpawnFlags SPAWNFLAG_WALL_START_ON = 4_spawnflag;
constexpr SpawnFlags SPAWNFLAG_WALL_ANIMATED = 8_spawnflag;
constexpr SpawnFlags SPAWNFLAG_WALL_ANIMATED_FAST = 16_spawnflag;

static USE(func_wall_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	if (self->solid == SOLID_NOT) {
		self->solid = SOLID_BSP;
		self->svFlags &= ~SVF_NOCLIENT;
		gi.linkEntity(self);
		KillBox(self, false);
	}
	else {
		self->solid = SOLID_NOT;
		self->svFlags |= SVF_NOCLIENT;
		gi.linkEntity(self);
	}

	if (!self->spawnFlags.has(SPAWNFLAG_WALL_TOGGLE))
		self->use = nullptr;
}

void SP_func_wall(gentity_t* self) {
	self->moveType = MoveType::Push;
	gi.setModel(self, self->model);

	if (self->spawnFlags.has(SPAWNFLAG_WALL_ANIMATED))
		self->s.effects |= EF_ANIM_ALL;
	if (self->spawnFlags.has(SPAWNFLAG_WALL_ANIMATED_FAST))
		self->s.effects |= EF_ANIM_ALLFAST;

	// just a wall
	if (!self->spawnFlags.has(SPAWNFLAG_WALL_TRIGGER_SPAWN | SPAWNFLAG_WALL_TOGGLE | SPAWNFLAG_WALL_START_ON)) {
		self->solid = SOLID_BSP;
		gi.linkEntity(self);
		return;
	}

	// it must be TRIGGER_SPAWN
	if (!(self->spawnFlags & SPAWNFLAG_WALL_TRIGGER_SPAWN))
		self->spawnFlags |= SPAWNFLAG_WALL_TRIGGER_SPAWN;

	// yell if the spawnFlags are odd
	if (self->spawnFlags.has(SPAWNFLAG_WALL_START_ON)) {
		if (!self->spawnFlags.has(SPAWNFLAG_WALL_TOGGLE)) {
			gi.Com_PrintFmt("{}: START_ON without TOGGLE\n", *self);
			self->spawnFlags |= SPAWNFLAG_WALL_TOGGLE;
		}
	}

	self->use = func_wall_use;
	if (self->spawnFlags.has(SPAWNFLAG_WALL_START_ON)) {
		self->solid = SOLID_BSP;
	}
	else {
		self->solid = SOLID_NOT;
		self->svFlags |= SVF_NOCLIENT;
	}
	gi.linkEntity(self);
}

/*QUAKED func_illusionary (0 .5 .8) ?
Non-solid brush model.
Used for decorations, fake walls, and effects.
Players, monsters, and projectiles can pass through.

Notes:
- Unlike func_wall, this is never solid.
- For new maps prefer using func_wall with spawnflags (non-solid).
*/
void SP_func_illusionary(gentity_t* ent) {
	// Set brush model
	gi.setModel(ent, ent->model);

	// Never solid
	ent->solid = SOLID_NOT;
	ent->clipMask = CONTENTS_NONE;

	// Some Q1 illusionaries were visible only
	ent->svFlags &= ~SVF_NOCLIENT;

	// Allow rendering
	ent->s.renderFX |= RF_NOSHADOW; // optional, prevent shadow casting

	// Link into world
	gi.linkEntity(ent);
}

// [Paril-KEX]
/*QUAKED func_animation (0 .5 .8) ? START_ON x x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
Similar to func_wall, but triggering it will toggle animation
state rather than going on/off.

START_ON		will start in alterate animation
*/

constexpr SpawnFlags SPAWNFLAG_ANIMATION_START_ON = 1_spawnflag;

static USE(func_animation_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	self->bmodel_anim.alternate = !self->bmodel_anim.alternate;
}

void SP_func_animation(gentity_t* self) {
	if (!self->bmodel_anim.enabled) {
		gi.Com_PrintFmt("{} has no animation data\n", *self);
		FreeEntity(self);
		return;
	}

	self->moveType = MoveType::Push;
	gi.setModel(self, self->model);
	self->solid = SOLID_BSP;

	self->use = func_animation_use;
	self->bmodel_anim.alternate = self->spawnFlags.has(SPAWNFLAG_ANIMATION_START_ON);

	if (self->bmodel_anim.alternate)
		self->s.frame = self->bmodel_anim.alt_start;
	else
		self->s.frame = self->bmodel_anim.start;

	gi.linkEntity(self);
}

/*QUAKED func_object (0 .5 .8) ? TRIGGER_SPAWN ANIMATED ANIMATED_FAST x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
This is solid bmodel that will fall if it's support is removed.

TRIGGER_SPAWN	the object will not be present until triggered
				it will then blink in to existance; it will
				kill anything that was in it's way

ANIMATED		the object will be animated
ANIMATED_FAST	if set, the object will animate faster than normal
*/

constexpr SpawnFlags SPAWNFLAGS_OBJECT_TRIGGER_SPAWN = 1_spawnflag;
constexpr SpawnFlags SPAWNFLAGS_OBJECT_ANIMATED = 2_spawnflag;
constexpr SpawnFlags SPAWNFLAGS_OBJECT_ANIMATED_FAST = 4_spawnflag;

static TOUCH(func_object_touch) (gentity_t* self, gentity_t* other, const trace_t& tr, bool otherTouchingSelf) -> void {
	// only squash thing we fall on top of
	if (otherTouchingSelf)
		return;
	if (tr.plane.normal[2] < 1.0f)
		return;
	if (!other->takeDamage)
		return;
	if (other->damage_debounce_time > level.time)
		return;

	Damage(other, self, self, vec3_origin, closest_point_to_box(other->s.origin, self->absMin, self->absMax), tr.plane.normal, self->dmg, 1, DamageFlags::NoProtection, ModID::Crushed);
	other->damage_debounce_time = level.time + 10_hz;
}

static THINK(func_object_release) (gentity_t* self) -> void {
	self->moveType = MoveType::Toss;
	self->touch = func_object_touch;
}

static USE(func_object_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	self->solid = SOLID_BSP;
	self->svFlags &= ~SVF_NOCLIENT;
	self->use = nullptr;
	func_object_release(self);
	KillBox(self, false);
}

void SP_func_object(gentity_t* self) {
	gi.setModel(self, self->model);

	self->mins[0] += 1;
	self->mins[1] += 1;
	self->mins[2] += 1;
	self->maxs[0] -= 1;
	self->maxs[1] -= 1;
	self->maxs[2] -= 1;

	if (!self->dmg)
		self->dmg = 100;

	if (!(self->spawnFlags & SPAWNFLAGS_OBJECT_TRIGGER_SPAWN)) {
		self->solid = SOLID_BSP;
		self->moveType = MoveType::Push;
		self->think = func_object_release;
		self->nextThink = level.time + 20_hz;
	}
	else {
		self->solid = SOLID_NOT;
		self->moveType = MoveType::Push;
		self->use = func_object_use;
		self->svFlags |= SVF_NOCLIENT;
	}

	if (self->spawnFlags.has(SPAWNFLAGS_OBJECT_ANIMATED))
		self->s.effects |= EF_ANIM_ALL;
	if (self->spawnFlags.has(SPAWNFLAGS_OBJECT_ANIMATED_FAST))
		self->s.effects |= EF_ANIM_ALLFAST;

	self->clipMask = MASK_MONSTERSOLID;
	self->flags |= FL_NO_STANDING;

	gi.linkEntity(self);
}

/*QUAKED func_explosive (0 .5 .8) ? TRIGGER_SPAWN ANIMATED ANIMATED_FAST INACTIVE ALWAYS_SHOOTABLE x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
A bmodel that explodes when shot or triggered and removed in the process.

If targeted it will not be shootable.

TRIGGER_SPAWN - specifies that the entity is not present until triggered. It will then blink into existence.
				Note that it will kill anything that was in its way.
ANIMATED - specifies that the entity is animated.
ANIMATED_FAST - specifies that the entity is animated faster than normal.
INACTIVE - specifies that the entity is not explodable until triggered. If you use this you must
			target the entity you want to trigger it. This is the only entity approved to activate it.
ALWAYS_SHOOTABLE - specifies that the entity is always shootable, even if it is inactive.

"health" defaults to 100.  If set, the entity will not explode until it is damaged.
"dmg" defaults to 100.  This is the damage it does when it explodes.
"mass" defaults to 75.  This is the mass of the entity, which determines how much debris is emitted when it explodes.
			You can set this to a higher value to increase the amount of debris emitted.
			For example, setting mass to 800 will give you the most debris.
			Note that this is not used for damage calculation, only for debris emission.
			You get one large chunk per 100 of mass (up to 8) and
			one small chunk per 25 of mass (up to 16).
"sounds"	preset sound to play when the entity explodes.
1 = glass breaking sound
*/

constexpr SpawnFlags SPAWNFLAGS_EXPLOSIVE_TRIGGER_SPAWN = 1_spawnflag;
constexpr SpawnFlags SPAWNFLAGS_EXPLOSIVE_ANIMATED = 2_spawnflag;
constexpr SpawnFlags SPAWNFLAGS_EXPLOSIVE_ANIMATED_FAST = 4_spawnflag;
constexpr SpawnFlags SPAWNFLAGS_EXPLOSIVE_INACTIVE = 8_spawnflag;
constexpr SpawnFlags SPAWNFLAGS_EXPLOSIVE_ALWAYS_SHOOTABLE = 16_spawnflag;

static DIE(func_explosive_explode) (gentity_t* self, gentity_t* inflictor, gentity_t* attacker, int damage, const Vector3& point, const MeansOfDeath& mod) -> void {
	size_t   count;
	int		 mass;
	gentity_t* master;
	bool	 done = false;

	self->takeDamage = false;

	if (self->dmg)
		RadiusDamage(self, attacker, (float)self->dmg, nullptr, (float)(self->dmg + 40), DamageFlags::Normal, ModID::Explosives);

	self->velocity = inflictor->s.origin - self->s.origin;
	self->velocity.normalize();
	self->velocity *= 150;

	mass = self->mass;
	if (!mass)
		mass = 75;

	// big chunks
	if (mass >= 100) {
		count = mass / 100;
		if (count > 8)
			count = 8;
		ThrowGibs(self, 1, {
			{ count, "models/objects/debris1/tris.md2", GIB_METALLIC | GIB_DEBRIS }
			});
	}

	// small chunks
	count = mass / 25;
	if (count > 16)
		count = 16;
	ThrowGibs(self, 2, {
		{ count, "models/objects/debris2/tris.md2", GIB_METALLIC | GIB_DEBRIS }
		});

	// PMM - if we're part of a train, clean ourselves out of it
	if (self->flags & FL_TEAMSLAVE) {
		if (self->teamMaster) {
			master = self->teamMaster;
			if (master && master->inUse) // because mappers (other than jim (usually)) are stupid....
			{
				while (!done) {
					if (master->teamChain == self) {
						master->teamChain = self->teamChain;
						done = true;
					}
					master = master->teamChain;
				}
			}
		}
	}

	UseTargets(self, attacker);

	self->s.origin = (self->absMin + self->absMax) * 0.5f;

	if (self->noiseIndex)
		gi.positionedSound(self->s.origin, self, CHAN_AUTO, self->noiseIndex, 1, ATTN_NORM, 0);

	if (deathmatch->integer && self->saved) {
		gentity_t* respawner = Spawn();
		respawner->think = Respawn_Think;
		respawner->nextThink = level.time + 1_min;
		respawner->saved = self->saved;
		self->saved = nullptr;
	}

	if (self->dmg)
		BecomeExplosion1(self);
	else
		FreeEntity(self);
}

static USE(func_explosive_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	// Paril: pass activator to explode as attacker. this fixes
	// "strike" trying to centerprint to the relay. Should be
	// a safe change.
	func_explosive_explode(self, self, activator, self->health, vec3_origin, ModID::Explosives);
}

static USE(func_explosive_activate) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	int approved;

	approved = 0;
	// PMM - looked like target and targetName were flipped here
	if (other != nullptr && other->target) {
		if (!strcmp(other->target, self->targetName))
			approved = 1;
	}
	if (!approved && activator != nullptr && activator->target) {
		if (!strcmp(activator->target, self->targetName))
			approved = 1;
	}

	if (!approved)
		return;

	self->use = func_explosive_use;
	if (!self->health)
		self->health = 100;
	self->die = func_explosive_explode;
	self->takeDamage = true;
}
// PGM

static USE(func_explosive_spawn) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	self->solid = SOLID_BSP;
	self->svFlags &= ~SVF_NOCLIENT;
	self->use = nullptr;
	gi.linkEntity(self);
	KillBox(self, false);
}

void SP_func_explosive(gentity_t* self) {
	self->moveType = MoveType::Push;

	gi.modelIndex("models/objects/debris1/tris.md2");
	gi.modelIndex("models/objects/debris2/tris.md2");

	gi.setModel(self, self->model);

	if (self->spawnFlags.has(SPAWNFLAGS_EXPLOSIVE_TRIGGER_SPAWN)) {
		self->svFlags |= SVF_NOCLIENT;
		self->solid = SOLID_NOT;
		self->use = func_explosive_spawn;
	}
	else if (self->spawnFlags.has(SPAWNFLAGS_EXPLOSIVE_INACTIVE)) {
		self->solid = SOLID_BSP;
		if (self->targetName)
			self->use = func_explosive_activate;
	}
	else {
		self->solid = SOLID_BSP;
		if (self->targetName)
			self->use = func_explosive_use;
	}

	if (self->spawnFlags.has(SPAWNFLAGS_EXPLOSIVE_ANIMATED))
		self->s.effects |= EF_ANIM_ALL;
	if (self->spawnFlags.has(SPAWNFLAGS_EXPLOSIVE_ANIMATED_FAST))
		self->s.effects |= EF_ANIM_ALLFAST;

	if (self->spawnFlags.has(SPAWNFLAGS_EXPLOSIVE_ALWAYS_SHOOTABLE) || ((self->use != func_explosive_use) && (self->use != func_explosive_activate))) {
		if (!self->health)
			self->health = 100;
		self->die = func_explosive_explode;
		self->takeDamage = true;
	}

	if (self->sounds) {
		if (self->sounds == 1)
			self->noiseIndex = gi.soundIndex("world/brkglas.wav");
		else
			gi.Com_PrintFmt("{}: invalid \"sounds\" {}\n", *self, self->sounds);
	}

	gi.linkEntity(self);
}

//=====================================================

/*QUAKED func_group (0 0 0) ? x x x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
Used to group brushes together just for editor convenience.
*/

//=====================================================

static USE(Use_Areaportal) (gentity_t* ent, gentity_t* other, gentity_t* activator) -> void {
	ent->count ^= 1; // toggle state
	gi.SetAreaPortalState(ent->style, ent->count);
}

/*QUAKED func_areaportal (0 0 0) ? x x x x x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP

This is a non-visible object that divides the world into
areas that are seperated when this portal is not activated.
Usually enclosed in the middle of a door.
*/
void SP_func_areaportal(gentity_t* ent) {
	ent->use = Use_Areaportal;
	ent->count = 0; // always start closed;
}


/*QUAKED func_clock (0 0 1) (-8 -8 -8) (8 8 8) TIMER_UP TIMER_DOWN START_OFF MULTI_USE x x x x NOT_EASY NOT_MEDIUM NOT_HARD NOT_DM NOT_COOP
target a target_string with this

The default is to be a time of day clock

TIMER_UP and TIMER_DOWN run for "count" seconds and then fire "pathTarget"
If START_OFF, this entity must be used before it starts

"style"		0 "xx"
			1 "xx:xx"
			2 "xx:xx:xx"
*/

constexpr SpawnFlags SPAWNFLAG_TIMER_UP = 1_spawnflag;
constexpr SpawnFlags SPAWNFLAG_TIMER_DOWN = 2_spawnflag;
constexpr SpawnFlags SPAWNFLAG_TIMER_START_OFF = 4_spawnflag;
constexpr SpawnFlags SPAWNFLAG_TIMER_MULTI_USE = 8_spawnflag;

static void func_clock_reset(gentity_t* self) {
	self->activator = nullptr;

	if (self->spawnFlags.has(SPAWNFLAG_TIMER_UP)) {
		self->health = 0;
		self->wait = (float)self->count;
	}
	else if (self->spawnFlags.has(SPAWNFLAG_TIMER_DOWN)) {
		self->health = self->count;
		self->wait = 0;
	}
}

static void func_clock_format_countdown(gentity_t* self) {
	if (self->style == 0) {
		G_FmtTo(self->clock_message, "{:2}", self->health);
		return;
	}

	if (self->style == 1) {
		G_FmtTo(self->clock_message, "{:2}:{:02}", self->health / 60, self->health % 60);
		return;
	}

	if (self->style == 2) {
		G_FmtTo(self->clock_message, "{:2}:{:02}:{:02}", self->health / 3600,
			(self->health - (self->health / 3600) * 3600) / 60, self->health % 60);
		return;
	}
}

static THINK(func_clock_think) (gentity_t* self) -> void {
	if (!self->enemy) {
		self->enemy = G_FindByString<&gentity_t::targetName>(nullptr, self->target);
		if (!self->enemy)
			return;
	}

	if (self->spawnFlags.has(SPAWNFLAG_TIMER_UP)) {
		func_clock_format_countdown(self);
		self->health++;
	}
	else if (self->spawnFlags.has(SPAWNFLAG_TIMER_DOWN)) {
		func_clock_format_countdown(self);
		self->health--;
	}
	else {
		struct tm* ltime;
		time_t	   gmtime;

		time(&gmtime);
		ltime = localtime(&gmtime);
		G_FmtTo(self->clock_message, "{:2}:{:02}:{:02}", ltime->tm_hour, ltime->tm_min,
			ltime->tm_sec);
	}

	self->enemy->message = self->clock_message;
	self->enemy->use(self->enemy, self, self);

	if ((self->spawnFlags.has(SPAWNFLAG_TIMER_UP) && (self->health > self->wait)) ||
		(self->spawnFlags.has(SPAWNFLAG_TIMER_DOWN) && (self->health < self->wait))) {
		if (self->pathTarget) {
			const char* savetarget;

			savetarget = self->target;
			self->target = self->pathTarget;
			UseTargets(self, self->activator);
			self->target = savetarget;
		}

		if (!self->spawnFlags.has(SPAWNFLAG_TIMER_MULTI_USE))
			return;

		func_clock_reset(self);

		if (self->spawnFlags.has(SPAWNFLAG_TIMER_START_OFF))
			return;
	}

	self->nextThink = level.time + 1_sec;
}

static USE(func_clock_use) (gentity_t* self, gentity_t* other, gentity_t* activator) -> void {
	if (!self->spawnFlags.has(SPAWNFLAG_TIMER_MULTI_USE))
		self->use = nullptr;
	if (self->activator)
		return;
	self->activator = activator;
	self->think(self);
}

void SP_func_clock(gentity_t* self) {
	if (!self->target) {
		gi.Com_PrintFmt("{} with no target\n", *self);
		FreeEntity(self);
		return;
	}

	if (self->spawnFlags.has(SPAWNFLAG_TIMER_DOWN) && !self->count) {
		gi.Com_PrintFmt("{} with no count\n", *self);
		FreeEntity(self);
		return;
	}

	if (self->spawnFlags.has(SPAWNFLAG_TIMER_UP) && (!self->count))
		self->count = 60 * 60;

	func_clock_reset(self);

	self->think = func_clock_think;

	if (self->spawnFlags.has(SPAWNFLAG_TIMER_START_OFF))
		self->use = func_clock_use;
	else
		self->nextThink = level.time + 1_sec;
}

