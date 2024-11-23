#include "Stack.h"
void InitStack(Stack** s) {
	*s = (Stack*)malloc(sizeof(Stack));
	(*s)->_a = (DataType*)malloc(sizeof(DataType) * DEFAULT_SIZE);
	(*s)->_capacity = DEFAULT_SIZE;
	(*s)->_top = 0;
}
void Push(Stack** s, DataType data)
{
	if ((*s)->_top == (*s)->_capacity)
	{
		DataType *new_a = (DataType*)realloc((*s)->_a, sizeof(DataType) * (*s)->_capacity * 2);
		if (new_a == NULL)
		{
			perror("realloc fail\n");
			exit(1);
		}
		(*s)->_a - new_a;
		(*s)->_capacity = (*s)->_capacity * 2;
	}
	(*s)->_a[(*s)->_top] = data;
	(*s)->_top++;
}
void Pop(Stack** s)
{
	if ((*s)->_top == 0)
	{
		perror("Pop fail\n");
	}
	--(*s)->_top;
}
DataType Top(Stack* s)
{
	if (Empty(s))
	{
		printf("Stack is empty!\n");
		return -1;
	}
	return s->_a[s->_top - 1];
}
int Size(Stack* s)
{
	return s->_top;
}
int Empty(Stack* s)
{
	return s->_top == 0;
}
void Destroy(Stack** s)
{
	if (*s == NULL || **s == NULL)
	{
		return;
	}
	free((*s)->_a);
	free(*s);
}
void Printf(Stack* s)
{
	for (int i = s->_top - 1; i >= 0; --i)
	{
		printf("%d ", s->_a[i]);
	}
	printf("\n");
}