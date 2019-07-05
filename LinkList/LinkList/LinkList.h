#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Lnode {
	ElemType data;  
	struct Lnode * next;
}Lnode,*LinkList;
void initLinkList(LinkList &L);//初始化头结点
void createLinkListHead(LinkList &L);//头插法创建单链表
void createLinkListTail(LinkList &L);//尾插法创建单链表
LinkList getElem(LinkList L, int i);//返回第i个结点的位置指针
LinkList locateElem(LinkList L, ElemType e);//定位数据为e的位置返回位置指针
void insertNode(LinkList &L, int i,ElemType e);//在第i个位置插入数据
void deleteNode(LinkList &L, int i);//删除第i个结点
int getLength(LinkList L);//返回表长
void printLinkList(LinkList L);//输出所有链表值
void deleteAllElemNoHead(LinkList &L, ElemType e);//递归方式删除不带头结点的单链表中所有结点值为e的结点
void deleteAllElemHaveHead(LinkList &L, ElemType e);//删除带头结点的单链表中所有结点值为e的结点
void reversePrintAllElem(LinkList L);//逆序输出所有结点值