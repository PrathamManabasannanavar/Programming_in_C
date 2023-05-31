//A simple C program to compute and print the prime numbers 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void print_prime(int, int);
main()

{
 int n,m;
 
 printf("Enter the value of m and n\n");
 scanf("%d %d",&m,&n);

 if(m<=0 || n<m)
 {
  printf("Enter valid values greater than 0\n");
  exit(0);
 }
 printf("The prime numbers between %d and %d are:-\n",m,n);
 print_prime(m,n);
}

void print_prime(int m, int n)
{
 int i,j,prime;
 for(i=m+1; i<n; i++)
 {
  prime=1;
  for(j=2; j<=sqrt(i); j++)
  {
   if(i%j==0)
   {
    prime=0;
    break;
   }
  }

  if(prime==1 && i!=1 && i!=0)
   printf("%d ",i);
 }

}