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
    _size = sizeof(DC);

    _segment_id = shmget(100, 0, 0);
    _shared_memory = (DC*)shmat(_segment_id, NULL, 0);
    // _shared_memory->initialize();
    // _shared_memory->_x = Eigen::VectorXd::Ones(6);
    // cout << "ROS Contents of shared memory : " << _shared_memory->_x.transpose() << '\n';
    shmdt(_shared_memory);
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