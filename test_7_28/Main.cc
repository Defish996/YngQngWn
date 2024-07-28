#include "UdpServer.hpp"
#include "Comm.hpp"
#include <memory>

//手册
void Usage(std::string proc)
{
    std::cout << "Usage : \n\t" << proc <<" local_ip local_port\n" << std::endl;
}
// ./udp_server 127.0.0.1 8888
int main(int argc, char *argv[])
{   
    if(argc != 3)
    {
        Usage(argv[0]);//输出使用手册
        return Usage_Err;
    }

    std::string ip = argv[1];
    uint16_t port = std::stoi(argv[2]);

    //使用std::make_unique函数初始化它
    std::unique_ptr<UdpServer> usvr = std::make_unique<UdpServer>(ip, port);
    usvr->Init();
    usvr->Start();

    return 0;
}