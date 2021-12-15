#include "shm.h"

Shm::Shm(DC* dc) : _shared_memory(dc)
{
    initialize();
}

Shm::~Shm()
{
    pthread_mutex_destroy(&_mtx);
}

void Shm::createSharedMemory()
{
    if((_segment_id = shmget(_key, _size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR)) == -1)
    {
        int err = errno;
        fprintf (stderr, "[FALUT] CANNOT CREATE NEW A SHARED MEMORY: %s\n", strerror (errno));
        _segment_id = shmget(_key, 0, IPC_CREAT | S_IRUSR | S_IWUSR);
    }
    else
    {
        _shared_memory = (DC *)shmat(_segment_id, NULL, 0);
        shmdt(_shared_memory);
    }
    return;
}

void Shm::removeSharedMemory()
{
    _segment_id = shmget(_key, 0, IPC_CREAT | S_IRUSR | S_IWUSR);
    if(shmctl(_segment_id, IPC_RMID, 0) == -1)
    {
        perror("[ERROR] Removing shared memory failed!\n");
        exit(0);
    }
}

void Shm::initialize()
{
    _segment_id = 0;
    _size = sizeof(DC); //PAGE_SIZE;
    _key = 100; // Arbitrary number
    pthread_mutex_init(&_mtx,NULL);
}