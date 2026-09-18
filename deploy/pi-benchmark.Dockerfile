# Pi-only ROS client environment; no robot hardware drivers or Nav2 server.
FROM ros:jazzy-ros-base
RUN apt-get update && apt-get install -y --no-install-recommends \
    ros-jazzy-nav2-msgs ros-jazzy-tf2-ros ros-jazzy-tf2-msgs \
    ros-jazzy-rmw-cyclonedds-cpp python3-paho-mqtt python3-yaml \
    python3-jsonschema python3-matplotlib git iproute2 \
    && rm -rf /var/lib/apt/lists/*
ENV RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
WORKDIR /project
