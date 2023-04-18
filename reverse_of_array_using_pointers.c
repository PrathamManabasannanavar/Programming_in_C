//A simple C program to find the reverse of an array
#include<stdio.h>

main()

{
 int a[50];
 int *ptr1=a;
 int *ptr2;
 int i,n,temp;

 printf("Enter size of array\n");
 scanf("%d",&n);

 ptr2=&a[n-1];

 printf("Enter elements of array\n");
 for(i=0; i<n; i++)
  scanf("%d",ptr1+i);

  for(i=0; i<n/2; i++)
  {
   temp=*(ptr1+i);
   *(ptr1+i)=*(ptr2-i);
   *(ptr2-i)=temp;
  }
 /*for(i=0; i<n/2; i++) //without pointers
   {
   temp=a[i];
   a[i]=a[n-1-i];
   a[n-1-i]=temp;
   } */

 printf("The array in reverse order is:\n");
 for(i=0; i<n; i++)
  printf("%d ",a[i]);
  
}