// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/PhysicalParameters.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/physical_parameters__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PhysicalParameters & msg,
  std::ostream & out)
{
  out << "{";
  // member: speed_min
  {
    out << "speed_min: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_min, out);
    out << ", ";
  }

  // member: speed_max
  {
    out << "speed_max: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_max, out);
    out << ", ";
  }

  // member: acceleration_max
  {
    out << "acceleration_max: ";
    rosidl_generator_traits::value_to_yaml(msg.acceleration_max, out);
    out << ", ";
  }

  // member: deceleration_max
  {
    out << "deceleration_max: ";
    rosidl_generator_traits::value_to_yaml(msg.deceleration_max, out);
    out << ", ";
  }

  // member: height_min
  {
    out << "height_min: ";
    rosidl_generator_traits::value_to_yaml(msg.height_min, out);
    out << ", ";
  }

  // member: height_max
  {
    out << "height_max: ";
    rosidl_generator_traits::value_to_yaml(msg.height_max, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: length
  {
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PhysicalParameters & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: speed_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_min: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_min, out);
    out << "\n";
  }

  // member: speed_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_max: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_max, out);
    out << "\n";
  }

  // member: acceleration_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceleration_max: ";
    rosidl_generator_traits::value_to_yaml(msg.acceleration_max, out);
    out << "\n";
  }

  // member: deceleration_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "deceleration_max: ";
    rosidl_generator_traits::value_to_yaml(msg.deceleration_max, out);
    out << "\n";
  }

  // member: height_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height_min: ";
    rosidl_generator_traits::value_to_yaml(msg.height_min, out);
    out << "\n";
  }

  // member: height_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height_max: ";
    rosidl_generator_traits::value_to_yaml(msg.height_max, out);
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

  // member: length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PhysicalParameters & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::PhysicalParameters & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::PhysicalParameters & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::PhysicalParameters>()
{
  return "vda5050_msgs::msg::PhysicalParameters";
}

template<>
inline const char * name<vda5050_msgs::msg::PhysicalParameters>()
{
  return "vda5050_msgs/msg/PhysicalParameters";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::PhysicalParameters>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::PhysicalParameters>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vda5050_msgs::msg::PhysicalParameters>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__TRAITS_HPP_
