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
    double x = 1.0;
    double y = -1.0;
    double z = 0.0;
    bool flag = false;
    while(1)
    {
        if (flag == false)
        {
            x -= 0.001;
        }
        else
        {
            x += 0.001;
        }
        y = std::sqrt((1 - std::pow(x, 2)));
        pthread_mutex_lock(&_shm._mtx);
        _shm._shared_memory->_x(0) = x;
        _shm._shared_memory->_x(1) = y;
        _shm._shared_memory->_x(2) = z;
        pthread_mutex_unlock(&_shm._mtx);
        if (x <= -1) flag = true;
        else if (x >= 1) flag = false;
        std::cout << "x: [" << x << "]\ty: [" << y << "]\tz: [" << z << "]\n";
    }
    return NULL;
}

void EtherCAT::initialize()
{
}