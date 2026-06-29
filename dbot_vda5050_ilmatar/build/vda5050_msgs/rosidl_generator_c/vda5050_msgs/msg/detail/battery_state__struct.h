// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/BatteryState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BatteryState in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__BatteryState
{
  /// State of Charge: if AGV only provides values for good or bad battery levels, these will
  /// be indicated as 20% (bad) and 80% (good).
  double battery_charge;
  /// Battery Voltage
  double battery_voltage;
  /// State of Health
  int8_t battery_health;
  /// True: charging in progress False: AGV is currently not charging
  bool charging;
  /// Estimated reach with current SoC
  uint32_t reach;
} vda5050_msgs__msg__BatteryState;

// Struct for a sequence of vda5050_msgs__msg__BatteryState.
typedef struct vda5050_msgs__msg__BatteryState__Sequence
{
  vda5050_msgs__msg__BatteryState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__BatteryState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__STRUCT_H_
