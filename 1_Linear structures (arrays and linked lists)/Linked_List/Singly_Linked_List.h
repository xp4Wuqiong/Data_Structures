#pragma once

#ifndef __Singly_Linked_List_H
#define __Singly_Linked_List_H

/*
作用：创建单向链的结点的结构体类型，成员包含数据域和指针域
*/
typedef int SLTDataType;                //将整型重新命名为SLTDate，整型可以改为float,double都行
typedef struct Single_Linked_Table
{
	struct Single_Linked_Table* next;//这个SLTNode还没定义呢，所以不能这样写SLTNode* next;
	SLTDataType data;
}SLTNode;

/*单向链表的基本操作*/
void SListPrint(SLTNode *phead);//打印链表
void SListClear(SLTNode **pphead);//清空链表
SLTNode *CreateSListNode(SLTDataType x);//创建节点
void SListPushBack(SLTNode** pphead, SLTDataType x);//尾插节点
void SListPopBack(SLTNode** pphead);//尾删节点
void SListPushFront(SLTNode** pphead, SLTDataType x);//头插节点
void SListPopFront(SLTNode** pphead);//头删节点
SLTNode* SListFind(SLTNode* phead, SLTDataType x);//查找值为x的节点并返回节点的指针
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//在pos指针指向的节点的前一个位置插入一个节点
void SListErese(SLTNode** pphead, SLTNode* pos);//删除pos指针指向的节点

/*方便与用户交互*/
SLTNode* CreateListFromInput();//用户从键盘自己输入数值，创建单向链表
#endif



