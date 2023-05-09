#include<stdio.h>

typedef struct marks
{
    char name[50];
    float marks;
}mk;

main()

{
 int n,i;   
 mk student[50];   
 mk *ptr = &student;
 
    printf("Enter the no of students\n");
    scanf("%d",&n);
    
    printf("Enter student details\n");
    for(i=0; i<n; i++,ptr++)
    {
        printf("Enter the name of the student no %d\n",i);
        scanf("%s",ptr->name);
        
        printf("Enter the marks of the student no %d\n",i);
        scanf("%f",&ptr->marks);
    }
    
    FILE *fptr;
    fptr = fopen("student_text.txt","w");
    fprintf(fptr,"The details of students is\n\n");
    
    ptr = &student;
    for(i=0; i<n; i++,ptr++)
    {
        fprintf(fptr,"The details of student no %d is:-\n",i);
        fprintf(fptr,"NAME : %s\n",ptr->name);
        fprintf(fptr,"MARKS : %f\n",ptr->marks);
    }
    
    float greatest = student[0].marks;
    ptr = &student;
    for(i=0; i<n; i++,ptr++)
    {
        if(ptr->marks > greatest)
         greatest = ptr->marks;
    }
    fprintf(fptr,"The largest marks obtained is %f \n",greatest);
    char var[50];
    
    for(i=0; i<n; i++)
    {
        if(student[i].marks == greatest)
         fprintf(fptr," and name of the student is:-  %s",student[i].name);
    }
    fclose(fptr);
}
