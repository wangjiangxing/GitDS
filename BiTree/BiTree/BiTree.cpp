// BiTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "LiQueue.h"
ElemType dat = 1;
LinkQueue Q=(LinkQueue)malloc(sizeof(LiQueue));
int main()
{
	BiTree T;
	createTree(T, 2);
	//preOrder(T);
	//printf("*****************************\n");
	//inOrder(T);
	//printf("*****************************\n");
	//postOrder(T);
	//printf("****************************\n");
	LevelOrder(T);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

void initTree(BiTree & T)
{
	T = (BiTNode *)malloc(sizeof(BiTNode));
	T->data = 0;
	T->Lchild = NULL;
	T->Rchild = NULL;
}

void makeTree(BiTree & T,int i)
{
	if (i >0)
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
