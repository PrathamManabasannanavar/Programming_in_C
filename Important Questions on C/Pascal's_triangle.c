/*A simple C program to compute and 
print the Pascal's triangle */

#include<stdio.h>

main()

{
    int rows, rem, val=1, j, i;
    
    printf("Enter no of rows\n");
    scanf("%d",&rows);
    
    int len=rows;
    
    for(i=0; i<rows; i++)
    {
       for(j=0; j<len; j++) //for giving space
       {
           printf(" ");
       }
       len--;
       
       val*=11;
       int var=val;
       
      while(var!=0)
      {
      rem=var%10;
      printf("%d ",rem);
      var=var/10;
      }
      printf("\n\n");
    }
    
}