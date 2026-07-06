// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vda5050_msgs:msg/InstantActions.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vda5050_msgs/msg/detail/instant_actions__rosidl_typesupport_introspection_c.h"
#include "vda5050_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vda5050_msgs/msg/detail/instant_actions__functions.h"
#include "vda5050_msgs/msg/detail/instant_actions__struct.h"


// Include directives for member types
// Member `timestamp`
// Member `version`
// Member `manufacturer`
// Member `serial_number`
#include "rosidl_runtime_c/string_functions.h"
// Member `actions`
#include "vda5050_msgs/msg/action.h"
// Member `actions`
#include "vda5050_msgs/msg/detail/action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_msgs__msg__InstantActions__init(message_memory);
}

void vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_fini_function(void * message_memory)
{
  vda5050_msgs__msg__InstantActions__fini(message_memory);
}

size_t vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__size_function__InstantActions__actions(
  const void * untyped_member)
{
  const vda5050_msgs__msg__Action__Sequence * member =
    (const vda5050_msgs__msg__Action__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__get_const_function__InstantActions__actions(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__Action__Sequence * member =
    (const vda5050_msgs__msg__Action__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__get_function__InstantActions__actions(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__Action__Sequence * member =
    (vda5050_msgs__msg__Action__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__fetch_function__InstantActions__actions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__Action * item =
    ((const vda5050_msgs__msg__Action *)
    vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__get_const_function__InstantActions__actions(untyped_member, index));
  vda5050_msgs__msg__Action * value =
    (vda5050_msgs__msg__Action *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__assign_function__InstantActions__actions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__Action * item =
    ((vda5050_msgs__msg__Action *)
    vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__get_function__InstantActions__actions(untyped_member, index));
  const vda5050_msgs__msg__Action * value =
    (const vda5050_msgs__msg__Action *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__resize_function__InstantActions__actions(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__Action__Sequence * member =
    (vda5050_msgs__msg__Action__Sequence *)(untyped_member);
  vda5050_msgs__msg__Action__Sequence__fini(member);
  return vda5050_msgs__msg__Action__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_message_member_array[6] = {
  {
    "header_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__InstantActions, header_id),  // bytes offset in struct
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
    offsetof(vda5050_msgs__msg__InstantActions, timestamp),  // bytes offset in struct
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
    offsetof(vda5050_msgs__msg__InstantActions, version),  // bytes offset in struct
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
    offsetof(vda5050_msgs__msg__InstantActions, manufacturer),  // bytes offset in struct
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
    offsetof(vda5050_msgs__msg__InstantActions, serial_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "actions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__InstantActions, actions),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__size_function__InstantActions__actions,  // size() function pointer
    vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__get_const_function__InstantActions__actions,  // get_const(index) function pointer
    vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__get_function__InstantActions__actions,  // get(index) function pointer
    vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__fetch_function__InstantActions__actions,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__assign_function__InstantActions__actions,  // assign(index, value) function pointer
    vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__resize_function__InstantActions__actions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_message_members = {
  "vda5050_msgs__msg",  // message namespace
  "InstantActions",  // message name
  6,  // number of fields
  sizeof(vda5050_msgs__msg__InstantActions),
  vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_message_member_array,  // message members
  vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_message_type_support_handle = {
  0,
  &vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, InstantActions)() {
  vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Action)();
  if (!vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_message_type_support_handle.typesupport_identifier) {
    vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_msgs__msg__InstantActions__rosidl_typesupport_introspection_c__InstantActions_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
