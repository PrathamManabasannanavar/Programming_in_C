//A simple C program to separate even and odd numbers in different files
#include<stdio.h>
#include<stdlib.h>

main ()
{
    int no, n;
    FILE *fptr, *even, *odd;
    fptr = fopen ("test.txt", "w");
    if(fptr == NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }

    printf ("Enter the count of numbers you want to store\n");
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf ("Enter the number %d\n",i+1);
        scanf ("%d", &no);
        fprintf (fptr, "%d ", no);
        //putw(no, fptr);
    }
    fclose (fptr);
    fptr = fopen ("test.txt", "r");
    even = fopen ("even.txt", "a");
    odd = fopen ("odd.txt", "a");
    fprintf(even, "The even numbers are:\n");
    fprintf(odd, "The odd numbers are:\n");
    while (fscanf(fptr, "%d",&no) != EOF)
    {
        if (no % 2 == 0)
            fprintf (even, "%d ", no);
        else
            fprintf (odd, "%d ", no);
    }
    fclose (fptr);
}

/*#include<stdio.h>
#include<stdlib.h>

main ()
{
    int no, n;
    FILE *fptr, *even, *odd;
    fptr = fopen ("test.txt", "w");
    if(fptr == NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }

    printf ("Enter the count of numbers you want to store\n");
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf ("Enter the number %d\n",i+1);
        scanf ("%d", &no);
        //fprintf (fptr, "%d ", no);
        putw(no, fptr);
    }
    fclose (fptr);
    //printf("Hello\n");
    fptr = fopen ("test.txt", "r");
    even = fopen ("even.txt", "a");
    odd = fopen ("odd.txt", "a");
    fprintf(even, "The even numbers are:\n");
    fprintf(odd, "The odd numbers are:\n");
    while((no = getw(fptr)) != EOF) // !feof(fptr);
    {
        //no = getw(fptr);
        if (no % 2 == 0)
            fprintf(even, "%d ", no); // preferred one is fwrite()
            //putw(no, even); //Prints in binary
        else
            fprintf (odd, "%d ", no);
    }
    fclose (fptr);
    fclose(even);
    fclose(odd);
}
*/