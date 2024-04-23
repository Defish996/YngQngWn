#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

extern char** environ;
char* const myenv[] = {
  "MYVAL1=111111111111111111",
  "MYVAL2=222222222222222222",
  "MYVAL3=333333333333333333",
  NULL
};
int main()
{

  pid_t id = fork();
  if(id==0)
  {
    printf("pid:%d, exec command start\n",getpid());
    
    
   // execle("./mytest","mytest","-b","-a",NULL,myenv);
    execle("./mytest","mytest","-b","-a",NULL,environ);

    printf("pid: %d ,exec command end\n",getpid());

  }
  else{
    pid_t rid = wait(NULL);
    if(rid==id)
    {
      printf("wait successful\n");
    }
    return 0;
  }
  
  // const  char* env_val = "MYVAL2=111111111111111111111111";
//  putenv(env_val);
// pid_t id = fork();
// if(id==0)
// {
//   printf("pid: %d exec command start\n",getpid());
//   execl("./mytest","mytest",NULL);
// }
// else{
//   pid_t rid= waitpid(-1,NULL,0);
//   if(rid > 0)
//   {
//     printf("wait success,rid : %d\n", rid);
//   }
// }
//

  return 0;
}
