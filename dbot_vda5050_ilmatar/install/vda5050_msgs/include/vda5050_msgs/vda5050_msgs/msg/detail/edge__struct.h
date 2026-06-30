// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Edge.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__EDGE__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__EDGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'edge_id'
// Member 'edge_description'
// Member 'start_node_id'
// Member 'end_node_id'
// Member 'direction'
#include "rosidl_runtime_c/string.h"
// Member 'trajectory'
#include "vda5050_msgs/msg/detail/trajectory__struct.h"
// Member 'actions'
#include "vda5050_msgs/msg/detail/action__struct.h"

/// Struct defined in msg/Edge in the package vda5050_msgs.
/**
  * Directional connection between two nodes
 */
typedef struct vda5050_msgs__msg__Edge
{
  /// Unique edge identification
  rosidl_runtime_c__String edge_id;
  /// Id to track the sequence of nodes and edges in an order and to simplify order
  /// updates. The variable sequence_id runs across all nodes and edges of the same order
  /// and is reset when a new order_id is issued.
  uint32_t sequence_id;
  /// Additional information on the edge
  rosidl_runtime_c__String edge_description;
  /// True indicates that the edge is part of the base. False indicates that the edge is
  /// part of the horizon.
  bool released;
  /// nodeID of startNode
  rosidl_runtime_c__String start_node_id;
  /// nodeID of endNode
  rosidl_runtime_c__String end_node_id;
  /// Permitted maximum speed on the edge. Speed is defined by the fastest point of the
  /// vehicle.
  double max_speed;
  /// Permitted maximum height of the vehicle, including the load, on edge
  double max_height;
  /// Permitted minimal height of the edge measured at the bottom of the load
  double min_height;
  /// Orientation of the AGV on the edge relative to the global project specific
  /// map coordinate origin (for holonomic vehicles with more than one driving
  /// direction).
  /// Example: orientation Pi/2 rad will lead to a rotation of 90 degrees.
  /// If AGVstarts in different orientation, rotate the vehicle on the edge to the
  /// desired orientation if rotationAllowed is set to “true”. If rotationAllowed
  /// is “false", rotate before entering the edge. If that is not possible, reject
  /// the order.
  /// If a trajectory with orientation is defined, follow the trajectories orientation.
  /// If a trajectory without orientation and the orientation field here is defined,
  /// apply the orientation to the tangent of the trajectory.
  double orientation;
  /// Sets direction at junctions for line-guided vehicles, to be defined initially
  /// (vehicle individual) Example: left, right, straight, 433MHz
  rosidl_runtime_c__String direction;
  /// “true”: rotation is allowed on the edge. “false”: rotation is not allowed on the edge.
  /// Optional: Default to “false”. If this value is set, rotation is allowed on the edge.
  bool rotation_allowed;
  /// Maximum rotation speed Optional: No limit if not set
  double max_rotation_speed;
  /// Trajectory JSON-object for this edge as a NURBS. Defines the curve on which the
  /// AGV should move between start_node and end_node. Optional: Can be omitted if AGV
  /// cannot process trajectories or if AGV plans its own trajectory.
  vda5050_msgs__msg__Trajectory trajectory;
  /// Length of the path from startNode to endNode. Optional: This value is used
  /// by lineguided AGVs to decrease their speed before reaching a stop position.
  double length;
  /// Array of action_ids to be executed on the edge. An action triggered by an edge will
  /// only be active for the time that the AGV is traversing the edge which triggered
  /// the action. When the AGV leaves the edge, the action will stop and the state
  /// before entering the edge will be restored.
  vda5050_msgs__msg__Action__Sequence actions;
} vda5050_msgs__msg__Edge;

// Struct for a sequence of vda5050_msgs__msg__Edge.
typedef struct vda5050_msgs__msg__Edge__Sequence
{
  vda5050_msgs__msg__Edge * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Edge__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__EDGE__STRUCT_H_
