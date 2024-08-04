#pragma once
#include <iostream>
#include <string>
#include <cerrno>
#include <cstring>

#include "Log.hpp"
#include "nocopy.hpp"
#include "Comm.hpp"

//后面的sockaddr_in的强转较多, 直接写为宏方便
const static int default_backlog = 5;

class TcpServer : public nocopy
{
public:
    TcpServer(int16_t port, bool isrunning = false)
        : _port(port), _isrunning(isrunning)
    {}
    void Init()
    {
        // 1. 创建socket, file fd, 本质是文件
        _listensock = socket(AF_INET, SOCK_STREAM, 0);//创建tcp套接字, 第一个参数不变, 第二个参数是tcp, 面向字节流
        if (_listensock < 0)
        {
            lg.LogMessage(Fatal, "create socket error, errno code: %d, error string: %s\n", errno, strerror(errno));
            exit(Fatal);
        }
        lg.LogMessage(Debug, "create socket success, sockfd: %d\n", _listensock);
        // 2. 填充网络信息并绑定
        struct sockaddr_in local;
        memset(&local, 0, sizeof(local));
        local.sin_addr.s_addr = htonl(INADDR_ANY);//必须是0, 表示任意
        local.sin_family = AF_INET;//IPv4的网络套接字
        local.sin_port = htons(_port);
        if(bind(_listensock, CONV(&local), sizeof(local)) != 0)
        {
            lg.LogMessage(Fatal, "bind socket error, errno code: %d, error string: %s\n", errno, strerror(errno));
            exit(Bind_Err);
        }
        lg.LogMessage(Debug, "bind socket success, sockfd: %d\n", _listensock);
        // 3.设置socket为监听状态
        if(listen(_listensock, default_backlog) != 0)
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
        while(true)
        {
            ssize_t n = read(sockfd, buffer, sizeof(buffer) - 1);
            if(n > 0)
            {
                buffer[n] = 0;
                std::cout << "client say# " << buffer << std::endl;

                std::string echo_string = "server echo# ";
                echo_string += buffer;
                write(sockfd, echo_string.c_str(), echo_string.size());
            }
            else if(n == 0)// read如果为0, 文件中表示读到了结尾, 这边表示对端关闭了连接(与管道的情况一模一样)
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
    void Start()
    {
        _isrunning = true;
        while(_isrunning)
        {
            // 4. 获取链接
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            int sockfd = accept(_listensock, CONV(&peer), &len);// 进行获取链接
            if(sockfd < 0)
            {
                lg.LogMessage(Warning, "accept socket error, errno code: %d, error string: %s\n", errno, strerror(errno));
                continue;// 获取失败则继续获取
            }
            lg.LogMessage(Debug, "accept socket success, get a new sockfd: %d\n", sockfd);
        
            // 5. 提供服务
            Service(sockfd);
            close(sockfd);
        } 
    }
    ~TcpServer(){}
private:
    int16_t _port;//
    int _listensock;
    bool _isrunning;//是否运行
};