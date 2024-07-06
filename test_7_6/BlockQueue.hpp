#pragma once
#include <iostream>
#include <pthread.h>
#include <queue>
#include "LockGuard.hpp"

int defaultcap = 5; // for test

template <class T>
class BlockQueue
{
public:
    BlockQueue(int cap = defaultcap)//初始为default个空间的大小
        : _capacity(cap)
    {
        pthread_mutex_init(&_mutex, nullptr);
        pthread_cond_init(&_p_cond, nullptr);
        pthread_cond_init(&_c_cond, nullptr);
    }
    bool IsEmpty()
    {
        return _q.size() == 0;//查看队列状态
    }
    bool IsFull()
    {
        return _q.size() == _capacity;//此时为满,
    }
    bool Pop(T *out)
    {
        LockGuard lg(&_mutex);
        while(IsEmpty())
        {
            //为空, 进行等待
            pthread_cond_wait(&_c_cond, &_mutex);
        }
        *out = _q.front();
        _q.pop();
        //可以生产//可增加水准线进行响应的操作
        pthread_cond_signal(&_p_cond);
        //pthread_mutex_unlock(&_mutex);
        return true;
    }
    bool Push(const T &in)//放入队列操作
    {
        // 当前变量进行加锁,只允许一个线程进入
        LockGuard lg(&_mutex);
        //pthread_mutex_lock(&_mutex);
        while(IsFull())
        {
            // 为满,进行阻塞等待
            pthread_cond_wait(&_p_cond, &_mutex);
        }
        // 进行生产等待
        _q.push(in);
        //可以进行消费
        pthread_cond_signal(&_c_cond);
        //pthread_mutex_unlock(&_mutex);
        return true;
    }
    ~BlockQueue()
    {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_p_cond);
        pthread_cond_destroy(&_c_cond);
    }

private:
    std::queue<T> _q;
    int _capacity; // 为空时,不能再消费,为满时,不能再生产,状态是capacity与size进行比较
    pthread_mutex_t _mutex;
    pthread_cond_t _p_cond;
    pthread_cond_t _c_cond;
};