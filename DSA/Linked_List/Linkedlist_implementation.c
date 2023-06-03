/*A simple C program to initialise the 
Linkedlist i.e Singular Linkedlist*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node *next_address;
}node;

int main()

{
 int choice,count=0;
 
 node *head=NULL,*temp=NULL,*ptr=NULL;
 
 while(1)
 {
  count++;
  printf("Enter your choice\n Enter 1 to continue\n Enter 0 to exit\n");
  scanf("%d",&choice);

  if(choice!=0 && choice!=1)
  {
   printf("Enter valid choice!!\n");
   continue;
  }
  if(choice==0)
  {
    if(count==1)
   {
   printf("You exited!!\n");
   exit(0);
   }
   break;
  }
  ptr=(struct node*)malloc(sizeof(node));
  printf("Enter the value\n");
  scanf("%d",&ptr->data);

  if(head==NULL)
  {
  head=ptr;
  temp=ptr;
  }

  else
  {
   temp->next_address=ptr;
   temp=ptr;
  }
 
 }
  temp->next_address=NULL;
  temp=head;

  printf("The Entered values are:-\n");
  while(temp!=NULL)
  {
   printf("%d ",temp->data);
   temp=temp->next_address;
  }

 return 0;
}
