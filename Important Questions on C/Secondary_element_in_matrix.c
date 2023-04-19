// A simple C program to compute and print secondary diagonal elements 
#include<stdio.h>

main()

{
    int i,j,n,m;// m for row and n for column
    int a[50][50];
    
    printf("Enter the order of the Square matrix\n");
    scanf("%d %d",&m,&n);// scanning the elements
    
    printf("Enter the elements of Square matrix\n");
     for(i=1; i<=m; i++) // Starting i from 1
        for(j=1; j<=n; j++) // Starting j from 1
           scanf("%d",&a[i][j]);

     printf("The Secondary diagonal elements are:-\n");
       for(i=1; i<=m; i++)
       {
          for(j=1; j<=n; j++)
             {
               if(j==n) {
               printf("%d ",a[i][j]);
               n--; // Decrementing n value in every iteration
                }
             }
            
            printf("\n");
            
    /*If I take j from 0 then I should end the loop at i<m
     which does not holds good for the condition inside the if */

       }

}