// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/TypeSpecification.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/type_specification__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_TypeSpecification_navigation_types
{
public:
  explicit Init_TypeSpecification_navigation_types(::vda5050_msgs::msg::TypeSpecification & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::TypeSpecification navigation_types(::vda5050_msgs::msg::TypeSpecification::_navigation_types_type arg)
  {
    msg_.navigation_types = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::TypeSpecification msg_;
};

class Init_TypeSpecification_localization_types
{
public:
  explicit Init_TypeSpecification_localization_types(::vda5050_msgs::msg::TypeSpecification & msg)
  : msg_(msg)
  {}
  Init_TypeSpecification_navigation_types localization_types(::vda5050_msgs::msg::TypeSpecification::_localization_types_type arg)
  {
    msg_.localization_types = std::move(arg);
    return Init_TypeSpecification_navigation_types(msg_);
  }

private:
  ::vda5050_msgs::msg::TypeSpecification msg_;
};

class Init_TypeSpecification_max_load_mass
{
public:
  explicit Init_TypeSpecification_max_load_mass(::vda5050_msgs::msg::TypeSpecification & msg)
  : msg_(msg)
  {}
  Init_TypeSpecification_localization_types max_load_mass(::vda5050_msgs::msg::TypeSpecification::_max_load_mass_type arg)
  {
    msg_.max_load_mass = std::move(arg);
    return Init_TypeSpecification_localization_types(msg_);
  }

private:
  ::vda5050_msgs::msg::TypeSpecification msg_;
};

class Init_TypeSpecification_agv_class
{
public:
  explicit Init_TypeSpecification_agv_class(::vda5050_msgs::msg::TypeSpecification & msg)
  : msg_(msg)
  {}
  Init_TypeSpecification_max_load_mass agv_class(::vda5050_msgs::msg::TypeSpecification::_agv_class_type arg)
  {
    msg_.agv_class = std::move(arg);
    return Init_TypeSpecification_max_load_mass(msg_);
  }

private:
  ::vda5050_msgs::msg::TypeSpecification msg_;
};

class Init_TypeSpecification_agv_kinematic
{
public:
  explicit Init_TypeSpecification_agv_kinematic(::vda5050_msgs::msg::TypeSpecification & msg)
  : msg_(msg)
  {}
  Init_TypeSpecification_agv_class agv_kinematic(::vda5050_msgs::msg::TypeSpecification::_agv_kinematic_type arg)
  {
    msg_.agv_kinematic = std::move(arg);
    return Init_TypeSpecification_agv_class(msg_);
  }

private:
  ::vda5050_msgs::msg::TypeSpecification msg_;
};

class Init_TypeSpecification_series_description
{
public:
  explicit Init_TypeSpecification_series_description(::vda5050_msgs::msg::TypeSpecification & msg)
  : msg_(msg)
  {}
  Init_TypeSpecification_agv_kinematic series_description(::vda5050_msgs::msg::TypeSpecification::_series_description_type arg)
  {
    msg_.series_description = std::move(arg);
    return Init_TypeSpecification_agv_kinematic(msg_);
  }

private:
  ::vda5050_msgs::msg::TypeSpecification msg_;
};

class Init_TypeSpecification_series_name
{
public:
  Init_TypeSpecification_series_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TypeSpecification_series_description series_name(::vda5050_msgs::msg::TypeSpecification::_series_name_type arg)
  {
    msg_.series_name = std::move(arg);
    return Init_TypeSpecification_series_description(msg_);
  }

private:
  ::vda5050_msgs::msg::TypeSpecification msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::TypeSpecification>()
{
  return vda5050_msgs::msg::builder::Init_TypeSpecification_series_name();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__BUILDER_HPP_
