#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT
cd "$ROOT"

echo "[1/6] Python syntax"
python3 -m py_compile \
  fleet_control/master_control.py \
  scripts/validate_messages.py \
  scripts/generate_rox_order.py \
  scripts/sync_vda_schemas_to_ros.py \
  ros2_ws/src/rox_vda5050_adapter/launch/rox_vda5050_adapter.launch.py \
  ros2_ws/src/rox_vda5050_adapter/rox_vda5050_adapter/*.py

echo "[2/6] Shell syntax"
for script in scripts/*.sh; do bash -n "$script"; done

echo "[3/6] ROS package XML"
python3 - <<'PY'
from pathlib import Path
import xml.etree.ElementTree as ET
for path in Path('ros2_ws/src').glob('*/package.xml'):
    ET.parse(path)
    print(f'valid XML: {path}')
PY

echo "[4/6] Stored official-schema examples"
python3 scripts/validate_messages.py --schema schemas/vda5050_v3/order.schema \
  examples/orders/order_ilmatar_v3.json
python3 scripts/validate_messages.py --schema schemas/vda5050_v3/state.schema \
  examples/states/rox_diff_idle_state.example.json
python3 scripts/validate_messages.py --schema schemas/vda5050_v3/factsheet.schema \
  examples/factsheets/rox_diff_factsheet.template.json

echo "[5/6] Generate and validate a test ROX order"
python3 scripts/generate_rox_order.py \
  --waypoints tests/fixtures/rox_waypoints.test.yaml \
  --route examples/routes/rox_crane_case_study.yaml \
  --output "$TMP/order_rox_diff_v3.json"
python3 scripts/validate_messages.py --schema schemas/vda5050_v3/order.schema \
  "$TMP/order_rox_diff_v3.json"

echo "[6/6] Safety guard: unconfigured coordinates must be rejected"
if python3 scripts/generate_rox_order.py \
  --waypoints configs/rox_waypoints.yaml.example \
  --route examples/routes/rox_crane_case_study.yaml \
  --output "$TMP/should_not_exist.json" >/dev/null 2>&1; then
  echo "ERROR: generator accepted unconfigured coordinates" >&2
  exit 1
fi

if [[ -e legacy/RaspberryPI/accesscode_url.txt ]]; then
  echo "ERROR: legacy/RaspberryPI/accesscode_url.txt contains deployment credentials and must not be distributed" >&2
  exit 1
fi

echo "All static/schema checks passed. ROS build and hardware runtime were not exercised."
