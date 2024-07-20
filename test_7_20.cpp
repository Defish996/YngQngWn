#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
template <class Lock> //设计成模板可以适应多种锁机制:如时间锁 递归锁等
class LockGuard
{
public:
	LockGuard(Lock& mtx) //需要接收来自外部的锁, 所以这边是引用
	:_mtx(mtx)
	{
		_mtx.lock();

	}
	~LockGuard() {
		_mtx.unlock();

	}
private:
	Lock& _mtx;//需要接收来自外部的锁, 所以这边是引用
};
//void Print(size_t j, size_t n, mutex &mtx)
//{
//	for (size_t i = j; i < n; i++)
//	{
//		lock_guard<mutex> a(mtx);
//		cout << this_thread::get_id()<< ":" << i << endl;
//	}
//}
int main()
{
	mutex mtx;
	condition_variable cv;
	bool flag = false;
	thread t1([&]() {

		for (int i = 1; i < 20; i+=2)
		{
			unique_lock<mutex> ug(mtx);
			if (flag)
				cv.wait(ug);
			cout << "thread-1:" << i << endl;
			flag = true;
			cv.notify_one();}
		});
	thread t2([&]() {

		for (int i = 2; i <= 20; i+=2)
		{
			unique_lock<mutex> ug(mtx);
			if (!flag)
				cv.wait(ug);
			cout << "thread-2:" << i << endl;
			flag = false;
			cv.notify_one();}
		});

	t1.join();
	t2.join();

	//mutex mtx;
	//thread t1(Print, 10, 200, ref(mtx));
	//thread t2(Print, 10, 200, ref(mtx));

	//t1.join();
	//t2.join();

	//mutex mtx;
	//size_t n1 = 0;
	//size_t n2 = 0;
	//cin >> n1;
	//cin >> n2;
	//size_t x = 0;
	//thread t1([n1, &x, &mtx]() {
	//	for (size_t i = 0; i < n1; i++)
	//	{
	//		mtx.lock();
	//		x++;
	//		mtx.unlock();
	//		//cout << this_thread::get_id() << ":" << i << endl;
	//	}
	//	});
	//thread t2([n2, &x, &mtx]() {
	//	for (size_t i = 0; i < n2; i++)
	//	{
	//		mtx.lock();
	//		x++;
	//		mtx.unlock();
	//		//cout << this_thread::get_id() << ":" << i << endl;
	//	}
	//	});
	//t1.join();
	//t2.join();
	//cout << x;
	//size_t n;
	//cin >> n;
	////线程声明
	//vector<thread> threads(n);


	//for (auto& thd : threads)
	//{
	//	//移动赋值 thread(Print, 10)是匿名对象, 属于将亡值
	//	thd = thread(Print, 10, 2);
	//}

	//for (auto& thd : threads)
	//{
	//	thd.join();
	//}

	//thread t1(Print, 10, 5);
	//thread t2(move(t1));

	//t2.join();





	//thread t1(Print, 1000, 500);
	//thread t2(Print, 1000, 600);

	//thread t3(t2);

	//t1.join();
	//t2.join();



	return 0;
	
}