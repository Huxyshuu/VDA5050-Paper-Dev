from setuptools import find_packages
from setuptools import setup

setup(
    name='dbot_nav_slam',
    version='0.0.0',
    packages=find_packages(
        include=('dbot_nav_slam', 'dbot_nav_slam.*')),
)
