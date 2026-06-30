// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/MaxStringLens.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MaxStringLens in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__MaxStringLens
{
  /// Maximum MQTT Message length
  uint32_t msg_len;
  /// Maximum length of serial-number part in MQTT-topics
  uint32_t topic_serial_len;
  /// Maximum length of all other parts in MQTT-topics (timestamp, versions, manufacturer)
  uint32_t topic_elem_len;
  /// Maximum length of ID-Strings
  uint32_t id_len;
  /// If true ID-strings need to contain numerical values only
  bool id_numerical_only;
  /// Maximum length of ENUM- and Key-Strings
  uint32_t enum_len;
  /// Maximum length of loadId Strings
  uint32_t load_id_len;
} vda5050_msgs__msg__MaxStringLens;

// Struct for a sequence of vda5050_msgs__msg__MaxStringLens.
typedef struct vda5050_msgs__msg__MaxStringLens__Sequence
{
  vda5050_msgs__msg__MaxStringLens * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__MaxStringLens__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__STRUCT_H_
