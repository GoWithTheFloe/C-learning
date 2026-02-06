/*Skriv et program som oversætter udvalgte engelske navneord fra ental til flertal. Følgende regler skal overholdes:

Hvis et navneord ender i et "y" fjernes "y" og der tilføjes "ies".
Hvis et navneord ender i et "s", "ch" eller "sh" tilføjes et "es".
I alle andre tilfælde tilføjes et "s" til navneordet.
Udskriv hvert navneord i både ental og flertal.

Som altid skal du designe en funktion med et passende navn, og med parametre (input og evt. output). Og som altid laver vi top-down programmering ved trinvis forfinelse. Ønsker du at bruge returværdien af funktionen til noget?

Afprøv dit program på følgende engelske navneord:

chair dairy boss circus fly dog church clue dish
Alloker plads til disse i en passende array af tekststrenge.

Denne opgave svarer til opgave 5 side 532 i 6. udgave af lærebogen

Hints: Måske er funktionen strrchr fra string.h nyttig i denne opgave. Den søger efter et tegn fra bagenden af strengen. Husk også at du blot kan tilgå tegn i en tekststreng med array subscripting operatoren: str[i]. Du kan teste om et tegn i din streng svarer til et bestemt tegn: str[i] == 'y'.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

char *plural(char str[]);

int main(void){

    char str[ARRAY_SIZE];
    char *strPlural;

    printf("Write your word\n");
    scanf(" %s", str);

    strPlural = plural(str);

    printf("Here's the new string: %s\n", strPlural);    
    
    

    return 0;

}


/*char *plural(char str[]){
    char *newWord = (char *) malloc((strlen(str) + 2) * sizeof(char) + 1);

    
    int i = 0;
    while (str[i] != '\0'){
        newWord[i] = str[i];
        if (strlen(str) == 'y' ){
            printf("%s", newWord);
        }
        i++;

    }

    return newWord;


}*/

char *plural(char str[]){
    // Alloker lidt ekstra: +3 for sikkerhed (fx 'ies' + '\0')
    size_t len = strlen(str);
    char *out = malloc(len + 4);

    // Håndter 'ch' og 'sh' (to-bogstavs endelser)
    if (len >= 2) {
        char last = str[len - 1];
        char second_last = str[len - 2];

        if(second_lastlast == 'c' && last == 'h'){
            // ends with "ch": add "es"
            strcpy(out, str);
            strcat(out, 'es');
            return out;

        } 
        if (second_last == 's' && last == 'h') {
            // ends with "sh": add "es"
            strcpy(out, str);
            strcat(out, "es");
            return out;
        }


    }

    // Håndter enkelt-bogstav endelser
    if (len >= 1) {
        char last = str[len - 1];
        if (last == 'y') {
            // fjern 'y', tilføj "ies"
            if (len == 1) {
                // edge-case: "y" -> "ies"
                strcpy(out, "ies");
            } else {
                strncpy(out, str, len - 1);
                out[len - 1] = '\0';
                strcat(out, "ies");
            }
            return out;
        } else if (last == 's') {
            // ends with "s": add "es"
            strcpy(out, str);
            strcat(out, "es");
            return out;
        }
    }

    // default: add 's'
    strcpy(out, str);
    strcat(out, "s");
    return out;

}








