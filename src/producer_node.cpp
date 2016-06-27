#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>

int
main(int argc, char **argv)
{
    ros::init(argc, argv, "producer");

    ros::NodeHandle nh;

    uint32_t queue_size = 1000;
    uint32_t rate = 30;

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
