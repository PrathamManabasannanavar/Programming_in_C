// A simple C program to find the marks of a student in a particular subjects
#include<stdio.h>

main()
{
   int i,j,m,n;
   int marks[30][30];
   int x,y; // Taking x & y to assign these to i and j

   printf("Enter the no of students, subjects \n");
   scanf("%d %d",&m,&n);

    for(i=0; i<m; i++)
    {
      printf("Enter the %d student's marks\n\n",i+1);
      for(j=0; j<n; j++)
      {
        printf("Enter %d subjects marks \n",j+1);
        scanf("%d",&marks[i][j]);
      }
       
    }  
    
   printf("\n");
   printf("The marks of the students are\n");

   for(i=0; i<m; i++)
   {
    printf("The %dth student marks are:- \n",i+1);
     for(j=0; j<n; j++)
      printf("%d ",marks[i][j]);
    
    printf("\n\n");
   }


   int largest,sum;

    for(j=0; j<n; j++) // Finding highest score in subjects
    {
     largest=0;
     for(i=0; i<m; i++)
     {
        if(marks[i][j]>largest)
        {
          largest=marks[i][j];
          x=i; y=j;
        }
     }   
         printf("The highest score in %d subject is %d marks by %dth person\n\n",y+1,largest,x+1);     
    }    


     for(i=0; i<m; i++) // Sum of marks scored in all subjects
    {
      sum=0;
       for(j=0; j<n; j++)
       {
        sum=sum+marks[i][j];
       }
      printf("The marks of %d student is %d\n",i,sum);
    }
}