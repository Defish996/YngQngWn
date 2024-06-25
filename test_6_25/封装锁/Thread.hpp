#pragma once
#include <iostream>
#include <functional>
#include <pthread.h>
#include <string>

using namespace std;
template<class T>
using func_t = function<void(T)>;//std::function 是C++标准库中的一个模板类,可以包装任何可调用目标（callable target），比如函数、lambda表达式、函数对象（functor）等。
template<class T>
class Thread
{
public:
    Thread(const string &name, func_t<T> func, T data)
        : _name(name), _func(func), _data(data), _tid(0), _isrunning(false)
    {}
    static void *ThreadRoutine(void *args)//子线程入口,接受参数为当前对象的指针
    {
        Thread *t = static_cast<Thread*>(args);//转义为所需要的指针类型,当前的t和this一样,但是不能与库内的this进行重名
        t->_func(t->_data); //当前对象调用参数_func(他是一个function类创建的对象,这个类可以包装任何内容,这边包装函数,_func是这个函数模板创建的对象),接受来自Thread创建时的第三个参数
        //到这边是完成对整个类的包装,模板概念已经结束,具体操作回到main内查看,对应的函数执行结束后,执行exit(0)
        exit(0);
    }
    bool Start()
    {
        int n = pthread_create(&_tid, nullptr, ThreadRoutine, this);//创建线程,加载输出OS给的tid,默认方式创建(不设置分离状态,栈大小等),子线程入口,传入参数给子线程
        if(n == 0)
        {
            _isrunning = true;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool Join()
    {
        if(!_isrunning)
        {
            return true;
        }
        int n = pthread_join(_tid, nullptr);
        if(n == 0)
        {
            _isrunning = false;
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Thread(){}
    bool IsRunning()
    {
        return _isrunning;
    }

private:
    pthread_t _tid;
    string _name;
    func_t<T> _func;
    T _data;
    bool _isrunning;
};
