#pragma once
#include <stdio.h>
#define  MAXSIZE 1000
typedef int ElemType;
typedef struct SqStack {
	ElemType data[MAXSIZE];
	int top;
};
void initStack(SqStack &S);//��ʼ��ջ
bool StackIsEmpty(SqStack S);//�ж�ջ�Ƿ�Ϊ��
bool Push(SqStack &S,ElemType e);//������ѹջ
bool Pop(SqStack &S,ElemType &e);//�����ݳ�ջ
void GetTop(SqStack S, ElemType &e);//��ȡջ��Ԫ�ز�����e
void ClearStack(SqStack &L);//���ջ
void testPush(SqStack &S);
void testPop(SqStack &S);
void printStack(SqStack S);//���ջ
int getStackLength(SqStack S);//����ջ�ĳ���