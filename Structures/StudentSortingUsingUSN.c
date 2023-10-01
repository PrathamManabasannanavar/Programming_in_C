// A simple C program to sort the students based on the USN
// USN format : 2sd22cs063
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 50

typedef struct STUDENT_DETAILS
{
    char name[size];
    int rollno;
    char usn[size];
} std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapStudent(std *a, std *b)
{
    std temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(std *student, int n, int *arrange)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arrange[j] > arrange[j+1])
            {
                swap(&arrange[j], &arrange[j+1]);
                swapStudent(&student[j], &student[j+1]);
            }
        }
    }
}

void extractNo(std *student, int n, int *arrange)
{
    for(int i=0; i<n; i++)
    {
        arrange[i] = 0;
        for(int j=strlen(student[i].usn)-3; j<strlen(student[i].usn); j++)
            arrange[i] = arrange[i] * 10 + student[i].usn[j] - '0';
    }        
}

void displayDetails(std *student)
{
    printf("Name : %s\n", student->name);
    printf("Roll no : %d\n", student->rollno);
    printf("USN : %s\n\n", student->usn);
}

void sortUsn(std *student, int n)
{
    int *arrange = (int *)calloc(n, sizeof(int));
    extractNo(student, n, arrange);
    bubbleSort(student, n, arrange);
    free(arrange);
    for(int i=0; i<n; i++)
    {
        printf("Student %d details\n",i+1);
        displayDetails(&student[i]);
    }
}

void readDetails(std *student, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Enter student no %d details:-\n",i+1);
        printf("Enter the name\n");
        scanf("%s", student[i].name);
        printf("Enter the Roll no\n");
        scanf("%d", &student[i].rollno);
        printf("Enter the USN\n");
        scanf("%s", student[i].usn);
    }
    printf("\n");
}

main()
{
    std student[size];
    int n;
    printf("Enter the no of students\n");
    scanf("%d",&n);
    readDetails(student, n);
    sortUsn(student, n);
}