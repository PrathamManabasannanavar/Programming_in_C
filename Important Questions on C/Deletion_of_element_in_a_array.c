#include<stdio.h>

main()

{
    int a[40],i,k,pos,n;
    
    printf("Enter the no of elements in array\n");
    scanf("%d",&n);

    printf("Enter the elements of array\n");
     for(i=0; i<n; i++)
      scanf("%d",&a[i]);

     printf("Enter the key and position to be deleted\n");
     scanf("%d %d",&k,&pos);

          i=pos;
        while(i!=n-1)
        {
           a[i]=a[i+1];
           i++;
        }
        a[n-1]=0;
        n=n-1;
    
      printf("The updated array is: \n");
       for(i=0; i<n; i++)
         printf("%d ",a[i]);
}