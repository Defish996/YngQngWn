#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class InetAddr
{
public:
    InetAddr(struct sockaddr_in &addr)
    {
        port = ntohs(addr.sin_port);      // 网络序列转主机序列
        ip = inet_ntoa(addr.sin_addr); // 网络序列转主机序列
    }
    std::string Ip(){return ip;}
    uint16_t Port(){return port;}
    std::string PrintDebug()
    {
        return ip + ":" + std::to_string(port);
    }
    ~InetAddr() {}

private:
    std::string ip;
    uint16_t port;
};