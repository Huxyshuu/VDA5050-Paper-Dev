// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/Action.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__ACTION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_Action_action_parameters
{
public:
  explicit Init_Action_action_parameters(::vda5050_msgs::msg::Action & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::Action action_parameters(::vda5050_msgs::msg::Action::_action_parameters_type arg)
  {
    msg_.action_parameters = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::Action msg_;
};

class Init_Action_blocking_type
{
public:
  explicit Init_Action_blocking_type(::vda5050_msgs::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_action_parameters blocking_type(::vda5050_msgs::msg::Action::_blocking_type_type arg)
  {
    msg_.blocking_type = std::move(arg);
    return Init_Action_action_parameters(msg_);
  }

private:
  ::vda5050_msgs::msg::Action msg_;
};

class Init_Action_action_description
{
public:
  explicit Init_Action_action_description(::vda5050_msgs::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_blocking_type action_description(::vda5050_msgs::msg::Action::_action_description_type arg)
  {
    msg_.action_description = std::move(arg);
    return Init_Action_blocking_type(msg_);
  }

private:
  ::vda5050_msgs::msg::Action msg_;
};

class Init_Action_action_id
{
public:
  explicit Init_Action_action_id(::vda5050_msgs::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_action_description action_id(::vda5050_msgs::msg::Action::_action_id_type arg)
  {
    msg_.action_id = std::move(arg);
    return Init_Action_action_description(msg_);
  }

private:
  ::vda5050_msgs::msg::Action msg_;
};

class Init_Action_action_type
{
public:
  Init_Action_action_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Action_action_id action_type(::vda5050_msgs::msg::Action::_action_type_type arg)
  {
    msg_.action_type = std::move(arg);
    return Init_Action_action_id(msg_);
  }

private:
  ::vda5050_msgs::msg::Action msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::Action>()
{
  return vda5050_msgs::msg::builder::Init_Action_action_type();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__ACTION__BUILDER_HPP_
