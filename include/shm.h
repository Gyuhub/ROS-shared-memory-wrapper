#pragma once
#include <iostream>
#include "pthread.h"
#include "sys/shm.h"
#include "sys/stat.h"
#include "sys/user.h"
#include "datacontainer.h"

using namespace std;

class Shm
{
public:
    Shm(DC* dc);
    ~Shm();
    void createSharedMemory();
    void removeSharedMemory();

    DC* _shared_memory;
    pthread_mutex_t _mtx;
private:
    int _segment_id;
    int _size;
    int _key;
    void initialize();
};