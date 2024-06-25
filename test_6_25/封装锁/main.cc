#include "Thread.hpp"
#include <unistd.h>
#include "LockGuard.hpp"

class ThreadData
{
public:
    ThreadData(string name, pthread_mutex_t *pmutex)
        : _name(name), pmutex(pmutex)
    {
    }
    ~ThreadData()
    {
    }

public:
    string _name;
    pthread_mutex_t *pmutex;
};
int numsize = 10000;

string GetThreadName()
{
    static int num = 1;
    return static_cast<string>("Thread-" + to_string(num++));
}
void Print(ThreadData *td)//执行Print方法,参数是来自线程创建函数的第四个参数,这一功能也由线程创建函数实现,功不可没,十分可秒啊
{
    //全局内定义的参数进行--操作,验证线程互斥问题
    while (true)
    {
        {//将临界区进行花括号包裹,代码更加明显
            LockGuard lockguard(td->pmutex);//利用锁保护功能模块进行加锁(启动锁)
            // LockGuard lockguard(&mutex);
            // pthread_mutex_lock(mutex);
            if (numsize > 0)
            {

                usleep(1000);
                std::cout << td->_name << ", the numsize is: " << numsize << std::endl;
                --numsize;
                // pthread_mutex_unlock(mutex);
            }
            else
            {
                // pthread_mutex_unlock(mutex);
                break;
            }
        }//加锁, 解锁功能结束,一个线程访问临界区的操作也结束,意味着后续线程可以访问这个临界区

        //在运行结果时会发现,有时候会出现一个线程把所有numsize都分完了,这是因为线程执行多久是由于时间片决定,当在多线程情况下把所有任务(同一份资源)都做完的情况叫做多线程饥饿问题
    }
}

int main()
{
    pthread_mutex_t mutex; // 创建锁初始化
    pthread_mutex_init(&mutex, nullptr);

    string name1 = GetThreadName();//获取线程名称
    ThreadData *td1 = new ThreadData(name1, &mutex); // 将锁和线程的名字的信息写入ThreadData,便于管理
    Thread<ThreadData *> t1(name1, Print, td1);//为线程创建进行加载对应信息

    string name2 = GetThreadName();
    ThreadData *td2 = new ThreadData(name2, &mutex);
    Thread<ThreadData *> t2(name2, Print, td2);

    string name3 = GetThreadName();
    ThreadData *td3 = new ThreadData(name3, &mutex);
    Thread<ThreadData *> t3(name3, Print, td3);

    string name4 = GetThreadName();
    ThreadData *td4 = new ThreadData(name4, &mutex);
    Thread<ThreadData *> t4(name4, Print, td4);

    string name5 = GetThreadName();
    ThreadData *td5 = new ThreadData(name5, &mutex);
    Thread<ThreadData *> t5(name5, Print, td5);

    t1.Start();//线程启动
    t2.Start();
    t3.Start();
    t4.Start();
    t5.Start();

    t1.Join();//线程等待
    t2.Join();
    t3.Join();
    t4.Join();
    t5.Join();

    pthread_mutex_destroy(&mutex); // 消除锁

    return 0;
}