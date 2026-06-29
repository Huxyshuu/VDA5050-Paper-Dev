from setuptools import find_packages
from setuptools import setup

setup(
    name='vda_dbot_nav_slam',
    version='0.0.0',
    packages=find_packages(
        include=('vda_dbot_nav_slam', 'vda_dbot_nav_slam.*')),
)
