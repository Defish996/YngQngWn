// 3192. 使二进制数组全部等于 1 的最少操作次数 II 模拟位运算

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int func(vector<int>& vec)
{
	int ans = 0;
	int n = vec.size();
	for (int i = 0; i < n - 2; ++i)
	{
		if (vec[i] == 0)
		{
			vec[i] ^= 1;
			vec[i + 1] ^= 1;
			vec[i + 2] ^= 1;
			++ans;
		}
	}
	if (vec[n - 1] == 0 || vec[n - 2] == 0)
	{
		return -1;
	}
	return ans;
}
int main()
{
	vector<int> vec = { 0,1,1,1 }; // 1 0 0 0 0...1 1 1 1 0
	cout << func(vec);

	return 0;
}

// 3192. 使二进制数组全部等于 1 的最少操作次数 II 利用奇偶性替换位运算

class Solution {
public:
    int minOperations(vector<int>& vec) {
	int ans = 0;
	for (auto& x : vec)
	{
		// if (x == 0 && 0 == ans % 2) // ans % 2 , 若ans为偶数, 则取模之后为0, 否则为1, 偶数次则不进行操作
		// 简化之后就是 值为0, 且为偶数次操作时(偶数等于没操作, 当成是第一次操作)
		// 这是第一种, 另一种是:
		// 当x为1时, 且ans % 2为1(奇数)时, 此时为需要变化的情况, 说明是奇次的变化使得原先的1变成了0, 所以需要进行变化
		// if(x == 1 && 1 == ans & 2)
		if(x == ans % 2)
		{
			++ans;
		}
	}
	return ans;
    }
};