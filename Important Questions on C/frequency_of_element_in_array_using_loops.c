#include<stdio.h>
#define size 100
// frequency of a element in a array
main()
{
   int i,j,n;
   int a[size];
    
       printf("Enter the no of elements\n");
       scanf("%d",&n);
 
       printf("Enter %d elements\n",n);
       for(i=0; i<n; i++)
          scanf("%d",&a[i]);

       int key[100],k;
       printf("Enter the no of keys to be searched\n");
       scanf("%d",&k);
    
       printf("Enter the %d keys to be searched\n",k);
       for(j=0; j<k; j++)
         scanf("%d",&key[j]);

      int count[100];
       for(i=0; i<n; i++)//Elements
       {
             for(j=0; j<n; j++)// key comparison
              {
                 if(key[j]==a[i])
                     count[j]++;
              }
             
       }
         j=0;

      for(i=0; i<k; i++)
       {
         printf("The key %d occurs %d times\n",key[j],count[j]);
       }


}