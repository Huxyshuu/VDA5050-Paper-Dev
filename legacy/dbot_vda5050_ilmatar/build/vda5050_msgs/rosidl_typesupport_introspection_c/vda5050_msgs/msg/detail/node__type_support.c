// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vda5050_msgs:msg/Node.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vda5050_msgs/msg/detail/node__rosidl_typesupport_introspection_c.h"
#include "vda5050_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vda5050_msgs/msg/detail/node__functions.h"
#include "vda5050_msgs/msg/detail/node__struct.h"


// Include directives for member types
// Member `node_id`
// Member `node_description`
#include "rosidl_runtime_c/string_functions.h"
// Member `node_position`
#include "vda5050_msgs/msg/node_position.h"
// Member `node_position`
#include "vda5050_msgs/msg/detail/node_position__rosidl_typesupport_introspection_c.h"
// Member `actions`
#include "vda5050_msgs/msg/action.h"
// Member `actions`
#include "vda5050_msgs/msg/detail/action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_msgs__msg__Node__init(message_memory);
}

void vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_fini_function(void * message_memory)
{
  vda5050_msgs__msg__Node__fini(message_memory);
}

size_t vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__size_function__Node__actions(
  const void * untyped_member)
{
  const vda5050_msgs__msg__Action__Sequence * member =
    (const vda5050_msgs__msg__Action__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__get_const_function__Node__actions(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__Action__Sequence * member =
    (const vda5050_msgs__msg__Action__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__get_function__Node__actions(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__Action__Sequence * member =
    (vda5050_msgs__msg__Action__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__fetch_function__Node__actions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__Action * item =
    ((const vda5050_msgs__msg__Action *)
    vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__get_const_function__Node__actions(untyped_member, index));
  vda5050_msgs__msg__Action * value =
    (vda5050_msgs__msg__Action *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__assign_function__Node__actions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__Action * item =
    ((vda5050_msgs__msg__Action *)
    vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__get_function__Node__actions(untyped_member, index));
  const vda5050_msgs__msg__Action * value =
    (const vda5050_msgs__msg__Action *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__resize_function__Node__actions(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__Action__Sequence * member =
    (vda5050_msgs__msg__Action__Sequence *)(untyped_member);
  vda5050_msgs__msg__Action__Sequence__fini(member);
  return vda5050_msgs__msg__Action__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_message_member_array[6] = {
  {
    "node_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Node, node_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sequence_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Node, sequence_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_description",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Node, node_description),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "released",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Node, released),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Node, node_position),  // bytes offset in struct
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
    offsetof(vda5050_msgs__msg__Node, actions),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__size_function__Node__actions,  // size() function pointer
    vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__get_const_function__Node__actions,  // get_const(index) function pointer
    vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__get_function__Node__actions,  // get(index) function pointer
    vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__fetch_function__Node__actions,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__assign_function__Node__actions,  // assign(index, value) function pointer
    vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__resize_function__Node__actions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_message_members = {
  "vda5050_msgs__msg",  // message namespace
  "Node",  // message name
  6,  // number of fields
  sizeof(vda5050_msgs__msg__Node),
  vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_message_member_array,  // message members
  vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_message_type_support_handle = {
  0,
  &vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Node)() {
  vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, NodePosition)();
  vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Action)();
  if (!vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_message_type_support_handle.typesupport_identifier) {
    vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_msgs__msg__Node__rosidl_typesupport_introspection_c__Node_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
