#include <stdio.h>

void getInput(int *lawnLenght, int *lawnWidth, int *factor);
void scale(int *lawnLenght, int *lawnWidth, int factor);

int main(void){
    
    int lawnLength, lawnWidth;
    int factor;


    getInput(&lawnLength, &lawnWidth, &factor);

    // Calculates the old length & width and then scales with factor
    // &-values are pointers.
    scale(&lawnLength, &lawnWidth, factor);

    printf("New length: %d\nNew width: %d\n", lawnLength, lawnWidth);
    
    return 0;

} 

void getInput(int *lawnLenght, int *lawnWidth, int *factor){
    printf("Write the length, width & scaling factor: \n");
    scanf(" %d %d %d", lawnLenght, lawnWidth, factor);
}

// Value of *-pointers are feeded back as the new values
void scale(int *lawnLenght, int *lawnWidth, int factor){

    *lawnLenght *= factor;
    *lawnWidth *= factor;
}