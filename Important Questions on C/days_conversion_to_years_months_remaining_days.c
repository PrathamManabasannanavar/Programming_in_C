//A simple C program to convert days into years,months,remaining days
#include<stdio.h>

main()

{

     int months,years,days,remaining_days;
    
             printf("Enter the days\n");
             scanf("%d",&days);

        years=days/365;
        months=days%365;
        remaining_days=months%30; //IMPORTANT 
        months=months/30; //IMPORTANT
    
           printf("The conversion of days results %d year/years\n %d month/months\n %d day/days\n",years,months, remaining_days);



}