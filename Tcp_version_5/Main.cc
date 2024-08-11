#include "TcpServer.hpp"
#include "Comm.hpp"
#include <memory>

void Usage(std::string proc)
{
    std::cout << "Usage : \n\t" << proc <<" local_port\n" << std::endl;
}
void Ping(int sockfd, InetAddr addr) // 执行ping指令的内容, 也就是之前tcp_server里面servre方法要做的事
{
    lg.LogMessage(Debug, "%s select %s success, fd : %d\n", addr.PrintDebug().c_str(), "ping", sockfd);
    char buf[1024];
    
    // 一直进行IO
    while(true)
    {
        ssize_t n = read(sockfd, buf, sizeof(buf) - 1);
        if(n > 0)
        {
            buf[n] = 0;
            std::cout << addr.PrintDebug() << "# " << buf << std::endl;
            
            std::string echo_string = "server echo# ";
            echo_string += buf;
            write(sockfd, echo_string.c_str(), echo_string.size());
        }
        else if(n == 0)
        {
            lg.LogMessage(Info, "client quit... \n");
            break;
        }
        else{
            lg.LogMessage(Error, "read error : %s\n", strerror(errno));
            break;
        }
    }
}
void Transform(int sockfd, InetAddr addr)
{
    lg.LogMessage(Debug, "Transform\n");
}
void Translate(int sockfd, InetAddr addr)
{
    lg.LogMessage(Debug, "%s select %s success, fd : %d\n", addr.PrintDebug().c_str(), "translate", sockfd);
}
void DefaultService(int sockfd, InetAddr addr)
{
    lg.LogMessage(Debug, "%s select %s success, fd : %d\n", addr.PrintDebug().c_str(), "default", sockfd);
}
// ./tcp_server 8888
int main(int argc, char *argv[])
{   
    if(argc != 2)
    {
        Usage(argv[0]);//输出使用手册
        return Usage_Err;
    }
    int16_t port = std::stoi(argv[1]);
    std::unique_ptr<TcpServer> tsvr= std::make_unique<TcpServer>(port);
    tsvr->Resgister("ping", Ping);
    tsvr->Resgister("transform", Transform);
    tsvr->Resgister("translate", Translate);
    tsvr->Resgister("default", DefaultService);
    tsvr->Init();
    tsvr->Start();
    return 0;
}