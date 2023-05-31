//A simple C program to find wheather the no is Palindrome or not
#include<stdio.h>

int palindrome(int);
main()

{
 int num, flag;

 printf("Enter a no\n");
 scanf("%d",&num);

 flag=palindrome(num);

 if(flag==1)
  printf("It is a Palindrome\n");

 else
  printf("It is not a Palindrome\n");
}

int palindrome(int n)
{
 int rev=0,rem,real=n;

 while(n!=0)
 {
  rem=n%10;
  rev=rev*10+rem;
  n=n/10;
 }

 if(real==rev)
  return 1;
 else
  return 0;
}