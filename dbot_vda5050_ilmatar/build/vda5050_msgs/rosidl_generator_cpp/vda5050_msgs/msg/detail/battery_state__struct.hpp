// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/BatteryState.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__BatteryState __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__BatteryState __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BatteryState_
{
  using Type = BatteryState_<ContainerAllocator>;

  explicit BatteryState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery_charge = 0.0;
      this->battery_voltage = 0.0;
      this->battery_health = 0;
      this->charging = false;
      this->reach = 0ul;
    }
  }

  explicit BatteryState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery_charge = 0.0;
      this->battery_voltage = 0.0;
      this->battery_health = 0;
      this->charging = false;
      this->reach = 0ul;
    }
  }

  // field types and members
  using _battery_charge_type =
    double;
  _battery_charge_type battery_charge;
  using _battery_voltage_type =
    double;
  _battery_voltage_type battery_voltage;
  using _battery_health_type =
    int8_t;
  _battery_health_type battery_health;
  using _charging_type =
    bool;
  _charging_type charging;
  using _reach_type =
    uint32_t;
  _reach_type reach;

  // setters for named parameter idiom
  Type & set__battery_charge(
    const double & _arg)
  {
    this->battery_charge = _arg;
    return *this;
  }
  Type & set__battery_voltage(
    const double & _arg)
  {
    this->battery_voltage = _arg;
    return *this;
  }
  Type & set__battery_health(
    const int8_t & _arg)
  {
    this->battery_health = _arg;
    return *this;
  }
  Type & set__charging(
    const bool & _arg)
  {
    this->charging = _arg;
    return *this;
  }
  Type & set__reach(
    const uint32_t & _arg)
  {
    this->reach = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::BatteryState_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::BatteryState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::BatteryState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::BatteryState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::BatteryState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::BatteryState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::BatteryState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::BatteryState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::BatteryState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::BatteryState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__BatteryState
    std::shared_ptr<vda5050_msgs::msg::BatteryState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__BatteryState
    std::shared_ptr<vda5050_msgs::msg::BatteryState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BatteryState_ & other) const
  {
    if (this->battery_charge != other.battery_charge) {
      return false;
    }
    if (this->battery_voltage != other.battery_voltage) {
      return false;
    }
    if (this->battery_health != other.battery_health) {
      return false;
    }
    if (this->charging != other.charging) {
      return false;
    }
    if (this->reach != other.reach) {
      return false;
    }
    return true;
  }
  bool operator!=(const BatteryState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BatteryState_

// alias to use template instance with default allocator
using BatteryState =
  vda5050_msgs::msg::BatteryState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__BATTERY_STATE__STRUCT_HPP_
