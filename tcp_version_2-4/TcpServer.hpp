#pragma once
#include <iostream>
#include <string>
#include <cerrno>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "Log.hpp"
#include "nocopy.hpp"
#include "Comm.hpp"

// 后面的sockaddr_in的强转较多, 直接写为宏方便
const static int default_backlog = 5;

class TcpServer;
class ThreadData// 因为线程的执行顺序不确定, 所以包装这个类保证被子线程先获取到sockfd
{
public:
    ThreadData(int sockfd, TcpServer *ptr)
        : _sockfd(sockfd), svr_ptr(ptr)
    {}
    int Sockfd()
    {
        return _sockfd;
    } 
    TcpServer *GetServer()
    {
        return svr_ptr;
    }
    ~ThreadData(){
        close(_sockfd);
    }
private:
    int _sockfd;
    TcpServer *svr_ptr;
};

class TcpServer : public nocopy
{
public:
    TcpServer(int16_t port, bool isrunning = false)
        : _port(port), _isrunning(isrunning)
    {
    }
    void Init()
    {
        // 1. 创建socket, file fd, 本质是文件
        _listensock = socket(AF_INET, SOCK_STREAM, 0); // 创建tcp套接字, 第一个参数不变, 第二个参数是tcp, 面向字节流
        if (_listensock < 0)
        {
            lg.LogMessage(Fatal, "create socket error, errno code: %d, error string: %s\n", errno, strerror(errno));
            exit(Fatal);
        }
        lg.LogMessage(Debug, "create socket success, sockfd: %d\n", _listensock);

        // 固定写法, 解决一些少量的bind失败问题
        int opt = 1;
        setsockopt(_listensock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
        // 2. 填充网络信息并绑定
        struct sockaddr_in local;
        memset(&local, 0, sizeof(local));
        local.sin_addr.s_addr = htonl(INADDR_ANY); // 必须是0, 表示任意
        local.sin_family = AF_INET;                // IPv4的网络套接字
        local.sin_port = htons(_port);
        if (bind(_listensock, CONV(&local), sizeof(local)) != 0)
        {
            lg.LogMessage(Fatal, "bind socket error, errno code: %d, error string: %s\n", errno, strerror(errno));
            exit(Bind_Err);
        }
        lg.LogMessage(Debug, "bind socket success, sockfd: %d\n", _listensock);
        // 3.设置socket为监听状态
        if (listen(_listensock, default_backlog) != 0)
        {
            lg.LogMessage(Fatal, "listen socket error, errno code: %d, error string: %s\n", errno, strerror(errno));
            exit(Listen_Err);
        }
        lg.LogMessage(Debug, "listen socket success, sockfd: %d\n", _listensock);
    }
    // 这个sockfd表示连接是全双工的
    void Service(int sockfd)
    {
        char buffer[1024];
        while (true)
        {
            ssize_t n = read(sockfd, buffer, sizeof(buffer) - 1);
            if (n > 0)
            {
                buffer[n] = 0;
                std::cout << "client say# " << buffer << std::endl;

                std::string echo_string = "server echo# ";
                echo_string += buffer;
                write(sockfd, echo_string.c_str(), echo_string.size());
            }
            else if (n == 0) // read如果为0, 文件中表示读到了结尾, 这边表示对端关闭了连接(与管道的情况一模一样)
            {
                lg.LogMessage(Info, "client quit...\n");
                break;
            }
            else
            {
                lg.LogMessage(Error, "read error, errno code: %d, error string: %s\n", errno, strerror(errno));
                break;
            }
        }
    }

    static void *HelderRequest(void *args) // 当前的这个函数包含this 指针
    {
        pthread_detach(pthread_self()); // 分离自己这个线程
        ThreadData *td = static_cast<ThreadData *>(args);
        td->GetServer()->Service(td->Sockfd());
        // 关闭文件描述符表的功能放在ThreadData的析构中 
        //close(td->Sockfd());

        delete td;
        return nullptr;
    }
    void Start()
    {
        _isrunning = true;
        signal(SIGCHLD, SIG_IGN); // 在linux 中, 如果对SIGCHLD设置为SIG_IGN, 则会自动回收子进程, 不会wait阻塞住
        while (_isrunning)
        {
            // 4. 获取链接
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            int sockfd = accept(_listensock, CONV(&peer), &len); // 进行获取链接
            if (sockfd < 0)
            {
                lg.LogMessage(Warning, "accept socket error, errno code: %d, error string: %s\n", errno, strerror(errno));
                continue; // 获取失败则继续获取
            }
            lg.LogMessage(Debug, "accept socket success, get a new sockfd: %d\n", sockfd);

            // // 5. 提供服务
            // Service(sockfd);
            // close(sockfd);

            // // v2 多进程
            // pid_t id = fork();
            // if (id < 0) // fork失败
            // {
            //     lg.LogMessage(Error, "fork error, errno code: %d, error string: %s\n", errno, strerror(errno));
            //     continue;
            // }
            // else if (id == 0)
            // {
            //     // 子进程
            //     close(_listensock);
            //     if(fork() > 0) exit(0);
                
            //     // 孙子进程
            //     // 子进程的退出, 会被父进程立马回收, 不会wait阻塞住, 这时孙子进程和父进程各司其职
            //     Service(sockfd);
            //     close(sockfd);
            //     //退出之后, 孙子进程由父进程进行领养
            // }
            // else // 父进程
            // {
            //     close(sockfd);
            //     pid_t rid = waitpid(id, nullptr, 0); // 这边子进程不退出, 父进程会一直阻塞等待, 还是没有达到并发的目的,如何解决, 看子进程
            //     if(rid == id)
            //     {
            //         lg.LogMessage(Info, "child process quit...\n");
            //     }
            // }

            // //v3 信号版本   
            // pid_t id = fork();
            // if (id < 0) // fork失败
            // {
            //     lg.LogMessage(Error, "fork error, errno code: %d, error string: %s\n", errno, strerror(errno));
            //     close(sockfd);
            //     continue;
            // }
            // else if (id == 0)
            // {
            //     // 子进程
            //     close(_listensock);
            //     Service(sockfd);
            //     close(sockfd);
            //     exit(0);
            // }
            // else // 父进程
            // {
            //     close(sockfd);
            // }
            
            // v4 多线程
            ThreadData *td = new ThreadData(sockfd, this);
            pthread_t tid;
            pthread_create(&tid, nullptr, HelderRequest, td);
            // 不等待新线程, 只需要设置为分离状态, 这样子线程被OS 回收, 不会阻塞住
        }
    }
    ~TcpServer() {}

private:
    int16_t _port; //
    int _listensock;
    bool _isrunning; // 是否运行
};