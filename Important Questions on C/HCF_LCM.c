//A C program to find to evaluate and print the LCM
#include<stdio.h>

main()

{
    int lcm,hcf,a,b,i,max;
    
     printf("Enter two no\n");
     scanf("%d %d",&a,&b);
    
       max=(a>b)?a:b;
    
    if(max%a==0 && max%b==0)
             printf("LCM is %d",max);
    
    else
   {
         while(max%a!=0 || max%b!=0)
           max++;    
        
       printf("The LCM  is %d\n",max);
   }


   //A C program to find and evaluate the HCF of two no

    
    max=(a>b)?a:b;
    
        for(i=1; i<=max; i++)
       {
           if(a%i==0 && b%i==0)
           {
              hcf=i;
           }
       }
      
     printf("HCF is %d\n",hcf);
    
    
    


}