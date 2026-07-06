// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/WheelDefinition.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/wheel_definition__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_WheelDefinition_constraints
{
public:
  explicit Init_WheelDefinition_constraints(::vda5050_msgs::msg::WheelDefinition & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::WheelDefinition constraints(::vda5050_msgs::msg::WheelDefinition::_constraints_type arg)
  {
    msg_.constraints = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::WheelDefinition msg_;
};

class Init_WheelDefinition_center_displacement
{
public:
  explicit Init_WheelDefinition_center_displacement(::vda5050_msgs::msg::WheelDefinition & msg)
  : msg_(msg)
  {}
  Init_WheelDefinition_constraints center_displacement(::vda5050_msgs::msg::WheelDefinition::_center_displacement_type arg)
  {
    msg_.center_displacement = std::move(arg);
    return Init_WheelDefinition_constraints(msg_);
  }

private:
  ::vda5050_msgs::msg::WheelDefinition msg_;
};

class Init_WheelDefinition_width
{
public:
  explicit Init_WheelDefinition_width(::vda5050_msgs::msg::WheelDefinition & msg)
  : msg_(msg)
  {}
  Init_WheelDefinition_center_displacement width(::vda5050_msgs::msg::WheelDefinition::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_WheelDefinition_center_displacement(msg_);
  }

private:
  ::vda5050_msgs::msg::WheelDefinition msg_;
};

class Init_WheelDefinition_diameter
{
public:
  explicit Init_WheelDefinition_diameter(::vda5050_msgs::msg::WheelDefinition & msg)
  : msg_(msg)
  {}
  Init_WheelDefinition_width diameter(::vda5050_msgs::msg::WheelDefinition::_diameter_type arg)
  {
    msg_.diameter = std::move(arg);
    return Init_WheelDefinition_width(msg_);
  }

private:
  ::vda5050_msgs::msg::WheelDefinition msg_;
};

class Init_WheelDefinition_position
{
public:
  explicit Init_WheelDefinition_position(::vda5050_msgs::msg::WheelDefinition & msg)
  : msg_(msg)
  {}
  Init_WheelDefinition_diameter position(::vda5050_msgs::msg::WheelDefinition::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_WheelDefinition_diameter(msg_);
  }

private:
  ::vda5050_msgs::msg::WheelDefinition msg_;
};

class Init_WheelDefinition_is_active_steered
{
public:
  explicit Init_WheelDefinition_is_active_steered(::vda5050_msgs::msg::WheelDefinition & msg)
  : msg_(msg)
  {}
  Init_WheelDefinition_position is_active_steered(::vda5050_msgs::msg::WheelDefinition::_is_active_steered_type arg)
  {
    msg_.is_active_steered = std::move(arg);
    return Init_WheelDefinition_position(msg_);
  }

private:
  ::vda5050_msgs::msg::WheelDefinition msg_;
};

class Init_WheelDefinition_is_active_driven
{
public:
  explicit Init_WheelDefinition_is_active_driven(::vda5050_msgs::msg::WheelDefinition & msg)
  : msg_(msg)
  {}
  Init_WheelDefinition_is_active_steered is_active_driven(::vda5050_msgs::msg::WheelDefinition::_is_active_driven_type arg)
  {
    msg_.is_active_driven = std::move(arg);
    return Init_WheelDefinition_is_active_steered(msg_);
  }

private:
  ::vda5050_msgs::msg::WheelDefinition msg_;
};

class Init_WheelDefinition_type
{
public:
  Init_WheelDefinition_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WheelDefinition_is_active_driven type(::vda5050_msgs::msg::WheelDefinition::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_WheelDefinition_is_active_driven(msg_);
  }

private:
  ::vda5050_msgs::msg::WheelDefinition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::WheelDefinition>()
{
  return vda5050_msgs::msg::builder::Init_WheelDefinition_type();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__WHEEL_DEFINITION__BUILDER_HPP_
