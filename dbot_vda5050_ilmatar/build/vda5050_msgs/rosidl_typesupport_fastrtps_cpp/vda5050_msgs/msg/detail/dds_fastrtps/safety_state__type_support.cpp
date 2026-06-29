// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_msgs:msg/SafetyState.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/safety_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "vda5050_msgs/msg/detail/safety_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace vda5050_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
cdr_serialize(
  const vda5050_msgs::msg::SafetyState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: e_stop
  cdr << ros_message.e_stop;
  // Member: field_violation
  cdr << (ros_message.field_violation ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vda5050_msgs::msg::SafetyState & ros_message)
{
  // Member: e_stop
  cdr >> ros_message.e_stop;

  // Member: field_violation
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.field_violation = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
get_serialized_size(
  const vda5050_msgs::msg::SafetyState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: e_stop
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.e_stop.size() + 1);
  // Member: field_violation
  {
    size_t item_size = sizeof(ros_message.field_violation);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
max_serialized_size_SafetyState(
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


  // Member: e_stop
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

  // Member: field_violation
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
    using DataType = vda5050_msgs::msg::SafetyState;
    is_plain =
      (
      offsetof(DataType, field_violation) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SafetyState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const vda5050_msgs::msg::SafetyState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SafetyState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<vda5050_msgs::msg::SafetyState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SafetyState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const vda5050_msgs::msg::SafetyState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SafetyState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SafetyState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SafetyState__callbacks = {
  "vda5050_msgs::msg",
  "SafetyState",
  _SafetyState__cdr_serialize,
  _SafetyState__cdr_deserialize,
  _SafetyState__get_serialized_size,
  _SafetyState__max_serialized_size
};

static rosidl_message_type_support_t _SafetyState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SafetyState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace vda5050_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_msgs::msg::SafetyState>()
{
  return &vda5050_msgs::msg::typesupport_fastrtps_cpp::_SafetyState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_msgs, msg, SafetyState)() {
  return &vda5050_msgs::msg::typesupport_fastrtps_cpp::_SafetyState__handle;
}

#ifdef __cplusplus
}
#endif
