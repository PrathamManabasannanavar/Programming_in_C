// A simple C program to find the SGPA of the student
#include<stdio.h>

typedef struct subjects
{
    char name[20];
    int sem_marks;
    int ia_marks;
    //char grade;
    int credits;
} subjects;

void read(subjects *, int);
void print(subjects *, int);
float compute_cgpa(subjects *, int);
void grade(float);

main()
{
    subjects subject[20];
    int n;
    printf("Enter no of subjects:\n");
    scanf("%d",&n);
    printf("Enter total marks in each subject:\n");
    read(subject, n);
    printf("Marks in each subject is:\n");
    print(subject, n);
    float cgpa = compute_cgpa(subject, n);
    printf("Your SGPA = %f\n",cgpa);
    grade(cgpa);
}

void read(subjects *subject, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Enter the name of sub %d\n",i+1);
        scanf("%s", subject[i].name);
        printf("Enter IA marks and SEE marks of %s\n", subject[i].name);
        scanf("%d %d",&subject[i].ia_marks, &subject[i].sem_marks);
        //printf("Enter the grade of %s\n", subject[i].name);
        //scanf(" %c",&subject[i].grade);
        printf("Enter the credit of %s\n", subject[i].name);
        scanf("%d",&subject[i].credits);
        printf("\n");
    }
}

void print(subjects *subject, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("For %s:-\n", subject[i].name);
        printf("SEE marks : %d and IA marks : %d\n", subject[i].sem_marks, subject[i].ia_marks);
        //printf("Grade : %c\n",subject[i].grade);
        printf("Credits : %d\n\n",subject[i].credits);
    }
}

float compute_cgpa(subjects *subject, int n)
{
    float sum = 0;
    int credits = 0;
    for(int i=0; i<n; i++)
    {
        if(subject[i].credits != 1)
            sum += ((subject[i].ia_marks + subject[i].sem_marks/2) * subject[i].credits/10);
        else
            sum += ((subject[i].ia_marks + subject[i].sem_marks) * subject[i].credits/10);
        credits += subject[i].credits;
    }

    return sum/credits;
}

void grade(float cgpa)
{
    if(cgpa > 9 && cgpa <= 10)
        printf("Grade : S\n");
    else if(cgpa > 8 && cgpa <= 9)
        printf("Grade : A\n");
    else if(cgpa > 6.5 && cgpa <= 8)
        printf("Grade : B\n");
    else if(cgpa > 5 && cgpa <= 6.5)
        printf("Grade : C\n");
    else if(cgpa > 3.5  && cgpa <= 5)
        printf("Grade : D\n");
    else if(cgpa >= 1 && cgpa <= 3.5)
        printf("Grade : E\n");
    else
        printf("Grade : F\n");
}