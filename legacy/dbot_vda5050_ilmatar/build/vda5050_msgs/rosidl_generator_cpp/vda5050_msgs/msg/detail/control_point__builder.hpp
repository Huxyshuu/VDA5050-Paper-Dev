// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/ControlPoint.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__CONTROL_POINT__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__CONTROL_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/control_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_ControlPoint_weight
{
public:
  explicit Init_ControlPoint_weight(::vda5050_msgs::msg::ControlPoint & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::ControlPoint weight(::vda5050_msgs::msg::ControlPoint::_weight_type arg)
  {
    msg_.weight = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::ControlPoint msg_;
};

class Init_ControlPoint_orientation
{
public:
  explicit Init_ControlPoint_orientation(::vda5050_msgs::msg::ControlPoint & msg)
  : msg_(msg)
  {}
  Init_ControlPoint_weight orientation(::vda5050_msgs::msg::ControlPoint::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return Init_ControlPoint_weight(msg_);
  }

private:
  ::vda5050_msgs::msg::ControlPoint msg_;
};

class Init_ControlPoint_y
{
public:
  explicit Init_ControlPoint_y(::vda5050_msgs::msg::ControlPoint & msg)
  : msg_(msg)
  {}
  Init_ControlPoint_orientation y(::vda5050_msgs::msg::ControlPoint::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ControlPoint_orientation(msg_);
  }

private:
  ::vda5050_msgs::msg::ControlPoint msg_;
};

class Init_ControlPoint_x
{
public:
  Init_ControlPoint_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControlPoint_y x(::vda5050_msgs::msg::ControlPoint::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ControlPoint_y(msg_);
  }

private:
  ::vda5050_msgs::msg::ControlPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::ControlPoint>()
{
  return vda5050_msgs::msg::builder::Init_ControlPoint_x();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__CONTROL_POINT__BUILDER_HPP_
