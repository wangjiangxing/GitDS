#pragma once
#include <stdio.h>
#define  MAXSIZE 1000
typedef int ElemType;
typedef struct SqStack {
	ElemType data[MAXSIZE];
	int top;
};
void initStack(SqStack &S);//初始化栈
bool StackIsEmpty(SqStack S);//判断栈是否为空
bool Push(SqStack &S,ElemType e);//将数据压栈
bool Pop(SqStack &S,ElemType &e);//将数据出栈
void GetTop(SqStack S, ElemType &e);//读取栈顶元素并存入e
void ClearStack(SqStack &L);//清空栈
void testPush(SqStack &S);
void testPop(SqStack &S);
void printStack(SqStack S);//输出栈
int getStackLength(SqStack S);//返回栈的长度