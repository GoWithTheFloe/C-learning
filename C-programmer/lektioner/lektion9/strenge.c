#include <stdio.h>

//  charReplace - karakter der skal erstattes
//  charExchange - karakter der skal indsættes
void exchange(char str[], char charReplace, char charExchange);


int main(void){

    //Streng
    char str[] = "Foodback";

    printf("Here's the string: %s\n", str);

    exchange(str, 'o', 'e');

    printf("Here's the string: %s\n", str);


    return 0;
}


void exchange(char str[], char charReplace, char charExchange){

    int i = 0;

    while(str[i] != '\0'){

        if (str[i] == charReplace){
            str[i] = charExchange;
        }

        i++;
    }
  

}