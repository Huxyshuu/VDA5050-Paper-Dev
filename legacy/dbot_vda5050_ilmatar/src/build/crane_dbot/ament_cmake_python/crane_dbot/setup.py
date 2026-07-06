from setuptools import find_packages
from setuptools import setup

setup(
    name='crane_dbot',
    version='0.0.0',
    packages=find_packages(
        include=('crane_dbot', 'crane_dbot.*')),
)
