#pragma once
#include <stdio.h>
#include <stdlib.h>
#define ElemType int
typedef struct LiStack {
	ElemType data;
	LiStack * next;
}LiStack,* LinkStack;
void initStack(LinkStack &S);//��ʼ��ջ
bool isStackEmpty(LinkStack S);//�ж��Ƿ�Ϊ��
void Push(LinkStack &S, ElemType e);//��ջ
void Pop(LinkStack &S, ElemType &e);//��ջ
void getTop(LinkStack S, ElemType &e);//����ջ��Ԫ��
void clearStack(LinkStack &S);//ջ���
void printStack(LinkStack S);//���ջ