#include<stdio.h>

int read(int[],int);
void search(int[],int);
void display(int[], int);

main()

{
  int a[50],n;
   
  printf("Enter the no of elements of array\n");
  scanf("%d",&n);

  read(a,n);
  search(a,n);
  display(a,n);

}

int read(int a[],int n)
{
  int i;
  printf("Enter the elements of array\n");
  for(i=0; i<n; i++)
   scanf("%d",&a[i]);
  return(a);
}

void search(int a[], int n)
{
 int key,i, found=0;

 printf("Enter the key to be searched\n");
 scanf("%d",&key);

 for(i=0; i<n; i++)
  if(key==a[i])
   found=1;

 if(found==1)
  printf("Key found\n");
 else
  printf("Key not found\n");
}

void display(int a[], int n)
{
 int i;
 printf("The elements of array are: \n");
 for(i=0; i<n; i++)
  printf("%d ",a[i]);

}