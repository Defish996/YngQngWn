#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
//  int a = 0;
//  a++;
//  printf("my pid:%d  ,start another process:\n",getpid());
//  execl("./process","process",NULL);
//  printf("a = %d\n",a);
  execl("/usr/bin/ls","-l","-a",NULL);


  return 0;
}
