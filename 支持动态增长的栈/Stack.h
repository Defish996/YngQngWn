#pragma once
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 5

typedef int DataType;
typedef struct Stack
{
	DataType* _a;
	int _top;
	int _capacity;
}Stack;

void InitStack(Stack** s);
void Push(Stack** s, DataType data);
void Pop(Stack** s);
DataType Top(Stack* s);
int Size(Stack* s);
int Empty(Stack* s);
void Destroy(Stack** s);
void Printf(Stack* s);