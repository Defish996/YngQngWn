#pragma once
#include <iostream>
#include <vector>
#include <semaphore.h>
#include <pthread.h>

const int defaultsize = 5;
template<class T>
class RingQueue
{
private:
    void P(sem_t &sem)//用于申请可以访问的资源
    {
        sem_wait(&sem);
    }
    void V(sem_t &sem)//资源使用完毕
    {
        sem_post(&sem);
    }
public:
    RingQueue(int size = defaultsize):_ringqueue(size), _size(size), _p_step(0), _c_step(0)
    {
        sem_init(&_space_sem, 0, size);
        sem_init(&_data_sem, 0, 0);
    }
    void Push(const T& in)//生产者放入数据
    {
        P(_space_sem);
        _ringqueue[_p_step] = in;
        _p_step++;
        _p_step %= _size;
        V(_data_sem);
    }
    void Pop(T *out)
    {
        P(_data_sem);
        *out = _ringqueue[_c_step];
        _c_step++;
        _c_step %= _size;
        V(_space_sem);
    }
    ~RingQueue()
    {
        sem_destroy(&_space_sem);
        sem_destroy(&_data_sem);
    }
private:
    std::vector<T> _ringqueue;
    int _size;

    sem_t _space_sem;
    sem_t _data_sem; 

    int _p_step;
    int _c_step;
};