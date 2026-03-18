param(
    [string]$WorkspaceRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path,
    [string]$Configuration = "Release",
    [ValidateSet("x64")]
    [string]$Platform = "x64",
    [string]$BinaryName = "game_x64.dll",
    [string]$StageFolderName = "reblivion",
    [string]$VersionFileRelativePath = "VERSION",
    [string]$ReadmeRelativePath = "docs\release-readme.html",
    [string]$DistRelativePath = "dist",
    [string]$NightlyStamp = "",
    [string]$ReleaseTag = "",
    [string]$Repository = "",
    [switch]$SkipBuild,
    [switch]$Publish
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest

function Get-GitValue {
    param(
        [string]$WorkspacePath,
        [string[]]$Arguments,
        [string]$Fallback
    )

    try {
        $result = (& git -C $WorkspacePath @Arguments 2>$null | Out-String).Trim()
        if ($LASTEXITCODE -eq 0 -and $result) {
            return $result
        }
    }
    catch {
    }

    return $Fallback
}

function Test-GitDirty {
    param(
        [string]$WorkspacePath
    )

    try {
        $status = & git -C $WorkspacePath status --porcelain --untracked-files=no 2>$null
        if ($LASTEXITCODE -eq 0 -and $status) {
            return $true
        }
    }
    catch {
    }

    return $false
}

function Invoke-PythonScript {
    param(
        [string]$WorkspacePath,
        [string[]]$ScriptArguments
    )

    $pythonCommand = Get-Command python -ErrorAction SilentlyContinue
    if ($pythonCommand) {
        & $pythonCommand.Source @ScriptArguments | Out-Host
        return $LASTEXITCODE
    }

    $pyLauncher = Get-Command py -ErrorAction SilentlyContinue
    if ($pyLauncher) {
        & $pyLauncher.Source -3 @ScriptArguments | Out-Host
        return $LASTEXITCODE
    }

    throw "Neither python nor py was found in PATH."
}

$workspacePath = (Resolve-Path $WorkspaceRoot).Path
$versionFilePath = Join-Path $workspacePath $VersionFileRelativePath
$readmePath = Join-Path $workspacePath $ReadmeRelativePath
$releaseBannerPath = Join-Path $workspacePath "docs\assets\reblivion-banner.png"
$buildScriptPath = Join-Path $workspacePath "tools\build_game.ps1"
$pakScriptPath = Join-Path $workspacePath "tools\make_pak.py"
$packSourcePath = Join-Path $workspacePath "pack"
$packVideoPath = Join-Path $packSourcePath "video"
$binaryPath = Join-Path $workspacePath $BinaryName
$distRoot = Join-Path $workspacePath $DistRelativePath
$stageRoot = Join-Path $distRoot "windows-x64"
$stageDir = Join-Path $stageRoot $StageFolderName
$stageAssetsPath = Join-Path $stageDir "assets"
$stageVideoPath = Join-Path $stageDir "video"
$pakPath = Join-Path $stageDir "pak0.pak"
$versionInfoPath = Join-Path $stageDir "VERSION.txt"
$notesPath = Join-Path $stageRoot "release-notes.txt"
$introVideoNames = @(
    "obintro.cin",
    "obintro.ogv",
    "obintro.srt",
    "obintro_de.srt",
    "obintro_es.srt",
    "obintro_fr.srt",
    "obintro_it.srt",
    "obintro_ru.srt"
)

if (-not (Test-Path $versionFilePath)) {
    throw "Missing VERSION file: $versionFilePath"
}

if (-not (Test-Path $readmePath)) {
    throw "Missing release readme: $readmePath"
}

if (-not (Test-Path $releaseBannerPath)) {
    throw "Missing release banner: $releaseBannerPath"
}

if (-not (Test-Path $buildScriptPath)) {
    throw "Missing build script: $buildScriptPath"
}

if (-not (Test-Path $pakScriptPath)) {
    throw "Missing pak build script: $pakScriptPath"
}

if (-not (Test-Path $packSourcePath)) {
    throw "Missing pack source directory: $packSourcePath"
}

foreach ($introVideoName in $introVideoNames) {
    $introVideoPath = Join-Path $packVideoPath $introVideoName
    if (-not (Test-Path $introVideoPath)) {
        throw "Missing Oblivion intro asset: $introVideoPath"
    }
}

$baseVersion = (Get-Content $versionFilePath -Raw).Trim()
if ($baseVersion -notmatch '^[0-9]+\.[0-9]+\.[0-9]+$') {
    throw "VERSION must contain semantic version text like 0.1.0"
}

if (-not $NightlyStamp) {
    $NightlyStamp = (Get-Date).ToUniversalTime().ToString("yyyyMMdd.HHmmss")
}

$commitShort = Get-GitValue -WorkspacePath $workspacePath -Arguments @("rev-parse", "--short=8", "HEAD") -Fallback "nogit"
$commitFull = Get-GitValue -WorkspacePath $workspacePath -Arguments @("rev-parse", "HEAD") -Fallback "unknown"
$isDirty = Test-GitDirty -WorkspacePath $workspacePath
$buildTimestampUtc = (Get-Date).ToUniversalTime().ToString("yyyy-MM-ddTHH:mm:ssZ")

if (-not $ReleaseTag) {
    $ReleaseTag = "v{0}-nightly.{1}.g{2}" -f $baseVersion, $NightlyStamp, $commitShort
}

$archiveName = "reblivion-windows-x64-{0}.zip" -f $ReleaseTag
$archivePath = Join-Path $distRoot $archiveName

$releaseNotes = @(
    "REBLIVION Windows x64 nightly build",
    "",
    "Base version: $baseVersion",
    "Release tag: $ReleaseTag",
    "Built at (UTC): $buildTimestampUtc",
    "Commit: $commitFull",
    "Working tree dirty: $isDirty",
    "Archive: $archiveName"
) -join [Environment]::NewLine

if (-not $SkipBuild) {
    & powershell -NoProfile -ExecutionPolicy Bypass -File $buildScriptPath `
        -WorkspaceRoot $workspacePath `
        -Configuration $Configuration `
        -Platform $Platform

    if ($LASTEXITCODE -ne 0) {
        exit $LASTEXITCODE
    }
}

if (-not (Test-Path $binaryPath)) {
    throw "Built binary not found: $binaryPath"
}

if (Test-Path $stageRoot) {
    Remove-Item -Recurse -Force $stageRoot
}

New-Item -ItemType Directory -Force -Path $stageDir | Out-Null
New-Item -ItemType Directory -Force -Path $stageAssetsPath | Out-Null
New-Item -ItemType Directory -Force -Path $stageVideoPath | Out-Null

Copy-Item -Force $binaryPath (Join-Path $stageDir $BinaryName)
Copy-Item -Force $readmePath (Join-Path $stageDir "README.html")
Copy-Item -Force $releaseBannerPath (Join-Path $stageAssetsPath "reblivion-banner.png")
foreach ($introVideoName in $introVideoNames) {
    Copy-Item -Force (Join-Path $packVideoPath $introVideoName) (Join-Path $stageVideoPath $introVideoName)
}

$versionInfo = @(
    "REBLIVION Windows x64 Nightly Build",
    "Base Version: $baseVersion",
    "Release Tag: $ReleaseTag",
    "Built At (UTC): $buildTimestampUtc",
    "Commit: $commitFull",
    "Commit Short: $commitShort",
    "Working Tree Dirty: $isDirty",
    "Platform: windows-x64",
    "Binary: $BinaryName",
    "Archive: $archiveName"
) -join [Environment]::NewLine
Set-Content -Path $versionInfoPath -Value $versionInfo -Encoding ASCII
Set-Content -Path $notesPath -Value $releaseNotes -Encoding ASCII

$pakExitCode = Invoke-PythonScript -WorkspacePath $workspacePath -ScriptArguments @(
    $pakScriptPath,
    $packSourcePath,
    $pakPath
)

if ($pakExitCode -ne 0) {
    exit $pakExitCode
}

New-Item -ItemType Directory -Force -Path $distRoot | Out-Null

if (Test-Path $archivePath) {
    Remove-Item -Force $archivePath
}

Add-Type -AssemblyName System.IO.Compression.FileSystem
[System.IO.Compression.ZipFile]::CreateFromDirectory(
    $stageDir,
    $archivePath,
    [System.IO.Compression.CompressionLevel]::Optimal,
    $true
)

if (-not (Test-Path $archivePath)) {
    throw "Failed to create archive: $archivePath"
}

if ($Publish) {
    $ghCommand = Get-Command gh -ErrorAction SilentlyContinue
    if (-not $ghCommand) {
        throw "GitHub CLI (gh) was not found in PATH."
    }

    $ghRepoArgs = @()
    if ($Repository) {
        $ghRepoArgs += @("--repo", $Repository)
    }

    $releaseApiBase = if ($Repository) {
        "repos/$Repository/releases"
    }
    else {
        "repos/{owner}/{repo}/releases"
    }

    Push-Location $workspacePath
    try {
        & $ghCommand.Source @ghRepoArgs release view $ReleaseTag *> $null
        $releaseExists = $LASTEXITCODE -eq 0

        if ($releaseExists) {
            & $ghCommand.Source @ghRepoArgs release edit $ReleaseTag --title $ReleaseTag --notes-file $notesPath
            if ($LASTEXITCODE -ne 0) {
                exit $LASTEXITCODE
            }

            $releaseId = (& $ghCommand.Source @ghRepoArgs release view $ReleaseTag --json databaseId --jq ".databaseId").Trim()
            if (-not $releaseId) {
                throw "Failed to resolve release id for $ReleaseTag"
            }

            & $ghCommand.Source api --method PATCH "$releaseApiBase/$releaseId" -F prerelease=false *> $null
            if ($LASTEXITCODE -ne 0) {
                exit $LASTEXITCODE
            }

            & $ghCommand.Source @ghRepoArgs release upload $ReleaseTag $archivePath --clobber
            if ($LASTEXITCODE -ne 0) {
                exit $LASTEXITCODE
            }
        }
        else {
            & $ghCommand.Source @ghRepoArgs release create $ReleaseTag $archivePath --title $ReleaseTag --notes-file $notesPath
            if ($LASTEXITCODE -ne 0) {
                exit $LASTEXITCODE
            }
        }
    }
    finally {
        Pop-Location
    }
}

$archiveHash = (Get-FileHash -Algorithm SHA256 $archivePath).Hash.ToLowerInvariant()

if ($env:GITHUB_OUTPUT) {
    Add-Content -Path $env:GITHUB_OUTPUT -Value "archive_path=$archivePath"
    Add-Content -Path $env:GITHUB_OUTPUT -Value "archive_name=$archiveName"
    Add-Content -Path $env:GITHUB_OUTPUT -Value "archive_sha256=$archiveHash"
    Add-Content -Path $env:GITHUB_OUTPUT -Value "release_tag=$ReleaseTag"
    Add-Content -Path $env:GITHUB_OUTPUT -Value "base_version=$baseVersion"
}

Write-Host "Created $archivePath"
Write-Host "SHA256 $archiveHash"
if ($Publish) {
    Write-Host "Published $ReleaseTag"
}
