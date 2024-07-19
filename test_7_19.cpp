//设计单例模式

#include <iostream>
#include <map>
#include <string>
using namespace std;
//饿汉模式
//class A
//{
//public:
//	static A* GetInsert()
//	{
//		return &_inst;
//	}
//	void Add(const string& s1, const string& s2)
//	{
//		_dict[s1] = s2;
//	}
//	void Print()
//	{
//		for (auto& e : _dict)
//		{
//			cout << e.first << ":" << e.second << endl;
//		}
//	}
//private:
//	A() {}
//	A(const A& a) = delete;
//	A& operator=(const A& a) = delete;
//	map<string, string> _dict;
//	static A _inst;//先声明
//};
//A A::_inst;//定义
//int main()
//{
//	A::GetInsert()->Add("sort", "排序");
//	A::GetInsert()->Add("right", "向右");
//	A::GetInsert()->Add("left", "向左");
//	
//	A::GetInsert()->Print();
//
//	return 0;
//}

//懒汉模式
class B
{
public:
	static B* GetInstance()
	{
		if (_inst == nullptr)
		{
			_inst = new B;
		}

		return _inst;
	}
	void Add(const string& s1, const string& s2)
	{
		_dict[s1] = s2;
	}
	void Print()
	{
		for (auto& e : _dict)
		{
			cout << e.first << ":" << e.second << endl;
		}
	}
	static void DelInstance()
	{
		if (_inst)
		{
			delete _inst;
			_inst = nullptr;
		}
	}
private:
	B() {}
	~B() {
		cout << "~B(){}" << endl;
	}
	B(const B& a) = delete;
	B& operator=(const B& a) = delete;
	map<string, string> _dict;
	static B* _inst;//先声明
	class gc
	{
	public:
		~gc()
		{
			DelInstance();
		}
	};
	static gc _gc;
};
B::gc B::_gc;
B* B::_inst = nullptr;//定义
int main()
{
	B::GetInstance()->Add("sort", "排序");
	B::GetInstance()->Add("right", "向右");
	B::GetInstance()->Add("left", "向左");
	
	B::GetInstance()->Print();

	return 0;
}


//IO设计
#include <iostream>
#include <string>
using namespace std;
class C
{
public:
	C(int x) {}
};
class D
{
public:
	D(const C& c) {}
};
class E
{
public:
	operator int()
	{
		//....
		return 0;
	}
};
int main()
{
	E e;
	int a = e;
	cout << e << endl;
	//C c = 11;
	//D d = c;
	/*string s1;
	while (cin >> s1)
	{
		cout << s1 << endl;
	}*/


	return 0;
}