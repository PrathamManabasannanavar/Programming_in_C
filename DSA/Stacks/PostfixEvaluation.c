// A simple C program to evaluate Postfix expression
//ex:5 2 4 * + 7 -  ---> 6
#include<stdio.h>
#include<ctype.h>
#define SIZE 50

int stack[SIZE], top = -1;

void push(int data)
{
    if(top == SIZE-1)
        return;
    stack[++top] = data;
}

int pop()
{
    if(top == -1)
        return -1;
    return stack[top--];
}

int result(char ch, int num1, int num2)
{
    switch(ch)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    default :
        return 0;
    }
}

int EvaluatePostfix(char *str)
{
    char ch;
    int num1, num2, start, end, no;
    for(int i=0; str[i]!='\0'; i++)
    {
        ch = str[i];
        if(isdigit(ch))
        {
            no = 0;
            while(isdigit(str[i]))
                no = no * 10 + (str[i++] - '0');
            push(no);
        }
        else if((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
        {
            num2 = pop();
            num1 = pop();
            push(result(ch, num1, num2));
        }
    }
    return pop();
}

main()
{
    char str[SIZE];
    printf("Enter the Postfix expression:\n");
    fgets(str, SIZE, stdin);
    printf("Evaluated Postfix expression:\n%d\n",EvaluatePostfix(str));
}