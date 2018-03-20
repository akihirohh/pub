#include "ros/ros.h"
#include <cmath>
#include "geometry_msgs/Twist.h"

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "turtle_sim_square");
  ros::NodeHandle n;  
  ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
  ros::Rate loop_rate(0.5);
  geometry_msgs::Twist cmd; 
   
  ROS_INFO_STREAM("Open turtlesim: rosrun turtlesim turtlesim_node");
  
  double angular[] = {0, M_PI/2 };
  double linear[] = {3, 0};
  int i = 0;
  while (ros::ok())
  {
  	cmd.angular.z = angular[i];
  	cmd.linear.x = linear[i];
  	i = (i 	== 0) ? 1: 0;
  	pub.publish(cmd);
  	ros::spinOnce();
  	loop_rate.sleep();  	
  }
}

