//A,simple C program to delete an element from array
#include<stdio.h>
#include<stdlib.h>

void deletion(int*, int, int, int);
int search(int*, int ,int);
void read(int*, int);
void print_arr(int*, int);
main()
{
    int a[50],n, element, pos;
    
    printf("Enter no of elements of array\n");
    scanf("%d",&n);
    
    read(a,n);
    
    printf("Enter element to be deleted\n");
    scanf("%d",&element);
    
    int found=search(a,n,element);
    if(found==0)
    {
     printf("Element not found!!\n");
     exit(0);
    }
    
    else
     pos=found;
    
    printf("The array before deletion is\n");
    print_arr(a,n);
    
    deletion(a,n,element,pos);
    n--;
    printf("The array after deletion is\n");
    print_arr(a,n);
}

void read(int *ptr, int n)
{
    printf("Enter elements of array\n");
    for(int i=0; i<n; i++)
      scanf("%d",ptr+i);
}

void deletion(int *ptr, int n, int element, int pos)
{
 int i;
  for(i=pos; i<n; i++)
   *(ptr+i) = *(ptr+i+1);
}

int search(int *ptr, int n, int element)
{
 int count=0;

 for(int i=0; i<n; i++,count++)
  if(*(ptr+i)==element)
    return count;

 return 0;
}

void print_arr(int *ptr, int n)
{
    for(int i=0; i<n; i++)
      printf("%d ",*(ptr+i));
    printf("\n");
}
