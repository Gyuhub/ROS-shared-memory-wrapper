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
    while(ros::ok())
    {
        pthread_mutex_lock(&_shm._mtx);
        // TODO ///////////////////////
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