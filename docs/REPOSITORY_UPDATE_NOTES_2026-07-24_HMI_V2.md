# Repository update notes — Flask HMI v2 — 2026-07-24

## Updated

- `fleet_control/dashboard_v3.py`
  - terminal mission states are immutable;
  - order rejection requires a matching order-rejection VDA error;
  - full scenario command-chain projection;
  - meaningful event transitions instead of generic state-change spam;
  - ROS map YAML/PGM loading and browser-compatible PNG endpoint;
  - SQLite experiment sessions and run records with full-database aggregate statistics;
  - JSON and CSV experiment exports.

- `fleet_control/templates/index.html`
  - redesigned operator-focused layout;
  - large live map panel;
  - single full command-chain tree;
  - simpler scenario library;
  - compact device status;
  - immutable mission history;
  - styled modal confirmations for every destructive or motion-starting operation;
  - experiment-mode toggle and statistics.

- `fleet_control/master_control.py`
  - installer changes `STATE_LOCK` from `threading.Lock()` to `threading.RLock()` to prevent the known nested orchestration callback deadlock.

## Added

- `docs/FLASK_HMI_V2.md`
- `scripts/install_dashboard_map.sh`
- `scripts/dashboard_hmi_smoke_test.py`
- `configs/maps/.gitkeep`

## Runtime files

The following are not intended for Git:

```text
results/experiments/*.sqlite3
results/experiments/*.sqlite3-*
```
