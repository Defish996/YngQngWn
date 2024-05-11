#include "comm.hpp"
int main()
{
    key_t key = GetKey();
    int shmid = GetShm(key);//获取共享内存,而不是创建

    char* s = (char*)shmat(shmid,nullptr,0);//创建关联
    //客户端的创建必须是成功的,所以只需提醒创建成功即可
    std::cout << "shmat success!" << std::endl;

    int fd = open(FIFONAME,O_WRONLY);//打开server创建的管道
    if(fd < 0)
    {
        return 1;
    }
    char c = 'a';
    //char n[1024];
    for(;c <= 'z';c++)
    {
        s[c-'a'] = c;
        std::cout << "write: " << s << std::endl;
        sleep(1);

        //通知对方
        int code =1;
        write(fd,&code,sizeof(code));//向管道内写入(实际并不是写入而是基于管道实现同步机制,这边也没有实际写入内容到code,但这个code没有实际意义,只是为了利用管道实现同步机制)

    }

    shmdt(s);//取消关联
    //对于客户机只需关联和取消关联即可,剩余的工作让server来处理
    close(fd);
    return 0;
}