//A simple C program to read, print and find sum of an array
#include<stdio.h>

void no_scan(int, int[]);
void arr_print(int, int[]);
int add(int, int[]);

main()
{
  int n,m,a[20],b[20];
  int sum[50];

    printf("Enter the no of elements in 1st array\n ");
    scanf("%d",&m);

    printf("Enter the no of elements in 2nd array\n ");
    scanf("%d",&n);

    printf("Enter the elements of first array\n");
    no_scan(m,a);
    
    printf("Enter the elements of 2nd array\n");
    no_scan(n,b);

    printf("The elements of 1st array are:\n");
    arr_print(m,a);
    
    printf("\n");
    
    printf("The elements of 2nd array are:\n");
    arr_print(n,b);
    
    printf("The sum of 1st array is: %d\n",add(m,a));
    printf("The sum of 2nd array is: %d\n",add(n,b));
}


void no_scan(int x, int read[])
{
   int i,y;
   for(i=0; i<x; i++)
    scanf("%d",&read[i]);
}

void arr_print(int x, int print[])
{
   int i,j;
   for(i=0; i<x; i++)
    printf("%d ",print[i]);
}

int add(int x, int arr[])
{
   int i,sum=0;
    for(i=0; i<x; i++)
     sum += arr[i];
    
   return(sum);

}