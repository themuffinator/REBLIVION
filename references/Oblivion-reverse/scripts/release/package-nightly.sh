#!/usr/bin/env bash

set -euo pipefail

if [[ $# -ne 2 ]]; then
	echo "usage: $0 <linux|macos> <binary-name>" >&2
	exit 1
fi

platform="$1"
binary_name="$2"
root_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
version_file="$root_dir/VERSION"

if [[ ! -f "$version_file" ]]; then
	echo "missing VERSION file" >&2
	exit 1
fi

base_version="$(tr -d '\r\n' < "$version_file")"
if [[ ! "$base_version" =~ ^[0-9]+\.[0-9]+\.[0-9]+$ ]]; then
	echo "VERSION must contain semantic version text like 0.1.0" >&2
	exit 1
fi

nightly_stamp="${NIGHTLY_STAMP:-$(date -u +%Y%m%d)}"
release_tag="${RELEASE_TAG:-v${base_version}-nightly.${nightly_stamp}}"
build_dir="${BUILD_DIR:-$root_dir/build-nightly-$platform}"
dist_dir="${DIST_DIR:-$root_dir/dist/$platform}"
stage_dir="$dist_dir/oblivion"
archive_name="oblivion-${platform}-${release_tag}.tar.gz"
archive_path="$root_dir/dist/$archive_name"

cmake -S "$root_dir" -B "$build_dir" -DCMAKE_BUILD_TYPE=Release
cmake --build "$build_dir" --config Release

binary_path=""
for candidate in \
	"$build_dir/$binary_name" \
	"$build_dir/Release/$binary_name"
do
	if [[ -f "$candidate" ]]; then
		binary_path="$candidate"
		break
	fi
done

if [[ -z "$binary_path" ]]; then
	echo "unable to find built binary $binary_name under $build_dir" >&2
	exit 1
fi

rm -rf "$dist_dir"
mkdir -p "$stage_dir"
cp "$binary_path" "$stage_dir/$binary_name"
cp "$root_dir/pack/oblivion.cfg" "$stage_dir/oblivion.cfg"
cp "$root_dir/docs/release-readme.html" "$stage_dir/README.html"

mkdir -p "$root_dir/dist"
tar -C "$dist_dir" -czf "$archive_path" oblivion

if [[ -n "${GITHUB_OUTPUT:-}" ]]; then
	{
		echo "archive_path=$archive_path"
		echo "archive_name=$archive_name"
		echo "release_tag=$release_tag"
		echo "base_version=$base_version"
	} >> "$GITHUB_OUTPUT"
fi

echo "created $archive_path"