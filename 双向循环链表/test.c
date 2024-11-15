#include "main.h"
int main()
{
	ListNode* phead = CreateList();
	PrintList(phead);
	PushBack(phead, 1);
	PrintList(phead);
	PushBack(phead, 3);
	PushBack(phead, 4);
	PrintList(phead);
	InsertList(phead->_next->_next, 2);
	PrintList(phead);
	EraseList(phead->_next->_next);
	PrintList(phead);
	PopBack(phead);
	PrintList(phead);
	PushBack(phead, 6);
	PrintList(phead);
	PopFront(phead);
	PrintList(phead);
	PushBack(phead, 1);
	PushBack(phead, 9);
	PrintList(phead);
	PushFront(phead, 7);
	PrintList(phead);
	DestroyList(phead);


}