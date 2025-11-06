#include <stdio.h>
#include <stdlib.h>
#include "squential_list.h"

/**
  * 函    数：实现比较函数
  * 参    数：结构体数组1，结构体数组2
  * 返 回 值：1为比较成功，0为比较失败
  */
int EqualElem(ElemType e1, ElemType e2)
{
	int pd_sno, pd_name, pd_age;
	//如果字符串相等，返回 0
	//如果第一个字符串小于第二个，返回负数
	//如果第一个字符串大于第二个，返回正数
	pd_sno = (strcmp(e1.sno, e2.sno) == 0);   //逻辑判断，等于0，为1
	pd_name = (strcmp(e1.name, e2.name) == 0);
	pd_age = (e1.age == e2.age);//逻辑判断，相等为1
	// 三个都相等时返回0，否则返回1
	if (pd_sno && pd_name && pd_age) return 1;
	return 0;
}

/**
  * 函    数：判断顺序表是否为空
  * 参    数：结构体数据类型SqList L
  * 返 回 值：如果长度是0，那么返回为OK，是空顺序表；否则不是空表
  */
Status ListEmpty(SqList L)
{
	return (L.length==0)?OK:ERROR;
}

/**
  * 函    数：求顺序表的长度
  * 参    数：结构体数据类型SqList L
  * 返 回 值：返回顺序表的长度
  */
int ListLength(SqList L)
{
	return L.length;
}

/**
  * 函    数：取顺序表的第i个数据元素并存入e中
  * 参    数：SqList L，i元素，结构体类型e,c语言中用指针传参
  * 返 回 值：OK or ERROR
  */
Status GetElem(SqList L, int i, ElemType* e)
{
	if (i > L.length || i < 1)
	{
		return ERROR;
	}
	*e = *(L.elem + i - 1);//把结构体赋给指针指向的对象
	return OK;
}

/**
  * 函    数：遍历顺序表
  * 参    数：SqList L
  * 返 回 值：OK or ERROR
  */
 Status ListTraverse(SqList L)
{
	int i;
	for (i = 0;i < L.length ;i++)
	{
		//printf("%4d", L.elem[i]);结构体类型的数组，有多个成员，所以逐条要把每一个成员都输出
		printf("ID:%s\tNAME:%s\tAGE:%d\n",L.elem[i].sno, L.elem[i].name, L.elem[i].age);
	}
	return OK;
}

 /**
  * 函    数：清空顺序表
  * 参    数：SqList &L
  * 返 回 值：OK
  */
 Status ClearList(SqList* L)//结构体指针
 {
	 L->length = 0;  // 使用 -> 来访问结构体成员
     //若使用 L.length 时，编译器认为你在访问一个 结构体变量 的成员，而不是指针
	 return OK;
 }

 /**
  * 函    数：销毁顺序表
  * 参    数：传递指针L，直接对L操作
  * 返 回 值：OK
  */
 Status DestroyList(SqList* L)
 {
	 if (L->elem!=NULL)  
     {
    free(L->elem);
	L->elem = NULL;
    }
    L->length = 0;
    L->Listsize = 0;
	 return OK;
 }

 /**
 * 函    数：构造顺序表
 * 参    数：引用&L，直接对L操作
 * 返 回 值：OK or ERROR
 */
 Status InitList(SqList* L)
 {
	 L->elem = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	 if (!L->elem) return ERROR;
	 L->length = 0;//可以改写长度，并加入for循环把里面的数组加入里面
	 L->Listsize = MAXSIZE;
	 return OK;
 }

 /**
 * 函    数：在顺序表中查找e，存在则返回位序
 * 参    数：顺序表L，结构体类型的e
 * 返 回 值：位序(下标加一）
 */
 int LocateElem(SqList L, ElemType e)
 {
	 int i;
	 for (i = 0;i < L.length;i++)
	 {
		 
		 if (EqualElem(L.elem[i],e)) return i + 1;
	 }
	 return 0;
}

 /**
 * 函    数：在顺序表中查找cur_e的前驱并存入pre_e
 * 参    数：顺序表L，所要查找的cur_e，直接引用pre_e
 * 返 回 值：OK or ERROR
 */
 Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e)
 {
	 int i;
	 i = LocateElem(L, cur_e);
	 if (i == 0 || i == 1) return ERROR;
	 *pre_e = L.elem[i - 1 - 1];
	 return OK;
}

 /**
 * 函    数：在顺序表中查找cur_e的后继
 * 参    数：顺序表L，所要查找的cur_e，直接引用next_e
 * 返 回 值：OK or ERROR
 */
 Status NextElem(SqList L, ElemType cur_e, ElemType* next_e)
 {
	 int i;
	 i = LocateElem(L, cur_e);
	 if (i == 0 || i == L.length) return ERROR;
	 *next_e = L.elem[i - 1 + 1];
	 return OK;
 }

 /**
 * 函    数：在顺序表中插入数据元素e，使之成为第i个数据元素
 * 参    数：顺序表引用L，i为所要插入的位置，插入数据元素e
 * 返 回 值：OK or ERROR
 */
 Status ListInsert(SqList* L, int i, ElemType e)
 {
	 int j;
	 if (i<1 || i>L->length+1) return ERROR;//因为可以在最后插入一个元素
	 if (L->length == L->Listsize)
	 {
		 ElemType *newbase = (ElemType*)realloc(L->elem, (L->Listsize + LIST_INCREMENT) * sizeof(ElemType));
		 if (!newbase) return ERROR;
		 L->elem = newbase;
		 L->Listsize += LIST_INCREMENT;
	 }
	 for (j = L->length;j >= i;j--)L->elem[j] = L->elem[j - 1];
	 L->elem[i - 1] = e;
	 L->length++;
	 return OK;
}

 /**
  * 函    数：在顺序表中删除第i个数据元素，并存入e中
  * 参    数：SqList& L, int i, ElemType& e
  * 返 回 值：OK or ERROR
  */
 Status ListDelete(SqList* L, int i, ElemType* e)
 {
	 int j;
	 if (i<1 || i>L->length) return ERROR;
	 *e = L->elem[i - 1];
	 for (j = i;j<L->length;j++)
		 L->elem[j - 1] = L->elem[j];
	 L->length--;
	 return OK;
 }