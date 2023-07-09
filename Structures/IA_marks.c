// A simple C program to compute the IA marks of the students using structures
#include<stdio.h>
#define SIZE 50

typedef struct marks
{
  char name[30];
  int roll_no;
  int IA[3],total, CTA;
}marks;

void read(marks *, int);
void print(marks *, int);
void result(marks *, int);
int check(int *);
main()
{
  marks student[SIZE];
  int n;
  printf("Enter the number of students\n");
  scanf("%d",&n);
  printf("Enter the details of students\n");
  read(student,n);
  result(student,n);
  printf("Entered the details of students is:-\n");
  print(student,n);
}

void read(marks *student, int n)
{
 for(int i=0; i<n; i++)
 {
   printf("Enter the student no %d details\n",i+1);
   printf("Enter the name of the student\n");
   scanf("%s",(student+i)->name);
   printf("Enter the roll no of the student\n");
   scanf("%d",&(student+i)->roll_no);
   read:
   printf("Enter the IA1,IA2 and IA3 marks of the student\n");
   for(int j=0; j<3; j++)
     scanf("%d",&(student+i)->IA[j]);
   if(check((student+i)->IA) == 0)
       goto read;
   cta:
   printf("Enter CIA marks of the student\n");
   scanf("%d",&(student+i)->CTA);
   if((student+i)->CTA < 0 || (student+i)->CTA > 10)
   {
     printf("Enter the marks between 0 and 10!!\n");
     goto cta;
   }
   student[i].total = student[i].CTA;
 }
}

void print(marks *student, int n)
{
 for(int i=0; i<n; i++)
 {
   printf("The details of students no %d is:\n",i+1);
   printf("Name : %s\n",(student+i)->name);
   printf("Roll no : %d\n",(student+i)->roll_no);
   printf("IA marks are\n");
   for(int j=0; j<3; j++)
     printf("IA%d = %d\n",j+1,(student+i)->IA[j]);
   printf("CTA marks = %d\n",(student+i)->CTA);
   printf("Total marks : %d\n",(student+i)->total);
 }
}

void result(marks *student, int n)
{
  for(int i=0; i<n; i++)
  {
     if(student[i].IA[0] > student[i].IA[1])
     {
       if(student[i].IA[1] > student[i].IA[2])
          student[i].total += student[i].IA[0] + student[i].IA[1];
       else
          student[i].total += student[i].IA[0] + student[i].IA[2];
     }
     else
       student[i].total += student[i].IA[1] + student[i].IA[2];
  }
}

int check(int *arr)
{
 for(int i=0; i<3; i++)
   if(arr[i] < 0 || arr[i] > 20)
   {
      printf("Enter the marks between 0 to 20!!\n");
      return 0;
   }
 return 1;
}