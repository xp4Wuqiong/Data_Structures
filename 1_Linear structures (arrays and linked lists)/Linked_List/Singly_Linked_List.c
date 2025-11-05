#define _CRT_SECURE_NO_WARNINGS 1
//单向链表的基本操作

#include<stdio.h>
#include<stdlib.h>//包含free函数的头文件
#include"Singly_Linked_List.h"

/**
  * 函    数：打印单向链表的数据域
  * 参    数：单向链表的头指针
  * 返 回 值：无
  * 说    明：无
  */
void SListPrint(SLTNode *phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

/**
  * 函    数：清空单向链表的数据域
  * 参    数：单向链表的头指针
  * 返 回 值：无
  * 说    明：无
  */
void SListClear(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	SLTNode* next = NULL;
	while (cur != NULL)
	{
		next = cur->next;//先用next存储下一个指针位置
		free(cur);//再把当前节点释放
		cur = next;//将next存储的指针位置再赋予给cur
	}
	*pphead = NULL;//因为外部的头指针还是指向原来的地址，原来的地址已经被释放了，所以就直接把外部指针设置为空指针

}

/**
  * 函    数：在单向链表中创建一个新的节点
  * 参    数：想要创建新的节点的数据域的值
  * 返 回 值：NewNode，新节点的指针
  * 说    明：无
  */
SLTNode* CreateSListNode(SLTDataType x)
{
	SLTNode* NewNode = (SLTNode*)malloc(sizeof(SLTNode));
	//首先计算SLTNode类型大小，然后通过malloc函数动态分配内存空间，再将值强制转换为SLTNode*类型，最后把转换后的指针值赋给变量
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

/**
  * 函    数：在单向链表的尾部插入一个节点
  * 参    数：想要去插入链表的头指针地址和想要插入的数据域
  * 返 回 值：NewNode，新节点的指针
  * 说    明：无
  */
void SListPushBack(SLTNode **pphead, SLTDataType x)
{
	SLTNode* NewNode = CreateSListNode(x);

	if (*pphead == NULL)//如果头指针指向的地址为空，链表为空
	{
		*pphead = NewNode;//即NewNode为尾节点
	}
	else
	{
		SLTNode* tail = *pphead;//存放头指针的地址
		while (tail->next != NULL)//如果头指针的下一个地址不等于空
		{
			tail = tail->next;//该指针指向头指针下一个地址
		}
		tail->next = NULL;//最后将这个指针指向空值
	}

}

/**
  * 函    数：在单向链表的尾部删除一个节点
  * 参    数：想要去插入链表的头指针地址
  * 返 回 值：无
  * 说    明：无
  */
void SListPopBack(SLTNode** pphead)
{
	//头指针指向的地址为空，那么链表为空
	if (*pphead == NULL)
	{
		return;
	}
	else if((*pphead)->next==NULL)//(*phead)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;//存储倒数第二个节点
			tail = tail->next;
		}
		free(tail);//释放最后一个节点
		prev->next = NULL;//把最后一个节点指向为空地址
	}
}

/**
  * 函    数：在单向链表的头部插入一个节点
  * 参    数：想要去插入链表的头指针地址和数据域
  * 返 回 值：无
  * 说    明：无
  */
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* NewNode = CreateSListNode(x);
	NewNode->next = *pphead;
	*pphead = NewNode;
}

/**
  * 函    数：在单向链表的头部删除一个节点
  * 参    数：想要去删去链表的头指针地址
  * 返 回 值：无
  * 说    明：无
  */
void SListPopFront(SLTNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

/**
  * 函    数：在单向链表中查找值为x的节点
  * 参    数：链表的头指针和所要查找的数据域
  * 返 回 值：返回节点的指针
  * 说    明：无
  */
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode *cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)//判断数据域是不是等于X
		{
           return cur;//返回指针
		}
          cur = cur->next;//指向下一个指针
	}
	return NULL;//找不到，指针返回空指针
}

/**
  * 函    数：在pos指针指向的节点的前一个位置插入一个节点
  * 参    数：链表的头指针，pos指针，所要插入的数据域
  * 返 回 值：返回节点的指针
  * 说    明：无
  */
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	if (*pphead == pos)//指向的指针如果等于头指针，相当于实在头指针前插入数据域
	{
		SListPushFront(pphead, x);// 传入 SLTNode**，不要取 &pphead（那会是 SLTNode***）
	}
	else
	{
		SLTNode* NewNode = CreateSListNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)//如果这个后一个指针不等于pos的话
		{
			prev = prev->next;//下移
		}
	    prev->next=NewNode;//将prev下一个指向的指针赋予插入的新节点的指针地址
		NewNode->next = pos;//新的节点地址的指向pos地址
	}
}

/**
  * 函    数：删除pos指针指向的节点
  * 参    数：链表的头指针，pos指针
  * 返 回 值：无
  * 说    明：无
  */
void SListErese(SLTNode** pphead, SLTNode* pos)
{
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;//prev的下一个指针指向pos的下一个指针的位置
		free(pos);//然后再释放pos指针
	}
}

/**
  * 函    数：用户从键盘自己输入数值，创建单向链表
  * 参    数：无
  * 返 回 值：单向链表的头指针
  * 说    明：无
  */
SLTNode* CreateListFromInput()
{
	SLTNode* pphead = NULL;//链表头部指针
	SLTNode* tail = NULL;//链表尾部指针
	int value;

	printf("Please enter a sequence of integers, ending with -1:\n");//请输入整数序列，以-1结束输入
	while (1)
	{
		scanf("%d", &value);
		if (value == -1)
		{
			break;
		}
		// 创建新节点
		SLTNode* NewNode = CreateSListNode(value);
		// 如果链表为空，新节点既是头也是尾
		if (pphead == NULL)
		{
			pphead = NewNode;
			tail = NewNode;
		}
		else
		{
			// 将新节点添加到链表尾部
			tail->next = NewNode;//尾指针的下一个指针指向所新创建的节点
			tail = NewNode;//将新创建的节点的地址存储在尾指针内
		}
	}
	return pphead;
}



		
	