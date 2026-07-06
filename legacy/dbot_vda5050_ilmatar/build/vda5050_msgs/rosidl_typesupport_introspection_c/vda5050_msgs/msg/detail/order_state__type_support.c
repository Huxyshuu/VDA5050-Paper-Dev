// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vda5050_msgs:msg/OrderState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vda5050_msgs/msg/detail/order_state__rosidl_typesupport_introspection_c.h"
#include "vda5050_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vda5050_msgs/msg/detail/order_state__functions.h"
#include "vda5050_msgs/msg/detail/order_state__struct.h"


// Include directives for member types
// Member `timestamp`
// Member `version`
// Member `manufacturer`
// Member `serial_number`
// Member `order_id`
// Member `zone_set_id`
// Member `last_node_id`
// Member `operating_mode`
#include "rosidl_runtime_c/string_functions.h"
// Member `node_states`
#include "vda5050_msgs/msg/node_state.h"
// Member `node_states`
#include "vda5050_msgs/msg/detail/node_state__rosidl_typesupport_introspection_c.h"
// Member `edge_states`
#include "vda5050_msgs/msg/edge_state.h"
// Member `edge_states`
#include "vda5050_msgs/msg/detail/edge_state__rosidl_typesupport_introspection_c.h"
// Member `agv_position`
#include "vda5050_msgs/msg/agv_position.h"
// Member `agv_position`
#include "vda5050_msgs/msg/detail/agv_position__rosidl_typesupport_introspection_c.h"
// Member `velocity`
#include "vda5050_msgs/msg/velocity.h"
// Member `velocity`
#include "vda5050_msgs/msg/detail/velocity__rosidl_typesupport_introspection_c.h"
// Member `loads`
#include "vda5050_msgs/msg/load.h"
// Member `loads`
#include "vda5050_msgs/msg/detail/load__rosidl_typesupport_introspection_c.h"
// Member `action_states`
#include "vda5050_msgs/msg/current_action.h"
// Member `action_states`
#include "vda5050_msgs/msg/detail/current_action__rosidl_typesupport_introspection_c.h"
// Member `battery_state`
#include "vda5050_msgs/msg/battery_state.h"
// Member `battery_state`
#include "vda5050_msgs/msg/detail/battery_state__rosidl_typesupport_introspection_c.h"
// Member `errors`
#include "vda5050_msgs/msg/error.h"
// Member `errors`
#include "vda5050_msgs/msg/detail/error__rosidl_typesupport_introspection_c.h"
// Member `informations`
#include "vda5050_msgs/msg/info.h"
// Member `informations`
#include "vda5050_msgs/msg/detail/info__rosidl_typesupport_introspection_c.h"
// Member `safety_state`
#include "vda5050_msgs/msg/safety_state.h"
// Member `safety_state`
#include "vda5050_msgs/msg/detail/safety_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_msgs__msg__OrderState__init(message_memory);
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_fini_function(void * message_memory)
{
  vda5050_msgs__msg__OrderState__fini(message_memory);
}

size_t vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__node_states(
  const void * untyped_member)
{
  const vda5050_msgs__msg__NodeState__Sequence * member =
    (const vda5050_msgs__msg__NodeState__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__node_states(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__NodeState__Sequence * member =
    (const vda5050_msgs__msg__NodeState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__node_states(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__NodeState__Sequence * member =
    (vda5050_msgs__msg__NodeState__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__node_states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__NodeState * item =
    ((const vda5050_msgs__msg__NodeState *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__node_states(untyped_member, index));
  vda5050_msgs__msg__NodeState * value =
    (vda5050_msgs__msg__NodeState *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__node_states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__NodeState * item =
    ((vda5050_msgs__msg__NodeState *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__node_states(untyped_member, index));
  const vda5050_msgs__msg__NodeState * value =
    (const vda5050_msgs__msg__NodeState *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__node_states(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__NodeState__Sequence * member =
    (vda5050_msgs__msg__NodeState__Sequence *)(untyped_member);
  vda5050_msgs__msg__NodeState__Sequence__fini(member);
  return vda5050_msgs__msg__NodeState__Sequence__init(member, size);
}

size_t vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__edge_states(
  const void * untyped_member)
{
  const vda5050_msgs__msg__EdgeState__Sequence * member =
    (const vda5050_msgs__msg__EdgeState__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__edge_states(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__EdgeState__Sequence * member =
    (const vda5050_msgs__msg__EdgeState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__edge_states(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__EdgeState__Sequence * member =
    (vda5050_msgs__msg__EdgeState__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__edge_states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__EdgeState * item =
    ((const vda5050_msgs__msg__EdgeState *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__edge_states(untyped_member, index));
  vda5050_msgs__msg__EdgeState * value =
    (vda5050_msgs__msg__EdgeState *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__edge_states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__EdgeState * item =
    ((vda5050_msgs__msg__EdgeState *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__edge_states(untyped_member, index));
  const vda5050_msgs__msg__EdgeState * value =
    (const vda5050_msgs__msg__EdgeState *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__edge_states(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__EdgeState__Sequence * member =
    (vda5050_msgs__msg__EdgeState__Sequence *)(untyped_member);
  vda5050_msgs__msg__EdgeState__Sequence__fini(member);
  return vda5050_msgs__msg__EdgeState__Sequence__init(member, size);
}

size_t vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__loads(
  const void * untyped_member)
{
  const vda5050_msgs__msg__Load__Sequence * member =
    (const vda5050_msgs__msg__Load__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__loads(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__Load__Sequence * member =
    (const vda5050_msgs__msg__Load__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__loads(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__Load__Sequence * member =
    (vda5050_msgs__msg__Load__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__loads(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__Load * item =
    ((const vda5050_msgs__msg__Load *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__loads(untyped_member, index));
  vda5050_msgs__msg__Load * value =
    (vda5050_msgs__msg__Load *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__loads(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__Load * item =
    ((vda5050_msgs__msg__Load *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__loads(untyped_member, index));
  const vda5050_msgs__msg__Load * value =
    (const vda5050_msgs__msg__Load *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__loads(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__Load__Sequence * member =
    (vda5050_msgs__msg__Load__Sequence *)(untyped_member);
  vda5050_msgs__msg__Load__Sequence__fini(member);
  return vda5050_msgs__msg__Load__Sequence__init(member, size);
}

size_t vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__action_states(
  const void * untyped_member)
{
  const vda5050_msgs__msg__CurrentAction__Sequence * member =
    (const vda5050_msgs__msg__CurrentAction__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__action_states(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__CurrentAction__Sequence * member =
    (const vda5050_msgs__msg__CurrentAction__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__action_states(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__CurrentAction__Sequence * member =
    (vda5050_msgs__msg__CurrentAction__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__action_states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__CurrentAction * item =
    ((const vda5050_msgs__msg__CurrentAction *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__action_states(untyped_member, index));
  vda5050_msgs__msg__CurrentAction * value =
    (vda5050_msgs__msg__CurrentAction *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__action_states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__CurrentAction * item =
    ((vda5050_msgs__msg__CurrentAction *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__action_states(untyped_member, index));
  const vda5050_msgs__msg__CurrentAction * value =
    (const vda5050_msgs__msg__CurrentAction *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__action_states(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__CurrentAction__Sequence * member =
    (vda5050_msgs__msg__CurrentAction__Sequence *)(untyped_member);
  vda5050_msgs__msg__CurrentAction__Sequence__fini(member);
  return vda5050_msgs__msg__CurrentAction__Sequence__init(member, size);
}

size_t vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__errors(
  const void * untyped_member)
{
  const vda5050_msgs__msg__Error__Sequence * member =
    (const vda5050_msgs__msg__Error__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__errors(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__Error__Sequence * member =
    (const vda5050_msgs__msg__Error__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__errors(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__Error__Sequence * member =
    (vda5050_msgs__msg__Error__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__errors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__Error * item =
    ((const vda5050_msgs__msg__Error *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__errors(untyped_member, index));
  vda5050_msgs__msg__Error * value =
    (vda5050_msgs__msg__Error *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__errors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__Error * item =
    ((vda5050_msgs__msg__Error *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__errors(untyped_member, index));
  const vda5050_msgs__msg__Error * value =
    (const vda5050_msgs__msg__Error *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__errors(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__Error__Sequence * member =
    (vda5050_msgs__msg__Error__Sequence *)(untyped_member);
  vda5050_msgs__msg__Error__Sequence__fini(member);
  return vda5050_msgs__msg__Error__Sequence__init(member, size);
}

size_t vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__informations(
  const void * untyped_member)
{
  const vda5050_msgs__msg__Info__Sequence * member =
    (const vda5050_msgs__msg__Info__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__informations(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__Info__Sequence * member =
    (const vda5050_msgs__msg__Info__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__informations(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__Info__Sequence * member =
    (vda5050_msgs__msg__Info__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__informations(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__Info * item =
    ((const vda5050_msgs__msg__Info *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__informations(untyped_member, index));
  vda5050_msgs__msg__Info * value =
    (vda5050_msgs__msg__Info *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__informations(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__Info * item =
    ((vda5050_msgs__msg__Info *)
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__informations(untyped_member, index));
  const vda5050_msgs__msg__Info * value =
    (const vda5050_msgs__msg__Info *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__informations(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__Info__Sequence * member =
    (vda5050_msgs__msg__Info__Sequence *)(untyped_member);
  vda5050_msgs__msg__Info__Sequence__fini(member);
  return vda5050_msgs__msg__Info__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array[25] = {
  {
    "header_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, header_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "version",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, version),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "manufacturer",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, manufacturer),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "serial_number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, serial_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "order_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, order_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "order_update_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, order_update_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "zone_set_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, zone_set_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "last_node_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, last_node_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "last_node_sequence_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, last_node_sequence_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, node_states),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__node_states,  // size() function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__node_states,  // get_const(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__node_states,  // get(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__node_states,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__node_states,  // assign(index, value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__node_states  // resize(index) function pointer
  },
  {
    "edge_states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, edge_states),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__edge_states,  // size() function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__edge_states,  // get_const(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__edge_states,  // get(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__edge_states,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__edge_states,  // assign(index, value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__edge_states  // resize(index) function pointer
  },
  {
    "agv_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, agv_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "loads",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, loads),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__loads,  // size() function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__loads,  // get_const(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__loads,  // get(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__loads,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__loads,  // assign(index, value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__loads  // resize(index) function pointer
  },
  {
    "driving",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, driving),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "paused",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, paused),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "new_base_request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, new_base_request),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_since_last_node",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, distance_since_last_node),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "action_states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, action_states),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__action_states,  // size() function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__action_states,  // get_const(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__action_states,  // get(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__action_states,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__action_states,  // assign(index, value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__action_states  // resize(index) function pointer
  },
  {
    "battery_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, battery_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "operating_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, operating_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "errors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, errors),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__errors,  // size() function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__errors,  // get_const(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__errors,  // get(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__errors,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__errors,  // assign(index, value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__errors  // resize(index) function pointer
  },
  {
    "informations",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, informations),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__size_function__OrderState__informations,  // size() function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_const_function__OrderState__informations,  // get_const(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__get_function__OrderState__informations,  // get(index) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__fetch_function__OrderState__informations,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__assign_function__OrderState__informations,  // assign(index, value) function pointer
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__resize_function__OrderState__informations  // resize(index) function pointer
  },
  {
    "safety_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__OrderState, safety_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_members = {
  "vda5050_msgs__msg",  // message namespace
  "OrderState",  // message name
  25,  // number of fields
  sizeof(vda5050_msgs__msg__OrderState),
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array,  // message members
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_type_support_handle = {
  0,
  &vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, OrderState)() {
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array[10].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, NodeState)();
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array[11].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, EdgeState)();
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array[12].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, AGVPosition)();
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array[13].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Velocity)();
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array[14].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Load)();
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array[19].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, CurrentAction)();
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array[20].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, BatteryState)();
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array[22].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Error)();
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array[23].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Info)();
  vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_member_array[24].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, SafetyState)();
  if (!vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_type_support_handle.typesupport_identifier) {
    vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_msgs__msg__OrderState__rosidl_typesupport_introspection_c__OrderState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
