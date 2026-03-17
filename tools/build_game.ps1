param(
    [string]$WorkspaceRoot = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path,
    [string]$Solution = "game.sln",
    [string]$Configuration = "Release",
    [string]$Platform = "x64"
)

$ErrorActionPreference = "Stop"

$workspacePath = (Resolve-Path $WorkspaceRoot).Path
$solutionPath = Join-Path $workspacePath $Solution

if (-not (Test-Path $solutionPath)) {
    throw "Solution not found: $solutionPath"
}

$vswherePath = Join-Path ${env:ProgramFiles(x86)} "Microsoft Visual Studio\Installer\vswhere.exe"
if (-not (Test-Path $vswherePath)) {
    throw "vswhere.exe not found at $vswherePath"
}

$msbuildPath = & $vswherePath `
    -latest `
    -products * `
    -requires Microsoft.Component.MSBuild `
    -find "MSBuild\**\Bin\MSBuild.exe" |
    Select-Object -First 1

if (-not $msbuildPath) {
    throw "MSBuild.exe not found via vswhere."
}

Write-Host "Building $solutionPath with $msbuildPath"

& $msbuildPath `
    $solutionPath `
    /m `
    /t:Build `
    "/p:Configuration=$Configuration" `
    "/p:Platform=$Platform" `
    /nologo

exit $LASTEXITCODE
