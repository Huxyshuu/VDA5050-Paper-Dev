
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to vda5050_connector__action__NavigateToNode_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub edge: vda5050_msgs::msg::Edge,


    // This member is not documented.
    #[allow(missing_docs)]
    pub node: vda5050_msgs::msg::Node,

}



impl Default for NavigateToNode_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::NavigateToNode_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_Goal {
  type RmwMsg = super::action::rmw::NavigateToNode_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        edge: vda5050_msgs::msg::Edge::into_rmw_message(std::borrow::Cow::Owned(msg.edge)).into_owned(),
        node: vda5050_msgs::msg::Node::into_rmw_message(std::borrow::Cow::Owned(msg.node)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        edge: vda5050_msgs::msg::Edge::into_rmw_message(std::borrow::Cow::Borrowed(&msg.edge)).into_owned(),
        node: vda5050_msgs::msg::Node::into_rmw_message(std::borrow::Cow::Borrowed(&msg.node)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      edge: vda5050_msgs::msg::Edge::from_rmw_message(msg.edge),
      node: vda5050_msgs::msg::Node::from_rmw_message(msg.node),
    }
  }
}


// Corresponds to vda5050_connector__action__NavigateToNode_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: std_msgs::msg::Empty,

}



impl Default for NavigateToNode_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::NavigateToNode_Result::default())
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_Result {
  type RmwMsg = super::action::rmw::NavigateToNode_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: std_msgs::msg::Empty::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: std_msgs::msg::Empty::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      result: std_msgs::msg::Empty::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to vda5050_connector__action__NavigateToNode_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub position: vda5050_msgs::msg::AGVPosition,


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity: vda5050_msgs::msg::Velocity,

}



impl Default for NavigateToNode_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::NavigateToNode_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_Feedback {
  type RmwMsg = super::action::rmw::NavigateToNode_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        position: vda5050_msgs::msg::AGVPosition::into_rmw_message(std::borrow::Cow::Owned(msg.position)).into_owned(),
        velocity: vda5050_msgs::msg::Velocity::into_rmw_message(std::borrow::Cow::Owned(msg.velocity)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        position: vda5050_msgs::msg::AGVPosition::into_rmw_message(std::borrow::Cow::Borrowed(&msg.position)).into_owned(),
        velocity: vda5050_msgs::msg::Velocity::into_rmw_message(std::borrow::Cow::Borrowed(&msg.velocity)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      position: vda5050_msgs::msg::AGVPosition::from_rmw_message(msg.position),
      velocity: vda5050_msgs::msg::Velocity::from_rmw_message(msg.velocity),
    }
  }
}


// Corresponds to vda5050_connector__action__NavigateToNode_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::NavigateToNode_Feedback,

}



impl Default for NavigateToNode_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::NavigateToNode_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_FeedbackMessage {
  type RmwMsg = super::action::rmw::NavigateToNode_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::NavigateToNode_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::NavigateToNode_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::NavigateToNode_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


// Corresponds to vda5050_connector__action__ProcessVDAAction_Goal

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_Goal {

    // This member is not documented.
    #[allow(missing_docs)]
    pub action: vda5050_msgs::msg::Action,

}



impl Default for ProcessVDAAction_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ProcessVDAAction_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_Goal {
  type RmwMsg = super::action::rmw::ProcessVDAAction_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        action: vda5050_msgs::msg::Action::into_rmw_message(std::borrow::Cow::Owned(msg.action)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        action: vda5050_msgs::msg::Action::into_rmw_message(std::borrow::Cow::Borrowed(&msg.action)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      action: vda5050_msgs::msg::Action::from_rmw_message(msg.action),
    }
  }
}


// Corresponds to vda5050_connector__action__ProcessVDAAction_Result

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: vda5050_msgs::msg::CurrentAction,

}



impl Default for ProcessVDAAction_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ProcessVDAAction_Result::default())
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_Result {
  type RmwMsg = super::action::rmw::ProcessVDAAction_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: vda5050_msgs::msg::CurrentAction::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: vda5050_msgs::msg::CurrentAction::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      result: vda5050_msgs::msg::CurrentAction::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to vda5050_connector__action__ProcessVDAAction_Feedback

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub current_action: vda5050_msgs::msg::CurrentAction,

}



impl Default for ProcessVDAAction_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ProcessVDAAction_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_Feedback {
  type RmwMsg = super::action::rmw::ProcessVDAAction_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        current_action: vda5050_msgs::msg::CurrentAction::into_rmw_message(std::borrow::Cow::Owned(msg.current_action)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        current_action: vda5050_msgs::msg::CurrentAction::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_action)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      current_action: vda5050_msgs::msg::CurrentAction::from_rmw_message(msg.current_action),
    }
  }
}


// Corresponds to vda5050_connector__action__ProcessVDAAction_FeedbackMessage

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::action::ProcessVDAAction_Feedback,

}



impl Default for ProcessVDAAction_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ProcessVDAAction_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_FeedbackMessage {
  type RmwMsg = super::action::rmw::ProcessVDAAction_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: super::action::ProcessVDAAction_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: super::action::ProcessVDAAction_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: super::action::ProcessVDAAction_Feedback::from_rmw_message(msg.feedback),
    }
  }
}






// Corresponds to vda5050_connector__action__NavigateToNode_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::NavigateToNode_Goal,

}



impl Default for NavigateToNode_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::NavigateToNode_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_SendGoal_Request {
  type RmwMsg = super::action::rmw::NavigateToNode_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::NavigateToNode_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::NavigateToNode_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::NavigateToNode_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to vda5050_connector__action__NavigateToNode_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for NavigateToNode_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::NavigateToNode_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_SendGoal_Response {
  type RmwMsg = super::action::rmw::NavigateToNode_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to vda5050_connector__action__NavigateToNode_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for NavigateToNode_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::NavigateToNode_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_GetResult_Request {
  type RmwMsg = super::action::rmw::NavigateToNode_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to vda5050_connector__action__NavigateToNode_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigateToNode_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::NavigateToNode_Result,

}



impl Default for NavigateToNode_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::NavigateToNode_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for NavigateToNode_GetResult_Response {
  type RmwMsg = super::action::rmw::NavigateToNode_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::NavigateToNode_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::NavigateToNode_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::NavigateToNode_Result::from_rmw_message(msg.result),
    }
  }
}


// Corresponds to vda5050_connector__action__ProcessVDAAction_SendGoal_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::action::ProcessVDAAction_Goal,

}



impl Default for ProcessVDAAction_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ProcessVDAAction_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_SendGoal_Request {
  type RmwMsg = super::action::rmw::ProcessVDAAction_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: super::action::ProcessVDAAction_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: super::action::ProcessVDAAction_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: super::action::ProcessVDAAction_Goal::from_rmw_message(msg.goal),
    }
  }
}


// Corresponds to vda5050_connector__action__ProcessVDAAction_SendGoal_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::Time,

}



impl Default for ProcessVDAAction_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ProcessVDAAction_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_SendGoal_Response {
  type RmwMsg = super::action::rmw::ProcessVDAAction_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


// Corresponds to vda5050_connector__action__ProcessVDAAction_GetResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::UUID,

}



impl Default for ProcessVDAAction_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ProcessVDAAction_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_GetResult_Request {
  type RmwMsg = super::action::rmw::ProcessVDAAction_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


// Corresponds to vda5050_connector__action__ProcessVDAAction_GetResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProcessVDAAction_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::action::ProcessVDAAction_Result,

}



impl Default for ProcessVDAAction_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::action::rmw::ProcessVDAAction_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ProcessVDAAction_GetResult_Response {
  type RmwMsg = super::action::rmw::ProcessVDAAction_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: super::action::ProcessVDAAction_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: super::action::ProcessVDAAction_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: super::action::ProcessVDAAction_Result::from_rmw_message(msg.result),
    }
  }
}






#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__NavigateToNode_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__action__NavigateToNode_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct NavigateToNode_SendGoal;

impl rosidl_runtime_rs::Service for NavigateToNode_SendGoal {
    type Request = NavigateToNode_SendGoal_Request;
    type Response = NavigateToNode_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__NavigateToNode_SendGoal() }
    }
}




#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__NavigateToNode_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__action__NavigateToNode_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct NavigateToNode_GetResult;

impl rosidl_runtime_rs::Service for NavigateToNode_GetResult {
    type Request = NavigateToNode_GetResult_Request;
    type Response = NavigateToNode_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__NavigateToNode_GetResult() }
    }
}




#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__ProcessVDAAction_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct ProcessVDAAction_SendGoal;

impl rosidl_runtime_rs::Service for ProcessVDAAction_SendGoal {
    type Request = ProcessVDAAction_SendGoal_Request;
    type Response = ProcessVDAAction_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__ProcessVDAAction_SendGoal() }
    }
}




#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__ProcessVDAAction_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct ProcessVDAAction_GetResult;

impl rosidl_runtime_rs::Service for ProcessVDAAction_GetResult {
    type Request = ProcessVDAAction_GetResult_Request;
    type Response = ProcessVDAAction_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__action__ProcessVDAAction_GetResult() }
    }
}






#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__vda5050_connector__action__NavigateToNode() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__action__NavigateToNode
#[allow(missing_docs, non_camel_case_types)]
pub struct NavigateToNode;

impl rosidl_runtime_rs::Action for NavigateToNode {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = NavigateToNode_Goal;

  /// The result message defined in the action definition.
  type Result = NavigateToNode_Result;

  /// The feedback message defined in the action definition.
  type Feedback = NavigateToNode_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::NavigateToNode_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::NavigateToNode_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::NavigateToNode_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__vda5050_connector__action__NavigateToNode() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::NavigateToNode_Goal,
  ) -> super::action::rmw::NavigateToNode_SendGoal_Request {
   super::action::rmw::NavigateToNode_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::NavigateToNode_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::NavigateToNode_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::NavigateToNode_SendGoal_Response {
   super::action::rmw::NavigateToNode_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::NavigateToNode_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::NavigateToNode_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::NavigateToNode_Feedback,
  ) -> super::action::rmw::NavigateToNode_FeedbackMessage {
    let mut message = super::action::rmw::NavigateToNode_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::NavigateToNode_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::NavigateToNode_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::NavigateToNode_GetResult_Request {
   super::action::rmw::NavigateToNode_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::NavigateToNode_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::NavigateToNode_Result,
  ) -> super::action::rmw::NavigateToNode_GetResult_Response {
   super::action::rmw::NavigateToNode_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::NavigateToNode_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::NavigateToNode_Result,
  ) {
    (response.status, response.result)
  }
}




#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__vda5050_connector__action__ProcessVDAAction() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__action__ProcessVDAAction
#[allow(missing_docs, non_camel_case_types)]
pub struct ProcessVDAAction;

impl rosidl_runtime_rs::Action for ProcessVDAAction {
  // --- Associated types for client library users ---
  /// The goal message defined in the action definition.
  type Goal = ProcessVDAAction_Goal;

  /// The result message defined in the action definition.
  type Result = ProcessVDAAction_Result;

  /// The feedback message defined in the action definition.
  type Feedback = ProcessVDAAction_Feedback;

  // --- Associated types for client library implementation ---
  /// The feedback message with generic fields which wraps the feedback message.
  type FeedbackMessage = super::action::ProcessVDAAction_FeedbackMessage;

  /// The send_goal service using a wrapped version of the goal message as a request.
  type SendGoalService = super::action::ProcessVDAAction_SendGoal;

  /// The generic service to cancel a goal.
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;

  /// The get_result service using a wrapped version of the result message as a response.
  type GetResultService = super::action::ProcessVDAAction_GetResult;

  // --- Methods for client library implementation ---
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__vda5050_connector__action__ProcessVDAAction() }
  }

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: super::action::rmw::ProcessVDAAction_Goal,
  ) -> super::action::rmw::ProcessVDAAction_SendGoal_Request {
   super::action::rmw::ProcessVDAAction_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn split_goal_request(
    request: super::action::rmw::ProcessVDAAction_SendGoal_Request,
  ) -> (
    [u8; 16],
   super::action::rmw::ProcessVDAAction_Goal,
  ) {
    (request.goal_id.uuid, request.goal)
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> super::action::rmw::ProcessVDAAction_SendGoal_Response {
   super::action::rmw::ProcessVDAAction_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &super::action::rmw::ProcessVDAAction_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &super::action::rmw::ProcessVDAAction_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: super::action::rmw::ProcessVDAAction_Feedback,
  ) -> super::action::rmw::ProcessVDAAction_FeedbackMessage {
    let mut message = super::action::rmw::ProcessVDAAction_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn split_feedback_message(
    feedback: super::action::rmw::ProcessVDAAction_FeedbackMessage,
  ) -> (
    [u8; 16],
   super::action::rmw::ProcessVDAAction_Feedback,
  ) {
    (feedback.goal_id.uuid, feedback.feedback)
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> super::action::rmw::ProcessVDAAction_GetResult_Request {
   super::action::rmw::ProcessVDAAction_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &super::action::rmw::ProcessVDAAction_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: super::action::rmw::ProcessVDAAction_Result,
  ) -> super::action::rmw::ProcessVDAAction_GetResult_Response {
   super::action::rmw::ProcessVDAAction_GetResult_Response {
      status,
      result,
    }
  }

  fn split_result_response(
    response: super::action::rmw::ProcessVDAAction_GetResult_Response
  ) -> (
    i8,
   super::action::rmw::ProcessVDAAction_Result,
  ) {
    (response.status, response.result)
  }
}


