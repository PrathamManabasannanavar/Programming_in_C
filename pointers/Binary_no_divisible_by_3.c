// A simple C program to compute the binary no is divisible by 3 or not?
#include<stdio.h>
#include<stdlib.h>

int isdivisible(char *);
void check(char *);
int main()
{
 char str[100];

 printf("Enter the binary no\n");
 scanf("%s",str);

 check(str);
 int flag = isdivisible(str);
 if(flag == 1)
    printf("Number is divisible by 3\n");
 else
    printf("Number is not divisible by 3\n");
 return 0;
}

int isdivisible(char *str)
{
 int even_count=0,odd_count=0;
  for(int i=0; str[i]!='\0'; i++)
  {
   if(str[i] == '1')
   {
      if(i%2 == 0)
        even_count++;
      else
        odd_count++;
   }
  }
  if(even_count == odd_count) // count of even and add indexes are same i.e 1
    return 1;
  else if((even_count % 3 == 0 || odd_count % 3 == 0) && (even_count>=3 || odd_count>=3))
    return 1; //even number or odd number indices should be in pair of 3
 return 0;
}

void check(char *str)
{
 for(int i=0; str[i]!='\0'; i++)
   if(str[i]!='1' && str[i]!='0')
   {
     printf("Enter the valid number!!\n");
     exit(0);
   }
}