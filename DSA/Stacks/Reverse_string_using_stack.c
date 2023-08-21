//A simple C program to reverse a string using stack
#include<stdio.h>

char stack[30];
int top = -1, len;

void push(char);
char pop();
main()
{
    char str[30];
    int i;
    printf("Enter the string\n");
    scanf("%s",str);
    len = strlen(str);
    for(i=0; str[i]!='\0'; i++)
    {
        push(str[i]);
    }
    printf("string before reversing is : %s\n",str);

    printf("Reversed string is:\n");
    for(int i=0; i<len; i++)
        printf("%c",pop());
    printf("\n");
}

char pop()
{
    if(top < 0)
    {
        printf("Stack is empty. Can't pop!!\n");
        return 0;
    }
    top--;
    return stack[top+1];
}

void push(char ch)
{
    if(top > len-1)
    {
        printf("You have reached end of the stack. Can't Push!!\n");
        return;
    }
    stack[++top] = ch;
}
