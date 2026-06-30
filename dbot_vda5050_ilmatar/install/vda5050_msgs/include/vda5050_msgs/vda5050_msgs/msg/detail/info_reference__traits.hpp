// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/InfoReference.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__INFO_REFERENCE__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__INFO_REFERENCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/info_reference__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const InfoReference & msg,
  std::ostream & out)
{
  out << "{";
  // member: reference_key
  {
    out << "reference_key: ";
    rosidl_generator_traits::value_to_yaml(msg.reference_key, out);
    out << ", ";
  }

  // member: reference_value
  {
    out << "reference_value: ";
    rosidl_generator_traits::value_to_yaml(msg.reference_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const InfoReference & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: reference_key
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reference_key: ";
    rosidl_generator_traits::value_to_yaml(msg.reference_key, out);
    out << "\n";
  }

  // member: reference_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reference_value: ";
    rosidl_generator_traits::value_to_yaml(msg.reference_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const InfoReference & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::InfoReference & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::InfoReference & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::InfoReference>()
{
  return "vda5050_msgs::msg::InfoReference";
}

template<>
inline const char * name<vda5050_msgs::msg::InfoReference>()
{
  return "vda5050_msgs/msg/InfoReference";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::InfoReference>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::InfoReference>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::InfoReference>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__INFO_REFERENCE__TRAITS_HPP_
