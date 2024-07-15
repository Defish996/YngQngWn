#include <iostream>
using namespace std;
class A
{
public:
	A() {
		cout << "A()" << endl;
	}
	~A() {
		cout << "~A()" << endl;
	}
};
template<class T>
class SmartPtr
{
public:
	//RAII
	SmartPtr(T *ptr) 
		:_ptr(ptr)
	{}
	~SmartPtr() {
		delete[] _ptr;
		cout << "delete[]" << endl;
	}
private:
	T* _ptr;
};
double func(int a, int b)
{
	if (b == 0)
	{
		throw "除0错误";
	}
	else
	{
		return (double)a / (double)b;
	}
}
void turn()
{	
	A x;
	int* p = new int[10];
	SmartPtr<int> s(p);
	int a  = 0, b = 0;
    cin >> a >> b;
	cout << func(a, b) << endl;
	/*delete[] p;
	cout << "delete[]" << endl;*/
	//异常之后的这条语句不会执行
	//但是类对象的析构会执行, 再抛出异常信息
}
int main()
{
	try
	{
		turn();
	}
	catch(const char *str)
	{
		cout << str << endl;
	}
	catch (...)
	{
		cout << "未知异常" << endl;
	}

	return 0;
}