//leetcode 21. 合并两个有序链表 递归法

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //递归解决问题
        if(!l1||!l2)
        {
            return l1 == nullptr ? l2 : l1;
        }
        if(l1->val > l2->val)
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        else
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        return nullptr;
    }
};

//实现线程atomic的内部原理&&shared_ptr的线程安全问题

#include <iostream>
#include <thread>
#include <atomic>
#include "shared_ptr.hpp"
using namespace std;
void test1()
{
	size_t n1 = 100000;
	size_t n2 = 100000;
	atomic<size_t> x = 0;
	thread t1([&]() {
		for (size_t i = 0; i < n1; i++)
		{
			size_t old, newval;
			do {
				old = x;
				newval = old + 1;
			} while (!atomic_compare_exchange_weak(&x, &old, newval));
		}
		});
	thread t2([&]() {
		for (size_t i = 0; i < n2; i++)
		{
			size_t old, newval;
			do {
				old = x;
				newval = old + 1;
			} while (!atomic_compare_exchange_weak(&x, &old, newval));
		}
		});

	t1.join();
	t2.join();
	cout << x << endl;
}
void test2()
{
	size_t n1 = 100000;
	size_t n2 = 100000;
	OK::shared_ptr<double> sp(new double(1.1));
	thread t1([&]() {
		for (size_t i = 0; i < n1; i++)
		{
			OK::shared_ptr<double> copy(sp);
		}
		});
	thread t2([&]() {
		for (size_t i = 0; i < n2; i++)
		{
			OK::shared_ptr<double> copy(sp);
		}
		});

	t1.join();
	t2.join();

	cout << sp.use_count() << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}