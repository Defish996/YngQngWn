#include <stdio.h>
#include <unistd.h>
int main()
{

  while(1)
  {
    printf("i am a process, my pid : %d\n",getpid());
    sleep(1);
  }

  return 0;
}
