# VDA 5050 v3 AMR–Crane Case Study

This repository is intended to support a VDA 5050 version 3.0 migration and warehouse case study based on an earlier AMR–overhead-crane project. The goal is to move from a VDA 5050 v2.x-style laboratory proof of concept toward a clearer VDA 5050 v3.0 architecture using:

- a fleet/master controller,
- an overhead crane edge adapter,
- a Neobotix ROX-Diff AMR running ROS 2/Nav2,
- VDA 5050 v3.0 MQTT/JSON messages,
- warehouse job scenarios,
- zone-based orchestration,
- simulation and event-tree evaluation.

The project should be treated as a mixed-fleet orchestration case study, not only as a software migration. The research question is whether VDA 5050 v3.0 can represent warehouse jobs that require an AMR only, a crane only, or coordinated AMR–crane handover, including priority handling, postponement, cancellation, blocked zones, failures, retries, and recovery.

---

## 1. System idea

The system is built around a task-level orchestration layer. The fleet controller receives or generates warehouse jobs, decides which resources are needed, and sends VDA 5050 v3.0 messages through MQTT. The crane and the AMR each keep their own local control systems.

```text
Warehouse job / scenario request
        |
        v
Fleet control / master controller
        |
        v
MQTT broker using VDA 5050 v3.0 topics
        |
        +--------------------------+
        |                          |
        v                          v
Crane edge adapter             ROX-Diff AMR adapter
Raspberry Pi / IPC             ROX-Diff onboard ROS 2 computer
        |                          |
        v                          v
OPC UA / PLC                   ROS 2 / Nav2 / robot drivers
        |                          |
        v                          v
Overhead crane                 Mobile robot
```

The important separation is:

- VDA 5050 is used for task-level communication.
- ROS 2/Nav2 remains responsible for AMR navigation.
- OPC UA/PLC remains responsible for crane control.
- Local safety systems remain authoritative.
- The fleet controller coordinates jobs, zones, states, and handover logic.

---

## 2. Recommended repository layout

The repository should be organized by deployment target. This makes it clear what runs on the fleet controller, what runs near the crane, what runs on the AMR, and what is only for simulation or research results.

```text
vda5050-v3-amr-crane-case-study/
├── README.md
├── docs/
│   ├── architecture.md
│   ├── deployment.md
│   ├── vda5050_v2_to_v3_migration.md
│   ├── crane_usage_profile.md
│   ├── warehouse_case_study.md
│   └── scenarios.md
├── configs/
│   ├── mqtt.env.example
│   ├── fleet_control.env.example
│   ├── crane_edge.env.example
│   ├── rox_diff.env.example
│   └── warehouse_layout.yaml
├── schemas/
│   └── vda5050_v3/
├── fleet_control/
│   ├── master_control.py
│   ├── scheduler.py
│   ├── zone_manager.py
│   ├── scenario_runner.py
│   └── requirements.txt
├── crane_edge/
│   ├── crane_vda5050_adapter.py
│   ├── opcua_client.py
│   ├── crane_state_mapper.py
│   ├── crane_action_mapper.py
│   └── requirements.txt
├── ros2_ws/
│   └── src/
│       ├── rox_vda5050_adapter/
│       ├── vda5050_msgs_v3/
│       └── rox_navigation_config/
├── simulation/
│   ├── warehouse_sim.py
│   ├── simulated_crane.py
│   ├── simulated_rox.py
│   ├── job_generator.py
│   └── event_logger.py
├── examples/
│   ├── orders/
│   ├── zone_sets/
│   └── scenarios/
├── scripts/
│   ├── run_fleet_control.sh
│   ├── run_crane_edge.sh
│   ├── run_simulation.sh
│   └── validate_messages.py
└── results/
    ├── logs/
    ├── figures/
    └── tables/
```

This layout is preferred over putting all adapters into one folder because the real crane adapter and real AMR adapter run in different environments with different dependencies.

---

## 3. Runtime deployment split

### 3.1 Fleet control side

**Runs on:**

- cloud service,
- development laptop,
- Raspberry Pi,
- industrial PC,
- server.

**Main folder:**

```text
fleet_control/
```

**Main responsibilities:**

- accept or generate warehouse jobs,
- classify jobs as AMR-only, crane-only, or AMR–crane,
- schedule jobs using priority and resource availability,
- reserve or release zones,
- generate VDA 5050 v3.0 orders,
- publish MQTT messages,
- subscribe to AMR and crane state messages,
- coordinate handover logic,
- cancel, postpone, retry, or recover jobs.

The fleet controller should not depend on ROS 2 or direct crane control libraries. It should communicate through MQTT and VDA 5050 messages only.

---

### 3.2 Crane edge side

**Runs on:**

- Raspberry Pi near the crane,
- industrial PC,
- edge device connected to the crane PLC or OPC UA server.

**Main folder:**

```text
crane_edge/
```

**Main responsibilities:**

- subscribe to VDA 5050 v3.0 crane orders/actions,
- translate crane actions into OPC UA/PLC commands,
- read bridge, trolley, hoist, and load state,
- publish crane state as VDA 5050 messages,
- report action progress and errors,
- enforce crane-specific adapter rules,
- keep unsafe or non-cancellable crane operations protected by local logic.

The crane adapter is not a ROS 2 package in the normal real-crane deployment. It belongs in `crane_edge/` because the crane is usually controlled through OPC UA/PLC rather than ROS 2.

---

### 3.3 ROX-Diff AMR side

**Runs on:**

- ROX-Diff onboard computer,
- ROS 2 environment on the robot.

**Main folder:**

```text
ros2_ws/src/rox_vda5050_adapter/
```

**Main responsibilities:**

- connect to the MQTT broker,
- subscribe to VDA 5050 v3.0 AMR orders,
- translate VDA 5050 nodes, edges, and actions into ROS 2/Nav2 commands,
- publish robot state back to the fleet controller,
- report position, velocity, battery, errors, current node/edge/action state,
- handle pause/cancel/retry where supported by the robot stack,
- optionally publish planned or intermediate path information if supported.

The ROX-Diff adapter should live inside the ROS 2 workspace because it needs access to ROS 2 topics, actions, TF, odometry, Nav2, and robot drivers.

---

### 3.4 Simulation side

**Runs on:**

- development laptop,
- CI environment,
- research workstation.

**Main folder:**

```text
simulation/
```

**Main responsibilities:**

- simulate AMR movement times,
- simulate crane movement/action times,
- simulate job arrivals,
- simulate zone occupation,
- inject delays, cancellations, failures, and communication loss,
- log state transitions and scenario outcomes,
- generate data for tables and figures.

Simulation is used for the conference-paper case study. It allows the event tree to be executed without needing the real crane or ROX-Diff available at all times.

---

## 4. Folder-by-folder documentation

### 4.1 `README.md`

The entry point for the repository.

It should explain:

- the project goal,
- the relation to the older VDA 5050 v2.x AMR–crane implementation,
- the VDA 5050 v3.0 migration target,
- the system architecture,
- deployment targets,
- how to run simulation,
- how to run the crane adapter,
- how to run the ROX-Diff adapter,
- where scenarios, schemas, logs, and results are stored.

---

### 4.2 `docs/`

The documentation folder contains detailed design notes and paper-supporting material.

```text
docs/
├── architecture.md
├── deployment.md
├── vda5050_v2_to_v3_migration.md
├── crane_usage_profile.md
├── warehouse_case_study.md
└── scenarios.md
```

#### `docs/architecture.md`

Explains the complete system architecture.

It should include:

- fleet control architecture,
- MQTT topic flow,
- AMR adapter architecture,
- crane adapter architecture,
- simulation architecture,
- message sequence diagrams,
- deployment diagrams.

It should clearly show that VDA 5050 is the task-level interface, while ROS 2/Nav2 and OPC UA/PLC remain local asset-control layers.

#### `docs/deployment.md`

Explains how to deploy each part.

Recommended sections:

- fleet controller deployment,
- crane edge deployment,
- ROX-Diff ROS 2 deployment,
- simulation-only deployment,
- MQTT broker setup,
- environment variables,
- network assumptions,
- troubleshooting.

#### `docs/vda5050_v2_to_v3_migration.md`

Documents the migration from the older implementation to VDA 5050 v3.0.

It should cover:

- old topic root such as `uagv/v2/...`,
- new VDA 5050 v3.0 topic expectations,
- order message changes,
- state message changes,
- action-state changes,
- blocking-type changes,
- cancellation behavior,
- pause and retry behavior,
- zone-set support,
- planned/intermediate path support,
- error-level changes,
- factsheet/capability updates.

This file is important for the conference paper because it becomes the technical migration evidence.

#### `docs/crane_usage_profile.md`

Defines how the overhead crane is represented as a VDA 5050 participant.

This is one of the most important documents because VDA 5050 does not natively define overhead-crane semantics.

It should define crane actions such as:

```text
moveBridge
moveTrolley
raiseHoist
lowerHoist
attachLoad
releaseLoad
moveToHandover
waitForTrigger
```

It should define crane state fields such as:

```text
bridge_position
trolley_position
hoist_height
load_attached
safe_height_reached
crane_busy
handover_ready
fault_active
```

It should also define whether each action can be paused or cancelled.

Example:

```text
moveBridge:    pauseAllowed=true,  cancelAllowed=true
moveTrolley:   pauseAllowed=true,  cancelAllowed=true
lowerHoist:    pauseAllowed=true,  cancelAllowed=false
raiseHoist:    pauseAllowed=true,  cancelAllowed=false
attachLoad:    pauseAllowed=false, cancelAllowed=false
releaseLoad:   pauseAllowed=false, cancelAllowed=false
```

These distinctions are important for VDA 5050 v3.0 because actions can have clearer pause, cancel, failed, and retriable behavior.

#### `docs/warehouse_case_study.md`

Describes the warehouse case study.

It should define:

- warehouse layout,
- storage area,
- shipping area,
- AMR travel lanes,
- crane workspace,
- handover zone,
- waiting zone,
- restricted zones,
- no-go zone under suspended load,
- job types,
- assumptions and limitations.

The case study should be described honestly as a representative scenario-based simulation, not as a validated industrial deployment unless real industrial data is later added.

#### `docs/scenarios.md`

Documents all event-tree scenarios.

Recommended scenarios:

```text
S1: Normal AMR-only transport
S2: Normal crane-only lift or relocation
S3: Normal AMR–crane handover
S4: Priority AMR–crane job enters queue
S5: Crane busy when AMR arrives
S6: AMR delayed while crane waits
S7: Handover zone occupied
S8: Suspended-load zone active
S9: Hoist below safe height blocks AMR release
S10: Job cancelled before dispatch
S11: Job cancelled during AMR movement
S12: Job cancelled during crane action
S13: Job postponed due to unavailable resource
S14: Crane action timeout
S15: Communication loss
S16: Retriable crane action failure
S17: Emergency or intervention state
```

Each scenario should specify:

- initial conditions,
- job request,
- required resources,
- expected VDA 5050 orders/actions,
- expected state transitions,
- expected result,
- logs or metrics to collect.

---

### 4.3 `configs/`

Stores environment and layout configuration templates.

```text
configs/
├── mqtt.env.example
├── fleet_control.env.example
├── crane_edge.env.example
├── rox_diff.env.example
└── warehouse_layout.yaml
```

#### `mqtt.env.example`

Shared MQTT settings.

Example:

```env
MQTT_HOST=192.168.1.50
MQTT_PORT=1883
MQTT_USERNAME=
MQTT_PASSWORD=
VDA_VERSION=3.0.0
```

#### `fleet_control.env.example`

Fleet controller settings.

Example:

```env
FLEET_ID=aalto_case_study
SCENARIO_FILE=examples/scenarios/s03_normal_robot_crane_handover.yaml
WAREHOUSE_LAYOUT=configs/warehouse_layout.yaml
MESSAGE_SCHEMA_DIR=schemas/vda5050_v3
```

#### `crane_edge.env.example`

Crane adapter settings.

Example:

```env
CRANE_ID=ilmatar
MQTT_CLIENT_ID=crane_adapter_ilmatar
OPCUA_ENDPOINT=opc.tcp://192.168.1.20:4840
SAFE_HOIST_HEIGHT=1.5
DEFAULT_BRIDGE_SPEED=0.3
DEFAULT_TROLLEY_SPEED=0.3
DEFAULT_HOIST_SPEED=0.1
```

#### `rox_diff.env.example`

ROX-Diff AMR adapter settings.

Example:

```env
ROBOT_ID=rox_diff_001
MQTT_CLIENT_ID=rox_diff_adapter_001
ROS_DOMAIN_ID=0
NAV2_ACTION_SERVER=/navigate_to_pose
BASE_FRAME=base_link
MAP_FRAME=map
ODOM_FRAME=odom
```

#### `warehouse_layout.yaml`

Defines the case-study layout.

Example structure:

```yaml
nodes:
  - id: storage_A
    x: 0.0
    y: 0.0
  - id: handover_1
    x: 5.0
    y: 2.0
  - id: shipping_B
    x: 10.0
    y: 0.0

zones:
  - id: crane_workspace
    type: restricted
    polygon: [[4, 1], [8, 1], [8, 5], [4, 5]]
  - id: handover_zone
    type: release
    polygon: [[4.5, 1.5], [5.5, 1.5], [5.5, 2.5], [4.5, 2.5]]
  - id: suspended_load_zone
    type: blocked
    active_when: crane.load_attached == true
```

---

### 4.4 `schemas/`

Stores VDA 5050 v3.0 JSON schemas.

```text
schemas/
└── vda5050_v3/
```

Used for:

- validating generated orders,
- validating state messages,
- validating connection messages,
- validating factsheets,
- validating zone sets,
- validating examples,
- validating logs during simulation.

Schema validation is useful for research results because the paper can report that generated messages were checked against VDA 5050 v3.0 schema definitions.

---

### 4.5 `fleet_control/`

Contains the master-control logic.

```text
fleet_control/
├── master_control.py
├── scheduler.py
├── zone_manager.py
├── scenario_runner.py
└── requirements.txt
```

#### `master_control.py`

Main orchestration application.

Responsible for:

- MQTT connection,
- VDA 5050 message publishing,
- VDA 5050 state subscription,
- job execution tracking,
- AMR–crane coordination,
- handover gating,
- cancellation/postponement/retry handling,
- event logging.

Example logic:

```text
If AMR reaches handover zone and crane is ready:
    start crane pickup sequence

If hoist is below safe height:
    keep AMR blocked

If crane action fails and is retriable:
    issue retry or mark job for recovery
```

#### `scheduler.py`

Handles job queue and priority rules.

Responsible for:

- storing jobs,
- sorting jobs by priority,
- checking required resources,
- deciding whether a job is ready,
- postponing jobs,
- dispatching the next feasible job.

Example job classes:

```text
AMR_ONLY
CRANE_ONLY
AMR_CRANE
AMR_CRANE_OPERATOR_CONFIRMATION
```

#### `zone_manager.py`

Handles VDA 5050 v3.0 zone logic.

Responsible for:

- maintaining active zones,
- activating blocked zones,
- releasing handover zones,
- checking whether a robot can enter a zone,
- handling no-go zones under suspended load,
- creating zone-set messages.

Example:

```text
If crane.load_attached is true:
    activate suspended_load_zone as BLOCKED

If AMR requests entry into handover zone:
    allow only if crane is ready and the zone is reserved for that job
```

#### `scenario_runner.py`

Runs defined case-study scenarios.

Responsible for:

- loading scenario YAML files,
- initializing job and resource states,
- starting the scheduler,
- injecting events,
- collecting logs and metrics.

Example usage:

```bash
python fleet_control/scenario_runner.py \
  --scenario examples/scenarios/s03_normal_robot_crane_handover.yaml
```

---

### 4.6 `crane_edge/`

Contains the real crane-side adapter.

```text
crane_edge/
├── crane_vda5050_adapter.py
├── opcua_client.py
├── crane_state_mapper.py
├── crane_action_mapper.py
└── requirements.txt
```

#### `crane_vda5050_adapter.py`

Main crane adapter.

Responsible for:

- connecting to MQTT,
- subscribing to crane-related VDA 5050 orders,
- parsing crane actions,
- invoking crane action mapper,
- publishing state/action updates,
- reporting errors.

#### `opcua_client.py`

Handles OPC UA communication with the crane PLC or crane control interface.

Responsible for:

- connecting to OPC UA server,
- reading bridge/trolley/hoist positions,
- writing target commands,
- reading load/fault/status flags,
- handling reconnects.

#### `crane_state_mapper.py`

Maps crane PLC/OPC UA values to VDA 5050 state fields.

Example mappings:

```text
PLC bridge position   -> crane state position/action feedback
PLC hoist height      -> custom crane state / safe-height logic
PLC load attached     -> load state
PLC fault active      -> VDA 5050 errors
```

#### `crane_action_mapper.py`

Maps VDA 5050 actions to crane commands.

Example mappings:

```text
moveBridge(target_x)  -> OPC UA bridge target write
moveTrolley(target_y) -> OPC UA trolley target write
raiseHoist(height)    -> OPC UA hoist target write
lowerHoist(height)    -> OPC UA hoist target write
attachLoad            -> crane load attach/confirmation sequence
releaseLoad           -> crane load release sequence
```

This module should also decide whether an action is pauseable, cancellable, or retriable.

---

### 4.7 `ros2_ws/`

ROS 2 workspace for the ROX-Diff AMR.

```text
ros2_ws/
└── src/
    ├── rox_vda5050_adapter/
    ├── vda5050_msgs_v3/
    └── rox_navigation_config/
```

#### `ros2_ws/src/rox_vda5050_adapter/`

The real ROX-Diff VDA 5050 adapter.

Responsible for:

- MQTT connection,
- receiving VDA 5050 v3.0 AMR orders,
- converting order nodes/edges into Nav2 goals,
- sending goals to Nav2,
- monitoring goal execution,
- publishing VDA 5050 state messages,
- reporting robot pose, velocity, battery, and action states,
- handling cancel/pause/retry when supported.

Example flow:

```text
VDA 5050 order node: handover_1
        |
        v
Nav2 NavigateToPose goal
        |
        v
ROX-Diff drives to handover point
        |
        v
Adapter publishes node reached / action finished
```

#### `ros2_ws/src/vda5050_msgs_v3/`

Optional ROS 2 message definitions mirroring VDA 5050 v3.0 structures.

Important note:

VDA 5050 itself is JSON over MQTT. ROS 2 messages are only an internal convenience for the robot-side implementation. The external interface remains VDA 5050 MQTT/JSON.

#### `ros2_ws/src/rox_navigation_config/`

Navigation configuration for ROX-Diff.

May include:

- Nav2 parameters,
- maps,
- costmap settings,
- localization settings,
- robot frames,
- launch files.

This is robot-specific and should stay separate from fleet-control logic.

---

### 4.8 `simulation/`

Contains fake AMR, fake crane, warehouse model, and event logging.

```text
simulation/
├── warehouse_sim.py
├── simulated_crane.py
├── simulated_rox.py
├── job_generator.py
└── event_logger.py
```

#### `warehouse_sim.py`

Main simulation engine.

Responsible for:

- maintaining simulated time,
- updating robot/crane states,
- handling zone occupation,
- checking handover conditions,
- injecting failures and delays.

#### `simulated_crane.py`

Simulated crane participant.

Responsible for:

- simulating bridge/trolley/hoist movement,
- simulating load pickup/release,
- producing VDA 5050-like state updates,
- simulating crane faults or timeouts.

#### `simulated_rox.py`

Simulated ROX-Diff participant.

Responsible for:

- simulating travel between warehouse nodes,
- simulating arrival delays,
- simulating blocked paths,
- producing VDA 5050-like state updates.

#### `job_generator.py`

Generates warehouse jobs.

Example jobs:

```text
Move pallet from storage A to shipping B
Move load using crane only
Move load through AMR–crane handover
Cancel job after dispatch
Inject high-priority job
Delay crane availability
```

#### `event_logger.py`

Records scenario execution.

Should log:

- job events,
- VDA 5050 orders,
- VDA 5050 state updates,
- action-state transitions,
- zone activations,
- cancellations,
- retries,
- failures,
- recovery outcomes,
- completion times.

---

### 4.9 `examples/`

Stores reusable example messages and scenarios.

```text
examples/
├── orders/
├── zone_sets/
└── scenarios/
```

#### `examples/orders/`

Example VDA 5050 v3.0 order messages.

Suggested files:

```text
robot_only_transport_order.json
crane_only_lift_order.json
robot_crane_handover_order.json
cancel_order.json
retry_action.json
```

#### `examples/zone_sets/`

Example VDA 5050 v3.0 zone-set messages.

Suggested files:

```text
warehouse_zones_basic.json
crane_handover_zone_set.json
suspended_load_blocked_zone.json
priority_corridor_zone.json
```

#### `examples/scenarios/`

Scenario definitions for the event-tree simulation.

Suggested files:

```text
s01_normal_robot_only.yaml
s02_normal_crane_only.yaml
s03_normal_robot_crane_handover.yaml
s04_priority_job.yaml
s05_crane_busy.yaml
s06_amr_delayed.yaml
s07_handover_zone_occupied.yaml
s08_suspended_load_zone_block.yaml
s09_cancel_before_dispatch.yaml
s10_cancel_during_amr_motion.yaml
s11_cancel_during_crane_action.yaml
s12_retriable_crane_failure.yaml
s13_communication_loss.yaml
```

---

### 4.10 `scripts/`

Utility scripts.

```text
scripts/
├── run_fleet_control.sh
├── run_crane_edge.sh
├── run_simulation.sh
└── validate_messages.py
```

#### `run_fleet_control.sh`

Starts fleet control with the correct environment variables.

#### `run_crane_edge.sh`

Starts the crane edge adapter.

#### `run_simulation.sh`

Runs simulation scenarios.

#### `validate_messages.py`

Validates example and generated JSON messages against VDA 5050 v3.0 schemas.

This script is useful for both development and research reporting.

---

### 4.11 `results/`

Stores output for the conference paper.

```text
results/
├── logs/
├── figures/
└── tables/
```

#### `results/logs/`

Stores raw logs.

Examples:

```text
s03_normal_handover_mqtt_log.jsonl
s05_crane_busy_event_log.csv
s12_retriable_failure_state_trace.json
```

#### `results/figures/`

Stores generated figures.

Examples:

```text
architecture_diagram.pdf
job_state_machine.pdf
event_tree.pdf
zone_layout.pdf
scenario_completion_times.pdf
```

#### `results/tables/`

Stores tables for the paper.

Examples:

```text
scenario_outcome_matrix.csv
v2_to_v3_migration_matrix.csv
crane_action_profile.csv
state_coverage_table.csv
```

---

## 5. Why deployment separation matters

The separation matters because each part has different dependencies.

| Component | Folder | Deployment target | Main dependencies |
|---|---|---|---|
| Fleet control | `fleet_control/` | Cloud, laptop, server, or Raspberry Pi | Python, MQTT, JSON schema |
| Crane edge adapter | `crane_edge/` | Raspberry Pi or industrial PC near crane | Python, MQTT, OPC UA |
| ROX-Diff adapter | `ros2_ws/src/rox_vda5050_adapter/` | ROX-Diff onboard computer | ROS 2, Nav2, MQTT |
| Simulation | `simulation/` | Development laptop or CI | Python, logging, optional MQTT |
| Schemas/config/examples | `schemas/`, `configs/`, `examples/` | Shared | No heavy runtime dependency |
| Results | `results/` | Research output | Logs, figures, tables |

This avoids unnecessary dependencies. The crane Pi should not need ROS 2. The ROX-Diff should not need OPC UA crane libraries. The fleet controller should not depend on robot drivers. Simulation should be able to run without real hardware.

---

## 6. VDA 5050 v3.0 concepts used in this project

The migration should use VDA 5050 v3.0 as more than a schema update. The useful v3.0 concepts for this project are:

### 6.1 Zones

Zones can represent:

```text
AMR waiting zone
Crane workspace
Crane handover zone
No-go zone under suspended load
Blocked aisle
Priority corridor
Release zone
```

This is central to the warehouse case study because AMR–crane handover is mostly about allowing or preventing access to shared space at the correct time.

### 6.2 Planned and intermediate paths

For a more autonomous AMR such as ROX-Diff, the adapter may allow the robot to report planned or intermediate path information back to the fleet controller. This helps the fleet controller understand the robot's movement intention near the crane workspace.

### 6.3 Action states

Crane and AMR actions should be tracked using action-state transitions.

Typical states:

```text
WAITING
INITIALIZING
RUNNING
PAUSED
FINISHED
FAILED
RETRIABLE
```

`RETRIABLE` is especially useful for crane handover failures where retry is possible.

### 6.4 Blocking types

Blocking types should be used to describe how actions affect driving or parallel action execution.

For crane handover:

- some actions may allow AMR movement,
- some actions should block only related actions,
- some actions should block the entire workflow.

### 6.5 Pause and cancel behavior

Crane actions must be carefully classified.

Some actions may be safe to cancel:

```text
moveBridge
moveTrolley
```

Some actions may not be safe to cancel once started:

```text
lowerHoist
attachLoad
releaseLoad
```

This distinction should be documented in `docs/crane_usage_profile.md`.

### 6.6 Error levels and recovery

The simulation should include:

```text
warning
normal failure
urgent fault
critical fault
communication loss
timeout
retriable action failure
non-retriable action failure
```

The case study should report how the system reacts to each.

---

## 7. Case-study job lifecycle

The project should model the full job lifecycle, not only robot movement.

```text
NEW_JOB
  |
  v
VALIDATED
  |
  v
CLASSIFIED
  |
  v
QUEUED
  |
  v
RESOURCE_CHECK
  |
  v
ZONE_CHECK
  |
  v
ASSIGNED
  |
  v
DISPATCHED
  |
  v
EXECUTING
  |
  +-------------------------+
  |                         |
  v                         v
WAITING_FOR_HANDOVER     WAITING_FOR_RESOURCE
  |                         |
  v                         v
COMPLETED              POSTPONED / FAILED / RECOVERING
```

Exception states:

```text
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

This lifecycle should be implemented in the scheduler and scenario runner.

---

## 8. Recommended scenario set

The project should execute a finite set of representative scenarios rather than trying to model every possible warehouse state.

| ID | Scenario | Main purpose |
|---|---|---|
| S1 | Normal AMR-only transport | Baseline robot order execution |
| S2 | Normal crane-only operation | Crane action profile |
| S3 | Normal AMR–crane handover | Full mixed-fleet workflow |
| S4 | Priority job enters queue | Scheduler and priority logic |
| S5 | Crane busy when AMR arrives | Waiting/staging logic |
| S6 | AMR delayed while crane waits | Timeout/postponement logic |
| S7 | Handover zone occupied | Zone reservation logic |
| S8 | Suspended-load zone active | No-go zone under load |
| S9 | Hoist below safe height | AMR release gating |
| S10 | Cancel before dispatch | Queue cancellation |
| S11 | Cancel during AMR movement | Cancel order and recovery |
| S12 | Cancel during crane action | Safety boundary |
| S13 | Postpone due to resource unavailability | Rescheduling |
| S14 | Crane action timeout | Failure and retry logic |
| S15 | Communication loss | Connection/error handling |
| S16 | Retriable crane action failure | `RETRIABLE` action flow |
| S17 | Emergency or intervention state | Safe halt boundary |

---

## 9. Expected research outputs

The repository should support the following paper outputs:

### 9.1 Architecture diagram

Shows:

```text
Fleet control -> MQTT broker -> ROX-Diff adapter / crane adapter
```

### 9.2 VDA 5050 v2.x to v3.0 migration matrix

Compares:

- topics,
- message fields,
- order structure,
- state structure,
- action states,
- zones,
- cancellation,
- retry logic,
- factsheet/capabilities.

### 9.3 Crane usage profile

Defines:

- crane action catalogue,
- crane state variables,
- pause/cancel/retry rules,
- handover conditions,
- safety-related limits.

### 9.4 Warehouse scenario model

Defines:

- layout,
- nodes,
- zones,
- job types,
- assumptions.

### 9.5 Event tree and state machine

Shows:

- job lifecycle,
- normal execution,
- cancellation branches,
- postponement branches,
- failure/retry/recovery branches.

### 9.6 Scenario outcome matrix

Records:

- which scenarios completed,
- which were cancelled,
- which were postponed,
- which failed,
- which required recovery,
- which VDA 5050 v3.0 concepts were used.

### 9.7 Logs and metrics

Possible metrics:

```text
schema-valid message count
job completion outcome
number of state transitions
number of zone conflicts
number of retries
handover wait time
simulated mission duration
failure recovery result
```

Avoid claiming real industrial throughput improvement unless real operational data is added.

---

## 10. Suggested development order

Recommended implementation order:

1. Create `schemas/vda5050_v3/`.
2. Create example VDA 5050 v3.0 messages in `examples/`.
3. Implement `scripts/validate_messages.py`.
4. Implement `configs/warehouse_layout.yaml`.
5. Implement simulation-only `simulated_rox.py` and `simulated_crane.py`.
6. Implement `fleet_control/scheduler.py`.
7. Implement `fleet_control/zone_manager.py`.
8. Implement `fleet_control/scenario_runner.py`.
9. Generate results for the paper.
10. Replace simulated ROX with real `ros2_ws/src/rox_vda5050_adapter/`.
11. Replace simulated crane with real `crane_edge/crane_vda5050_adapter.py`.
12. Compare VDA 5050 v2.x and v3.0 behavior.

This order gives useful research results early, before full hardware integration is complete.

---

## 11. Notes on older project migration

The older project contained two major runtime sides:

1. Raspberry Pi / crane side:
   - crane OPC UA client,
   - VDA 5050 crane adapter,
   - simple master-control panel,
   - old order templates,
   - older VDA 5050 schemas.

2. ROS 2 / Dbot side:
   - VDA 5050 connector,
   - TurtleBot/Dbot adapter,
   - Nav2 and SLAM packages,
   - low-level motion and odometry packages.

The new project should not simply copy the old structure. It should separate components by deployment target and update the design for VDA 5050 v3.0 and the ROX-Diff AMR.

Main migration changes:

```text
Dbot-specific ROS 2 adapter      -> ROX-Diff ROS 2/Nav2 adapter
Ilmatar crane adapter            -> crane_edge VDA 5050 v3 adapter
old master control panel         -> fleet_control scheduler + zone manager
old static handover workflow     -> scenario/event-tree job lifecycle
old VDA 5050 v2.x schemas        -> VDA 5050 v3.0 schemas
hard-coded handover logic        -> documented crane usage profile
limited lab test                 -> warehouse simulation case study
```

---

## 12. Design principles

Use these principles throughout the repository:

1. Keep VDA 5050 as the external communication layer.
2. Keep ROS 2-specific code inside `ros2_ws/`.
3. Keep crane OPC UA/PLC code inside `crane_edge/`.
4. Keep fleet scheduling independent of robot and crane drivers.
5. Make simulation runnable without hardware.
6. Validate VDA 5050 messages against schemas.
7. Store all example orders, zones, and scenarios.
8. Log every scenario in a reproducible format.
9. Document crane-specific conventions as a usage profile.
10. Do not claim safety certification; local safety systems remain authoritative.

---

## 13. Quick start: simulation mode

A future implementation should support a flow like this:

```bash
# 1. Install Python dependencies
pip install -r fleet_control/requirements.txt

# 2. Run message validation
python scripts/validate_messages.py examples/orders/ schemas/vda5050_v3/

# 3. Run a scenario
python fleet_control/scenario_runner.py \
  --scenario examples/scenarios/s03_normal_robot_crane_handover.yaml

# 4. Inspect results
ls results/logs/
ls results/tables/
ls results/figures/
```

---

## 14. Quick start: real crane edge

A future real-crane deployment should support:

```bash
cd crane_edge
cp ../configs/crane_edge.env.example .env
# edit .env with OPC UA endpoint and crane parameters
pip install -r requirements.txt
python crane_vda5050_adapter.py
```

This should be run on the Raspberry Pi or industrial PC connected to the crane control system.

---

## 15. Quick start: ROX-Diff AMR

A future ROX-Diff deployment should support:

```bash
cd ros2_ws
colcon build
source install/setup.bash
ros2 launch rox_vda5050_adapter rox_vda5050_adapter.launch.py
```

This should be run on the ROX-Diff onboard computer in the same network as the MQTT broker.

---

## 16. Final recommended interpretation

This repository should be understood as a research and implementation framework for:

```text
VDA 5050 v3.0 mixed-fleet warehouse orchestration
with a ROX-Diff AMR and an overhead crane.
```

The project is strongest if it does not only update old code. It should demonstrate how VDA 5050 v3.0 concepts such as zones, action states, path sharing, cancellation, pause, retry, and error handling can be used to model realistic warehouse job logic.

The main conference-paper contribution should be:

```text
A scenario-based VDA 5050 v3.0 simulation and migration framework
for AMR–overhead-crane warehouse orchestration,
including job-state logic, zone handling, crane usage profiles,
and comparison against the older AMR–crane VDA 5050 implementation.
```
