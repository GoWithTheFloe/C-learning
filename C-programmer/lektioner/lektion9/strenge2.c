#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  charReplace - karakter der skal erstattes
//  charExchange - karakter der skal indsættes
char *exchange(char str[], char charReplace, char charExchange);

int main(void){

    //Streng
    char str[] = "Foodback";
    char *str2[10];
    printf("Here's the string: %s\n", str);
    printf("We exhange\n");

    str2 = exchange(str, 'o', 'e');

    printf("Here's the old string: %s\n", str);
    printf("Here's the new string: %s\n", str2);


    return 0;
}

//Dynamisk lager lokering/hukkomelse
char *exchange(char str[], char charReplace, char charExchange){
    char *strNew = (char *) malloc((strlen(str) + 1) * sizeof(char));
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] == charReplace){
            strNew[i] = charExchange;
        } else {
            strNew[i] = str[i];
        }
        i++;
    }
    strNew[i] = '\0';

    return strNew;
}