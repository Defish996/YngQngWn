#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <cassert>
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
    pid_t workid;
    string name;
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
        assert(n == sizeof(code));
        (void)n;

        if (!init.CheckSafe(code))
            continue; // 检查这个传入的code具有合法性,合法性判断在CheckSafe定义处
        init.RunTask(code);


        // cout << "i am runnning,my pid:" << getpid() << endl;
        // sleep(1);
    }
}
void CreatChannels(vector<channel> *c)
{
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
            // child
            close(pipefd[1]);
            dup2(pipefd[0],0);
            // TODO
            Work();
            exit(0);
        }

        // father
        close(pipefd[0]);
        c->push_back(channel(pipefd[1], id)); // 父进程进行管道写入,
    }
}
void PrintDebug(const vector<channel> &e)
{
    for (const auto &channel : e)
    {
        cout << channel.name << "," << channel.ctrlfd << "," << channel.workid << endl;
    }
}
void SendCommand(const vector<channel>& c,bool flag,int num = -1)
{
    int pos = 0;
    while (true)
    {
        // 1.选择任务,根据随机数随机分配给进程
        int command = init.SelectTask();

        // 2.选择信道(进程),进行轮巡式分配任务,保证负载均衡
        const auto &channel = c[pos++];
        pos %= c.size();
        
        // 3.发送任务
        write(channel.ctrlfd, &command, sizeof(command));

        //4.判断是否要退出
        if(!flag)
        {
            num--;
            if(num<=0) break;
        }
        sleep(1);
    }
}
const bool g_always_loop = true;
int main()
{
    vector<channel> channels; // 不推荐指定大小,当指定大小时,会调用指定大小次数的默认构造函数,即调用无参构造函数,还需要提供构造函数的重载,不推荐
    // 创建信道,创建进程
    CreatChannels(&channels);
    // PrintDebug(channels);
    // sleep(10);

    //开始派发任务
    //SendCommand(channels,g_always_loop);//愿意让他一直发送
    SendCommand(channels,!g_always_loop,10);//有次数限制的发送


    return 0;
}
