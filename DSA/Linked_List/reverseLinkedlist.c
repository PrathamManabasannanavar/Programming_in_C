// A simple C program to reverse a linkedlist
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;


node *createNode(node *head)
{
    head = (node *)malloc(sizeof(node));
    printf("Enter data\n");
    scanf("%d",&head->data);
    return head;
}

node *createLinkedlist(node *head)
{
    int choice;
    node *temp = NULL;
    temp = head = createNode(head);
    while(1)
    {
        printf("Enter 1 to continue\nEnter 0 to exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            temp->next = createNode(head);
            temp = temp->next;
            break;
        case 0:
            temp = NULL;
            return head;
        default:
            printf("Enter valid choice!!\n");
        }
    }
    return head;
}

void displayLinkedlist(node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

node *reverseLinkedlist(node *head)
{
    node *prev=NULL, *cur=head, *end=head;
    while(cur != NULL)
    {
        end = end->next;
        cur->next = prev;
        prev = cur;
        cur = end;
    }
    return prev;
}

main()
{
    node *head = NULL;
    head = createLinkedlist(head);
    displayLinkedlist(head);
    head = reverseLinkedlist(head);
    printf("Reversed linkedlist is:\n");
    displayLinkedlist(head);
}