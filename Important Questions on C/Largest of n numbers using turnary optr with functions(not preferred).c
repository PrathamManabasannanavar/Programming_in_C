#include<stdio.h>
int largest(int[], int);
void read(int[], int);

main()

{
  int num[50],n;
  int biggest_no;

  printf("Enter the no of numbers to be compared\n");
  scanf("%d",&n);

  read(num, n);
  biggest_no = largest(num, n);

  printf("The largest among the %d numbers is: %d\n",n,biggest_no);
}

int largest(int a[], int n)
{
 int i, big, temp, hi ;//hi only a temporary variable, no use of it
 big = a[0];
 for(i=1; i<n; i++)
 {
   (big<a[i])?(big=a[i]):(hi=1); //using turnary optr
 }
 return(big);
}

void read(int a[], int n)
{
 int i;
 printf("Enter the numbers to be compared\n");
 for(i=0; i<n; i++)
  scanf("%d",&a[i]);
}