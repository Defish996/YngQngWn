#include <iostream>
#include <unistd.h>
#include <signal.h>
using namespace std;
volatile int flag = 0;
void handler(int signo)
{
    cout << "my signo is : " << signo << endl;
    flag = 1;
    cout << "change flag: " << flag << endl;
}
int main()
{
    signal(2,handler);
    cout << "mypid: " << getpid() << endl;

    while(!flag);



    return 0;
}