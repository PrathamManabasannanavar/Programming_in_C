//A simple C program to read the student details and conpute the highest marks of the student
#include<stdio.h>

typedef struct student_details
{
  char name[20];
  struct DOB
  {
    char month[20];
    int date;
    int year;
  }dob;
 int roll_no;
 float percentage;
}std;

void read(std *, int);
void print_details(std *, int);
std* highest(std *, int n);
main()
{
  std student[50];
  int n;

  printf("Enter no of students\n");
  scanf("%d",&n);

  read(student,n);
  printf("Details of students are:-\n");
  print_details(student,n);
  
  std *ptr = highest(student,n);
  printf("\n\nStudent who scored highest marks is %s and percentage = %f\n",ptr->name, ptr->percentage);
}

void read(std *student, int n)
{
 int i;
 for(i=0; i<n; i++)
 {
   printf("Enter the details of the student no %d\n",i+1);
   printf("Enter the name of the student\n");
   scanf("%s",student[i].name);
   printf("Enter the DOB of the student\n");
   scanf("%d %s %d",&student[i].dob.date,student[i].dob.month,&student[i].dob.year);
   printf("Enter the roll no of student\n");
   scanf("%d",&student[i].roll_no);
   printf("Enter the percentage of the student\n");
   scanf("%f",&student[i].percentage);
 }
}

void print_details(std *student, int n)
{
 int i;
 for(i=0; i<n; i++)
 {
  printf("Student %d details is\n",i+1);
  printf("Name:- %s\n",student[i].name);
  printf("DOB:- %d %s %d\n", student[i].dob.date, student[i].dob.month, student[i].dob.year);
  printf("Roll no:- %d\n", student[i].roll_no);
  printf("Percentage:- %f\n",student[i].percentage);
 }
}

std* highest(std *student, int n)
{
 int i;
 float high=student[0].percentage;
 std *ptr;

 for(i=0; i<n; i++)
   if(student[i].percentage > high)
   {
      high = student[i].percentage;
      ptr = &student[i];
   }
 return ptr;
}
    