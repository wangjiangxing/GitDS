#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct ElemType{
	int key;
};

void createTable(ElemType A[],int n);
void printTable(ElemType A[], int n);
/********************************插入排序     三种：插入排序，折半插入排序，希尔排序*************************************/
void insertSort(ElemType A[] , int n);//插入排序
void binaryInsertSort(ElemType A[], int n);//优化的插入排序——折半插入排序
void shellSort(ElemType A[], int n);//希尔排序


/*********************************交换排序     两种：冒泡排序，快速排序**************************************************/
void bubbleSort(ElemType A[], int n);//冒泡排序
void quickSort(ElemType A[], int n);//快速排序

/*************************************选择排序:简单选择排序，堆排序***********************************************************************/

