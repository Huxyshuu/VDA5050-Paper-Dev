# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/OrderState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_OrderState(type):
    """Metaclass of message 'OrderState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'AUTOMATIC': 'AUTOMATIC',
        'SEMIAUTOMATIC': 'SEMIAUTOMATIC',
        'MANUAL': 'MANUAL',
        'SERVICE': 'SERVICE',
        'TEACHIN': 'TEACHIN',
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vda5050_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vda5050_msgs.msg.OrderState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__order_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__order_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__order_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__order_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__order_state

            from vda5050_msgs.msg import AGVPosition
            if AGVPosition.__class__._TYPE_SUPPORT is None:
                AGVPosition.__class__.__import_type_support__()

            from vda5050_msgs.msg import BatteryState
            if BatteryState.__class__._TYPE_SUPPORT is None:
                BatteryState.__class__.__import_type_support__()

            from vda5050_msgs.msg import CurrentAction
            if CurrentAction.__class__._TYPE_SUPPORT is None:
                CurrentAction.__class__.__import_type_support__()

            from vda5050_msgs.msg import EdgeState
            if EdgeState.__class__._TYPE_SUPPORT is None:
                EdgeState.__class__.__import_type_support__()

            from vda5050_msgs.msg import Error
            if Error.__class__._TYPE_SUPPORT is None:
                Error.__class__.__import_type_support__()

            from vda5050_msgs.msg import Info
            if Info.__class__._TYPE_SUPPORT is None:
                Info.__class__.__import_type_support__()

            from vda5050_msgs.msg import Load
            if Load.__class__._TYPE_SUPPORT is None:
                Load.__class__.__import_type_support__()

            from vda5050_msgs.msg import NodeState
            if NodeState.__class__._TYPE_SUPPORT is None:
                NodeState.__class__.__import_type_support__()

            from vda5050_msgs.msg import SafetyState
            if SafetyState.__class__._TYPE_SUPPORT is None:
                SafetyState.__class__.__import_type_support__()

            from vda5050_msgs.msg import Velocity
            if Velocity.__class__._TYPE_SUPPORT is None:
                Velocity.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'AUTOMATIC': cls.__constants['AUTOMATIC'],
            'SEMIAUTOMATIC': cls.__constants['SEMIAUTOMATIC'],
            'MANUAL': cls.__constants['MANUAL'],
            'SERVICE': cls.__constants['SERVICE'],
            'TEACHIN': cls.__constants['TEACHIN'],
        }

    @property
    def AUTOMATIC(self):
        """Message constant 'AUTOMATIC'."""
        return Metaclass_OrderState.__constants['AUTOMATIC']

    @property
    def SEMIAUTOMATIC(self):
        """Message constant 'SEMIAUTOMATIC'."""
        return Metaclass_OrderState.__constants['SEMIAUTOMATIC']

    @property
    def MANUAL(self):
        """Message constant 'MANUAL'."""
        return Metaclass_OrderState.__constants['MANUAL']

    @property
    def SERVICE(self):
        """Message constant 'SERVICE'."""
        return Metaclass_OrderState.__constants['SERVICE']

    @property
    def TEACHIN(self):
        """Message constant 'TEACHIN'."""
        return Metaclass_OrderState.__constants['TEACHIN']


class OrderState(metaclass=Metaclass_OrderState):
    """
    Message class 'OrderState'.

    Constants:
      AUTOMATIC
      SEMIAUTOMATIC
      MANUAL
      SERVICE
      TEACHIN
    """

    __slots__ = [
        '_header_id',
        '_timestamp',
        '_version',
        '_manufacturer',
        '_serial_number',
        '_order_id',
        '_order_update_id',
        '_zone_set_id',
        '_last_node_id',
        '_last_node_sequence_id',
        '_node_states',
        '_edge_states',
        '_agv_position',
        '_velocity',
        '_loads',
        '_driving',
        '_paused',
        '_new_base_request',
        '_distance_since_last_node',
        '_action_states',
        '_battery_state',
        '_operating_mode',
        '_errors',
        '_informations',
        '_safety_state',
    ]

    _fields_and_field_types = {
        'header_id': 'uint32',
        'timestamp': 'string',
        'version': 'string',
        'manufacturer': 'string',
        'serial_number': 'string',
        'order_id': 'string',
        'order_update_id': 'uint32',
        'zone_set_id': 'string',
        'last_node_id': 'string',
        'last_node_sequence_id': 'uint32',
        'node_states': 'sequence<vda5050_msgs/NodeState>',
        'edge_states': 'sequence<vda5050_msgs/EdgeState>',
        'agv_position': 'vda5050_msgs/AGVPosition',
        'velocity': 'vda5050_msgs/Velocity',
        'loads': 'sequence<vda5050_msgs/Load>',
        'driving': 'boolean',
        'paused': 'boolean',
        'new_base_request': 'boolean',
        'distance_since_last_node': 'double',
        'action_states': 'sequence<vda5050_msgs/CurrentAction>',
        'battery_state': 'vda5050_msgs/BatteryState',
        'operating_mode': 'string',
        'errors': 'sequence<vda5050_msgs/Error>',
        'informations': 'sequence<vda5050_msgs/Info>',
        'safety_state': 'vda5050_msgs/SafetyState',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'NodeState')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'EdgeState')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'AGVPosition'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'Velocity'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'Load')),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'CurrentAction')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'BatteryState'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'Error')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'Info')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'SafetyState'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.header_id = kwargs.get('header_id', int())
        self.timestamp = kwargs.get('timestamp', str())
        self.version = kwargs.get('version', str())
        self.manufacturer = kwargs.get('manufacturer', str())
        self.serial_number = kwargs.get('serial_number', str())
        self.order_id = kwargs.get('order_id', str())
        self.order_update_id = kwargs.get('order_update_id', int())
        self.zone_set_id = kwargs.get('zone_set_id', str())
        self.last_node_id = kwargs.get('last_node_id', str())
        self.last_node_sequence_id = kwargs.get('last_node_sequence_id', int())
        self.node_states = kwargs.get('node_states', [])
        self.edge_states = kwargs.get('edge_states', [])
        from vda5050_msgs.msg import AGVPosition
        self.agv_position = kwargs.get('agv_position', AGVPosition())
        from vda5050_msgs.msg import Velocity
        self.velocity = kwargs.get('velocity', Velocity())
        self.loads = kwargs.get('loads', [])
        self.driving = kwargs.get('driving', bool())
        self.paused = kwargs.get('paused', bool())
        self.new_base_request = kwargs.get('new_base_request', bool())
        self.distance_since_last_node = kwargs.get('distance_since_last_node', float())
        self.action_states = kwargs.get('action_states', [])
        from vda5050_msgs.msg import BatteryState
        self.battery_state = kwargs.get('battery_state', BatteryState())
        self.operating_mode = kwargs.get('operating_mode', str())
        self.errors = kwargs.get('errors', [])
        self.informations = kwargs.get('informations', [])
        from vda5050_msgs.msg import SafetyState
        self.safety_state = kwargs.get('safety_state', SafetyState())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header_id != other.header_id:
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.version != other.version:
            return False
        if self.manufacturer != other.manufacturer:
            return False
        if self.serial_number != other.serial_number:
            return False
        if self.order_id != other.order_id:
            return False
        if self.order_update_id != other.order_update_id:
            return False
        if self.zone_set_id != other.zone_set_id:
            return False
        if self.last_node_id != other.last_node_id:
            return False
        if self.last_node_sequence_id != other.last_node_sequence_id:
            return False
        if self.node_states != other.node_states:
            return False
        if self.edge_states != other.edge_states:
            return False
        if self.agv_position != other.agv_position:
            return False
        if self.velocity != other.velocity:
            return False
        if self.loads != other.loads:
            return False
        if self.driving != other.driving:
            return False
        if self.paused != other.paused:
            return False
        if self.new_base_request != other.new_base_request:
            return False
        if self.distance_since_last_node != other.distance_since_last_node:
            return False
        if self.action_states != other.action_states:
            return False
        if self.battery_state != other.battery_state:
            return False
        if self.operating_mode != other.operating_mode:
            return False
        if self.errors != other.errors:
            return False
        if self.informations != other.informations:
            return False
        if self.safety_state != other.safety_state:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header_id(self):
        """Message field 'header_id'."""
        return self._header_id

    @header_id.setter
    def header_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'header_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'header_id' field must be an unsigned integer in [0, 4294967295]"
        self._header_id = value

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'timestamp' field must be of type 'str'"
        self._timestamp = value

    @builtins.property
    def version(self):
        """Message field 'version'."""
        return self._version

    @version.setter
    def version(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'version' field must be of type 'str'"
        self._version = value

    @builtins.property
    def manufacturer(self):
        """Message field 'manufacturer'."""
        return self._manufacturer

    @manufacturer.setter
    def manufacturer(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'manufacturer' field must be of type 'str'"
        self._manufacturer = value

    @builtins.property
    def serial_number(self):
        """Message field 'serial_number'."""
        return self._serial_number

    @serial_number.setter
    def serial_number(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'serial_number' field must be of type 'str'"
        self._serial_number = value

    @builtins.property
    def order_id(self):
        """Message field 'order_id'."""
        return self._order_id

    @order_id.setter
    def order_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'order_id' field must be of type 'str'"
        self._order_id = value

    @builtins.property
    def order_update_id(self):
        """Message field 'order_update_id'."""
        return self._order_update_id

    @order_update_id.setter
    def order_update_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'order_update_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'order_update_id' field must be an unsigned integer in [0, 4294967295]"
        self._order_update_id = value

    @builtins.property
    def zone_set_id(self):
        """Message field 'zone_set_id'."""
        return self._zone_set_id

    @zone_set_id.setter
    def zone_set_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'zone_set_id' field must be of type 'str'"
        self._zone_set_id = value

    @builtins.property
    def last_node_id(self):
        """Message field 'last_node_id'."""
        return self._last_node_id

    @last_node_id.setter
    def last_node_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'last_node_id' field must be of type 'str'"
        self._last_node_id = value

    @builtins.property
    def last_node_sequence_id(self):
        """Message field 'last_node_sequence_id'."""
        return self._last_node_sequence_id

    @last_node_sequence_id.setter
    def last_node_sequence_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'last_node_sequence_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'last_node_sequence_id' field must be an unsigned integer in [0, 4294967295]"
        self._last_node_sequence_id = value

    @builtins.property
    def node_states(self):
        """Message field 'node_states'."""
        return self._node_states

    @node_states.setter
    def node_states(self, value):
        if __debug__:
            from vda5050_msgs.msg import NodeState
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, NodeState) for v in value) and
                 True), \
                "The 'node_states' field must be a set or sequence and each value of type 'NodeState'"
        self._node_states = value

    @builtins.property
    def edge_states(self):
        """Message field 'edge_states'."""
        return self._edge_states

    @edge_states.setter
    def edge_states(self, value):
        if __debug__:
            from vda5050_msgs.msg import EdgeState
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, EdgeState) for v in value) and
                 True), \
                "The 'edge_states' field must be a set or sequence and each value of type 'EdgeState'"
        self._edge_states = value

    @builtins.property
    def agv_position(self):
        """Message field 'agv_position'."""
        return self._agv_position

    @agv_position.setter
    def agv_position(self, value):
        if __debug__:
            from vda5050_msgs.msg import AGVPosition
            assert \
                isinstance(value, AGVPosition), \
                "The 'agv_position' field must be a sub message of type 'AGVPosition'"
        self._agv_position = value

    @builtins.property
    def velocity(self):
        """Message field 'velocity'."""
        return self._velocity

    @velocity.setter
    def velocity(self, value):
        if __debug__:
            from vda5050_msgs.msg import Velocity
            assert \
                isinstance(value, Velocity), \
                "The 'velocity' field must be a sub message of type 'Velocity'"
        self._velocity = value

    @builtins.property
    def loads(self):
        """Message field 'loads'."""
        return self._loads

    @loads.setter
    def loads(self, value):
        if __debug__:
            from vda5050_msgs.msg import Load
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Load) for v in value) and
                 True), \
                "The 'loads' field must be a set or sequence and each value of type 'Load'"
        self._loads = value

    @builtins.property
    def driving(self):
        """Message field 'driving'."""
        return self._driving

    @driving.setter
    def driving(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'driving' field must be of type 'bool'"
        self._driving = value

    @builtins.property
    def paused(self):
        """Message field 'paused'."""
        return self._paused

    @paused.setter
    def paused(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'paused' field must be of type 'bool'"
        self._paused = value

    @builtins.property
    def new_base_request(self):
        """Message field 'new_base_request'."""
        return self._new_base_request

    @new_base_request.setter
    def new_base_request(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'new_base_request' field must be of type 'bool'"
        self._new_base_request = value

    @builtins.property
    def distance_since_last_node(self):
        """Message field 'distance_since_last_node'."""
        return self._distance_since_last_node

    @distance_since_last_node.setter
    def distance_since_last_node(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance_since_last_node' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'distance_since_last_node' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._distance_since_last_node = value

    @builtins.property
    def action_states(self):
        """Message field 'action_states'."""
        return self._action_states

    @action_states.setter
    def action_states(self, value):
        if __debug__:
            from vda5050_msgs.msg import CurrentAction
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, CurrentAction) for v in value) and
                 True), \
                "The 'action_states' field must be a set or sequence and each value of type 'CurrentAction'"
        self._action_states = value

    @builtins.property
    def battery_state(self):
        """Message field 'battery_state'."""
        return self._battery_state

    @battery_state.setter
    def battery_state(self, value):
        if __debug__:
            from vda5050_msgs.msg import BatteryState
            assert \
                isinstance(value, BatteryState), \
                "The 'battery_state' field must be a sub message of type 'BatteryState'"
        self._battery_state = value

    @builtins.property
    def operating_mode(self):
        """Message field 'operating_mode'."""
        return self._operating_mode

    @operating_mode.setter
    def operating_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'operating_mode' field must be of type 'str'"
        self._operating_mode = value

    @builtins.property
    def errors(self):
        """Message field 'errors'."""
        return self._errors

    @errors.setter
    def errors(self, value):
        if __debug__:
            from vda5050_msgs.msg import Error
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Error) for v in value) and
                 True), \
                "The 'errors' field must be a set or sequence and each value of type 'Error'"
        self._errors = value

    @builtins.property
    def informations(self):
        """Message field 'informations'."""
        return self._informations

    @informations.setter
    def informations(self, value):
        if __debug__:
            from vda5050_msgs.msg import Info
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Info) for v in value) and
                 True), \
                "The 'informations' field must be a set or sequence and each value of type 'Info'"
        self._informations = value

    @builtins.property
    def safety_state(self):
        """Message field 'safety_state'."""
        return self._safety_state

    @safety_state.setter
    def safety_state(self, value):
        if __debug__:
            from vda5050_msgs.msg import SafetyState
            assert \
                isinstance(value, SafetyState), \
                "The 'safety_state' field must be a sub message of type 'SafetyState'"
        self._safety_state = value
