#include<stdio.h>
int swap(int*, int*);

main()

{
  int a=3, b=10;
  //int* x=&a,y=&b;
   swap(&a,&b);
  printf("a=%d and b=%d\n",a,b);
}

int swap(int* x, int*y)
{
 int temp;
    temp=*x;
    *x=*y;
    *y=temp;
 return(0);
}