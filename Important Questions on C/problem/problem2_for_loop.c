#include<stdio.h>
#include<math.h>
main()
{

       int n,i;
       int sum=0,prod=1;
       
      printf("Enter the value of last no: \n");
      scanf("%d",&n);
    
           for(i=1; i<=n; i++)
               {
            prod=prod*i; // Factorial computing
            sum=sum+prod*pow(-1,i); // Adding factorial
               }
           
      printf("The Answer to the expression is: %d\n",sum);




}
