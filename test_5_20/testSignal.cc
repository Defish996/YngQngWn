#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
void handler(int signo)
{
    cout << "i am returnning... " << endl;
    pid_t id;
    while(id = waitpid(-1,nullptr,WNOHANG))
    {
        if(id<=0) break;
        cout << "进程回收" << id << endl;
    }

}
int main()
{
    signal(SIGCHLD,SIG_IGN);
    for(int i = 0; i< 10; i++)
    {
        pid_t id = fork();
        if(id==0)
        {
            cout << "i am a child, my pid is: " << getpid() << endl;
            sleep(5);
            exit(1);
        }
    }

    sleep(10);

    return 0;
}