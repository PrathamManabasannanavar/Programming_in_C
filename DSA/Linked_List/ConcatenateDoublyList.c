// A simple C program to concatenate 2 doubly LinkedList
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *createNode()
{
    node *head = (node *)malloc(sizeof(node));
    head->prev = head->next = NULL;
    printf("Enter data\n");
    scanf("%d",&head->data);
    return head;
}

void displayList(node *head)
{
    if(! head )
    {
        printf("List is empty\n");
        return;
    }
    printf("List is:\n");
    while(head)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node *concatenateList(node *head1, node *head2)
{
    if(!head1) return head2;
    if(!head2) return head1;
    node *first = head1;
    while(head1->next)
        head1 = head1->next;
    head1->next = head2;
    head2->prev = head1;
    return first;
}

void displayConcatenatedList(node *head)
{
    printf("From left->right\n");
    while(head->next)
    {
        printf("%d->",head->data);
        head = head->next;
    }
    printf("%d->NULL\n",head->data);
    printf("From right->left\n");
    printf("NULL");
    while(head)
    {
        printf("<-%d",head->data);
        head = head->prev;
    }
    printf("\n");
}

node *DoublyListImp()
{
    node *head = NULL, *temp = NULL;
    int choice;
    while(1)
    {
        printf("Enter 1 to add nodes\nEnter 2 to exit\nEnter 3 to display\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(!head)
            {
                head = temp = createNode();
                break;
            }
            temp->next = createNode();
            temp->next->prev = temp;
            temp = temp->next;
            break;
        case 2:
            printf("You exited\n\n");
            return head;
        case 3:
            displayList(head);
            break;
        default:
            printf("Enter the valid choice\n");
        }
    }
}

int main()
{
    printf("Enter the 1st List:\n");
    node *head1 = DoublyListImp();
    printf("Enter the 2nd List:\n");
    node *head2 = DoublyListImp();
    if(!head1 && !head2)
    {
       printf("List is empty\n");
       return 0;
    }
    node *head = concatenateList(head1, head2);
    displayConcatenatedList(head);
    return 0;
}