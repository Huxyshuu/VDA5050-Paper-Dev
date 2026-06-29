// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_msgs:msg/Connection.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__CONNECTION__STRUCT_H_
#define VDA5050_MSGS__MSG__DETAIL__CONNECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'ONLINE'.
static const char * const vda5050_msgs__msg__Connection__ONLINE = "ONLINE";

/// Constant 'OFFLINE'.
static const char * const vda5050_msgs__msg__Connection__OFFLINE = "OFFLINE";

/// Constant 'CONNECTIONBROKEN'.
static const char * const vda5050_msgs__msg__Connection__CONNECTIONBROKEN = "CONNECTIONBROKEN";

// Include directives for member types
// Member 'timestamp'
// Member 'version'
// Member 'manufacturer'
// Member 'serial_number'
// Member 'connection_state'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Connection in the package vda5050_msgs.
/**
  * HEADER
 */
typedef struct vda5050_msgs__msg__Connection
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
  /// Enum{ONLINE, OFFLINE, CONNECTIONBROKEN}
  /// ONLINE: connection between AGV and broker is active.
  /// OFFLINE: connection between AGV and broker has gone offline in a coordinated way.
  /// CONNECTIONBROKEN: The connection between  AGV and  broker  has unexpectedly ended.
  rosidl_runtime_c__String connection_state;
} vda5050_msgs__msg__Connection;

// Struct for a sequence of vda5050_msgs__msg__Connection.
typedef struct vda5050_msgs__msg__Connection__Sequence
{
  vda5050_msgs__msg__Connection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_msgs__msg__Connection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_MSGS__MSG__DETAIL__CONNECTION__STRUCT_H_
