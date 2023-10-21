// A simple C program to construct and search in the Chain of Nodes
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct node
{
    int data;
    struct node *next;
} node;

node *ptr[SIZE], *temp[SIZE];

void createNode()
{
    node *new = (node *)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&new->data);
    new->next = NULL;
    int index = new->data % SIZE;
    if(!ptr[index])
    {
        ptr[index] = temp[index] = new;
        return;
    }
    temp[index]->next = new;
    temp[index] = temp[index]->next;
}

void chainOfNodes()
{
    int choice;
    node *temp[10];
    while(1)
    {
        printf("Enter 1 to add nodes\n");
        printf("Enter 0 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            createNode(ptr);
            break;
        case 0:
            printf("You exited\n\n");
            return;
        default:
            printf("Enter valid choice!!\n");
        }
    }
}

void displaychain()
{
    node *temp;
    for(int i=0; i<SIZE; i++)
    {
        temp = ptr[i];
        printf("%d) ",i);
        while(temp != NULL)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}

int searchInChain(int key)
{
    node *temp = ptr[key % SIZE];
    while(temp != NULL)
    {
        if(temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main()
{
    int key;
    chainOfNodes();
    printf("The chain is:\n");
    displaychain();
    printf("Enter the key element to be searched in the chain\n");
    scanf("%d",&key);
    if(searchInChain(key))
        printf("Element found in the Chain\n");
    else
        printf("Element was not found in the Chain\n");
    return 0;
}