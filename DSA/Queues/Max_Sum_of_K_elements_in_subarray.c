// A simple C program to implement the highest sum of k pairs in the array
//ex : {4, 8, 7, 9} and k = 3 --> largest sum is 24 because of {8,7,9}
#include<stdio.h>
#include<stdlib.h>

int queue[50];
int top = -1;
int bottom = 0;

int pop();
int push(int);
void read(int *, int);
void print(int *, int);
int kth_largest_sum(int *, int, int);

main()
{
    int n, k;
    printf("Enter the no of elements of the array\n");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    printf("Enter the %d elements of the array\n",n);
    read(arr, n);
    printf("Entered %d elements of the array are:\n",n);
    print(arr, n);
    printf("Enter the no of elements in subarray\n");
    scanf("%d",&k);
    printf("largest sum in subarray %d is = %d\n",k,kth_largest_sum(arr, n, k));
}

void read(int *arr, int n)
{
    for(int i=0; i<n; i++)
        scanf("%d",arr+i);
}

void print(int *arr, int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int push(int no)
{
    queue[++top] = no;
    return no;
}

int pop()
{
    if(bottom < top)
    {
        bottom++;
        return queue[bottom - 1];
    }
    else
        return 0;
}

int kth_largest_sum(int *arr, int n, int k)
{
    int sum = 0, largest = 0;
    for(int i=0; i<n; i++)
    {
        sum += push(arr[i]);
        if(top-bottom+1 > k)
            sum -= pop();
        if(largest < sum)
            largest = sum;
    }
    return largest;
}

// Time complexity: O(n)