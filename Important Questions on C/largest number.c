#include<stdio.h>
#include<math.h>
main()
{
    float a,b,c,x;
    
    printf("The value of a b c");
    scanf("%f,%f,%f",&a,&b,&c);
    
  x=(a>b)?a:((b>c)?b:c);
  printf("%f",x);

}