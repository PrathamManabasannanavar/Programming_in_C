#include<stdio.h>
main()
{
    char R,Y,G,colour;
    
      printf("Enter the colour\n");
      scanf("%c",&colour);
    
    
    if(colour=='R') //Red 
        printf("STOP\n");
        
    else if(colour=='G')   //Green 
        printf("GO\n");
        
    else if(colour=='Y') //Yellow
        printf("Observe Carefully\n");

     else
         printf("Enter valid colour\n");

}