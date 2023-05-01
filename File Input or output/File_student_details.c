/*A simple C program to input and
print the details in another file*/
#include<stdio.h>

typedef struct student_marks
{
    char name[50];
    float score;
}st;

main ()
{
  st students[50];
  st *ptr = &students; //pointer of datatype st
  
  int i,n;
  
  printf("Enter no student of students\n");
  scanf("%d",&n);
  
  for(i=0; i<n; i++, ptr++)
  {
      printf("Enter name of %d student \n",i+1);
      scanf("%s",&ptr->name);
      
      printf("Enter the score\n");
      scanf("%f",&ptr->score);
  }
  
  FILE *fptr; //file pointer
  fptr=fopen("Student_details.txt", "w");
  ptr=&students;
  
  for(i=0; i<n; i++,ptr++)
  {
      fprintf (fptr,"Name= %s\n",ptr->name);
      fprintf(fptr, "Score= %f\n\n",ptr->score);
  }


  fclose (fptr);

}
