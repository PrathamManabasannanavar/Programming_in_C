// A simple C program to capitalize the first letter in a word
// ex:- google Is the best search Engine ---> Google Is The Best Search Engine
#include<stdio.h>

void capitalize(char *);
main()
{
 char str[50];

 printf("Enter the string\n");
 scanf("%[^\n]s",str);

 capitalize(str);
 printf("Modified String is\n%s\n",str);
}

void capitalize(char *str)
{
 if(*str>='a' && *str<='z')
    *str -= 32;
 for(int i=0; str[i]!='\0'; i++)
 {
   if(*(str+i) == ' ' && (*(str+i+1)>='a' && *(str+i+1)<='z'))
   {
     *(str+i+1) -= 32;
     i++;
   }
 }
}
