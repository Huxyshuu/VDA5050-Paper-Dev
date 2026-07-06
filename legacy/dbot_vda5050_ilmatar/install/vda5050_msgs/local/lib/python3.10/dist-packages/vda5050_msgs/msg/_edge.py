# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/Edge.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Edge(type):
    """Metaclass of message 'Edge'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'vda5050_msgs.msg.Edge')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__edge
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__edge
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__edge
            cls._TYPE_SUPPORT = module.type_support_msg__msg__edge
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__edge

            from vda5050_msgs.msg import Action
            if Action.__class__._TYPE_SUPPORT is None:
                Action.__class__.__import_type_support__()

            from vda5050_msgs.msg import Trajectory
            if Trajectory.__class__._TYPE_SUPPORT is None:
                Trajectory.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Edge(metaclass=Metaclass_Edge):
    """Message class 'Edge'."""

    __slots__ = [
        '_edge_id',
        '_sequence_id',
        '_edge_description',
        '_released',
        '_start_node_id',
        '_end_node_id',
        '_max_speed',
        '_max_height',
        '_min_height',
        '_orientation',
        '_direction',
        '_rotation_allowed',
        '_max_rotation_speed',
        '_trajectory',
        '_length',
        '_actions',
    ]

    _fields_and_field_types = {
        'edge_id': 'string',
        'sequence_id': 'uint32',
        'edge_description': 'string',
        'released': 'boolean',
        'start_node_id': 'string',
        'end_node_id': 'string',
        'max_speed': 'double',
        'max_height': 'double',
        'min_height': 'double',
        'orientation': 'double',
        'direction': 'string',
        'rotation_allowed': 'boolean',
        'max_rotation_speed': 'double',
        'trajectory': 'vda5050_msgs/Trajectory',
        'length': 'double',
        'actions': 'sequence<vda5050_msgs/Action>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'Trajectory'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'Action')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.edge_id = kwargs.get('edge_id', str())
        self.sequence_id = kwargs.get('sequence_id', int())
        self.edge_description = kwargs.get('edge_description', str())
        self.released = kwargs.get('released', bool())
        self.start_node_id = kwargs.get('start_node_id', str())
        self.end_node_id = kwargs.get('end_node_id', str())
        self.max_speed = kwargs.get('max_speed', float())
        self.max_height = kwargs.get('max_height', float())
        self.min_height = kwargs.get('min_height', float())
        self.orientation = kwargs.get('orientation', float())
        self.direction = kwargs.get('direction', str())
        self.rotation_allowed = kwargs.get('rotation_allowed', bool())
        self.max_rotation_speed = kwargs.get('max_rotation_speed', float())
        from vda5050_msgs.msg import Trajectory
        self.trajectory = kwargs.get('trajectory', Trajectory())
        self.length = kwargs.get('length', float())
        self.actions = kwargs.get('actions', [])

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
        if self.edge_id != other.edge_id:
            return False
        if self.sequence_id != other.sequence_id:
            return False
        if self.edge_description != other.edge_description:
            return False
        if self.released != other.released:
            return False
        if self.start_node_id != other.start_node_id:
            return False
        if self.end_node_id != other.end_node_id:
            return False
        if self.max_speed != other.max_speed:
            return False
        if self.max_height != other.max_height:
            return False
        if self.min_height != other.min_height:
            return False
        if self.orientation != other.orientation:
            return False
        if self.direction != other.direction:
            return False
        if self.rotation_allowed != other.rotation_allowed:
            return False
        if self.max_rotation_speed != other.max_rotation_speed:
            return False
        if self.trajectory != other.trajectory:
            return False
        if self.length != other.length:
            return False
        if self.actions != other.actions:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def edge_id(self):
        """Message field 'edge_id'."""
        return self._edge_id

    @edge_id.setter
    def edge_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'edge_id' field must be of type 'str'"
        self._edge_id = value

    @builtins.property
    def sequence_id(self):
        """Message field 'sequence_id'."""
        return self._sequence_id

    @sequence_id.setter
    def sequence_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sequence_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'sequence_id' field must be an unsigned integer in [0, 4294967295]"
        self._sequence_id = value

    @builtins.property
    def edge_description(self):
        """Message field 'edge_description'."""
        return self._edge_description

    @edge_description.setter
    def edge_description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'edge_description' field must be of type 'str'"
        self._edge_description = value

    @builtins.property
    def released(self):
        """Message field 'released'."""
        return self._released

    @released.setter
    def released(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'released' field must be of type 'bool'"
        self._released = value

    @builtins.property
    def start_node_id(self):
        """Message field 'start_node_id'."""
        return self._start_node_id

    @start_node_id.setter
    def start_node_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'start_node_id' field must be of type 'str'"
        self._start_node_id = value

    @builtins.property
    def end_node_id(self):
        """Message field 'end_node_id'."""
        return self._end_node_id

    @end_node_id.setter
    def end_node_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'end_node_id' field must be of type 'str'"
        self._end_node_id = value

    @builtins.property
    def max_speed(self):
        """Message field 'max_speed'."""
        return self._max_speed

    @max_speed.setter
    def max_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_speed = value

    @builtins.property
    def max_height(self):
        """Message field 'max_height'."""
        return self._max_height

    @max_height.setter
    def max_height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_height' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_height' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_height = value

    @builtins.property
    def min_height(self):
        """Message field 'min_height'."""
        return self._min_height

    @min_height.setter
    def min_height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'min_height' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'min_height' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._min_height = value

    @builtins.property
    def orientation(self):
        """Message field 'orientation'."""
        return self._orientation

    @orientation.setter
    def orientation(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'orientation' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'orientation' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._orientation = value

    @builtins.property
    def direction(self):
        """Message field 'direction'."""
        return self._direction

    @direction.setter
    def direction(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'direction' field must be of type 'str'"
        self._direction = value

    @builtins.property
    def rotation_allowed(self):
        """Message field 'rotation_allowed'."""
        return self._rotation_allowed

    @rotation_allowed.setter
    def rotation_allowed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'rotation_allowed' field must be of type 'bool'"
        self._rotation_allowed = value

    @builtins.property
    def max_rotation_speed(self):
        """Message field 'max_rotation_speed'."""
        return self._max_rotation_speed

    @max_rotation_speed.setter
    def max_rotation_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_rotation_speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_rotation_speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_rotation_speed = value

    @builtins.property
    def trajectory(self):
        """Message field 'trajectory'."""
        return self._trajectory

    @trajectory.setter
    def trajectory(self, value):
        if __debug__:
            from vda5050_msgs.msg import Trajectory
            assert \
                isinstance(value, Trajectory), \
                "The 'trajectory' field must be a sub message of type 'Trajectory'"
        self._trajectory = value

    @builtins.property
    def length(self):
        """Message field 'length'."""
        return self._length

    @length.setter
    def length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'length' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'length' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._length = value

    @builtins.property
    def actions(self):
        """Message field 'actions'."""
        return self._actions

    @actions.setter
    def actions(self, value):
        if __debug__:
            from vda5050_msgs.msg import Action
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
                 all(isinstance(v, Action) for v in value) and
                 True), \
                "The 'actions' field must be a set or sequence and each value of type 'Action'"
        self._actions = value
