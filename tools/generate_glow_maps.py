from __future__ import annotations

import argparse
import struct
from collections import deque
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, Sequence

from PIL import Image


DEFAULT_THRESHOLD = 192
DEFAULT_GAMMA = 1.35
DEFAULT_GROW_RANGE = 28
DEFAULT_SATURATION_REDUCTION = 20.0
DEFAULT_ROOTS = (Path("pack/textures"), Path("pack/models"))
SUPPORTED_EXTENSIONS = {".pcx", ".wal"}


@dataclass
class RunStats:
    scanned: int = 0
    generated: int = 0
    overwritten: int = 0
    skipped_existing: int = 0
    skipped_dark: int = 0
    deleted_stale: int = 0


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Generate Quake II rerelease glow map PNGs for bright PCX and WAL assets."
    )
    parser.add_argument(
        "--repo-root",
        type=Path,
        default=Path(__file__).resolve().parents[1],
        help="Repository root. Defaults to the parent of this script's directory.",
    )
    parser.add_argument(
        "--root",
        dest="roots",
        action="append",
        type=Path,
        help="Relative asset root to scan. Can be specified multiple times.",
    )
    parser.add_argument(
        "--threshold",
        type=int,
        default=DEFAULT_THRESHOLD,
        help=f"Luminance threshold for glow extraction. Default: {DEFAULT_THRESHOLD}.",
    )
    parser.add_argument(
        "--gamma",
        type=float,
        default=DEFAULT_GAMMA,
        help=f"Alpha response curve for bright pixels. Default: {DEFAULT_GAMMA}.",
    )
    parser.add_argument(
        "--grow-range",
        type=int,
        default=DEFAULT_GROW_RANGE,
        help=(
            "How far below the local seed threshold connected pixels can extend while still "
            f"belonging to the same glowing element. Default: {DEFAULT_GROW_RANGE}."
        ),
    )
    parser.add_argument(
        "--saturation-reduction",
        type=float,
        default=DEFAULT_SATURATION_REDUCTION,
        help=(
            "Maximum amount by which fully saturated pixels reduce the glow threshold. "
            f"Default: {DEFAULT_SATURATION_REDUCTION}."
        ),
    )
    parser.add_argument(
        "--overwrite",
        action="store_true",
        help="Overwrite existing glow maps instead of skipping them.",
    )
    parser.add_argument(
        "--delete-stale",
        action="store_true",
        help="Delete existing glow maps when a source asset no longer qualifies.",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Report actions without writing or deleting files.",
    )
    parser.add_argument(
        "--quiet",
        action="store_true",
        help="Suppress per-file output and print only the summary.",
    )
    args = parser.parse_args()

    if not 0 <= args.threshold <= 255:
        parser.error("--threshold must be between 0 and 255.")
    if args.gamma <= 0:
        parser.error("--gamma must be greater than 0.")
    if args.grow_range < 0:
        parser.error("--grow-range must be greater than or equal to 0.")
    if args.saturation_reduction < 0:
        parser.error("--saturation-reduction must be greater than or equal to 0.")

    return args


def load_quake_palette(repo_root: Path) -> list[tuple[int, int, int]]:
    palette_source = repo_root / "pack/pics/colormap.pcx"
    with Image.open(palette_source) as image:
        palette = image.getpalette()

    if palette is None or len(palette) < 256 * 3:
        raise RuntimeError(f"Palette image does not contain a usable palette: {palette_source}")

    return [tuple(palette[index : index + 3]) for index in range(0, 256 * 3, 3)]


def iter_source_assets(repo_root: Path, roots: Sequence[Path]) -> Iterable[Path]:
    for relative_root in roots:
        asset_root = repo_root / relative_root
        if not asset_root.is_dir():
            continue

        for path in sorted(asset_root.rglob("*")):
            if path.suffix.lower() in SUPPORTED_EXTENSIONS:
                yield path


def read_wal_image(path: Path, palette: Sequence[tuple[int, int, int]]) -> Image.Image:
    data = path.read_bytes()
    if len(data) < 56:
        raise RuntimeError(f"WAL file is too small: {path}")

    width, height = struct.unpack_from("<II", data, 32)
    offset0 = struct.unpack_from("<I", data, 40)[0]
    pixel_count = width * height
    pixel_bytes = data[offset0 : offset0 + pixel_count]

    if len(pixel_bytes) != pixel_count:
        raise RuntimeError(f"WAL pixel data is truncated: {path}")

    image = Image.new("RGB", (width, height))
    image.putdata([palette[pixel] for pixel in pixel_bytes])
    return image


def load_rgb_image(path: Path, palette: Sequence[tuple[int, int, int]]) -> Image.Image:
    if path.suffix.lower() == ".wal":
        return read_wal_image(path, palette)

    with Image.open(path) as image:
        return image.convert("RGB")


def compute_saturation(red: int, green: int, blue: int) -> float:
    value = max(red, green, blue)
    if value == 0:
        return 0.0

    return (value - min(red, green, blue)) / value


def build_glow_image(
    image: Image.Image,
    threshold: int,
    gamma: float,
    grow_range: int,
    saturation_reduction: float,
) -> tuple[Image.Image, int] | None:
    width, height = image.size
    glow = Image.new("RGBA", (width, height))

    pixel_count = width * height
    luminances = [0.0] * pixel_count
    candidate_thresholds = [0.0] * pixel_count
    seed_pixels = [False] * pixel_count
    candidate_pixels = [False] * pixel_count
    included_pixels = [False] * pixel_count

    for index, (red, green, blue) in enumerate(image.getdata()):
        luminance = 0.2126 * red + 0.7152 * green + 0.0722 * blue
        saturation = compute_saturation(red, green, blue)
        local_seed_threshold = max(0.0, threshold - (saturation * saturation_reduction))
        local_candidate_threshold = max(0.0, local_seed_threshold - grow_range)

        luminances[index] = luminance
        candidate_thresholds[index] = local_candidate_threshold
        seed_pixels[index] = luminance >= local_seed_threshold
        candidate_pixels[index] = luminance >= local_candidate_threshold

    pending: deque[int] = deque(index for index, is_seed in enumerate(seed_pixels) if is_seed)
    while pending:
        index = pending.popleft()
        if included_pixels[index] or not candidate_pixels[index]:
            continue

        included_pixels[index] = True
        x = index % width
        y = index // width

        for neighbor_y in range(max(0, y - 1), min(height, y + 2)):
            row_offset = neighbor_y * width
            for neighbor_x in range(max(0, x - 1), min(width, x + 2)):
                neighbor_index = row_offset + neighbor_x
                if neighbor_index != index and candidate_pixels[neighbor_index] and not included_pixels[neighbor_index]:
                    pending.append(neighbor_index)

    output_pixels: list[tuple[int, int, int, int]] = []
    glowing_pixels = 0

    for index, luminance in enumerate(luminances):
        if not included_pixels[index]:
            output_pixels.append((255, 255, 255, 0))
            continue

        local_threshold = candidate_thresholds[index]
        scale_divisor = max(1.0, 255.0 - local_threshold)
        normalized = max(0.0, min(1.0, (luminance - local_threshold) / scale_divisor))
        alpha = round((normalized**gamma) * 255)
        output_pixels.append((255, 255, 255, alpha))
        glowing_pixels += 1

    if glowing_pixels == 0:
        return None

    glow.putdata(output_pixels)
    return glow, glowing_pixels


def write_glow_map(
    source_path: Path,
    glow_image: Image.Image | None,
    dry_run: bool,
    overwrite: bool,
    delete_stale: bool,
) -> tuple[str, Path]:
    glow_path = source_path.with_name(f"{source_path.stem}_glow.png")
    existed_before = glow_path.exists()

    if glow_image is None:
        if existed_before and delete_stale:
            if not dry_run:
                glow_path.unlink()
            return "deleted-stale", glow_path
        return "skipped-dark", glow_path

    if existed_before and not overwrite:
        return "skipped-existing", glow_path

    if not dry_run:
        glow_image.save(glow_path)

    return ("overwritten" if existed_before and overwrite else "generated"), glow_path


def record_result(stats: RunStats, result: str) -> None:
    if result == "generated":
        stats.generated += 1
    elif result == "overwritten":
        stats.overwritten += 1
    elif result == "skipped-existing":
        stats.skipped_existing += 1
    elif result == "skipped-dark":
        stats.skipped_dark += 1
    elif result == "deleted-stale":
        stats.deleted_stale += 1


def main() -> int:
    args = parse_args()
    repo_root = args.repo_root.resolve()
    roots = tuple(args.roots or DEFAULT_ROOTS)
    palette = load_quake_palette(repo_root)
    stats = RunStats()

    for source_path in iter_source_assets(repo_root, roots):
        stats.scanned += 1
        rgb_image = load_rgb_image(source_path, palette)
        glow_result = build_glow_image(
            rgb_image,
            args.threshold,
            args.gamma,
            args.grow_range,
            args.saturation_reduction,
        )
        glow_image = glow_result[0] if glow_result is not None else None
        result, glow_path = write_glow_map(
            source_path=source_path,
            glow_image=glow_image,
            dry_run=args.dry_run,
            overwrite=args.overwrite,
            delete_stale=args.delete_stale,
        )
        record_result(stats, result)

        if not args.quiet:
            print(f"{result:>15}  {glow_path.relative_to(repo_root).as_posix()}")

    print(
        "Summary: "
        f"scanned={stats.scanned} "
        f"generated={stats.generated} "
        f"overwritten={stats.overwritten} "
        f"skipped_existing={stats.skipped_existing} "
        f"skipped_dark={stats.skipped_dark} "
        f"deleted_stale={stats.deleted_stale}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())