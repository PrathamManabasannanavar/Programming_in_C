#include<stdio.h>

int factorial(int);

main()

{
   int n;

     printf("Enter the no whose factorial has to be found\n");
     scanf("%d",&n);

   int f= factorial(n);

    printf("Factorial of %d is = %d\n",n,f);
}

factorial (int num)
{
   int i,prod=1;

    for(i=num; i>1; i--)
       prod=prod*i;
   return(prod);
}