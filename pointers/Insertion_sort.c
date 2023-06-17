//A simple C program to perform Insertion sort using pointers
#include<stdio.h>

void read(int*, int);
void insertion_sort(int*, int);
void print_arr(int*, int);

int main()

{
 int a[50], n;

 printf("Enter no of elements\n");
 scanf("%d",&n);
 read(a,n);

 printf("The array before sort is\n");
 print_arr(a,n);

 insertion_sort(a,n);
 printf("The sorted array is\n");
 print_arr(a,n);

 return 0;
}

void insertion_sort(int* ptr, int n)
{
 int i,j,temp;

 for(i=1; i<n; i++)
 {
   temp = *(ptr+i);
   for(j=i-1; j>=0; j--)
   {
     if(ptr[j]>temp)
     {
       *(ptr+j+1) = *(ptr+j);
     }
     else
     {
       break;
     }
   }
   *(ptr+j+1)=temp;
 }

}

void read(int *ptr, int n)
{
 printf("Enter elements array\n");
  for(int i=0; i<n; i++)
    scanf("%d",ptr+i);
}

void print_arr(int *ptr, int n)
{
 for(int i=0; i<n; i++)
  printf("%d ",*(ptr+i));
 printf("\n");
}