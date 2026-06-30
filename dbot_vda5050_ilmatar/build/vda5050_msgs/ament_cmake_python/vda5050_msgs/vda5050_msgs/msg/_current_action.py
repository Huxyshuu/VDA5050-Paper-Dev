# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_msgs:msg/CurrentAction.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CurrentAction(type):
    """Metaclass of message 'CurrentAction'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'WAITING': 'WAITING',
        'INITIALIZING': 'INITIALIZING',
        'RUNNING': 'RUNNING',
        'PAUSED': 'PAUSED',
        'FINISHED': 'FINISHED',
        'FAILED': 'FAILED',
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
                'vda5050_msgs.msg.CurrentAction')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__current_action
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__current_action
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__current_action
            cls._TYPE_SUPPORT = module.type_support_msg__msg__current_action
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__current_action

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'WAITING': cls.__constants['WAITING'],
            'INITIALIZING': cls.__constants['INITIALIZING'],
            'RUNNING': cls.__constants['RUNNING'],
            'PAUSED': cls.__constants['PAUSED'],
            'FINISHED': cls.__constants['FINISHED'],
            'FAILED': cls.__constants['FAILED'],
        }

    @property
    def WAITING(self):
        """Message constant 'WAITING'."""
        return Metaclass_CurrentAction.__constants['WAITING']

    @property
    def INITIALIZING(self):
        """Message constant 'INITIALIZING'."""
        return Metaclass_CurrentAction.__constants['INITIALIZING']

    @property
    def RUNNING(self):
        """Message constant 'RUNNING'."""
        return Metaclass_CurrentAction.__constants['RUNNING']

    @property
    def PAUSED(self):
        """Message constant 'PAUSED'."""
        return Metaclass_CurrentAction.__constants['PAUSED']

    @property
    def FINISHED(self):
        """Message constant 'FINISHED'."""
        return Metaclass_CurrentAction.__constants['FINISHED']

    @property
    def FAILED(self):
        """Message constant 'FAILED'."""
        return Metaclass_CurrentAction.__constants['FAILED']


class CurrentAction(metaclass=Metaclass_CurrentAction):
    """
    Message class 'CurrentAction'.

    Constants:
      WAITING
      INITIALIZING
      RUNNING
      PAUSED
      FINISHED
      FAILED
    """

    __slots__ = [
        '_action_id',
        '_action_type',
        '_action_description',
        '_action_status',
        '_result_description',
    ]

    _fields_and_field_types = {
        'action_id': 'string',
        'action_type': 'string',
        'action_description': 'string',
        'action_status': 'string',
        'result_description': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.action_id = kwargs.get('action_id', str())
        self.action_type = kwargs.get('action_type', str())
        self.action_description = kwargs.get('action_description', str())
        self.action_status = kwargs.get('action_status', str())
        self.result_description = kwargs.get('result_description', str())

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
        if self.action_id != other.action_id:
            return False
        if self.action_type != other.action_type:
            return False
        if self.action_description != other.action_description:
            return False
        if self.action_status != other.action_status:
            return False
        if self.result_description != other.result_description:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def action_id(self):
        """Message field 'action_id'."""
        return self._action_id

    @action_id.setter
    def action_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'action_id' field must be of type 'str'"
        self._action_id = value

    @builtins.property
    def action_type(self):
        """Message field 'action_type'."""
        return self._action_type

    @action_type.setter
    def action_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'action_type' field must be of type 'str'"
        self._action_type = value

    @builtins.property
    def action_description(self):
        """Message field 'action_description'."""
        return self._action_description

    @action_description.setter
    def action_description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'action_description' field must be of type 'str'"
        self._action_description = value

    @builtins.property
    def action_status(self):
        """Message field 'action_status'."""
        return self._action_status

    @action_status.setter
    def action_status(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'action_status' field must be of type 'str'"
        self._action_status = value

    @builtins.property
    def result_description(self):
        """Message field 'result_description'."""
        return self._result_description

    @result_description.setter
    def result_description(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'result_description' field must be of type 'str'"
        self._result_description = value
