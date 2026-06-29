// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_connector:srv/SupportedActions.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__BUILDER_HPP_
#define VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_connector/srv/detail/supported_actions__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_connector
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::srv::SupportedActions_Request>()
{
  return ::vda5050_connector::srv::SupportedActions_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace srv
{

namespace builder
{

class Init_SupportedActions_Response_agv_actions
{
public:
  Init_SupportedActions_Response_agv_actions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vda5050_connector::srv::SupportedActions_Response agv_actions(::vda5050_connector::srv::SupportedActions_Response::_agv_actions_type arg)
  {
    msg_.agv_actions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::srv::SupportedActions_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::srv::SupportedActions_Response>()
{
  return vda5050_connector::srv::builder::Init_SupportedActions_Response_agv_actions();
}

}  // namespace vda5050_connector

#endif  // VDA5050_CONNECTOR__SRV__DETAIL__SUPPORTED_ACTIONS__BUILDER_HPP_
