#pragma once
#include <cstring>
#include <cerrno>
#include <iostream>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/ipc.h>//ipc----inter process communication(进程间通信)
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFONAME ".fifo"

const char* pathname = "/home/wyq/test_5_8/shm";
const int proj_id = 0x11223344;

const size_t size = 4096;
key_t GetKey()
{
    key_t n = ftok(pathname,proj_id);
    if(n < 0)
    {
        std::cerr << errno << "errno:" << strerror(errno) << std::endl;
        exit(1);
    }
    return n;
}

std::string ToHEX(int id)
{
    char buf[1024];
    snprintf(buf, sizeof(buf), "0x%x", id);
    return buf;
}

int CreatShmHelper(key_t key, int flag)
{
    int shmid = shmget(key,size, flag);
    if(shmid < 0)
    {
        std::cerr << errno << "errno:" << strerror(errno) << std::endl;
        exit(2);
    }
    return shmid;
}

int GetShm(key_t key)
{
    return CreatShmHelper(key,IPC_CREAT/*0也可以*/);
}

int CreatShm(key_t key)
{
    return CreatShmHelper(key,IPC_CREAT|IPC_EXCL|0666);
}
bool MakeFifo()
{
    int n = mkfifo(FIFONAME, 0666);//创建管道
    if(n < 0)
    {
        std::cerr << "errno:" << errno << ", errstring: " << strerror(errno) << std::endl;
        return false;
    }
    return true;
}