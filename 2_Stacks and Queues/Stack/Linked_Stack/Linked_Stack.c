#include "Linked_Stack.h"


/**
 * 函    数：初始化链栈
 * 参    数：SqStack *S
 * 返 回 值：OK
 */
Status InitStack(LinkedStack *S) 
{
    S = NULL;
    return OK;
}

/**
 * 函    数：栈的遍历输出
 * 参    数：LinkedStack S
 * 返 回 值：无
 */
void StackTraverse(LinkedStack *S) 
{
    LinkedStack p;    //使用指针p辅助访问栈里元素
    p = S;           //p初始从栈顶开始
    printf("从栈顶依次读出该栈中的元素值为:");
    while (p != NULL) 
	{
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
 
/**
 * 函    数：判断栈是否为空
 * 参    数：LinkedStack S
 * 返 回 值：OK or ERROR
 */
Status stackEmpty(LinkedStack S) 
{
    if (S == NULL) //如果栈顶的指针域指向空，则栈空
	{
        return OK;
    } 
        return ERROR;
}

/**
 * 函    数：求栈长
 * 参    数：LinkedStack S
 * 返 回 值：len
 */
Status stackLength(LinkedStack S) 
{
    int len = 0;
    while (S != NULL) 
	{
        len++;
        S = S->next;
    }
    return len;
}
 
/**
 * 函    数：清空栈
 * 参    数：LinkedStack *S,指向指针的指针
 * 返 回 值：OK or ERROR
 */
Status ClearStack(LinkedStack *S) 
{
    LinkedStackNode *p;
    while (*S != NULL) //当栈不为空时循环
    {
        p = (*S)->next;//用p临时保存下一个结点的地址
        free(*S);//释放栈顶结点
        *S = p;//修改栈顶指针
    }
    return OK;
}
 
/**
 * 函    数：销毁栈
 * 参    数：LinkedStack *S
 * 返 回 值：OK or ERROR
 */
Status DestroyStack(LinkedStack *S) 
{
    LinkedStackNode *p;
    while (*S) 
	{
        p = *S;
        *S = (*S)->next;
        free(*S);//释放栈顶结点
    }
    *S = NULL;
    return OK;
}


/**
 * 函    数：入栈，在栈顶插入元素e
 * 参    数：LinkStack *S, elemtype e
 * 返 回 值：OK or ERROR
 */
Status Push(LinkedStack *S, elemtype e) 
{
    LinkedStackNode *p = (LinkedStack *)malloc(sizeof(LinkedStack));  // 新节点创建
    if (!p) return ERROR;
    p->data = e;
    p->next = S; //将新结点插入栈顶
    S = p;       //修改栈顶指针为p
    return OK;
}
 
/**
 * 函    数：出栈，删除S的栈顶元素
 * 参    数：LinkStack *S，int &e
 * 返 回 值：OK or ERROR
 */
Status Pop(LinkedStack *S, elemtype e) //删除S的栈顶元素，用e返回其值
{
    if (S == NULL) 
	{
        return ERROR;
    }
    e = (*S)->data;      //将栈顶元素赋给e
    LinkedStack p = S;  //用p临时保存栈顶元素空间，以备释放
    S = (*S)->next;     //修改栈顶指针
    free(p);
    return OK;
}


/**
 * 函    数：获取栈顶元素
 * 参    数：LinkStack *S，elemtype e
 * 返 回 值：e
 */
int Top(LinkedStack *S, elemtype e)
{
    if (S == NULL) return ERROR;
    e = (*S)->data;
    return e;
}

/**
 * 函    数：火车调度问题
 * 参    数：int in[]，int out[]，int n
 * 返 回 值：无
 */
void TrainDispatch(int in[], int out[], int n)
{
    LinkedStack S;
    InitStack(&S);
    int i = 0; // 进站序列下标
    int j = 0; // 出站序列下标
    int topElem;// 栈顶元素

    printf("操作过程如下：\n");
    // 模拟调度过程
    while (j < n)// 当出站序列未完成时循环
    {
        
        if (!stackEmpty(S))// 如果栈顶不是目标出栈元素，就继续进站
        {
            Top(&S, &topElem);
        }
        if (!stackEmpty(S) && topElem == out[j])//栈顶元素等于当前出站元素
        {
            Pop(&S, &topElem);// 出栈（出站）
            printf("pop(%d)\n", topElem);// 输出出栈操作
            j++;// 移动到下一个出站元素
        }
        else if (i < n)// 继续进站
        {
            Push(&S, in[i]);// 入栈（进站）
            printf("push(%d)\n", in[i]);// 输出入栈操作
            i++;// 移动到下一个进站元素
        }
        else
        {
            printf("该出站序列不可行（不安全）！\n");// 无法继续匹配，说明不可行
            ClearStack(&S);
            return;
        }
    }
    printf("该出站序列可行！\n");
    ClearStack(&S);
}