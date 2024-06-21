#include <iostream>
#include "Thread.hpp"
#include <vector>

void Print(int cnt)
{
    while(cnt--)
    {
        cout << "hello world" << endl;
        sleep(1);
    }
}
string GetThreadName()
{
    static int num = 0;
    return static_cast<string>("Thread-") + to_string(++num);
}

int main()
{
    Thread<int> t(GetThreadName(), Print, 10);
    t.Start();
    t.join();

    // int num = 5; 
    // vector<Thread> threads;
    // for(int i = 0; i < num; ++i)
    // {
    //     threads.emplace_back(Print, GetThreadName());
    // }
    // for(int i = 0; i < num; ++i)
    // {
    //     cout << "Is thread is running? " << threads[i].IsRunning() << endl;
    // }

    // for(int i = 0; i < num; ++i)
    // {
    //     threads[i].Start();
    // }
    // for(int i = 0; i < num; ++i)
    // {
    //     cout << "Is thread is running? " << threads[i].IsRunning() << endl;
    // }

    // for(int i = 0; i < num; ++i)
    // {
    //     threads[i].join();
    // }



    return 0;
}