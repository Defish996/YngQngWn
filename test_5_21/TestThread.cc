#include <iostream> 
#include <unistd.h>
#include <sys/types.h>
// 新线程
int cnt = 100;
void *threadRoutain(void *arg)
{
    const char *thread = (const char *)arg;
    while (true)
    {
        std::cout << "i am a new thread: " << thread << ",pid: " << getpid() << std::endl;
        cnt--;       
        sleep(1);
    }
}
int main()
{
    pthread_t thread;
    pthread_create(&thread, nullptr, threadRoutain, (void *)"thread 1");


    while(true)
    {
        std::cout << "cnt: " << cnt << std::endl;
        sleep(1);

    }
    return 0;
}