param(
  [ValidateSet('release', 'source')]
  [string]$Mode = 'release',
  [string]$Version = 'latest',
  [string]$OutputRoot = '.\reference\reverse-engineering\upstream\ghidrassistmcp',
  [string]$GhidraHome = 'C:\Users\djdac\Tools\ghidra_12.0.4_PUBLIC',
  [switch]$Force,
  [switch]$DryRun
)

$ErrorActionPreference = 'Stop'

$repoRoot = (Resolve-Path (Join-Path $PSScriptRoot '..\..')).Path
if ([System.IO.Path]::IsPathRooted($OutputRoot)) {
  $outputAbs = $OutputRoot
} else {
  $outputAbs = Join-Path $repoRoot $OutputRoot
}

New-Item -ItemType Directory -Force -Path $outputAbs | Out-Null
$outputAbs = (Resolve-Path $outputAbs).Path

$apiHeaders = @{
  'User-Agent' = 'Oblivion-Reverse-GhidrAssistMCP-Setup'
  'Accept' = 'application/vnd.github+json'
}

function Get-GhidrAssistRelease {
  param(
    [Parameter(Mandatory = $true)]
    [string]$RequestedVersion
  )

  if ($RequestedVersion -eq 'latest') {
    $api = 'https://api.github.com/repos/symgraph/GhidrAssistMCP/releases/latest'
  } else {
    $api = "https://api.github.com/repos/symgraph/GhidrAssistMCP/releases/tags/$RequestedVersion"
  }

  return Invoke-RestMethod -Uri $api -Headers $apiHeaders
}

function Get-ReleaseZipAsset {
  param(
    [Parameter(Mandatory = $true)]
    $Release
  )

  $asset = $Release.assets |
    Where-Object { $_.name -match 'GhidrAssistMCP\.zip$' } |
    Select-Object -First 1

  if (-not $asset) {
    throw "No GhidrAssistMCP zip asset found in release '$($Release.tag_name)'."
  }

  return $asset
}

function Show-EndpointHint {
  Write-Host ''
  Write-Host 'MCP endpoint defaults:'
  Write-Host '  SSE:             http://127.0.0.1:8080/sse'
  Write-Host '  Streamable HTTP: http://127.0.0.1:8080/mcp'
  Write-Host 'Auth modes: none | api_key | jwt'
}

if ($Mode -eq 'release') {
  $release = Get-GhidrAssistRelease -RequestedVersion $Version
  $asset = Get-ReleaseZipAsset -Release $release
  $releaseDir = Join-Path $outputAbs (Join-Path 'releases' $release.tag_name)
  $zipPath = Join-Path $releaseDir $asset.name

  if ($DryRun) {
    Write-Host "[dry-run] release tag: $($release.tag_name)"
    Write-Host "[dry-run] asset: $($asset.name)"
    Write-Host "[dry-run] destination: $zipPath"
    Show-EndpointHint
    return
  }

  New-Item -ItemType Directory -Force -Path $releaseDir | Out-Null

  if ((Test-Path $zipPath) -and (-not $Force)) {
    Write-Host "Using existing asset: $zipPath"
  } else {
    Write-Host "Downloading $($asset.name) from release $($release.tag_name)..."
    Invoke-WebRequest -Uri $asset.browser_download_url -OutFile $zipPath -Headers $apiHeaders
  }

  Write-Host "Saved: $zipPath"
  Write-Host 'Install the extension in Ghidra via: File -> Install Extensions...'
  Write-Host 'Then enable MCP server in GhidrAssist settings.'
  Show-EndpointHint
  return
}

$release = Get-GhidrAssistRelease -RequestedVersion $Version
$resolvedVersion = $release.tag_name
$sourceRoot = Join-Path $outputAbs 'source'
$repoPath = Join-Path $sourceRoot $resolvedVersion
$ghidraHeadless = Join-Path $GhidraHome 'support\analyzeHeadless.bat'

if ($DryRun) {
  Write-Host "[dry-run] source tag: $resolvedVersion"
  Write-Host "[dry-run] source path: $repoPath"
  Write-Host "[dry-run] ghidra home: $GhidraHome"
  Write-Host '[dry-run] command: gradlew(.bat) -PGHIDRA_INSTALL_DIR=<GhidraHome> installExtension'
  Show-EndpointHint
  return
}

if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
  throw 'git is required for source mode but was not found in PATH.'
}

if (-not (Test-Path $ghidraHeadless)) {
  throw "Ghidra analyzeHeadless not found: $ghidraHeadless"
}

New-Item -ItemType Directory -Force -Path $sourceRoot | Out-Null

if (Test-Path $repoPath) {
  Write-Host "Reusing source tree: $repoPath"
  & git -C $repoPath fetch --tags origin
  & git -C $repoPath checkout --force "tags/$resolvedVersion"
} else {
  Write-Host "Cloning GhidrAssistMCP tag $resolvedVersion..."
  & git clone --branch $resolvedVersion --depth 1 https://github.com/symgraph/GhidrAssistMCP.git $repoPath
}

if ($LASTEXITCODE -ne 0) {
  throw 'git operation failed while preparing source tree.'
}

$gradleWrapper = Join-Path $repoPath 'gradlew.bat'
if (-not (Test-Path $gradleWrapper)) {
  $gradleWrapper = Join-Path $repoPath 'gradlew'
}

if (-not (Test-Path $gradleWrapper)) {
  throw "Gradle wrapper not found in source tree: $repoPath"
}

Write-Host "Running source install against Ghidra home: $GhidraHome"
& $gradleWrapper "-PGHIDRA_INSTALL_DIR=$GhidraHome" installExtension

if ($LASTEXITCODE -ne 0) {
  throw 'Gradle installExtension failed.'
}

Write-Host 'GhidrAssistMCP source install completed.'
Write-Host 'Restart Ghidra, then enable MCP server in GhidrAssist settings.'
Show-EndpointHint
