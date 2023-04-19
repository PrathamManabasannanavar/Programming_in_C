//A simple C program to find and print wheather a triangle is formed by 3 sides or not?
#include<stdio.h>
#include<stdlib.h>

main()

{

      float a,b,c,A,B,C;
    
    printf("Enter the value of sides of triangle a,b,c\n");
    scanf("%f %f %f",&a,&b,&c);
    
       if(a>=b && b>=c)
           {
             A=a;B=b;C=c;
           }
        else if(b>=a && a>=c)
           {
             A=b;B=a;C=c;
           }
    
        else if(c>=a && a>=b)
           {
             A=c;B=a;C=b;
           }
        
        else if(c>=b && b>=a)
        {
            A=c;B=b;C=a;
        }
            
        else if(a>=c && c>=b)
        {
           A=a;B=c;C=b;
        }
        
        else if(b>=c && c>=a)
        {
           A=b;B=c;C=a;
        }
        
    
    printf("The sides of a Triangle are: %f %f %f\n\n\n",A,B,C);
   

    
    if(A<B+C)
    {
      printf("The triangle is formed\n");
    }
    
    else
      {
        printf("The triangle is not formed\n\n\n");
        exit(0);
      }
    
    
    float x=A*A; //A2 value
    float y=B*B+C*C; //B2+C2 value
    
       if(x==y)
        {
         printf("The triangle is Right angled\n");
        }
    
       else
        {
         printf("The triangle is not Right angled\n");
        }
        
        
}  

