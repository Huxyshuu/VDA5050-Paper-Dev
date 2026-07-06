// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Timing.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__TIMING__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__TIMING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Timing in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__Timing
{
  /// Minimum interval for sending order messages to the AGV
  float min_order_interval;
  /// Minimum interval for sending state messages to the AGV
  float min_state_interval;
  /// Default interval for sending state messages if not defined
  float default_state_interval;
  /// Default interval for sending on visualization topic
  float visualization_interval;
} vda5050_msgs__msg__Timing;

// Struct for a sequence of vda5050_msgs__msg__Timing.
typedef struct vda5050_msgs__msg__Timing__Sequence
{
  vda5050_msgs__msg__Timing * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Timing__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__TIMING__STRUCT_H_
