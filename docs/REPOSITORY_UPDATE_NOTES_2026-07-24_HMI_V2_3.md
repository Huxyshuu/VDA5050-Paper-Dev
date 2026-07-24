# Flask HMI v2.3 single-map update

This incremental update changes only the browser HMI and map-control documentation.

## Changes

- enforces one map rendering canvas;
- removes legacy map images and extra canvases from the map container;
- clears the complete canvas before each frame;
- coalesces map rendering with `requestAnimationFrame`;
- keeps route, waypoint, and robot overlays above the occupancy image;
- removes the **Fit all** and **Follow** controls;
- keeps **Robot + all** as the preferred centered overview;
- keeps the desktop 16:9 landscape viewport;
- keeps the serialized 500 ms polling loop;
- versions browser map-state storage from `v3` to `v4` for one clean reset.

No backend, MQTT, ROS, Nav2, VDA 5050, map-coordinate, waypoint, or safety behavior is changed.
