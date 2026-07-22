#!/usr/bin/env bash
set -eo pipefail
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
exec "$PROJECT_ROOT/scripts/rox.sh" visualize "${1:-$PROJECT_ROOT/configs/rox_waypoints.yaml}"
