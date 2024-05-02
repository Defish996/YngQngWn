#include<iostream>
#include<unistd.h>
#include<cassert>

using namespace std;
int main()
{

    int pipefd[2] = {0};
    int n = pipe(pipefd);
    assert(n == 0);//debug下才存在,在release模式下这条语句会不存在,这样导致的问题是,n在后续的release中会未被使用
    (void*)n;//这样会导致一些编译器的报错,所以加此语句的目的是防止这样的报错发生

    return 0;
}