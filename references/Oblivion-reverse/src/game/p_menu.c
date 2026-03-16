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

#define MISSION_TIMER_TICKS_PER_SECOND ((int)(1.0f / FRAMETIME))

void MissionMenu_BuildObjectiveLayout (char *buffer, size_t size)
{
        int count;
        int y;
        size_t length;
        int i;

        if (!buffer || size == 0)
                return;

        buffer[0] = '\0';
        length = 0;
        y = 54;

        Com_sprintf (buffer + length, size - length, "xv 0 yv %d cstring2 \"Objectives\" ", y);
        length += strlen (buffer + length);
        y += 10;

        count = Mission_GetObjectiveCount ();
        if (count <= 0)
        {
                if (length < size)
                Com_sprintf (buffer + length, size - length, "xv 0 yv %d cstring \"No active objectives\" ", y);
                length += strlen (buffer + length);
                return;
        }

        for (i = 0; i < count; i++)
        {
                const mission_objective_save_t *obj = Mission_GetObjective (i);
                const char *marker;

                if (!obj)
                        continue;

                switch (obj->state)
                {
                case MISSION_OBJECTIVE_COMPLETED:
                        marker = "[X]";
                        break;
                case MISSION_OBJECTIVE_FAILED:
                        marker = "[!]";
                        break;
                case MISSION_OBJECTIVE_ACTIVE:
                        marker = obj->primary ? "[*]" : "[ ]";
                        break;
                default:
                        marker = "[ ]";
                        break;
                }

                if (length < size)
                        Com_sprintf (buffer + length, size - length, "xv 0 yv %d cstring2 \"%s %s\" ", y, marker, obj->title);
                        length += strlen (buffer + length);
                y += 10;

                if (obj->text[0])
                {
                        if (length < size)
                                Com_sprintf (buffer + length, size - length, "xv 0 yv %d cstring \"%s\" ", y, obj->text);
                                length += strlen (buffer + length);
                        y += 8;
                }

                if (obj->state == MISSION_OBJECTIVE_ACTIVE && obj->timer_remaining > 0)
                {
                        int seconds = obj->timer_remaining / MISSION_TIMER_TICKS_PER_SECOND;
                        if (seconds < 0)
                                seconds = 0;
                        if (length < size)
                                Com_sprintf (buffer + length, size - length, "xv 0 yv %d cstring \"Time Remaining: %ds\" ", y, seconds);
                                length += strlen (buffer + length);
                        y += 8;
                }

                y += 6;
        }
}
