cd '~/catkin_ws'
catkin_make
cd '~/sketchbook/libraries'
rm -rf ros_lib
rosrun rosserial_arduino make_libraries.py .
