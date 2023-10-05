// A simple C program to check whether given string is Palindrome or not?
#include<stdio.h>
#define SIZE 50

char stack[SIZE];
int top = -1;

char pop()
{
    return stack[top--];
}

void push(char ch)
{
    if(top >= SIZE)
        return;
    stack[++top] = ch;
}

int isPalindrome(char *str)
{
    int n = strlen(str), i;

    if(n&1)
    {
        for(i=0; i<n/2; i++)
            push(str[i]);
        i++;
        while(i < n)
            if((top > -1) && (pop() != str[i++]))
                return 0;
    }
    else
    {
        for(i=0; i<n/2; i++)
            push(str[i]);
        while(i<n)
            if(pop() != str[i++])
                return 0;
    }
    return 1;
}

main()
{
    char str[SIZE];
    printf("Enter the string\n");
    scanf("%s",str);
    if(isPalindrome(str))
        printf("It is a Palindrome\n");
    else
        printf("It is not a Palindrome\n");
}