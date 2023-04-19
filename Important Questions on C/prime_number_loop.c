#include<stdio.h>
main()
{

      int num,i;
      int n;
    
      printf("Enter last no\n");
      scanf("%d",&num);
    
             i=1;
            for(i=1; i<=100; i++)
            {
              n=1;
            for(n=1; n<=100; ++n)
               {
              if(i%n!=0 && i!=n)
                        {
                 printf("%d %d\n",i,n);
                        }
              else
                  printf("Hi\n");
               }
            
            }






}