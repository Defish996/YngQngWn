#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
  printf("fd->stdin:%d\n",stdin->_fileno);
  printf("fd->stdout:%d\n",stdout->_fileno);
  printf("fd->stderr:%d\n",stderr->_fileno);
  
  FILE* fd = fopen("test.txt","w");

  printf("fd->stdin:%d\n",fd->_fileno);
  
  
  
  //umask(0);
  ////int fd = open("log.txt",O_WRONLY | O_CREAT | O_TRUNC,0666);
  //int fd = open("log.txt",O_WRONLY | O_CREAT | O_APPEND,0666);
  //if(fd < 0)
  //{
  //  perror("open");
  //  return 1;
  //}
  //
  //const char* msg = "ccccccc\n";
  ////操作文件

  //  write(fd, msg, strlen(msg));
  return 0;
}
