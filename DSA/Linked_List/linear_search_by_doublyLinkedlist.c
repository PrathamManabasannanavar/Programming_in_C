//A simple C program to perform linear search in Doubly linkedlist
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node* add1; //add1 for forward transversing
 struct node* add2; //add2 for backward transversing 
}node;

void read(node**, node**);
void print(node**, node**);
int linear_search(node**, node*, int);

int main()
{
 node *head=NULL, *temp=NULL, *last;
 int key;

 read(&head,&temp);
 last = temp;
 printf("The Linkedlist is:-\n");
 print(&head,&temp);

 printf("Enter the key to be searched\n");
 scanf("%d",&key);
 int found = linear_search(&head, last, key);

 if(found>0)
    printf("Element found at position %d\n",found);
 else if(found<0)
    printf("Element found at position %d from last\n",-1*found);
 else
    printf("Element not found!!\n");
    
 return 0;
}

void read(node **head, node **temp)
{
 int choice;
 node *ptr=NULL, *var=NULL;

 printf("Enter 1 to continue\nEnter 0 to exit\n");
 while(1)
 {
   printf("Enter your choice\n");
   scanf("  %d",&choice);

   if(choice!=0 && choice!=1)
   {
     printf("Enter correct choice!!\n");
     continue;
   }

   if(choice==0)
   {
     printf("You exited!!\n");
     break;
   }
   ptr = (struct node *)malloc(sizeof(node));

   printf("Enter the data\n");
   scanf("%d",&ptr->data);

   if(*head==NULL)
   {
    *head = ptr;
    *temp = ptr;
    var = ptr;
    ptr->add1 = NULL;
    ptr->add2 = NULL;
   }
   
   else
   {
     ptr->add2 = var;
   }

   (*temp)->add1 = ptr;

   var = ptr;
   
   *temp = (*temp)->add1;
 }
   (*temp)->add1 = NULL;
   printf("\n");
}

void print(node **head, node **temp)
{
  *temp = *head;
  while((*temp)!=NULL)
  {
    printf("%d ",(*temp)->data);
    *temp = (*temp)->add1;
  }

}

int linear_search(node **head, node *last, int key)
{
  int count = 1;
  node *temp1 = *head;
  node *temp2 = last;

  while (temp1 != NULL)
  {
    if (temp1->data == key)
    {
     return count; // +ve for forward search
    }
    if (temp2->data == key)
    {
     return -(count); //-ve for backward search
    }

    temp1 = temp1->add1;
    temp2 = temp2->add2;
    count++;
  }

  return 0; //0 for element not found
}
  