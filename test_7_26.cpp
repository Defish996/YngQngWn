//原子操作

#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>
using namespace std;
int main()
{
	size_t n1 = 1000000;
	size_t n2 = 1000000;
	mutex mtx;
	atomic <size_t> x = 0;
	//size_t x = 0;
	thread t1([n1, &x, &mtx]() {
		for (size_t i = 0; i < n1; i++)
		{
			++x;
		}
		});
	thread t2([n2, &x, &mtx]() {
		for (size_t i = 0; i < n2; i++)
		{
			++x;
		}
		});


	t1.join();
	t2.join();
	std::cout << x;
	//printf("%d\n", x);
	printf("%d\n", x.load());

	return 0;
}