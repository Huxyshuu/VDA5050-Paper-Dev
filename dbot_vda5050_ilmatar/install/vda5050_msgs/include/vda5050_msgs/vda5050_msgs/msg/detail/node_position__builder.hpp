// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/NodePosition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__NODE_POSITION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__NODE_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/node_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_NodePosition_map_description
{
public:
  explicit Init_NodePosition_map_description(::vda5050_msgs::msg::NodePosition & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::NodePosition map_description(::vda5050_msgs::msg::NodePosition::_map_description_type arg)
  {
    msg_.map_description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::NodePosition msg_;
};

class Init_NodePosition_map_id
{
public:
  explicit Init_NodePosition_map_id(::vda5050_msgs::msg::NodePosition & msg)
  : msg_(msg)
  {}
  Init_NodePosition_map_description map_id(::vda5050_msgs::msg::NodePosition::_map_id_type arg)
  {
    msg_.map_id = std::move(arg);
    return Init_NodePosition_map_description(msg_);
  }

private:
  ::vda5050_msgs::msg::NodePosition msg_;
};

class Init_NodePosition_allowed_deviation_theta
{
public:
  explicit Init_NodePosition_allowed_deviation_theta(::vda5050_msgs::msg::NodePosition & msg)
  : msg_(msg)
  {}
  Init_NodePosition_map_id allowed_deviation_theta(::vda5050_msgs::msg::NodePosition::_allowed_deviation_theta_type arg)
  {
    msg_.allowed_deviation_theta = std::move(arg);
    return Init_NodePosition_map_id(msg_);
  }

private:
  ::vda5050_msgs::msg::NodePosition msg_;
};

class Init_NodePosition_allowed_deviation_x_y
{
public:
  explicit Init_NodePosition_allowed_deviation_x_y(::vda5050_msgs::msg::NodePosition & msg)
  : msg_(msg)
  {}
  Init_NodePosition_allowed_deviation_theta allowed_deviation_x_y(::vda5050_msgs::msg::NodePosition::_allowed_deviation_x_y_type arg)
  {
    msg_.allowed_deviation_x_y = std::move(arg);
    return Init_NodePosition_allowed_deviation_theta(msg_);
  }

private:
  ::vda5050_msgs::msg::NodePosition msg_;
};

class Init_NodePosition_theta
{
public:
  explicit Init_NodePosition_theta(::vda5050_msgs::msg::NodePosition & msg)
  : msg_(msg)
  {}
  Init_NodePosition_allowed_deviation_x_y theta(::vda5050_msgs::msg::NodePosition::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_NodePosition_allowed_deviation_x_y(msg_);
  }

private:
  ::vda5050_msgs::msg::NodePosition msg_;
};

class Init_NodePosition_y
{
public:
  explicit Init_NodePosition_y(::vda5050_msgs::msg::NodePosition & msg)
  : msg_(msg)
  {}
  Init_NodePosition_theta y(::vda5050_msgs::msg::NodePosition::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_NodePosition_theta(msg_);
  }

private:
  ::vda5050_msgs::msg::NodePosition msg_;
};

class Init_NodePosition_x
{
public:
  Init_NodePosition_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NodePosition_y x(::vda5050_msgs::msg::NodePosition::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_NodePosition_y(msg_);
  }

private:
  ::vda5050_msgs::msg::NodePosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::NodePosition>()
{
  return vda5050_msgs::msg::builder::Init_NodePosition_x();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__NODE_POSITION__BUILDER_HPP_
