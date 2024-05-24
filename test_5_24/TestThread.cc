#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <functional>
#include <time.h>
#include <vector>
const int threadnum = 5;
using func_t = std::function<void()>; // functional的 函数模板,参数无,返回值为void,可接受这个类型的函数指针,函数lambda表达式等
class threadData
{
public:
    threadData(const std::string &threadname, const uint64_t &ctime, func_t func)
        : _threadname(threadname), _ctime(ctime), _func(func)
    {
    }

public:
    std::string _threadname;
    uint64_t _ctime;
    func_t _func;
};
void Print()
{
    std::cout << "我是线程执行的任务的一部分" << std::endl;
}
// 新线程
void *threadRountain(void *args)//新线程的起点
{
    threadData *td = static_cast<threadData *>(args); // 将接收到的void*参数args转化为threadData*的类型,static_cast<目的>(源)这样的转化方式更安全,在编译时完成转化
    while (true)
    {
        std::cout << "new thread " << "my name is: " << td->_threadname << ",creat time: " << td->_ctime << std::endl;
        td->_func();//执行对应的函数方法
        // if(td->_threadname=="thread-4")//用于测试多线程进行时,一个线程报错其他线程退出的问题
        // {
        //     int a = 10;
        //     a /= 0;
        // }
        sleep(1);
    }
}

int main()
{
    std::vector<pthread_t> pthreads;//创建多个线程
    for (int i = 0; i < threadnum; i++)
    {
        char threadname[64];
        snprintf(threadname,sizeof(threadname),"%s-%lu","thread",i);//方便将多个线程进行不同的命名放入threadData类中
        pthread_t tid;
        threadData *td = new threadData(threadname, (uint64_t)time(nullptr), Print); // time获取时间戳
        pthread_create(&tid, nullptr, threadRountain, td);                           // pthread_create函数的第四个参数可以传通用的指针类型,新创建的线程会执行threadRountain方法,将
                                                                                     //第三个参数是新线程的起点,他是一个函数,第四个参数是第三个参数的函数参数
        pthreads.push_back(tid);//main线程继续向下执行,子线程从上一步开始于主线程并发执行

        sleep(1);
    }

    for(const auto& e : pthreads)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    while (true)
    {
        std::cout << "main thread " << std::endl;
        sleep(3);
    }

    return 0;
}