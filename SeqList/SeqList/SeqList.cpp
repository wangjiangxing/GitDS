// SeqList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "SeqList.h"
int main()
{
	SeqList L;
	testInsert(L);
	PrintList(L);
	//deleteMinElem(L);//删除最小值测试
	//ReverseList(L);//逆置顺序表测试
	deleteTheSameElem(L, 60);
	PrintList(L);
	return 0;
}

int InitList(SeqList & L)
{
	L.data = (ElemType *)malloc(sizeof(ElemType)*MaxSize);
	L.length = 0;
	return 0;
}

bool isEmpty(SeqList L)
{
	if (L.length == 0)
		return true;
	else
		return false;
}

int GetLength(SeqList L)
{
	return L.length;
}

int LocateElem(SeqList L, ElemType e)
{
	int len = L.length;
	while (len) {
		if (L.data[len] == e)
			return len;
		len--;
	}
	return 0;
}

ElemType GetElem(SeqList L, int i)
{
	if (L.length < i) {
		printf("您输入的值有误!");
		return -1;
	}
	return L.data[i];
}

int ListInsert(SeqList & L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1) {
		printf("输入有误!");
		return -1;
	}
	else if (L.length+1 > MaxSize) {
		printf("存储已满!");
		return -1;
	}
	for (int j = L.length; j >= i; j--)
		L.data[j+ 1] = L.data[j];
	L.data[i] = e;
	L.length++;
	return 0;
}

int ListDelete(SeqList & L, int i, ElemType & e)
{
	if (i > L.length || i < 1) {
		printf("您输入的数值有误");
		return -1;
	}
	e = L.data[i];
	for (int j = i; j <= L.length; j++)
		L.data[j] = L.data[j+1];
	L.data[L.length] = 0;
	L.length--;
	return 0;
}

void PrintList(SeqList L)
{
	for (int i = 1; i <= L.length; i++)
		printf("第%d个元素值为%d\n", i, L.data[i]);
}

void DestoryList(SeqList & L)
{
	free(L.data);
}

void testInsert(SeqList & L)
{
	InitList(L);
	ListInsert(L, 1, 60);
	ListInsert(L, 2, 20);
	ListInsert(L, 3, 60);
	ListInsert(L, 4, 40);
	ListInsert(L, 5, 50);
	ListInsert(L, 6, 60);
	ListInsert(L, 7, 60);
	ListInsert(L, 8, 60);
	ListInsert(L, 9, 60);
	ListInsert(L, 10, 60);
	ListInsert(L, 11, 60);
}

void testDelete(SeqList & L)
{
	int num = 0;
	ListDelete(L, 1, num);
	printf("您删除的值是:%d\n", num);
	ListDelete(L, 1, num);
	printf("您删除的值是:%d\n", num);
	ListDelete(L, 1, num);
	printf("您删除的值是:%d\n", num);
	printf("\n**************************************\n");
	PrintList(L);
	
}

ElemType deleteMinElem(SeqList & L)
{
	//基本算法思想
	//利用data[0]存储当前最小的值遍历整个数据循环更新同时记录下标，最后返回。
	int num = 0;//记录下标
	if (L.length == 0) {
		printf("该顺序表没有数值。");
		return -1;
	}
	L.data[0] = 1; num = 1;
	for (int i = 2; i <= L.length; i++)
	{
		if (L.data[0] > L.data[i])
		{
			L.data[0] = L.data[i];
			num = i;
		}
	}
	L.data[num] = L.data[L.length];
	return L.data[0];
}

void ReverseList(SeqList & L)
{
	//算法思想
	//利用data[0]来从两边交换
	for (int i = 1; i <= L.length / 2; i++)
	{
		L.data[0] = L.data[i];
		L.data[i] = L.data[L.length - i + 1];
		L.data[L.length - i + 1] = L.data[0];
	}
}

void deleteTheSameElem(SeqList & L, ElemType e)
{
	//算法思想
	//用K记录当前不为e的值  
	int K = 0;
	for (int i = 1; i <= L.length; i++)
	{
		if (L.data[i] != e)
		{
			K++;
			L.data[K] = L.data[i];
		}	
	}
	L.length = K;
}
