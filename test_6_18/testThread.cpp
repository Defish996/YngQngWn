#include <iostream>
#include <thread>
#include <unistd.h>
void myrun()
{
    std::cout << "i am a new thread" << std::endl;
    sleep(2);
}
using namespace std;
int main()
{
    thread t(myrun);

    t.join();
    return 0;
    
}