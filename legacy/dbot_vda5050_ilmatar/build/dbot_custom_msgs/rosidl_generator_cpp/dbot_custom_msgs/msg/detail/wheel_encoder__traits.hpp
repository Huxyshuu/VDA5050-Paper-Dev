// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dbot_custom_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice

#ifndef DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__TRAITS_HPP_
#define DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dbot_custom_msgs/msg/detail/wheel_encoder__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace dbot_custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const WheelEncoder & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: left
  {
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << ", ";
  }

  // member: right
  {
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WheelEncoder & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left: ";
    rosidl_generator_traits::value_to_yaml(msg.left, out);
    out << "\n";
  }

  // member: right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right: ";
    rosidl_generator_traits::value_to_yaml(msg.right, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WheelEncoder & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace dbot_custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use dbot_custom_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dbot_custom_msgs::msg::WheelEncoder & msg,
  std::ostream & out, size_t indentation = 0)
{
  dbot_custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dbot_custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const dbot_custom_msgs::msg::WheelEncoder & msg)
{
  return dbot_custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dbot_custom_msgs::msg::WheelEncoder>()
{
  return "dbot_custom_msgs::msg::WheelEncoder";
}

template<>
inline const char * name<dbot_custom_msgs::msg::WheelEncoder>()
{
  return "dbot_custom_msgs/msg/WheelEncoder";
}

template<>
struct has_fixed_size<dbot_custom_msgs::msg::WheelEncoder>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<dbot_custom_msgs::msg::WheelEncoder>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<dbot_custom_msgs::msg::WheelEncoder>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__TRAITS_HPP_
