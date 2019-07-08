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

void initQueue(LinkQueue &Q);//��ʼ����ʽ�ṹ�Ķ���
bool isEmpty(LinkQueue &Q);//�ж϶����Ƿ�Ϊ��
void enQueue(LinkQueue &Q, ElemType e);//�����
void deQueue(LinkQueue &Q, ElemType &e);//������
void getHead(LinkQueue Q);//�����ǰͷ//���в��ܱ���
void clearQueue(LinkQueue &Q);//��ն���