# Diagnosing Ilmatar watchdog timing failures

This instrumentation is designed to classify the next physical watchdog event;
it does not claim to fix the PLC, OPC UA transport, Wi-Fi, or Raspberry Pi. The
authoritative automatic-availability signal remains
`DX_Custom_V.Status.WatchDogFault`: `false` permits remote operation and `true`
stops/cancels crane execution. Recovery remains supervised.

## Why the timing was split

The no-load test established a normal successful gap of about 49 ms and a normal
OPC UA write near 6 ms. The failure reached a 1040.6 ms success gap and a 993.8
ms combined watchdog operation without an OPC UA exception, immediately followed
by `WatchDogFault=true`. The old combined duration could not tell whether the
watchdog was waiting for the application's session lock or blocked inside the
actual OPC UA write.

The watchdog now uses a dedicated OPC UA client/session and retains these
monotonic timestamps:

- scheduled deadline and Python attempt start;
- actual OPC UA write start and finish.

The dashboard and JSONL records derive current and startup-maximum values for
schedule lateness, OPC UA write duration, total cycle duration, and
successful-write gap. Watchdog lock wait is reported as not applicable, with
`control_lock_wait_ms=0`, because the dedicated client never acquires the
control-session transaction lock.

Every control-session read/write is separately timed with owner, operation,
logical node, lock wait, actual transaction duration, total duration, thread,
success, and exception type. Slow and critical control calls are persisted with
the latest already-collected network/Pi sample.

## Four diagnostic cases

### Case A: application/session-lock contention

A high control `lock_wait_ms` means one control operation queued behind another.
This can still delay motion or telemetry, but can no longer block the watchdog,
which has a separate connection and session. Inspect the slow transaction's
owner and logical node.

### Case B: network or Wi-Fi delay

`lock_wait_ms` is low, `write_duration_ms` is high, and the same pre-failure
samples show poor RSSI, ping failure/spike, new interface drops/errors, or TCP
retransmission growth. Investigate the Pi-to-PLC route, Wi-Fi power save, signal,
access point, interference, cabling, and switch/AP logs.

### Case C: PLC OPC UA server/session delay

`lock_wait_ms` is low and `write_duration_ms` is high, while ping, interface,
Wi-Fi, TCP, CPU, temperature, and throttle evidence remain normal. Investigate
the Siemens/OPC UA server, PLC scan/load, session behavior, and server logs.

### Case D: Raspberry Pi scheduling or power delay

`schedule_lateness_ms` is already high before the dedicated watchdog write,
and the same samples show high CPU/load, temperature, undervoltage, or throttling.
Investigate Pi power, cooling, competing processes, storage stalls, and OS
scheduling before changing application timing.

## Evidence locations

The adapter writes JSON Lines to the configured directory, defaulting to:

```text
logs/crane_diagnostics/crane-diagnostics-<UTC>-<pid>.jsonl
```

Normal `WATCHDOG_SAMPLE` records are limited to approximately one per second.
`WATCHDOG_DEGRADED`, `WATCHDOG_CRITICAL`, `WATCHDOG_RECOVERED`,
`WATCHDOG_FAULT_TRUE/FALSE`, `OPCUA_TRANSACTION_EXCEPTION`, session-loss,
slow/critical control transaction, `NETWORK_DEGRADED`, motion, and scenario/action
transitions are immediate. Critical/fault records contain the
roughly 60-second network/system ring buffer from before the event. VDA state and
the dashboard receive only compact current/latest-failure projections, not the
full history.

The dashboard's execution monitor shows:

- watchdog gap, actual dedicated-session write, schedule lateness, maxima, and
  diagnostic hint;
- independent session health plus control transaction lock wait, actual
  duration, owner, operation, and logical node;
- PLC route interface/source IP, wired versus Wi-Fi, raw RSSI and bitrate,
  ping, drops/errors, CPU/load/temperature, throttling, and undervoltage;
- the latest persistent failure snapshot and execution timeline transitions.

If Linux utilities such as `iw`, `ping`, or `vcgencmd` are absent, their metrics
are marked unavailable. The collector continues and never acquires the OPC UA
lock.

## Configuration

The defaults are documented in `configs/fleet_control.env.example` and have also
been added, only where previously absent, to the current local environment file:

```text
CRANE_NETWORK_DIAGNOSTICS=true
CRANE_NETWORK_SAMPLE_S=1.0
CRANE_NETWORK_HISTORY_S=60
CRANE_DIAGNOSTICS_LOG_DIR=logs/crane_diagnostics
CRANE_PLC_PING_TIMEOUT_S=0.5
CRANE_OPCUA_SLOW_WARN_MS=100
CRANE_OPCUA_SLOW_CRITICAL_MS=500
CRANE_CONTROLLER_GUARD_TIMEOUT_S=5.0
```

Network command execution and JSON serialization/file I/O run in their own
threads. The watchdog thread only enqueues a diagnostic record after releasing
its write call; a slow SD card therefore cannot extend the watchdog write.

The access code is written once by the main control session. The watchdog
session does not resolve or write the access-code node. Its only recurring PLC
operation is the watchdog heartbeat write.

## Pi-side checks after an event

Preserve the JSONL file before restarting the adapter. Then run, without changing
the PLC mode automatically:

```bash
ip route get 10.210.1.12
ping -c 10 10.210.1.12
iw dev
iw dev <wireless-interface> link
iw dev <wireless-interface> get power_save
vcgencmd get_throttled
```

Commands that do not apply to a wired interface or non-Raspberry Pi host may be
unavailable; that is expected.

## Next physical test

1. Start the adapter and confirm JSONL records and dashboard network data appear.
2. Leave the crane idle for at least 15 minutes and retain the log.
3. Run repeated supervised, no-load XY and hoist movements.
4. If `WatchDogFault` becomes true, do not automatically retry motion. Save the
   adapter/master logs and JSONL file before operator recovery.
5. Compare the event's lock, write, schedule, and pre-failure network/Pi evidence
   using Cases A-D.

The dual-session physical prerequisite has passed: two read-only sessions were
stable for 60 seconds, and a second read-only session coexisted with the running
adapter for five minutes. The next tests must validate the dedicated session
while it is performing heartbeat writes; see `DEDICATED_WATCHDOG_SESSION.md`.

Do not raise `CRANE_WATCHDOG_CRITICAL_GAP_S` to hide the event. That threshold is
software telemetry; the PLC watchdog timeout is what removed automatic mode.
