// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vda5050_connector:srv/SupportedActions.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__STRUCT_H_
#define VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SupportedActions in the package vda5050_connector.
typedef struct vda5050_connector__srv__SupportedActions_Request
{
  uint8_t structure_needs_at_least_one_member;
} vda5050_connector__srv__SupportedActions_Request;

// Struct for a sequence of vda5050_connector__srv__SupportedActions_Request.
typedef struct vda5050_connector__srv__SupportedActions_Request__Sequence
{
  vda5050_connector__srv__SupportedActions_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_connector__srv__SupportedActions_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'agv_actions'
#include "vda5050_msgs/msg/detail/agv_action__struct.h"

/// Struct defined in srv/SupportedActions in the package vda5050_connector.
typedef struct vda5050_connector__srv__SupportedActions_Response
{
  vda5050_msgs__msg__AGVAction__Sequence agv_actions;
} vda5050_connector__srv__SupportedActions_Response;

// Struct for a sequence of vda5050_connector__srv__SupportedActions_Response.
typedef struct vda5050_connector__srv__SupportedActions_Response__Sequence
{
  vda5050_connector__srv__SupportedActions_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vda5050_connector__srv__SupportedActions_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__STRUCT_H_
