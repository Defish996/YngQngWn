#include "Thread.hpp"
#include <unistd.h>

int numsize = 10000;
string GetThreadName()
{
    static int num = 1;
    return static_cast<string>("Thread-"+to_string(num++));
}
void Print(pthread_mutex_t *mutex)
{
    while(true)
    {
        //pthread_mutex_lock(mutex);
        if(numsize > 0)
        {
            usleep(1000);
            std::cout << "the numsize is: "<< numsize << std::endl;
            --numsize;
            // pthread_mutex_unlock(mutex);
        }
        else{
            // pthread_mutex_unlock(mutex);
            break;
        }

    }
}
int main()
{
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, nullptr);

    string name1 = GetThreadName();
    Thread<pthread_mutex_t *> t1(name1, Print, &mutex);

    string name2 = GetThreadName();
    Thread<pthread_mutex_t *> t2(name2, Print, &mutex);  

    string name3 = GetThreadName();
    Thread<pthread_mutex_t *> t3(name3, Print, &mutex);   

    string name4 = GetThreadName();
    Thread<pthread_mutex_t *> t4(name4, Print, &mutex);   
 
    
    string name5 = GetThreadName();
    Thread<pthread_mutex_t *> t5(name5, Print, &mutex);

    t1.Start();
    t2.Start();
    t3.Start();
    t4.Start();
    t5.Start();

    t1.Join();
    t2.Join();
    t3.Join();
    t4.Join();
    t5.Join();

    pthread_mutex_destroy(&mutex);





    return 0;
}