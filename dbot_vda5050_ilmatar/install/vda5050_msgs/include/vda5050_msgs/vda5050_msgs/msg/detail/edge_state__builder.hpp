// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/EdgeState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/edge_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_EdgeState_trajectory
{
public:
  explicit Init_EdgeState_trajectory(::vda5050_msgs::msg::EdgeState & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::EdgeState trajectory(::vda5050_msgs::msg::EdgeState::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::EdgeState msg_;
};

class Init_EdgeState_released
{
public:
  explicit Init_EdgeState_released(::vda5050_msgs::msg::EdgeState & msg)
  : msg_(msg)
  {}
  Init_EdgeState_trajectory released(::vda5050_msgs::msg::EdgeState::_released_type arg)
  {
    msg_.released = std::move(arg);
    return Init_EdgeState_trajectory(msg_);
  }

private:
  ::vda5050_msgs::msg::EdgeState msg_;
};

class Init_EdgeState_edge_description
{
public:
  explicit Init_EdgeState_edge_description(::vda5050_msgs::msg::EdgeState & msg)
  : msg_(msg)
  {}
  Init_EdgeState_released edge_description(::vda5050_msgs::msg::EdgeState::_edge_description_type arg)
  {
    msg_.edge_description = std::move(arg);
    return Init_EdgeState_released(msg_);
  }

private:
  ::vda5050_msgs::msg::EdgeState msg_;
};

class Init_EdgeState_sequence_id
{
public:
  explicit Init_EdgeState_sequence_id(::vda5050_msgs::msg::EdgeState & msg)
  : msg_(msg)
  {}
  Init_EdgeState_edge_description sequence_id(::vda5050_msgs::msg::EdgeState::_sequence_id_type arg)
  {
    msg_.sequence_id = std::move(arg);
    return Init_EdgeState_edge_description(msg_);
  }

private:
  ::vda5050_msgs::msg::EdgeState msg_;
};

class Init_EdgeState_edge_id
{
public:
  Init_EdgeState_edge_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EdgeState_sequence_id edge_id(::vda5050_msgs::msg::EdgeState::_edge_id_type arg)
  {
    msg_.edge_id = std::move(arg);
    return Init_EdgeState_sequence_id(msg_);
  }

private:
  ::vda5050_msgs::msg::EdgeState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::EdgeState>()
{
  return vda5050_msgs::msg::builder::Init_EdgeState_edge_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__EDGE_STATE__BUILDER_HPP_
