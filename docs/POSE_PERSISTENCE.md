# Automatic Nav2 pose persistence

This feature removes the normal RViz **2D Pose Estimate** step when Nav2 is restarted **and the ROX-Diff has not been physically moved while Nav2 was off**.

It does not provide absolute localization without assumptions. The saved pose is an initial estimate for AMCL. AMCL still uses the laser scan and map to refine the estimate.

## How it works

The command:

```bash
./scripts/rox.sh nav
```

now launches two processes together:

1. the delivered Neobotix `rox_navigation/navigation.launch.py`;
2. `rox_vda5050_adapter/pose_persistence`.

The persistence node:

1. waits until the occupancy map is available and AMCL subscribes to `/initialpose`;
2. loads `runtime/rox_last_pose.yaml` when it exists;
3. verifies the logical `map_id` and a SHA-256 fingerprint of the map YAML plus its referenced image;
4. within the same Linux boot, compares the saved and current `odom -> base_link` poses and refuses restoration if the robot appears to have moved;
5. publishes the saved pose as `geometry_msgs/msg/PoseWithCovarianceStamped` on `/initialpose` three times;
6. continuously saves the current `map -> base_link` pose every two seconds using an atomic file replacement;
7. attempts one final save during an orderly shutdown.

The periodic snapshots mean a recent pose normally remains available even if Nav2 crashes or the terminal closes unexpectedly.

## First-time setup

Build after applying the source update:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh build
source ros2_ws/install/setup.bash
```

The first run has no saved pose. Start without automatic restoration:

```bash
./scripts/rox.sh nav-fresh
```

In RViz:

1. use **2D Pose Estimate** once;
2. verify that the laser scan aligns with walls and fixed objects;
3. leave Nav2 running for a few seconds so the pose file is written.

Check it in another terminal:

```bash
./scripts/rox.sh pose-status
```

Stop Nav2 with `Ctrl+C`. The next normal startup is:

```bash
./scripts/rox.sh nav
```

After AMCL restores and scan/map alignment looks correct:

```bash
./scripts/rox.sh goto home
```

## Daily workflow

Terminal 1:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh nav
```

Terminal 2, after `/navigate_to_pose` is available and localization looks correct:

```bash
cd ~/Projects/VDA5050-Paper-Dev
./scripts/rox.sh goto home
```

Optional markers in Terminal 3:

```bash
./scripts/rox.sh visualize
```

## Pose commands

```bash
./scripts/rox.sh pose-status
./scripts/rox.sh pose-save
./scripts/rox.sh pose-restore
./scripts/rox.sh pose-clear
```

- `pose-status` prints the saved pose, age, map match, fingerprint match and whether it came from the current Linux boot.
- `pose-save` immediately captures the current `map -> base_link` transform.
- `pose-restore` republishes the saved pose to AMCL while Nav2 is running.
- `pose-clear` deletes the runtime file. `nav-fresh` also clears it automatically before starting Nav2, so a stale estimate cannot be restored on the following run.

The default runtime file is:

```text
~/Projects/VDA5050-Paper-Dev/runtime/rox_last_pose.yaml
```

The `runtime/` directory is ignored by Git. Do not publish a site-specific last pose to the public repository.

## When the robot was moved while Nav2 was off

Do not trust the saved pose. Run:

```bash
./scripts/rox.sh nav-fresh
```

Then use RViz **2D Pose Estimate** again.

The same applies when:

- the map was regenerated or edited;
- the robot was pushed, carried or towed;
- wheels moved while localization was unavailable;
- the scanner/map overlay is visibly wrong;
- the map origin or robot base frame changed;
- the stored pose file reports a map mismatch.

## Full robot reboot

The map fingerprint is still checked after a reboot, but the same-boot odometry movement guard cannot prove that the robot remained stationary. The node prints a warning and uses the saved estimate under the operator's stated assumption that the robot was not moved.

For more conservative operation after every reboot:

```bash
./scripts/rox.sh nav-fresh
```

## Environment overrides

```bash
ROX_LAST_POSE_FILE=/absolute/path/last_pose.yaml ./scripts/rox.sh nav
ROX_AUTO_RESTORE=false ./scripts/rox.sh nav
ROX_MAX_POSE_AGE_HOURS=24 ./scripts/rox.sh nav
```

`ROX_MAX_POSE_AGE_HOURS=0` disables age rejection. Map ID and map fingerprint checks remain active.

## Direct launch equivalent

```bash
ros2 launch rox_vda5050_adapter \
  navigation_with_pose_persistence.launch.py \
  rox_type:=diff \
  use_rviz:=True \
  map:="$HOME/maps/df_map.yaml" \
  map_id:=df_map \
  pose_file:="$HOME/Projects/VDA5050-Paper-Dev/runtime/rox_last_pose.yaml" \
  auto_restore:=true
```

## Verification before movement

Automatic restoration does not itself authorize motion. Before `goto home`, verify:

```bash
./scripts/rox.sh status
./scripts/rox.sh tf
```

Confirm:

- `/navigate_to_pose` exists;
- `map -> base_link` is available;
- the RViz scan aligns with the map;
- the robot marker is at the real physical location;
- no emergency or scanner stop is active.
