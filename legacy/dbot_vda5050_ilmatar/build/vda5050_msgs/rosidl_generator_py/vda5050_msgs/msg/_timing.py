# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/Timing.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Timing(type):
    """Metaclass of message 'Timing'."""

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
                'vda5050_msgs.msg.Timing')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__timing
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__timing
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__timing
            cls._TYPE_SUPPORT = module.type_support_msg__msg__timing
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__timing

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Timing(metaclass=Metaclass_Timing):
    """Message class 'Timing'."""

    __slots__ = [
        '_min_order_interval',
        '_min_state_interval',
        '_default_state_interval',
        '_visualization_interval',
    ]

    _fields_and_field_types = {
        'min_order_interval': 'float',
        'min_state_interval': 'float',
        'default_state_interval': 'float',
        'visualization_interval': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.min_order_interval = kwargs.get('min_order_interval', float())
        self.min_state_interval = kwargs.get('min_state_interval', float())
        self.default_state_interval = kwargs.get('default_state_interval', float())
        self.visualization_interval = kwargs.get('visualization_interval', float())

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
        if self.min_order_interval != other.min_order_interval:
            return False
        if self.min_state_interval != other.min_state_interval:
            return False
        if self.default_state_interval != other.default_state_interval:
            return False
        if self.visualization_interval != other.visualization_interval:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def min_order_interval(self):
        """Message field 'min_order_interval'."""
        return self._min_order_interval

    @min_order_interval.setter
    def min_order_interval(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'min_order_interval' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'min_order_interval' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._min_order_interval = value

    @builtins.property
    def min_state_interval(self):
        """Message field 'min_state_interval'."""
        return self._min_state_interval

    @min_state_interval.setter
    def min_state_interval(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'min_state_interval' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'min_state_interval' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._min_state_interval = value

    @builtins.property
    def default_state_interval(self):
        """Message field 'default_state_interval'."""
        return self._default_state_interval

    @default_state_interval.setter
    def default_state_interval(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'default_state_interval' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'default_state_interval' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._default_state_interval = value

    @builtins.property
    def visualization_interval(self):
        """Message field 'visualization_interval'."""
        return self._visualization_interval

    @visualization_interval.setter
    def visualization_interval(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'visualization_interval' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'visualization_interval' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._visualization_interval = value
