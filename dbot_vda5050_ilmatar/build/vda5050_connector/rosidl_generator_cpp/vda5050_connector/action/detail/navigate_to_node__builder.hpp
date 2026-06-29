// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vda5050_connector:action/NavigateToNode.idl
// generated code does not contain a copyright notice

#ifndef VDA5050_CONNECTOR__ACTION__DETAIL__NAVIGATE_TO_NODE__BUILDER_HPP_
#define VDA5050_CONNECTOR__ACTION__DETAIL__NAVIGATE_TO_NODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vda5050_connector/action/detail/navigate_to_node__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_NavigateToNode_Goal_node
{
public:
  explicit Init_NavigateToNode_Goal_node(::vda5050_connector::action::NavigateToNode_Goal & msg)
  : msg_(msg)
  {}
  ::vda5050_connector::action::NavigateToNode_Goal node(::vda5050_connector::action::NavigateToNode_Goal::_node_type arg)
  {
    msg_.node = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_Goal msg_;
};

class Init_NavigateToNode_Goal_edge
{
public:
  Init_NavigateToNode_Goal_edge()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToNode_Goal_node edge(::vda5050_connector::action::NavigateToNode_Goal::_edge_type arg)
  {
    msg_.edge = std::move(arg);
    return Init_NavigateToNode_Goal_node(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::NavigateToNode_Goal>()
{
  return vda5050_connector::action::builder::Init_NavigateToNode_Goal_edge();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_NavigateToNode_Result_result
{
public:
  Init_NavigateToNode_Result_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vda5050_connector::action::NavigateToNode_Result result(::vda5050_connector::action::NavigateToNode_Result::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::NavigateToNode_Result>()
{
  return vda5050_connector::action::builder::Init_NavigateToNode_Result_result();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_NavigateToNode_Feedback_velocity
{
public:
  explicit Init_NavigateToNode_Feedback_velocity(::vda5050_connector::action::NavigateToNode_Feedback & msg)
  : msg_(msg)
  {}
  ::vda5050_connector::action::NavigateToNode_Feedback velocity(::vda5050_connector::action::NavigateToNode_Feedback::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_Feedback msg_;
};

class Init_NavigateToNode_Feedback_position
{
public:
  Init_NavigateToNode_Feedback_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToNode_Feedback_velocity position(::vda5050_connector::action::NavigateToNode_Feedback::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_NavigateToNode_Feedback_velocity(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::NavigateToNode_Feedback>()
{
  return vda5050_connector::action::builder::Init_NavigateToNode_Feedback_position();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_NavigateToNode_SendGoal_Request_goal
{
public:
  explicit Init_NavigateToNode_SendGoal_Request_goal(::vda5050_connector::action::NavigateToNode_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::vda5050_connector::action::NavigateToNode_SendGoal_Request goal(::vda5050_connector::action::NavigateToNode_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_SendGoal_Request msg_;
};

class Init_NavigateToNode_SendGoal_Request_goal_id
{
public:
  Init_NavigateToNode_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToNode_SendGoal_Request_goal goal_id(::vda5050_connector::action::NavigateToNode_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigateToNode_SendGoal_Request_goal(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::NavigateToNode_SendGoal_Request>()
{
  return vda5050_connector::action::builder::Init_NavigateToNode_SendGoal_Request_goal_id();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_NavigateToNode_SendGoal_Response_stamp
{
public:
  explicit Init_NavigateToNode_SendGoal_Response_stamp(::vda5050_connector::action::NavigateToNode_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::vda5050_connector::action::NavigateToNode_SendGoal_Response stamp(::vda5050_connector::action::NavigateToNode_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_SendGoal_Response msg_;
};

class Init_NavigateToNode_SendGoal_Response_accepted
{
public:
  Init_NavigateToNode_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToNode_SendGoal_Response_stamp accepted(::vda5050_connector::action::NavigateToNode_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_NavigateToNode_SendGoal_Response_stamp(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::NavigateToNode_SendGoal_Response>()
{
  return vda5050_connector::action::builder::Init_NavigateToNode_SendGoal_Response_accepted();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_NavigateToNode_GetResult_Request_goal_id
{
public:
  Init_NavigateToNode_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vda5050_connector::action::NavigateToNode_GetResult_Request goal_id(::vda5050_connector::action::NavigateToNode_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::NavigateToNode_GetResult_Request>()
{
  return vda5050_connector::action::builder::Init_NavigateToNode_GetResult_Request_goal_id();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_NavigateToNode_GetResult_Response_result
{
public:
  explicit Init_NavigateToNode_GetResult_Response_result(::vda5050_connector::action::NavigateToNode_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::vda5050_connector::action::NavigateToNode_GetResult_Response result(::vda5050_connector::action::NavigateToNode_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_GetResult_Response msg_;
};

class Init_NavigateToNode_GetResult_Response_status
{
public:
  Init_NavigateToNode_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToNode_GetResult_Response_result status(::vda5050_connector::action::NavigateToNode_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NavigateToNode_GetResult_Response_result(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::NavigateToNode_GetResult_Response>()
{
  return vda5050_connector::action::builder::Init_NavigateToNode_GetResult_Response_status();
}

}  // namespace vda5050_connector


namespace vda5050_connector
{

namespace action
{

namespace builder
{

class Init_NavigateToNode_FeedbackMessage_feedback
{
public:
  explicit Init_NavigateToNode_FeedbackMessage_feedback(::vda5050_connector::action::NavigateToNode_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::vda5050_connector::action::NavigateToNode_FeedbackMessage feedback(::vda5050_connector::action::NavigateToNode_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_FeedbackMessage msg_;
};

class Init_NavigateToNode_FeedbackMessage_goal_id
{
public:
  Init_NavigateToNode_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToNode_FeedbackMessage_feedback goal_id(::vda5050_connector::action::NavigateToNode_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigateToNode_FeedbackMessage_feedback(msg_);
  }

private:
  ::vda5050_connector::action::NavigateToNode_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::vda5050_connector::action::NavigateToNode_FeedbackMessage>()
{
  return vda5050_connector::action::builder::Init_NavigateToNode_FeedbackMessage_goal_id();
}

}  // namespace vda5050_connector

#endif  // VDA5050_CONNECTOR__ACTION__DETAIL__NAVIGATE_TO_NODE__BUILDER_HPP_
