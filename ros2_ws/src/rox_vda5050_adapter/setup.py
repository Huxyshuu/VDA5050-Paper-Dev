from glob import glob

from setuptools import find_packages, setup

package_name = "rox_vda5050_adapter"

setup(
    name=package_name,
    version="0.4.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        ("share/" + package_name + "/launch", glob("launch/*.launch.py")),
        ("share/" + package_name + "/config", glob("config/*")),
        ("share/" + package_name + "/factsheets", glob("factsheets/*")),
    ],
    install_requires=["setuptools", "paho-mqtt", "jsonschema", "PyYAML"],
    zip_safe=True,
    maintainer="Hugo Tamm",
    maintainer_email="hugo.tamm@aalto.fi",
    description=(
        "VDA 5050 v3.0 MQTT/Nav2 adapter, waypoint tools, pose persistence "
        "and remote operator support for Neobotix ROX-Diff"
    ),
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "rox_vda5050_adapter = rox_vda5050_adapter.rox_vda5050_adapter:main",
            "capture_waypoint = rox_vda5050_adapter.capture_waypoint:main",
            "waypoint_visualizer = rox_vda5050_adapter.waypoint_visualizer:main",
            "goto_waypoint = rox_vda5050_adapter.goto_waypoint:main",
            "pose_persistence = rox_vda5050_adapter.pose_persistence:main",
        ],
    },
)
