//A simple C program to find capital of text
#include<stdio.h>

main()

{
   char str[100];
   int i,m;

  printf("Enter the text\n");
  scanf("%s",str);
   
  for(i=0; str[i]!='\0'; i++);
  
  m=i;
  for(i=0; i<m; i++) // ansii value of a=97 and A=65 and 0=32
  {
    if(str[i]>=97 && str[i]<=123)
       str[i]=str[i]-32;
    else
       continue;   
  }

   printf("%s",str);

}