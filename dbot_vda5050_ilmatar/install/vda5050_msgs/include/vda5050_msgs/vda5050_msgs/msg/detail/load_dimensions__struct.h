// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/LoadDimensions.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD_DIMENSIONS__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__LOAD_DIMENSIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/LoadDimensions in the package vda5050_msgs.
/**
  * Dimensions of the load’s bounding box in meters.
 */
typedef struct vda5050_msgs__msg__LoadDimensions
{
  /// Absolute length of the load’s bounding box.
  double length;
  /// Absolute width of the load’s bounding box.
  double width;
  /// Absolute height of the load’s bounding box. Optional: Set value only if known.
  double height;
} vda5050_msgs__msg__LoadDimensions;

// Struct for a sequence of vda5050_msgs__msg__LoadDimensions.
typedef struct vda5050_msgs__msg__LoadDimensions__Sequence
{
  vda5050_msgs__msg__LoadDimensions * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__LoadDimensions__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD_DIMENSIONS__STRUCT_H_
