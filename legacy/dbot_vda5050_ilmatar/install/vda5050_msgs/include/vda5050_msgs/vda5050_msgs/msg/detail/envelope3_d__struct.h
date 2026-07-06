// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Envelope3D.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ENVELOPE3_D__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__ENVELOPE3_D__STRUCT_H_

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
// Member 'format'
// Member 'data'
// Member 'url'
// Member 'description'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Envelope3D in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__Envelope3D
{
  /// Name of the envelope curve set
  rosidl_runtime_c__String set;
  rosidl_runtime_c__String format;
  rosidl_runtime_c__String data;
  /// Protocol and url-definition for downloading the 3D-envelope curve data
  rosidl_runtime_c__String url;
  rosidl_runtime_c__String description;
} vda5050_msgs__msg__Envelope3D;

// Struct for a sequence of vda5050_msgs__msg__Envelope3D.
typedef struct vda5050_msgs__msg__Envelope3D__Sequence
{
  vda5050_msgs__msg__Envelope3D * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Envelope3D__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__ENVELOPE3_D__STRUCT_H_
