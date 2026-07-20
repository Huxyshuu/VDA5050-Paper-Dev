#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
export VDA_SCHEMA_DIR="${VDA_SCHEMA_DIR:-$ROOT/schemas/vda5050_v3}"
export CRANE_FACTSHEET_FILE="${CRANE_FACTSHEET_FILE:-$ROOT/crane_edge/factsheets/ilmatar_crane_factsheet.template.json}"
cd "$ROOT/crane_edge"
PYTHON="$ROOT/.venv-crane/bin/python"
if [[ ! -x "$PYTHON" ]]; then PYTHON=python3; fi
exec "$PYTHON" crane_vda5050_adapter_v3.py
