#pragma once
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>
#include <string.h>
#include "sys/shm.h"
#include "sys/stat.h"
#include "sys/user.h"
#include "datacontainer.h"

using namespace std;
using namespace ros;

class ROSWrapper
{
public:
    ROSWrapper(const NodeHandle& nh);
    ~ROSWrapper();
    Publisher _pub;
    Subscriber _sub;
    NodeHandle _nh;

    void *internalThreadRoutine();
    static void* externalThreadRoutine(void* arg) {return ((ROSWrapper *)arg)->internalThreadRoutine();};
private:
    int _segment_id;
    int _size;
    int _key;
    DC* _shared_memory;
    
    void initialize();
    void SubscribeCallBack(const std_msgs::StringConstPtr msg);
};