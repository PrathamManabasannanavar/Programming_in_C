#include<stdio.h>

main()

{
 int i;
 int a[50];
 int n;
 
 // a[50]={2,3,41,78,54};
 int* ptr=&a[0];// int* ptr=&a
 
 printf("Enter no of elements of array\n");
 scanf("%d",&n);

 printf("Enter the elements of array\n");
 for(i=0; i<n; i++,ptr++)
 scanf("%d",ptr);
 for(i=0; i<5; i++)
  
 ptr=&a;
 for(i=0; i<n; i++,ptr++)
  printf("%u ",*ptr);

}
