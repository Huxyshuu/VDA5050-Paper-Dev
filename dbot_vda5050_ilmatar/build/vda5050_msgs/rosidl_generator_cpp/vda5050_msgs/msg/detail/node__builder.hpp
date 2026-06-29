// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Node.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__NODE__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__NODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/node__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Node_actions
{
public:
  explicit Init_Node_actions(::vda5050_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Node actions(::vda5050_msgs::msg::Node::_actions_type arg)
  {
    msg_.actions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Node msg_;
};

class Init_Node_node_position
{
public:
  explicit Init_Node_node_position(::vda5050_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_actions node_position(::vda5050_msgs::msg::Node::_node_position_type arg)
  {
    msg_.node_position = std::move(arg);
    return Init_Node_actions(msg_);
  }

private:
  ::vda5050_msgs::msg::Node msg_;
};

class Init_Node_released
{
public:
  explicit Init_Node_released(::vda5050_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_node_position released(::vda5050_msgs::msg::Node::_released_type arg)
  {
    msg_.released = std::move(arg);
    return Init_Node_node_position(msg_);
  }

private:
  ::vda5050_msgs::msg::Node msg_;
};

class Init_Node_node_description
{
public:
  explicit Init_Node_node_description(::vda5050_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_released node_description(::vda5050_msgs::msg::Node::_node_description_type arg)
  {
    msg_.node_description = std::move(arg);
    return Init_Node_released(msg_);
  }

private:
  ::vda5050_msgs::msg::Node msg_;
};

class Init_Node_sequence_id
{
public:
  explicit Init_Node_sequence_id(::vda5050_msgs::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_node_description sequence_id(::vda5050_msgs::msg::Node::_sequence_id_type arg)
  {
    msg_.sequence_id = std::move(arg);
    return Init_Node_node_description(msg_);
  }

private:
  ::vda5050_msgs::msg::Node msg_;
};

class Init_Node_node_id
{
public:
  Init_Node_node_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Node_sequence_id node_id(::vda5050_msgs::msg::Node::_node_id_type arg)
  {
    msg_.node_id = std::move(arg);
    return Init_Node_sequence_id(msg_);
  }

private:
  ::vda5050_msgs::msg::Node msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Node>()
{
  return vda5050_msgs::msg::builder::Init_Node_node_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__NODE__BUILDER_HPP_
