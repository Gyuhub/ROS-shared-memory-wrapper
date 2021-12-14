#pragma once
#include "roswrapper.h"
#include "shm.h"
#include "signal.h"
pthread_t pth_ros_, pth_shm_;
void signal_handler(int sig_num)
{
    ROS_WARN("CAUGHT \'Ctrl+c\'!! TERMINATE ALL PROCESSES...");
    ros::shutdown();
    exit(sig_num);
    return;
}