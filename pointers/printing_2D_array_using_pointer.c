#include<stdio.h>

main()

{
 int row_size,col_size;

 printf("Enter row size and col size\n");
 scanf("%d %d",&row_size,&col_size);

 int a[row_size][col_size];
 int *ptr=&a;
 int i,j,m=row_size,n=col_size;
  
 ptr=&a[0];
 printf("Enter the elements of matrix\n");
 for(i=0; i<m; i++) 
  for(j=0; j<n; j++,ptr++){
   scanf("%d ",ptr);
   //printf(" address is %u\n ",ptr);
  }

 ptr=&a;
 for(i=0; i<m; i++) 
  for(j=0; j<n; j++)
   printf("%d ",*ptr++);

}
