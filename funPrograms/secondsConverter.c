#include <stdio.h>
#include <math.h>

#define SECS_PER_MIN 60
#define SECS_PER_HOUR 3600
#define SECS_PER_DAY 86400
#define SECS_PER_WEEK 604800
#define SECS_PER_MONTH 2678400

int main() {

    //Forskellige variabler, placeholders.
    int amountOfSeconds, totalAmountOfSeconds; 
    int months, weeks, days, hours, minutes, seconds;
    char *totalMonths, *totalWeeks, *totalDays, *totalHours, *totalMinutes, *totalSeconds;

    //Tjekker om det er korret input, altså en integar
    printf("Heyo, please enter the amount of seconds you want measured\n");
    if (scanf("%d", &amountOfSeconds) != 1) {
            fprintf(stderr, "Invalid input. Write an integar.\n");
        return 1;
    }

    //sætter totale antal sekunder til en variabels værdi
    totalAmountOfSeconds = amountOfSeconds;

    //Udregner de forskellige værdier af variablerne
    months = amountOfSeconds / SECS_PER_MONTH;
    amountOfSeconds = amountOfSeconds % SECS_PER_MONTH;

    weeks = amountOfSeconds / SECS_PER_WEEK;
    amountOfSeconds = amountOfSeconds % SECS_PER_WEEK;

    days = amountOfSeconds / SECS_PER_DAY;
    amountOfSeconds = amountOfSeconds % SECS_PER_DAY;

    hours = amountOfSeconds / SECS_PER_HOUR;
    amountOfSeconds = amountOfSeconds % SECS_PER_HOUR;

    minutes = amountOfSeconds / SECS_PER_MIN;
    amountOfSeconds = amountOfSeconds % SECS_PER_MIN;

    seconds = amountOfSeconds % SECS_PER_MIN;

    //Tjekker om det er 1 eller flere måneder, uger, dage, timer, minutter og sekunder
    if (months == 1){

        totalMonths = "month";
    } else {
        totalMonths = "months";
    }

    if (weeks == 1){
        totalWeeks = "week";
    } else {
        totalWeeks = "weeks";
    }

    if (days == 1){
        totalDays = "day";
    } else {
        totalDays = "days";
    }

    if (hours == 1){
        totalHours = "hour";
    } else {
        totalHours = "hours";
    }

    if (minutes == 1){
        totalMinutes = "minutes";
    } else {
        totalMinutes = "minutes";
    }
    
    if (seconds == 1){
        totalSeconds = "second";
    } else {
        totalSeconds = "seconds";
    }


    printf("%d seconds is equivalent to:\n", totalAmountOfSeconds);
    printf("  %d %s \n", months, totalMonths);
    printf("  %d %s \n", weeks, totalWeeks);
    printf("  %d %s \n", days, totalDays);
    printf("  %d %s \n", hours, totalHours);
    printf("  %d %s \n", minutes, totalMinutes);
    printf("  %d %s \n", seconds, totalSeconds);

return 0;

}