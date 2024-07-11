#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <array>
const int defaultval = 5;

void test1()
{

	class A
	{
	public:
		A(int a = defaultval):_a(a)
		{}


	private:
		int _a;
	};

}
void test2()
{
	//std::pair<std::string, std::string> p = { "insert", "插入" };
	//std::map<std::string, std::string> m = { p, {"sort", "排序"}, {"get", "获取"} };

}
void test3()
{
	int i = 3;
	double d = 4.4;
	//类型以字符串的方式获取打印
	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
}
void test4()
{
	int i = 0;
	auto j = i*1.1;
	decltype(i) x = 4;
	std::vector<decltype(j)> vec;
	vec.push_back(1);
	vec.push_back(1.2);
	for (auto &e : vec)
	{
		std::cout << e << ' ';
	}

}
void test5()
{
	std::array<int, 10> a1;
	//a1[10];
	std::vector<int> a2(10, 0);
}
void test6()
{
	//左值定义
	int j = 0, i = 0;

	//右值
	const int &x = 10;
	j + i;
	test2();
}
void test7() 
{
	int i = 10;
	int&& a = std::move(i);//允许
}
namespace my
{
	class string {
	public:
		to_string(int a);
	};
	my::string to_string(int a)
	{}
}
void test8()
{
	my::string s = my::to_string(10)

}
int main()
{
	//test1();
	//test2();

	//test3();
	//test4();
	return 0;
}