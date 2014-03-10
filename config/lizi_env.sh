#!/bin/sh
export ROS_HOSTNAME="10.0.0.4"
export ROS_IP="10.0.0.4"
export ROS_MASTER_URI="http://10.0.0.5:11311"
. ~/catkin_ws/devel/setup.sh
exec "$@"
