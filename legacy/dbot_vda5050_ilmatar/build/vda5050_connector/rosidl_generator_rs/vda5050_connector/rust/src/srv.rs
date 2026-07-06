#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to vda5050_connector__srv__GetState_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetState_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetState_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetState_Request {
  type RmwMsg = super::srv::rmw::GetState_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to vda5050_connector__srv__GetState_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetState_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub state: vda5050_msgs::msg::OrderState,

}



impl Default for GetState_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetState_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetState_Response {
  type RmwMsg = super::srv::rmw::GetState_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state: vda5050_msgs::msg::OrderState::into_rmw_message(std::borrow::Cow::Owned(msg.state)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        state: vda5050_msgs::msg::OrderState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.state)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      state: vda5050_msgs::msg::OrderState::from_rmw_message(msg.state),
    }
  }
}


// Corresponds to vda5050_connector__srv__SupportedActions_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SupportedActions_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for SupportedActions_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SupportedActions_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SupportedActions_Request {
  type RmwMsg = super::srv::rmw::SupportedActions_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to vda5050_connector__srv__SupportedActions_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SupportedActions_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub agv_actions: Vec<vda5050_msgs::msg::AGVAction>,

}



impl Default for SupportedActions_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SupportedActions_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SupportedActions_Response {
  type RmwMsg = super::srv::rmw::SupportedActions_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        agv_actions: msg.agv_actions
          .into_iter()
          .map(|elem| vda5050_msgs::msg::AGVAction::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        agv_actions: msg.agv_actions
          .iter()
          .map(|elem| vda5050_msgs::msg::AGVAction::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      agv_actions: msg.agv_actions
          .into_iter()
          .map(vda5050_msgs::msg::AGVAction::from_rmw_message)
          .collect(),
    }
  }
}






#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__srv__GetState() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__srv__GetState
#[allow(missing_docs, non_camel_case_types)]
pub struct GetState;

impl rosidl_runtime_rs::Service for GetState {
    type Request = GetState_Request;
    type Response = GetState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__srv__GetState() }
    }
}




#[link(name = "vda5050_connector__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__srv__SupportedActions() -> *const std::ffi::c_void;
}

// Corresponds to vda5050_connector__srv__SupportedActions
#[allow(missing_docs, non_camel_case_types)]
pub struct SupportedActions;

impl rosidl_runtime_rs::Service for SupportedActions {
    type Request = SupportedActions_Request;
    type Response = SupportedActions_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__vda5050_connector__srv__SupportedActions() }
    }
}


