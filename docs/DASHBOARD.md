# Raspberry Pi dashboard

Start the existing master with `bash scripts/run_master_control.sh` and open
the Pi on port 5000. The dashboard operates named waypoint missions, displays
the occupancy map and device states, and runs the supervised handover sequence.

## Laptop command timing

The dedicated panel receives copies of events already timestamped by the laptop
runner. It displays the raw monotonic nanoseconds, elapsed milliseconds from
command submission, trial ID, condition and outcome. Latest acknowledgement
and completion values are shown above the timeline.

| Event | Meaning |
|---|---|
| `COMMAND_ISSUED` | Laptop submits a prepared native goal or VDA order |
| `COMMAND_ACK_RECEIVED` | Laptop receives the device acknowledgement |
| `COMMAND_RESULT_RECEIVED` | Laptop receives the device completion response |
| `TRIAL_FINISHED` | Endpoint verification or failure accounting, outside timing |

The UI polls at its normal rate. Polling affects when a value becomes visible,
not the captured timestamp. The benchmark can run with the UI closed. Keep
the same background workload in both conditions and do not dispatch dashboard
missions while the runner is controlling ROX.

`/api/benchmark/events` supplies the display projection. The panel's JSONL
export is only the bounded in-memory view; restart or clearing can remove
display history. The complete research record is `events.jsonl` in the laptop run
directory. Use [the LaTeX methods and command comments](../paper/measurement_architecture.tex) for CSV and
statistics. No benchmark toggle on ROX is required.

## Other dashboard features

Mission history preserves terminal outcomes: finished, failed, rejected or
cancelled. Order rejection is attributed by VDA order references. The route
line shows the logical waypoint sequence; Nav2 chooses the actual trajectory.

The map supports mouse drag/pan, wheel zoom, touch pinch/twist, centering and
reset. View changes affect browser rendering only, never the ROS map or
waypoint coordinates. Install the current map pair with
`bash scripts/install_dashboard_map.sh` (see its help and deployment guide).

The existing mission-history recorder writes
`results/experiments/mission_control.sqlite3` and exports through
`/api/experiments/export.csv`. Those are master-dispatched mission records,
distinct from the new Pi benchmark's two response-time metrics.

For crane operation use [crane controls](crane_automatic_and_manual_controls.md).
For cross-device handover use [the sequential scenario guide](SEQUENTIAL_PICKUP_DELIVERY_SCENARIO.md).
