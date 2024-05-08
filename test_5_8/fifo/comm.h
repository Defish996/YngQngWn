#include<iostream>
#include<unistd.h>
#include<vector>
#include<cstring>
#include<cerrno>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#define FIFONAME ".fifo"//生成的文件默认为隐藏文件
using namespace std;
