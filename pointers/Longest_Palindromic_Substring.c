// A simple C program to find the smallest Palindromic Substring in a string
//ex : 14oppomalayalam  ---> Length of Longest Palindrome Substring is 9 i.e 'malayalam' before 'oppo' 
#include<stdio.h>
#include<string.h>

int substring(char *);
int check_palindrome(char *, int, int);
main()
{
 char str[50];

 printf("Enter the string\n");
 scanf("%s",str);
 int palindrome = substring(str);

 if(palindrome > 0)
   printf("Longest length of the Palindromic Substring is: %d\n",palindrome);
 else
   printf("Palindromic substring not found!!\n");

}

int substring(char *str)
{
 int i=0, j, len=strlen(str), longest = 0;
  
  for(i=0; i<len; i++)
    for(j=len-1; j>i; j--)
    {
      if(longest < j-i && str[j] == str[i])
         if(check_palindrome(str,i,j) == 1)
          {
             longest = j-i;
          }
    }
 if(longest > 0)
     return longest+1;
 else
     return -1;
}

int check_palindrome(char *str, int start, int end)
{
 int j = end;
 for(int i=start; i<=end; i++,j--)
    if(str[i] != str[j])
       return -1;
 return 1;
}