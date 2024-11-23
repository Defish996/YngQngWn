#include "Stack.h"
int main()
{
	Stack* s = NULL;
	InitStack(&s);
	Push(&s, 1);
	Push(&s, 2);
	Push(&s, 3);
	Push(&s, 4);
	Push(&s, 5);
	Push(&s, 5);
	Push(&s, 5);
	Push(&s, 5);
	Push(&s, 5);
	Push(&s, 5);
	Printf(s);
	
	Pop(&s);
	Printf(s);
	Destroy(&s);

	int* a = (int*)malloc(sizeof(int));
	free(a);



	return 0;
}