#pragma once

#ifndef __Linked_Stack_H
#define __Linked_Stack_H

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int Status;

/*
作用：创建队链的结点的结构体类型，成员包含数据域和指针域
*/
typedef int elemtype;                
typedef struct LinkedStackNode
{
	elemtype data;                   //数据域
	struct LinkedStackNode* next;   //指针域
}LinkedStackNode,*LinkedStack;


/*链栈的基本操作*/
Status InitStack(LinkedStack* S);//初始化链栈
void StackTraverse(LinkedStack *S);//栈的遍历输出
Status stackEmpty(LinkedStack S);//判断栈是否为空
Status stackLength(LinkedStack S);//求栈长
Status ClearStack(LinkedStack *S);//清空栈
Status DestroyStack(LinkedStack *S);//销毁栈
Status Push(LinkedStack *S, elemtype e);//入栈
Status Pop(LinkedStack *S, elemtype e);//出栈
Status Top(LinkedStack *S, elemtype e);//获取栈顶元素

/*链栈的应用*/
void TrainDispatch(int in[], int out[], int n);//火车调度问题
#endif
