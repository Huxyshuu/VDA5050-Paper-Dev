from setuptools import find_packages, setup

package_name = 'motor_driver'

setup(
    name= package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Pejman',
    maintainer_email='pejman.habibiroudkenar@aalto.fi',
    description='Package to connect the motors to ROS2',
    license='Apache license -2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': ['motor_bringup = motor_driver.ros2_wrapper:main'
        ],
    }
)
