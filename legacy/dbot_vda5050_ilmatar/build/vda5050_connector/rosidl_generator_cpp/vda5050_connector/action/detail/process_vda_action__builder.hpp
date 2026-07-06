// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_connector:action/ProcessVDAAction.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__ACTION__DETAIL__PROCESS_VDA_ACTION__BUILDER_HPP_
#define VDA5050_CONNECTOR__ACTION__DETAIL__PROCESS_VDA_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_connector/action/detail/process_vda_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_ProcessVDAAction_Goal_action
{
public:
  Init_ProcessVDAAction_Goal_action()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vda5050_connector::action::ProcessVDAAction_Goal action(::vda5050_connector::action::ProcessVDAAction_Goal::_action_type arg)
  {
    msg_.action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::ProcessVDAAction_Goal>()
{
  return vda5050_connector::action::builder::Init_ProcessVDAAction_Goal_action();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_ProcessVDAAction_Result_result
{
public:
  Init_ProcessVDAAction_Result_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vda5050_connector::action::ProcessVDAAction_Result result(::vda5050_connector::action::ProcessVDAAction_Result::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::ProcessVDAAction_Result>()
{
  return vda5050_connector::action::builder::Init_ProcessVDAAction_Result_result();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_ProcessVDAAction_Feedback_current_action
{
public:
  Init_ProcessVDAAction_Feedback_current_action()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vda5050_connector::action::ProcessVDAAction_Feedback current_action(::vda5050_connector::action::ProcessVDAAction_Feedback::_current_action_type arg)
  {
    msg_.current_action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::ProcessVDAAction_Feedback>()
{
  return vda5050_connector::action::builder::Init_ProcessVDAAction_Feedback_current_action();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_ProcessVDAAction_SendGoal_Request_goal
{
public:
  explicit Init_ProcessVDAAction_SendGoal_Request_goal(::vda5050_connector::action::ProcessVDAAction_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::vda5050_connector::action::ProcessVDAAction_SendGoal_Request goal(::vda5050_connector::action::ProcessVDAAction_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_SendGoal_Request msg_;
};

class Init_ProcessVDAAction_SendGoal_Request_goal_id
{
public:
  Init_ProcessVDAAction_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcessVDAAction_SendGoal_Request_goal goal_id(::vda5050_connector::action::ProcessVDAAction_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ProcessVDAAction_SendGoal_Request_goal(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::ProcessVDAAction_SendGoal_Request>()
{
  return vda5050_connector::action::builder::Init_ProcessVDAAction_SendGoal_Request_goal_id();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_ProcessVDAAction_SendGoal_Response_stamp
{
public:
  explicit Init_ProcessVDAAction_SendGoal_Response_stamp(::vda5050_connector::action::ProcessVDAAction_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::vda5050_connector::action::ProcessVDAAction_SendGoal_Response stamp(::vda5050_connector::action::ProcessVDAAction_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_SendGoal_Response msg_;
};

class Init_ProcessVDAAction_SendGoal_Response_accepted
{
public:
  Init_ProcessVDAAction_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcessVDAAction_SendGoal_Response_stamp accepted(::vda5050_connector::action::ProcessVDAAction_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ProcessVDAAction_SendGoal_Response_stamp(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::ProcessVDAAction_SendGoal_Response>()
{
  return vda5050_connector::action::builder::Init_ProcessVDAAction_SendGoal_Response_accepted();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_ProcessVDAAction_GetResult_Request_goal_id
{
public:
  Init_ProcessVDAAction_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vda5050_connector::action::ProcessVDAAction_GetResult_Request goal_id(::vda5050_connector::action::ProcessVDAAction_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::ProcessVDAAction_GetResult_Request>()
{
  return vda5050_connector::action::builder::Init_ProcessVDAAction_GetResult_Request_goal_id();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_ProcessVDAAction_GetResult_Response_result
{
public:
  explicit Init_ProcessVDAAction_GetResult_Response_result(::vda5050_connector::action::ProcessVDAAction_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::vda5050_connector::action::ProcessVDAAction_GetResult_Response result(::vda5050_connector::action::ProcessVDAAction_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_GetResult_Response msg_;
};

class Init_ProcessVDAAction_GetResult_Response_status
{
public:
  Init_ProcessVDAAction_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcessVDAAction_GetResult_Response_result status(::vda5050_connector::action::ProcessVDAAction_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ProcessVDAAction_GetResult_Response_result(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::ProcessVDAAction_GetResult_Response>()
{
  return vda5050_connector::action::builder::Init_ProcessVDAAction_GetResult_Response_status();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_ProcessVDAAction_FeedbackMessage_feedback
{
public:
  explicit Init_ProcessVDAAction_FeedbackMessage_feedback(::vda5050_connector::action::ProcessVDAAction_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::vda5050_connector::action::ProcessVDAAction_FeedbackMessage feedback(::vda5050_connector::action::ProcessVDAAction_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_FeedbackMessage msg_;
};

class Init_ProcessVDAAction_FeedbackMessage_goal_id
{
public:
  Init_ProcessVDAAction_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcessVDAAction_FeedbackMessage_feedback goal_id(::vda5050_connector::action::ProcessVDAAction_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ProcessVDAAction_FeedbackMessage_feedback(msg_);
  }

private:
  ::vda5050_connector::action::ProcessVDAAction_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::ProcessVDAAction_FeedbackMessage>()
{
  return vda5050_connector::action::builder::Init_ProcessVDAAction_FeedbackMessage_goal_id();
}

}  // namespace vda5050_connector

#endif  // VDA5050_CONNECTOR__ACTION__DETAIL__PROCESS_VDA_ACTION__BUILDER_HPP_
