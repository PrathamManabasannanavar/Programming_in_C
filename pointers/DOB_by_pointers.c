/*A simple C program to find and compute 
the date of birth of an individual using pointers */
#include<stdio.h>

void convert(int*, int*);
int add(int*, int*, int*);
int diff(int*, int*);
void age(int*, int*, int*, int*);

main()

{
 int days,months,years;
 int *ptr_months=&months;
 int *ptr_years=&years;
 int present_day, present_month, present_year;
 
 printf("Enter your date of birth in the format DATE/MONTH/YEAR \n");
 scanf("%d %d %d",&days, &months, &years);

 printf("Enter today's date\n");
 scanf("%d %d %d",&present_day, &present_month, &present_year);

 convert(ptr_months, ptr_years);
 convert(&present_month, &present_year);

 int DOB_days=add(&days, &months, &years); //adds the total no of days
 int present_days=add(&present_day, &present_month, &present_year); //adds the total no of days

 int diff_days = diff(&DOB_days, &present_days); //for taking difference between today's date and your DOB 

 int age_years;
 int age_months;
 int age_days;

 age(&age_days, &age_months, &age_years, &diff_days);

 printf("The persons age is:- \n");
 printf("%d years\n%d months\n%d days\n",age_years,age_months, age_days);
}

void convert(int *ptr1, int *ptr2)
{
 *ptr1*=30;
 *ptr2*=12*30;
}

int add(int *ptr1, int *ptr2, int *ptr3)
{
 int sum=*ptr1 + *ptr2 + *ptr3;
 return(sum);
}

int diff(int *ptr1, int *ptr2)
{
 int difference = *ptr2 - *ptr1;
 return(difference);
}

void age(int *ptr1, int *ptr2, int *ptr3, int *ptr)
{
 int rem;
 
 rem=*ptr % (12*30);
 *ptr3= *ptr/(12*30);
 *ptr1= rem % 30;
 *ptr2= rem/30;
}
