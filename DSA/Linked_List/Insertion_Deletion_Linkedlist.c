// A simple C program to perform Insertion and deletion in Linkedlist
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *address;
} node;

void readLinkedlist(node **head)
{
    node *temp;
    int choice;
    while(1)
    {
        printf("Enter 1 to continue\n");
        printf("Enter 2 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        if(choice == 2)
        {
            printf("You exited\n");
            temp->address = NULL;
            return;
        }
        else if(choice != 1)
        {
            printf("Enter valid choice!!\n");
            continue;
        }

        node *new = (node *)malloc(sizeof(node));
        printf("Enter data\n");
        scanf("%d",&new->data);
        if(*head == NULL)
        {
            *head = temp = new;
            continue;
        }

        temp->address = new;
        temp = temp->address;
    }

}

void printLinkedlist(int **head)
{
    node *temp = *head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->address;
    }
    printf("\n");
}

void insertNode(node **head)
{
    node *temp = *head, *new, *prev;
    int pos;
    new = (node *)malloc(sizeof(node));
    printf("Enter data and position of the node to be inserted\n");
    scanf("%d %d",&new->data, &pos);

    while(temp != NULL)
    {
        if(pos < 0)
        {
            printf("Can't insert. Size of linkedlist is less\n");
            free(new);
            return;
        }

        else if(pos == 0)
        {
            new->address = temp;
            prev->address = new;
            return;
        }
        pos--;
        prev = temp;
        temp = temp->address;
    }
}

void deleteNode(node **head)
{
    node *temp = *head, *prev;
    int pos;
    printf("Enter the position of the node to be deleted\n");
    scanf("%d",&pos);
    while(temp != NULL)
    {
        if(pos < 0)
        {
            printf("Can't delete. Size of the linkedlist is less than specified position\n");
            return;
        }

        else if(pos == 0)
        {
            prev->address = temp->address;
            return;
        }

        prev = temp;
        temp = temp->address;
        pos--;
    }
}

int main()
{
    node *head = NULL;
    printf("Enter the elements of linkedlist\n");
    readLinkedlist(&head);
    printf("Entered elements of linkedlidt are:\n");
    printLinkedlist(&head);
    insertNode(&head);
    printf("Linkedlist after insertion is:\n");
    printLinkedlist(&head);
    deleteNode(&head);
    printf("Linkedlist after deletion is:\n");
    printLinkedlist(&head);
}