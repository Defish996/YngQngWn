// 蓝桥杯 1.奇怪的捐赠
#include <iostream>
using namespace std;
int main()
{
    // 题意要求最多, 为什么这样的方式就能得到最多呢?
    // 举个例子
    int n = 1000000, ans = 0;
    while(n)
    {
        ans += n % 7;
        n /= 7;
    }
    cout << ans;


    return 0;
}
