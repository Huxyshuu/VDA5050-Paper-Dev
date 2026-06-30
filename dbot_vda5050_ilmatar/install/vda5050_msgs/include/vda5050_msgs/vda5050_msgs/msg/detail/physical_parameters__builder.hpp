// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/PhysicalParameters.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/physical_parameters__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_PhysicalParameters_length
{
public:
  explicit Init_PhysicalParameters_length(::vda5050_msgs::msg::PhysicalParameters & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::PhysicalParameters length(::vda5050_msgs::msg::PhysicalParameters::_length_type arg)
  {
    msg_.length = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::PhysicalParameters msg_;
};

class Init_PhysicalParameters_width
{
public:
  explicit Init_PhysicalParameters_width(::vda5050_msgs::msg::PhysicalParameters & msg)
  : msg_(msg)
  {}
  Init_PhysicalParameters_length width(::vda5050_msgs::msg::PhysicalParameters::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_PhysicalParameters_length(msg_);
  }

private:
  ::vda5050_msgs::msg::PhysicalParameters msg_;
};

class Init_PhysicalParameters_height_max
{
public:
  explicit Init_PhysicalParameters_height_max(::vda5050_msgs::msg::PhysicalParameters & msg)
  : msg_(msg)
  {}
  Init_PhysicalParameters_width height_max(::vda5050_msgs::msg::PhysicalParameters::_height_max_type arg)
  {
    msg_.height_max = std::move(arg);
    return Init_PhysicalParameters_width(msg_);
  }

private:
  ::vda5050_msgs::msg::PhysicalParameters msg_;
};

class Init_PhysicalParameters_height_min
{
public:
  explicit Init_PhysicalParameters_height_min(::vda5050_msgs::msg::PhysicalParameters & msg)
  : msg_(msg)
  {}
  Init_PhysicalParameters_height_max height_min(::vda5050_msgs::msg::PhysicalParameters::_height_min_type arg)
  {
    msg_.height_min = std::move(arg);
    return Init_PhysicalParameters_height_max(msg_);
  }

private:
  ::vda5050_msgs::msg::PhysicalParameters msg_;
};

class Init_PhysicalParameters_deceleration_max
{
public:
  explicit Init_PhysicalParameters_deceleration_max(::vda5050_msgs::msg::PhysicalParameters & msg)
  : msg_(msg)
  {}
  Init_PhysicalParameters_height_min deceleration_max(::vda5050_msgs::msg::PhysicalParameters::_deceleration_max_type arg)
  {
    msg_.deceleration_max = std::move(arg);
    return Init_PhysicalParameters_height_min(msg_);
  }

private:
  ::vda5050_msgs::msg::PhysicalParameters msg_;
};

class Init_PhysicalParameters_acceleration_max
{
public:
  explicit Init_PhysicalParameters_acceleration_max(::vda5050_msgs::msg::PhysicalParameters & msg)
  : msg_(msg)
  {}
  Init_PhysicalParameters_deceleration_max acceleration_max(::vda5050_msgs::msg::PhysicalParameters::_acceleration_max_type arg)
  {
    msg_.acceleration_max = std::move(arg);
    return Init_PhysicalParameters_deceleration_max(msg_);
  }

private:
  ::vda5050_msgs::msg::PhysicalParameters msg_;
};

class Init_PhysicalParameters_speed_max
{
public:
  explicit Init_PhysicalParameters_speed_max(::vda5050_msgs::msg::PhysicalParameters & msg)
  : msg_(msg)
  {}
  Init_PhysicalParameters_acceleration_max speed_max(::vda5050_msgs::msg::PhysicalParameters::_speed_max_type arg)
  {
    msg_.speed_max = std::move(arg);
    return Init_PhysicalParameters_acceleration_max(msg_);
  }

private:
  ::vda5050_msgs::msg::PhysicalParameters msg_;
};

class Init_PhysicalParameters_speed_min
{
public:
  Init_PhysicalParameters_speed_min()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PhysicalParameters_speed_max speed_min(::vda5050_msgs::msg::PhysicalParameters::_speed_min_type arg)
  {
    msg_.speed_min = std::move(arg);
    return Init_PhysicalParameters_speed_max(msg_);
  }

private:
  ::vda5050_msgs::msg::PhysicalParameters msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::PhysicalParameters>()
{
  return vda5050_msgs::msg::builder::Init_PhysicalParameters_speed_min();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__PHYSICAL_PARAMETERS__BUILDER_HPP_
