//A simple C program to implement the Queue using Linkedlist 
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

void display(node *head)
{
    if(!head)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is:\n");
    while(head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

node *dequeue(node *head)
{
    if(!head)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    node *temp = head->next;
    printf("%d deleted\n",head->data);
    free(head);
    return temp;
}

node *enqueue(node *head)
{
    head->next = createNode();
    return head->next;
}

node *QueueImp()
{
    node *head = NULL, *temp = NULL;
    int choice;
    while(1)
    {
        printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to display\nEnter 4 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            if(!head)
            {
                head = temp = createNode();
                break;
            }
            temp->next = enqueue(temp);
            temp = temp->next;
            break;
        case 2:
            head = dequeue(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            printf("You exited\n");
            return head;
        default:
            printf("Enter the valid choice\n");
        }
    }
}

int main()
{
    node *head = QueueImp();
    return 0;
}