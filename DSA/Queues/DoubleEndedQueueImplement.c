// A simple C program to implement Double Ended Queue
#include<stdio.h>
#define SIZE 5

int dEQueue[SIZE], front = -1, rear = SIZE;

void insertRear(int data)
{
   /* if(rear == front)
    {
        printf("Can't insert from rear\n");
        return;
    }*/
    dEQueue[--rear] = data;
}

void insertFront(int data)
{
   /* if(rear == front)
    {
        printf("Can't insert from front\n");
        return;
    }*/
    dEQueue[++front] = data;
}

int deleteRear()
{
   /* if(rear == SIZE)
    {
        printf("Can't delete from Rear\n");
        return -1;
    }*/
    return dEQueue[rear++];
}

int deleteFront()
{
    /*if(front == -1)
    {
        printf("Can't delete fron from front\n");
        return -1;
    }*/
    return dEQueue[front--];
}

void implementDEQueue()
{
    int choice, ele;
    while(1)
    {
        printf("rear = %d\nfront = %d\n", rear, front);
        printf("Enter 1 to insert from rear\n");
        printf("Enter 2 to delete from rear\n");
        printf("Enter 3 to insert from front\n");
        printf("Enter 4 to delete from front\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
              printf("You exited!!\n");
              return;
        case 1:
            if(rear == front)
            {
                printf("Can't insert from rear!!\n");
                continue;
            }
            printf("Enter the element to be inserted\n");
            scanf("%d",&ele);
            insertRear(ele);
            break;

        case 2:
            if(rear == SIZE)
            {
                printf("Can't delete from Rear!!\n\n");
                continue;
            }
            printf("%d deleted from Rear\n\n",deleteRear());
            break;

        case 3:
            if(rear == front)
            {
                printf("Can't insert from front!!\n\n");
                continue;
            }
            printf("Enter the element to be inserted\n");
            scanf("%d",&ele);
            insertFront(ele);
            break;
        case 4:
            if(front == -1)
            {
                printf("Can't delete from front!!\n\n");
                continue;
            }
            printf("%d deleted from the front\n\n",deleteFront());
            break;
        default:
            printf("Enter valid choice\n");
        }
    }
}

main()
{
    implementDEQueue();
}