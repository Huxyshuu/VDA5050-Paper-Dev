// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vda5050_msgs:msg/TypeSpecification.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vda5050_msgs/msg/detail/type_specification__rosidl_typesupport_introspection_c.h"
#include "vda5050_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vda5050_msgs/msg/detail/type_specification__functions.h"
#include "vda5050_msgs/msg/detail/type_specification__struct.h"


// Include directives for member types
// Member `series_name`
// Member `series_description`
// Member `agv_kinematic`
// Member `agv_class`
// Member `localization_types`
// Member `navigation_types`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_msgs__msg__TypeSpecification__init(message_memory);
}

void vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_fini_function(void * message_memory)
{
  vda5050_msgs__msg__TypeSpecification__fini(message_memory);
}

size_t vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__size_function__TypeSpecification__localization_types(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_const_function__TypeSpecification__localization_types(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_function__TypeSpecification__localization_types(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__fetch_function__TypeSpecification__localization_types(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_const_function__TypeSpecification__localization_types(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__assign_function__TypeSpecification__localization_types(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_function__TypeSpecification__localization_types(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__resize_function__TypeSpecification__localization_types(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__size_function__TypeSpecification__navigation_types(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_const_function__TypeSpecification__navigation_types(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_function__TypeSpecification__navigation_types(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__fetch_function__TypeSpecification__navigation_types(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_const_function__TypeSpecification__navigation_types(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__assign_function__TypeSpecification__navigation_types(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_function__TypeSpecification__navigation_types(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__resize_function__TypeSpecification__navigation_types(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_message_member_array[7] = {
  {
    "series_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__TypeSpecification, series_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "series_description",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__TypeSpecification, series_description),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "agv_kinematic",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__TypeSpecification, agv_kinematic),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "agv_class",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__TypeSpecification, agv_class),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_load_mass",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__TypeSpecification, max_load_mass),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "localization_types",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__TypeSpecification, localization_types),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__size_function__TypeSpecification__localization_types,  // size() function pointer
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_const_function__TypeSpecification__localization_types,  // get_const(index) function pointer
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_function__TypeSpecification__localization_types,  // get(index) function pointer
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__fetch_function__TypeSpecification__localization_types,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__assign_function__TypeSpecification__localization_types,  // assign(index, value) function pointer
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__resize_function__TypeSpecification__localization_types  // resize(index) function pointer
  },
  {
    "navigation_types",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__TypeSpecification, navigation_types),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__size_function__TypeSpecification__navigation_types,  // size() function pointer
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_const_function__TypeSpecification__navigation_types,  // get_const(index) function pointer
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__get_function__TypeSpecification__navigation_types,  // get(index) function pointer
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__fetch_function__TypeSpecification__navigation_types,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__assign_function__TypeSpecification__navigation_types,  // assign(index, value) function pointer
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__resize_function__TypeSpecification__navigation_types  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_message_members = {
  "vda5050_msgs__msg",  // message namespace
  "TypeSpecification",  // message name
  7,  // number of fields
  sizeof(vda5050_msgs__msg__TypeSpecification),
  vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_message_member_array,  // message members
  vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_message_type_support_handle = {
  0,
  &vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, TypeSpecification)() {
  if (!vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_message_type_support_handle.typesupport_identifier) {
    vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_msgs__msg__TypeSpecification__rosidl_typesupport_introspection_c__TypeSpecification_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
