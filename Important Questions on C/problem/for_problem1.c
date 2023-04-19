
//A simple C program to compute and print the nunbers from 1 to num divisible by 6 but not by 4

#include<stdio.h>

main()

{

    int num,i;
    
        printf("Enter the last value\n");
        scanf("%d",&num);

       for(i=1; i<=num; i++)
         {
          
            if(i%6==0 && i%4!=0)
            {
            
            printf("%d\n",i);
            
            } //Don't put else and exit(0);
             
         }




}
