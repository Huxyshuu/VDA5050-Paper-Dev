# Crane watchdog and dashboard diagnostics

## Purpose

This update improves two areas of the Ilmatar + ROX-Diff cell:

1. reduce the likelihood that OPC UA traffic starves the crane watchdog;
2. make scenario, watchdog, and crane-motion failures visible in the Flask dashboard.

It does not bypass crane safety logic or automatically reset the crane after a PLC/safety fault.

## Watchdog changes

The crane uses `DX_Custom_V.Controls.Watchdog` for the external watchdog and
`DX_Custom_V.Status.WatchDogFault` as the authoritative automatic-mode signal.

The update adds:

- one serialized OPC UA I/O lock for watchdog, telemetry, and motion commands;
- priority for pending watchdog writes;
- monotonic deadline scheduling instead of `write + sleep` timing;
- last and maximum successful write gaps;
- write duration, overrun, and failure counters;
- visible warnings on the first write failure;
- fail-closed cancellation if watchdog transport health becomes critical;
- VDA `information[]` entries named `WATCHDOG_HEALTH` and `CRANE_MOTION_HEALTH`.

Default settings:

```dotenv
CRANE_WATCHDOG_INTERVAL_S=0.049
CRANE_WATCHDOG_WARN_GAP_S=0.15
CRANE_WATCHDOG_CRITICAL_GAP_S=0.50
CRANE_WATCHDOG_FAILURE_LIMIT=3
CRANE_MOTION_STALL_WARN_S=6.0
CRANE_MOTION_STALL_FAIL_S=15.0
```

Do not tighten these values without knowing the PLC watchdog timeout. The dashboard
will show the observed write gap, which should be measured during crane-only no-load
cycles before tuning.

## Dashboard execution monitor

A new **Scenario, crane motion and watchdog health** panel shows:

- active scenario step, status, elapsed time, and timeout;
- watchdog status, last-success age, write duration, current/max gap, failures, and overruns;
- crane motion phase, action ID, elapsed time, and no-progress age;
- the latest failure or transition;
- a filtered execution timeline for crane, ROX-Diff, scenario, and operator events.

The existing event log remains available for the complete server event stream.

## Sequential scenario changes

Each step now has a timeout. Defaults are:

| Command | Default timeout |
|---|---:|
| Crane home | 300 s |
| Crane XY waypoint | 180 s |
| Crane hoist movement | 120 s |
| ROX waypoint | 300 s |
| Operator confirmation | Manual: wait until confirmed; timed mode: continue after 5 s |

A step records:

- start and finish timestamps;
- elapsed duration;
- order/action result identifier;
- failure reason;
- operator wait and confirmation transitions.

If a crane or ROX command exceeds its timeout, the controller sends `cancelOrder`,
marks the scenario failed, and records the failure in the dashboard timeline.
Operator gates use the per-run confirmation policy instead: manual mode waits
indefinitely, while timed mode records an automatic confirmation after five seconds.

## Recommended test procedure

1. Start the master and crane adapter.
2. Leave the crane online and idle for at least 15 minutes.
3. Confirm watchdog status remains `HEALTHY`.
4. Run repeated crane-only Home → Source → Home movements without a payload.
5. Watch current/max watchdog gaps and write failures.
6. Run the sequential scenario without a payload.
7. Save adapter and master terminal logs if watchdog status becomes `DEGRADED` or `CRITICAL`.

A single old maximum-gap value is evidence for later analysis; the current status can
return to `HEALTHY` after timing recovers.

## Failure interpretation

- **Watchdog CRITICAL**: repeated write failures or no successful write within the critical gap.
- **WatchDogFault true**: PLC no longer permits automatic/remote operation.
- **Motion STALLED**: crane was commanded to move but no axis position changed for the configured fail period.
- **Scenario FAILED**: device reported failure/rejection or the active step timed out.

The software stops and reports these conditions. Physical recovery and automatic-mode
reset remain supervised operations.
