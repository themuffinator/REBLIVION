#!/usr/bin/env python3
from __future__ import annotations

import argparse
from dataclasses import dataclass
from pathlib import Path
import re
import sys


QUAKED_BLOCK_RE = re.compile(r"/\*QUAKED\s+.*?\*/", re.S)
QUAKED_HEADER_RE = re.compile(
    r"/\*QUAKED\s+([^\s(]+)\s+\(([^)]*)\)\s+(?:(\?)|\(([^)]*)\)\s+\(([^)]*)\))\s*(.*?)\n",
    re.S,
)
FGD_NAME_RE = re.compile(r"=\s*([A-Za-z0-9_]+)\s*(?::|\[)")
DECLARED_MODEL_RE = re.compile(r'\bmodel\s*=\s*"([^"]+)"')
QUOTED_PROPERTY_RE = re.compile(r'^"([A-Za-z_][A-Za-z0-9_]*)"\s*:?\s*(.+)$')
COLON_PROPERTY_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s*:\s*(.+)$")
SPACED_PROPERTY_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s{2,}(.+)$")
DEFAULT_PROPERTY_RE = re.compile(
    r"^([A-Za-z_][A-Za-z0-9_]*)\s+default(?:\s*(?:is|=|:))?\s*([-+]?\d+(?:\.\d+)?)\b",
    re.I,
)


RUNTIME_SOURCE_GLOBS = ("*.c", "*.cc", "*.cpp", "*.cxx")


TB_MODEL_HINTS = {
    "ammo_detpack": "models/items/ammo/detpack/tris.md2",
    "ammo_dod": "models/weapons/g_dod/tris.md2",
    "ammo_mines": "models/items/ammo/mines/tris.md2",
    "ammo_rifleplasma": "models/items/plasmapack/tris.md2",
    "dm_dball_ball": "models/objects/dball/tris.md2",
    "item_invisibility": "models/items/cloaker/tris.md2",
    "item_legacy_head": "models/items/legacyhead/tris.md2",
    "monster_badass": "models/monsters/badass/tris.md2",
    "monster_cyborg": "models/monsters/cyborg/tris.md2",
    "monster_kigrax": "models/monsters/kigrax/tris.md2",
    "monster_soldier_deatom": "models/monsters/soldier/tris.md2",
    "monster_spider": "models/monsters/spider/tris.md2",
    "monster_tank_stand": "models/monsters/tank/tris.md2",
    "monster_widow2": "models/monsters/blackwidow2/tris.md2",
    "rotating_light": "models/objects/light/tris.md2",
    "target_railgun": "models/objects/laser/tris.md2",
    "target_rocket": "models/objects/laser/tris.md2",
    "weapon_deatomizer": "models/weapons/g_deatom/tris.md2",
    "weapon_hellfury": "models/weapons/g_hellfury/tris.md2",
    "weapon_plasma_rifle": "models/weapons/g_plasma/tris.md2",
    "weapon_rtdu": "models/objects/rtdu/rtdu.md2",
}


NRC_MODEL_HINTS = {
    classname: path for classname, path in TB_MODEL_HINTS.items()
}


ALIASES = {
    "info_teleporter_dest": "info_teleport_dest",
}


TITLE_OVERRIDES = {
    "ammo_detpack": "Detpack Ammo",
    "ammo_dod": "DOD Ammo",
    "ammo_mines": "Mines",
    "ammo_rifleplasma": "Rifle Plasma",
    "dm_dball_ball": "Deathball Ball",
    "dm_dball_ball_start": "Deathball Ball Start",
    "dm_dball_goal": "Deathball Goal",
    "dm_dball_speed_change": "Deathball Speed Change",
    "dm_dball_team1_start": "Deathball Team 1 Start",
    "dm_dball_team2_start": "Deathball Team 2 Start",
    "dm_tag_token": "Tag Token",
    "func_conveyor": "Conveyor",
    "func_rotate_train": "Rotating Train",
    "info_ctf_teleport_destination": "CTF Teleport Destination",
    "info_teleport_dest": "Teleport Destination",
    "info_teleporter_dest": "Teleport Destination (Alias)",
    "item_invisibility": "Invisibility",
    "item_legacy_head": "Legacy Head",
    "misc_actor": "Scripted Actor",
    "misc_camera": "Cutscene Camera",
    "misc_camera_target": "Camera Target",
    "misc_fireball": "Lava Ball Spawner",
    "misc_model": "Map Model",
    "misc_screenfader": "Screen Fader",
    "monster_badass": "Badass",
    "monster_cyborg": "Cyborg",
    "monster_kigrax": "Kigrax",
    "monster_soldier_deatom": "Deatom Soldier",
    "monster_spider": "Spider",
    "monster_tank_stand": "Tank Stand",
    "monster_widow2": "Widow 2",
    "rotating_light": "Rotating Light",
    "target_achievement": "Achievement Trigger",
    "target_actor": "Actor Target",
    "target_gravity": "Gravity Trigger",
    "target_light": "Dynamic Light",
    "target_railgun": "Railgun Emitter",
    "target_rocket": "Rocket Emitter",
    "target_soundfx": "Sound FX Trigger",
    "trigger_ctf_teleport": "CTF Teleport",
    "trigger_misc_camera": "Camera Trigger",
    "weapon_deatomizer": "Deatomizer",
    "weapon_hellfury": "Hellfury",
    "weapon_plasma_rifle": "Plasma Rifle",
    "weapon_remote_detonator": "Remote Detonator",
    "weapon_rtdu": "RTDU",
}


DESCRIPTION_OVERRIDES = {
    "dm_dball_ball": "Deathball ball entity for the retail rerelease Deathball ruleset.",
    "dm_dball_ball_start": "Spawn marker used to place the Deathball ball when the round begins.",
    "dm_dball_goal": "Brush goal volume for the retail rerelease Deathball ruleset.",
    "dm_dball_speed_change": "Brush volume that multiplies the ball speed for retail rerelease Deathball maps.",
    "dm_dball_team1_start": "Spawn point for team 1 players in retail rerelease Deathball.",
    "dm_dball_team2_start": "Spawn point for team 2 players in retail rerelease Deathball.",
    "dm_tag_token": "Pickup token used by the retail rerelease Tag ruleset.",
    "info_teleporter_dest": "Legacy alias accepted by the REBLIVION runtime for info_teleport_dest.",
    "misc_model": "Arbitrary model entity that renders the model specified in the model key.",
    "misc_screenfader": "Screen fade controller that blends from a start RGBA string to an end RGBA string over time.",
    "target_achievement": "Gives the named Quake II rerelease achievement when triggered.",
    "target_actor": "Scripted waypoint for misc_actor pathing, jumps, fire commands, and held attacks.",
    "target_gravity": "Changes the global gravity value when triggered.",
    "target_light": "Dynamic light entity that follows a lightstyle and can interpolate toward a target light.",
    "target_railgun": "Fires a railgun trace in the set direction when triggered.",
    "target_rocket": "Fires a rocket in the set direction when triggered.",
    "target_soundfx": "Plays an N64-era Quake II rerelease sound effect when triggered.",
    "trigger_ctf_teleport": "Brush teleporter volume for retail rerelease CTF maps.",
}


SOUND_FX_CHOICES = (
    ("1", "Alarm"),
    ("2", "Flyby"),
    ("4", "Ambient 12"),
    ("5", "Ambient 17"),
    ("7", "Big Pump"),
)


PROPERTY_TYPE_OVERRIDES = {
    "achievement": "string",
    "attenuation": "float",
    "combattarget": "target_destination",
    "count": "integer",
    "deathtarget": "target_destination",
    "delay": "float",
    "dmg": "float",
    "dmg_radius": "float",
    "frame": "integer",
    "gravity": "float",
    "health": "integer",
    "healthtarget": "target_destination",
    "height": "float",
    "item": "string",
    "itemtarget": "target_destination",
    "killtarget": "target_destination",
    "map": "string",
    "message": "string",
    "model": "string",
    "noise": "string",
    "pathtarget": "target_destination",
    "radius": "float",
    "rgba": "color255",
    "scale": "float",
    "sounds": "integer",
    "speed": "float",
    "style": "integer",
    "target": "target_destination",
    "targetname": "target_source",
    "team": "string",
    "volume": "float",
    "wait": "float",
}


PROPERTY_LABEL_OVERRIDES = {
    "achievement": "Achievement",
    "attenuation": "Attenuation",
    "combattarget": "Point Combat Target",
    "count": "Count",
    "deathtarget": "Death Target",
    "delay": "Delay",
    "dmg": "Damage",
    "dmg_radius": "Damage Radius",
    "gravity": "Gravity",
    "health": "Health",
    "healthtarget": "Health Target",
    "height": "Height",
    "item": "Spawn Item",
    "itemtarget": "Item Target",
    "killtarget": "Kill Target",
    "message": "Message",
    "model": "Model Path",
    "noise": "Sound",
    "pathtarget": "Path Target",
    "radius": "Radius",
    "rgba": "Color",
    "speed": "Speed",
    "target": "Target",
    "targetname": "Target Name",
    "team": "Team",
    "volume": "Volume",
    "wait": "Wait",
}


IGNORED_AUTO_PROPERTIES = {
    "angle",
    "angles",
    "not_player",
    "note",
    "oneway",
    "team1",
    "team2",
    "these",
    "this",
    "triggered",
}


@dataclass(frozen=True)
class PropertySpec:
    name: str
    prop_type: str
    label: str
    default: str | None = None
    choices: tuple[tuple[str, str], ...] = ()


@dataclass
class QuakedBlock:
    classname: str
    color: str
    mins: str | None
    maxs: str | None
    is_brush: bool
    flags: tuple[str, ...]
    body: str
    raw: str


@dataclass
class EntitySpec:
    classname: str
    kind: str
    base_classes: tuple[str, ...]
    title: str
    description: str
    color: str
    mins: str | None
    maxs: str | None
    model_path: str | None = None
    emit_spawnflags: bool = False
    flags: tuple[str, ...] = ()
    properties: tuple[PropertySpec, ...] = ()


ENTITY_PROPERTY_OVERRIDES: dict[str, tuple[PropertySpec, ...]] = {
    "dm_dball_goal": (
        PropertySpec("wait", "float", "Score", "10"),
    ),
    "dm_dball_speed_change": (
        PropertySpec("speed", "float", "Speed Multiplier", "2"),
        PropertySpec("delay", "float", "Retrigger Delay", "0.2"),
    ),
    "func_conveyor": (
        PropertySpec("speed", "float", "Speed", "100"),
    ),
    "func_rotate_train": (
        PropertySpec("pathtarget", "target_destination", "Path Target"),
        PropertySpec("target", "target_destination", "First Corner"),
        PropertySpec("speed", "float", "Speed", "100"),
        PropertySpec("dmg", "float", "Blocked Damage", "100"),
        PropertySpec("noise", "string", "Travel Noise"),
    ),
    "misc_camera": (
        PropertySpec("wait", "float", "View Time", "3"),
        PropertySpec("speed", "float", "Move Speed"),
        PropertySpec("target", "target_destination", "Focus Target"),
        PropertySpec("pathtarget", "target_destination", "Path Target"),
    ),
    "misc_camera_target": (
        PropertySpec("speed", "float", "Move Speed"),
        PropertySpec("target", "target_destination", "Focus Target"),
    ),
    "misc_fireball": (
        PropertySpec("speed", "float", "Launch Speed", "100"),
    ),
    "misc_model": (
        PropertySpec("model", "string", "Model Path"),
    ),
    "misc_screenfader": (
        PropertySpec("pathtarget", "string", "Start RGBA"),
        PropertySpec("message", "string", "Start RGBA Fallback"),
        PropertySpec("deathtarget", "string", "End RGBA"),
        PropertySpec("delay", "float", "Fade Time"),
    ),
    "rotating_light": (
        PropertySpec("health", "integer", "Health", "10"),
        PropertySpec("speed", "float", "Light Radius", "32"),
    ),
    "target_achievement": (
        PropertySpec("achievement", "string", "Achievement"),
    ),
    "target_actor": (
        PropertySpec("target", "target_destination", "Next Actor Target"),
        PropertySpec("pathtarget", "target_destination", "Action Target"),
        PropertySpec("wait", "float", "Pause Time"),
        PropertySpec("message", "string", "Actor Speech"),
        PropertySpec("speed", "float", "Jump Speed"),
        PropertySpec("height", "float", "Jump Height"),
    ),
    "target_gravity": (
        PropertySpec("gravity", "float", "Gravity"),
    ),
    "target_light": (
        PropertySpec("rgba", "color255", "Color", "255 255 255 255"),
        PropertySpec("radius", "float", "Radius", "150"),
        PropertySpec("speed", "float", "Style Speed", "1"),
        PropertySpec("target", "target_destination", "Style Source Light"),
    ),
    "target_railgun": (
        PropertySpec("dmg", "float", "Damage"),
    ),
    "target_rocket": (
        PropertySpec("dmg", "float", "Damage"),
        PropertySpec("speed", "float", "Speed"),
        PropertySpec("dmg_radius", "float", "Damage Radius"),
        PropertySpec("count", "integer", "Radius Damage"),
    ),
    "target_soundfx": (
        PropertySpec("noise", "choices", "Sound", "1", choices=SOUND_FX_CHOICES),
        PropertySpec("volume", "float", "Volume", "1"),
        PropertySpec("attenuation", "float", "Attenuation", "1"),
        PropertySpec("delay", "float", "Delay", "0"),
    ),
    "trigger_ctf_teleport": (
        PropertySpec("target", "target_destination", "Destination"),
    ),
    "trigger_misc_camera": (
        PropertySpec("wait", "float", "Camera Time"),
        PropertySpec("delay", "float", "Retrigger Delay", "1.0"),
        PropertySpec("target", "target_destination", "Camera Target"),
        PropertySpec("pathtarget", "target_destination", "Focus Target Override"),
        PropertySpec("message", "string", "Message"),
    ),
}


ENTITY_BASE_CLASS_OVERRIDES: dict[str, tuple[str, ...]] = {
    "dm_dball_ball": ("EditorFlags",),
    "dm_dball_ball_start": ("EditorFlags",),
    "dm_dball_goal": ("EditorFlags",),
    "dm_dball_speed_change": ("EditorFlags", "Angleable"),
    "dm_dball_team1_start": ("EditorFlags", "Angleable"),
    "dm_dball_team2_start": ("EditorFlags", "Angleable"),
    "dm_tag_token": ("Items",),
    "func_conveyor": ("EditorFlags", "Targetable", "EWT_base_BModel"),
    "func_rotate_train": ("EditorFlags", "Targetable", "UseTargets", "Teamable", "EWT_base_BModel"),
    "info_ctf_teleport_destination": ("info_notnull", "Angleable"),
    "info_teleport_dest": ("info_notnull", "Angleable"),
    "info_teleporter_dest": ("info_notnull", "Angleable"),
    "item_invisibility": ("Items",),
    "item_legacy_head": ("Items",),
    "misc_actor": ("REBLIVION_Monsters",),
    "misc_camera": ("EditorFlags", "Targetable", "Angleable"),
    "misc_camera_target": ("EditorFlags", "Targetable"),
    "misc_fireball": ("EditorFlags",),
    "misc_model": ("EditorFlags", "Scale", "Alpha"),
    "misc_screenfader": ("EditorFlags", "Targetable"),
    "rotating_light": ("EditorFlags", "Targetable"),
    "target_achievement": ("EditorFlags", "Targetable"),
    "target_actor": ("EditorFlags", "Targetable"),
    "target_gravity": ("EditorFlags", "Targetable"),
    "target_light": ("EditorFlags", "Targetable"),
    "target_railgun": ("EditorFlags", "Targetable", "Angleable"),
    "target_rocket": ("EditorFlags", "Targetable", "Angleable"),
    "target_soundfx": ("EditorFlags", "Targetable"),
    "trigger_ctf_teleport": ("EditorFlags",),
    "trigger_misc_camera": ("EditorFlags", "Targetable"),
}


SPAWNFLAG_ENTITY_ALLOWLIST = {
    "dm_dball_ball",
    "dm_dball_goal",
    "dm_dball_speed_change",
    "func_conveyor",
    "func_rotate_train",
    "misc_actor",
    "misc_camera",
    "misc_fireball",
    "misc_screenfader",
    "rotating_light",
    "target_actor",
    "target_light",
    "trigger_misc_camera",
}


AUTO_PROPERTY_EXCLUDES: dict[str, set[str]] = {
    "func_rotate_train": {"duration", "rotate", "speeds", "wait"},
    "target_rocket": {"delay"},
}


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate REBLIVION rerelease-first FGD files for NRC and TrenchBroom."
    )
    parser.add_argument(
        "--legacy-source",
        type=Path,
        default=Path("references/Oblivion-reverse/pack/oblivion.c"),
        help="Legacy Oblivion QUAKED source used as a fallback for recovered editor metadata.",
    )
    parser.add_argument(
        "--runtime-root",
        type=Path,
        default=Path("src"),
        help="Current runtime source tree used as the authoritative entity surface.",
    )
    parser.add_argument(
        "--maps-root",
        type=Path,
        default=Path("src/maps"),
        help="Map source root used to verify entity coverage.",
    )
    parser.add_argument(
        "--nrc-base-fgd",
        type=Path,
        default=Path("editor/netradiant-custom/gamepacks/reblivion.game/baseq2/Quake2.fgd"),
        help="Base q2re FGD file used for the NetRadiant-Custom pack.",
    )
    parser.add_argument(
        "--nrc-output",
        type=Path,
        default=Path("editor/netradiant-custom/gamepacks/reblivion.game/reblivion/Quake2.fgd"),
        help="Generated REBLIVION FGD for NetRadiant-Custom.",
    )
    parser.add_argument(
        "--tb-base-fgd",
        type=Path,
        default=Path("editor/trenchbroom/games/REBLIVION/Quake2.fgd"),
        help="Base q2re FGD file used for the TrenchBroom pack.",
    )
    parser.add_argument(
        "--tb-output",
        type=Path,
        default=Path("editor/trenchbroom/games/REBLIVION/REBLIVION.fgd"),
        help="Generated REBLIVION FGD for TrenchBroom.",
    )
    return parser.parse_args()


def read_text(path: Path) -> str:
    return path.read_text(encoding="utf-8", errors="ignore")


def iter_runtime_sources(root: Path) -> list[Path]:
    paths: list[Path] = []
    for pattern in RUNTIME_SOURCE_GLOBS:
        paths.extend(sorted(root.rglob(pattern)))
    return paths


def parse_quaked_block(raw: str) -> QuakedBlock | None:
    match = QUAKED_HEADER_RE.match(raw)
    if not match:
        return None

    classname = match.group(1)
    color = " ".join(match.group(2).split())
    is_brush = match.group(3) == "?"
    mins = None if is_brush else " ".join((match.group(4) or "").split())
    maxs = None if is_brush else " ".join((match.group(5) or "").split())
    flags = tuple(token for token in match.group(6).split() if token)
    body = raw[match.end() : -2].strip()
    return QuakedBlock(
        classname=classname,
        color=color,
        mins=mins,
        maxs=maxs,
        is_brush=is_brush,
        flags=flags,
        body=body,
        raw=raw,
    )


def parse_quaked_blocks(text: str) -> dict[str, QuakedBlock]:
    blocks: dict[str, QuakedBlock] = {}
    for raw in QUAKED_BLOCK_RE.findall(text):
        block = parse_quaked_block(raw)
        if block is not None:
            blocks[block.classname] = block
    return blocks


def parse_fgd_names(text: str) -> set[str]:
    return set(FGD_NAME_RE.findall(text))


def collect_map_entities(maps_root: Path) -> set[str]:
    classnames: set[str] = set()
    for path in sorted(maps_root.rglob("*.map")):
        classnames.update(re.findall(r'"classname"\s+"([^"]+)"', read_text(path)))
    return classnames


def has_runtime_reference(runtime_text: str, classname: str) -> bool:
    return f'"{classname}"' in runtime_text


def block_has_useful_body(block: QuakedBlock | None) -> bool:
    return block is not None and any(ch.isalpha() for ch in block.body)


def merge_blocks(runtime_block: QuakedBlock | None, legacy_block: QuakedBlock | None) -> QuakedBlock:
    if runtime_block is None and legacy_block is None:
        raise ValueError("merge_blocks requires at least one source block")
    if runtime_block is None:
        return legacy_block  # type: ignore[return-value]
    if legacy_block is None:
        return runtime_block
    if block_has_useful_body(runtime_block):
        return runtime_block
    return QuakedBlock(
        classname=runtime_block.classname,
        color=runtime_block.color,
        mins=runtime_block.mins,
        maxs=runtime_block.maxs,
        is_brush=runtime_block.is_brush,
        flags=runtime_block.flags or legacy_block.flags,
        body=legacy_block.body,
        raw=runtime_block.raw,
    )


def first_paragraph(body: str) -> str:
    lines: list[str] = []
    for raw_line in body.splitlines():
        line = raw_line.strip()
        if not line:
            if lines:
                break
            continue
        if line.startswith('"'):
            break
        if re.match(r"^[A-Z0-9_]+\s*:?", line):
            break
        if "\t" in line and line.split("\t", 1)[0].isidentifier():
            break
        lines.append(line)
    return " ".join(lines).strip()


def extract_declared_model(body: str) -> str | None:
    match = DECLARED_MODEL_RE.search(body)
    if not match:
        return None
    return match.group(1)


def display_flag_name(token: str) -> str:
    token = token.replace("_", " ")
    return " ".join(part.capitalize() for part in token.split())


def build_spawnflags_block(flags: tuple[str, ...], indent: str) -> str:
    lines = [f"{indent}spawnflags(Flags) =", f"{indent}["]
    for index, flag in enumerate(flags):
        if flag.lower() == "x":
            continue
        bit_value = 1 << index
        lines.append(f'{indent}    {bit_value} : "{display_flag_name(flag)}" : 0')
    lines.append(f"{indent}]")
    return "\n".join(lines)


def format_default(value: str | None) -> str | None:
    if value is None:
        return None
    try:
        float(value)
    except ValueError:
        return f'"{value}"'
    return value


def emit_property(prop: PropertySpec, indent: str) -> str:
    if prop.choices:
        default = format_default(prop.default) or "0"
        lines = [f'{indent}{prop.name}({prop.prop_type}) : "{prop.label}" : {default} =', f"{indent}["]
        for value, label in prop.choices:
            lines.append(f'{indent}    {value} : "{label}"')
        lines.append(f"{indent}]")
        return "\n".join(lines)

    default = format_default(prop.default)
    if default is None:
        return f'{indent}{prop.name}({prop.prop_type}) : "{prop.label}"'
    return f'{indent}{prop.name}({prop.prop_type}) : "{prop.label}" : {default}'


def emit_tb_model(model_path: str | None) -> str:
    if model_path is None:
        return ""
    return f' model({{ "path": ":{model_path}" }})'


def emit_nrc_model(model_path: str | None) -> str:
    if model_path is None:
        return ""
    return f' studio("{model_path}")'


def build_base_class_text() -> str:
    return "@BaseClass base(Monsters) = REBLIVION_Monsters []"


def humanize_classname(classname: str) -> str:
    return " ".join(part.capitalize() for part in classname.split("_"))


def humanize_key(name: str) -> str:
    return " ".join(part.upper() if part == "rgba" else part.capitalize() for part in name.split("_"))


def extract_default_value(description: str) -> str | None:
    match = re.search(r"default(?:\s*(?:is|=|:))?\s*([-+]?\d+(?:\.\d+)?)", description, re.I)
    if not match:
        return None
    return match.group(1)


def infer_property_spec(name: str, description: str) -> PropertySpec | None:
    if name.lower() in IGNORED_AUTO_PROPERTIES:
        return None
    if name != name.lower():
        return None

    prop_type = PROPERTY_TYPE_OVERRIDES.get(name)
    if prop_type is None:
        lowered = name.lower()
        if lowered.endswith("target") or lowered == "target":
            prop_type = "target_destination"
        elif lowered == "targetname":
            prop_type = "target_source"
        elif lowered == "rgba":
            prop_type = "color255"
        elif lowered.endswith("color"):
            prop_type = "color1"
        elif lowered in {"count", "frame", "health", "sounds", "style"}:
            prop_type = "integer"
        elif lowered in {"attenuation", "delay", "dmg", "dmg_radius", "gravity", "height", "radius", "speed", "volume", "wait"}:
            prop_type = "float"
        else:
            prop_type = "string"

    return PropertySpec(
        name=name,
        prop_type=prop_type,
        label=PROPERTY_LABEL_OVERRIDES.get(name, humanize_key(name)),
        default=extract_default_value(description),
    )


def extract_documented_properties(body: str) -> tuple[PropertySpec, ...]:
    properties: list[PropertySpec] = []
    seen: set[str] = set()

    for raw_line in body.splitlines():
        line = raw_line.strip()
        if not line:
            continue

        default_match = DEFAULT_PROPERTY_RE.match(line)
        if default_match:
            name = default_match.group(1)
            if name not in seen:
                prop = infer_property_spec(name, f"default {default_match.group(2)}")
                if prop is not None:
                    properties.append(prop)
                    seen.add(name)
            continue

        property_match = (
            QUOTED_PROPERTY_RE.match(line)
            or COLON_PROPERTY_RE.match(line)
            or SPACED_PROPERTY_RE.match(line)
        )
        if not property_match:
            continue

        name = property_match.group(1)
        if name in seen:
            continue

        prop = infer_property_spec(name, property_match.group(2))
        if prop is None:
            continue

        properties.append(prop)
        seen.add(name)

    return tuple(properties)


def entity_properties(classname: str, block: QuakedBlock) -> tuple[PropertySpec, ...]:
    properties = list(ENTITY_PROPERTY_OVERRIDES.get(classname, ()))
    seen = {prop.name for prop in properties}
    excluded = AUTO_PROPERTY_EXCLUDES.get(classname, set())

    for prop in extract_documented_properties(block.body):
        if prop.name in excluded:
            continue
        if prop.name in seen:
            continue
        properties.append(prop)
        seen.add(prop.name)

    return tuple(properties)


def entity_base_classes(classname: str, block: QuakedBlock) -> tuple[str, ...]:
    override = ENTITY_BASE_CLASS_OVERRIDES.get(classname)
    if override is not None:
        return override
    if classname.startswith("ammo_"):
        return ("Ammo",)
    if classname.startswith("weapon_"):
        return ("Weapons",)
    if classname.startswith("item_"):
        return ("Items",)
    if classname.startswith("monster_"):
        return ("REBLIVION_Monsters",)
    if block.is_brush:
        return ("EditorFlags",)
    return ("EditorFlags",)


def should_emit_spawnflags(classname: str) -> bool:
    return classname in SPAWNFLAG_ENTITY_ALLOWLIST


def build_entity_spec(classname: str, block: QuakedBlock, model_hints: dict[str, str]) -> EntitySpec:
    kind = "solid" if block.is_brush else "point"
    title = TITLE_OVERRIDES.get(classname, humanize_classname(classname))
    description = DESCRIPTION_OVERRIDES.get(classname) or first_paragraph(block.body) or title
    return EntitySpec(
        classname=classname,
        kind=kind,
        base_classes=entity_base_classes(classname, block),
        title=title,
        description=description,
        color=block.color,
        mins=block.mins,
        maxs=block.maxs,
        model_path=model_hints.get(classname) or extract_declared_model(block.body),
        emit_spawnflags=should_emit_spawnflags(classname),
        flags=block.flags,
        properties=entity_properties(classname, block),
    )


def emit_entity_spec(spec: EntitySpec, tool: str) -> str:
    emitter = emit_tb_model if tool == "tb" else emit_nrc_model
    class_keyword = "@SolidClass" if spec.kind == "solid" else "@PointClass"
    base_text = f' base({", ".join(spec.base_classes)})' if spec.base_classes else ""
    color_text = f" color({spec.color})"
    size_text = ""
    if spec.kind == "point" and spec.mins is not None and spec.maxs is not None:
        size_text = f" size({spec.mins}, {spec.maxs})"
    header = (
        f'{class_keyword}{base_text}{color_text}{size_text}{emitter(spec.model_path)}'
        f' = {spec.classname} : "{spec.title}"'
    )

    body_lines: list[str] = []
    if spec.emit_spawnflags and spec.flags:
        body_lines.append(build_spawnflags_block(spec.flags, "    "))
    for prop in spec.properties:
        body_lines.append(emit_property(prop, "    "))

    if not body_lines:
        return f"{header} []"

    return header + "\n[\n" + "\n".join(body_lines) + "\n]"


def build_overlay_text(
    tool: str,
    base_text: str,
    base_names: set[str],
    custom_blocks: dict[str, QuakedBlock],
    model_hints: dict[str, str],
) -> tuple[str, set[str]]:
    specs: list[EntitySpec] = []
    overlay_names: set[str] = set()

    for classname in sorted(custom_blocks):
        if classname in base_names:
            continue
        specs.append(build_entity_spec(classname, custom_blocks[classname], model_hints))
        overlay_names.add(classname)

    for alias, canonical in sorted(ALIASES.items()):
        if alias in base_names:
            continue
        block = custom_blocks.get(canonical)
        if block is None:
            raise KeyError(f"Missing canonical class for alias {alias}: {canonical}")
        alias_block = QuakedBlock(
            classname=alias,
            color=block.color,
            mins=block.mins,
            maxs=block.maxs,
            is_brush=block.is_brush,
            flags=block.flags,
            body=DESCRIPTION_OVERRIDES.get(alias, ""),
            raw=block.raw,
        )
        specs.append(build_entity_spec(alias, alias_block, model_hints))
        overlay_names.add(alias)

    overlay_header = [
        "//",
        "// REBLIVION runtime delta",
        "// Generated by tools/generate_reblivion_entity_defs.py.",
        "// Stock Quake II rerelease definitions remain intact; this section appends",
        "// runtime-supported entities missing from the stock editor FGDs, including",
        "// both REBLIVION additions and retail rerelease classes the stock packs omit.",
        "// Runtime source of truth: src/",
        "// Legacy fallback: references/Oblivion-reverse/pack/oblivion.c",
        "//",
        "",
        build_base_class_text(),
        "",
    ]

    overlay_body = "\n\n".join(emit_entity_spec(spec, tool) for spec in specs)
    output_text = base_text.rstrip() + "\n\n" + "\n".join(overlay_header) + overlay_body + "\n"
    return output_text, overlay_names | {"REBLIVION_Monsters"}


def verify_coverage(base_names: set[str], overlay_names: set[str], map_entities: set[str], label: str) -> None:
    covered = base_names | overlay_names
    missing = sorted(map_entities - covered)
    if missing:
        print(f"{label} definitions do not cover the following map classnames:", file=sys.stderr)
        for name in missing:
            print(name, file=sys.stderr)
        raise SystemExit(1)


def collect_custom_blocks(
    legacy_source: Path,
    runtime_root: Path,
    map_entities: set[str],
) -> dict[str, QuakedBlock]:
    legacy_blocks = parse_quaked_blocks(read_text(legacy_source))

    runtime_text_parts: list[str] = []
    runtime_blocks: dict[str, QuakedBlock] = {}
    for path in iter_runtime_sources(runtime_root):
        text = read_text(path)
        runtime_text_parts.append(text)
        runtime_blocks.update(parse_quaked_blocks(text))

    runtime_text = "\n".join(runtime_text_parts)
    custom_blocks: dict[str, QuakedBlock] = {}
    for classname in sorted(set(runtime_blocks) | set(legacy_blocks)):
        runtime_block = runtime_blocks.get(classname)
        legacy_block = legacy_blocks.get(classname)
        if runtime_block is None and legacy_block is not None:
            if classname not in map_entities and not has_runtime_reference(runtime_text, classname):
                continue
        custom_blocks[classname] = merge_blocks(runtime_block, legacy_block)
    return custom_blocks


def main() -> int:
    args = parse_args()

    if not args.legacy_source.exists():
        raise FileNotFoundError(f"Missing legacy QUAKED source: {args.legacy_source}")
    if not args.runtime_root.exists():
        raise FileNotFoundError(f"Missing runtime source tree: {args.runtime_root}")
    if not args.nrc_base_fgd.exists():
        raise FileNotFoundError(f"Missing NRC base FGD: {args.nrc_base_fgd}")
    if not args.tb_base_fgd.exists():
        raise FileNotFoundError(f"Missing TrenchBroom base FGD: {args.tb_base_fgd}")

    map_entities = collect_map_entities(args.maps_root)
    custom_blocks = collect_custom_blocks(args.legacy_source, args.runtime_root, map_entities)

    nrc_base_text = read_text(args.nrc_base_fgd)
    tb_base_text = read_text(args.tb_base_fgd)
    nrc_base_names = parse_fgd_names(nrc_base_text)
    tb_base_names = parse_fgd_names(tb_base_text)

    nrc_output_text, nrc_overlay_names = build_overlay_text(
        "nrc", nrc_base_text, nrc_base_names, custom_blocks, NRC_MODEL_HINTS
    )
    tb_output_text, tb_overlay_names = build_overlay_text(
        "tb", tb_base_text, tb_base_names, custom_blocks, TB_MODEL_HINTS
    )

    verify_coverage(nrc_base_names, nrc_overlay_names, map_entities, "NRC")
    verify_coverage(tb_base_names, tb_overlay_names, map_entities, "TrenchBroom")

    args.nrc_output.parent.mkdir(parents=True, exist_ok=True)
    args.tb_output.parent.mkdir(parents=True, exist_ok=True)
    args.nrc_output.write_text(nrc_output_text, encoding="utf-8")
    args.tb_output.write_text(tb_output_text, encoding="utf-8")

    print(f"Wrote {args.nrc_output}")
    print(f"Wrote {args.tb_output}")
    print(f"Custom entities emitted for NRC: {len(nrc_overlay_names)}")
    print(f"Custom entities emitted for TrenchBroom: {len(tb_overlay_names)}")
    print(f"Verified map classnames: {len(map_entities)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
