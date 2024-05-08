#pragma once
#include <cstring>
#include <cerrno>
#include <iostream>
#include <sys/types.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/ipc.h>//ipc----inter process communication(进程间通信)
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