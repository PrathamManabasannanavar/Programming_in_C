// A simple C program to compute the employee details and salary after tax deduction
#include<stdio.h>

typedef struct employees
{
    char name[30];
    int age;
    float salary;
} emp;

int readInput(char *, int);
void printInput(char *, int, long);
void compute_tax(char *, int, long);
main()
{
    char filename[30];
    int n;
    printf("Enter the no of employees\n");
    scanf("%d",&n);
    printf("Enter name of the file\n");
    scanf("%s",filename);
    printf("Enter employee details\n");
    long index = readInput(filename, n);
    printf("Details of employee are:- \n");
    printInput(filename, n, index);
    compute_tax(filename, n, index);
}

int readInput(char *filename, int n)
{
    emp e1;
    FILE *fptr = fopen( filename, "w");
    fprintf(fptr, "Name\t Age\t Salary\n");
    long index = ftell(fptr);
    for(int i=0; i<n; i++)
    {
        printf("Enter name, age and Salary of employee %d\n",i+1);
        scanf("%s %d %f",e1.name, &e1.age, &e1.salary);
        fprintf(fptr,"%s\t %d\t %f\n",e1.name, e1.age, e1.salary);
    }
    fclose(fptr);
    return index;
}

void printInput(char *filename, int n, long index)
{
    emp e1;
    FILE *fptr = fopen( filename, "r");
    fseek(fptr, index, SEEK_SET);
    for(int i=0; i<n; i++)
    {
        fscanf(fptr, "%s %d %f",e1.name, &e1.age, &e1.salary);
        printf("Employee %d details\n",i+1);
        printf("Name : %s\nAge : %d\nSalary : %f\n\n",e1.name, e1.age, e1.salary);
    }
    fclose(fptr);
}

void compute_tax(char *filename, int n, long index)
{
    emp e1;
    float tax;

    FILE *fptr = fopen(filename, "r");
    fseek(fptr, index, SEEK_SET);
    for(int i = 0; i < n; i++)
    {
        fscanf(fptr, "%s %d %f", e1.name, &e1.age, &e1.salary);
        if(e1.salary >= 5000 && e1.salary < 15000)
            tax = e1.salary / 10; // 10% tax
        else if(e1.salary > 15000 && e1.salary <= 20000)
            tax = e1.salary / 5; // 20% tax
        else
            tax = 0;
        printf("Salary of employee %d after tax deduction is %fRs\n", i + 1, e1.salary - tax);
    }
}