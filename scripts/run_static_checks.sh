#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"
python3 scripts/project_static_checks.py
python3 scripts/check_watchdog_dashboard_diagnostics.py
