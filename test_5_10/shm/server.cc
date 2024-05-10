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
        // fd = open(FIFONAME, O_RDONLY);
        // if (fd < 0)
        // {
        //     return;
        // }
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
    Init init;//创建共享内存
    struct shmid_ds ds;//创建结构体用于shmctl,这个结构体在<sys/shm.h>中封装,直接调用
    shmctl(init.shmid,IPC_STAT,&ds);//用于管理共享内存,IPC_STAT参数用于获取shm的数据到ds中
    std::cout << ToHEX(ds.shm_perm.__key) << std::endl;
    std::cout << ds.shm_atime << std::endl;
    std::cout << ds.shm_segsz << std::endl;


    sleep(5);
    return 0;
}