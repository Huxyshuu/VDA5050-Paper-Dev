# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vda5050_connector:srv/SupportedActions.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SupportedActions_Request(type):
    """Metaclass of message 'SupportedActions_Request'."""

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
            module = import_type_support('vda5050_connector')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vda5050_connector.srv.SupportedActions_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__supported_actions__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__supported_actions__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__supported_actions__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__supported_actions__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__supported_actions__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SupportedActions_Request(metaclass=Metaclass_SupportedActions_Request):
    """Message class 'SupportedActions_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_SupportedActions_Response(type):
    """Metaclass of message 'SupportedActions_Response'."""

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
            module = import_type_support('vda5050_connector')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vda5050_connector.srv.SupportedActions_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__supported_actions__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__supported_actions__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__supported_actions__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__supported_actions__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__supported_actions__response

            from vda5050_msgs.msg import AGVAction
            if AGVAction.__class__._TYPE_SUPPORT is None:
                AGVAction.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SupportedActions_Response(metaclass=Metaclass_SupportedActions_Response):
    """Message class 'SupportedActions_Response'."""

    __slots__ = [
        '_agv_actions',
    ]

    _fields_and_field_types = {
        'agv_actions': 'sequence<vda5050_msgs/AGVAction>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['vda5050_msgs', 'msg'], 'AGVAction')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.agv_actions = kwargs.get('agv_actions', [])

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
        if self.agv_actions != other.agv_actions:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def agv_actions(self):
        """Message field 'agv_actions'."""
        return self._agv_actions

    @agv_actions.setter
    def agv_actions(self, value):
        if __debug__:
            from vda5050_msgs.msg import AGVAction
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
                 all(isinstance(v, AGVAction) for v in value) and
                 True), \
                "The 'agv_actions' field must be a set or sequence and each value of type 'AGVAction'"
        self._agv_actions = value


class Metaclass_SupportedActions(type):
    """Metaclass of service 'SupportedActions'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vda5050_connector')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vda5050_connector.srv.SupportedActions')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__supported_actions

            from vda5050_connector.srv import _supported_actions
            if _supported_actions.Metaclass_SupportedActions_Request._TYPE_SUPPORT is None:
                _supported_actions.Metaclass_SupportedActions_Request.__import_type_support__()
            if _supported_actions.Metaclass_SupportedActions_Response._TYPE_SUPPORT is None:
                _supported_actions.Metaclass_SupportedActions_Response.__import_type_support__()


class SupportedActions(metaclass=Metaclass_SupportedActions):
    from vda5050_connector.srv._supported_actions import SupportedActions_Request as Request
    from vda5050_connector.srv._supported_actions import SupportedActions_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
