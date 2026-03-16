#!/usr/bin/env python3
"""Extract spawn manifest information from Oblivion HLIL listing and compare with repo sources."""

from __future__ import annotations

import argparse
import ast
import bisect
import json
import math
import re
import shutil
import struct
import subprocess
import sys
from collections import deque
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Sequence, Set, Tuple

# ----------------------------- utility helpers -----------------------------

def _parse_hex_bytes(line: str) -> List[int]:
    """Return a list of byte values parsed from a line of hex dump text."""
    hex_bytes = re.findall(r"(?i)\b[0-9a-f]{2}\b", line)
    return [int(h, 16) for h in hex_bytes]


def _bytes_to_int_le(bytes_seq: Sequence[int]) -> int:
    if len(bytes_seq) != 4:
        raise ValueError(f"expected 4 bytes, got {len(bytes_seq)}")
    return int.from_bytes(bytes(bytes_seq), byteorder="little", signed=False)


def _decode_float(value: int) -> float:
    return struct.unpack("<f", struct.pack("<I", value & 0xFFFFFFFF))[0]


def _decode_double(value: int) -> float:
    return struct.unpack("<d", struct.pack("<Q", value & 0xFFFFFFFFFFFFFFFF))[0]


def _encode_float(value: float) -> int:
    return struct.unpack("<I", struct.pack("<f", float(value)))[0]


def _encode_double(value: float) -> int:
    return struct.unpack("<Q", struct.pack("<d", float(value)))[0]


@dataclass
class FieldInfo:
    name: str
    offset: int
    type_id: int
    flags: int


@dataclass
class HLILSpawnInfo:
    classname: str
    function: str
    has_block: bool = False
    block_source: str = "none"
    spawnflags_source: str = "none"
    defaults_source: str = "none"
    defaults: Dict[str, List[Dict[str, object]]] = field(default_factory=dict)
    spawnflags: Dict[str, List[int]] = field(default_factory=lambda: {
        "checks": [],
        "sets": [],
        "clears": [],
        "assignments": [],
    })


@dataclass
class RepoSpawnInfo:
    classname: str
    function: str
    defaults: Dict[str, float] = field(default_factory=dict)
    spawnflags: Dict[str, List[int]] = field(default_factory=lambda: {
        "checks": [],
        "sets": [],
        "clears": [],
        "assignments": [],
    })


@dataclass
class SourceFile:
    path: Path
    lines: List[str]
    is_split: bool


@dataclass
class BinarySection:
    name: str
    virtual_address: int
    virtual_size: int
    raw_address: int
    raw_size: int


@dataclass
class XMMConstant:
    float_value: Optional[float] = None
    raw_bits: Optional[int] = None
    width: int = 32


# ----------------------------- HLIL parsing -----------------------------

class HLILParser:
    def __init__(self, path: Path):
        self.path = path
        self._split_root = self.path.parent / "split"
        self._sources: List[SourceFile] = []
        self.lines: List[str] = []
        for source_path in self._iter_source_paths():
            source_lines = source_path.read_text(encoding="utf-8", errors="replace").splitlines()
            is_split = self._is_split_source(source_path)
            self._sources.append(SourceFile(path=source_path, lines=source_lines, is_split=is_split))
            self.lines.extend(source_lines)

        self._function_blocks: Optional[Dict[str, List[str]]] = None
        self._fields: Optional[Dict[int, FieldInfo]] = None
        self._spawn_map: Optional[Dict[str, str]] = None
        self._string_literals: Optional[Dict[str, str]] = None
        self._interpreted_strings: Optional[List[Dict[str, str]]] = None
        self._binary_path = self._resolve_binary_path()
        self._binary_data: Optional[bytes] = None
        self._binary_sections: Optional[List[BinarySection]] = None
        self._image_base: Optional[int] = None
        self._spawn_table_cache: Dict[Tuple[int, int], Dict[str, str]] = {}
        self._itemlist_cache: Optional[Dict[str, Tuple[int, ...]]] = None
        self._call_graph_entries: Optional[Dict[str, str]] = None
        self._spawn_table_records_cache: Optional[List[Dict[str, object]]] = None
        self._sub_1000b150_literals: Optional[Dict[str, Set[str]]] = None
        self._logged_spawn_entries_cache: Optional[Dict[str, Dict[str, object]]] = None
        self._function_start_cache: Optional[Dict[str, int]] = None
        self._sorted_function_starts: Optional[List[int]] = None

    # -- general helpers --
    def _resolve_binary_path(self) -> Optional[Path]:
        name = self.path.name
        suffix = "_hlil.txt"
        binary_name = name[:-len(suffix)] if name.endswith(suffix) else name
        candidate = self.path.with_name(binary_name)
        if candidate.exists():
            return candidate
        return None

    def _iter_source_paths(self) -> Iterable[Path]:
        yield self.path
        if self._split_root.is_dir():
            for extra_path in sorted(self._split_root.rglob("*.txt")):
                yield extra_path

    def _is_split_source(self, source_path: Path) -> bool:
        try:
            source_path.relative_to(self._split_root)
        except ValueError:
            return False
        return True

    def _parse_sub_address(self, name: str) -> Optional[int]:
        match = re.match(r"sub_([0-9a-f]+)", name, re.IGNORECASE)
        if not match:
            return None
        return int(match.group(1), 16)

    def _function_start_addresses(self) -> Dict[str, int]:
        if self._function_start_cache is None:
            start_map: Dict[str, int] = {}
            addr_pattern = re.compile(r"^(?:\d+:)?\s*(100[0-9a-f]+)\s", re.IGNORECASE)
            for name, block in self.function_blocks.items():
                if not block:
                    continue
                match = addr_pattern.match(block[0])
                if not match:
                    continue
                start_map[name] = int(match.group(1), 16)
            self._function_start_cache = start_map
            self._sorted_function_starts = sorted(start_map.values())
        return self._function_start_cache

    def _next_function_address(self, address: int) -> Optional[int]:
        self._function_start_addresses()
        if not self._sorted_function_starts:
            return None
        idx = bisect.bisect_right(self._sorted_function_starts, address)
        if idx >= len(self._sorted_function_starts):
            return None
        return self._sorted_function_starts[idx]

    def _disassemble_range(self, start: int, stop: int) -> List[str]:
        if not self._binary_path:
            return []
        tool = shutil.which("llvm-objdump")
        if not tool:
            return []
        result = subprocess.run(
            [
                tool,
                "-d",
                f"--start-address=0x{start:x}",
                f"--stop-address=0x{stop:x}",
                str(self._binary_path),
            ],
            capture_output=True,
            text=True,
        )
        if result.returncode != 0:
            return []
        return result.stdout.splitlines()

    def _parse_immediate(self, token: str) -> Optional[int]:
        token = token.strip()
        if not token.startswith("$"):
            return None
        value = token[1:]
        if not value:
            return None
        base = 16 if value.lower().startswith("0x") else 10
        try:
            return int(value, base)
        except ValueError:
            return None

    def _spawnflags_width_mask(self, mnemonic: str) -> int:
        if mnemonic.endswith("b"):
            return 0xFF
        if mnemonic.endswith("w"):
            return 0xFFFF
        return 0xFFFFFFFF

    def _parse_mem_operand_parts(
        self, operand: str
    ) -> Optional[Tuple[Optional[str], Optional[str], int, int]]:
        operand = operand.strip()
        if not operand:
            return None
        if "(" not in operand or ")" not in operand:
            if re.match(r"^[-+]?(?:0x[0-9a-f]+|\d+)$", operand, re.IGNORECASE):
                return None, None, 1, int(operand, 0)
            return None
        match = re.match(
            r"^(?P<disp>[-+]?(?:0x[0-9a-f]+|\d+))?\((?P<base>%[a-z0-9]+)?(?:,(?P<index>%[a-z0-9]+))?(?:,(?P<scale>\d+))?\)$",
            operand,
            re.IGNORECASE,
        )
        if not match:
            return None
        disp_text = match.group("disp")
        disp = int(disp_text, 0) if disp_text else 0
        base_text = match.group("base") or ""
        index_text = match.group("index") or ""
        base_reg = self._register_base(base_text) if base_text else None
        index_reg = self._register_base(index_text) if index_text else None
        scale_text = match.group("scale")
        scale = int(scale_text, 0) if scale_text else 1
        return base_reg, index_reg, scale, disp

    def _parse_mem_operand(self, operand: str) -> Optional[Tuple[str, int]]:
        parts = self._parse_mem_operand_parts(operand)
        if not parts:
            return None
        base_reg, index_reg, scale, disp = parts
        if base_reg is None or index_reg is not None:
            return None
        return base_reg, disp

    def _mem_operand_offset(
        self,
        operand: str,
        self_bases: Dict[str, int],
        reg_constants: Dict[str, int],
    ) -> Optional[int]:
        parts = self._parse_mem_operand_parts(operand)
        if not parts:
            return None
        base_reg, index_reg, scale, disp = parts
        if base_reg is None or base_reg not in self_bases:
            return None
        offset = self_bases[base_reg] + disp
        if index_reg:
            index_value = reg_constants.get(index_reg)
            if index_value is None:
                return None
            offset += index_value * scale
        return offset

    def _mem_operand_address(
        self, operand: str, reg_constants: Dict[str, int]
    ) -> Optional[int]:
        parts = self._parse_mem_operand_parts(operand)
        if not parts:
            return None
        base_reg, index_reg, scale, disp = parts
        address = disp
        if base_reg:
            base_value = reg_constants.get(base_reg)
            if base_value is None:
                return None
            address += base_value
        if index_reg:
            index_value = reg_constants.get(index_reg)
            if index_value is None:
                return None
            address += index_value * scale
        return address

    def _operand_is_spawnflags_mem(self, operand: str) -> bool:
        return "0x11c(" in operand.lower()

    def _register_base(self, operand: str) -> Optional[str]:
        operand = operand.strip()
        if not operand.startswith("%"):
            return None
        reg = operand[1:].lower()
        aliases = {
            "al": "eax",
            "ah": "eax",
            "ax": "eax",
            "eax": "eax",
            "bl": "ebx",
            "bh": "ebx",
            "bx": "ebx",
            "ebx": "ebx",
            "cl": "ecx",
            "ch": "ecx",
            "cx": "ecx",
            "ecx": "ecx",
            "dl": "edx",
            "dh": "edx",
            "dx": "edx",
            "edx": "edx",
            "esi": "esi",
            "edi": "edi",
            "ebp": "ebp",
            "esp": "esp",
        }
        return aliases.get(reg)

    def _xmm_register(self, operand: str) -> Optional[str]:
        operand = operand.strip()
        if not operand.startswith("%"):
            return None
        reg = operand[1:].lower()
        if reg.startswith("xmm") and reg[3:].isdigit():
            return reg
        return None

    def _disassemble_function(self, func_addr: int) -> List[str]:
        if not self._load_binary_image():
            return []
        next_addr = self._next_function_address(func_addr)
        stop_addr = func_addr + 0x400
        if next_addr and next_addr > func_addr:
            if next_addr - func_addr < 0x400:
                stop_addr = next_addr
        return self._disassemble_range(func_addr, stop_addr)

    def _extract_spawnflags_from_disassembly(self, lines: List[str]) -> Dict[str, List[int]]:
        checks: Set[int] = set()
        sets: Set[int] = set()
        clears: Set[int] = set()
        assignments: Set[int] = set()
        reg_spawnflags: Set[str] = set()
        write_prefixes = (
            "add",
            "and",
            "dec",
            "imul",
            "inc",
            "lea",
            "mov",
            "neg",
            "not",
            "or",
            "pop",
            "rol",
            "ror",
            "sal",
            "sar",
            "shl",
            "shr",
            "sub",
            "xchg",
            "xor",
        )
        instr_pattern = re.compile(
            r"^\s*[0-9a-f]+:\s+[0-9a-f ]+\s+(?P<mnemonic>[a-z]+)\s*(?P<ops>.*)$",
            re.IGNORECASE,
        )

        for line in lines:
            match = instr_pattern.match(line)
            if not match:
                continue
            mnemonic = match.group("mnemonic").lower()
            if mnemonic.startswith("ret"):
                reg_spawnflags.clear()
                continue
            if mnemonic.startswith("call"):
                reg_spawnflags.discard("eax")
                reg_spawnflags.discard("ecx")
                reg_spawnflags.discard("edx")
                continue
            ops = match.group("ops").strip()
            operands = [op.strip() for op in ops.split(",") if op.strip()] if ops else []

            if mnemonic.startswith("mov") and len(operands) >= 2:
                src, dst = operands[0], operands[1]
                dst_reg = self._register_base(dst)
                if dst_reg:
                    src_reg = self._register_base(src)
                    if self._operand_is_spawnflags_mem(src):
                        reg_spawnflags.add(dst_reg)
                    elif src_reg and src_reg in reg_spawnflags:
                        reg_spawnflags.add(dst_reg)
                    else:
                        reg_spawnflags.discard(dst_reg)
                if self._operand_is_spawnflags_mem(dst):
                    imm = self._parse_immediate(src)
                    if imm is not None:
                        mask = imm & self._spawnflags_width_mask(mnemonic)
                        if mask:
                            assignments.add(mask)

            if mnemonic.startswith("test") and len(operands) >= 2:
                imm = None
                target = None
                for op in operands:
                    value = self._parse_immediate(op)
                    if value is not None:
                        imm = value
                    else:
                        target = op
                if imm is not None and target is not None:
                    mask = imm & self._spawnflags_width_mask(mnemonic)
                    if mask:
                        target_reg = self._register_base(target)
                        if (target_reg and target_reg in reg_spawnflags) or self._operand_is_spawnflags_mem(target):
                            checks.add(mask)

            if (mnemonic.startswith("and") or mnemonic.startswith("or")) and len(operands) >= 2:
                src, dst = operands[0], operands[1]
                imm = self._parse_immediate(src)
                if imm is None:
                    continue
                mask = imm & self._spawnflags_width_mask(mnemonic)
                if not mask:
                    continue
                if self._operand_is_spawnflags_mem(dst):
                    if mnemonic.startswith("or"):
                        sets.add(mask)
                    else:
                        cleared = (~mask) & self._spawnflags_width_mask(mnemonic)
                        if 0 < cleared < self._spawnflags_width_mask(mnemonic):
                            clears.add(cleared)
                else:
                    dst_reg = self._register_base(dst)
                    if dst_reg and dst_reg in reg_spawnflags and mnemonic.startswith("and"):
                        checks.add(mask)

            if any(mnemonic.startswith(prefix) for prefix in write_prefixes):
                if operands:
                    dst_reg = self._register_base(operands[-1])
                    if dst_reg and not mnemonic.startswith("mov"):
                        reg_spawnflags.discard(dst_reg)

        return {
            "checks": sorted(checks),
            "sets": sorted(sets),
            "clears": sorted(clears),
            "assignments": sorted(assignments),
        }

    def _extract_spawnflags_from_binary(self, func_addr: int) -> Dict[str, List[int]]:
        lines = self._disassemble_function(func_addr)
        if not lines:
            return {"checks": [], "sets": [], "clears": [], "assignments": []}
        return self._extract_spawnflags_from_disassembly(lines)

    def _extract_defaults_from_disassembly(
        self, lines: List[str], fields: Dict[int, FieldInfo]
    ) -> Dict[str, List[Dict[str, object]]]:
        results: Dict[str, List[Dict[str, object]]] = {}
        self_bases: Dict[str, int] = {}
        reg_constants: Dict[str, int] = {}
        fpu_stack: List[Optional[float]] = []
        xmm_constants: Dict[str, XMMConstant] = {}
        write_prefixes = (
            "and",
            "dec",
            "imul",
            "inc",
            "neg",
            "not",
            "or",
            "pop",
            "rol",
            "ror",
            "sal",
            "sar",
            "shl",
            "shr",
            "xchg",
            "xor",
        )
        instr_pattern = re.compile(
            r"^\s*[0-9a-f]+:\s+[0-9a-f ]+\s+(?P<mnemonic>[a-z]+)\s*(?P<ops>.*)$",
            re.IGNORECASE,
        )

        def record_default_value(offset: int, value: object, mask: Optional[int] = None) -> None:
            if offset < 0:
                return
            field_info = fields.get(offset)
            if not field_info or offset < 0x100:
                field_name = f"offset_0x{offset:x}"
            else:
                field_name = field_info.name
            if isinstance(value, float):
                results.setdefault(field_name, []).append({"value": value, "offset": offset})
                return
            if not isinstance(value, int):
                return
            if mask is None:
                mask = 0xFFFFFFFF
            value &= mask
            if field_info and field_info.type_id == 1:
                value = _decode_float(value)
            elif mask == 0xFFFFFFFF and value & 0x80000000:
                value -= 0x100000000
            results.setdefault(field_name, []).append({"value": value, "offset": offset})

        def xmm_float_value(reg: str) -> Optional[float]:
            constant = xmm_constants.get(reg)
            if constant is None:
                return None
            if constant.float_value is not None:
                return constant.float_value
            if constant.raw_bits is None:
                return None
            if constant.width == 64:
                return _decode_double(constant.raw_bits)
            return _decode_float(constant.raw_bits)

        def set_xmm_constant(
            reg: str,
            *,
            float_value: Optional[float],
            raw_bits: Optional[int],
            width: int,
        ) -> None:
            xmm_constants[reg] = XMMConstant(
                float_value=float_value,
                raw_bits=raw_bits,
                width=width,
            )

        def copy_xmm_constant(dst_reg: str, src_reg: str) -> None:
            constant = xmm_constants.get(src_reg)
            if constant is None:
                xmm_constants.pop(dst_reg, None)
                return
            xmm_constants[dst_reg] = XMMConstant(
                float_value=constant.float_value,
                raw_bits=constant.raw_bits,
                width=constant.width,
            )

        for idx, line in enumerate(lines):
            match = instr_pattern.match(line)
            if not match:
                continue
            mnemonic = match.group("mnemonic").lower()
            if mnemonic.startswith("ret"):
                self_bases.clear()
                reg_constants.clear()
                fpu_stack.clear()
                xmm_constants.clear()
                continue
            if mnemonic.startswith("call"):
                for reg in ("eax", "ecx", "edx"):
                    self_bases.pop(reg, None)
                    reg_constants.pop(reg, None)
                fpu_stack.clear()
                xmm_constants.clear()
                continue

            ops = match.group("ops").strip()
            if "#" in ops:
                ops = ops.split("#", 1)[0].strip()
            operands = [op.strip() for op in ops.split(",") if op.strip()] if ops else []

            for operand in operands:
                parts = self._parse_mem_operand_parts(operand)
                if not parts:
                    continue
                base_reg, index_reg, scale, disp = parts
                if base_reg and disp == 0x11C:
                    if index_reg is None or reg_constants.get(index_reg, 0) == 0:
                        self_bases.setdefault(base_reg, 0)

            src = operands[0] if len(operands) >= 1 else ""
            dst = operands[1] if len(operands) >= 2 else ""
            src_xmm = self._xmm_register(src) if src else None
            dst_xmm = self._xmm_register(dst) if dst else None
            if src_xmm or dst_xmm:
                if mnemonic in ("xorps", "xorpd", "pxor"):
                    if dst_xmm and src_xmm == dst_xmm:
                        width = 64 if mnemonic in ("xorpd", "pxor") else 32
                        set_xmm_constant(
                            dst_xmm,
                            float_value=0.0,
                            raw_bits=0,
                            width=width,
                        )
                    elif dst_xmm:
                        xmm_constants.pop(dst_xmm, None)
                    continue
                if mnemonic in ("cvtsi2ss", "cvtsi2sd"):
                    if dst_xmm:
                        value = None
                        src_reg = self._register_base(src)
                        if src_reg and src_reg in reg_constants:
                            value = float(reg_constants[src_reg])
                        if value is not None:
                            width = 64 if mnemonic == "cvtsi2sd" else 32
                            raw_bits = (
                                _encode_double(value)
                                if width == 64
                                else _encode_float(value)
                            )
                            set_xmm_constant(
                                dst_xmm,
                                float_value=value,
                                raw_bits=raw_bits,
                                width=width,
                            )
                        else:
                            xmm_constants.pop(dst_xmm, None)
                    continue
                if mnemonic in ("cvtss2sd", "cvtsd2ss"):
                    if dst_xmm:
                        value = xmm_float_value(src_xmm) if src_xmm else None
                        if value is not None:
                            width = 64 if mnemonic == "cvtss2sd" else 32
                            raw_bits = (
                                _encode_double(value)
                                if width == 64
                                else _encode_float(value)
                            )
                            set_xmm_constant(
                                dst_xmm,
                                float_value=float(value),
                                raw_bits=raw_bits,
                                width=width,
                            )
                        else:
                            xmm_constants.pop(dst_xmm, None)
                    continue
                if mnemonic in ("cvtps2pd", "cvtpd2ps"):
                    if dst_xmm:
                        value = None
                        if src_xmm:
                            value = xmm_float_value(src_xmm)
                        else:
                            address = self._mem_operand_address(src, reg_constants)
                            if address is not None:
                                if mnemonic == "cvtpd2ps":
                                    value = self._read_double(address)
                                else:
                                    value = self._read_float(address)
                        if value is not None:
                            width = 64 if mnemonic == "cvtps2pd" else 32
                            raw_bits = (
                                _encode_double(value)
                                if width == 64
                                else _encode_float(value)
                            )
                            set_xmm_constant(
                                dst_xmm,
                                float_value=float(value),
                                raw_bits=raw_bits,
                                width=width,
                            )
                        else:
                            xmm_constants.pop(dst_xmm, None)
                    continue
                if mnemonic in ("cvttss2si", "cvtss2si", "cvttsd2si", "cvtsd2si"):
                    dst_reg = self._register_base(dst)
                    if dst_reg:
                        value = xmm_float_value(src_xmm) if src_xmm else None
                        if value is not None:
                            reg_constants[dst_reg] = int(value)
                        else:
                            reg_constants.pop(dst_reg, None)
                    continue
                if mnemonic in ("movss", "movsd"):
                    if dst_xmm:
                        value = None
                        raw_bits = None
                        if src_xmm:
                            copy_xmm_constant(dst_xmm, src_xmm)
                            continue
                        else:
                            address = self._mem_operand_address(src, reg_constants)
                            if address is not None:
                                if mnemonic == "movsd":
                                    raw_bits = self._read_u64(address)
                                    value = self._read_double(address)
                                else:
                                    raw_bits = self._read_u32(address)
                                    value = self._read_float(address)
                        if value is not None:
                            width = 64 if mnemonic == "movsd" else 32
                            set_xmm_constant(
                                dst_xmm,
                                float_value=float(value),
                                raw_bits=raw_bits,
                                width=width,
                            )
                        else:
                            xmm_constants.pop(dst_xmm, None)
                    elif src_xmm:
                        offset = self._mem_operand_offset(dst, self_bases, reg_constants)
                        if offset is not None:
                            value = xmm_float_value(src_xmm)
                            if value is not None:
                                record_default_value(offset, float(value))
                    continue
                if mnemonic in ("movd", "movq"):
                    width = 64 if mnemonic == "movq" else 32
                    if dst_xmm:
                        if src_xmm:
                            copy_xmm_constant(dst_xmm, src_xmm)
                        else:
                            src_reg = self._register_base(src)
                            if src_reg and src_reg in reg_constants:
                                mask = 0xFFFFFFFFFFFFFFFF if width == 64 else 0xFFFFFFFF
                                bits = reg_constants[src_reg] & mask
                                value = _decode_double(bits) if width == 64 else _decode_float(bits)
                                set_xmm_constant(
                                    dst_xmm,
                                    float_value=float(value),
                                    raw_bits=bits,
                                    width=width,
                                )
                            else:
                                address = self._mem_operand_address(src, reg_constants)
                                if address is not None:
                                    bits = (
                                        self._read_u64(address)
                                        if width == 64
                                        else self._read_u32(address)
                                    )
                                    if bits is not None:
                                        value = (
                                            _decode_double(bits)
                                            if width == 64
                                            else _decode_float(bits)
                                        )
                                        set_xmm_constant(
                                            dst_xmm,
                                            float_value=float(value),
                                            raw_bits=bits,
                                            width=width,
                                        )
                                    else:
                                        xmm_constants.pop(dst_xmm, None)
                                else:
                                    xmm_constants.pop(dst_xmm, None)
                        continue
                    dst_reg = self._register_base(dst)
                    if dst_reg and src_xmm:
                        constant = xmm_constants.get(src_xmm)
                        if constant:
                            bits = constant.raw_bits
                            if bits is None and constant.float_value is not None:
                                bits = _encode_float(constant.float_value)
                            if bits is not None:
                                reg_constants[dst_reg] = bits & 0xFFFFFFFF
                            else:
                                reg_constants.pop(dst_reg, None)
                        continue
                    if src_xmm:
                        offset = self._mem_operand_offset(dst, self_bases, reg_constants)
                        if offset is not None:
                            constant = xmm_constants.get(src_xmm)
                            if constant:
                                if width == 32:
                                    bits = constant.raw_bits
                                    if bits is None and constant.float_value is not None:
                                        bits = _encode_float(constant.float_value)
                                    if bits is not None:
                                        record_default_value(offset, bits, 0xFFFFFFFF)
                                else:
                                    value = constant.float_value
                                    if value is None and constant.raw_bits is not None:
                                        value = _decode_double(constant.raw_bits)
                                    if value is not None:
                                        record_default_value(offset, float(value))
                        continue
                if mnemonic in ("movdqa", "movdqu"):
                    if dst_xmm:
                        if src_xmm:
                            copy_xmm_constant(dst_xmm, src_xmm)
                        else:
                            address = self._mem_operand_address(src, reg_constants)
                            if address is not None:
                                bits = self._read_u32(address)
                                if bits is not None:
                                    value = _decode_float(bits)
                                    set_xmm_constant(
                                        dst_xmm,
                                        float_value=float(value),
                                        raw_bits=bits,
                                        width=32,
                                    )
                                else:
                                    xmm_constants.pop(dst_xmm, None)
                            else:
                                xmm_constants.pop(dst_xmm, None)
                        continue
                    if src_xmm:
                        offset = self._mem_operand_offset(dst, self_bases, reg_constants)
                        if offset is not None:
                            value = xmm_float_value(src_xmm)
                            if value is not None:
                                record_default_value(offset, float(value))
                        continue
                if mnemonic.startswith("mov") and dst_xmm:
                    if src_xmm:
                        copy_xmm_constant(dst_xmm, src_xmm)
                    else:
                        xmm_constants.pop(dst_xmm, None)
                    continue
                if dst_xmm:
                    xmm_constants.pop(dst_xmm, None)
                continue

            if mnemonic in ("fld1", "fldz"):
                fpu_stack.append(1.0 if mnemonic == "fld1" else 0.0)
                continue
            if mnemonic.startswith("fld") and operands:
                value: Optional[float] = None
                address = self._mem_operand_address(operands[0], reg_constants)
                if address is not None:
                    if mnemonic == "fldl":
                        value = self._read_double(address)
                    else:
                        value = self._read_float(address)
                fpu_stack.append(value)
                continue
            if mnemonic.startswith("fst") and operands and not mnemonic.startswith("fstsw"):
                value = fpu_stack[-1] if fpu_stack else None
                if mnemonic.endswith("p"):
                    value = fpu_stack.pop() if fpu_stack else None
                offset = self._mem_operand_offset(operands[0], self_bases, reg_constants)
                if offset is not None and value is not None:
                    record_default_value(offset, float(value))
                continue

            if mnemonic.startswith("xor") and len(operands) >= 2:
                src_reg = self._register_base(operands[0])
                dst_reg = self._register_base(operands[1])
                if src_reg and dst_reg and src_reg == dst_reg:
                    self_bases.pop(dst_reg, None)
                    reg_constants[dst_reg] = 0
                    continue

            if mnemonic.startswith("sub") and len(operands) >= 2:
                src_reg = self._register_base(operands[0])
                dst_reg = self._register_base(operands[1])
                if src_reg and dst_reg and src_reg == dst_reg:
                    self_bases.pop(dst_reg, None)
                    reg_constants[dst_reg] = 0
                    continue

            if mnemonic.startswith("add") and len(operands) >= 2:
                src, dst = operands[0], operands[1]
                dst_reg = self._register_base(dst)
                if dst_reg:
                    delta: Optional[int] = None
                    src_imm = self._parse_immediate(src)
                    if src_imm is not None:
                        delta = src_imm
                    else:
                        src_reg = self._register_base(src)
                        if src_reg and src_reg in reg_constants:
                            delta = reg_constants[src_reg]
                    if delta is not None:
                        if dst_reg in self_bases:
                            self_bases[dst_reg] += delta
                        if dst_reg in reg_constants:
                            reg_constants[dst_reg] = (
                                reg_constants[dst_reg] + delta
                            ) & self._spawnflags_width_mask(mnemonic)
                        continue
                    if dst_reg in self_bases or dst_reg in reg_constants:
                        self_bases.pop(dst_reg, None)
                        reg_constants.pop(dst_reg, None)
                        continue

            if mnemonic.startswith("sub") and len(operands) >= 2:
                src, dst = operands[0], operands[1]
                dst_reg = self._register_base(dst)
                if dst_reg:
                    delta = None
                    src_imm = self._parse_immediate(src)
                    if src_imm is not None:
                        delta = -src_imm
                    else:
                        src_reg = self._register_base(src)
                        if src_reg and src_reg in reg_constants:
                            delta = -reg_constants[src_reg]
                    if delta is not None:
                        if dst_reg in self_bases:
                            self_bases[dst_reg] += delta
                        if dst_reg in reg_constants:
                            reg_constants[dst_reg] = (
                                reg_constants[dst_reg] + delta
                            ) & self._spawnflags_width_mask(mnemonic)
                        continue
                    if dst_reg in self_bases or dst_reg in reg_constants:
                        self_bases.pop(dst_reg, None)
                        reg_constants.pop(dst_reg, None)
                        continue

            if mnemonic.startswith("mov") and len(operands) >= 2:
                src, dst = operands[0], operands[1]
                offset = self._mem_operand_offset(dst, self_bases, reg_constants)
                if offset is not None:
                    value: Optional[int] = None
                    imm = self._parse_immediate(src)
                    if imm is not None:
                        value = imm
                    else:
                        src_reg = self._register_base(src)
                        if src_reg and src_reg in reg_constants:
                            value = reg_constants[src_reg]
                    if value is not None:
                        record_default_value(
                            offset, value, self._spawnflags_width_mask(mnemonic)
                        )

                dst_reg = self._register_base(dst)
                if dst_reg:
                    src_reg = self._register_base(src)
                    src_mem = self._parse_mem_operand_parts(src)
                    if src_reg and src_reg in self_bases:
                        self_bases[dst_reg] = self_bases[src_reg]
                    elif src_mem and src_mem[0] in ("ebp", "esp") and src_mem[1] is None:
                        base_reg, _, _, disp = src_mem
                        if base_reg == "ebp" and disp >= 8:
                            self_bases[dst_reg] = 0
                        elif base_reg == "esp" and idx <= 80 and 4 <= disp <= 0x80:
                            self_bases[dst_reg] = 0
                        else:
                            self_bases.pop(dst_reg, None)
                    else:
                        self_bases.pop(dst_reg, None)

                    imm = self._parse_immediate(src)
                    if imm is not None:
                        reg_constants[dst_reg] = imm & self._spawnflags_width_mask(mnemonic)
                    elif src_reg and src_reg in reg_constants:
                        reg_constants[dst_reg] = reg_constants[src_reg]
                    else:
                        reg_constants.pop(dst_reg, None)

            if mnemonic.startswith("lea") and len(operands) >= 2:
                src, dst = operands[0], operands[1]
                dst_reg = self._register_base(dst)
                src_mem = self._parse_mem_operand_parts(src)
                if dst_reg:
                    if src_mem and src_mem[0] in self_bases:
                        base_reg, index_reg, scale, disp = src_mem
                        offset = self_bases[base_reg] + disp
                        if index_reg:
                            index_value = reg_constants.get(index_reg)
                            if index_value is None:
                                self_bases.pop(dst_reg, None)
                            else:
                                self_bases[dst_reg] = offset + index_value * scale
                        else:
                            self_bases[dst_reg] = offset
                    else:
                        self_bases.pop(dst_reg, None)
                    reg_constants.pop(dst_reg, None)

            if any(mnemonic.startswith(prefix) for prefix in write_prefixes):
                if operands:
                    dst_reg = self._register_base(operands[-1])
                    if dst_reg and not mnemonic.startswith(("mov", "lea", "add", "sub")):
                        self_bases.pop(dst_reg, None)
                        reg_constants.pop(dst_reg, None)

        return results

    def _extract_defaults_from_binary(
        self, func_addr: int, fields: Dict[int, FieldInfo]
    ) -> Dict[str, List[Dict[str, object]]]:
        lines = self._disassemble_function(func_addr)
        if not lines:
            return {}
        return self._extract_defaults_from_disassembly(lines, fields)

    def _match_function_decl(self, raw_line: str) -> Optional[str]:
        decl_pattern = re.compile(
            r"^(?:\d+:)?\s*100[0-9a-f]+\s+(?P<rest>.+)$", re.IGNORECASE
        )
        sub_pattern = re.compile(r"\b(sub_[0-9a-f]+)\s*\(", re.IGNORECASE)
        type_pattern = re.compile(
            r"\b(?:void|char|short|int|long|float|double|qboolean|size_t|uint\d+_t|int\d+_t)\b",
            re.IGNORECASE,
        )
        match = decl_pattern.match(raw_line)
        if not match:
            return None
        rest = match.group("rest").strip()
        sub_match = sub_pattern.search(rest)
        if not sub_match:
            return None
        prefix = rest[: sub_match.start()]
        if not prefix.strip():
            return None
        if "=" in prefix or "return" in prefix:
            return None
        if "(" in prefix:
            return None
        if not type_pattern.search(prefix):
            return None
        return sub_match.group(1)

    @property
    def function_blocks(self) -> Dict[str, List[str]]:
        if self._function_blocks is None:
            blocks: Dict[str, List[str]] = {}

            def append_block(name: str, new_lines: List[str]) -> None:
                existing = blocks.setdefault(name, [])
                for entry in new_lines:
                    if entry not in existing:
                        existing.append(entry)

            for source in self._sources:
                current_name: Optional[str] = None
                current_lines: List[str] = []
                for raw_line in source.lines:
                    line = raw_line.strip()
                    decl = self._match_function_decl(raw_line)
                    if decl:
                        if current_name is not None:
                            append_block(current_name, current_lines)
                        current_name = decl
                        current_lines = [line]
                    elif current_name is not None:
                        current_lines.append(line)
                if current_name is not None:
                    append_block(current_name, current_lines)
            self._function_blocks = blocks
        return self._function_blocks

    @property
    def fields(self) -> Dict[int, FieldInfo]:
        if self._fields is None:
            entries: Dict[int, FieldInfo] = {}
            ptr_pattern = re.compile(
                r"^(?:\d+:)?\s*100[0-9a-f]+\s+char \(\* (?P<label>data_[0-9a-f]+)\)\[[^]]+\] = (?P<target>data_[0-9a-f]+) {\"(?P<name>[^\"]+)\"}"
            )
            for source in self._sources:
                for idx, raw_line in enumerate(source.lines):
                    m = ptr_pattern.match(raw_line)
                    if not m:
                        continue
                    next_line = ""
                    for j in range(idx + 1, len(source.lines)):
                        candidate = source.lines[j]
                        if candidate.strip():
                            next_line = candidate
                            break
                    if not next_line:
                        continue
                    if not re.search(r"[0-9a-f]{2}\s+[0-9a-f]{2}\s+[0-9a-f]{2}", next_line, re.IGNORECASE):
                        continue
                    byte_values = _parse_hex_bytes(next_line)[:12]
                    if len(byte_values) < 12:
                        continue
                    offset = _bytes_to_int_le(byte_values[0:4])
                    if offset in entries:
                        continue
                    type_id = _bytes_to_int_le(byte_values[4:8])
                    flags = _bytes_to_int_le(byte_values[8:12])
                    entries[offset] = FieldInfo(name=m.group("name"), offset=offset, type_id=type_id, flags=flags)
            self._fields = entries
        return self._fields

    @property
    def spawn_map(self) -> Dict[str, str]:
        if self._spawn_map is None:
            spawn_entries: Dict[str, str] = {}
            literal_map = self._string_literal_map()
            ptr_pattern = re.compile(
                r"^(?:\d+:)?\s*100[0-9a-f]+\s+char \(\* (?P<label>data_[0-9a-f]+)\)\[[^]]+\] = (?P<target>data_[0-9a-f]+) {\"(?P<name>[^\"]+)\"}"
            )
            func_pattern = re.compile(
                r"^(?:\d+:)?\s*100[0-9a-f]+\s+void\* (?P<label>data_[0-9a-f]+) = (?P<func>sub_[0-9a-f]+)"
            )
            sub_decl_pattern = re.compile(r"\b(sub_[0-9a-f]+)\s*\(", re.IGNORECASE)
            for source in self._sources:
                for idx, raw_line in enumerate(source.lines):
                    m = ptr_pattern.match(raw_line)
                    if not m:
                        continue
                    next_line = ""
                    for j in range(idx + 1, len(source.lines)):
                        candidate = source.lines[j]
                        if candidate.strip():
                            next_line = candidate
                            break
                    if not next_line:
                        continue
                    classname = m.group("name")
                    if classname in spawn_entries:
                        continue
                    m_func = func_pattern.match(next_line)
                    if m_func:
                        spawn_entries[classname] = m_func.group("func")
                        continue
                    if source.is_split:
                        follow_func = self._find_next_function_decl(
                            source.lines, idx + 1, sub_decl_pattern
                        )
                        if follow_func:
                            spawn_entries[classname] = follow_func
            for block in self.function_blocks.values():
                table_entries = self._extract_spawn_map_from_spawn_tables(block, literal_map)
                for classname, func in table_entries.items():
                    if classname not in spawn_entries:
                        spawn_entries[classname] = func
                for classname, func in self._extract_spawn_map_from_strcmp(block).items():
                    if classname not in spawn_entries:
                        spawn_entries[classname] = func

            binary_entries = self._spawn_entries_from_binary_tables()
            if binary_entries:
                spawn_entries.update(binary_entries)
            item_entries = self._itemlist_entries()
            for classname in ("ammo_mines",):
                if classname in item_entries and classname not in spawn_entries:
                    spawn_entries[classname] = "SpawnItemFromItemlist"

            interpreted_weapons = self._interpreted_classnames(
                category="weapon_descriptor", prefix="weapon_"
            )
            for classname in sorted(interpreted_weapons):
                if classname in item_entries and classname not in spawn_entries:
                    spawn_entries[classname] = "SpawnItemFromItemlist"

            for classname, func in self._call_graph_spawn_entries().items():
                if classname not in spawn_entries:
                    spawn_entries[classname] = func

            for classname, entry in self._logged_spawn_entries().items():
                if classname not in spawn_entries or spawn_entries[classname] == "SpawnItemFromItemlist":
                    spawn_entries[classname] = entry["function"]

            # Remove known non-spawn literals picked up by string/table scans.
            for ignored in ("%s/listip.cfg", "j", "player_noise"):
                spawn_entries.pop(ignored, None)

            self._spawn_map = spawn_entries
        return self._spawn_map

    def _string_literal_map(self) -> Dict[str, str]:
        if self._string_literals is None:
            literal_map: Dict[str, str] = {}
            ptr_pattern = re.compile(
                r"^(?:\d+:)?\s*100[0-9a-f]+\s+char \(\* (?P<label>data_[0-9a-f]+)\)\[[^]]+\] = (?P<target>data_[0-9a-f]+) {\"(?P<name>[^\"]+)\"}"
            )
            for source in self._sources:
                for raw_line in source.lines:
                    match = ptr_pattern.match(raw_line)
                    if not match:
                        continue
                    name = match.group("name")
                    for key in (match.group("label"), match.group("target")):
                        normalized = key.lower()
                        literal_map[normalized] = name
                        if key.startswith("data_"):
                            literal_map[f"0x{key.split('_', 1)[1].lower()}"] = name

            for entry in self._load_interpreted_strings():
                value = entry.get("value")
                if not value:
                    continue
                for key in (entry.get("symbol"), entry.get("address")):
                    if not key:
                        continue
                    normalized = key.lower()
                    literal_map[normalized] = value

            self._string_literals = literal_map
        return self._string_literals

    def _load_interpreted_strings(self) -> List[Dict[str, str]]:
        if self._interpreted_strings is not None:
            return self._interpreted_strings
        interpreted_path = self.path.parent / "interpreted" / "strings.json"
        if interpreted_path.is_file():
            try:
                self._interpreted_strings = json.loads(
                    interpreted_path.read_text(encoding="utf-8")
                )
            except json.JSONDecodeError:
                self._interpreted_strings = []
        else:
            self._interpreted_strings = []
        return self._interpreted_strings

    def _interpreted_classnames(
        self, category: Optional[str] = None, prefix: Optional[str] = None
    ) -> Set[str]:
        classnames: Set[str] = set()
        for entry in self._load_interpreted_strings():
            if category and entry.get("category") != category:
                continue
            value = entry.get("value")
            if not value:
                continue
            normalized = self._normalize_classname(value)
            if prefix and not normalized.startswith(prefix):
                continue
            classnames.add(normalized)
        return classnames

    def _normalize_classname(self, classname: str) -> str:
        return classname.strip().strip("\0")

    def _call_graph_spawn_entries(self) -> Dict[str, str]:
        if self._call_graph_entries is not None:
            return self._call_graph_entries

        interpreted_path = self.path.parent / "interpreted" / "controller_classnames.json"
        entries: Dict[str, str] = {}
        if interpreted_path.is_file():
            try:
                data = json.loads(interpreted_path.read_text(encoding="utf-8"))
            except json.JSONDecodeError:
                data = []
            if isinstance(data, list):
                for item in data:
                    if not isinstance(item, dict):
                        continue
                    classname = item.get("classname")
                    function = item.get("function")
                    if not classname or not function:
                        continue
                    normalized = self._normalize_classname(str(classname))
                    entries.setdefault(normalized, str(function))
        if entries:
            self._call_graph_entries = entries
            return entries

        targets = ("sub_1001ad80", "sub_100166e7")
        literal_pattern = re.compile(r'"([a-z0-9_]+)"')
        for func_name, block in self.function_blocks.items():
            call_index = self._locate_call_graph_start(block, targets)
            if call_index is None:
                continue
            for line in block[call_index:]:
                for literal in literal_pattern.findall(line):
                    normalized = self._normalize_classname(literal)
                    if not self._looks_like_classname(normalized):
                        continue
                    entries.setdefault(normalized, func_name)

        self._call_graph_entries = entries
        return entries

    def _locate_call_graph_start(
        self, block: List[str], targets: Sequence[str]
    ) -> Optional[int]:
        if not block:
            return None
        for idx, line in enumerate(block):
            for target in targets:
                if target in line:
                    return idx
        return None

    def _looks_like_classname(self, literal: str) -> bool:
        if not literal or "_" not in literal:
            return False
        prefixes = (
            "target_",
            "trigger_",
            "func_",
            "misc_",
            "monster_",
            "path_",
            "info_",
            "weapon_",
            "item_",
            "ammo_",
            "key_",
            "turret_",
            "point_",
            "bodyque_",
            "light_",
            "script_",
            "model_",
        )
        literal_lower = literal.lower()
        return any(literal_lower.startswith(prefix) for prefix in prefixes)

    def _load_binary_image(self) -> bool:
        if self._binary_path is None:
            return False
        if self._binary_data is not None and self._binary_sections is not None:
            return True
        data = self._binary_path.read_bytes()
        if len(data) < 0x100 or data[:2] != b"MZ":
            return False
        e_lfanew = struct.unpack_from("<I", data, 0x3C)[0]
        if e_lfanew + 6 >= len(data) or data[e_lfanew : e_lfanew + 4] != b"PE\0\0":
            return False
        number_of_sections = struct.unpack_from("<H", data, e_lfanew + 6)[0]
        optional_header_size = struct.unpack_from("<H", data, e_lfanew + 20)[0]
        optional_header_offset = e_lfanew + 24
        if optional_header_offset + optional_header_size > len(data):
            return False
        image_base = struct.unpack_from("<I", data, optional_header_offset + 28)[0]
        section_offset = optional_header_offset + optional_header_size
        sections: List[BinarySection] = []
        for idx in range(number_of_sections):
            entry_offset = section_offset + idx * 40
            if entry_offset + 40 > len(data):
                break
            name_bytes = data[entry_offset : entry_offset + 8]
            name = name_bytes.split(b"\0", 1)[0].decode("ascii", errors="ignore")
            virtual_size = struct.unpack_from("<I", data, entry_offset + 8)[0]
            virtual_address = struct.unpack_from("<I", data, entry_offset + 12)[0]
            raw_size = struct.unpack_from("<I", data, entry_offset + 16)[0]
            raw_address = struct.unpack_from("<I", data, entry_offset + 20)[0]
            sections.append(
                BinarySection(
                    name=name,
                    virtual_address=virtual_address,
                    virtual_size=virtual_size,
                    raw_address=raw_address,
                    raw_size=raw_size,
                )
            )
        if not sections:
            return False
        self._binary_data = data
        self._binary_sections = sections
        self._image_base = image_base
        return True

    def _va_to_file_offset(self, address: int) -> Optional[int]:
        if not self._load_binary_image() or self._binary_data is None:
            return None
        assert self._binary_sections is not None
        assert self._image_base is not None
        rva = address - self._image_base
        for section in self._binary_sections:
            max_size = section.virtual_size or section.raw_size
            if max_size == 0:
                continue
            start = section.virtual_address
            end = start + max_size
            if start <= rva < end:
                delta = rva - start
                if delta >= section.raw_size:
                    return None
                return section.raw_address + delta
        return None

    def _read_c_string(self, address: int) -> Optional[str]:
        if not self._load_binary_image() or self._binary_data is None:
            return None
        offset = self._va_to_file_offset(address)
        if offset is None or offset >= len(self._binary_data):
            return None
        data = self._binary_data
        end = data.find(b"\0", offset)
        if end == -1:
            return None
        try:
            return data[offset:end].decode("ascii")
        except UnicodeDecodeError:
            return None

    def _read_u32(self, address: int) -> Optional[int]:
        if not self._load_binary_image() or self._binary_data is None:
            return None
        offset = self._va_to_file_offset(address)
        if offset is None or offset + 4 > len(self._binary_data):
            return None
        return struct.unpack_from("<I", self._binary_data, offset)[0]

    def _read_u64(self, address: int) -> Optional[int]:
        if not self._load_binary_image() or self._binary_data is None:
            return None
        offset = self._va_to_file_offset(address)
        if offset is None or offset + 8 > len(self._binary_data):
            return None
        return struct.unpack_from("<Q", self._binary_data, offset)[0]

    def _read_float(self, address: int) -> Optional[float]:
        value = self._read_u32(address)
        if value is None:
            return None
        return _decode_float(value)

    def _read_double(self, address: int) -> Optional[float]:
        if not self._load_binary_image() or self._binary_data is None:
            return None
        offset = self._va_to_file_offset(address)
        if offset is None or offset + 8 > len(self._binary_data):
            return None
        return struct.unpack_from("<d", self._binary_data, offset)[0]

    def _is_valid_function_address(self, address: int) -> bool:
        if not self._load_binary_image() or self._binary_sections is None:
            return False
        assert self._image_base is not None
        for section in self._binary_sections:
            if section.name.strip().lower() != ".text":
                continue
            start = self._image_base + section.virtual_address
            end = start + (section.virtual_size or section.raw_size)
            if start <= address < end:
                return True
        return False

    def _parse_spawn_table_from_address(
        self,
        address: int,
        *,
        entry_size: Optional[int] = None,
        literal_map: Optional[Dict[str, str]] = None,
    ) -> Dict[str, str]:
        if entry_size is None:
            if address in (0x10046928, 0x1004A5C0):
                entry_size = 0x48
            else:
                entry_size = 8
        cache_key = (address, entry_size)
        if cache_key in self._spawn_table_cache:
            return self._spawn_table_cache[cache_key]
        entries: Dict[str, str] = {}
        if not self._load_binary_image() or self._binary_data is None:
            return entries
        offset = self._va_to_file_offset(address)
        if offset is None:
            return entries
        data = self._binary_data
        literal_map = literal_map or self._string_literal_map()
        seen_valid = 0
        invalid_streak = 0
        while offset + entry_size <= len(data):
            name_ptr, func_ptr = struct.unpack_from("<II", data, offset)
            classname = self._resolve_classname_from_pointer(name_ptr, literal_map)
            if not classname:
                classname = self._read_c_string(name_ptr)
            if not classname or not self._is_valid_function_address(func_ptr):
                if seen_valid:
                    invalid_streak += 1
                    if invalid_streak >= 64:
                        break
                offset += entry_size
                continue
            invalid_streak = 0
            seen_valid += 1
            normalized = self._normalize_classname(classname)
            if normalized not in entries:
                entries[normalized] = f"sub_{func_ptr:08x}"
            offset += entry_size
        self._spawn_table_cache[cache_key] = entries
        return entries

    def _resolve_classname_from_pointer(
        self, pointer: int, literal_map: Dict[str, str]
    ) -> Optional[str]:
        for key in (
            f"data_{pointer:08x}",
            f"0x{pointer:08x}",
        ):
            value = literal_map.get(key)
            if value:
                return value
        return None

    def _spawn_entries_from_binary_tables(self) -> Dict[str, str]:
        combined: Dict[str, str] = {}
        for record in self._spawn_table_records():
            classname = record.get("classname")
            function = record.get("function")
            if not classname or not function:
                continue
            if classname not in combined:
                combined[classname] = function
        return combined

    def _spawn_table_records(self) -> List[Dict[str, object]]:
        if self._spawn_table_records_cache is not None:
            return self._spawn_table_records_cache
        records: List[Dict[str, object]] = []
        if not self._load_binary_image() or self._binary_data is None:
            self._spawn_table_records_cache = records
            return records
        base_address = 0x10046928
        entry_size = 0x48
        offset = self._va_to_file_offset(base_address)
        if offset is None:
            self._spawn_table_records_cache = records
            return records
        literal_map = self._string_literal_map()
        data = self._binary_data
        idx = 0
        invalid_streak = 0
        while offset + (idx + 1) * entry_size <= len(data):
            start = offset + idx * entry_size
            chunk = data[start : start + entry_size]
            if len(chunk) < entry_size:
                break
            values = struct.unpack("<" + "I" * (entry_size // 4), chunk)
            if not any(values):
                invalid_streak += 1
                if invalid_streak >= 64 and records:
                    break
                idx += 1
                continue

            text_ptr = values[0x28 // 4]
            text_label = self._read_c_string(text_ptr) if text_ptr else None

            for pair_offset in range(0, entry_size, 8):
                name_ptr, func_ptr = values[pair_offset // 4 : pair_offset // 4 + 2]
                if not name_ptr or not func_ptr:
                    continue
                if not self._is_valid_function_address(func_ptr):
                    continue
                classname = self._resolve_classname_from_pointer(name_ptr, literal_map)
                if not classname:
                    classname = self._read_c_string(name_ptr)
                if not classname:
                    continue

                normalized = self._normalize_classname(classname)
                if not re.match(r"^[A-Za-z][A-Za-z0-9_]*$", normalized):
                    continue

                record = {
                    "index": idx,
                    "address": base_address + idx * entry_size + pair_offset,
                    "pair_offset": pair_offset,
                    "classname": normalized,
                    "function": f"sub_{func_ptr:08x}",
                    "text_label": text_label,
                    "name_pointer": name_ptr,
                    "text_pointer": text_ptr,
                    "function_pointer": func_ptr,
                }
                records.append(record)

            invalid_streak = 0 if any(r.get("index") == idx for r in records) else invalid_streak + 1
            idx += 1
        self._spawn_table_records_cache = records
        return records

    def _extract_spawn_map_from_spawn_tables(
        self,
        block: List[str],
        literal_map: Optional[Dict[str, str]] = None,
    ) -> Dict[str, str]:
        if not block:
            return {}
        if literal_map is None:
            literal_map = self._string_literal_map()

        results: Dict[str, str] = {}
        block_text = "\n".join(block)
        entry_pattern = re.compile(
            r"\{\s*(?P<raw>(?:\&\s*)?data_[0-9a-f]+|0x[0-9a-f]+|\"[^\"]+\")\s*,\s*(?P<func>sub_[0-9a-f]+)\s*\}",
            re.IGNORECASE,
        )
        for match in entry_pattern.finditer(block_text):
            raw = match.group("raw").strip()
            func = match.group("func")
            classname = self._resolve_classname_from_literal(raw, literal_map)
            if not classname:
                continue
            normalized = self._normalize_classname(classname)
            if normalized not in results:
                results[normalized] = func

        if "spawn function" in block_text.lower() and "data_1004a5c0" in block_text.lower():
            table_entries = self._parse_spawn_table_from_address(0x1004A5C0)
            for classname, func in table_entries.items():
                if classname not in results:
                    results[classname] = func

        if not any("switch (" in line for line in block):
            return results

        goto_pattern = re.compile(r"goto\s+(label_[0-9a-f]+)", re.IGNORECASE)
        return_pattern = re.compile(
            r"return\s+(sub_[0-9a-f]+)(?:\b|(?=\())", re.IGNORECASE
        )
        label_pattern = re.compile(r"(label_[0-9a-f]+):", re.IGNORECASE)
        label_indices: Dict[str, int] = {}
        for idx, line in enumerate(block):
            m_label = label_pattern.search(line)
            if m_label:
                label_indices[m_label.group(1)] = idx

        case_indices: List[int] = []
        case_pattern = re.compile(r"\b(case|default)\b", re.IGNORECASE)
        for idx, line in enumerate(block):
            if case_pattern.search(line):
                case_indices.append(idx)
        if not case_indices:
            return results
        case_indices.append(len(block))

        strcmp_call_pattern = re.compile(
            r"sub_10038b20\([^,]+,\s*\"([^\"]+)\"\)", re.IGNORECASE
        )
        for pos, start in enumerate(case_indices[:-1]):
            end = case_indices[pos + 1]
            for idx in range(start, end):
                line = block[idx]
                for literal_match in strcmp_call_pattern.finditer(line):
                    classname = self._normalize_classname(literal_match.group(1))
                    if classname in results:
                        continue
                    target = self._resolve_strcmp_chain(
                        block,
                        idx + 1,
                        end,
                        goto_pattern,
                        return_pattern,
                        label_indices,
                    )
                    if target:
                        results[classname] = target
        return results

    def _resolve_classname_from_literal(
        self, raw: str, literal_map: Dict[str, str]
    ) -> Optional[str]:
        token = raw.strip()
        if token.startswith("\"") and token.endswith("\""):
            return token.strip("\"")
        if token.startswith("&"):
            token = token[1:].strip()
        lookup = literal_map.get(token.lower())
        if lookup:
            return lookup
        if token.lower().startswith("0x"):
            try:
                as_int = int(token, 16)
            except ValueError:
                return None
            lookup = literal_map.get(f"data_{as_int:08x}")
            if lookup:
                return lookup
        return None

    def _find_next_function_decl(
        self,
        lines: Sequence[str],
        start_index: int,
        sub_decl_pattern: re.Pattern[str],
    ) -> Optional[str]:
        for idx in range(start_index, len(lines)):
            candidate = lines[idx]
            stripped = candidate.strip()
            if not stripped:
                continue
            if stripped.startswith(("#", "//", "/*", "*", "*/")):
                continue
            decl = self._match_function_decl(candidate)
            if decl:
                return decl
        return None

    def _extract_spawn_map_from_strcmp(self, block: List[str]) -> Dict[str, str]:
        literal_pattern = re.compile(
            r'(?:const\s+)?char(?:\s+const)?\s*\*\s+[^=]+\s*=\s*"([^"]+)"'
        )
        goto_pattern = re.compile(r'goto\s+(label_[0-9a-f]+)')
        return_pattern = re.compile(r'return\s+(sub_[0-9a-f]+)(?:\b|(?=\())')
        label_pattern = re.compile(r'(label_[0-9a-f]+):')

        label_indices: Dict[str, int] = {}
        for idx, line in enumerate(block):
            m_label = label_pattern.search(line)
            if m_label:
                label_indices[m_label.group(1)] = idx

        literal_positions: List[Tuple[int, str]] = []
        for idx, line in enumerate(block):
            m_literal = literal_pattern.search(line)
            if m_literal:
                literal_positions.append((idx, m_literal.group(1)))

        results: Dict[str, str] = {}
        for pos, (line_idx, classname) in enumerate(literal_positions):
            search_limit = (
                literal_positions[pos + 1][0]
                if pos + 1 < len(literal_positions)
                else len(block)
            )
            classname = self._normalize_classname(classname)
            target = self._resolve_strcmp_chain(
                block,
                line_idx + 1,
                search_limit,
                goto_pattern,
                return_pattern,
                label_indices,
            )
            if target:
                results[classname] = target
        return results

    def _resolve_strcmp_chain(
        self,
        block: List[str],
        start_index: int,
        search_limit: int,
        goto_pattern: re.Pattern[str],
        return_pattern: re.Pattern[str],
        label_indices: Dict[str, int],
    ) -> Optional[str]:
        if not block:
            return None

        queue: deque[int] = deque()
        queue.append(max(0, start_index))
        visited_starts: Set[int] = set()

        while queue:
            current = queue.popleft()
            if current in visited_starts or current >= len(block):
                continue
            visited_starts.add(current)

            end = search_limit if current == start_index else len(block)
            idx = current
            while idx < end and idx < len(block):
                line = block[idx].strip()
                if line:
                    m_return = return_pattern.search(line)
                    if m_return:
                        return m_return.group(1)

                    for m_goto in goto_pattern.finditer(line):
                        label_name = m_goto.group(1)
                        target_idx = label_indices.get(label_name)
                        if target_idx is not None and target_idx not in visited_starts:
                            queue.append(target_idx)
                idx += 1

        return None

    # -- extraction --
    def build_manifest(self) -> Dict[str, HLILSpawnInfo]:
        manifest: Dict[str, HLILSpawnInfo] = {}
        fields = self.fields
        func_blocks = self.function_blocks
        for classname, func in sorted(self.spawn_map.items()):
            info = HLILSpawnInfo(classname=classname, function=func)
            block = func_blocks.get(func)
            if block:
                info.has_block = True
                info.block_source = "hlil"
                info.defaults = self._extract_defaults(block, fields)
                if info.defaults:
                    info.defaults_source = "hlil"
                if self._should_follow_helper_calls(classname):
                    info.spawnflags = self._extract_spawnflags_with_helpers(func)
                else:
                    info.spawnflags = self._extract_spawnflags(block)
                if any(info.spawnflags.values()):
                    info.spawnflags_source = "hlil"
            else:
                addr = self._parse_sub_address(func)
                if addr is not None:
                    lines = self._disassemble_function(addr)
                    if lines:
                        info.has_block = True
                        info.block_source = "binary"
                        info.spawnflags = self._extract_spawnflags_from_disassembly(lines)
                        if any(info.spawnflags.values()):
                            info.spawnflags_source = "binary"
                        info.defaults = self._extract_defaults_from_disassembly(lines, fields)
                        if info.defaults:
                            info.defaults_source = "binary"
            if not info.defaults and classname in self._itemlist_entries():
                item_defaults = self._itemlist_defaults_for(classname)
                if item_defaults:
                    info.defaults = item_defaults
                    info.defaults_source = "itemlist"
            if info.function == "SpawnItemFromItemlist" and info.block_source == "none":
                info.has_block = True
                info.block_source = "itemlist"
            manifest[classname] = info
        return manifest

    def _should_follow_helper_calls(self, classname: str) -> bool:
        if not classname:
            return False
        if classname == "light":
            return True
        prefixes = ("func_", "target_", "trigger_", "misc_", "info_", "path_", "point_")
        return classname.startswith(prefixes)

    def _merge_spawnflags(
        self, first: Dict[str, List[int]], second: Dict[str, List[int]]
    ) -> Dict[str, List[int]]:
        merged: Dict[str, List[int]] = {}
        keys = set(first) | set(second)
        for key in keys:
            merged[key] = sorted(set(first.get(key, [])) | set(second.get(key, [])))
        return merged

    def _direct_sub_calls(self, block: List[str]) -> Set[str]:
        calls: Set[str] = set()
        call_pattern = re.compile(r"\b(sub_[0-9a-f]+)\s*\(", re.IGNORECASE)
        for line in block:
            if self._match_function_decl(line):
                continue
            for match in call_pattern.finditer(line):
                calls.add(match.group(1))
        return calls

    def _extract_spawnflags_with_helpers(self, func_name: str) -> Dict[str, List[int]]:
        merged: Dict[str, List[int]] = {
            "checks": [],
            "sets": [],
            "clears": [],
            "assignments": [],
        }
        visited: Set[str] = set()

        def walk(name: str, depth: int) -> None:
            nonlocal merged
            if name in visited:
                return
            visited.add(name)
            block = self.function_blocks.get(name)
            if not block:
                return
            merged = self._merge_spawnflags(merged, self._extract_spawnflags(block))
            if depth >= 2:
                return
            for callee in self._direct_sub_calls(block):
                if callee in visited:
                    continue
                callee_block = self.function_blocks.get(callee)
                if not callee_block:
                    continue
                if not any("0x11c" in line for line in callee_block):
                    continue
                walk(callee, depth + 1)

        walk(func_name, 0)
        return merged

    def _itemlist_entries(self) -> Dict[str, Tuple[int, ...]]:
        if self._itemlist_cache is not None:
            return self._itemlist_cache
        entries: Dict[str, Tuple[int, ...]] = {}
        if not self._load_binary_image() or self._binary_data is None:
            self._itemlist_cache = entries
            return entries
        base_address = 0x10046928
        entry_size = 0x48
        offset = self._va_to_file_offset(base_address)
        if offset is None:
            self._itemlist_cache = entries
            return entries
        data = self._binary_data
        idx = 0
        while offset + (idx + 1) * entry_size <= len(data):
            start = offset + idx * entry_size
            chunk = data[start : start + entry_size]
            if len(chunk) < entry_size:
                break
            values = struct.unpack("<" + "I" * (entry_size // 4), chunk)
            if not any(values):
                if idx != 0:
                    break
                idx += 1
                continue
            classname_ptr = values[0]
            classname = self._read_c_string(classname_ptr)
            if classname:
                entries[self._normalize_classname(classname)] = values
            idx += 1
        self._itemlist_cache = entries
        return entries

    def _itemlist_defaults_for(self, classname: str) -> Dict[str, List[Dict[str, object]]]:
        entries = self._itemlist_entries()
        values = entries.get(classname)
        if not values:
            return {}
        defaults: Dict[str, List[Dict[str, object]]] = {}
        for idx, raw_value in enumerate(values):
            offset = idx * 4
            field_name = f"offset_0x{offset:x}"
            defaults[field_name] = [{"offset": offset, "value": int(raw_value)}]
        return defaults

    def _sub_1000b150_literal_sources(self) -> Dict[str, Set[str]]:
        if self._sub_1000b150_literals is not None:
            return self._sub_1000b150_literals
        pattern = re.compile(r'sub_1000b150\("([^\"]+)"\)', re.IGNORECASE)
        sources: Dict[str, Set[str]] = {}
        root = self.path.parent
        for source in self._sources:
            try:
                rel_path = source.path.relative_to(root).as_posix()
            except ValueError:
                rel_path = source.path.as_posix()
            for line in source.lines:
                for match in pattern.finditer(line):
                    literal = match.group(1)
                    sources.setdefault(literal, set()).add(rel_path)
        self._sub_1000b150_literals = sources
        return sources

    def _logged_spawn_entries(self) -> Dict[str, Dict[str, object]]:
        if self._logged_spawn_entries_cache is not None:
            return self._logged_spawn_entries_cache
        persisted_entries = self._load_persisted_sub_1000b150_map()
        interpreted_entries = self._interpret_sub_1000b150_calls()

        entries: Dict[str, Dict[str, object]] = {**persisted_entries}
        for classname, record in interpreted_entries.items():
            existing = entries.get(classname)
            if existing:
                merged_sources = sorted(
                    set(existing.get("sources", [])) | set(record.get("sources", []))
                )
                record["sources"] = merged_sources
            entries[classname] = record

        self._logged_spawn_entries_cache = entries
        return entries

    def _interpret_sub_1000b150_calls(self) -> Dict[str, Dict[str, object]]:
        literal_sources = self._sub_1000b150_literal_sources()
        if not literal_sources:
            return {}
        text_map: Dict[str, Dict[str, object]] = {}
        for record in self._spawn_table_records():
            text_label = record.get("text_label")
            if not text_label:
                continue
            text_map.setdefault(text_label.lower(), record)

        entries: Dict[str, Dict[str, object]] = {}
        for literal, source_paths in literal_sources.items():
            record = text_map.get(literal.lower())
            if not record:
                continue
            classname = record.get("classname")
            function = record.get("function")
            index = record.get("index")
            if classname is None or function is None or index is None:
                continue
            normalized = self._normalize_classname(classname)
            entries[normalized] = {
                "classname": normalized,
                "function": function,
                "index": int(index),
                "literal": literal,
                "sources": sorted(source_paths),
            }

        return entries

    def _load_persisted_sub_1000b150_map(self) -> Dict[str, Dict[str, object]]:
        interpreted_path = self.path.parent / "interpreted" / "sub_1000b150_map.json"
        entries: Dict[str, Dict[str, object]] = {}
        if not interpreted_path.is_file():
            return entries
        try:
            data = json.loads(interpreted_path.read_text(encoding="utf-8"))
        except json.JSONDecodeError:
            return entries
        if not isinstance(data, list):
            return entries
        for record in data:
            if not isinstance(record, dict):
                continue
            classname = record.get("classname")
            function = record.get("function")
            index = record.get("index")
            literal = record.get("literal")
            if classname is None or function is None or index is None or literal is None:
                continue
            normalized = self._normalize_classname(str(classname))
            entries[normalized] = {
                "classname": normalized,
                "function": str(function),
                "index": int(index),
                "literal": str(literal),
                "sources": sorted(record.get("sources", [])),
            }
        return entries

    def sub_1000b150_logged_map(self) -> List[Dict[str, object]]:
        entries = []
        for record in self._logged_spawn_entries().values():
            entries.append(
                {
                    "classname": record["classname"],
                    "function": record["function"],
                    "index": record["index"],
                    "literal": record["literal"],
                    "sources": record["sources"],
                }
            )
        return sorted(entries, key=lambda entry: (entry["index"], entry["classname"]))

    def _extract_defaults(self, block: List[str], fields: Dict[int, FieldInfo]) -> Dict[str, List[Dict[str, object]]]:
        results: Dict[str, List[Dict[str, object]]] = {}
        assign_pattern = re.compile(
            r"\*\((?:[a-z0-9_]+ \+ )?0x([0-9a-f]+)\) = (0x[0-9a-f]+|-?\d+)",
            re.IGNORECASE,
        )
        for line in block:
            for match in assign_pattern.finditer(line):
                offset = int(match.group(1), 16)
                raw_val = match.group(2)
                if raw_val.lower().startswith("0x"):
                    value = int(raw_val, 16)
                else:
                    value = int(raw_val, 10)
                field_info = fields.get(offset)
                if not field_info or offset < 0x100:
                    field_name = f"offset_0x{offset:x}"
                else:
                    field_name = field_info.name
                    if field_info.type_id == 1:  # float-like
                        value = _decode_float(value)
                    elif field_info.type_id in (0x10001, 0x10002):  # handle extended markers
                        value = value
                entry = {"value": value, "offset": offset}
                results.setdefault(field_name, []).append(entry)
        return results

    def _extract_spawnflags(self, block: List[str]) -> Dict[str, List[int]]:
        checks: Set[int] = set()
        sets: Set[int] = set()
        clears: Set[int] = set()
        assignments: Set[int] = set()
        alias_names: Set[str] = set()
        def normalize_alias(name: str) -> str:
            base = name
            if ":" in base:
                base = base.split(":", 1)[0]
            if "." in base:
                base = base.split(".", 1)[0]
            return base
        alias_pattern = re.compile(
            r"(?P<lhs>[A-Za-z_][\w\.:]*)\s*=\s*(?:\(\*[^)]*0x11c[^)]*\)(?:\.\w+)?|\*[^;]*0x11c[^;]*)",
            re.IGNORECASE,
        )
        direct_check_pattern = re.compile(
            r"\([^)]*0x11c[^)]*\)\s*&\s*(0x[0-9a-f]+|\d+)",
            re.IGNORECASE,
        )
        direct_assign_pattern = re.compile(
            r"\*\([^)]*0x11c[^)]*\)\s*=\s*(0x[0-9a-f]+|\d+)",
            re.IGNORECASE,
        )
        direct_clear_pattern = re.compile(
            r"\*\([^)]*0x11c[^)]*\)\s*=\s*\*\([^)]*0x11c[^)]*\)\s*&\s*(0x[0-9a-f]+|\d+)",
            re.IGNORECASE,
        )
        direct_or_pattern = re.compile(r"\|=\s*(0x[0-9a-f]+|\d+)", re.IGNORECASE)
        direct_or_assign_pattern = re.compile(
            r"=\s*[^;]*\|\s*(0x[0-9a-f]+|\d+)", re.IGNORECASE
        )
        direct_and_pattern = re.compile(r"&=\s*(0x[0-9a-f]+|\d+)", re.IGNORECASE)
        alias_op_pattern = re.compile(
            r"(?P<alias>[A-Za-z_][\w\.:]*)\s*(?P<op>\|=|&=)\s*(0x[0-9a-f]+|\d+)",
            re.IGNORECASE,
        )
        alias_check_pattern = re.compile(
            r"([A-Za-z_][\w\.:]*)\s*&\s*(0x[0-9a-f]+|\d+)",
            re.IGNORECASE,
        )
        reverse_alias_check_pattern = re.compile(
            r"(0x[0-9a-f]+|\d+)\s*&\s*([A-Za-z_][\w\.:]*)",
            re.IGNORECASE,
        )

        for line in block:
            if "0x11c" not in line:
                continue
            for alias_match in alias_pattern.finditer(line):
                if "==" in line or "!=" in line:
                    continue
                alias_names.add(normalize_alias(alias_match.group("lhs")))
            m_assign = direct_assign_pattern.search(line)
            if m_assign:
                assignments.add(int(m_assign.group(1), 0))
            for m in direct_or_pattern.finditer(line):
                sets.add(int(m.group(1), 0))
            if "|=" not in line:
                for m in direct_or_assign_pattern.finditer(line):
                    sets.add(int(m.group(1), 0))
            for m in direct_and_pattern.finditer(line):
                mask = int(m.group(1), 0) & 0xFFFFFFFF
                cleared = (~mask) & 0xFFFFFFFF
                if 0 < cleared < 0xFFFFFFFF:
                    clears.add(cleared)
            m_clear = direct_clear_pattern.search(line)
            if m_clear:
                mask = int(m_clear.group(1), 0) & 0xFFFFFFFF
                cleared = (~mask) & 0xFFFFFFFF
                if 0 < cleared < 0xFFFFFFFF:
                    clears.add(cleared)
            for m in direct_check_pattern.finditer(line):
                checks.add(int(m.group(1), 0))

        for line in block:
            for m in alias_op_pattern.finditer(line):
                alias = normalize_alias(m.group("alias"))
                value = int(m.group(3), 0)
                if alias not in alias_names:
                    continue
                if m.group("op") == "|=":
                    sets.add(value)
                else:
                    mask = value & 0xFFFFFFFF
                    cleared = (~mask) & 0xFFFFFFFF
                    if 0 < cleared < 0xFFFFFFFF:
                        clears.add(cleared)
            for m in alias_check_pattern.finditer(line):
                alias = normalize_alias(m.group(1))
                if alias not in alias_names:
                    continue
                checks.add(int(m.group(2), 0))
            for m in reverse_alias_check_pattern.finditer(line):
                alias = normalize_alias(m.group(2))
                if alias not in alias_names:
                    continue
                checks.add(int(m.group(1), 0))

        return {
            "checks": sorted(checks),
            "sets": sorted(sets),
            "clears": sorted(clears),
            "assignments": sorted(assignments),
        }


# ----------------------------- Repo parsing -----------------------------

class MacroResolver:
    def __init__(self, source_paths: Iterable[Path], overrides: Optional[Dict[str, str]] = None):
        self.definitions: Dict[str, str] = {}
        pattern = re.compile(r"^\s*#\s*define\s+(\w+)\s+(.+)$")
        for path in source_paths:
            for line in path.read_text(encoding="utf-8", errors="ignore").splitlines():
                match = pattern.match(line)
                if match:
                    name, expr = match.groups()
                    if name not in self.definitions:
                        self.definitions[name] = expr.strip()
        for name, expr in (overrides or {}).items():
            self.definitions[name] = expr
        self._cache: Dict[str, int] = {}

    def evaluate(self, name: str) -> Optional[int]:
        if name in self._cache:
            return self._cache[name]
        expr = self.definitions.get(name)
        if expr is None:
            return None
        try:
            value = self._eval_expr(expr)
        except Exception:
            return None
        self._cache[name] = value
        return value

    def _eval_expr(self, expr: str) -> int:
        tree = ast.parse(expr, mode="eval")

        def _eval(node: ast.AST) -> int:
            if isinstance(node, ast.Expression):
                return _eval(node.body)
            if isinstance(node, ast.Num):  # type: ignore[attr-defined]
                return int(node.n)
            if isinstance(node, ast.Constant):
                if isinstance(node.value, (int, float)):
                    return int(node.value)
                if isinstance(node.value, str) and node.value.startswith("0x"):
                    return int(node.value, 16)
                raise ValueError
            if isinstance(node, ast.UnaryOp):
                operand = _eval(node.operand)
                if isinstance(node.op, ast.USub):
                    return -operand
                if isinstance(node.op, ast.UAdd):
                    return operand
                if isinstance(node.op, ast.Invert):
                    return (~operand) & 0xFFFFFFFF
                raise ValueError
            if isinstance(node, ast.BinOp):
                left = _eval(node.left)
                right = _eval(node.right)
                if isinstance(node.op, ast.Add):
                    return left + right
                if isinstance(node.op, ast.Sub):
                    return left - right
                if isinstance(node.op, ast.Mult):
                    return left * right
                if isinstance(node.op, ast.FloorDiv) or isinstance(node.op, ast.Div):
                    return int(left / right)
                if isinstance(node.op, ast.BitOr):
                    return left | right
                if isinstance(node.op, ast.BitAnd):
                    return left & right
                if isinstance(node.op, ast.BitXor):
                    return left ^ right
                if isinstance(node.op, ast.LShift):
                    return left << right
                if isinstance(node.op, ast.RShift):
                    return left >> right
                raise ValueError
            if isinstance(node, ast.Name):
                resolved = self.evaluate(node.id)
                if resolved is None:
                    raise ValueError
                return resolved
            raise ValueError

        return _eval(tree)


class RepoParser:
    def __init__(self, root: Path, macro_overrides: Optional[Dict[str, str]] = None):
        self.root = root
        self.game_dir = self.root / "src" / "game"
        self.source_files = list(self.game_dir.glob("**/*.c")) + list(self.game_dir.glob("**/*.h"))
        self.macro_resolver = MacroResolver(self.source_files, overrides=macro_overrides)
        self.spawn_map = self._parse_spawn_map()
        self.functions = self._parse_functions()
        self._function_cache: Dict[str, Optional[List[str]]] = {}
        self._call_blacklist = {
            "if",
            "for",
            "while",
            "switch",
            "return",
            "sizeof",
            "do",
            "case",
            "goto",
            "break",
            "continue",
        }

    def _parse_spawn_map(self) -> Dict[str, str]:
        spawn_map: Dict[str, str] = {}
        spawn_file = self.game_dir / "g_spawn.c"
        text = spawn_file.read_text(encoding="utf-8", errors="ignore")
        array_pattern = re.compile(r"\{\s*\"([^\"]+)\",\s*(SP_[^}]+)\}")
        for classname, func in array_pattern.findall(text):
            spawn_map[classname] = func.strip()
        for classname in sorted(self._parse_itemlist_classnames()):
            spawn_map.setdefault(classname, "SpawnItemFromItemlist")
        rotate_flag = self.macro_resolver.evaluate("OBLIVION_ENABLE_ROTATE_TRAIN")
        if rotate_flag is not None and rotate_flag == 0:
            spawn_map.pop("func_rotate_train", None)
        sentinel_flag = self.macro_resolver.evaluate("OBLIVION_ENABLE_MONSTER_SENTINEL")
        if sentinel_flag is not None and sentinel_flag == 0:
            spawn_map.pop("monster_sentinel", None)
        return spawn_map

    def _parse_itemlist_classnames(self) -> Set[str]:
        items_file = self.game_dir / "g_items.c"
        text = items_file.read_text(encoding="utf-8", errors="ignore")
        anchor = re.search(r"gitem_t\s+itemlist\s*\[\]\s*=", text)
        if not anchor:
            return set()
        brace_start = text.find("{", anchor.end())
        if brace_start == -1:
            return set()
        depth = 0
        brace_end = None
        for idx in range(brace_start, len(text)):
            ch = text[idx]
            if ch == "{":
                depth += 1
            elif ch == "}":
                depth -= 1
                if depth == 0:
                    brace_end = idx
                    break
        if brace_end is None:
            return set()
        block = text[brace_start:brace_end]
        classnames = set(re.findall(r"\{\s*\"([^\"]+)\"\s*,", block))
        lasercannon_flag = self.macro_resolver.evaluate("OBLIVION_ENABLE_WEAPON_LASERCANNON")
        if lasercannon_flag is not None and lasercannon_flag == 0:
            classnames.discard("weapon_lasercannon")
        return classnames

    def _parse_functions(self) -> Dict[str, List[str]]:
        functions: Dict[str, List[str]] = {}
        func_pattern = re.compile(r"^\w[\w\s\*]*\b(SP_[a-zA-Z0-9_]+)\s*\(([^)]*)\)")
        brace_stack: List[str] = []
        current_name: Optional[str] = None
        current_lines: List[str] = []
        for path in self.source_files:
            lines = path.read_text(encoding="utf-8", errors="ignore").splitlines()
            for line in lines:
                if current_name is None:
                    match = func_pattern.match(line)
                    if match:
                        if line.strip().endswith(";"):
                            continue
                        current_name = match.group(1)
                        brace_stack = []
                        if "{" in line:
                            brace_stack.append("{")
                        current_lines = [line]
                    continue
                else:
                    current_lines.append(line)
                    brace_stack.extend(ch for ch in line if ch == "{")
                    for ch in line:
                        if ch == "}":
                            if brace_stack:
                                brace_stack.pop()
                            else:
                                brace_stack = []
                    if not brace_stack and line.strip().endswith("}"):
                        functions[current_name] = current_lines[:]
                        current_name = None
                        current_lines = []
        return functions

    def _get_function_lines(self, name: str) -> Optional[List[str]]:
        cached = self._function_cache.get(name)
        if name in self._function_cache:
            return cached
        func_pattern = re.compile(rf"^\w[\w\s\*]*\b{name}\s*\(([^)]*)\)")
        brace_stack: List[str] = []
        current_lines: List[str] = []
        for path in self.source_files:
            lines = path.read_text(encoding="utf-8", errors="ignore").splitlines()
            for line in lines:
                if not current_lines:
                    match = func_pattern.match(line)
                    if match:
                        if line.strip().endswith(";"):
                            continue
                        current_lines.append(line)
                        brace_stack = ["{"] if "{" in line else []
                    continue
                current_lines.append(line)
                brace_stack.extend(ch for ch in line if ch == "{")
                for ch in line:
                    if ch == "}":
                        if brace_stack:
                            brace_stack.pop()
                        else:
                            brace_stack = []
                if not brace_stack and line.strip().endswith("}"):
                    self._function_cache[name] = current_lines
                    return current_lines
        self._function_cache[name] = None
        return None

    def _should_follow_helper_calls(self, classname: str) -> bool:
        if not classname:
            return False
        if classname == "light":
            return True
        prefixes = ("func_", "target_", "trigger_", "misc_", "info_", "path_", "point_")
        return classname.startswith(prefixes)

    def _match_function_decl(self, line: str) -> bool:
        decl_pattern = re.compile(
            r"^\s*[A-Za-z_][\w\s\*]*\b[A-Za-z_][A-Za-z0-9_]*\s*\([^;]*\)\s*(\{|$)"
        )
        return bool(decl_pattern.match(line))

    def _is_member_call(self, line: str, start: int) -> bool:
        idx = start - 1
        while idx >= 0 and line[idx].isspace():
            idx -= 1
        if idx >= 0 and line[idx] == ".":
            return True
        if idx >= 1 and line[idx - 1 : idx + 1] == "->":
            return True
        return False

    def _direct_helper_calls(self, lines: List[str]) -> Set[str]:
        calls: Set[str] = set()
        call_pattern = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(")
        for line in lines:
            if self._match_function_decl(line):
                continue
            if line.lstrip().startswith("#"):
                continue
            for match in call_pattern.finditer(line):
                name = match.group(1)
                if name in self._call_blacklist:
                    continue
                if self._is_member_call(line, match.start()):
                    continue
                calls.add(name)
        return calls

    def _extract_spawnflags_with_helpers(self, func_name: str) -> Dict[str, List[int]]:
        merged: Dict[str, List[int]] = {
            "checks": [],
            "sets": [],
            "clears": [],
            "assignments": [],
        }
        visited: Set[str] = set()

        def walk(name: str, depth: int) -> None:
            nonlocal merged
            if name in visited:
                return
            visited.add(name)
            block = self._get_function_lines(name)
            if not block:
                return
            merged = self._merge_spawnflags(merged, self._extract_spawnflags(block))
            if depth >= 2:
                return
            for callee in self._direct_helper_calls(block):
                if callee in visited:
                    continue
                callee_block = self._get_function_lines(callee)
                if not callee_block:
                    continue
                if not any("spawnflags" in line for line in callee_block):
                    continue
                walk(callee, depth + 1)

        walk(func_name, 0)
        return merged

    def build_manifest(self) -> Dict[str, RepoSpawnInfo]:
        manifest: Dict[str, RepoSpawnInfo] = {}
        for classname, func in sorted(self.spawn_map.items()):
            info = RepoSpawnInfo(classname=classname, function=func)
            lines = self.functions.get(func)
            if lines:
                info.defaults = self._extract_defaults(lines)
                if self._should_follow_helper_calls(classname):
                    info.spawnflags = self._extract_spawnflags_with_helpers(func)
                else:
                    info.spawnflags = self._extract_spawnflags(lines)
                if classname in {"func_door", "func_door_rotating", "func_door_secret"}:
                    merged: Dict[str, List[int]] = {}
                    for helper_name in (
                        "Think_SpawnDoorTrigger",
                        "Think_CalcMoveSpeed",
                        "Door_ClearStartOpenFlag",
                    ):
                        helper_lines = self._get_function_lines(helper_name) or []
                        helper_flags = self._extract_spawnflags(helper_lines)
                        merged = self._merge_spawnflags(merged, helper_flags)
                    info.spawnflags = self._merge_spawnflags(info.spawnflags, merged)
            manifest[classname] = info
        return manifest

    def _merge_spawnflags(
        self, first: Dict[str, List[int]], second: Dict[str, List[int]]
    ) -> Dict[str, List[int]]:
        merged: Dict[str, List[int]] = {}
        keys = set(first) | set(second)
        for key in keys:
            merged[key] = sorted(set(first.get(key, [])) | set(second.get(key, [])))
        return merged

    def _extract_defaults(self, lines: List[str]) -> Dict[str, float]:
        defaults: Dict[str, float] = {}
        assign_pattern = re.compile(
            r"\b([a-zA-Z_][a-zA-Z0-9_]*)->([a-zA-Z0-9_\.]+)\s*=\s*([^;]+)"
        )
        for line in lines:
            for match in assign_pattern.finditer(line):
                field = match.group(2)
                expr = match.group(3).strip()
                value = self._evaluate_default_expr(expr)
                if value is None:
                    continue
                defaults[field] = value
        return defaults

    def _evaluate_default_expr(self, expr: str) -> Optional[float]:
        expr = expr.strip()
        if not expr:
            return None
        normalized = self._normalize_c_numeric_expr(expr)
        value = self._eval_ast_numeric_expr(normalized)
        if value is not None:
            return value
        return self._parse_literal_or_macro(normalized)

    def _normalize_c_numeric_expr(self, expr: str) -> str:
        expr = expr.rstrip(";").strip()
        cast_pattern = re.compile(r"^\(\s*(?:const\s+)?(?:struct\s+)?[a-zA-Z_][\w\s\*]*\)")
        while True:
            match = cast_pattern.match(expr)
            if not match:
                break
            expr = expr[match.end() :].lstrip()
        expr = re.sub(r"(\d+\.\d+)[fF]\b", r"\\1", expr)
        expr = re.sub(r"(?<![0-9a-fA-FxX])(\d+)[fF]\b", r"\\1", expr)
        return expr

    def _eval_ast_numeric_expr(self, expr: str) -> Optional[float]:
        try:
            tree = ast.parse(expr, mode="eval")
        except SyntaxError:
            return None

        def _eval(node: ast.AST) -> Optional[float]:
            if isinstance(node, ast.Expression):
                return _eval(node.body)
            if isinstance(node, ast.Constant):
                if isinstance(node.value, (int, float)):
                    return float(node.value)
                if isinstance(node.value, str) and node.value.lower().startswith("0x"):
                    try:
                        return float(int(node.value, 16))
                    except ValueError:
                        return None
                return None
            if hasattr(ast, "Num") and isinstance(node, ast.Num):  # type: ignore[attr-defined]
                return float(node.n)
            if isinstance(node, ast.UnaryOp):
                operand = _eval(node.operand)
                if operand is None:
                    return None
                if isinstance(node.op, ast.USub):
                    return -operand
                if isinstance(node.op, ast.UAdd):
                    return operand
                if isinstance(node.op, ast.Invert):
                    return float((~int(operand)) & 0xFFFFFFFF)
                return None
            if isinstance(node, ast.BinOp):
                left = _eval(node.left)
                right = _eval(node.right)
                if left is None or right is None:
                    return None
                if isinstance(node.op, ast.Add):
                    return left + right
                if isinstance(node.op, ast.Sub):
                    return left - right
                if isinstance(node.op, ast.Mult):
                    return left * right
                if isinstance(node.op, ast.Div):
                    return left / right
                if isinstance(node.op, ast.FloorDiv):
                    return float(int(left / right))
                if isinstance(node.op, ast.Mod):
                    return left % right
                if isinstance(node.op, ast.BitOr):
                    return float(int(left) | int(right))
                if isinstance(node.op, ast.BitAnd):
                    return float(int(left) & int(right))
                if isinstance(node.op, ast.BitXor):
                    return float(int(left) ^ int(right))
                if isinstance(node.op, ast.LShift):
                    return float(int(left) << int(right))
                if isinstance(node.op, ast.RShift):
                    return float(int(left) >> int(right))
                return None
            if isinstance(node, ast.Name):
                resolved = self.macro_resolver.evaluate(node.id)
                if resolved is None:
                    return None
                return float(resolved)
            return None

        return _eval(tree)

    def _parse_literal_or_macro(self, expr: str) -> Optional[float]:
        token = expr.strip()
        if not token:
            return None
        if token.lower().startswith("0x"):
            try:
                return float(int(token, 16))
            except ValueError:
                return None
        try:
            return float(token)
        except ValueError:
            resolved = self.macro_resolver.evaluate(token)
            if resolved is not None:
                return float(resolved)
        return None

    def _extract_spawnflags(self, lines: List[str]) -> Dict[str, List[int]]:
        checks: List[int] = []
        sets: List[int] = []
        clears: List[int] = []
        assignments: List[int] = []
        resolver = self.macro_resolver

        def resolve_token(token: str) -> Optional[int]:
            token = token.strip()
            if not token:
                return None
            if token.lower().startswith("0x"):
                return int(token, 16)
            if token.isdigit():
                return int(token)
            return resolver.evaluate(token)

        for line in lines:
            if "spawnflags" not in line:
                continue
            if "|=" in line:
                token = line.split("|=")[-1].split(";")[0]
                value = resolve_token(token)
                if value is not None and value not in sets:
                    sets.append(value)
            if "&=" in line:
                token = line.split("&=")[-1].split(";")[0]
                value = resolve_token(token)
                if value is not None:
                    mask = value & 0xFFFFFFFF
                    cleared = (~mask) & 0xFFFFFFFF
                    if 0 < cleared < 0xFFFFFFFF and cleared not in clears:
                        clears.append(cleared)
            if "spawnflags =" in line:
                token = line.split("spawnflags =", 1)[1].split(";")[0]
                value = resolve_token(token)
                if value is not None and value not in assignments:
                    assignments.append(value)
            check_pattern = re.compile(r"spawnflags\s*&\s*([^&|)]+)")
            for match in check_pattern.finditer(line):
                value = resolve_token(match.group(1))
                if value is not None and value not in checks:
                    checks.append(value)
        return {
            "checks": sorted([v for v in checks if v is not None]),
            "sets": sorted([v for v in sets if v is not None]),
            "clears": sorted([v for v in clears if v is not None]),
            "assignments": sorted([v for v in assignments if v is not None]),
        }


# ----------------------------- comparison -----------------------------

@dataclass
class ComparisonResult:
    missing_in_repo: List[str] = field(default_factory=list)
    missing_in_hlil: List[str] = field(default_factory=list)
    hlil_missing_blocks: List[str] = field(default_factory=list)
    spawnflag_mismatches: Dict[str, Dict[str, Tuple[List[int], List[int]]]] = field(default_factory=dict)
    default_mismatches: Dict[str, Dict[str, Tuple[List[Dict[str, object]], Optional[float]]]] = field(default_factory=dict)


def compare_manifests(hlil: Dict[str, HLILSpawnInfo], repo: Dict[str, RepoSpawnInfo]) -> ComparisonResult:
    result = ComparisonResult()
    hlil_classnames = set(hlil)
    repo_classnames = set(repo)
    result.missing_in_repo = sorted(hlil_classnames - repo_classnames)
    result.missing_in_hlil = sorted(repo_classnames - hlil_classnames)

    shared = sorted(hlil_classnames & repo_classnames)
    result.hlil_missing_blocks = sorted(
        classname for classname in shared if not hlil[classname].has_block
    )
    for classname in shared:
        hl = hlil[classname]
        rp = repo[classname]
        if rp.function == "SpawnItemFromItemlist":
            continue
        if hl.spawnflags_source != "none":
            spawnflag_diff: Dict[str, Tuple[List[int], List[int]]] = {}
            for key in ("checks", "sets", "clears", "assignments"):
                hl_vals = sorted(set(hl.spawnflags.get(key, [])))
                rp_vals = sorted(set(rp.spawnflags.get(key, [])))
                if hl_vals != rp_vals:
                    spawnflag_diff[key] = (hl_vals, rp_vals)
            if spawnflag_diff:
                result.spawnflag_mismatches[classname] = spawnflag_diff

        default_diff: Dict[str, Tuple[List[Dict[str, object]], Optional[float]]] = {}
        for field_name, entries in hl.defaults.items():
            repo_value = rp.defaults.get(field_name)
            if repo_value is None:
                default_diff[field_name] = (entries, None)
            else:
                hl_values = sorted({json.dumps(e, sort_keys=True) for e in entries})
                if not math.isclose(float(json.loads(hl_values[0])["value"]), repo_value, rel_tol=1e-4, abs_tol=1e-4):
                    default_diff[field_name] = (entries, repo_value)
        if default_diff:
            result.default_mismatches[classname] = default_diff

    return result


# ----------------------------- command line interface -----------------------------


def _parse_macro_overrides(definitions: Sequence[str]) -> Dict[str, str]:
    overrides: Dict[str, str] = {}
    for definition in definitions:
        if "=" in definition:
            name, value = definition.split("=", 1)
        else:
            name, value = definition, "1"
        name = name.strip()
        value = value.strip()
        if not name:
            continue
        overrides[name] = value or "1"
    return overrides


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--hlil", type=Path, default=Path("references/HLIL/oblivion/gamex86.dll_hlil.txt"))
    parser.add_argument("--repo", type=Path, default=Path("."))
    parser.add_argument("--output", type=Path, help="Write combined manifest JSON to this path")
    parser.add_argument("--comparison", type=Path, help="Write comparison JSON to this path")
    parser.add_argument("--pretty", action="store_true", help="Pretty-print JSON when writing to stdout")
    parser.add_argument(
        "-D",
        "--define",
        action="append",
        default=[],
        help="Override a macro definition when parsing repo spawn data (NAME or NAME=VALUE)",
    )
    parser.add_argument(
        "--dump-b150-map",
        type=Path,
        help="Write the interpreted sub_1000b150 literal-to-classname map to this path",
    )
    args = parser.parse_args(argv)

    hlil_parser = HLILParser(args.hlil)
    macro_overrides = _parse_macro_overrides(args.define)
    repo_parser = RepoParser(args.repo, macro_overrides=macro_overrides)

    hlil_manifest = hlil_parser.build_manifest()
    repo_manifest = repo_parser.build_manifest()
    comparison = compare_manifests(hlil_manifest, repo_manifest)

    if args.dump_b150_map:
        args.dump_b150_map.write_text(
            json.dumps(hlil_parser.sub_1000b150_logged_map(), indent=2, sort_keys=True)
        )

    combined = {
        "hlil": {
            classname: {
                "function": info.function,
                "defaults": info.defaults,
                "defaults_source": info.defaults_source,
                "spawnflags": info.spawnflags,
                "spawnflags_source": info.spawnflags_source,
                "block_source": info.block_source,
            }
            for classname, info in sorted(hlil_manifest.items())
        },
        "repo": {
            classname: {
                "function": info.function,
                "defaults": info.defaults,
                "spawnflags": info.spawnflags,
            }
            for classname, info in sorted(repo_manifest.items())
        },
    }

    if args.output:
        args.output.write_text(json.dumps(combined, indent=2, sort_keys=True))
    if args.comparison:
        args.comparison.write_text(
            json.dumps(
                {
                    "missing_in_repo": comparison.missing_in_repo,
                    "missing_in_hlil": comparison.missing_in_hlil,
                    "hlil_missing_blocks": comparison.hlil_missing_blocks,
                    "spawnflag_mismatches": comparison.spawnflag_mismatches,
                    "default_mismatches": comparison.default_mismatches,
                },
                indent=2,
                sort_keys=True,
            )
        )

    if not args.output:
        dump = {
            "combined": combined,
            "comparison": {
                "missing_in_repo": comparison.missing_in_repo,
                "missing_in_hlil": comparison.missing_in_hlil,
                "hlil_missing_blocks": comparison.hlil_missing_blocks,
                "spawnflag_mismatches": comparison.spawnflag_mismatches,
                "default_mismatches": comparison.default_mismatches,
            },
        }
        json_kwargs = {"indent": 2, "sort_keys": True} if args.pretty else {}
        json.dump(dump, sys.stdout, **json_kwargs)
        if args.pretty:
            sys.stdout.write("\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
