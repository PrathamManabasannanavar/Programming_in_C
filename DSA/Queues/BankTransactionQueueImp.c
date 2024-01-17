/*In a bank, the customers entering for the cash transactions are made to sit in a row of chairs.
Every customer entering for the transaction gets a token and he/she sits on a chair beside 
the customer at the tail end. The customer who is sitting at the initial chair in that row will 
be called for the transaction and is the first to leave the chair. Write C program to simulate 
this scenario.*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int queue[SIZE], rear = -1, chairs, count;

void enqueue()
{
    if(rear == chairs-1)
    {
        printf("Chairs are occupied. Please wait\n");
        return;
    }
    queue[++rear] = ++count;
    printf("Person %d sat on %d chair\n",count, rear+1);
}

void dequeue()
{
    if(rear == -1)
    {
        printf("Chairs are already empty\n");
        return;
    }
    printf("Person %d got up from 1st chair\n",queue[0]);
    for(int i=0; i<rear; i++)
       queue[i] = queue[i+1];
    rear--;
}

void display()
{
    if(rear == -1)
    {
        printf("Chairs are empty\n");
        return;
    }
    for(int i=0; i<=rear; i++)
        printf("Chair %d --> Person %d\n", queue[i], i+1);
    printf("\n");
}

main()
{
    int choice;
    printf("Enter the no of chairs\n");
    scanf("%d",&chairs);
    while(1)
    {
        printf("Enter 1 to sit on the chair\nEnter 2 for the 1st person to leave 1st chair\nEnter 3 to display the number of people sitting on the chair\nEnter 4 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("You exited\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
        printf("\n");
    }
}