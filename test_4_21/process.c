#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
  while(1)
  {
    printf("i am a monitor,my pid: %d",getpid());
    printf("this is a monitor......\n");
    sleep(1);
  }



  return 0;
}
