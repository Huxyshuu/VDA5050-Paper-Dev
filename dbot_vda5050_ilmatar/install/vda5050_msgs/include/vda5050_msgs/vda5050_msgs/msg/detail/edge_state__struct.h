// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/EdgeState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__STRUCT_H_

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
#include "rosidl_runtime_c/string.h"
// Member 'trajectory'
#include "vda5050_msgs/msg/detail/trajectory__struct.h"

/// Struct defined in msg/EdgeState in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__EdgeState
{
  /// Unique edge identification
  rosidl_runtime_c__String edge_id;
  /// sequenceId to differentiate between multiple edges with
  uint32_t sequence_id;
  /// Additional information on the edge
  rosidl_runtime_c__String edge_description;
  /// True indicates that the edge is part of the base. False indicates that the edge is
  /// part of the horizon.
  bool released;
  /// The trajectory is to be communicated as a NURBS and is defined in chapter6.4
  /// Trajectory segments are from the point where the AGV starts to enter the edge
  /// until the point where it reports that the next node was traversed.
  vda5050_msgs__msg__Trajectory trajectory;
} vda5050_msgs__msg__EdgeState;

// Struct for a sequence of vda5050_msgs__msg__EdgeState.
typedef struct vda5050_msgs__msg__EdgeState__Sequence
{
  vda5050_msgs__msg__EdgeState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__EdgeState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__STRUCT_H_
