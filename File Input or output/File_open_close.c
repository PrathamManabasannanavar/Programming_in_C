//This is a C program to open and close the file
#include<stdio.h>

int main()

{
 int num1, num2;
 
 FILE *ptr;
 // ptr = fopen("hi.txt","w");
 ptr = fopen("hi.txt", "r");
 fscanf(ptr, "%d",&num1);
 fscanf(ptr, "%d",&num2);
// fprintf(ptr,"My name is Apple %d\n",47588);
 fclose;
 
 printf("The value is %d\n",num1);
 printf("The second value is %d\n",num2);
 return 0;
}