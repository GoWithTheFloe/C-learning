/*Strengomvending består i at bytte om på tegnene i en tekststreng, således at de første tegn ender med at være de sidste. Eksempelvis er strengomvendingen af "streng" lig med "gnerts".

Programmer funktionen strrev(char *str), som omvender tegnene i parameteren str. Bemærk at parameteren str både tjener som input og output parameter. Vi ønsker altså at bytte om på tegnene i det char array, som str peger på.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

char *reversal(char str[]);

int main(void){
    char str[ARRAY_SIZE];
    char *strReversal;

    printf("Enter a string: \n");
    scanf(" %[^\n]", str);

    strReversal = reversal(str);

    printf("The old string: %s\n", str);
    printf("The new string: %s\n", strReversal);

    return 0;

}

char *reversal(char str[]){
    if (str == NULL) return NULL;

    int len = strlen(str);
    if (len <= 1) return str; 

    char *strNew = malloc(len + 1);

    /*int i = 0;
    int j = len - 1;

    while (str[i] != '\0'){
        char tmp = str[i];
        str[i] = strNew[j];
        strNew[j] = tmp;
        i++;
        j--;
    }*/

    for (int i = 0; i < len; i++){
        strNew[i] = str[len - 1 - i];
    }

    strNew[len] = '\0';

    return strNew;
}