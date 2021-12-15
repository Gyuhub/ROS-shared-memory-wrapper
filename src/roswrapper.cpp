#include "roswrapper.h"

ROSWrapper::ROSWrapper(const NodeHandle& nh, Shm* shm) : _nh(nh) , _shm(*shm)
{
    initialize();
}

ROSWrapper::~ROSWrapper()
{

}

void* ROSWrapper::internalThreadRoutine()
{
    _pub = _nh.advertise<std_msgs::Float32MultiArray>("/topic", 1);
    std_msgs::Float32MultiArray msg_;
    while(ros::ok())
    {
        pthread_mutex_lock(&_shm._mtx);
        msg_.data.push_back(_shm._shared_memory->_x(0));
        msg_.data.push_back(_shm._shared_memory->_x(1));
        msg_.data.push_back(_shm._shared_memory->_x(2));
        _pub.publish(msg_);
        msg_.data.clear();
        pthread_mutex_unlock(&_shm._mtx);
    }
    ros::spin();
    return NULL;
}

// void ROSWrapper::SubscribeCallBack(const std_msgs msg)
// {
// }

void ROSWrapper::initialize()
{
}