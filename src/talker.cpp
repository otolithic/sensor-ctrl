#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
	//ros::init() remaps arguments so needs access to argc & argv
	ros::init(argc, argv, "talker");

	//NodeHandle is access point to communications in ROS
	ros::NodeHandle n;

	//advertise() tells ROS to publish on a topic name
	//the master node notifies other subscribers to negotiate a p2p connection to the node
	//advertise() returns a Publisher. destroying it unadvertises the topic
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter",1000);

	ros::Rate loop_rate(1); //rate in Hz

	int count = 0;
	while (ros::ok()) //until ctrl+C is pressed, shutdown is called, or all nodes are destroyed/kicked off
	{
		//fill message object with data and publish it
		std_msgs::String msg;

		std::stringstream ss;
		ss << "hello world " << count;

		msg.data = ss.str();

		//ROS_INFO is the replacement for printf or cout
		ROS_INFO("%s",  msg.data.c_str());

		//publish() sends messages with the same type as the parameter given in the advertise<>() call
		chatter_pub.publish(msg);

		//necessary to call callbacks (if any)
		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}

	return 0;
}

