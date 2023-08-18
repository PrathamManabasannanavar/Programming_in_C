// A simple C program for seperating the even and odd numbers into different files
#include<stdio.h>

void read_input(char *, int);
void print_input(char *);
void even_odd(char *);
main()
{
    char str[30];
    int n;
    printf("Enter file name\n");
    scanf("%s",str);
    printf("Enter the no of inputs\n");
    scanf("%d",&n);
    read_input(str, n);
    print_input(str);
    even_odd(str);
    printf("Even numbers are:-\n");
    print_input("even.txt");
    printf("Odd numbers are:-\n");
    print_input("odd.txt");
}

void read_input(char *str, int n)
{
    int no;
    FILE *fptr = fopen(str, "w");
    while(n>0)
    {
        printf("Enter the no\n");
        scanf("%d",&no);
        putw(no, fptr);
        n--;
    }
    fclose(fptr);
}

void print_input(char *str)
{
    int no;
    FILE *fptr = fopen(str, "r");
    while((no = getw(fptr)) != EOF)
    {
        //no = getw(fptr);
        printf("%d ",no);
        if(no == EOF)
            break;
    }
    printf("\n");
    fclose(fptr);
}

void even_odd(char *str)
{
    int no;
    FILE *fptr = fopen(str, "r");
    FILE *even = fopen("even.txt", "w");
    FILE *odd = fopen("odd.txt", "w");
    while((no = getw(fptr)) != EOF)
    {
        if(no % 2 == 0)
            putw(no, even);
        else
            putw(no, odd);
    }
    fclose(fptr);
    fclose(even);
    fclose(odd);
}