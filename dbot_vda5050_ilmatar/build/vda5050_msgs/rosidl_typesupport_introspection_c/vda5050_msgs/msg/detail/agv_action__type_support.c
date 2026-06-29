// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vda5050_msgs:msg/AGVAction.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vda5050_msgs/msg/detail/agv_action__rosidl_typesupport_introspection_c.h"
#include "vda5050_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vda5050_msgs/msg/detail/agv_action__functions.h"
#include "vda5050_msgs/msg/detail/agv_action__struct.h"


// Include directives for member types
// Member `action_type`
// Member `action_description`
// Member `action_scopes`
// Member `result_description`
#include "rosidl_runtime_c/string_functions.h"
// Member `action_parameters`
#include "vda5050_msgs/msg/action_parameter_definition.h"
// Member `action_parameters`
#include "vda5050_msgs/msg/detail/action_parameter_definition__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_msgs__msg__AGVAction__init(message_memory);
}

void vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_fini_function(void * message_memory)
{
  vda5050_msgs__msg__AGVAction__fini(message_memory);
}

size_t vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__size_function__AGVAction__action_scopes(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_const_function__AGVAction__action_scopes(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_function__AGVAction__action_scopes(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__fetch_function__AGVAction__action_scopes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_const_function__AGVAction__action_scopes(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__assign_function__AGVAction__action_scopes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_function__AGVAction__action_scopes(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__resize_function__AGVAction__action_scopes(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__size_function__AGVAction__action_parameters(
  const void * untyped_member)
{
  const vda5050_msgs__msg__ActionParameterDefinition__Sequence * member =
    (const vda5050_msgs__msg__ActionParameterDefinition__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_const_function__AGVAction__action_parameters(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__ActionParameterDefinition__Sequence * member =
    (const vda5050_msgs__msg__ActionParameterDefinition__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_function__AGVAction__action_parameters(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__ActionParameterDefinition__Sequence * member =
    (vda5050_msgs__msg__ActionParameterDefinition__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__fetch_function__AGVAction__action_parameters(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__ActionParameterDefinition * item =
    ((const vda5050_msgs__msg__ActionParameterDefinition *)
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_const_function__AGVAction__action_parameters(untyped_member, index));
  vda5050_msgs__msg__ActionParameterDefinition * value =
    (vda5050_msgs__msg__ActionParameterDefinition *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__assign_function__AGVAction__action_parameters(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__ActionParameterDefinition * item =
    ((vda5050_msgs__msg__ActionParameterDefinition *)
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_function__AGVAction__action_parameters(untyped_member, index));
  const vda5050_msgs__msg__ActionParameterDefinition * value =
    (const vda5050_msgs__msg__ActionParameterDefinition *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__resize_function__AGVAction__action_parameters(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__ActionParameterDefinition__Sequence * member =
    (vda5050_msgs__msg__ActionParameterDefinition__Sequence *)(untyped_member);
  vda5050_msgs__msg__ActionParameterDefinition__Sequence__fini(member);
  return vda5050_msgs__msg__ActionParameterDefinition__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_message_member_array[5] = {
  {
    "action_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__AGVAction, action_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "action_description",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__AGVAction, action_description),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "action_scopes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__AGVAction, action_scopes),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__size_function__AGVAction__action_scopes,  // size() function pointer
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_const_function__AGVAction__action_scopes,  // get_const(index) function pointer
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_function__AGVAction__action_scopes,  // get(index) function pointer
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__fetch_function__AGVAction__action_scopes,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__assign_function__AGVAction__action_scopes,  // assign(index, value) function pointer
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__resize_function__AGVAction__action_scopes  // resize(index) function pointer
  },
  {
    "action_parameters",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__AGVAction, action_parameters),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__size_function__AGVAction__action_parameters,  // size() function pointer
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_const_function__AGVAction__action_parameters,  // get_const(index) function pointer
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__get_function__AGVAction__action_parameters,  // get(index) function pointer
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__fetch_function__AGVAction__action_parameters,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__assign_function__AGVAction__action_parameters,  // assign(index, value) function pointer
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__resize_function__AGVAction__action_parameters  // resize(index) function pointer
  },
  {
    "result_description",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__AGVAction, result_description),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_message_members = {
  "vda5050_msgs__msg",  // message namespace
  "AGVAction",  // message name
  5,  // number of fields
  sizeof(vda5050_msgs__msg__AGVAction),
  vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_message_member_array,  // message members
  vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_message_type_support_handle = {
  0,
  &vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, AGVAction)() {
  vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, ActionParameterDefinition)();
  if (!vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_message_type_support_handle.typesupport_identifier) {
    vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_msgs__msg__AGVAction__rosidl_typesupport_introspection_c__AGVAction_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
