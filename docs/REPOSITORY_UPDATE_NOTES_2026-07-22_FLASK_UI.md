# Repository Update: VDA 5050 v3 Flask Mission Control

Date: 2026-07-22

## Added

- `fleet_control/dashboard_v3.py`
  - dynamic waypoint-order generation
  - live device and server projections
  - VDA action/control API
  - mission lifecycle and node/edge progress
  - ROX-first sequential scenario runner
  - in-memory events and mission history
  - health endpoint
- `configs/dashboard_scenarios.yaml`
- `docs/FLASK_MISSION_CONTROL.md`
- `scripts/dashboard_smoke_test.py`

## Replaced

- `fleet_control/templates/index.html`
  - responsive futuristic dashboard
  - dynamic waypoint cards
  - current order timeline
  - state-aware pause/resume/cancel/retry controls
  - scenario cards and progress
  - ROX and crane status
  - server status
  - event log and recent missions

## Patched

- `fleet_control/master_control.py`
  - site MQTT default updated to `192.168.50.115`
  - default map updated to `df_map`
  - dashboard extension registered before Flask startup
- `configs/fleet_control.env`
- `configs/fleet_control.env.example`
  - current site defaults
  - ROX enabled
  - crane disabled
  - dashboard paths and stale-state limits
- `README.md`
  - dashboard documentation link

## Current limitations

- Crane operation is intentionally disabled.
- Dashboard mission/event history is process-local and resets when Flask restarts.
- The dashboard does not yet implement order updates, zones or request/response coordination.
- Dynamic orders contain navigation only; edge actions are intentionally omitted because the current ROX adapter rejects them.
- The generated update was statically and synthetically tested, but not run against the physical ROX-Diff or crane from the build environment.
