#include <iostream>
#include <unistd.h>
#include <signal.h>
int main()
{
    int a = 10;
    a /= 0;
    return 0;
}