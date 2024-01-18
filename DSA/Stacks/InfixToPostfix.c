//A simple C program to convert Infix Expression to Postfix Expression
#include<stdio.h>
#include<ctype.h>
#define SIZE 20

int stack[SIZE], top = -1;

void push(int data)
{
    if(top == SIZE-1) return;
    stack[++top] = data;
}

int pop()
{
    if(top == -1) return 0;
    return stack[top--];
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return 0;
}

void infixToPostfix(char *str)
{
    char exp[SIZE];
    int j = 0;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i] == '(') push (str[i]);
        else if(str[i] == ')')
        {
            while(top != -1 && stack[top] != '(')  exp[j++] = pop();
            pop();
        }
        else
        {
           if(isalnum(str[i])) 
               exp[j++] = str[i];
           else if(precedence(str[i]) > precedence(stack[top]))
               push(str[i]);
           else
           {
               while(top != -1 && precedence(str[i]) >= precedence(stack[top]))
                 exp[j++] = pop();
               push(str[i]);
           }      
        }
    }
    while(top != -1) exp[j++] = pop();
    exp[j] = '\0';
    printf("Postfix Expression of %s is %s\n",str, exp);
}

main()
{
   char infix[SIZE];
   printf("Enter the infixExp :\n");
   scanf("%s",infix);
   infixToPostfix(infix);
}
   
