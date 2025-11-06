#include "Sequential_Stack.h"

/**
  * 函    数：判断顺序栈是否为空
  * 参    数：顺序栈
  * 返 回 值：如果是空返回0K，否则是ERROR
  */
Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return OK;
	else
	    return ERROR;
}

/**
  * 函    数：判断顺序栈是否为满
  * 参    数：SqStack S
  * 返 回 值：如果是空返回0K，否则是ERROR
  */
Status FullEmpty(SqStack S)
{
	if (S.top - S.base == S.stacksize)
		return OK;
	else 
		return ERROR;
}


/**
  * 函    数：求顺序栈的长度
  * 参    数：结构体数据类型SqStack S
  * 返 回 值：返回顺序表的长度
  */
int StackLength(SqStack S)
{
	return (int)(S.top-S.base);//强制类型转换
}


/**
  * 函    数：遍历顺序栈
  * 参    数：SqStack S
  * 返 回 值：无
  */
void StackTraverse(SqStack S)
{
	printf("现在的栈内元素为：");
	SElemType* p = S.base;
	while (p != S.top)
	{
		printf("%d  ", *p);
		p++;
	}
	printf("\n");
}

 /**
  * 函    数：清空顺序栈
  * 参    数：SqStack &S
  * 返 回 值：OK
  */
Status ClearList(SqStack* S)//清空顺序栈
 {
	S->top = S->base;
	 return OK;
 }


 /**
  * 函    数：销毁顺序栈
  * 参    数：引用&S，直接对S操作
  * 返 回 值：OK
  */
Status DestroyStack(SqStack *S)
{
	if (S->base)
	{
		free(S->base);
		S->stacksize = 0;
		S->top = S->base = NULL;
	}
	return OK;
}


 /**
 * 函    数：初始化链栈
 * 参    数：SqStack *S
 * 返 回 值：OK
 */
 Status InitStack(SqStack *S)
 {
	 S=NULL;
	 return OK;
 }


 /**
 * 函    数：获取栈顶元素
 * 参    数：SqStack& S，SElemType e
 * 返 回 值：OK or ERROR
 */
int Top(SqStack* S, SElemType *e)
{
	 if (S->top == S->base)
		 return ERROR;
	 *e = *(S->top - 1);
	 return OK;
}

 /**
 * 函    数：入栈
 * 参    数：SqStack& S, SElemType e
 * 返 回 值：OK or ERROR
 */
 Status Push(SqStack* S, SElemType e)
{
	 if (S->top - S->base == S->stacksize) return ERROR;
	 *(S->top) = e;//先将值存储到栈顶指向的位置
	 S->top++;//栈顶指针增加
	 return OK;
}

 /**
 * 函    数：出栈
 * 参    数：引用SqStack& S, SElemType *e
 * 返 回 值：OK or ERROR
 */
 Status Pop(SqStack* S, SElemType *e)
 {
	 if (S->top == S->base)
		 return ERROR;
	 S->top--;      //先自减
	*e = *(S->top);//再赋值
	 return OK;
 }
