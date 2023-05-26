// A simple C program to print the elements of the array in Spiral order using pointers
/* ex:-
  1 2 3          
  4 5 6   ---->  [1 2 3 6 9 8 7 4 5]
  7 8 9
*/
// It is an APPLE's interview question
#include<stdio.h>
#define row 50
#define col 50

void spiral_order(int(*)[col], int*, int, int);
void print_arr(int*, int);
void read(int(*)[col], int, int);

main()

{

 int a[row][col],m,n,b[row*col];

 printf("Enter the order of 2D arrayl\n");
 scanf("%d %d",&m,&n);

 read(a,m,n);
 spiral_order(a,b,m,n);

 print_arr(b,m*n);

}

void spiral_order(int (*ptr)[col], int *ptr1, int m, int n)
{
 int i,j;
 int up=0, down=m-1, left=0, right=n-1;
 int direction=0;

 while(up<=down && left<=right)
 {
  //left-->right

  if(direction==0)
  {
   for(j=left; j<=right; j++,ptr1++)
   
{
    *ptr1 = *(*(ptr+up)+j);
   }
  up++;
  }
   
  //up-->down
  if(direction==1)
  {
   for(i=up; i<=down; i++,ptr1++)
   {
    *ptr1 = *(*(ptr+i)+right);
   }
   right--;
  }

  //right-->left
  if(direction==2)
  {
   for(j=right; j>=left; j--,ptr1++)
   {
    *ptr1 = *(*(ptr+down)+j);
   }
   down--;
  }

  //down-->up
  if(direction==3)
  {
   for(i=down; i>=up; i--,ptr1++)
   {
    *ptr1 = *(*(ptr+up)+left);
   }
   left++;
  }

  direction++;

   if(direction>3)
   {
   direction = direction % 4;
   }

 }
}

void print_arr(int *ptr1, int n)
{
 int i;

 printf("[ ");
 for(i=0; i<n; i++)
 {
  printf("%d ",*(ptr1+i));
 }
 printf("]\n");
}

void read(int (*ptr)[50], int m, int n)
{
 int i,j;
 printf("Enter the elements of 2D arr\n");
 for(i=0; i<m; i++)
  for(j=0; j<n; j++)
  scanf("%d",*(ptr+i)+j);
}