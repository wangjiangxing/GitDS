#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#define MaxSize 100
typedef struct  {
	ElemType* data;
	int length;
}SeqList;
int InitList(SeqList &L);//��ʼ���б�
bool isEmpty(SeqList L);//�ж��Ƿ�Ϊ��
int GetLength(SeqList L);//�����б���
int LocateElem(SeqList L, ElemType e);//����ָ��Ԫ�صĽ���λ��
ElemType GetElem(SeqList L, int i);//����ָ��λ�õ���ֵ
int ListInsert(SeqList &L, int i,ElemType e);//�ڵ�i��λ�ò���e
int ListDelete(SeqList &L, int i, ElemType &e);//ɾ����i��λ�ò���e����¼ɾ������ֵ
void PrintList(SeqList L);//�����ӡ��������
void DestoryList(SeqList &L);//����˳���
void testInsert(SeqList &L);//���Բ�������
void testDelete(SeqList &L);//����ɾ������
ElemType deleteMinElem(SeqList &L);//ɾ��˳�������С��Ԫ�أ��������һ��Ԫ�����룬������Сֵ
void ReverseList(SeqList &L);//ԭ�ؽ�˳�������
void deleteTheSameElem(SeqList &L, ElemType e);//ɾ����˳���������ֵΪe�����ݣ�Ҫ��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)  