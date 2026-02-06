#include <stdio.h>
#include <string.h>

#define SECS_PER_MIN 60
#define SECS_PER_HOUR 3600
#define SECS_PER_DAY 86400
#define SECS_PER_WEEK 604800
#define SECS_PER_MONTH 2678400

int main() {

    // Variabler til beregning
    int amountOfSeconds, totalAmountOfSeconds;
    int months, weeks, days, hours, minutes, seconds;
    char *totalMonths, *totalWeeks, *totalDays, *totalHours, *totalMinutes, *totalSeconds;

    // Variabler til valg af program
    char program[50];
    char *secondsConverter = "secondsConverter";

    printf("Please enter which program you want to run:\n");
    printf("1. %s\n", secondsConverter);
    printf("Choose by number or name: ");
    scanf("%49s", program); // læs input, max 49 tegn

    // Tjek om input matcher "1" eller programnavnet
    if(strcmp(program, "1") == 0 || strcmp(program, secondsConverter) == 0) {

        // Bed om input af sekunder
        printf("Heyo, please enter the amount of seconds you want measured: ");
        if (scanf("%d", &amountOfSeconds) != 1) {
            fprintf(stderr, "Invalid input. Write an integer.\n");
            return 1;
        }

        totalAmountOfSeconds = amountOfSeconds;

        // Udregn tid
        months = amountOfSeconds / SECS_PER_MONTH;
        amountOfSeconds %= SECS_PER_MONTH;

        weeks = amountOfSeconds / SECS_PER_WEEK;
        amountOfSeconds %= SECS_PER_WEEK;

        days = amountOfSeconds / SECS_PER_DAY;
        amountOfSeconds %= SECS_PER_DAY;

        hours = amountOfSeconds / SECS_PER_HOUR;
        amountOfSeconds %= SECS_PER_HOUR;

        minutes = amountOfSeconds / SECS_PER_MIN;
        seconds = amountOfSeconds % SECS_PER_MIN;

        // Vælg singular/plural
        totalMonths = (months == 1) ? "month" : "months";
        totalWeeks  = (weeks == 1) ? "week" : "weeks";
        totalDays   = (days == 1) ? "day" : "days";
        totalHours  = (hours == 1) ? "hour" : "hours";
        totalMinutes= (minutes == 1) ? "minute" : "minutes";
        totalSeconds= (seconds == 1) ? "second" : "seconds";

        // Print resultat
        printf("%d seconds is equivalent to:\n", totalAmountOfSeconds);
        if(months > 0)  printf("  %d %s\n", months, totalMonths);
        if(weeks > 0)   printf("  %d %s\n", weeks, totalWeeks);
        if(days > 0)    printf("  %d %s\n", days, totalDays);
        if(hours > 0)   printf("  %d %s\n", hours, totalHours);
        if(minutes > 0) printf("  %d %s\n", minutes, totalMinutes);
        if(seconds > 0) printf("  %d %s\n", seconds, totalSeconds);

    } else {
        printf("Unknown program selection.\n");
    }

    return 0;
}
