#include<stdio.h>
int sum(int a, int b);


 main()

{
    int a,b;
    
   printf("Enter the value of a and b\n");
   scanf("%d %d",&a,&b);

    int c;
    sum(a, b);
    
    printf("sum is %d\n",sum(a,b));
   
}

int sum(int a,int b)
{
   int sum=a+b;
   return sum;
    
}

    