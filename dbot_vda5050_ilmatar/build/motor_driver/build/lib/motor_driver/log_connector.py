import logging
import rclpy.logging

class ConnectPythonLoggingToROS2(logging.Handler):
    """Logging handler that maps python log messages to ROS 2 logs."""

    MAP = {
        logging.DEBUG: rclpy.logging.get_logger('Python').debug,
        logging.INFO: rclpy.logging.get_logger('Python').info,
        logging.WARNING: rclpy.logging.get_logger('Python').warn,
        logging.ERROR: rclpy.logging.get_logger('Python').error,
        logging.CRITICAL: rclpy.logging.get_logger('Python').fatal,
    }

    def emit(self, record):
        try:
            self.MAP[record.levelno]("%s: %s" % (record.name, record.msg))
        except KeyError:
            rclpy.logging.get_logger('Python').error(
                "Unknown log level %s LOG: %s: %s"
                % (record.levelno, record.name, record.msg)
            )
