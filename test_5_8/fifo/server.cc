#include "comm.h"
bool MakeFifo()
{
    int n = mkfifo(FIFONAME, 0666);//创建管道
    if(n < 0)
    {
        cerr << "errno:" << errno << ", errstring: " << strerror(errno) << endl;
        return false;
    }
    return true;
}
int main()
{
Strat:
    int rfd = open(FIFONAME,O_RDONLY);//打开管道
    if(rfd < 0)
    {
        if(MakeFifo()) goto Strat;
        cerr << "errno:" << errno << ", errstring: " << strerror(errno) << endl;
        return 1;
    }
    char buf[1024];
    while(true)//读端
    {
        ssize_t s = read(rfd,buf,sizeof(buf)-1);
        if(s > 0)
        {
            buf[s] = 0;
            cout << "Client say# " << buf << endl;
        }
        else if(s == 0)
        {
            cout << "client quit,server quit too!" << endl;
            break;
        }
    }

    close(rfd);
    return 0;
}