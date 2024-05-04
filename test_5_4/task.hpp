#pragma once

#include <iostream>
#include <functional>
#include <vector>
#include <unistd.h>
#include <ctime> 
using namespace std;
//using task_t = function<void()>;
typedef function<void()> task_t;
void Download()
{
    cout << "我是一个下载任务" << endl;
}
void PrintLog()
{
    cout << "我是一个打印日志任务" << endl;
}
void PushVideoStream()
{

    cout << "我是一个推送视频流任务" << endl;
}

class Init
{
public:
    // 任务集合
    vector<task_t> tasks; // 将上述的三个函数的功能添加到这个vector里面
    // 任务码
    const static int g_download_code = 0;
    const static int g_printlog_code = 1;
    const static int g_push_videostream_code = 2;
public:
    Init()
    {
        tasks.push_back(Download);
        tasks.push_back(PrintLog);
        tasks.push_back(PushVideoStream);

        srand(time(nullptr) ^ getpid());//随机数种子生成
    }
    bool CheckSafe(int code)//保障传过来的任务码是合法的
    {
        if(code >= 0 && code < tasks.size()) return true;
        else return false;
    }
    void RunTask(int code)
    {
        return tasks[code]();//根据传入的code找到对应的vector,然后每次vector里面是一些方法,然后顺便执行调用

    }
    int SelectTask()
    {
        return rand() % tasks.size();
    }
};
Init init; //创建对象
