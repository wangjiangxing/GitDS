#pragma once
typedef int ElemType;
typedef struct {
	ElemType *data;
	int TableLength;
}SSTable;
int SerachBySeq(SSTable ST, ElemType elem);//˳�����
int SerachByBinary(SSTable ST, ElemType elem);//���ֲ���
void CreateSSTable(SSTable &ST);//�½�һ����
void printSST(SSTable ST);//��ӡ��˳����Ԫ��
void SSTableSort(SSTable &ST);//�����Ա�������ð�������������Զ��ֲ���