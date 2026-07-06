// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/Info.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__INFO__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'info_references'
#include "vda5050_msgs/msg/detail/info_reference__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Info & msg,
  std::ostream & out)
{
  out << "{";
  // member: info_type
  {
    out << "info_type: ";
    rosidl_generator_traits::value_to_yaml(msg.info_type, out);
    out << ", ";
  }

  // member: info_references
  {
    if (msg.info_references.size() == 0) {
      out << "info_references: []";
    } else {
      out << "info_references: [";
      size_t pending_items = msg.info_references.size();
      for (auto item : msg.info_references) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: info_description
  {
    out << "info_description: ";
    rosidl_generator_traits::value_to_yaml(msg.info_description, out);
    out << ", ";
  }

  // member: info_level
  {
    out << "info_level: ";
    rosidl_generator_traits::value_to_yaml(msg.info_level, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Info & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info_type: ";
    rosidl_generator_traits::value_to_yaml(msg.info_type, out);
    out << "\n";
  }

  // member: info_references
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.info_references.size() == 0) {
      out << "info_references: []\n";
    } else {
      out << "info_references:\n";
      for (auto item : msg.info_references) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: info_description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info_description: ";
    rosidl_generator_traits::value_to_yaml(msg.info_description, out);
    out << "\n";
  }

  // member: info_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info_level: ";
    rosidl_generator_traits::value_to_yaml(msg.info_level, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Info & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::Info & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::Info & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::Info>()
{
  return "vda5050_msgs::msg::Info";
}

template<>
inline const char * name<vda5050_msgs::msg::Info>()
{
  return "vda5050_msgs/msg/Info";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::Info>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::Info>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::Info>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__INFO__TRAITS_HPP_
