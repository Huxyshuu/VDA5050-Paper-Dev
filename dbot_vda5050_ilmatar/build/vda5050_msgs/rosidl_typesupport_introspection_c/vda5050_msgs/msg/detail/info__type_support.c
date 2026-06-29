// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vda5050_msgs:msg/Info.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vda5050_msgs/msg/detail/info__rosidl_typesupport_introspection_c.h"
#include "vda5050_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vda5050_msgs/msg/detail/info__functions.h"
#include "vda5050_msgs/msg/detail/info__struct.h"


// Include directives for member types
// Member `info_type`
// Member `info_description`
// Member `info_level`
#include "rosidl_runtime_c/string_functions.h"
// Member `info_references`
#include "vda5050_msgs/msg/info_reference.h"
// Member `info_references`
#include "vda5050_msgs/msg/detail/info_reference__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_msgs__msg__Info__init(message_memory);
}

void vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_fini_function(void * message_memory)
{
  vda5050_msgs__msg__Info__fini(message_memory);
}

size_t vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__size_function__Info__info_references(
  const void * untyped_member)
{
  const vda5050_msgs__msg__InfoReference__Sequence * member =
    (const vda5050_msgs__msg__InfoReference__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__get_const_function__Info__info_references(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__InfoReference__Sequence * member =
    (const vda5050_msgs__msg__InfoReference__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__get_function__Info__info_references(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__InfoReference__Sequence * member =
    (vda5050_msgs__msg__InfoReference__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__fetch_function__Info__info_references(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__InfoReference * item =
    ((const vda5050_msgs__msg__InfoReference *)
    vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__get_const_function__Info__info_references(untyped_member, index));
  vda5050_msgs__msg__InfoReference * value =
    (vda5050_msgs__msg__InfoReference *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__assign_function__Info__info_references(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__InfoReference * item =
    ((vda5050_msgs__msg__InfoReference *)
    vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__get_function__Info__info_references(untyped_member, index));
  const vda5050_msgs__msg__InfoReference * value =
    (const vda5050_msgs__msg__InfoReference *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__resize_function__Info__info_references(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__InfoReference__Sequence * member =
    (vda5050_msgs__msg__InfoReference__Sequence *)(untyped_member);
  vda5050_msgs__msg__InfoReference__Sequence__fini(member);
  return vda5050_msgs__msg__InfoReference__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_message_member_array[4] = {
  {
    "info_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Info, info_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "info_references",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Info, info_references),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__size_function__Info__info_references,  // size() function pointer
    vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__get_const_function__Info__info_references,  // get_const(index) function pointer
    vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__get_function__Info__info_references,  // get(index) function pointer
    vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__fetch_function__Info__info_references,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__assign_function__Info__info_references,  // assign(index, value) function pointer
    vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__resize_function__Info__info_references  // resize(index) function pointer
  },
  {
    "info_description",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Info, info_description),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "info_level",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__Info, info_level),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_message_members = {
  "vda5050_msgs__msg",  // message namespace
  "Info",  // message name
  4,  // number of fields
  sizeof(vda5050_msgs__msg__Info),
  vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_message_member_array,  // message members
  vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_message_type_support_handle = {
  0,
  &vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, Info)() {
  vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, InfoReference)();
  if (!vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_message_type_support_handle.typesupport_identifier) {
    vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_msgs__msg__Info__rosidl_typesupport_introspection_c__Info_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
