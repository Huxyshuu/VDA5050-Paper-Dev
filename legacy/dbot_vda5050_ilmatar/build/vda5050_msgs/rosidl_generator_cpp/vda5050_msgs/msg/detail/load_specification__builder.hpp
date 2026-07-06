// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/LoadSpecification.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/load_specification__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_LoadSpecification_load_sets
{
public:
  explicit Init_LoadSpecification_load_sets(::vda5050_msgs::msg::LoadSpecification & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::LoadSpecification load_sets(::vda5050_msgs::msg::LoadSpecification::_load_sets_type arg)
  {
    msg_.load_sets = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSpecification msg_;
};

class Init_LoadSpecification_load_positions
{
public:
  Init_LoadSpecification_load_positions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadSpecification_load_sets load_positions(::vda5050_msgs::msg::LoadSpecification::_load_positions_type arg)
  {
    msg_.load_positions = std::move(arg);
    return Init_LoadSpecification_load_sets(msg_);
  }

private:
  ::vda5050_msgs::msg::LoadSpecification msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::LoadSpecification>()
{
  return vda5050_msgs::msg::builder::Init_LoadSpecification_load_positions();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__LOAD_SPECIFICATION__BUILDER_HPP_
