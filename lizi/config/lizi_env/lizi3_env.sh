#!/bin/sh
export ROS_HOSTNAME="192.168.0.103"
export ROS_IP="192.168.0.103"
export ROS_MASTER_URI="http://192.168.0.100:11311"
. ~/catkin_ws/devel/setup.sh
exec "$@"
