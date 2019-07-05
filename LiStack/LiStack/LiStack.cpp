#include "pch.h"
#include "LiStack.h"

int main()
{
	LinkStack S;
	int i;
	initStack(S);
	Push(S, 1); Push(S, 2); Push(S, 3); Push(S, 4); Push(S, 5); Push(S, 6); Push(S, 7); Push(S, 8);
	Pop(S, i); Pop(S, i); Pop(S, i); Pop(S, i); Pop(S, i); Pop(S, i); 
	printStack(S);
	return 0;
}

void initStack(LinkStack & S)
{
	S = (LinkStack)malloc(sizeof(LiStack));
	S->next = NULL;
	S->data = 0;
}

bool isStackEmpty(LinkStack S)
{
	if (S->next == NULL)
		return false;
	else
		return true;
}

void Push(LinkStack & S, ElemType e)
{
	LinkStack P = (LinkStack)malloc(sizeof(LiStack));
	P->data = e;
	P->next = S->next;
	S->next = P;
	printf("入栈元素为%d\n", e);
}

void Pop(LinkStack & S, ElemType & e)
{
	if (S->next == NULL)
	{
		printf("栈空!");
		return;
	}
	e = S->next->data;
	LinkStack P = S->next;
	S->next = P->next;
	printf("出栈元素为%d\n", e);
	free(P);
}

void getTop(LinkStack S, ElemType & e)
{
	if (isStackEmpty(S))
	{
		printf("栈空!");
		return;
	}
	e = S->next->data;
}

void clearStack(LinkStack & S)
{
	int e;
	while (S->next != NULL)
	{
		Pop(S, e);

	}
	free(S);
}

void printStack(LinkStack S)
{
	S = S->next;
	int i = 1;
	while (S != NULL) {
		printf("第%d个栈元素是%d\n", i, S->data);
		i++;
		S = S->next;
	}
}
