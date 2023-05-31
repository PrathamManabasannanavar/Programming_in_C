//A simple C program to compute and print the Fibonacci series

#include<stdio.h>

main()

{
 int i,n;
 int f1=0, f2=1,f3;

 printf("Enter the value of n\n");
 scanf("%d",&n);

 printf("%d %d ",f1,f2);
 for(i=0; i<n-2; i++)
 {
  f3 = f1 + f2;
  f1=f2;
  f2=f3;
  printf("%d ",f3);
 }
}