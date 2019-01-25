#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "robotiq_ft_sensor/ft_sensor.h"
#include "robotiq_ft_sensor/sensor_accessor.h"


//this fxn gets called when a new message has arrived on the chatter topic
//the actual msg is passed (as a reference) and so can be altered as seen fit or copied and stored without worrying about it getting deleted
void chatterCallback(const robotiq_ft_sensor::ft_sensor& msg)
{
	ROS_INFO("Fz: [%f]", msg.Fz);
	// Access with msg.Fx,msg.Fy,msg.Fz,msg.Mx,msg.My,msg.Mz
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");

	ros::NodeHandle n;

	//Create a client for the sensor_accessor service
	ros::ServiceClient client = n.serviceClient<robotiq_ft_sensor::sensor_accessor>("robotiq_ft_sensor_acc");

	//subscribe() tells ROS you want to receive messages on a topic
	//messages are passed to the callback fxn (3rd arg), a Subscriber is returned
	//note that you don't need to specify the type of message you expect to receive!
	ros::Subscriber sub = n.subscribe("robotiq_ft_sensor",10,chatterCallback);

	//Create an instance of a sensor_accessor service	
	robotiq_ft_sensor::sensor_accessor srv;

	int count = 0;
	//LOOP
	while (ros::ok())
	{
		if (count == 1)
		{
			ROS_INFO("Listener online. Count: [%d]", count);
			
		}		

		if(count == 10000000)
		{

			/// Deprecated Interface
			// srv.request.command = "SET ZRO";

			/// New Interface with numerical commands
			srv.request.command_id = srv.request.COMMAND_SET_ZERO;

			if(client.call(srv))
			{
				ROS_INFO("ret: %s", srv.response.res.c_str());
			}
			count = 0;
		}

		ros::spinOnce();
		
		

		++count;
	}

	return 0;
}
