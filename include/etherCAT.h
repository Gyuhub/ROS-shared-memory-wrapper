#pragma once
#include <iostream>
#include "sys/shm.h"
#include "sys/stat.h"
#include "sys/user.h"
#include "datacontainer.h"

class EtherCAT
{
public:
    EtherCAT();
    ~EtherCAT();
    void createSharedMemory();
    void removeSharedMemory();
private:
    int _segment_id;
    int _size;
    int _key;
    DC* _shared_memory;
    void initialize();
};