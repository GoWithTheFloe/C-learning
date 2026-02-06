#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZÉ 200

void counter(char str[]);
char *exclamation(char str[]);
char *doubleLetters(char str[]);

int main(void){

    char str[STRING_SIZÉ];
    char *strExclamation;
    char *strDouble;

    printf("Write a string\n");
    scanf(" %[^\n]", str);


    counter(str);

    strExclamation = exclamation(str);
    printf("Here's the old string: %s\n", str);
    printf("Here's the new string: %s\n", strExclamation);    
    
    strDouble = doubleLetters(str);
    printf("Here's the new string: %s\n", strDouble);

}


void counter(char str[]){

    int i = 0;
    int amount = 0;

    while (str[i] != '\0'){
        if(islower(str[i]) && isspace(str[i]) == 0){

            amount++;
            //firstLower(str);
        }
        i++;
    }
    printf("The amount of lower case letters are: %d\n", amount);

}

char *exclamation(char str[]){
    char *strExclamation = (char *) malloc((strlen(str) + 2) * sizeof(char));
    int i = 0;
    while (str[i] != '\0'){
        strExclamation[i] = str[i];
        i++;
    } 
   
    strExclamation[i] = '!';
    strExclamation[i + 1] = '\0';

    return strExclamation;
}

char *doubleLetters(char str[]){
    char *strDouble = (char *) malloc(((strlen(str)) * sizeof(char) * 2) + 1);
    //  i holder styr på placering i str arrayet
    int i = 0;

    //  j holder styr på placering i strDouble arrayet
    int j = 0;

    if (strDouble == NULL){
        printf("not enough space\n");
        exit(EXIT_FAILURE);
    }
    
    while (str[i] != '\0'){
        strDouble[j] = str[i];
        strDouble[j + 1] = str[i];
        j = j + 2;
        i++;
    }

    strDouble[j] = '\0';

    return strDouble;

}


/*char *firstLower(char str[]){

    if(int j = 0; j <= 1; j++){
        
    }
}*/