#include "shm.h"

Shm::Shm()
{
    initialize();
}

Shm::~Shm()
{

}

void Shm::createSharedMemory()
{
    if(_segment_id = shmget(_key, _size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR) == -1)
    {
        int err = errno;
        fprintf (stderr, "[FALUT] CANNOT CREATE SHARED MEMORY: %s\n", strerror (errno));
        // _segment_id = shmget(_key, _size, IPC_CREAT | S_IRUSR | S_IWUSR);
        // exit(0);
    }
    _shared_memory = (DC *)shmat(_segment_id, NULL, 0);
    cout << "Contents of shared memory : " << _shared_memory << '\n';
    shmdt(_shared_memory);
    return;
}

void Shm::removeSharedMemory()
{
    shmctl(_segment_id, IPC_RMID, NULL);
    cout << "remove shared memory...\n";
}

void* Shm::internalThreadRoutine()
{
    createSharedMemory();
    while(1)
    {

    }
    return NULL;
}

void Shm::initialize()
{
    _segment_id = 0;
    _size = sizeof(DC); //PAGE_SIZE;
    _key = 100; // Arbitrary number
}