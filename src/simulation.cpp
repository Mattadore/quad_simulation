#include <geometry_msgs/Torque.h>
#include <geometry_msgs/Vector3.h>
#include <ros.h>

#define throttled false

bool load(quad_simulation::register_quads::Request  &req,
	      quad_simulation::register_quads::Response &ret) {
	
}

int main(int argc, char** argv) {
	ros::init(argc,argv,"simulate");
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("register_quads",control);	
    ROS_INFO("quad simulation node running");
    ros::Rate freq(60);
    while (ros::ok()) {
        #if throttled
            freq.sleep();
        #endif
        ros::spinOnce();
    }
	return 0;
}

