//A simple C program to Concatenate 2 Linked lists
#include<stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;


node *createNode()
{
    node *new = (node *)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&new->data);
    new->next = NULL;
    return new;
}

void displayList(node *head)
{
    while(head)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node *concatenateList(node *head1, node *head2)
{
    node *temp=head1;
    if(!head1) return head2;
    while(temp->next)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

node *linkedlistImp(node *head)
{
    int choice;
    node *temp=NULL;
    while(1)
    {
        printf("Enter 1 to insert\nEnter 2 to exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(head == NULL)
            {
                head = temp = createNode();
                break;
            }
            temp->next = createNode();
            temp = temp->next;
            break;
        case 2:
            if(!temp) return NULL;
            temp->next = NULL;
            return head;
        default:
            printf("Enter the Valid choice\n");
        }
    }
    return head;
}

main()
{
    node *head1 = NULL, *head2 = NULL;
    printf("Enter Linkedlist 1 contents:\n");
    head1 = linkedlistImp(head1);
    printf("Enter Linkedlist 2 contents:\n");
    head2 = linkedlistImp(head2);
    printf("\nLinkedlist 1: ");
    displayList(head1);
    printf("Linkedlist 2: ");
    displayList(head2);
    node *head = concatenateList(head1, head2);
    printf("\nConcatenated list is:\n");
    displayList(head);
}