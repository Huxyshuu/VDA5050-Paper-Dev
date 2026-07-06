// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from vda5050_msgs:msg/MaxArrayLens.idl
// generated code does not contain a copyright notice
#include "vda5050_msgs/msg/detail/max_array_lens__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "vda5050_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "vda5050_msgs/msg/detail/max_array_lens__struct.h"
#include "vda5050_msgs/msg/detail/max_array_lens__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _MaxArrayLens__ros_msg_type = vda5050_msgs__msg__MaxArrayLens;

static bool _MaxArrayLens__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MaxArrayLens__ros_msg_type * ros_message = static_cast<const _MaxArrayLens__ros_msg_type *>(untyped_ros_message);
  // Field name: order_nodes
  {
    cdr << ros_message->order_nodes;
  }

  // Field name: order_edges
  {
    cdr << ros_message->order_edges;
  }

  // Field name: node_actions
  {
    cdr << ros_message->node_actions;
  }

  // Field name: edge_actions
  {
    cdr << ros_message->edge_actions;
  }

  // Field name: actions_parameters
  {
    cdr << ros_message->actions_parameters;
  }

  // Field name: instant_actions
  {
    cdr << ros_message->instant_actions;
  }

  // Field name: trajectory_knot_vector
  {
    cdr << ros_message->trajectory_knot_vector;
  }

  // Field name: trajectory_control_points
  {
    cdr << ros_message->trajectory_control_points;
  }

  // Field name: state_node_states
  {
    cdr << ros_message->state_node_states;
  }

  // Field name: state_edge_states
  {
    cdr << ros_message->state_edge_states;
  }

  // Field name: state_loads
  {
    cdr << ros_message->state_loads;
  }

  // Field name: state_action_states
  {
    cdr << ros_message->state_action_states;
  }

  // Field name: state_errors
  {
    cdr << ros_message->state_errors;
  }

  // Field name: state_information
  {
    cdr << ros_message->state_information;
  }

  // Field name: error_references
  {
    cdr << ros_message->error_references;
  }

  // Field name: info_references
  {
    cdr << ros_message->info_references;
  }

  return true;
}

static bool _MaxArrayLens__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MaxArrayLens__ros_msg_type * ros_message = static_cast<_MaxArrayLens__ros_msg_type *>(untyped_ros_message);
  // Field name: order_nodes
  {
    cdr >> ros_message->order_nodes;
  }

  // Field name: order_edges
  {
    cdr >> ros_message->order_edges;
  }

  // Field name: node_actions
  {
    cdr >> ros_message->node_actions;
  }

  // Field name: edge_actions
  {
    cdr >> ros_message->edge_actions;
  }

  // Field name: actions_parameters
  {
    cdr >> ros_message->actions_parameters;
  }

  // Field name: instant_actions
  {
    cdr >> ros_message->instant_actions;
  }

  // Field name: trajectory_knot_vector
  {
    cdr >> ros_message->trajectory_knot_vector;
  }

  // Field name: trajectory_control_points
  {
    cdr >> ros_message->trajectory_control_points;
  }

  // Field name: state_node_states
  {
    cdr >> ros_message->state_node_states;
  }

  // Field name: state_edge_states
  {
    cdr >> ros_message->state_edge_states;
  }

  // Field name: state_loads
  {
    cdr >> ros_message->state_loads;
  }

  // Field name: state_action_states
  {
    cdr >> ros_message->state_action_states;
  }

  // Field name: state_errors
  {
    cdr >> ros_message->state_errors;
  }

  // Field name: state_information
  {
    cdr >> ros_message->state_information;
  }

  // Field name: error_references
  {
    cdr >> ros_message->error_references;
  }

  // Field name: info_references
  {
    cdr >> ros_message->info_references;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t get_serialized_size_vda5050_msgs__msg__MaxArrayLens(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MaxArrayLens__ros_msg_type * ros_message = static_cast<const _MaxArrayLens__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name order_nodes
  {
    size_t item_size = sizeof(ros_message->order_nodes);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name order_edges
  {
    size_t item_size = sizeof(ros_message->order_edges);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name node_actions
  {
    size_t item_size = sizeof(ros_message->node_actions);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name edge_actions
  {
    size_t item_size = sizeof(ros_message->edge_actions);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name actions_parameters
  {
    size_t item_size = sizeof(ros_message->actions_parameters);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name instant_actions
  {
    size_t item_size = sizeof(ros_message->instant_actions);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name trajectory_knot_vector
  {
    size_t item_size = sizeof(ros_message->trajectory_knot_vector);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name trajectory_control_points
  {
    size_t item_size = sizeof(ros_message->trajectory_control_points);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name state_node_states
  {
    size_t item_size = sizeof(ros_message->state_node_states);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name state_edge_states
  {
    size_t item_size = sizeof(ros_message->state_edge_states);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name state_loads
  {
    size_t item_size = sizeof(ros_message->state_loads);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name state_action_states
  {
    size_t item_size = sizeof(ros_message->state_action_states);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name state_errors
  {
    size_t item_size = sizeof(ros_message->state_errors);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name state_information
  {
    size_t item_size = sizeof(ros_message->state_information);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name error_references
  {
    size_t item_size = sizeof(ros_message->error_references);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name info_references
  {
    size_t item_size = sizeof(ros_message->info_references);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MaxArrayLens__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_vda5050_msgs__msg__MaxArrayLens(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_vda5050_msgs
size_t max_serialized_size_vda5050_msgs__msg__MaxArrayLens(
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

  // member: order_nodes
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: order_edges
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: node_actions
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: edge_actions
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: actions_parameters
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: instant_actions
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: trajectory_knot_vector
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: trajectory_control_points
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: state_node_states
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: state_edge_states
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: state_loads
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: state_action_states
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: state_errors
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: state_information
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: error_references
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: info_references
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
    using DataType = vda5050_msgs__msg__MaxArrayLens;
    is_plain =
      (
      offsetof(DataType, info_references) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _MaxArrayLens__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_vda5050_msgs__msg__MaxArrayLens(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MaxArrayLens = {
  "vda5050_msgs::msg",
  "MaxArrayLens",
  _MaxArrayLens__cdr_serialize,
  _MaxArrayLens__cdr_deserialize,
  _MaxArrayLens__get_serialized_size,
  _MaxArrayLens__max_serialized_size
};

static rosidl_message_type_support_t _MaxArrayLens__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MaxArrayLens,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vda5050_msgs, msg, MaxArrayLens)() {
  return &_MaxArrayLens__type_support;
}

#if defined(__cplusplus)
}
#endif
