// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Envelope2D.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ENVELOPE2_D__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__ENVELOPE2_D__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'set'
// Member 'description'
#include "rosidl_runtime_c/string.h"
// Member 'polygon_points'
#include "vda5050_msgs/msg/detail/polygon_point__struct.h"

/// Struct defined in msg/Envelope2D in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__Envelope2D
{
  /// Name of the envelope curve set
  rosidl_runtime_c__String set;
  /// Envelope curve as a x/y-polygon
  vda5050_msgs__msg__PolygonPoint__Sequence polygon_points;
  rosidl_runtime_c__String description;
} vda5050_msgs__msg__Envelope2D;

// Struct for a sequence of vda5050_msgs__msg__Envelope2D.
typedef struct vda5050_msgs__msg__Envelope2D__Sequence
{
  vda5050_msgs__msg__Envelope2D * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Envelope2D__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__ENVELOPE2_D__STRUCT_H_
