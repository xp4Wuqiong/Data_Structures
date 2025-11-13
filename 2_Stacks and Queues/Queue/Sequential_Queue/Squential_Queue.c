#include <stdio.h>
#include <stdlib.h>
#include "Squential_Queue.h"

/**
 * 函    数：动态分配一个大小为size的数组空间，base指向数组空间首地址
 * 参    数：队列最大长度size
 * 返 回 值：SqQueue类型的指针
 */
SqQueue* InitQueue(int size) 
{
	SqQueue* Q = malloc(sizeof(SqQueue));//先创建队列结构体指针
	Q->base = (int*)malloc(sizeof(int) * size);//为队列分配一个最大容量为size的数组空间
	//队列最大长度置为size，头指针尾指针置为0，队列为空
	Q->maxsize = size;//队列最大长度
	Q->front = 0;//头指针
	Q->rear = 0;//尾指针
	return Q;
}

/**
 * 函    数：打印队列中的元素（遍历）
 * 参    数：SqQueue类型的指针Q
 * 返 回 值：无
 */
void print(SqQueue* Q) 
{
	printf("(front) ");//打印队头标识
	int i;

	//i = Q->front -> 从队列的头开始
    //i != Q->rear -> 直到遇到队列的尾（不包含rear指向的位置）
	//让指针循环移动到下一个位置，当到达数组末尾时自动回到开头
	for (i = Q->front; i != Q->rear; i = (i + 1) % Q->maxsize) 
	{
		printf("%d ", Q->base[i]);//打印当前指针指向的元素
	}
	printf("(rear)\n");//打印队尾标识
}

/**
 * 函    数：入队操作
 * 参    数：SqQueue类型的指针Q，插入的元素e
 * 返 回 值：true or false
 */
Status EnQueue(SqQueue* Q, int e) 
{
	if ((Q->rear + 1) % Q->maxsize == Q->front)//预判下一个插入位置是否与队头重合来判断队满，区分了队空和队满状态
	return ERROR;
	Q->base[Q->rear] = e;//将新元素 e 放入队尾指针当前指向的位置
	Q->rear = (Q->rear + 1) % Q->maxsize;//指针向后移动，处理循环通过取模运算实现循环，更新指针
	return OK;
}

/**
 * 函    数：出队操作
 * 参    数：SqQueue类型的指针Q，删除的元素e
 * 返 回 值：true or false
 */
Status DeQueue(SqQueue* Q, int* e) 
{
	
	if (Q->front == Q->rear)//删除队头元素，用e返回其值	
	return ERROR;//队空
	*e = Q->base[Q->front];//用e保存队头元素
	Q->front = (Q->front + 1) % Q->maxsize;//头指针加1
	return OK;
}


/**
 * 函    数：返回队头元素，不修改头指针
 * 参    数：SqQueue类型的指针Q，删除的元素e
 * 返 回 值：true or false
 */
Status GetHead(SqQueue* Q, int* e) 
{
	//返回队头元素，不修改头指针
	if (Q->front == Q->rear)	
	return ERROR;//队空
	*e = Q->base[Q->front];//用e保存队头元素
	return OK;
}

/**
 * 函    数：求队列长度
 * 参    数：SqQueue类型的指针Q
 * 返 回 值：队列元素个数
 */
int QueueLength(SqQueue* Q) 
{
	int len;
	len=(Q->rear - Q->front + Q->maxsize) % Q->maxsize;
	//对于非循环队列，尾指针与头指针的差值就是队列长度；但是循环队列差值可能为负数，所以需要将差值加上maxsize再与maxsize求余。
	return len;
}