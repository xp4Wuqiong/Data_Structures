#pragma once
#ifndef __Applications_of_Sequential_Stack_H_
#define __Applications_of_Sequential_Stack_H_

#include <ctype.h>//专门提供字符处理函数
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Sequential_Stack.h"

#define TRUE 1          // 定义 TRUE 表示真
#define FALSE 0         // 定义 FALSE 表示假

/*辅助函数*/
int IsOperator(char c);//判断是否是四则运算符
int precedence(char op) ;//判断四则运算符优先级

/*顺序栈的应用*/
void Conversion(int N, int m);//十进制转换为R进制
void Infix_To_Postfix(const char *infix, char *postfix) ;//将中缀表达式转换为后缀表达式
Status IsPalindrome(const char *str);//判断字符串是否为回文
#endif

