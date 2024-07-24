#include <iostream>
#include <memory>
#include <ctime>
#include "ThreadPool.hpp"
#include "Task.hpp"
int main()
{
    // std::unique_ptr<ThreadPool<Task>> tp(new ThreadPool<Task>());
    //tp->Start();
    
    ThreadPool<Task>::GetInstance()->Start();

    srand((uint64_t)time(nullptr) ^ getpid());
    
    while (true)
    {
        // 未来可以将这个任务换成对应的任务即可
        int x = rand() % 100 + 1;
        usleep(1000);
        int y = rand() % 200;
        usleep(1000);
        char oper = opts[rand() % opts.size()];

        Task t(x, y, oper);

        ThreadPool<Task>::GetInstance()->Push(t);
        sleep(1);
    }
    ThreadPool<Task>::GetInstance()->Wait();
    // TODO
    return 0;
}