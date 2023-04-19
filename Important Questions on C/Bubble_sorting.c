#include<stdio.h>
#include<stdlib.h>
#define size 100

main()

{
    int i,j,swap,n;
    int a[size],sorted=1;
    
    printf("Enter the no of elements\n ");
    scanf("%d",&n);
    
    printf("Enter the elements\n");
     for(j=0; j<n; j++)
      scanf("%d",&a[j]);


      for(i=0; i<n-1; i++) // Number of passes
       {
           for(j=0; j<n-1-i; j++) // swapping adjacent elements 
             {
                 if(a[j]>a[j+1])
                  {
                     swap=a[j];
                     a[j]=a[j+1];
                     a[j+1]=swap;
                    
                     sorted=0; // Flag variable
                     
                  }
           
             }
              if(sorted==1) // Checking wheather swapping has taken place or not?
               {
                    printf("Array is already sorted\n");
                    exit(0);
               }
       }
    
    j=0;

printf("The sorted array is: ");
for(j=0; j<n; j++)
     printf("%d ",a[j]);





}