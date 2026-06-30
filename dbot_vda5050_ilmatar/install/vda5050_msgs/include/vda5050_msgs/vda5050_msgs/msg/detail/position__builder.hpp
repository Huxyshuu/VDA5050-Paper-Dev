// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Position.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Position_theta
{
public:
  explicit Init_Position_theta(::vda5050_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Position theta(::vda5050_msgs::msg::Position::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Position msg_;
};

class Init_Position_y
{
public:
  explicit Init_Position_y(::vda5050_msgs::msg::Position & msg)
  : msg_(msg)
  {}
  Init_Position_theta y(::vda5050_msgs::msg::Position::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Position_theta(msg_);
  }

private:
  ::vda5050_msgs::msg::Position msg_;
};

class Init_Position_x
{
public:
  Init_Position_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Position_y x(::vda5050_msgs::msg::Position::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Position_y(msg_);
  }

private:
  ::vda5050_msgs::msg::Position msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Position>()
{
  return vda5050_msgs::msg::builder::Init_Position_x();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__POSITION__BUILDER_HPP_
