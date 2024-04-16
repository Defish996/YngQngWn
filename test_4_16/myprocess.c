#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>


//2.1代码创建子进程， 父进程调用wait/waitpid函数进行等待， 子进程打印“i am child process”之后，等待5s钟结束子进程；
//2.2 父进程在等待到子进程之后， 分析子进程的退出信号， coredump标志位以及退出码， 并打印到标准输出
int main()
{
	pid_t id = fork();
	if(id==0)
	{
    printf("I am child process\n");
    sleep(5);
    exit(6);
  }
  else
  {

    int status = 0;
    pid_t rid = waitpid(-1,&status,0);

    if(id==rid)//表明wait返回的id是子进程的id,父进程得到的id为子进程的id
    {
      if(WIFEXITED(status))//WIFEXITED(status)表示正常退出时为true,异常退出为false
      {
        printf("exit successful correctly,exit num=%d\n",WIFEXITED(status));
      }
      else if(WIFSIGNALED(status))//因为收到某种信号终止
      {
        printf("exitting by signed,exit num=%d\n",WIFSIGNALED(status));
      }
      else if(WIFSTOPPED(status))//进程收到某种信号暂停
      {
        printf("process have a temporary file named coredump,exit num=%d\n",WIFSTOPPED(status));
      }
      else
      {
        printf("exit other stations\n");
      }
    }
  }
	return 0;
}
