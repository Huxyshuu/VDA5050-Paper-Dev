// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/Error.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ERROR__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ERROR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/error__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'error_references'
#include "vda5050_msgs/msg/detail/error_reference__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Error & msg,
  std::ostream & out)
{
  out << "{";
  // member: error_type
  {
    out << "error_type: ";
    rosidl_generator_traits::value_to_yaml(msg.error_type, out);
    out << ", ";
  }

  // member: error_references
  {
    if (msg.error_references.size() == 0) {
      out << "error_references: []";
    } else {
      out << "error_references: [";
      size_t pending_items = msg.error_references.size();
      for (auto item : msg.error_references) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: error_description
  {
    out << "error_description: ";
    rosidl_generator_traits::value_to_yaml(msg.error_description, out);
    out << ", ";
  }

  // member: error_level
  {
    out << "error_level: ";
    rosidl_generator_traits::value_to_yaml(msg.error_level, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Error & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: error_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_type: ";
    rosidl_generator_traits::value_to_yaml(msg.error_type, out);
    out << "\n";
  }

  // member: error_references
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.error_references.size() == 0) {
      out << "error_references: []\n";
    } else {
      out << "error_references:\n";
      for (auto item : msg.error_references) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: error_description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_description: ";
    rosidl_generator_traits::value_to_yaml(msg.error_description, out);
    out << "\n";
  }

  // member: error_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_level: ";
    rosidl_generator_traits::value_to_yaml(msg.error_level, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Error & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::Error & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::Error & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::Error>()
{
  return "vda5050_msgs::msg::Error";
}

template<>
inline const char * name<vda5050_msgs::msg::Error>()
{
  return "vda5050_msgs/msg/Error";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::Error>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::Error>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::Error>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__ERROR__TRAITS_HPP_
