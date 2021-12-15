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

void ROSWrapper::broadcastTF()
{
    for (int i = 0; i < 3; i++) _tf_vec[i] = _shm._shared_memory->_x(i);
    _tf_transform.setOrigin(_tf_vec);
    double roll  = _shm._shared_memory->_x(3);
    double pitch = _shm._shared_memory->_x(4);
    double yaw   = _shm._shared_memory->_x(5);
    _tf_quat.setRPY(roll, pitch, yaw);
    _tf_transform.setRotation(_tf_quat);
    _tf_br.sendTransform(tf::StampedTransform(_tf_transform, ros::Time::now(), "base_frame", "end_effector"));
}

// void ROSWrapper::SubscribeCallBack(const std_msgs msg)
// {
// }

bool ROSWrapper::serviceCallBack(shm_ros::srvwrapper::Request& req, shm_ros::srvwrapper::Response& res)
{
    // Do what you want!
    double x = req.x;
    double y = req.y;
    double result = x + y;
    res.result = result;
}

void ROSWrapper::ROSInitialize()
{
    // _pub = _nh.advertise<//Some ROS standard message type ex) std_msgs::String...>("/Topic name", Queue size(normaly '1'));
    // _sub = _nh.subscribe<//Some ROS standard message type ex) std_msgs::String...>("/Topic", Queue size (normaly 1), &ROSWrapper::SomeCallBackFunction, this);
    _serv = _nh.advertiseService("/Service_name", &ROSWrapper::serviceCallBack, this);
    ROS_INFO("* Initialize ROS settings!");
}

void ROSWrapper::initialize()
{
    ROSInitialize();
}