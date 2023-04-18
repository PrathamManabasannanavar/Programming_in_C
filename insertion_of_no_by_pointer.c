//A simple C program to insert a no in array
#include<stdio.h>

main()

{
 int a[50],m,key,pos,i;
 //int b[50],n;
 int *ptr1=&a[0];
 int *ptr2, *ptr3;
 int swap;

 printf("Enter the no elements of array\n");
 scanf("%d",&m);

 ptr2=ptr1+m;

 printf("Enter the elements of array\n");
 for(i=0; i<m; i++)
  scanf("%d",ptr1+i);

 printf("Enter the key and pos of key to be entered\n");
 scanf("%d %d",&key,&pos);
 ptr3=&a[pos];

 for(i=m; i>pos; i--,ptr2--)
 {
 //for(i=0; i<m-pos; i++,ptr3++) 
  swap=*(ptr2-1);
  *(ptr2-1)=*(ptr2);
  *(ptr2)=swap;
 }

 a[pos]=key;
 for(i=0; i<m+1; i++)
  printf("%d ",a[i]);
}