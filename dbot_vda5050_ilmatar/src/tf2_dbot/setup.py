from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'tf2_dbot'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Hari Prasanth SM',
    maintainer_email='sm.hariprasanth@gmail.com',
    description='A package for publishing the static and dynamic transforms in the environment and robot',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'odom_baselink_broadcaster = tf2_dbot.odom_baselink_broadcaster:main'
        ],
    },
)
