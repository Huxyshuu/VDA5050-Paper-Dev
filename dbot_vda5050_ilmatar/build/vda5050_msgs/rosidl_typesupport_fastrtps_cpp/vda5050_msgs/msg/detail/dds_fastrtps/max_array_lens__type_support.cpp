// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_msgs:msg/MaxArrayLens.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/max_array_lens__rosidl_typesupport_fastrtps_cpp.hpp"
#include "vda5050_msgs/msg/detail/max_array_lens__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace vda5050_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
cdr_serialize(
  const vda5050_msgs::msg::MaxArrayLens & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: order_nodes
  cdr << ros_message.order_nodes;
  // Member: order_edges
  cdr << ros_message.order_edges;
  // Member: node_actions
  cdr << ros_message.node_actions;
  // Member: edge_actions
  cdr << ros_message.edge_actions;
  // Member: actions_parameters
  cdr << ros_message.actions_parameters;
  // Member: instant_actions
  cdr << ros_message.instant_actions;
  // Member: trajectory_knot_vector
  cdr << ros_message.trajectory_knot_vector;
  // Member: trajectory_control_points
  cdr << ros_message.trajectory_control_points;
  // Member: state_node_states
  cdr << ros_message.state_node_states;
  // Member: state_edge_states
  cdr << ros_message.state_edge_states;
  // Member: state_loads
  cdr << ros_message.state_loads;
  // Member: state_action_states
  cdr << ros_message.state_action_states;
  // Member: state_errors
  cdr << ros_message.state_errors;
  // Member: state_information
  cdr << ros_message.state_information;
  // Member: error_references
  cdr << ros_message.error_references;
  // Member: info_references
  cdr << ros_message.info_references;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vda5050_msgs::msg::MaxArrayLens & ros_message)
{
  // Member: order_nodes
  cdr >> ros_message.order_nodes;

  // Member: order_edges
  cdr >> ros_message.order_edges;

  // Member: node_actions
  cdr >> ros_message.node_actions;

  // Member: edge_actions
  cdr >> ros_message.edge_actions;

  // Member: actions_parameters
  cdr >> ros_message.actions_parameters;

  // Member: instant_actions
  cdr >> ros_message.instant_actions;

  // Member: trajectory_knot_vector
  cdr >> ros_message.trajectory_knot_vector;

  // Member: trajectory_control_points
  cdr >> ros_message.trajectory_control_points;

  // Member: state_node_states
  cdr >> ros_message.state_node_states;

  // Member: state_edge_states
  cdr >> ros_message.state_edge_states;

  // Member: state_loads
  cdr >> ros_message.state_loads;

  // Member: state_action_states
  cdr >> ros_message.state_action_states;

  // Member: state_errors
  cdr >> ros_message.state_errors;

  // Member: state_information
  cdr >> ros_message.state_information;

  // Member: error_references
  cdr >> ros_message.error_references;

  // Member: info_references
  cdr >> ros_message.info_references;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
get_serialized_size(
  const vda5050_msgs::msg::MaxArrayLens & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: order_nodes
  {
    size_t item_size = sizeof(ros_message.order_nodes);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: order_edges
  {
    size_t item_size = sizeof(ros_message.order_edges);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: node_actions
  {
    size_t item_size = sizeof(ros_message.node_actions);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: edge_actions
  {
    size_t item_size = sizeof(ros_message.edge_actions);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: actions_parameters
  {
    size_t item_size = sizeof(ros_message.actions_parameters);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: instant_actions
  {
    size_t item_size = sizeof(ros_message.instant_actions);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: trajectory_knot_vector
  {
    size_t item_size = sizeof(ros_message.trajectory_knot_vector);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: trajectory_control_points
  {
    size_t item_size = sizeof(ros_message.trajectory_control_points);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: state_node_states
  {
    size_t item_size = sizeof(ros_message.state_node_states);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: state_edge_states
  {
    size_t item_size = sizeof(ros_message.state_edge_states);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: state_loads
  {
    size_t item_size = sizeof(ros_message.state_loads);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: state_action_states
  {
    size_t item_size = sizeof(ros_message.state_action_states);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: state_errors
  {
    size_t item_size = sizeof(ros_message.state_errors);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: state_information
  {
    size_t item_size = sizeof(ros_message.state_information);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: error_references
  {
    size_t item_size = sizeof(ros_message.error_references);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: info_references
  {
    size_t item_size = sizeof(ros_message.info_references);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vda5050_msgs
max_serialized_size_MaxArrayLens(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: order_nodes
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: order_edges
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: node_actions
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: edge_actions
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: actions_parameters
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: instant_actions
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: trajectory_knot_vector
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: trajectory_control_points
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: state_node_states
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: state_edge_states
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: state_loads
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: state_action_states
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: state_errors
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: state_information
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: error_references
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: info_references
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = vda5050_msgs::msg::MaxArrayLens;
    is_plain =
      (
      offsetof(DataType, info_references) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _MaxArrayLens__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const vda5050_msgs::msg::MaxArrayLens *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MaxArrayLens__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<vda5050_msgs::msg::MaxArrayLens *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MaxArrayLens__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const vda5050_msgs::msg::MaxArrayLens *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MaxArrayLens__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MaxArrayLens(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MaxArrayLens__callbacks = {
  "vda5050_msgs::msg",
  "MaxArrayLens",
  _MaxArrayLens__cdr_serialize,
  _MaxArrayLens__cdr_deserialize,
  _MaxArrayLens__get_serialized_size,
  _MaxArrayLens__max_serialized_size
};

static rosidl_message_type_support_t _MaxArrayLens__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MaxArrayLens__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace vda5050_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_vda5050_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_msgs::msg::MaxArrayLens>()
{
  return &vda5050_msgs::msg::typesupport_fastrtps_cpp::_MaxArrayLens__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vda5050_msgs, msg, MaxArrayLens)() {
  return &vda5050_msgs::msg::typesupport_fastrtps_cpp::_MaxArrayLens__handle;
}

#ifdef __cplusplus
}
#endif
