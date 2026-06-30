// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Edge.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__EDGE__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__EDGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/edge__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Edge_actions
{
public:
  explicit Init_Edge_actions(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Edge actions(::vda5050_msgs::msg::Edge::_actions_type arg)
  {
    msg_.actions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_length
{
public:
  explicit Init_Edge_length(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_actions length(::vda5050_msgs::msg::Edge::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_Edge_actions(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_trajectory
{
public:
  explicit Init_Edge_trajectory(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_length trajectory(::vda5050_msgs::msg::Edge::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return Init_Edge_length(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_max_rotation_speed
{
public:
  explicit Init_Edge_max_rotation_speed(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_trajectory max_rotation_speed(::vda5050_msgs::msg::Edge::_max_rotation_speed_type arg)
  {
    msg_.max_rotation_speed = std::move(arg);
    return Init_Edge_trajectory(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_rotation_allowed
{
public:
  explicit Init_Edge_rotation_allowed(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_max_rotation_speed rotation_allowed(::vda5050_msgs::msg::Edge::_rotation_allowed_type arg)
  {
    msg_.rotation_allowed = std::move(arg);
    return Init_Edge_max_rotation_speed(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_direction
{
public:
  explicit Init_Edge_direction(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_rotation_allowed direction(::vda5050_msgs::msg::Edge::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_Edge_rotation_allowed(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_orientation
{
public:
  explicit Init_Edge_orientation(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_direction orientation(::vda5050_msgs::msg::Edge::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return Init_Edge_direction(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_min_height
{
public:
  explicit Init_Edge_min_height(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_orientation min_height(::vda5050_msgs::msg::Edge::_min_height_type arg)
  {
    msg_.min_height = std::move(arg);
    return Init_Edge_orientation(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_max_height
{
public:
  explicit Init_Edge_max_height(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_min_height max_height(::vda5050_msgs::msg::Edge::_max_height_type arg)
  {
    msg_.max_height = std::move(arg);
    return Init_Edge_min_height(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_max_speed
{
public:
  explicit Init_Edge_max_speed(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_max_height max_speed(::vda5050_msgs::msg::Edge::_max_speed_type arg)
  {
    msg_.max_speed = std::move(arg);
    return Init_Edge_max_height(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_end_node_id
{
public:
  explicit Init_Edge_end_node_id(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_max_speed end_node_id(::vda5050_msgs::msg::Edge::_end_node_id_type arg)
  {
    msg_.end_node_id = std::move(arg);
    return Init_Edge_max_speed(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_start_node_id
{
public:
  explicit Init_Edge_start_node_id(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_end_node_id start_node_id(::vda5050_msgs::msg::Edge::_start_node_id_type arg)
  {
    msg_.start_node_id = std::move(arg);
    return Init_Edge_end_node_id(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_released
{
public:
  explicit Init_Edge_released(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_start_node_id released(::vda5050_msgs::msg::Edge::_released_type arg)
  {
    msg_.released = std::move(arg);
    return Init_Edge_start_node_id(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_edge_description
{
public:
  explicit Init_Edge_edge_description(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_released edge_description(::vda5050_msgs::msg::Edge::_edge_description_type arg)
  {
    msg_.edge_description = std::move(arg);
    return Init_Edge_released(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_sequence_id
{
public:
  explicit Init_Edge_sequence_id(::vda5050_msgs::msg::Edge & msg)
  : msg_(msg)
  {}
  Init_Edge_edge_description sequence_id(::vda5050_msgs::msg::Edge::_sequence_id_type arg)
  {
    msg_.sequence_id = std::move(arg);
    return Init_Edge_edge_description(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

class Init_Edge_edge_id
{
public:
  Init_Edge_edge_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Edge_sequence_id edge_id(::vda5050_msgs::msg::Edge::_edge_id_type arg)
  {
    msg_.edge_id = std::move(arg);
    return Init_Edge_sequence_id(msg_);
  }

private:
  ::vda5050_msgs::msg::Edge msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Edge>()
{
  return vda5050_msgs::msg::builder::Init_Edge_edge_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__EDGE__BUILDER_HPP_
