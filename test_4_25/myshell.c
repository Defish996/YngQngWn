#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<ctype.h>
#include<sys/stat.h>


#define NUM 1024
#define SIZE 64
#define SEP " "

#define NoneRedir   0
#define OutputRedir 1
#define AppendRedir 2
#define InputRedir  3

int redir = NoneRedir;
int lastcode = 0;

char* filename = NULL;
//#define Debug 1
char envval[1024];//环境变量存放
char cwd[1024];//不能存在临时空间,要让它一直有效,若因为消失,环境变量会消失,所以要去全局
const char* getUserName()
{
  const char* name = getenv("USER");
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
#ifdef Debug
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
      int fd = 0;
      if(redir==InputRedir)
      {
        fd = open(filename,O_RDONLY);
        if(fd<0)
        {
          perror("open");
          return 1;
        }
        dup2(fd,0);
      }
      else if(redir==OutputRedir)
      {
             
        fd = open(filename,O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if(fd<0)
        {
          perror("open");
          return 1;
        }
        dup2(fd,1);
      }
      else if(redir==AppendRedir)
      {

        fd = open(filename,O_WRONLY | O_CREAT | O_APPEND, 0666);
        if(fd<0)
        {
          perror("open");
          return 1;
        }
        dup2(fd,1);
      }
      else{
          //....
      }
      
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
#define SkipSpace(pos) do{while(isspace(*pos)) pos++;}while(0)
void checkRedir(char * command,int len)
{
  char* end = command + len - 1; 
  char* begin = command; 
  while(end > begin)
  {
    if(*(end) =='>')
    {
      if(*(end-1)=='>')
      {
        *(end-1)='\0';
        filename = end+1;
        SkipSpace(filename);
        redir = AppendRedir;
        break;
      }
      else{
        *(end)='\0';
        filename = end+1;
        SkipSpace(filename);
        redir = OutputRedir;
        break;
      }
    }
    else if(*(end)=='<')
    {
      *(end) = '\0';
      filename = end+1;
      SkipSpace(filename);
      redir = InputRedir;
      break;
    }
    else{
      end--;
    }
  }
}
//1->yes   0->no
int doBuildin(char *argv[])
{
    if(strcmp(argv[0], "cd")==0)
    {
      char* path = NULL;
      if(argv[1]==NULL) path =(char*) ".";
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
      char* val = argv[1]+1;//$PATH $?,现在这个val指向的是$后面的一个字符 
      if(strcmp(val,"?")==0)
      {
        printf("%d\n",lastcode);
        lastcode = 0;
        return 1;
      }
      else if(strcmp(val,"PATH")==0)
      {
        printf("%s\n",getenv(val));
        return 1;
      }
      else if(strcmp(val,"$")==0)
      {
        printf("%d\n",getpid());
        return 1;
      }
      else{

        printf("%s\n",argv[1]);
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
    filename = NULL;
    redir = 0;
    char usercommand[NUM];
    char *argv[SIZE];
    //int argc = 0;
    //1.印提示符&&获取用户命令字符串
    int n = getUserCommand(usercommand,sizeof(usercommand));
    if(n<=0) continue;
    //1.1检查重定向
    
     checkRedir(usercommand,strlen(usercommand));
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
//命令将从名为"input.txt"的文件中读取输入数据，而不是从键盘读取。
