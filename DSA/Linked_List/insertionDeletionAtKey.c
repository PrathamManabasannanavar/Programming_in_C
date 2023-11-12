//A simple C program to demonstrate the Linkedlist insertion and deletion by searching key element 
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
    newNode->next = NULL;
    printf("Enter the data\n");
    scanf("%d",&newNode->data);
    return newNode;
}

int searchData(node *head, int key)
{
    int count=1;
    while(head)
    {
        if(head->data == key)
            return count;
        head = head->next;
        count++;
    }
    return -1;
}

node *insertBeforeKey(node *head, int key, int pos)
{
    node *prev = NULL, *newNode = NULL, *temp = head;
    if(pos == 1)
    {
       newNode = createNode();
       newNode->next = head;
       return newNode;
    }
    while(head)
    {
        if(head->data == key)
        {
            newNode = createNode();
            prev->next = newNode;
            newNode->next = head;
            return temp;
        }
        prev = head;
        head = head->next;
    }
    return head;
}

node *insertAfterKey(node *head, int key)
{
    node *prev = NULL, *newNode=NULL;
    while(head)
    {
        prev = head;
        head = head->next;
        if(prev->data == key)
        {
            newNode = createNode();
            prev->next = newNode;
            newNode->next = head;
            return head;
        }
    }
    return head;
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

node *linkedListImp(node *head)
{
    node *temp=NULL;
    int choice;
    while(1)
    {
        printf("Enter 1 to create node\nEnter 2 to exit\n");
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
            temp->next = createNode();
            temp = temp->next;
            break;

        case 2:
            return head;
        }
    }
    return head;
}

main()
{
    int choice, key, pos;
    node *head=NULL;
    head = linkedListImp(head);
    while(1)
    {
        printf("\nEnter 1 to search the element\nEnter 2 to display\nEnter 3 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the key to be searched\n");
            scanf("%d",&key);
            pos = searchData(head, key);
            if(pos == -1)
            {
                printf("key not found!!\n");
                continue;
            }
            printf("key found at %d position\n",pos);
            printf("Enter 1 to insertBeforeKey\nEnter 2 to insertAfterKey\n");
            printf("Enter your choice\n");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                head = insertBeforeKey(head, key, pos);
                break;
            case 2:
                insertAfterKey(head, key);
                break;
            }
        case 2:
            printf("Linkedlist is:\n");
            displayList(head);
            break;
        case 3:
            printf("Exited\n");
            exit(0);
        default:
            printf("Enter the valid choice!!\n");
        }
    }
}