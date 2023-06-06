//A simple C program to perform Linear search on Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node *next_address;
}node;

void read_linkedlist(node**, node**);
void print_linkedlist(node**);
int search(node**, int);

main()

{
 node *head=NULL, *temp=NULL,*ptr=NULL;
 
 read_linkedlist(&head, &temp);
 temp=head;
 
  printf("The linkedlist is:\n");
  print_linkedlist(&temp);
  temp=head;
 
 int key;
 printf("Enter element to be searched\n");
 scanf("%d",&key);

 int found = search(&temp,key);
  if(found==0)
   printf("Element not found\n");
  else
   printf("Element found at position no %d\n",found+1);
}

void read_linkedlist(node **head, node **temp)
{
 int choice;
 node *ptr;

 while(1)
 {
  printf(" Enter 1 to continue\n Enter 0 to exit\n");
  printf("Enter your choice\n");
  scanf("%d",&choice);
  
  if(choice!=1 && choice!=0)
  {
    printf("Enter valid choice!!\n");
    continue;
  }

  if(choice==0)
  {
   printf("You exited\n");
   break;
  }
  ptr=(struct node*)malloc(sizeof(int));

  printf("Enter the data\n");
  scanf("%d",&ptr->data);

  
  if(*head==NULL)
   {
    *head=ptr;
    *temp=ptr;
   }

  else
   {
    (*temp)->next_address=ptr;
    *temp=(*temp)->next_address;
   }

 }

  (*temp)->next_address=NULL;
}

void print_linkedlist(node **temp)
{
 while(*temp!=NULL)
  {
   printf("%d ",(*temp)->data);

   *temp=(*temp)->next_address;
  }
 printf("\n");
}

int search(node **temp, int key)
{
 int count=0;
 while(*temp!=NULL)
  {
   if(key==(*temp)->data)
    return count;
    
   count++;
   *temp=(*temp)->next_address;
  }
 return 0;
}