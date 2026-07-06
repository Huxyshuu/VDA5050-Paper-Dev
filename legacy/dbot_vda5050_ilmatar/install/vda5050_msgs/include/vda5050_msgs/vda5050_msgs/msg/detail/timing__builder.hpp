// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Timing.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__TIMING__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__TIMING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/timing__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Timing_visualization_interval
{
public:
  explicit Init_Timing_visualization_interval(::vda5050_msgs::msg::Timing & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Timing visualization_interval(::vda5050_msgs::msg::Timing::_visualization_interval_type arg)
  {
    msg_.visualization_interval = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Timing msg_;
};

class Init_Timing_default_state_interval
{
public:
  explicit Init_Timing_default_state_interval(::vda5050_msgs::msg::Timing & msg)
  : msg_(msg)
  {}
  Init_Timing_visualization_interval default_state_interval(::vda5050_msgs::msg::Timing::_default_state_interval_type arg)
  {
    msg_.default_state_interval = std::move(arg);
    return Init_Timing_visualization_interval(msg_);
  }

private:
  ::vda5050_msgs::msg::Timing msg_;
};

class Init_Timing_min_state_interval
{
public:
  explicit Init_Timing_min_state_interval(::vda5050_msgs::msg::Timing & msg)
  : msg_(msg)
  {}
  Init_Timing_default_state_interval min_state_interval(::vda5050_msgs::msg::Timing::_min_state_interval_type arg)
  {
    msg_.min_state_interval = std::move(arg);
    return Init_Timing_default_state_interval(msg_);
  }

private:
  ::vda5050_msgs::msg::Timing msg_;
};

class Init_Timing_min_order_interval
{
public:
  Init_Timing_min_order_interval()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Timing_min_state_interval min_order_interval(::vda5050_msgs::msg::Timing::_min_order_interval_type arg)
  {
    msg_.min_order_interval = std::move(arg);
    return Init_Timing_min_state_interval(msg_);
  }

private:
  ::vda5050_msgs::msg::Timing msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Timing>()
{
  return vda5050_msgs::msg::builder::Init_Timing_min_order_interval();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__TIMING__BUILDER_HPP_
