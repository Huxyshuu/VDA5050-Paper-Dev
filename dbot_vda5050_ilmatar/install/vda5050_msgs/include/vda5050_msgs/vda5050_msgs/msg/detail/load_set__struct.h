// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/LoadSet.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD_SET__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__LOAD_SET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'set_name'
// Member 'load_type'
// Member 'load_positions'
// Member 'description'
#include "rosidl_runtime_c/string.h"
// Member 'bounding_box_reference'
#include "vda5050_msgs/msg/detail/bounding_box_reference__struct.h"
// Member 'load_dimensions'
#include "vda5050_msgs/msg/detail/load_dimensions__struct.h"

/// Struct defined in msg/LoadSet in the package vda5050_msgs.
typedef struct vda5050_msgs__msg__LoadSet
{
  rosidl_runtime_c__String set_name;
  rosidl_runtime_c__String load_type;
  /// List of load positions / load handling devices
  rosidl_runtime_c__String__Sequence load_positions;
  /// Bounding box reference as defined in parameter loads[] in state-message
  vda5050_msgs__msg__BoundingBoxReference bounding_box_reference;
  vda5050_msgs__msg__LoadDimensions load_dimensions;
  /// Maximum weight of load type
  double max_weight;
  /// Minimum allowed height for handling of this load-type and weight
  double min_loadhandling_height;
  /// Maximum allowed height for handling of this load-type and weight
  double max_loadhandling_height;
  /// Minimum allowed depth for this load-type and weight
  double min_loadhandling_depth;
  /// Maximum allowed depth for this load-type and weight
  double max_loadhandling_depth;
  /// Minimum allowed tilt for this load-type and weight
  double min_loadhandling_tilt;
  /// Maximum allowed tilt for this load-type and weight
  double max_loadhandling_tilt;
  /// Maximum allowed speed for this load-type and weight
  double agv_speed_limit;
  /// Maximum allowed acceleration for this load-type and weight
  double agv_acceleration_limit;
  /// Maximum allowed deceleration for this load-type and weight
  double agv_deceleration_limit;
  /// Approx. time for picking up the load
  double pick_time;
  /// Approx. time for dropping the load
  double drop_time;
  /// Free description of the load handling set
  rosidl_runtime_c__String description;
} vda5050_msgs__msg__LoadSet;

// Struct for a sequence of vda5050_msgs__msg__LoadSet.
typedef struct vda5050_msgs__msg__LoadSet__Sequence
{
  vda5050_msgs__msg__LoadSet * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__LoadSet__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD_SET__STRUCT_H_
