#ifndef G_OBLIVION_MONSTER_H
#define G_OBLIVION_MONSTER_H

void fire_deatom(edict_t *self, vec3_t start, vec3_t dir, int damage,
                 int speed);
void monster_fire_deatom(edict_t *self, vec3_t start, vec3_t dir, int damage,
                         int speed);

// Frames will be defined in respective monster files or here if shared.

#endif
