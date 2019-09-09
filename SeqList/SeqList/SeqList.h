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
void testInsert(SeqList &L);//测试插入数据方法1
void testInsert2(SeqList &L);//测试插入数据方法2
void testDelete(SeqList &L);//测试删除数据
/*以下均为王道第二章 线性表 课后题*/
ElemType deleteMinElem(SeqList &L);//1.删除顺序表中最小的元素，并用最后一个元素填入，返回最小值
void ReverseList(SeqList &L);//2.原地将顺序表逆置
void deleteTheSameElem(SeqList &L, ElemType e);//3.删除该顺序表中所有值为e的数据，要求时间复杂度为O(n),空间复杂度为O(1)  
void deleteSeqListAllBetweenSandT(SeqList &L, ElemType s, ElemType t);//4.有序顺序表中删除所有值在s~t之间的数值
void deleteAllNoSeqBetweenSandT(SeqList &L, ElemType s, ElemType t);//5.无序顺序表中删除所有值在s~t之间的数值
void deleteAllSameNumber(SeqList &L);//6.删除顺序表中重复的元素
SeqList combineTwoSeqList(SeqList L, SeqList S);//7.合并两个顺序表并返回合成的顺序表
void swapSeqList( int m, int n,SeqList &L );//8:交换A[m+n]数组从A[m1,m2.....mm,n1,n2....nn]->A[n1,n2....nn,m1,m2...mm]
//第十题也是顺序左移，故不再编写
void findSomeoneToSwapLaterOrInset(SeqList& L, ElemType e);//9:查找顺序表中某个特定元素的值，若存在与后继元素交换，若不存在则插入表中并且是表中元素有序
ElemType findTwoListTheMiddleNum(SeqList A,SeqList B);//11，找出两个等长数组的中位数
ElemType findTheMainNumber(SeqList L);//找出主元素，主元素的定义是在长度为N的链表中出现元素最多的且大于N/2的元素