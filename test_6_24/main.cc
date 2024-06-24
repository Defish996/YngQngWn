#include "Thread.hpp"
#include <unistd.h>

int numsize = 10000;
string GetThreadName()
{
    static int num = 1;
    return static_cast<string>("Thread-"+to_string(num++));
}
void Print(string name)
{
    while(true)
    {
        if(numsize > 0)
        {
            usleep(1000);
            std::cout << name << ", the numsize is: "<< numsize << std::endl;
            --numsize;
        }
        else{
            break;
        }

    }
}
int main()
{
    string name1 = GetThreadName();
    Thread<string> t1(name1, Print, name1);

    string name2 = GetThreadName();
    Thread<string> t2(name2, Print, name2);  

    string name3 = GetThreadName();
    Thread<string> t3(name3, Print, name3);   

    string name4 = GetThreadName();
    Thread<string> t4(name4, Print, name4);   
 
    
    string name5 = GetThreadName();
    Thread<string> t5(name5, Print, name5);

    t1.Start();
    t2.Start();
    t3.Start();
    t4.Start();
    t5.Start();

    t1.Join();
    t2.Join();
    t3.Join();
    t4.Join();
    t5.Join();






    return 0;
}