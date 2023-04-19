#include<stdio.h>

main()

{
 long int a[20]={3,6,25,2,};
  int i,j,largest1=a[0],largest2=a[0];
  int n=5;

   for(i=0; i<n; i++)
         if(a[i]>largest1)
             largest1=a[i];
            
            i=0;
     for(i=0; i<n; i++)
            if(largest2 < a[i] && a[i]!=largest1) {
              largest2=a[i];
              }

   printf("The largest no is %d and 2nd largest no is %d\n",largest1,largest2);

}