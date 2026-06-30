// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/Load.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__LOAD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/load__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'bounding_box_reference'
#include "vda5050_msgs/msg/detail/bounding_box_reference__traits.hpp"
// Member 'load_dimensions'
#include "vda5050_msgs/msg/detail/load_dimensions__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Load & msg,
  std::ostream & out)
{
  out << "{";
  // member: load_id
  {
    out << "load_id: ";
    rosidl_generator_traits::value_to_yaml(msg.load_id, out);
    out << ", ";
  }

  // member: load_type
  {
    out << "load_type: ";
    rosidl_generator_traits::value_to_yaml(msg.load_type, out);
    out << ", ";
  }

  // member: load_position
  {
    out << "load_position: ";
    rosidl_generator_traits::value_to_yaml(msg.load_position, out);
    out << ", ";
  }

  // member: bounding_box_reference
  {
    out << "bounding_box_reference: ";
    to_flow_style_yaml(msg.bounding_box_reference, out);
    out << ", ";
  }

  // member: load_dimensions
  {
    out << "load_dimensions: ";
    to_flow_style_yaml(msg.load_dimensions, out);
    out << ", ";
  }

  // member: weight
  {
    out << "weight: ";
    rosidl_generator_traits::value_to_yaml(msg.weight, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Load & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: load_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "load_id: ";
    rosidl_generator_traits::value_to_yaml(msg.load_id, out);
    out << "\n";
  }

  // member: load_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "load_type: ";
    rosidl_generator_traits::value_to_yaml(msg.load_type, out);
    out << "\n";
  }

  // member: load_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "load_position: ";
    rosidl_generator_traits::value_to_yaml(msg.load_position, out);
    out << "\n";
  }

  // member: bounding_box_reference
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bounding_box_reference:\n";
    to_block_style_yaml(msg.bounding_box_reference, out, indentation + 2);
  }

  // member: load_dimensions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "load_dimensions:\n";
    to_block_style_yaml(msg.load_dimensions, out, indentation + 2);
  }

  // member: weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "weight: ";
    rosidl_generator_traits::value_to_yaml(msg.weight, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Load & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::Load & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::Load & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::Load>()
{
  return "vda5050_msgs::msg::Load";
}

template<>
inline const char * name<vda5050_msgs::msg::Load>()
{
  return "vda5050_msgs/msg/Load";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::Load>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::Load>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::Load>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD__TRAITS_HPP_
