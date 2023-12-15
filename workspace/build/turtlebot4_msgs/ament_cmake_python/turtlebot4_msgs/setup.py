from setuptools import find_packages
from setuptools import setup

setup(
    name='turtlebot4_msgs',
    version='1.0.4',
    packages=find_packages(
        include=('turtlebot4_msgs', 'turtlebot4_msgs.*')),
)
