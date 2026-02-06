#include <stdio.h>

int main(void) {

    int number;

    printf("What number do you wanna check? \n");
    scanf(" %d", &number);

    int checker = number % 2;

    if(checker == 1) {
        printf("%d is an odd number!", number);
    } else {
        printf("%d is an even number!", number);
    }

}