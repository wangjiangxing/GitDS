// SqQueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "SqQueue.h"

int main()
{
	SqQueue Q;
	int i=0;
	initQueue(Q);
	enQueue(Q, 1); enQueue(Q, 2); enQueue(Q, 3); enQueue(Q, 4);
	deQueue(Q, i); deQueue(Q, i);
	getHead(Q, i);
	return 0;
}


void initQueue(SqQueue & Q)
{
	Q.rear = 0;
	Q.front = 0;
}

bool isQueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
	return false;
}

void enQueue(SqQueue & Q, ElemType e)
{
	if ((Q.rear+1)%MAXSIZE == Q.front)
	{
		printf("队列已满\n");
		return;
	}
	Q.data[Q.rear] = e;
	printf("入队列元素%d\n", e);
	Q.rear = (Q.rear + 1) % MAXSIZE;
}

void deQueue(SqQueue & Q, ElemType e)
{
	if (Q.front==Q.rear)
	{
		printf("队列空\n");
		return;
	}
	printf("出队列元素%d\n", Q.data[Q.front]);
	Q.front = (Q.front + 1) % MAXSIZE;
}

void getHead(SqQueue Q, ElemType & e)
{
	if (Q.front == Q.rear)
	{
		printf("队列空\n");
		return;
	}
	printf("出队列元素%d\n", Q.data[Q.front]);
}
