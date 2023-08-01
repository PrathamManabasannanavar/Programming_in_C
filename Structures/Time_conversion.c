//A simple C program to compute hours, minutes and seconds
#include<stdio.h>

typedef struct TIME
{
    int hour, min, sec;
} TIME;

void read_time(TIME *);
void update_time(TIME *);
void display_time(TIME *);

main()
{
    TIME t1;
    printf("Enter hour min and sec\n");
    read_time(&t1);
    printf("Entered time is:\n");
    display_time(&t1);
    update_time(&t1);
    printf("Time after incrementing 1sec is:\n");
    display_time(&t1);
}

void read_time(TIME *t1)
{
    scanf("%d %d %d",&t1->hour, &t1->min, &t1->sec);
}

void display_time(TIME *t1)
{
    printf("%dhours %dmin %dsec\n",t1->hour, t1->min, t1->sec);
}

// This function is only for 1sec increment
/*void update_time(TIME *t1)
{
    t1->sec++;

    if(t1->sec >= 60)
    {
        (t1)->min++;
        (t1)->sec = 0;
    }

    if(t1->min >= 60)
    {
        (t1)->hour++;
        (t1)->min = 0;
    }

    if(t1->hour >= 24)
        (t1)->hour = (t1)->hour % 24;
}
*/

//This function is for n sec increment
void update_time(TIME *t1)
{
    {
        int incr;
        printf("\nEnter the number of seconds you want to increment\n");
        scanf("%d",&incr);
        t1->sec += incr;
    }
    while(t1->sec >= 60 || t1->min >= 60 || t1->hour >= 24)
    {
        if(t1->sec >= 60)
        {
            t1->min += t1->sec/60;
            t1->sec %= 60;
        }
        else if(t1->min >= 60)
        {
            t1->hour += t1->min/60;
            t1->min %= 60;
        }
        else if(t1->hour >= 24)
        {
            t1->hour %= 24;
        }
    }
}