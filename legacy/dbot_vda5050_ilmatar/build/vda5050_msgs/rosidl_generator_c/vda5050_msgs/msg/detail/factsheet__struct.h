// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Factsheet.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__FACTSHEET__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__FACTSHEET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'timestamp'
// Member 'version'
// Member 'manufacturer'
// Member 'serial_number'
#include "rosidl_runtime_c/string.h"
// Member 'type_specification'
#include "vda5050_msgs/msg/detail/type_specification__struct.h"
// Member 'physical_parameters'
#include "vda5050_msgs/msg/detail/physical_parameters__struct.h"
// Member 'protocol_limits'
#include "vda5050_msgs/msg/detail/protocol_limits__struct.h"
// Member 'protocol_features'
#include "vda5050_msgs/msg/detail/protocol_features__struct.h"
// Member 'agv_geometry'
#include "vda5050_msgs/msg/detail/agv_geometry__struct.h"
// Member 'load_specification'
#include "vda5050_msgs/msg/detail/load_specification__struct.h"

/// Struct defined in msg/Factsheet in the package vda5050_msgs.
/**
  * HEADER
 */
typedef struct vda5050_msgs__msg__Factsheet
{
  /// header ID of the message. The headerId is defined per topic and incremented by 1 with each sent
  /// (but not necessarily received) message.
  uint32_t header_id;
  /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
  rosidl_runtime_c__String timestamp;
  /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
  rosidl_runtime_c__String version;
  /// Manufacturer of the AGV
  rosidl_runtime_c__String manufacturer;
  /// Serial Number of the AGV
  rosidl_runtime_c__String serial_number;
  /// CONTENTS
  /// Class and capabilities of the AGV
  vda5050_msgs__msg__TypeSpecification type_specification;
  /// Physical properties of the AGV
  vda5050_msgs__msg__PhysicalParameters physical_parameters;
  /// Protocol limitations of the AGV
  vda5050_msgs__msg__ProtocolLimits protocol_limits;
  /// Supported and/or required optional parameters
  vda5050_msgs__msg__ProtocolFeatures protocol_features;
  /// Detailed definition of AGV geometry
  vda5050_msgs__msg__AGVGeometry agv_geometry;
  /// Load positions / load handling devices
  vda5050_msgs__msg__LoadSpecification load_specification;
  /// Detailed specification of localization
  int32_t localization_parameters;
} vda5050_msgs__msg__Factsheet;

// Struct for a sequence of vda5050_msgs__msg__Factsheet.
typedef struct vda5050_msgs__msg__Factsheet__Sequence
{
  vda5050_msgs__msg__Factsheet * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Factsheet__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__FACTSHEET__STRUCT_H_
