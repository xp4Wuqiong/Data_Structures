#include <stdio.h>
#include <stdlib.h>
#include "Linked_Queue.h"

/**
 * 函    数：初始化链队列
 * 参    数：无
 * 返 回 值：LinkQueue类型的指针
 */
LinkQueue* InitQueue() 
{
	LinkQueue* Q = malloc(sizeof(LinkQueue));//生成队头队尾指针
	Q->front = (QNode*)malloc(sizeof(QNode));//生成新结点作为头结点，队头队尾指针指向该结点
	Q->rear = Q->front;//队尾指针指向头结点
	Q->front->next = NULL;//头结点指针域置空
	return Q;
}

/**
 * 函    数：打印链队列中的元素（遍历）
 * 参    数：LinkQueue类型的指针Q
 * 返 回 值：无
 */
void print(LinkQueue *Q) 
{
	printf("(front) ");
	if (Q->front != Q->rear)//队不为空 
	{
		QNode* p = Q->front->next;//使用指针p辅助访问队列里元素
		while (p != NULL)        //遍历直到指针域为空
		{
			printf("%d ", p->data);//打印当前指针指向的元素
			p = p->next;//指针移动到下一个结点
		}
	}
	printf("(rear)\n");
}

/**
 * 函    数：入队操作
 * 参    数：LinkQueue类型的指针Q，插入的元素e
 * 返 回 值：无
 */
void EnQueue(LinkQueue* Q, int e) 
{
	QNode* p = malloc(sizeof(QNode));//生成新结点
	p->data = e;//新结点数据域置为e，指针域置空
	p->next = NULL;//新结点指针域置空
	Q->rear->next = p;//新结点插入队尾
	Q->rear = p;//修改队尾指针
}

/**
 * 函    数：出队操作
 * 参    数：LinkQueue类型的指针Q，删除的元素e
 * 返 回 值：OK or ERROR
 */
Status DeQueue(LinkQueue* Q, int* e) 
{
	if (Q->front == Q->rear)//删除队头元素，用e返回其值	
	return ERROR;//判断队列是否为空
	QNode* p = Q->front->next;//p指向队头元素
	*e = p->data;//e保存队头元素
	Q->front->next = p->next;//修改头结点指针域
	if (Q->rear == p)	Q->rear = Q->front;//最后一个元素被删，队尾指针指向头结点
	free(p);//释放队头元素空间
	return OK;
}

/**
 * 函    数：获取队头元素
 * 参    数：LinkQueue类型的指针Q，获取的元素e
 * 返 回 值：OK or ERROR
 */
Status GetHead(LinkQueue* Q, int* e) 
{
	if (Q->front == Q->rear)//判断队列是否为空	
	return ERROR;
	QNode* p = Q->front->next;//p指向队头元素
	*e =p->data;//用e返回队头元素值
	return OK;
}