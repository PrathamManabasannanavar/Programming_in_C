/*A simple C program to scan and print
 the details of employees using functions */
#include<stdio.h>

typedef struct employee_details
{
 char name[50];
 int roll_no;
 float salary;
} emp;

void scan_details(emp*, int);

main()
{
 int n,i;

 emp employee[100];
 emp *ptr = &employee; //using pointer

 printf("Enter the no of employees \n");
 scanf("%d",&n);
 scan_details(ptr,n); //passing structure to function

 //printing the details of employee 
 printf("The details of the employees are:\n\n");
 for(i=0; i<n; i++)
 {
  printf("\n\n\nName :- %s\n\n",employee[i].name);
  printf("Roll no:- %d\n\n",employee[i].roll_no);
  printf("Salary:- %f\n\n",employee[i].salary);
 }

}

void scan_details(emp *ptr, int n)
{
 int i;
 printf("***Enter the details of %d employees***\n\n",n);
 for(i=0; i<n; i++,ptr++)
 {
  printf("Enter the details of employee no %d \n\n",i+1);

  printf("Enter name of employee\n");
  scanf("%s",ptr->name);

  printf("Enter roll no of employee\n");
  scanf("%d",&ptr->roll_no);

  printf("Enter salary of employee\n");
  scanf("%f",&ptr->salary);
  printf("\n");
 }
}