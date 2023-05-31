//A simple C program to find the lcm and hcf of two numbers by pointers
#include<stdio.h>

void gcd_lcm(int, int, int*, int*);
main()

{
 int a,b,gcd,lcm;

 printf("Enter the nos\n");
 scanf("%d %d",&a,&b);

 gcd_lcm(a,b,&lcm,&gcd);

 printf("gcd=%d\nlcm=%d\n",gcd,lcm);
}

void gcd_lcm(int a, int b, int *gcd, int *lcm)
{
 int x=a, y=b;

 while(a!=b)
 {
  if(a>b)
   a=a-b;

  else if(b>a)
   b=b-a;
 }

 *lcm=a;

 *gcd = x*y / *lcm;

}