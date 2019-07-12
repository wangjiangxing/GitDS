#pragma once
#include "BiTree.h"
#include <stdio.h>
#include <stdlib.h>
typedef BiTree Elemtype;
typedef struct Lnode{
	Elemtype data;
	 struct Lnode * next;
}*LinkList;
typedef struct LiQueue{
	struct Lnode *front;
	struct Lnode *rear;
}LiQueue,*LinkQueue;

void initQueue(LinkQueue &Q);//��ʼ����ʽ�ṹ�Ķ���
bool isEmpty(LinkQueue &Q);//�ж϶����Ƿ�Ϊ��
void enQueue(LinkQueue &Q, Elemtype e);//�����
void deQueue(LinkQueue &Q, Elemtype &e);//������
void getHead(LinkQueue Q);//�����ǰͷ//���в��ܱ���
void clearQueue(LinkQueue &Q);//��ն���