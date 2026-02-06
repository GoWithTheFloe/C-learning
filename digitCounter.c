/*
Ciffer-tæller
Målet med denne opgave er at træne dig i programmering med løkker, herunder at vælge gode iterative kontrolstrukturer til opgaven. 
Som altid er det også målet at lave et velopstillet program med god indrykning, og med brug af gode variabelnavne.

I denne opgave skal du skrive et program, der kan tælle hvor mange tal (fra 1 til n) der indeholder et bestemt ciffer c. 
For eksempel er der 19 tal fra 1 til 100 der indeholder cifferet 5. (Vi bruger det almindelige 10-talsystem i denne opgave).

Vi starter med en simplere opgave og bygger os frem mod en komplet løsning. 
Du skal kun aflevere den færdige version (eller så langt du nåede).

Programmet skal indlæse to heltal n og c. Cifferet c skal være et heltal mellem 0 og 9, og n skal være mindst 1. 
(Du kan printe en fejlbesked, hvis brugeren indtaster et ugyldigt input).

Som en opvarmning til den egentlige opgave, kan du skrive et program, der tjekker om n slutter på cifret c. 
(Hint: du kan benytte modulo-operatoren til dette.)

Næste skridt er at omskrive programmet, så det kan tjekke om n indeholder cifret c. 
Hvilken iterativ kontrolstruktur kan du bruge til at opnå dette? Overvej omhyggeligt hvordan løkken starter, og hvordan den slutter. 
Tag gerne inspiration fra følgende regne-eksempel, hvor jeg har beskrevet processen for et konkret tal og ciffer.

Indeholder 7264 cifret 2?
     Slutter 7264 på 2?
     Nej
     Divider med 10 (heltalsdivision) = 726
Indeholder 726 cifret 2?
     Slutter 726 på 2?
     Nej
     Divider med 10 (heltalsdivision) = 72
Indeholder 72 cifret 2?
     Slutter 72 på 2?
     Ja
     Derfor indeholder 7264 cifret 2.

Som det sidste skridt skal du nu udvide programmet, så det tæller hvor mange af tallene fra 1 til n, der indeholder cifferet c. 
Hvilken iterativ kontrolstruktur egner sig godt til dette?

Udskriv resultatet med printf: for eksempel hvis input er 100 5, så er output 19.

Tak til Morten Konggaard Schou for denne opgavetekst.
*/
#include <stdio.h>


int main(void) {

    int n; // input number
    int d; // digit to search for

    printf("Enter two integers n (>=1) and d (0..9) (e.g. 100 5): \n");    
    scanf(" %d %d", &n, &d);

    // Validate input: n must be >= 1 and d must be a single digit (0–9)
    if (n < 1 || d < 0 || d > 9) {
        fprintf(stderr, "Error: n must be >= 1 and d must be between 0 and 9.\n");
        return 1; // Exit the program with an error code

    }


    int count = 0; // keeps track of how many numbers contain the digit 'd'

    // Loop through all numbers from 1 to n
    for (int i = 1; i <= n; i++) {

        int temp = i; // temporary copy of the number to inspect its digits
        int found = 0; // variable to mark if the digit 'd' is found in the current number

        // Extract digits from the current number one by one
        while (temp > 0) {
            int digit = temp % 10; // get the last digit
            if (digit == d) {      // check if it matches the digit we're looking for
                found = 1;         // mark that we've found the digit
                break;             // no need to check remaining digits
            }
            temp /= 10; // remove the last digit
        }
        // If the digit was found in this number, increment the count
        if (found == 1) count++;
    }


    printf("The digit %d occurs %d times from 1 to %d.\n", d, count, n);
    return 0;
}

