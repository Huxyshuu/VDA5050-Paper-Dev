# VDA 5050 v3.0 ROX-Diff–Crane Case Study

This repository is a migration of the earlier DBot/TurtleBot AMR–overhead-crane demonstrator to a **Neobotix ROX-Diff**, while retaining the Raspberry Pi master control and Ilmatar crane integration.

The active architecture is now:

- **VDA 5050 v3.0 MQTT/JSON** between fleet control and equipment adapters;
- **Raspberry Pi** for Mosquitto, the Flask master control, and normally the crane adapter;
- **Neobotix ROX-Diff onboard computer** for native Neobotix ROS 2, Nav2, and the new VDA adapter;
- **OPC UA / PLC** for the Ilmatar crane;
- newly captured ROX map poses instead of the invalid DBot coordinates.

The old DBot source remains under `legacy/` for traceability only. It is not part of the active build or deployment.

## Start here

- [ROX command reference](docs/ROX_COMMANDS.md) — one-command entry point for Nav2, RViz markers, capture, exact waypoint goals and adapter operation.
- [Remote operator workstation](docs/REMOTE_OPERATOR_WORKSTATION.md) — run the same `rox` commands from Ubuntu laptops with local Neobotix RViz.
- [Automatic pose persistence](docs/POSE_PERSISTENCE.md) — restore the last validated AMCL estimate and remove routine manual 2D pose setup.
- [Complete commissioning runbook](docs/COMMISSIONING_RUNBOOK.md) — exact Pi, ROX, mapping, order-generation, crane and coordinated-test sequence.
- [Current DTLabOpen network](docs/NETWORK_CONFIGURATION.md) — direct Pi/ROX addressing and route checks.
- [Site configuration checklist](docs/SITE_CONFIGURATION_CHECKLIST.md) — values that must be measured or discovered on the real equipment.
- [Repository audit](docs/REPOSITORY_AUDIT_2026-07-20.md) — defects corrected, deferred work and verification limits.

---

## 1. Migration status

### Implemented in this update

- Replaced the active `dbot` target in the master with `rox`.
- Added a direct **VDA 5050 v3.0 MQTT-to-Nav2 ROS 2 adapter** for ROX-Diff.
- Added an installable ROS package containing the official VDA 5050 v3.0 schemas.
- Removed old DBot coordinates and order templates from the active runtime path.
- Added a safe waypoint-capture and order-generation workflow.
- Added an RViz waypoint visualizer and an exact named-waypoint Nav2 goal sender with final TF tolerance checks.
- Added `scripts/rox.sh` as the central ROX commissioning command interface.
- Added disk-backed Nav2 pose persistence with automatic AMCL `/initialpose` restoration, map fingerprint validation and same-boot odometry movement checks.
- Added a short two-node commissioning route and a full crane case-study route.
- Added official-schema validation for stored orders, states, factsheets, generated ROX orders, and live adapter traffic.
- Added master endpoints for independent crane/ROX order tests, pause, resume, cancellation, factsheet requests, initialization, and custom instant actions.
- Added initial `retry` and `skipRetry` handling for the currently blocked node action.
- Added retained VDA connection messages and MQTT last-will handling on the ROX adapter.
- Added dynamic subscriptions to ROX odometry, battery, emergency-stop, and safety-state topics.
- Added dry-run navigation and made it the safe default.
- Added network/interface/static-check scripts and deployment examples.
- Removed a crane access-code file from the distributable source and replaced it with examples.

### Still requires the real ROX-Diff and lab environment

- Preserve and verify the delivered boot-time bringup configuration after software updates.
- Back up and version the commissioned `df_map.yaml`/`.pgm` pair outside the generated `install/` tree.
- Tune localization, footprint, costmaps, controller, and speed limits.
- Recheck the committed `home`, `short_test`, `crane_handover`, and `warehouse_dropoff` poses on the current `df_map`.
- Keep `configured: false` until repeated exact-goal and physical alignment tests pass, then regenerate the active ROX order.
- Verify battery and safety-state mapping on the delivered robot.
- Fill and verify the ROX factsheet physical/capability values.
- Build the ROS overlay on the ROX onboard computer.
- Run dry-run, short-motion, full-route, and coordinated no-load tests.
- Add order-update/base-horizon support, edge actions, zones, responses, interactive marker editing, and planned-path reporting after the first physical handover is stable.

See [MIGRATION_UPDATE.md](MIGRATION_UPDATE.md) for the full file-by-file change report.

---

## 2. Runtime architecture and deployment separation

```text
Raspberry Pi
├── eth0 / DTLabOpen: 192.168.50.115
├── Wi-Fi / Ilmatar: 192.168.0.116
├── Mosquitto MQTT broker :1883
├── fleet_control/master_control.py :5000
└── crane_edge/crane_vda5050_adapter_v3.py
      └── OPC UA / PLC -> Ilmatar overhead crane

                         VDA 5050 v3.0 MQTT
                                  |
                                  v
ROX-Diff onboard computer
├── DTLabOpen: 192.168.50.50
├── Neobotix rox_bringup
├── Neobotix rox_navigation / Nav2
└── rox_vda5050_adapter
      ├── VDA order nodes -> Nav2 NavigateToPose
      ├── instantActions -> pause/resume/cancel/init/hold/trigger/retry
      └── TF + odom + battery + safety -> VDA state
```

The Raspberry Pi does **not** need ROS 2. The Pi and ROX are direct peers on DTLabOpen (`192.168.50.115` and `192.168.50.50`) and communicate with the Pi-hosted MQTT broker without NAT or port forwarding. The Pi also retains its separate Ilmatar Wi-Fi address `192.168.0.116`. Hardware bringup, localization, Nav2 and safety-critical execution remain on the robot. ROS 2 visualization and command clients may run on configured operator computers over DDS. The crane remains locally controlled by its PLC/safety system through the crane adapter.

Suggested topic roots:

```text
vda5050/v3/konecranes/ilmatar_1/{order,instantActions,state,connection,factsheet}
vda5050/v3/neobotix/rox_diff_1/{order,instantActions,state,connection,factsheet}
```

---

## 3. Repository layout

```text
configs/
  fleet_control.env.example         Pi master and participant identities
  fleet_control.env                 current lab configuration
  rox_waypoints.yaml.example        safe, unconfigured coordinate template

crane_edge/
  crane.py                          low-level Ilmatar OPC UA wrapper
  crane_vda5050_adapter_v3.py       crane VDA 5050 v3 adapter
  access.txt.example                credential placeholder only

deploy/
  mosquitto/                        lab broker configuration example
  systemd/                          optional Pi/ROX service examples

docs/
  architecture.md                   deployment and data flow
  deployment.md                     Pi and robot installation
  ROX_COMMANDS.md                   daily ROX command reference
  waypoint_visualizer.md             RViz markers and exact Nav2 waypoint goals
  rox_diff_mapping_and_orders.md    new map/coordinates/order procedure
  raspberry_pi_rox_test_plan.md     staged commissioning plan
  vda5050_v2_to_v3_migration.md     protocol/software migration notes

examples/
  factsheets/                       ROX factsheet template
  orders/                           crane order and generated ROX order location
  routes/                           logical routes independent of coordinates
  states/                           schema-valid example ROX state

fleet_control/
  master_control.py                 Pi-hosted Flask/MQTT master
  requirements.txt                  Pi Python dependencies
  templates/                        existing master-control UI

ros2_ws/src/
  rox_vda5050_adapter/              new ROX-Diff MQTT/Nav2 adapter
  vda5050_schemas_v3/               official schemas installed as ROS data

schemas/vda5050_v3/                 official VDA 5050 v3.0 JSON schemas
scripts/                            validation, generation, network and launch helpers
tests/fixtures/                     non-hardware test data
legacy/                             old DBot project; reference only
results/                            logs, figures and tables for the case study
```

---

## 4. Important design changes from DBot to ROX-Diff

The old robot side is not simply renamed. It is replaced at the correct architectural boundary.

| Old DBot component | ROX-Diff migration decision |
|---|---|
| Custom DBot motor/CAN drivers | Removed from active system; Neobotix drivers remain authoritative |
| DBot URDF and TF publishers | Removed; use ROX description and TF tree |
| DBot odometry model | Removed; use ROX `/odom` |
| DBot SLAM/Nav2 configuration | Removed; use and tune `rox_navigation` |
| Old DBot map and XY coordinates | Invalid; create a new map and capture new poses |
| Old VDA v2 ROS connector/messages/controller | Replaced with direct official v3 MQTT JSON adapter |
| TurtleBot-specific adapter | Replaced with `rox_vda5050_adapter` |
| DBot MQTT identity | Replaced with `neobotix / rox_diff_1` |
| Hard-coded DBot order | Replaced with generated order from named ROX waypoints |

The new adapter intentionally does not recreate the old DBot hardware stack. It lets the official Neobotix software handle robot motion, localization and safety interfaces, and only translates between VDA 5050 and Nav2.

---

## 5. Raspberry Pi setup

### 5.1 Install broker and Python environment

```bash
sudo apt update
sudo apt install -y mosquitto mosquitto-clients python3-venv netcat-openbsd
sudo systemctl enable --now mosquitto

cd ~/VDA5050-Paper-Dev
python3 -m venv .venv
source .venv/bin/activate
pip install --upgrade pip
pip install -r fleet_control/requirements.txt
cp -n configs/fleet_control.env.example configs/fleet_control.env
```

### 5.2 Allow the ROX to reach Mosquitto

Many Mosquitto installations listen only on localhost until a listener is configured. For an **isolated lab network only**:

```bash
sudo cp deploy/mosquitto/vda5050-lab.conf.example \
  /etc/mosquitto/conf.d/vda5050-lab.conf
sudo systemctl restart mosquitto
ss -ltnp | grep 1883
```

Before using a wider or untrusted network, replace anonymous MQTT with authentication and TLS.

Monitor all case-study traffic:

```bash
mosquitto_sub -h 192.168.50.115 -t 'vda5050/v3/#' -v
```

### 5.3 Start master control

```bash
./scripts/run_master_control.sh
```

Open:

```text
http://192.168.50.115:5000
```

Useful runtime inspection:

```bash
curl http://192.168.50.115:5000/runtime | python3 -m json.tool
```

The optional service template is in `deploy/systemd/vda5050-master.service.example`.

---

## 6. ROX-Diff ROS 2 overlay setup

The delivered Neobotix workspace remains the underlay and this repository remains a separate overlay.

```text
~/ros2_workspace                         Neobotix underlay
~/Projects/VDA5050-Paper-Dev/ros2_ws     project overlay
```

Build or rebuild with the central helper:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh build
source ros2_ws/install/setup.bash
./scripts/rox.sh status
```

The helper avoids the ROS-generated `AMENT_TRACE_SETUP_FILES`/`set -u` startup problem and sources ROS Jazzy, the Neobotix underlay and the project overlay in the correct order.

See [docs/ROX_COMMANDS.md](docs/ROX_COMMANDS.md) for all supported commands.

---

## 7. Native ROX bringup and verified interfaces

The hardware bringup is already started at robot boot by `ROS_AUTOSTART.sh`:

```bash
source ~/ros2_workspace/install/setup.bash
sleep 2
ros2 launch rox_bringup bringup_launch.py \
  rox_type:=diff \
  imu_enable:=True \
  use_d435:=True \
  enable_io_board:=True
```

Do not start another `rox_bringup` instance. Use the launch command only with `--show-arguments` when inspecting supported options.

Check the delivered interfaces with:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh interfaces
```

Verified hardware interfaces include:

```text
/tf                       tf2_msgs/msg/TFMessage
/tf_static                tf2_msgs/msg/TFMessage
/odom                     nav_msgs/msg/Odometry
/battery_state            sensor_msgs/msg/BatteryState
/emergency_stop_state     neo_msgs2/msg/EmergencyStopState
/safety_state             neo_msgs2/msg/SafetyState
/scan                     sensor_msgs/msg/LaserScan
```

`/navigate_to_pose` and `map -> base_link` are expected only after Nav2/AMCL starts and the initial pose is set.

---

## 8. Current map and waypoint workflow

The commissioned map pair is installed at:

```text
/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.yaml
/home/neobotix/ros2_workspace/install/rox_navigation/share/rox_navigation/maps/df_map.pgm
```

Back up both files outside the generated `install/` tree.

### 8.1 Start Nav2 and RViz

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh nav
```

Equivalent direct command with automatic pose restoration:

```bash
ros2 launch rox_vda5050_adapter \
  navigation_with_pose_persistence.launch.py \
  rox_type:=diff \
  use_rviz:=True \
  map:="$HOME/maps/df_map.yaml" \
  map_id:=df_map \
  pose_file:="$HOME/Projects/VDA5050-Paper-Dev/runtime/rox_last_pose.yaml" \
  auto_restore:=true
```

### 8.2 Visualize the named waypoints

In a second terminal:

```bash
./scripts/rox.sh visualize
```

Add `/rox_waypoints/markers` as an RViz `MarkerArray` display. The markers are visual only.

### 8.3 Capture and test exact waypoint poses

```bash
./scripts/rox.sh capture home
./scripts/rox.sh capture short_test
./scripts/rox.sh capture crane_handover
./scripts/rox.sh capture warehouse_dropoff
```

The current logical identifier is:

```yaml
map_id: df_map
```

List all values:

```bash
./scripts/rox.sh list
```

Validate a goal without motion:

```bash
./scripts/rox.sh goto-dry crane_handover
```

Send the exact YAML pose to Nav2 and verify the final TF pose against the YAML tolerances:

```bash
./scripts/rox.sh goto crane_handover
```

Equivalent direct command:

```bash
ros2 run rox_vda5050_adapter goto_waypoint \
  --name crane_handover \
  --waypoint-file configs/rox_waypoints.yaml
```

Repeat every waypoint from different starting poses. Only after the full footprint, payload clearance, final yaw, scanner behavior, departure path and crane alignment are acceptable should `configured: true` be set.

### 8.4 Generate orders on the Pi

Copy the verified YAML to the Pi and generate the short or full order using the existing `scripts/generate_rox_order.py` workflow. The `map_id` in the waypoint file, generated VDA order and ROX adapter configuration must remain `df_map` unless all three are deliberately changed together.

---

## 9. Start and test the ROX adapter

The native hardware bringup is already running from boot. Start Nav2/AMCL first, then run the adapter from the project overlay.

### 9.1 Dry-run mode

Dry-run is the default and must be used first:

```bash
ros2 launch rox_vda5050_adapter rox_vda5050_adapter.launch.py \
  mqtt_host:=192.168.50.115 \
  map_id:=df_map \
  dry_run_navigation:=true
```

The adapter should:

- publish retained `ONLINE` connection;
- publish schema-valid state;
- receive orders from the Pi;
- simulate node arrival without Nav2 movement;
- stop at `holdPose` until `releaseHold` is sent;
- report node/action transitions to the master.

Pi test commands:

```bash
curl -X POST http://192.168.50.115:5000/order/rox
curl http://192.168.50.115:5000/runtime | python3 -m json.tool
curl -X POST http://192.168.50.115:5000/release_hold
curl -X POST http://192.168.50.115:5000/pause/rox
curl -X POST http://192.168.50.115:5000/resume/rox
curl -X POST http://192.168.50.115:5000/cancel/rox
```

Monitor on either machine:

```bash
mosquitto_sub -h 192.168.50.115 \
  -t 'vda5050/v3/neobotix/rox_diff_1/#' -v
```

### 9.2 Real Nav2 motion

Only after dry-run results are correct:

```bash
ros2 launch rox_vda5050_adapter rox_vda5050_adapter.launch.py \
  mqtt_host:=192.168.50.115 \
  map_id:=df_map \
  dry_run_navigation:=false
```

Start with the short two-node route, low speed limits, an empty area, accessible emergency stops, and no crane motion.

---

## 10. Test order

Run the stages in [docs/raspberry_pi_rox_test_plan.md](docs/raspberry_pi_rox_test_plan.md):

1. Pi/ROX network and MQTT.
2. Native ROX health and teleoperation.
3. Mapping and ordinary Nav2 goals.
4. VDA adapter dry run.
5. Pause/resume/cancel/initialization.
6. Short real VDA motion.
7. Full ROX route without crane motion.
8. Crane-only test.
9. Coordinated handover without load.
10. Supervised loaded/scenario testing.

Independent order endpoints:

```bash
curl -X POST http://192.168.50.115:5000/order/rox
curl -X POST http://192.168.50.115:5000/order/crane
curl -X POST http://192.168.50.115:5000/order
```

The combined endpoint should only be used after both participants work independently.

---

## 11. Current ROX adapter behavior

### Implemented

- official v3 schema validation;
- order identity/map/start-node checks;
- continuous node/edge sequence checks;
- Nav2 `NavigateToPose` goals;
- node-state and edge-state progression;
- TF pose and odometry velocity reporting;
- battery and safety topic discovery;
- `startPause`, `stopPause`, `cancelOrder`;
- `initializePosition`, `factsheetRequest`;
- custom `holdPose`/`releaseHold`;
- `waitForTrigger`/`trigger`;
- initial `retry`/`skipRetry` for the current retriable node action;
- connection last will and retained ONLINE/OFFLINE;
- cancellation protection for goals whose asynchronous Nav2 acceptance is still pending;
- safe dry-run mode.

### Deliberately deferred

- same-order updates and base/horizon merging;
- edge-action execution;
- `zoneSet`, `responses`, zone requests and zone action states;
- planned/intermediate path publication;
- multi-order scheduling on the robot;
- verified production factsheet values;
- automated ROS/Nav2 integration tests.

The first physical case-study milestone is a repeatable new order with `orderUpdateId: 0`, node actions only, and a manually supervised handover.

---

## 12. Safety boundary

This project does not replace or certify the safety functions of the ROX-Diff or crane.

- nanoScan3, FlexiSoft, relayboard and robot controller remain authoritative for ROX safety;
- the crane PLC and local crane safety logic remain authoritative;
- VDA state reporting is informational;
- MQTT or Flask commands are not safety-rated;
- dry-run must precede real motion;
- the robot and crane must be commissioned independently before combined movement;
- loaded handover tests must follow supervised no-load tests.

---

## 13. Static validation performed for this delivery

The delivered source was checked for:

- Python syntax;
- shell-script syntax;
- ROS package XML parsing;
- official-schema validation of the crane order, ROX state example and ROX factsheet template;
- generation and validation of a test ROX order;
- rejection of unconfigured zero-coordinate waypoint files;
- absence of the previously tracked crane access-code file.

The source bundle was statically checked outside the ROX environment. A real Jazzy/Neobotix `colcon build`, Nav2 action test, MQTT test and physical robot/crane commissioning are still required after applying the update.

---

## 14. Upstream references

- Official VDA 5050 specification and schemas: https://github.com/VDA5050/VDA5050
- Neobotix ROX ROS repository: https://github.com/neobotix/rox
- Neobotix ROS 2 startup documentation: https://neobotix-docs.de/ros/ros2/starting_with_ROS.html
- Neobotix mapping/navigation documentation: https://neobotix-docs.de/ros/ros2/autonomous_navigation.html

<!-- rox-pose-persistence-update -->
## Automatic pose restoration

`scripts/rox.sh nav` now launches Nav2 together with a disk-backed pose-persistence companion. When the robot has not been moved while navigation was off, the last `map -> base_link` pose is republished to AMCL through `/initialpose`, eliminating the routine manual RViz **2D Pose Estimate** step. The current pose is atomically updated under `runtime/rox_last_pose.yaml`, which is intentionally excluded from Git.

First run or after physical movement:

```bash
./scripts/rox.sh pose-clear
./scripts/rox.sh nav-fresh
```

Normal operation:

```bash
./scripts/rox.sh nav
# In another terminal after localization is verified:
./scripts/rox.sh goto home
```

See [`docs/POSE_PERSISTENCE.md`](docs/POSE_PERSISTENCE.md) for map-fingerprint checks, same-boot odometry movement detection, recovery commands and limitations.

---

## Remote operator workstation

Ubuntu 24.04 operator computers can run the same `rox` command interface as the ROX-Diff. `rox nav` starts headless robot-side Nav2 when needed and opens the standard Neobotix Nav2 RViz locally with the robot model, live map/scan/costmaps and named waypoint markers. One-time shell installation removes the need to source ROS workspaces manually.

See [docs/REMOTE_OPERATOR_WORKSTATION.md](docs/REMOTE_OPERATOR_WORKSTATION.md) for installation, SSH setup, daily operation and troubleshooting.

## Web mission control

The Raspberry Pi Flask UI provides dynamic ROX waypoint orders, VDA 5050 v3
pause/resume/cancel/retry controls, live node/edge progress, ROX and crane
status, repeatable ROX-first scenarios, and an event log.

See [`docs/FLASK_MISSION_CONTROL.md`](docs/FLASK_MISSION_CONTROL.md) for setup,
operation, protocol mapping and the staged ROX test procedure.

