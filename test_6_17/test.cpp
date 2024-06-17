#include <iostream>
#include <pthread.h>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;

string ToHex(pthread_t id)
{
    char ans[64];
    snprintf(ans,sizeof(ans),"0x%lx",id);
    return ans;
}
void* ThreadRoutine(void* arg)
{
    const char* thread = (char*) arg;
    int cnt = 5;
    while(cnt)
    {
        cout << "i am " << thread << ", my thread id is: "<< ToHex(pthread_self()) << endl;
        sleep(1);
        cnt--;
    }
    pthread_exit((void*)"thread-1 done");
    //return (void*)"thread-1 done";

}
int main() 
{
    // pthread_t id;
    // pthread_create(&id,nullptr,ThreadRoutine,(void*)"new thread");

    // //cout << "i am main thread, my thread id is: " << ToHex(pthread_self()) << endl;
    // void* ret;
    // int n = pthread_join(id, &ret);
    // cout << (const char*)ret << endl;
    // cout << "error code is: " << n << endl;

    while (1)
    {
        uint64_t id = (uint64_t)time(nullptr);
        cout << id << endl;
        sleep(1);
    }

    return 0;
}