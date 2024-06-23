#include "Thread.hpp"
#include <cstdio>
#include <unistd.h>
using namespace std;

int ticket = 10000;//全局的共享资源
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

string GetThreadName()
{
    static int num = 1;
    return static_cast<string>("Thread-" + to_string(num++));
}
void GetTicket(string name)
{
    while(true)
    {
        // pthread_mutex_lock(&mutex);
        if(ticket > 0)
        {
            usleep(1000);
            cout << name.c_str() << ", Get a ticket: " << ticket << endl;
            ticket--;
            // pthread_mutex_unlock(&mutex);
        }
        else
        {
            // pthread_mutex_unlock(&mutex);
            break;
        }
    }
}
int main()
{
    string name1 = GetThreadName();
    Thread<string> t1(name1, GetTicket, name1);

    string name2 = GetThreadName();
    Thread<string> t2(name2, GetTicket, name2);  

    string name3 = GetThreadName();
    Thread<string> t3(name3, GetTicket, name3);   

    string name4 = GetThreadName();
    Thread<string> t4(name4, GetTicket, name4);   
 
    
    string name5 = GetThreadName();
    Thread<string> t5(name5, GetTicket, name5);


    t1.Start();
    t2.Start();
    t3.Start();
    t4.Start();
    t5.Start();

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();




    return 0;
}

