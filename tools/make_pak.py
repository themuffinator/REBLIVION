from __future__ import annotations

import argparse
import shutil
import struct
from pathlib import Path


PAK_HEADER = struct.Struct("<4sii")
PAK_ENTRY = struct.Struct("<56sii")
PAK_MAGIC = b"PACK"
MAX_PAK_PATH = 56


def iter_files(root: Path) -> list[tuple[Path, str]]:
    files: list[tuple[Path, str]] = []

    for path in sorted((p for p in root.rglob("*") if p.is_file()), key=lambda item: item.relative_to(root).as_posix().lower()):
        rel = path.relative_to(root).as_posix()

        if len(rel.encode("ascii")) >= MAX_PAK_PATH:
            raise ValueError(f"PAK path is too long ({len(rel)} >= {MAX_PAK_PATH}): {rel}")

        files.append((path, rel))

    return files


def build_pak(source_dir: Path, output_path: Path) -> None:
    entries: list[tuple[str, int, int]] = []

    output_path.parent.mkdir(parents=True, exist_ok=True)

    with output_path.open("wb") as pak_file:
        pak_file.write(PAK_HEADER.pack(PAK_MAGIC, 0, 0))

        for file_path, rel_path in iter_files(source_dir):
            file_offset = pak_file.tell()
            file_size = file_path.stat().st_size

            with file_path.open("rb") as source_file:
                shutil.copyfileobj(source_file, pak_file, length=1024 * 1024)

            entries.append((rel_path, file_offset, file_size))

        dir_offset = pak_file.tell()

        for rel_path, file_offset, file_size in entries:
            name = rel_path.encode("ascii")
            pak_file.write(PAK_ENTRY.pack(name.ljust(MAX_PAK_PATH, b"\0"), file_offset, file_size))

        dir_size = len(entries) * PAK_ENTRY.size
        pak_file.seek(0)
        pak_file.write(PAK_HEADER.pack(PAK_MAGIC, dir_offset, dir_size))

    print(f"Packed {len(entries)} files into {output_path}")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Create a Quake II .pak archive from a directory tree.")
    parser.add_argument("source_dir", type=Path, help="Directory whose contents should become the pak root")
    parser.add_argument("output_path", type=Path, help="Destination pak file path")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    source_dir = args.source_dir.resolve()
    output_path = args.output_path.resolve()

    if not source_dir.is_dir():
        raise SystemExit(f"Source directory not found: {source_dir}")

    build_pak(source_dir, output_path)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
