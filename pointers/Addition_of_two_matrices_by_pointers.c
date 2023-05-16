//A simple C program to find and compute of sum of two matrices
#include<stdio.h>
#include<stdlib.h>
#define col 50

void read(int(*)[col], int(*)[col], int, int);
void add(int(*)[col], int(*)[col], int(*)[col], int, int);
void print_array(int(*)[col], int, int);

main()

{
  int x[50][50],y[50][50];
  int m,n,a,b;
  int z[50][50];

  printf("Enter the order of 1st matrix\n");
  scanf("%d %d",&a,&b);

  printf("Enter the order of 2nd matrix\n");
  scanf("%d %d",&m,&n);

  if(a!=m || b!=n)
  {
   printf("Matrices cannot be added!!\n");
   exit(0);
  }

  read(x,y,m,n);
  add(x,y,z,m,n);
  print_array(z,m,n);

}

void read(int (*ptr1)[col], int (*ptr2)[col], int m, int n )
{
 int i,j;
 
 printf("Enter the elements of the 1st Matrix\n");
 for(i=0; i<m; i++)
  for(j=0; j<n; j++)
   scanf("%d",*(ptr1+i)+j);

 printf("Enter the elements of the 2nd Matrix\n");
 for(i=0; i<m; i++)
  for(j=0; j<n; j++)
   scanf("%d",*(ptr2+i)+j);
}

void add(int (*ptr1)[col], int (*ptr2)[col], int (*ptr)[col], int m, int n )
{
 int i,j;

 for(i=0; i<m; i++)
  for(j=0; j<n; j++)
  {
   *(*(ptr+i)+j) = *(*(ptr1+i)+j) + *(*(ptr2+i)+j);
  }
}

void print_array(int (*ptr)[col], int m, int n)
{
 int i,j;

 for(i=0; i<m; i++)
 {
  for(j=0; j<n; j++)
   printf("%d ",*(*(ptr+i)+j));
  printf("\n");
 }
}
