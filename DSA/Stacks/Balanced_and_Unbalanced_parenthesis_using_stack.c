// A simple C program to check the balanced parantheses
//ex : {[()]} --> balanced
//ex : {[}] -->  Unbalanced
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int stack[SIZE], top = -1;

void push(int data)
{
    if(top == SIZE-1) return;
    stack[++top] = data;
}

int pop()
{
    if(top == -1) return -1;
    return stack[top--];
}

int compare(char ch)
{
    if(ch == '}') return stack[top] == '{';
    if(ch == ')') return stack[top] == '(';
    if(ch == ']') return stack[top] == '[';
    return 0;
}

int isBalanced(char *str)
{
    for(int i=0; str[i] != '\0'; i++)
    {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[')
            push(str[i]);
        else if(str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            if(top != -1 && !compare(str[i]))
            {
                printf("mismatched parentheses\n");
                return 0;
            }
            else if(pop() == -1)
            {
                printf("Right Parentheses are more\n");
                return 0;
            }
        }
    }
    if(top != -1)
    {
        printf("Left parentheses are more\n");
        return 0;
    }
    return 1;
}


main()
{
    char exp[SIZE];
    printf("Enter the expression\n");
    scanf("%s",exp);
    if(isBalanced(exp))
        printf("Balanced\n");
    else
        printf("UnBalanced\n");
}