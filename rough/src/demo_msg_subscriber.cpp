#include "ros/ros.h"
#include "rough/demo_msg.h"
#include <iostream>

void number_callback(const rough::demo_msg::ConstPtr& msg){
	ROS_INFO("Received [%s %d]", msg->greeting.c_str(), msg->number);
}

int main(int argc, char **argv){
	ros::init(argc, argv, "demo_msg_subsciber");
	ros::NodeHandle node_obj;
	ros::Subscriber number_subscriber = node_obj.subscribe("string_and_number",10,number_callback);
	ros::spin();
	return 0;
}
