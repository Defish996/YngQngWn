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