#pragma once
#include <iostream>

template <class T>
class SmartPtr
{
public:
	//RAII
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}
	//c++98 auto_ptr
	//SmartPtr(SmartPtr<T>& sp)
	//	:_ptr(sp._ptr)//转移
	//{
	//	sp._ptr = nullptr;//自己置空
	//}
	~SmartPtr() {
		std::cout << "~SmartPtr()" << _ptr << std::endl;
		delete _ptr;
	}

	// 像指针一样
	//迭代器实现那里讲过了
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
	SmartPtr(const SmartPtr<T>& sp) {} = delete;
	SmartPtr<T>& operator= (const SmartPtr<T>& sp) = delete;
//private:
//	SmartPtr(const SmartPtr<T>& sp) {};
//	SmartPtr<T>& operator= (const SmartPtr<T>& sp);
private:
	T* _ptr;
};