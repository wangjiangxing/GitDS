// LiQueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "LiQueue.h"

int main()
{
	int i = 0;
	LinkQueue Q=(LinkQueue)malloc(sizeof(LiQueue));
	initQueue(Q);
	enQueue(Q, 1); enQueue(Q, 2); enQueue(Q, 3); enQueue(Q, 4); enQueue(Q, 5);
	deQueue(Q, i); deQueue(Q, i); deQueue(Q, i); deQueue(Q, i);
	isEmpty(Q);
	deQueue(Q, i);
	isEmpty(Q);
	return 0;
}

void initQueue(LinkQueue & Q)
{
	Q->front = (LinkList)malloc(sizeof(Lnode));
	Q->rear = Q->front;
	Q->front->data = 0;
	Q->rear->data = 0;
}

bool isEmpty(LinkQueue & Q)
{
	if (Q->front==Q->rear)
	{
		printf("队列空!\n");
		return true;
	}
	else
	return false;
}

void enQueue(LinkQueue & Q, ElemType e)
{
	LinkList s = (LinkList)malloc(sizeof(Lnode));
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = Q->rear->next;
}

void deQueue(LinkQueue & Q, ElemType & e)
{
	if (Q->front==Q->rear)
	{
		printf("队列空!\n");
		return;
	}
	LinkList p = Q->front;
	Q->front = Q->front->next;
	printf("出队列元素为%d\n", Q->front->data);
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
	int i = 0;
	while (Q->front != Q->rear) {
		deQueue(Q,i);
	}
}
