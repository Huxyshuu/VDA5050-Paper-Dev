# ROX-Diff: Create a New Map and Recapture Waypoints

Use this procedure whenever the existing occupancy map needs to be replaced.

## 1. Stop navigation and the VDA adapter

Stop `rox adapter-real` with `Ctrl+C`, then run:

```bash
rox nav-stop
```

Keep the normal ROX hardware bringup running.

## 2. Start mapping

On the ROX-Diff:

```bash
ros2 launch rox_navigation mapping.launch.py
```

Leave this terminal open.

## 3. Open the mapping view

On the operator laptop:

```bash
ros2 launch neo_nav2_bringup rviz_launch.py
```

In RViz, confirm:

```text
Fixed Frame: map
Map topic: /map
LaserScan topic: /lidar_1/scan_filtered or /scan
```

Drive the robot slowly through the required operating area. Revisit the starting area before finishing so SLAM can close the loop.

## 4. Save the new map

Before closing the mapping launch, save a candidate map on the ROX:

```bash
mkdir -p "$HOME/maps"

ros2 run nav2_map_server map_saver_cli \
  -f "$HOME/maps/df_map_candidate"
```

This creates:

```text
~/maps/df_map_candidate.yaml
~/maps/df_map_candidate.pgm
```

Stop mapping with `Ctrl+C` after saving.

## 5. Back up the current map and waypoints

```bash
PROJECT="$HOME/Projects/VDA5050-Paper-Dev"
STAMP="$(date +%F-%H%M%S)"
BACKUP="$HOME/maps/archive/$STAMP"

mkdir -p "$BACKUP"

cp -a "$HOME/maps/df_map.yaml" \
      "$HOME/maps/df_map.pgm" \
      "$BACKUP/" 2>/dev/null || true

cp -a "$PROJECT/configs/rox_waypoints.yaml" \
      "$BACKUP/" 2>/dev/null || true

echo "Backup created at: $BACKUP"
```

## 6. Test the candidate map

```bash
ROX_MAP_YAML="$HOME/maps/df_map_candidate.yaml" \
rox nav-fresh
```

In RViz:

1. Set **2D Pose Estimate**.
2. Confirm the laser scan aligns with walls.
3. Rotate and drive around the mapped area.
4. Send a few normal RViz Nav2 goals.

If the map is correct, stop navigation:

```bash
rox nav-stop
```

## 7. Replace the runtime map

```bash
cp "$HOME/maps/df_map_candidate.pgm" \
   "$HOME/maps/df_map.pgm"

cp "$HOME/maps/df_map_candidate.yaml" \
   "$HOME/maps/df_map.yaml"

sed -i \
  's#^image:.*#image: df_map.pgm#' \
  "$HOME/maps/df_map.yaml"
```

Verify:

```bash
grep -E \
  '^(image|resolution|origin|mode|negate|occupied_thresh|free_thresh):' \
  "$HOME/maps/df_map.yaml"

ls -lh \
  "$HOME/maps/df_map.yaml" \
  "$HOME/maps/df_map.pgm"
```

The YAML must contain:

```yaml
image: df_map.pgm
```

## 8. Copy the new map into the repository

```bash
cd "$HOME/Projects/VDA5050-Paper-Dev"
mkdir -p configs/maps

cp "$HOME/maps/df_map.yaml" \
   configs/maps/df_map.yaml

cp "$HOME/maps/df_map.pgm" \
   configs/maps/df_map.pgm

sed -i \
  's#^image:.*#image: df_map.pgm#' \
  configs/maps/df_map.yaml
```

Confirm both images match:

```bash
sha256sum \
  "$HOME/maps/df_map.pgm" \
  configs/maps/df_map.pgm
```

## 9. Clear the old saved pose

```bash
rox pose-clear
```

## 10. Start navigation with the new map

```bash
rox nav-fresh
```

In RViz:

1. Set **2D Pose Estimate**.
2. Confirm the scan aligns with the new map.
3. Confirm localization remains stable while moving and rotating.

## 11. Recapture the waypoints

Drive the robot manually to each physical location and capture it:

```bash
rox capture home
rox capture short_test
rox capture crane_handover
rox capture warehouse_dropoff
```

Inspect the captured values:

```bash
rox list
rox visualize
```

## 12. Test every waypoint

Dry-run validation:

```bash
rox goto-dry home
rox goto-dry short_test
rox goto-dry crane_handover
rox goto-dry warehouse_dropoff
```

Physical tests:

```bash
rox goto home
rox goto short_test
rox goto home
rox goto crane_handover
rox goto home
rox goto warehouse_dropoff
rox goto home
```

Each successful test should end with:

```text
WAYPOINT CHECK: PASS
```

## 13. Approve the waypoint set

Open:

```bash
nano "$HOME/Projects/VDA5050-Paper-Dev/configs/rox_waypoints.yaml"
```

Change:

```yaml
configured: false
```

to:

```yaml
configured: true
```

Only do this after all waypoints have been tested successfully.

## 14. Commit and push

```bash
cd "$HOME/Projects/VDA5050-Paper-Dev"

git add \
  configs/maps/df_map.yaml \
  configs/maps/df_map.pgm \
  configs/rox_waypoints.yaml

git commit -m "Replace ROX map and recapture waypoints"
git push origin main
```

## 15. Update the Raspberry Pi

On the Pi:

```bash
cd "$HOME/VDA5050-Paper-Dev"
git pull --ff-only
```

Restart the Flask master controller:

```bash
pkill -f 'fleet_control/master_control.py' 2>/dev/null || true
./scripts/run_master_control.sh
```

Hard-refresh the browser:

```text
Ctrl + Shift + R
```

## 16. Final test

On the ROX:

```bash
rox adapter-real
```

From the Flask UI, test in this order:

```text
1. Go to Short Test
2. Go to Home
3. Run Short Commissioning Loop
4. Run ROX Case-Study Route
```

Confirm:

```text
[ ] New map displays correctly in RViz and Flask
[ ] Laser scan aligns throughout the route
[ ] Old persisted pose was cleared
[ ] All waypoints were recaptured
[ ] All direct waypoint tests pass
[ ] configured: true is set
[ ] MQTT and ROX are online in the Flask UI
[ ] VDA waypoint orders and scenarios complete successfully
```
