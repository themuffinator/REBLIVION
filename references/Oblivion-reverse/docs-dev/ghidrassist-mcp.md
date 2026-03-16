# GhidrAssistMCP Integration

## Purpose

GhidrAssistMCP provides a live MCP bridge for interactive Ghidra analysis. In Oblivion-reverse, it is optional and supplemental.

Canonical evidence remains:

- retail `gamex86.dll`
- Binary Ninja HLIL under `references/HLIL/oblivion/`
- committed Ghidra corpus under `reference/reverse-engineering/ghidra/gamex86/`

Use GhidrAssistMCP to accelerate exploration, then persist conclusions into committed corpus-backed notes.

## Setup Paths

Bootstrap script:

- `scripts/ghidra/setup_ghidrassist_mcp.ps1`

Default upstream cache location:

- `reference/reverse-engineering/upstream/ghidrassistmcp/`

### Release package download

```powershell
scripts\ghidra\setup_ghidrassist_mcp.ps1 -Mode release
```

Options:

- `-Version <tag>` to pin a release tag instead of `latest`
- `-Force` to re-download an existing zip
- `-DryRun` to preview paths without writing files

After download, install from Ghidra UI:

1. `File -> Install Extensions...`
2. Select the downloaded `*GhidrAssistMCP.zip`
3. Restart Ghidra

### Source install path

```powershell
scripts\ghidra\setup_ghidrassist_mcp.ps1 -Mode source -GhidraHome "C:\Users\djdac\Tools\ghidra_12.0.4_PUBLIC"
```

This clones the tagged source under `reference/reverse-engineering/upstream/ghidrassistmcp/source/<tag>/` and runs:

- `gradlew(.bat) -PGHIDRA_INSTALL_DIR=<GhidraHome> installExtension`

## MCP Server Configuration

Inside Ghidra, configure GhidrAssist and enable MCP server mode.

Default endpoint modes:

- SSE: `http://127.0.0.1:8080/sse`
- Streamable HTTP: `http://127.0.0.1:8080/mcp`

Auth modes supported by GhidrAssistMCP:

- `none`
- `api_key`
- `jwt`

Client-side MCP configuration must match the endpoint and auth settings chosen in GhidrAssist.

## Project Workflow Policy

1. Use GhidrAssistMCP for interactive exploration and hypothesis generation.
2. Re-validate conclusions against committed corpus files and HLIL references.
3. Record confirmed findings in:
   - `docs-dev/reverse-engineering-export-evidence.md`
   - `docs-dev/game-api-mapping-mvp.md`
4. Refresh the committed Ghidra corpus when analysis meaningfully changes:
   - `scripts\ghidra\run_oblivion_reference.ps1 -BinaryPath "C:\q2Clean\oblivion\gamex86.dll"`

Do not treat live MCP output as canonical unless the conclusion is backed by committed corpus evidence.
