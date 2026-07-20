# Repository Audit and Migration Update — 2026-07-20

## Scope reviewed

The uploaded repository was reviewed across active fleet control, crane edge code, ROS 2 packages, VDA schemas/messages, configuration, routes, examples, deployment scripts, documentation and legacy material. The public GitHub repository was used as an architectural cross-check; the uploaded archive was the source patched for this delivery.

## Critical findings corrected

1. **Crane schema path crash.** The crane adapter constructed an invalid path with `Path.with_name("../...")` and referenced an undefined fallback. It now resolves the repository schema directory explicitly and fails clearly if required schemas are missing.
2. **Tracked credentials.** Real credential files were present in the archive. They were removed from the distributable project, replaced with ignored examples, and the adapter now supports environment-based credentials.
3. **Unsafe handover condition.** The master used human-readable `information[]` hoist text as a release condition. Handover now uses exact configured VDA action IDs and statuses; hoist information remains display-only.
4. **Ambiguous release action.** Multiple crane `buttonPress` actions existed at the same node. Automatic and manual release now match separate configured action IDs rather than any action of the same type.
5. **Failed safe-lift handling.** ROX release now requires the exact configured crane safe-lift action to finish. A failed safe-lift action keeps the ROX hold active.
6. **Crane fail-open startup.** The crane adapter previously continued after missing automatic mode or failed homing. It now exits by default. The explicit override is documented as supervised telemetry diagnosis only.
7. **Crane order acceptance gaps.** Identity, version, map, update ID, busy-order, sequence and unsupported edge-action checks were added.
8. **Crane state progression.** Traversed node and edge states are now cleared and active-order lifecycle is tracked.
9. **Missing crane dependencies.** A crane requirements file was added with MQTT, JSON-schema, OPC UA, HTTP and numerical dependencies used by the source.
10. **Missing crane factsheet behavior.** A schema-valid factsheet template, retained publication and `factsheetRequest` response were added.
11. **ROX initialization frame error.** Logical VDA `mapId` is no longer used as a ROS TF frame. The adapter validates the logical map ID and publishes `/initialpose` in the configured ROS map frame.
12. **ROX factsheet default.** The packaged factsheet is resolved and published by default, including retained publication on connect.
13. **ROX Nav2 result robustness.** Asynchronous result exceptions are handled and reported instead of escaping the callback.
14. **Unsafe default motion.** Dry-run remains the default; real Nav2 motion is launched only by the explicit real-mode helper.
15. **Broken service paths.** Pi and ROX systemd examples now use the supplied project directory and helper scripts.
16. **Active VDA v2 leftovers.** Old DBot/crane test orders were moved under legacy compatibility material so active order discovery cannot use them accidentally.
17. **Repository hygiene.** ROS build/install/log products, caches, secrets and generated site files are excluded from the updated distributable copy.
18. **Static verification.** A single-process static checker validates active Python/shell/XML, schema mirrors, factsheets, examples, generated test order, fail-closed waypoint behavior, credential absence and active v2-message absence.

## Active architecture after the update

```text
Raspberry Pi
  Mosquitto + Flask master
      | VDA 5050 v3 MQTT/JSON
      +---- Neobotix ROX-Diff adapter -> native Nav2 -> native Neobotix stack
      +---- Crane VDA adapter -> OPC UA -> crane PLC
```

The old DBot motor, URDF, odometry, VDA v2 connector and map coordinates are not active. They remain under `legacy/` only for traceability.

## Manual work that cannot be completed from source code alone

- identify the exact ROS distribution and Neobotix launch files installed on the delivered ROX-Diff;
- verify scanner, battery, emergency-stop and safety-state topic names/types;
- create and save a map of the real environment;
- tune localization, footprint, costmaps, planner, controller and speed limits;
- capture and physically validate all waypoint poses;
- generate the real ROX order and initial-pose settings;
- fill ROX and crane factsheet physical values from verified equipment data;
- configure the real Pi address, MQTT security, OPC UA URL and crane access code;
- verify the crane action IDs correspond to actual PLC events;
- run dry-run, ROX-only, crane-only and coordinated no-load tests in order;
- document recovery behavior and results before any loaded test.

## Verification completed in this delivery

The updated repository passes `./scripts/run_static_checks.sh`. This checks source syntax and VDA schema consistency. The delivery was not executed on the actual ROS/Neobotix environment, Raspberry Pi broker, Nav2 action server, OPC UA server, PLC, crane or mobile robot. Physical interoperability and safety remain commissioning tasks.
