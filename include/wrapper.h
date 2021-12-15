#pragma once
#include "roswrapper.h"
#include "etherCAT.h"
#include "signal.h"
pthread_t pth_ros_, pth_ECAT_;
void signal_handler(int sig_num)
{
    ROS_WARN("CAUGHT \'Ctrl+c\'!! TERMINATE ALL PROCESSES...");
    ros::shutdown();
    exit(sig_num);
    return;
}