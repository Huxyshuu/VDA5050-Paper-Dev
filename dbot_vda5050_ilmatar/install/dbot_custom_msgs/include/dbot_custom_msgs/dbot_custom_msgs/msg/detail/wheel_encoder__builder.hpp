// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dbot_custom_msgs:msg/WheelEncoder.idl
// generated code does not contain a copyright notice

#ifndef DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__BUILDER_HPP_
#define DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dbot_custom_msgs/msg/detail/wheel_encoder__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dbot_custom_msgs
{

namespace msg
{

namespace builder
{

class Init_WheelEncoder_right
{
public:
  explicit Init_WheelEncoder_right(::dbot_custom_msgs::msg::WheelEncoder & msg)
  : msg_(msg)
  {}
  ::dbot_custom_msgs::msg::WheelEncoder right(::dbot_custom_msgs::msg::WheelEncoder::_right_type arg)
  {
    msg_.right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dbot_custom_msgs::msg::WheelEncoder msg_;
};

class Init_WheelEncoder_left
{
public:
  explicit Init_WheelEncoder_left(::dbot_custom_msgs::msg::WheelEncoder & msg)
  : msg_(msg)
  {}
  Init_WheelEncoder_right left(::dbot_custom_msgs::msg::WheelEncoder::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_WheelEncoder_right(msg_);
  }

private:
  ::dbot_custom_msgs::msg::WheelEncoder msg_;
};

class Init_WheelEncoder_header
{
public:
  Init_WheelEncoder_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WheelEncoder_left header(::dbot_custom_msgs::msg::WheelEncoder::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_WheelEncoder_left(msg_);
  }

private:
  ::dbot_custom_msgs::msg::WheelEncoder msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dbot_custom_msgs::msg::WheelEncoder>()
{
  return dbot_custom_msgs::msg::builder::Init_WheelEncoder_header();
}

}  // namespace dbot_custom_msgs

#endif  // DBOT_CUSTOM_MSGS__MSG__DETAIL__WHEEL_ENCODER__BUILDER_HPP_
