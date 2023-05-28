// A simple C program to rotate the Square matrix in right angle using pointers
/* ex:-
  1 2 3          7 4 1
  4 5 6   ---->  8 5 2
  7 8 9.         9 6 3
*/

#include<stdio.h>
#define row 50
#define col 50

void reverse_rows(int (*)[col], int, int);
void transpose(int(*)[col], int(*)[col], int, int);
void print_arr(int(*)[col], int, int);
void read(int(*)[col], int, int);

main()

{

 int a[row][col],m,n,b[row][col];

 printf("Enter the order of array\n");
 scanf("%d %d",&m,&n);

 read(a,m,n);
 transpose(a,b,m,n); //Taking transpose of Matrix
 reverse_rows(b,m,n);//Reversing every row after transpose
 print_arr(b,m,n);

}


void print_arr(int (*ptr1)[col], int m, int n)
{
 int i,j;

 for(i=0; i<n; i++)
 {
  for(j=0; j<m; j++)
  printf("%d ",*(*(ptr1+i)+j));
  printf("\n");
 }
 
}

void read(int (*ptr)[50], int m, int n)
{
 int i,j;
 printf("Enter the elements of array\n");
 for(i=0; i<m; i++)
  for(j=0; j<n; j++)
  scanf("%d",*(ptr+i)+j);
}

void transpose(int (*ptr)[col], int (*ptr1)[col], int m, int n)
{
 int i,j;
 for(i=0; i<m; i++)
  for(j=0; j<n; j++)
   *(*(ptr1+j)+i) = *(*(ptr+i)+j);
}

void reverse_rows(int (*ptr1)[col], int m, int n)
{
 int i,j,temp,x;
 for(i=0; i<n; i++)
 {
  x=n-1; //assigning the last column
  for(j=0; j<m/2; j++,x--) //swapping the elements in that row
  {
   temp = *(*(ptr1+i)+x);
   *(*(ptr1+i)+x) = *(*(ptr1+i)+j);
   *(*(ptr1+i)+j) = temp;
  }
 }
}
