#include <stdio.h>

int main(void) {

    char answer, forget;

    // Checks if whether letters y or n is used, 
    // tho it does not exclude if other letters are added too or both.
    do {
        printf("Answer yes or no (y/n): \n");
        scanf(" %c%c", &answer, &forget);
    }   while (answer != 'y' && answer != 'n');

    printf("The answer is %s \n", 
            answer == 'y' ? "yes" : "no");
}
