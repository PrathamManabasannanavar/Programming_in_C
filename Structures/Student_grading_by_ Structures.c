/*A simple C program to find and compute the
  details of n no of students using structures*/
#include<stdio.h>

struct student_details
{
 char name[50];
 int roll_no;
 float percentage;
};

main()

{
 int n,i;
 /*It can also be initialised as
 student[0] = {"Google",30,89.53}*/

 struct student_details student[100];

 printf("Enter the no of students\n");
 scanf("%d",&n); 

 for(i=0; i<n; i++)
 {
 printf("\nEnter details of student no %d:-\n\n",i+1);

 printf("Enter the name of student no %d:-\n",i+1);
 scanf("%s",student[i].name);

 printf("Enter the roll no of student no %d:-\n",i+1);
 scanf("%d",&student[i].roll_no);

 printf("Enter the percentage of student no %d:-\n",i+1);
 scanf("%f",&student[i].percentage);
 }

 printf("\n\n**The details of %d students are:**\n\n",n);
 for(i=0; i<n; i++)
 {
  printf("student %d details are:-\n",i);
  printf("Name:- "); puts(student[i].name);
  printf("Roll no:- %d\n",student[i].roll_no);
  printf("Percentage:- %f\n",student[i].percentage);
 }



}