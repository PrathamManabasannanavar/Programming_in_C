//A simple C program to check the string of the form "xCy".
#include <stdio.h>
#define SIZE 10

int stack[SIZE], top = -1;

int pop()
{
    if(top == -1) return 0;
    return stack[top--];
}

void push(int data)
{
    if(top == SIZE-1) return;
    stack[++top] = data;
}

int isxCy(char *str)
{
    int i = 0;
    while(str[i] && str[i] != 'C')
        push(str[i++]);
    while(str[i])
    {
      if(str[++i] != pop()) 
        return 0;
    }
    return 1;
}

int main()
{
    char str[SIZE];
    printf("Enter the String\n");
    scanf("%s",str);
    if(isxCy(str))
        printf("TRUE. x is reverse of y in xCy format\n");
    else
        printf("FALSE. x is not reverse of y in xCy format\n");
    return 0;
}
