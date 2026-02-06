#include <stdio.h>

int main(void) {
    int i, j;
    int height, width;

    printf("Input two integers: \n");
    scanf(" %d %d", &height, &width);


    for(j = 0; j < height; j++) {

        //  Excludes 0 fropm being printed
        printf("%d", j+1);
        for(i = 0; i < width; i++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}