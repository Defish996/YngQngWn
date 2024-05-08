#include "comm.hpp"
int main()
{
    key_t key = GetKey();
    int shmid = shmget(key,size,IPC_CREAT|IPC_EXCL|0666);
    if(shmid < 0)
    {
        std::cerr << errno << "errno:" << strerror(errno) << std::endl;
        return 1;
    }

    std::cout << "shmid: " << shmid << std::endl;
    char* s = (char*)shmat(shmid,nullptr,0);
    if(s<0)
    {
        std::cerr << errno << "errno:" << strerror(errno) << std::endl;
        return 1;
    }
    sleep(5);

    return 0;
}