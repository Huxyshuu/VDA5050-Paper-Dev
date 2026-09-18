# Pi benchmark revision

Base reviewed: `1441592c67eff2f4f6db48c32120868c3de73947`.
This revision includes everything needed from that repository version. Do not
apply the previous ROX final-test package first.

## Changed

1. The runner sends both native ROS 2 goals and VDA/MQTT orders from the Pi.
2. Only three timing events remain; all are captured on the Pi. A fourth
   record preserves endpoint checks and failed attempts outside timing.
3. The ROX adapter sends correlated Nav2 replies without timestamps, file
   logging or additional services. This requires rebuilding its existing overlay.
4. One run directory contains the frozen configuration, unique paired schedule,
   source snapshot, manifest, raw events and derived outputs. The runner rejects
   source/config/environment changes, repeats, skips, and failed-attempt resumes.
5. CSV derivation audits against the schedule, retaining entirely missing rows,
   failures, resets and invalid sequences. It refuses mixed clocks/identities.
6. Statistics report two metrics, mean, sample standard deviation, median, IQR,
   p95, range, paired VDA-minus-native differences and bootstrap confidence
   intervals. No p99 estimate is advertised from a small campaign.
7. The dashboard shows the Pi timing events and two measured durations.

## Removed or consolidated

The entire inactive `legacy/` tree (old DBot workspace and generated/vendor
material), the old map copy, dated migration/audit/update notes, and the old
eight-event benchmark instructions were removed. Overlapping dashboard
documents were consolidated into `DASHBOARD.md`; duplicate mapping/test
instructions point to the current remapping and commissioning guides.

The obsolete ROX adapter logger and its colcon data-file dependency were
removed. The old crane benchmark runner and experimental hooks were also
retired because their acknowledgement meant local target assignment, not PLC
acceptance. Crane control, watchdog diagnostics, automatic-mode guards,
pause/cancel handling and handover operations remain in the active project.

Current maps and commissioned waypoints are retained. Useful hardware setup,
network, pose-persistence, watchdog and third-party attribution documents remain.
Git history preserves removed material; measurement results are not deleted.

## Evidence and limits

Offline tests cover matched response boundaries, correlation, duplicate replies,
rejection/failure accounting, missing trials, clock isolation, schedule resumption
and paired analysis. Existing project/static checks remain required.

Physical navigation, Docker image execution on the Pi, ROS discovery on the lab
network, and the final dataset must still be verified on the actual equipment.
Use the read-only check, one supervised pair, and a fresh five-pair pilot before
the confirmatory run. This patch contains no measured hardware results.
