#include"comm.h"
int main()
{
    int wfd = open(FIFONAME,O_WRONLY);//打开管道文件
    if(wfd < 0)
    {
        cerr << "errno:" << errno << ", errstring: " << strerror(errno) << endl;
        return 1;
    }
    //将信息写入管道
    string message;
    while(true)
    {
        cout << "Please Enter# " << endl;
        getline(cin,message);//从键盘获取message
        
        //将message写入管道
        ssize_t s = write(wfd,message.c_str(),message.size());
        if(s < 0)
        {
            cerr << "errno:" << errno << ", errstring: " << strerror(errno) << endl;
            break;
        }


    }

    close(wfd);
    return 0;
}