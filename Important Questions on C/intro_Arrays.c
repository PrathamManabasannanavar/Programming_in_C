
#include<stdio.h>
main()

{
       int n,i;
    
    printf("Enter the no of data\n");
    scanf("%d",&n);
    
      int a[n];
    
    printf("Enter the values\n\n");
    
    for(i=0; i<=n; i++)
      {
          
    scanf("%d",&a[i]);
    
      }
    
    printf("The values entered are\n");
    
    for(i=0; i<=n; i++) 
        {
            printf("%d, ",a[i]);
        }





}