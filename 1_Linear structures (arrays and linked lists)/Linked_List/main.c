#define _CRT_SECURE_NO_WARNINGS 1 // Tell compiler not to generate security warnings, allow using traditional C standard library functions without compiler warnings or errors
//主函数调用使用
#include<stdio.h>
#include"Singly_Linked_List.h"

int main()
{   
    SLTNode* temp = NULL;
    SLTNode* FindOut = NULL;
    temp=CreateListFromInput();
    printf("User-created singly linked list is: "); // 用户所自己创建的单向链表为：
    SListPrint(temp);

    FindOut=SListFind(temp, 4);
    if (FindOut != NULL)
    {
        printf("Found value %d in the singly linked list\n", FindOut->data); // 经查找该%d值在单向链表中
    }
    else
    {
        printf("Value not found in the singly linked list\n"); // 经查找该值不在单向链表中
    }
    SListInsert(&temp, FindOut, 16);
    printf("Linked list after inserting node:\n"); // 插入节点后的链表为：
    SListPrint(temp);

    SListErese(&temp, FindOut);
    printf("Linked list after deleting node:\n"); // 删除节点后的链表为:
    SListPrint(temp);

     // 添加暂停代码
    printf("\nPress Enter to exit..."); // 按回车退出
    getchar();  // 等待用户按回车
    getchar();  // 第二个getchar()用于等待用户按键（因为第一个可能被之前的输入缓冲消耗）
    return 0;
}