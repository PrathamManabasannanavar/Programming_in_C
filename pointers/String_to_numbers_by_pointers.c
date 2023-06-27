//A simple C program to convert the numbers in string to integers and compute their sum
#include<stdio.h>
#include<stdlib.h>

int numbers(char *,int *arr);
void print_no(int *, int);
int sum(int *, int);
main()

{
  char str[50];
  int arr[50];

  printf("Enter the string\n");
  scanf("%s",str);

  int len = numbers(str,arr); // count of numbers in string
  printf("The numbers in string are:-\n");
  print_no(arr,len);
  printf("Sum of the numbers in the string = %d\n",sum(arr,len));
}

int numbers(char *str, int *arr)
{
  int i,j=0,found=0;
  for(i=0; str[i]!='\0'; i++)
    if(*(str+i) >= '0' && *(str+i) <= '9')
    {
       *(arr + j) = *(str + i) - '0';
       j++; found = 1;
    }
  if(found == 0)
  {
    printf("No number found in a string!!\n");
    exit(0);
  }
  return j;
}

void print_no(int *arr, int n)
{
  for(int i=0; i<n; i++)
    printf("%d ",*(arr+i));
  printf("\n");
}

int sum(int *arr, int n)
{
  int add=0;
  for(int i=0; i<n; i++)
    add += *(arr+i);
  return add;
}