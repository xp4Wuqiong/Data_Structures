#include "Applications_of_Sequential_Stack.h"

/**
* 函    数：将十进制数转换为R进制数
* 参    数：十进制数N，m是选择转换为什么进制（2,8,16……进制）
* 返 回 值：无
*/
void Conversion(int N, int m)
{
	 SqStack S;//定义一个SqStack类型的顺序栈
	 SElemType e;//定义一个SElemType类型的变量
	 int FUshu_PD = 0;

	 if (m < 2 || m>36)//如果进制是小于2（排除1进制），大于36进制（最大只有36进制）
	 {
		 printf("Base number must be between 2 and 36!\n"); // 进制数必须在2——36之间！
		 return;//直接退出函数
	 }

	 printf("Decimal number %d converted to base %d is: ", N, m); // 十进制数%d转换为%d进制数为：

	 if (N == 0)//十进制数为0，退出
	 {
		 printf("0\n");
		 return;
	 }
	 if (!InitStack(&S))
	 {
		 printf("Stack initialization failed!\n"); // 栈初始化失败！
		 return;
	 }
	 if (N < 0)//处理负数
	 {
		 FUshu_PD = 1;
		 N = -N;
	 }
	 while (N > 0)//把进制数都放入栈中
	 {
		 Push(&S, N % m);
		 N = N / m;
	 }
	 if (FUshu_PD) 
	 {
		 printf("-");
	 }
	 while (!StackEmpty(S))//输出结果
	 {
		 Pop(&S, &e);
		 if (e < 10)
		 {
			 printf("%d", e);//0-9直接输出，不是16进制以上的进制
		 }
		 else
		 {
			 printf("%c", 'A' + (e - 10));//10以上的输出字母
		 }
	 }
	 printf("\n");
	 DestroyStack(&S);//销毁栈
}


/**
* 函    数：判断是否是四则运算符
* 参    数：字符
* 返 回 值：如果是c == '+' || c == '-' || c == '*' || c == '/'任意一个，返回1，否则为0
*/
int IsOperator(char c)
{
	 return (c == '+' || c == '-' || c == '*' || c == '/');
}

 
/**
* 函    数：判断四则运算符优先级
* 参    数：1个运算符
* 返 回 值：1 ,2 ,0
*/
int precedence(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


/**
* 函    数：将中缀表达式转换为后缀表达式
* 参    数：输入的中缀表达式字符串infix，输出的后缀表达式字符串postfix
* 返 回 值：无
*/
void Infix_To_Postfix(const char *infix, char *postfix) 
{
    SqStack S;
    SElemType e;
    InitStack(&S);
    int k = 0;//用于记录输出后表达式字符串的当前位置索引

    for (int i = 0; infix[i] != '\0'; i++)//遍历整个输入字符串，直到遇到字符串结束符 '\0'
    {
        char c = infix[i];//当前读取的字符

        if (isspace(c)) continue;  // 忽略空格，制表符，跳过

        if (isdigit(c)) // 数字(0~9)
        {          
            postfix[k++] = c;//直接讲数字加入到输出字符串中
        } 
        else if (c == '(') //左括号
        {
            Push(&S, c);//入栈
        }
        else if (c == ')')//右括号
        {
            while (!StackEmpty(S) && Top(&S, &e) == OK && e != '(') 
            {
                Pop(&S, &e);
                postfix[k++] = e;//弹出栈顶运算符并添加到输出字符串中，直到遇到左括号为止
            }
            if (!StackEmpty(S) && Top(&S, &e) == OK && e == '(') 
            {
                Pop(&S, &e); // 弹出 '('
            }
        } 
        else if (IsOperator(c)) 
        {
            while (!StackEmpty(S) && Top(&S, &e) == OK && precedence(e) >= precedence(c))//当栈不为空且栈顶运算符的优先级大于或等于当前运算符时 
            {
                Pop(&S, &e);
                postfix[k++] = e;//弹出栈顶运算符并添加到输出字符串中
            }
            Push(&S, c);//将当前运算符入栈
        }
    }

    while (!StackEmpty(S)) //弹出栈中剩余的运算符
    {
        Pop(&S, &e);
        postfix[k++] = e;//弹出栈顶运算符并添加到输出字符串中
    }

    postfix[k] = '\0';//添加字符串结束符
    DestroyStack(&S);
}

/**
* 函    数：判断字符串是否为回文
* 参    数：str 是一个指向常量字符的指针
* 返 回 值：OK表示是回文，ERROR表示不是回文
*/
Status IsPalindrome(const char *str) 
{
    int len = (int)strlen(str);             // 计算字符串长度
    SqStack S;
    SElemType ch;
    
    if (!InitStack(&S)) 
    {
        return FALSE;                   // 如果栈创建失败，返回 FALSE
    }

    
    for (int i = 0; i < len / 2; i++) //将前半部分字符压入栈中
    {
       Push(&S, str[i]);    // 将字符串的前半部分字符入栈
    }

    for (int i = (len + 1) / 2; i < len; i++) // 从中间开始比较后半部分字符
    {
        if (Pop(&S, &ch) == ERROR) 
        { 
            DestroyStack(&S);// 如果出栈失败，释放栈并返回 FALSE
            return FALSE;
        }
        if (ch != str[i]) // 若出栈字符与字符串后半部分字符不匹配
        {                 
            DestroyStack(&S);  // 释放栈内存
            return FALSE;// 返回 FALSE，表示不是回文
        }
    }
    DestroyStack(&S); // 所有字符匹配成功，释放栈内存
    return TRUE;  // 返回 TRUE，表示是回文
}