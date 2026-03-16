#include "g_local.h"

#if OBLIVION_ENABLE_ROTATE_TRAIN

#define RTRAIN_START_ON		1
#define RTRAIN_TOGGLE		2
#define RTRAIN_BLOCK_STOPS	4

void train_blocked(edict_t *self, edict_t *other);

static void rotate_train_next(edict_t *self);
static void rotate_train_wait(edict_t *self);
static void rotate_train_resume(edict_t *self);

/*
=============
RotateTrain_WrapAngle

Wrap a completed angle using the retail signed modulo path.
=============
*/
static float RotateTrain_WrapAngle(float angle)
{
	return (float)((int)angle % 360);
}

/*
=============
RotateTrain_MoveDone

Stop translation and rotation, wrap the final angles, and fire the move tail.
=============
*/
static void RotateTrain_MoveDone(edict_t *self)
{
	VectorClear(self->velocity);
	VectorClear(self->avelocity);

	self->s.angles[0] = RotateTrain_WrapAngle(self->s.angles[0]);
	self->s.angles[1] = RotateTrain_WrapAngle(self->s.angles[1]);
	self->s.angles[2] = RotateTrain_WrapAngle(self->s.angles[2]);

	self->moveinfo.endfunc(self);
}

/*
=============
RotateTrain_MoveFinal

Finish the last frame of movement before handing off to RotateTrain_MoveDone.
=============
*/
static void RotateTrain_MoveFinal(edict_t *self)
{
	vec3_t delta;

	if (self->moveinfo.remaining_distance == 0) {
		RotateTrain_MoveDone(self);
		return;
	}

	VectorScale(self->moveinfo.dir, self->moveinfo.remaining_distance * 10.0f,
		    self->velocity);

	if (!VectorCompare(self->rotate, vec3_origin)) {
		VectorSubtract(self->moveinfo.end_angles, self->s.angles, delta);
		if (VectorCompare(delta, vec3_origin))
			VectorClear(self->avelocity);
		else
			VectorScale(delta, 10.0f, self->avelocity);
	}

	self->think = RotateTrain_MoveDone;
	self->nextthink = level.time + FRAMETIME;
}

/*
=============
RotateTrain_MoveBegin

Start the active rotate-train move segment.
=============
*/
static void RotateTrain_MoveBegin(edict_t *self)
{
	vec3_t delta;
	float frames;
	float travel_time;

	if ((self->moveinfo.speed * FRAMETIME) >= self->moveinfo.remaining_distance) {
		RotateTrain_MoveFinal(self);
		return;
	}

	VectorScale(self->moveinfo.dir, self->moveinfo.speed, self->velocity);

	travel_time = self->moveinfo.remaining_distance / self->moveinfo.speed;
	frames = (float)floor(travel_time * 10.0f);
	self->moveinfo.remaining_distance -=
		frames * self->moveinfo.speed * FRAMETIME;

	if (!VectorCompare(self->rotate, vec3_origin)) {
		VectorSubtract(self->moveinfo.end_angles, self->moveinfo.start_angles,
			       delta);

		if (VectorCompare(delta, vec3_origin)) {
			VectorClear(self->avelocity);
		} else {
			if (self->duration > 0)
				travel_time = self->duration;
			else
				travel_time = VectorLength(delta) / self->moveinfo.speed;

			frames = (float)floor(travel_time * 10.0f);
			VectorScale(delta, 1.0f / travel_time, self->avelocity);
		}
	}

	self->think = RotateTrain_MoveFinal;
	self->nextthink = level.time + frames * FRAMETIME;
}

/*
=============
RotateTrain_MoveCalc

Initialize the current rotate-train move segment.
=============
*/
static void RotateTrain_MoveCalc(edict_t *self, vec3_t dest,
				 void (*func)(edict_t *))
{
	VectorClear(self->velocity);
	VectorSubtract(dest, self->s.origin, self->moveinfo.dir);
	self->moveinfo.remaining_distance = VectorNormalize(self->moveinfo.dir);
	self->moveinfo.endfunc = func;

	if (self->duration > 0)
		self->moveinfo.speed =
			self->moveinfo.remaining_distance / self->duration;

	if (!VectorCompare(self->rotate, vec3_origin)) {
		VectorCopy(self->s.angles, self->moveinfo.start_angles);
		VectorCopy(self->s.angles, self->moveinfo.end_angles);
		VectorAdd(self->moveinfo.end_angles, self->rotate,
			  self->moveinfo.end_angles);
	} else if (!VectorCompare(self->rotate_speed, vec3_origin)) {
		VectorCopy(self->rotate_speed, self->avelocity);
	}

	if (level.current_entity ==
	    ((self->flags & FL_TEAMSLAVE) ? self->teammaster : self)) {
		RotateTrain_MoveBegin(self);
	} else {
		self->think = RotateTrain_MoveBegin;
		self->nextthink = level.time + FRAMETIME;
	}
}

/*
=============
rotate_train_wait

Handle the retail end-of-corner callback for func_rotate_train.
=============
*/
static void rotate_train_wait(edict_t *self)
{
	if (self->target_ent->pathtarget) {
		char *savetarget;
		edict_t *ent;

		ent = self->target_ent;
		savetarget = ent->target;
		ent->target = ent->pathtarget;
		G_UseTargets(ent, self->activator);
		ent->target = savetarget;

		if (!self->inuse)
			return;
	}

	if (self->moveinfo.wait) {
		if (self->moveinfo.wait > 0) {
			self->nextthink = level.time + self->moveinfo.wait;
			self->think = rotate_train_next;
		} else if (self->spawnflags & RTRAIN_TOGGLE) {
			rotate_train_next(self);
			self->spawnflags &= ~RTRAIN_START_ON;
			VectorClear(self->velocity);
			self->nextthink = 0;
		}

		if (!(self->flags & FL_TEAMSLAVE)) {
			if (self->moveinfo.sound_end)
				gi.sound(self, CHAN_NO_PHS_ADD + CHAN_VOICE,
					 self->moveinfo.sound_end, 1, ATTN_STATIC, 0);
			self->s.sound = 0;
		}
	} else {
		rotate_train_next(self);
	}
}

/*
=============
rotate_train_next

Advance func_rotate_train to its next path corner using the retail move chain.
=============
*/
static void rotate_train_next(edict_t *self)
{
	edict_t *ent;
	vec3_t dest;
	qboolean first;

	first = true;

again:
	if (!self->target)
		return;

	ent = G_PickTarget(self->target);
	if (!ent) {
		gi.dprintf("train_next: bad target %s\n", self->target);
		return;
	}

	self->target = ent->target;

	if (ent->spawnflags & 1) {
		if (!first) {
			gi.dprintf("connected teleport path_corners, see %s at %s\n",
				   ent->classname, vtos(ent->s.origin));
			return;
		}

		first = false;
		VectorCopy(ent->s.origin, self->s.origin);
		VectorCopy(self->s.origin, self->s.old_origin);
		self->s.event = EV_OTHER_TELEPORT;
		gi.linkentity(self);
		goto again;
	}

	self->moveinfo.wait = ent->wait;
	self->target_ent = ent;

	if (!(self->flags & FL_TEAMSLAVE)) {
		if (self->moveinfo.sound_start)
			gi.sound(self, CHAN_NO_PHS_ADD + CHAN_VOICE,
				 self->moveinfo.sound_start, 1, ATTN_STATIC, 0);
		self->s.sound = self->moveinfo.sound_middle;
	}

	if (ent->duration > 0)
		self->duration = ent->duration;
	else
		self->duration = 0;

	if (ent->speed > 0)
		self->moveinfo.speed = ent->speed;

	if (!VectorCompare(ent->rotate, vec3_origin))
		VectorCopy(ent->rotate, self->rotate);
	else
		VectorClear(self->rotate);

	if (!VectorCompare(ent->rotate_speed, vec3_origin))
		VectorCopy(ent->rotate_speed, self->rotate_speed);
	else
		VectorClear(self->rotate_speed);

	VectorCopy(ent->s.origin, dest);
	VectorCopy(self->s.origin, self->moveinfo.start_origin);
	VectorCopy(dest, self->moveinfo.end_origin);

	RotateTrain_MoveCalc(self, dest, rotate_train_wait);
	self->spawnflags |= RTRAIN_START_ON;
}

/*
=============
rotate_train_resume

Resume the current rotate-train leg without re-reading the path-corner overrides.
=============
*/
static void rotate_train_resume(edict_t *self)
{
	edict_t *ent;
	vec3_t dest;

	ent = self->target_ent;

	VectorCopy(ent->s.origin, dest);
	VectorCopy(self->s.origin, self->moveinfo.start_origin);
	VectorCopy(dest, self->moveinfo.end_origin);

	RotateTrain_MoveCalc(self, dest, rotate_train_wait);
	self->spawnflags |= RTRAIN_START_ON;
}

/*
=============
rotate_train_find

Resolve the first path corner and seed the retail func_rotate_train state.
=============
*/
static void rotate_train_find(edict_t *self)
{
	edict_t *ent;

	if (!self->target) {
		gi.dprintf("train_find: no target\n");
		return;
	}

	ent = G_PickTarget(self->target);
	if (!ent) {
		gi.dprintf("train_find: target %s not found\n", self->target);
		return;
	}

	self->target = ent->target;

	if (ent->duration > 0)
		self->duration = ent->duration;
	else
		self->duration = 0;

	if (!VectorCompare(ent->rotate, vec3_origin))
		VectorCopy(ent->rotate, self->rotate);
	else
		VectorClear(self->rotate);

	if (!VectorCompare(ent->rotate_speed, vec3_origin))
		VectorCopy(ent->rotate_speed, self->rotate_speed);
	else
		VectorClear(self->rotate_speed);

	self->moveinfo.speed = ent->speed;

	VectorCopy(ent->s.origin, self->s.origin);
	gi.linkentity(self);

	if (!self->targetname)
		self->spawnflags |= RTRAIN_START_ON;

	if (self->spawnflags & RTRAIN_START_ON) {
		self->think = rotate_train_next;
		self->nextthink = level.time + FRAMETIME;
		self->activator = self;
	}
}

/*
=============
rotate_train_use

Handle func_rotate_train activation and retail toggle-stop behavior.
=============
*/
static void rotate_train_use(edict_t *self, edict_t *other, edict_t *activator)
{
	self->activator = activator;

	if (self->spawnflags & RTRAIN_START_ON) {
		if (!(self->spawnflags & RTRAIN_TOGGLE))
			return;

		self->spawnflags &= ~RTRAIN_START_ON;
		VectorClear(self->velocity);
		self->nextthink = 0;
		return;
	}

	if (self->target_ent)
		rotate_train_resume(self);
	else
		rotate_train_next(self);
}

/*
=============
SP_func_rotate_train

Spawn the retail func_rotate_train mover wrapper.
=============
*/
/*QUAKED func_rotate_train (0 .5 .8) ? START_ON TOGGLE BLOCK_STOPS
Rotating trains are moving platforms that players can ride.
The target origin specifies the exact point of the train at each corner.
The train spawns at the first target it is pointing at.
If the train is the target of a button or trigger, it will not begin moving
until activated.

"speed"		default 100
"dmg"		default 100
"noise"		looping sound to play when the train is in motion

Per-corner keys on path_corner:
"wait"		pause before advancing
"duration"	overrides travel time for the next leg
"rotate"	x y z angle delta for the next leg
"speeds"	x y z angular speeds for the next leg
*/
void SP_func_rotate_train(edict_t *self)
{
	self->movetype = MOVETYPE_PUSH;
	VectorClear(self->s.angles);
	self->blocked = train_blocked;

	if (self->spawnflags & RTRAIN_BLOCK_STOPS)
		self->dmg = 0;
	else if (!self->dmg)
		self->dmg = 100;

	self->solid = SOLID_BSP;
	gi.setmodel(self, self->model);

	if (st.noise)
		self->moveinfo.sound_middle = gi.soundindex(st.noise);

	if (!self->speed)
		self->speed = 100;

	if (self->duration <= 0)
		self->duration = 0;

	self->moveinfo.speed = self->speed;
	self->use = rotate_train_use;

	gi.linkentity(self);

	if (self->target) {
		self->think = rotate_train_find;
		self->nextthink = level.time + FRAMETIME;
	} else {
		gi.dprintf("func_train without a target at %s\n", vtos(self->absmin));
	}
}

#endif
