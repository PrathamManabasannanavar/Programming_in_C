#include<stdio.h>

main()

{
    int num,i,j=10;
    
    printf("What is the ISD code for India?\n");
    
    j=10;
      for(i=2; i>=0; i--)
       {
           scanf("%d",&num);
       
           while(j!=1)
            {
                if(num==91)
                  {
                     printf("SUCCESSFUL\n*** Your score is %d ***\n",j);
                     exit(0);
                  } 
      
                if(num!=91)
                  {
                     j=j-3;
                     printf("---->YOU HAVE %d ATTEMPTS LEFT\n",i);
                     break;
            
                  }
                 
            }
       }

   printf("The score is %d\n",j);

}