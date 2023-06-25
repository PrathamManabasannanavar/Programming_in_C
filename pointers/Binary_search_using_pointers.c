// A simple C program to perform binary search using pointers
#include<stdio.h>

void read(int *, int);
void print_arr(int *, int);
int binary_search(int *, int, int);
void insertion_sort(int *, int);

main()
{
 int marks[50],n,key;

 printf("Enter the no of the students\n");
 scanf("%d",&n);

 printf("Enter the marks of the student\n");
 read(marks,n);
 printf("The marks of the student are:-\n");
 print_arr(marks,n);
 
 printf("Enter the key to be searched\n");
 scanf("%d",&key);

 insertion_sort(marks, n);

 int found = binary_search(marks,n,key);
 if(found > 0)
    printf("Element found in the array\n");
 else
    printf("Element not found in the array!!\n");

}

void read(int *marks, int n)
{
  for(int i=0; i<n; i++)
    scanf("%d",marks+i);
}

void print_arr(int *marks, int n)
{
  for(int i=0; i<n; i++)
     printf("%d ",*(marks+i));
  printf("\n");
}

int binary_search(int *marks, int n, int key)
{
 int low=0, high=n-1,mid;
 while(low<=high)
 {
    mid = (low + high)/2;
    
    if(*(marks+mid) == key)
        return 1;
    else if(*(marks+mid) < key)
         low = mid+1;
    else
         high = mid-1;
 }
 return -1;
}

void insertion_sort(int *marks, int n)
{
 int temp,i,j;
 for(i=1; i<n; i++)
 {
    temp = *(marks+i);
    for(j=i-1; j>=0; j--)
    {
      if(*(marks+j) > *(marks+j+1))
          *(marks + j + 1) = *(marks + j);
      else
           break;
    }
    *(marks+j+1) = temp;
 }
}
