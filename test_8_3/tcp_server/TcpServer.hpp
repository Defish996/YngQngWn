#pragma once
#include <iostream>
#include <string>
#include <cerrno>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include "Log.hpp"
#include "nocopy.hpp"

class TcpServer : public nocopy
{
public:
    TcpServer(int16_t port)
        : _port(port)
    {}
    void Init()
    {
        // 1. 创建socket, file fd, 本质是文件
        _sockfd = socket(AF_INET, SOCK_STREAM, 0);//创建tcp套接字, 第一个参数不变, 第二个参数是tcp, 面向字节流
        if (_sockfd < 0)
        {
            lg.LogMessage(Fatal, "create socket error, errno code: %d, error string: %s\n", errno, strerror(errno));
            exit(Fatal);
        }
        lg.LogMessage(Debug, "create socket success, sockfd: %d\n", _sockfd);
    }
    void Start()
    {

    }
    ~TcpServer(){}
private:
    int16_t _port;//
    int _sockfd;
};