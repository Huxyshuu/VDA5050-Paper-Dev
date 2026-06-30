# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/PhysicalParameters.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PhysicalParameters(type):
    """Metaclass of message 'PhysicalParameters'."""

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
                'vda5050_msgs.msg.PhysicalParameters')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__physical_parameters
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__physical_parameters
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__physical_parameters
            cls._TYPE_SUPPORT = module.type_support_msg__msg__physical_parameters
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__physical_parameters

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PhysicalParameters(metaclass=Metaclass_PhysicalParameters):
    """Message class 'PhysicalParameters'."""

    __slots__ = [
        '_speed_min',
        '_speed_max',
        '_acceleration_max',
        '_deceleration_max',
        '_height_min',
        '_height_max',
        '_width',
        '_length',
    ]

    _fields_and_field_types = {
        'speed_min': 'double',
        'speed_max': 'double',
        'acceleration_max': 'double',
        'deceleration_max': 'double',
        'height_min': 'double',
        'height_max': 'double',
        'width': 'double',
        'length': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.speed_min = kwargs.get('speed_min', float())
        self.speed_max = kwargs.get('speed_max', float())
        self.acceleration_max = kwargs.get('acceleration_max', float())
        self.deceleration_max = kwargs.get('deceleration_max', float())
        self.height_min = kwargs.get('height_min', float())
        self.height_max = kwargs.get('height_max', float())
        self.width = kwargs.get('width', float())
        self.length = kwargs.get('length', float())

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
        if self.speed_min != other.speed_min:
            return False
        if self.speed_max != other.speed_max:
            return False
        if self.acceleration_max != other.acceleration_max:
            return False
        if self.deceleration_max != other.deceleration_max:
            return False
        if self.height_min != other.height_min:
            return False
        if self.height_max != other.height_max:
            return False
        if self.width != other.width:
            return False
        if self.length != other.length:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def speed_min(self):
        """Message field 'speed_min'."""
        return self._speed_min

    @speed_min.setter
    def speed_min(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed_min' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed_min' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed_min = value

    @builtins.property
    def speed_max(self):
        """Message field 'speed_max'."""
        return self._speed_max

    @speed_max.setter
    def speed_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed_max' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed_max' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed_max = value

    @builtins.property
    def acceleration_max(self):
        """Message field 'acceleration_max'."""
        return self._acceleration_max

    @acceleration_max.setter
    def acceleration_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'acceleration_max' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'acceleration_max' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._acceleration_max = value

    @builtins.property
    def deceleration_max(self):
        """Message field 'deceleration_max'."""
        return self._deceleration_max

    @deceleration_max.setter
    def deceleration_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'deceleration_max' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'deceleration_max' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._deceleration_max = value

    @builtins.property
    def height_min(self):
        """Message field 'height_min'."""
        return self._height_min

    @height_min.setter
    def height_min(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'height_min' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'height_min' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._height_min = value

    @builtins.property
    def height_max(self):
        """Message field 'height_max'."""
        return self._height_max

    @height_max.setter
    def height_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'height_max' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'height_max' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._height_max = value

    @builtins.property
    def width(self):
        """Message field 'width'."""
        return self._width

    @width.setter
    def width(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'width' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'width' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._width = value

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
