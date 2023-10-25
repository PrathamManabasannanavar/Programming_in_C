//A simple C program to implement Priority Queue using Linear Queue 
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

int queue[SIZE], rear=-1, front=-1;

void enqueue(int data)
{
    if(rear == -1 && front == -1)
    {
        rear = 0, front = 0;
        queue[rear] = data;
        return;
    }
    int i = rear;
    while(i >= 0 && queue[i] > data)
        queue[i+1] = queue[i], i--;
    queue[i+1] = data, rear++;
}

int dequeue()
{
    return queue[front++];
}

void displayQueue()
{
    if(front != rear)
    {
        printf("Priority Queue is:\n");
        for(int i=front; i<=rear; i++)
            printf("%d ", queue[i]);
        printf("\n"); return;
    }
        printf("Queue is empty\n");
}

void PriorityQueue()
{
    int choice, ele;
    while(1)
    {
        printf("rear = %d\nfront = %d\n", rear, front);
        printf("Enter 0 to exit\n");
        printf("Enter 1 to insert\n");
        printf("Enter 2 to delete\n");
        printf("Enter 3 to display\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            printf("You exited\n");
            exit(0);
        case 1:
            if(rear >= SIZE-1)
            {
                printf("Queue is full\n");
                continue;
            }
            printf("Enter the element to be inserted\n");
            scanf("%d",&ele);
            enqueue(ele);
            break;
        case 2:
            if(front >= rear && front != 0)
            {
                printf("Queue underflow\n");
                continue;
            }
            printf("%d poped\n",dequeue());
            break;
        case 3:
            displayQueue();
            break;
        default:
            printf("Enter valid choice\n");
        }
    }
}

main()
{
    PriorityQueue();
}