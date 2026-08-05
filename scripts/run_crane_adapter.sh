#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"
if [[ ! -f configs/fleet_control.env ]]; then
  echo "Missing configs/fleet_control.env" >&2
  exit 1
fi
set -a
# shellcheck disable=SC1091
source configs/fleet_control.env
set +a
case "${CRANE_ENABLED:-false}" in
  1|true|TRUE|yes|YES|on|ON) ;;
  *) echo "CRANE_ENABLED is not true. Verify crane waypoints and generate the crane order with --enable-crane first." >&2; exit 1 ;;
esac
: "${CRANE_MAP_ID:=map}"
: "${BUTTON_STATUS_URL:=http://${VDA_MQTT_HOST:-192.168.50.115}:5000/status}"
export CRANE_MAP_ID BUTTON_STATUS_URL
exec python3 crane_edge/crane_vda5050_adapter_v3.py
