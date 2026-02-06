#include <stdio.h>
#include <math.h>

#define DELTA 0.1

int main(void){

    double r, x, y;

    printf("Input radius of circle: ");
    scanf("\n %lf", &r);

    printf("Input x-coordinate: ");
    scanf("\n %lf", &x);

    printf("Input y-coordinate: ");
    scanf("\n %lf", &y);

    //Tjekker om hypotenusen er større end radius 
    if(sqrt((x * x)+ (y * y)) > r){

        printf("The point is out of the circle \n");

    } else if((r - DELTA) < sqrt((x * x)+ (y * y)) && sqrt((x * x)+ (y * y)) < r + DELTA){

        printf("The point is on the periferi \n");

    } else {

        printf("The point is within the circle \n");

    }

    return 0;


}