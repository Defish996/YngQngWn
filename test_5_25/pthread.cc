#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <vector>
#include <time.h>
#include <string>
using namespace std;
void* threadRountain(void* args)
{
    string name = static_cast<const char*>(args);
    while(true)
    {
        cout << "new thread is running, thread name: " << name << endl;
        sleep(1);
    }

}
int main()
{
    pthread_t tid;
    pthread_create(&tid,nullptr,threadRountain,(void*)"thread-1");

    while (true)
    {
        std::cout << "main thread " << std::endl;
        sleep(1);
    }


    return 0;
} 