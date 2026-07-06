// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/WheelDefinition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/wheel_definition__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "vda5050_msgs/msg/detail/position__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const WheelDefinition & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: is_active_driven
  {
    out << "is_active_driven: ";
    rosidl_generator_traits::value_to_yaml(msg.is_active_driven, out);
    out << ", ";
  }

  // member: is_active_steered
  {
    out << "is_active_steered: ";
    rosidl_generator_traits::value_to_yaml(msg.is_active_steered, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: diameter
  {
    out << "diameter: ";
    rosidl_generator_traits::value_to_yaml(msg.diameter, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: center_displacement
  {
    out << "center_displacement: ";
    rosidl_generator_traits::value_to_yaml(msg.center_displacement, out);
    out << ", ";
  }

  // member: constraints
  {
    out << "constraints: ";
    rosidl_generator_traits::value_to_yaml(msg.constraints, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WheelDefinition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: is_active_driven
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_active_driven: ";
    rosidl_generator_traits::value_to_yaml(msg.is_active_driven, out);
    out << "\n";
  }

  // member: is_active_steered
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_active_steered: ";
    rosidl_generator_traits::value_to_yaml(msg.is_active_steered, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: diameter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "diameter: ";
    rosidl_generator_traits::value_to_yaml(msg.diameter, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: center_displacement
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_displacement: ";
    rosidl_generator_traits::value_to_yaml(msg.center_displacement, out);
    out << "\n";
  }

  // member: constraints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "constraints: ";
    rosidl_generator_traits::value_to_yaml(msg.constraints, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WheelDefinition & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::WheelDefinition & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::WheelDefinition & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::WheelDefinition>()
{
  return "vda5050_msgs::msg::WheelDefinition";
}

template<>
inline const char * name<vda5050_msgs::msg::WheelDefinition>()
{
  return "vda5050_msgs/msg/WheelDefinition";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::WheelDefinition>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::WheelDefinition>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::WheelDefinition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__TRAITS_HPP_
