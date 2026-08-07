# Dedicated Ilmatar watchdog OPC UA session

## Architecture and verified prerequisite

The Pi now opens two independent `asyncua` clients to the configured crane OPC
UA endpoint:

```text
Siemens PLC
  <- dedicated watchdog session: watchdog heartbeat only
  <- control session: motion, STOP, home/reset, telemetry, visualization,
     automatic-mode guard, and the one startup access-code write
```

Physical prerequisite testing already established that two read-only sessions
can coexist for 60 seconds and that a second read-only session can coexist with
the running adapter for five minutes without disturbing it. Physical heartbeat
write testing is still required.

The watchdog session never resolves or writes the access-code node. The access
code remains a single startup write through the main control session, and its
value is never included in transaction diagnostics.

## Controller-health feed gate

The dedicated session must not hide a dead controller. Feeding is allowed only
while the control session is healthy and the startup preflight or runtime
automatic-mode guard continues producing heartbeats. The gate latches off for:

- control-session transaction failure;
- dedicated watchdog-session failure;
- expired controller/automatic-mode guard heartbeat;
- fatal adapter thread or runtime MQTT loss;
- runtime `DX_Custom_V.Status.WatchDogFault=true`;
- critical watchdog transport health;
- application shutdown.

After inhibition, feeding cannot be restored within that process run. The code
issues a best-effort control-session STOP, cancels execution, reports the crane
unavailable, and allows the PLC watchdog to expire. There is no shared-session
fallback, automatic reconnect, automatic-mode reset, or physical mission retry.

## Slow control-operation evidence

Every main-session transaction measures lock request/acquisition, actual OPC UA
transaction start/finish, lock wait, transaction duration, and total duration.
It records the owner, operation, logical node, node ID, thread, success, and
exception type. Calls exceeding `CRANE_OPCUA_SLOW_WARN_MS` generate
`OPCUA_SLOW_TRANSACTION`; calls exceeding
`CRANE_OPCUA_SLOW_CRITICAL_MS` generate `OPCUA_CRITICAL_TRANSACTION`.

The JSONL event includes current motion/order/action/scenario context and the
latest asynchronous network/Pi sample. No network command, JSON encoding, disk
write, MQTT operation, or sleep occurs while the control lock is held.

## Required physical tests

### Test 1: idle

1. Confirm startup logs report both sessions connected and the watchdog node
   ready.
2. Confirm the dashboard reports control `CONNECTED`, watchdog `CONNECTED`, and
   architecture `dedicated_watchdog`.
3. Run without movement for at least 15 minutes.
4. Preserve the maximum watchdog write/gap and all slow control operations.

### Test 2: repeated crane-only motion

With no payload and direct operator supervision, repeat:

```text
Home -> Source -> Home -> Handover -> Home
```

Inspect any slow `stop_all`, motion, home, or automatic-guard transaction down
to its logical PLC node.

### Test 3: full scenario

Run the complete crane plus ROX-Diff scenario without payload, using manual
confirmation mode first. Preserve adapter/master logs and the diagnostics JSONL
before any supervised recovery.

## Expected result and remaining risk

A slow control `stop_all` transaction may still be recorded, but it must not
produce a watchdog control-lock wait because the two clients share neither a
session nor the application transaction lock.

If the dedicated watchdog still records a 500-1000 ms actual write while
scheduling is normal, investigate Wi-Fi/TCP, `asyncua`, the Siemens OPC UA
server, and PLC processing.

Shared-session watchdog starvation has been architecturally removed. Physical
testing is still required to determine whether independent watchdog OPC UA
writes can also exhibit long transport/server delays.
