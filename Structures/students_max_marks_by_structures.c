// A simple C program to compute the marks of the students using structures
#include<stdio.h>

typedef struct students
{
 char name[20];
 int sub[10];
 int sum;
 int highest;
}std;

main()

{
  int i,j,m,n;
  std student[20];

  printf("Enter the no of the students\n");
  scanf("%d",&n);

  printf("Enter the no of the subjects\n");
  scanf("%d",&m);

  for(i=0; i<n; i++)
  {
    printf("Enter the student no %d details\n",i+1);
    printf("Enter the name of the student\n");
    scanf("%s",student[i].name);
    student[i].sum = 0;
    printf("Enter the marks of the student\n");
    for(j=0; j<m; j++)
    {
       printf("Enter sub %d marks\n",j+1);
       scanf("%d",&student[i].sub[j]);
       student[i].sum += student[i].sub[j];
    }
    printf("\n");
  }

  int largest = student[0].sum; // largest marks scored among the students
  int var; 
  for(i=0; i<n; i++)
  {
    if(largest<student[i].sum)
    {
       largest = student[i].sum;
       var = i; //To find the index of student
    }
    
    student[i].highest = student[i].sub[0];
    for(j=0; j<m; j++)
      if(student[i].highest < student[i].sub[j])
         student[i].highest = student[i].sub[j];
        
    printf("Highest marks of student %d is %d\n",i, student[i].highest);
  }
  printf("\nName of the student who scored highest marks is %s and marks is %d\n", student[var].name, student[var].sum);
}