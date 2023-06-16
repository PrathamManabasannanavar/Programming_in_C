//A simple C program to delete a occurence of a particular character from a string
#include<stdio.h>
#include<stdlib.h>

int search(char *, char, int );
void delete(char *, int, int);
int str_len(char *);

main()

{
 char str[50], ch;
 int len;

 printf("Enter the string\n");
 scanf("%s",str);

 len = str_len(str);
 printf("Enter character to be deleted\n");
 scanf(" %c",&ch);

 len = search(str,ch,len);
 
 printf("The string is:-\n %s\n",str);
}

int search(char *str, char ch, int len)
{
 int i, count=0;
 for(i=0; i<len; i++)
 {
  if(*(str+i) == ch)
  {
    delete(str,i,len);
    i=i-1; //very important in case of repeated characters
    len--; count=1;
  }
  else if(count==0)
  {
   printf("Entered character not found in the string!!\n");
   exit(0);
  }
 }

 return len;
}

int str_len(char *str)
{
 int i;
 for(i=0; *(str+i)!='\0'; i++);
 return i;
}

void delete(char *str, int first, int len)
{
 int i;
 for(i=first; i<len; i++)
 {
   *(str+i) = *(str+i+1);
 }
  *(str+len)='\0';
}
