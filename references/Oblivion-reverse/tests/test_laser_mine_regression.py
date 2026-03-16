import re
from pathlib import Path
import unittest


REPO_ROOT = Path(__file__).resolve().parents[1]
P_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "p_weapon.c"
G_WEAPON_SOURCE = REPO_ROOT / "src" / "game" / "g_weapon.c"
G_SPAWN_SOURCE = REPO_ROOT / "src" / "game" / "g_spawn.c"
G_TARGET_SOURCE = REPO_ROOT / "src" / "game" / "g_target.c"


def extract_function_block(source: str, function_name: str) -> str:
	pattern = re.compile(rf"{function_name}\s*\([^)]*\)\s*\{{", re.MULTILINE)
	match = pattern.search(source)
	if not match:
		raise AssertionError(f"Function {function_name} not found")
	start = match.end()
	depth = 1
	idx = start
	while idx < len(source) and depth > 0:
		char = source[idx]
		if char == "{":
			depth += 1
		elif char == "}":
			depth -= 1
		idx += 1
	return source[match.start():idx]


class LaserMineRetailRegression(unittest.TestCase):
	@classmethod
	def setUpClass(cls) -> None:
		cls.p_weapon_source = P_WEAPON_SOURCE.read_text(encoding="utf-8")
		cls.g_weapon_source = G_WEAPON_SOURCE.read_text(encoding="utf-8")
		cls.g_spawn_source = G_SPAWN_SOURCE.read_text(encoding="utf-8")
		cls.g_target_source = G_TARGET_SOURCE.read_text(encoding="utf-8")

	def test_change_weapon_cancels_hold_without_forcing_throw(self) -> None:
		change_weapon_block = extract_function_block(self.p_weapon_source, "ChangeWeapon")

		self.assertIn("ent->client->grenade_time = level.time;", change_weapon_block)
		self.assertIn("ent->client->weapon_sound = 0;", change_weapon_block)
		self.assertIn("ent->client->grenade_time = 0;", change_weapon_block)
		self.assertNotIn("weapon_grenade_fire", change_weapon_block)

	def test_proximity_mine_weapon_uses_retail_custom_state_machine(self) -> None:
		weapon_block = extract_function_block(self.p_weapon_source, "Weapon_ProximityMines")
		fire_block = extract_function_block(self.p_weapon_source, "Weapon_ProximityMines_Fire")

		self.assertNotIn("Weapon_Generic", weapon_block)
		self.assertIn("ent->client->ps.gunframe = 16;", weapon_block)
		self.assertIn('gi.sound(ent, CHAN_WEAPON, gi.soundindex("weapons/hgrena1b.wav"), 1,', weapon_block)
		self.assertIn('gi.soundindex("weapons/hgrenc1b.wav")', weapon_block)
		self.assertIn("Weapon_ProximityMines_Fire(ent);", weapon_block)
		self.assertIn("ent->client->grenade_time = level.time + GRENADE_TIMER + 0.2f;", weapon_block)

		self.assertIn("timer = ent->client->grenade_time - level.time;", fire_block)
		self.assertIn("speed = GRENADE_MINSPEED +", fire_block)
		self.assertIn("fire_proximity_mine(ent, start, forward, speed);", fire_block)
		self.assertIn("ent->client->grenade_time = level.time + 1.0f;", fire_block)

	def test_proximity_mine_projectile_matches_retail_callbacks_and_laser_phase(self) -> None:
		fire_block = extract_function_block(self.g_weapon_source, "fire_proximity_mine")
		laser_start_block = extract_function_block(self.g_weapon_source, "proximity_mine_laser_start")
		laser_block = extract_function_block(self.g_weapon_source, "proximity_mine_laser_think")
		target_laser_block = extract_function_block(self.g_target_source, "target_laser_start")

		self.assertIn('mine->classname = "mine";', fire_block)
		self.assertIn("mine->touch = proximity_mine_touch;", fire_block)
		self.assertIn("mine->think = proximity_mine_think;", fire_block)
		self.assertIn("mine->die = proximity_mine_die;", fire_block)
		self.assertIn("mine->health = 10;", fire_block)
		self.assertIn("mine->dmg = 150;", fire_block)
		self.assertIn("mine->radius_dmg = 100;", fire_block)
		self.assertIn("mine->dmg_radius = 180.0f;", fire_block)
		self.assertIn("mine_enforce_limit(mine);", fire_block)

		self.assertIn("VectorClear(self->s.angles);", laser_start_block)
		self.assertIn("VectorScale(self->movedir, 30.0f, self->velocity);", laser_start_block)

		self.assertIn("for (i = 0; i < 4; i++)", laser_block)
		self.assertIn("VectorSet(self->avelocity, 0.0f, 74.0f, 0.0f);", laser_block)
		self.assertIn("child->spawnflags = 0x89;", laser_block)
		self.assertIn('child->classname = "mine laser";', laser_block)
		self.assertIn("target_laser_start(child);", laser_block)
		self.assertIn("if (self->count < 30)", laser_block)
		self.assertIn("self->think = proximity_mine_explode;", laser_block)

		self.assertIn("else if (self->spawnflags & 128)", target_laser_block)
		self.assertIn("self->s.frame = 2;", target_laser_block)

	def test_spawn_table_and_spawner_expose_retail_mine_classname(self) -> None:
		spawn_block = extract_function_block(self.g_weapon_source, "SP_mine")

		self.assertIn('{"mine", SP_mine},', self.g_spawn_source)
		self.assertIn("if (self->speed <= 0)", spawn_block)
		self.assertIn("self->speed = 600;", spawn_block)
		self.assertIn("self->dmg = 150;", spawn_block)
		self.assertIn("self->radius_dmg = 100;", spawn_block)
		self.assertIn("self->dmg_radius = 180.0f;", spawn_block)
		self.assertIn("fire_proximity_mine(&g_edicts[0], self->s.origin, forward, (int)self->speed);", spawn_block)


if __name__ == "__main__":
	unittest.main()
