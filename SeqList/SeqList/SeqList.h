#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
#define MaxSize 100
typedef struct  {
	ElemType* data;
	int length;
}SeqList;
int InitList(SeqList &L);//初始化列表
bool isEmpty(SeqList L);//判断是否为空
int GetLength(SeqList L);//返回列表长度
int LocateElem(SeqList L, ElemType e);//返回指定元素的结点的位置
ElemType GetElem(SeqList L, int i);//返回指定位置的数值
int ListInsert(SeqList &L, int i,ElemType e);//在第i个位置插入e
int ListDelete(SeqList &L, int i, ElemType &e);//删除第i个位置并用e来记录删除的数值
void PrintList(SeqList L);//按序打印所有数据
void DestoryList(SeqList &L);//销毁顺序表
void testInsert(SeqList &L);//测试插入数据
void testDelete(SeqList &L);//测试删除数据
ElemType deleteMinElem(SeqList &L);//删除顺序表中最小的元素，并用最后一个元素填入，返回最小值
void ReverseList(SeqList &L);//原地将顺序表逆置
void deleteTheSameElem(SeqList &L, ElemType e);//删除该顺序表中所有值为e的数据，要求时间复杂度为O(n),空间复杂度为O(1)  