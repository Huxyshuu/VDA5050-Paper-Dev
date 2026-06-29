// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/MaxStringLens.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/max_string_lens__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MaxStringLens & msg,
  std::ostream & out)
{
  out << "{";
  // member: msg_len
  {
    out << "msg_len: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_len, out);
    out << ", ";
  }

  // member: topic_serial_len
  {
    out << "topic_serial_len: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_serial_len, out);
    out << ", ";
  }

  // member: topic_elem_len
  {
    out << "topic_elem_len: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_elem_len, out);
    out << ", ";
  }

  // member: id_len
  {
    out << "id_len: ";
    rosidl_generator_traits::value_to_yaml(msg.id_len, out);
    out << ", ";
  }

  // member: id_numerical_only
  {
    out << "id_numerical_only: ";
    rosidl_generator_traits::value_to_yaml(msg.id_numerical_only, out);
    out << ", ";
  }

  // member: enum_len
  {
    out << "enum_len: ";
    rosidl_generator_traits::value_to_yaml(msg.enum_len, out);
    out << ", ";
  }

  // member: load_id_len
  {
    out << "load_id_len: ";
    rosidl_generator_traits::value_to_yaml(msg.load_id_len, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MaxStringLens & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: msg_len
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg_len: ";
    rosidl_generator_traits::value_to_yaml(msg.msg_len, out);
    out << "\n";
  }

  // member: topic_serial_len
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "topic_serial_len: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_serial_len, out);
    out << "\n";
  }

  // member: topic_elem_len
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "topic_elem_len: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_elem_len, out);
    out << "\n";
  }

  // member: id_len
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id_len: ";
    rosidl_generator_traits::value_to_yaml(msg.id_len, out);
    out << "\n";
  }

  // member: id_numerical_only
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id_numerical_only: ";
    rosidl_generator_traits::value_to_yaml(msg.id_numerical_only, out);
    out << "\n";
  }

  // member: enum_len
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enum_len: ";
    rosidl_generator_traits::value_to_yaml(msg.enum_len, out);
    out << "\n";
  }

  // member: load_id_len
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "load_id_len: ";
    rosidl_generator_traits::value_to_yaml(msg.load_id_len, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MaxStringLens & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::MaxStringLens & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::MaxStringLens & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::MaxStringLens>()
{
  return "vda5050_msgs::msg::MaxStringLens";
}

template<>
inline const char * name<vda5050_msgs::msg::MaxStringLens>()
{
  return "vda5050_msgs/msg/MaxStringLens";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::MaxStringLens>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::MaxStringLens>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vda5050_msgs::msg::MaxStringLens>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__MAX_STRING_LENS__TRAITS_HPP_
