// A simple C program to print the elements of the array in the snake order
/*
1 2 3
4 5 6   ---->  [1 2 3 6 5 4 7 8 9]
7 8 9
*/
#include<stdio.h>

void read(int (*)[50], int, int);
void print(int (*)[50], int, int);
void snake_order(int (*)[50], int, int);
main()
{
 int a[50][50],n,m;

 printf("Enter the order of the Matrix\n");
 scanf("%d %d",&m,&n);

 printf("Enter the elements of Matrix\n");
 read(a,m,n);
 printf("Elements of Matrix are:-\n");
 print(a,m,n);
 printf("Elements in Snake order are:-\n");
 snake_order(a,m,n);
}

void read(int (*ptr)[50], int m, int n)
{
 for(int i=0; i<m; i++)
   for(int j=0; j<n; j++)
     scanf("%d",*(ptr+i)+j);
}

void print(int (*ptr)[50], int m, int n)
{
 for(int i=0; i<m; i++)
 {
   for(int j=0; j<n; j++)
     printf("%d ",*(*(ptr+i)+j));
   printf("\n");
 }
 printf("\n");
}

void snake_order(int (*ptr)[50], int m, int n)
{
  for(int i=0; i<m; i++)
  {
    if(i%2 == 0) // if index is even
      for(int j=0; j<n; j++)
        printf("%d ",*(*(ptr+i)+j));
        
    else // if index is odd
      for(int j=n-1; j>=0; j--)
        printf("%d ",*(*(ptr+i)+j));
  }
}