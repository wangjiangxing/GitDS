#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType ;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *Lchild;
	struct BiTNode *Rchild;
}BiTNode,*BiTree;
void initTree(BiTree &T);//��ʼ����
void makeTree(BiTree &T,int i);//��������ͷ�����Ϊ�������
void createTree(BiTree &T,int i);//����һ����������
void visitNode(BiTree &T);//���ʽ��
void preOrder(BiTree T);//�������
void inOrder(BiTree T);//�������
void postOrder(BiTree T);//�������
void LevelOrder(BiTree T);//��α���
