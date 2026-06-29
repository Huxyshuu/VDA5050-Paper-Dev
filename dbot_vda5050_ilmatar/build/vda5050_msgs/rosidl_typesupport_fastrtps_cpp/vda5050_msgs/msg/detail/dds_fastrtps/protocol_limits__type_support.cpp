// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_msgs:msg/ProtocolLimits.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/protocol_limits__rosidl_typesupport_fastrtps_cpp.hpp"
#include "vda5050_msgs/msg/detail/protocol_limits__struct.hpp"

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
bool cdr_serialize(
  const vda5050_msgs::msg::MaxStringLens &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vda5050_msgs::msg::MaxStringLens &);
size_t get_serialized_size(
  const vda5050_msgs::msg::MaxStringLens &,
  size_t current_alignment);
size_t
max_serialized_size_MaxStringLens(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vda5050_msgs

namespace vda5050_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vda5050_msgs::msg::MaxArrayLens &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vda5050_msgs::msg::MaxArrayLens &);
size_t get_serialized_size(
  const vda5050_msgs::msg::MaxArrayLens &,
  size_t current_alignment);
size_t
max_serialized_size_MaxArrayLens(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vda5050_msgs

namespace vda5050_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const vda5050_msgs::msg::Timing &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  vda5050_msgs::msg::Timing &);
size_t get_serialized_size(
  const vda5050_msgs::msg::Timing &,
  size_t current_alignment);
size_t
max_serialized_size_Timing(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace vda5050_msgs


namespace vda5050_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
cdr_serialize(
  const vda5050_msgs::msg::ProtocolLimits & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: max_string_lens
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.max_string_lens,
    cdr);
  // Member: max_array_lens
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.max_array_lens,
    cdr);
  // Member: timing
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.timing,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vda5050_msgs::msg::ProtocolLimits & ros_message)
{
  // Member: max_string_lens
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.max_string_lens);

  // Member: max_array_lens
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.max_array_lens);

  // Member: timing
  vda5050_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.timing);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
get_serialized_size(
  const vda5050_msgs::msg::ProtocolLimits & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: max_string_lens

  current_alignment +=
    vda5050_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.max_string_lens, current_alignment);
  // Member: max_array_lens

  current_alignment +=
    vda5050_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.max_array_lens, current_alignment);
  // Member: timing

  current_alignment +=
    vda5050_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.timing, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
max_serialized_size_ProtocolLimits(
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


  // Member: max_string_lens
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vda5050_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_MaxStringLens(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: max_array_lens
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vda5050_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_MaxArrayLens(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: timing
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        vda5050_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Timing(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vda5050_msgs::msg::ProtocolLimits;
    is_plain =
      (
      offsetof(DataType, timing) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ProtocolLimits__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const vda5050_msgs::msg::ProtocolLimits *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ProtocolLimits__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<vda5050_msgs::msg::ProtocolLimits *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ProtocolLimits__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const vda5050_msgs::msg::ProtocolLimits *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ProtocolLimits__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ProtocolLimits(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ProtocolLimits__callbacks = {
  "vda5050_msgs::msg",
  "ProtocolLimits",
  _ProtocolLimits__cdr_serialize,
  _ProtocolLimits__cdr_deserialize,
  _ProtocolLimits__get_serialized_size,
  _ProtocolLimits__max_serialized_size
};

static rosidl_message_type_support_t _ProtocolLimits__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ProtocolLimits__callbacks,
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
get_message_type_support_handle<vda5050_msgs::msg::ProtocolLimits>()
{
  return &vda5050_msgs::msg::typesupport_fastrtps_cpp::_ProtocolLimits__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_msgs, msg, ProtocolLimits)() {
  return &vda5050_msgs::msg::typesupport_fastrtps_cpp::_ProtocolLimits__handle;
}

#ifdef __cplusplus
}
#endif
