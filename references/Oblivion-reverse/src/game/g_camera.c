#include "g_local.h"

void InitTrigger(edict_t *self);
void multi_wait(edict_t *ent);
void trigger_enable(edict_t *self, edict_t *other, edict_t *activator);

#define CAMERA_DEFAULT_WAIT		3.0f
#define CAMERA_PATH_DEFAULT_SPEED	100.0f
#define CAMERA_PATH_STOPPED		-1.0f

static edict_t *DummyBody_Find(edict_t *player);
static void DummyBody_Sync(edict_t *player, edict_t *body);
static void DummyBody_Setup(edict_t *player);
static void DummyBody_Teardown(edict_t *player);
static edict_t *RemoteView_GetEntity(edict_t *ent);
static qboolean RemoteView_ClientPreFrame(edict_t *ent);
static qboolean RemoteView_ClientPostFrame(edict_t *ent);
static void Camera_RemoteViewCmd(edict_t *ent, usercmd_t *ucmd);
static void Camera_AttachClient(edict_t *player, edict_t *camera);
static void Camera_DetachClient(edict_t *player, edict_t *camera);
static void Camera_MoveStep(edict_t *self);
static void Camera_Deactivate(edict_t *self);
static void Camera_Activate(edict_t *self);
static void Camera_Use(edict_t *self, edict_t *other, edict_t *activator);
static void Camera_Think(edict_t *self);
static void TriggerCamera_Fire(edict_t *self);
static void TriggerCamera_Use(edict_t *self, edict_t *other, edict_t *activator);
static void TriggerCamera_Touch(edict_t *self, edict_t *other, cplane_t *plane, csurface_t *surf);
static void Camera_TargetUse(edict_t *self, edict_t *other, edict_t *activator);
static void Camera_TargetThink(edict_t *self);

/*
=================
DummyBody_Find
=================
*/
static edict_t *DummyBody_Find(edict_t *player)
{
	if (!player || !player->client)
		return NULL;
	if (!player->client->remote_view_body)
		return NULL;
	if (!player->client->remote_view_body->inuse)
	{
		player->client->remote_view_body = NULL;
		return NULL;
	}

	return player->client->remote_view_body;
}

/*
=================
DummyBody_Sync
=================
*/
static void DummyBody_Sync(edict_t *player, edict_t *body)
{
	if (!player || !body)
		return;

	VectorCopy(player->s.origin, body->s.origin);
	VectorCopy(player->s.angles, body->s.angles);
	VectorCopy(player->velocity, body->velocity);
	VectorCopy(player->avelocity, body->avelocity);
	body->s.modelindex = player->s.modelindex;
	body->s.modelindex2 = player->s.modelindex2;
	body->s.frame = player->s.frame;
	gi.linkentity(body);
}

/*
=================
DummyBody_Setup
=================
*/
static void DummyBody_Setup(edict_t *player)
{
	edict_t	*body;

	if (!player || !player->client)
		return;

	body = DummyBody_Find(player);
	if (!body)
	{
		body = G_Spawn();
		player->client->remote_view_body = body;
	}

	body->classname = "dummy_body";
	body->enemy = player;
	VectorCopy(player->mins, body->mins);
	VectorCopy(player->maxs, body->maxs);
	DummyBody_Sync(player, body);
	player->client->remote_view_active = true;
	player->svflags |= SVF_NOCLIENT;
	gi.linkentity(player);
}

/*
=================
DummyBody_Teardown
=================
*/
static void DummyBody_Teardown(edict_t *player)
{
	edict_t	*body;

	if (!player || !player->client)
		return;

	body = DummyBody_Find(player);
	player->client->remote_view_body = NULL;
	player->client->remote_view_active = false;
	player->svflags &= ~SVF_NOCLIENT;
	gi.linkentity(player);

	if (body)
		G_FreeEdict(body);
}

/*
=================
RemoteView_GetEntity
=================
*/
static edict_t *RemoteView_GetEntity(edict_t *ent)
{
	edict_t	*viewent;

	if (!ent || !ent->client)
		return NULL;
	if (!ent->client->remote_view_active)
		return NULL;

	viewent = ent->client->remote_view_entity;
	if (!viewent || !viewent->inuse)
	{
		ent->client->remote_view_entity = NULL;
		RemoteView_End(ent);
		return NULL;
	}

	return viewent;
}

/*
=================
RemoteView_ApplyClientState

Behavioral alias for the retail `0x10002E20` helper that pushes the
tracked entity plus stored view offsets back into the live playerstate.
=================
*/
static void RemoteView_ApplyClientState(edict_t *ent, edict_t *viewent)
{
	if (!ent || !ent->client || !viewent)
		return;

	ent->client->ps.pmove.origin[0] = viewent->s.origin[0] * 8.0f;
	ent->client->ps.pmove.origin[1] = viewent->s.origin[1] * 8.0f;
	ent->client->ps.pmove.origin[2] = viewent->s.origin[2] * 8.0f;
	VectorCopy(viewent->s.angles, ent->client->ps.viewangles);
	ent->client->ps.viewoffset[0] = (float)ent->client->remote_view_state_1;
	ent->client->ps.viewoffset[1] = (float)ent->client->remote_view_state_2;
	ent->client->ps.viewoffset[2] = ent->client->remote_view_timer;
	ent->client->ps.pmove.pm_type = PM_FREEZE;
}

/*
=================
RemoteView_ClientPreFrame
=================
*/
static qboolean RemoteView_ClientPreFrame(edict_t *ent)
{
	return RemoteView_GetEntity(ent) != NULL;
}

/*
=================
RemoteView_ClientPostFrame
=================
*/
static qboolean RemoteView_ClientPostFrame(edict_t *ent)
{
	edict_t	*viewent;
	edict_t	*body;

	viewent = RemoteView_GetEntity(ent);
	if (!viewent)
		return false;

	RemoteView_ApplyClientState(ent, viewent);

	body = DummyBody_Find(ent);
	if (body)
		DummyBody_Sync(ent, body);

	return true;
}

/*
=================
RemoteView_Begin
=================
*/
void RemoteView_Begin(edict_t *ent, edict_t *viewent)
{
	(void)viewent;

	if (!ent || !ent->client)
		return;

	if (ent->client->remote_view_active)
		RemoteView_End(ent);

	DummyBody_Setup(ent);
	ent->client->remote_view_cmd_hook = NULL;
	ent->client->remote_view_state_1 = 0;
	ent->client->remote_view_state_2 = 0;
	ent->client->remote_view_timer = 0.0f;
	ent->client->remote_view_saved_gunindex = ent->client->ps.gunindex;
	ent->client->ps.gunindex = 0;
	ent->svflags |= SVF_NOCLIENT;
	gi.linkentity(ent);
}

/*
=================
RemoteView_End
=================
*/
void RemoteView_End(edict_t *ent)
{
	if (!ent || !ent->client)
		return;

	DummyBody_Teardown(ent);
	ent->client->remote_view_cmd_hook = NULL;
	ent->client->remote_view_state_1 = 0;
	ent->client->remote_view_state_2 = 0;
	ent->client->remote_view_timer = 0.0f;
	ent->client->ps.gunindex = ent->client->remote_view_saved_gunindex;
	ent->client->remote_view_saved_gunindex = 0;
}

/*
=================
RemoteView_AttachController

Behavioral alias for the retail `0x10002EB0` helper used by controller
entities adjacent to the RTDU support cluster.
=================
*/
void RemoteView_AttachController(edict_t *ent, edict_t *viewent,
	remote_view_cmd_func_t *cmd_hook)
{
	if (!ent || !ent->client || !viewent)
		return;
	if (ent->client->remote_view_entity)
		return;

	ent->client->remote_view_entity = viewent;
	RemoteView_Begin(ent, viewent);
	ent->client->remote_view_cmd_hook = cmd_hook;
}

/*
=================
RemoteView_DetachController

Behavioral alias for the retail `0x10002F20` helper that tears down the
shared controller-target slot when the tracked entity matches.
=================
*/
void RemoteView_DetachController(edict_t *ent, edict_t *viewent)
{
	if (!ent || !ent->client)
		return;
	if (ent->client->remote_view_entity != viewent)
		return;

	RemoteView_End(ent);
	ent->client->remote_view_entity = NULL;
}

/*
=================
Camera_RemoteViewCmd
=================
*/
static void Camera_RemoteViewCmd(edict_t *ent, usercmd_t *ucmd)
{
	edict_t	*camera;

	if (!ent || !ent->client || !ucmd)
		return;

	camera = ent->client->remote_view_entity;
	if (!camera || !camera->inuse)
		return;
	if (!(camera->spawnflags & 1))
		return;

	ucmd->angles[0] = 0;
	ucmd->angles[1] = 0;
	ucmd->angles[2] = 0;
	ucmd->forwardmove = 0;
	ucmd->sidemove = 0;
	ucmd->upmove = 0;
	ucmd->buttons &= 0xfc;
}

/*
=================
Camera_AttachClient
=================
*/
static void Camera_AttachClient(edict_t *player, edict_t *camera)
{
	if (!player || !player->client)
		return;

	RemoteView_AttachController(player, camera, Camera_RemoteViewCmd);
}

/*
=================
Camera_DetachClient
=================
*/
static void Camera_DetachClient(edict_t *player, edict_t *camera)
{
	if (!player || !player->client)
		return;

	RemoteView_DetachController(player, camera);
}

/*
=================
Camera_MoveStep
=================
*/
static void Camera_MoveStep(edict_t *self)
{
	vec3_t	delta;
	float	distance;
	float	move_time;
	float	main_time;
	float	remaining_time;
	float	speed;
	float	remaining_speed;
	int		full_frames;

	switch (self->oblivion.deatom_state)
	{
	case 0:
	case 1:
		if (!self->movetarget)
		{
			self->oblivion.deatom_f_32c = 0.0f;
			self->delay = CAMERA_PATH_STOPPED;
			return;
		}

		VectorSubtract(self->movetarget->s.origin, self->s.origin, delta);
		VectorCopy(delta, self->oblivion.deatom_origin);
		distance = VectorLength(self->oblivion.deatom_origin);
		self->oblivion.deatom_f_34c = distance;
		VectorNormalize(self->oblivion.deatom_origin);

		speed = self->oblivion.deatom_f_320;
		if (speed <= 0.0f)
			speed = 1.0f;

		move_time = distance / speed;
		full_frames = (int)(move_time * 10.0f);
		main_time = full_frames * FRAMETIME;
		remaining_time = move_time - main_time;
		self->oblivion.deatom_state = 2;
		self->oblivion.deatom_f_34c = distance - (main_time * speed);
		if (self->oblivion.deatom_f_34c < 0.0f)
			self->oblivion.deatom_f_34c = 0.0f;

		remaining_speed = 0.0f;
		if (remaining_time > 0.0f)
			remaining_speed = self->oblivion.deatom_f_34c / remaining_time;
		self->oblivion.deatom_v_340[2] = remaining_speed;

		if (main_time > 0.0f)
		{
			VectorScale(self->oblivion.deatom_origin, speed, self->velocity);
			self->oblivion.deatom_f_32c = level.time + main_time;
			return;
		}

		if (remaining_speed > 0.0f)
			VectorScale(self->oblivion.deatom_origin, remaining_speed, self->velocity);
		else
			VectorClear(self->velocity);

		self->oblivion.deatom_f_32c = level.time + remaining_time;
		gi.bprintf(PRINT_HIGH, "no main move\n");
		return;

	case 2:
		self->oblivion.deatom_f_32c = 0.0f;
		if (self->oblivion.deatom_f_34c > 0.0f)
		{
			speed = self->oblivion.deatom_v_340[2];
			self->oblivion.deatom_f_320 = speed;
			if (speed > 0.0f)
			{
				VectorScale(self->oblivion.deatom_origin, speed, self->velocity);
				self->oblivion.deatom_f_32c =
					level.time + (self->oblivion.deatom_f_34c / speed);
			}
			if (self->movetarget)
				self->delay = self->movetarget->delay;
		}

		self->oblivion.deatom_f_34c = 0.0f;
		self->oblivion.deatom_v_340[2] = 0.0f;
		self->oblivion.deatom_state = 3;
		if (self->oblivion.deatom_f_32c == 0.0f)
			self->oblivion.deatom_f_32c = level.time;
		return;

	case 3:
		if (self->movetarget)
		{
			VectorCopy(self->movetarget->s.origin, self->s.origin);
			VectorCopy(self->s.origin, self->s.old_origin);
			gi.linkentity(self);
		}

		if (self->delay != CAMERA_PATH_STOPPED)
		{
			self->oblivion.deatom_f_32c = level.time + self->delay;
			self->oblivion.deatom_state = 1;
			self->delay = 0.0f;
		}
		else
		{
			self->oblivion.deatom_f_32c = 0.0f;
			self->oblivion.deatom_state = 0;
		}

		if (self->movetarget)
			self->movetarget = G_PickTarget(self->movetarget->target);

		VectorClear(self->velocity);
		VectorClear(self->avelocity);
		return;
	}
}

/*
=================
Camera_Deactivate
=================
*/
static void Camera_Deactivate(edict_t *self)
{
	edict_t	*player;
	int		i;

	for (i = 1; i <= game.maxclients; i++)
	{
		player = &g_edicts[i];
		if (!player->inuse || !player->client)
			continue;
		Camera_DetachClient(player, self);
	}

	VectorClear(self->velocity);
	VectorClear(self->avelocity);
	self->delay = 0.0f;
	self->oblivion.deatom_f_34c = 0.0f;
	self->oblivion.deatom_v_340[2] = 0.0f;
	self->oblivion.deatom_f_32c = 0.0f;
	self->oblivion.deatom_state = 0;
	self->count = 0;
	self->nextthink = 0.0f;
}

/*
=================
Camera_Activate
=================
*/
static void Camera_Activate(edict_t *self)
{
	edict_t	*player;
	int		i;

	self->delay = 0.0f;

	if (!self->enemy && self->target)
	{
		self->enemy = G_PickTarget(self->target);
		if (!self->enemy)
			gi.dprintf("%s target %s not found\n", self->classname, self->target);
	}

	if (!self->movetarget && self->pathtarget)
	{
		self->movetarget = G_Find(NULL, FOFS(targetname), self->pathtarget);
		if (!self->movetarget)
			gi.dprintf("%s pathtarget %s not found\n", self->classname, self->pathtarget);
		else
		{
			self->oblivion.deatom_f_320 =
				self->speed ? self->speed : CAMERA_PATH_DEFAULT_SPEED;
			self->oblivion.deatom_state = 0;
			VectorCopy(self->movetarget->s.origin, self->s.origin);
			VectorCopy(self->s.origin, self->s.old_origin);
			self->oblivion.deatom_f_32c = level.time;
			gi.linkentity(self);
		}
	}

	for (i = 1; i <= game.maxclients; i++)
	{
		player = &g_edicts[i];
		if (!player->inuse || !player->client)
			continue;
		Camera_AttachClient(player, self);
	}

	self->count = 1;
	self->timestamp = level.time;
	self->nextthink = level.time + FRAMETIME;
}

/*
=================
Camera_Use
=================
*/
static void Camera_Use(edict_t *self, edict_t *other, edict_t *activator)
{
	(void)other;
	(void)activator;

	if (self->count == 0)
	{
		Camera_Activate(self);
		return;
	}

	Camera_Deactivate(self);
}

/*
=================
Camera_Think
=================
*/
static void Camera_Think(edict_t *self)
{
	vec3_t	current_forward;
	vec3_t	target;
	vec3_t	target_dir;

	if (self->wait != CAMERA_PATH_STOPPED &&
		self->timestamp + self->wait < level.time)
	{
		Camera_Deactivate(self);
		return;
	}

	if (self->movetarget && self->delay == CAMERA_PATH_STOPPED)
	{
		Camera_Deactivate(self);
		return;
	}

	while (self->movetarget &&
		self->oblivion.deatom_f_32c != 0.0f &&
		self->oblivion.deatom_f_32c <= level.time)
	{
		Camera_MoveStep(self);
	}

	if (self->enemy && !self->enemy->inuse)
		self->enemy = NULL;
	else if (self->enemy)
	{
		VectorAdd(self->enemy->absmin, self->enemy->absmax, target);
		VectorScale(target, 0.5f, target);
		target[2] += self->enemy->viewheight;
		VectorSubtract(target, self->s.origin, target_dir);

		if (!VectorCompare(target_dir, vec3_origin))
		{
			VectorNormalize(target_dir);
			AngleVectors(self->s.angles, current_forward, NULL, NULL);
			VectorScale(current_forward, 0.9f, current_forward);
			VectorMA(current_forward, 0.1f, target_dir, current_forward);
			VectorNormalize(current_forward);
			vectoangles(current_forward, self->s.angles);
			gi.linkentity(self);
		}
	}

	if (self->enemy)
	{
		self->nextthink = level.time + FRAMETIME;
		return;
	}

	self->nextthink = self->timestamp + self->wait;
	if (self->oblivion.deatom_f_32c != 0.0f &&
		self->nextthink > self->oblivion.deatom_f_32c)
	{
		self->nextthink = self->oblivion.deatom_f_32c;
	}
}

/*
=================
SP_misc_camera
=================
*/
void SP_misc_camera(edict_t *self)
{
	self->solid = SOLID_NOT;
	self->movetype = MOVETYPE_FLYMISSILE;
	self->svflags |= SVF_NOCLIENT;
	VectorClear(self->mins);
	VectorClear(self->maxs);

	if (!self->targetname)
	{
		gi.bprintf(PRINT_HIGH, "%s with no targetname\n", self->classname);
		self->targetname = "unused";
	}

	if (self->wait == 0.0f)
		self->wait = CAMERA_DEFAULT_WAIT;

	self->use = Camera_Use;
	self->think = Camera_Think;
	self->s.modelindex = gi.modelindex("sprites/s_deatom1.sp2");
	gi.linkentity(self);
}

/*
=================
Camera_ClientPreFrame
=================
*/
void Camera_ClientPreFrame(edict_t *ent)
{
	if (!ent->client)
		return;

	RemoteView_ClientPreFrame(ent);
}

/*
=================
Camera_ClientPostFrame
=================
*/
void Camera_ClientPostFrame(edict_t *ent)
{
	if (!ent->client)
		return;

	RemoteView_ClientPostFrame(ent);
}

/*
=================
TriggerCamera_Fire
=================
*/
static void TriggerCamera_Fire(edict_t *self)
{
	edict_t	*camera;
	int		sound_index;

	if (self->nextthink)
		return;

	if (self->message && self->activator && !(self->activator->svflags & SVF_MONSTER))
	{
		gi.centerprintf(self->activator, "%s", self->message);
		sound_index = self->noise_index;
		if (!sound_index)
			sound_index = gi.soundindex("misc/talk1.wav");
		gi.sound(self->activator, CHAN_AUTO, sound_index, 1.0f, ATTN_NORM, 0);
	}

	camera = NULL;
	if (self->target)
	{
		for (camera = G_Find(NULL, FOFS(targetname), self->target);
			camera;
			camera = G_Find(camera, FOFS(targetname), self->target))
		{
			if (!camera->classname || strcmp(camera->classname, "misc_camera") != 0)
				continue;

			if (self->wait != 0.0f)
				camera->wait = self->wait;

			if (self->pathtarget)
				camera->target = self->pathtarget;
			else
				camera->enemy = self->activator;

			if (camera->count == 0)
				Camera_Use(camera, self, self->activator);
			else
				camera->timestamp = level.time;
			break;
		}

		if (!camera)
			gi.bprintf(PRINT_HIGH, "Illegal target for trigger_misc_camera\n");
	}

	if (self->delay > 0.0f)
	{
		self->think = multi_wait;
		self->nextthink = level.time + self->delay;
		return;
	}

	self->touch = NULL;
	self->think = G_FreeEdict;
	self->nextthink = level.time + FRAMETIME;
}

/*
=================
TriggerCamera_Use
=================
*/
static void TriggerCamera_Use(edict_t *self, edict_t *other, edict_t *activator)
{
	(void)other;

	self->activator = activator;
	TriggerCamera_Fire(self);
}

/*
=================
TriggerCamera_Touch
=================
*/
static void TriggerCamera_Touch(edict_t *self, edict_t *other, cplane_t *plane, csurface_t *surf)
{
	vec3_t	forward;

	(void)plane;
	(void)surf;

	if (other->client)
	{
		if (self->spawnflags & 2)
			return;
	}
	else if (other->svflags & SVF_MONSTER)
	{
		if (!(self->spawnflags & 1))
			return;
	}
	else
	{
		return;
	}

	if (!VectorCompare(self->movedir, vec3_origin))
	{
		AngleVectors(other->s.angles, forward, NULL, NULL);
		if (_DotProduct(forward, self->movedir) < 0)
			return;
	}

	self->activator = other;
	TriggerCamera_Fire(self);
}

/*
=================
SP_trigger_misc_camera
=================
*/
void SP_trigger_misc_camera(edict_t *self)
{
	if (self->sounds == 1)
		self->noise_index = gi.soundindex("misc/secret.wav");
	else if (self->sounds == 2)
		self->noise_index = gi.soundindex("misc/talk.wav");
	else if (self->sounds == 3)
		self->noise_index = gi.soundindex("misc/trigger1.wav");

	InitTrigger(self);
	self->touch = TriggerCamera_Touch;
	if (self->spawnflags & 4)
	{
		self->solid = SOLID_NOT;
		self->use = trigger_enable;
	}
	else
	{
		self->solid = SOLID_TRIGGER;
		self->use = TriggerCamera_Use;
	}

	gi.linkentity(self);
}

/*
=================
Camera_TargetUse
=================
*/
static void Camera_TargetUse(edict_t *self, edict_t *other, edict_t *activator)
{
	(void)other;
	(void)activator;

	if (self->count != 0)
	{
		self->delay = 0.0f;
		self->count = 0;
		VectorClear(self->velocity);
		VectorClear(self->avelocity);
		self->nextthink = 0.0f;
		self->oblivion.deatom_f_32c = 0.0f;
		self->oblivion.deatom_state = 0;
		return;
	}

	self->count = 1;
	self->delay = 0.0f;
	if (!self->movetarget && self->target)
	{
		self->movetarget = G_Find(NULL, FOFS(targetname), self->target);
		if (!self->movetarget)
		{
			gi.bprintf(PRINT_HIGH, "%s at %s: invalid target %s\n",
				self->classname, vtos(self->s.origin), self->target);
		}
		else
		{
			self->oblivion.deatom_f_320 =
				self->speed ? self->speed : CAMERA_PATH_DEFAULT_SPEED;
			self->oblivion.deatom_state = 0;
			VectorCopy(self->movetarget->s.origin, self->s.origin);
			VectorCopy(self->s.origin, self->s.old_origin);
			self->oblivion.deatom_f_32c = level.time;
			gi.linkentity(self);
		}
	}

	self->nextthink = level.time + FRAMETIME;
}

/*
=================
Camera_TargetThink
=================
*/
static void Camera_TargetThink(edict_t *self)
{
	if (self->movetarget)
	{
		if (self->delay == CAMERA_PATH_STOPPED)
		{
			self->delay = 0.0f;
			VectorClear(self->velocity);
			VectorClear(self->avelocity);
			self->nextthink = 0.0f;
			self->oblivion.deatom_f_32c = 0.0f;
			self->oblivion.deatom_state = 0;
			return;
		}

		while (self->oblivion.deatom_f_32c != 0.0f &&
			self->oblivion.deatom_f_32c <= level.time)
		{
			Camera_MoveStep(self);
		}
	}

	self->nextthink = self->oblivion.deatom_f_32c;
}

/*
=================
SP_misc_camera_target
=================
*/
void SP_misc_camera_target(edict_t *self)
{
	self->solid = SOLID_NOT;
	self->movetype = MOVETYPE_FLYMISSILE;
	self->svflags |= SVF_NOCLIENT;
	VectorClear(self->mins);
	VectorClear(self->maxs);

	if (!self->targetname)
	{
		gi.bprintf(PRINT_HIGH, "%s with no targetname\n", self->classname);
		self->targetname = "unused";
	}

	self->count = 0;
	self->movetarget = NULL;
	self->use = Camera_TargetUse;
	self->think = Camera_TargetThink;
	self->s.modelindex = gi.modelindex("sprites/s_deatom1.sp2");
	gi.linkentity(self);
}

/*
=================
SP_misc_deatomizer_control
=================
*/
void SP_misc_deatomizer_control(edict_t *self)
{
	SP_misc_camera(self);
}

/*
=================
SP_misc_deatomizer_target
=================
*/
void SP_misc_deatomizer_target(edict_t *self)
{
	SP_misc_camera_target(self);
}
