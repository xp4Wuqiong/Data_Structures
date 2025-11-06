#pragma once
#ifndef __Sequential_Stack_H_
#define __Sequential_Stack_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 300
#define LIST_INCREMENT 10

typedef int Status;
typedef int SElemType;


//定义顺序栈结构体
typedef struct
{
	SElemType *base;   //地基   
	SElemType *top;   //头部
	int stacksize;   //容量
}SqStack;

/*顺序栈的基本操作*/
int StackLength(SqStack S);//求顺序栈的长度
void StackTraverse(SqStack S);//遍历顺序栈
Status StackEmpty(SqStack S);//判断顺序栈是否为空
Status FullEmpty(SqStack S);//判断顺序栈是否为满
Status ClearList(SqStack *S);//清空顺序栈
Status DestroyStack(SqStack *S);//销毁顺序栈
Status InitStack(SqStack *S);//初始化顺序栈
Status Top(SqStack* S, SElemType  *e);//获取栈顶元素
Status Push(SqStack* S, SElemType e);//入栈
Status Pop(SqStack* S, SElemType  *e);//出栈

#endif

