//A simple C program to implement the Circular Queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

int queue[SIZE], rear = -1, front = -1, count;

void dequeue()
{
    if(count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d deleted\n", queue[front]);
    front = (front + 1)%SIZE;
    count--;
}

void enqueue(int data)
{
    if(front == -1) front = 0;
    else if(count == SIZE)
    {
        printf("Queue is Full\n");
        return;
    }
    rear = (rear+1)%SIZE;
    queue[rear] = data;
    count++;
}

void display()
{
   if(count == 0)
   {
     printf("Queue is Empty\n");
     return;
   }
   int i = front;
   printf("Queue elements are:\n");
   while(i != rear)
   {
      printf("%d -> %d\n", i, queue[i]);
      i = (i+1) % SIZE;
   }
   printf("%d -> %d\n",i, queue[i]);
}

void circularQueue()
{
    int choice, data;
    while(1)
    {
        printf("f = %d\nr = %d\n",front, rear);
        printf("Enter 1 to insert\nEnter 2 to deleted\nEnter 3 to display\nEnter 4 to exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data\n");
            scanf("%d",&data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
        printf("\n");
    }
}

main()
{
   circularQueue();
}