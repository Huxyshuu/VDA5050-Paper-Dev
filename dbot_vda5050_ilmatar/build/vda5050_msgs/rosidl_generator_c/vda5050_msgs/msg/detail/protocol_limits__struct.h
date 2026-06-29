// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/ProtocolLimits.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'max_string_lens'
#include "vda5050_msgs/msg/detail/max_string_lens__struct.h"
// Member 'max_array_lens'
#include "vda5050_msgs/msg/detail/max_array_lens__struct.h"
// Member 'timing'
#include "vda5050_msgs/msg/detail/timing__struct.h"

/// Struct defined in msg/ProtocolLimits in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__ProtocolLimits
{
  /// Maximum lengths of strings
  vda5050_msgs__msg__MaxStringLens max_string_lens;
  /// Maximum lengths of arrays
  vda5050_msgs__msg__MaxArrayLens max_array_lens;
  /// Timing information
  vda5050_msgs__msg__Timing timing;
} vda5050_msgs__msg__ProtocolLimits;

// Struct for a sequence of vda5050_msgs__msg__ProtocolLimits.
typedef struct vda5050_msgs__msg__ProtocolLimits__Sequence
{
  vda5050_msgs__msg__ProtocolLimits * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__ProtocolLimits__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__STRUCT_H_
