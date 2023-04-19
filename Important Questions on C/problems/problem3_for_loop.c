#include<stdio.h>
#include<math.h>
main()
{

       int n,i;
       int prod=1;
       float sum=0;
       
      printf("Enter the value of last no: \n");
      scanf("%d",&n);
    
           for(i=1; i<=n; i++)
               {
            prod=prod*i; // Factorial computing

                    if(i%2!=0)
                      {
            sum=sum+1/(prod*1.0);   // Adding factorial
                      }
              }
            
           
      printf("The Answer to the expression is: %f\n",sum);




}
