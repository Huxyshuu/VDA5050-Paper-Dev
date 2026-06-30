// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/NodePosition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__NODE_POSITION__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__NODE_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'map_id'
// Member 'map_description'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/NodePosition in the package vda5050_msgs.
/**
  * Defines the position on a map in world coordinates. Each floor has its own map.
 */
typedef struct vda5050_msgs__msg__NodePosition
{
  /// X-position on the map in reference to the world coordinate system
  double x;
  /// Y-position on the map in reference to the world coordinate system
  double y;
  /// The angular dimension
  double theta;
  /// Indicates how exact an AGV has to drive over a node in order for it
  /// to count as traversed.
  ///
  /// If = 0: no deviation is allowed (no deviation means within the
  /// normal tolerance of the AGV manufacturer).
  ///
  /// If > 0: allowed deviationradius in meters. If the AGV passes a node
  /// within the deviation-radius, the node is considered to have been
  /// traversed.
  float allowed_deviation_x_y;
  /// Range:
  /// Indicates how big the deviation of theta angle can be.
  /// The lowest acceptable angle  is theta -allowedDevaitionTheta and
  /// the  highest acceptable angle is theta + allowedDeviationTheta
  float allowed_deviation_theta;
  /// Unique identification of the map in which the position is referenced. Each map has the same
  /// origin of coordinates. When an AGV uses an elevator, e. g. leading from a departure floor to a
  /// target floor, it will disappear off the map of the departure floor and spawn in the related
  /// lift node on the map of the target floor.
  rosidl_runtime_c__String map_id;
  /// Additional information on the map
  rosidl_runtime_c__String map_description;
} vda5050_msgs__msg__NodePosition;

// Struct for a sequence of vda5050_msgs__msg__NodePosition.
typedef struct vda5050_msgs__msg__NodePosition__Sequence
{
  vda5050_msgs__msg__NodePosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__NodePosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__NODE_POSITION__STRUCT_H_
