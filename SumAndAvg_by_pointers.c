#include<stdio.h>

void sumAndAvg(int,int,int,int*,float*);
main()

{
 int sum,a,b,c;
 float avg;

 printf("Enter the value of a,b,c\n");
 scanf("%d %d %d",&a,&b,&c);

 sumAndAvg(a,b,c,&sum,&avg);

 printf("The sum and avg of %d, %d and %d are %d and %f\n",a,b,c,sum,avg);
}

void sumAndAvg(int x, int y, int z, int*sum,float*avg)
{
 *sum=x+y+z;
 *avg=*sum/3.0;
}