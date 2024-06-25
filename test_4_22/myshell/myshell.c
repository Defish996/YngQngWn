#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#define NUM 1024
#define SIZE 64
#define SEP " "
int lastcode = 0;

//#define Debug 1
char envval[1024];//环境变量存放
char cwd[1024];//不能存在临时空间,要让它一直有效,若因为消失,环境变量会消失,所以要去全局
const char* getUserName()
{
  const char* name = getenv("USER");//从环境变量中找到k为USER的val
  if(name) return name;
  else return "none";
}
const char* getHostName()
{
  const char* hostname = getenv("HOSTNAME");
  if(hostname) return hostname;
  else return "none";
}

const char* getCwd()
{
  const char* cwd = getenv("PWD");
  if(cwd) return cwd;
  else return "none";
}
int getUserCommand(char* command,int num)
{
  
  printf("[%s@%s %s]# ",getUserName(),getHostName(),getCwd());

  char* r = fgets(command,num,stdin);
  if(r==NULL) return -1;
 
  command[strlen(command)-1] = '\0';
  return strlen(command);
}
void commandSplit(char* in, char* out[])
{
  int argc = 0;
  out[argc++] = strtok(in,SEP);
  while(out[argc++] = strtok(NULL,SEP));
#ifdef Debug//debug版本,release下不存在这个
  for(int i = 0;out[i];i++)
  {
    printf("%d:%s\n",argc,out[i]);
  }
#endif 
}
int execute(char*argv[])
{
  
    pid_t id = fork();
    if(id<0)return -1;
    else if(id==0)
    {
      execvp(argv[0],argv);
      exit(1);
    }
    else{
      int status = 0;
      pid_t rid = waitpid(id,&status,0);
      if(rid > 0)
      {
        lastcode = WEXITSTATUS(status);
      }
      else{
        //printf("wait fail\n");
      }
    }
    return 0;
}
void cd(const char* path)
{
  //char cwd[1024];//不能存在临时空间,要让它一直有效,若因为消失,环境变量会消失
  //               //将这个换成全局
  //sprintf(cwd,"PWD=%s",path);//将2位置的内容写进1位置
  //putenv(cwd);
  //chdir(path);
  chdir(path);
  char tmp[1024];
  getcwd(tmp,sizeof(tmp));
  sprintf(cwd,"PWD=%s",tmp);//将2位置的内容写进1位置
  putenv(cwd);
}
//1->yes   0->no
int doBuildin(char *argv[])
{
    if(strcmp(argv[0], "cd")==0)
    {
      char* path = NULL;
      if(argv[1]==NULL) path = ".";
      else path=argv[1];
      cd(path);
      return 1;
    }
    else if(strcmp(argv[0],"export")==0)
    {
      //putenv(argv[1]);
      strcpy(envval,argv[1]);
      putenv(envval);
      return 1;
    }
    else if(strcmp(argv[0],"echo")==0)
    {
      char* val = argv[1]+1;//$PATH $? 
      if(strcmp(val,"?")==0)
      {
        printf("%d\n",lastcode);
        lastcode = 0;
        return 1;
      }
      else{
        printf("%s\n",getenv(val));
        return 1;
      }
    }
    else if(0){}
    return 0;
}
int main()
{
  while(1)
  {

    char usercommand[NUM];
    char *argv[SIZE];
    //int argc = 0;
    //1.印提示符&&获取用户命令字符串
    int n = getUserCommand(usercommand,sizeof(usercommand));
    if(n<=0) continue;
    //2.分割字符串
    commandSplit(usercommand,argv);
    //printf("%s\n",usercommand);
    //3.check build-in command 
    n = doBuildin(argv);
    if(n)//若为内建指令,则内部自己执行,执行完毕后,重新从步骤1开始走程序
    {
      continue;
    }
    //4.执行指令
    execute(argv);
  }
  //scanf("%s",usercommand);
  return 0;
}
