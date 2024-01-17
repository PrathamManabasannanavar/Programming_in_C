#include <stdio.h>
#include<stdlib.h>
#define SIZE 4

int queue[SIZE];

void enqueue(int data)
{
    if(queue[1] == SIZE-1){
        printf("Can't push\n");
        return;
    }
    queue[++queue[1]] = data;
}

void dequeue()
{
    if(queue[0] > queue[1])
    {
       printf("Can't pop\n");
       return;
    }
    printf("%d deleted\n",queue[queue[0]++]);
}

void display()
{
    if(queue[0] > queue[1] || queue[1] == 1) 
    {
        printf("Empty\n");
        return;
    }
    for(int i=queue[0]; i<=queue[1]; i++)
        printf("%d ",queue[i]);
    printf("\n");
}

void queueImp()
{
    int choice, data;
    while(1)
    {
        printf("front = %d\nrear = %d\n",queue[0], queue[1]);
        printf("Enter 1 to push\nEnter 2 to pop\nENter 3 to display\nEnter 4 to exit\n");
        scanf("%d",&choice);
        switch(choice)
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
            case 4: exit(0);
            default:
                printf("Enter the valid choice\n");
        }
    }
}

int main()
{
    queue[0] = queue[1] = 1;
    queueImp();    
    return 0;
}
