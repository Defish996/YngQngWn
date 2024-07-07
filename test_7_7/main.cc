#include "RingQueue.hpp"
#include <unistd.h>
void *Productor(void *args)
{
    RingQueue<int> *rq = static_cast<RingQueue<int> *>(args);
    int cnt = 100;
    while(true)
    {
        rq->Push(cnt);
        std::cout << "Productor done, the data is " << cnt << std::endl;
        cnt--;
    }
}
void *Consumer(void *args)
{
    RingQueue<int> *rq = static_cast<RingQueue<int> *>(args);
    while(true)
    {
        int data = 0;
        rq->Pop(&data);
        std::cout << "Consumer done, the data is " << data << std::endl;
        sleep(1);
    }
    
}
int main()
{
    pthread_t c, p;
    RingQueue<int> *rq = new RingQueue<int>();
    pthread_create(&p, nullptr, Productor, rq);
    pthread_create(&c, nullptr, Consumer, rq);   

    pthread_join(p, nullptr);
    pthread_join(c, nullptr);


    return 0;
}