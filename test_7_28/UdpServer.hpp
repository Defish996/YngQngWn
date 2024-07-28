#pragma once
#include "nocopy.hpp"
#include "Log.hpp"
#include "Comm.hpp"
#include "InetAddr.hpp"

#include <iostream>
#include <string>
#include <strings.h>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const static uint16_t defaultport = 8888;
const static int defaultfd = -1;
const static int defaultsize = 1024;

// 父类内不存在拷贝, 所以基类也不存在拷贝
class UdpServer : public nocopy
{
public:
    UdpServer(const std::string &ip, uint16_t port = defaultport)
        : _ip(ip), _port(port)
    {
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

        // 2.绑定, 指定网络信息
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); // 指定的内存大小清零, 也可以使用memset
        // 告诉系统绑定网络通信的信息
        local.sin_family = AF_INET;    // 协议家族, s表示socket的意思, in表示inet, 使用ipconfig查看会发现inet表示IP地址, 这边的in也表示ip地址
        local.sin_port = htons(_port); // 我们自己写的是一个主机序列, 要转化为网络序列
        //绑定随机IP
        //local.sin_addr.s_addr = inet_addr(_ip.c_str());
        local.sin_addr.s_addr = INADDR_ANY;//地址任意

        // 结构体填完, 只是在当前的用户地址空间, 但是还没有设置到内核, 需要调用bind函数
        // 将网络信息与文件信息进行关联
        int n = ::bind(_sockfd, (struct sockaddr *)&local, sizeof(local));
        if (n != 0)
        {
            lg.LogMessage(Fatal, "bind error , %d : %s", errno, strerror(errno));
            exit(Bind_Err);
        }
    }
    void Start()
    {
        // 接收数据
        char buf[defaultsize]; // 缓冲区大小
        while (true)
        {
            struct sockaddr_in peer;      // 远端
            socklen_t len = sizeof(peer); // 不能乱写, 表示长度, 实际是个无符号int
            // 从哪收消息, 放在哪, 信息大小, 预留一个,用于字符串\0, 0表示阻塞式收消息 把缓冲区客户端套接字信息拿出来 套接字长度
            ssize_t n = recvfrom(_sockfd, buf, sizeof(buf) - 1, 0, (struct sockaddr *)&peer, &len);
            if (n > 0)
            {
                InetAddr addr(peer);
                buf[n] = 0;                                                         // 得到信息
                std::cout << "[" << addr.PrintDebug() << "]# " << buf << std::endl; // 服务端收到来自客户端的消息

                // 给对方(客户端)发消息
                sendto(_sockfd, buf, strlen(buf), 0, (struct sockaddr *)&peer, len);
            }
        }
    }
    ~UdpServer() {}

private:
    std::string _ip; // 后期调整
    uint16_t _port;
    int _sockfd; // 套接字文件描述符
};