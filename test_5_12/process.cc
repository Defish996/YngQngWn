#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <cstdlib>
void handler(int signo)
{   
    std::cout << "获得另一个2信号" << std:: endl;
    exit(1);

}
int main()
{
    signal(2, handler);

    while(1)
    {
        std::cout << "runging...,pid:" << getpid() << std::endl;
        sleep(1);
    }
    return 0;
}