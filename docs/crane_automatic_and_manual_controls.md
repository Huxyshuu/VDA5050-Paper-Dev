# Crane automatic-mode and manual-control update

## What changed

The crane adapter no longer waits for the Flask `/automatic` button counter.
It reads the real PLC value:

```text
DX_Custom_V.Status.WatchDogFault
```

For this installation:

- `false` = external watchdog healthy and crane automatic/remote mode active;
- `true` = automatic mode unavailable.

The adapter requires `false` continuously for `CRANE_AUTO_STABLE_S` before it
connects to MQTT and announces itself online. A background guard continues to
read the value. If it becomes `true` during movement, the adapter sends STOP,
cancels the current VDA order, and publishes `operatingMode: MANUAL`.

Startup movement is disabled by default:

```text
CRANE_HOME_ON_START=false
```

Use the dashboard Home buttons when the work area is ready. Set the value to
`true` only if you intentionally want the old automatic Z-then-XY homing after
automatic mode is detected.

The old `/automatic` HTTP route remains only as a legacy ROX-Diff
`initializePosition` route. It is no longer used by the crane adapter.

## Dashboard controls

A new **Ilmatar waypoints and hook heights** section provides:

- Source station, ROX handover and home XY destinations;
- Safe travel, source pickup, source clear, handover lower, handover clear and
  home-hook heights;
- Home all, home XY, home hook, pause, resume and cancel controls.

Every movement is published as a VDA 5050 order or instant action. Flask does
not call OPC UA motion methods directly.

For XY destination orders, the controller raises the hook to at least
`travel_safe_m` when the current hook position is below that value. It does not
lower an already-higher hook merely to match the minimum travel height.

## Install

From the extracted package directory:

```bash
python3 apply_crane_controls_update.py \
  ~/VDA5050-Paper-Dev \
  --dry-run
```

Review the output, then apply:

```bash
python3 apply_crane_controls_update.py \
  ~/VDA5050-Paper-Dev
```

The installer is resumable, creates backups under `.repo_update_backups/`, and
does not replace your calibrated `configs/crane_waypoints.yaml` values. It only
adds `travel_safe_m` when it is missing, initially copying the existing
`source_safe_lift_m` value as a conservative starting point that still requires
physical verification.

## Validate after installation

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate

python3 -m py_compile \
  crane_edge/crane.py \
  crane_edge/crane_vda5050_adapter_v3.py \
  fleet_control/master_control.py \
  fleet_control/dashboard_v3.py \
  fleet_control/crane_manual_controls.py \
  scripts/crane_waypoint_tool.py

bash -n scripts/run_crane_adapter.sh
git diff --check
./scripts/run_static_checks.sh
```

Confirm each unique item exists once:

```bash
grep -c 'DX_Custom_V.Status.WatchDogFault' crane_edge/crane.py
grep -c 'def wait_for_crane_automatic_mode' crane_edge/crane_vda5050_adapter_v3.py
grep -c 'def _automatic_mode_guard_task' crane_edge/crane_vda5050_adapter_v3.py
grep -c 'VDA5050_CRANE_MANUAL_CONTROLS_BEGIN' fleet_control/master_control.py
grep -c 'id="craneManualPanel"' fleet_control/templates/index.html
```

The first count can be greater than one because the NodeId also appears in
comments/method descriptions. The other four counts should be exactly `1`.

## Configure and capture crane coordinates

The crane and ROX-Diff use different coordinate systems. ROX-Diff waypoints are
ROS/Nav2 poses in `df_map`; crane waypoints are absolute bridge/trolley values in
metres. They are aligned physically, not numerically.

Keep:

```yaml
configured: false
```

while capturing and testing.

### Capture source bridge/trolley

Move the crane locally to the source station, stop all axes, then run:

```bash
python3 scripts/crane_waypoint_tool.py --update source_station
```

### Capture the ROX handover bridge/trolley

1. Move ROX-Diff to its verified ROS `crane_handover` waypoint.
2. Keep the robot stationary.
3. Align the crane hook over the physical transfer point using approved local
   crane controls.
4. Stop all crane axes.
5. Capture:

```bash
python3 scripts/crane_waypoint_tool.py --update rox_handover
```

### Capture hook heights

At each physically verified height:

```bash
python3 scripts/crane_waypoint_tool.py --update-hoist travel_safe_m
python3 scripts/crane_waypoint_tool.py --update-hoist source_lower_m
python3 scripts/crane_waypoint_tool.py --update-hoist source_safe_lift_m
python3 scripts/crane_waypoint_tool.py --update-hoist handover_lower_m
python3 scripts/crane_waypoint_tool.py --update-hoist handover_safe_lift_m
```

Meaning:

- `travel_safe_m`: minimum height required before standalone XY travel;
- `source_lower_m`: pickup/attachment height at the source;
- `source_safe_lift_m`: source clearance height after pickup;
- `handover_lower_m`: transfer/release height above ROX-Diff;
- `handover_safe_lift_m`: hook-clear height required before ROX-Diff departs.

Capture home:

```bash
python3 scripts/crane_waypoint_tool.py --update home
```

Every capture resets `configured: false`.

## Supervised commissioning with unverified values

The dashboard blocks manual movement while `configured: false`. To test newly
captured values without falsely marking the full configuration verified, set:

```text
CRANE_ALLOW_UNVERIFIED_MANUAL=true
```

in `configs/fleet_control.env`, restart the master controller, and perform
no-load, one-command-at-a-time tests. This override does not bypass automatic
mode, online state, state freshness, active-order, emergency-stop or safety-field
checks.

After every coordinate and height is independently repeatable:

1. Set `CRANE_ALLOW_UNVERIFIED_MANUAL=false`.
2. Set `configured: true` in `configs/crane_waypoints.yaml`.
3. Regenerate the coordinated order:

```bash
python3 scripts/generate_crane_order.py \
  --waypoints configs/crane_waypoints.yaml \
  --output examples/orders/order_ilmatar_v3.json \
  --update-fleet-env configs/fleet_control.env \
  --enable-crane
```

4. Validate:

```bash
python3 scripts/check_crane_rox_integration.py
./scripts/run_static_checks.sh
```

## Start and diagnose automatic mode

Start the master controller, then the crane adapter:

```bash
./scripts/run_master_control.sh
```

```bash
./scripts/run_crane_adapter.sh
```

Expected adapter sequence:

```text
Global watchdog loop started
Preflight: STOP written to OPC UA
Waiting for OPC UA automatic mode
OPC UA WatchDogFault=False -> operating mode AUTOMATIC candidate
Automatic mode confirmed from OPC UA
CRANE_HOME_ON_START=false ... no movement is performed at adapter startup
Connecting MQTT
Published ONLINE connection state
```

Inspect the live dashboard API:

```bash
curl -s http://127.0.0.1:5000/api/crane/manual | python3 -m json.tool
```

Inspect VDA state:

```bash
mosquitto_sub \
  -h 127.0.0.1 \
  -t 'vda5050/v3/konecranes/ilmatar_1/state' \
  -C 1 -v
```

The message should contain:

```json
"operatingMode": "AUTOMATIC"
```

and an `information` entry named `WATCHDOG_FAULT` with value `false`.

If the adapter remains waiting, independently read the OPC UA value using the
included crane interface:

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
python3 - <<'PY'
import os
import sys
from pathlib import Path

root = Path.cwd()
sys.path.insert(0, str(root / "crane_edge"))
from crane import Crane

url = os.environ.get("CRANE_OPCUA_URL")
code = os.environ.get("CRANE_ACCESS_CODE")
if not url or not code:
    lines = [line.strip() for line in (root / "crane_edge/access.txt").read_text().splitlines() if line.strip()]
    url, code = lines[0], lines[1]
crane = Crane(url)
try:
    crane.set_accesscode(int(code))
    print("WatchDogFault:", crane.get_watchdog_fault())
    print("Automatic mode:", crane.is_automatic_mode())
finally:
    crane.disconnect()
PY
```

Do not command crane motion if the value is `true`, if its meaning changes in
PLC logic, or if the work area is not clear. Physical safety systems and local
operating procedures remain authoritative.
