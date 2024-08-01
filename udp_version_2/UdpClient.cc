#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Thread.hpp"
#include "InetAddr.hpp"

class ThreadData
{
public:
    ThreadData(int sockfd, struct sockaddr_in &server)
        : _sockfd(sockfd), _serveraddr(server)
    {
    }
    ~ThreadData() {}

public:
    int _sockfd;
    InetAddr _serveraddr;
};

void RecverRoutine(ThreadData &td) // 收消息
{
    char buffer[4096] = {0};
    while (true)
    {
        // 从sock收消息
        struct sockaddr_in temp;
        socklen_t len = sizeof(temp);
        ssize_t n = recvfrom(td._sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&temp, &len); // 最后两个参数建议要填, 不然会有问题
        if (n > 0)
        {
            buffer[n] = 0;
            std::cerr << buffer << std::endl;
        }
        else break;
    }
}
void SenderRoutine(ThreadData &td) // 只负责发消息
{
    while (true)
    {
        // 客户端信息输入, 发消息
        std::string inbuffer;
        std::cout << "Please Enter#: ";
        std::getline(std::cin, inbuffer);

        // 给server发消息
        auto server = td._serveraddr.GetAddr();
        ssize_t n = sendto(td._sockfd, inbuffer.c_str(), inbuffer.size(), 0, (struct sockaddr *)&server, sizeof(server)); // 向sock发消息
        // 我不发消息就会阻塞在这里
        if (n <= 0)
            std::cout << "sendto error" << std::endl;
    }
}
void Usage(const std::string &proc)
{
    std::cout << "Usage: " << proc << " server_ip server_port" << std::endl;
}

// ./udp_client server_ip server_port  将来由服务器提供
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        return 1;
    }
    std::string serverip = argv[1];
    uint16_t serverport = std::stoi(argv[2]);
    // 1. 创建套接字
    // udp是全双工的, 不会引起多线程读写问题
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        std::cerr << "socket error: " << strerror(errno) << std::endl;
        return 2;
    }
    std::cout << "create socket successful : " << sock << std::endl;

    // 2.bind绑定套接字和用户地址空间 不需要显示bind,client会在首次发送数据时自动绑定
    // client需要bind, 但是不需要显示bind, 让本地的ip和port随机bind
    // 2.1 填充套接字信息
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport); // 主机字节序列转网络字节序列
    server.sin_addr.s_addr = inet_addr(serverip.c_str());

    ThreadData td(sock, server);
    Thread<ThreadData> recver("recver", RecverRoutine, td);
    Thread<ThreadData> sender("recver", SenderRoutine, td);
    recver.Start();
    sender.Start();

    recver.join();
    sender.join();
    close(sock);
    return 0;
}