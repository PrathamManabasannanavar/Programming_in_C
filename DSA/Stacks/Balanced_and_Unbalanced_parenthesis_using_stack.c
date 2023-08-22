// A simple C program to check the balanced parantheses
//ex : {[()]} --> balanced
//ex : {[}] -->  Unbalanced
#include<stdio.h>

#define size 50

int top = -1;
char stack[size];

char pop();
void push(char);
int check_parentheses(char *);

main()
{
    char str[size];
    printf("Enter the string\n");
    fgets(str, size, stdin);

    if( check_parentheses(str) == 1)
        printf("Balanced\n");
    else
        printf("UnBalanced\n");
}

char pop()
{
    if(top < 0)
        return '\0';
    top--;
    return stack[top+1];
}

void push(char ch)
{
    if(top > size)
        return;
    stack[++top] = ch;
}

int check_parentheses(char *str)
{
    for(int i=0; str[i] != '\0'; i++)
    {
        // storing open parentheses in stack
        if(str[i] == '{')
            push('{');
        else if(str[i] == '[')
            push('[');
        else if(str[i] == '(')
            push('(');
        // checking for appropriate closed parentheses
        else if(str[i] == ')' && stack[top] == '(')
            pop();
        else if(str[i] == ']' && stack[top] == '[')
            pop();
        else if(str[i] == '}' && stack[top] == '{')
            pop();
    }

    if(top == -1)
        return 1;
    else
        return 0;
}