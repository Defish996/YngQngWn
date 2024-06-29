#include <iostream>
#include <unistd.h>
#include <string>
#include <pthread.h>

//创建条件变量和互斥锁
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int ticket = 1000;

void *ThreadRoutine(void* args)
{
    std::string name = static_cast<const char *>(args);
    while(true)
    {
        //sleep(1);
        pthread_mutex_lock(&mutex);
        if(ticket > 0)
        {   
            std::cout << name << ", ticket is: " << ticket-- << std::endl;
            usleep(1000);
        }
        else
        {
            std::cout << name << ", no ticket" << std::endl;
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{

    pthread_t t1, t2, t3;
    pthread_create(&t1, nullptr, ThreadRoutine, (void*)"Thread-1");
    pthread_create(&t2, nullptr, ThreadRoutine, (void*)"Thread-2");
    pthread_create(&t3, nullptr, ThreadRoutine, (void*)"Thread-3");


    while(true)
    {
        sleep(6);
        pthread_mutex_lock(&mutex);
        ticket+=100;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
          
    }
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);
    pthread_join(t3, nullptr);



    return 0;
}