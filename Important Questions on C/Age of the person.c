#include<stdio.h>
#include<math.h>
main()
{
   float a,b,c,x,y,z,T,p,q,r,A,B,C,DOB,P,Q,R,S;
    
    printf("Enter the your DOB\n");
    scanf("%f %f %f",&a,&b,&c);
    
       x=a;
       y=b*30;
       z=c*12*30;
    
    T=x+y+z;
    

    printf("Enter today's date\n");
    scanf("%f %f %f",&p,&q,&r);
    
 
       A=p;
       B=q*30;
       C=r*30*12;
    
    P=(A+B+C)-T;
    
    Q=P/(12*30);
    R=P/(30);
    S=C;
    
  printf("The age of the person is\n");
  printf("%f years\n",Q);
  printf("%f months\n",R);
  printf("%f days\n",S);



}