// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/AGVGeometry.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'wheel_definitions'
#include "vda5050_msgs/msg/detail/wheel_definition__struct.h"
// Member 'envelopes2d'
#include "vda5050_msgs/msg/detail/envelope2_d__struct.h"
// Member 'envelopes3d'
#include "vda5050_msgs/msg/detail/envelope3_d__struct.h"

/// Struct defined in msg/AGVGeometry in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__AGVGeometry
{
  /// List of wheels, containing wheel-arrangement and geometry
  vda5050_msgs__msg__WheelDefinition__Sequence wheel_definitions;
  vda5050_msgs__msg__Envelope2D__Sequence envelopes2d;
  /// List of AGV-envelope curves in 3D
  vda5050_msgs__msg__Envelope3D__Sequence envelopes3d;
} vda5050_msgs__msg__AGVGeometry;

// Struct for a sequence of vda5050_msgs__msg__AGVGeometry.
typedef struct vda5050_msgs__msg__AGVGeometry__Sequence
{
  vda5050_msgs__msg__AGVGeometry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__AGVGeometry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_GEOMETRY__STRUCT_H_
