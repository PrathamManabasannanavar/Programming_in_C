// A simple C program to find the Lowest +ve integer among the given array
#include<stdio.h>

void read(int *, int);
void print(int *, int);
int missing_no(int *, int);
void quick_sort(int *, int, int);
void swap(int *, int *);

main()
{
  int arr[50],n;
  printf("Enter the no of elements of the array\n");
  scanf("%d",&n);

  printf("Enter elements of the array\n");
  read(arr, n);

  printf("Entered elements are:-\n");
  print(arr,n);

  quick_sort(arr, 0, n-1);
  printf("Smallest +ve missing number is %d\n",missing_no(arr,n));
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

int missing_no(int *arr, int n)
{
 int i;
 for(i=0; i<n; i++)
 {
  if(arr[i] < 0 || arr[i]+1 == arr[i+1])
      continue;
   else
      break;
  }
 return arr[i]+1;
}

void quick_sort(int *arr, int low, int high)
{
  if (low < high)
  {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
      if (arr[j] <= pivot
      {
        i++;
        swap(&arr[i], &arr[j]);
      }
    }
    swap(&arr[i+1], &arr[high]);
    quick_sort(arr, low, i);
    quick_sort(arr, i+2, high);
  }
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
    