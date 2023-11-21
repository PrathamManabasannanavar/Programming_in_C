//A simple C program to implement the Circular singly Linkedlist 
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode()
{
    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    return newNode;
}

void displayList(node *tail)
{
    if(!tail)
    {
        printf("NULL\n");
        return;
    }
    node *head = tail->next;
    while(head != tail)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("%d\n",head->data);
}

node *circularListImp()
{
    int choice;
    node *tail = NULL, *temp = NULL;
    while (1)
    {
        printf("Enter 1 to insert nodes\nEnter 2 to exit\nEnter 3 to display\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch ( choice )
        {
        case 1:
            if(!tail)
            {
                tail = createNode();
                tail->next = tail;
                break;
            }
            temp = createNode();
            temp->next = tail->next;
            tail->next = temp;
            tail = temp;
            break;
        case 2:
            if(!tail) return NULL;
            return tail;
        case 3:
            displayList(tail);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}

main()
{
   node *head = circularListImp();
}