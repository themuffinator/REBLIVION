# Building the game module

This repository now ships with a CMake build that targets the Quake II game DLL/SO located under `src/game/`.

Retail Oblivion itself was released only for Windows. The reconstruction in this repository is what enables equivalent game-module builds for Windows, Linux, and macOS.

The repository version is stored in the top-level `VERSION` file and is used by the nightly packaging workflow.

## Prerequisites

- A C11-capable compiler (tested with GCC 11.4 on Ubuntu 22.04)
- [CMake](https://cmake.org/) 3.16 or newer
- Build tools supported by CMake (for example `ninja` or GNU Make)

## Configure and build (Linux / macOS)

```bash
cmake -S . -B build
cmake --build build
```

The resulting shared object is placed in `build/` as `game.so` (or `game.dylib` on macOS).

## Configure and build (Windows)

```powershell
cmake -S . -B build
cmake --build build --config Release
```

The resulting DLL will be emitted as `build/Release/gamex86.dll` for Visual Studio generators, or `build/gamex86.dll` for single-config generators.

### Notes

- The build script automatically includes every `.c` file located in `src/game/` and produces a position-independent shared module named `game`.
- The Windows build uses the existing `game.def` export definition file so that the exports match the original SDK.
- If `C:/q2Clean` exists, the default Windows build also copies the produced DLL into `C:/q2Clean/oblivion-re` for local testing. Set `-DOBLIVION_ENABLE_LOCAL_DEPLOY=OFF` to disable that behavior explicitly.
- You can change the build directory (`build` in the commands above) to any location you prefer.
- To install the compiled library, run `cmake --install build` and look under `lib/` (Linux/macOS) or `bin/` (Windows) inside the installation prefix.

## Nightly packaging

Nightly packaging scripts are provided for Linux, macOS, and Windows:

```bash
bash scripts/release/nightly-linux.sh
bash scripts/release/nightly-macos.sh
```

```powershell
powershell -ExecutionPolicy Bypass -File scripts/release/nightly-windows.ps1
```

Each script:

- reads the base semantic version from `VERSION`
- builds a release binary for its platform
- stages an `oblivion/` folder containing the platform binary, `pack/oblivion.cfg`, and `README.html`
- writes a versioned archive under `dist/` (`.tar.gz` on Linux/macOS, `.zip` on Windows)

The GitHub Actions workflow at `.github/workflows/nightly-release.yml` runs these scripts on a nightly schedule and publishes the generated archives as a release tagged like `v1.0.0-nightly.20260316`.

These release archives are intended to be extracted over an existing Oblivion installation. They replace the platform game module and `oblivion.cfg`; they do not replace the original mod data install.

## Validation

The Linux instructions above were validated on Ubuntu 22.04 using GCC 11.4 and CMake 3.22.1. The build completed successfully and produced `build/game.so`.
