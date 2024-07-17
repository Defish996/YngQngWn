#include <iostream>
#include <vector>
#include <string>
#include <string>
#include <functional>
using namespace std;
namespace OK
{
	template <class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)//构造函数
			:_ptr(ptr)
			, _pcount(new int(1))
		{}
		template <class D> 
		shared_ptr(T* ptr, D del)//构造函数
			:_ptr(ptr)
			,_pcount(new int(1))
			,_del(del)
		{}
		shared_ptr(const shared_ptr<T>& sp)//拷贝构造内对计数器+1
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			++(*_pcount);
		}
		shared_ptr<T>& operator= (const shared_ptr<T>& sp)//重载=就是将sp赋值给this
		{
			if (_ptr != sp._ptr)
			{
				if (--(*_pcount) == 0)//
				{
					delete _pcount;
					/*delete _ptr;*/
					_del(_ptr);
				}
				_pcount = sp._pcount;
				_ptr = sp._ptr;

				++(*_pcount);

			}
			return *this;
		}
		// 像指针一样
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
		~shared_ptr()
		{
			if (--(*_pcount) == 0)//当这个计数器为0时进行析构
			{
				//cout << "delete->" << _ptr << endl;
				//delete _ptr;
				
				_del(_ptr);
				delete _pcount;
			}
		}
		int use_count()
		{
			return *_pcount;
		}
		T* get() const
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pcount;

		function<void(T*)> _del;// = [](T* p) {delete p; };
	};

	template <class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}
		weak_ptr(const shared_ptr<T>& sp) 
			:_ptr(sp.get())
		{

		}
		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();
			return* this;
		}
		// 像指针一样
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
		T* get() const
		{
			return _ptr;
		}
		~weak_ptr() {}
	private:
		T* _ptr;
	};

}