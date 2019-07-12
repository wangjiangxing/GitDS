#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType ;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *Lchild;
	struct BiTNode *Rchild;
}BiTNode,*BiTree;
void initTree(BiTree &T);//初始化树
void makeTree(BiTree &T,int i);//建立除了头结点以为的树结点
void createTree(BiTree &T,int i);//建立一棵完整的树
void visitNode(BiTree &T);//访问结点
void preOrder(BiTree T);//先序遍历
void inOrder(BiTree T);//中序遍历
void postOrder(BiTree T);//后序遍历
void LevelOrder(BiTree T);//层次遍历
