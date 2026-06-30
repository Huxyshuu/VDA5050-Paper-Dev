# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/AGVPosition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AGVPosition(type):
    """Metaclass of message 'AGVPosition'."""

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
                'vda5050_msgs.msg.AGVPosition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__agv_position
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__agv_position
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__agv_position
            cls._TYPE_SUPPORT = module.type_support_msg__msg__agv_position
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__agv_position

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AGVPosition(metaclass=Metaclass_AGVPosition):
    """Message class 'AGVPosition'."""

    __slots__ = [
        '_position_initialized',
        '_localization_score',
        '_deviation_range',
        '_x',
        '_y',
        '_theta',
        '_map_id',
        '_map_description',
    ]

    _fields_and_field_types = {
        'position_initialized': 'boolean',
        'localization_score': 'double',
        'deviation_range': 'double',
        'x': 'double',
        'y': 'double',
        'theta': 'double',
        'map_id': 'string',
        'map_description': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.position_initialized = kwargs.get('position_initialized', bool())
        self.localization_score = kwargs.get('localization_score', float())
        self.deviation_range = kwargs.get('deviation_range', float())
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.theta = kwargs.get('theta', float())
        self.map_id = kwargs.get('map_id', str())
        self.map_description = kwargs.get('map_description', str())

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
        if self.position_initialized != other.position_initialized:
            return False
        if self.localization_score != other.localization_score:
            return False
        if self.deviation_range != other.deviation_range:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.theta != other.theta:
            return False
        if self.map_id != other.map_id:
            return False
        if self.map_description != other.map_description:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def position_initialized(self):
        """Message field 'position_initialized'."""
        return self._position_initialized

    @position_initialized.setter
    def position_initialized(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'position_initialized' field must be of type 'bool'"
        self._position_initialized = value

    @builtins.property
    def localization_score(self):
        """Message field 'localization_score'."""
        return self._localization_score

    @localization_score.setter
    def localization_score(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'localization_score' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'localization_score' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._localization_score = value

    @builtins.property
    def deviation_range(self):
        """Message field 'deviation_range'."""
        return self._deviation_range

    @deviation_range.setter
    def deviation_range(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'deviation_range' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'deviation_range' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._deviation_range = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y = value

    @builtins.property
    def theta(self):
        """Message field 'theta'."""
        return self._theta

    @theta.setter
    def theta(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'theta' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'theta' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._theta = value

    @builtins.property
    def map_id(self):
        """Message field 'map_id'."""
        return self._map_id

    @map_id.setter
    def map_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'map_id' field must be of type 'str'"
        self._map_id = value

    @builtins.property
    def map_description(self):
        """Message field 'map_description'."""
        return self._map_description

    @map_description.setter
    def map_description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'map_description' field must be of type 'str'"
        self._map_description = value
