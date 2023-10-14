// A simple C program to check the balanced parentheses 
#include<stdio.h>
#define SIZE 50

typedef struct stack
{
    int top;
    char stk[SIZE];
} stack;

void push(stack *s, int data)
{
    if(s->top == SIZE-1)
        return;
    s->stk[++s->top] = data;
}

int pop(stack *s)
{
    if(s->top == -1)
        return -1;
    return s->stk[s->top--];
}

int checkParentheses(stack *s, char ch)
{
    if(ch == ')' && s->stk[s->top] == '(')
        return 1;
    else if(ch == '}' && s->stk[s->top] == '{')
        return 1;
    else if(ch == ']' && s->stk[s->top] == '[')
        return 1;
    else
        return 0;
}

int isBalanced(stack *s, char *str)
{
    int count = 0, balanced = 1;
    char ch;
    for(int i=0; str[i]!='\0'; i++)
    {
        ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[')
        {
            push(s, ch);
            count++;
        }
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            count--;
            if((s->top != -1) && checkParentheses(s, ch))
                pop(s);
            else
                balanced = 0;
        }
    }
    if(count < 0)
    {
        printf("Right parentheses are more\n");
        return 0;
    }
    else if(count > 0)
    {
        printf("left parentheses are more\n");
        return 0;
    }
    printf("Parentheses count is equal\n");
    return balanced;
}

int main()
{
    stack s;
    s.top = -1;
    char str[SIZE];
    printf("Enter the string\n");
    fgets(str, SIZE, stdin);
    if(isBalanced(&s, str))
        printf("Balanced\n");
    else
        printf("Unbalanced\n");
    return 0;   
}