#include<stdio.h>

main()

{
     int i,a[50];
     int n,k,count,m;
    
    printf("Enter the no of elements in array\n");
    scanf("%d",&n);

    printf("Enter the %d elements of array\n",n);
    for(i=0; i<n; i++)
     scanf("%d",&a[i]);
    
    for(i=0; i<n; i++)
    {
      k=a[i];
      count=0;
      m=i;
       for(i=0; i<n; i++)
       {
         if(k==a[i]) 
           count++;
       }
           i=m;
        printf("The element %d occurs %d times\n",k,count);
    }

    





}