//A simple C program to find and process wheather a number is prime or not

#include<stdio.h>

main()

{
       int n,i,prime,rem;
    
          printf("Enter a positive no\n");
          scanf("%d",&n);
        
                 for(i=2; i<=n/2; i++)
                      {
                          rem=n%i;
            
                           if(rem==0)
                                  {
                                        printf("It is not a prime no\n");
                                        printf("Because the number %d is divisible by: %d\n",n,i);
                                          exit(0);
            
                                  }
            
                      }
                
               printf("It is a prime no\n");
            






}