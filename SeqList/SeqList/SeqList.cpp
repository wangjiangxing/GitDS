﻿// SeqList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "SeqList.h"
int main()
{
	SeqList A,B;
	testInsert(A);//插入元素
	testInsert2(B);
	findTheMainNumber(A);
	//findTwoListTheMiddleNum(A, B);//测试找出两个顺序表中的中位数
	//PrintList(L);
	//swapSeqList(5, 6, L);//测试交换A[m+n]数组从A[m1,m2.....mm,n1,n2....nn]->A[n1,n2....nn,m1,m2...mm]
	//findSomeoneToSwapLaterOrInset(L, 14);//测试最快速度找到某一个值，若不存在就插入这个值
	//PrintList(L);
	//testInsert2(S);
	//PrintList(L);
	//PrintList(S);
	//PrintList(L);//输出
	//deleteMinElem(L);//删除最小值测试
	//ReverseList(L);//逆置顺序表测试
	//deleteTheSameElem(L, 60);//测试删除顺序表中相同的元素
	//deleteAllBetweenSandT(L, 0, 10);//测试删除顺序表中中所有在s和t之间的数值
	//deleteAllSameNumber(L);//测试删除表中所有重复的元素
	//deleteAllNoSeqBetweenSandT(L,0,10);
	//SeqList returnSeqList = combineTwoSeqList(L, S);
	//printf("=================================\n");
	//PrintList(returnSeqList);
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
	ListInsert(L, 1, 1);ListInsert(L, 2, 1);ListInsert(L, 3, 1);
	ListInsert(L, 4, 1);ListInsert(L, 5, 1);ListInsert(L, 6, 1);
	ListInsert(L, 7, 1);ListInsert(L, 8,1 );ListInsert(L, 9, 17);
	ListInsert(L, 10, 19);ListInsert(L, 11, 21);
}

void testInsert2(SeqList & L)
{
	InitList(L);
	ListInsert(L, 1, 2); ListInsert(L, 2, 4); ListInsert(L, 3, 6);
	ListInsert(L, 4, 8); ListInsert(L, 5, 10); ListInsert(L, 6, 12);
	ListInsert(L, 7, 14); ListInsert(L, 8, 16); ListInsert(L, 9, 18);
	ListInsert(L, 10, 22); ListInsert(L, 11, 23);
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

SeqList combineTwoSeqList(SeqList L, SeqList S)
{
	/*算法思想：分别遍历两个有序表，并分别判断，并分别判断是否已经结束一个链表的遍历
	以减少判断的次数，，本算法要求L和S的长度之和不大于MaxSize*/
	//定义一个能够容纳两个数组的要求返回数组returnSeqList;
	SeqList returnSeqList;
	returnSeqList.data = (ElemType *)malloc(MaxSize * sizeof(ElemType));
	//定义两个“指针”用来比较当前应当存入数组的值
	int ptr1 = 1; int len1= L.length;
	int ptr2 = 1; int len2 = S.length;
	if (len1 + len2 > MaxSize)
		return returnSeqList;
	int returnPtr = 1;
	//循环遍历两个顺序表
	while(ptr1<=len1&&ptr2<len2 )	//判断其中某一个顺序表是否已经判断结束,若是结束，直接停止比较直接让后面的依次加入返回顺序表中
	{
		if (L.data[ptr1] >= S.data[ptr2])
		{
			returnSeqList.data[returnPtr] = S.data[ptr2];
			returnPtr++;
			ptr2++;
		}
		else if (L.data[ptr1] < S.data[ptr2])
		{
			returnSeqList.data[returnPtr] = L.data[ptr1];
			returnPtr++;
			ptr1++;
		}
	}
	//进行相应的后续添加
	if (ptr1 > len1)
	{
		for (ptr2; ptr2<= len2; ptr2++)
		{
			returnSeqList.data[returnPtr] = S.data[ptr2];
			returnPtr++;
		}
	}
	if (ptr2 > len2)
	{
		for (ptr1; ptr1<= len1; ptr1++)
		{
			returnSeqList.data[returnPtr] = L.data[ptr1];
			returnPtr++;
		}
	}
	//将该顺序表中的length设置为两者之和
	returnSeqList.length = len1 + len2;
	return returnSeqList;
}

void swapSeqList(int m, int n,SeqList &L)
{
	/*算法思想：借鉴逻辑移位的思想，定义一个暂存之后一直进行移位操作，循环N次后即可交换*/
	//判断输入的数据是否合法
	if (n + m != L.length)
	{
		printf("输入有错，运行结束!");
		return;
	}	
	//首先定义一个暂存，定义一个数字用来记录次数
	//由于本结构默认采用data[0]未用，可以当作暂存
	int num = 1;
	while (num <= n)
	{
		L.data[0] = L.data[L.length];
		//开始向后移位
	   //将第i次移位的暂存存入L.data[i-1]中
		for (int i = 0; i < L.length; i++)
			L.data[L.length - i] = L.data[L.length - i - 1];
		num++;
	}
}

void findSomeoneToSwapLaterOrInset(SeqList& L, ElemType e)
{
	/*算法思想:在找元素上可以利用二分查找，效率快，时间复杂度是logn，
		若是查找的到，自然可以直接交换；
		若是找不到，则必须移动大于该数据的后续元素
	*/
	//首先利用二分查找
	int front =L.length,rear=1;
	while (rear < front)
	{
		int middle = (front + rear) / 2;
		if (L.data[middle] > e)
			front = middle - 1;
		if (L.data[middle] < e)
			rear = middle + 1;
		if (L.data[middle] == e)
			rear = front = middle;
	}
	//若是找到，交换它与后继元素
	if (L.data[rear] == e)
	{
		ElemType tmp = L.data[rear];
		L.data[rear] = L.data[rear+1];
		L.data[rear + 1]=tmp;
	}
	//找不到，将后面的元素均向后推移之后将数值插入
	if (L.data[rear] != e)
	{
		//将后续数值均向后移位一位
		for (int i = L.length; i >= rear; i--)
			L.data[i + 1] = L.data[i];
		L.data[rear] = e;
		//将数值插入rear
		//将length加上1
		L.length++;
	}
}

ElemType findTwoListTheMiddleNum(SeqList A, SeqList B)
{
	/*原算法思想：先将两个数组元素通过比较合并为一个数组，然后使用二分查找，若使用这种方法，时间复杂度为O(n)
		空间复杂度为:O(n),效果不理想
	现算法思想:不对两个数组进行合并排序。首先找出两个数组中各自的中位数然后进行数据上的比较，假设a,b
		若a=b，说明中位数已经找到，
		若是a>b，说明中位数一定在a的左边或者b的右边，就把a的右边和b的左边"删去"
		若是a<b，说明中位数一定在a的右边或者b的左边，就把a的左边和b的右边"删去"
		可以看出来时间复杂度为O(log2n),由于占用常数个变量，空间复杂度为O(1)
	*/
	//首先判断输入的两个数组的合法性
	
	if (A.length != B.length)
	{
		printf("输入的两个数组元素有误!");
		return -1;
	}
	//定义四个变量分别记录左端和右端，为二分法做准备
	int Arear = A.length; int Afront = 1; int Amiddle = (Arear + Afront) / 2;
	int Brear = B.length; int Bfront = 1; int Bmiddle = (Brear + Bfront) / 2;
	//使用二分法查找
	while (Arear!=Afront|| Brear != Bfront)
	{
		Amiddle = (Arear + Afront) / 2;
		Bmiddle = (Brear + Bfront) / 2;
		if (A.data[Amiddle] ==B.data[Bmiddle])
		{
			return A.data[Amiddle];
		}
		if (A.data[Amiddle] > B.data[Bmiddle])
		{
			if ((Brear + Bfront) % 2 == 0)
			{
				Arear = Amiddle ;
				Bfront = Bmiddle ;
			}
			else {
				Arear = Amiddle ;
				Bfront = Bmiddle + 1;
			}
			
		}
		if (A.data[Amiddle] < B.data[Bmiddle])
		{
			if ((Arear + Afront) % 2 == 0)
			{
				Afront = Amiddle ;
				Brear = Bmiddle ;
			}
			else {
				Afront = Amiddle + 1;
				Brear = Bmiddle ;
			}
		}
	}
	//最后结果若是两个中位数相等，则结果就是这个数值，若不等就是两者之中更大的数
	ElemType returnNum= A.data[Amiddle] > B.data[Bmiddle] ? A.data[Amiddle] : B.data[Bmiddle];
	//if (A.data[Amiddle] == B.data[Bmiddle])
	//	return A.data[Amiddle];
	//else
	//	A.data[Amiddle] > B.data[Bmiddle] ? A.data[Amiddle] : B.data[Bmiddle];
	printf("中位数为%d\n", returnNum);
	return 0;
		
}

ElemType findTheMainNumber(SeqList L)
{
	/*原算法思想：由于该数组的元素的值不会大于所在元素下标，可以设置一个数组用来专门存储所在元素出现的个数
	时间复杂度为O(n),空间复杂度为O(n)*/
	//定义一个频率数组，下标表示元素值，里面的数值代表下标值出现的次数,初始化频率数组
	int A[MaxSize];
	for (int i = 0; i <= L.length; i++)
	{
		A[i] = 0;
	}
	//遍历要求的数组
	for (int i = 1; i <= L.length; i++)
	{
		A[L.data[i]]++;
	}
	//查找是否存在一个值>n/2
	int maxIndex = 0;
	for (int i = 0; i < L.length; i++)
		if (A[i] > L.length / 2)
		{
			printf("该顺序表的主元素为:%d", i);
			return 0;
		}
	printf("该顺序表不存在主元素!");
	return -1;
}
