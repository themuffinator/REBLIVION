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

#include "g_local.h"

#include <string.h>

static mission_state_t *MissionState (void)
{
        return &game.mission;
}

static void Mission_ResetObjective (mission_objective_save_t *obj)
{
        memset (obj, 0, sizeof(*obj));
        obj->state = MISSION_OBJECTIVE_INACTIVE;
}

static void Mission_CopySubstring (char *dest, size_t dest_size, const char *src, size_t length)
{
        if (!dest || !dest_size)
                return;

        if (!src)
        {
                dest[0] = '\0';
                return;
        }

        if (length >= dest_size)
                length = dest_size - 1;

        memcpy (dest, src, length);
        dest[length] = '\0';
}

static void Mission_Strncpy (char *dest, size_t dest_size, const char *src)
{
        if (!dest || !dest_size)
                return;

        if (!src)
        {
                dest[0] = '\0';
                return;
        }

        strncpy (dest, src, dest_size - 1);
        dest[dest_size - 1] = '\0';
}

static int Mission_SecondsToTicks (int seconds)
{
        if (seconds <= 0)
                return 0;
        return seconds * MISSION_TIMER_TICKS_PER_SECOND;
}

static int Mission_TicksToSeconds (int ticks)
{
        if (ticks <= 0)
                return 0;
        return ticks / MISSION_TIMER_TICKS_PER_SECOND;
}

static mission_objective_save_t *Mission_FindObjective (const char *id)
{
        mission_state_t *state = MissionState ();
        int i;

        if (!id || !id[0])
                return NULL;

        for (i = 0; i < state->objective_count; i++)
        {
                if (!strcmp (state->objectives[i].id, id))
                        return &state->objectives[i];
        }

        return NULL;
}

static mission_objective_save_t *Mission_AllocateObjective (const char *id)
{
        mission_state_t *state = MissionState ();
        mission_objective_save_t *obj;

        if (state->objective_count >= MAX_MISSION_OBJECTIVES)
        {
                gi.dprintf ("mission: objective limit reached\n");
                return &state->objectives[MAX_MISSION_OBJECTIVES - 1];
        }

        obj = &state->objectives[state->objective_count++];
        Mission_ResetObjective (obj);
        Mission_Strncpy (obj->id, sizeof(obj->id), id);
        return obj;
}

static void Mission_RemoveObjectiveIndex (int index)
{
        mission_state_t *state = MissionState ();

        if (index < 0 || index >= state->objective_count)
                return;

        if (index < state->objective_count - 1)
                memmove (&state->objectives[index], &state->objectives[index + 1],
                        sizeof(state->objectives[0]) * (state->objective_count - index - 1));

        state->objective_count--;
        Mission_ResetObjective (&state->objectives[state->objective_count]);
}

static void Mission_RemoveObjectiveById (const char *id)
{
        mission_state_t *state = MissionState ();
        int i;

        for (i = 0; i < state->objective_count; i++)
        {
                if (!strcmp (state->objectives[i].id, id))
                {
                        Mission_RemoveObjectiveIndex (i);
                        return;
                }
        }
}

static void Mission_MarkUnread (void)
{
        mission_state_t *state = MissionState ();

        if (state->unread_events < 0)
                state->unread_events = 0;
        state->unread_events++;
}

static void Mission_FillObjectiveId (char *buffer, size_t buffer_size, edict_t *ent)
{
        if (!buffer || !buffer_size)
                return;

        if (ent->oblivion.mission_id && ent->oblivion.mission_id[0])
        {
                Mission_Strncpy (buffer, buffer_size, ent->oblivion.mission_id);
                return;
        }

        if (ent->targetname && ent->targetname[0])
        {
                Mission_Strncpy (buffer, buffer_size, ent->targetname);
                return;
        }

        if (ent->target && ent->target[0])
        {
                Mission_Strncpy (buffer, buffer_size, ent->target);
                return;
        }

        // fallback to edict index for uniqueness
        Com_sprintf (buffer, buffer_size, "mission_%d", (int)(ent - g_edicts));
}

static void Mission_SetObjectiveText (mission_objective_save_t *obj, edict_t *ent)
{
        const char *explicit_title = ent->oblivion.mission_title;
        const char *explicit_text = ent->oblivion.mission_text;
        const char *message = ent->message;

        if (explicit_title && explicit_title[0])
        {
            Mission_Strncpy (obj->title, sizeof(obj->title), explicit_title);
        }
        else if (message && message[0])
        {
            const char *newline = strchr (message, '\n');
            if (newline)
            {
                Mission_CopySubstring (obj->title, sizeof(obj->title), message, newline - message);
                message = newline + 1;
            }
            else
            {
                Mission_Strncpy (obj->title, sizeof(obj->title), message);
                message = NULL;
            }
        }
        else
        {
            Mission_Strncpy (obj->title, sizeof(obj->title), "Objective");
        }

        if (explicit_text && explicit_text[0])
        {
            Mission_Strncpy (obj->text, sizeof(obj->text), explicit_text);
        }
        else if (message && message[0])
        {
            Mission_Strncpy (obj->text, sizeof(obj->text), message);
        }
        else
        {
            obj->text[0] = '\0';
        }
}

static void Mission_RebuildHelpMessages_Internal (void)
{
        mission_state_t *state = MissionState ();
        mission_objective_save_t *primary = NULL;
        int i;

        if (state->objective_count <= 0)
        {
                Com_sprintf (game.helpmessage1, sizeof(game.helpmessage1), "No active objectives");
                game.helpmessage2[0] = '\0';
                return;
        }

        for (i = 0; i < state->objective_count; i++)
        {
                mission_objective_save_t *obj = &state->objectives[i];
                if (obj->state == MISSION_OBJECTIVE_ACTIVE && obj->primary)
                {
                        primary = obj;
                        break;
                }
        }

        if (!primary)
        {
                for (i = 0; i < state->objective_count; i++)
                {
                        mission_objective_save_t *obj = &state->objectives[i];
                        if (obj->state == MISSION_OBJECTIVE_ACTIVE)
                        {
                                primary = obj;
                                break;
                        }
                }
        }

        if (!primary)
                primary = &state->objectives[0];

        Mission_Strncpy (game.helpmessage1, sizeof(game.helpmessage1), primary->title);

        if (primary->state == MISSION_OBJECTIVE_ACTIVE && primary->timer_remaining > 0)
        {
                char timer[32];
                int seconds = Mission_TicksToSeconds (primary->timer_remaining);
                if (seconds > 0)
                {
                        Com_sprintf (timer, sizeof(timer), " (%ds)", seconds);
                        if (strlen(game.helpmessage1) + strlen(timer) < sizeof(game.helpmessage1))
                                strcat (game.helpmessage1, timer);
                }
        }

        Mission_Strncpy (game.helpmessage2, sizeof(game.helpmessage2), primary->text);
}

void Mission_InitGame (void)
{
        mission_state_t *state = MissionState ();

        memset (state, 0, sizeof(*state));
        Mission_RebuildHelpMessages_Internal ();
}

void Mission_OnGameLoaded (void)
{
        mission_state_t *state = MissionState ();

        if (state->objective_count < 0 || state->objective_count > MAX_MISSION_OBJECTIVES)
                state->objective_count = 0;

        Mission_RebuildHelpMessages_Internal ();
}

void Mission_BeginLevel (const char *mapname)
{
        mission_state_t *state = MissionState ();
        int i = 0;

        (void)mapname;

        while (i < state->objective_count)
        {
                mission_objective_save_t *obj = &state->objectives[i];

                if (!obj->persistent)
                {
                        Mission_RemoveObjectiveIndex (i);
                        continue;
                }

                if (obj->timer_limit > 0)
                        obj->timer_remaining = Mission_SecondsToTicks (obj->timer_limit);
                else
                        obj->timer_remaining = 0;

                i++;
        }

        state->unread_events = 0;
        Mission_RebuildHelpMessages_Internal ();
}

void Mission_FrameUpdate (void)
{
        mission_state_t *state = MissionState ();
        qboolean changed = false;
        int i;

        for (i = 0; i < state->objective_count; i++)
        {
                mission_objective_save_t *obj = &state->objectives[i];

                if (obj->state != MISSION_OBJECTIVE_ACTIVE)
                        continue;

                if (obj->timer_remaining > 0)
                {
                        obj->timer_remaining--;

                        if (obj->timer_remaining == 0 && obj->timer_limit > 0)
                        {
                                obj->state = MISSION_OBJECTIVE_FAILED;
                                changed = true;
                        }
                }
        }

        if (changed)
        {
                Mission_RebuildHelpMessages_Internal ();
                Mission_MarkUnread ();
                game.helpchanged++;
        }
}

void Mission_RegisterHelpTarget (edict_t *ent)
{
        if (!ent)
                return;

        if (!ent->oblivion.mission_state)
        {
                if (ent->spawnflags & 4)
                        ent->oblivion.mission_state = MISSION_EVENT_START;
                else
                        ent->oblivion.mission_state = MISSION_EVENT_UPDATE;
        }

        if (!ent->oblivion.mission_timer_cooldown)
        {
                if (ent->spawnflags & 1)
                        ent->oblivion.mission_timer_cooldown |= MISSION_FLAG_PRIMARY;
                if (ent->spawnflags & 256)
                        ent->oblivion.mission_timer_cooldown |= MISSION_FLAG_PERSISTENT;
        }

        if (ent->oblivion.mission_timer_limit < 0)
                ent->oblivion.mission_timer_limit = 0;

        if (ent->oblivion.mission_timer_remaining <= 0 && ent->oblivion.mission_timer_limit > 0)
                ent->oblivion.mission_timer_remaining = ent->oblivion.mission_timer_limit;
}

static qboolean Mission_HandleObjectiveEvent (edict_t *ent, const char *id, mission_objective_save_t **out_obj)
{
        mission_objective_save_t *obj = Mission_FindObjective (id);

        if (!obj)
                obj = Mission_AllocateObjective (id);

        if (!obj)
                return false;

        Mission_SetObjectiveText (obj, ent);

	obj->primary = (ent->oblivion.mission_timer_cooldown & MISSION_FLAG_PRIMARY) != 0;
	obj->persistent = (ent->oblivion.mission_timer_cooldown & MISSION_FLAG_PERSISTENT) != 0;
	VectorCopy (ent->oblivion.mission_origin, obj->origin);
	VectorCopy (ent->oblivion.mission_angles, obj->angles);
	VectorCopy (ent->oblivion.mission_velocity, obj->velocity);
	obj->blend = ent->oblivion.mission_blend;
	obj->radius = ent->oblivion.mission_radius;
        obj->timer_limit = ent->oblivion.mission_timer_limit;
        if (obj->timer_limit < 0)
                obj->timer_limit = 0;
        if (obj->timer_limit > 0)
                obj->timer_remaining = Mission_SecondsToTicks (ent->oblivion.mission_timer_remaining > 0 ? ent->oblivion.mission_timer_remaining : obj->timer_limit);
        else
                obj->timer_remaining = 0;

        if (out_obj)
                *out_obj = obj;

        return true;
}

qboolean Mission_TargetHelpFired (edict_t *ent, edict_t *activator)
{
        char id[32];
        mission_objective_save_t *obj = NULL;
        int event;

        (void)activator;

        if (!ent)
                return false;

        event = ent->oblivion.mission_state;
        if (!event)
                event = (ent->spawnflags & 4) ? MISSION_EVENT_START : MISSION_EVENT_UPDATE;

        if (!ent->message && (!ent->oblivion.mission_text || !ent->oblivion.mission_text[0])
                && !ent->oblivion.mission_id && event == MISSION_EVENT_UPDATE)
        {
                return false;
        }

        Mission_FillObjectiveId (id, sizeof(id), ent);

        switch (event)
        {
        case MISSION_EVENT_CLEAR:
                Mission_RemoveObjectiveById (id);
                Mission_RebuildHelpMessages_Internal ();
                Mission_MarkUnread ();
                return true;

        case MISSION_EVENT_COMPLETE:
        case MISSION_EVENT_FAIL:
        case MISSION_EVENT_START:
        case MISSION_EVENT_UPDATE:
                if (!Mission_HandleObjectiveEvent (ent, id, &obj))
                        return false;
                break;

        default:
                return false;
        }

        switch (event)
        {
        case MISSION_EVENT_START:
                obj->state = MISSION_OBJECTIVE_ACTIVE;
                if (obj->timer_limit > 0 && obj->timer_remaining <= 0)
                        obj->timer_remaining = Mission_SecondsToTicks (obj->timer_limit);
                break;

        case MISSION_EVENT_COMPLETE:
                obj->state = MISSION_OBJECTIVE_COMPLETED;
                obj->timer_remaining = 0;
                break;

        case MISSION_EVENT_FAIL:
                obj->state = MISSION_OBJECTIVE_FAILED;
                obj->timer_remaining = 0;
                break;

        case MISSION_EVENT_UPDATE:
        default:
                if (obj->state == MISSION_OBJECTIVE_INACTIVE)
                        obj->state = MISSION_OBJECTIVE_ACTIVE;
                break;
        }

        Mission_RebuildHelpMessages_Internal ();
        Mission_MarkUnread ();
        return true;
}

int Mission_GetObjectiveCount (void)
{
        return MissionState ()->objective_count;
}

const mission_objective_save_t *Mission_GetObjective (int index)
{
        mission_state_t *state = MissionState ();

        if (index < 0 || index >= state->objective_count)
                return NULL;

        return &state->objectives[index];
}

void Mission_ClearUnread (edict_t *ent)
{
        (void)ent;
        MissionState ()->unread_events = 0;
}

qboolean Mission_HasUnread (void)
{
        return MissionState ()->unread_events > 0;
}
