// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'knot_vector'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'control_points'
#include "vda5050_msgs/msg/detail/control_point__struct.h"

/// Struct defined in msg/Trajectory in the package vda5050_msgs.
/**
  * Points defining a spline. Theta allows holonomic vehicles to rotate along the trajecotry.
 */
typedef struct vda5050_msgs__msg__Trajectory
{
  /// Range: [1 … infinity) Defines the number of control points that influence
  /// any given point on the curve. Increasing the degree increases continuity.
  /// If not defined, the default value is 1.
  double degree;
  /// Range: Sequence of parameter values that determines where and
  /// how the control points affect the NURBS curve. knot_vector has size of number
  /// of control points + degree + 1.
  rosidl_runtime_c__double__Sequence knot_vector;
  /// List of JSON control_point objects defining the control points of the nurbs,
  /// which includes the beginning and end point.
  vda5050_msgs__msg__ControlPoint__Sequence control_points;
} vda5050_msgs__msg__Trajectory;

// Struct for a sequence of vda5050_msgs__msg__Trajectory.
typedef struct vda5050_msgs__msg__Trajectory__Sequence
{
  vda5050_msgs__msg__Trajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Trajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_
