#include "comm.hpp"
class Init
{
public:
    Init()
    {
        bool r = MakeFifo(); // 创建管道
        if (!r)
        {
            return;
        }
        key_t key = GetKey(); // 创建key
        std::cout << "key:" << ToHEX(key) << std::endl;

        shmid = CreatShm(key); // 创建共享内存

        std::cout << "shmid: " << shmid << std::endl;
        s = (char *)shmat(shmid, nullptr, 0); // 创建关联
        if (s < 0)
        {
            std::cerr << errno << "errno:" << strerror(errno) << std::endl;
            return;
        }
        fd = open(FIFONAME, O_RDONLY);
        if (fd < 0)
        {
            return;
        }
    }
    ~Init() 
    {
        std::cout << "shm被创建了" << std::endl;
        // sleep(5);

        shmdt(s);
        std::cout << "shm被取消关联" << std::endl;
        // sleep(5);

        shmctl(shmid, IPC_RMID, nullptr);
        std::cout << "shm被从OS中删除" << std::endl;
        // sleep(5);

        close(fd);//关闭管道文件
        unlink(FIFONAME);//删除管道文件

    }

public:
    int fd;
    int shmid;
    char *s; 
};

int main()
{

    Init init;
    while (true)
    {
        int n = 1;//这个n没有实际意义,只是为了实现管道的同步机制
        ssize_t  rd = read(init.fd, &n, sizeof(n)); // 从管道读取(从fd读取到n,读取的长度最大为n的大小,防止溢出)
        if (rd > 0)
        {
            std::cout << "writed: " << init.s << std::endl;

        }
        else if (rd == 0)
        {
            break;
        }

        sleep(1);
    }

    return 0;
}