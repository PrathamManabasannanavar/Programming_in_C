//A simple C program to implement the 3 priority queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

typedef struct QUEUE
{
    int queue[SIZE], front, rear, size;
} QUEUE;

QUEUE q1, q2, q3;

int isEmpty(QUEUE *q)
{
    if(q->rear == -1 || q->front > q->rear)
        return 1;
    return 0;
}

QUEUE *selectQueue()
{
    if(q1.size-1 > q1.rear)
        return &q1;
    else if(q2.size-1 > q2.rear)
        return &q2;
    else if(q3.size-1 > q3.rear)
        return &q3;
    return NULL;
}

void enqueue(int data)
{
    QUEUE *q = selectQueue();
    if(!q)
    {
        printf("Queue is full\n");
        return;
    }
    q->queue[++q->rear] = data;
}

void dequeue(QUEUE *q)
{
    printf("%d poped\n",q->queue[q->front++]);
}

void display()
{
    int i;
    if(!isEmpty(&q1))
        for(i=0; i<=q1.rear; i++)
            printf("%d ",q1.queue[i]);
    if(!isEmpty(&q2))
        for(i=0; i<=q2.rear; i++)
            printf("%d ",q2.queue[i]);
    if(!isEmpty(&q3))
        for(i=0; i<=q3.rear; i++)
            printf("%d ",q3.queue[i]);
    printf("\n");        
}

void ThreePriorityImp()
{
    int choice, ele;
    while(1)
    {
        printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to display\nEnter 4 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data\n");
            scanf("%d",&ele);
            enqueue(ele);
            break;
        case 2:
            if(!isEmpty(&q1))
                dequeue(&q1);
            else if(!isEmpty(&q2))
                dequeue(&q2);
            else if(!isEmpty(&q3))
                dequeue(&q3);
            else
                printf("Queue is empty\n");
            break;
        case 3:
            display();
            break;
        case 4:
            printf("You exited\n");
            exit(0);
        default:
            printf("Enter the valid choice\n");
        }
    }
}

main()
{
    q1.rear = q2.rear = q3.rear = -1;
    q1.front = q2.front = q3.front = 0;
    q1.size = q2.size = q3.size = SIZE;
    ThreePriorityImp();
}