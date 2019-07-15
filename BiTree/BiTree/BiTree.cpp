// BiTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "LiQueue.h"
ElemType dat = 1;
LinkQueue Q=(LinkQueue)malloc(sizeof(LiQueue));
int sumNoLeafNum = 0;
int main()
{
	BiTree T;
	createTree(T, 3);
	preOrder(T);
	printf("*****************************\n");
	inOrder(T);
	printf("*****************************\n");
	postOrder(T);
	printf("****************************\n");
	LevelOrder(T);
	sumNoLeaf(T);
	printf("该树的非叶子结点有%d个", sumNoLeafNum);
	return 0;
}

void initTree(BiTree & T)
{
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T->data = 0;
	T->Lchild = NULL;
	T->Rchild = NULL;
}

void makeTree(BiTree & T,int i)
{
	if (i >1)
	{
		T->Lchild = (BiTree)malloc(sizeof(BiTNode)); initTree(T->Lchild);
		dat++;
		T->Lchild->data = dat;
		T->Rchild = (BiTree)malloc(sizeof(BiTNode)); initTree(T->Rchild);
		dat++;
		T->Rchild->data = dat;
		makeTree(T->Lchild, i - 1);
		makeTree(T->Rchild, i - 1);
	}
	
}

void createTree(BiTree & T,int i)
{
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = 1;
	makeTree(T, i);
}

void visitNode(BiTree & T)
{
	printf("访问结点的值为%d\n", T->data);
}

void preOrder(BiTree T)
{
	if (T != NULL) {
		visitNode(T);
		preOrder(T->Lchild);
		preOrder(T->Rchild);
	}
}

void inOrder(BiTree T)
{
	if (T != NULL) {
		inOrder(T->Lchild);
		visitNode(T);
		inOrder(T->Rchild);
	}
}

void postOrder(BiTree T)
{
	if (T != NULL) {
		postOrder(T->Lchild);
		postOrder(T->Rchild);
		visitNode(T);
	}
}

void LevelOrder(BiTree T)
{
	initQueue(Q);
	BiTree p;
	enQueue(Q, T);
	while (!isEmpty(Q))
	{
		deQueue(Q, p);
		visitNode(p);
		if (p->Lchild != NULL)
			enQueue(Q,p->Lchild);
		if (p->Rchild != NULL)
			enQueue(Q, p->Rchild);
	}
}
void sumNoLeaf(BiTree T)
{
	if (T != NULL)
	{
		if (T->Lchild != NULL || T->Rchild != NULL)
			sumNoLeafNum++;
		sumNoLeaf(T->Lchild);
		sumNoLeaf(T->Rchild);
	}
	//printf("该树的非叶子结点有%d个", sumNoLeafNum);
}
