#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 3
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int front, rear;
}SqQueue;
//�˲���ʹ��˳��洢�ṹ��ѭ������
void initQueue(SqQueue &Q);//��ʼ���ն���
bool isQueueEmpty(SqQueue Q);//�ж϶����Ƿ�Ϊ��
void enQueue(SqQueue &Q,ElemType e);//Ԫ�������
void deQueue(SqQueue &Q,ElemType e);//Ԫ�س�����
void getHead(SqQueue Q, ElemType &e);//ͷԪ�ظ�ֵ��e,��������

