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
        :_addr(addr)
    {
        _port = ntohs(_addr.sin_port);      // 网络序列转主机序列
        _ip = inet_ntoa(_addr.sin_addr); // 网络序列转主机序列
    }
    std::string Ip(){return _ip;}
    uint16_t Port(){return _port;}
    std::string PrintDebug()
    {
        return _ip + ":" + std::to_string(_port);
    }
    ~InetAddr() {}

private:
    std::string _ip;
    uint16_t _port;
    struct sockaddr_in _addr;
};