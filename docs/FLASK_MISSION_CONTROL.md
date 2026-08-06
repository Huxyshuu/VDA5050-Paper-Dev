# VDA 5050 v3 Mission-Control Dashboard

This document describes the Raspberry Pi Flask dashboard used to operate and observe the current ROX-Diff + Ilmatar research cell.

The dashboard is intentionally **ROX-first** for the present test phase:

- The Neobotix ROX-Diff is available for waypoint and scenario tests.
- The Ilmatar crane remains visible in the architecture and UI, but is disabled until it is commissioned again.
- No dashboard button silently falls back to a non-VDA command.
- Movement, pause, resume, cancellation, retry and skip-retry are sent through the VDA 5050 v3 MQTT interface.

## 1. Runtime architecture

```text
Browser
  |
  | HTTP / JSON
  v
Raspberry Pi Flask master controller
  |
  | MQTT, VDA 5050 v3.0.0
  v
Mosquitto broker on Raspberry Pi
  |
  +--> ROX-Diff adapter --> Nav2 --> ROX-Diff
  |
  +--> Crane adapter (retained, currently unavailable)
```

Default site addresses:

| Component | Address |
|---|---|
| Raspberry Pi Ethernet / MQTT / Flask | `192.168.50.115` |
| Raspberry Pi Wi-Fi | `192.168.0.116` |
| ROX-Diff | `192.168.50.50` |
| Flask dashboard | `http://192.168.50.115:5000` |

## 2. Dashboard sections

### Current command chain

Shows the latest dashboard-dispatched VDA order. The progress model is derived from:

- `orderId`
- `lastNodeId`
- `lastNodeSequenceId`
- `nodeStates`
- `edgeStates`
- `driving`
- `paused`
- `actionStates`
- `errors`

The timeline classifies each node and edge as:

- completed
- active
- upcoming
- cancelled

No timer is used to pretend an order has completed.

### Dynamic waypoint destinations

Waypoint buttons are loaded from:

```text
configs/rox_waypoints.yaml
```

Adding or capturing a new valid waypoint automatically creates a new dashboard card after the next poll. The Flask template does not contain a hard-coded waypoint list.

A movement button is disabled when dispatch is unsafe or invalid, including:

- MQTT disconnected
- ROX VDA connection not `ONLINE`
- state older than the configured VDA heartbeat limit
- no schema-valid state received
- another order active
- unsuitable operating mode
- emergency stop active
- safety field violation active
- localization invalid
- waypoint YAML not marked `configured: true`

### Immediate VDA controls

The ROX control panel offers:

| UI control | VDA 5050 v3 instant action |
|---|---|
| Pause | `startPause` |
| Resume | `stopPause` |
| Cancel order | `cancelOrder` |
| Retry action | `retry` with `actionId` |
| Skip retry | `skipRetry` with `actionId` |
| Request factsheet | `factsheetRequest` |

Controls are enabled from the latest state. For example, Resume is disabled unless `paused` is true, and retry controls only become available when an order action reports `RETRIABLE`.

### Scenarios

Scenario definitions are loaded from:

```text
configs/dashboard_scenarios.yaml
```

A scenario is not sent as an undocumented custom message. Instead, the scenario engine dispatches one normal VDA 5050 new order at a time. The next motion is sent only after the previous VDA command has reached its terminal state.

Current defaults:

1. **Short commissioning loop**: `home -> short_test -> home`
2. **ROX case-study route**: `home -> short_test -> crane_handover -> warehouse_dropoff -> home`
3. **ROX crane approach**: `crane_handover` without sending a crane command
4. **Coordinated crane handover**: sends the two verified stored orders together
5. **Sequential pickup and warehouse delivery**: runs 15 crane, ROX-Diff and confirmation steps one at a time

When starting the sequential pickup/delivery scenario, the modal offers two
per-run policies for its three physical transfer gates. Manual confirmation is
the default. The optional timed policy completes each gate after five seconds;
it is server-side, remains auditable as a timeout rather than a human action,
and does not claim that a payload sensor verified the transfer.

### Cell status

Displays the server, MQTT link, robot and crane. ROX information includes:

- VDA connection state
- operating mode
- current pose and map
- localization validity
- motion and pause state
- battery state when reported
- emergency-stop state
- safety-field violation
- active errors

The crane remains visible as unavailable, avoiding the misleading impression that the project no longer includes it.

### Event log and mission history

The in-memory event log records:

- dashboard startup
- order dispatches
- mission-state transitions
- scenario starts and finishes
- pause/resume/cancel/retry actions
- device-state transitions
- scenario errors

Mission history is retained for the current Flask process. It is not intended as a permanent audit database.

## 3. VDA 5050 v3 order construction

A dashboard waypoint command creates a new order with:

```text
orderUpdateId = 0
node sequence IDs = 0 and 2
edge sequence ID = 1
all nodes and edges released = true
edge actions = []
```

The base is:

```text
Temporary current-pose node
    -> navigation edge
Target waypoint node
```

The first node uses the latest schema-valid `mobileRobotPosition` from the ROX state. This is necessary because the current adapter verifies that the first released node is reachable from the real current robot pose.

The target pose comes from `configs/rox_waypoints.yaml`. The dashboard converts the configured scalar XY tolerance to the v3 ellipse structure:

```json
{
  "allowedDeviationXY": {
    "a": 0.2,
    "b": 0.2,
    "theta": 0.0
  }
}
```

Before MQTT publishing, the existing master controller:

1. stamps the VDA header fields;
2. assigns the target manufacturer and serial number;
3. validates against the official local `order.schema`;
4. publishes to the ROX order topic;
5. indexes order actions for the existing handover orchestration.

## 4. VDA-state interpretation

The dashboard uses state arrays and fields defined for protocol operation. It does **not** use `information[]` for dispatch, completion, safety or scenario progression.

Dashboard mission labels are UI projections, not additional VDA fields:

| Dashboard status | Evidence |
|---|---|
| `SENT` | Published locally; waiting for matching robot `orderId` |
| `ACCEPTED` | Matching `orderId`, remaining base, not currently driving |
| `RUNNING` | Matching order and `driving: true` |
| `PAUSED` | Matching order and `paused: true` |
| `RETRIABLE` | At least one order action reports `RETRIABLE` |
| `CANCELLING` | `cancelOrder` sent; robot still reports remaining order work |
| `CANCELLED` | Cancel requested and order work has stopped |
| `FINISHED` | Matching order with empty node/edge states and terminal action states |
| `REJECTED` | Order-referenced error or another order remains active after dispatch |
| `FAILED` | Failed action or order-referenced critical/fatal error |

VDA 5050 v3 does not provide a separate generic `orderStatus` field, so the dashboard does not invent one on the wire.

## 5. Configuration

Add these values to `configs/fleet_control.env`:

```dotenv
VDA_MQTT_HOST=192.168.50.115
VDA_MQTT_PORT=1883
VDA_DEFAULT_MAP_ID=df_map
ROX_INIT_MAP_ID=df_map

ROX_ENABLED=true
CRANE_ENABLED=false
ROX_WAYPOINT_FILE=configs/rox_waypoints.yaml
FLEET_UI_SCENARIO_FILE=configs/dashboard_scenarios.yaml

FLEET_UI_REQUIRE_LOCALIZED=true
FLEET_UI_REQUIRE_CONFIGURED_WAYPOINTS=true
FLEET_UI_START_TOLERANCE_M=0.35
FLEET_UI_STATE_STALE_S=35.0
FLEET_UI_ORDER_ACCEPT_TIMEOUT_S=12.0
FLEET_UI_EVENT_LIMIT=300
FLEET_UI_MISSION_LIMIT=50
```

Relative paths are resolved from the repository root.

The retained `connection` message is checked by `connectionState`, not by age. VDA 5050 v3 explicitly notes that connection timestamps and header IDs can remain outdated because liveness is detected through MQTT heartbeat/last-will handling. The master stores local message-arrival timestamps, so freshness does not depend on the ROX and Pi clocks being perfectly synchronized. The state staleness default is 35 seconds because a state shall be published at least every 30 seconds.

## 6. Install on the Raspberry Pi

From the repository root:

```bash
cd ~/VDA5050-Paper-Dev

git switch main
git pull --ff-only

python3 -m venv .venv
source .venv/bin/activate
pip install --upgrade pip
pip install -r fleet_control/requirements.txt
```

Verify the local v3 schemas exist:

```bash
ls schemas/vda5050_v3/order.schema
ls schemas/vda5050_v3/instantActions.schema
ls schemas/vda5050_v3/state.schema
ls schemas/vda5050_v3/connection.schema
ls schemas/vda5050_v3/factsheet.schema
```

Start Mosquitto if it is not already running:

```bash
sudo systemctl enable --now mosquitto
sudo systemctl status mosquitto --no-pager
```

Start the master controller:

```bash
cd ~/VDA5050-Paper-Dev
source .venv/bin/activate
python3 fleet_control/master_control.py
```

Open:

```text
http://192.168.50.115:5000
```

## 7. Recommended ROX-first test sequence

### Stage A: no physical motion

1. Start Mosquitto and the Flask master controller.
2. Start the ROX VDA adapter in dry-run mode.
3. Open the dashboard.
4. Confirm:
   - server is online;
   - MQTT is connected;
   - ROX connection becomes online;
   - crane appears unavailable;
   - waypoint cards appear dynamically;
   - the factsheet request button works.
5. Send `home` or `short_test` in dry-run mode.
6. Observe the mission transition through the VDA state.
7. Test pause, resume and cancel.

### Stage B: supervised short motion

1. Start native ROX bringup and Nav2.
2. Confirm localization and map alignment in RViz.
3. Start the adapter in real mode.
4. Use only `short_test` first.
5. Keep the emergency stop immediately available.
6. Confirm the dashboard timeline follows node/edge progress.
7. Send `home`.

### Stage C: scenarios

Run the short commissioning loop before the longer route.

Do not enable the coordinated crane scenario until:

- the crane adapter is operational;
- crane factsheet capabilities are verified;
- the handover actions are tested independently;
- the physical shared-zone safety procedure is approved;
- action IDs and rendezvous nodes match the actual order templates.

## 8. API endpoints

| Method | Endpoint | Purpose |
|---|---|---|
| GET | `/api/dashboard` | Complete dashboard snapshot |
| GET | `/api/waypoints` | Current waypoint configuration |
| POST | `/api/waypoints/<name>/dispatch` | Dispatch a dynamic ROX waypoint order |
| POST | `/api/controls/rox/pause` | `startPause` |
| POST | `/api/controls/rox/resume` | `stopPause` |
| POST | `/api/controls/rox/cancel` | `cancelOrder` |
| POST | `/api/controls/rox/retry` | Retry a RETRIABLE action |
| POST | `/api/controls/rox/skip-retry` | Skip a RETRIABLE action |
| POST | `/api/controls/rox/factsheet` | Request factsheet |
| POST | `/api/scenarios/<id>/start` | Start a scenario; sequential runs accept `{"confirmation_mode":"manual"}` or `{"confirmation_mode":"timeout"}` |
| POST | `/api/scenarios/active/confirm` | Manually complete the displayed sequential gate; requires its `{"run_id":"...","step_id":"..."}` binding |
| POST | `/api/scenarios/active/stop` | Cancel the current scenario/order |
| POST | `/api/events/clear` | Clear in-memory UI events |
| GET | `/healthz` | Server and MQTT health |

## 9. Smoke test

With the server running:

```bash
python3 scripts/dashboard_smoke_test.py \
  --url http://127.0.0.1:5000
```

To test from another computer:

```bash
python3 scripts/dashboard_smoke_test.py \
  --url http://192.168.50.115:5000
```

The smoke test is read-only. It does not send a movement order.

## 10. Useful future additions

The following are useful but should be implemented only when supported by the actual adapter and factsheet:

- persistent mission/event database;
- login and role-based authorization;
- TLS/reverse proxy for networks beyond the isolated lab;
- map thumbnail with live robot pose;
- visualization-topic path overlay;
- zone-set monitoring and request/response handling;
- crane-specific manual commissioning page;
- downloadable experiment run report;
- order-update support for released base/horizon extension;
- multi-robot traffic and shared-zone reservation.

The dashboard currently exposes unsupported capabilities as unavailable rather than presenting buttons that cannot be executed correctly.

## 11. Normative references

Implementation decisions should be checked against the released VDA 5050 v3 material:

- VDA 5050 v3.0.0 specification: <https://github.com/VDA5050/VDA5050/blob/main/VDA5050_EN.md>
- Official schemas and examples: <https://github.com/VDA5050/VDA5050>
- VDA overview and current download: <https://www.vda.de/en/topics/automotive-industry/vda-5050>

The schemas stored under `schemas/vda5050_v3/` remain the executable validation authority for messages published by this repository.
