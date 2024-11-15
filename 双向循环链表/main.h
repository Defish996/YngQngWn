#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int LTDataType;
typedef struct ListNode {
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

ListNode* CreateList();
void DestroyList(ListNode* pHead);
void PrintList(ListNode* pHead);
void PushBack(ListNode* pHead, LTDataType x);
void PopBack(ListNode* pHead);
void PushFront(ListNode* pHead, LTDataType x);
void PopFront(ListNode* pHead);
ListNode* FindList(ListNode* pHead, LTDataType x);
void InsertList(ListNode* pos, LTDataType x);
void EraseList(ListNode* pos);
