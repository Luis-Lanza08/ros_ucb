#include <ros/ros.h>
#include <turtlesim/Spawn.h>
#include <std_srvs/Empty.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>


float vel_linear = 0.0;
float vel_angular = 0.0;

ros::Publisher pub;


void cmdVelCallback(const geometry_msgs::Twist& msg) {
    geometry_msgs::Twist vel;

    ROS_INFO_STREAM("Received cmd_vel message - Linear: " << msg.linear.x << ", Angular: " << msg.angular.z);
    vel.linear.x = -msg.linear.x;
    vel.angular.z = -msg.angular.z;
    pub.publish(vel);
}   


int main(int argc, char **argv) {
    ros::init(argc, argv, "spawn_turtle_plus");
    ros::NodeHandle nh;

    ros::ServiceClient spawnClient = nh.serviceClient<turtlesim::Spawn>("spawn");

    ros::Subscriber sub = nh.subscribe("turtle1/cmd_vel", 1000, cmdVelCallback);

    pub=nh.advertise<geometry_msgs::Twist>("Leo/cmd_vel",1000);



    turtlesim::Spawn::Request req;
    turtlesim::Spawn::Response resp;
 
    req.x = 5.5;
    req.y = 5.5;
    req.theta = 0;
    req.name = "Leo";
 
    bool success = spawnClient.call(req, resp);
 
    if (success) {
        ROS_INFO_STREAM("Spawned a turtle named " << resp.name);
        
 
    } else {
        ROS_ERROR_STREAM("Failed to spawn.");
        return 1;
    }
    
    ros::spin();

 
    return 0;
}