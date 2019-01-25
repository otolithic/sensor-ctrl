# sensor-ctrl
Testing ground for integrating Robotiq FT300 sensor readings into motion control for a UR5 robot arm.

Currently runs in ROS Kinetic Kame on Ubuntu 16.04, using the robotiq ft sensor libraries for ROS. This first version is a minimum working example, which listens to the ft_sensor topic and prints only the Fz value to ROS_INFO. Parts of the code reuse code found in rq_test_sensor, included in the robotiq package.

**I AM A BEGINNER AT THIS; IF YOU SEE ANY GLARING BAD PRACTICES, PLEASE LET ME KNOW! :)**
