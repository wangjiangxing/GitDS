// LiQueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "LiQueue.h"
void initQueue(LinkQueue & Q)
{
	Q->front = (LinkList)malloc(sizeof(Lnode));
	Q->rear = Q->front;
	Q->front->data = NULL;
	Q->rear->data = NULL;
}

bool isEmpty(LinkQueue & Q)
{
	if (Q->front==Q->rear)
	{
		return true;
	}
	else
	return false;
}

void enQueue(LinkQueue & Q, Elemtype e)
{
	LinkList s = (LinkList)malloc(sizeof(Lnode));
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = Q->rear->next;
}

void deQueue(LinkQueue & Q, Elemtype & e)
{
	if (Q->front==Q->rear)
	{
		return;
	}
	LinkList p = Q->front;
	Q->front = Q->front->next;
	e = Q->front->data;
	free(p);
}

void getHead(LinkQueue Q)
{
	if (Q->front == Q->rear)
	{
		printf("队列空!\n");
		return;
	}
	printf("出队列元素为%d", Q->front->next->data);
}

void clearQueue(LinkQueue & Q)
{
	Elemtype i = NULL;
	while (Q->front != Q->rear) {
		deQueue(Q,i);
	}
}
