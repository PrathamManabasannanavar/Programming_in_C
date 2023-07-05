// A Simple C program to find the maximum distance between elements in the array followed such that a[i]<=a[j]
//ex :-34 8 10 32 2 80 30 33 1 --> Here maximum difference is 6 between a[1] and a[7] i.e 8<=33
#include<stdio.h>

int max_diff(int *, int);
void read(int *, int);
void print(int *, int);
main()
{
 int arr[50],n;

 printf("Enter the no of elements of array\n");
 scanf("%d",&n);

 printf("Enter elements of array\n");
 read(arr,n);
 
 printf("Entered elements of array are;-\n");
 print(arr,n);

 int diff = max_diff(arr,n);
 printf("The maximum difference between the two elements is %d\n",diff);
}

int max_diff(int *arr, int n)
{
 int diff=0;
 for(int i=0; i<n; i++)
 {
   for(int j=n-1; j>=i; j--)
   {
     if(arr[i] <= arr[j])
     {
       if(j-i < diff)
         break;
       diff = j-i;
       break;
     }
    if(diff > n-i-1)
       return diff;
   }
 }
 return diff;
}

void print(int *arr, int n)
{
  for(int i=0; i<n; i++)
    printf("%d ",arr[i]);
  printf("\n");
}

void read(int *arr, int n)
{
  for(int i=0; i<n; i++)
    scanf("%d",&arr[i]);
}