// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Velocity.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__VELOCITY__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__VELOCITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/velocity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Velocity_omega
{
public:
  explicit Init_Velocity_omega(::vda5050_msgs::msg::Velocity & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Velocity omega(::vda5050_msgs::msg::Velocity::_omega_type arg)
  {
    msg_.omega = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Velocity msg_;
};

class Init_Velocity_vy
{
public:
  explicit Init_Velocity_vy(::vda5050_msgs::msg::Velocity & msg)
  : msg_(msg)
  {}
  Init_Velocity_omega vy(::vda5050_msgs::msg::Velocity::_vy_type arg)
  {
    msg_.vy = std::move(arg);
    return Init_Velocity_omega(msg_);
  }

private:
  ::vda5050_msgs::msg::Velocity msg_;
};

class Init_Velocity_vx
{
public:
  Init_Velocity_vx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Velocity_vy vx(::vda5050_msgs::msg::Velocity::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_Velocity_vy(msg_);
  }

private:
  ::vda5050_msgs::msg::Velocity msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Velocity>()
{
  return vda5050_msgs::msg::builder::Init_Velocity_vx();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__VELOCITY__BUILDER_HPP_
