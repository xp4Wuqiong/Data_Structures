#pragma once
#ifndef __squential_list_H_
#define __d_H_

#include <string.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 300
#define LIST_INCREMENT 10

typedef int Status;

typedef struct
{
	char sno[11];
	char name[6];
	int age;
}ElemType;

//定义顺序表结构体
typedef struct
{
	ElemType* elem;//数组
	int length;   //长度
	int Listsize;//容量
}SqList;


int EqualElem(ElemType e1, ElemType e2);//实现比较函数

Status ListEmpty(SqList L);//判断顺序表是否为空
int ListLength(SqList L);//求顺序表的长度
Status GetElem(SqList L, int i, ElemType* e);//取顺序表的第i个数据元素并存入e中
Status ListTraverse(SqList L);//遍历顺序表
Status ClearList(SqList *L);//清空顺序表
Status DestroyList(SqList* L);//销毁顺序表
Status InitList(SqList* L);//构造顺序表
int LocateElem(SqList L, ElemType e);//在顺序表中查找e，存在则返回位序
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e);//在顺序表中查找cur_e的前驱
Status NextElem(SqList L, ElemType cur_e, ElemType* next_e);//在顺序表中查找cur_e的后继
Status ListInsert(SqList* L, int i, ElemType e);//在顺序表中插入数据元素e，使之成为第i个数据元素
Status ListDelete(SqList* L, int i, ElemType* e);//删除元素

#endif

