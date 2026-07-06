# VDA5050-Paper Project Map and Migration README

This README documents the uploaded `VDA5050-Paper-main.zip` project. It is based on a full static inspection of the ZIP contents. I did not run the ROS 2 nodes, MQTT broker, OPC UA crane connection, or hardware drivers because the runtime environment, crane PLC/OPC UA server, AMR hardware, and ROS workspace are not available in this sandbox.

The current project is an older VDA 5050 v2.x mixed-fleet prototype for coordinating:

- an Ilmatar/Konecranes overhead crane through a Raspberry Pi, OPC UA, and a custom VDA 5050 adapter;
- a Dbot/TurtleBot-style ROS 2 mobile robot stack through the InOrbit/Clearpath-style `vda5050_connector` and a custom `vda5050_tb3_adapter`;
- a small Flask-based master-control UI that publishes VDA 5050 orders and instant actions to both devices over MQTT.

The intended next research step is to migrate this architecture to VDA 5050 v3.0 and use it as a case study with the Ilmatar crane and a newer Neobotix ROX-Diff AMR in a warehouse-style scenario.

---

## 1. What the Project Currently Does

At a high level, the project demonstrates a task-level orchestration layer where both the crane and the mobile robot are treated as VDA 5050 participants. The master control publishes VDA 5050 orders to both assets. Each asset has an adapter that translates VDA 5050 messages into device-specific behaviour.

```text
              Browser UI / Flask master control
                         |
                         | MQTT orders + instantActions
                         v
                    MQTT broker
                 /               \
                /                 \
  Crane VDA adapter              Dbot VDA connector
  RaspberryPI/*.py               ROS 2 vda5050_connector
        |                              |
        | OPC UA                       | ROS 2 actions/services
        v                              v
  Ilmatar crane PLC              Nav2 / Dbot robot stack
```

The system is not a safety-rated controller. VDA 5050 is used as an orchestration interface. Low-level motion and safety remain with the crane PLC, the robot controller, Nav2, and local hardware systems.

---

## 2. Top-Level Repository Structure

```text
VDA5050-Paper-main/
├── RaspberryPI/
│   ├── crane_vda5050_adapter_TEST.py
│   ├── master_control_panel_TEST.py
│   ├── new_crane.py
│   ├── order_dbot_TEST.json
│   ├── order_ilmatar_TEST.json
│   ├── schemas/
│   └── templates/index_TEST.html
├── dbot_vda5050_ilmatar/
│   ├── src/
│   │   ├── dbot/
│   │   ├── dbot_bridge/
│   │   ├── dbot_custom_msgs/
│   │   ├── dbot_nav_slam/
│   │   ├── gesturecontrol/
│   │   ├── joycontrol/
│   │   ├── motor_driver/
│   │   ├── odom_motion_model/
│   │   ├── ros2_odometry_estimation/
│   │   ├── tf2_dbot/
│   │   ├── vda5050_connector/
│   │   ├── vda5050_msgs/
│   │   ├── vda5050_tb3_adapter/
│   │   └── vda_dbot_nav_slam/
│   ├── build/
│   ├── install/
│   └── log/
├── readme_dbot.txt
├── readme_ilmatar.txt
└── readme_rpi.txt
```

The uploaded repository contains source code plus generated build, install, cache, and log artifacts. For a clean future Git repository, the following should normally be removed or ignored:

```text
dbot_vda5050_ilmatar/build/
dbot_vda5050_ilmatar/install/
dbot_vda5050_ilmatar/log/
dbot_vda5050_ilmatar/src/*/build/
dbot_vda5050_ilmatar/src/*/install/
dbot_vda5050_ilmatar/src/*/log/
__pycache__/
*.pyc
*.swp
```

`RaspberryPI/accesscode_url.txt` appears to contain crane connection/access data. Do not publish it in a public repository. Replace it with `accesscode_url.example.txt` and document the required format instead.

---

## 3. Runtime Components and Responsibilities

### 3.1 RaspberryPI Layer: Crane and Master Control

#### `RaspberryPI/new_crane.py`

Role: low-level Python interface to the Ilmatar crane through OPC UA.

Main responsibilities:

- connects to the crane OPC UA server using `asyncua.sync.Client`;
- reads and writes OPC UA nodes under namespace `ns=5`;
- handles crane watchdog and access code;
- reads bridge, trolley, and hoist positions;
- reads hoist load values;
- writes direction booleans and speed values for bridge, trolley, and hoist;
- implements motion helper functions such as:
  - `move_bridge_to_target_p()`;
  - `move_trolley_to_target_p()`;
  - `move_hoist_to_target()`;
  - `stop_all()`;
  - `zero_*_position()`;
  - speed scaling helpers.

Conceptually, this is the hardware abstraction layer for the crane. It does not understand VDA 5050 itself. It exposes crane-specific operations that the VDA adapter calls.

Important crane axes:

```text
Bridge  -> crane long-travel axis
Trolley -> cross-travel axis
Hoist   -> vertical lifting axis
```

#### `RaspberryPI/crane_vda5050_adapter_TEST.py`

Role: VDA 5050-to-OPC UA adapter for the Ilmatar crane.

Main responsibilities:

- connects to MQTT broker at `VDA_MQTT_HOST`, default `192.168.1.115:1883`;
- subscribes to crane VDA topics:
  - `uagv/v2/konecranes/ilmatar_1/order`;
  - `uagv/v2/konecranes/ilmatar_1/instantActions`;
- publishes crane VDA topics:
  - `/connection`;
  - `/state`;
  - `/visualization`;
- validates VDA 5050 JSON payloads using local schemas in `RaspberryPI/schemas/`;
- executes received VDA order nodes sequentially;
- treats VDA node positions as crane bridge/trolley targets;
- executes node actions as crane behaviours;
- maintains VDA state fields such as `orderId`, `lastNodeId`, `actionStates`, `agvPosition`, `operatingMode`, `errors`, and `safetyState`;
- reports hoist height through `information` entries with `infoType = HOIST_POSITION`;
- supports pause, resume, cancel, and reset instant actions.

Current crane action catalogue:

| Action type | Current meaning | Typical parameters | Blocking type used |
|---|---|---|---|
| `lowerHoist` | Move hoist down to target height | `zd` in metres | `SOFT` |
| `buttonPress` | Wait for UI/manual release or instant release | optional `timeout` | `HARD` |
| `raiseHoist` | Raise hoist to target height | `zu` in metres | `SOFT` |
| `pause` | Pause crane motion / speed scale to zero | none | `NONE` |
| `resume` | Resume after pause | none | `NONE` |
| `cancelOrder` | Stop motion, cancel current order, clear queued future work | none | `HARD` |
| `resetHoist` | Return hoist to home height | none | `HARD` |
| `resetBridgeTrolley` | Return bridge/trolley to home XY | none | `HARD` |
| `resetAllHome` | Return hoist first, then bridge/trolley | none | `HARD` |

Important implementation detail: the adapter currently ignores edge traversal/actions for the crane and executes nodes sequentially. Crane XY movement is derived from each node’s `nodePosition.x` and `nodePosition.y`.

#### `RaspberryPI/master_control_panel_TEST.py`

Role: Flask-based master-control UI and simple orchestration logic.

Main responsibilities:

- serves `templates/index_TEST.html` on port `5000`;
- provides UI buttons for:
  - automatic/init position;
  - release;
  - pause;
  - resume;
  - order;
  - cancel;
  - reset all;
  - reset hoist;
  - reset bridge/trolley;
  - release hold;
- publishes VDA 5050 orders to both crane and Dbot;
- publishes VDA 5050 instant actions;
- subscribes to crane and Dbot `/state` topics;
- keeps a runtime cache of latest states;
- indexes `actionId -> nodeId` mappings from orders;
- coordinates handover between crane `buttonPress` and Dbot `holdPose` actions;
- applies a hoist clearance gate using `HOIST_CLEARANCE_M`, default `1.0` m;
- automatically sends crane `release` when both crane and Dbot are at the same rendezvous and hoist height is safe;
- sends `releaseHold` to Dbot after manual release and safe hoist height.

Current target configuration:

```text
Crane topic root: uagv/v2/konecranes/ilmatar_1
Dbot topic root:  uagv/v2/aaltoUniversity/dbot_1
Protocol version: 2.1.0 for both targets in the master config
```

Current rendezvous logic:

```python
RENDEZVOUS = [
    {"crane_node": "node2", "dbot_node": "node2", "tag": "DROP_1"},
]
```

This means the master only considers a coordinated handover valid when the crane is executing `buttonPress` at `node2` and Dbot is executing `holdPose` at `node2`.

#### `RaspberryPI/templates/index_TEST.html`

Role: browser-based operator panel for the Flask master control.

It provides large coloured buttons for all master control actions. The JavaScript maps each button to a Flask POST route, e.g. `/order`, `/cancel`, `/release`, `/pause`, `/resume`, `/reset_all`.

#### `RaspberryPI/order_dbot_TEST.json`

Role: Dbot order template.

Current behaviour:

- Dbot moves through four released nodes;
- node 2 and node 3 include `holdPose` actions;
- `holdPose` is used to stop Dbot at a handover point until a `releaseHold` instant action is received.

#### `RaspberryPI/order_ilmatar_TEST.json`

Role: crane order template.

Current behaviour:

- crane moves between three nodes;
- node actions perform hoist/lift interaction:
  - lower hoist;
  - wait for button press/release;
  - raise hoist;
- used together with Dbot `holdPose` for handover orchestration.

#### `RaspberryPI/schemas/`

Role: local VDA 5050 JSON Schema validation for the Raspberry Pi side.

Files:

```text
connection.schema
factsheet.schema
instantActions.schema
order.schema
state.schema
visualization.schema
```

These schemas correspond to the older v2.x message model used by the current system. They must be replaced or regenerated for VDA 5050 v3.0 migration.

---

### 3.2 ROS 2 Workspace: `dbot_vda5050_ilmatar/src/`

This folder is a ROS 2 workspace containing Dbot low-level packages, navigation packages, and VDA 5050 connector packages.

#### `vda5050_connector/`

Role: generic ROS 2 VDA 5050 connector.

This package is based on the InOrbit/Clearpath VDA5050 connector pattern. It has three core responsibilities:

1. **MQTT bridge**
   - translates MQTT VDA JSON messages into ROS 2 `vda5050_msgs`;
   - publishes ROS 2 state/connection/visualization back to MQTT.

2. **Controller**
   - validates and processes VDA orders;
   - accepts or rejects order updates;
   - executes node actions;
   - sends navigation goals to the adapter;
   - publishes state, connection, visualization, and factsheet information.

3. **Adapter interface**
   - delegates robot-specific state, navigation, and action execution to an adapter package.

Key files:

| File | Responsibility |
|---|---|
| `vda5050_connector_py/mqtt_bridge.py` | MQTT-to-ROS and ROS-to-MQTT translation |
| `vda5050_connector_py/vda5050_controller.py` | Main order/instantAction controller |
| `scripts/mqtt_bridge.py` | executable wrapper |
| `scripts/vda5050_controller.py` | executable wrapper |
| `launch/mqtt_bridge.launch.py` | starts MQTT bridge node |
| `launch/controller.launch.py` | starts VDA controller node |
| `action/NavigateToNode.action` | ROS action for navigation to VDA node |
| `action/ProcessVDAAction.action` | ROS action for executing VDA actions |
| `srv/GetState.srv` | adapter state service |
| `srv/SupportedActions.srv` | supported action service |

The connector is currently configured for v2.x topics and messages. The default interface name is `uagv`, and the topic alias is generated from the protocol major version such as `v2`.

#### `vda5050_msgs/`

Role: ROS 2 message definitions for the VDA 5050 message model.

This package defines ROS message equivalents of VDA 5050 entities such as:

```text
Order
Node
Edge
Action
CurrentAction
OrderState
Connection
Factsheet
Visualization
BatteryState
SafetyState
Error
Info
Trajectory
```

The current message definitions are v2.x style. For example, `Action.msg` contains only `NONE`, `SOFT`, and `HARD` blocking types. VDA 5050 v3.0 introduces new/changed semantics such as `SINGLE`, split action-state arrays, `RETRIABLE`, updated operating modes, zones, planned paths, and other breaking field changes. This package will need a major update or replacement for v3.0.

#### `vda5050_tb3_adapter/`

Role: Dbot/TurtleBot-style adapter between the generic VDA connector and ROS 2 Nav2.

Key file:

```text
vda5050_tb3_adapter/vda5050_tb3_adapter/tb3_adapter.py
```

Main responsibilities:

- exposes adapter services/actions used by `vda5050_connector`;
- provides current robot state through `/odom` and TF lookup from `map` to `base_link`;
- handles VDA `initPosition` by publishing `/initialpose`;
- handles VDA `holdPose` by cancelling Nav2 and waiting until `releaseHold` is received;
- handles VDA `releaseHold` by clearing the hold latch;
- translates VDA node navigation requests into Nav2 `/navigate_to_pose` goals.

Current custom AMR actions:

| Action | Meaning |
|---|---|
| `initPosition` | publish initial pose to Nav2/AMCL |
| `holdPose` | stop and wait at handover node |
| `releaseHold` | release the hold and allow execution to continue |

Current config:

```text
vda5050_tb3_adapter/config/connector_tb3.yaml
```

This points the Dbot connector to MQTT broker `192.168.1.115:1883`, manufacturer `aaltoUniversity`, serial `dbot_1`, and protocol version `2.1.0`.

#### `dbot_nav_slam/` and `vda_dbot_nav_slam/`

Role: ROS 2 robot description, maps, SLAM/localization/Nav2 configuration, and helper scripts.

These two packages are near-duplicates. `vda_dbot_nav_slam` appears to be a VDA-specific copy of `dbot_nav_slam`.

Important contents:

| Path | Responsibility |
|---|---|
| `description/*.xacro` | robot URDF/xacro description and ROS 2 control setup |
| `config/nav2_params.yaml` | Nav2 configuration |
| `config/mapper_params_online_async.yaml` | SLAM toolbox configuration |
| `config/diff_drive_controller.yaml` / `my_controllers.yaml` | diff-drive and ROS 2 control configuration |
| `config/twist_mux.yaml` | velocity command muxing |
| `maps/*.yaml`, `maps/*.pgm` | saved maps such as `clean_df_map`, `cage`, `office_map` |
| `launch/auto_nav_dbot_launch.py` | launches Dbot, TF, and Nav2 bringup |
| `launch/navigation_launch.py` | Nav2 navigation stack launch |
| `launch/localization_launch.py` | localization launch |
| `scripts/nav_through_poses.py` | scripted multi-goal navigation |
| `scripts/mqtt_dbot.py`, `mqtt_inspection.py` | MQTT helper/test scripts |

The main launch command in the old notes is:

```bash
ros2 launch dbot_nav_slam auto_nav_dbot_launch.py
```

#### `dbot/`

Role: lightweight ROS 2 package mostly containing launch files that start the Dbot base stack.

Important files:

```text
launch/dbot_launch.py
launch/remote_dbot_launch.py
launch/remote_dbot_no_odom_launch.py
```

These are used by `dbot_nav_slam/launch/auto_nav_dbot_launch.py`.

#### `motor_driver/`

Role: ROS 2 interface to the Dbot motor controller.

Main responsibilities:

- connects to ZLAC8015D motor controller through CANopen;
- subscribes to `cmd_vel`;
- converts Twist commands to motor speeds;
- publishes current speed and motor status;
- publishes custom wheel encoder message `wheel_encoder_rpm`.

Key files:

| File | Responsibility |
|---|---|
| `ros2_wrapper.py` | ROS 2 node wrapping the motor driver |
| `zlac8015d_canopen.py` / `zlac8015d_canopen_2.py` | CANopen motor driver abstraction |
| `node_controls.py` | helper functions for configuration/network/speed conversion |
| `dbot_config.yaml` | hardware configuration |
| `od_definitions.py` | object dictionary definitions/helpers |

#### `dbot_custom_msgs/`

Role: custom ROS 2 message package.

Defines:

```text
WheelEncoder.msg
```

The message contains left and right wheel encoder/RPM values used by odometry packages.

#### `odom_motion_model/`

Role: Python odometry estimation from wheel encoder values.

Main responsibilities:

- subscribes to `wheel_encoder_rpm`;
- computes robot odometry using a vehicle model;
- publishes `/odom`.

#### `ros2_odometry_estimation/`

Role: C++ odometry estimation package.

This appears to be an alternative or previous odometry estimator implementation. It receives wheel encoder data and publishes odometry using vehicle model logic.

#### `tf2_dbot/`

Role: broadcasts the transform from `odom` to `base_link`.

Main file:

```text
tf2_dbot/tf2_dbot/odom_baselink_broadcaster.py
```

It subscribes to `/odom` and broadcasts the dynamic transform required by Nav2 and TF lookup.

#### `dbot_bridge/`

Role: simpler direct MQTT-to-Nav2 bridge.

This package is separate from the main `vda5050_connector` architecture. It subscribes to a hard-coded MQTT order topic, sends the first released node as a Nav2 goal, and publishes a simple VDA-style state message.

It appears to be an experimental/debug bridge and should not be the main path for the new v3.0 case study.

#### `joycontrol/` and `gesturecontrol/`

Role: manual/control experiments.

- `joycontrol` publishes `cmd_vel` from joystick input.
- `gesturecontrol` uses a camera/hand gesture recognizer to control robot movement.

These are not central to VDA 5050 orchestration and can be archived or moved to `experimental/`.

---

## 4. Current VDA 5050 Topic Map

### Crane

```text
uagv/v2/konecranes/ilmatar_1/order
uagv/v2/konecranes/ilmatar_1/instantActions
uagv/v2/konecranes/ilmatar_1/connection
uagv/v2/konecranes/ilmatar_1/state
uagv/v2/konecranes/ilmatar_1/visualization
```

### Dbot

```text
uagv/v2/aaltoUniversity/dbot_1/order
uagv/v2/aaltoUniversity/dbot_1/instantActions
uagv/v2/aaltoUniversity/dbot_1/connection
uagv/v2/aaltoUniversity/dbot_1/state
uagv/v2/aaltoUniversity/dbot_1/visualization
```

Some older notes also refer to:

```text
uagv/v2/OSRF/TB3_1/#
uagv/v2/dbot/0001/#
uagv/v1/OSRF/TB3_1/#
```

For the migrated project, choose one consistent identity scheme and remove obsolete examples.

---

## 5. Current End-to-End Handover Logic

The current test scenario is built around a synchronized handover between crane and Dbot.

### Normal flow

```text
1. Operator presses Order in the Flask UI.
2. Master publishes one order to the crane and one order to Dbot.
3. Dbot moves through its nodes using Nav2.
4. At selected nodes, Dbot executes holdPose and waits.
5. Crane moves to its nodePosition using bridge/trolley axes.
6. Crane executes lowerHoist.
7. Crane executes buttonPress and waits for release.
8. Master observes crane buttonPress RUNNING and Dbot holdPose RUNNING at matching rendezvous nodes.
9. If hoist height is above clearance threshold, master sends release to crane.
10. Crane continues its action sequence and raises hoist.
11. After manual release and safe hoist clearance, master sends releaseHold to Dbot.
12. Dbot continues to next node.
```

### Safety/orchestration gate currently implemented

```text
DBot must not be released while the crane hoist is below HOIST_CLEARANCE_M.
```

This is implemented as non-safety-rated application logic in the Flask master control. It should be treated as an orchestration gate, not a certified safety function.

---

## 6. Current Limitations

### Architectural limitations

- The crane is represented as if it were a VDA mobile robot, using `agvPosition` for bridge/trolley coordinates.
- Edge traversal is ignored by the crane adapter.
- The master control has hard-coded rendezvous logic.
- The master control uses VDA `information` messages to parse hoist height; this is useful for debugging but should not be the long-term control interface.
- Dbot action logic is tightly coupled to `holdPose`/`releaseHold`.
- There is no generic job scheduler, priority queue, or warehouse task lifecycle.
- The VDA factsheet/capability discovery is not systematically used.
- Build, install, and logs are committed inside the repository.

### VDA 5050 limitations in current implementation

- Current code is v2.x-oriented.
- Topic roots use `uagv/v2/...`.
- Protocol versions are set to `2.0.0` or `2.1.0` depending on file.
- JSON schemas are older v2.x schemas.
- ROS messages are older `vda5050_msgs` definitions.
- Blocking types are old-style `NONE`, `SOFT`, `HARD`.
- There are no v3.0 zone sets, responses, planned paths, intermediate paths, `SINGLE` blocking type, split action state arrays, or `RETRIABLE` state.

### Hardware/runtime limitations

- Crane operation depends on a real OPC UA connection and access code.
- Dbot stack depends on hardware-specific paths such as `/home/dbot2/...`.
- MQTT host is hard-coded in multiple places as `192.168.1.115`.
- Some code assumes local maps and fixed coordinates.
- The current system is not containerized or hardware-agnostic.

---

## 7. Migration Target: VDA 5050 v3.0 + ROX-Diff AMR

The migration should not be treated as only changing `version = "3.0.0"`. VDA 5050 v3.0 is a major update. The new paper case study can be much stronger if the system is refactored around warehouse job logic, zones, path sharing, and explicit state transitions.

### 7.1 New target architecture

```text
Warehouse scenario / job generator
             |
             v
VDA 5050 v3.0 Fleet Control / Master
             |
             v
         MQTT broker
       /             \
      /               \
ROX-Diff adapter     Crane adapter
ROS 2 / Nav2         OPC UA / PLC
      |               |
      v               v
ROX-Diff AMR       Ilmatar crane
```

### 7.2 Replace Dbot/TB3 adapter with ROX-Diff adapter

The current Dbot/TB3 adapter should become a reference, not the final AMR implementation.

Migration tasks:

1. Identify ROX-Diff ROS 2 interfaces:
   - navigation action server;
   - odometry topic;
   - TF frames;
   - localization/initial pose interface;
   - footprint/contour data;
   - battery/state topics;
   - emergency/diagnostic topics.
2. Create a new package, for example:

```text
rox_vda5050_adapter/
```

3. Port useful logic from `vda5050_tb3_adapter/tb3_adapter.py`:
   - `initPosition` equivalent if needed;
   - navigation to VDA node;
   - state reporting;
   - action processing.
4. Add ROX-specific support for VDA 5050 v3.0:
   - `plannedPath` / `intermediatePath` if ROX/Nav2 can expose planned paths;
   - robot contour/geometry for zone interaction;
   - battery and diagnostics;
   - current operating mode.

### 7.3 Update VDA 5050 packages to v3.0

Required changes:

- replace old v2.x JSON schemas with v3.0 schemas;
- update or regenerate `vda5050_msgs` for v3.0;
- update MQTT topic major version from `v2` to `v3`;
- update controller logic for v3.0 message changes;
- add support for new topics and concepts:
  - `zoneSet`;
  - `responses`;
  - zone requests/actions/states where applicable;
  - planned and intermediate path sharing;
  - split `actionStates`, `instantActionStates`, and `zoneActionStates`;
  - `SINGLE` blocking type;
  - `RETRIABLE` action state;
  - `pauseAllowed` and `cancelAllowed`;
  - new/changed operating modes such as `STARTUP` and `INTERVENED`;
  - updated error levels and error descriptions.

### 7.4 Update crane representation for v3.0

The crane adapter should be refactored into a clearer usage profile.

Current crane action catalogue can be migrated as follows:

| Current action | v3.0 migration suggestion |
|---|---|
| `lowerHoist` | keep as crane-specific action; set `cancelAllowed` carefully |
| `raiseHoist` | keep as crane-specific action; candidate for `SINGLE` or `HARD` depending on context |
| `buttonPress` | replace or align with v3.0 `waitForTrigger` / trigger mechanism |
| `pause` / `resume` | map to v3.0 mandatory pause actions if appropriate |
| `cancelOrder` | add explicit order ID handling and safe cancellation rules |
| `resetHoist` | crane-specific instant action, likely not generally cancellable |
| `resetBridgeTrolley` | crane-specific instant action |
| `resetAllHome` | crane-specific instant action |

Recommended additional crane state fields/conventions:

```text
bridgePosition
 trolleyPosition
hoistHeight
loadAttached
loadWeight
workspaceZoneId
suspendedLoadZoneActive
currentCraneAction
safeForAMRRelease
```

These should not be hidden inside `information` if used for orchestration. For the paper, define a clear crane usage profile showing how these are represented in v3.0 messages or adapter-specific extensions.

### 7.5 Use v3.0 zones for the warehouse case study

The key novelty of the new case study should be zone-based orchestration.

Proposed zones:

| Zone | Meaning |
|---|---|
| `AMR_TRAVEL_AISLE` | normal ROX-Diff travel area |
| `CRANE_WORKSPACE` | area covered by bridge/trolley motion |
| `HANDOVER_ZONE` | shared AMR-crane transfer area |
| `AMR_WAITING_ZONE` | staging zone while crane is busy |
| `SUSPENDED_LOAD_NO_GO` | dynamic exclusion zone under crane load |
| `PRIORITY_CORRIDOR` | optional high-priority path for urgent jobs |
| `BLOCKED_AISLE` | simulated obstacle/blocked area |

For the research paper, the strongest question is whether VDA 5050 v3.0 zones can represent these mixed-fleet constraints cleanly, or whether crane-specific conventions are still needed.

---

## 8. Proposed Warehouse Case Study

The future case study should move beyond the single lab handover and simulate a small warehouse cell.

### 8.1 Warehouse cell

Minimal layout:

```text
Inbound / picking area
    |
    | AMR route
    v
AMR waiting zone ---- handover zone ---- crane workspace
                                      |
                                      v
                           crane-served storage/drop area
```

### 8.2 Job types

| Job type | Required resources | Example |
|---|---|---|
| Robot-only | ROX-Diff | move tote from inbound to packing |
| Crane-only | Ilmatar crane | relocate heavy load inside crane workspace |
| Robot + crane | ROX-Diff + crane | AMR delivers load to crane handover point, crane lifts/transfers it |
| Robot + crane + operator | ROX-Diff + crane + trigger | handover requires manual confirmation |

### 8.3 Job lifecycle

```text
NEW_JOB
  -> VALIDATED
  -> CLASSIFIED
  -> QUEUED
  -> RESOURCE_CHECK
  -> ZONE_CHECK
  -> ASSIGNED
  -> DISPATCHED
  -> EXECUTING
  -> WAITING_FOR_RESOURCE / WAITING_FOR_HANDOVER / WAITING_FOR_TRIGGER
  -> COMPLETED
```

Exceptional states:

```text
POSTPONED
CANCEL_REQUESTED
CANCELLING
CANCELLED
BLOCKED
TIMEOUT
FAILED
RETRIABLE
RECOVERING
ABORTED
```

### 8.4 Scenarios to execute

| ID | Scenario | What it tests |
|---|---|---|
| S1 | Robot-only transport | baseline ROX-Diff VDA order/state/path logic |
| S2 | Crane-only relocation | crane action catalogue without AMR |
| S3 | Normal AMR-crane handover | full mixed-fleet workflow |
| S4 | Crane busy when AMR arrives | waiting zone and postponement |
| S5 | AMR delayed while crane ready | timeout and recovery |
| S6 | Handover zone occupied | zone reservation/conflict |
| S7 | Suspended load active | no-go zone under crane load |
| S8 | Hoist below safe height | block AMR release |
| S9 | Priority job arrives | queue and priority policy |
| S10 | Cancel before dispatch | job-level cancellation |
| S11 | Cancel during AMR motion | v3.0 cancel semantics and safe stop |
| S12 | Cancel during crane hoist | non-cancellable/safety-boundary action |
| S13 | Crane action fails but is retriable | `RETRIABLE` action state |
| S14 | Communication loss | connection/error handling |
| S15 | Blocked aisle / replanning | path sharing and zone constraints |

---

## 9. Recommended New Repository Layout

For the migration, refactor the repository so it is easier to understand and publish.

```text
vda5050-v3-amr-crane-case-study/
├── README.md
├── docs/
│   ├── architecture.md
│   ├── vda5050_v2_to_v3_migration.md
│   ├── crane_usage_profile.md
│   ├── warehouse_case_study.md
│   └── scenarios.md
├── configs/
│   ├── mqtt.env.example
│   ├── crane.env.example
│   ├── rox.env.example
│   └── warehouse_layout.yaml
├── schemas/
│   └── vda5050_v3/
├── fleet_control/
│   ├── master_control.py
│   ├── scheduler.py
│   ├── zone_manager.py
│   └── scenario_runner.py
├── adapters/
│   ├── crane_adapter/
│   └── rox_diff_adapter/
├── simulation/
│   ├── warehouse_sim.py
│   ├── job_generator.py
│   └── event_logger.py
├── ros2_ws/
│   └── src/
│       ├── rox_vda5050_adapter/
│       ├── crane_vda5050_adapter/
│       └── vda5050_msgs_v3/
├── examples/
│   ├── orders/
│   ├── zone_sets/
│   └── scenarios/
└── results/
    ├── logs/
    ├── figures/
    └── tables/
```

---

## 10. Old-System Quick Start Notes

These commands are reconstructed from the old README notes and inspected launch files.

### Crane/Raspberry Pi side

```bash
cd ~/masters_thesis/ilmatar/vda5050_adapter/ON-GOING_TEST
source opcua-env/bin/activate
python3 crane_vda5050_adapter_TEST.py
python3 master_control_panel_TEST.py
```

Subscribe to crane topics:

```bash
mosquitto_sub -h 192.168.1.115 -p 1883 -t 'uagv/v2/konecranes/ilmatar_1/#' -v
```

Publish a crane order:

```bash
mosquitto_pub -h 192.168.1.115 -p 1883 \
  -t 'uagv/v2/konecranes/ilmatar_1/order' \
  -f order_ilmatar_TEST.json
```

### Dbot side

```bash
cd dbot_vda5050_ilmatar/
colcon build
source install/setup.bash

ros2 launch dbot_nav_slam auto_nav_dbot_launch.py
ros2 launch vda5050_tb3_adapter connector_tb3.launch.py
```

Subscribe to Dbot topics:

```bash
mosquitto_sub -h 192.168.1.115 -p 1883 -t 'uagv/v2/aaltoUniversity/dbot_1/#' -v
```

---

## 11. Paper-Relevant Interpretation

The current project already supports the basic claim that crane and AMR orchestration can be expressed through VDA 5050-style order/action/state messages. The next conference paper should not only say that the old project was updated to v3.0. A stronger contribution is:

> A VDA 5050 v3.0 scenario-based simulation and migration study for mixed warehouse jobs involving robot-only, crane-only, and coordinated AMR-crane workflows, using zones, path sharing, priority handling, cancellation, postponement, and recovery logic.

The old project provides:

- working VDA-to-crane action mapping;
- working VDA-to-ROS/Nav2 adapter concept;
- example orders for AMR and crane;
- master control orchestration logic;
- hoist-height-based AMR release gating;
- pause/resume/cancel/reset behaviours;
- MQTT topic structure and schema validation.

The new case study should add:

- VDA 5050 v3.0 message compliance;
- ROX-Diff AMR adapter;
- warehouse job scheduler;
- event tree for job outcomes;
- zone manager;
- scenario logs and outcome matrix;
- v2.x vs v3.0 migration comparison;
- crane usage profile for v3.0.

---

## 12. Immediate To-Do List

1. Clean repository: remove build/install/log/cache artifacts.
2. Move old notes into `docs/legacy/`.
3. Replace sensitive files with `.example` templates.
4. Freeze the old v2.x implementation under `legacy_v2/`.
5. Download/add official VDA 5050 v3.0 schemas under `schemas/vda5050_v3/`.
6. Create a `warehouse_case_study.yaml` layout with zones and job types.
7. Implement a pure Python message-level simulator first.
8. Define a ROX-Diff adapter interface from the current TB3 adapter.
9. Define a crane usage profile for v3.0 actions and states.
10. Run all scenarios and export logs/tables for the paper.

---

## 13. External References for Migration Context

- VDA5050 GitHub repository, current main version 3.0.0: https://github.com/VDA5050/VDA5050
- VDA5050 v3.0.0 release notes: https://github.com/VDA5050/VDA5050/releases
- Neobotix ROX-Diff product page: https://www.neobotix-robots.com/products/mobile-robots/mobile-robot-rox/rox-diff
- Neobotix ROX data sheet: https://www.neobotix-roboter.de/fileadmin/images/downloads/Datenbl%C3%A4tter/Data-Sheet_ROX.pdf
