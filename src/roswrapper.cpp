#include "roswrapper.h"

ROSWrapper::ROSWrapper(const NodeHandle& nh) : _nh(nh)
{
    initialize();
}

ROSWrapper::~ROSWrapper()
{

}

void* ROSWrapper::internalThreadRoutine()
{
    int segment_id_;
    char *shared_memory;
    int size = PAGE_SIZE;

    segment_id_ = shmget(100, size, 0);
    shared_memory = (char*)shmat(segment_id_, NULL, 0);
    shared_memory = "Hello\n";
    cout << "Contents of shared memory : " << shared_memory << '\n';
    shmdt(shared_memory);
    // shmctl(segment_id_, IPC_RMID, NULL);
    while(ros::ok())
    {
    }
    ros::spin();
    return NULL;
}

void ROSWrapper::SubscribeCallBack(const std_msgs::StringConstPtr msg)
{
}

void ROSWrapper::initialize()
{
}