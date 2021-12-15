#pragma once
#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <string.h>
#include "shm.h"

using namespace std;
using namespace ros;

class ROSWrapper
{
public:
    ROSWrapper(const NodeHandle& nh, Shm* shm);
    ~ROSWrapper();
    Publisher _pub;
    Subscriber _sub;
    NodeHandle _nh;

    void *internalThreadRoutine();
    static void* externalThreadRoutine(void* arg) {return ((ROSWrapper *)arg)->internalThreadRoutine();};
private:
    Shm& _shm;
    
    void initialize();
    // void SubscribeCallBack(const std_msgs msg);
};