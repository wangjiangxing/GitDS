// SqStack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "SqStack.h"
int main()
{
	SqStack S;
	initStack(S);
	testPush(S);
	testPop(S);
	return 0;
}

void initStack(SqStack & S)
{
	S.top = -1;
}

bool StackIsEmpty(SqStack S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}

bool Push(SqStack & S,ElemType e)
{
	if (S.top >= MAXSIZE - 1)
	{
		printf("栈满!");
		return false;
	}
		
	else {
		S.data[++S.top] = e;
		return true;
	}	
}

bool Pop(SqStack & S,ElemType &e)
{
	if (S.top <= -1)
	{
		printf("栈空!");
		return false;
	}
	else
	{
		e = S.data[S.top--];
		return true;
	}
}

void GetTop(SqStack S, ElemType & e)
{
	if (S.top > -1)
		e = S.data[S.top];
	else
		printf("栈空!");
}

void ClearStack(SqStack & S)
{
	S.top = -1;
}

void testPush(SqStack & S)
{
	ElemType  i;
	for (i = 1; i < 6; i++)
	{
		Push(S, i);
		printf("进栈元素是%d\n", i);
	}
}

void testPop(SqStack & S)
{
	ElemType  i;
	Pop(S, i);
	printf("出栈元素是%d\n", i);
	Pop(S, i);
	printf("出栈元素是%d\n", i);
	Pop(S, i);
	printf("出栈元素是%d\n", i);
	Pop(S, i);
	printf("出栈元素是%d\n", i);
}
