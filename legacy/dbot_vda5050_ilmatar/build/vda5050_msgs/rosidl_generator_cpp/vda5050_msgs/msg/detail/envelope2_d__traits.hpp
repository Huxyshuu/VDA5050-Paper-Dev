// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/Envelope2D.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ENVELOPE2_D__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ENVELOPE2_D__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/envelope2_d__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'polygon_points'
#include "vda5050_msgs/msg/detail/polygon_point__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Envelope2D & msg,
  std::ostream & out)
{
  out << "{";
  // member: set
  {
    out << "set: ";
    rosidl_generator_traits::value_to_yaml(msg.set, out);
    out << ", ";
  }

  // member: polygon_points
  {
    if (msg.polygon_points.size() == 0) {
      out << "polygon_points: []";
    } else {
      out << "polygon_points: [";
      size_t pending_items = msg.polygon_points.size();
      for (auto item : msg.polygon_points) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: description
  {
    out << "description: ";
    rosidl_generator_traits::value_to_yaml(msg.description, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Envelope2D & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: set
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "set: ";
    rosidl_generator_traits::value_to_yaml(msg.set, out);
    out << "\n";
  }

  // member: polygon_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.polygon_points.size() == 0) {
      out << "polygon_points: []\n";
    } else {
      out << "polygon_points:\n";
      for (auto item : msg.polygon_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "description: ";
    rosidl_generator_traits::value_to_yaml(msg.description, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Envelope2D & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::Envelope2D & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::Envelope2D & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::Envelope2D>()
{
  return "vda5050_msgs::msg::Envelope2D";
}

template<>
inline const char * name<vda5050_msgs::msg::Envelope2D>()
{
  return "vda5050_msgs/msg/Envelope2D";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::Envelope2D>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::Envelope2D>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::Envelope2D>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__ENVELOPE2_D__TRAITS_HPP_
