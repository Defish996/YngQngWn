#define _CRT_SECURE_NO_WARNINGS 1
#include "Shared.hpp"
void Test_shared_ptr()
{
	OK::shared_ptr<string> sp1(new string("xxxxxxxx"));
	OK::shared_ptr<string> sp2(sp1);

	OK::shared_ptr<string> sp3(new string("yyyyyyyy"));
}

struct ListNode
{
	int val;
	OK::shared_ptr<ListNode> next;
	OK::shared_ptr<ListNode> prev;
	~ListNode()
	{
		cout << "~ListNode(){}" << endl;
	}
};
void Test_shared_ptr2()
{
	OK::shared_ptr<ListNode> n1(new ListNode);
	OK::shared_ptr<ListNode> n2(new ListNode);
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;

	n1->next = n2;
	n2->next = n1;
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;
}
template <class T>
class DelArray
{
public:
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};
void Test_shared_ptr3()
{
	//OK::shared_ptr<ListNode> sp1(new ListNode[10], DelArray<ListNode>());
	//OK::shared_ptr<ListNode> sp2(new ListNode[10], [](ListNode* p) {delete[] p; });
	//OK::shared_ptr<FILE> sp3(fopen("test.txt", "w"), [](FILE* p) {fclose(p); });
	//
	OK::shared_ptr<ListNode> sp4(new ListNode);

}

int main()
{
	//Test_shared_ptr();
	//Test_shared_ptr2();
	Test_shared_ptr3();


	return 0;
}