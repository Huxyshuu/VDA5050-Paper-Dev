// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__POSITION__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Position in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__Position
{
  /// x-position in AGV-coordinate system
  double x;
  /// y-position in AGV-coordinate system
  double y;
  /// orientation of wheel in AGV-coordinate system - necessary for fixed wheels
  double theta;
} vda5050_msgs__msg__Position;

// Struct for a sequence of vda5050_msgs__msg__Position.
typedef struct vda5050_msgs__msg__Position__Sequence
{
  vda5050_msgs__msg__Position * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Position__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__POSITION__STRUCT_H_
