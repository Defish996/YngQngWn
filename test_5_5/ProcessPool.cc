#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <cassert>
#include <sys/wait.h>
#include <sys/types.h>
#include "task.hpp"

using namespace std;

const int num = 5;
static int number = 1;

class channel
{
public:
    channel(int fd, pid_t id)
        : ctrlfd(fd), workid(id)
    {
        name = "channel-" + to_string(number++);
    }

public:
    int ctrlfd; // 这个文件描述符来控制写端
    pid_t workid;//进程id
    string name;//进程名称
};

// 输入参数: const &
// 输出参数: *
// 输入输出参数: &

void Work()
{
    while (true)
    {
        // 子进程的工作是每次接受从父进程传入的4个字节的数据,当然这边也可以每次传一个字节
        int code = 0;
        ssize_t n = read(0, &code, sizeof(code));
        if (n == sizeof(code)) // 说明读到正常值
        {
            if (!init.CheckSafe(code)) // 检查code合法
            {
                continue;
            }
            init.RunTask(code);
        }
        else if (n == 0) // 读到管道文件结尾
        {
            break;
        }
        else // 读取错误
        {
        }
        // cout << "i am runnning,my pid:" << getpid() << endl;
        // sleep(1);
        //
    }
    cout << "child quit" << endl;
}
void Printfd(const vector<int>& fds)
{
    cout << getpid() << "close fds:";
    for(auto fd : fds)
    {
        cout << fd << " ";
    }
    cout << endl;
}
void CreatChannels(vector<channel> *c)
{
    vector<int> old;
    for (int i = 0; i < num; i++)
    {

        // 1.定义并创建管道
        int pipefd[2] = {0};
        int n = pipe(pipefd);
        assert(n == 0);
        (void)n;

        // 2.创建进程
        pid_t id = fork();
        assert(id != -1);

        // 3.构建单向信道
        if (id == 0)
        {
            if(!old.empty())
            {
                for(auto fd:old)
                {
                    close(fd);
                }
                Printfd(old);
            }
            // child
            close(pipefd[1]);
            dup2(pipefd[0], 0);
            // TODO
            Work();
            exit(0); // 进程退出会关闭自己打开的所有fd
        }

        // father
        close(pipefd[0]);
        c->push_back(channel(pipefd[1], id)); // 父进程进行管道写入
        old.push_back(pipefd[1]); //将需要关闭的进程的文件描述符记录下来
    }
}
void PrintDebug(const vector<channel> &e)
{
    for (const auto &channel : e)
    {
        cout << channel.name << "," << channel.ctrlfd << "," << channel.workid << endl;
    }
}
void SendCommand(const vector<channel> &c, bool flag, int num = -1)
{
    int pos = 0;
    while (true)
    {
        // 1.选择任务,根据随机数随机分配给进程
        int command = init.SelectTask();

        // 2.选择信道(进程),进行轮巡式分配任务,保证负载均衡
        const auto &channel = c[pos++];
        pos %= c.size();

        // debug
        // cout << "send command: " << init.ToDesc(command) << "[" << command << "]"
        //      << " in " << channel.name << "work is:" << channel.workid << endl;
        // 3.发送任务
        write(channel.ctrlfd, &command, sizeof(command));

        // 4.判断是否要退出
        if (!flag)
        {
            num--;
            if (num <= 0)
                break;
        }
        sleep(1);
    }
    cout << "SendCommand over......" << endl;
}
// void ProcessExit()
// {
//     exit(0);
// }
void ReleaseChannels(vector<channel> c)
{
    // int num = c.size() - 1;
    // while(num>=0)
    // {
    //     close(c[num].ctrlfd); // 关闭写端
    //     waitpid(c[num--].workid, nullptr, 0);
    // }
    for (const auto &channel : c) // 子进程回收
    {
        // pid_t rid = waitpid(channel.workid, nullptr, 0); //(每一个子进程的pid,文件退出的信号(状态),父进程进行等待的方式)
        // if (rid == channel.workid)
        // {
        //     cout << "wait child" << channel.workid << "success..." << endl;
        //}
        close(channel.ctrlfd); // 关闭写端
        waitpid(channel.workid, nullptr, 0);
    }
}
int main()
{
    vector<channel> channels; // 不推荐指定大小,当指定大小时,会调用指定大小次数的默认构造函数,即调用无参构造函数,还需要提供构造函数的重载,我们提供的构造函数是有参的,不推荐
    // 1. 创建信道,创建进程
    CreatChannels(&channels);
    // PrintDebug(channels);
    // sleep(10);

    // 2. 开始派发任务
    const bool g_always_loop = true;

    //SendCommand(channels,g_always_loop);//愿意让他一直发送
    SendCommand(channels, !g_always_loop, 10); // 有次数限制的发送

    // 3. 回收进程关闭所有的文件描述符,关闭文件写端即可
    ReleaseChannels(channels);

    return 0;
}
