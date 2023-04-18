#include<stdio.h>

main()

{

 int a=12;
 int b=3;
 int c=50;

 int* x=&a;
 int* y=&b;

 printf("The value of address of a,b =%u, %u\n",x,y);
 //printf("%u\n",c);
 
 x--;
 y--;
 printf("The updated address of a,b =%u, %u\n",x,y);
 printf("The updated value of a,b =%u, %u\n",*x,*y);
}
