#include <iostream>
#include <unistd.h>
#include <signal.h>
long long int cnt = 0;

void handler(int signo)
{
    alarm(2);
    std::cout << "get a signo: " << signo << std::endl;
    //exit(1);
}
int main()
{
    signal(14,handler);
    alarm(2);
    std::cout << "mypid : " << getpid() << std::endl;
    while(1)
    {
        std::cout << "Runging..." << std::endl;
        sleep(1);

    }    
    return 0;
}