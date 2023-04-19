/*A simple C program to find and compute the 
 Z value using real(int type) and imaginary(float type) value using 
structures and pointers*/
#include<stdio.h>
#include<stdio.h>

typedef struct complex_no {
int real;
float img;
}complx;


main()
{

 complx num;

 complx *ptr_num = &num;
 printf("Enter real and img value of num\n");
 scanf("%d %f",&num.real,&num.img);
 

 float ans = sqrt(pow(ptr_num->real,2)+pow(ptr_num->img,2));
 // or float ans = sqrt(pow((*ptr_num).real,2)+pow((*ptr_num).img,2)); 

 printf("Z = %f\n",ans);
}
