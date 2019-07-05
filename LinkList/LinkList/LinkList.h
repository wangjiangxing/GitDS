#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Lnode {
	ElemType data;  
	struct Lnode * next;
}Lnode,*LinkList;
void initLinkList(LinkList &L);//��ʼ��ͷ���
void createLinkListHead(LinkList &L);//ͷ�巨����������
void createLinkListTail(LinkList &L);//β�巨����������
LinkList getElem(LinkList L, int i);//���ص�i������λ��ָ��
LinkList locateElem(LinkList L, ElemType e);//��λ����Ϊe��λ�÷���λ��ָ��
void insertNode(LinkList &L, int i,ElemType e);//�ڵ�i��λ�ò�������
void deleteNode(LinkList &L, int i);//ɾ����i�����
int getLength(LinkList L);//���ر�
void printLinkList(LinkList L);//�����������ֵ
void deleteAllElemNoHead(LinkList &L, ElemType e);//�ݹ鷽ʽɾ������ͷ���ĵ����������н��ֵΪe�Ľ��
void deleteAllElemHaveHead(LinkList &L, ElemType e);//ɾ����ͷ���ĵ����������н��ֵΪe�Ľ��
void reversePrintAllElem(LinkList L);//����������н��ֵ