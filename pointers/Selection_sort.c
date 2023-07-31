// A simple C program to perform Selection sort
#include<stdio.h>

void read(int *, int);
void print(int *, int);
void selection_sort(int *, int);
void swap(int *, int *);

main()
{
    int arr[50], n;
    printf("Enter the no of elements\n");
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    read(arr, n);
    printf("Entered elements of the array are:\n");
    print(arr, n);
    selection_sort(arr, n);
    printf("Array after sorting is\n");
    print(arr, n);
}

void read(int *arr, int n)
{
    for(int i=0; i<n; i++)
        scanf("%d",arr+i);
}
void print(int *arr, int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void selection_sort(int *arr, int n)
{
    int min;
    for(int i=0; i<n-1; i++)
    {
        min = i;
        for(int j=i+1; j<n; j++)
            if(arr[j] < arr[min])
                min = j;
        if(min > i)
            swap(&arr[i], &arr[min]);
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}