param(
    [string]$WorkspaceRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path,
    [string]$StageRelativePath = ".install\oblivion",
    [string]$BinaryName = "game_x64.dll",
    [string]$PdbName = "game_x64.pdb",
    [string]$SteamRereleasePath = "C:\Program Files (x86)\Steam\steamapps\common\Quake 2\rerelease",
    [string]$SteamModName = "oblivion"
)

$ErrorActionPreference = "Stop"

$workspacePath = (Resolve-Path $WorkspaceRoot).Path
$stagePath = Join-Path $workspacePath $StageRelativePath
$binaryPath = Join-Path $workspacePath $BinaryName
$pdbPath = Join-Path $workspacePath $PdbName
$packSourcePath = Join-Path $workspacePath "pack"
$packBotsPath = Join-Path $packSourcePath "bots"
$packVideoPath = Join-Path $packSourcePath "video"
$pakPath = Join-Path $stagePath "pak0.pak"
$pakScriptPath = Join-Path $workspacePath "tools\make_pak.py"
$stageBotsPath = Join-Path $stagePath "bots"
$stageVideoPath = Join-Path $stagePath "video"
$introOverrideNames = @(
    "ntro.cin",
    "ntro.ogv",
    "ntro.srt",
    "ntro_de.srt",
    "ntro_es.srt",
    "ntro_fr.srt",
    "ntro_it.srt",
    "ntro_ru.srt"
)
$legacyIntroNames = @(
    "oblintro.cin",
    "oblintro.ogv",
    "oblintro.srt"
)
$steamPath = $SteamRereleasePath
$steamModPath = Join-Path $steamPath $SteamModName
$steamBaseQ2Path = Join-Path $steamPath "baseq2"
$steamBootstrapPakPath = Join-Path $steamBaseQ2Path ("pak0-{0}.pak" -f $SteamModName)
$stageMapDbPath = Join-Path $stagePath "mapdb.json"

if (-not (Test-Path $binaryPath)) {
    throw "Built binary not found: $binaryPath"
}

if (-not (Test-Path $packSourcePath)) {
    throw "Pack source directory not found: $packSourcePath"
}

if (-not (Test-Path $packBotsPath)) {
    throw "Bot config directory not found: $packBotsPath"
}

if (-not (Test-Path $pakScriptPath)) {
    throw "PAK builder script not found: $pakScriptPath"
}

foreach ($introOverrideName in $introOverrideNames) {
    $introOverridePath = Join-Path $packVideoPath $introOverrideName
    if (-not (Test-Path $introOverridePath)) {
        throw "Required intro override asset not found: $introOverridePath"
    }
}

New-Item -ItemType Directory -Force -Path $stagePath | Out-Null

Copy-Item -Force $binaryPath (Join-Path $stagePath $BinaryName)

if (Test-Path $pdbPath) {
    Copy-Item -Force $pdbPath (Join-Path $stagePath $PdbName)
}

if (Test-Path $pakPath) {
    Remove-Item -Force $pakPath
}

& python $pakScriptPath $packSourcePath $pakPath
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

if (Test-Path $stageBotsPath) {
    Remove-Item -Recurse -Force $stageBotsPath
}
Copy-Item -Recurse -Force $packBotsPath $stagePath

New-Item -ItemType Directory -Force -Path $stageVideoPath | Out-Null
foreach ($introOverrideName in $introOverrideNames) {
    Copy-Item -Force (Join-Path $packVideoPath $introOverrideName) (Join-Path $stageVideoPath $introOverrideName)
}
foreach ($legacyIntroName in $legacyIntroNames) {
    $legacyStagePath = Join-Path $stageVideoPath $legacyIntroName
    if (Test-Path $legacyStagePath) {
        Remove-Item -Force $legacyStagePath
    }
}

if (Test-Path $stageMapDbPath) {
    Remove-Item -Force $stageMapDbPath
}

if (Test-Path $steamPath) {
    if (Test-Path $steamBaseQ2Path) {
        if (Test-Path $steamBootstrapPakPath) {
            Remove-Item -Force $steamBootstrapPakPath
        }
        Copy-Item -Force $pakPath $steamBootstrapPakPath
        Write-Host "Updated bootstrap pack at $steamBootstrapPakPath"
    }
    else {
        Write-Warning "Steam baseq2 path not found: $steamBaseQ2Path"
    }

    if (Test-Path $steamModPath) {
        $steamModItem = Get-Item -Force $steamModPath
        $isLink = $steamModItem.Attributes -band [IO.FileAttributes]::ReparsePoint

        if ($isLink) {
            $linkTarget = $steamModItem.Target
            if ($linkTarget -is [array]) {
                $linkTarget = $linkTarget[0]
            }

            $normalizedLinkTarget = [IO.Path]::GetFullPath([string]$linkTarget)
            $normalizedStagePath = [IO.Path]::GetFullPath($stagePath)

            if ($normalizedLinkTarget -ne $normalizedStagePath) {
                cmd /c rmdir "$steamModPath" | Out-Null
                New-Item -ItemType Junction -Path $steamModPath -Target $stagePath | Out-Null
                Write-Host "Relinked $steamModPath -> $stagePath"
            }
        }
        else {
            Copy-Item -Force $binaryPath (Join-Path $steamModPath $BinaryName)

            if (Test-Path $pdbPath) {
                Copy-Item -Force $pdbPath (Join-Path $steamModPath $PdbName)
            }

            $steamPakPath = Join-Path $steamModPath "pak0.pak"
            if (Test-Path $steamPakPath) {
                Remove-Item -Force $steamPakPath
            }

            Copy-Item -Force $pakPath $steamPakPath

            $steamBotsPath = Join-Path $steamModPath "bots"
            if (Test-Path $steamBotsPath) {
                Remove-Item -Recurse -Force $steamBotsPath
            }
            Copy-Item -Recurse -Force $packBotsPath $steamModPath

            $steamVideoPath = Join-Path $steamModPath "video"
            New-Item -ItemType Directory -Force -Path $steamVideoPath | Out-Null
            foreach ($introOverrideName in $introOverrideNames) {
                Copy-Item -Force (Join-Path $packVideoPath $introOverrideName) (Join-Path $steamVideoPath $introOverrideName)
            }
            foreach ($legacyIntroName in $legacyIntroNames) {
                $legacySteamPath = Join-Path $steamVideoPath $legacyIntroName
                if (Test-Path $legacySteamPath) {
                    Remove-Item -Force $legacySteamPath
                }
            }

            $steamMapDbPath = Join-Path $steamModPath "mapdb.json"
            if (Test-Path $steamMapDbPath) {
                Remove-Item -Force $steamMapDbPath
            }

            Write-Host "Updated existing Steam mod directory at $steamModPath"
        }
    }
    else {
        New-Item -ItemType Junction -Path $steamModPath -Target $stagePath | Out-Null
        Write-Host "Linked $steamModPath -> $stagePath"
    }
}
else {
    Write-Warning "Steam rerelease path not found: $steamPath"
}

Write-Host "Installed dev stage to $stagePath"
