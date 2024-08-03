#include "TcpServer.hpp"
#include "Comm.hpp"
#include <memory>

void Usage(std::string proc)
{
    std::cout << "Usage : \n\t" << proc <<" local_port\n" << std::endl;
}
int main(int argc, char *argv[])
{   
    if(argc != 2)
    {
        Usage(argv[0]);//输出使用手册
        return Usage_Err;
    }
    std::unique_ptr<TcpServer> tsvr= std::make_unique<TcpServer>();
    tsvr->Init();
    tsvr->Start();
    return 0;
}