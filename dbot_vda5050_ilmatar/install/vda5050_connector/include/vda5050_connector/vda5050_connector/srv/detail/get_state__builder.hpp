// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_connector:srv/GetState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__SRV__DETAIL__GET_STATE__BUILDER_HPP_
#define VDA5050_CONNECTOR__SRV__DETAIL__GET_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_connector/srv/detail/get_state__struct.hpp"
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
auto build<::vda5050_connector::srv::GetState_Request>()
{
  return ::vda5050_connector::srv::GetState_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace srv
{

namespace builder
{

class Init_GetState_Response_state
{
public:
  Init_GetState_Response_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vda5050_connector::srv::GetState_Response state(::vda5050_connector::srv::GetState_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::srv::GetState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::srv::GetState_Response>()
{
  return vda5050_connector::srv::builder::Init_GetState_Response_state();
}

}  // namespace vda5050_connector

#endif  // VDA5050_CONNECTOR__SRV__DETAIL__GET_STATE__BUILDER_HPP_
