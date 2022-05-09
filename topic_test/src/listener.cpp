#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg_p)
{
    ROS_INFO("I hear %s",msg_p->data.c_str());
}

int main(int argc, char ** argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"listener_test");
    
    ros::NodeHandle nh;
    // test
    ros::Subscriber sub = nh.subscribe<std_msgs::String> ("chatter",10,doMsg);
    ros::spin();   
    
    return 0;

}