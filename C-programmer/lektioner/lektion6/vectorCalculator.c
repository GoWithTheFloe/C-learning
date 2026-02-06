#include <stdio.h>

void add(int u1, int u2, int v1, int v2, int *w1, int *w2);
void minus(int u1, int u2, int v1, int v2, int *w1, int *w2);
void scalar(int u1, int u2, int v1, int v2, int *w1, int *w2);

int main(void) {

    // output parameters
    int u1, u2;
    int v1, v2;
    // result coordinates
    int w1, w2;

    int choice;
    char *printChoice;


    printf("What would you like to do?\n"
           "1. Add\n"
           "2. Subtract\n"
           "3. Scalar product\n");

    scanf("%d", &choice);

    if (choice == 1) printChoice = "add";
     else if (choice == 2) printChoice = "subtract";
     else if (choice == 3) printChoice = "find the scalar product with";


    printf("Write the first vector input (e.g. 1 2 ): \n");
    scanf(" %d %d", &u1, &u2);

    printf("Now write the vector you would like to %s: \n", printChoice);
    scanf(" %d %d", &v1, &v2);


    if (choice == 1) {
        add(u1, u2, v1, v2, &w1, &w2);
        printf("The added vector is: %d, %d\n", w1, w2);
    } else if (choice == 2) {
        minus(u1, u2, v1, v2, &w1, &w2);
        printf("The subtracted vector is: %d, %d\n", w1, w2);
    } else if (choice == 3) {
        scalar(u1, u2, v1, v2, &w1, &w2);
        printf("The scalar product of the vectors is: %d\n", w1 + w2);
    }
    

    return 0;
}


void add(int u1, int u2, int v1, int v2, int *w1, int *w2){
    *w1 = u1 + v1;
    *w2 = u2 + v2;
}

void minus(int u1, int u2, int v1, int v2, int *w1, int *w2){
    *w1 = u1 - v1;
    *w2 = u2 - v2;

}

void scalar(int u1, int u2, int v1, int v2, int *w1, int *w2){
    *w1 = u1 * v1;
    *w2 = u2 * v2;

}