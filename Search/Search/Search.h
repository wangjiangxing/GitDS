#pragma once
typedef int ElemType;
typedef struct {
	ElemType *data;
	int TableLength;
}SSTable;
int SerachBySeq(SSTable ST, ElemType elem);//顺序查找
int SerachByBinary(SSTable ST, ElemType elem);//二分查找
void CreateSSTable(SSTable &ST);//新建一个表
void printSST(SSTable ST);//打印出顺序表的元素
void SSTableSort(SSTable &ST);//对线性表进行最简单冒泡排序用来测试二分查找