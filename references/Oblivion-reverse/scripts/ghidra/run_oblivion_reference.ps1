param(
  [string]$GhidraHome = "C:\Users\djdac\Tools\ghidra_12.0.4_PUBLIC",
  [string]$BinaryPath = "C:\q2Clean\oblivion\gamex86.dll",
  [string]$OutputRoot = ".\reference\reverse-engineering\ghidra",
  [int]$MaxDecompFunctions = 180
)

$ErrorActionPreference = "Stop"

$analyzeHeadless = Join-Path $GhidraHome "support\analyzeHeadless.bat"
if (-not (Test-Path $analyzeHeadless)) {
  throw "Ghidra analyzeHeadless not found: $analyzeHeadless"
}

if (-not (Test-Path $BinaryPath)) {
  throw "Required binary not found: $BinaryPath"
}

$repoRoot = (Resolve-Path (Join-Path $PSScriptRoot "..\..")).Path
if ([System.IO.Path]::IsPathRooted($OutputRoot)) {
  $outputAbs = $OutputRoot
} else {
  $outputAbs = Join-Path $repoRoot $OutputRoot
}

New-Item -ItemType Directory -Force -Path $outputAbs | Out-Null
$outputAbs = (Resolve-Path $outputAbs).Path

$projectRoot = Join-Path $outputAbs "tmp-ghidra-project"
$scriptPath = Join-Path $repoRoot "scripts\ghidra"

New-Item -ItemType Directory -Force -Path $projectRoot | Out-Null

$args = @(
  $projectRoot,
  "OblivionReference",
  "-import", $BinaryPath,
  "-overwrite",
  "-scriptPath", $scriptPath,
  "-postScript", "ExportOblivionReference.java", $outputAbs, "$MaxDecompFunctions",
  "-deleteProject"
)

& $analyzeHeadless @args
if ($LASTEXITCODE -ne 0) {
  throw "Ghidra export failed with exit code $LASTEXITCODE."
}

if (Test-Path $projectRoot) {
  Remove-Item -Recurse -Force $projectRoot
}

$binaryItem = Get-Item $BinaryPath
$md5 = (Get-FileHash $BinaryPath -Algorithm MD5).Hash
$sha256 = (Get-FileHash $BinaryPath -Algorithm SHA256).Hash
$programName = [System.IO.Path]::GetFileNameWithoutExtension($binaryItem.Name).ToLowerInvariant()
$metadataPath = Join-Path (Join-Path $outputAbs $programName) "metadata.txt"

if (-not (Test-Path $metadataPath)) {
  throw "Expected metadata output not found: $metadataPath"
}

Add-Content -Path $metadataPath -Value @(
  "binary_path=$($binaryItem.FullName)",
  "binary_size=$($binaryItem.Length)",
  "binary_last_write_time_utc=$($binaryItem.LastWriteTimeUtc.ToString("o"))",
  "binary_md5=$md5",
  "binary_sha256=$sha256"
)
