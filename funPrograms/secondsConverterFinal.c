/*
 * Program: secondsConverter
 * Forfatter: Theodor Fløe
 * Dato: 2. oktober 2025
 * Formål: Konverterer et antal sekunder til måneder, uger, dage, timer, minutter og sekunder
 * Input: Heltal, antal sekunder
 * Output: Antal måneder, uger, dage, timer, minutter og sekunder
 * Kommentar: Træner brugen af heltalsdivision og modulus-operatoren
 */

#include <stdio.h>
#include <math.h>
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
    
    /* Program vælger
    // Variabler til valg af program
    char program[50];
    char *secondsConverter = "secondsConverter";

    printf("Please enter which program you want to run \n");
    printf("Choose by number or name: \n");
    printf("1. %s \n", secondsConverter);
    scanf("%49s", &program); // læs input, max 49 tegn
    
    
    // Tjek om input matcher "1" eller programnavnet
    if(strcmp(program, "1") == 0 || strcmp(program, secondsConverter) == 0) {

*/
        //Checks if the input is an integar (Correct)
        printf("Please enter the amount of seconds you want measured\n");
        if (scanf("%d", &amountOfSeconds) != 1) {
            fprintf(stderr, "Invalid input. Write an integar.\n");
            return 1;
        }

        //Saves total amount of seconds in an integar
        totalAmountOfSeconds = amountOfSeconds;

        //Calculates the different amounts of values
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

        // Vælg singular/plural
        /*
        Hvordan det virker:
        (months == 1) → testen/condition
        ? "month" → hvad der bruges hvis condition er sand
        : "months" → hvad der bruges hvis condition er falsk
        Det betyder: “Hvis months er 1, brug "month", ellers brug "months"”
        */
        totalMonths = (months == 1) ? "month" : "months";
        totalWeeks  = (weeks == 1) ? "week" : "weeks";
        totalDays   = (days == 1) ? "day" : "days";
        totalHours  = (hours == 1) ? "hour" : "hours";
        totalMinutes= (minutes == 1) ? "minute" : "minutes";
        totalSeconds= (seconds == 1) ? "second" : "seconds";

        
        printf("%d seconds is equivalent to:\n", totalAmountOfSeconds);

        //Tjekker om det er værd at printe linjerne
        if (months > 0) printf("  %d %s\n", months, totalMonths);
        if (weeks > 0) printf("  %d %s\n", weeks, totalWeeks);
        if (days > 0) printf("  %d %s\n", days, totalDays);
        if (hours > 0) printf("  %d %s\n", hours, totalHours);
        if (minutes > 0) printf("  %d %s\n", minutes, totalMinutes);
        if (seconds > 0) printf("  %d %s\n", seconds, totalSeconds);
    //}
return 0;

}