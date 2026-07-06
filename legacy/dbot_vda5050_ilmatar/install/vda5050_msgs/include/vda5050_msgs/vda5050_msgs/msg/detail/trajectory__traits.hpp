// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'control_points'
#include "vda5050_msgs/msg/detail/control_point__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Trajectory & msg,
  std::ostream & out)
{
  out << "{";
  // member: degree
  {
    out << "degree: ";
    rosidl_generator_traits::value_to_yaml(msg.degree, out);
    out << ", ";
  }

  // member: knot_vector
  {
    if (msg.knot_vector.size() == 0) {
      out << "knot_vector: []";
    } else {
      out << "knot_vector: [";
      size_t pending_items = msg.knot_vector.size();
      for (auto item : msg.knot_vector) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: control_points
  {
    if (msg.control_points.size() == 0) {
      out << "control_points: []";
    } else {
      out << "control_points: [";
      size_t pending_items = msg.control_points.size();
      for (auto item : msg.control_points) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Trajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: degree
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "degree: ";
    rosidl_generator_traits::value_to_yaml(msg.degree, out);
    out << "\n";
  }

  // member: knot_vector
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.knot_vector.size() == 0) {
      out << "knot_vector: []\n";
    } else {
      out << "knot_vector:\n";
      for (auto item : msg.knot_vector) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: control_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.control_points.size() == 0) {
      out << "control_points: []\n";
    } else {
      out << "control_points:\n";
      for (auto item : msg.control_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Trajectory & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::Trajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::Trajectory & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::Trajectory>()
{
  return "vda5050_msgs::msg::Trajectory";
}

template<>
inline const char * name<vda5050_msgs::msg::Trajectory>()
{
  return "vda5050_msgs/msg/Trajectory";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::Trajectory>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::Trajectory>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::Trajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
