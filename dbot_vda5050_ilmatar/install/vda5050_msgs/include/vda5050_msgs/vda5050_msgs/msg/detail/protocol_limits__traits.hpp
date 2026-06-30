// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/ProtocolLimits.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/protocol_limits__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'max_string_lens'
#include "vda5050_msgs/msg/detail/max_string_lens__traits.hpp"
// Member 'max_array_lens'
#include "vda5050_msgs/msg/detail/max_array_lens__traits.hpp"
// Member 'timing'
#include "vda5050_msgs/msg/detail/timing__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ProtocolLimits & msg,
  std::ostream & out)
{
  out << "{";
  // member: max_string_lens
  {
    out << "max_string_lens: ";
    to_flow_style_yaml(msg.max_string_lens, out);
    out << ", ";
  }

  // member: max_array_lens
  {
    out << "max_array_lens: ";
    to_flow_style_yaml(msg.max_array_lens, out);
    out << ", ";
  }

  // member: timing
  {
    out << "timing: ";
    to_flow_style_yaml(msg.timing, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ProtocolLimits & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: max_string_lens
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_string_lens:\n";
    to_block_style_yaml(msg.max_string_lens, out, indentation + 2);
  }

  // member: max_array_lens
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_array_lens:\n";
    to_block_style_yaml(msg.max_array_lens, out, indentation + 2);
  }

  // member: timing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timing:\n";
    to_block_style_yaml(msg.timing, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProtocolLimits & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::ProtocolLimits & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::ProtocolLimits & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::ProtocolLimits>()
{
  return "vda5050_msgs::msg::ProtocolLimits";
}

template<>
inline const char * name<vda5050_msgs::msg::ProtocolLimits>()
{
  return "vda5050_msgs/msg/ProtocolLimits";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::ProtocolLimits>
  : std::integral_constant<bool, has_fixed_size<vda5050_msgs::msg::MaxArrayLens>::value && has_fixed_size<vda5050_msgs::msg::MaxStringLens>::value && has_fixed_size<vda5050_msgs::msg::Timing>::value> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::ProtocolLimits>
  : std::integral_constant<bool, has_bounded_size<vda5050_msgs::msg::MaxArrayLens>::value && has_bounded_size<vda5050_msgs::msg::MaxStringLens>::value && has_bounded_size<vda5050_msgs::msg::Timing>::value> {};

template<>
struct is_message<vda5050_msgs::msg::ProtocolLimits>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__PROTOCOL_LIMITS__TRAITS_HPP_
