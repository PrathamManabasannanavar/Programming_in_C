//A simple C program to implement the doublyLinkedlist and perform deletion operation 
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

node *deleteElement(node *head, int ele)
{
    if(!head) return NULL;
    node *cur = head;
    while(cur)
    {
        if(cur->data == ele)
            break;
        cur = cur->next;
    }
    if(!cur)
    {
        printf("Element not found!!\n");
        return head;
    }
    else if(!cur->prev)
    {
        head = cur->next;
        if(!head) return NULL;
        head->prev = cur->prev;
        return head;
    }
    else if(!cur->next)
    {
        cur->prev->next = NULL;
        return head;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);
    return head;
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
    int ele;
    printf("Enter the element to be deleted\n");
    scanf("%d",&ele);
    head = deleteElement(head, ele);
    printf("List after deletion is:\n");
    displayList(head);
}