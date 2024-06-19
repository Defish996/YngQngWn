#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

__thread int g_val = 100;

void *ThreadRoutine(void* args)
{
    string  name = static_cast<const char*>(args);
    while(1)
    {
        sleep(1);
        cout << name << ", g_val = " << g_val << ", &g_val:" << &g_val << endl;
        g_val--;
    }
    return nullptr;
}
int main()
{
    pthread_t tid;
    pthread_create(&tid, nullptr, ThreadRoutine, (void*)"thread-1");
    while(1)
    {
        sleep(1);
        cout << "main thread"<< ", g_val = " << g_val <<  ", &g_val:" << &g_val << endl;
    }


    return 0;
}