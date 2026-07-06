// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/AGVPosition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/agv_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const AGVPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: position_initialized
  {
    out << "position_initialized: ";
    rosidl_generator_traits::value_to_yaml(msg.position_initialized, out);
    out << ", ";
  }

  // member: localization_score
  {
    out << "localization_score: ";
    rosidl_generator_traits::value_to_yaml(msg.localization_score, out);
    out << ", ";
  }

  // member: deviation_range
  {
    out << "deviation_range: ";
    rosidl_generator_traits::value_to_yaml(msg.deviation_range, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << ", ";
  }

  // member: map_id
  {
    out << "map_id: ";
    rosidl_generator_traits::value_to_yaml(msg.map_id, out);
    out << ", ";
  }

  // member: map_description
  {
    out << "map_description: ";
    rosidl_generator_traits::value_to_yaml(msg.map_description, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AGVPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position_initialized
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_initialized: ";
    rosidl_generator_traits::value_to_yaml(msg.position_initialized, out);
    out << "\n";
  }

  // member: localization_score
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "localization_score: ";
    rosidl_generator_traits::value_to_yaml(msg.localization_score, out);
    out << "\n";
  }

  // member: deviation_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "deviation_range: ";
    rosidl_generator_traits::value_to_yaml(msg.deviation_range, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }

  // member: map_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "map_id: ";
    rosidl_generator_traits::value_to_yaml(msg.map_id, out);
    out << "\n";
  }

  // member: map_description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "map_description: ";
    rosidl_generator_traits::value_to_yaml(msg.map_description, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AGVPosition & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::AGVPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::AGVPosition & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::AGVPosition>()
{
  return "vda5050_msgs::msg::AGVPosition";
}

template<>
inline const char * name<vda5050_msgs::msg::AGVPosition>()
{
  return "vda5050_msgs/msg/AGVPosition";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::AGVPosition>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::AGVPosition>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::AGVPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_POSITION__TRAITS_HPP_
