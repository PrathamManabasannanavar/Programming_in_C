/*A simple C program to compute and print the tables*/
//A program using for loop
#include<stdio.h>

main()

{
      int num,i;
      int sum=0;
    
    printf("   Enter the table which you want\n");
    scanf("%d",&num);

          for(i=1; i<=10; i++)
          {
        
        printf("%d * %d = %d\n",num,i,i*num);
        
        
          }
        
        printf("\n\n\n");
        
        
        
        
 //A program using while loop

        i=1;
        while(i<=10)
        {
        
        printf("%d * %d = %d\n",num,i,i*num);
        
       i++;
        }
        
        printf("\n\n\n");
        
           
        
        
 // A program using do while loop  
        
        i=0;//special
       
          do
        
          {
                i++;
           
               printf("%d * %d = %d\n",num,i,num*i);
        
          }while(i<=9 /*we should take i=9 not i=10*/);//special


}