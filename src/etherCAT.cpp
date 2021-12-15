#include "etherCAT.h"

EtherCAT::EtherCAT(Shm* shm) : _shm(*shm)
{
    initialize();
}

EtherCAT::~EtherCAT()
{

}

void* EtherCAT::internalThreadRoutine()
{
    while(1)
    {
        pthread_mutex_lock(&_shm._mtx);
        // TODO ///////////////////////
        pthread_mutex_unlock(&_shm._mtx);
    }
    return NULL;
}

void EtherCAT::initialize()
{
}