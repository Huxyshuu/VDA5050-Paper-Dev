// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/CurrentAction.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/current_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_CurrentAction_result_description
{
public:
  explicit Init_CurrentAction_result_description(::vda5050_msgs::msg::CurrentAction & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::CurrentAction result_description(::vda5050_msgs::msg::CurrentAction::_result_description_type arg)
  {
    msg_.result_description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::CurrentAction msg_;
};

class Init_CurrentAction_action_status
{
public:
  explicit Init_CurrentAction_action_status(::vda5050_msgs::msg::CurrentAction & msg)
  : msg_(msg)
  {}
  Init_CurrentAction_result_description action_status(::vda5050_msgs::msg::CurrentAction::_action_status_type arg)
  {
    msg_.action_status = std::move(arg);
    return Init_CurrentAction_result_description(msg_);
  }

private:
  ::vda5050_msgs::msg::CurrentAction msg_;
};

class Init_CurrentAction_action_description
{
public:
  explicit Init_CurrentAction_action_description(::vda5050_msgs::msg::CurrentAction & msg)
  : msg_(msg)
  {}
  Init_CurrentAction_action_status action_description(::vda5050_msgs::msg::CurrentAction::_action_description_type arg)
  {
    msg_.action_description = std::move(arg);
    return Init_CurrentAction_action_status(msg_);
  }

private:
  ::vda5050_msgs::msg::CurrentAction msg_;
};

class Init_CurrentAction_action_type
{
public:
  explicit Init_CurrentAction_action_type(::vda5050_msgs::msg::CurrentAction & msg)
  : msg_(msg)
  {}
  Init_CurrentAction_action_description action_type(::vda5050_msgs::msg::CurrentAction::_action_type_type arg)
  {
    msg_.action_type = std::move(arg);
    return Init_CurrentAction_action_description(msg_);
  }

private:
  ::vda5050_msgs::msg::CurrentAction msg_;
};

class Init_CurrentAction_action_id
{
public:
  Init_CurrentAction_action_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CurrentAction_action_type action_id(::vda5050_msgs::msg::CurrentAction::_action_id_type arg)
  {
    msg_.action_id = std::move(arg);
    return Init_CurrentAction_action_type(msg_);
  }

private:
  ::vda5050_msgs::msg::CurrentAction msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::CurrentAction>()
{
  return vda5050_msgs::msg::builder::Init_CurrentAction_action_id();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__CURRENT_ACTION__BUILDER_HPP_
