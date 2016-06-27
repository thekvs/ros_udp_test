#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>

void data_cb(const geometry_msgs::Vector3::ConstPtr& msg)
{
    ROS_INFO_STREAM(std::endl << *msg << "----");
}

int
main(int argc, char **argv)
{
    ros::init(argc, argv, "consumer");

    ros::NodeHandle nh;

    uint32_t queue_size = 1000;
    ros::TransportHints transport_hints = ros::TransportHints().unreliable(); // UDP transport

    ros::Subscriber sub = nh.subscribe("chatter", queue_size, data_cb, transport_hints);

    ros::spin();

    return 0;
}
