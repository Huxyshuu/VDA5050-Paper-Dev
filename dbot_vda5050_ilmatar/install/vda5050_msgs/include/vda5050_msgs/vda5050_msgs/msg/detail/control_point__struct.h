// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/ControlPoint.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__CONTROL_POINT__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__CONTROL_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ControlPoint in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__ControlPoint
{
  /// X coordinate described in the world coordinate system.
  double x;
  /// Y coordinate described in the world coordinate system.
  double y;
  /// [rad] Range [-pi...pi] Orientation of the AGV on this position of the curve.
  /// The orientation is in world coordinates.
  /// When not defined the orientation of the AGV will be tangential to the curve.
  double orientation;
  /// Range [0..infinity) The weight with which this control point pulls on the curve.
  /// When not defined, the default will be 1.0
  double weight;
} vda5050_msgs__msg__ControlPoint;

// Struct for a sequence of vda5050_msgs__msg__ControlPoint.
typedef struct vda5050_msgs__msg__ControlPoint__Sequence
{
  vda5050_msgs__msg__ControlPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__ControlPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__CONTROL_POINT__STRUCT_H_
