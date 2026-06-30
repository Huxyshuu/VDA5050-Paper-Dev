# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/TypeSpecification.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TypeSpecification(type):
    """Metaclass of message 'TypeSpecification'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'DIFF': 'DIFF',
        'OMNI': 'OMNI',
        'THREEWHEEL': 'THREEWHEEL',
        'FORKLIFT': 'FORKLIFT',
        'CONVEYOR': 'CONVEYOR',
        'TUGGER': 'TUGGER',
        'CARRIER': 'CARRIER',
        'NATURAL': 'NATURAL',
        'REFLECTOR': 'REFLECTOR',
        'RFID': 'RFID',
        'DMC': 'DMC',
        'SPOT': 'SPOT',
        'GRID': 'GRID',
        'PHYSICAL_LINE_GUIDED': 'PHYSICAL_LINE_GUIDED',
        'VIRTUAL_LINE_GUIDED': 'VIRTUAL_LINE_GUIDED',
        'AUTONOMOUS': 'AUTONOMOUS',
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
                'vda5050_msgs.msg.TypeSpecification')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__type_specification
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__type_specification
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__type_specification
            cls._TYPE_SUPPORT = module.type_support_msg__msg__type_specification
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__type_specification

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'DIFF': cls.__constants['DIFF'],
            'OMNI': cls.__constants['OMNI'],
            'THREEWHEEL': cls.__constants['THREEWHEEL'],
            'FORKLIFT': cls.__constants['FORKLIFT'],
            'CONVEYOR': cls.__constants['CONVEYOR'],
            'TUGGER': cls.__constants['TUGGER'],
            'CARRIER': cls.__constants['CARRIER'],
            'NATURAL': cls.__constants['NATURAL'],
            'REFLECTOR': cls.__constants['REFLECTOR'],
            'RFID': cls.__constants['RFID'],
            'DMC': cls.__constants['DMC'],
            'SPOT': cls.__constants['SPOT'],
            'GRID': cls.__constants['GRID'],
            'PHYSICAL_LINE_GUIDED': cls.__constants['PHYSICAL_LINE_GUIDED'],
            'VIRTUAL_LINE_GUIDED': cls.__constants['VIRTUAL_LINE_GUIDED'],
            'AUTONOMOUS': cls.__constants['AUTONOMOUS'],
        }

    @property
    def DIFF(self):
        """Message constant 'DIFF'."""
        return Metaclass_TypeSpecification.__constants['DIFF']

    @property
    def OMNI(self):
        """Message constant 'OMNI'."""
        return Metaclass_TypeSpecification.__constants['OMNI']

    @property
    def THREEWHEEL(self):
        """Message constant 'THREEWHEEL'."""
        return Metaclass_TypeSpecification.__constants['THREEWHEEL']

    @property
    def FORKLIFT(self):
        """Message constant 'FORKLIFT'."""
        return Metaclass_TypeSpecification.__constants['FORKLIFT']

    @property
    def CONVEYOR(self):
        """Message constant 'CONVEYOR'."""
        return Metaclass_TypeSpecification.__constants['CONVEYOR']

    @property
    def TUGGER(self):
        """Message constant 'TUGGER'."""
        return Metaclass_TypeSpecification.__constants['TUGGER']

    @property
    def CARRIER(self):
        """Message constant 'CARRIER'."""
        return Metaclass_TypeSpecification.__constants['CARRIER']

    @property
    def NATURAL(self):
        """Message constant 'NATURAL'."""
        return Metaclass_TypeSpecification.__constants['NATURAL']

    @property
    def REFLECTOR(self):
        """Message constant 'REFLECTOR'."""
        return Metaclass_TypeSpecification.__constants['REFLECTOR']

    @property
    def RFID(self):
        """Message constant 'RFID'."""
        return Metaclass_TypeSpecification.__constants['RFID']

    @property
    def DMC(self):
        """Message constant 'DMC'."""
        return Metaclass_TypeSpecification.__constants['DMC']

    @property
    def SPOT(self):
        """Message constant 'SPOT'."""
        return Metaclass_TypeSpecification.__constants['SPOT']

    @property
    def GRID(self):
        """Message constant 'GRID'."""
        return Metaclass_TypeSpecification.__constants['GRID']

    @property
    def PHYSICAL_LINE_GUIDED(self):
        """Message constant 'PHYSICAL_LINE_GUIDED'."""
        return Metaclass_TypeSpecification.__constants['PHYSICAL_LINE_GUIDED']

    @property
    def VIRTUAL_LINE_GUIDED(self):
        """Message constant 'VIRTUAL_LINE_GUIDED'."""
        return Metaclass_TypeSpecification.__constants['VIRTUAL_LINE_GUIDED']

    @property
    def AUTONOMOUS(self):
        """Message constant 'AUTONOMOUS'."""
        return Metaclass_TypeSpecification.__constants['AUTONOMOUS']


class TypeSpecification(metaclass=Metaclass_TypeSpecification):
    """
    Message class 'TypeSpecification'.

    Constants:
      DIFF
      OMNI
      THREEWHEEL
      FORKLIFT
      CONVEYOR
      TUGGER
      CARRIER
      NATURAL
      REFLECTOR
      RFID
      DMC
      SPOT
      GRID
      PHYSICAL_LINE_GUIDED
      VIRTUAL_LINE_GUIDED
      AUTONOMOUS
    """

    __slots__ = [
        '_series_name',
        '_series_description',
        '_agv_kinematic',
        '_agv_class',
        '_max_load_mass',
        '_localization_types',
        '_navigation_types',
    ]

    _fields_and_field_types = {
        'series_name': 'string',
        'series_description': 'string',
        'agv_kinematic': 'string',
        'agv_class': 'string',
        'max_load_mass': 'double',
        'localization_types': 'sequence<string>',
        'navigation_types': 'sequence<string>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.series_name = kwargs.get('series_name', str())
        self.series_description = kwargs.get('series_description', str())
        self.agv_kinematic = kwargs.get('agv_kinematic', str())
        self.agv_class = kwargs.get('agv_class', str())
        self.max_load_mass = kwargs.get('max_load_mass', float())
        self.localization_types = kwargs.get('localization_types', [])
        self.navigation_types = kwargs.get('navigation_types', [])

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
        if self.series_name != other.series_name:
            return False
        if self.series_description != other.series_description:
            return False
        if self.agv_kinematic != other.agv_kinematic:
            return False
        if self.agv_class != other.agv_class:
            return False
        if self.max_load_mass != other.max_load_mass:
            return False
        if self.localization_types != other.localization_types:
            return False
        if self.navigation_types != other.navigation_types:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def series_name(self):
        """Message field 'series_name'."""
        return self._series_name

    @series_name.setter
    def series_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'series_name' field must be of type 'str'"
        self._series_name = value

    @builtins.property
    def series_description(self):
        """Message field 'series_description'."""
        return self._series_description

    @series_description.setter
    def series_description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'series_description' field must be of type 'str'"
        self._series_description = value

    @builtins.property
    def agv_kinematic(self):
        """Message field 'agv_kinematic'."""
        return self._agv_kinematic

    @agv_kinematic.setter
    def agv_kinematic(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'agv_kinematic' field must be of type 'str'"
        self._agv_kinematic = value

    @builtins.property
    def agv_class(self):
        """Message field 'agv_class'."""
        return self._agv_class

    @agv_class.setter
    def agv_class(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'agv_class' field must be of type 'str'"
        self._agv_class = value

    @builtins.property
    def max_load_mass(self):
        """Message field 'max_load_mass'."""
        return self._max_load_mass

    @max_load_mass.setter
    def max_load_mass(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_load_mass' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'max_load_mass' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._max_load_mass = value

    @builtins.property
    def localization_types(self):
        """Message field 'localization_types'."""
        return self._localization_types

    @localization_types.setter
    def localization_types(self, value):
        if __debug__:
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'localization_types' field must be a set or sequence and each value of type 'str'"
        self._localization_types = value

    @builtins.property
    def navigation_types(self):
        """Message field 'navigation_types'."""
        return self._navigation_types

    @navigation_types.setter
    def navigation_types(self, value):
        if __debug__:
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'navigation_types' field must be a set or sequence and each value of type 'str'"
        self._navigation_types = value
