// A simple C program to implement the Circular Queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE], rear=-1, front=-1, count=0;

void enqueue(int data)
{
    if(rear == -1)
    {
        rear = front = 0;
        queue[rear] = data;
        count++;
    }
    else if((rear+1)%SIZE == front)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = (rear + 1) % SIZE;
        queue[rear] = data;
        count++;
    }
}

int dequeue()
{
    int deletedNo;
    if(count != 0)
    {
        deletedNo = queue[front];
        front = (front + 1) % SIZE;
        count--;
        return deletedNo;
    }
    else
    {
        printf("Queue underflow\n");
        return -1;
    }
}

void displayQueue()
{
    int index = front;
    while(index != rear)
    {
        printf("%d ", queue[index]);
        index = (index + 1) % SIZE;
    }
    printf("%d \n", queue[index]);
}
void circularQueueImp()
{
    int choice, data;
    while(1)
    {
        printf("1 -> Insert\n2 -> Delete\n3 -> display\n4 -> exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d",&data);
            enqueue(data);
            break;
        case 2:
            data = dequeue();
            if(data != -1)
                printf("%d deleted\n", data);
            break;
        case 3:
            printf("Elements in Queue are:\n");
            displayQueue();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter valid choice!!\n");
        }
    }

}

main()
{
    printf("Queue size is %d\n",SIZE);
    circularQueueImp();
}