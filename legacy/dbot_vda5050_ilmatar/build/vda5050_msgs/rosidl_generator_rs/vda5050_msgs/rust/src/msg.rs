#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to vda5050_msgs__msg__Action
/// Action the AGV can perform.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action {
    /// Name of action as described in the first column
    /// of "Actions and Parameters".
    /// Identifies the function of the action.
    pub action_type: std::string::String,

    /// Unique ID to identify the action and map them to
    /// the actionState in the state.
    /// Suggestion: Use UUIDs.
    pub action_id: std::string::String,

    /// Additional information on the action
    pub action_description: std::string::String,

    /// Enum {NONE, SOFT, HARD}
    /// “NONE” – allows driving and other actions
    /// “SOFT” - allows other actions, but not driving
    /// “HARD” - is the only allowd action at that time
    pub blocking_type: std::string::String,

    /// Array of actionParameter objects for the indicated
    /// action e. g. deviceId, loadId, external Triggers.
    /// See “Actions and Parameters”.
    ///
    /// Note on Porting to ROS:
    /// Since those parameter vary in type but their
    /// serialization is always a json dictionary with "key"
    /// and "value" we decided to serialize the value as
    /// string. This way the (de-)serialization has to be done by
    /// the user depending on the key, but the protocol is met
    pub action_parameters: Vec<super::msg::ActionParameter>,

}

impl Action {
    /// Enums for blockingType
    pub const NONE: &'static str = "NONE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SOFT: &'static str = "SOFT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const HARD: &'static str = "HARD";

}


impl Default for Action {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Action::default())
  }
}

impl rosidl_runtime_rs::Message for Action {
  type RmwMsg = super::msg::rmw::Action;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        action_type: msg.action_type.as_str().into(),
        action_id: msg.action_id.as_str().into(),
        action_description: msg.action_description.as_str().into(),
        blocking_type: msg.blocking_type.as_str().into(),
        action_parameters: msg.action_parameters
          .into_iter()
          .map(|elem| super::msg::ActionParameter::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        action_type: msg.action_type.as_str().into(),
        action_id: msg.action_id.as_str().into(),
        action_description: msg.action_description.as_str().into(),
        blocking_type: msg.blocking_type.as_str().into(),
        action_parameters: msg.action_parameters
          .iter()
          .map(|elem| super::msg::ActionParameter::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      action_type: msg.action_type.to_string(),
      action_id: msg.action_id.to_string(),
      action_description: msg.action_description.to_string(),
      blocking_type: msg.blocking_type.to_string(),
      action_parameters: msg.action_parameters
          .into_iter()
          .map(super::msg::ActionParameter::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__ActionParameter

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ActionParameter {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value: std::string::String,

}



impl Default for ActionParameter {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ActionParameter::default())
  }
}

impl rosidl_runtime_rs::Message for ActionParameter {
  type RmwMsg = super::msg::rmw::ActionParameter;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key: msg.key.as_str().into(),
        value: msg.value.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key: msg.key.as_str().into(),
        value: msg.value.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      key: msg.key.to_string(),
      value: msg.value.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__ActionParameterDefinition

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ActionParameterDefinition {

    // This member is not documented.
    #[allow(missing_docs)]
    pub key: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value_data_type: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub description: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_optional: bool,

}

impl ActionParameterDefinition {
    /// Enums for valueDataType
    pub const BOOL: &'static str = "BOOL";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NUMBER: &'static str = "NUMBER";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INTEGER: &'static str = "INTEGER";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FLOAT: &'static str = "FLOAT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const STRING: &'static str = "STRING";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const OBJECT: &'static str = "OBJECT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ARRAY: &'static str = "ARRAY";

}


impl Default for ActionParameterDefinition {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ActionParameterDefinition::default())
  }
}

impl rosidl_runtime_rs::Message for ActionParameterDefinition {
  type RmwMsg = super::msg::rmw::ActionParameterDefinition;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key: msg.key.as_str().into(),
        value_data_type: msg.value_data_type.as_str().into(),
        description: msg.description.as_str().into(),
        is_optional: msg.is_optional,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        key: msg.key.as_str().into(),
        value_data_type: msg.value_data_type.as_str().into(),
        description: msg.description.as_str().into(),
      is_optional: msg.is_optional,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      key: msg.key.to_string(),
      value_data_type: msg.value_data_type.to_string(),
      description: msg.description.to_string(),
      is_optional: msg.is_optional,
    }
  }
}


// Corresponds to vda5050_msgs__msg__AGVAction

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AGVAction {
    /// Unique actionType corresponding to action.actionType
    pub action_type: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub action_description: std::string::String,

    /// Allowed scopes for using this action-type
    pub action_scopes: Vec<std::string::String>,

    /// List of parameters defined for the action
    pub action_parameters: Vec<super::msg::ActionParameterDefinition>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result_description: std::string::String,

}

impl AGVAction {
    /// Enums for action scopes
    pub const INSTANT: &'static str = "INSTANT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NODE: &'static str = "NODE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const EDGE: &'static str = "EDGE";

}


impl Default for AGVAction {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::AGVAction::default())
  }
}

impl rosidl_runtime_rs::Message for AGVAction {
  type RmwMsg = super::msg::rmw::AGVAction;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        action_type: msg.action_type.as_str().into(),
        action_description: msg.action_description.as_str().into(),
        action_scopes: msg.action_scopes
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        action_parameters: msg.action_parameters
          .into_iter()
          .map(|elem| super::msg::ActionParameterDefinition::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        result_description: msg.result_description.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        action_type: msg.action_type.as_str().into(),
        action_description: msg.action_description.as_str().into(),
        action_scopes: msg.action_scopes
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        action_parameters: msg.action_parameters
          .iter()
          .map(|elem| super::msg::ActionParameterDefinition::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        result_description: msg.result_description.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      action_type: msg.action_type.to_string(),
      action_description: msg.action_description.to_string(),
      action_scopes: msg.action_scopes
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      action_parameters: msg.action_parameters
          .into_iter()
          .map(super::msg::ActionParameterDefinition::from_rmw_message)
          .collect(),
      result_description: msg.result_description.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__AGVGeometry

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AGVGeometry {
    /// List of wheels, containing wheel-arrangement and geometry
    pub wheel_definitions: Vec<super::msg::WheelDefinition>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub envelopes2d: Vec<super::msg::Envelope2D>,

    /// List of AGV-envelope curves in 3D
    pub envelopes3d: Vec<super::msg::Envelope3D>,

}



impl Default for AGVGeometry {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::AGVGeometry::default())
  }
}

impl rosidl_runtime_rs::Message for AGVGeometry {
  type RmwMsg = super::msg::rmw::AGVGeometry;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        wheel_definitions: msg.wheel_definitions
          .into_iter()
          .map(|elem| super::msg::WheelDefinition::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        envelopes2d: msg.envelopes2d
          .into_iter()
          .map(|elem| super::msg::Envelope2D::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        envelopes3d: msg.envelopes3d
          .into_iter()
          .map(|elem| super::msg::Envelope3D::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        wheel_definitions: msg.wheel_definitions
          .iter()
          .map(|elem| super::msg::WheelDefinition::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        envelopes2d: msg.envelopes2d
          .iter()
          .map(|elem| super::msg::Envelope2D::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        envelopes3d: msg.envelopes3d
          .iter()
          .map(|elem| super::msg::Envelope3D::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      wheel_definitions: msg.wheel_definitions
          .into_iter()
          .map(super::msg::WheelDefinition::from_rmw_message)
          .collect(),
      envelopes2d: msg.envelopes2d
          .into_iter()
          .map(super::msg::Envelope2D::from_rmw_message)
          .collect(),
      envelopes3d: msg.envelopes3d
          .into_iter()
          .map(super::msg::Envelope3D::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__AGVPosition
/// Defines the position on a map in world coordinates. Each floor has its own map.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct AGVPosition {
    /// False: position is not initialized True: position is initialized
    pub position_initialized: bool,

    /// Range: Describes the quality of the localization and therefore, can be used
    /// e. g. by SLAMAGVs to describe how accurate the current position information is.
    /// 0.0: position unknown 1.0: position known
    pub localization_score: f64,

    /// Value for the deviation range of the position in meters.
    pub deviation_range: f64,

    /// X-position on the map in reference to the map coordinate system. Precision is up to
    /// the specific implementation
    pub x: f64,

    /// Y-position on the map in reference to the map coordinate system. Precision is up to
    /// the specific implementation.
    pub y: f64,

    /// [rad] Range: [-Pi … Pi] Orientation of the AGV.
    pub theta: f64,

    /// Unique identification of the map in which the position is referenced. Each map has the
    /// same origin of coordinates. When an AGV uses an elevator, e. g. leading from a departure
    /// floor to a target floor, it will disappear off the map of the departure floor and spawn
    /// in the related lift node on the map of the target floor.
    pub map_id: std::string::String,

    /// Additional information on the map.
    pub map_description: std::string::String,

}



impl Default for AGVPosition {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::AGVPosition::default())
  }
}

impl rosidl_runtime_rs::Message for AGVPosition {
  type RmwMsg = super::msg::rmw::AGVPosition;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        position_initialized: msg.position_initialized,
        localization_score: msg.localization_score,
        deviation_range: msg.deviation_range,
        x: msg.x,
        y: msg.y,
        theta: msg.theta,
        map_id: msg.map_id.as_str().into(),
        map_description: msg.map_description.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      position_initialized: msg.position_initialized,
      localization_score: msg.localization_score,
      deviation_range: msg.deviation_range,
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
        map_id: msg.map_id.as_str().into(),
        map_description: msg.map_description.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      position_initialized: msg.position_initialized,
      localization_score: msg.localization_score,
      deviation_range: msg.deviation_range,
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
      map_id: msg.map_id.to_string(),
      map_description: msg.map_description.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__BatteryState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BatteryState {
    /// State of Charge: if AGV only provides values for good or bad battery levels, these will
    /// be indicated as 20% (bad) and 80% (good).
    pub battery_charge: f64,

    /// Battery Voltage
    pub battery_voltage: f64,

    /// State of Health
    pub battery_health: i8,

    /// True: charging in progress False: AGV is currently not charging
    pub charging: bool,

    /// Estimated reach with current SoC
    pub reach: u32,

}



impl Default for BatteryState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::BatteryState::default())
  }
}

impl rosidl_runtime_rs::Message for BatteryState {
  type RmwMsg = super::msg::rmw::BatteryState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        battery_charge: msg.battery_charge,
        battery_voltage: msg.battery_voltage,
        battery_health: msg.battery_health,
        charging: msg.charging,
        reach: msg.reach,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      battery_charge: msg.battery_charge,
      battery_voltage: msg.battery_voltage,
      battery_health: msg.battery_health,
      charging: msg.charging,
      reach: msg.reach,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      battery_charge: msg.battery_charge,
      battery_voltage: msg.battery_voltage,
      battery_health: msg.battery_health,
      charging: msg.charging,
      reach: msg.reach,
    }
  }
}


// Corresponds to vda5050_msgs__msg__BoundingBoxReference
/// Point of reference for the location of the bounding box. The point of reference is always the center of the bounding
/// box’s bottom surface (at height = 0) and is described in coordinates of the AGV’s coordinate system.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct BoundingBoxReference {
    /// x-coordinate of the point of reference.
    pub x: f64,

    /// y-coordinate of the point of reference.
    pub y: f64,

    /// z-coordinate of the point of reference.
    pub z: f64,

    /// Orientation of the loads bounding box. Important for tugger trains etc
    pub theta: f64,

}



impl Default for BoundingBoxReference {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::BoundingBoxReference::default())
  }
}

impl rosidl_runtime_rs::Message for BoundingBoxReference {
  type RmwMsg = super::msg::rmw::BoundingBoxReference;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        z: msg.z,
        theta: msg.theta,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      z: msg.z,
      theta: msg.theta,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      z: msg.z,
      theta: msg.theta,
    }
  }
}


// Corresponds to vda5050_msgs__msg__Connection
/// HEADER

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Connection {
    /// header ID of the message. The headerId is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: std::string::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: std::string::String,

    /// Manufacturer of the AGV
    pub manufacturer: std::string::String,

    /// Serial Number of the AGV
    pub serial_number: std::string::String,

    /// CONTENTS
    /// Enum{ONLINE, OFFLINE, CONNECTIONBROKEN}
    /// ONLINE: connection between AGV and broker is active.
    /// OFFLINE: connection between AGV and broker has gone offline in a coordinated way.
    /// CONNECTIONBROKEN: The connection between  AGV and  broker  has unexpectedly ended.
    pub connection_state: std::string::String,

}

impl Connection {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ONLINE: &'static str = "ONLINE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const OFFLINE: &'static str = "OFFLINE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONNECTIONBROKEN: &'static str = "CONNECTIONBROKEN";

}


impl Default for Connection {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Connection::default())
  }
}

impl rosidl_runtime_rs::Message for Connection {
  type RmwMsg = super::msg::rmw::Connection;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        connection_state: msg.connection_state.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        connection_state: msg.connection_state.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header_id: msg.header_id,
      timestamp: msg.timestamp.to_string(),
      version: msg.version.to_string(),
      manufacturer: msg.manufacturer.to_string(),
      serial_number: msg.serial_number.to_string(),
      connection_state: msg.connection_state.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__ControlPoint

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ControlPoint {
    /// X coordinate described in the world coordinate system.
    pub x: f64,

    /// Y coordinate described in the world coordinate system.
    pub y: f64,

    /// [rad] Range [-pi...pi] Orientation of the AGV on this position of the curve.
    /// The orientation is in world coordinates.
    /// When not defined the orientation of the AGV will be tangential to the curve.
    pub orientation: f64,

    /// Range [0..infinity) The weight with which this control point pulls on the curve.
    /// When not defined, the default will be 1.0
    pub weight: f64,

}



impl Default for ControlPoint {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ControlPoint::default())
  }
}

impl rosidl_runtime_rs::Message for ControlPoint {
  type RmwMsg = super::msg::rmw::ControlPoint;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        orientation: msg.orientation,
        weight: msg.weight,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      orientation: msg.orientation,
      weight: msg.weight,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      orientation: msg.orientation,
      weight: msg.weight,
    }
  }
}


// Corresponds to vda5050_msgs__msg__CurrentAction

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CurrentAction {
    /// action_name_ID
    pub action_id: std::string::String,

    /// actionType of the action.
    /// Optional: Only for informational or
    /// visualization purposes. Order knows
    /// the type.
    pub action_type: std::string::String,

    /// Additional information on the current action
    pub action_description: std::string::String,

    /// Enum {waiting; initializing; running; finished; failed} waiting: waiting for trigger
    /// failed: action could not be performed.
    pub action_status: std::string::String,

    /// Description of the result, e.g. the result of a RFID-read. Errors will be transmitted in
    /// errors. Examples for results are given in 5.2
    pub result_description: std::string::String,

}

impl CurrentAction {
    /// Enums for actionStatus
    pub const WAITING: &'static str = "WAITING";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INITIALIZING: &'static str = "INITIALIZING";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RUNNING: &'static str = "RUNNING";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PAUSED: &'static str = "PAUSED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FINISHED: &'static str = "FINISHED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FAILED: &'static str = "FAILED";

}


impl Default for CurrentAction {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::CurrentAction::default())
  }
}

impl rosidl_runtime_rs::Message for CurrentAction {
  type RmwMsg = super::msg::rmw::CurrentAction;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        action_id: msg.action_id.as_str().into(),
        action_type: msg.action_type.as_str().into(),
        action_description: msg.action_description.as_str().into(),
        action_status: msg.action_status.as_str().into(),
        result_description: msg.result_description.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        action_id: msg.action_id.as_str().into(),
        action_type: msg.action_type.as_str().into(),
        action_description: msg.action_description.as_str().into(),
        action_status: msg.action_status.as_str().into(),
        result_description: msg.result_description.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      action_id: msg.action_id.to_string(),
      action_type: msg.action_type.to_string(),
      action_description: msg.action_description.to_string(),
      action_status: msg.action_status.to_string(),
      result_description: msg.result_description.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__Edge
/// Directional connection between two nodes

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Edge {
    /// Unique edge identification
    pub edge_id: std::string::String,

    /// Id to track the sequence of nodes and edges in an order and to simplify order
    /// updates. The variable sequence_id runs across all nodes and edges of the same order
    /// and is reset when a new order_id is issued.
    pub sequence_id: u32,

    /// Additional information on the edge
    pub edge_description: std::string::String,

    /// True indicates that the edge is part of the base. False indicates that the edge is
    /// part of the horizon.
    pub released: bool,

    /// nodeID of startNode
    pub start_node_id: std::string::String,

    /// nodeID of endNode
    pub end_node_id: std::string::String,

    /// Permitted maximum speed on the edge. Speed is defined by the fastest point of the
    /// vehicle.
    pub max_speed: f64,

    /// Permitted maximum height of the vehicle, including the load, on edge
    pub max_height: f64,

    /// Permitted minimal height of the edge measured at the bottom of the load
    pub min_height: f64,

    /// Orientation of the AGV on the edge relative to the global project specific
    /// map coordinate origin (for holonomic vehicles with more than one driving
    /// direction).
    /// Example: orientation Pi/2 rad will lead to a rotation of 90 degrees.
    /// If AGVstarts in different orientation, rotate the vehicle on the edge to the
    /// desired orientation if rotationAllowed is set to “true”. If rotationAllowed
    /// is “false", rotate before entering the edge. If that is not possible, reject
    /// the order.
    /// If a trajectory with orientation is defined, follow the trajectories orientation.
    /// If a trajectory without orientation and the orientation field here is defined,
    /// apply the orientation to the tangent of the trajectory.
    pub orientation: f64,

    /// Sets direction at junctions for line-guided vehicles, to be defined initially
    /// (vehicle individual) Example: left, right, straight, 433MHz
    pub direction: std::string::String,

    /// “true”: rotation is allowed on the edge. “false”: rotation is not allowed on the edge.
    /// Optional: Default to “false”. If this value is set, rotation is allowed on the edge.
    pub rotation_allowed: bool,

    /// Maximum rotation speed Optional: No limit if not set
    pub max_rotation_speed: f64,

    /// Trajectory JSON-object for this edge as a NURBS. Defines the curve on which the
    /// AGV should move between start_node and end_node. Optional: Can be omitted if AGV
    /// cannot process trajectories or if AGV plans its own trajectory.
    pub trajectory: super::msg::Trajectory,

    /// Length of the path from startNode to endNode. Optional: This value is used
    /// by lineguided AGVs to decrease their speed before reaching a stop position.
    pub length: f64,

    /// Array of action_ids to be executed on the edge. An action triggered by an edge will
    /// only be active for the time that the AGV is traversing the edge which triggered
    /// the action. When the AGV leaves the edge, the action will stop and the state
    /// before entering the edge will be restored.
    pub actions: Vec<super::msg::Action>,

}



impl Default for Edge {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Edge::default())
  }
}

impl rosidl_runtime_rs::Message for Edge {
  type RmwMsg = super::msg::rmw::Edge;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        edge_id: msg.edge_id.as_str().into(),
        sequence_id: msg.sequence_id,
        edge_description: msg.edge_description.as_str().into(),
        released: msg.released,
        start_node_id: msg.start_node_id.as_str().into(),
        end_node_id: msg.end_node_id.as_str().into(),
        max_speed: msg.max_speed,
        max_height: msg.max_height,
        min_height: msg.min_height,
        orientation: msg.orientation,
        direction: msg.direction.as_str().into(),
        rotation_allowed: msg.rotation_allowed,
        max_rotation_speed: msg.max_rotation_speed,
        trajectory: super::msg::Trajectory::into_rmw_message(std::borrow::Cow::Owned(msg.trajectory)).into_owned(),
        length: msg.length,
        actions: msg.actions
          .into_iter()
          .map(|elem| super::msg::Action::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        edge_id: msg.edge_id.as_str().into(),
      sequence_id: msg.sequence_id,
        edge_description: msg.edge_description.as_str().into(),
      released: msg.released,
        start_node_id: msg.start_node_id.as_str().into(),
        end_node_id: msg.end_node_id.as_str().into(),
      max_speed: msg.max_speed,
      max_height: msg.max_height,
      min_height: msg.min_height,
      orientation: msg.orientation,
        direction: msg.direction.as_str().into(),
      rotation_allowed: msg.rotation_allowed,
      max_rotation_speed: msg.max_rotation_speed,
        trajectory: super::msg::Trajectory::into_rmw_message(std::borrow::Cow::Borrowed(&msg.trajectory)).into_owned(),
      length: msg.length,
        actions: msg.actions
          .iter()
          .map(|elem| super::msg::Action::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      edge_id: msg.edge_id.to_string(),
      sequence_id: msg.sequence_id,
      edge_description: msg.edge_description.to_string(),
      released: msg.released,
      start_node_id: msg.start_node_id.to_string(),
      end_node_id: msg.end_node_id.to_string(),
      max_speed: msg.max_speed,
      max_height: msg.max_height,
      min_height: msg.min_height,
      orientation: msg.orientation,
      direction: msg.direction.to_string(),
      rotation_allowed: msg.rotation_allowed,
      max_rotation_speed: msg.max_rotation_speed,
      trajectory: super::msg::Trajectory::from_rmw_message(msg.trajectory),
      length: msg.length,
      actions: msg.actions
          .into_iter()
          .map(super::msg::Action::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__EdgeState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EdgeState {
    /// Unique edge identification
    pub edge_id: std::string::String,

    /// sequenceId to differentiate between multiple edges with
    pub sequence_id: u32,

    /// Additional information on the edge
    pub edge_description: std::string::String,

    /// True indicates that the edge is part of the base. False indicates that the edge is
    /// part of the horizon.
    pub released: bool,

    /// The trajectory is to be communicated as a NURBS and is defined in chapter6.4
    /// Trajectory segments are from the point where the AGV starts to enter the edge
    /// until the point where it reports that the next node was traversed.
    pub trajectory: super::msg::Trajectory,

}



impl Default for EdgeState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::EdgeState::default())
  }
}

impl rosidl_runtime_rs::Message for EdgeState {
  type RmwMsg = super::msg::rmw::EdgeState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        edge_id: msg.edge_id.as_str().into(),
        sequence_id: msg.sequence_id,
        edge_description: msg.edge_description.as_str().into(),
        released: msg.released,
        trajectory: super::msg::Trajectory::into_rmw_message(std::borrow::Cow::Owned(msg.trajectory)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        edge_id: msg.edge_id.as_str().into(),
      sequence_id: msg.sequence_id,
        edge_description: msg.edge_description.as_str().into(),
      released: msg.released,
        trajectory: super::msg::Trajectory::into_rmw_message(std::borrow::Cow::Borrowed(&msg.trajectory)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      edge_id: msg.edge_id.to_string(),
      sequence_id: msg.sequence_id,
      edge_description: msg.edge_description.to_string(),
      released: msg.released,
      trajectory: super::msg::Trajectory::from_rmw_message(msg.trajectory),
    }
  }
}


// Corresponds to vda5050_msgs__msg__Envelope2D

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Envelope2D {
    /// Name of the envelope curve set
    pub set: std::string::String,

    /// Envelope curve as a x/y-polygon
    pub polygon_points: Vec<super::msg::PolygonPoint>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub description: std::string::String,

}



impl Default for Envelope2D {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Envelope2D::default())
  }
}

impl rosidl_runtime_rs::Message for Envelope2D {
  type RmwMsg = super::msg::rmw::Envelope2D;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        set: msg.set.as_str().into(),
        polygon_points: msg.polygon_points
          .into_iter()
          .map(|elem| super::msg::PolygonPoint::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        description: msg.description.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        set: msg.set.as_str().into(),
        polygon_points: msg.polygon_points
          .iter()
          .map(|elem| super::msg::PolygonPoint::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        description: msg.description.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      set: msg.set.to_string(),
      polygon_points: msg.polygon_points
          .into_iter()
          .map(super::msg::PolygonPoint::from_rmw_message)
          .collect(),
      description: msg.description.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__Envelope3D

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Envelope3D {
    /// Name of the envelope curve set
    pub set: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub format: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub data: std::string::String,

    /// Protocol and url-definition for downloading the 3D-envelope curve data
    pub url: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub description: std::string::String,

}



impl Default for Envelope3D {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Envelope3D::default())
  }
}

impl rosidl_runtime_rs::Message for Envelope3D {
  type RmwMsg = super::msg::rmw::Envelope3D;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        set: msg.set.as_str().into(),
        format: msg.format.as_str().into(),
        data: msg.data.as_str().into(),
        url: msg.url.as_str().into(),
        description: msg.description.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        set: msg.set.as_str().into(),
        format: msg.format.as_str().into(),
        data: msg.data.as_str().into(),
        url: msg.url.as_str().into(),
        description: msg.description.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      set: msg.set.to_string(),
      format: msg.format.to_string(),
      data: msg.data.to_string(),
      url: msg.url.to_string(),
      description: msg.description.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__Error

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Error {
    /// Type / name of error
    pub error_type: std::string::String,

    /// Array of references to identify the source of the error (e. g. header_id,
    /// order_id, action_id, …). For additional information see best practice
    /// chapter 6.3
    pub error_references: Vec<super::msg::ErrorReference>,

    /// Error description
    pub error_description: std::string::String,

    /// Enum {warning, fatal} warning: AGV is ready to start (e.g. maintenance
    /// cycle expiration warning) fatal: AGV is not in running condition, user
    /// intervention required (e.g. laser scanner is contaminated)
    pub error_level: std::string::String,

}

impl Error {
    /// Enums for error_level
    pub const WARNING: &'static str = "WARNING";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FATAL: &'static str = "FATAL";

}


impl Default for Error {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Error::default())
  }
}

impl rosidl_runtime_rs::Message for Error {
  type RmwMsg = super::msg::rmw::Error;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        error_type: msg.error_type.as_str().into(),
        error_references: msg.error_references
          .into_iter()
          .map(|elem| super::msg::ErrorReference::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        error_description: msg.error_description.as_str().into(),
        error_level: msg.error_level.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        error_type: msg.error_type.as_str().into(),
        error_references: msg.error_references
          .iter()
          .map(|elem| super::msg::ErrorReference::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        error_description: msg.error_description.as_str().into(),
        error_level: msg.error_level.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      error_type: msg.error_type.to_string(),
      error_references: msg.error_references
          .into_iter()
          .map(super::msg::ErrorReference::from_rmw_message)
          .collect(),
      error_description: msg.error_description.to_string(),
      error_level: msg.error_level.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__ErrorReference

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ErrorReference {
    /// References the type of reference (e. g. header_id, order_id, action_id, …).
    pub reference_key: std::string::String,

    /// References the value the reference key.
    pub reference_value: std::string::String,

}



impl Default for ErrorReference {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ErrorReference::default())
  }
}

impl rosidl_runtime_rs::Message for ErrorReference {
  type RmwMsg = super::msg::rmw::ErrorReference;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        reference_key: msg.reference_key.as_str().into(),
        reference_value: msg.reference_value.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        reference_key: msg.reference_key.as_str().into(),
        reference_value: msg.reference_value.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      reference_key: msg.reference_key.to_string(),
      reference_value: msg.reference_value.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__Factsheet
/// HEADER

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Factsheet {
    /// header ID of the message. The headerId is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: std::string::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: std::string::String,

    /// Manufacturer of the AGV
    pub manufacturer: std::string::String,

    /// Serial Number of the AGV
    pub serial_number: std::string::String,

    /// CONTENTS
    /// Class and capabilities of the AGV
    pub type_specification: super::msg::TypeSpecification,

    /// Physical properties of the AGV
    pub physical_parameters: super::msg::PhysicalParameters,

    /// Protocol limitations of the AGV
    pub protocol_limits: super::msg::ProtocolLimits,

    /// Supported and/or required optional parameters
    pub protocol_features: super::msg::ProtocolFeatures,

    /// Detailed definition of AGV geometry
    pub agv_geometry: super::msg::AGVGeometry,

    /// Load positions / load handling devices
    pub load_specification: super::msg::LoadSpecification,

    /// Detailed specification of localization
    pub localization_parameters: i32,

}



impl Default for Factsheet {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Factsheet::default())
  }
}

impl rosidl_runtime_rs::Message for Factsheet {
  type RmwMsg = super::msg::rmw::Factsheet;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        type_specification: super::msg::TypeSpecification::into_rmw_message(std::borrow::Cow::Owned(msg.type_specification)).into_owned(),
        physical_parameters: super::msg::PhysicalParameters::into_rmw_message(std::borrow::Cow::Owned(msg.physical_parameters)).into_owned(),
        protocol_limits: super::msg::ProtocolLimits::into_rmw_message(std::borrow::Cow::Owned(msg.protocol_limits)).into_owned(),
        protocol_features: super::msg::ProtocolFeatures::into_rmw_message(std::borrow::Cow::Owned(msg.protocol_features)).into_owned(),
        agv_geometry: super::msg::AGVGeometry::into_rmw_message(std::borrow::Cow::Owned(msg.agv_geometry)).into_owned(),
        load_specification: super::msg::LoadSpecification::into_rmw_message(std::borrow::Cow::Owned(msg.load_specification)).into_owned(),
        localization_parameters: msg.localization_parameters,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        type_specification: super::msg::TypeSpecification::into_rmw_message(std::borrow::Cow::Borrowed(&msg.type_specification)).into_owned(),
        physical_parameters: super::msg::PhysicalParameters::into_rmw_message(std::borrow::Cow::Borrowed(&msg.physical_parameters)).into_owned(),
        protocol_limits: super::msg::ProtocolLimits::into_rmw_message(std::borrow::Cow::Borrowed(&msg.protocol_limits)).into_owned(),
        protocol_features: super::msg::ProtocolFeatures::into_rmw_message(std::borrow::Cow::Borrowed(&msg.protocol_features)).into_owned(),
        agv_geometry: super::msg::AGVGeometry::into_rmw_message(std::borrow::Cow::Borrowed(&msg.agv_geometry)).into_owned(),
        load_specification: super::msg::LoadSpecification::into_rmw_message(std::borrow::Cow::Borrowed(&msg.load_specification)).into_owned(),
      localization_parameters: msg.localization_parameters,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header_id: msg.header_id,
      timestamp: msg.timestamp.to_string(),
      version: msg.version.to_string(),
      manufacturer: msg.manufacturer.to_string(),
      serial_number: msg.serial_number.to_string(),
      type_specification: super::msg::TypeSpecification::from_rmw_message(msg.type_specification),
      physical_parameters: super::msg::PhysicalParameters::from_rmw_message(msg.physical_parameters),
      protocol_limits: super::msg::ProtocolLimits::from_rmw_message(msg.protocol_limits),
      protocol_features: super::msg::ProtocolFeatures::from_rmw_message(msg.protocol_features),
      agv_geometry: super::msg::AGVGeometry::from_rmw_message(msg.agv_geometry),
      load_specification: super::msg::LoadSpecification::from_rmw_message(msg.load_specification),
      localization_parameters: msg.localization_parameters,
    }
  }
}


// Corresponds to vda5050_msgs__msg__Info

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Info {
    /// Type / name of information
    pub info_type: std::string::String,

    /// array of references
    pub info_references: Vec<super::msg::InfoReference>,

    /// Info description
    pub info_description: std::string::String,

    /// Enum {DEBUG, INFO} DEBUG: used for debugging, INFO: used for visualization
    pub info_level: std::string::String,

}

impl Info {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DEBUG: &'static str = "DEBUG";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const INFO: &'static str = "INFO";

}


impl Default for Info {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Info::default())
  }
}

impl rosidl_runtime_rs::Message for Info {
  type RmwMsg = super::msg::rmw::Info;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        info_type: msg.info_type.as_str().into(),
        info_references: msg.info_references
          .into_iter()
          .map(|elem| super::msg::InfoReference::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        info_description: msg.info_description.as_str().into(),
        info_level: msg.info_level.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        info_type: msg.info_type.as_str().into(),
        info_references: msg.info_references
          .iter()
          .map(|elem| super::msg::InfoReference::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        info_description: msg.info_description.as_str().into(),
        info_level: msg.info_level.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      info_type: msg.info_type.to_string(),
      info_references: msg.info_references
          .into_iter()
          .map(super::msg::InfoReference::from_rmw_message)
          .collect(),
      info_description: msg.info_description.to_string(),
      info_level: msg.info_level.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__InfoReference

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InfoReference {
    /// References the type of reference (e. g. headerId, orderId, actionId, …).
    pub reference_key: std::string::String,

    /// References the value the reference key.
    pub reference_value: std::string::String,

}



impl Default for InfoReference {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::InfoReference::default())
  }
}

impl rosidl_runtime_rs::Message for InfoReference {
  type RmwMsg = super::msg::rmw::InfoReference;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        reference_key: msg.reference_key.as_str().into(),
        reference_value: msg.reference_value.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        reference_key: msg.reference_key.as_str().into(),
        reference_value: msg.reference_value.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      reference_key: msg.reference_key.to_string(),
      reference_value: msg.reference_value.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__Header

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Header {
    /// header ID of the message. The header_id is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: i32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: std::string::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: std::string::String,

    /// Manufacturer of the AGV
    pub manufacturer: std::string::String,

    /// Serial Number of the AGV
    pub serial_number: std::string::String,

}



impl Default for Header {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Header::default())
  }
}

impl rosidl_runtime_rs::Message for Header {
  type RmwMsg = super::msg::rmw::Header;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header_id: msg.header_id,
      timestamp: msg.timestamp.to_string(),
      version: msg.version.to_string(),
      manufacturer: msg.manufacturer.to_string(),
      serial_number: msg.serial_number.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__InstantActions

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InstantActions {
    /// header ID of the message. The headerId is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: std::string::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: std::string::String,

    /// Manufacturer of the AGV
    pub manufacturer: std::string::String,

    /// Serial Number of the AGV
    pub serial_number: std::string::String,

    /// List of actions to execute
    pub actions: Vec<super::msg::Action>,

}



impl Default for InstantActions {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::InstantActions::default())
  }
}

impl rosidl_runtime_rs::Message for InstantActions {
  type RmwMsg = super::msg::rmw::InstantActions;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        actions: msg.actions
          .into_iter()
          .map(|elem| super::msg::Action::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        actions: msg.actions
          .iter()
          .map(|elem| super::msg::Action::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header_id: msg.header_id,
      timestamp: msg.timestamp.to_string(),
      version: msg.version.to_string(),
      manufacturer: msg.manufacturer.to_string(),
      serial_number: msg.serial_number.to_string(),
      actions: msg.actions
          .into_iter()
          .map(super::msg::Action::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__Load

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Load {
    /// Unique identification number of the load (e. g. barcode or
    /// RFID)
    pub load_id: std::string::String,

    /// Type of load
    pub load_type: std::string::String,

    /// Indicates which load handling/carrying unit of the AGV is
    /// used, e. g. in case the AGV has multiple spots/positions to
    /// carry loads. For example: “front”, “back”, “positionC1”, etc.
    pub load_position: std::string::String,

    /// Point of reference for the location of the bounding box. The
    /// point of reference is always the center of the bounding box’s
    /// bottom surface (at height = 0) and is described in coordinates
    /// of the AGV’s coordinate system.
    pub bounding_box_reference: super::msg::BoundingBoxReference,

    /// Dimensions of the load’s bounding box in meters.
    pub load_dimensions: super::msg::LoadDimensions,

    /// Absolute weight of the load measured in kg.
    pub weight: f64,

}



impl Default for Load {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Load::default())
  }
}

impl rosidl_runtime_rs::Message for Load {
  type RmwMsg = super::msg::rmw::Load;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        load_id: msg.load_id.as_str().into(),
        load_type: msg.load_type.as_str().into(),
        load_position: msg.load_position.as_str().into(),
        bounding_box_reference: super::msg::BoundingBoxReference::into_rmw_message(std::borrow::Cow::Owned(msg.bounding_box_reference)).into_owned(),
        load_dimensions: super::msg::LoadDimensions::into_rmw_message(std::borrow::Cow::Owned(msg.load_dimensions)).into_owned(),
        weight: msg.weight,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        load_id: msg.load_id.as_str().into(),
        load_type: msg.load_type.as_str().into(),
        load_position: msg.load_position.as_str().into(),
        bounding_box_reference: super::msg::BoundingBoxReference::into_rmw_message(std::borrow::Cow::Borrowed(&msg.bounding_box_reference)).into_owned(),
        load_dimensions: super::msg::LoadDimensions::into_rmw_message(std::borrow::Cow::Borrowed(&msg.load_dimensions)).into_owned(),
      weight: msg.weight,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      load_id: msg.load_id.to_string(),
      load_type: msg.load_type.to_string(),
      load_position: msg.load_position.to_string(),
      bounding_box_reference: super::msg::BoundingBoxReference::from_rmw_message(msg.bounding_box_reference),
      load_dimensions: super::msg::LoadDimensions::from_rmw_message(msg.load_dimensions),
      weight: msg.weight,
    }
  }
}


// Corresponds to vda5050_msgs__msg__LoadDimensions
/// Dimensions of the load’s bounding box in meters.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadDimensions {
    /// Absolute length of the load’s bounding box.
    pub length: f64,

    /// Absolute width of the load’s bounding box.
    pub width: f64,

    /// Absolute height of the load’s bounding box. Optional: Set value only if known.
    pub height: f64,

}



impl Default for LoadDimensions {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::LoadDimensions::default())
  }
}

impl rosidl_runtime_rs::Message for LoadDimensions {
  type RmwMsg = super::msg::rmw::LoadDimensions;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        length: msg.length,
        width: msg.width,
        height: msg.height,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      length: msg.length,
      width: msg.width,
      height: msg.height,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      length: msg.length,
      width: msg.width,
      height: msg.height,
    }
  }
}


// Corresponds to vda5050_msgs__msg__LoadSet

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadSet {

    // This member is not documented.
    #[allow(missing_docs)]
    pub set_name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub load_type: std::string::String,

    /// List of load positions / load handling devices
    pub load_positions: Vec<std::string::String>,

    /// Bounding box reference as defined in parameter loads[] in state-message
    pub bounding_box_reference: super::msg::BoundingBoxReference,


    // This member is not documented.
    #[allow(missing_docs)]
    pub load_dimensions: super::msg::LoadDimensions,

    /// Maximum weight of load type
    pub max_weight: f64,

    /// Minimum allowed height for handling of this load-type and weight
    pub min_loadhandling_height: f64,

    /// Maximum allowed height for handling of this load-type and weight
    pub max_loadhandling_height: f64,

    /// Minimum allowed depth for this load-type and weight
    pub min_loadhandling_depth: f64,

    /// Maximum allowed depth for this load-type and weight
    pub max_loadhandling_depth: f64,

    /// Minimum allowed tilt for this load-type and weight
    pub min_loadhandling_tilt: f64,

    /// Maximum allowed tilt for this load-type and weight
    pub max_loadhandling_tilt: f64,

    /// Maximum allowed speed for this load-type and weight
    pub agv_speed_limit: f64,

    /// Maximum allowed acceleration for this load-type and weight
    pub agv_acceleration_limit: f64,

    /// Maximum allowed deceleration for this load-type and weight
    pub agv_deceleration_limit: f64,

    /// Approx. time for picking up the load
    pub pick_time: f64,

    /// Approx. time for dropping the load
    pub drop_time: f64,

    /// Free description of the load handling set
    pub description: std::string::String,

}



impl Default for LoadSet {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::LoadSet::default())
  }
}

impl rosidl_runtime_rs::Message for LoadSet {
  type RmwMsg = super::msg::rmw::LoadSet;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        set_name: msg.set_name.as_str().into(),
        load_type: msg.load_type.as_str().into(),
        load_positions: msg.load_positions
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        bounding_box_reference: super::msg::BoundingBoxReference::into_rmw_message(std::borrow::Cow::Owned(msg.bounding_box_reference)).into_owned(),
        load_dimensions: super::msg::LoadDimensions::into_rmw_message(std::borrow::Cow::Owned(msg.load_dimensions)).into_owned(),
        max_weight: msg.max_weight,
        min_loadhandling_height: msg.min_loadhandling_height,
        max_loadhandling_height: msg.max_loadhandling_height,
        min_loadhandling_depth: msg.min_loadhandling_depth,
        max_loadhandling_depth: msg.max_loadhandling_depth,
        min_loadhandling_tilt: msg.min_loadhandling_tilt,
        max_loadhandling_tilt: msg.max_loadhandling_tilt,
        agv_speed_limit: msg.agv_speed_limit,
        agv_acceleration_limit: msg.agv_acceleration_limit,
        agv_deceleration_limit: msg.agv_deceleration_limit,
        pick_time: msg.pick_time,
        drop_time: msg.drop_time,
        description: msg.description.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        set_name: msg.set_name.as_str().into(),
        load_type: msg.load_type.as_str().into(),
        load_positions: msg.load_positions
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        bounding_box_reference: super::msg::BoundingBoxReference::into_rmw_message(std::borrow::Cow::Borrowed(&msg.bounding_box_reference)).into_owned(),
        load_dimensions: super::msg::LoadDimensions::into_rmw_message(std::borrow::Cow::Borrowed(&msg.load_dimensions)).into_owned(),
      max_weight: msg.max_weight,
      min_loadhandling_height: msg.min_loadhandling_height,
      max_loadhandling_height: msg.max_loadhandling_height,
      min_loadhandling_depth: msg.min_loadhandling_depth,
      max_loadhandling_depth: msg.max_loadhandling_depth,
      min_loadhandling_tilt: msg.min_loadhandling_tilt,
      max_loadhandling_tilt: msg.max_loadhandling_tilt,
      agv_speed_limit: msg.agv_speed_limit,
      agv_acceleration_limit: msg.agv_acceleration_limit,
      agv_deceleration_limit: msg.agv_deceleration_limit,
      pick_time: msg.pick_time,
      drop_time: msg.drop_time,
        description: msg.description.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      set_name: msg.set_name.to_string(),
      load_type: msg.load_type.to_string(),
      load_positions: msg.load_positions
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      bounding_box_reference: super::msg::BoundingBoxReference::from_rmw_message(msg.bounding_box_reference),
      load_dimensions: super::msg::LoadDimensions::from_rmw_message(msg.load_dimensions),
      max_weight: msg.max_weight,
      min_loadhandling_height: msg.min_loadhandling_height,
      max_loadhandling_height: msg.max_loadhandling_height,
      min_loadhandling_depth: msg.min_loadhandling_depth,
      max_loadhandling_depth: msg.max_loadhandling_depth,
      min_loadhandling_tilt: msg.min_loadhandling_tilt,
      max_loadhandling_tilt: msg.max_loadhandling_tilt,
      agv_speed_limit: msg.agv_speed_limit,
      agv_acceleration_limit: msg.agv_acceleration_limit,
      agv_deceleration_limit: msg.agv_deceleration_limit,
      pick_time: msg.pick_time,
      drop_time: msg.drop_time,
      description: msg.description.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__LoadSpecification

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LoadSpecification {
    /// List of load positions / load handling devices
    pub load_positions: Vec<std::string::String>,

    /// List of load-sets that can be handled by the AGV
    pub load_sets: Vec<super::msg::LoadSet>,

}



impl Default for LoadSpecification {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::LoadSpecification::default())
  }
}

impl rosidl_runtime_rs::Message for LoadSpecification {
  type RmwMsg = super::msg::rmw::LoadSpecification;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        load_positions: msg.load_positions
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        load_sets: msg.load_sets
          .into_iter()
          .map(|elem| super::msg::LoadSet::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        load_positions: msg.load_positions
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        load_sets: msg.load_sets
          .iter()
          .map(|elem| super::msg::LoadSet::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      load_positions: msg.load_positions
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      load_sets: msg.load_sets
          .into_iter()
          .map(super::msg::LoadSet::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__MaxArrayLens

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MaxArrayLens {
    /// Maximum number of nodes per order processable by the AGV
    pub order_nodes: u32,

    /// Maximum number of edges per order processable by the AGV
    pub order_edges: u32,

    /// Maximum number of action per node processable by the AGV
    pub node_actions: u32,

    /// Maximum number of action per edge processable by the AGV
    pub edge_actions: u32,

    /// Maximum number of parameters per action processable by the AGV
    pub actions_parameters: u32,

    /// Maximum number of instant actions per message processable by the AGV
    pub instant_actions: u32,

    /// Maximum number of knots per trajectory processable by the AGV
    pub trajectory_knot_vector: u32,

    /// Maximum number of control points per trajectory processable by the AGV
    pub trajectory_control_points: u32,

    /// Maximum number of nodeStates sent by the AGV, maximum number of nodes in base of AGV
    pub state_node_states: u32,

    /// Maximum number of edgeStates sent by the AGV, maximum number of edges in base of AGV
    pub state_edge_states: u32,

    /// Maximum number of load-objects sent by the AGV
    pub state_loads: u32,

    /// Maximum number of actionStates sent by the AGV
    pub state_action_states: u32,

    /// Maximum number of errors sent by the AGV in one state-message
    pub state_errors: u32,

    /// Maximum number of information objects sent by the AGV in one state-message
    pub state_information: u32,

    /// Maximum number of error references sent by the AGV for each error
    pub error_references: u32,

    /// Maximum number of info references sent by the AGV for each information
    pub info_references: u32,

}



impl Default for MaxArrayLens {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MaxArrayLens::default())
  }
}

impl rosidl_runtime_rs::Message for MaxArrayLens {
  type RmwMsg = super::msg::rmw::MaxArrayLens;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        order_nodes: msg.order_nodes,
        order_edges: msg.order_edges,
        node_actions: msg.node_actions,
        edge_actions: msg.edge_actions,
        actions_parameters: msg.actions_parameters,
        instant_actions: msg.instant_actions,
        trajectory_knot_vector: msg.trajectory_knot_vector,
        trajectory_control_points: msg.trajectory_control_points,
        state_node_states: msg.state_node_states,
        state_edge_states: msg.state_edge_states,
        state_loads: msg.state_loads,
        state_action_states: msg.state_action_states,
        state_errors: msg.state_errors,
        state_information: msg.state_information,
        error_references: msg.error_references,
        info_references: msg.info_references,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      order_nodes: msg.order_nodes,
      order_edges: msg.order_edges,
      node_actions: msg.node_actions,
      edge_actions: msg.edge_actions,
      actions_parameters: msg.actions_parameters,
      instant_actions: msg.instant_actions,
      trajectory_knot_vector: msg.trajectory_knot_vector,
      trajectory_control_points: msg.trajectory_control_points,
      state_node_states: msg.state_node_states,
      state_edge_states: msg.state_edge_states,
      state_loads: msg.state_loads,
      state_action_states: msg.state_action_states,
      state_errors: msg.state_errors,
      state_information: msg.state_information,
      error_references: msg.error_references,
      info_references: msg.info_references,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      order_nodes: msg.order_nodes,
      order_edges: msg.order_edges,
      node_actions: msg.node_actions,
      edge_actions: msg.edge_actions,
      actions_parameters: msg.actions_parameters,
      instant_actions: msg.instant_actions,
      trajectory_knot_vector: msg.trajectory_knot_vector,
      trajectory_control_points: msg.trajectory_control_points,
      state_node_states: msg.state_node_states,
      state_edge_states: msg.state_edge_states,
      state_loads: msg.state_loads,
      state_action_states: msg.state_action_states,
      state_errors: msg.state_errors,
      state_information: msg.state_information,
      error_references: msg.error_references,
      info_references: msg.info_references,
    }
  }
}


// Corresponds to vda5050_msgs__msg__MaxStringLens

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MaxStringLens {
    /// Maximum MQTT Message length
    pub msg_len: u32,

    /// Maximum length of serial-number part in MQTT-topics
    pub topic_serial_len: u32,

    /// Maximum length of all other parts in MQTT-topics (timestamp, versions, manufacturer)
    pub topic_elem_len: u32,

    /// Maximum length of ID-Strings
    pub id_len: u32,

    /// If true ID-strings need to contain numerical values only
    pub id_numerical_only: bool,

    /// Maximum length of ENUM- and Key-Strings
    pub enum_len: u32,

    /// Maximum length of loadId Strings
    pub load_id_len: u32,

}



impl Default for MaxStringLens {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MaxStringLens::default())
  }
}

impl rosidl_runtime_rs::Message for MaxStringLens {
  type RmwMsg = super::msg::rmw::MaxStringLens;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        msg_len: msg.msg_len,
        topic_serial_len: msg.topic_serial_len,
        topic_elem_len: msg.topic_elem_len,
        id_len: msg.id_len,
        id_numerical_only: msg.id_numerical_only,
        enum_len: msg.enum_len,
        load_id_len: msg.load_id_len,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      msg_len: msg.msg_len,
      topic_serial_len: msg.topic_serial_len,
      topic_elem_len: msg.topic_elem_len,
      id_len: msg.id_len,
      id_numerical_only: msg.id_numerical_only,
      enum_len: msg.enum_len,
      load_id_len: msg.load_id_len,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      msg_len: msg.msg_len,
      topic_serial_len: msg.topic_serial_len,
      topic_elem_len: msg.topic_elem_len,
      id_len: msg.id_len,
      id_numerical_only: msg.id_numerical_only,
      enum_len: msg.enum_len,
      load_id_len: msg.load_id_len,
    }
  }
}


// Corresponds to vda5050_msgs__msg__Node
/// Array of nodes to be traversed for fulfilling the order

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Node {
    /// Unique node identification.
    pub node_id: std::string::String,

    /// Id to track the sequence of nodes and edges in an order and to
    /// simplify order updates. The variable sequence_id runs across all
    /// nodes and edges of the same order and is reset when a new order_id is
    /// issued.
    pub sequence_id: u32,

    /// Additional information on the node
    pub node_description: std::string::String,

    /// True indicates that the node is part of the base. False indicates
    /// that the node is part of the horizon.
    pub released: bool,

    /// Node position
    pub node_position: super::msg::NodePosition,

    /// Array of actions to be executed in node. Empty array if no actions
    /// required. An action triggered by a node will persist until changed
    /// in another node unless restricted by duration_type/duration_value.
    pub actions: Vec<super::msg::Action>,

}



impl Default for Node {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Node::default())
  }
}

impl rosidl_runtime_rs::Message for Node {
  type RmwMsg = super::msg::rmw::Node;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        node_id: msg.node_id.as_str().into(),
        sequence_id: msg.sequence_id,
        node_description: msg.node_description.as_str().into(),
        released: msg.released,
        node_position: super::msg::NodePosition::into_rmw_message(std::borrow::Cow::Owned(msg.node_position)).into_owned(),
        actions: msg.actions
          .into_iter()
          .map(|elem| super::msg::Action::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        node_id: msg.node_id.as_str().into(),
      sequence_id: msg.sequence_id,
        node_description: msg.node_description.as_str().into(),
      released: msg.released,
        node_position: super::msg::NodePosition::into_rmw_message(std::borrow::Cow::Borrowed(&msg.node_position)).into_owned(),
        actions: msg.actions
          .iter()
          .map(|elem| super::msg::Action::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      node_id: msg.node_id.to_string(),
      sequence_id: msg.sequence_id,
      node_description: msg.node_description.to_string(),
      released: msg.released,
      node_position: super::msg::NodePosition::from_rmw_message(msg.node_position),
      actions: msg.actions
          .into_iter()
          .map(super::msg::Action::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__NodePosition
/// Defines the position on a map in world coordinates. Each floor has its own map.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NodePosition {
    /// X-position on the map in reference to the world coordinate system
    pub x: f64,

    /// Y-position on the map in reference to the world coordinate system
    pub y: f64,

    /// The angular dimension
    pub theta: f64,

    /// Indicates how exact an AGV has to drive over a node in order for it
    /// to count as traversed.
    ///
    /// If = 0: no deviation is allowed (no deviation means within the
    /// normal tolerance of the AGV manufacturer).
    ///
    /// If > 0: allowed deviationradius in meters. If the AGV passes a node
    /// within the deviation-radius, the node is considered to have been
    /// traversed.
    pub allowed_deviation_x_y: f32,

    /// Range:
    /// Indicates how big the deviation of theta angle can be.
    /// The lowest acceptable angle  is theta -allowedDevaitionTheta and
    /// the  highest acceptable angle is theta + allowedDeviationTheta
    pub allowed_deviation_theta: f32,

    /// Unique identification of the map in which the position is referenced. Each map has the same
    /// origin of coordinates. When an AGV uses an elevator, e. g. leading from a departure floor to a
    /// target floor, it will disappear off the map of the departure floor and spawn in the related
    /// lift node on the map of the target floor.
    pub map_id: std::string::String,

    /// Additional information on the map
    pub map_description: std::string::String,

}



impl Default for NodePosition {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::NodePosition::default())
  }
}

impl rosidl_runtime_rs::Message for NodePosition {
  type RmwMsg = super::msg::rmw::NodePosition;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        theta: msg.theta,
        allowed_deviation_x_y: msg.allowed_deviation_x_y,
        allowed_deviation_theta: msg.allowed_deviation_theta,
        map_id: msg.map_id.as_str().into(),
        map_description: msg.map_description.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
      allowed_deviation_x_y: msg.allowed_deviation_x_y,
      allowed_deviation_theta: msg.allowed_deviation_theta,
        map_id: msg.map_id.as_str().into(),
        map_description: msg.map_description.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
      allowed_deviation_x_y: msg.allowed_deviation_x_y,
      allowed_deviation_theta: msg.allowed_deviation_theta,
      map_id: msg.map_id.to_string(),
      map_description: msg.map_description.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__NodeState
/// Array of nodes to be traversed for fulfilling the order

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NodeState {
    /// Unique node identification
    pub node_id: std::string::String,

    /// sequenceId to discern multiple nodes with same nodeId.
    pub sequence_id: u32,

    /// Additional information on the node
    pub node_description: std::string::String,

    /// Node position (see Topic: Order)
    pub node_position: super::msg::NodePosition,

    /// true indicates that the node is part of the base.
    /// false indicates that the node is part of the horizon.
    pub released: bool,

}



impl Default for NodeState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::NodeState::default())
  }
}

impl rosidl_runtime_rs::Message for NodeState {
  type RmwMsg = super::msg::rmw::NodeState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        node_id: msg.node_id.as_str().into(),
        sequence_id: msg.sequence_id,
        node_description: msg.node_description.as_str().into(),
        node_position: super::msg::NodePosition::into_rmw_message(std::borrow::Cow::Owned(msg.node_position)).into_owned(),
        released: msg.released,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        node_id: msg.node_id.as_str().into(),
      sequence_id: msg.sequence_id,
        node_description: msg.node_description.as_str().into(),
        node_position: super::msg::NodePosition::into_rmw_message(std::borrow::Cow::Borrowed(&msg.node_position)).into_owned(),
      released: msg.released,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      node_id: msg.node_id.to_string(),
      sequence_id: msg.sequence_id,
      node_description: msg.node_description.to_string(),
      node_position: super::msg::NodePosition::from_rmw_message(msg.node_position),
      released: msg.released,
    }
  }
}


// Corresponds to vda5050_msgs__msg__OptionalParameter

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OptionalParameter {
    /// Full name of optional parameter
    pub parameter: std::string::String,

    /// Type of support for the optional parameter
    pub support: std::string::String,

    /// Description of optional parameter
    pub description: std::string::String,

}

impl OptionalParameter {
    /// Enums for support
    pub const SUPPORTED: &'static str = "SUPPORTED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const REQUIRED: &'static str = "REQUIRED";

}


impl Default for OptionalParameter {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::OptionalParameter::default())
  }
}

impl rosidl_runtime_rs::Message for OptionalParameter {
  type RmwMsg = super::msg::rmw::OptionalParameter;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        parameter: msg.parameter.as_str().into(),
        support: msg.support.as_str().into(),
        description: msg.description.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        parameter: msg.parameter.as_str().into(),
        support: msg.support.as_str().into(),
        description: msg.description.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      parameter: msg.parameter.to_string(),
      support: msg.support.to_string(),
      description: msg.description.to_string(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__Order
/// HEADER

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Order {
    /// header ID of the message. The header_id is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: std::string::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: std::string::String,

    /// Manufacturer of the AGV
    pub manufacturer: std::string::String,

    /// Serial Number of the AGV
    pub serial_number: std::string::String,

    /// CONTENTS
    /// Unique order identification
    pub order_id: std::string::String,

    /// order_update identification. Is unique per order_id. If an order update is
    /// rejected, this field is to be passed in the rejection message
    pub order_update_id: u32,

    /// Unique identifier of the zone set that the AGV has to use for navigation or that was used by master controlfor planning
    /// Optional: Some master controlsystems do not use zones. Some AGVs do not understand zones. Do not add to message if no zones are used
    pub zone_set_id: std::string::String,

    /// Array of nodes to be traversed for fulfilling the order. The nodes come
    /// in the sequence of the fulfilling.
    pub nodes: Vec<super::msg::Node>,

    /// Array of edges to be traversed for fulfilling the order
    pub edges: Vec<super::msg::Edge>,

}



impl Default for Order {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Order::default())
  }
}

impl rosidl_runtime_rs::Message for Order {
  type RmwMsg = super::msg::rmw::Order;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        order_id: msg.order_id.as_str().into(),
        order_update_id: msg.order_update_id,
        zone_set_id: msg.zone_set_id.as_str().into(),
        nodes: msg.nodes
          .into_iter()
          .map(|elem| super::msg::Node::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        edges: msg.edges
          .into_iter()
          .map(|elem| super::msg::Edge::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        order_id: msg.order_id.as_str().into(),
      order_update_id: msg.order_update_id,
        zone_set_id: msg.zone_set_id.as_str().into(),
        nodes: msg.nodes
          .iter()
          .map(|elem| super::msg::Node::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        edges: msg.edges
          .iter()
          .map(|elem| super::msg::Edge::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header_id: msg.header_id,
      timestamp: msg.timestamp.to_string(),
      version: msg.version.to_string(),
      manufacturer: msg.manufacturer.to_string(),
      serial_number: msg.serial_number.to_string(),
      order_id: msg.order_id.to_string(),
      order_update_id: msg.order_update_id,
      zone_set_id: msg.zone_set_id.to_string(),
      nodes: msg.nodes
          .into_iter()
          .map(super::msg::Node::from_rmw_message)
          .collect(),
      edges: msg.edges
          .into_iter()
          .map(super::msg::Edge::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__OrderState
/// HEADER

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct OrderState {
    /// header ID of the message. The header_id is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: std::string::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: std::string::String,

    /// Manufacturer of the AGV
    pub manufacturer: std::string::String,

    /// Serial Number of the AGV
    pub serial_number: std::string::String,

    /// CONTENTS
    /// Unique order identification “none” if vehicle is idle and has no order
    pub order_id: std::string::String,

    /// order_update identification. Is unique per order_id. If an order update is rejected, this field is to be passed in the rejection message.
    pub order_update_id: u32,

    /// Unique ID of the zone set that the AGV currently uses for path planning. Must be the same as the one used in the order,
    /// otherwise the AGV hasto reject the order. Optional: If the AGV does not use zones, this field can be omitted.
    pub zone_set_id: std::string::String,

    /// nodeId of last reached node or, if AGV is currently on a node, current node (e.g. „node7”).
    /// Empty string ("") if no lastNodeId is available.
    pub last_node_id: std::string::String,

    /// sequence_id of the last reached node or, if the AGV is currently on a node, sequence_id of current node.
    /// “0” if no last_node_sequence_id is available.
    pub last_node_sequence_id: u32,

    /// Array of node_state_objects (empty list if idle)
    pub node_states: Vec<super::msg::NodeState>,

    /// Array of edge_state_objects (empty list if idle)
    pub edge_states: Vec<super::msg::EdgeState>,

    /// Current position of the AGV. Optional: Can only be omitted for
    /// AGVs without the capability to localize themselves, e.g. line
    /// guided AGVs.
    pub agv_position: super::msg::AGVPosition,

    /// AGV's velocity in vehicle coordinates
    pub velocity: super::msg::Velocity,

    /// Loads that are currently handled by the AGV.
    /// Optional: If AGV cannot determine load state, leave the array out of the state.
    /// If the  AGV  can determine the  load  state,  but  the  array  is  empty,  the  AGV  is considered unloaded.
    pub loads: Vec<super::msg::Load>,

    /// True: indicates that the AGV is driving and/or rotating. Other
    /// movements of the AGV (e.g. lift movements) are not included here.
    /// False: indicates that the AGV is neither driving nor rotating
    pub driving: bool,

    /// True: AGV is currently in a paused state, either because of the push of a physical button on the AGV or
    /// because of an instantAction. The AGV can resume the order.
    /// False: The AGV is currently not in a paused state
    pub paused: bool,

    /// True: AGV is almost at the end of the base and will reduce speed if no new base is transmitted. Trigger for MC to send ne base
    /// False: no base update required
    pub new_base_request: bool,

    /// Used by line guided vehicles to indicate the distance it has been driving past the last_node_id. Distance is in meters
    pub distance_since_last_node: f64,

    /// Contains a list of the current actions and the actions which are
    /// yet to be finished. This may include actions from previous nodes
    /// that are still in progress. When an action is completed, an
    /// updated state message is published with action_status set to
    /// finished and if applicable with the corresponding
    /// result_description. Completed actions are omitted from the array
    pub action_states: Vec<super::msg::CurrentAction>,

    /// Contains all batteryrelated information.
    pub battery_state: super::msg::BatteryState,

    /// Enum {AUTOMATIC, SEMIAUTOMATIC, MANUAL, SERVICE, TEACHIN}
    /// For additional information see chapter 6.2
    pub operating_mode: std::string::String,

    /// Array of errorobjects. Empty array if there are no errors.
    pub errors: Vec<super::msg::Error>,

    /// Array of info-objects. An empty array indicates that the AGV has no information.
    /// This should only be used for visualization or debugging – it must not be used for logic in master control
    pub informations: Vec<super::msg::Info>,

    /// Contains all safetyrelated information.
    /// Enums for operatingMode
    pub safety_state: super::msg::SafetyState,

}

impl OrderState {
    /// AGV is under full control of the supervisor. AGV drives and executes actions based on orders from the supervisor
    pub const AUTOMATIC: &'static str = "AUTOMATIC";

    /// AGV is under control of the supervisor. AGV drives and executes actions based on orders from the supervisor. The driving speeds is controlled by the HMI. (speed can’t exceed the speed of automatic mode) The steering is under automatic control. (non-safe HMI possible)
    pub const SEMIAUTOMATIC: &'static str = "SEMIAUTOMATIC";

    /// Supervisor is not in control of the AGV. Supervisor doesn’t send driving order or actions to the AGV. HMI can be used the control the steering and velocity and handling device of the AGV. Location of the AGV is send to the supervisor. When AGV enters or leaves this mode, it immediately clears all the orders. (safe HMI required)
    /// Supervisor is not in control of the AGV. Supervisor doesn’t send driving order or actions to the AGV. Authorized personal can reconfigure the AGV.
    pub const MANUAL: &'static str = "MANUAL";

    /// Supervisor is not in control of the AGV. Supervisor doesn’t send driving order or actions to the AGV. The AGV is being taught, e.g. mapping is done by a supervisor
    pub const SERVICE: &'static str = "SERVICE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TEACHIN: &'static str = "TEACHIN";

}


impl Default for OrderState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::OrderState::default())
  }
}

impl rosidl_runtime_rs::Message for OrderState {
  type RmwMsg = super::msg::rmw::OrderState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        order_id: msg.order_id.as_str().into(),
        order_update_id: msg.order_update_id,
        zone_set_id: msg.zone_set_id.as_str().into(),
        last_node_id: msg.last_node_id.as_str().into(),
        last_node_sequence_id: msg.last_node_sequence_id,
        node_states: msg.node_states
          .into_iter()
          .map(|elem| super::msg::NodeState::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        edge_states: msg.edge_states
          .into_iter()
          .map(|elem| super::msg::EdgeState::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        agv_position: super::msg::AGVPosition::into_rmw_message(std::borrow::Cow::Owned(msg.agv_position)).into_owned(),
        velocity: super::msg::Velocity::into_rmw_message(std::borrow::Cow::Owned(msg.velocity)).into_owned(),
        loads: msg.loads
          .into_iter()
          .map(|elem| super::msg::Load::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        driving: msg.driving,
        paused: msg.paused,
        new_base_request: msg.new_base_request,
        distance_since_last_node: msg.distance_since_last_node,
        action_states: msg.action_states
          .into_iter()
          .map(|elem| super::msg::CurrentAction::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        battery_state: super::msg::BatteryState::into_rmw_message(std::borrow::Cow::Owned(msg.battery_state)).into_owned(),
        operating_mode: msg.operating_mode.as_str().into(),
        errors: msg.errors
          .into_iter()
          .map(|elem| super::msg::Error::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        informations: msg.informations
          .into_iter()
          .map(|elem| super::msg::Info::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        safety_state: super::msg::SafetyState::into_rmw_message(std::borrow::Cow::Owned(msg.safety_state)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        order_id: msg.order_id.as_str().into(),
      order_update_id: msg.order_update_id,
        zone_set_id: msg.zone_set_id.as_str().into(),
        last_node_id: msg.last_node_id.as_str().into(),
      last_node_sequence_id: msg.last_node_sequence_id,
        node_states: msg.node_states
          .iter()
          .map(|elem| super::msg::NodeState::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        edge_states: msg.edge_states
          .iter()
          .map(|elem| super::msg::EdgeState::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        agv_position: super::msg::AGVPosition::into_rmw_message(std::borrow::Cow::Borrowed(&msg.agv_position)).into_owned(),
        velocity: super::msg::Velocity::into_rmw_message(std::borrow::Cow::Borrowed(&msg.velocity)).into_owned(),
        loads: msg.loads
          .iter()
          .map(|elem| super::msg::Load::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      driving: msg.driving,
      paused: msg.paused,
      new_base_request: msg.new_base_request,
      distance_since_last_node: msg.distance_since_last_node,
        action_states: msg.action_states
          .iter()
          .map(|elem| super::msg::CurrentAction::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        battery_state: super::msg::BatteryState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.battery_state)).into_owned(),
        operating_mode: msg.operating_mode.as_str().into(),
        errors: msg.errors
          .iter()
          .map(|elem| super::msg::Error::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        informations: msg.informations
          .iter()
          .map(|elem| super::msg::Info::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        safety_state: super::msg::SafetyState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.safety_state)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header_id: msg.header_id,
      timestamp: msg.timestamp.to_string(),
      version: msg.version.to_string(),
      manufacturer: msg.manufacturer.to_string(),
      serial_number: msg.serial_number.to_string(),
      order_id: msg.order_id.to_string(),
      order_update_id: msg.order_update_id,
      zone_set_id: msg.zone_set_id.to_string(),
      last_node_id: msg.last_node_id.to_string(),
      last_node_sequence_id: msg.last_node_sequence_id,
      node_states: msg.node_states
          .into_iter()
          .map(super::msg::NodeState::from_rmw_message)
          .collect(),
      edge_states: msg.edge_states
          .into_iter()
          .map(super::msg::EdgeState::from_rmw_message)
          .collect(),
      agv_position: super::msg::AGVPosition::from_rmw_message(msg.agv_position),
      velocity: super::msg::Velocity::from_rmw_message(msg.velocity),
      loads: msg.loads
          .into_iter()
          .map(super::msg::Load::from_rmw_message)
          .collect(),
      driving: msg.driving,
      paused: msg.paused,
      new_base_request: msg.new_base_request,
      distance_since_last_node: msg.distance_since_last_node,
      action_states: msg.action_states
          .into_iter()
          .map(super::msg::CurrentAction::from_rmw_message)
          .collect(),
      battery_state: super::msg::BatteryState::from_rmw_message(msg.battery_state),
      operating_mode: msg.operating_mode.to_string(),
      errors: msg.errors
          .into_iter()
          .map(super::msg::Error::from_rmw_message)
          .collect(),
      informations: msg.informations
          .into_iter()
          .map(super::msg::Info::from_rmw_message)
          .collect(),
      safety_state: super::msg::SafetyState::from_rmw_message(msg.safety_state),
    }
  }
}


// Corresponds to vda5050_msgs__msg__PhysicalParameters

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PhysicalParameters {
    /// Minimal controlled continuous speed of the AGV
    pub speed_min: f64,

    /// Maximum speed of the AGV
    pub speed_max: f64,

    /// Maximum acceleration with maximum load
    pub acceleration_max: f64,

    /// Maximum deceleration with maximum load
    pub deceleration_max: f64,

    /// Minimum height of the AGV
    pub height_min: f64,

    /// Maximum height of the AGV
    pub height_max: f64,

    /// Width of the AGV
    pub width: f64,

    /// Length of the AGV
    pub length: f64,

}



impl Default for PhysicalParameters {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::PhysicalParameters::default())
  }
}

impl rosidl_runtime_rs::Message for PhysicalParameters {
  type RmwMsg = super::msg::rmw::PhysicalParameters;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        speed_min: msg.speed_min,
        speed_max: msg.speed_max,
        acceleration_max: msg.acceleration_max,
        deceleration_max: msg.deceleration_max,
        height_min: msg.height_min,
        height_max: msg.height_max,
        width: msg.width,
        length: msg.length,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      speed_min: msg.speed_min,
      speed_max: msg.speed_max,
      acceleration_max: msg.acceleration_max,
      deceleration_max: msg.deceleration_max,
      height_min: msg.height_min,
      height_max: msg.height_max,
      width: msg.width,
      length: msg.length,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      speed_min: msg.speed_min,
      speed_max: msg.speed_max,
      acceleration_max: msg.acceleration_max,
      deceleration_max: msg.deceleration_max,
      height_min: msg.height_min,
      height_max: msg.height_max,
      width: msg.width,
      length: msg.length,
    }
  }
}


// Corresponds to vda5050_msgs__msg__PolygonPoint

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PolygonPoint {
    /// x-position of polygon-point
    pub x: f64,

    /// y-position of polygon-point
    pub y: f64,

}



impl Default for PolygonPoint {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::PolygonPoint::default())
  }
}

impl rosidl_runtime_rs::Message for PolygonPoint {
  type RmwMsg = super::msg::rmw::PolygonPoint;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
    }
  }
}


// Corresponds to vda5050_msgs__msg__Position

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Position {
    /// x-position in AGV-coordinate system
    pub x: f64,

    /// y-position in AGV-coordinate system
    pub y: f64,

    /// orientation of wheel in AGV-coordinate system - necessary for fixed wheels
    pub theta: f64,

}



impl Default for Position {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Position::default())
  }
}

impl rosidl_runtime_rs::Message for Position {
  type RmwMsg = super::msg::rmw::Position;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        theta: msg.theta,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
    }
  }
}


// Corresponds to vda5050_msgs__msg__ProtocolFeatures

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProtocolFeatures {
    /// List of supported and/or required optional parameters
    pub optional_parameters: Vec<super::msg::OptionalParameter>,

    /// List of all actions with parameters supported by this AGV
    pub agv_actions: Vec<super::msg::AGVAction>,

}



impl Default for ProtocolFeatures {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ProtocolFeatures::default())
  }
}

impl rosidl_runtime_rs::Message for ProtocolFeatures {
  type RmwMsg = super::msg::rmw::ProtocolFeatures;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        optional_parameters: msg.optional_parameters
          .into_iter()
          .map(|elem| super::msg::OptionalParameter::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        agv_actions: msg.agv_actions
          .into_iter()
          .map(|elem| super::msg::AGVAction::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        optional_parameters: msg.optional_parameters
          .iter()
          .map(|elem| super::msg::OptionalParameter::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        agv_actions: msg.agv_actions
          .iter()
          .map(|elem| super::msg::AGVAction::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      optional_parameters: msg.optional_parameters
          .into_iter()
          .map(super::msg::OptionalParameter::from_rmw_message)
          .collect(),
      agv_actions: msg.agv_actions
          .into_iter()
          .map(super::msg::AGVAction::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__ProtocolLimits

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ProtocolLimits {
    /// Maximum lengths of strings
    pub max_string_lens: super::msg::MaxStringLens,

    /// Maximum lengths of arrays
    pub max_array_lens: super::msg::MaxArrayLens,

    /// Timing information
    pub timing: super::msg::Timing,

}



impl Default for ProtocolLimits {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ProtocolLimits::default())
  }
}

impl rosidl_runtime_rs::Message for ProtocolLimits {
  type RmwMsg = super::msg::rmw::ProtocolLimits;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        max_string_lens: super::msg::MaxStringLens::into_rmw_message(std::borrow::Cow::Owned(msg.max_string_lens)).into_owned(),
        max_array_lens: super::msg::MaxArrayLens::into_rmw_message(std::borrow::Cow::Owned(msg.max_array_lens)).into_owned(),
        timing: super::msg::Timing::into_rmw_message(std::borrow::Cow::Owned(msg.timing)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        max_string_lens: super::msg::MaxStringLens::into_rmw_message(std::borrow::Cow::Borrowed(&msg.max_string_lens)).into_owned(),
        max_array_lens: super::msg::MaxArrayLens::into_rmw_message(std::borrow::Cow::Borrowed(&msg.max_array_lens)).into_owned(),
        timing: super::msg::Timing::into_rmw_message(std::borrow::Cow::Borrowed(&msg.timing)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      max_string_lens: super::msg::MaxStringLens::from_rmw_message(msg.max_string_lens),
      max_array_lens: super::msg::MaxArrayLens::from_rmw_message(msg.max_array_lens),
      timing: super::msg::Timing::from_rmw_message(msg.timing),
    }
  }
}


// Corresponds to vda5050_msgs__msg__SafetyState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SafetyState {
    /// Enum {autoAck, manual, remote, none} Acknowledge-Type of eStop:
    /// autoAck: autoacknowledgeable e-stop is activated e.g. by bumper or protective field
    /// manual: e-stop has to be acknowledged manually at the vehicle
    /// remote: facility estop has to be acknowledged remotely
    /// none: no e-stop activated
    pub e_stop: std::string::String,

    /// Protective field violation. True: field is violated False: field is not violated
    pub field_violation: bool,

}

impl SafetyState {
    /// Enums for eStop
    pub const AUTO_ACK: &'static str = "AUTOACK";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MANUAL: &'static str = "MANUAL";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const REMOTE: &'static str = "REMOTE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NONE: &'static str = "NONE";

}


impl Default for SafetyState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SafetyState::default())
  }
}

impl rosidl_runtime_rs::Message for SafetyState {
  type RmwMsg = super::msg::rmw::SafetyState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        e_stop: msg.e_stop.as_str().into(),
        field_violation: msg.field_violation,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        e_stop: msg.e_stop.as_str().into(),
      field_violation: msg.field_violation,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      e_stop: msg.e_stop.to_string(),
      field_violation: msg.field_violation,
    }
  }
}


// Corresponds to vda5050_msgs__msg__Timing

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Timing {
    /// Minimum interval for sending order messages to the AGV
    pub min_order_interval: f32,

    /// Minimum interval for sending state messages to the AGV
    pub min_state_interval: f32,

    /// Default interval for sending state messages if not defined
    pub default_state_interval: f32,

    /// Default interval for sending on visualization topic
    pub visualization_interval: f32,

}



impl Default for Timing {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Timing::default())
  }
}

impl rosidl_runtime_rs::Message for Timing {
  type RmwMsg = super::msg::rmw::Timing;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        min_order_interval: msg.min_order_interval,
        min_state_interval: msg.min_state_interval,
        default_state_interval: msg.default_state_interval,
        visualization_interval: msg.visualization_interval,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      min_order_interval: msg.min_order_interval,
      min_state_interval: msg.min_state_interval,
      default_state_interval: msg.default_state_interval,
      visualization_interval: msg.visualization_interval,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      min_order_interval: msg.min_order_interval,
      min_state_interval: msg.min_state_interval,
      default_state_interval: msg.default_state_interval,
      visualization_interval: msg.visualization_interval,
    }
  }
}


// Corresponds to vda5050_msgs__msg__Trajectory
/// Points defining a spline. Theta allows holonomic vehicles to rotate along the trajecotry.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Trajectory {
    /// Range: [1 … infinity) Defines the number of control points that influence
    /// any given point on the curve. Increasing the degree increases continuity.
    /// If not defined, the default value is 1.
    pub degree: f64,

    /// Range: Sequence of parameter values that determines where and
    /// how the control points affect the NURBS curve. knot_vector has size of number
    /// of control points + degree + 1.
    pub knot_vector: Vec<f64>,

    /// List of JSON control_point objects defining the control points of the nurbs,
    /// which includes the beginning and end point.
    pub control_points: Vec<super::msg::ControlPoint>,

}



impl Default for Trajectory {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Trajectory::default())
  }
}

impl rosidl_runtime_rs::Message for Trajectory {
  type RmwMsg = super::msg::rmw::Trajectory;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        degree: msg.degree,
        knot_vector: msg.knot_vector.into(),
        control_points: msg.control_points
          .into_iter()
          .map(|elem| super::msg::ControlPoint::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      degree: msg.degree,
        knot_vector: msg.knot_vector.as_slice().into(),
        control_points: msg.control_points
          .iter()
          .map(|elem| super::msg::ControlPoint::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      degree: msg.degree,
      knot_vector: msg.knot_vector
          .into_iter()
          .collect(),
      control_points: msg.control_points
          .into_iter()
          .map(super::msg::ControlPoint::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__TypeSpecification

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TypeSpecification {
    /// Generalized series name as specified by manufacturer
    pub series_name: std::string::String,

    /// Human readable description of the AGV type series
    pub series_description: std::string::String,

    /// Simplified description of AGV kinematics-type
    pub agv_kinematic: std::string::String,

    /// Simplified description of AGV class
    pub agv_class: std::string::String,

    /// Maximum loadable mass
    pub max_load_mass: f64,

    /// Simplified description of localization type
    pub localization_types: Vec<std::string::String>,

    /// Path planning types supported by the AGV, sorted by priority
    pub navigation_types: Vec<std::string::String>,

}

impl TypeSpecification {
    /// Enums for agv_kinematic
    pub const DIFF: &'static str = "DIFF";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const OMNI: &'static str = "OMNI";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const THREEWHEEL: &'static str = "THREEWHEEL";

    /// Enums for agv_class
    pub const FORKLIFT: &'static str = "FORKLIFT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CONVEYOR: &'static str = "CONVEYOR";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TUGGER: &'static str = "TUGGER";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CARRIER: &'static str = "CARRIER";

    /// Enums for localization_types
    pub const NATURAL: &'static str = "NATURAL";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const REFLECTOR: &'static str = "REFLECTOR";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RFID: &'static str = "RFID";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DMC: &'static str = "DMC";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const SPOT: &'static str = "SPOT";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const GRID: &'static str = "GRID";

    /// Enums for navigation_types
    pub const PHYSICAL_LINE_GUIDED: &'static str = "PHYSICAL_LINE_GUIDED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VIRTUAL_LINE_GUIDED: &'static str = "VIRTUAL_LINE_GUIDED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const AUTONOMOUS: &'static str = "AUTONOMOUS";

}


impl Default for TypeSpecification {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::TypeSpecification::default())
  }
}

impl rosidl_runtime_rs::Message for TypeSpecification {
  type RmwMsg = super::msg::rmw::TypeSpecification;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        series_name: msg.series_name.as_str().into(),
        series_description: msg.series_description.as_str().into(),
        agv_kinematic: msg.agv_kinematic.as_str().into(),
        agv_class: msg.agv_class.as_str().into(),
        max_load_mass: msg.max_load_mass,
        localization_types: msg.localization_types
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        navigation_types: msg.navigation_types
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        series_name: msg.series_name.as_str().into(),
        series_description: msg.series_description.as_str().into(),
        agv_kinematic: msg.agv_kinematic.as_str().into(),
        agv_class: msg.agv_class.as_str().into(),
      max_load_mass: msg.max_load_mass,
        localization_types: msg.localization_types
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        navigation_types: msg.navigation_types
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      series_name: msg.series_name.to_string(),
      series_description: msg.series_description.to_string(),
      agv_kinematic: msg.agv_kinematic.to_string(),
      agv_class: msg.agv_class.to_string(),
      max_load_mass: msg.max_load_mass,
      localization_types: msg.localization_types
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      navigation_types: msg.navigation_types
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
    }
  }
}


// Corresponds to vda5050_msgs__msg__Velocity

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Velocity {
    /// forward velocity
    pub vx: f64,

    /// sideways velocity
    pub vy: f64,

    /// rotational velocity
    pub omega: f64,

}



impl Default for Velocity {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Velocity::default())
  }
}

impl rosidl_runtime_rs::Message for Velocity {
  type RmwMsg = super::msg::rmw::Velocity;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        vx: msg.vx,
        vy: msg.vy,
        omega: msg.omega,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      vx: msg.vx,
      vy: msg.vy,
      omega: msg.omega,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      vx: msg.vx,
      vy: msg.vy,
      omega: msg.omega,
    }
  }
}


// Corresponds to vda5050_msgs__msg__Visualization
/// HEADER

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Visualization {
    /// header ID of the message. The headerId is defined per topic and incremented by 1 with each sent
    /// (but not necessarily received) message.
    pub header_id: u32,

    /// Timestamp after ISO8601 in the format YYYY-MM-DDTHH:mm:ss.ssZ (e.g.“2017-04-15T11:40:03.12Z”)
    pub timestamp: std::string::String,

    /// Version of the protocol [Major].[Minor].[Patch] (e.g. 1.3.2)
    pub version: std::string::String,

    /// Manufacturer of the AGV
    pub manufacturer: std::string::String,

    /// Serial Number of the AGV
    pub serial_number: std::string::String,

    /// CONTENTS
    /// The AGV's position
    pub agv_position: super::msg::AGVPosition,

    /// The AGV's velocity in vehicle coordinates
    pub velocity: super::msg::Velocity,

}



impl Default for Visualization {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Visualization::default())
  }
}

impl rosidl_runtime_rs::Message for Visualization {
  type RmwMsg = super::msg::rmw::Visualization;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        agv_position: super::msg::AGVPosition::into_rmw_message(std::borrow::Cow::Owned(msg.agv_position)).into_owned(),
        velocity: super::msg::Velocity::into_rmw_message(std::borrow::Cow::Owned(msg.velocity)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      header_id: msg.header_id,
        timestamp: msg.timestamp.as_str().into(),
        version: msg.version.as_str().into(),
        manufacturer: msg.manufacturer.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        agv_position: super::msg::AGVPosition::into_rmw_message(std::borrow::Cow::Borrowed(&msg.agv_position)).into_owned(),
        velocity: super::msg::Velocity::into_rmw_message(std::borrow::Cow::Borrowed(&msg.velocity)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header_id: msg.header_id,
      timestamp: msg.timestamp.to_string(),
      version: msg.version.to_string(),
      manufacturer: msg.manufacturer.to_string(),
      serial_number: msg.serial_number.to_string(),
      agv_position: super::msg::AGVPosition::from_rmw_message(msg.agv_position),
      velocity: super::msg::Velocity::from_rmw_message(msg.velocity),
    }
  }
}


// Corresponds to vda5050_msgs__msg__WheelDefinition

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct WheelDefinition {
    /// Wheel type
    pub type_: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_active_driven: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_active_steered: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub position: super::msg::Position,

    /// Nominal diameter of the wheel
    pub diameter: f64,

    /// Nominal width of the wheel
    pub width: f64,

    /// Nominal displacement of the wheel’s center to the rotation point
    pub center_displacement: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub constraints: std::string::String,

}

impl WheelDefinition {
    /// Enums for wheel type
    pub const DRIVE: &'static str = "DRIVE";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CASTER: &'static str = "CASTER";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FIXED: &'static str = "FIXED";


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MECANUM: &'static str = "MECANUM";

}


impl Default for WheelDefinition {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::WheelDefinition::default())
  }
}

impl rosidl_runtime_rs::Message for WheelDefinition {
  type RmwMsg = super::msg::rmw::WheelDefinition;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_: msg.type_.as_str().into(),
        is_active_driven: msg.is_active_driven,
        is_active_steered: msg.is_active_steered,
        position: super::msg::Position::into_rmw_message(std::borrow::Cow::Owned(msg.position)).into_owned(),
        diameter: msg.diameter,
        width: msg.width,
        center_displacement: msg.center_displacement,
        constraints: msg.constraints.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_: msg.type_.as_str().into(),
      is_active_driven: msg.is_active_driven,
      is_active_steered: msg.is_active_steered,
        position: super::msg::Position::into_rmw_message(std::borrow::Cow::Borrowed(&msg.position)).into_owned(),
      diameter: msg.diameter,
      width: msg.width,
      center_displacement: msg.center_displacement,
        constraints: msg.constraints.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      type_: msg.type_.to_string(),
      is_active_driven: msg.is_active_driven,
      is_active_steered: msg.is_active_steered,
      position: super::msg::Position::from_rmw_message(msg.position),
      diameter: msg.diameter,
      width: msg.width,
      center_displacement: msg.center_displacement,
      constraints: msg.constraints.to_string(),
    }
  }
}


