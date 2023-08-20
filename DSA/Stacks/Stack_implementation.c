// A simple C program to implement the stack
#include<stdio.h>
#include<stdlib.h>

int *stack, n;
int top = -1;

void pop();
void push(int);
int peek();
void display_stack();

main()
{
    int choice, no;
    printf("Enter the size of stack\n");
    scanf("%d",&n);
    stack = (int *)malloc(n * sizeof(int));
    do
    {
        printf("Enter 1 to PUSH\nEnter 2 to POP\nEnter 3 to Peek\nEnter 4 to display stack\nEnter 5 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter element to be pushed\n");
            scanf("%d",&no);
            push(no);
            printf("%d pushed\n",no);
            continue;
        case 2:
            pop();
            continue;
        case 3:
            printf("Element in top position is %d\n",peek());
            continue;
        case 4:
            display_stack();
            continue;
        case 5:
            printf("You exited!!\n");
            exit(0);
        default:
            printf("Enter valid choice!!\n");
            continue;
        }
    } while(choice != 5);
}

void pop()
{
    if(top < 0)
    {
        printf("Stack is empty. Can't pop!!\n");
        return;
    }
    printf("Element %d poped\n",stack[top]);
    stack[top] = 0;
    top--;
}

void push(int no)
{
    if(top > n-1)
    {
        printf("You have reached end of the stack. Can't Push!!\n");
        return;
    }
    stack[++top] = no;
}

int peek()
{
    if(top < 0)
    {
        printf("Stack is empty. Can't Peek!!\n");
        return 0;
    }
    return stack[top];
}

void display_stack()
{
    int end = 0;
    printf("stack is : ");
    while(end <= top)
        printf("%d ",stack[end++]);
    printf("\n");
}