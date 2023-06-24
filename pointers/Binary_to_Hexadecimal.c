//A simple C program to convert binary no to hexadecimal no
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void convert(char *, char *);
int compare(char *, char (*)[5], int, int);
void check(char *);
main()
{

 char binary_no[50];
 char hexadecimal_no[20];
 
 printf("Enter the binary number\n");
 scanf("%s",binary_no);
 check(binary_no);

 convert(binary_no, hexadecimal_no);
 printf("The Hexadecimal equivalent of this Binary no is: %s\n",hexadecimal_no);
}

void convert(char *binary_no, char *hexadecimal_no)
{
 int i,j;
 char hexa[16][5] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
 char no[17] = "0123456789ABCDEF"; 


 for(i=0; binary_no[i]!='\0'; i=i+4)
 {
   int temp = compare(binary_no,hexa,i,i+3);
   if(temp>=0)
       *hexadecimal_no = no[temp];
   hexadecimal_no++;
 }
  *hexadecimal_no = '\0';
}

int compare(char *binary_no, char (*hexa)[5], int start, int end)
{
 char temp[5];
 int i,j=0;
 for(i=start; i<=end; i++,j++)
   temp[j] = binary_no[i];
  temp[j]='\0';

 for(i=0; i<16; i++)
 {
  if(strcmp(temp,hexa[i]) == 0)
    return i;
 }
 return -1;
}

void check(char *binary_no)
{
  for(int i=0; binary_no[i]!='\0'; i++)
    if(binary_no[i] != '1' && binary_no[i] != '0')
    {
       printf("Enter valid binary no!!\n");
       exit(0);
    } 
}