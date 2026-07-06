// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from vda5050_msgs:msg/ActionParameterDefinition.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/action_parameter_definition__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "vda5050_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vda5050_msgs/msg/detail/action_parameter_definition__struct.h"
#include "vda5050_msgs/msg/detail/action_parameter_definition__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // description, key, value_data_type
#include "rosidl_runtime_c/string_functions.h"  // description, key, value_data_type

// forward declare type support functions


using _ActionParameterDefinition__ros_msg_type = vda5050_msgs__msg__ActionParameterDefinition;

static bool _ActionParameterDefinition__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ActionParameterDefinition__ros_msg_type * ros_message = static_cast<const _ActionParameterDefinition__ros_msg_type *>(untyped_ros_message);
  // Field name: key
  {
    const rosidl_runtime_c__String * str = &ros_message->key;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: value_data_type
  {
    const rosidl_runtime_c__String * str = &ros_message->value_data_type;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: description
  {
    const rosidl_runtime_c__String * str = &ros_message->description;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: is_optional
  {
    cdr << (ros_message->is_optional ? true : false);
  }

  return true;
}

static bool _ActionParameterDefinition__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ActionParameterDefinition__ros_msg_type * ros_message = static_cast<_ActionParameterDefinition__ros_msg_type *>(untyped_ros_message);
  // Field name: key
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->key.data) {
      rosidl_runtime_c__String__init(&ros_message->key);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->key,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'key'\n");
      return false;
    }
  }

  // Field name: value_data_type
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->value_data_type.data) {
      rosidl_runtime_c__String__init(&ros_message->value_data_type);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->value_data_type,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'value_data_type'\n");
      return false;
    }
  }

  // Field name: description
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->description.data) {
      rosidl_runtime_c__String__init(&ros_message->description);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->description,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'description'\n");
      return false;
    }
  }

  // Field name: is_optional
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_optional = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t get_serialized_size_vda5050_msgs__msg__ActionParameterDefinition(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ActionParameterDefinition__ros_msg_type * ros_message = static_cast<const _ActionParameterDefinition__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name key
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->key.size + 1);
  // field.name value_data_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->value_data_type.size + 1);
  // field.name description
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->description.size + 1);
  // field.name is_optional
  {
    size_t item_size = sizeof(ros_message->is_optional);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ActionParameterDefinition__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vda5050_msgs__msg__ActionParameterDefinition(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t max_serialized_size_vda5050_msgs__msg__ActionParameterDefinition(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: key
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: value_data_type
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: description
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: is_optional
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vda5050_msgs__msg__ActionParameterDefinition;
    is_plain =
      (
      offsetof(DataType, is_optional) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ActionParameterDefinition__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_vda5050_msgs__msg__ActionParameterDefinition(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ActionParameterDefinition = {
  "vda5050_msgs::msg",
  "ActionParameterDefinition",
  _ActionParameterDefinition__cdr_serialize,
  _ActionParameterDefinition__cdr_deserialize,
  _ActionParameterDefinition__get_serialized_size,
  _ActionParameterDefinition__max_serialized_size
};

static rosidl_message_type_support_t _ActionParameterDefinition__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ActionParameterDefinition,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, ActionParameterDefinition)() {
  return &_ActionParameterDefinition__type_support;
}

#if defined(__cplusplus)
}
#endif
