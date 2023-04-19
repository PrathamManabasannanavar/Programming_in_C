#include<stdio.h>

main()

{

     char A,Z,ch;
    
    printf("Enter the Character\n");
    scanf(" %c",&ch);
    
    if(ch>='A' && ch<='Z')
    printf("Capital\n");
    
    else
      printf("Lower case\n");

      printf("The size is %d",sizeof(ch));

}