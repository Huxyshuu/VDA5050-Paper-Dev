// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Velocity.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__VELOCITY__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__VELOCITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Velocity in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__Velocity
{
  /// forward velocity
  double vx;
  /// sideways velocity
  double vy;
  /// rotational velocity
  double omega;
} vda5050_msgs__msg__Velocity;

// Struct for a sequence of vda5050_msgs__msg__Velocity.
typedef struct vda5050_msgs__msg__Velocity__Sequence
{
  vda5050_msgs__msg__Velocity * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Velocity__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__VELOCITY__STRUCT_H_
