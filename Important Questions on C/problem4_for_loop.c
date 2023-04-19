#include<stdio.h>

main()

{

    int n,i,j;
    
       printf("Enter the last integer\n");
       scanf("%d",&n);

          for(i=1; i<=n; i++)
                {
                   for(j=1; j<=i; j++)
                        {
                           printf("%d\t",j);
            
                        }
            
                     printf("\n\n");
                }






}
