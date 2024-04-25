#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define FILENAME "log.txt"
#define MAXSIZE 1024
int main()
{
 
 
  int fd = open(FILENAME,O_RDONLY,0666);
  if(fd<0)
  {
    perror("open");
    return 1;
  }
  dup2(fd, 0);
  char buffer[1024];
  fread(buffer,1,sizeof(buffer),stdin);
  printf("%s\n",buffer);
  
  close(fd); 
  
  
  
  
  
  //int fd = open(FILENAME, O_WRONLY | O_CREAT | O_APPEND, 0666);
 //if(fd<0)
 //{
 // perror("open");
 // return 1;
 //}
 //dup2(fd,1); //1和fd的文件描述符都指向fd所代表的文件
 //printf("hello world\n");
 //fprintf(stdout,"hello world\n");
 //close(fd);
  
  
  
  
  // char buf[1024];
 // 
 // ssize_t s = read(0,buf,1024);
 // if(s>0)
 // {
 //   buf[s]=0;//读取后进行截断\0
 //   //printf("echo# %s",buf);
 //   write(1,buf,strlen(buf));
 // }
 // 
  //close(0); 
  //close(1);
  //int fd = open(FILENAME,O_CREAT | O_WRONLY | O_TRUNC,0666);
  //if(fd<0)
  //{
  //  perror("open");
  //  return 1;
  //}
  //fprintf(stdout,"fd: %d\n",fd);
  //fprintf(stdout,"stdout->fd: %d\n", stdout->_fileno);
  //fflush(stdout);
  //
  //
  //close(fd);

  //
  //
  
  return 0;
}
