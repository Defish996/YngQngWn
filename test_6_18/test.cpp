#include <iostream>
#include <pthread.h>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;

class RoutineReturn
{
public:
    RoutineReturn(int code, string msg, pthread_t id)
    : _code(code), _msg(msg), _id(id)
    {}

    int _code;
    string _msg;
    pthread_t  _id;
}; 

string ToHex(pthread_t id)
{
    char ans[64];
    snprintf(ans,sizeof(ans),"0x%lx",id);
    return ans;
}
void* ThreadRoutine(void* arg)
{
    pthread_detach(pthread_self());
    const char* thread = (char*) arg;
    int cnt = 5;
    while(cnt)
    {
        cout << "i am " << thread << ", my thread id is: "<< ToHex(pthread_self()) << endl;
        sleep(1);
        cnt--;
    }

   
    return nullptr;
     //RoutineReturn *ret = new RoutineReturn(10, "thread-1 done", pthread_self());
    //pthread_exit((void*)ret);
    //return (void*)"thread-1 done";
}
int main() 
{
    pthread_t id;
    pthread_create(&id,nullptr,ThreadRoutine,(void*)"new thread");
   
    sleep(3);
    int CelN = pthread_cancel(id);

    void *ret = nullptr;
    int n = pthread_join(id, &ret);
    cout << "main thread wait code is: " << n << endl;
    cout << "main thread cancel code is: " << CelN << endl;
    cout << "main thread return code is: " << (int64_t)ret << endl;


     //pthread_detach(id);
    //cout << "i am main thread, my thread id is: " << ToHex(pthread_self()) << endl;
    // void* ret = nullptr;
    // int n = pthread_join(id, &ret);
    // cout << "pthread wait code is: " << n << endl;

    

    // RoutineReturn* r = static_cast<RoutineReturn*>(ret);
    // cout << r->_msg << "my return val is, " << r->_code << ", my id is, " << ToHex(r->_id) << endl;

    sleep(2);
    

    return 0;
}