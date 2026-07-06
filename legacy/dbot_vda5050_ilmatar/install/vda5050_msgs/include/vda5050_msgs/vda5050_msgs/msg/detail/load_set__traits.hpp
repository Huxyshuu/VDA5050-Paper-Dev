// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/LoadSet.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD_SET__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__LOAD_SET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/load_set__struct.hpp"
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
  const LoadSet & msg,
  std::ostream & out)
{
  out << "{";
  // member: set_name
  {
    out << "set_name: ";
    rosidl_generator_traits::value_to_yaml(msg.set_name, out);
    out << ", ";
  }

  // member: load_type
  {
    out << "load_type: ";
    rosidl_generator_traits::value_to_yaml(msg.load_type, out);
    out << ", ";
  }

  // member: load_positions
  {
    if (msg.load_positions.size() == 0) {
      out << "load_positions: []";
    } else {
      out << "load_positions: [";
      size_t pending_items = msg.load_positions.size();
      for (auto item : msg.load_positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
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

  // member: max_weight
  {
    out << "max_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.max_weight, out);
    out << ", ";
  }

  // member: min_loadhandling_height
  {
    out << "min_loadhandling_height: ";
    rosidl_generator_traits::value_to_yaml(msg.min_loadhandling_height, out);
    out << ", ";
  }

  // member: max_loadhandling_height
  {
    out << "max_loadhandling_height: ";
    rosidl_generator_traits::value_to_yaml(msg.max_loadhandling_height, out);
    out << ", ";
  }

  // member: min_loadhandling_depth
  {
    out << "min_loadhandling_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.min_loadhandling_depth, out);
    out << ", ";
  }

  // member: max_loadhandling_depth
  {
    out << "max_loadhandling_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.max_loadhandling_depth, out);
    out << ", ";
  }

  // member: min_loadhandling_tilt
  {
    out << "min_loadhandling_tilt: ";
    rosidl_generator_traits::value_to_yaml(msg.min_loadhandling_tilt, out);
    out << ", ";
  }

  // member: max_loadhandling_tilt
  {
    out << "max_loadhandling_tilt: ";
    rosidl_generator_traits::value_to_yaml(msg.max_loadhandling_tilt, out);
    out << ", ";
  }

  // member: agv_speed_limit
  {
    out << "agv_speed_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.agv_speed_limit, out);
    out << ", ";
  }

  // member: agv_acceleration_limit
  {
    out << "agv_acceleration_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.agv_acceleration_limit, out);
    out << ", ";
  }

  // member: agv_deceleration_limit
  {
    out << "agv_deceleration_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.agv_deceleration_limit, out);
    out << ", ";
  }

  // member: pick_time
  {
    out << "pick_time: ";
    rosidl_generator_traits::value_to_yaml(msg.pick_time, out);
    out << ", ";
  }

  // member: drop_time
  {
    out << "drop_time: ";
    rosidl_generator_traits::value_to_yaml(msg.drop_time, out);
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
  const LoadSet & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: set_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "set_name: ";
    rosidl_generator_traits::value_to_yaml(msg.set_name, out);
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

  // member: load_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.load_positions.size() == 0) {
      out << "load_positions: []\n";
    } else {
      out << "load_positions:\n";
      for (auto item : msg.load_positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

  // member: max_weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.max_weight, out);
    out << "\n";
  }

  // member: min_loadhandling_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_loadhandling_height: ";
    rosidl_generator_traits::value_to_yaml(msg.min_loadhandling_height, out);
    out << "\n";
  }

  // member: max_loadhandling_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_loadhandling_height: ";
    rosidl_generator_traits::value_to_yaml(msg.max_loadhandling_height, out);
    out << "\n";
  }

  // member: min_loadhandling_depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_loadhandling_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.min_loadhandling_depth, out);
    out << "\n";
  }

  // member: max_loadhandling_depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_loadhandling_depth: ";
    rosidl_generator_traits::value_to_yaml(msg.max_loadhandling_depth, out);
    out << "\n";
  }

  // member: min_loadhandling_tilt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_loadhandling_tilt: ";
    rosidl_generator_traits::value_to_yaml(msg.min_loadhandling_tilt, out);
    out << "\n";
  }

  // member: max_loadhandling_tilt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_loadhandling_tilt: ";
    rosidl_generator_traits::value_to_yaml(msg.max_loadhandling_tilt, out);
    out << "\n";
  }

  // member: agv_speed_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agv_speed_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.agv_speed_limit, out);
    out << "\n";
  }

  // member: agv_acceleration_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agv_acceleration_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.agv_acceleration_limit, out);
    out << "\n";
  }

  // member: agv_deceleration_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agv_deceleration_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.agv_deceleration_limit, out);
    out << "\n";
  }

  // member: pick_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pick_time: ";
    rosidl_generator_traits::value_to_yaml(msg.pick_time, out);
    out << "\n";
  }

  // member: drop_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drop_time: ";
    rosidl_generator_traits::value_to_yaml(msg.drop_time, out);
    out << "\n";
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

inline std::string to_yaml(const LoadSet & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::LoadSet & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::LoadSet & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::LoadSet>()
{
  return "vda5050_msgs::msg::LoadSet";
}

template<>
inline const char * name<vda5050_msgs::msg::LoadSet>()
{
  return "vda5050_msgs/msg/LoadSet";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::LoadSet>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::LoadSet>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::LoadSet>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD_SET__TRAITS_HPP_
