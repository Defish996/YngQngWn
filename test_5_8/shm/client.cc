#include "comm.hpp"
int main()
{
    key_t key = GetKey();
    int shmid = shmget(key,size,IPC_CREAT|IPC_EXCL);
    if(shmid < 0)
    {
        std::cerr << errno << "errno:" << strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "shmid: " << shmid << std::endl;
    return 0;
}