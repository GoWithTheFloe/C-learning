#include <stdio.h>

void getInput(int *oldLawnLengthPtr, int *oldLawnWidthPtr, int *factorPtr);
void scale(int oldLawnLength, int oldLawnWidth, int factor, int *newLawnLengthPtr, int *newLawnWidthPtr);

int main(void){
    int oldLawnLength;
    int oldLawnWidth;
    int newLawnLength, newLawnWidth;
    int factor;



    getInput(&oldLawnLength, &oldLawnWidth, &factor);

    // Calculates the old length & width and then scales with factor
    // &-values are pointers.
    scale(oldLawnLength, oldLawnWidth, factor, &newLawnLength, &newLawnWidth);

    printf("New length: %d\nNew width: %d\n", newLawnLength, newLawnWidth);
    
    return 0;

} 

void getInput(int *oldLawnLengthPtr, int *oldLawnWidthPtr, int *factorPtr){
    printf("Write the length, width & scaling factor: \n");
    scanf(" %d %d %d", oldLawnLengthPtr, oldLawnWidthPtr, factorPtr);
}

// Value of *-pointers are feeded back as the new values
void scale(int oldLawnLength, int oldLawnWidth, int factor, int *newLawnLengthPtr, int *newLawnWidthPtr){

    *newLawnLengthPtr = oldLawnLength * factor;
    *newLawnWidthPtr = oldLawnWidth * factor;
}