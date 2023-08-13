#include<stdio.h>

void read_file(FILE *);
void copy_file(FILE *, FILE *);
main()
{
    FILE *fptr1 = fopen("hello1.txt", "w");
    FILE *fptr2 = fopen("hello2.txt", "a+");
    read_file(fptr1);
    fclose(fptr1);
    fptr1 = fopen("hello1.txt", "r");
    copy_file(fptr2, fptr1);
    fclose(fptr1);
    fclose(fptr2);
}

void read_file(FILE *fptr)
{
    char str[50];
    printf("Enter the contents of the file\n");
    fgets(str, sizeof(str), stdin);
    fputs(str, fptr);
}

void copy_file(FILE *fptr2, FILE *fptr1)
{
    int ch;
    while ((ch = fgetc(fptr1)) != EOF)
    {
        fputc(ch, fptr2);
    }
}
