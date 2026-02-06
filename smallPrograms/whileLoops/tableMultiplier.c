#include <stdio.h>

int main(void){
    
    int number;

    printf("Enter a number: ");
    scanf(" %d", &number);

    int count = 1;

    while (count <=20) {
        printf("%d ", count * number);

        count += 1;
    }

}