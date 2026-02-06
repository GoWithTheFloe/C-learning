#include <stdio.h>
#include <math.h>

#define SECS_PER_MONTH 2628000
#define SECS_PER_WEEK 604800
#define SECS_PER_DAY 86400
#define SECS_PER_HOUR 3600
#define SECS_PER_MINUTE 60
#define SECS_PER_SEC 1

int main(void){

    int months, weeks, days, hours, minutes, seconds;
    int inputSeconds = 2729000;

    printf("insert the amount of seconds you want calculated: \n");
    scanf("%d", &inputSeconds);

    months = inputSeconds / SECS_PER_MONTH;
    inputSeconds = inputSeconds % SECS_PER_MONTH;

    weeks = inputSeconds / SECS_PER_WEEK;
    inputSeconds = inputSeconds % SECS_PER_WEEK;

    days = inputSeconds / SECS_PER_DAY;
    inputSeconds = inputSeconds % SECS_PER_DAY;

    hours = inputSeconds / SECS_PER_HOUR;
    inputSeconds = inputSeconds % SECS_PER_HOUR;

    minutes = inputSeconds / SECS_PER_MINUTE;
    inputSeconds = inputSeconds % SECS_PER_MINUTE;


    printf("Months left: %d, Weeks: %d, Days: %d, Hours: %d, Minutes: %d, and Seconds: %d \n", months, weeks, days, hours, minutes, seconds);

    return 0;
}