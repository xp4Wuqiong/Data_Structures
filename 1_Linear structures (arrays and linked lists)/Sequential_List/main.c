//在C++中要加这个宏定义才可以使用scanf函数
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "squential_list.h"

int main()
{
    int caozuo=1;  // 操作选项

    // 定义顺序表
    SqList L;
    ElemType e, pre_e, next_e, cur_e;  // 当前元素、前驱元素、后继元素
    int i, pos;  // 位置变量
    Status status;  // 状态返回值

    // 初始化顺序表（但还未构造）
    L.elem = NULL;
    L.length = 0;
    L.Listsize = 0;

    while (caozuo != 0)
    {
        printf("\n------ Sequential List Operation Menu ------\n");  // 顺序表操作菜单
        printf("1. Create Sequential List\n");                      // 构造顺序表
        printf("2. Traverse Sequential List\n");                    // 遍历顺序表
        printf("3. Clear Sequential List\n");                       // 清空顺序表
        printf("4. Destroy Sequential List\n");                     // 销毁顺序表
        printf("5. Get the i-th element and store in e\n");         // 取顺序表的第i个数据元素并存入e中
        printf("6. Find element e in the list, return position if exists\n");  // 在顺序表中查找e，存在则返回位序
        printf("7. Find predecessor of cur_e in the list\n");       // 在顺序表中查找cur_e的前驱
        printf("8. Find successor of cur_e in the list\n");         // 在顺序表中查找cur_e的后继
        printf("9. Insert element e to become the i-th element\n"); // 在顺序表中插入数据元素e，使之成为第i个数据元素
        printf("0. Exit program\n");                                // 退出程序
        printf("Please enter the operation you need to complete (input integer 0~9):\n");  // 请输入您所需要完成的操作（从键盘输入整数0~9）

        scanf("%d", &caozuo);

        while (caozuo > 9 || caozuo < 0)
        {
            printf("Invalid input, please re-enter: ");  // 输入无效值，请重新输入
            scanf("%d", &caozuo);
        }

        switch (caozuo)
        {
        case 0:
            printf("Program exited, goodbye!\n");  // 程序退出，再见
            break;

        case 1:
            if (L.elem != NULL) 
            {
                printf("Sequential list already exists, destroy and recreate? (1-Yes/0-No): ");  // 顺序表已存在，先销毁再重新构造？（1-是/0-否）
                int choice;
                scanf("%d", &choice);
                if (choice == 1) 
                {
                    DestroyList(&L);  // 传递指针
                }
                else 
                {
                    printf("Create operation cancelled\n");  // 取消构造操作
                    break;
                }
            }
            status = InitList(&L);  // 传递指针
            if (status == OK) 
            {
                printf("Sequential list created successfully!\n");  // 顺序表构造成功

                // 可以添加一些初始数据
                printf("Add initial data? (1-Yes/0-No): ");  // 是否添加初始数据？（1-是/0-否）
                int add_data;
                scanf("%d", &add_data);
                if (add_data == 1) 
                {
                    printf("Enter number of students to add: ");  // 请输入要添加的学生数量
                    int count;
                    scanf("%d", &count);
                    for (int k = 0; k < count; k++) 
                    {
                        ElemType student;
                        printf("Enter student ID for student %d: ", k + 1);  // 请输入第%d个学生的学号
                        scanf("%s", student.sno);
                        printf("Enter name for student %d: ", k + 1);        // 请输入第%d个学生的姓名
                        scanf("%s", student.name);
                        printf("Enter age for student %d: ", k + 1);         // 请输入第%d个学生的年龄
                        scanf("%d", &student.age);
                        ListInsert(&L, L.length + 1, student);  // 指针传递
                    }
                }
            }
            else 
            {
                printf("Sequential list creation failed!\n");  // 顺序表构造失败
            }
            break;

        case 2:
            if (L.elem == NULL) 
            {
                printf("Sequential list not created, please select option 1 first!\n");  // 顺序表未构造，请先选择操作1构造顺序表
            }
            else if (ListEmpty(L)==OK) 
            {
                printf("Sequential list is empty!\n");  // 顺序表为空
            }
            else 
            {
                printf("Sequential list contents:\n");  // 顺序表内容
                ListTraverse(L);
            }
            break;

        case 3:
            if (L.elem == NULL) 
            {
                printf("Sequential list not created, please select option 1 first!\n");  // 顺序表未构造，请先选择操作1构造顺序表
            }
            else 
            {
                status = ClearList(&L);
                if (status == OK) 
                {
                    printf("Sequential list cleared successfully!\n");  // 顺序表清空成功
                }
            }
            break;

        case 4:
            if (L.elem == NULL) {
                printf("Sequential list not created or already destroyed!\n");  // 顺序表未构造或已销毁
            }
            else {
                status = DestroyList(&L);
                if (status == OK) 
                {
                    printf("Sequential list destroyed successfully!\n");  // 顺序表销毁成功
                }
            }
            break;

        case 5:
            if (L.elem == NULL) 
            {
                printf("Sequential list not created, please select option 1 first!\n");  // 顺序表未构造，请先选择操作1构造顺序表
            }
            else if (ListEmpty(L)) 
            {
                printf("Sequential list is empty!\n");  // 顺序表为空
            }
            else {
                printf("Enter position to get element (1-%d): ", L.length);  // 请输入要获取的元素位置(1-%d)
                scanf("%d", &i);
                status = GetElem(L, i, &e);
                if (status == OK) 
                {
                    printf("Element at position %d: ID:%s Name:%s Age:%d\n",  // 第%d个元素：学号:%s 姓名:%s 年龄:%d
                        i, e.sno, e.name, e.age);
                }
                else 
                {
                    printf("Failed to get element, position out of range!\n");  // 获取元素失败，位置超出范围
                }
            }
            break;

        case 6:
            if (L.elem == NULL) 
            {
                printf("Sequential list not created, please select option 1 first!\n");  // 顺序表未构造，请先选择操作1构造顺序表
            }
            else if (ListEmpty(L)) 
            {
                printf("Sequential list is empty!\n");  // 顺序表为空
            }
            else {
                printf("Enter student information to find:\n");  // 请输入要查找的学生信息
                ElemType target;
                printf("Student ID: ");  // 学号
                scanf("%s", target.sno);
                printf("Name: ");        // 姓名
                scanf("%s", target.name);
                printf("Age: ");         // 年龄
                scanf("%d", &target.age);

                pos = LocateElem(L, target);
                if (pos > 0) 
                {
                    printf("Student found at position: %d\n", pos);  // 找到该学生，位置为：%d
                }
                else 
                {
                    printf("Student not found!\n");  // 未找到该学生
                }
            }
            break;

        case 7:
            if (L.elem == NULL) 
            {
                printf("Sequential list not created, please select option 1 first!\n");  // 顺序表未构造，请先选择操作1构造顺序表
            }
            else if (ListEmpty(L)) 
            {
                printf("Sequential list is empty!\n");  // 顺序表为空
            }
            else {
                printf("Enter current student information:\n");  // 请输入当前学生信息
                printf("Student ID: ");  // 学号
                scanf("%s", cur_e.sno);
                printf("Name: ");        // 姓名
                scanf("%s", cur_e.name);
                printf("Age: ");         // 年龄
                scanf("%d", &cur_e.age);

                status = PriorElem(L, cur_e, &pre_e);
                if (status == OK) 
                {
                    printf("Predecessor element: ID:%s Name:%s Age:%d\n",  // 前驱元素：学号:%s 姓名:%s 年龄:%d
                        pre_e.sno, pre_e.name, pre_e.age);
                }
                else 
                {
                    printf("Failed to find predecessor! Could be first element or element not found\n");  // 查找前驱失败！可能是第一个元素或元素不存在
                }
            }
            break;

        case 8:
            if (L.elem == NULL) 
            {
                printf("Sequential list not created, please select option 1 first!\n");  // 顺序表未构造，请先选择操作1构造顺序表
            }
            else if (ListEmpty(L)) 
            {
                printf("Sequential list is empty!\n");  // 顺序表为空
            }
            else {
                printf("Enter current student information:\n");  // 请输入当前学生信息
                printf("Student ID: ");  // 学号
                scanf("%s", cur_e.sno);
                printf("Name: ");        // 姓名
                scanf("%s", cur_e.name);
                printf("Age: ");         // 年龄
                scanf("%d", &cur_e.age);

                status = NextElem(L, cur_e, &next_e);
                if (status == OK) 
                {
                    printf("Successor element: ID:%s Name:%s Age:%d\n",  // 后继元素：学号:%s 姓名:%s 年龄:%d
                        next_e.sno, next_e.name, next_e.age);
                }
                else 
                {
                    printf("Failed to find successor! Could be last element or element not found\n");  // 查找后继失败！可能是最后一个元素或元素不存在
                }
            }
            break;

        case 9:
            if (L.elem == NULL) 
            {
                printf("Sequential list not created, please select option 1 first!\n");  // 顺序表未构造，请先选择操作1构造顺序表
            }
            else {
                printf("Enter insertion position (1-%d): ", L.length + 1);  // 请输入要插入的位置(1-%d)
                scanf("%d", &i);
                printf("Enter student information:\n");  // 请输入学生信息
                ElemType new_student;
                printf("Student ID: ");  // 学号
                scanf("%s", new_student.sno);
                printf("Name: ");        // 姓名
                scanf("%s", new_student.name);
                printf("Age: ");         // 年龄
                scanf("%d", &new_student.age);

                status = ListInsert(&L, i, new_student);
                if (status == OK) {
                    printf("Insertion successful!\n");  // 插入成功
                }
                else {
                    printf("Insertion failed!\n");  // 插入失败
                }
            }
            break;

        default:
            printf("Invalid input, please reselect!\n");  // 输入无效值，请重新选择
            break;
        }

        // 如果不是退出操作，暂停一下让用户看到结果
        if (caozuo != 0) 
        {
            printf("\nPress Enter to continue...");  // 按回车键继续
            getchar();  // 清除之前的换行符
            getchar();  // 等待用户按回车
        }
    }

    // 程序退出前销毁顺序表
    if (L.elem != NULL) 
    {
        DestroyList(&L);
    }

    return 0;
}