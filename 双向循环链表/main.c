#include "main.h"
ListNode* CreateList()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	if (pHead == NULL)
	{
		printf("malloc fail\n");
		exit(1);
	}
	pHead->_data = -1;
	pHead->_next = pHead;
	pHead->_prev = pHead;
	return pHead;
}

void DestroyList(ListNode* pHead)
{
	while(pHead->_next != pHead)
	{
		ListNode* pDel = pHead->_next;
		pHead->_next = pDel->_next;
		free(pDel);
	}
	free(pHead);
	printf("Destroy\n");
}
void PrintList(ListNode* pHead)
{
	if (pHead == pHead->_next)
	{
		printf("NULL\n");
		return;
	}
	ListNode* node = pHead->_next;
	while (node != pHead->_prev)
	{
		printf("%d<=>", node->_data);
		node = node->_next;
	}
	printf("%d\n", pHead->_prev->_data);
}
void PushBack(ListNode* pHead, LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;

	newnode->_next = pHead;
	pHead->_prev->_next = newnode;

	newnode->_prev = pHead->_prev;
	pHead->_prev = newnode;
	
}
void PopBack(ListNode* pHead)
{
	ListNode* pDel = pHead->_prev;
	pDel->_prev->_next = pHead;
	pHead->_prev = pDel->_prev;
	free(pDel);
}
void PushFront(ListNode* pHead, LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_next = pHead->_next;
	newnode->_prev = pHead;

	pHead->_next->_prev = newnode;
	pHead->_next = newnode;
}
void PopFront(ListNode* pHead)
{
	ListNode* pDel = pHead->_next;
	pDel->_next->_prev = pHead;
	pHead->_next = pDel->_next;
	free(pDel);
}
ListNode* FindList(ListNode* pHead, LTDataType x)
{
	int i = 0;
	ListNode* node = pHead->_next;

	while (node->_data != x && node -> _next != pHead)
	{
		node = node->_next;
		++i;
	}
	if (node -> _next != pHead)
	{
		printf("find %d is %d\n",pHead->_data, i);
		return node;
	}
	printf("not found\n");
	return NULL;
}
void InsertList(ListNode* pos, LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;

	ListNode* node = pos->_prev;
	node->_next = newnode;
	newnode-> _next = pos;

	pos->_prev = newnode;
	newnode->_prev = node;
}
void EraseList(ListNode* pos)
{
	ListNode* node = pos->_prev;
	node->_next = pos->_next;
	pos->_next->_prev = node;
	free(pos);
}