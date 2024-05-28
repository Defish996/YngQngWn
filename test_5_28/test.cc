#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        cout << "i am a child, my pid is: " << getpid() << endl;
        exit(1);
    }   
    //father
    cout << "wait before, my id is: " << id << endl;
    cout << "i am father, my id is: " << id << " , my pid is: " << getpid() << endl;
    pid_t rid = wait(nullptr);
    if(rid == id)
    {
        cout << "rid is: " << rid << endl;
    }







    return 0;
}