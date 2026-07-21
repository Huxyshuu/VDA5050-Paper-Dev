# ROX-Diff AMR Migration Update

## Scope

This delivery migrates the active AMR/ROS side from the previous DBot/TurtleBot implementation to a Neobotix ROX-Diff. It preserves the Raspberry Pi fleet/master control and Ilmatar crane adapter, but replaces the robot-side dependency chain, identities, configuration, map/order workflow, and deployment documentation.

The update is a development migration, not a claim of completed hardware commissioning. Static and JSON-schema checks were performed; the ROS overlay and real robot still need to be built and tested on the ROX-Diff.

---

## Architectural decision

The legacy robot path was approximately:

```text
VDA 5050 v2 MQTT
  -> old ROS connector
  -> custom vda5050_msgs/controller
  -> TurtleBot/DBot adapter
  -> DBot-specific Nav2, TF, odometry and motor packages
```

The new path is:

```text
VDA 5050 v3 MQTT
  -> rox_vda5050_adapter
  -> native Nav2 NavigateToPose
  -> Neobotix ROX drivers/navigation
```

This avoids porting obsolete DBot hardware and v2 connector code. Neobotix remains responsible for the platform drivers, kinematics, TF tree, odometry, laser scanners, safety messages, localization and Nav2 configuration.

---

## Existing files changed

### `fleet_control/master_control.py`

Changed:

- loads `configs/fleet_control.env` through `python-dotenv`;
- resolves schema and order paths relative to the repository root;
- renames the active robot target from `dbot` to `rox`;
- changes the default ROX identity to `neobotix / rox_diff_1`;
- changes the topic root to `vda5050/v3/neobotix/rox_diff_1`;
- changes the robot order path to generated `examples/orders/order_rox_diff_v3.json`;
- removes hard-coded DBot initialization coordinates;
- requires `ROX_INIT_*` values generated from captured ROX poses;
- makes crane and ROX handover node IDs configurable;
- subscribes to `state`, QoS-1 `connection`, and `factsheet` for both participants;
- validates incoming state, connection and factsheet messages;
- adds independent `/order/rox` and `/order/crane` endpoints;
- adds target-specific pause, resume, cancel and factsheet request endpoints;
- sends the active `orderId` with v3 `cancelOrder` when known;
- adds a generic development instant-action endpoint;
- adds `/runtime` for current order/state/connection inspection;
- retains the first-migration `holdPose`/`releaseHold` crane rendezvous logic.

### `fleet_control/templates/index.html` and `index_grid.html`

Changed visible DBot labels to Neobotix ROX-Diff.

### `fleet_control/requirements.txt`

Adds/standardizes Flask, Paho MQTT, JSON Schema, dotenv and YAML dependencies.

### `configs/fleet_control.env` and `.example`

Changed:

- removes active DBot identity/settings;
- defines Pi broker `192.168.50.115:1883`;
- defines crane and ROX v3 participant identities;
- points to the generated ROX order location;
- leaves the ROX initialization pose intentionally blank;
- defines configurable handover node IDs and exact action-state milestone IDs.

### `examples/orders/order_ilmatar_v3.json`

Changed to a stored order that validates directly against the official v3 `order.schema`:

- v3 header/version fields;
- template order ID/update ID;
- v3 edge representation without old `startNodeId`/`endNodeId`.

### `.gitignore`

Added exclusions for:

- virtual environments;
- ROS build/install/log products;
- local credentials;
- captured waypoint file;
- generated active ROX order;
- generated experiment results;
- Python/editor artifacts.

---

## Active files removed or retired

Removed from active runtime:

- `examples/orders/order_dbot_v3.json`;
- `fleet_control/order_dbot_TEST.json`;
- `fleet_control/order_ilmatar_TEST.json`;
- DBot workspace/build products from the active `ros2_ws`;
- tracked crane access-code file.

Historical source remains under `legacy/`, but it is not sourced or built. The credential-bearing `legacy/RaspberryPI/accesscode_url.txt` was removed and replaced by an example file.

---

## New ROS 2 package: `rox_vda5050_adapter`

Location:

```text
ros2_ws/src/rox_vda5050_adapter/
```

### MQTT/VDA behavior

Implemented:

- direct MQTT JSON communication using VDA 5050 v3.0 topics;
- official schema validation of incoming `order`/`instantActions` and outgoing `state`/`connection`/`factsheet`;
- participant identity and protocol-version checks;
- retained `ONLINE`/`OFFLINE` connection messages;
- MQTT last will with `CONNECTION_BROKEN`;
- order start-node/map checks;
- continuous sequence checks with even nodes and odd edges;
- rejection of order updates until update merging is implemented;
- safe rejection of edge actions in the first migration version.

### ROS/Nav2 behavior

Implemented:

- `NavigateToPose` action client;
- `map -> base_link` pose reporting;
- `/odom` velocity reporting;
- dynamic subscription to actual battery/emergency/safety topic types;
- `/initialpose` publication for `initializePosition`;
- dry-run Nav2 simulation;
- cancellation handling, including a goal whose asynchronous acceptance is still pending;
- pause/resume of active navigation and dry-run navigation.

### Order action behavior

Supported node actions:

- `holdPose`;
- `waitForTrigger`;
- `noop` / `noOp`.

Supported instant actions:

- `startPause`;
- `stopPause`;
- `cancelOrder`;
- `initializePosition`;
- `factsheetRequest`;
- `releaseHold`;
- `trigger`;
- `retry`;
- `skipRetry`.

The retry implementation is intentionally limited to the currently blocked node action in `RETRIABLE` state. It is not a general retry scheduler.

### State reporting

Publishes:

- `orderId` / `orderUpdateId`;
- last node and remaining node/edge states;
- normal and instant action states;
- `driving` and `paused`;
- `mobileRobotPosition` and velocity when localized;
- `powerSupply`;
- `operatingMode`;
- errors;
- VDA safety state mapped from Neobotix messages.

Safety mapping is for reporting only and is not safety-rated.

### Utilities in the package

- `capture_waypoint`: records the current `map -> base_link` pose into YAML;
- launch/config files with Pi broker and participant defaults;
- factsheet template copied into the package share data.

---

## New ROS data package: `vda5050_schemas_v3`

Location:

```text
ros2_ws/src/vda5050_schemas_v3/
```

Installs all official v3 schemas into the ROS share tree so the adapter can validate messages without relying on a source checkout path.

---

## New coordinate/order workflow

### `configs/rox_waypoints.yaml.example`

Provides safe zero-value placeholders and `configured: false`. It includes:

- `home`;
- `short_test`;
- `crane_handover`;
- `warehouse_dropoff`;
- per-waypoint XY and orientation tolerances.

The order generator refuses this file until it is copied, populated, verified and marked configured.

### `examples/routes/rox_short_motion_test.yaml`

Two-node low-speed commissioning route:

```text
home -> short_test + holdPose
```

Use before the full route.

### `examples/routes/rox_crane_case_study.yaml`

Logical full route independent of coordinates:

```text
home -> crane_handover + holdPose -> warehouse_dropoff -> home
```

### `scripts/generate_rox_order.py`

- reads captured named poses;
- reads a logical route;
- creates even node / odd edge sequence IDs;
- adds node actions;
- uses per-waypoint tolerances;
- validates against official `order.schema`;
- writes `examples/orders/order_rox_diff_v3.json`;
- can update the Pi `ROX_INIT_*` values from the first waypoint.

### `scripts/validate_messages.py`

Validates one or more JSON files against an official schema.

### `scripts/check_rox_ros_interfaces.sh`

Reports Nav2, TF, odometry, scan, battery and safety interfaces on the actual robot.

### `scripts/check_pi_mqtt_from_rox.sh`

Checks Pi TCP/MQTT reachability and publishes a commissioning message.

### `scripts/run_static_checks.sh`

Runs syntax, XML, schema, generated-order and safe-placeholder checks without needing ROS hardware.

### `scripts/sync_vda_schemas_to_ros.py`

Copies root official schemas into the ROS schema package.

---

## Deployment and documentation added

- `docs/architecture.md`;
- `docs/deployment.md`;
- `docs/rox_diff_mapping_and_orders.md`;
- `docs/raspberry_pi_rox_test_plan.md`;
- `docs/vda5050_v2_to_v3_migration.md`;
- lab Mosquitto listener example;
- Pi master systemd example;
- ROX dry-run adapter systemd example.

The ROS packages should be built as a separate overlay after sourcing the existing Neobotix workspace. The project does not replace `rox_bringup` or `rox_navigation`.

---

## Static checks completed

Completed in the delivery environment:

- Python syntax compilation;
- shell syntax checks;
- ROS package XML parsing;
- official-schema validation of the crane order;
- official-schema validation of the ROX example state;
- official-schema validation of the ROX factsheet template;
- test ROX order generation and validation;
- rejection of unconfigured placeholder coordinates;
- scan for the removed credential file.

Not completed in the delivery environment:

- `colcon build` with ROS/Neobotix installed;
- Paho/Flask master runtime against a broker;
- Nav2 action-server integration;
- Pi deployment;
- real ROX topic verification;
- robot motion;
- crane motion or combined handover.

---

## Required hardware work

1. Confirm Pi and ROX network connectivity.
2. Configure the Pi Mosquitto listener and verify a message from ROX.
3. Build and source the project ROS overlay.
4. Start native ROX bringup and inspect actual topic/message types.
5. Verify scanner, emergency stop, odometry, TF and teleoperation.
6. Create a new map with ROX-Diff.
7. Tune and verify ordinary Nav2 goals.
8. Capture all required poses.
9. Copy waypoint YAML to the Pi.
10. Generate the short test order and restart the master.
11. Run VDA dry-run end to end.
12. Run a short real order at low speed.
13. Generate and run the full route without crane motion.
14. Test crane independently.
15. Test coordinated handover without load.
16. Only then test payload/scenario cases under supervision.

---

## Recommended next software milestones

After the first repeatable physical handover:

1. same-order updates and base/horizon merging;
2. edge-action execution;
3. verified ROX factsheet values and supported action declarations;
4. `zoneSet` support for crane workspace, handover release and suspended-load blocking;
5. `responses` and zone requests;
6. planned/intermediate path reporting;
7. visualization topic;
8. automated MQTT + simulated Nav2 integration tests;
9. structured scenario/event logging and paper result generation;
10. robust persistence/recovery across adapter or broker restarts.

## Network correction - 21 July 2026

The active lab network uses DTLabOpen directly: Raspberry Pi Ethernet `192.168.50.115` and ROX-Diff `192.168.50.50`. The Pi also has Ilmatar Wi-Fi `192.168.0.116`. No intermediate training subnet, NAT or port forwarding is part of the active architecture. All MQTT, Flask, SCP and test commands use the Pi DTLabOpen address `192.168.50.115`.

