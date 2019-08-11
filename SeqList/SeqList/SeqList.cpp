// SeqList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "SeqList.h"
int main()
{
	SeqList L;
	testInsert(L);//插入元素
	PrintList(L);//输出
	//deleteMinElem(L);//删除最小值测试
	//ReverseList(L);//逆置顺序表测试
	//deleteTheSameElem(L, 60);//测试删除顺序表中相同的元素
	//deleteAllBetweenSandT(L, 0, 10);//测试删除顺序表中中所有在s和t之间的数值
	//deleteAllSameNumber(L);//测试删除表中所有重复的元素
	deleteAllNoSeqBetweenSandT(L,0,10);
	printf("=================================\n");
	PrintList(L);
	return 0;
}

int InitList(SeqList & L)
{
	L.data = (ElemType *)malloc(sizeof(ElemType)*MaxSize);
	L.length = 0;
	return 0;
}

bool isEmpty(SeqList L)
{
	if (L.length == 0)
		return true;
	else
		return false;
}

int GetLength(SeqList L)
{
	return L.length;
}

int LocateElem(SeqList L, ElemType e)
{
	//默认不含重复元素
	int len = L.length;
	while (len) {
		if (L.data[len] == e)
			return len;
		len--;
	}
	return 0;
}

ElemType GetElem(SeqList L, int i)
{
	if (L.length < i) {
		printf("您输入的值有误!");
		return -1;
	}
	return L.data[i];
}

int ListInsert(SeqList & L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1) {
		printf("输入有误!");
		return -1;
	}
	else if (L.length+1 > MaxSize) {
		printf("存储已满!");
		return -1;
	}
	for (int j = L.length; j >= i; j--)
		L.data[j+ 1] = L.data[j];
	L.data[i] = e;
	L.length++;
	return 0;
}

int ListDelete(SeqList & L, int i, ElemType & e)
{
	if (i > L.length || i < 1) {
		printf("您输入的数值有误");
		return -1;
	}
	e = L.data[i];
	for (int j = i; j <= L.length; j++)
		L.data[j] = L.data[j+1];
	L.data[L.length] = 0;
	L.length--;
	return 0;
}

void PrintList(SeqList L)
{
	for (int i = 1; i <= L.length; i++)
		printf("第%d个元素值为%d\n", i, L.data[i]);
}

void DestoryList(SeqList & L)
{
	free(L.data);
}

void testInsert(SeqList & L)
{
	InitList(L);
	ListInsert(L, 1, 100);ListInsert(L, 2, 2);ListInsert(L, 3, 200);
	ListInsert(L, 4, 1);ListInsert(L, 5, 300);ListInsert(L, 6, 4);
	ListInsert(L, 7, 3);ListInsert(L, 8, 400);ListInsert(L, 9, 9);
	ListInsert(L, 10, 10);ListInsert(L, 11, 11);
}

void testDelete(SeqList & L)
{
	int num = 0;
	ListDelete(L, 1, num);
	printf("您删除的值是:%d\n", num);
	ListDelete(L, 1, num);
	printf("您删除的值是:%d\n", num);
	ListDelete(L, 1, num);
	printf("您删除的值是:%d\n", num);
	printf("\n**************************************\n");
	PrintList(L);
	
}

ElemType deleteMinElem(SeqList & L)
{
	//基本算法思想
	//利用data[0]存储当前最小的值遍历整个数据循环更新同时记录下标，最后返回。
	int num = 0;//记录下标
	if (L.length == 0) {
		printf("该顺序表没有数值。");
		return -1;
	}
	L.data[0] = 1; num = 1;
	for (int i = 2; i <= L.length; i++)
	{
		if (L.data[0] > L.data[i])
		{
			L.data[0] = L.data[i];
			num = i;
		}
	}
	L.data[num] = L.data[L.length];
	return L.data[0];
}

void ReverseList(SeqList & L)
{
	//算法思想
	//利用data[0]来从两边交换
	for (int i = 1; i <= L.length / 2; i++)
	{
		L.data[0] = L.data[i];
		L.data[i] = L.data[L.length - i + 1];
		L.data[L.length - i + 1] = L.data[0];
	}
}

void deleteTheSameElem(SeqList & L, ElemType e)
{
	//算法思想
	//用K记录当前不为e的值  
	int K = 0;
	for (int i = 1; i <= L.length; i++)
	{
		if (L.data[i] != e)
		{
			K++;
			L.data[K] = L.data[i];
		}	
	}
	L.length = K;
}

void deleteSeqListAllBetweenSandT(SeqList & L, ElemType s, ElemType t)
{
	/*算法思想：设置两个指针(伪)，一个指向在s和t之间的，即应当删除的，一个指向第一个大于t的数值位置
	                    另外一个指向第一个大于t的，然后把这个数值移到这个里面，循环到末尾
					    将长度设置为i的长度*/
	if (s > t)
		return;
	//首先找到第一个在区间s和t之间的，然后再找一个第一个大于t的
	int front = 1, rear = 1;
	while (L.data[rear] < s)
		rear++;
	while (L.data[front] <= t)
		front++;
	//出现极端情况：全部在区间里面，全部不在区间里面
	if (rear == L.length|| front == 1)//rear代表找到第一个在被删除区间的值，若为Length说明没有一个是在这个区间的
	//front代表第一个比被删区间大的值，若是1说明没有一个在这个区间则直接返回
		return;
	for (int i = 0; i <= L.length - front; i++)//依次把区间外的向前面移动位置，移动完成之后将长度修改
		L.data[rear + i] = L.data[front + i];
	L.length = L.length - (front - rear);
}

void deleteAllNoSeqBetweenSandT(SeqList & L, ElemType s, ElemType t)
{
	/*算法思想：设置一个数组，其中存储着每个元素应当向前移动的步数，之后遍历，最后移动*/
	//定义一个大小为顺序表长度+1的数组,用来存储对应的元素应当向前移动的步数
	int Step[MaxSize+1];
	//将数组初始化为0；
	for (int i = 0; i < MaxSize + 1; i++)
		Step[i] =0;
	//定义一个整形变量暂存向前移动的步数
	int step = 0;
	//遍历，若是在s~t区间就将步数+1，并且将步数添加到步数数组中
	for (int i = 1; i <= L.length; i++)
	{
		if (L.data[i] >= s &&L.data[i] <= t)
		{
			step++;
			Step[i] = step;
		}
		else {
			Step[i] = step;
		}
	}
	//遍历，移动数据
	for (int i = 1; i <= L.length; i++)
		if (L.data[i] < s || L.data[i] >t)
			L.data[i -Step[i]]= L.data[i] ;
	//将顺序表的长度减去步数
	L.length -= step;
}

void deleteAllSameNumber(SeqList & L)
{
	/*算法思想：首先设置两个"指针"，分别指向开始，首先先让后面的指针一直走
	如果不相同就都向前一个，如果相同就让后面一个一直走同时记录向前移动的步数
	之后当碰到第一个不相同的数值后开始移动，重复这个过程*/
	//首先设置两个指针，初始时指向顺序表的第一个
	int front = 2;
	int rear = 1;
	//设置一个变量来保存向前移动的步数
	int step= 0;
	//for循环来遍历整个顺序表，如果两个指针指向的数值相同后面的指针继续向前移动
	for (int i = 1; i <= L.length; i++)
	{
		if (L.data[front] == L.data[rear])
		{
			front++;
			step++;
		}
		//如果不同就两个都移动，并且移动数值。
		if (L.data[front] != L.data[rear])
		{
			L.data[front - step] = L.data[front];
			front++;
			rear++;
		}	
	}
	//将顺序表的长度减去移动的数值
	L.length -= step;
}
