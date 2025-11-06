//在C++中要加这个宏定义才可以使用scanf函数
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Sequential_Stack.h"
#include "Applications_of_Sequential_Stack.h"

int main() 
{
    int choice;
    
    printf("========== Sequential Stack Applications ==========\n");  // 顺序栈应用
    
    do {
        printf("\nPlease select the function to test:\n");  // 请选择要测试的功能
        printf("1. Number Base Conversion\n");              // 进制转换
        printf("2. Infix to Postfix Expression Conversion\n");  // 中缀表达式转后缀表达式
        printf("3. Palindrome Check\n");                    // 判断回文
        printf("4. Exit\n");                                // 退出
        printf("Please enter your choice (1-4): ");         // 请输入选择 (1-4)
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer  // 清除输入缓冲区中的换行符
        
        switch(choice) 
        {
            case 1: // Number Base Conversion Test  // 进制转换测试
            {
                printf("\n--- Number Base Conversion Test ---\n");  // 进制转换测试
                int num, base;
                printf("Please enter the decimal number: ");        // 请输入要转换的十进制数
                scanf("%d", &num);
                printf("Please enter the target base (2-36): ");    // 请输入目标进制 (2-36)
                scanf("%d", &base);
                Conversion(num, base);
                break;
            }
            case 2: // Infix to Postfix Expression Test  // 中缀表达式转后缀表达式测试
            {
                printf("\n--- Infix to Postfix Expression Test ---\n");  // 中缀表达式转后缀表达式测试
                char infix[100], postfix[100];
                printf("Please enter the infix expression (e.g., (3+4)*5-6 ): ");  // 请输入中缀表达式 (例如: (3+4)*5-6 )
                fgets(infix, sizeof(infix), stdin);  // fgets is a standard input function in C for reading strings from file or standard input stream  // fgets 是 C 语言中的一个标准输入函数，用于从文件或标准输入流中读取字符串
                for(int i = 0; infix[i] != '\0'; i++) 
                {
                    if(infix[i] == '\n') 
                    {
                        infix[i] = '\0';
                        break;
                    }
                }         
                Infix_To_Postfix(infix, postfix);
                printf("Infix Expression: %s\n", infix);    // 中缀表达式
                printf("Postfix Expression: %s\n", postfix); // 后缀表达式
                break;
            }
            
            case 3: // Palindrome Check Test  // 回文判断测试
            {
                printf("\n--- Palindrome Check Test ---\n");  // 回文判断测试
                char str[100];
                printf("Please enter the string to check: ");  // 请输入要判断的字符串
                fgets(str, sizeof(str), stdin);
                // Remove newline character  // 去除换行符
                for(int i = 0; str[i] != '\0'; i++) 
                {
                    if(str[i] == '\n') 
                    {
                        str[i] = '\0';
                        break;
                    }
                }
                if(IsPalindrome(str)) 
                {
                    printf("'%s' is a palindrome!\n", str);  // 是回文
                } 
                else 
                {
                    printf("'%s' is not a palindrome!\n", str);  // 不是回文
                }
                break;
            }
            case 4:
                printf("Program exited, thank you for using!\n");  // 程序退出，谢谢使用
                break;
            default:
                printf("Invalid choice, please try again!\n");  // 无效选择，请重新输入
                break;
        }
        
    } while(choice != 4);

    return 0;
}