#include <iostream>
//设计一个类, 只能在堆上创建对象
using namespace std;
//class HeapOnly
//{
//public:
//	//void Destroy()
//	//{
//	//	delete this;
//	//}
//public:
//	static void Destroy(HeapOnly* ho)
//	{
//		delete ho;
//	}
//private:
//	//方案一:析构函数私有化
//	~HeapOnly() {
//		cout << "~HeapOnly()" << endl;
//	}
//};
//class B
//{
//	int x;
//};
//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObj()
//	{
//		return new HeapOnly;
//	}
//	HeapOnly(const HeapOnly& ho) = delete;
//private:
//	HeapOnly() {
//		cout << "HeapOnly()" << endl;
//	}
//};

class StackOnly
{
public:
	static StackOnly CreateObj()
	{
		StackOnly so;
		return so;
	}
	void* operator new(size_t size) = delete;
private:
	StackOnly() {
		cout << "StackOnly()" << endl;
	}
};
class A final
{
public:

private:
};

int main()
{

	volatile const int a = 10;
	//int* n = const_cast<int*>(&a);
	int* n = (int*)&a;
	*n = 20;
	cout << *n << endl;
	cout << a << endl;
	
	cout << n << endl;
	cout << &a << endl;

	/*double d= 20;
	int i = static_cast<int>(d); */


	////隐式转换
	//int i = 20;
	//double d = i;

	////显式转换
	//int  x = 10;
	//int *p = &x;
	//int address = (int)p;

	//StackOnly so = StackOnly::CreateObj();
	//int m = (int)so;
	////StackOnly* so1 = new StackOnly(so);


	//HeapOnly ho;
	//static HeapOnly ho2;
	////HeapOnly ho1;
	////static HeapOnly ho2;
	//HeapOnly* ho3 = new HeapOnly;
	//HeapOnly::Destroy(ho3);
	////ho3->Destroy();




	return 0;
}