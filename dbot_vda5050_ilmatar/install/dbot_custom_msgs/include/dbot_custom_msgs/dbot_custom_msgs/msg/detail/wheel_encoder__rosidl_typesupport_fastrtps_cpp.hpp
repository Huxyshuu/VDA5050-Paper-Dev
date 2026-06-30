// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from dbot_custom_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice

#ifndef DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "dbot_custom_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "dbot_custom_msgs/msg/detail/wheel_encoder__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace dbot_custom_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dbot_custom_msgs
cdr_serialize(
  const dbot_custom_msgs::msg::WheelEncoder & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dbot_custom_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dbot_custom_msgs::msg::WheelEncoder & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dbot_custom_msgs
get_serialized_size(
  const dbot_custom_msgs::msg::WheelEncoder & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dbot_custom_msgs
max_serialized_size_WheelEncoder(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace dbot_custom_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dbot_custom_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dbot_custom_msgs, msg, WheelEncoder)();

#ifdef __cplusplus
}
#endif

#endif  // DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
