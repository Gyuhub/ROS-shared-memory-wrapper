#include <iostream>
#include "wrapper.h"

using namespace std;

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "shm_node", ros::init_options::NoSigintHandler);
    ros::NodeHandle nh_;

    ROSWrapper _ros_wrapper(nh_);
    Shm _shm;
    EtherCAT ECAT;
    
    signal(SIGINT, signal_handler);
    pthread_create(&pth_ros_, NULL, &ROSWrapper::externalThreadRoutine, &_ros_wrapper);
    pthread_create(&pth_shm_, NULL, &Shm::externalThreadRoutine, &_shm);
    pthread_join(pth_ros_, NULL);
    pthread_join(pth_shm_, NULL);
}