// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_msgs:msg/TypeSpecification.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__STRUCT_HPP_
#define VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vda5050_msgs__msg__TypeSpecification __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_msgs__msg__TypeSpecification __declspec(deprecated)
#endif

namespace vda5050_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TypeSpecification_
{
  using Type = TypeSpecification_<ContainerAllocator>;

  explicit TypeSpecification_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->series_name = "";
      this->series_description = "";
      this->agv_kinematic = "";
      this->agv_class = "";
      this->max_load_mass = 0.0;
    }
  }

  explicit TypeSpecification_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : series_name(_alloc),
    series_description(_alloc),
    agv_kinematic(_alloc),
    agv_class(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->series_name = "";
      this->series_description = "";
      this->agv_kinematic = "";
      this->agv_class = "";
      this->max_load_mass = 0.0;
    }
  }

  // field types and members
  using _series_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _series_name_type series_name;
  using _series_description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _series_description_type series_description;
  using _agv_kinematic_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _agv_kinematic_type agv_kinematic;
  using _agv_class_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _agv_class_type agv_class;
  using _max_load_mass_type =
    double;
  _max_load_mass_type max_load_mass;
  using _localization_types_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _localization_types_type localization_types;
  using _navigation_types_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _navigation_types_type navigation_types;

  // setters for named parameter idiom
  Type & set__series_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->series_name = _arg;
    return *this;
  }
  Type & set__series_description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->series_description = _arg;
    return *this;
  }
  Type & set__agv_kinematic(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->agv_kinematic = _arg;
    return *this;
  }
  Type & set__agv_class(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->agv_class = _arg;
    return *this;
  }
  Type & set__max_load_mass(
    const double & _arg)
  {
    this->max_load_mass = _arg;
    return *this;
  }
  Type & set__localization_types(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->localization_types = _arg;
    return *this;
  }
  Type & set__navigation_types(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->navigation_types = _arg;
    return *this;
  }

  // constant declarations
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> DIFF;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> OMNI;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> THREEWHEEL;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> FORKLIFT;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> CONVEYOR;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> TUGGER;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> CARRIER;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> NATURAL;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> REFLECTOR;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> RFID;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> DMC;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> SPOT;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> GRID;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> PHYSICAL_LINE_GUIDED;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> VIRTUAL_LINE_GUIDED;
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> AUTONOMOUS;

  // pointer types
  using RawPtr =
    vda5050_msgs::msg::TypeSpecification_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_msgs::msg::TypeSpecification_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_msgs::msg::TypeSpecification_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_msgs::msg::TypeSpecification_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::TypeSpecification_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::TypeSpecification_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_msgs::msg::TypeSpecification_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_msgs::msg::TypeSpecification_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_msgs::msg::TypeSpecification_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_msgs::msg::TypeSpecification_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_msgs__msg__TypeSpecification
    std::shared_ptr<vda5050_msgs::msg::TypeSpecification_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_msgs__msg__TypeSpecification
    std::shared_ptr<vda5050_msgs::msg::TypeSpecification_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TypeSpecification_ & other) const
  {
    if (this->series_name != other.series_name) {
      return false;
    }
    if (this->series_description != other.series_description) {
      return false;
    }
    if (this->agv_kinematic != other.agv_kinematic) {
      return false;
    }
    if (this->agv_class != other.agv_class) {
      return false;
    }
    if (this->max_load_mass != other.max_load_mass) {
      return false;
    }
    if (this->localization_types != other.localization_types) {
      return false;
    }
    if (this->navigation_types != other.navigation_types) {
      return false;
    }
    return true;
  }
  bool operator!=(const TypeSpecification_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TypeSpecification_

// alias to use template instance with default allocator
using TypeSpecification =
  vda5050_msgs::msg::TypeSpecification_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::DIFF = "DIFF";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::OMNI = "OMNI";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::THREEWHEEL = "THREEWHEEL";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::FORKLIFT = "FORKLIFT";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::CONVEYOR = "CONVEYOR";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::TUGGER = "TUGGER";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::CARRIER = "CARRIER";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::NATURAL = "NATURAL";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::REFLECTOR = "REFLECTOR";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::RFID = "RFID";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::DMC = "DMC";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::SPOT = "SPOT";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::GRID = "GRID";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::PHYSICAL_LINE_GUIDED = "PHYSICAL_LINE_GUIDED";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::VIRTUAL_LINE_GUIDED = "VIRTUAL_LINE_GUIDED";
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
TypeSpecification_<ContainerAllocator>::AUTONOMOUS = "AUTONOMOUS";

}  // namespace msg

}  // namespace vda5050_msgs

#endif  // VDA5050_MSGS__MSG__DETAIL__TYPE_SPECIFICATION__STRUCT_HPP_
