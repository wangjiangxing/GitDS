// LinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "LinkList.h"
 
int main()
{
	LinkList L;
	initLinkList(L);
	//createLinkListHead(L);//头插法建立单链表
	createLinkListTail(L);//尾插法建立单链表
	//insertNode(L, 1, 100);//测试插入结点
	//deleteNode(L, 1);//测试删除结点
	//deleteAllElemNoHead(L, 10);
	//deleteAllElemHaveHead(L, 10);//测试删除含有头结点的所有元素为某一个数值的结点
	printLinkList(L);//输出单链表
	//reversePrintAllElem(L);//测试倒序输出单链表
	printf("链表长度为:%d", getLength(L));
	return 0;
}

void initLinkList(LinkList & L)
{
	L = (LinkList)malloc(sizeof(Lnode));
	//printf("%d", L->next);
	L->next = NULL;
	printf("%d", L->next);
	L->data = 0;
}

void createLinkListHead(LinkList & L)
{
	initLinkList(L);
	LinkList s;
	ElemType dat = 0;
	printf("请输入链表值:");
	scanf("%d", &dat);
	while (dat != -1)
	{
		s = (LinkList)malloc(sizeof(Lnode));
		s->data = dat;
		printf("请输入链表值:");
		scanf("%d", &dat);
		s->next = L->next;
		L->next = s;
	}
}

void createLinkListTail(LinkList & L)
{
	LinkList s, p;
	ElemType dat;
	initLinkList(L);
	s = L;
	printf("请输入链表的值:");
	scanf("%d", &dat);
	while (dat != -1)
	{
		p = (LinkList)malloc(sizeof(Lnode));
		p->data = dat;
		p->next = NULL;
		s->next = p;
		s = s->next;
		printf("请输入链表的值:");
		scanf("%d", &dat);
	}
}

LinkList getElem(LinkList L, int i)
{
	while (i != 0) {
		L = L->next;
		if (L == NULL)
		{
			printf("链表没有这么长");
			return NULL;
		}
		i--;
	}
	return L;
}

LinkList locateElem(LinkList L, ElemType e)
{
	while (L->next->data != e || L == NULL) {
		L = L->next;
		if (L==NULL)
		{
			printf("没有找到这个值");
			return NULL;
		}
	}	
	return L;
}

void insertNode(LinkList & L, int i, ElemType e)
{
	if (getLength(L) < i)
	{
		printf("输入有误!");
		return;
	}
	LinkList s = getElem(L, i-1);
	LinkList p = (LinkList)malloc(sizeof(Lnode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

void deleteNode(LinkList & L, int i)
{
	if (getLength(L) < i)
	{
		printf("输入有误!");
		return;
	}
	LinkList s=getElem(L, i-1);
	LinkList p = s->next;
	s->next = s->next->next;
	free(p);
}

int  getLength(LinkList L)
{
	int length=0;
	L = L->next;
	while (L != NULL)
	{
		length++;
		L = L->next;
	}
	return length;
}

void printLinkList(LinkList L)
{
	int i = 0;
	L = L->next;
	while (L != NULL)
	{
		i++;
		printf("链表第%d个值为%d\n", i, L->data);
		L = L->next;
	}
}

void deleteAllElemNoHead(LinkList & L, ElemType e)
{
	//算法思想
	//本结点带头结点所以模拟头结点只是一个普通结点，采用递归方式
	LinkList p;
	if (L == NULL)
		return;
	if (L->data == e)//要删除的结点
	{
		p = L;
		L = L->next;
		free(p);
		deleteAllElemNoHead(L, e);
	}
	else
		deleteAllElemNoHead(L->next, e);
}

void deleteAllElemHaveHead(LinkList & L, ElemType e)
{
	//算法思路
	//遍历之后若是找到则删除
	LinkList s, p;
	s = L;
	p = L->next;
	while (p!= NULL) {
		if (p->data == e)
		{
			LinkList h = p;
			p = p->next;
			s->next = p;
			free(h);
		}
		else {
			p = p->next;
			s = s->next;
		}
		
	}
}

void reversePrintAllElem(LinkList L)
{
	if (L->next != NULL)
		reversePrintAllElem(L->next);
	printf("链表值为:%d", L->data);
}
