#include "RingQueue.hpp"
#include <unistd.h>
#include "Task.hpp"
#include "RQThreadData.hpp"
void *Productor(void *args)
{
    ThreadData<Task> *td = static_cast<ThreadData<Task> *>(args);
    while(true)
    {
        int x = rand() % 11;//[0,10];
        int y = rand() % 11;//[0,10];
        char opt = opts[rand() % opts.size()];
        Task t(x, y, opt);
        std::cout << "Productor data is " << t.print_task() << ", " << td->name << std::endl;
        td->rq->Push(t);
        usleep(1000);
    }
}
void *Consumer(void *args)
{
    ThreadData<Task> *td = static_cast<ThreadData<Task> *>(args);
    //RingQueue<Task> *rq = static_cast<RingQueue<Task> *>(args);
    while(true)
    {
        Task t;
        td->rq->Pop(&t);
        t();
        std::cout<< "Consumer result is " << t.print_result() << ", " << td->name  << std::endl;
    } 
}
int main()
{
    srand((unsigned int)time(nullptr) ^ getpid() ^ pthread_self());
    pthread_t c[3], p[2];
    RingQueue<Task> *rq = new RingQueue<Task>();
    ThreadData<Task> td[5];
    td[0].rq = rq;
    td[0].name = "Thread-1";
    td[1].rq = rq;
    td[1].name = "Thread-2";
    td[2].rq = rq;
    td[2].name = "Thread-3";
    td[3].rq = rq;
    td[3].name = "Thread-4";
    td[4].rq = rq;
    td[4].name = "Thread-5";

    
    pthread_create(&p[0], nullptr, Productor, td + 3);
    pthread_create(&p[1], nullptr, Productor, td + 4);
    pthread_create(&c[0], nullptr, Consumer, td);   
    pthread_create(&c[1], nullptr, Consumer, td + 1);   
    pthread_create(&c[2], nullptr, Consumer, td + 2);   

    pthread_join(p[0], nullptr);
    pthread_join(p[1], nullptr);
    pthread_join(c[0], nullptr);
    pthread_join(c[1], nullptr);
    pthread_join(c[2], nullptr);

    return 0;
}