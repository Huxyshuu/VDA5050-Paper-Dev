// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/AGVAction.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/agv_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_AGVAction_result_description
{
public:
  explicit Init_AGVAction_result_description(::vda5050_msgs::msg::AGVAction & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::AGVAction result_description(::vda5050_msgs::msg::AGVAction::_result_description_type arg)
  {
    msg_.result_description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVAction msg_;
};

class Init_AGVAction_action_parameters
{
public:
  explicit Init_AGVAction_action_parameters(::vda5050_msgs::msg::AGVAction & msg)
  : msg_(msg)
  {}
  Init_AGVAction_result_description action_parameters(::vda5050_msgs::msg::AGVAction::_action_parameters_type arg)
  {
    msg_.action_parameters = std::move(arg);
    return Init_AGVAction_result_description(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVAction msg_;
};

class Init_AGVAction_action_scopes
{
public:
  explicit Init_AGVAction_action_scopes(::vda5050_msgs::msg::AGVAction & msg)
  : msg_(msg)
  {}
  Init_AGVAction_action_parameters action_scopes(::vda5050_msgs::msg::AGVAction::_action_scopes_type arg)
  {
    msg_.action_scopes = std::move(arg);
    return Init_AGVAction_action_parameters(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVAction msg_;
};

class Init_AGVAction_action_description
{
public:
  explicit Init_AGVAction_action_description(::vda5050_msgs::msg::AGVAction & msg)
  : msg_(msg)
  {}
  Init_AGVAction_action_scopes action_description(::vda5050_msgs::msg::AGVAction::_action_description_type arg)
  {
    msg_.action_description = std::move(arg);
    return Init_AGVAction_action_scopes(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVAction msg_;
};

class Init_AGVAction_action_type
{
public:
  Init_AGVAction_action_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AGVAction_action_description action_type(::vda5050_msgs::msg::AGVAction::_action_type_type arg)
  {
    msg_.action_type = std::move(arg);
    return Init_AGVAction_action_description(msg_);
  }

private:
  ::vda5050_msgs::msg::AGVAction msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::AGVAction>()
{
  return vda5050_msgs::msg::builder::Init_AGVAction_action_type();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__AGV_ACTION__BUILDER_HPP_
