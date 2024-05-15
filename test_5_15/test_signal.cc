#include <iostream>
#include <unistd.h>
#include <signal.h>
//把2号信号直接屏蔽,不断让现在的进程获取pending表并打印(以0 1的方式),默认一个信号都没有所以是一直为0的,此时像这个进程发送2号信号,2号信号也不会递达,
//那么2号不被收到,他也就只能在pending表里面,我们就能看到pending表内的数据由0--->1的全过程
void handler(int signo)
{
    std::cout << "i get a signo, my signo: " << signo << std::endl;
}
void PrintPending(const sigset_t& pending)
{
    for(int signo = 32; signo > 0; signo--)
    {
        if(sigismember(&pending,signo))
        {
            std::cout << 1;
        }
        else{
            std::cout << 0;
        }
    }
    std::cout << std::endl;
}
int main()
{
    signal(2,handler);
    std::cout << "mypid: " << getpid() << std::endl;

    sigset_t set, oset, pending;
    //signal(2,handler);
    sigemptyset(&set);
    sigemptyset(&oset);
    sigaddset(&set,2);
    //语言与OS关联
    sigprocmask(SIG_BLOCK, &set, &oset);
    int cnt = 0;
    while(1)
    {
        sigpending(&pending);
        PrintPending(pending);
        sleep(1);
        cnt++;
        if(cnt==10)
        {
            std::cout << "解除屏蔽" << std::endl;
            sigprocmask(SIG_SETMASK,&oset,nullptr);
        }
    }
    return 0;
}