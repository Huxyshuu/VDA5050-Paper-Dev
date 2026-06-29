# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/WheelDefinition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_WheelDefinition(type):
    """Metaclass of message 'WheelDefinition'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'DRIVE': 'DRIVE',
        'CASTER': 'CASTER',
        'FIXED': 'FIXED',
        'MECANUM': 'MECANUM',
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
                'vda5050_msgs.msg.WheelDefinition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__wheel_definition
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__wheel_definition
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__wheel_definition
            cls._TYPE_SUPPORT = module.type_support_msg__msg__wheel_definition
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__wheel_definition

            from vda5050_msgs.msg import Position
            if Position.__class__._TYPE_SUPPORT is None:
                Position.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'DRIVE': cls.__constants['DRIVE'],
            'CASTER': cls.__constants['CASTER'],
            'FIXED': cls.__constants['FIXED'],
            'MECANUM': cls.__constants['MECANUM'],
        }

    @property
    def DRIVE(self):
        """Message constant 'DRIVE'."""
        return Metaclass_WheelDefinition.__constants['DRIVE']

    @property
    def CASTER(self):
        """Message constant 'CASTER'."""
        return Metaclass_WheelDefinition.__constants['CASTER']

    @property
    def FIXED(self):
        """Message constant 'FIXED'."""
        return Metaclass_WheelDefinition.__constants['FIXED']

    @property
    def MECANUM(self):
        """Message constant 'MECANUM'."""
        return Metaclass_WheelDefinition.__constants['MECANUM']


class WheelDefinition(metaclass=Metaclass_WheelDefinition):
    """
    Message class 'WheelDefinition'.

    Constants:
      DRIVE
      CASTER
      FIXED
      MECANUM
    """

    __slots__ = [
        '_type',
        '_is_active_driven',
        '_is_active_steered',
        '_position',
        '_diameter',
        '_width',
        '_center_displacement',
        '_constraints',
    ]

    _fields_and_field_types = {
        'type': 'string',
        'is_active_driven': 'boolean',
        'is_active_steered': 'boolean',
        'position': 'vda5050_msgs/Position',
        'diameter': 'double',
        'width': 'double',
        'center_displacement': 'double',
        'constraints': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'Position'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.type = kwargs.get('type', str())
        self.is_active_driven = kwargs.get('is_active_driven', bool())
        self.is_active_steered = kwargs.get('is_active_steered', bool())
        from vda5050_msgs.msg import Position
        self.position = kwargs.get('position', Position())
        self.diameter = kwargs.get('diameter', float())
        self.width = kwargs.get('width', float())
        self.center_displacement = kwargs.get('center_displacement', float())
        self.constraints = kwargs.get('constraints', str())

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
        if self.type != other.type:
            return False
        if self.is_active_driven != other.is_active_driven:
            return False
        if self.is_active_steered != other.is_active_steered:
            return False
        if self.position != other.position:
            return False
        if self.diameter != other.diameter:
            return False
        if self.width != other.width:
            return False
        if self.center_displacement != other.center_displacement:
            return False
        if self.constraints != other.constraints:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'type' field must be of type 'str'"
        self._type = value

    @builtins.property
    def is_active_driven(self):
        """Message field 'is_active_driven'."""
        return self._is_active_driven

    @is_active_driven.setter
    def is_active_driven(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_active_driven' field must be of type 'bool'"
        self._is_active_driven = value

    @builtins.property
    def is_active_steered(self):
        """Message field 'is_active_steered'."""
        return self._is_active_steered

    @is_active_steered.setter
    def is_active_steered(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_active_steered' field must be of type 'bool'"
        self._is_active_steered = value

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if __debug__:
            from vda5050_msgs.msg import Position
            assert \
                isinstance(value, Position), \
                "The 'position' field must be a sub message of type 'Position'"
        self._position = value

    @builtins.property
    def diameter(self):
        """Message field 'diameter'."""
        return self._diameter

    @diameter.setter
    def diameter(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'diameter' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'diameter' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._diameter = value

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
    def center_displacement(self):
        """Message field 'center_displacement'."""
        return self._center_displacement

    @center_displacement.setter
    def center_displacement(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'center_displacement' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'center_displacement' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._center_displacement = value

    @builtins.property
    def constraints(self):
        """Message field 'constraints'."""
        return self._constraints

    @constraints.setter
    def constraints(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'constraints' field must be of type 'str'"
        self._constraints = value
