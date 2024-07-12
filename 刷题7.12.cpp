//leetcode 2974. 最小数字游戏 今日lc水题


class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i += 2)
        {
            swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};

#include <iostream>
class A
{
public:
	A(int a)
		:_a(a)
	{}
	A(const A& a)
	{

	}
	A(A&& a)
	{

	}
	~A()
	{
		std::cout << "~A()" << std::endl;
	}
private:
	int _a;
};
////这个...Args可以包含任意个模板参数
//template<class ...Args>
//void test(Args... args)
//{
//	//计算参数个数
//	std::cout << sizeof...(args) << std::endl;
//}

void _test()
{
	std::cout << std::endl;
}
template<class T, class ...Args>
void _test(const T &val, Args... args)
{
	std::cout << val << " ";
	_test(args...);
}
template<class ...Args>
void test(Args... args)
{
	_test(args...);
}
int main()
{
	test(1);
	test(1, 2);
	test(1, 2, 3);
	test(1, 'x', "dadsa");
	int i = 10;
	int j = 20;
	A a(std::move(i + j));



	return 0;
}