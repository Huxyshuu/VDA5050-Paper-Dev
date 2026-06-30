// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/AGVPosition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__STRUCT_H_

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

/// Struct defined in msg/AGVPosition in the package vda5050_msgs.
/**
  * Defines the position on a map in world coordinates. Each floor has its own map.
 */
typedef struct vda5050_msgs__msg__AGVPosition
{
  /// False: position is not initialized True: position is initialized
  bool position_initialized;
  /// Range: Describes the quality of the localization and therefore, can be used
  /// e. g. by SLAMAGVs to describe how accurate the current position information is.
  /// 0.0: position unknown 1.0: position known
  double localization_score;
  /// Value for the deviation range of the position in meters.
  double deviation_range;
  /// X-position on the map in reference to the map coordinate system. Precision is up to
  /// the specific implementation
  double x;
  /// Y-position on the map in reference to the map coordinate system. Precision is up to
  /// the specific implementation.
  double y;
  /// [rad] Range: [-Pi … Pi] Orientation of the AGV.
  double theta;
  /// Unique identification of the map in which the position is referenced. Each map has the
  /// same origin of coordinates. When an AGV uses an elevator, e. g. leading from a departure
  /// floor to a target floor, it will disappear off the map of the departure floor and spawn
  /// in the related lift node on the map of the target floor.
  rosidl_runtime_c__String map_id;
  /// Additional information on the map.
  rosidl_runtime_c__String map_description;
} vda5050_msgs__msg__AGVPosition;

// Struct for a sequence of vda5050_msgs__msg__AGVPosition.
typedef struct vda5050_msgs__msg__AGVPosition__Sequence
{
  vda5050_msgs__msg__AGVPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__AGVPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__STRUCT_H_
