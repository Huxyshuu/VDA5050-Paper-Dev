// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from vda5050_msgs:msg/WheelDefinition.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/wheel_definition__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "vda5050_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vda5050_msgs/msg/detail/wheel_definition__struct.h"
#include "vda5050_msgs/msg/detail/wheel_definition__functions.h"
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

#include "rosidl_runtime_c/string.h"  // constraints, type
#include "rosidl_runtime_c/string_functions.h"  // constraints, type
#include "vda5050_msgs/msg/detail/position__functions.h"  // position

// forward declare type support functions
size_t get_serialized_size_vda5050_msgs__msg__Position(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_vda5050_msgs__msg__Position(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, Position)();


using _WheelDefinition__ros_msg_type = vda5050_msgs__msg__WheelDefinition;

static bool _WheelDefinition__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _WheelDefinition__ros_msg_type * ros_message = static_cast<const _WheelDefinition__ros_msg_type *>(untyped_ros_message);
  // Field name: type
  {
    const rosidl_runtime_c__String * str = &ros_message->type;
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

  // Field name: is_active_driven
  {
    cdr << (ros_message->is_active_driven ? true : false);
  }

  // Field name: is_active_steered
  {
    cdr << (ros_message->is_active_steered ? true : false);
  }

  // Field name: position
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, Position
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->position, cdr))
    {
      return false;
    }
  }

  // Field name: diameter
  {
    cdr << ros_message->diameter;
  }

  // Field name: width
  {
    cdr << ros_message->width;
  }

  // Field name: center_displacement
  {
    cdr << ros_message->center_displacement;
  }

  // Field name: constraints
  {
    const rosidl_runtime_c__String * str = &ros_message->constraints;
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

  return true;
}

static bool _WheelDefinition__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _WheelDefinition__ros_msg_type * ros_message = static_cast<_WheelDefinition__ros_msg_type *>(untyped_ros_message);
  // Field name: type
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->type.data) {
      rosidl_runtime_c__String__init(&ros_message->type);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->type,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'type'\n");
      return false;
    }
  }

  // Field name: is_active_driven
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_active_driven = tmp ? true : false;
  }

  // Field name: is_active_steered
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_active_steered = tmp ? true : false;
  }

  // Field name: position
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, Position
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->position))
    {
      return false;
    }
  }

  // Field name: diameter
  {
    cdr >> ros_message->diameter;
  }

  // Field name: width
  {
    cdr >> ros_message->width;
  }

  // Field name: center_displacement
  {
    cdr >> ros_message->center_displacement;
  }

  // Field name: constraints
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->constraints.data) {
      rosidl_runtime_c__String__init(&ros_message->constraints);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->constraints,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'constraints'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t get_serialized_size_vda5050_msgs__msg__WheelDefinition(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WheelDefinition__ros_msg_type * ros_message = static_cast<const _WheelDefinition__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->type.size + 1);
  // field.name is_active_driven
  {
    size_t item_size = sizeof(ros_message->is_active_driven);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_active_steered
  {
    size_t item_size = sizeof(ros_message->is_active_steered);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name position

  current_alignment += get_serialized_size_vda5050_msgs__msg__Position(
    &(ros_message->position), current_alignment);
  // field.name diameter
  {
    size_t item_size = sizeof(ros_message->diameter);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name width
  {
    size_t item_size = sizeof(ros_message->width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name center_displacement
  {
    size_t item_size = sizeof(ros_message->center_displacement);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name constraints
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->constraints.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _WheelDefinition__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vda5050_msgs__msg__WheelDefinition(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t max_serialized_size_vda5050_msgs__msg__WheelDefinition(
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

  // member: type
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
  // member: is_active_driven
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_active_steered
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: position
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_vda5050_msgs__msg__Position(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: diameter
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: width
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: center_displacement
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: constraints
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

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vda5050_msgs__msg__WheelDefinition;
    is_plain =
      (
      offsetof(DataType, constraints) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _WheelDefinition__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_vda5050_msgs__msg__WheelDefinition(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_WheelDefinition = {
  "vda5050_msgs::msg",
  "WheelDefinition",
  _WheelDefinition__cdr_serialize,
  _WheelDefinition__cdr_deserialize,
  _WheelDefinition__get_serialized_size,
  _WheelDefinition__max_serialized_size
};

static rosidl_message_type_support_t _WheelDefinition__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_WheelDefinition,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, WheelDefinition)() {
  return &_WheelDefinition__type_support;
}

#if defined(__cplusplus)
}
#endif
