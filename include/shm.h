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
    Shm();
    ~Shm();
    void createSharedMemory();
    void removeSharedMemory();
    void* internalThreadRoutine();
    static void* externalThreadRoutine(void* arg) {return ((Shm*)arg)->internalThreadRoutine();}
private:
    int _segment_id;
    int _size;
    int _key;
    DC* _shared_memory;
    void initialize();
};