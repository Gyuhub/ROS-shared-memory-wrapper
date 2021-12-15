#pragma once
#include "shm.h"

class EtherCAT
{
public:
    EtherCAT(Shm* shm);
    ~EtherCAT();
    void* internalThreadRoutine();
    static void* externalThreadRoutine(void* arg) {return ((EtherCAT*)arg)->internalThreadRoutine();}
private:
    Shm &_shm;
    void initialize();
};