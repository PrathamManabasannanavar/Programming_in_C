//A simple C program to implement the doublyLinkedlist and perform Insertion operation
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;


node *createNode()
{
    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&newNode->data);
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void displayList(node *head)
{
    while(head)
    {
        //printf("%u %d %u\n", head->prev,head->data, head->next);
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node *insert(node *head, int pos)
{
    if(!head) return NULL;
    node *cur=head, *newNode;
    while(--pos && cur)
    {
        if(pos == 1)
        {
            newNode = createNode();
            newNode->prev = cur;
            newNode->next = cur->next;
            cur->next = newNode;
            if(cur->next)
                cur->next->prev = newNode;
            return head;
        }
        cur = cur->next;
    }
    if(!cur)
    {
        printf("Invalid position. Can't insert\n");
        return head;
    }
    newNode = createNode();
    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;
    return newNode;
}


node *doublyLinkedlist()
{
    node *head = NULL, *cur, *prev=NULL;
    int choice;
    while(1)
    {
        printf("Enter 1 to insert the node\nEnter 2 to exit\nEnter 3 to displayList\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(!head)
            {
                head = cur = createNode();
                break;
            }
            cur->next = createNode();
            cur->prev = prev;
            prev = cur;
            cur = cur->next;
            break;
        case 2:
            if(!head)  return NULL;
            cur->prev = prev;
            return head;
        case 3:
            cur->prev = prev;
            displayList(head);
            break;
        default:
            printf("Enter Valid choice\n");
        }
    }
}

main()
{
    node *head = doublyLinkedlist();
    int pos;
    printf("Enter the position to be inserted\n");
    scanf("%d",&pos);
    head = insert(head, pos);
    printf("Linkedlist is:\n");
    displayList(head);
}