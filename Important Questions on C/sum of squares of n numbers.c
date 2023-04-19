#include<stdio.h>

main()

{
      int num,i;
      int sum=0;
    
    printf("Enter the Final value\n");
    scanf("%d",&num);

               for(i=1;i<=num;i++)
            {
                 sum=sum+i*i;
             
            }

       printf("The sum of squares of no is %d\n",sum);
  







}