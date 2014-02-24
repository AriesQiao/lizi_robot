#!/bin/bash
source ../../../devel/setup.bash
echo "Setting usb rules..."
cp lizi_usb.rules /etc/udev/rules.d
echo "Adding user: [$SUDO_USER] to dialout group (serial premmisions)"
usermod -a -G dialout $SUDO_USER
echo "Installing usb_cam..."
apt-get install ros-hydro-usb-cam
echo "Installing openni2..."
apt-get install ros-hydro-openni2-*
echo "Installing rosserial..."
roscd lizi
cd ..
git clone https://github.com/ros-drivers/rosserial.git
cd ..
catkin_make



