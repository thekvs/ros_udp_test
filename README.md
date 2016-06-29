### Usage
1. On _every_ host where you are going to run ROS components ```export ROS_IP=self.ip.addr```.
1. Run producer node and all needed infrastructure ```$ roslaunch ros_udp_test producer.launch```
1. On host where you are going to run a consumer node ```export ROS_MASTER_URI=http://roscore.ip.addr:11311```
1. Run consumer node ```$ rosrun ros_udp_test consumer_node```
