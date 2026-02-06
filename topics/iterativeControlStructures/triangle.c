#include <stdio.h>

int main(void) {
    int i, j;
    int height;

    printf("Input an integers: \n");
    scanf(" %d", &height);

    for(i = 0; i < height; i++) {
        
        printf("%d", i+1); 
        printf("*");

        for(j = 0; j < i; j++) {
            printf("*");
        }

        printf(" \n");
    }

    return 0;
    
}
