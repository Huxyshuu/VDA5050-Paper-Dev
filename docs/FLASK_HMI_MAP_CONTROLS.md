# Interactive Flask HMI map controls

The live occupancy-map panel is interactive. These controls only change the browser view; they never alter the ROS map, localization, waypoints, Nav2 goal, or VDA 5050 order.

## Mouse and touch controls

- Drag with the mouse or one finger to pan.
- Use the mouse wheel or a two-finger pinch to zoom around the pointer.
- Use a two-finger twist to rotate on touch hardware.
- Double-click the map to center the current view on ROX-Diff.
- Focus the canvas and use `+` / `-` to zoom, `Shift+Left` / `Shift+Right` to rotate, and `0` to reset.

## Toolbar

- **− / +**: zoom out or in.
- **↶ / ↷**: rotate by 15 degrees.
- **Center robot**: place the current robot pose at the middle while preserving zoom and rotation.
- **Robot + all**: center on the robot and zoom out sufficiently to keep the robot, every waypoint, and the active command chain visible.
- **Fit all**: fit the robot, all waypoints, and active route into the available viewport.
- **Follow**: keep the robot centered as live VDA position updates arrive. Manual panning, zooming, or rotation disables follow mode.
- **Reset**: restore north-up rotation and the complete-map fit.

The lower-right readout shows the current relative zoom percentage and map rotation.

## Persistence

The browser stores view state in `localStorage`, keyed by map identity and revision. Zoom, rotation, normalized pan position, and follow mode survive page refreshes without being written to the Raspberry Pi or Git repository. A changed map revision receives an independent default view.

## Default view

On first load, the UI uses **Robot + all** so the robot and all configured waypoints are immediately visible. Use **Reset** whenever the complete occupancy image is preferred.

## Coordinate fallback

When the map image is unavailable, all controls remain available over the coordinate-grid fallback. The map files should normally already be present in:

```text
configs/maps/df_map.yaml
configs/maps/df_map.pgm
```

No temporary folder or map-install command is required when those repository files exist and `FLEET_UI_MAP_YAML=configs/maps/df_map.yaml` is configured.

## Safety

Map manipulation is visualization only. It does not rotate the Nav2 coordinate frame, change `mapId`, alter localization, or override protective systems.
