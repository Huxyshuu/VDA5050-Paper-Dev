// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/Timing.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__TIMING__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__TIMING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/timing__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Timing & msg,
  std::ostream & out)
{
  out << "{";
  // member: min_order_interval
  {
    out << "min_order_interval: ";
    rosidl_generator_traits::value_to_yaml(msg.min_order_interval, out);
    out << ", ";
  }

  // member: min_state_interval
  {
    out << "min_state_interval: ";
    rosidl_generator_traits::value_to_yaml(msg.min_state_interval, out);
    out << ", ";
  }

  // member: default_state_interval
  {
    out << "default_state_interval: ";
    rosidl_generator_traits::value_to_yaml(msg.default_state_interval, out);
    out << ", ";
  }

  // member: visualization_interval
  {
    out << "visualization_interval: ";
    rosidl_generator_traits::value_to_yaml(msg.visualization_interval, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Timing & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: min_order_interval
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_order_interval: ";
    rosidl_generator_traits::value_to_yaml(msg.min_order_interval, out);
    out << "\n";
  }

  // member: min_state_interval
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_state_interval: ";
    rosidl_generator_traits::value_to_yaml(msg.min_state_interval, out);
    out << "\n";
  }

  // member: default_state_interval
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "default_state_interval: ";
    rosidl_generator_traits::value_to_yaml(msg.default_state_interval, out);
    out << "\n";
  }

  // member: visualization_interval
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "visualization_interval: ";
    rosidl_generator_traits::value_to_yaml(msg.visualization_interval, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Timing & msg, bool use_flow_style = false)
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

}  // namespace vda5050_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_msgs::msg::Timing & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::Timing & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::Timing>()
{
  return "vda5050_msgs::msg::Timing";
}

template<>
inline const char * name<vda5050_msgs::msg::Timing>()
{
  return "vda5050_msgs/msg/Timing";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::Timing>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::Timing>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vda5050_msgs::msg::Timing>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__TIMING__TRAITS_HPP_
