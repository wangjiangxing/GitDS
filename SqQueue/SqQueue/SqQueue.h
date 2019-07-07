#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 3
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int front, rear;
}SqQueue;
//此部分使用顺序存储结构的循环队列
void initQueue(SqQueue &Q);//初始化空队列
bool isQueueEmpty(SqQueue Q);//判断队列是否为空
void enQueue(SqQueue &Q,ElemType e);//元素入队列
void deQueue(SqQueue &Q,ElemType e);//元素出队列
void getHead(SqQueue Q, ElemType &e);//头元素赋值给e,不出队列

