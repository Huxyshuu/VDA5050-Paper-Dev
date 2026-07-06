// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dbot_custom_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dbot_custom_msgs/msg/detail/wheel_encoder__rosidl_typesupport_introspection_c.h"
#include "dbot_custom_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dbot_custom_msgs/msg/detail/wheel_encoder__functions.h"
#include "dbot_custom_msgs/msg/detail/wheel_encoder__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dbot_custom_msgs__msg__WheelEncoder__init(message_memory);
}

void dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_fini_function(void * message_memory)
{
  dbot_custom_msgs__msg__WheelEncoder__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dbot_custom_msgs__msg__WheelEncoder, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dbot_custom_msgs__msg__WheelEncoder, left),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "right",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dbot_custom_msgs__msg__WheelEncoder, right),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_message_members = {
  "dbot_custom_msgs__msg",  // message namespace
  "WheelEncoder",  // message name
  3,  // number of fields
  sizeof(dbot_custom_msgs__msg__WheelEncoder),
  dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_message_member_array,  // message members
  dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_init_function,  // function to initialize message memory (memory has to be allocated)
  dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_message_type_support_handle = {
  0,
  &dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dbot_custom_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dbot_custom_msgs, msg, WheelEncoder)() {
  dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_message_type_support_handle.typesupport_identifier) {
    dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dbot_custom_msgs__msg__WheelEncoder__rosidl_typesupport_introspection_c__WheelEncoder_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
