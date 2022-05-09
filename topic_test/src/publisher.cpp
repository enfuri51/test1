#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <signal.h>

void mySignalHandler(int sig)
{
    ROS_INFO("Shut down!");
    ROS_INFO("Good night ,everybody!");
    ros::shutdown();
    exit(sig);
}

int main(int argc, char **argv) 
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"publisher_test", ros::init_options::NoSigintHandler);
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",10);

    std_msgs::String msg;
    std::string msg_front = "你好, ";

    signal (SIGINT,mySignalHandler);// exchange ctrl + c

    int count = 0;
    while (ros::ok)
    {
        std::stringstream ss;
        ss<<msg_front<<count;
        msg.data = ss.str();
        pub.publish(msg);       

        ROS_INFO("%s 号玩家，欢迎来到代码世界。",msg.data.c_str());

        ros::Rate r(1);
        r.sleep();
        count++;

        ros::spinOnce();
    }
    return 0;
    

}
