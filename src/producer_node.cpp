#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>

static const int kDefaultRateParameter = 10;

int
main(int argc, char **argv)
{
    ros::init(argc, argv, "producer");

    ros::NodeHandle nh;
    ros::NodeHandle priv_nh("~");

    uint32_t queue_size = 1000;
    int rate;

    if (!priv_nh.getParam("rate", rate)) {
        ROS_WARN_STREAM("couldn't find 'rate' configuration parameter, using the default=" << kDefaultRateParameter);
        rate = kDefaultRateParameter;
    }

    ROS_INFO_STREAM("Publishing messages at rate " << rate << " hz.");

    ros::Publisher chatter_pub = nh.advertise<geometry_msgs::Vector3>("chatter", queue_size);
    ros::Rate loop_rate(rate);

    while (ros::ok()) {
        geometry_msgs::Vector3 msg;

        msg.x = 1;
        msg.y = 2;
        msg.z = 3;

        chatter_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return EXIT_SUCCESS;
}
