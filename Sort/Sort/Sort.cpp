// Sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Sort.h"

int main()
{
	int n = 19;
	ElemType A[20];
	createTable(A, n);
	printTable(A, n);
	return 0;
}

void createTable(ElemType A[],int n)
{
	A[0].key = 0;//此单元不存储数据，用作哨兵
	for (int i = 1; i <= n;i++)
	{
		A[i].key = rand() % 100;
	}
	return ;
}

void printTable(ElemType A[], int n)
{
	for (int i = 1; i <= n; i++)
		printf("[%d]:%d\t", i, A[i].key);
	printf("\n");
	return;
}

void insertSort(ElemType A[], int n)//直接插入排序
{
	/*
	基本思想:左边是已经排好序的元素，之后将后面的元素一个一个插入
	算法复杂度：O(n^2)
	*/
	for(int i=2;i<n;i++)
		for()
}
