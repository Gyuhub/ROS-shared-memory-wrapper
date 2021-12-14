#include "etherCAT.h"

EtherCAT::EtherCAT()
{
    initialize();
}

EtherCAT::~EtherCAT()
{

}

void EtherCAT::createSharedMemory()
{
    _size = sizeof(DC);

    _segment_id = shmget(100, 0, 0);
    _shared_memory = (DC*)shmat(_segment_id, NULL, 0);
    _shared_memory->_x = Eigen::Vector3d::Ones(3) * 2.0;
    cout << "EtherCAT Contents of shared memory : " << _shared_memory->_x.transpose() << '\n';
    shmdt(_shared_memory);
}

void EtherCAT::removeSharedMemory()
{
    shmctl(_segment_id, IPC_RMID, NULL);
}

void EtherCAT::initialize()
{
    createSharedMemory();
}