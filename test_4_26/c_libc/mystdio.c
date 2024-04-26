#include "mystdio.h"
#include<unistd.h>
#include<fcntl.h>
#include<strings.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#define DFL_MODE 0666


myFILE* my_fopen(const char* path,const char* mode)
{

  int fd = 0;
  int flags = 0;
  if(strcmp(mode,"r")==0)
  {
    
  }



}
