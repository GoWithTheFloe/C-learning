#include <stdio.h>

// pH værdi tjekker...

int main(void){

int pH;

printf("Input pH-værdi \n");
scanf(" %d", &pH);

    if (pH > 7){
        if (pH < 12) {
            printf("Alkaline \n");
        } else {
            printf("Very alkaline \n");
        }
        
    } else {
        if (pH == 7) {
            printf("Neutral \n");
        } else if (pH > 2){
            printf("Acidic \n");
        } else {
            printf("Very Acidic \n");
        }   
    }

    return 0;
}