#include <stdio.h>
#include <math.h>

/* Find roots in the quadratic euqtion a * x*x + b * x + c = 0.
   Assume as a precondition that a is not zero
   
   Output parametre i eksemplet - call-by-reference parametre:
    Der overføres en pointer til en int og two pointere til doubles
    Output fra rod-beregningen formidles tilbage til kaldstedet gennem disse tre pointere
                                                                */

void solveQuadraticEquation(double a, double b, double c, int *numberOfRoots, double *root1, double *root2){
    
    double discriminant;

    discriminant = b * b - 4 * a * c;

    if(discriminant < 0)
    {
        *numberOfRoots = 0;
    }
    else if(discriminant == 0)
    {
        *numberOfRoots = 1;
        *root1 = -b/(2*a);
    }
    else
    {
        *numberOfRoots = 2;
        *root1 = (-b + sqrt(discriminant))/(2*a);
        *root2 = (-b - sqrt(discriminant))/(2*a);
    }
}

int main(void){
    double a, b, c, firstRoot, secondRoot;
    int numberOfRoots;

    printf("Enter coeficients a, b, and c: \n");
    scanf(" %lf %lf %lf", &a, &b, &c);

    if(a != 0)
    {
        solveQuadraticEquation(a, b, c, &numberOfRoots, &firstRoot, &secondRoot);

        if(numberOfRoots == 0) printf("No roots\n");
        else if(numberOfRoots == 1) printf("One root: %f\n", firstRoot);
        else printf("Two roots: %f and %f\n", firstRoot, secondRoot);

    }
    else printf("The coeficient a must be non-zero");

    return 0;

}

