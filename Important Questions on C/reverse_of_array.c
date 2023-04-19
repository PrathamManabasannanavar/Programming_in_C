#include<stdio.h>
#include<stdlib.h>
 main()
{
     int i,n,rev,j;
     int a[50];
     int b[50];
    
    
     printf("Enter the no of elements in a array\n");
     scanf("%d",&n);


      printf("Enter the %d elements\n",n);
       for(i=0; i<n; i++) 
       scanf("%d",&a[i]);
        
      for(i=0; i<n; i++) { // original array copied to temp array 
           b[j]=a[i];
           j++;
        }
            i=0;
     for(j=n-1; j>=0; j--) { // Assigning the values back to array in reverse order
             a[i]=b[j];
           i++;
        }

       printf("The elements in reverse order are: \n");
        for(i=0; i<n; i++)
          printf("%d ",a[i]);
}