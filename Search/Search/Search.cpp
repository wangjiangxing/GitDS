// Search.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "Search.h"
#include <stdlib.h>
int main() {
	SSTable ST;
	ST.data = (ElemType *)malloc(11*sizeof(int));
	CreateSSTable(ST);
	printSST(ST);
	SerachByBinary(ST, 44);
	printSST(ST);
	return 0;
}

int  SerachBySeq(SSTable ST, ElemType elem)
{
	ST.data[0] = elem;//起到哨兵的作用
	while (ST.data[ST.TableLength] != elem)
		ST.TableLength--;
	printf("查找的元素位置为data[%d]\n", ST.TableLength);
	return ST.TableLength;
}

int SerachByBinary(SSTable ST, ElemType elem)//此函数要求顺序表内的数据有序排列
{
	SSTableSort(ST);
	int front = ST.TableLength, rear = 0;
	while (front > rear)
	{
		int middle = (front + rear) / 2;
		if (ST.data[middle] > elem)
			front = middle - 1;
		else if (ST.data[middle] < elem)
			rear = middle + 1;
		else if (ST.data[middle] == elem) {
			printf("查找的元素为data[%d]\n", middle);
			return middle;
		}		
	}
	return -1;
}

void CreateSSTable(SSTable & ST)
{
	ST.data[0] = -1;
	ST.data[1] = 30; ST.data[2] = 24; ST.data[3] = 60; ST.data[4] = 20; ST.data[5] = 13; 
	ST.data[6] = 99;ST.data[7] = 45; ST.data[8] = 83; ST.data[9] = 86; ST.data[10] = 44; 
	ST.TableLength = 10;
		
}

void printSST(SSTable ST)
{
	for (int i = 1; i <= ST.TableLength; i++)
		printf("%d\t", ST.data[i]);
	printf("\n");
}

void SSTableSort(SSTable & ST)
{
	for(int i=1;i<=ST.TableLength;i++)
		for (int j = ST.TableLength-1; j >= i; j--)
		{
			if (ST.data[j+1] < ST.data[j])
			{
				int tmp=ST.data[j];
				ST.data[j] = ST.data[j + 1];
				ST.data[j + 1] = tmp;
			}
		}
}
