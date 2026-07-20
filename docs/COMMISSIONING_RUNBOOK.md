# VDA 5050 v3 ROX-Diff–Crane Commissioning Runbook

**Project root used in this guide:** `~/VDA5050-Paper-Dev`  
**Raspberry Pi / MQTT example address:** `192.168.1.115`  
**Protocol identity:** VDA 5050 `3.0.0`

This runbook starts with the Neobotix ROX-Diff alone, then the Raspberry Pi master, then the crane, and only then the coordinated no-load handover. Do not skip directly to combined movement.

## Safety boundary

The MQTT/Flask/VDA software is not safety-rated. The ROX safety controller, scanners, emergency stops, motor controller, crane PLC, crane emergency stop and local operating procedures remain authoritative. Keep the work area clear, use reduced commissioning speeds, keep emergency stops reachable, and test without a payload before any loaded test.

---

# Part A — Prepare the Raspberry Pi master

## A1. Put the project on the Pi

Using Git:

```bash
cd ~
git clone https://github.com/Huxyshuu/VDA5050-Paper-Dev.git
cd ~/VDA5050-Paper-Dev
```

Or copy the supplied updated ZIP to the Pi and extract it:

```bash
cd ~
unzip VDA5050-Paper-Dev-updated.zip
mv VDA5050-Paper-Dev-updated VDA5050-Paper-Dev
cd ~/VDA5050-Paper-Dev
```

Confirm the expected files:

```bash
pwd
ls README.md fleet_control/master_control.py scripts/run_master_control.sh
```

## A2. Install the broker and basic tools

```bash
sudo apt update
sudo apt install -y \
  mosquitto mosquitto-clients \
  python3 python3-venv python3-pip \
  netcat-openbsd curl unzip git
sudo systemctl enable --now mosquitto
```

## A3. Create the Python environment

```bash
cd ~/VDA5050-Paper-Dev
python3 -m venv .venv
source .venv/bin/activate
python -m pip install --upgrade pip
python -m pip install -r fleet_control/requirements.txt
```

## A4. Configure the Pi master

```bash
cd ~/VDA5050-Paper-Dev
cp -n configs/fleet_control.env.example configs/fleet_control.env
nano configs/fleet_control.env
```

Fill or verify at least:

```text
VDA_MQTT_HOST=192.168.1.115
VDA_MQTT_PORT=1883
VDA_DEFAULT_MAP_ID=warehouse_case_study
CRANE_TOPIC_ROOT=vda5050/v3/konecranes/ilmatar_1
ROX_TOPIC_ROOT=vda5050/v3/neobotix/rox_diff_1
CRANE_AUTO_RELEASE_ACTION_ID=action4
CRANE_MANUAL_RELEASE_ACTION_ID=action6
CRANE_SAFE_LIFT_ACTION_ID=action7
ROX_HOLD_ACTION_ID=rox_hold_at_crane
```

Do not fill `ROX_INIT_X`, `ROX_INIT_Y` or `ROX_INIT_THETA` with DBot values. The order generator fills them after real ROX waypoints have been captured.

## A5. Permit MQTT access on the isolated lab network

Inspect the supplied broker example:

```bash
cat deploy/mosquitto/vda5050-lab.conf.example
```

Install it only on a trusted, isolated commissioning network:

```bash
sudo cp deploy/mosquitto/vda5050-lab.conf.example \
  /etc/mosquitto/conf.d/vda5050-lab.conf
sudo systemctl restart mosquitto
sudo systemctl status mosquitto --no-pager
ss -ltnp | grep 1883
```

Anonymous unencrypted MQTT must not be exposed to a general company, campus or Internet-facing network. Add authentication and TLS before production deployment.

## A6. Run repository checks

```bash
cd ~/VDA5050-Paper-Dev
./scripts/run_static_checks.sh
```

All checks should end in `PASS`. These checks validate source syntax, schemas and generated test messages; they do not test ROS, Nav2, the PLC or physical hardware.

## A7. Start the master manually

Terminal Pi-1:

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
./scripts/run_master_control.sh
```

Terminal Pi-2, inspect the runtime:

```bash
curl http://127.0.0.1:5000/runtime | python3 -m json.tool
```

Terminal Pi-3, monitor all VDA traffic:

```bash
mosquitto_sub -h 127.0.0.1 -t 'vda5050/v3/#' -v
```

From another computer, open:

```text
http://192.168.1.115:5000
```

At this stage the master may report that the generated ROX order is missing. That is expected until Part D.

---

# Part B — Prepare the Neobotix ROX-Diff

## B1. Copy or clone the project on the robot computer

```bash
cd ~
git clone https://github.com/Huxyshuu/VDA5050-Paper-Dev.git
cd ~/VDA5050-Paper-Dev
```

For the supplied updated ZIP, copy and extract it instead, then make the directory name `~/VDA5050-Paper-Dev`.

## B2. Identify the installed ROS and Neobotix workspace

```bash
printenv ROS_DISTRO
ls /opt/ros
find ~ -maxdepth 3 -path '*/install/setup.bash' -print
```

The helper scripts assume:

```text
ROS_DISTRO=humble
NEOBOTIX_WS=$HOME/ros2_workspace
```

Set different values if your delivered robot differs:

```bash
export ROS_DISTRO=<installed_ros_distribution>
export NEOBOTIX_WS=<path_to_neobotix_workspace>
```

Example:

```bash
export ROS_DISTRO=humble
export NEOBOTIX_WS=$HOME/ros2_workspace
```

## B3. Verify the native Neobotix packages before building this project

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
source "$NEOBOTIX_WS/install/setup.bash"
ros2 pkg prefix rox_bringup
ros2 pkg prefix rox_navigation
```

List the exact launch files installed on this robot:

```bash
find "$(ros2 pkg prefix rox_bringup)/share/rox_bringup/launch" \
  -maxdepth 1 -type f -name '*.launch.py' -printf '%f\n' | sort
find "$(ros2 pkg prefix rox_navigation)/share/rox_navigation/launch" \
  -maxdepth 1 -type f -name '*.launch.py' -printf '%f\n' | sort
```

Use the actual filenames printed by these commands. Verify launch arguments before starting the robot:

```bash
ros2 launch rox_navigation navigation.launch.py --show-arguments
```

For the native bringup file, substitute the filename shown by the first `find` command:

```bash
ros2 launch rox_bringup <ACTUAL_BRINGUP_FILE>.launch.py --show-arguments
```

Record the correct values in `docs/SITE_CONFIGURATION_CHECKLIST.md`.

## B4. Build this repository as a separate overlay

Do not copy the adapter into or overwrite Neobotix packages.

```bash
cd ~/VDA5050-Paper-Dev
export ROS_DISTRO=${ROS_DISTRO:-humble}
export NEOBOTIX_WS=${NEOBOTIX_WS:-$HOME/ros2_workspace}
./scripts/build_rox_overlay.sh
```

In every new ROX terminal, source in this order:

```bash
export ROS_DISTRO=${ROS_DISTRO:-humble}
export NEOBOTIX_WS=${NEOBOTIX_WS:-$HOME/ros2_workspace}
source /opt/ros/$ROS_DISTRO/setup.bash
source "$NEOBOTIX_WS/install/setup.bash"
source ~/VDA5050-Paper-Dev/ros2_ws/install/setup.bash
```

Confirm the adapter is visible:

```bash
ros2 pkg prefix rox_vda5050_adapter
ros2 pkg executables rox_vda5050_adapter
```

## B5. Verify Pi network and MQTT from ROX

```bash
ping -c 3 192.168.1.115
nc -vz 192.168.1.115 1883
```

Install MQTT client tools if needed:

```bash
sudo apt update
sudo apt install -y mosquitto-clients netcat-openbsd
```

Run the supplied check:

```bash
cd ~/VDA5050-Paper-Dev
./scripts/check_pi_mqtt_from_rox.sh 192.168.1.115 1883
```

On the Pi, confirm that the message arrives:

```bash
mosquitto_sub -h 127.0.0.1 \
  -t 'vda5050/v3/commissioning/ping' -C 1 -v
```

## B6. Start and verify native ROX only

Terminal ROX-1:

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
source "$NEOBOTIX_WS/install/setup.bash"
ros2 launch rox_bringup <ACTUAL_BRINGUP_FILE>.launch.py \
  rox_type:=diff \
  <OTHER_VERIFIED_ARGUMENTS>
```

Do not copy the example arguments blindly. Use `--show-arguments` and the delivered robot configuration to determine scanner, frame and namespace settings.

Terminal ROX-2:

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
source "$NEOBOTIX_WS/install/setup.bash"
cd ~/VDA5050-Paper-Dev
./scripts/check_rox_ros_interfaces.sh
```

Also inspect the actual topics and message types:

```bash
ros2 topic list | sort
ros2 topic echo /odom --once
ros2 topic echo /scan --once
ros2 topic type /battery_state
ros2 topic type /emergency_stop_state
ros2 topic type /safety_state
ros2 interface show neo_msgs2/msg/EmergencyStopState
ros2 interface show neo_msgs2/msg/SafetyState
ros2 run tf2_ros tf2_echo odom base_link
```

Do not continue until teleoperation, odometry, TF, lidar data, scanner fields and emergency-stop behavior are correct without the VDA adapter.

---

# Part C — Create the ROX map and verify Nav2

## C1. Discover the installed mapping launch command

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
source "$NEOBOTIX_WS/install/setup.bash"
find "$(ros2 pkg prefix rox_navigation)/share/rox_navigation/launch" \
  -maxdepth 1 -type f -iname '*map*.launch.py' -printf '%f\n' | sort
```

For every candidate printed, inspect its arguments:

```bash
ros2 launch rox_navigation <ACTUAL_MAPPING_FILE>.launch.py --show-arguments
```

The exact mapping launch filename is a delivered-software detail. Do not guess it from the old DBot project.

## C2. Start mapping

Keep native ROX bringup running in ROX-1.

Terminal ROX-2:

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
source "$NEOBOTIX_WS/install/setup.bash"
mkdir -p "$HOME/maps"
ros2 launch rox_navigation <ACTUAL_MAPPING_FILE>.launch.py \
  rox_type:=diff \
  <OTHER_VERIFIED_ARGUMENTS>
```

If no Neobotix mapping launch is installed, use the mapping method supported by the delivered workspace, commonly `slam_toolbox`, after verifying the lidar topic and parameters. Do not replace the Neobotix navigation configuration without reviewing it.

Drive slowly through the complete case-study area. Include the home area, short test target, crane approach, handover area, drop-off area and enough stable walls/features for localization.

## C3. Save the map

```bash
ros2 run nav2_map_server map_saver_cli \
  -f "$HOME/maps/warehouse_case_study"
ls -l "$HOME/maps/warehouse_case_study.yaml" \
      "$HOME/maps/warehouse_case_study.pgm"
```

Back up both files together.

## C4. Start localization and navigation

Stop the mapping launch. Keep native bringup running.

Terminal ROX-2:

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
source "$NEOBOTIX_WS/install/setup.bash"
ros2 launch rox_navigation navigation.launch.py \
  rox_type:=diff \
  frame_type:=short \
  use_amcl:=true \
  map:="$HOME/maps/warehouse_case_study.yaml"
```

Change `frame_type` or other arguments only to values confirmed for the delivered robot. The official package exposes the accepted arguments through `--show-arguments`.

## C5. Verify Nav2 before VDA

```bash
ros2 action list -t | grep -E 'navigate_to_pose|NavigateToPose'
ros2 run tf2_ros tf2_echo map base_link
```

In RViz:

1. Set the initial pose.
2. Confirm lidar overlays the map.
3. Confirm global and local costmaps.
4. Send at least three normal Nav2 goals.
5. Repeat the crane approach from different directions.
6. Confirm position and orientation repeatability.
7. Confirm the robot can stop and depart without violating scanner fields.

The VDA adapter must not be used to compensate for a poor map, incorrect TF, wrong footprint, unstable localization or untuned Nav2 controller.

---

# Part D — Capture waypoints and generate the VDA order

## D1. Create the site waypoint file on ROX

```bash
cd ~/VDA5050-Paper-Dev
cp -n configs/rox_waypoints.yaml.example configs/rox_waypoints.yaml
```

Keep `configured: false` until all poses have been captured and individually tested.

## D2. Capture each pose

Source the project overlay in the terminal used for capture:

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
source "$NEOBOTIX_WS/install/setup.bash"
source ~/VDA5050-Paper-Dev/ros2_ws/install/setup.bash
cd ~/VDA5050-Paper-Dev
```

At each physical pose, wait for localization to settle and run the corresponding command:

```bash
ros2 run rox_vda5050_adapter capture_waypoint \
  --name home \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study
```

```bash
ros2 run rox_vda5050_adapter capture_waypoint \
  --name short_test \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study
```

```bash
ros2 run rox_vda5050_adapter capture_waypoint \
  --name crane_handover \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study
```

```bash
ros2 run rox_vda5050_adapter capture_waypoint \
  --name warehouse_dropoff \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study
```

Review the file:

```bash
cat configs/rox_waypoints.yaml
```

## D3. Verify every captured pose with normal Nav2

For each waypoint, move away and return using RViz/Nav2 several times. Verify:

- the robot center and full footprint;
- payload clearance;
- final yaw;
- scanner fields;
- crane reach and hook/load alignment;
- departure path;
- practical position/orientation tolerances.

Then edit:

```bash
nano configs/rox_waypoints.yaml
```

Set:

```yaml
configured: true
```

Do not set this flag merely to bypass the generator check.

## D4. Copy the waypoint file to the Pi

From ROX:

```bash
scp ~/VDA5050-Paper-Dev/configs/rox_waypoints.yaml \
  <PI_USER>@192.168.1.115:/home/<PI_USER>/VDA5050-Paper-Dev/configs/
```

Replace `<PI_USER>` with the real Pi username.

## D5. Generate the short test order on the Pi

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
python3 scripts/generate_rox_order.py \
  --waypoints configs/rox_waypoints.yaml \
  --route examples/routes/rox_short_motion_test.yaml \
  --output examples/orders/order_rox_diff_v3.json \
  --update-fleet-env configs/fleet_control.env
./scripts/run_static_checks.sh
```

Inspect the generated order and initial pose:

```bash
python3 -m json.tool examples/orders/order_rox_diff_v3.json | less
grep '^ROX_INIT_' configs/fleet_control.env
```

Restart the Pi master so it reloads the order and environment:

```bash
# In the master terminal: Ctrl+C
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
./scripts/run_master_control.sh
```

---

# Part E — Test the ROX adapter without robot movement

## E1. Keep native bringup and Nav2 running

Use the native commands verified in Parts B and C.

## E2. Start the VDA adapter in dry-run mode

Terminal ROX-3:

```bash
cd ~/VDA5050-Paper-Dev
export ROS_DISTRO=${ROS_DISTRO:-humble}
export NEOBOTIX_WS=${NEOBOTIX_WS:-$HOME/ros2_workspace}
export VDA_MQTT_HOST=192.168.1.115
export VDA_MAP_ID=warehouse_case_study
./scripts/run_rox_adapter_dry.sh
```

Expected first observations on the Pi MQTT monitor:

```text
.../connection  ONLINE
.../factsheet   retained factsheet template
.../state       periodic v3 state
```

## E3. Request the factsheet and send the ROX order

On the Pi:

```bash
curl -X POST http://127.0.0.1:5000/factsheet/rox
curl -X POST http://127.0.0.1:5000/order/rox
curl http://127.0.0.1:5000/runtime | python3 -m json.tool
```

The dry run must progress through simulated nodes and stop with the configured `holdPose` action running. Release it:

```bash
curl -X POST http://127.0.0.1:5000/release_hold
```

Test instant actions individually:

```bash
curl -X POST http://127.0.0.1:5000/pause/rox
curl -X POST http://127.0.0.1:5000/resume/rox
curl -X POST http://127.0.0.1:5000/cancel/rox
curl -X POST http://127.0.0.1:5000/automatic
```

Acceptance criteria:

- no schema errors;
- correct manufacturer, serial number and version;
- order accepted only when identity, map and sequence are valid;
- `holdPose` remains active until released;
- pause/resume/cancel action states reach a terminal state;
- `initializePosition` uses ROS frame `map` and the configured logical `mapId`;
- no physical motion occurs.

---

# Part F — First real ROX motion

## F1. Stop the dry-run adapter

Press `Ctrl+C` in ROX-3.

## F2. Confirm the short order is active

On the Pi:

```bash
grep '^ROX_ORDER_JSON_PATH=' configs/fleet_control.env
python3 -m json.tool examples/orders/order_rox_diff_v3.json | head -80
```

The route should be the two-node commissioning route using `home` and `short_test`.

## F3. Position and localize ROX at `home`

Use RViz and the native robot tools. Confirm that `map -> base_link` is within the waypoint tolerance. The adapter intentionally rejects a real order if the robot is not near the first node.

## F4. Start real navigation mode

Terminal ROX-3:

```bash
cd ~/VDA5050-Paper-Dev
export ROS_DISTRO=${ROS_DISTRO:-humble}
export NEOBOTIX_WS=${NEOBOTIX_WS:-$HOME/ros2_workspace}
export VDA_MQTT_HOST=192.168.1.115
export VDA_MAP_ID=warehouse_case_study
./scripts/run_rox_adapter_real.sh
```

## F5. Send only the ROX order

On the Pi:

```bash
curl -X POST http://127.0.0.1:5000/order/rox
```

Observe the robot, Nav2 logs, adapter logs, MQTT state and physical safety system. Release the short-route hold only after arrival is verified:

```bash
curl -X POST http://127.0.0.1:5000/release_hold
```

Acceptance criteria:

- exactly one Nav2 goal is issued for the destination;
- the robot reaches the correct position and yaw;
- the state removes traversed nodes/edges correctly;
- the action state changes match the physical event;
- cancellation does not cause a delayed goal to start later;
- scanner and emergency-stop interventions remain authoritative.

## F6. Generate and test the full ROX-only route

On the Pi:

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
python3 scripts/generate_rox_order.py \
  --waypoints configs/rox_waypoints.yaml \
  --route examples/routes/rox_crane_case_study.yaml \
  --output examples/orders/order_rox_diff_v3.json \
  --update-fleet-env configs/fleet_control.env
./scripts/run_static_checks.sh
```

Restart the master and test:

```bash
curl -X POST http://127.0.0.1:5000/order/rox
```

Run the route with the crane powered down or otherwise prevented from moving. Manually release the ROX handover hold after checking alignment.

---

# Part G — Configure and test the crane adapter

## G1. Install crane Python dependencies on its runtime device

If the crane adapter runs on the Pi:

```bash
cd ~/VDA5050-Paper-Dev
python3 -m venv .venv-crane
source .venv-crane/bin/activate
python -m pip install --upgrade pip
python -m pip install -r crane_edge/requirements.txt
```

## G2. Configure credentials without committing them

Preferred environment variables:

```bash
export CRANE_OPCUA_URL='<REAL_OPCUA_URL>'
export CRANE_ACCESS_CODE='<REAL_NUMERIC_ACCESS_CODE>'
```

Or create the ignored local file:

```bash
cd ~/VDA5050-Paper-Dev/crane_edge
cp access.txt.example access.txt
chmod 600 access.txt
nano access.txt
```

The file format is:

```text
<OPC_UA_URL>
<NUMERIC_ACCESS_CODE>
```

Never commit or distribute `access.txt`.

## G3. Verify the crane factsheet template

```bash
nano ~/VDA5050-Paper-Dev/crane_edge/factsheets/ilmatar_crane_factsheet.template.json
```

Replace zero/placeholder physical values only with verified values from the actual crane and implementation. Keep the identity aligned with:

```text
manufacturer=konecranes
serialNumber=ilmatar_1
version=3.0.0
```

Validate after editing:

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
python3 scripts/validate_messages.py \
  --schema-dir schemas/vda5050_v3 \
  factsheet crane_edge/factsheets/ilmatar_crane_factsheet.template.json
```

## G4. Start the crane adapter fail-closed

The crane must be in the approved automatic state and homing/preflight must succeed. Do not set the override for normal operation.

```bash
cd ~/VDA5050-Paper-Dev
export VDA_MQTT_HOST=192.168.1.115
export ALLOW_UNHOMED_START=false
./scripts/run_crane_adapter.sh
```

If the adapter exits because automatic mode or homing is not valid, correct the physical/control state. `ALLOW_UNHOMED_START=true` is for supervised telemetry diagnosis only and must not be used for motion commissioning.

## G5. Test the crane alone

On the Pi master terminal host:

```bash
curl -X POST http://127.0.0.1:5000/factsheet/crane
curl -X POST http://127.0.0.1:5000/order/crane
```

Verify exact action IDs from `examples/orders/order_ilmatar_v3.json`:

```bash
python3 - <<'PY'
import json
p=json.load(open('examples/orders/order_ilmatar_v3.json'))
for n in p['nodes']:
    for a in n.get('actions', []):
        print(n['nodeId'], a['actionId'], a['actionType'])
PY
```

Acceptance criteria:

- wrong participant identity, map or order update is rejected;
- a second order is rejected while one is active;
- unsupported edge actions are rejected;
- node and edge state lists clear as traversal completes;
- action states correspond to real PLC/crane events;
- factsheet is retained and returned on request;
- free-text `information[]` is display-only and never controls release logic.

---

# Part H — Coordinated ROX–crane no-load test

Run this only after the full ROX-only route and crane-only order both pass.

## H1. Confirm orchestration IDs

On the Pi:

```bash
curl http://127.0.0.1:5000/runtime | python3 -m json.tool
```

Confirm:

```text
CRANE_AUTO_RELEASE_ACTION_ID = action4
CRANE_MANUAL_RELEASE_ACTION_ID = action6
CRANE_SAFE_LIFT_ACTION_ID = action7
ROX_HOLD_ACTION_ID = rox_hold_at_crane
```

These values must match the actual crane order and generated ROX route.

## H2. Start all components

1. Pi Mosquitto.
2. Pi master control.
3. Native ROX bringup.
4. ROX Nav2/localization.
5. ROX VDA adapter in real mode.
6. Crane VDA adapter in fail-closed mode.
7. MQTT monitor.

## H3. Send the combined order

On the Pi:

```bash
curl -X POST http://127.0.0.1:5000/order
```

Expected handover logic:

1. ROX reaches `node2` and its exact `rox_hold_at_crane` action is active.
2. The master only associates the configured crane action IDs with that rendezvous.
3. Automatic release uses only `action4` when the configured conditions are met.
4. Manual `/release` arms only the configured `action6` path and expires after the configured TTL.
5. ROX remains held until the exact crane safe-lift milestone `action7` finishes.
6. A failed `action7` does not release the ROX.
7. Crane hoist telemetry in `information[]` may be displayed but is not a release condition.

Manual release command, only when the local procedure permits it:

```bash
curl -X POST http://127.0.0.1:5000/release
```

Emergency or abnormal behavior must be handled through the physical safety controls first. Software cancellation is secondary:

```bash
curl -X POST http://127.0.0.1:5000/cancel/rox
curl -X POST http://127.0.0.1:5000/cancel/crane
```

Repeat the coordinated test without load until action/state sequencing, alignment and departure are consistently correct. Record logs before considering a supervised loaded test.

---

# Part I — Optional systemd services after manual tests pass

## I1. Pi master service

```bash
sudo cp ~/VDA5050-Paper-Dev/deploy/systemd/vda5050-master.service.example \
  /etc/systemd/system/vda5050-master.service
sudo nano /etc/systemd/system/vda5050-master.service
sudo systemctl daemon-reload
sudo systemctl enable --now vda5050-master.service
sudo systemctl status vda5050-master.service --no-pager
journalctl -u vda5050-master.service -f
```

Edit the service username and paths to match the real Pi account before enabling it.

## I2. ROX dry-run service first

```bash
sudo cp ~/VDA5050-Paper-Dev/deploy/systemd/rox-vda5050-adapter-dry.service.example \
  /etc/systemd/system/rox-vda5050-adapter.service
sudo nano /etc/systemd/system/rox-vda5050-adapter.service
sudo systemctl daemon-reload
sudo systemctl enable --now rox-vda5050-adapter.service
sudo systemctl status rox-vda5050-adapter.service --no-pager
journalctl -u rox-vda5050-adapter.service -f
```

Use the real-mode service template only after all manual dry-run and real short-route checks pass.

---

# Part J — Fast troubleshooting

## Master says schema or order file is missing

```bash
cd ~/VDA5050-Paper-Dev
ls schemas/vda5050_v3/order.schema
ls examples/orders/order_ilmatar_v3.json
ls examples/orders/order_rox_diff_v3.json
./scripts/run_static_checks.sh
```

The ROX order is intentionally generated after waypoint capture.

## ROX cannot connect to MQTT

```bash
ping -c 3 192.168.1.115
nc -vz 192.168.1.115 1883
mosquitto_pub -h 192.168.1.115 \
  -t vda5050/v3/commissioning/ping -m test
```

On Pi:

```bash
sudo journalctl -u mosquitto -n 100 --no-pager
ss -ltnp | grep 1883
```

## Adapter cannot find Nav2

```bash
ros2 action list -t | grep navigate_to_pose
ros2 node list
ros2 lifecycle nodes
```

Start native `rox_navigation` and confirm it is active before the adapter.

## Order is rejected at the first node

```bash
ros2 run tf2_ros tf2_echo map base_link
cat ~/VDA5050-Paper-Dev/configs/rox_waypoints.yaml
```

Physically/localize the robot at the captured first node or regenerate the route with the correct `home`. Do not increase tolerance merely to hide localization or mapping errors.

## `initializePosition` does not visibly move the robot

That action initializes localization; it is not a movement command. Verify `/initialpose`, AMCL/localization and RViz. Then send a normal Nav2 or VDA order.

## Crane adapter exits during startup

Check automatic mode, homing/preflight, OPC UA URL/access code and PLC connectivity. Do not bypass a failed preflight for motion.

## An action is stuck

Inspect exact action IDs and statuses:

```bash
curl http://127.0.0.1:5000/runtime | python3 -m json.tool
mosquitto_sub -h 127.0.0.1 -t 'vda5050/v3/#' -v
```

Use `cancelOrder`, `retry` or `skipRetry` only where the adapter reports the corresponding supported state and the physical process permits it.
