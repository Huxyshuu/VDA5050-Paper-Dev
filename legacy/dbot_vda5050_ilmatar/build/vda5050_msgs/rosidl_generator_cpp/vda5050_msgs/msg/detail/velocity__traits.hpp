// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/Velocity.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__VELOCITY__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__VELOCITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/velocity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Velocity & msg,
  std::ostream & out)
{
  out << "{";
  // member: vx
  {
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << ", ";
  }

  // member: vy
  {
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << ", ";
  }

  // member: omega
  {
    out << "omega: ";
    rosidl_generator_traits::value_to_yaml(msg.omega, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Velocity & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << "\n";
  }

  // member: vy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vy: ";
    rosidl_generator_traits::value_to_yaml(msg.vy, out);
    out << "\n";
  }

  // member: omega
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "omega: ";
    rosidl_generator_traits::value_to_yaml(msg.omega, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Velocity & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::Velocity & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::Velocity & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::Velocity>()
{
  return "vda5050_msgs::msg::Velocity";
}

template<>
inline const char * name<vda5050_msgs::msg::Velocity>()
{
  return "vda5050_msgs/msg/Velocity";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::Velocity>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::Velocity>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vda5050_msgs::msg::Velocity>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__VELOCITY__TRAITS_HPP_
