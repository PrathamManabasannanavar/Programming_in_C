#include<stdio.h>
main()

{


      int n,i,rem,rev=0,sum=0;
    
    
    printf("Enter the no\n");
    scanf("%d",&n);
    
         while(n!=0)
            {
            
                rem=n%10;
                rev=rev*10+rem;
                
            sum=sum+rem*rem;
                n=n/10;
                
                
            
            }


        printf("The reversed no is: %d \n",rev);
        
        printf("The sum of reversed no is %d\n",sum);




}