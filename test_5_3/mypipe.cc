#include<iostream>
#include<unistd.h>
#include<cassert>
#include<sys/types.h>
#include<sys/wait.h>
#include<cstring>
#define MAX 1024

using namespace std;
int main()
{
    //第一步,建立管道
    int pipefd[2] = {0};
    int n = pipe(pipefd);
    assert(n == 0);//debug下才存在,在release模式下这条语句会不存在,这样导致的问题是,n在后续的release中会未被使用
    (void)n;//这样会导致一些编译器的报错,所以加此语句的目的是防止这样的报错发生

    cout<<"pipe[0]:"<<pipefd[0]<<",pipe[1]"<<pipefd[1]<<endl;

    //第二步,创建子进程
    pid_t id = fork();
    if(id<0)
    {
        perror("fork");
        return 1;
    }
    
    //第三步,形成单向通信的管道,子写,父读
    //父子进程关闭不需要的fd,即可形成单行通信的管道
    //形成单行管道后,可以不用手动关闭,因为进程退出后会自动释放当前进程对应的文件描述符表
    //所以手动关闭不关闭看情况,这边是不需要手动关闭
    if(id == 0)
    {
        //child 子进程写入
        close(pipefd[0]);

        //向管道写入信息,只有写入,没有打印
        int cnt = 0;
        while(true)
        {

            // char c = 'a';
            // write(pipefd[1],&c,1);
            // cout<<"write  :" << ++cnt <<endl;
            cnt++;
            char message[MAX];
            snprintf(message,sizeof(message),"i'm child,my pid is %d , cnt %d",getpid(),cnt);
            //snprintf,向指定的对象中写入,写入多少个字节,写入什么内容...
            write(pipefd[1],message,strlen(message));
            sleep(1);
            if(cnt > 3) break;

        }
        //close(pipefd[1]);
        cout << "child close w point" << endl;
        exit(0);
    }
    //father,读取
    close(pipefd[1]);

    //用来从管道当中读取
    char buf[MAX];
    while(true)
    {
        ssize_t n = read(pipefd[0],buf,sizeof(buf)-1);//减一的目的是万一缓冲区读满了,可以留出空位置来给\0
        if(n > 0)//读取成功,切返回读取到的字符串的长度
        {
            buf[n] = 0;//当做字符串
            cout << "my pid:"<<getpid()<<",child says:" << buf << "to me!" << endl;//向屏幕打印信息
        }
        else if(n == 0)
        {
            cout << "child is quit, me too!" << endl;
            break;
        }
        sleep(1);
        cout << "father return val(n): " << n << endl;

        break;
    }

    cout<<"read is closed"<<endl;
    close(pipefd[0]);

    sleep(5);
    int status = 0;
    pid_t rid = waitpid(id,&status,0);
    if(rid==id)
    {
        cout<<"wait successful,child exit sig: "<<(status&0x7F)<<endl;//低7为该进程退出时收到的信号,次低8位退出码
    }

    return 0;
}
