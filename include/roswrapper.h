#pragma once
// ROS header ///////////////////////////////
#include <ros/ros.h>
// ROS message header ///////////////////////
#include <std_msgs/Float32MultiArray.h>
#include <shm_ros/srvwrapper.h>
#include <tf/transform_broadcaster.h>
/////////////////////////////////////////////
#include <string.h>
#include "shm.h"

using namespace std;
using namespace ros;

class ROSWrapper
{
public:
    ROSWrapper(const NodeHandle& nh, Shm* shm);
    ~ROSWrapper();

    void *internalThreadRoutine();
    static void* externalThreadRoutine(void* arg) {return ((ROSWrapper *)arg)->internalThreadRoutine();};
private:
    Shm& _shm;
// ROS Node & Service objects ///////////////
    NodeHandle _nh;
    Publisher _pub;
    Subscriber _sub;
    ServiceServer _serv;
/////////////////////////////////////////////

// ROS variables ////////////////////////////
    tf::TransformBroadcaster _tf_br;
    tf::Transform _tf_transform;
    tf::Vector3 _tf_vec;
    tf::Quaternion _tf_quat;
/////////////////////////////////////////////

// ROS Custom functions /////////////////////
    void broadcastTF();
/////////////////////////////////////////////

// ROS CallBack functions ///////////////////
    // void SubscribeCallBack(const std_msgs msg);
    bool serviceCallBack(shm_ros::srvwrapper::Request& req, shm_ros::srvwrapper::Response& res);
/////////////////////////////////////////////

// ROS wrapper initialization ///////////////
    void ROSInitialize();
    void initialize();
/////////////////////////////////////////////
};