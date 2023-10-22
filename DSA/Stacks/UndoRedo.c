//A simple C program to perform Undo and Redo to some extent using 2 Stacks
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

typedef struct STACK
{
    int top;
    char stack[SIZE];
} STACK;

void push(STACK *s, char data)
{
    s->stack[++s->top] = data;
}

char pop(STACK *s)
{
    return s->stack[s->top--];
}

void display(STACK *s)
{
    for(int i=0; i<=s->top; i++)
        printf("%c",s->stack[i]);
    printf("\n");
}

void copyToStack(STACK *s, char *str)
{
    int i;
    for(i=0; str[i]!='\0'; i++)
        if(str[i] != '\n' && s->top != SIZE-1)
            push(s, str[i]);
}

void UndoRedo(char *str)
{
    STACK s, temp;
    s.top = temp.top = -1;
    copyToStack(&s, str);
    int choice;
    while(1)
    {
        printf("Enter 0 to exit\nEnter 1 to Undo\nEnter 2 to Redo\nEnter 3 to display\nEnter 4 to insert text\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(s.top != -1 && temp.top != SIZE-1)
            {
                push(&temp, pop(&s));
                display(&s);
            }
            else
                printf("Can't Undo\n");
            break;
        case 2:
            if(s.top != SIZE-1 && temp.top != -1)
            {
                push(&s, pop(&temp));
                display(&s);
            }
            else
                printf("Can't Redo\n");
            break;
        case 3:
            if(s.top == -1)
            {
                printf("\n");
                continue;
            }
            display(&s);
            break;
        case 4:
            printf("Enter the text to be inserted\n");
            getchar();
            gets(str, SIZE, stdin);
            copyToStack(&s, str);
            break;
        case 0:
            exit(0);
        default:
            printf("Enter valid choice!!\n");
        }
    }
}

main()
{
    char str[SIZE];
    printf("Enter the text\n");
    fgets(str, SIZE, stdin);
    UndoRedo(str);
}