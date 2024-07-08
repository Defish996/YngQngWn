#pragma once
#include <iostream>
#include <string>
template <class T>
class ThreadData
{
public:
    RingQueue<T> *rq;
    std::string name;
};