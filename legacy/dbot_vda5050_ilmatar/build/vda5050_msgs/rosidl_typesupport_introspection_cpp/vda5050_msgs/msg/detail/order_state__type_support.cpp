// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vda5050_msgs:msg/OrderState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vda5050_msgs/msg/detail/order_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace vda5050_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void OrderState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vda5050_msgs::msg::OrderState(_init);
}

void OrderState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vda5050_msgs::msg::OrderState *>(message_memory);
  typed_message->~OrderState();
}

size_t size_function__OrderState__node_states(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::NodeState> *>(untyped_member);
  return member->size();
}

const void * get_const_function__OrderState__node_states(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::NodeState> *>(untyped_member);
  return &member[index];
}

void * get_function__OrderState__node_states(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::NodeState> *>(untyped_member);
  return &member[index];
}

void fetch_function__OrderState__node_states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::NodeState *>(
    get_const_function__OrderState__node_states(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::NodeState *>(untyped_value);
  value = item;
}

void assign_function__OrderState__node_states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::NodeState *>(
    get_function__OrderState__node_states(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::NodeState *>(untyped_value);
  item = value;
}

void resize_function__OrderState__node_states(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::NodeState> *>(untyped_member);
  member->resize(size);
}

size_t size_function__OrderState__edge_states(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::EdgeState> *>(untyped_member);
  return member->size();
}

const void * get_const_function__OrderState__edge_states(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::EdgeState> *>(untyped_member);
  return &member[index];
}

void * get_function__OrderState__edge_states(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::EdgeState> *>(untyped_member);
  return &member[index];
}

void fetch_function__OrderState__edge_states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::EdgeState *>(
    get_const_function__OrderState__edge_states(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::EdgeState *>(untyped_value);
  value = item;
}

void assign_function__OrderState__edge_states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::EdgeState *>(
    get_function__OrderState__edge_states(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::EdgeState *>(untyped_value);
  item = value;
}

void resize_function__OrderState__edge_states(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::EdgeState> *>(untyped_member);
  member->resize(size);
}

size_t size_function__OrderState__loads(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::Load> *>(untyped_member);
  return member->size();
}

const void * get_const_function__OrderState__loads(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::Load> *>(untyped_member);
  return &member[index];
}

void * get_function__OrderState__loads(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::Load> *>(untyped_member);
  return &member[index];
}

void fetch_function__OrderState__loads(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::Load *>(
    get_const_function__OrderState__loads(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::Load *>(untyped_value);
  value = item;
}

void assign_function__OrderState__loads(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::Load *>(
    get_function__OrderState__loads(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::Load *>(untyped_value);
  item = value;
}

void resize_function__OrderState__loads(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::Load> *>(untyped_member);
  member->resize(size);
}

size_t size_function__OrderState__action_states(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::CurrentAction> *>(untyped_member);
  return member->size();
}

const void * get_const_function__OrderState__action_states(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::CurrentAction> *>(untyped_member);
  return &member[index];
}

void * get_function__OrderState__action_states(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::CurrentAction> *>(untyped_member);
  return &member[index];
}

void fetch_function__OrderState__action_states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::CurrentAction *>(
    get_const_function__OrderState__action_states(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::CurrentAction *>(untyped_value);
  value = item;
}

void assign_function__OrderState__action_states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::CurrentAction *>(
    get_function__OrderState__action_states(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::CurrentAction *>(untyped_value);
  item = value;
}

void resize_function__OrderState__action_states(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::CurrentAction> *>(untyped_member);
  member->resize(size);
}

size_t size_function__OrderState__errors(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::Error> *>(untyped_member);
  return member->size();
}

const void * get_const_function__OrderState__errors(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::Error> *>(untyped_member);
  return &member[index];
}

void * get_function__OrderState__errors(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::Error> *>(untyped_member);
  return &member[index];
}

void fetch_function__OrderState__errors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::Error *>(
    get_const_function__OrderState__errors(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::Error *>(untyped_value);
  value = item;
}

void assign_function__OrderState__errors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::Error *>(
    get_function__OrderState__errors(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::Error *>(untyped_value);
  item = value;
}

void resize_function__OrderState__errors(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::Error> *>(untyped_member);
  member->resize(size);
}

size_t size_function__OrderState__informations(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vda5050_msgs::msg::Info> *>(untyped_member);
  return member->size();
}

const void * get_const_function__OrderState__informations(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vda5050_msgs::msg::Info> *>(untyped_member);
  return &member[index];
}

void * get_function__OrderState__informations(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vda5050_msgs::msg::Info> *>(untyped_member);
  return &member[index];
}

void fetch_function__OrderState__informations(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vda5050_msgs::msg::Info *>(
    get_const_function__OrderState__informations(untyped_member, index));
  auto & value = *reinterpret_cast<vda5050_msgs::msg::Info *>(untyped_value);
  value = item;
}

void assign_function__OrderState__informations(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vda5050_msgs::msg::Info *>(
    get_function__OrderState__informations(untyped_member, index));
  const auto & value = *reinterpret_cast<const vda5050_msgs::msg::Info *>(untyped_value);
  item = value;
}

void resize_function__OrderState__informations(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vda5050_msgs::msg::Info> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember OrderState_message_member_array[25] = {
  {
    "header_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, header_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "version",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, version),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "manufacturer",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, manufacturer),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "serial_number",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, serial_number),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "order_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, order_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "order_update_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, order_update_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "zone_set_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, zone_set_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "last_node_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, last_node_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "last_node_sequence_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, last_node_sequence_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "node_states",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::NodeState>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, node_states),  // bytes offset in struct
    nullptr,  // default value
    size_function__OrderState__node_states,  // size() function pointer
    get_const_function__OrderState__node_states,  // get_const(index) function pointer
    get_function__OrderState__node_states,  // get(index) function pointer
    fetch_function__OrderState__node_states,  // fetch(index, &value) function pointer
    assign_function__OrderState__node_states,  // assign(index, value) function pointer
    resize_function__OrderState__node_states  // resize(index) function pointer
  },
  {
    "edge_states",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::EdgeState>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, edge_states),  // bytes offset in struct
    nullptr,  // default value
    size_function__OrderState__edge_states,  // size() function pointer
    get_const_function__OrderState__edge_states,  // get_const(index) function pointer
    get_function__OrderState__edge_states,  // get(index) function pointer
    fetch_function__OrderState__edge_states,  // fetch(index, &value) function pointer
    assign_function__OrderState__edge_states,  // assign(index, value) function pointer
    resize_function__OrderState__edge_states  // resize(index) function pointer
  },
  {
    "agv_position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::AGVPosition>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, agv_position),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "velocity",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::Velocity>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, velocity),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "loads",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::Load>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, loads),  // bytes offset in struct
    nullptr,  // default value
    size_function__OrderState__loads,  // size() function pointer
    get_const_function__OrderState__loads,  // get_const(index) function pointer
    get_function__OrderState__loads,  // get(index) function pointer
    fetch_function__OrderState__loads,  // fetch(index, &value) function pointer
    assign_function__OrderState__loads,  // assign(index, value) function pointer
    resize_function__OrderState__loads  // resize(index) function pointer
  },
  {
    "driving",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, driving),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "paused",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, paused),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "new_base_request",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, new_base_request),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "distance_since_last_node",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, distance_since_last_node),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "action_states",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::CurrentAction>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, action_states),  // bytes offset in struct
    nullptr,  // default value
    size_function__OrderState__action_states,  // size() function pointer
    get_const_function__OrderState__action_states,  // get_const(index) function pointer
    get_function__OrderState__action_states,  // get(index) function pointer
    fetch_function__OrderState__action_states,  // fetch(index, &value) function pointer
    assign_function__OrderState__action_states,  // assign(index, value) function pointer
    resize_function__OrderState__action_states  // resize(index) function pointer
  },
  {
    "battery_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::BatteryState>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, battery_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "operating_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, operating_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "errors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::Error>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, errors),  // bytes offset in struct
    nullptr,  // default value
    size_function__OrderState__errors,  // size() function pointer
    get_const_function__OrderState__errors,  // get_const(index) function pointer
    get_function__OrderState__errors,  // get(index) function pointer
    fetch_function__OrderState__errors,  // fetch(index, &value) function pointer
    assign_function__OrderState__errors,  // assign(index, value) function pointer
    resize_function__OrderState__errors  // resize(index) function pointer
  },
  {
    "informations",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::Info>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, informations),  // bytes offset in struct
    nullptr,  // default value
    size_function__OrderState__informations,  // size() function pointer
    get_const_function__OrderState__informations,  // get_const(index) function pointer
    get_function__OrderState__informations,  // get(index) function pointer
    fetch_function__OrderState__informations,  // fetch(index, &value) function pointer
    assign_function__OrderState__informations,  // assign(index, value) function pointer
    resize_function__OrderState__informations  // resize(index) function pointer
  },
  {
    "safety_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vda5050_msgs::msg::SafetyState>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vda5050_msgs::msg::OrderState, safety_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers OrderState_message_members = {
  "vda5050_msgs::msg",  // message namespace
  "OrderState",  // message name
  25,  // number of fields
  sizeof(vda5050_msgs::msg::OrderState),
  OrderState_message_member_array,  // message members
  OrderState_init_function,  // function to initialize message memory (memory has to be allocated)
  OrderState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t OrderState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &OrderState_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace vda5050_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vda5050_msgs::msg::OrderState>()
{
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::OrderState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vda5050_msgs, msg, OrderState)() {
  return &::vda5050_msgs::msg::rosidl_typesupport_introspection_cpp::OrderState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
