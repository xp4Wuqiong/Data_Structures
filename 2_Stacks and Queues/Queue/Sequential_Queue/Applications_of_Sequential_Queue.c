#include "Applications_of_Sequential_Queue.h"


// 初始化银行系统
BankQueueSystem* InitBankSystem(int capacity) 
{
    BankQueueSystem *bank = (BankQueueSystem*)malloc(sizeof(BankQueueSystem));
    bank->vipQueue = InitQueue(capacity);// VIP 队列
    bank->regularQueue = InitQueue(capacity);// 普通队列
    bank->capacity = capacity;// 队列容量
    return bank;
}

// 客户入队（isVIP = 1 表示VIP）
void EnqueueCustomer(BankQueueSystem *bank, int customer_id, int isVIP) {
    Status flag;
    if (isVIP) {
        flag = EnQueue(bank->vipQueue, customer_id);
        if (flag == OK)
            printf("VIP客户 %d 已加入VIP队列\n", customer_id);
        else
            printf("VIP队列已满，无法添加新客户\n");
    } else {
        flag = EnQueue(bank->regularQueue, customer_id);
        if (flag == OK)
            printf("普通客户 %d 已加入普通队列\n", customer_id);
        else
            printf("普通队列已满，无法添加新客户\n");
    }
}

// 客户出队（优先服务VIP）
void DequeueCustomer(BankQueueSystem *bank) {
    int customer_id;
    if (QueueLength(bank->vipQueue) > 0) {
        DeQueue(bank->vipQueue, &customer_id);
        printf("正在服务 VIP 客户：%d\n", customer_id);
    } else if (QueueLength(bank->regularQueue) > 0) {
        DeQueue(bank->regularQueue, &customer_id);
        printf("正在服务 普通客户：%d\n", customer_id);
    } else {
        printf("没有客户需要服务\n");
    }
}

// 显示两个队列状态
void DisplayQueues(BankQueueSystem *bank) {
    printf("VIP队列: ");
    print(bank->vipQueue);
    printf("普通队列: ");
    print(bank->regularQueue);
    printf("\n");
}