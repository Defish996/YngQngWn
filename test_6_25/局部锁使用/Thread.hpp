#include <iostream>
#include <functional>
#include <pthread.h>
#include <string>

using namespace std;
template<class T>
using func_t = function<void(T)>;
template<class T>
class Thread
{
public:
    Thread(const string &name, func_t<T> func, T data)
        : _name(name), _func(func), _data(data), _tid(0), _isrunning(false)
    {}
    static void *ThreadRoutine(void *args)
    {
        Thread *t = static_cast<Thread*>(args);
        t->_func(t->_data); 
        exit(0);
    }
    bool Start()
    {
        int n = pthread_create(&_tid, nullptr, ThreadRoutine, this);
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
