#include <stdio.h>

int main(void) {

    int i, j;
    int height, space;

    printf("Input a digit \n");
    scanf(" %d", &height);

    for(i = 0; i <= height; ++i) {

        printf("%d", i);
        
        for(space = height; space > i; --space) {
            printf(" ");
        }

        for(j = 0; j < i; ++j) {
            printf("*");   
        }

        printf("\n");
    }

}