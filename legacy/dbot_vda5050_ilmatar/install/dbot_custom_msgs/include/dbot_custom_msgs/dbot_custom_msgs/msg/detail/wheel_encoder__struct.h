// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dbot_custom_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice

#ifndef DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__STRUCT_H_
#define DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/WheelEncoder in the package dbot_custom_msgs.
typedef struct dbot_custom_msgs__msg__WheelEncoder
{
  std_msgs__msg__Header header;
  double left;
  double right;
} dbot_custom_msgs__msg__WheelEncoder;

// Struct for a sequence of dbot_custom_msgs__msg__WheelEncoder.
typedef struct dbot_custom_msgs__msg__WheelEncoder__Sequence
{
  dbot_custom_msgs__msg__WheelEncoder * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dbot_custom_msgs__msg__WheelEncoder__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__STRUCT_H_
