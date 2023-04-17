/*A simple C program to compute and print the largest and
 second largest no in array using pointers*/
#include<stdio.h>
void big(int[],int *, int *, int);
main()

{
 int largest, largest_2;
 int arr[50],n,i,key;
 int *ptr=arr;

 printf("Enter the size of array\n");
 scanf("%d",&n);

 printf("Enter elements of array\n");
 for(i=0; i<n; i++)
  scanf("%u",ptr++);

 big(arr,&largest,&largest_2,n);
   
  printf("The largest value is %d\nSecond largest value is %d\n",largest,largest_2);
}

void big(int a[50], int *larg, int *larg_2, int n)
{
 int i;

 *larg = a[0];

 for(i=0; i<n; i++)
  if(*larg < a[i])
  {
   *larg = a[i];
  }

 *larg_2 = a[0];

 for(i=0; i<n; i++)
  if(*larg_2 < a[i] && a[i] != *larg)
  {
   *larg_2 = a[i];
  }
}