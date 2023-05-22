//A simple C program to multiply the two Matrices using pointers
#include<stdio.h>
#include<stdlib.h>

void read(int(*)[50], int(*)[50], int, int, int, int);
void multiply(int(*)[50], int(*)[50], int(*)[50], int, int);
void display(int(*)[50],int,int);
int main()
{
 int x[50][50],y[50][50], prod[50][50];
 int a,b,p,q;

 printf("Enter the order of 1st Matrix\n");
 scanf("%d %d",&a,&b);

 printf("Enter the order of 2nd Matrix\n");
 scanf("%d %d",&p,&q);

 if(b!=p)//checks for multiplication condition 
 { 
   printf("Two Matrices cannot be multiplied\n");
   exit(0);
 }

 read(x,y,a,b,p,q); //reads the matrix elements 
 multiply(x,y,prod,a,q); //Multiplies two matrix

 printf("The product Matrix is:-\n");
 display(prod,a,q);
 return 0;
}

void multiply(int (*ptr1)[50], int (*ptr2)[50], int (*ptr)[50], int a, int q)
{
 int i,j,k;

  for(i=0; i<a; i++)
   for(j=0; j<q; j++)
   {
     *(*(ptr+i)+j)=0;
     for(k=0; k<q; k++)
     {
      *(*(ptr+i)+j) += *(*(ptr1+i)+k) * *(*(ptr2+k)+j);
     }
   }
}

void read(int (*ptr1)[50], int (*ptr2)[50], int a, int b, int p, int q)
{
 int i,j;

 printf("Enter the elements of 1st Matrix\n");
 for(i=0; i<a; i++)
  for(j=0; j<b; j++)
  scanf("%d",*(ptr1+i)+j);

 printf("Enter the elements of 2nd Matrix\n");
 for(i=0; i<a; i++)
  for(j=0; j<b; j++)
  scanf("%d",*(ptr2+i)+j);
}

void display(int(*ptr)[50], int a, int q)
{
 int i,j;
 for(i=0; i<a; i++)
 {
  for(j=0; j<q; j++)
   printf("%d ",*(*(ptr+i)+j));
  printf("\n");
 }
}

    
