//leetcode 爬楼梯
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);//题目要求楼顶在数组+1位置处,所以比数组位置+1
        //根据vector的特性, 这一步可以不用写
        //dp[0] = dp[1] = 0;
        for(int i = 2; i <= n; i++)//一直到达楼顶,才结束判断
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};

//c++11新语法 仿函数定义 lambda表达式 function包装器
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <string>

using namespace std;

class A
{
public:
	A(int a) :a(a) {}
public:
	int a;
};
//int main()
//{
//	vector<A> vec = { 5,1,6,4,2,3,8 };
//	sort(vec.begin(), vec.end(), [](const A& a, const A& b) {return a.a < b.a;});
//	for (auto x : vec)
//	{
//		cout << x.a  << " ";
//	}
//
//
//	return 0;
//}

//int main()
//{
//	auto fc = [](int x)->int {cout << x << endl; return 0; };
//	fc(1);
//
//	auto fc2 = [](int x)
//		{
//			cout << x << endl; return 0; 
//		};
//	fc2(2);
//	cout << typeid(fc).name() << endl;
//	cout << typeid(fc2).name() << endl;
//
//	int x = 10, y = 20;
//	auto f = [&x, &y]() {
//		int tmp = x;
//		x = y;
//		y = tmp;
//		};
//	f();
//	cout << x << " " << y << endl;
//	return 0;
//}

void swap_func(int& x, int& y)//函数
{
	int tmp = x;
	x = y;
	y = tmp;
}
class Swap//仿函数
{
public:
	void operator()(int& x, int& y)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
};
auto f = [](int& x, int& y)//lambda表达式
	{
		int tmp = x;
		x = y;
		y = tmp;
	};
int main()
{
	int x = 10, y = 20;
	//这两种方式的定义结果一样
	//function<void(int&, int&)> f1(swap_func);
	function<void(int&, int&)> f1 = swap_func;
	f1(x, y);

	function<void(int&, int&)> f2 = Swap();
	f2(x, y);

	function<void(int&, int&)> f3 = f;
	f3(x, y);

	map<string, function<void(int&, int&)>> cmdOP =
	{
		{"函数指针", swap_func},
		{"仿函数", Swap()},
		{"lambda",f}
	};
	cmdOP["函数指针"](x, y);

	cmdOP["仿函数"](x, y);
	
	cmdOP["lambda"](x, y);
	return 0;
}