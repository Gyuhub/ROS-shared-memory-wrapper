#include "shm.h"
#include "cstdlib"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "[ERROR] Please enter the command \'y\' or \'n\' depending on whether you want to create a new shared memory!\n";
        exit(0);
    }
    if (strcmp(argv[1], "y")  == 0)
    {
        std::cout << "[INFO] Try to create a new shared memory...\n";
        DC dc_;
        Shm shm_(&dc_);
        shm_.createSharedMemory();
        std::cout << "[INFO] Successfully create a new shared memory!\n";
    }
    else if (strcmp(argv[1],"n") == 0)
    {
        std::cout << "If you want to remove the previous shared memory? then please enter the command \'y\' : ";
        string str;
        cin >> str;
        if (str == "y" || str == "Y")
        {
            std::cout << "[INFO] Try to remove the shared memory...\n";
            DC dc_;
            Shm shm_(&dc_);
            shm_.removeSharedMemory();
            std::cout << "[INFO] Successfully remove the shared memory!\n";
        }
        else
        {
            std::cout << "\nYou enter the wrong command or you choose to save the previous shared memory! Terminate process...\n";
            exit(0);
        }
    }
    std::cout << "Terminate the process...\n";
    return 0;
}