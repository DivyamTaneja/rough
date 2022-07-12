#include "ros/ros.h"
#include "rough/demo_msg.h"
#include <iostream>

int main(int argc, char **argv){
	ros::init(argc, argv, "demo_msg_publisher");
	ros::NodeHandle node_obj;
	ros::Publisher number_publisher = node_obj.advertise<rough::demo_msg>("string_and_number",10);
	ros::Rate loop_rate(10);
	int number_count = 0;
	while(ros::ok()){
		rough::demo_msg msg;
		msg.greeting = "Hello World";
		msg.number = number_count;
		ROS_INFO("%s %d", msg.greeting.c_str(), msg.number);
		number_publisher.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		++number_count;
	}
	return 0;
}
