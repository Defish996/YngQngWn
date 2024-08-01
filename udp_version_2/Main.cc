#include "UdpServer.hpp"
#include "Comm.hpp"
#include <memory>
#include <vector>

using cb_t = std::function<std::string(std::string)>;//定义函数类型 <返回值(参数)>

std::string OnMessageDefault(std::string request)
{
    return request + "[haha, got you]";
}
//手册
void Usage(std::string proc)
{
    std::cout << "Usage : \n\t" << proc <<" local_port\n" << std::endl;
}

std::vector<std::string> black_words = {
    "rm",
    "unlink",
    "cp",
    "chmod",
    "exit",
    "shutdown",
    "halt",
    "reboot",
    "mv",
    "top",
    "kill",
    "dd",
    "vim",
    "vi",
    "nano",
    "man",
    "mkfs",
    "fdisk",
    "killall",
    "chgrp"
};
bool SelfCheck(std::string command)
{
    for(auto &word : black_words)
    {
        if(command.find(word) != std::string::npos)//!=npos表明找到了, 直接返回false
        {
            return false;
        }
    }
    return true;
}
std::string ExecuteCommand(std::string command)
{
    if(!SelfCheck(command)) return "bad man!";//检查命令安全性
    std::cout << "get a command : " << command << std::endl;
    std::string result;
    FILE *fp = popen(command.c_str(), "r");//执行命令
    if(fp == nullptr)
    {
        return result;
    }
    char buf[1024] = {0};
    while(fgets(buf, sizeof(buf), fp) != nullptr)//读取命令的输出
    {
        result += buf;
    }
    pclose(fp);
    return result;
}
// ./udp_server 127.0.0.1 8888
// ./udp_server 8888
int main(int argc, char *argv[])
{   
    if(argc != 2)
    {
        Usage(argv[0]);//输出使用手册
        return Usage_Err;
    }

    uint16_t port = std::stoi(argv[1]); //创建端口号

    std::unique_ptr<UdpServer> usvr = std::make_unique<UdpServer>(OnMessageDefault, port);//创建服务器

    usvr->Init();
    usvr->Start();//服务器启动

    return 0;
}