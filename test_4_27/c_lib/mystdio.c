#include "mystdio.h"
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

#define DFL_MODE 0666


int my_fwrite(const char* s,int num, myFILE* fp)
{

  memcpy(fp->buffer+fp->end,s,num);
  fp->end+=num;

  if((fp->flag & FLUSH_LINE)&&fp->end>0&&fp->buffer[strlen(fp->buffer)-1] =='\n')
  {
    my_fflush(fp);
  }
  return num;
}

myFILE* my_fopen(const char* path,const char* mode)
{

  int fd = 0;
  int flags = 0;
  if(strcmp(mode,"r")==0)
  {
   flags |= O_RDONLY;   
  }
  else if(strcmp(mode,"w")==0)
  {
    flags |= O_CREAT | O_TRUNC | O_WRONLY;
    
  }
  else if(strcmp(mode,"a")==0)
  {
    flags |= O_CREAT | O_APPEND | O_WRONLY;
  }
  else{
    //other thing...
  }
  if(flags&O_CREAT)
  {
    fd = open(path,flags,DFL_MODE);
  }
  else{
    fd = open(path,flags);
  }
  if(fd<0)
  {
    errno = 2;
    return NULL;

  }
  myFILE* fp = (myFILE*)malloc(sizeof(myFILE));
  if(!fp)
  {
    errno = 3;
    return NULL;
  }
  fp->end = 0;
  fp->flag = FLUSH_LINE;
  
  
  fp->_fileno = fd;

  return fp;
}

int my_fflush(myFILE* fp)
{
  if(fp->end>0)
  {
    write(fp->_fileno,fp->buffer,fp->end);
    fp->end = 0;
  }
  return 0;
}

int my_fclose(myFILE* fp)
{
  my_fflush(fp);
  return close(fp->_fileno);
}
