#include <stdio.h>
#include <stdlib.h>

int daysInMonth(int mth, int yr);
int isLeapYear(int yr);


int main(void) {

    int mth, yr;

    do{
        printf("Enter a month - a number between 1 and 12: \n");
        scanf(" %d", &mth);
        printf("Enter a year (write 0 to end): \n");
        scanf(" %d", &yr);

        if (yr != 0)
            printf("There are %d days in month %d in year %d \n", daysInMonth(mth, yr), mth, yr);
    } while (yr != 0);

    return 0;

}

int daysInMonth(int month, int year){
    int numberOfDays;
    switch(month) {
        case 1: 
        case 3: 
        case 5: 
        case 7:
        case 8:
        case 10:
        case 12:
            numberOfDays = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            numberOfDays = 30;
            break;
        case 2:
            if (isLeapYear(year)) numberOfDays = 29;
            else numberOfDays = 28;
            break;
        default: 
            exit(-1);
            break;
    }
    return numberOfDays;
}

int isLeapYear(int year){
    int res;
    if (year % 400 == 0) res = 1;
     else if (year % 100 == 0) res = 0;
     else if (year % 4 == 0) res = 1;
     else res = 0;

    return res;
}