// A simple C program to implement stack using Linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *address;
} node;

node *HEAD;

/*
void readLinkedlist(node **head)
{
    node *temp;
    int choice;
    while(1)
    {
        printf("Enter 1 to continue\nEnter 0 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);

        if(choice == 0)
        {
            printf("You exited\n");
            break;
        }
        else if(choice != 1)
        {
            printf("Enter valid choice!!\n");
            continue;
        }

        node *new = (node *)malloc(sizeof(node));
        printf("Enter the data\n");
        scanf("%d",&new->data);
        if(*head == NULL)
        {
            *head = temp = new;
            continue;
        }
        temp->address = new;
        temp = temp->address;
    }
    temp->address = NULL;
}
*/

void printLinkedlist(node **head)
{
    node *temp = *head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->address;
    }
    printf("\n");
}

void pop()
{
    node *temp = HEAD;
    HEAD = HEAD->address;
    free(temp);
}

void push()
{
    node *new = (node *)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&new->data);
    new->address = HEAD;
    HEAD = new;
}

int stackImplement()
{
    int choice;
    while(1)
    {
        printf("Enter 1 to push\nEnter 2 to pop\nEnter 3 to Reverse Stack\nEnter 4 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        if(choice == 1)
        {
            push();
        }
        else if(choice == 2)
        {
            pop();
        }
        else if(choice == 3)
        {
            printf("Stack is:\n");
            printLinkedlist(&HEAD);
        }
        else if(choice == 4)
        {
            printf("You exited\n");
            break;
        }
        else
        {
            printf("Enter valid choice!!\n");
            continue;
        }
    }
}


main()
{
    //node *head = NULL;
    //printf("Enter elements of Linked list\n");
    //readLinkedlist(&head);
    //printf("Entered elements of Linked list\n");
    //printLinkedlist(&head);
    stackImplement();
}