// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from vda5050_msgs:msg/BatteryState.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/battery_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "vda5050_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vda5050_msgs/msg/detail/battery_state__struct.h"
#include "vda5050_msgs/msg/detail/battery_state__functions.h"
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


// forward declare type support functions


using _BatteryState__ros_msg_type = vda5050_msgs__msg__BatteryState;

static bool _BatteryState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BatteryState__ros_msg_type * ros_message = static_cast<const _BatteryState__ros_msg_type *>(untyped_ros_message);
  // Field name: battery_charge
  {
    cdr << ros_message->battery_charge;
  }

  // Field name: battery_voltage
  {
    cdr << ros_message->battery_voltage;
  }

  // Field name: battery_health
  {
    cdr << ros_message->battery_health;
  }

  // Field name: charging
  {
    cdr << (ros_message->charging ? true : false);
  }

  // Field name: reach
  {
    cdr << ros_message->reach;
  }

  return true;
}

static bool _BatteryState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BatteryState__ros_msg_type * ros_message = static_cast<_BatteryState__ros_msg_type *>(untyped_ros_message);
  // Field name: battery_charge
  {
    cdr >> ros_message->battery_charge;
  }

  // Field name: battery_voltage
  {
    cdr >> ros_message->battery_voltage;
  }

  // Field name: battery_health
  {
    cdr >> ros_message->battery_health;
  }

  // Field name: charging
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->charging = tmp ? true : false;
  }

  // Field name: reach
  {
    cdr >> ros_message->reach;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t get_serialized_size_vda5050_msgs__msg__BatteryState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BatteryState__ros_msg_type * ros_message = static_cast<const _BatteryState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name battery_charge
  {
    size_t item_size = sizeof(ros_message->battery_charge);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name battery_voltage
  {
    size_t item_size = sizeof(ros_message->battery_voltage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name battery_health
  {
    size_t item_size = sizeof(ros_message->battery_health);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name charging
  {
    size_t item_size = sizeof(ros_message->charging);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name reach
  {
    size_t item_size = sizeof(ros_message->reach);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _BatteryState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vda5050_msgs__msg__BatteryState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t max_serialized_size_vda5050_msgs__msg__BatteryState(
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

  // member: battery_charge
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: battery_voltage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: battery_health
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: charging
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: reach
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vda5050_msgs__msg__BatteryState;
    is_plain =
      (
      offsetof(DataType, reach) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _BatteryState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_vda5050_msgs__msg__BatteryState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_BatteryState = {
  "vda5050_msgs::msg",
  "BatteryState",
  _BatteryState__cdr_serialize,
  _BatteryState__cdr_deserialize,
  _BatteryState__get_serialized_size,
  _BatteryState__max_serialized_size
};

static rosidl_message_type_support_t _BatteryState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BatteryState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, BatteryState)() {
  return &_BatteryState__type_support;
}

#if defined(__cplusplus)
}
#endif
