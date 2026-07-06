// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vda5050_msgs:msg/ProtocolFeatures.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vda5050_msgs/msg/detail/protocol_features__rosidl_typesupport_introspection_c.h"
#include "vda5050_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vda5050_msgs/msg/detail/protocol_features__functions.h"
#include "vda5050_msgs/msg/detail/protocol_features__struct.h"


// Include directives for member types
// Member `optional_parameters`
#include "vda5050_msgs/msg/optional_parameter.h"
// Member `optional_parameters`
#include "vda5050_msgs/msg/detail/optional_parameter__rosidl_typesupport_introspection_c.h"
// Member `agv_actions`
#include "vda5050_msgs/msg/agv_action.h"
// Member `agv_actions`
#include "vda5050_msgs/msg/detail/agv_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vda5050_msgs__msg__ProtocolFeatures__init(message_memory);
}

void vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_fini_function(void * message_memory)
{
  vda5050_msgs__msg__ProtocolFeatures__fini(message_memory);
}

size_t vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__size_function__ProtocolFeatures__optional_parameters(
  const void * untyped_member)
{
  const vda5050_msgs__msg__OptionalParameter__Sequence * member =
    (const vda5050_msgs__msg__OptionalParameter__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_const_function__ProtocolFeatures__optional_parameters(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__OptionalParameter__Sequence * member =
    (const vda5050_msgs__msg__OptionalParameter__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_function__ProtocolFeatures__optional_parameters(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__OptionalParameter__Sequence * member =
    (vda5050_msgs__msg__OptionalParameter__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__fetch_function__ProtocolFeatures__optional_parameters(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__OptionalParameter * item =
    ((const vda5050_msgs__msg__OptionalParameter *)
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_const_function__ProtocolFeatures__optional_parameters(untyped_member, index));
  vda5050_msgs__msg__OptionalParameter * value =
    (vda5050_msgs__msg__OptionalParameter *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__assign_function__ProtocolFeatures__optional_parameters(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__OptionalParameter * item =
    ((vda5050_msgs__msg__OptionalParameter *)
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_function__ProtocolFeatures__optional_parameters(untyped_member, index));
  const vda5050_msgs__msg__OptionalParameter * value =
    (const vda5050_msgs__msg__OptionalParameter *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__resize_function__ProtocolFeatures__optional_parameters(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__OptionalParameter__Sequence * member =
    (vda5050_msgs__msg__OptionalParameter__Sequence *)(untyped_member);
  vda5050_msgs__msg__OptionalParameter__Sequence__fini(member);
  return vda5050_msgs__msg__OptionalParameter__Sequence__init(member, size);
}

size_t vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__size_function__ProtocolFeatures__agv_actions(
  const void * untyped_member)
{
  const vda5050_msgs__msg__AGVAction__Sequence * member =
    (const vda5050_msgs__msg__AGVAction__Sequence *)(untyped_member);
  return member->size;
}

const void * vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_const_function__ProtocolFeatures__agv_actions(
  const void * untyped_member, size_t index)
{
  const vda5050_msgs__msg__AGVAction__Sequence * member =
    (const vda5050_msgs__msg__AGVAction__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_function__ProtocolFeatures__agv_actions(
  void * untyped_member, size_t index)
{
  vda5050_msgs__msg__AGVAction__Sequence * member =
    (vda5050_msgs__msg__AGVAction__Sequence *)(untyped_member);
  return &member->data[index];
}

void vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__fetch_function__ProtocolFeatures__agv_actions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vda5050_msgs__msg__AGVAction * item =
    ((const vda5050_msgs__msg__AGVAction *)
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_const_function__ProtocolFeatures__agv_actions(untyped_member, index));
  vda5050_msgs__msg__AGVAction * value =
    (vda5050_msgs__msg__AGVAction *)(untyped_value);
  *value = *item;
}

void vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__assign_function__ProtocolFeatures__agv_actions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vda5050_msgs__msg__AGVAction * item =
    ((vda5050_msgs__msg__AGVAction *)
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_function__ProtocolFeatures__agv_actions(untyped_member, index));
  const vda5050_msgs__msg__AGVAction * value =
    (const vda5050_msgs__msg__AGVAction *)(untyped_value);
  *item = *value;
}

bool vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__resize_function__ProtocolFeatures__agv_actions(
  void * untyped_member, size_t size)
{
  vda5050_msgs__msg__AGVAction__Sequence * member =
    (vda5050_msgs__msg__AGVAction__Sequence *)(untyped_member);
  vda5050_msgs__msg__AGVAction__Sequence__fini(member);
  return vda5050_msgs__msg__AGVAction__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_message_member_array[2] = {
  {
    "optional_parameters",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__ProtocolFeatures, optional_parameters),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__size_function__ProtocolFeatures__optional_parameters,  // size() function pointer
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_const_function__ProtocolFeatures__optional_parameters,  // get_const(index) function pointer
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_function__ProtocolFeatures__optional_parameters,  // get(index) function pointer
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__fetch_function__ProtocolFeatures__optional_parameters,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__assign_function__ProtocolFeatures__optional_parameters,  // assign(index, value) function pointer
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__resize_function__ProtocolFeatures__optional_parameters  // resize(index) function pointer
  },
  {
    "agv_actions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs__msg__ProtocolFeatures, agv_actions),  // bytes offset in struct
    NULL,  // default value
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__size_function__ProtocolFeatures__agv_actions,  // size() function pointer
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_const_function__ProtocolFeatures__agv_actions,  // get_const(index) function pointer
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__get_function__ProtocolFeatures__agv_actions,  // get(index) function pointer
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__fetch_function__ProtocolFeatures__agv_actions,  // fetch(index, &value) function pointer
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__assign_function__ProtocolFeatures__agv_actions,  // assign(index, value) function pointer
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__resize_function__ProtocolFeatures__agv_actions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_message_members = {
  "vda5050_msgs__msg",  // message namespace
  "ProtocolFeatures",  // message name
  2,  // number of fields
  sizeof(vda5050_msgs__msg__ProtocolFeatures),
  vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_message_member_array,  // message members
  vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_init_function,  // function to initialize message memory (memory has to be allocated)
  vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_message_type_support_handle = {
  0,
  &vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, ProtocolFeatures)() {
  vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, OptionalParameter)();
  vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vda5050_msgs, msg, AGVAction)();
  if (!vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_message_type_support_handle.typesupport_identifier) {
    vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vda5050_msgs__msg__ProtocolFeatures__rosidl_typesupport_introspection_c__ProtocolFeatures_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
