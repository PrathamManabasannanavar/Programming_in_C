#include<stdio.h>

main()

{
     int i,j,a[50],pos,n;
     int swap;
     int k;
 
      printf("Enter no of elements in array\n");
      scanf("%d",&n);
    
      printf("Enter elements of array\n");
       for(i=0; i<n; i++)
         scanf("%d",&a[i]);
    
      printf("Enter the key and position it has to be inserted\n");
      scanf("%d %d",&k,&pos);
    
       n=n+1;
       a[n]=k;
        i=n;
        while(i!=pos)
        {
           swap=a[i];
           a[i]=a[i-1];
           a[i-1]=swap;
           i--;
        }
         
    printf("The updated array is: \n");
      for(i=0; i<n; i++)
       printf("%d ",a[i]);
    
    
    
       
}