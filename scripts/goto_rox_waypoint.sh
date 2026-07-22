#!/usr/bin/env bash
set -eo pipefail
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
name="${1:-}"
if [[ -z "$name" ]]; then
  echo "Usage: ./scripts/goto_rox_waypoint.sh WAYPOINT_NAME [WAYPOINT_FILE]" >&2
  exit 2
fi
exec "$PROJECT_ROOT/scripts/rox.sh" goto "$name" "${2:-$PROJECT_ROOT/configs/rox_waypoints.yaml}"
