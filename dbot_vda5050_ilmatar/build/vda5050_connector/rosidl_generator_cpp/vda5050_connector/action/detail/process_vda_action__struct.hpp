// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vda5050_connector:action/ProcessVDAAction.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__ACTION__DETAIL__PROCESS_VDA_ACTION__STRUCT_HPP_
#define VDA5050_CONNECTOR__ACTION__DETAIL__PROCESS_VDA_ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'action'
#include "vda5050_msgs/msg/detail/action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_Goal __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_Goal __declspec(deprecated)
#endif

namespace vda5050_connector
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ProcessVDAAction_Goal_
{
  using Type = ProcessVDAAction_Goal_<ContainerAllocator>;

  explicit ProcessVDAAction_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : action(_init)
  {
    (void)_init;
  }

  explicit ProcessVDAAction_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : action(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _action_type =
    vda5050_msgs::msg::Action_<ContainerAllocator>;
  _action_type action;

  // setters for named parameter idiom
  Type & set__action(
    const vda5050_msgs::msg::Action_<ContainerAllocator> & _arg)
  {
    this->action = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_Goal
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_Goal
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessVDAAction_Goal_ & other) const
  {
    if (this->action != other.action) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessVDAAction_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessVDAAction_Goal_

// alias to use template instance with default allocator
using ProcessVDAAction_Goal =
  vda5050_connector::action::ProcessVDAAction_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace vda5050_connector


// Include directives for member types
// Member 'result'
#include "vda5050_msgs/msg/detail/current_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_Result __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_Result __declspec(deprecated)
#endif

namespace vda5050_connector
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ProcessVDAAction_Result_
{
  using Type = ProcessVDAAction_Result_<ContainerAllocator>;

  explicit ProcessVDAAction_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    (void)_init;
  }

  explicit ProcessVDAAction_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _result_type =
    vda5050_msgs::msg::CurrentAction_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const vda5050_msgs::msg::CurrentAction_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_Result
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_Result
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessVDAAction_Result_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessVDAAction_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessVDAAction_Result_

// alias to use template instance with default allocator
using ProcessVDAAction_Result =
  vda5050_connector::action::ProcessVDAAction_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace vda5050_connector


// Include directives for member types
// Member 'current_action'
// already included above
// #include "vda5050_msgs/msg/detail/current_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_Feedback __declspec(deprecated)
#endif

namespace vda5050_connector
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ProcessVDAAction_Feedback_
{
  using Type = ProcessVDAAction_Feedback_<ContainerAllocator>;

  explicit ProcessVDAAction_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_action(_init)
  {
    (void)_init;
  }

  explicit ProcessVDAAction_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_action(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _current_action_type =
    vda5050_msgs::msg::CurrentAction_<ContainerAllocator>;
  _current_action_type current_action;

  // setters for named parameter idiom
  Type & set__current_action(
    const vda5050_msgs::msg::CurrentAction_<ContainerAllocator> & _arg)
  {
    this->current_action = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_Feedback
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_Feedback
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessVDAAction_Feedback_ & other) const
  {
    if (this->current_action != other.current_action) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessVDAAction_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessVDAAction_Feedback_

// alias to use template instance with default allocator
using ProcessVDAAction_Feedback =
  vda5050_connector::action::ProcessVDAAction_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace vda5050_connector


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "vda5050_connector/action/detail/process_vda_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_SendGoal_Request __declspec(deprecated)
#endif

namespace vda5050_connector
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ProcessVDAAction_SendGoal_Request_
{
  using Type = ProcessVDAAction_SendGoal_Request_<ContainerAllocator>;

  explicit ProcessVDAAction_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit ProcessVDAAction_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const vda5050_connector::action::ProcessVDAAction_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_SendGoal_Request
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_SendGoal_Request
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessVDAAction_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessVDAAction_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessVDAAction_SendGoal_Request_

// alias to use template instance with default allocator
using ProcessVDAAction_SendGoal_Request =
  vda5050_connector::action::ProcessVDAAction_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace vda5050_connector


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_SendGoal_Response __declspec(deprecated)
#endif

namespace vda5050_connector
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ProcessVDAAction_SendGoal_Response_
{
  using Type = ProcessVDAAction_SendGoal_Response_<ContainerAllocator>;

  explicit ProcessVDAAction_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit ProcessVDAAction_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_SendGoal_Response
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_SendGoal_Response
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessVDAAction_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessVDAAction_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessVDAAction_SendGoal_Response_

// alias to use template instance with default allocator
using ProcessVDAAction_SendGoal_Response =
  vda5050_connector::action::ProcessVDAAction_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace vda5050_connector

namespace vda5050_connector
{

namespace action
{

struct ProcessVDAAction_SendGoal
{
  using Request = vda5050_connector::action::ProcessVDAAction_SendGoal_Request;
  using Response = vda5050_connector::action::ProcessVDAAction_SendGoal_Response;
};

}  // namespace action

}  // namespace vda5050_connector


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_GetResult_Request __declspec(deprecated)
#endif

namespace vda5050_connector
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ProcessVDAAction_GetResult_Request_
{
  using Type = ProcessVDAAction_GetResult_Request_<ContainerAllocator>;

  explicit ProcessVDAAction_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit ProcessVDAAction_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_GetResult_Request
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_GetResult_Request
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessVDAAction_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessVDAAction_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessVDAAction_GetResult_Request_

// alias to use template instance with default allocator
using ProcessVDAAction_GetResult_Request =
  vda5050_connector::action::ProcessVDAAction_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace vda5050_connector


// Include directives for member types
// Member 'result'
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_GetResult_Response __declspec(deprecated)
#endif

namespace vda5050_connector
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ProcessVDAAction_GetResult_Response_
{
  using Type = ProcessVDAAction_GetResult_Response_<ContainerAllocator>;

  explicit ProcessVDAAction_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit ProcessVDAAction_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const vda5050_connector::action::ProcessVDAAction_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_GetResult_Response
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_GetResult_Response
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessVDAAction_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessVDAAction_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessVDAAction_GetResult_Response_

// alias to use template instance with default allocator
using ProcessVDAAction_GetResult_Response =
  vda5050_connector::action::ProcessVDAAction_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace vda5050_connector

namespace vda5050_connector
{

namespace action
{

struct ProcessVDAAction_GetResult
{
  using Request = vda5050_connector::action::ProcessVDAAction_GetResult_Request;
  using Response = vda5050_connector::action::ProcessVDAAction_GetResult_Response;
};

}  // namespace action

}  // namespace vda5050_connector


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "vda5050_connector/action/detail/process_vda_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__vda5050_connector__action__ProcessVDAAction_FeedbackMessage __declspec(deprecated)
#endif

namespace vda5050_connector
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ProcessVDAAction_FeedbackMessage_
{
  using Type = ProcessVDAAction_FeedbackMessage_<ContainerAllocator>;

  explicit ProcessVDAAction_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit ProcessVDAAction_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const vda5050_connector::action::ProcessVDAAction_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_FeedbackMessage
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vda5050_connector__action__ProcessVDAAction_FeedbackMessage
    std::shared_ptr<vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessVDAAction_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessVDAAction_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessVDAAction_FeedbackMessage_

// alias to use template instance with default allocator
using ProcessVDAAction_FeedbackMessage =
  vda5050_connector::action::ProcessVDAAction_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace vda5050_connector

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace vda5050_connector
{

namespace action
{

struct ProcessVDAAction
{
  /// The goal message defined in the action definition.
  using Goal = vda5050_connector::action::ProcessVDAAction_Goal;
  /// The result message defined in the action definition.
  using Result = vda5050_connector::action::ProcessVDAAction_Result;
  /// The feedback message defined in the action definition.
  using Feedback = vda5050_connector::action::ProcessVDAAction_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = vda5050_connector::action::ProcessVDAAction_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = vda5050_connector::action::ProcessVDAAction_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = vda5050_connector::action::ProcessVDAAction_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct ProcessVDAAction ProcessVDAAction;

}  // namespace action

}  // namespace vda5050_connector

#endif  // VDA5050_CONNECTOR__ACTION__DETAIL__PROCESS_VDA_ACTION__STRUCT_HPP_
