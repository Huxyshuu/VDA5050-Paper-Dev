# Watchdog and crane action transition hardening

This update responds to the observed failure after the source-safe lift.

## Changes

- Every crane order begins with a short stop-and-settle barrier.
- Every completed XY or hoist movement stops all axes and waits before the next command.
- The barrier requires `WatchDogFault=false` and a stable, fresh watchdog write stream.
- A successful watchdog write gap above the critical threshold is latched as CRITICAL for a recovery window instead of disappearing immediately on the next tick.
- Sequential steps wait `SEQUENTIAL_ACTION_DELAY_S` before dispatching the next command.
- The source-to-handover sequential step no longer adds an implicit `travel_safe_m` raise. It verifies that the hook is already at or above `source_safe_lift_m` and then sends only the XY movement.
- VDA `information[].infoLevel` values use only schema-valid `INFO`; warning severity remains available through `infoType`, descriptors, references, errors, and dashboard status.

## Default timing

```dotenv
CRANE_ACTION_SETTLE_S=1.5
CRANE_PRE_MOTION_SETTLE_S=0.75
CRANE_WATCHDOG_RECOVERY_TIMEOUT_S=5.0
CRANE_WATCHDOG_RECOVERY_STABLE_S=0.75
CRANE_WATCHDOG_CRITICAL_LATCH_S=1.5
SEQUENTIAL_ACTION_DELAY_S=1.5
```

These delays do not reset PLC automatic mode. If automatic mode or watchdog transport health is lost, the current action fails closed and the scenario stops.
