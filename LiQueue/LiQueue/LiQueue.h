#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Lnode{
	ElemType data;
	 struct Lnode * next;
}*LinkList;
typedef struct LiQueue{
	struct Lnode *front;
	struct Lnode *rear;
}LiQueue,*LinkQueue;

void initQueue(LinkQueue &Q);//初始化链式结构的队列
bool isEmpty(LinkQueue &Q);//判断队列是否为空
void enQueue(LinkQueue &Q, ElemType e);//入队列
void deQueue(LinkQueue &Q, ElemType &e);//出队列
void getHead(LinkQueue Q);//输出当前头//队列不能遍历
void clearQueue(LinkQueue &Q);//清空队列