// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/NodeState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__NODE_STATE__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__NODE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/node_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_NodeState_released
{
public:
  explicit Init_NodeState_released(::vda5050_msgs::msg::NodeState & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::NodeState released(::vda5050_msgs::msg::NodeState::_released_type arg)
  {
    msg_.released = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::NodeState msg_;
};

class Init_NodeState_node_position
{
public:
  explicit Init_NodeState_node_position(::vda5050_msgs::msg::NodeState & msg)
  : msg_(msg)
  {}
  Init_NodeState_released node_position(::vda5050_msgs::msg::NodeState::_node_position_type arg)
  {
    msg_.node_position = std::move(arg);
    return Init_NodeState_released(msg_);
  }

private:
  ::vda5050_msgs::msg::NodeState msg_;
};

class Init_NodeState_node_description
{
public:
  explicit Init_NodeState_node_description(::vda5050_msgs::msg::NodeState & msg)
  : msg_(msg)
  {}
  Init_NodeState_node_position node_description(::vda5050_msgs::msg::NodeState::_node_description_type arg)
  {
    msg_.node_description = std::move(arg);
    return Init_NodeState_node_position(msg_);
  }

private:
  ::vda5050_msgs::msg::NodeState msg_;
};

class Init_NodeState_sequence_id
{
public:
  explicit Init_NodeState_sequence_id(::vda5050_msgs::msg::NodeState & msg)
  : msg_(msg)
  {}
  Init_NodeState_node_description sequence_id(::vda5050_msgs::msg::NodeState::_sequence_id_type arg)
  {
    msg_.sequence_id = std::move(arg);
    return Init_NodeState_node_description(msg_);
  }

private:
  ::vda5050_msgs::msg::NodeState msg_;
};

class Init_NodeState_node_id
{
public:
  Init_NodeState_node_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NodeState_sequence_id node_id(::vda5050_msgs::msg::NodeState::_node_id_type arg)
  {
    msg_.node_id = std::move(arg);
    return Init_NodeState_sequence_id(msg_);
  }

private:
  ::vda5050_msgs::msg::NodeState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::NodeState>()
{
  return vda5050_msgs::msg::builder::Init_NodeState_node_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__NODE_STATE__BUILDER_HPP_
