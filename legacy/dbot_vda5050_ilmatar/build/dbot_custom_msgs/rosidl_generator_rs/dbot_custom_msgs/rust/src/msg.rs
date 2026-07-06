#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to dbot_custom_msgs__msg__WheelEncoder

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct WheelEncoder {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right: f64,

}



impl Default for WheelEncoder {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::WheelEncoder::default())
  }
}

impl rosidl_runtime_rs::Message for WheelEncoder {
  type RmwMsg = super::msg::rmw::WheelEncoder;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        left: msg.left,
        right: msg.right,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      left: msg.left,
      right: msg.right,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      left: msg.left,
      right: msg.right,
    }
  }
}


