/*QUAKED func_plat (0 .5 .8) ? PLAT_LOW_TRIGGER
speed	default 150

Plats are always drawn in the extended position, so they will light correctly.

If the plat is the target of another trigger or button, it will start out disabled in the extended position until it is trigger, when it will lower and become a normal plat.

"speed"	overrides default 200.
"accel" overrides default 500
"lip"	overrides default 8 pixel lip

If the "height" key is set, that will determine the amount the plat moves, instead of being implicitly determoveinfoned by the model's height.

Set "sounds" to one of the following:
1) base fast
2) chain slow
*/

/*QUAKED func_rotating (0 .5 .8) ? START_ON TOUCH_PAIN LOOP ANIMATED ANIMATED_FAST
A generic rotating brush/set of brushes.  Be sure to include an origin
brush with the group and its origin will serve as the center of rotation
for the entire entity.  Use START_ON to have it rotating at level start.
Use the LOOP flag in conjunction with mangle and partial rotation.  
See mangle field desc for more info.

"mangle"    Takes x y z values, if set, does a partial move and stops.  
            if LOOP flag is set, does rotation over and over every wait
		    seconds.  Uses "speed" instead of "speeds".
"speeds"    Takes x y z values and allows for seperate speed values on
            each axis.
"durations" Used if mangle is set and overrides speed.  Specifies the
            number of seconds for each axis to get from starting to
			ending point of partial rotation.  Takes x y z values.
"speed"     determines how fast it moves; default value is 100.
"duration"  Used with partial rotation, specifies # of seconds to
            complete move.  Overrides speed value.
"dmg"	    Damage to inflict when blocked (2 default)
"accel"     Acceleration speed when activated, goes from stopped to speed
"decel"     Deceleration speed when deactivated, goes from speed to 0
"wait"      Used with mangle and loop to set wait between rotations

Good values for acceleration run from 20-100.
Acceleration isn't used with partial rotation... for now.

*/

/*QUAKED func_button (0 .5 .8) ?
When a button is touched, it moves some distance in the direction of it's angle, triggers all of it's targets, waits some time, then returns to it's original position where it can be triggered again.

"angle"		determines the opening direction
"target"	all entities with a matching targetname will be used
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

/*QUAKED func_door (0 .5 .8) ? START_OPEN x CRUSHER NOMONSTER ANIMATED TOGGLE ANIMATED_FAST
TOGGLE		wait in both the start and end states for a trigger event.
START_OPEN	the door to moves to its destination when spawned, and operate in reverse.  It is used to temporarily or permanently close off an area when triggered (not useful for touch or takedamage doors).
NOMONSTER	monsters will not trigger this door

"message"	is printed when the door is touched if it is a trigger door and it hasn't been fired yet
"angle"		determines the opening direction
"targetname" if set, no touch field will be spawned and a remote button or trigger field activates the door.
"health"	if set, door must be shot open
"speed"		movement speed (100 default)
"wait"		wait before returning (3 default, -1 = never return)
"lip"		lip remaining at end of move (8 default)
"dmg"		damage to inflict when blocked (2 default)
"sounds"
1)	silent
2)	light
3)	medium
4)	heavy
*/

/*QUAKED func_door_rotating (0 .5 .8) ? START_OPEN REVERSE CRUSHER NOMONSTER ANIMATED TOGGLE X_AXIS Y_AXIS
TOGGLE causes the door to wait in both the start and end states for a trigger event.

START_OPEN	the door to moves to its destination when spawned, and operate in reverse.  It is used to temporarily or permanently close off an area when triggered (not useful for touch or takedamage doors).
NOMONSTER	monsters will not trigger this door

You need to have an origin brush as part of this entity.  The center of that brush will be
the point around which it is rotated. It will rotate around the Z axis by default.  You can
check either the X_AXIS or Y_AXIS box to change that.

"distance" is how many degrees the door will be rotated.
"speed" determines how fast the door moves; default value is 100.

REVERSE will cause the door to rotate in the opposite direction.

"message"	is printed when the door is touched if it is a trigger door and it hasn't been fired yet
"angle"		determines the opening direction
"targetname" if set, no touch field will be spawned and a remote button or trigger field activates the door.
"health"	if set, door must be shot open
"speed"		movement speed (100 default)
"wait"		wait before returning (3 default, -1 = never return)
"dmg"		damage to inflict when blocked (2 default)
"sounds"
1)	silent
2)	light
3)	medium
4)	heavy
*/

/*QUAKED func_water (0 .5 .8) ? START_OPEN
func_water is a moveable water brush.  It must be targeted to operate.  Use a non-water texture at your own risk.

START_OPEN causes the water to move to its destination when spawned and operate in reverse.

"angle"		determines the opening direction (up or down only)
"speed"		movement speed (25 default)
"wait"		wait before returning (-1 default, -1 = TOGGLE)
"lip"		lip remaining at end of move (0 default)
"sounds"	(yes, these need to be changed)
0)	no sound
1)	water
2)	lava
*/

/*QUAKED func_train (0 .5 .8) ? START_ON TOGGLE BLOCK_STOPS EXPLODABLE
Trains are moving platforms that players can ride.
The targets origin specifies the min point of the train at each corner.
The train spawns at the first target it is pointing at.
If the train is the target of a button or trigger, it will not begin moving until activated.

speed		default 100
dmg		default	20		This is how much damage it does when it squishes stuff.
count		default  10 if EXPLODABLE		Explosion damage is dmg * count
wait		default  dmg*count + 40	Radius for explosion.

health	defaults to 100 if EXPLODABLE

mass defaults to 75.  This determines how much debris is emitted when
it explodes.  You get one large chunk per 100 of mass (up to 8) and
one small chunk per 25 of mass (up to 16).  So 800 gives the most.

noise	looping sound to play when the train is in motion

*/

/*QUAKED trigger_elevator (0.3 0.1 0.6) (-8 -8 -8) (8 8 8)
*/

/*QUAKED func_timer (0.3 0.1 0.6) (-8 -8 -8) (8 8 8) START_ON
"wait"			base time between triggering all targets, default is 1
"random"		wait variance, default is 0

so, the basic time between firing is a random time between
(wait - random) and (wait + random)

"delay"			delay before first firing when turned on, default is 0

"pausetime"		additional delay used only the very first time
				and only if spawned with START_ON

These can used but not touched.
*/

/*QUAKED func_conveyor (0 .5 .8) ? START_ON TOGGLE
Conveyors are stationary brushes that move what's on them.
The brush should be have a surface with at least one current content enabled.
speed	default 100
*/

/*QUAKED func_door_secret (0 .5 .8) ? always_shoot 1st_left 1st_down
A secret door.  Slide back and then to the side.

open_once		doors never closes
1st_left		1st move is left of arrow
1st_down		1st move is down from arrow
always_shoot	door is shootebale even if targeted

"angle"		determines the direction
"dmg"		damage to inflic when blocked (default 2)
"wait"		how long to hold in the open position (default 5, -1 means hold)
*/

/*QUAKED func_killbox (1 0 0) ?
Kills everything inside when fired, irrespective of protection.
*/

/*QUAKED item_armor_body (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_armor_combat (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_armor_jacket (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_armor_shard (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_power_screen (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_shotgun (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_supershotgun (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_machinegun (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_chaingun (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_plasma_rifle (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED ammo_grenades (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED ammo_mines (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED ammo_detpack (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED ammo_dod (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_grenadelauncher (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_rocketlauncher (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_hellfury (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_hyperblaster (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_railgun (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_bfg (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_deatomizer (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_lasercannon (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED weapon_rtdu (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED ammo_shells (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED ammo_bullets (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED ammo_cells (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED ammo_rockets (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED ammo_slugs (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED ammo_rifleplasma (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_quad (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_invulnerability (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_silencer (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_breather (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_enviro (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_ancient_head (.3 .3 1) (-16 -16 -16) (16 16 16)
Special item that gives +2 to maximum health
*/

/*QUAKED item_adrenaline (.3 .3 1) (-16 -16 -16) (16 16 16)
gives +1 to maximum health
*/

/*QUAKED item_bandolier (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_pack (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED key_data_cd (0 .5 .8) (-16 -16 -16) (16 16 16)
key for computer centers
*/

/*QUAKED key_power_cube (0 .5 .8) (-16 -16 -16) (16 16 16) TRIGGER_SPAWN NO_TOUCH
warehouse circuits
*/

/*QUAKED key_pyramid (0 .5 .8) (-16 -16 -16) (16 16 16)
key for the entrance of jail3
*/

/*QUAKED key_data_spinner (0 .5 .8) (-16 -16 -16) (16 16 16)
key for the city computer
*/

/*QUAKED key_pass (0 .5 .8) (-16 -16 -16) (16 16 16)
security pass for the security level
*/

/*QUAKED key_blue_key (0 .5 .8) (-16 -16 -16) (16 16 16)
normal door key - blue
*/

/*QUAKED key_red_key (0 .5 .8) (-16 -16 -16) (16 16 16)
normal door key - red
*/

/*QUAKED key_commander_head (0 .5 .8) (-16 -16 -16) (16 16 16)
tank commander's head
*/

/*QUAKED key_airstrike_target (0 .5 .8) (-16 -16 -16) (16 16 16)
tank commander's head
*/

/*QUAKED item_health (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_health_small (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_health_large (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED item_health_mega (.3 .3 1) (-16 -16 -16) (16 16 16)
*/

/*QUAKED func_group (0 0 0) ?
Used to group brushes together just for editor convenience.
*/

/*QUAKED func_areaportal (0 0 0) ?

This is a non-visible object that divides the world into
areas that are seperated when this portal is not activated.
Usually enclosed in the middle of a door.
*/

/*QUAKED path_corner (.5 .3 0) (-8 -8 -8) (8 8 8) TELEPORT
This is a point entity used by trains and monsters to
facilitate movement between waypoints.

target		next path corner
pathtarget	gets used when an entity that has this path_corner targeted 
			touches it
speed		speed to move until a path corner has a new speed or
			duration defined. default 100.
duration	Number of seconds to take to move to next path_corner.
			Does not carry between path_corners.  Overrides speed
			but no default.
speeds		Takes x y z values for rotation with rotate_train.
rotate		takes x y z values to be used for partial rotation
			on rotate_trains.  Overrides speeds.
*/

/*QUAKED point_combat (0.5 0.3 0) (-8 -8 -8) (8 8 8) Hold
Makes this the target of a monster and it will head here
when first activated before going after the activator.  If
hold is selected, it will stay here.
*/

/*QUAKED viewthing (0 .5 .8) (-8 -8 -8) (8 8 8)
Just for the debugging level.  Don't use
*/

/*QUAKED info_null (0 0.5 0) (-4 -4 -4) (4 4 4)
Used as a positional target for spotlights, etc.
*/

/*QUAKED info_notnull (0 0.5 0) (-4 -4 -4) (4 4 4)
Used as a positional target for lightning.
*/

/*QUAKED info_teleport_dest (1 0 0) (-64 -64 -96) (32 32 64)
Invisible teleport landing marker. Point trigger_teleports at these to define
the exit position and facing.
*/

/*QUAKED light (0 1 0) (-8 -8 -8) (8 8 8) START_OFF
Non-displayed light.
Default light value is 300.
Default style is 0.
If targeted, will toggle between on and off.
Default _cone value is 10 (used to set size of light for spotlights)
*/

/*QUAKED func_wall (0 .5 .8) ? TRIGGER_SPAWN TOGGLE START_ON ANIMATED ANIMATED_FAST
This is just a solid wall if not inhibited

TRIGGER_SPAWN	the wall will not be present until triggered
				it will then blink in to existance; it will
				kill anything that was in it's way

TOGGLE			only valid for TRIGGER_SPAWN walls
				this allows the wall to be turned on and off

START_ON		only valid for TRIGGER_SPAWN walls
				the wall will initially be present
*/

/*QUAKED func_object (0 .5 .8) ? TRIGGER_SPAWN ANIMATED ANIMATED_FAST
This is solid bmodel that will fall if it's support it removed.
*/

/*QUAKED func_explosive (0 .5 .8) ? Trigger_Spawn ANIMATED ANIMATED_FAST
Any brush that you want to explode or break apart.


If targeted it will not be shootable.

health	default	100
dmg		default	0		Base damage for explosion
count		default  1		Explosion damage is dmg * count.  For compatibility with func_train
wait		default  dmg*count+40	Radius for explosion.

mass defaults to 75.  This determines how much debris is emitted when
it explodes.  You get one large chunk per 100 of mass (up to 8) and
one small chunk per 25 of mass (up to 16).  So 800 gives the most.
*/

/*QUAKED misc_explobox (0 .5 .8) (-16 -16 0) (16 16 40)
Large exploding box.  You can override its mass (100),
health (80), and dmg (150).
*/

/*QUAKED misc_blackhole (1 .5 0) (-8 -8 -8) (8 8 8)
*/

/*QUAKED misc_eastertank (1 .5 0) (-32 -32 -16) (32 32 32)
*/

/*QUAKED misc_easterchick (1 .5 0) (-32 -32 0) (32 32 32)
*/

/*QUAKED misc_easterchick2 (1 .5 0) (-32 -32 0) (32 32 32)
*/

/*QUAKED misc_camera (1 0 0 ) (-8 -8 -8) (8 8 8) FREEZE
Cutscene camera type thing.

FREEZE: freezes player's movement when viewing through camera

"angles" - sets the starting view dir, target overrides this
"wait" - time to view through this camera.  Overridden if the
         camera encounters a path_corner with delay -1.  A
         wait of -1 means the camera stays on indefinitely.  Default
         is 3.
"speed" - speed to move until reset by a path_corner
"target" - entity to stay focused on
"pathtarget" - this allows the camera to move
*/

/*QUAKED misc_camera_target (1 0 0 ) (-8 -8 -8) (8 8 8)
Target for cutscene misc_camera.

"speed" - speed to move until reset by a path_corner
"target" - entity to stay focused on
*/

/*QUAKED monster_commander_body (1 .5 0) (-32 -32 0) (32 32 48)
Not really a monster, this is the Tank Commander's decapitated body.
There should be a item_commander_head that has this as it's target.
*/

/*QUAKED misc_banner (1 .5 0) (-4 -4 -4) (4 4 4)
The origin is the bottom of the banner.
The banner is 128 tall.
*/

/*QUAKED misc_deadsoldier (1 .5 0) (-16 -16 0) (16 16 16) ON_BACK ON_STOMACH BACK_DECAP FETAL_POS SIT_DECAP IMPALED
This is the dead player model. Comes in 6 exciting different poses!
*/

/*QUAKED misc_viper (1 .5 0) (-16 -16 0) (16 16 32)
This is the Viper for the flyby bombing.
It is trigger_spawned, so you must have something use it for it to show up.
There must be a path for it to follow once it is activated.

"speed"		How fast the Viper should fly
*/

/*QUAKED misc_bigviper (1 .5 0) (-176 -120 -24) (176 120 72) 
This is a large stationary viper as seen in Paul's intro
*/

/*QUAKED misc_viper_bomb (1 0 0) (-8 -8 -8) (8 8 8)
"dmg"	how much boom should the bomb make?
*/

/*QUAKED misc_strogg_ship (1 .5 0) (-16 -16 0) (16 16 32)
This is a Storgg ship for the flybys.
It is trigger_spawned, so you must have something use it for it to show up.
There must be a path for it to follow once it is activated.

"speed"		How fast it should fly
*/

/*QUAKED misc_satellite_dish (1 .5 0) (-64 -64 0) (64 64 128)
*/

/*QUAKED light_mine1 (0 1 0) (-2 -2 -12) (2 2 12)
*/

/*QUAKED light_mine2 (0 1 0) (-2 -2 -12) (2 2 12)
*/

/*QUAKED misc_gib_arm (1 0 0) (-8 -8 -8) (8 8 8)
Intended for use with the target_spawner
*/

/*QUAKED misc_gib_leg (1 0 0) (-8 -8 -8) (8 8 8)
Intended for use with the target_spawner
*/

/*QUAKED misc_gib_head (1 0 0) (-8 -8 -8) (8 8 8)
Intended for use with the target_spawner
*/

/*QUAKED target_character (0 0 1) ?
used with target_string (must be on same "team")
"count" is position in the string (starts at 1)
*/

/*QUAKED target_string (0 0 1) (-8 -8 -8) (8 8 8)
*/

/*QUAKED func_clock (0 0 1) (-8 -8 -8) (8 8 8) TIMER_UP TIMER_DOWN START_OFF MULTI_USE
target a target_string with this

The default is to be a time of day clock

TIMER_UP and TIMER_DOWN run for "count" seconds and the fire "pathtarget"
If START_OFF, this entity must be used before it starts

"style"		0 "xx"
			1 "xx:xx"
			2 "xx:xx:xx"
*/

/*QUAKED misc_teleporter (1 0 0) (-32 -32 -24) (32 32 -16)
Stepping onto this disc will teleport players to the targeted misc_teleporter_dest object.
*/

/*QUAKED misc_teleporter_dest (1 0 0) (-32 -32 -24) (32 32 -16)
Point teleporters at these.
*/

/*QUAKED func_rotate_train (0 .5 .8) ? START_ON TOGGLE BLOCK_STOPS
Rotate trains are like standard trains but can rotate as well.
The targets origin specifies the ORIGIN of the train at each corner.
The train spawns at the first target it is pointing at.
If the train is the target of a button or trigger, it will not begin
moving until activated.

NOTE: This classname was historically compiled out of the stock DLL unless
`OBLIVION_ENABLE_ROTATE_TRAIN` was set to 1. The repo now enables the macro by
default so that the entity matches the recovered HLIL reference, but level
scripts can still toggle it off if they need to mirror the retail binary.

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

/*QUAKED worldspawn (0 0 0) ?

Only used for the world.
"sky"	environment map name
"skyaxis"	vector axis for rotating sky
"skyrotate"	speed of rotation in degrees/second
"nextmap"	map to load after completing the level
"sounds"	music cd track number
"gravity"	800 is default gravity
"message"	text to print at user logon
*/

/*QUAKED target_temp_entity (1 0 0) (-8 -8 -8) (8 8 8)
Fire an origin based temp entity event to the clients.
"style"		type byte
*/

/*QUAKED target_speaker (1 0 0) (-8 -8 -8) (8 8 8) looped-on looped-off reliable
"noise"		wav file to play
"attenuation"
-1 = none, send to whole level
1 = normal fighting sounds
2 = idle sound level
3 = ambient sound level
"volume"	0.0 to 1.0

Normal sounds play each time the target is used.  The reliable flag can be set for crucial voiceovers.

Looped sounds are always atten 3 / vol 1, and the use function toggles it on/off.
Multiple identical looping sounds will just increase volume without any speed cost.
*/

/*QUAKED target_help (1 0 1) (-16 -16 -24) (16 16 24) help1
When fired, the "message" key becomes the current personal computer string, and the message light will be set on all clients status bars.
*/

/*QUAKED target_secret (1 0 1) (-8 -8 -8) (8 8 8)
Counts a secret found.
These are single use targets.
*/

/*QUAKED target_goal (1 0 1) (-8 -8 -8) (8 8 8)
Counts a goal completed.
These are single use targets.
*/

/*QUAKED target_explosion (1 0 0) (-8 -8 -8) (8 8 8)
Spawns an explosion temporary entity when used.

"delay"		wait this long before going off
"dmg"		how much radius damage should be done, defaults to 0
*/

/*QUAKED target_changelevel (1 0 0) (-8 -8 -8) (8 8 8)
Changes level to "map" when fired
*/

/*QUAKED target_splash (1 0 0) (-8 -8 -8) (8 8 8)
Creates a particle splash effect when used.

Set "sounds" to one of the following:
  1) sparks
  2) blue water
  3) brown water
  4) slime
  5) lava
  6) blood

"count"	how many pixels in the splash
"dmg"	if set, does a radius damage at this location when it splashes
		useful for lava/sparks
*/

/*QUAKED target_spawner (1 0 0) (-8 -8 -8) (8 8 8)
Set target to the type of entity you want spawned.
Useful for spawning monsters and gibs in the factory levels.

For monsters:
	Set direction to the facing you want it to have.

For gibs:
	Set direction if you want it moving and
	speed how fast it should be moving otherwise it
	will just be dropped
*/

/*QUAKED target_blaster (1 0 0) (-8 -8 -8) (8 8 8) NOTRAIL NOEFFECTS
Fires a blaster bolt in the set direction when triggered.

dmg		default is 15
speed	default is 1000
*/

/*QUAKED target_railgun (1 0 0) (-8 -8 -8) (8 8 8)
Fires a railgun shot in set direction when triggered

dmg		default is 150
*/

/*QUAKED target_rocket (1 0 0) (-8 -8 -8) (8 8 8)
Fires a rocket in the set direction

dmg		default is 100 + (int)(random() * 20.0);
count		radius damage - default 120
delay		damage radius - how far out the radius damage applies
speed		default is 650
*/

/*QUAKED target_crosslevel_trigger (.5 .5 .5) (-8 -8 -8) (8 8 8) trigger1 trigger2 trigger3 trigger4 trigger5 trigger6 trigger7 trigger8
Once this trigger is touched/used, any trigger_crosslevel_target with the same trigger number is automatically used when a level is started within the same unit.  It is OK to check multiple triggers.  Message, delay, target, and killtarget also work.
*/

/*QUAKED target_crosslevel_target (.5 .5 .5) (-8 -8 -8) (8 8 8) trigger1 trigger2 trigger3 trigger4 trigger5 trigger6 trigger7 trigger8
Triggered by a trigger_crosslevel elsewhere within a unit.  If multiple triggers are checked, all must be true.  Delay, target and
killtarget also work.

"delay"		delay before using targets if the trigger has been activated (default 1)
*/

/*QUAKED target_laser (0 .5 .8) (-8 -8 -8) (8 8 8) START_ON RED GREEN BLUE YELLOW ORANGE FAT THIN
When triggered, fires a laser.  You can either set a target
or a direction.
*/

/*QUAKED target_lightramp (0 .5 .8) (-8 -8 -8) (8 8 8) TOGGLE
speed		How many seconds the ramping will take
message		two letters; starting lightlevel and ending lightlevel
*/

/*QUAKED target_earthquake (1 0 0) (-8 -8 -8) (8 8 8)
When triggered, this initiates a level-wide earthquake.
All players and monsters are affected.
"speed"		severity of the quake (default:200)
"count"		duration of the quake (default:5)
*/

/*QUAKED trigger_multiple (.5 .5 .5) ? MONSTER NOT_PLAYER TRIGGERED
Variable sized repeatable trigger.  Must be targeted at one or more entities.
If "delay" is set, the trigger waits some time after activating before firing.
"wait" : Seconds between triggerings. (.2 default)
sounds
1)	secret
2)	beep beep
3)	large switch
4)
set "message" to text string
*/

/*QUAKED trigger_once (.5 .5 .5) ? x x TRIGGERED
Triggers once, then removes itself.
You must set the key "target" to the name of another object in the level that has a matching "targetname".

If TRIGGERED, this trigger must be triggered before it is live.

sounds
 1)	secret
 2)	beep beep
 3)	large switch
 4)

"message"	string to be displayed when triggered
*/

/*QUAKED trigger_relay (.5 .5 .5) (-8 -8 -8) (8 8 8)
This fixed size trigger cannot be touched, it can only be fired by other events.
*/

/*QUAKED trigger_key (.5 .5 .5) (-8 -8 -8) (8 8 8)
A relay trigger that only fires it's targets if player has the proper key.
Use "item" to specify the required key, for example "key_data_cd"
*/

/*QUAKED trigger_counter (.5 .5 .5) ? nomessage
Acts as an intermediary for an action that takes multiple inputs.

If nomessage is not set, t will print "1 more.. " etc when triggered and "sequence complete" when finished.

After the counter has been triggered "count" times (default 2), it will fire all of it's targets and remove itself.
*/

/*QUAKED trigger_always (.5 .5 .5) (-8 -8 -8) (8 8 8)
This trigger will always fire.  It is activated by the world.
*/

/*QUAKED trigger_push (.5 .5 .5) ? PUSH_ONCE START_OFF
Pushes the player
"speed"		defaults to 1000
*/

/*QUAKED trigger_hurt (.5 .5 .5) ? START_OFF TOGGLE SILENT NO_PROTECTION SLOW
Any entity that touches this will be hurt.

It does dmg points of damage each server frame

SILENT			supresses playing the sound
SLOW			changes the damage rate to once per second
NO_PROTECTION	*nothing* stops the damage

"dmg"			default 5 (whole numbers only)

*/

/*QUAKED trigger_gravity (.5 .5 .5) ?
Changes the touching entites gravity to
the value of "gravity".  1.0 is standard
gravity for the level.
*/

/*QUAKED trigger_monsterjump (.5 .5 .5) ?
Walking monsters that touch this will jump in the direction of the trigger's angle
"speed" default to 200, the speed thrown forward
"height" default to 200, the speed thrown upwards
*/

/*QUAKED trigger_teleport (.5 .5 .5) ? NOMONSTER NOPLAYER START_OFF NOEFFECTS NOTOUCH

must have a "target" that points to misc_teleporter_dest or info_teleport_dest

NOMONSTER - doesn't teleports monsters
NOPLAYER - doesn't teleport the player
START_OFF - starts disabled, makes it so when targetted, it becomes enabled.
            ignored if NOTOUCH is set
NOEFFECTS - no effects or noise or anything
NOTOUCH - only teleports when targetted

*/

/*QUAKED trigger_misc_camera (.5 .5 .5) ? MONSTER NOT_PLAYER TRIGGERED
Variable sized repeatable trigger for activating a misc_camera.
Must be targeted at ONLY ONE misc_camera.
"wait" - this is how long the targetted camera will stay on (unless its
         path_corners make it turn off earlier).  If wait is -1, the camera
         will stay on indefinitely.  Default wait is to use misc_camera's wait.
"delay" - this is how long the trigger will wait before reactivating itself.  Default
         is 1.0.  NOTE: This allows the trigger to trigger a camera that's still on.
"target" - this is the camera to target
"pathtarget" - this is the targetname of the entity the camera should track.
               The default is the entity that activated the trigger.
"message" - guess

HINT: If you fill a room with a trigger_misc_camera, then set the delay to .1 and the
wait to .2, then as long as the player is in the room, the camera will stay on.  Then
as soon as the player leaves the room, the camera will turn off.

sounds
1)	secret
2)	beep beep
3)	large switch
4)
*/

/*QUAKED turret_breach (0 0 0) ?
This portion of the turret can change both pitch and yaw.
The model  should be made with a flat pitch.
It (and the associated base) need to be oriented towards 0.
Use "angle" to set the starting angle.

"speed"		default 50
"dmg"		default 10
"angle"		point this forward
"target"	point this at an info_notnull at the muzzle tip
"minpitch"	min acceptable pitch angle : default -30
"maxpitch"	max acceptable pitch angle : default 30
"minyaw"	min acceptable yaw angle   : default 0
"maxyaw"	max acceptable yaw angle   : default 360
*/

/*QUAKED turret_base (0 0 0) ?
This portion of the turret changes yaw only.
MUST be teamed with a turret_breach.
*/

/*QUAKED turret_driver (1 .5 0) (-16 -16 -24) (16 16 32)
Must NOT be on the team with the rest of the turret parts.it must target the turret_breach.
*/

/*QUAKED misc_actor (1 .5 0) (-16 -16 -24) (16 16 32)  Ambush Trigger_Spawn Sight Corpse x START_ON WIMPY
*/

/*QUAKED target_actor (.5 .3 0) (-8 -8 -8) (8 8 8) JUMP SHOOT ATTACK x HOLD BRUTAL
JUMP			jump in set direction upon reaching this target
SHOOT			take a single shot at the pathtarget
ATTACK			attack pathtarget until it or actor is dead 

"target"		next target_actor
"pathtarget"	target of any action to be taken at this point
"wait"			amount of time actor should pause at this point
"message"		actor will "say" this to the player

for JUMP only:
"speed"			speed thrown forward (default 200)
"height"		speed thrown upwards (default 200)
*/

/*QUAKED monster_berserk (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_boss2 (1 .5 0) (-56 -56 0) (56 56 80) Ambush Trigger_Spawn Sight
*/

/*QUAKED monster_boss3_stand (1 .5 0) (-32 -32 0) (32 32 90)

Just stands and cycles in one place until targeted, then teleports away.
*/

/*QUAKED monster_jorg (1 .5 0) (-80 -80 0) (90 90 140) Ambush Trigger_Spawn Sight
*/

/*QUAKED monster_makron (1 .5 0) (-30 -30 0) (30 30 90) Ambush Trigger_Spawn Sight
*/

/*QUAKED monster_brain (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_chick (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_flipper (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight
*/

/*QUAKED monster_floater (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight
*/

/*QUAKED monster_flyer (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight
*/

/*QUAKED monster_gladiator (1 .5 0) (-32 -32 -24) (32 32 64) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_gunner (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_hover (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_infantry (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED misc_insane (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn CRAWL Corpse CRUCIFIED STAND_GROUND ALWAYS_STAND
*/

/*QUAKED monster_medic (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_mutant (1 .5 0) (-32 -32 -24) (32 32 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_parasite (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_soldier_light (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_soldier (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_soldier_ss (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_soldier_deatom (1 .5 0) (-16 -16 -24) (16 16 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_supertank (1 .5 0) (-64 -64 0) (64 64 72) Ambush Trigger_Spawn Sight
*/

/*QUAKED monster_tank (1 .5 0) (-32 -32 -16) (32 32 72) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_tank_commander (1 .5 0) (-32 -32 -16) (32 32 72) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_kigrax (1 .5 0) (-20 -20 -32) (20 20 12) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_badass (1 .5 0) (-45 -48 -64) (38 48 30) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_spider (1 .5 0) (-32 -32 -35) (32 32 32) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED monster_cyborg (1 .5 0) (-16 -16 -38) (32 32 27) Ambush Trigger_Spawn Sight Corpse
*/

/*QUAKED info_player_start (1 0 0) (-16 -16 -24) (16 16 32)
The normal starting point for a level.
*/

/*QUAKED info_player_deathmatch (1 0 1) (-16 -16 -24) (16 16 32)
potential spawning position for deathmatch games
*/

/*QUAKED info_player_coop (1 0 1) (-16 -16 -24) (16 16 32)
potential spawning position for coop games
*/

/*QUAKED info_player_intermission (1 0 1) (-16 -16 -24) (16 16 32)
The deathmatch intermission point will be at one of these
Use 'angles' instead of 'angle', so you can set pitch or roll as well as yaw.  'pitch yaw roll'
*/

/*QUAKED misc_screenfader (0 0 1) (-8 -8 -8) (8 8 8) START_ON
fades the player's screen from the first color to the second color over count seconds.
colors are text strings of the form "r.r g.g b.b a.a".  They should be floating point
values between 0 and 1.  This is the same as the scale of 0 to 255 most people are used to.
r,g, and b are self-explanatory. a is the "alpha" component.  That is, how opaque/transparent
the color is.  0 is completely transparent, 1 is completely opaque.  So to fade a screen
from normal to black, you'd do
target "0.0 0.0 0.0 0.0"
pathtarget "0.0 0.0 0.0 1.0"

pathtarget	color 1
deathtarget	color 2
count			# of seconds
target		object to trigger when this finishes (good for triggering another misc_screenfader
            or a trigger_changelevel

*/
