// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vda5050_connector:action/NavigateToNode.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__ACTION__DETAIL__NAVIGATE_TO_NODE__TRAITS_HPP_
#define VDA5050_CONNECTOR__ACTION__DETAIL__NAVIGATE_TO_NODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'edge'
#include "vda5050_msgs/msg/detail/edge__traits.hpp"
// Member 'node'
#include "vda5050_msgs/msg/detail/node__traits.hpp"

namespace vda5050_connector
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToNode_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: edge
  {
    out << "edge: ";
    to_flow_style_yaml(msg.edge, out);
    out << ", ";
  }

  // member: node
  {
    out << "node: ";
    to_flow_style_yaml(msg.node, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToNode_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: edge
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "edge:\n";
    to_block_style_yaml(msg.edge, out, indentation + 2);
  }

  // member: node
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node:\n";
    to_block_style_yaml(msg.node, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToNode_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_connector::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_connector::action::NavigateToNode_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::action::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::action::NavigateToNode_Goal & msg)
{
  return vda5050_connector::action::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::action::NavigateToNode_Goal>()
{
  return "vda5050_connector::action::NavigateToNode_Goal";
}

template<>
inline const char * name<vda5050_connector::action::NavigateToNode_Goal>()
{
  return "vda5050_connector/action/NavigateToNode_Goal";
}

template<>
struct has_fixed_size<vda5050_connector::action::NavigateToNode_Goal>
  : std::integral_constant<bool, has_fixed_size<vda5050_msgs::msg::Edge>::value && has_fixed_size<vda5050_msgs::msg::Node>::value> {};

template<>
struct has_bounded_size<vda5050_connector::action::NavigateToNode_Goal>
  : std::integral_constant<bool, has_bounded_size<vda5050_msgs::msg::Edge>::value && has_bounded_size<vda5050_msgs::msg::Node>::value> {};

template<>
struct is_message<vda5050_connector::action::NavigateToNode_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
#include "std_msgs/msg/detail/empty__traits.hpp"

namespace vda5050_connector
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToNode_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToNode_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToNode_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_connector::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_connector::action::NavigateToNode_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::action::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::action::NavigateToNode_Result & msg)
{
  return vda5050_connector::action::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::action::NavigateToNode_Result>()
{
  return "vda5050_connector::action::NavigateToNode_Result";
}

template<>
inline const char * name<vda5050_connector::action::NavigateToNode_Result>()
{
  return "vda5050_connector/action/NavigateToNode_Result";
}

template<>
struct has_fixed_size<vda5050_connector::action::NavigateToNode_Result>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Empty>::value> {};

template<>
struct has_bounded_size<vda5050_connector::action::NavigateToNode_Result>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Empty>::value> {};

template<>
struct is_message<vda5050_connector::action::NavigateToNode_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'position'
#include "vda5050_msgs/msg/detail/agv_position__traits.hpp"
// Member 'velocity'
#include "vda5050_msgs/msg/detail/velocity__traits.hpp"

namespace vda5050_connector
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToNode_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToNode_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToNode_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_connector::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_connector::action::NavigateToNode_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::action::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::action::NavigateToNode_Feedback & msg)
{
  return vda5050_connector::action::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::action::NavigateToNode_Feedback>()
{
  return "vda5050_connector::action::NavigateToNode_Feedback";
}

template<>
inline const char * name<vda5050_connector::action::NavigateToNode_Feedback>()
{
  return "vda5050_connector/action/NavigateToNode_Feedback";
}

template<>
struct has_fixed_size<vda5050_connector::action::NavigateToNode_Feedback>
  : std::integral_constant<bool, has_fixed_size<vda5050_msgs::msg::AGVPosition>::value && has_fixed_size<vda5050_msgs::msg::Velocity>::value> {};

template<>
struct has_bounded_size<vda5050_connector::action::NavigateToNode_Feedback>
  : std::integral_constant<bool, has_bounded_size<vda5050_msgs::msg::AGVPosition>::value && has_bounded_size<vda5050_msgs::msg::Velocity>::value> {};

template<>
struct is_message<vda5050_connector::action::NavigateToNode_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "vda5050_connector/action/detail/navigate_to_node__traits.hpp"

namespace vda5050_connector
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToNode_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToNode_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToNode_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_connector::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_connector::action::NavigateToNode_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::action::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::action::NavigateToNode_SendGoal_Request & msg)
{
  return vda5050_connector::action::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::action::NavigateToNode_SendGoal_Request>()
{
  return "vda5050_connector::action::NavigateToNode_SendGoal_Request";
}

template<>
inline const char * name<vda5050_connector::action::NavigateToNode_SendGoal_Request>()
{
  return "vda5050_connector/action/NavigateToNode_SendGoal_Request";
}

template<>
struct has_fixed_size<vda5050_connector::action::NavigateToNode_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value && has_fixed_size<vda5050_connector::action::NavigateToNode_Goal>::value> {};

template<>
struct has_bounded_size<vda5050_connector::action::NavigateToNode_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value && has_bounded_size<vda5050_connector::action::NavigateToNode_Goal>::value> {};

template<>
struct is_message<vda5050_connector::action::NavigateToNode_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace vda5050_connector
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToNode_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToNode_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToNode_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_connector::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_connector::action::NavigateToNode_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::action::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::action::NavigateToNode_SendGoal_Response & msg)
{
  return vda5050_connector::action::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::action::NavigateToNode_SendGoal_Response>()
{
  return "vda5050_connector::action::NavigateToNode_SendGoal_Response";
}

template<>
inline const char * name<vda5050_connector::action::NavigateToNode_SendGoal_Response>()
{
  return "vda5050_connector/action/NavigateToNode_SendGoal_Response";
}

template<>
struct has_fixed_size<vda5050_connector::action::NavigateToNode_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<vda5050_connector::action::NavigateToNode_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<vda5050_connector::action::NavigateToNode_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vda5050_connector::action::NavigateToNode_SendGoal>()
{
  return "vda5050_connector::action::NavigateToNode_SendGoal";
}

template<>
inline const char * name<vda5050_connector::action::NavigateToNode_SendGoal>()
{
  return "vda5050_connector/action/NavigateToNode_SendGoal";
}

template<>
struct has_fixed_size<vda5050_connector::action::NavigateToNode_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<vda5050_connector::action::NavigateToNode_SendGoal_Request>::value &&
    has_fixed_size<vda5050_connector::action::NavigateToNode_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<vda5050_connector::action::NavigateToNode_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<vda5050_connector::action::NavigateToNode_SendGoal_Request>::value &&
    has_bounded_size<vda5050_connector::action::NavigateToNode_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<vda5050_connector::action::NavigateToNode_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<vda5050_connector::action::NavigateToNode_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vda5050_connector::action::NavigateToNode_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace vda5050_connector
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToNode_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToNode_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToNode_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_connector::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_connector::action::NavigateToNode_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::action::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::action::NavigateToNode_GetResult_Request & msg)
{
  return vda5050_connector::action::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::action::NavigateToNode_GetResult_Request>()
{
  return "vda5050_connector::action::NavigateToNode_GetResult_Request";
}

template<>
inline const char * name<vda5050_connector::action::NavigateToNode_GetResult_Request>()
{
  return "vda5050_connector/action/NavigateToNode_GetResult_Request";
}

template<>
struct has_fixed_size<vda5050_connector::action::NavigateToNode_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<vda5050_connector::action::NavigateToNode_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<vda5050_connector::action::NavigateToNode_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__traits.hpp"

namespace vda5050_connector
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToNode_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToNode_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToNode_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_connector::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_connector::action::NavigateToNode_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::action::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::action::NavigateToNode_GetResult_Response & msg)
{
  return vda5050_connector::action::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::action::NavigateToNode_GetResult_Response>()
{
  return "vda5050_connector::action::NavigateToNode_GetResult_Response";
}

template<>
inline const char * name<vda5050_connector::action::NavigateToNode_GetResult_Response>()
{
  return "vda5050_connector/action/NavigateToNode_GetResult_Response";
}

template<>
struct has_fixed_size<vda5050_connector::action::NavigateToNode_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<vda5050_connector::action::NavigateToNode_Result>::value> {};

template<>
struct has_bounded_size<vda5050_connector::action::NavigateToNode_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<vda5050_connector::action::NavigateToNode_Result>::value> {};

template<>
struct is_message<vda5050_connector::action::NavigateToNode_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vda5050_connector::action::NavigateToNode_GetResult>()
{
  return "vda5050_connector::action::NavigateToNode_GetResult";
}

template<>
inline const char * name<vda5050_connector::action::NavigateToNode_GetResult>()
{
  return "vda5050_connector/action/NavigateToNode_GetResult";
}

template<>
struct has_fixed_size<vda5050_connector::action::NavigateToNode_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<vda5050_connector::action::NavigateToNode_GetResult_Request>::value &&
    has_fixed_size<vda5050_connector::action::NavigateToNode_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<vda5050_connector::action::NavigateToNode_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<vda5050_connector::action::NavigateToNode_GetResult_Request>::value &&
    has_bounded_size<vda5050_connector::action::NavigateToNode_GetResult_Response>::value
  >
{
};

template<>
struct is_service<vda5050_connector::action::NavigateToNode_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<vda5050_connector::action::NavigateToNode_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vda5050_connector::action::NavigateToNode_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "vda5050_connector/action/detail/navigate_to_node__traits.hpp"

namespace vda5050_connector
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToNode_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToNode_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToNode_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace vda5050_connector

namespace rosidl_generator_traits
{

[[deprecated("use vda5050_connector::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vda5050_connector::action::NavigateToNode_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  vda5050_connector::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vda5050_connector::action::to_yaml() instead")]]
inline std::string to_yaml(const vda5050_connector::action::NavigateToNode_FeedbackMessage & msg)
{
  return vda5050_connector::action::to_yaml(msg);
}

template<>
inline const char * data_type<vda5050_connector::action::NavigateToNode_FeedbackMessage>()
{
  return "vda5050_connector::action::NavigateToNode_FeedbackMessage";
}

template<>
inline const char * name<vda5050_connector::action::NavigateToNode_FeedbackMessage>()
{
  return "vda5050_connector/action/NavigateToNode_FeedbackMessage";
}

template<>
struct has_fixed_size<vda5050_connector::action::NavigateToNode_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value && has_fixed_size<vda5050_connector::action::NavigateToNode_Feedback>::value> {};

template<>
struct has_bounded_size<vda5050_connector::action::NavigateToNode_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value && has_bounded_size<vda5050_connector::action::NavigateToNode_Feedback>::value> {};

template<>
struct is_message<vda5050_connector::action::NavigateToNode_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<vda5050_connector::action::NavigateToNode>
  : std::true_type
{
};

template<>
struct is_action_goal<vda5050_connector::action::NavigateToNode_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<vda5050_connector::action::NavigateToNode_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<vda5050_connector::action::NavigateToNode_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // VDA5050_CONNECTOR__ACTION__DETAIL__NAVIGATE_TO_NODE__TRAITS_HPP_
