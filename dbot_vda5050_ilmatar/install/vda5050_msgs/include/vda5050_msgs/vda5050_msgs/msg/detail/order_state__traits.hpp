// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_msgs:msg/OrderState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__TRAITS_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_msgs/msg/detail/order_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'node_states'
#include "vda5050_msgs/msg/detail/node_state__traits.hpp"
// Member 'edge_states'
#include "vda5050_msgs/msg/detail/edge_state__traits.hpp"
// Member 'agv_position'
#include "vda5050_msgs/msg/detail/agv_position__traits.hpp"
// Member 'velocity'
#include "vda5050_msgs/msg/detail/velocity__traits.hpp"
// Member 'loads'
#include "vda5050_msgs/msg/detail/load__traits.hpp"
// Member 'action_states'
#include "vda5050_msgs/msg/detail/current_action__traits.hpp"
// Member 'battery_state'
#include "vda5050_msgs/msg/detail/battery_state__traits.hpp"
// Member 'errors'
#include "vda5050_msgs/msg/detail/error__traits.hpp"
// Member 'informations'
#include "vda5050_msgs/msg/detail/info__traits.hpp"
// Member 'safety_state'
#include "vda5050_msgs/msg/detail/safety_state__traits.hpp"

namespace vda5050_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const OrderState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header_id
  {
    out << "header_id: ";
    rosidl_generator_traits::value_to_yaml(msg.header_id, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: version
  {
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << ", ";
  }

  // member: manufacturer
  {
    out << "manufacturer: ";
    rosidl_generator_traits::value_to_yaml(msg.manufacturer, out);
    out << ", ";
  }

  // member: serial_number
  {
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
    out << ", ";
  }

  // member: order_id
  {
    out << "order_id: ";
    rosidl_generator_traits::value_to_yaml(msg.order_id, out);
    out << ", ";
  }

  // member: order_update_id
  {
    out << "order_update_id: ";
    rosidl_generator_traits::value_to_yaml(msg.order_update_id, out);
    out << ", ";
  }

  // member: zone_set_id
  {
    out << "zone_set_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_set_id, out);
    out << ", ";
  }

  // member: last_node_id
  {
    out << "last_node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.last_node_id, out);
    out << ", ";
  }

  // member: last_node_sequence_id
  {
    out << "last_node_sequence_id: ";
    rosidl_generator_traits::value_to_yaml(msg.last_node_sequence_id, out);
    out << ", ";
  }

  // member: node_states
  {
    if (msg.node_states.size() == 0) {
      out << "node_states: []";
    } else {
      out << "node_states: [";
      size_t pending_items = msg.node_states.size();
      for (auto item : msg.node_states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: edge_states
  {
    if (msg.edge_states.size() == 0) {
      out << "edge_states: []";
    } else {
      out << "edge_states: [";
      size_t pending_items = msg.edge_states.size();
      for (auto item : msg.edge_states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: agv_position
  {
    out << "agv_position: ";
    to_flow_style_yaml(msg.agv_position, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: loads
  {
    if (msg.loads.size() == 0) {
      out << "loads: []";
    } else {
      out << "loads: [";
      size_t pending_items = msg.loads.size();
      for (auto item : msg.loads) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: driving
  {
    out << "driving: ";
    rosidl_generator_traits::value_to_yaml(msg.driving, out);
    out << ", ";
  }

  // member: paused
  {
    out << "paused: ";
    rosidl_generator_traits::value_to_yaml(msg.paused, out);
    out << ", ";
  }

  // member: new_base_request
  {
    out << "new_base_request: ";
    rosidl_generator_traits::value_to_yaml(msg.new_base_request, out);
    out << ", ";
  }

  // member: distance_since_last_node
  {
    out << "distance_since_last_node: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_since_last_node, out);
    out << ", ";
  }

  // member: action_states
  {
    if (msg.action_states.size() == 0) {
      out << "action_states: []";
    } else {
      out << "action_states: [";
      size_t pending_items = msg.action_states.size();
      for (auto item : msg.action_states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: battery_state
  {
    out << "battery_state: ";
    to_flow_style_yaml(msg.battery_state, out);
    out << ", ";
  }

  // member: operating_mode
  {
    out << "operating_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.operating_mode, out);
    out << ", ";
  }

  // member: errors
  {
    if (msg.errors.size() == 0) {
      out << "errors: []";
    } else {
      out << "errors: [";
      size_t pending_items = msg.errors.size();
      for (auto item : msg.errors) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: informations
  {
    if (msg.informations.size() == 0) {
      out << "informations: []";
    } else {
      out << "informations: [";
      size_t pending_items = msg.informations.size();
      for (auto item : msg.informations) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: safety_state
  {
    out << "safety_state: ";
    to_flow_style_yaml(msg.safety_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrderState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header_id: ";
    rosidl_generator_traits::value_to_yaml(msg.header_id, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }

  // member: version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "version: ";
    rosidl_generator_traits::value_to_yaml(msg.version, out);
    out << "\n";
  }

  // member: manufacturer
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "manufacturer: ";
    rosidl_generator_traits::value_to_yaml(msg.manufacturer, out);
    out << "\n";
  }

  // member: serial_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "serial_number: ";
    rosidl_generator_traits::value_to_yaml(msg.serial_number, out);
    out << "\n";
  }

  // member: order_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order_id: ";
    rosidl_generator_traits::value_to_yaml(msg.order_id, out);
    out << "\n";
  }

  // member: order_update_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "order_update_id: ";
    rosidl_generator_traits::value_to_yaml(msg.order_update_id, out);
    out << "\n";
  }

  // member: zone_set_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_set_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_set_id, out);
    out << "\n";
  }

  // member: last_node_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_node_id: ";
    rosidl_generator_traits::value_to_yaml(msg.last_node_id, out);
    out << "\n";
  }

  // member: last_node_sequence_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_node_sequence_id: ";
    rosidl_generator_traits::value_to_yaml(msg.last_node_sequence_id, out);
    out << "\n";
  }

  // member: node_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.node_states.size() == 0) {
      out << "node_states: []\n";
    } else {
      out << "node_states:\n";
      for (auto item : msg.node_states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: edge_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.edge_states.size() == 0) {
      out << "edge_states: []\n";
    } else {
      out << "edge_states:\n";
      for (auto item : msg.edge_states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: agv_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "agv_position:\n";
    to_block_style_yaml(msg.agv_position, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }

  // member: loads
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.loads.size() == 0) {
      out << "loads: []\n";
    } else {
      out << "loads:\n";
      for (auto item : msg.loads) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: driving
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "driving: ";
    rosidl_generator_traits::value_to_yaml(msg.driving, out);
    out << "\n";
  }

  // member: paused
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "paused: ";
    rosidl_generator_traits::value_to_yaml(msg.paused, out);
    out << "\n";
  }

  // member: new_base_request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "new_base_request: ";
    rosidl_generator_traits::value_to_yaml(msg.new_base_request, out);
    out << "\n";
  }

  // member: distance_since_last_node
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_since_last_node: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_since_last_node, out);
    out << "\n";
  }

  // member: action_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.action_states.size() == 0) {
      out << "action_states: []\n";
    } else {
      out << "action_states:\n";
      for (auto item : msg.action_states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: battery_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_state:\n";
    to_block_style_yaml(msg.battery_state, out, indentation + 2);
  }

  // member: operating_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "operating_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.operating_mode, out);
    out << "\n";
  }

  // member: errors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.errors.size() == 0) {
      out << "errors: []\n";
    } else {
      out << "errors:\n";
      for (auto item : msg.errors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: informations
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.informations.size() == 0) {
      out << "informations: []\n";
    } else {
      out << "informations:\n";
      for (auto item : msg.informations) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: safety_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "safety_state:\n";
    to_block_style_yaml(msg.safety_state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrderState & msg, bool use_flow_style = false)
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
  const vda5050_msgs::msg::OrderState & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_msgs::msg::OrderState & msg)
{
  return vda5050_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_msgs::msg::OrderState>()
{
  return "vda5050_msgs::msg::OrderState";
}

template<>
inline const char * name<vda5050_msgs::msg::OrderState>()
{
  return "vda5050_msgs/msg/OrderState";
}

template<>
struct has_fixed_size<vda5050_msgs::msg::OrderState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vda5050_msgs::msg::OrderState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vda5050_msgs::msg::OrderState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VDA5050_MSGS__MSG__DETAIL__ORDER_STATE__TRAITS_HPP_
