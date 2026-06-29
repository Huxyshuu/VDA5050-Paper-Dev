// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/PhysicalParameters.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PhysicalParameters in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__PhysicalParameters
{
  /// Minimal controlled continuous speed of the AGV
  double speed_min;
  /// Maximum speed of the AGV
  double speed_max;
  /// Maximum acceleration with maximum load
  double acceleration_max;
  /// Maximum deceleration with maximum load
  double deceleration_max;
  /// Minimum height of the AGV
  double height_min;
  /// Maximum height of the AGV
  double height_max;
  /// Width of the AGV
  double width;
  /// Length of the AGV
  double length;
} vda5050_msgs__msg__PhysicalParameters;

// Struct for a sequence of vda5050_msgs__msg__PhysicalParameters.
typedef struct vda5050_msgs__msg__PhysicalParameters__Sequence
{
  vda5050_msgs__msg__PhysicalParameters * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__PhysicalParameters__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__STRUCT_H_
