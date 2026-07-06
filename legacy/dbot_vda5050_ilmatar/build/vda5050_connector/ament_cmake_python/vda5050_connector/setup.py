from setuptools import find_packages
from setuptools import setup

setup(
    name='vda5050_connector',
    version='1.1.1',
    packages=find_packages(
        include=('vda5050_connector', 'vda5050_connector.*')),
)
