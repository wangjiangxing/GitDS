#pragma once
#include <stdio.h>
#include <stdlib.h>
#define ElemType int
typedef struct LiStack {
	ElemType data;
	LiStack * next;
}LiStack,* LinkStack;
void initStack(LinkStack &S);//初始化栈
bool isStackEmpty(LinkStack S);//判断是否为空
void Push(LinkStack &S, ElemType e);//入栈
void Pop(LinkStack &S, ElemType &e);//出栈
void getTop(LinkStack S, ElemType &e);//返回栈顶元素
void clearStack(LinkStack &S);//栈清空
void printStack(LinkStack S);//输出栈