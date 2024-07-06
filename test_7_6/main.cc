#include "BlockQueue.hpp"
#include "Task.hpp"
#include <pthread.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>


class ThreadData
{
public:
    BlockQueue<Task> *bq;
    std::string name;
};
void *productor(void *args)//生产者
{
    ThreadData *td = static_cast<ThreadData *>(args);
    //BlockQueue<Task> *bq = static_cast<BlockQueue<Task> *>(args);//阻塞队列的对象
    while(true)
    {
        int x = rand() % 11;//[0,10];
        int y = rand() % 11;//[0,10];
        char opt = opts[rand() % opts.size()];
        Task t(x, y, opt);
        std::cout << t.print_task() << std::endl;;
        td->bq->Push(t);//放入队列,队列size+1

        //usleep(1000);
    }
}
void *consumer(void *args)
{
    ThreadData *td = static_cast<ThreadData *>(args);
    //BlockQueue<Task> *bq = static_cast<BlockQueue<Task> *>(args);
    while(true)
    {
        sleep(1);
        Task t;
        //1.拿到消费数据
        td->bq->Pop(&t);

        //2.执行任务
        t();
        
        //3.打印任务信息
        std::cout << t.print_result() << td->name << std::endl;;
    }
}
int main()
{
    srand((uint64_t)time(nullptr) ^ getpid() ^ pthread_self());//伪随机种子
    BlockQueue<Task> * bq = new BlockQueue<Task>();//创建一个阻塞队列
    pthread_t c[3], p[2];//两个线程
    ThreadData td[3];
    td[0].bq = bq;
    td[0].name = "thread-1";
    td[1].bq = bq;
    td[1].name = "thread-2";
    td[2].bq = bq;
    td[2].name = "thread-3";

    pthread_create(&p[0], nullptr, productor, td);//两个线程模拟消费者生产者模型
    pthread_create(&p[1], nullptr, productor, td+1);
    
    pthread_create(&c[0], nullptr, consumer, td);
    pthread_create(&c[1], nullptr, consumer, td+1);
    pthread_create(&c[2], nullptr, consumer, td+2);



    pthread_join(p[0], nullptr);
    pthread_join(p[1], nullptr);
    pthread_join(c[0], nullptr);
    pthread_join(c[1], nullptr);
    pthread_join(c[2], nullptr);

    return 0;
}