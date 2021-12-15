#include "wrapper.h"

using namespace std;

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "shm_node", ros::init_options::NoSigintHandler);
    ros::NodeHandle nh_;
    DC dc_;
    Shm shm_(&dc_);
    ROSWrapper _ros_wrapper(nh_, &shm_);
    EtherCAT ECAT(&shm_);
    
    signal(SIGINT, signal_handler);
    pthread_create(&pth_ros_, NULL, &ROSWrapper::externalThreadRoutine, &_ros_wrapper);
    pthread_create(&pth_ECAT_, NULL, &EtherCAT::externalThreadRoutine, &ECAT);
    pthread_join(pth_ros_, NULL);
    pthread_join(pth_ECAT_, NULL);
}