//A simple C program to arrange the characters in a string in dictionary order
#include<stdio.h>
#include<string.h>
#define SIZE 50

void read(char *);
void arrange(char *);
void print_str(char *);
int check(char *);

int main()

{
 char str[SIZE], alpha[SIZE];

 read(str);
 while(check(str)==0)
 {
  printf("Enter Valid String!!\n");
  read(str);
 }

 strcpy(alpha, str);
 arrange(alpha);

 printf("Original string is:-\n");
 print_str(str);
 printf("The arranged string in dictionary order is:-\n");
 print_str(alpha);
 return 0;
}

void read(char *str)
{
 printf("Enter the string\n");
 scanf("%s",str);
}

void arrange(char *ptr)
{
 int i,j,len=0;
 char temp;

 //Sorting of the Alphabets
 for(i=0; ptr[i]!='\0'; i++)
  len++;
 for(i=0; i<len; i++)
  for(j=0; j<len-i-1; j++)
 {
  if(*(ptr+j+1) < *(ptr+j))
  {
   temp = *(ptr+j);
   *(ptr+j) = *(ptr+j+1);
   *(ptr+j+1) = temp;
  }
 }
}

void print_str(char *str)
{
 int i;
 for(i=0; str[i]!='\0'; i++)
  printf("%c",*(str+i));
 printf("\n");
}

int check(char *str)
{
 int i;
 for(i=0; str[i]!='\0'; i++)
 {
  if(*(str+i)<65 || (*(str+i)>90 && *(str+i)<97) || *(str+i)>122)
   return 0;
 }
 return 1;
}
    
