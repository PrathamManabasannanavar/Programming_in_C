#include<stdio.h>

main()

{

       int n;
       float i,j;
       
      printf ("Enter the value of last no: \n");
      scanf("%d",&n);
    
              for(i=1; i<=n/2; i++)
               {
                     for(j=1; j<=i; j++)
                          {
                             printf("*\t");
                          }
                     
                      printf("\n\n");
               }
            
            
            
            for(i=(n-1)/2; i>=1; i--)
               {
                     for(j=1; j<=i; j++)
                          {
                             printf("*\t");
                          }
                     
                      printf("\n\n");
               }
    
               
    
    
 }