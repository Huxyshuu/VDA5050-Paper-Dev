# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/ActionParameterDefinition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ActionParameterDefinition(type):
    """Metaclass of message 'ActionParameterDefinition'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'BOOL': 'BOOL',
        'NUMBER': 'NUMBER',
        'INTEGER': 'INTEGER',
        'FLOAT': 'FLOAT',
        'STRING': 'STRING',
        'OBJECT': 'OBJECT',
        'ARRAY': 'ARRAY',
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
                'vda5050_msgs.msg.ActionParameterDefinition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__action_parameter_definition
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__action_parameter_definition
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__action_parameter_definition
            cls._TYPE_SUPPORT = module.type_support_msg__msg__action_parameter_definition
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__action_parameter_definition

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'BOOL': cls.__constants['BOOL'],
            'NUMBER': cls.__constants['NUMBER'],
            'INTEGER': cls.__constants['INTEGER'],
            'FLOAT': cls.__constants['FLOAT'],
            'STRING': cls.__constants['STRING'],
            'OBJECT': cls.__constants['OBJECT'],
            'ARRAY': cls.__constants['ARRAY'],
        }

    @property
    def BOOL(self):
        """Message constant 'BOOL'."""
        return Metaclass_ActionParameterDefinition.__constants['BOOL']

    @property
    def NUMBER(self):
        """Message constant 'NUMBER'."""
        return Metaclass_ActionParameterDefinition.__constants['NUMBER']

    @property
    def INTEGER(self):
        """Message constant 'INTEGER'."""
        return Metaclass_ActionParameterDefinition.__constants['INTEGER']

    @property
    def FLOAT(self):
        """Message constant 'FLOAT'."""
        return Metaclass_ActionParameterDefinition.__constants['FLOAT']

    @property
    def STRING(self):
        """Message constant 'STRING'."""
        return Metaclass_ActionParameterDefinition.__constants['STRING']

    @property
    def OBJECT(self):
        """Message constant 'OBJECT'."""
        return Metaclass_ActionParameterDefinition.__constants['OBJECT']

    @property
    def ARRAY(self):
        """Message constant 'ARRAY'."""
        return Metaclass_ActionParameterDefinition.__constants['ARRAY']


class ActionParameterDefinition(metaclass=Metaclass_ActionParameterDefinition):
    """
    Message class 'ActionParameterDefinition'.

    Constants:
      BOOL
      NUMBER
      INTEGER
      FLOAT
      STRING
      OBJECT
      ARRAY
    """

    __slots__ = [
        '_key',
        '_value_data_type',
        '_description',
        '_is_optional',
    ]

    _fields_and_field_types = {
        'key': 'string',
        'value_data_type': 'string',
        'description': 'string',
        'is_optional': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.key = kwargs.get('key', str())
        self.value_data_type = kwargs.get('value_data_type', str())
        self.description = kwargs.get('description', str())
        self.is_optional = kwargs.get('is_optional', bool())

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
        if self.key != other.key:
            return False
        if self.value_data_type != other.value_data_type:
            return False
        if self.description != other.description:
            return False
        if self.is_optional != other.is_optional:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def key(self):
        """Message field 'key'."""
        return self._key

    @key.setter
    def key(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'key' field must be of type 'str'"
        self._key = value

    @builtins.property
    def value_data_type(self):
        """Message field 'value_data_type'."""
        return self._value_data_type

    @value_data_type.setter
    def value_data_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'value_data_type' field must be of type 'str'"
        self._value_data_type = value

    @builtins.property
    def description(self):
        """Message field 'description'."""
        return self._description

    @description.setter
    def description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'description' field must be of type 'str'"
        self._description = value

    @builtins.property
    def is_optional(self):
        """Message field 'is_optional'."""
        return self._is_optional

    @is_optional.setter
    def is_optional(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_optional' field must be of type 'bool'"
        self._is_optional = value
