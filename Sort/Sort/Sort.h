#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct ElemType{
	int key;
};

void createTable(ElemType A[],int n);
void printTable(ElemType A[], int n);
/********************************��������     ���֣����������۰��������ϣ������*************************************/
void insertSort(ElemType A[] , int n);//��������
void binaryInsertSort(ElemType A[], int n);//�Ż��Ĳ������򡪡��۰��������
void shellSort(ElemType A[], int n);//ϣ������


/*********************************��������     ���֣�ð�����򣬿�������**************************************************/
void bubbleSort(ElemType A[], int n);//ð������
void quickSort(ElemType A[], int n);//��������

/*************************************ѡ������:��ѡ�����򣬶�����***********************************************************************/

