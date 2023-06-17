//A simple C program to find to convert digits in numbers to alphabets
// ex:- 123    one two three
#include<stdio.h>
#include<stdlib.h>

int extract(int *, int);
void print_no(int *, char (*)[10], int);
main()

{
 char str[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
 int num, a[50];

 printf("Enter the number\n");
 scanf("%d",&num);

 if(num<0)
 {
  printf("Enter a +ve number!!\n");
  exit(0);
 }

 int digits = extract(a,num);

 print_no(a, str, digits);

}

int extract(int *ptr, int num)
{
 int count=0;
 while(num!=0)
 {
   *(ptr+count) = num%10;
   num=num/10;
   count++;
 }
 return count;
}

void print_no(int *a, char (*str)[10], int digits)
{
 int i,j;
 printf("The numbers to alphabet conversion is :-\n");
 for(i=digits-1; i>=0; i--)
  for(j=0; j<=9; j++)
    if(*(a+i) == j)
      printf("%s ",*(str+j));
}