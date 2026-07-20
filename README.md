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

- [Complete commissioning runbook](docs/COMMISSIONING_RUNBOOK.md) — exact Pi, ROX, mapping, order-generation, crane and coordinated-test sequence.
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

- Verify the installed Neobotix launch filenames and arguments.
- Verify the installed ROS distribution and `neo_msgs2` message fields.
- Create a new warehouse map with the ROX-Diff.
- Tune localization, footprint, costmaps, controller, and speed limits.
- Capture the real `home`, `short_test`, `crane_handover`, and `warehouse_dropoff` poses.
- Generate the active ROX order from those poses.
- Verify battery and safety-state mapping on the delivered robot.
- Fill and verify the ROX factsheet physical/capability values.
- Build the ROS overlay on the ROX onboard computer.
- Run dry-run, short-motion, full-route, and coordinated no-load tests.
- Add order-update/base-horizon support, edge actions, zones, responses, visualization, and planned-path reporting after the first physical handover is stable.

See [MIGRATION_UPDATE.md](MIGRATION_UPDATE.md) for the full file-by-file change report.

---

## 2. Runtime architecture and deployment separation

```text
Raspberry Pi: 192.168.1.115
├── Mosquitto MQTT broker :1883
├── fleet_control/master_control.py :5000
└── crane_edge/crane_vda5050_adapter_v3.py
      └── OPC UA / PLC -> Ilmatar overhead crane

                         VDA 5050 v3.0 MQTT
                                  |
                                  v
ROX-Diff onboard computer
├── Neobotix rox_bringup
├── Neobotix rox_navigation / Nav2
└── rox_vda5050_adapter
      ├── VDA order nodes -> Nav2 NavigateToPose
      ├── instantActions -> pause/resume/cancel/init/hold/trigger/retry
      └── TF + odom + battery + safety -> VDA state
```

The Raspberry Pi does **not** need ROS 2. The Pi and ROX only need IP connectivity to the same MQTT broker. ROS 2 and Nav2 remain local to the robot. The crane remains locally controlled by its PLC/safety system through the crane adapter.

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
mosquitto_sub -h 192.168.1.115 -t 'vda5050/v3/#' -v
```

### 5.3 Start master control

```bash
./scripts/run_master_control.sh
```

Open:

```text
http://192.168.1.115:5000
```

Useful runtime inspection:

```bash
curl http://192.168.1.115:5000/runtime | python3 -m json.tool
```

The optional service template is in `deploy/systemd/vda5050-master.service.example`.

---

## 6. ROX-Diff ROS 2 overlay setup

Do not overwrite or copy project files into the Neobotix source tree. Build this repository's `ros2_ws` as a **separate overlay**.

Assumed paths below:

```text
~/ros2_workspace        existing Neobotix underlay
~/VDA5050-Paper-Dev/ros2_ws   this project overlay
```

Build:

```bash
cd ~/VDA5050-Paper-Dev/ros2_ws
source /opt/ros/$ROS_DISTRO/setup.bash
source ~/ros2_workspace/install/setup.bash
rosdep install --from-paths src --ignore-src -r -y
colcon build --symlink-install
source install/setup.bash
```

Every robot terminal should source in this order:

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
source ~/ros2_workspace/install/setup.bash
source ~/VDA5050-Paper-Dev/ros2_ws/install/setup.bash
```

Run static checks before building on hardware:

```bash
cd ~/VDA5050-Paper-Dev
./scripts/run_static_checks.sh
```

The static checks do not replace a ROS build or hardware test.

---

## 7. Verify native ROX interfaces before VDA integration

The native bringup filename and scanner arguments depend on the software delivered with the robot. Discover them instead of copying a guessed command:

```bash
ros2 pkg prefix rox_bringup
find "$(ros2 pkg prefix rox_bringup)/share/rox_bringup/launch" \
  -maxdepth 1 -type f -name '*.launch.py' -printf '%f\n' | sort
ros2 launch rox_bringup <ACTUAL_BRINGUP_FILE>.launch.py --show-arguments
```

Then start the actual file with `rox_type:=diff` and the verified scanner/frame arguments.

Then run:

```bash
./scripts/check_rox_ros_interfaces.sh
```

Expected core interfaces include:

```text
/odom
/tf
/tf_static
/scan
/battery_state
/emergency_stop_state
/safety_state
/navigate_to_pose        after Nav2 is started
```

Also inspect the actual types:

```bash
ros2 topic type /battery_state
ros2 topic type /emergency_stop_state
ros2 topic type /safety_state
ros2 interface show neo_msgs2/msg/EmergencyStopState
ros2 interface show neo_msgs2/msg/SafetyState
```

Do not proceed to VDA-controlled motion until native teleoperation, scanner behavior, odometry, TF, and Nav2 work reliably.

---

## 8. Replace DBot map, coordinates and orders

The old DBot coordinates cannot be converted mechanically. They belong to a different map, map origin, sensor setup, robot footprint and physical placement.

The required process is:

1. create a new ROX warehouse map;
2. verify localization and ordinary Nav2 goals;
3. physically place the robot at each desired waypoint;
4. capture `map -> base_link` poses;
5. copy the waypoint YAML to the Pi;
6. generate a schema-valid VDA order;
7. restart the Pi master so it reloads the generated initial pose and order path.

Full instructions are in [docs/rox_diff_mapping_and_orders.md](docs/rox_diff_mapping_and_orders.md).

### 8.1 Create and save a map

Terminal A: start normal ROX bringup.

Terminal B: first discover the installed mapping launch file, then run it with verified arguments:

```bash
find "$(ros2 pkg prefix rox_navigation)/share/rox_navigation/launch" \
  -maxdepth 1 -type f -iname '*map*.launch.py' -printf '%f\n' | sort
ros2 launch rox_navigation <ACTUAL_MAPPING_FILE>.launch.py --show-arguments
mkdir -p ~/maps
ros2 launch rox_navigation <ACTUAL_MAPPING_FILE>.launch.py \
  rox_type:=diff <OTHER_VERIFIED_ARGUMENTS>
```

Drive through the complete test area using safe teleoperation, then save:

```bash
ros2 run nav2_map_server map_saver_cli \
  -f ~/maps/warehouse_case_study
```

This produces:

```text
~/maps/warehouse_case_study.yaml
~/maps/warehouse_case_study.pgm
```

### 8.2 Start navigation on that map

```bash
ros2 launch rox_navigation navigation.launch.py \
  rox_type:=diff \
  map:=$HOME/maps/warehouse_case_study.yaml
```

Use RViz to initialize localization and send several ordinary goals before VDA testing.

### 8.3 Capture waypoints on the robot

```bash
cd ~/VDA5050-Paper-Dev
cp configs/rox_waypoints.yaml.example configs/rox_waypoints.yaml
```

Drive and localize at each exact pose, then capture:

```bash
ros2 run rox_vda5050_adapter capture_waypoint \
  --name home \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study

ros2 run rox_vda5050_adapter capture_waypoint \
  --name short_test \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study

ros2 run rox_vda5050_adapter capture_waypoint \
  --name crane_handover \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study

ros2 run rox_vda5050_adapter capture_waypoint \
  --name warehouse_dropoff \
  --output "$PWD/configs/rox_waypoints.yaml" \
  --map-id warehouse_case_study
```

Verify each pose with ordinary Nav2. Only then edit:

```yaml
configured: true
```

### 8.4 Copy coordinates to the Pi

From the ROX:

```bash
scp configs/rox_waypoints.yaml \
  pi@192.168.1.115:/home/pi/VDA5050-Paper-Dev/configs/
```

Adjust Pi username/path as required.

### 8.5 Generate a short commissioning order on the Pi

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
python3 scripts/generate_rox_order.py \
  --waypoints configs/rox_waypoints.yaml \
  --route examples/routes/rox_short_motion_test.yaml \
  --output examples/orders/order_rox_diff_v3.json \
  --update-fleet-env configs/fleet_control.env
```

Restart the master after the environment file changes.

After short-motion testing succeeds, generate the full route:

```bash
python3 scripts/generate_rox_order.py \
  --waypoints configs/rox_waypoints.yaml \
  --route examples/routes/rox_crane_case_study.yaml \
  --output examples/orders/order_rox_diff_v3.json \
  --update-fleet-env configs/fleet_control.env
```

The generator refuses `configured: false`, validates the output against the official `order.schema`, uses continuous even/odd node-edge sequence IDs, and supports per-waypoint XY/orientation tolerances.

### 8.6 First-node rule

Before sending a new order, the ROX must be localized and physically within the configured tolerance of the first node. The adapter intentionally rejects an order if the robot is not near that start pose. This prevents a generated route from silently treating a distant point as already reached.

The `/automatic` master route sends `initializePosition` using the captured home pose. This sets the localization initial pose; it does not physically move the robot and does not replace verification in RViz.

---

## 9. Start and test the ROX adapter

Source the Neobotix underlay and project overlay, then start native bringup and Nav2 first.

### 9.1 Dry-run mode

Dry-run is the default and must be used first:

```bash
ros2 launch rox_vda5050_adapter rox_vda5050_adapter.launch.py \
  mqtt_host:=192.168.1.115 \
  map_id:=warehouse_case_study \
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
curl -X POST http://192.168.1.115:5000/order/rox
curl http://192.168.1.115:5000/runtime | python3 -m json.tool
curl -X POST http://192.168.1.115:5000/release_hold
curl -X POST http://192.168.1.115:5000/pause/rox
curl -X POST http://192.168.1.115:5000/resume/rox
curl -X POST http://192.168.1.115:5000/cancel/rox
```

Monitor on either machine:

```bash
mosquitto_sub -h 192.168.1.115 \
  -t 'vda5050/v3/neobotix/rox_diff_1/#' -v
```

### 9.2 Real Nav2 motion

Only after dry-run results are correct:

```bash
ros2 launch rox_vda5050_adapter rox_vda5050_adapter.launch.py \
  mqtt_host:=192.168.1.115 \
  map_id:=warehouse_case_study \
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
curl -X POST http://192.168.1.115:5000/order/rox
curl -X POST http://192.168.1.115:5000/order/crane
curl -X POST http://192.168.1.115:5000/order
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
- visualization topic;
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

The delivery was **not** built in a ROS 2/Neobotix environment and was **not** executed on the Raspberry Pi, ROX-Diff, Nav2, MQTT broker or crane hardware. Those hardware/runtime steps remain necessary.

---

## 14. Upstream references

- Official VDA 5050 specification and schemas: https://github.com/VDA5050/VDA5050
- Neobotix ROX ROS repository: https://github.com/neobotix/rox
- Neobotix ROS 2 startup documentation: https://neobotix-docs.de/ros/ros2/starting_with_ROS.html
- Neobotix mapping/navigation documentation: https://neobotix-docs.de/ros/ros2/autonomous_navigation.html
