// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_msgs:msg/BatteryState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__BUILDER_HPP_
#define VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_msgs/msg/detail/battery_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_msgs
{

namespace msg
{

namespace builder
{

class Init_BatteryState_reach
{
public:
  explicit Init_BatteryState_reach(::vda5050_msgs::msg::BatteryState & msg)
  : msg_(msg)
  {}
  ::vda5050_msgs::msg::BatteryState reach(::vda5050_msgs::msg::BatteryState::_reach_type arg)
  {
    msg_.reach = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_msgs::msg::BatteryState msg_;
};

class Init_BatteryState_charging
{
public:
  explicit Init_BatteryState_charging(::vda5050_msgs::msg::BatteryState & msg)
  : msg_(msg)
  {}
  Init_BatteryState_reach charging(::vda5050_msgs::msg::BatteryState::_charging_type arg)
  {
    msg_.charging = std::move(arg);
    return Init_BatteryState_reach(msg_);
  }

private:
  ::vda5050_msgs::msg::BatteryState msg_;
};

class Init_BatteryState_battery_health
{
public:
  explicit Init_BatteryState_battery_health(::vda5050_msgs::msg::BatteryState & msg)
  : msg_(msg)
  {}
  Init_BatteryState_charging battery_health(::vda5050_msgs::msg::BatteryState::_battery_health_type arg)
  {
    msg_.battery_health = std::move(arg);
    return Init_BatteryState_charging(msg_);
  }

private:
  ::vda5050_msgs::msg::BatteryState msg_;
};

class Init_BatteryState_battery_voltage
{
public:
  explicit Init_BatteryState_battery_voltage(::vda5050_msgs::msg::BatteryState & msg)
  : msg_(msg)
  {}
  Init_BatteryState_battery_health battery_voltage(::vda5050_msgs::msg::BatteryState::_battery_voltage_type arg)
  {
    msg_.battery_voltage = std::move(arg);
    return Init_BatteryState_battery_health(msg_);
  }

private:
  ::vda5050_msgs::msg::BatteryState msg_;
};

class Init_BatteryState_battery_charge
{
public:
  Init_BatteryState_battery_charge()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BatteryState_battery_voltage battery_charge(::vda5050_msgs::msg::BatteryState::_battery_charge_type arg)
  {
    msg_.battery_charge = std::move(arg);
    return Init_BatteryState_battery_voltage(msg_);
  }

private:
  ::vda5050_msgs::msg::BatteryState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_msgs::msg::BatteryState>()
{
  return vda5050_msgs::msg::builder::Init_BatteryState_battery_charge();
}

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__BUILDER_HPP_
