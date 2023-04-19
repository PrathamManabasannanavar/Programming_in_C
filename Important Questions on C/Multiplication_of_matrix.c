#include<stdio.h>
#include<stdlib.h>
main()
{
    int x,y,m,n;
    int a[20][20],b[20][20],i,j;
    int prod[50][50],k;
    
    printf("Enter the order of first matrix\n");
    scanf("%d %d",&x,&y);
    
    printf("Enter the order of 2nd matrix\n");
    scanf("%d %d",&m,&n);
    
      if(m!=n)
      {
       printf("Matrices can't be multiplied\n");
       exit(0);
      }
    
     printf("Enter the elements of 1st matrix\n");
       for(i=0; i<x; i++)
        for(j=0; j<n; j++)
         scanf("%d",&a[i][j]);
    
    printf("Enter the elements of 2nd matrix\n");
       for(i=0; i<x; i++)
        for(j=0; j<n; j++)
         scanf("%d",&b[i][j]);
    
    for(i=0; i<x; i++)
     for(j=0; j<n; j++)
      {
         prod[i][j]=0;
         for(k=0; k<x; k++)
         {
          prod[i][j]+=a[i][k]*b[k][j];
         }
      }
    
    printf("The product matrix is;\n");
     for(i=0; i<x; i++)
    {
      for(j=0; j<n; j++)
      {
       printf("%d ",prod[i][j]);
      }
      printf("\n\n");
    } 
    
}