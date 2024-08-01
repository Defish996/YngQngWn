#pragma once
#include "nocopy.hpp"
#include "Log.hpp"
#include "Comm.hpp"
#include "InetAddr.hpp"
#include "ThreadPool.hpp"

#include <iostream>
#include <string>
#include <strings.h>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <functional>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



const static uint16_t defaultport = 8888;
const static int defaultfd = -1;
const static int defaultsize = 1024;

using cb_t = std::function<std::string(std::string)>;//定义函数类型 <返回值(参数)>
using task_t = std::function<void()>;//定义函数类型 <返回值(参数)>

// 父类内不存在拷贝, 所以基类也不存在拷贝
class UdpServer : public nocopy
{
public:
    UdpServer(cb_t OnMessage, uint16_t port = defaultport)
        : _port(port), _OnMessage(OnMessage)
    {
        pthread_mutex_init(&_user_mutex, nullptr);
    }
    void Init()
    {
        // 1.创建socket, 就是创建了一个文件信息
        _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (_sockfd < 0)
        {
            lg.LogMessage(Fatal, "socket error , %d : %s", errno, strerror(errno));
            exit(Socket_Err);
        }
        lg.LogMessage(Info, "socket success, sockfd : %d\n", _sockfd);

        // 2.绑定, 指定网络信息, 填充这个SOCKET结构体
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); // 指定的内存大小清零, 也可以使用memset
        // 告诉系统绑定网络通信的信息
        local.sin_family = AF_INET;    // 协议家族, s表示socket的意思, in表示inet, 使用ipconfig查看会发现inet表示IP地址, 这边的in也表示ip地址
        local.sin_port = htons(_port); // 我们自己写的是一个主机序列, 要转化为网络序列
        //绑定随机IP
        //local.sin_addr.s_addr = inet_addr(_ip.c_str());
        local.sin_addr.s_addr = INADDR_ANY;//地址任意 为0

        // 结构体填完, 只是在当前的用户地址空间, 但是还没有设置到内核, 需要调用bind函数
        // 将网络信息与文件信息进行关联
        int n = ::bind(_sockfd, (struct sockaddr *)&local, sizeof(local));
        if (n != 0)
        {
            lg.LogMessage(Fatal, "bind error , %d : %s", errno, strerror(errno));
            exit(Bind_Err);
        }
        ThreadPool<task_t>::GetInstance()->Start();
    }
    void AddOnlineUser(InetAddr addr)//添加用户到在线列表
    {
        LockGuard lock(&_user_mutex);
        for(auto &it : _online_user)
        {
            if(addr == it) return;
        }
        _online_user.push_back(addr);

        //日志打印添加成功
        lg.LogMessage(Debug, "AddOnlineUser: %s\n", addr.PrintDebug().c_str());

    }
    //将message要执行的Route 方法
    void Route(int sock, const std::string &message)//version_2要执行的内容, 将message通过sock发送给所有在线用户
    {
        LockGuard lock(&_user_mutex);
        for(auto &it : _online_user)
        {
            //执行任务, 将message发给指定的人
            sendto(sock, message.c_str(), message.size(), 0, (struct sockaddr *)&it.GetAddr(), sizeof(it.GetAddr()));
            lg.LogMessage(Debug, "Send message to %s, message is %s\n", it.PrintDebug().c_str(), message.c_str());
        }
    }
    void Start()
    {
        // 接收消息
        char buf[defaultsize]; // 缓冲区大小
        while (true)
        {
            struct sockaddr_in peer;      // 远端
            socklen_t len = sizeof(peer); // 不能乱写, 表示长度, 实际是个无符号int
            // 从哪收消息, 放在哪, 信息大小, 预留一个,用于字符串\0, 0表示阻塞式收消息 把缓冲区客户端套接字信息拿出来 套接字长度
            //verxion_2消息有了
            ssize_t n = recvfrom(_sockfd, buf, sizeof(buf) - 1, 0, (struct sockaddr *)&peer, &len);
            //收消息成功
            if (n > 0)
            {
                //version_2用户也有了
                //添加用户
                AddOnlineUser(InetAddr(peer));//添加在线用户
                buf[n] = 0;                                                         // 得到信息
                
                //version_2任务的理解, 主线程做什么 
                std::string message = "[" + InetAddr(peer).PrintDebug() + "]: ";
                message += buf;//获取消息
                //消息与任务进行绑定
                task_t task = std::bind(&UdpServer::Route, this, _sockfd, message);//将路由方法, 当前对象 哪个套接字 路由哪个消息
                ThreadPool<task_t>::GetInstance()->Push(task);//push任务到线程池进行Route
            }
        }
    }
    ~UdpServer() {
        pthread_mutex_destroy(&_user_mutex);
    }

private:
    //std::string _ip; // 后期调整
    uint16_t _port;
    int _sockfd; // 套接字文件描述符
    std::vector<InetAddr> _online_user;// 在线用户, 可被多个线程同时访问
    pthread_mutex_t _user_mutex;

    cb_t _OnMessage;// 回调函数
};