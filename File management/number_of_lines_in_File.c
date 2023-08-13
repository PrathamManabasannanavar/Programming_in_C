// A simple C program to find the no of lines in the file
#include<stdio.h>

main()
{
 int count = 1;
 char ch;
 FILE *fptr = fopen("hello.txt", "r");
 if(fptr == NULL)
     printf("Error!!\n");
 while((ch = getc(fptr)) != EOF)
 {
    if(ch == '\n')
        count++;
    
 }
 fclose(fptr);       
 printf("There are %d lines in the file\n",count);       
}