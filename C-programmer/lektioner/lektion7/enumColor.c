#include <stdio.h>

enum color {red, green, blue};

int main(void){

    // test 1
    enum color c = red;

    printf("test 1\n");
    printf("c = %d\n", c);
    printf("c+1 = %d\n", c+1);
    printf("c+2 = %d\n", c+2);


    // test 2

    enum color c1 = green, c2;
    int i1 = 10, i2;
    double d1 = 123.789, d2;

    c2 = d1;
    i2 = d1;
    d2 = c1;

    printf("\ntest 2\n");

    printf("c2 = %d\n", c2);
    printf("i2 = %d\n", i2);
    printf("d2 = %f\n", d2);

    return 0;
    
}