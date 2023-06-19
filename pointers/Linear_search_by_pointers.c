// A simple C program to perform linear search in the array using pointers
#include<stdio.h>

void read(int *, int);
void print(int * , int);
int search(int *, int, int);

int main()
{
 int a[50],n,key;

 printf("Enter the no of elements of the array\n");
 scanf("%d",&n);

 printf("Enter elements of array\n");
 read(a,n);
 printf("The array is\n");
 print(a,n);
 printf("Enter the key to be searched\n");
 scanf("%d",&key);

 int found = search(a,n,key);
 if(found != 0)
   printf("Key found at position %d\n", found+1);
 else
   printf("Key not found in the array!!\n");
 return 0;
}

void read(int *ptr, int n)
{
 for(int i=0; i<n; i++)
   scanf("%d",ptr+i);
}

int search(int *ptr, int n, int key)
{
 int i=0,j=n-1;
 for(i=0; i<n; i++,j--)
 {
  if(*(ptr+i)==key)
    return i;
  if(*(ptr+j)==key)
    return j;
 }
 return 0;
}

void print(int *ptr, int n)
{
 for(int i=0; i<n; i++)
   printf("%d ",*(ptr+i));
 printf("\n");
}
    