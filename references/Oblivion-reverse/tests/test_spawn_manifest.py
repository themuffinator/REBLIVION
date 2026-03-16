import json
import subprocess
import sys
import tempfile
from pathlib import Path
import unittest


class SpawnManifestSnapshotTest(unittest.TestCase):
    def _extract_manifest(self, defines: list[str] | None = None) -> tuple[dict, Path]:
        repo_root = Path(__file__).resolve().parents[1]
        script = repo_root / "tools" / "extract_spawn_manifest.py"
        cmd = [sys.executable, str(script)]
        for definition in defines or []:
            cmd.extend(["--define", definition])
        result = subprocess.run(
            cmd,
            check=True,
            capture_output=True,
            text=True,
        )
        return json.loads(result.stdout), repo_root

    def test_manifest_matches_snapshot(self) -> None:
        current, repo_root = self._extract_manifest()
        expected_path = repo_root / "tests" / "expected_spawn_manifest.json"
        expected = json.loads(expected_path.read_text(encoding="utf-8"))
        hlil_manifest = current.get("combined", {}).get("hlil", {})
        self.assertGreater(
            len(hlil_manifest),
            0,
            "Parsed HLIL manifest should contain at least one classname",
        )
        self.assertIn(
            "monster_jorg",
            hlil_manifest,
            "Expected monster_jorg entry missing from HLIL manifest",
        )
        self.assertEqual(
            hlil_manifest["monster_jorg"].get("function"),
            "sub_10022100",
            "monster_jorg HLIL manifest entry does not match expected function",
        )
        self.assertIn(
            "weapon_rtdu",
            hlil_manifest,
            "Expected weapon_rtdu entry missing from HLIL manifest",
        )
        self.assertEqual(
            hlil_manifest["weapon_rtdu"].get("function"),
            "sub_10014220",
            "weapon_rtdu HLIL manifest entry does not match expected function",
        )
        self.assertEqual(
            hlil_manifest["ammo_rifleplasma"].get("function"),
            "sub_10037c80",
            "ammo_rifleplasma should map to the HLIL function recovered from sub_1000b150",
        )
        self.assertEqual(
            hlil_manifest["misc_camera"].get("function"),
            "sub_100035f0",
            "misc_camera should map to the retail camera spawn recovered from the HLIL corpus",
        )
        self.assertEqual(
            hlil_manifest["misc_camera_target"].get("function"),
            "sub_10003880",
            "misc_camera_target should map to the retail path-target spawn recovered from the HLIL corpus",
        )
        self.assertEqual(
            hlil_manifest["trigger_misc_camera"].get("function"),
            "sub_10003ba0",
            "trigger_misc_camera should map to the retail trigger wrapper recovered from the HLIL corpus",
        )
        repo_manifest = current.get("combined", {}).get("repo", {})
        self.assertIn(
            "monster_makron",
            repo_manifest,
            "Expected monster_makron entry missing from repo manifest",
        )
        self.assertEqual(
            repo_manifest["monster_makron"].get("function"),
            "SP_monster_makron",
            "monster_makron repo manifest entry does not match expected function",
        )
        missing_in_repo = current.get("comparison", {}).get("missing_in_repo", [])
        self.assertNotIn(
            "monster_makron",
            missing_in_repo,
            "monster_makron should be spawnable by maps but is still reported missing",
        )
        self.assertEqual(current, expected)

    def test_parity_manifest_omits_oblivion_only_sentinel(self) -> None:
        current, repo_root = self._extract_manifest(["OBLIVION_ENABLE_MONSTER_SENTINEL=0"])
        repo_manifest = current.get("combined", {}).get("repo", {})
        self.assertNotIn(
            "monster_sentinel",
            repo_manifest,
            "monster_sentinel should not be present when the custom flag is disabled",
        )
        comparison = current.get("comparison", {})
        for key in ("missing_in_hlil", "only_in_repo"):
            self.assertNotIn(
                "monster_sentinel",
                comparison.get(key, []),
                f"monster_sentinel should be dropped from {key} when disabled",
            )

        expected_path = repo_root / "tests" / "expected_spawn_manifest.json"
        parity_expected = json.loads(expected_path.read_text(encoding="utf-8"))
        parity_expected.get("combined", {}).get("repo", {}).pop("monster_sentinel", None)
        parity_missing = parity_expected.get("comparison", {}).get("missing_in_hlil", [])
        parity_expected["comparison"]["missing_in_hlil"] = [
            classname for classname in parity_missing if classname != "monster_sentinel"
        ]
        self.assertEqual(current, parity_expected)

    def test_func_door_does_not_clear_start_open_bit(self) -> None:
        current, _ = self._extract_manifest()
        repo_manifest = current.get("combined", {}).get("repo", {})
        door_spawnflags = repo_manifest.get("func_door", {}).get("spawnflags", {})
        clears = door_spawnflags.get("clears", [])
        self.assertNotIn(
            1,
            clears,
            "func_door should not clear spawnflag bit 0 (START_OPEN) to mirror retail behaviour",
        )

    def test_func_water_does_not_toggle_spawnflags(self) -> None:
        current, _ = self._extract_manifest()
        repo_manifest = current.get("combined", {}).get("repo", {})
        water_flags = repo_manifest.get("func_water", {}).get("spawnflags", {})
        self.assertNotIn(
            32,
            water_flags.get("sets", []),
            "func_water should not rewrite spawnflags (e.g., DOOR_TOGGLE) when seeded",
        )

    def test_monster_spawners_and_defaults_are_present(self) -> None:
        current, _ = self._extract_manifest()
        combined = current.get("combined", {})
        repo_manifest = combined.get("repo", {})
        hlil_manifest = combined.get("hlil", {})

        required = {
            "monster_cyborg": {
                "defaults": {
                    "health": 300.0,
                    "mass": 300.0,
                    "gib_health": -120.0,
                    "monsterinfo.max_ideal_distance": 512.0,
                }
            },
            "monster_spider": {
                "defaults": {
                    "health": 400.0,
                    "mass": 300.0,
                    "gib_health": -175.0,
                },
                "spawnflags": {
                    "checks": [8],
                },
            },
            "monster_kigrax": {
                "defaults": {
                    "health": 200.0,
                    "mass": 150.0,
                    "gib_health": -100.0,
                    "viewheight": 90.0,
                }
            },
        }

        for classname, expectations in required.items():
            with self.subTest(classname=classname):
                self.assertIn(
                    classname,
                    repo_manifest,
                    f"{classname} missing from repo manifest",
                )
                self.assertIn(
                    classname,
                    hlil_manifest,
                    f"{classname} missing from HLIL manifest",
                )
                defaults = repo_manifest.get(classname, {}).get("defaults", {})
                for key, value in expectations.get("defaults", {}).items():
                    self.assertAlmostEqual(
                        defaults.get(key),
                        value,
                        msg=f"{classname} default {key} diverged from snapshot",
                    )

                spawnflags = repo_manifest.get(classname, {}).get("spawnflags", {})
                checks = spawnflags.get("checks", [])
                expected_checks = expectations.get("spawnflags", {}).get("checks", [])
                for flag in expected_checks:
                    self.assertIn(
                        flag,
                        checks,
                        f"{classname} missing expected spawnflag check {flag}",
                    )


class SpawnManifestControllersTest(unittest.TestCase):
    def test_target_controllers_are_extracted(self) -> None:
        repo_root = Path(__file__).resolve().parents[1]
        script = repo_root / "tools" / "extract_spawn_manifest.py"
        result = subprocess.run(
            [sys.executable, str(script)],
            check=True,
            capture_output=True,
            text=True,
        )
        manifest = json.loads(result.stdout)
        hlil_manifest = manifest.get("combined", {}).get("hlil", {})
        required = {
            "target_actor": "target_actor controllers should be present",
            "target_crosslevel_target": "Missing target_crosslevel_target controller entry",
        }
        for classname, message in required.items():
            self.assertIn(classname, hlil_manifest, message)
            func_name = hlil_manifest[classname].get("function", "")
            self.assertTrue(
                func_name.startswith("sub_"),
                f"{classname} should dispatch to a sub_* function, got {func_name!r}",
            )


class SpawnManifestDocsCoverageTest(unittest.TestCase):
    def test_docs_manifest_includes_controller_entries(self) -> None:
        repo_root = Path(__file__).resolve().parents[1]
        manifest_path = repo_root / "docs" / "manifests" / "spawn_manifest.json"
        data = json.loads(manifest_path.read_text(encoding="utf-8"))
        hlil_manifest = data.get("hlil", {})
        required = {
            "target_actor": "target_actor entry missing from docs manifest",
            "target_changelevel": "target_changelevel entry missing from docs manifest",
            "target_crosslevel_target": "target_crosslevel_target entry missing from docs manifest",
            "trigger_once": "trigger_once entry missing from docs manifest",
        }
        for classname, message in required.items():
            self.assertIn(classname, hlil_manifest, message)
            func_name = hlil_manifest[classname].get("function")
            self.assertTrue(
                isinstance(func_name, str) and func_name,
                f"{classname} should declare a function name",
            )


class Sub1000b150LogTest(unittest.TestCase):
    def test_logged_map_matches_snapshot(self) -> None:
        repo_root = Path(__file__).resolve().parents[1]
        script = repo_root / "tools" / "extract_spawn_manifest.py"
        expected_path = (
            repo_root
            / "references"
            / "HLIL"
            / "oblivion"
            / "interpreted"
            / "sub_1000b150_map.json"
        )
        with tempfile.TemporaryDirectory() as tmpdir:
            output = Path(tmpdir) / "map.json"
            subprocess.run(
                [
                    sys.executable,
                    str(script),
                    "--dump-b150-map",
                    str(output),
                ],
                check=True,
                capture_output=True,
                text=True,
            )
            current = json.loads(output.read_text(encoding="utf-8"))
        expected = json.loads(expected_path.read_text(encoding="utf-8"))
        self.assertEqual(
            current,
            expected,
            "sub_1000b150_map.json is out of date; rerun extract_spawn_manifest.py with --dump-b150-map",
        )


if __name__ == "__main__":
    unittest.main()
